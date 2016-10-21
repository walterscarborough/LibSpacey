#!/bin/bash

# Create build directory if it doesn't exist yet
if [ ! -d build ]; then
    mkdir  build
fi

# Install dependencies via Conan
cd build

conan install --file ../conanfile.txt --build gtest .

# Create build scripts via cmake
cmake ..

# Run generated build scripts
make
