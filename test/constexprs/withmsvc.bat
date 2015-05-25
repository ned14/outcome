setlocal EnableDelayedExpansion 
for %%f in (*.cpp) do (
  set FILE=%%~nf
  cl /EHsc /c /O2 /GS- /arch:SSE2 /GR /Gy /Zc:inline /DBOOST_SPINLOCK_STANDALONE=1 %%f /I..\..\include\boost\spinlock\bindlib\include
  dumpbin /disasm:nobytes !FILE!.obj > !FILE!.msvc.S
  del !FILE!.obj
)
