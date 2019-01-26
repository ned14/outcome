+++
title = "Prerequisites"
weight = 2
+++

Outcome is a header-only C++ 14 library known to work on these compiler-platform combinations or better:

- clang 4.0.1 (LLVM) [FreeBSD, Linux, OS X]
- GCC 6.3 [Linux]
- Visual Studio 2017 [Windows]
- XCode 9 [MacOS]

It is worth turning on C++ 17 if you can, as there are many usability and performance improvements.
If your compiler implements the Concepts TS, it is worth turning support on. Support is automatically
detected and used.


Partially working compilers (this was last updated January 2019):

- clang 3.5 - 3.9 can compile varying degrees of the test suite, the problem is lack of complete and unbuggy C++ 14 language support.
- GCC's 7 and 8 have internal compiler error bugs in their constexpr implementation which tend to be triggered by using Outcome in constexpr. GCC 8 likes to internal compiler error with Outcome in C++ 2a mode, hopefully this will be fixed soon by the GCC devs. clang and Visual Studio work correctly, if you need an alternative. 
- Early editions of Visual Studio 2017 have many corner case problems. The latest point release, VS2017.9, only has a few known problems, and should be relatively unsurprising for most use cases.
