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

## Fedora

Fedora 38+ has google test available as a package. You can install it with
`gtest` and `gtest-devel`. If google test is not installed locally this project
will download it dynamically. You will also want to install `libasan` to take
advantage of address sanitizers.

Install the following packages on Fedora 38+

- gtest-devel
- gtest
- libasan

## Windows

Install [vcpkg](https://vcpkg.io/en/getting-started) and integrate vcpkg

- readline

## Quick Start

This project has a preset file to help build the project. You can list all the
presets with `cmake --list-presets`. You can then pick one of the presets to
configure and build as shown below.

```bash
cmake --preset x86_x64-ASan
cmake --build --preset x86_x64-ASan
```
