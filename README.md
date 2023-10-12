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

Use one of the configure scripts to setup the project.

- configure - for a default release build no optimizations
- configure-coverage - for a code coverage build
  - run with `make coverage`
- configure-debug-as - for a debug build with address sanitizer

Then change into the build directory `cd build` and run `make` to build the
project and tests. The program and tests will be located in the build directory.
The program that will run all your tests that you wrote in `test-lab.cpp` is
named `test-lab`.

If you run into problems and don't know what when wrong you should run the
`clean.sh` and start over.
