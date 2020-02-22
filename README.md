# CopperSpice Hello World

[CopperSpice](https://www.copperspice.com) is a alternative to QT, that uses macros, templates and constant expressions instead of a meta object compiler (short moc). 

## Requirements
* A C++17 compatible compiler. ``gcc`` or ``MSVC``
* CopperSpice
* Make
* CMake

## Build & Run on Linux
```shell
$ git clone https://github.com/feldim2425/CopperSpiceHelloWorld.git
$ cd CopperSpiceHelloWorld
$ mkdir build && cd build
$ cmake -DCMAKE_INSTALL_PREFIX=./install -DCS_PATH=<COPPERSPICE PATH> ..
$ make
$ make install
$ ./install/HelloCopperSpice
```