<center>
master branch unit test status:

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.outcome?branch=master)

Documentation: https://ned14.github.io/boost.outcome/

Outcome/Result/Option:
 - [ ] Add constexpr compile unit tests for when `<T>` is a LiteralType.
 - [ ] Fix all remaining mentions of Boost.Monad (e.g. doxygen docs)

Later:
 - [ ] when_any composure.
 - [ ] Add when_all_p() to complement when_all() with error propagation.
 - [ ] Port AFIO's intrusive enqueued_task into a lightweight packaged_task design.
 - [ ] Loosen explicit basic_monad constructors to allow option => result => monad implicitly, and
monad => result => option explicitly (with potential exception throwing).
 - [ ] Pack bools in basic_promise_future_storage into value_storage_impl, thus saving 8 bytes
 - [ ] Add testing of C++ 1z coroutines support
 - [ ] Add Boost.Fiber support
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Add tribool logic programming operator overloads

</center>
