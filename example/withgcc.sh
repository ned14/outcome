rm -rf monad_example
g++ -std=c++14 -o monad_example -DSPINLOCK_STANDALONE=1 monad_example.cpp
./monad_example
