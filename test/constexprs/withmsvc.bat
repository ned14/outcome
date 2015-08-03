@echo off
setlocal EnableDelayedExpansion
set MSVCLINE=
if not exist msvc.csv (
  for %%f in (*.cpp) do (
    set FILE=%%~nf
    if "!MSVCLINE!" == "" (
      set MSVCLINE="!FILE!"
    ) else (
      set MSVCLINE=!MSVCLINE!,"!FILE!"
    )
  )
  echo !MSVCLINE! >> msvc.csv
)
set MSVCLINE=
echo ^<?xml version="1.0" encoding="UTF-8"?^> > results.xml
echo ^<testsuite name="constexprs"^> >> results.xml
for %%f in (*.cpp) do (
  set FILE=%%~nf
  cl /EHsc /c /O2 /GS- /GR /Gy /Zc:inline /DBOOST_MONAD_ENABLE_OPERATORS=1 /DSPINLOCK_STANDALONE=1 /DNDEBUG %%f
  dumpbin /disasm !FILE!.obj > !FILE!.msvc.S
  del !FILE!.obj
  set LINE=
  for /f %%i in ('count_opcodes.py !FILE!.msvc.S') do set LINE=%%i
  if "!MSVCLINE!" == "" (
    set MSVCLINE=!LINE!
  ) else (
    set MSVCLINE=!MSVCLINE!,!LINE!
  )
  if not "!FILE:min_=!" == "!FILE!" (
      echo   ^<testcase name="!FILE!.msvc"^> >> results.xml
      if !LINE! GTR 7 (
        if "!FILE!" == "min_monad_construct_exception_move_destruct" (
          echo     ^<skipped/^> >> results.xml
        ) else if "!FILE!" == "min_promise_future_reduce" (
          echo     ^<skipped/^> >> results.xml
        ) else if "!FILE!" == "min_future_construct_move_destruct" (
          echo     ^<skipped/^> >> results.xml
        ) else if "!FILE!" == "min_monad_then" (
          echo     ^<skipped/^> >> results.xml
        ) else (
          echo     ^<failure message="Opcodes generated !LINE! exceeds 7"/^> >> results.xml
        )
      )
      echo     ^<system-out^> >> results.xml
      echo ^<^^![CDATA[ >> results.xml
      type !FILE!.msvc.S.test1.s >> results.xml
      echo ]]^> >> results.xml
      echo     ^</system-out^> >> results.xml
      echo   ^</testcase^> >> results.xml
    )
  )
)
echo ^</testsuite^> >> results.xml
echo !MSVCLINE! >> msvc.csv
