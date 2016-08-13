<center>
master branch unit test status:

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master) CTest dashboard: http://my.cdash.org/index.php?project=Boost.Outcome

Documentation: https://ned14.github.io/boost.outcome/

Tarballs of source with all unit tests passing: https://dedi4.nedprod.com/static/files/

Todo:
 - [x] Fix all remaining mentions of Boost.Monad (e.g. doxygen docs)
 - [x] Loosen explicit basic_monad constructors to allow option => result => monad implicitly.
 - [x] Pack bools in basic_promise_future_storage into value_storage_impl, thus saving 8 bytes
 - [x] Get the constexpr tests firing per-commit in Travis (and maybe Appveyor)
 - [x] Add comparison operators for monad (long overdue!). These need to be able to compare
heterogeneous monad types (add unit tests proving this).
 - [x] Add constexpr compile unit tests for when `<T>` is a LiteralType.
 - [x] Add unit tests for `result<int>` being trivially destructible
 - [x] Add debugging visualisers for Monad for VS2015 as a minimum (it's getting painful to work
on AFIO without these!)
 
Later:
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Add tribool logic programming operator overloads

</center>
