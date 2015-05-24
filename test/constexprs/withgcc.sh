#!/bin/bash
for f in *.cpp
do
  FILE=${f%.cpp}
  g++ -S -o $FILE.S -fverbose-asm -O3 -std=c++14 -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
#  g++ -S -o $FILE.S -fverbose-asm -O3 -g -std=c++14 -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
#  as -alhnd $FILE.S > $FILE.lst
done
