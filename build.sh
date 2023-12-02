#!/bin/bash

OUT_DIR="./build"
BUILD_DIR="./build"
SRC_DIR="./"

if [ ! -d $OUT_DIR ]; then
    mkdir -p $BUILD_DIR
fi

cmake -S $SRC_DIR -G Ninja  -B $BUILD_DIR

# Explicitly build the project
cmake --build $BUILD_DIR --config Debug

# Build the fetched library specifically in Release mode
cmake --build $BUILD_DIR --target sfml-graphics --config Release
cmake --build $BUILD_DIR --target sfml-audio --config Release