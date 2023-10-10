#!/bin/bash
git submodule update --init --recursive
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..