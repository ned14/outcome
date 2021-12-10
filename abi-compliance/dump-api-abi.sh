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
rm -f $DUMPFILE.xml
echo "<version>$DUMPFILE-gcc7-cxx14</version><headers>../single-header/abi.hpp</headers><libs>build/liboutcome-abi-lib-gcc7-cxx14.so</libs>" > $DUMPFILE.xml
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-7 gcc-options -DOUTCOME_DISABLE_ABI_PERMUTATION=1
