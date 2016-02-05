
Debian
====================
This directory contains files used to package aricoind/aricoin-qt
for Debian-based Linux systems. If you compile aricoind/aricoin-qt yourself, there are some useful files here.

## aricoin: URI support ##


aricoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install aricoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your aricoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/aricoin128.png` to `/usr/share/pixmaps`

aricoin-qt.protocol (KDE)

