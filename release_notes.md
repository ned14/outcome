This is the proposed Boost.Outcome library, a Boost C++ 14 library providing
\ref monad, a factory and family of policy driven lightweight monads with
the specialisations of `outcome<T>`, `result<T>` and `option<T>`.

Its github source code repository lives at https://github.com/ned14/boost.outcome.

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master) CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

You need these compilers or better:
- GCC 5.0
- clang 3.7
- VS2015 Update 2
- clang 3.7 with Microsoft Codegen ("winclang")

Its sole mandatory dependency is on https://github.com/ned14/boost-lite, a minimal emulation of Boost for C++ 11.
