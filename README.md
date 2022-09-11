# KDE Thumbnailer HPGL

Based on https://github.com/z3ntu/kde-thumbnailer-apk.
HPGL thumbnails are created by calling [hp2xx](https://www.gnu.org/software/hp2xx/) which needs to be installed.
This package will also install a better HPGL file detection based on a few common HPGL commands, because consistent file extensions apparently weren't a thing in the 90s (at least not within the HP test & measurements divisions).

## Installation

1. Install hp2xx, cmake, qt5
2. These lines will install it correctly for Arch Linux, be careful with other distros!
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX='/usr' -DCMAKE_INSTALL_LIBDIR=lib ..
make
sudo make install
```
