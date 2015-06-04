@echo off
setlocal EnableDelayedExpansion
set MSVCLINE=
echo ^<?xml version="1.0" encoding="UTF-8"?^> > results.xml
echo ^<testsuite name="constexprs"^> >> results.xml
for %%f in (*.cpp) do (
  set FILE=%%~nf
  cl /EHsc /c /O2 /GS- /GR /Gy /Zc:inline /DBOOST_SPINLOCK_STANDALONE=1 %%f /I..\..\include\boost\spinlock\bindlib\include
  dumpbin /disasm !FILE!.obj > !FILE!.msvc.S
  del !FILE!.obj
  set LINE=
  for /f %%i in ('count_opcodes.py !FILE!.msvc.S') do set LINE=%%i
  if "!MSVCLINE!" == "" (
    set MSVCLINE=!LINE!
  ) else (
    set MSVCLINE=!MSVCLINE!,!LINE!
  )
  echo   ^<testcase name="!FILE!.msvc"^> >> results.xml
  if !LINE! GTR 5 (
    if "!FILE!" == "promise_future_reduce" (
      echo     ^<skipped/^> >> results.xml
    ) else (
      echo     ^<failure message="Opcodes generated !LINE! exceeds 5"/^> >> results.xml
    )
  )
  echo     ^<system-out^> >> results.xml
  echo ^<^^![CDATA[ >> results.xml
  type !FILE!.msvc.S.test1.s >> results.xml
  echo ]]^> >> results.xml
  echo     ^</system-out^> >> results.xml
  echo   ^</testcase^> >> results.xml
)
echo ^</testsuite^> >> results.xml
echo !MSVCLINE! >> msvc.csv
