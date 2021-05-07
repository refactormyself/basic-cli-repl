#! /usr/bin/env bash

INIT_DIR=$PWD

echo "******* Using the very basic CMake setup *******"
mkdir build
cd build
cmake ..
make test
./app
cd $INIT_DIR 
#rm -rf build

# echo
# echo "******* Using the very basic Make setup *******"
# make
# ./basic_gtests 
# make clean