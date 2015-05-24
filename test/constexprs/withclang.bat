for %%f in (*.cpp) do (
  set FILE=%%~nf
  clang++ -S -fverbose-asm -o %FILE%.S -O3 -std=c++11 -DBOOST_SPINLOCK_STANDALONE=1 %%f -I../../include/boost/spinlock/bindlib/include -Wno-c++14-extensions
)
