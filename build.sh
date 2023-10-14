#!/bin/bash
if [ ! -d build ]
then
    echo "Configure the project first!"
    exit 1
fi

cmake --build build
