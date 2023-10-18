[![Test on multiple platforms](https://github.com/shanep/cpp-project-template/actions/workflows/test-multi-platform.yml/badge.svg)](https://github.com/shanep/cpp-project-template/actions/workflows/test-multi-platform.yml)

# Project

This is a project template using [cmake](https://cmake.org/),
[googletest](https://github.com/google/googletest), and github actions to run
tests on multiple platforms.

## Dependencies

This project has the following dependencies which need to be installed with
your package manager before you can continue:

- [readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [pthreads](https://hpc-tutorials.llnl.gov/posix/)
- [lcov](https://github.com/linux-test-project/lcov)

## Quick Start

Once all the dependencies are installed you can build the project with cmake.
This project has a preset file to help build the project. You can list all the
presets with `cmake --list-presets`. You can get started right away with the
Address Sanitizer build as shown below.

```bash
cmake --preset x86_x64-ASan
cmake --build --preset x86_x64-ASan
```

## Operating Systems Notes

The `coverage` target only works on Linux. Visual Studio Enterprise is required
if you want code coverage reports on windows.

### Fedora

Fedora 38+ has google test available as a package. You can install it with
`gtest` and `gtest-devel`. If google test is not installed locally this project
will download it dynamically. You will also want to install `libasan` to take
advantage of address sanitizers.

Install the following packages on Fedora 38+

- gtest-devel
- gtest
- libasan

### Windows

Install [vcpkg](https://vcpkg.io/en/getting-started) make sure you set the
`VCPKG_ROOT` to the install location and then install the following packages.

- .\vcpkg install readline
- .\vcpkg install gtest

## VSCode Notes

- The VSCode CMake extension (2023-10-17) does not support all the features of
  cmake presets that this project uses so you will need to add the following to
  your settings.json file so that the extension does not complain about the
  new features we are using.`"cmake.allowUnsupportedPresetsVersions": true`

## Workflows

The following workflows are setup to run on github actions.

- cmake --workflow --preset coverage
- cmake --workflow --preset test
