setlocal EnableDelayedExpansion
set MSVCLINE=
for %%f in (*.cpp) do (
  set FILE=%%~nf
  cl /EHsc /c /O2 /GS- /GR /Gy /Zc:inline /DBOOST_SPINLOCK_STANDALONE=1 %%f /I..\..\include\boost\spinlock\bindlib\include
  dumpbin /disasm !FILE!.obj > !FILE!.msvc.S
  del !FILE!.obj
  for /f %%i in ('count_opcodes.py !FILE!.msvc.S') do set LINE=%%i
  if "!MSVCLINE!" == "" (
    set MSVCLINE=!LINE!
  ) else (
    set MSVCLINE=!MSVCLINE!,!LINE!
  )
)
echo !MSVCLINE! >> msvc.csv
