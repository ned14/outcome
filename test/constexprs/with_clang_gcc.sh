#!/bin/bash 
GCCLINE=""
CLANGLINE=""
if [ ! -f gcc.csv ]; then
  for f in *.cpp
  do
    FILE=${f%.cpp}
    if [ "$GCCLINE" != "" ]; then
      GCCLINE=$GCCLINE,\"$FILE\"
      CLANGLINE=$CLANGLINE,\"$FILE\"
    else
      GCCLINE=\"$FILE\"
      CLANGLINE=\"$FILE\"
    fi
  done
  echo $GCCLINE >> gcc.csv
  echo $CLANGLINE >> clang.csv
fi
GCCLINE=""
CLANGLINE=""
echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > results.xml
echo "<testsuite name=\"constexprs\">" >> results.xml
for f in *.cpp
do
  FILE=${f%.cpp}
  
  if [ 1 -eq 1 ]; then
    echo "Compiling ${FILE} with gcc ..."
    g++-5 -c -o $FILE.o -O3 -std=c++14 -fno-keep-inline-functions -DBOOST_OUTCOME_ENABLE_OPERATORS=1 -DSPINLOCK_STANDALONE=1 -DNDEBUG $f
    objdump -d -S $FILE.o > $FILE.gcc.S

    echo "Compiling ${FILE} with clang ..."
    clang++-3.8 -Wall -Wextra -c -o $FILE.o -O3 -std=c++14 -DBOOST_CXX14_CONSTEXPR=constexpr -DBOOST_OUTCOME_ENABLE_OPERATORS=1 -DSPINLOCK_STANDALONE=1 -DNDEBUG $f
    objdump -d -S $FILE.o > $FILE.clang.S
    rm $FILE.o
  fi

  if [ "$GCCLINE" != "" ]; then
    GCCLINE=$GCCLINE,
    CLANGLINE=$CLANGLINE,
  fi
  echo "Counting assembler ops in ${FILE}.gcc.S ..."
  GCCVAL=$(python3 count_opcodes.py $FILE.gcc.S)
  GCCLINE=$GCCLINE$GCCVAL
  echo "GCC produces ${GCCVAL} ops"
  echo "Counting assembler ops in ${FILE}.clang.S ..."
  CLANGVAL=$(python3 count_opcodes.py $FILE.clang.S)
  CLANGLINE=$CLANGLINE$CLANGVAL
  echo "clang produces ${CLANGVAL} ops"

  # We only care about the min_* tests
  if [ "${FILE#min_}" != "$FILE" ]; then
    echo "  <testcase name=\"${FILE}.gcc\">" >> results.xml
    if [ $GCCVAL -gt 7 ] \
         && ([ "$FILE" != "min_monad_bind" ] || [ $GCCVAL -gt 20 ]) \
         && ([ "$FILE" != "min_monad_construct_exception_move_destruct" ] || [ $GCCVAL -gt 30 ]) \
         && ([ "$FILE" != "min_option_next" ] || [ $GCCVAL -gt 12 ]) \
      ; then
      echo "FAILURE: Opcodes generated $GCCVAL exceeds limit"
      echo "    <failure message=\"Opcodes generated $GCCVAL exceeds limit\"/>" >> results.xml
    fi
    echo "    <system-out>" >> results.xml
    echo "<![CDATA[" >> results.xml
    cat $FILE.gcc.S.test1.s >> results.xml
    echo "]]>" >> results.xml
    echo "    </system-out>" >> results.xml
    echo "  </testcase>" >> results.xml

    echo "  <testcase name=\"${FILE}.clang\">" >> results.xml
    if [ $CLANGVAL -gt 7 ]; then
#      echo "    <skipped/>" >> results.xml
      echo "FAILURE: Opcodes generated $CLANGVAL exceeds limit"
      echo "    <failure message=\"Opcodes generated $CLANGVAL exceeds limit\"/>" >> results.xml
    fi
    echo "    <system-out>" >> results.xml
    echo "<![CDATA[" >> results.xml
    cat $FILE.clang.S.test1.s >> results.xml
    echo "]]>" >> results.xml
    echo "    </system-out>" >> results.xml
    echo "  </testcase>" >> results.xml
  fi
  echo
done
echo "</testsuite>" >> results.xml
echo $GCCLINE >> gcc.csv
echo $CLANGLINE >> clang.csv
