#!/bin/bash

if [ -d build ]
then
    rm -rf build
fi
mkdir build

if [ -d bin ]
then
    rm -rf bin
fi
mkdir bin

cd build
cmake ..
make -j

../bin/$1
