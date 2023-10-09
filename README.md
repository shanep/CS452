# Project

This is a project setup to build a C project using [cmake](https://cmake.org/)
and using [unity](https://github.com/ThrowTheSwitch/Unity) unit testing
framework.

## Files and Directories

Below is a detailed explication of all the directories and files of this project.

- cmake - This directory contains some extra scripts to help setup our project
  in our case we want to use address sanitizer to make sure we don't have memory
  errors in our program
- src - This is the directory that will contain all the code that you will write.
  - CMakeLists.txt - this is the build file for this directory.
  - lab.c - this is were you will write your solution
  - lab.h - this is the header file containing the all the functions that you
    need to implement
  - labconfig.h.in - this is a file that will be completed by cmake during the
    build process.
  - main.cpp - a stub for the main method.
