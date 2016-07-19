del /q unittests_*.exe
cl /EHsc /O2 /GL /D_UNICODE /DUNICODE /DNDEBUG /DBOOST_OUTCOME_ENABLE_OPERATORS=1 unittests.cpp /I../include/boost/outcome/v1.0

rename unittests.exe unittests_1.exe
