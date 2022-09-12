# KDE Thumbnailer HPGL

HPGL thumbnails are created by calling [hp2xx](https://www.gnu.org/software/hp2xx/) which needs to be installed.

This package will also install a better HPGL file detection based on a few common HPGL commands, because consistent file extensions apparently weren't a thing in the 90s (at least not within the HP test & measurements divisions).

Based on https://github.com/z3ntu/kde-thumbnailer-apk.

## Installation
### Arch Linux (aur)
Install aur package [kde-thumbnailer-hpgl-git](https://aur.archlinux.org/packages/kde-thumbnailer-hpgl-git)

### Manual
1. Install the dependencies: hp2xx, kio, cmake, extra-cmake-modules
2. These lines will install it correctly for Arch Linux, be careful with other distros!
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX='/usr' -DCMAKE_INSTALL_LIBDIR=lib ..
make
sudo make install
```
