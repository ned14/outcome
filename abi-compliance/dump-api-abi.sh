#!/bin/sh
mkdir -p build
cd build
CXX=g++-6 cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build .
cd ..
if [ $# -eq 0 ]; then
  DUMPFILE=0
else
  DUMPFILE=$1
fi
rm -f $DUMPFILE.xml
echo "<version>$DUMPFILE</version>" > $DUMPFILE.xml
cat v2.xml >> $DUMPFILE.xml
abi-compliance-checker -l Outcome -dump $DUMPFILE.xml -gcc-path g++-6 gcc-options -DOUTCOME_DISABLE_ABI_PERMUTATION=1
