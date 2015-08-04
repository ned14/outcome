IF "%VisualStudioVersion%" == "14.0" (
cl /Zi /EHsc /O2 /MD /GF /GR /Gy /bigobj /wd4503 test_multiabi.cpp /DUNICODE=1 /DWIN32=1 /D_UNICODE=1 /D_WIN32=1 /DBOOST_THREAD_VERSION=3 /DBOOST_MONAD_ENABLE_OPERATORS /I..\include /I. /I..\..\.. /link /LIBPATH:..\..\..\stage\lib
) ELSE (
echo Sorry need inline namespace support for this
)
