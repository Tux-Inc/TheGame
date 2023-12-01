#!/bin/bash

OUT_DIR="./build"
BUILD_DIR="./build"
SRC_DIR="./"

# if [ -d $OUT_DIR ]; then
#     rm -Rf $OUT_DIR;
# fi

if [ ! -d $OUT_DIR ]; then
    mkdir -p $BUILD_DIR
fi

cmake -S $SRC_DIR -G Ninja  -B $BUILD_DIR

ninja

cmake --build $BUILD_DIR