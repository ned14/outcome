if [ -z "$CXX" ]; then
  if [ "$HOSTTYPE" = "FreeBSD" ]; then
    CXX=clang++
  else
    CXX=g++
  fi
fi
rm -rf unittests_* *.gcda *.gcno
INCLUDE=""
if [ -n "$BUILD_EXTRA" ]; then
  echo Building unittests_coverage ...
  #g++ -std=c++0x -pthread -O1 -DNDEBUG -DRUNNING_ON_VALGRIND=1 -g -gdwarf-2 -o unittests_coverage unittests.cpp -lrt -fprofile-arcs -ftest-coverage -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-elide-constructors -fno-inline $INCLUDE
fi
echo C++ 14 check
time clang++-3.7 -Wall -Wextra -std=c++14 -pthread -O3 -DNDEBUG -DBOOST_MONAD_ENABLE_OPERATORS=1 -g -gdwarf-2 -o unittests_1 unittests.cpp -lrt $INCLUDE -Wno-unknown-pragmas -Wno-unused-function || true
echo C++ 11 check
time clang++-3.7 -Wall -Wextra -std=c++11 -pthread -O3 -DNDEBUG -DBOOST_MONAD_ENABLE_OPERATORS=1 -g -gdwarf-2 -o unittests_1 unittests.cpp -lrt $INCLUDE -Wno-unknown-pragmas -Wno-unused-function || true
echo No operators check
time clang++-3.7 -Wall -Wextra -std=c++11 -pthread -O3 -DNDEBUG -g -gdwarf-2 -o unittests_nooperators unittests.cpp -lrt $INCLUDE -Wno-unknown-pragmas -Wno-unused-function || true
echo Building unittests_valgrind ...
time $CXX -std=c++1y -pthread -O1 -DNDEBUG -DBOOST_MONAD_ENABLE_OPERATORS=1 -g -gdwarf-2 -o unittests_valgrind unittests.cpp -lrt -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-elide-constructors -fno-inline -DBOOST_SPINLOCK_ENABLE_VALGRIND $INCLUDE
echo Building unittests_1 ...
time $CXX -Wall -Wextra -std=c++1y -pthread -O3 -DNDEBUG -g -gdwarf-2 -o unittests_1 unittests.cpp -lrt $INCLUDE -Wno-unknown-pragmas -Wno-unused-function
echo Building unittests_N ...
time $CXX -Wall -Wextra -std=c++1y -pthread -O3 -DNDEBUG -g -fopenmp -gdwarf-2 -o unittests_N unittests.cpp -lrt $INCLUDE -Wno-unused-function
if [ -n "$BUILD_EXTRA" ]; then
#  echo Building unittests_stm_1 ...
#  $CXX -std=c++0x -O3 -DNDEBUG -g -fgnu-tm -DBOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER -o unittests_stm_1 unittests.cpp -lrt $INCLUDE
#  echo Building unittests_stm_N ...
#  $CXX -std=c++0x -O3 -DNDEBUG -g -fopenmp -fgnu-tm -DBOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER -o unittests_stm_N unittests.cpp -lrt $INCLUDE
  echo Building unittests_sanitise ...
  #g++-4.8 -std=c++0x -fsanitize=thread -fPIC -pie -O0 -DNDEBUG -g -fopenmp -gdwarf-2 -o unittests_sanitise unittests.cpp -lrt -ltsan -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-elide-constructors -I$BOOSTCONFIG
  #clang++-3.4 -std=c++0x -fsanitize=thread -O2 -DNDEBUG -g -o unittests_sanitise unittests.cpp -lrt -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-elide-constructors -fno-inline $INCLUDE
  $CXX -std=c++1y -fsanitize=undefined -fsanitize=thread -fPIC -pie -O1 -DNDEBUG -DRUNNING_ON_VALGRIND=1 -D__SANITIZE_ADDRESS__=1 -g -fopenmp -gdwarf-2 -o unittests_sanitise unittests.cpp -lrt -ltsan -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-elide-constructors -fno-inline $INCLUDE
fi
