# Project

This is a project setup to build a C project using [cmake](https://cmake.org/)
and using [unity](https://github.com/ThrowTheSwitch/Unity) unit testing
framework.

TODO: command line arguments
TODO: Unit tests
TODO: Refactored code

## Dependencies

This project has the following dependencies which need to be installed with
your package manager before you can continue:

- [readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [pthreads](https://hpc-tutorials.llnl.gov/posix/)
- [lcov](https://github.com/linux-test-project/lcov)

## Quick Start

1. run `./setup.sh`
2. compile the project `cd build && make`
3. run the tests `./test-lab`

The program and tests will be located in the build directory. The program that
will run all your tests that you wrote in `test-lab.c` is named `test-lab`. Some
projects may also require an executable which is named `myprogram`.

If you run into problems and don't know what when wrong you should run the
`clean.sh` and start over.

## Writing tests

## Files and Directories

Below is a detailed explication of all the directories and files of this project.

```bash
.
├── .vscode
├── CMakeLists.txt
├── LICENSE
├── README.md
├── Retrospective.md
├── clean.sh
├── cmake
├── run-coverage.sh
├── run-leak-check.sh
├── run-tests.sh
├── setup.sh
├── src
│   ├── CMakeLists.txt
│   ├── lab.c
│   ├── lab.h
│   ├── labconfig.h.in
│   └── main.c
└── tests
    ├── CMakeLists.txt
    └── test-lab.c
```

- **.gitignore** - files and directories that we want git to ignore
- **.vscode** - This directory contains all our VSCode settings
  - extensions.json - recommended extensions for this project
  - launch.json - settings to run and debug our program
  - settings.json - generally editor settings
- **CMakeLists.txt** - Base build file for the whole project
- **LICENSE** - This projects license
- **README.md** - This file 😃
- **Retrospective.md** - This file needs to be completed when you are done with the project
- **clean.sh** - bash script to clean out all generated files
- **cmake** - This directory contains some extra scripts to help setup our project
  in our case we want to use address sanitizer to make sure we don't have memory
  errors in our program
- **run-coverage.sh** - runs code coverage
- **run-leak-check.sh** - runs the unit tests with leak check enabled
- **run-tests.sh** - runs all the unit tests
- **setup.sh** - Generate the project using cmake!
- **src** - This is the directory that will contain all the code that you will write.
  - CMakeLists.txt - this is the build file for this directory.
  - lab.c - this is were you will write your solution
  - lab.h - this is the header file containing the all the functions that you
    need to implement
  - labconfig.h.in - this is a file that will be completed by cmake during the
    build process.
  - main.c - a stub for the main method.
- **tests** - This is the directory that will contain our unit tests
  - CMakeLists.txt - this is the build file for our tests
  - test-lab.c - this is the file where all our tests will live
