#!/bin/sh -e
mkdir -p build-gcc7-cxx14
cd build-gcc7-cxx14
CXX=g++-7 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=14 -DLABEL=gcc7-cxx14
cmake --build .
cd ..
mkdir -p build-gcc9-cxx17
cd build-gcc9-cxx17
CXX=g++-9 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 -DLABEL=gcc9-cxx17
cmake --build .
cd ..

if [ $# -eq 0 ]; then
  DUMPFILE=2.2
else
  DUMPFILE=$1
fi
RETCODE=0
abidw --stats --no-show-locs --out-file abi_dumps/Outcome/$DUMPFILE-gcc7-cxx14/abigail.xml --headers-dir ../single-header/abi.hpp build-gcc7-cxx14/liboutcome-abi-lib-gcc7-cxx14.so || RETCODE=1
abidw --stats --no-show-locs --out-file abi_dumps/Outcome/$DUMPFILE-gcc9-cxx17/abigail.xml --headers-dir ../single-header/abi.hpp build-gcc9-cxx17/liboutcome-abi-lib-gcc9-cxx17.so || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc7-cxx14 $DUMPFILE-gcc9-cxx17 || true
  cd ../..
fi
exit $RETCODE
