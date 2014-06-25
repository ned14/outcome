g++-4.8 -std=c++0x -O3 -g -fopenmp -o unittests unittests.cpp -lrt
g++-4.8 -std=c++0x -O3 -g -fopenmp -fgnu-tm -DBOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER -o unittests_stm unittests.cpp -lrt
