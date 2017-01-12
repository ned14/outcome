IF "%VisualStudioVersion%" == "14.0" (
cl /Zi /EHsc /O2 /MD /GF /GR /Gy /bigobj /wd4503 test_multiabi.cpp /DUNICODE=1 /DWIN32=1 /D_UNICODE=1 /DBOOST_OUTCOME_ENABLE_ADVANCED=1 /I..\include /I. /I..\..\.. /link
) ELSE (
echo Sorry need inline namespace support for this
)
