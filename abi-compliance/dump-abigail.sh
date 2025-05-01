#!/bin/sh -e
mkdir -p build-gcc13-cxx17
cd build-gcc13-cxx17
CXX=g++ cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 -DLABEL=gcc13-cxx17
cmake --build .
cd ..
mkdir -p build-gcc13-cxx20
cd build-gcc13-cxx20
CXX=g++ cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 -DLABEL=gcc13-cxx20
cmake --build .
cd ..

if [ $# -eq 0 ]; then
  DUMPFILE=2.2
else
  DUMPFILE=$1
fi
RETCODE=0
mkdir -p abi_dumps/Outcome/$DUMPFILE-gcc13-cxx17
abidw --stats --no-show-locs --out-file abi_dumps/Outcome/$DUMPFILE-gcc13-cxx17/abigail.xml --headers-dir ../single-header/abi.hpp build-gcc13-cxx17/liboutcome-abi-lib-gcc13-cxx17.so || RETCODE=1
mkdir -p abi_dumps/Outcome/$DUMPFILE-gcc13-cxx20
abidw --stats --no-show-locs --out-file abi_dumps/Outcome/$DUMPFILE-gcc13-cxx20/abigail.xml --headers-dir ../single-header/abi.hpp build-gcc13-cxx20/liboutcome-abi-lib-gcc13-cxx20.so || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc13-cxx17 $DUMPFILE-gcc13-cxx20 || true
  cd ../..
fi
exit $RETCODE
