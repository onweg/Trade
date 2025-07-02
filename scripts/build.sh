#!/bin/bash
set -e

BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi
cd "$BUILD_DIR"
cmake ..
make -j$(nproc)
cd ..
echo
echo "Build completed! Binaries and plugins are in build" 