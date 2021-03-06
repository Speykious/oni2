---
id: integrated-terminal
title: Integrated Terminal
sidebar_label: Integrated Terminal
---

Onivim features an integrated terminal, with support for modal navigation via 'normal mode'.

<center>
	<figure>
		<video autoplay loop muted playsinline width=640>
			<source src="/vid/open-terminal.mp4" type="video/mp4">
			<source src="/vid/open-terminal.webm" type="video/webm">
		</video>
		<figcaption>
			<i>
				Opening the terminal with `:term ++curwin`
			</i>
			</figcaption>
	</figure>
</center>

To open the terminal:

- `:term` to open a terminal in a horizontal split
- `:term ++curwin` to open the terminal in the current window
- `:term <cmd>` to open a terminal running a command other than the default shell
- From the __Command Palette__ <kbd>Cmd/Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> - use the _Terminal: Open terminal in new horizontal split_ command.

## Moving between windows

The terminals support the same window movement commands as other windows:

- Move left a window: <kbd>Ctrl</kbd>+<kbd>W</kbd>, <kbd>Ctrl</kbd>+<kbd>H</kbd>
- Move right a window: <kbd>Ctrl</kbd>+<kbd>W</kbd>, <kbd>Ctrl</kbd>+<kbd>L</kbd>
- Move up a window: <kbd>Ctrl</kbd>+<kbd>W</kbd>, <kbd>Ctrl</kbd>+<kbd>K</kbd>
- Move down a window: <kbd>Ctrl</kbd>+<kbd>W</kbd>, <kbd>Ctrl</kbd>+<kbd>J</kbd>

To change the current working directory, which will also update the file explorer root, you can use the `:cd` command - for example: `:cd ~/my/project`.

## Normal Mode

<center>
	<figure>
		<video autoplay loop muted playsinline width=640>
			<source src="/vid/terminal-normal-mode.mp4" type="video/mp4">
			<source src="/vid/termina-normal-mode.webm" type="video/webm">
		</video>
		<figcaption>
			<i>
				Switching to `Terminal Normal` mode and back
			</i>
			</figcaption>
	</figure>
</center>

To switch to `Terminal Normal` mode, use the following command:

- <kbd>Ctrl</kbd>+<kbd>\\</kbd>, <kbd>Ctrl</kbd>+<kbd>N</kbd>

> __NOTE:__ In `Terminal Normal` mode, the buffer is _read-only_.

To switch back to `Terminal Insert` mode, use any command that would transition
to `Insert` mode - for example, <kbd>i</kbd>.

## Configuration

The terminal font can be configured independently from the editor font, via the following settings:

### Appearance

- `terminal.integrated.fontFamily` __(_string_)__ - The font family used by the editor surface. This must be a monospace font. The font may be specified by either the name of the font, or an absolute path to the font file.
- `terminal.integrated.fontSize` __(_int_ default: `12`)__ - The font size used by the editor surface.
- `terminal.integrated.fontSmoothing` __(_"none"|"antialiased"|"subpixel-antialised"_)__ - The smoothing strategy used when rendering fonts. The `"antialised"` setting smooths font edges, and `"subpixel-antialiased"` means characters may be positioned fractionally on the pixel grid.

### Shell command & arguments

- `terminal.integrated.shell.windows` __(_string_ default: `powershell.exe`)__ - The shell command to run on Windows.
- `terminal.integrated.shell.linux` __(_string_ default: `bash`)__ - The shell command to run on Linux.
- `terminal.integrated.shell.osx` __(_string_ default: `zsh`)__ - The shell command to run on Mac.

- `terminal.integrated.shellArgs.windows` __(_string list default: `[]`)__ - Arguments to pass to the Windows shell command.
- `terminal.integrated.shellArgs.linux` __(_string list_ default: `[]`)__ - Arguments to pass to the Linux shell command.
- `terminal.integrated.shellArgs.osx` __(_string list_ default: `["-l"]`)__ - Arguments to pass to the Mac shell command. Note that on macOS by default, each shell should be a login shell, as `~/.bash_profile` (or equivalents) are not loaded at login and should instead be loaded by each shell. See more at http://unix.stackexchange.com/a/119675/115410.

The default shell and command will be used when running a terminal via `:term`, but can be overrided by passing a command to `:term`.

### Environment

Some special environment variables are set for the embedded terminal:

- `ONIVIM_TERMINAL` - set to the current version of the editor. This is guaranteed to be non-empty, so can be used in initialization scripts to determine if the current environment is an embedded Onivim terminal.

