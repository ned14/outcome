del /q unittests_*.exe
cl /EHsc /O2 /DNDEBUG /DBOOST_SPINLOCK_MONAD_ENABLE_OPERATORS=1 /DBOOST_SPINLOCK_STANDALONE=1 unittests.cpp -I..\include\boost\spinlock\bindlib\include

rename unittests.exe unittests_1.exe
cl /openmp /EHsc /O2 /DNDEBUG /DBOOST_SPINLOCK_MONAD_ENABLE_OPERATORS=1 /DBOOST_SPINLOCK_STANDALONE=1 unittests.cpp -I..\include\boost\spinlock\bindlib\include

rename unittests.exe unittests_N.exe
