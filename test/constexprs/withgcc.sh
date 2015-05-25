#!/bin/bash
for f in *.cpp
do
  FILE=${f%.cpp}
  echo "Compiling ${FILE} with gcc ..."
  g++5 -c -o $FILE.o -O3 -std=c++14 -fno-keep-inline-functions -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
  objdump -d -S $FILE.o > $FILE.gcc.S
  echo "Compiling ${FILE} with clang ..."
  clang++ -c -o $FILE.o -O3 -std=c++14 -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
  objdump -d -S $FILE.o > $FILE.clang.S
  rm $FILE.o
done
