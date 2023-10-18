[![Test on multiple platforms](https://github.com/shanep/cpp-project-template/actions/workflows/test-multi-platform.yml/badge.svg)](https://github.com/shanep/cpp-project-template/actions/workflows/test-multi-platform.yml)

# Project

Before you can start working on this project you will need to install all the
required tools and libraries. This project has the following dependencies which
need to be installed with your system package manager before you can continue.
Any project specific dependencies will be listed in the [Software Requirement
Specifications](SRS.md).

- [cmake](https://cmake.org/)
- [googletest](https://github.com/google/googletest)

## Quick Start

Once all the dependencies are installed you can build the project with cmake.
This project has a preset file to help build the project. You can list all the
presets with `cmake --list-presets`. You can get started right away with the
Address Sanitizer build as shown below.

```bash
cmake --preset x86_x64-ASan
cmake --build --preset x86_x64-ASan
```

The following workflows are setup. Each workflow will configure build and test.
The `coverage` target only works on Linux.

```bash
- cmake --workflow --preset coverage
- cmake --workflow --preset test
```

## Operating Systems Notes

This project is configured to build on Linux, Windows and MacOS. The following
sections will help you install the required dependencies for each operating
system.

### Fedora 38+

- sudo dnf group install "Development Tools"
- sudo dnf install libasan lcov gtest gtest-devel

### Windows 11+

- Install [vcpkg](https://vcpkg.io/en/getting-started) in `C:\vcpkg`
- Install [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/) Community Edition

Then set the `VCPKG_ROOT` environment variable as shown below.

```cmd
set VCPKG_ROOT=C:\vcpkg
```

### MacOS

- Install [homebrew](https://brew.sh/)
- Install [Xcode](https://apps.apple.com/us/app/xcode/id497799835?mt=12)
- xcode-select –install to install Command Line Tools.
- brew install cmake gtest

## VSCode Notes

The VSCode CMake extension (2023-10-17) does not support all the features of
cmake presets that this project uses so you will need to add the following to
your settings.json file so that the extension does not complain about the
new features we are using.`"cmake.allowUnsupportedPresetsVersions": true`
