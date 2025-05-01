#!/bin/sh -e
mkdir -p build-gcc11-cxx14
cd build-gcc11-cxx14
CXX=g++-11 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=14 -DLABEL=gcc11-cxx14
cmake --build .
cd ..
mkdir -p build-gcc11-cxx17
cd build-gcc11-cxx17
CXX=g++-11 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 -DLABEL=gcc11-cxx17
cmake --build .
cd ..

if [ $# -eq 0 ]; then
  DUMPFILE=2.2
else
  DUMPFILE=$1
fi
RETCODE=0
abi-dumper -o abi_dumps/Outcome/$DUMPFILE-gcc11-cxx14/binary_only.dump -vnum $DUMPFILE-gcc11-cxx14 build-gcc11-cxx14/liboutcome-abi-lib-gcc11-cxx14.so || RETCODE=1
abi-dumper -o abi_dumps/Outcome/$DUMPFILE-gcc11-cxx17/binary_only.dump -vnum $DUMPFILE-gcc11-cxx17 build-gcc11-cxx17/liboutcome-abi-lib-gcc11-cxx17.so || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc11-cxx14 $DUMPFILE-gcc11-cxx17 || true
  cd ../..
fi
exit $RETCODE
