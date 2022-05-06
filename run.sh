#! /usr/bin/env bash

INIT_DIR=$PWD

echo "******* Using the very basic CMake setup *******"
mkdir build
cd build
cmake ..
make
make test

echo "========  RUN THE GTEST TESTING OF THE APP ======="
./test/app_tests

echo "========  TESTING BASIC cli functions ======="
./app --version
./app --help

echo "========  TESTING THE APP WITH A FILE ======="
./app  $INIT_DIR/data.txt

echo
echo "========  TESTING THE APP AT REPL MODE ======="
./app

cd $INIT_DIR
#rm -rf build

# echo
# echo "******* Using the very basic Make setup *******"
# make
# ./basic_gtests 
# make clean
