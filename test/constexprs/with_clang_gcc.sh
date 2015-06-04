#!/bin/bash
GCCLINE=""
CLANGLINE=""
for f in *.cpp
do
  FILE=${f%.cpp}
  
  if [ 1 -eq 0 ]; then
    echo "Compiling ${FILE} with gcc ..."
    g++-5 -c -o $FILE.o -O3 -std=c++14 -fno-keep-inline-functions -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
    objdump -d -j .text -S $FILE.o > $FILE.gcc.S

    echo "Compiling ${FILE} with clang ..."
    clang++ -c -o $FILE.o -O3 -std=c++14 -DBOOST_CXX14_CONSTEXPR=constexpr -DBOOST_SPINLOCK_STANDALONE=1 -I../../include/boost/spinlock/bindlib/include $f
    objdump -d -j .text -S $FILE.o > $FILE.clang.S
    rm $FILE.o
  fi

  if [ "$GCCLINE" != "" ]; then
    GCCLINE=$GCCLINE,
    CLANGLINE=$CLANGLINE,
  fi
  echo "Counting assembler ops in ${FILE}.gcc.S ..."
  GCCLINE=$GCCLINE $(python3 count_opcodes.py ${FILE}.gcc.S)
  echo "Counting assembler ops in ${FILE}.clang.S ..."
  CLANGLINE=$CLANGLINE $(python3 count_opcodes.py ${FILE}.clang.S)
done
echo $GCCLINE >> gcc.csv
echo $CLANGLINE >> clang.csv