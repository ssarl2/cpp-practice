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

if [ ! -z $1 ] && [ ! -z $2 ]
then
    ../bin/$1 $2
else
    echo "usage : bash run.sh add_person_cpp book.data"
fi
