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
rm -f $DUMPFILE.xml
echo "<version>$DUMPFILE-gcc7-cxx14</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc7-cxx14/liboutcome-abi-lib-gcc7-cxx14.so</libs>" > $DUMPFILE.xml
RETCODE=0
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-7 || RETCODE=1
echo "<version>$DUMPFILE-gcc9-cxx17</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc9-cxx17/liboutcome-abi-lib-gcc9-cxx17.so</libs>" > $DUMPFILE.xml
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-9 || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc7-cxx14 $DUMPFILE-gcc9-cxx17 || true
  cd ../..
fi
exit $RETCODE
