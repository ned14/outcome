del /q unittests_*.exe
cl /EHsc /O2 /GL /DNDEBUG /DBOOST_OUTCOME_ENABLE_OPERATORS=1 /DSPINLOCK_STANDALONE=1 unittests.cpp

rename unittests.exe unittests_1.exe
cl /openmp /EHsc /O2 /GL /DNDEBUG /DBOOST_OUTCOME_ENABLE_OPERATORS=1 /DSPINLOCK_STANDALONE=1 unittests.cpp

rename unittests.exe unittests_N.exe
