Abuse SE README
============

This is a fork of the original Abuse SDL port from <http://abuse.zoy.org/>. It
switches the build system to CMake to make crossplatform building easier.

----

1. Introduction
2. Additional Features
3. Requirements
4. Running Abuse
5. Configuration
6. Installing the datafiles
7. Notes
8. Special Thanks
9. Feedback

----

## 1. INTRODUCTION

Welcome to Abuse SE, the port of the classic game Abuse to the Simple
DirectMedia Layer. Abuse was originally developed by Crack dot Com and
released in 1995 for MS-DOS. A Linux version was also made available at
a later date. It had a few limitations the most restrictive of which was
that it only ran on an 8-bit display, and only in a window.

This version of Abuse will run at any color depth and supports fullscreen mode,
as well as many other new features. It should also be more portable and
hopefully run on a variety of *nix variants, as well as Windows and macOS.

Main purpose of this fork would be re-imagining of the original game, as if it
was re-issued as a deluxe/chanced CD-edition, which would include a new CD soundtrack
as well as some rendered cutscenes, to sink you deeper down into the gritty sci-fi horror 
world of Abuse. 

This port is a work in progress. 

## 2. ADDITIONAL FEATURES

Abuse SE has the following extra features over the original:

  * Runs at a screen bit depth of 8, 16, 24 or 32.
  * Fullscreen display.
  * Scaling by any amount (eg. 2, 3 or 4)
  * SDL2 support for hardware scaling and anti-aliasing.
  * Stereo sound with panning.
  * Mouse wheel support for changing weapons.
  * Customizable keys.
  * CD-quality soundtrack support
  * (planned) Pre-rendered cutscenes playback support 

## 3. REQUIREMENTS

Abuse has the following requirements:

  * SDL2 2.0.3 or above.
  * SDL_mixer 2.0.0 or above.

## 4. RUNNING ABUSE

Generally, just launch it however is appropriate for your platform after
running the `install` build.
If Abuse has been installed properly, the command:

    abuse

will start the game.

The following command-line switches can be used:

    -datadir <arg>    Set the location of the datafiles
    -edit             Start in editor mode
    -f <arg>          Load the map file named <arg>
    -fullscreen       Enable fullscreen mode
    -antialias        Enable anti-aliasing
    -lisp             Start in lisp interpreter mode
    -mono             Disable stereo sound
    -nodelay          Run at maximum speed
    -nosound          Disable sound
    -scale <arg>      Scale by <arg> amount

## 5. CONFIGURATION

Abuse also has a configuration file where these options can be set
instead of using the command line. The file "abuserc" will be created in
your ~/.abuse directory the first time Abuse is run.

Lines starting with a ';' are comments.
Setting an option to '1' turns it on, and '0' turns it off.

To change the keys used in the game, simply type the key after the option.
The following special keys can also be used:

| Code                          | Represents
|-------------------------------|-----------------------
| `LEFT`, `RIGHT`, `UP`, `DOWN` | Cursor keys and keypad.
| `CTRL_L`, `CTRL_R`            | Left and right Ctrl keys.
| `ALT_L`, `ALT_R`              | Left and right Alt keys.
| `SHIFT_L`, `SHIFT_R`          | Left and right Shift keys.
| `F1` - `F10`                  | Function keys 1 through 10.
| `TAB`                         | Tab key.
| `BACKSPACE`                   | Backspace key.
| `ENTER`                       | Enter key
| `INSERT`, `DEL`               | Insert and Delete keys.
| `PAGEUP`, `PAGEDOWN`          | Page Up and Page Down keys.
| `CAPS`, `NUM_LOCK`            | Caps-Lock and Num-Lock keys.
| `SPACE`                       | Spacebar.

The default key settings are as follows:

| Action      | Bound to
|-------------|---------
| Left        | Left arrow, A
| Right       | Right arrow, D
| Up/Jump     | Up arrow, W
| Down/Use    | Down arrow, S
| Prev Weapon | Left or Right Ctrl
| Next Weapon | Insert

The mouse always controls your aim, with Left button for fire and
Right button for special.  The mouse wheel can be used for changing weapons.

## 6. INSTALLING THE DATAFILES

This repository contains the majority of the data files. The only data currently
missing are the sound effects and the music as they weren't released into the
public domain.

You can still grab them off of <http://abuse.zoy.org/> and extract them into
the data directory, and they will be used by the build script.

Under Windows and macOS, Abuse looks for the data files in a path relative to
the executable. Using the CMake `install` and `publish` targets will set up
the directory in the correct way. (See BUILDING.md for more information about
that.)

Under Linux, by default, Abuse expects the datafiles to be installed in the
following location:

    /usr/local/share/games/abuse

However it is possible to change this and tell Abuse where to find the
files if they are in another location.

The location can be set when Abuse is compiled. See the INSTALL.md file for
instructions on how to do this.

You can also specify the location with the -datadir argument when
Abuse is run. See section 4 above.

Finally, the location can be set in the configuration file. See section
5 above.


## 7. CD SOUNDTRACK

Currently, a completely new CD soundtrack for this version of Abuse is in the works. The necessary 
code changes to support this are already in the branch. WAVE file playback is built using the SDL library. 

Unless, explicitly disabled, *.WAV files placed in `/music/cd` data directory are preferred over found
HMI files in the original distribution, i.e. if both `/music/abuse00.hmi` and `/music/cd/track00.wav` are 
present, the WAV soundtrack will be picked.

In the future, a proper red book CD track structure will be supported, where the first CD track is reserved
for the game data, and all the rest, are named incrementally (`track%02d.wav`). That would require some mapping conventions, as currently, 
ABUSE loads off-game music (intro, menu and ending) directly by name, rather than track number.  

## 8. NOTES

### Scaling:
  Scaling is still experimental and not very fast.  Try scaling by different
  amounts to see which ones work the best.

### OpenGL:
  OpenGL can be used to provide hardware accelerated scaling and anti-aliasing.
  You will require a 3D card with the appropriate drivers and GL libraries
  installed for this to work.

### fRaBs:
  The current release of fRaBs has some naming issues under Linux.
  In the 'addon/leon/' directory a lot of the files are uppercase when Abuse
  is expecting them to be lowercase.
  Renaming the files to be all lowercase will fix this problem.

## 8. SPECIAL THANKS

Go to Jonathan Clark, Dave Taylor and the rest of the Crack Dot Com team
for making the best 2D platform shooter ever, and then releasing the
code that makes Abuse possible.

Also, thanks go to Jonathan Clark for allowing Anthony to distribute the
original datafiles with Abuse.

Thanks also to everyone who has contributed ideas, bug reports and patches.
See the AUTHORS file for details.

## 9. FEEDBACK

For this fork, please use the [GitHub page](https://github.com/Xenoveritas/abuse)
if you have any questions, comments, or find bugs.

The original code was taken from <http://abuse.zoy.org/>, but any issues on
non-Linux platforms should be directed to the GitHub page.

----

Have fun!