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
rm -f $DUMPFILE.xml
echo "<version>$DUMPFILE-gcc13-cxx17</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc13-cxx17/liboutcome-abi-lib-gcc13-cxx17.so</libs>" > $DUMPFILE.xml
RETCODE=0
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++ || RETCODE=1
echo "<version>$DUMPFILE-gcc13-cxx20</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc13-cxx20/liboutcome-abi-lib-gcc13-cxx20.so</libs>" > $DUMPFILE.xml
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++ || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc13-cxx17 $DUMPFILE-gcc13-cxx20 || true
  cd ../..
fi
exit $RETCODE
