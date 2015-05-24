for %%f in (*.cpp) do (
  set FILE=%%~nf
  cl /EHsc /FAs /O2 /DBOOST_SPINLOCK_STANDALONE=1 %%f /I..\..\include\boost\spinlock\bindlib\include
)
