#!/bin/sh -e
mkdir -p build-gcc11-cxx14
cd build-gcc11-cxx14
CXX=g++-7 cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=14 -DLABEL=gcc11-cxx14
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
rm -f $DUMPFILE.xml
echo "<version>$DUMPFILE-gcc11-cxx14</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc11-cxx14/liboutcome-abi-lib-gcc11-cxx14.so</libs>" > $DUMPFILE.xml
RETCODE=0
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-11 || RETCODE=1
echo "<version>$DUMPFILE-gcc11-cxx17</version><headers>../single-header/outcome.hpp</headers><libs>build-gcc11-cxx17/liboutcome-abi-lib-gcc11-cxx17.so</libs>" > $DUMPFILE.xml
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-11 || RETCODE=1
if [ $RETCODE -eq 0 ]; then
  cd abi_dumps/Outcome
  tar jcf $DUMPFILE.tar.bz2 $DUMPFILE-gcc11-cxx14 $DUMPFILE-gcc11-cxx17 || true
  cd ../..
fi
exit $RETCODE
