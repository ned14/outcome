#!/bin/sh -e
mkdir -p build
cd build
CXX=g++-7 cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_STANDARD=14 -DLABEL=gcc7-cxx14
cmake --build .
cd ..
if [ $# -eq 0 ]; then
  DUMPFILE=2.2
else
  DUMPFILE=$1
fi
abi-dumper -o abi_dumps/Outcome/$DUMPFILE-gcc7-cxx14/binary_only.dump -vnum $DUMPFILE-gcc7-cxx14 build/liboutcome-abi-lib-gcc7-cxx14.so
