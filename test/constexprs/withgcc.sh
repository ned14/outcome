#!/bin/bash
for f in *.cpp
do
  FILE=${f%.cpp}
  g++-5 -S -o $FILE.S -fverbose-asm -O3 -g -std=c++14 $f
  as -alhnd $FILE.S > $FILE.lst
done
