#!/bin/sh
mkdir -p build
cd build
CXX=g++-6 cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build .
cd ..
if [ $# -eq 0 ]; then
  DUMPFILE=test.dump
else
  DUMPFILE=$1
fi
abi-dumper -o $DUMPFILE -vnum 2.1 build/liboutcome-abi-lib.so
