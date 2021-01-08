open Oni_Core;

module Sub = {
  type menuParams = {builtMenu: MenuBar.builtMenu};

  module OSXMenuSub =
    Isolinear.Sub.Make({
      type nonrec msg = string;
      type nonrec params = menuParams;
      type state = unit;

      let name = "Feature_Menu.nativeOSX";
      let id = (_: params) => "";

      let init = (~params, ~dispatch as _) => {
        module NativeMenu = Revery.Native.Menu;
        let menuBar = NativeMenu.getMenuBarHandle();

        let topItems = MenuBar.top(params.builtMenu |> MenuBar.schema);

        let rec buildItem =
                (parent: NativeMenu.t, items: list(MenuBar.Item.t)) => {
          items
          |> List.iter(item => {
               let title = MenuBar.Item.title(item);
               if (MenuBar.Item.isSubmenu(item)) {
                 let nativeMenu = NativeMenu.create(title);
                 NativeMenu.addSubmenu(~parent, ~child=nativeMenu);
                 buildGroup(nativeMenu, MenuBar.Item.submenu(item));
               } else {
                 ();
               };
             });
        }
        and buildGroup =
            (parent: NativeMenu.t, groups: list(MenuBar.Group.t)) => {
          groups
          |> List.iter(group => {
               let items = MenuBar.Group.items(group);
               buildItem(parent, items);
             });
        };
        topItems
        |> List.iter(item => {
             let title = MenuBar.Menu.title(item);
             let nativeMenu = NativeMenu.create(title);
             let () =
               NativeMenu.addSubmenu(~parent=menuBar, ~child=nativeMenu);
             buildGroup(
               nativeMenu,
               MenuBar.Menu.contents(item, params.builtMenu),
             );
           });
        ();
      };

      let update = (~params as _, ~state, ~dispatch as _) => {
        state;
      };

      let dispose = (~params as _, ~state as _) => {
        ();
      };
    });

  let menu = (~builtMenu: MenuBar.builtMenu, ~toMsg) =>
    if (Revery.Environment.isMac) {
      OSXMenuSub.create({builtMenu: builtMenu}) |> Isolinear.Sub.map(toMsg);
    } else {
      Isolinear.Sub.none;
    };
};

let sub = Sub.menu;
