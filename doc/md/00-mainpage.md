<center><table border="0" cellpadding="4">
<tr>
<td align="center"> <a href="https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz">Source</a><br><a href="https://dedi4.nedprod.com/static/files/boost.outcome-v1.0-source-latest.tar.xz">Tarball</a> </td>
<td align="center"> <a href="https://github.com/ned14/boost.outcome">Boost.Outcome</a><br><a href="https://github.com/ned14/boost.outcome">on GitHub</a> </td>
<td align="center"> <a href="http://my.cdash.org/index.php?project=Boost.Outcome">CTest summary</a><br><a href="http://my.cdash.org/index.php?project=Boost.Outcome">dashboard</a> </td>
<td align="center"> <a href="https://travis-ci.org/ned14/boost.outcome">Linux and MacOS CI:</a><img src="https://travis-ci.org/ned14/boost.outcome.svg?branch=master"/> </td>
<td align="center"> <a href="https://ci.appveyor.com/project/ned14/boost-outcome/branch/master">Windows CI:</a><img src="https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true"/> </td>
<td align="center"> <a href="https://coveralls.io/r/ned14/boost.outcome?branch=master">Coverage:</a><img src="https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master"/> </td>
</tr>
</table></center>

[TOC]

\section description Description

This is the proposed Boost.Outcome library, a Boost C++ 14 library providing
a factory and family of policy driven lightweight monadic value-or-error transports with
the convenience simple specialisations of `outcome<T>`, `result<T>` and `option<T>`.
Its main intended usage is as an ultra light weight error handling framework,
providing a more expressive and type safe alternative to error code integers
or enums, yet much lower overhead than exception throws. Unlike alternatives
such as `expected<T, E>`, it works perfectly with exceptions and RTTI disabled and
thus is suitable for low-latency/games/finance/SG14 users. One could view Outcome as a
"hard coded", less generic `expected<T, E>` intended mainly as a minimum overhead
universal outcome handling framework for C++, hence being named "Outcome".

If you are familiar with Swift's error code throws or Rust's `Result<T>` and `Option<T>`,
you will find almost identical semantics in the transports provided here.
One can therefore write systems programming code using these transports in C++
in the same design pattern as when writing in Rust or Swift, and with a similarly
low runtime overhead. Outcome even has a `try` macro doing the same thing as in
Rust and Swift!

\note Boost.Outcome has not been peer reviewed and is not part of the Boost libraries
(yet). It is hoped it will enter the peer review queue in Q1 2017.

\snippet simple_example.cpp simple_example


\page prerequisites Prerequisites

Boost.Outcome is a header only C++ 14 library known to work on these compilers or better:
- clang 3.5 (LLVM)
- clang 3.7 (with Microsoft Codegen)
- GCC 5.4
- VS2015 Update 2
- Xcode 7.3

**A copy of Boost is not required to use this library**. You can simply drop Outcome into
your project and go.

\warning MSVC generates significant code bloat when using Outcome in large code bases.
If you can use VS2017 which implements C++ 14 constexpr and has a better optimiser for
modern C++, you will see tigher executables. Execution speed is not particularly
different, though one would have thought the extra cache load caused by code bloat might
affect some applications. In this situation, use LLVM clang targeting the MSVC ABI.


\page support Support

<a href="https://stackoverflow.com/">StackOverflow</a> with the boost-outcome tag is the preferred place to ask questions on usage.

If you have a problem, please review the FAQ and the wiki. Searching
<a href="https://github.com/ned14/boost.outcome/issues">the issues</a>
for your problem is also a good idea. If you are encountering what you
think is a bug, please open an issue.
