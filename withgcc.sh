rm -rf unittests_* *.gcda *.gcno
g++-4.8 -std=c++0x -O1 -DNDEBUG -g -gdwarf-2 -o unittests_coverage unittests.cpp -lrt -fprofile-arcs -ftest-coverage -fno-omit-frame-pointer -fno-optimize-sibling-calls
g++-4.8 -std=c++0x -O3 -DNDEBUG -g -gdwarf-2 -o unittests_1 unittests.cpp -lrt
g++-4.8 -std=c++0x -O3 -DNDEBUG -g -fopenmp -gdwarf-2 -o unittests_N unittests.cpp -lrt
g++-4.8 -std=c++0x -O3 -DNDEBUG -g -fgnu-tm -DBOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER -o unittests_stm_1 unittests.cpp -lrt
g++-4.8 -std=c++0x -O3 -DNDEBUG -g -fopenmp -fgnu-tm -DBOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER -o unittests_stm_N unittests.cpp -lrt
