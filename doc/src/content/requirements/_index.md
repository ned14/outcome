+++
title = "Prerequisites"
weight = 2
+++

Outcome is a header only C++ 14 library known to work on these compiler-platform combinations or better:

- clang 4.0.1 (LLVM) [FreeBSD, Linux, OS X]
- GCC 6.3 [Linux]
- Visual Studio 2017 [Windows]
- XCode 9 [MacOS]

It is worth turning on C++ 17 if you can, there are many usability and performance improvements.
If your compiler implements the Concepts TS, it is worth turning support on. Support is automatically
detected and used.


Partially working compilers:

- GCC 5.4.1 is highly usable so long as you don't use Outcome in a `constexpr` evaluation context.
- clang 3.5 - 3.9 can compile varying degrees of the test suite, the problem is lack of complete and unbuggy C++ 14 language support.
