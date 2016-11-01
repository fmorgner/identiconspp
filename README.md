# IdenticonsPP

This is an implementation attempt of github-like retro identicons in C++.

## Requirements

* Conan
* Cmake
* C++14 capable compiler
* (Probably Linux)

## Building

```shell
$ cd build
$ cmake ..
$ cmake --build .
```

## Usage

```shell
$ ./bin/png $(echo -n '<your_string_here>' | sha256sum | grep -o --colour=never "\w*")
```

The identicon will be saved in the current working directory as `identicon.png`

### Example for 'fmorgner'

![Example Identicon for the string 'fmorgner'](/../media/images/fmorgner-identicon.png?raw=true "Example Identicon for the string 'fmorgner'")
