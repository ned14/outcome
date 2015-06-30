<center>
master branch unit test status:

Linux: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/) Windows: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.spinlock/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.spinlock?branch=master)

Documentation: https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/doxygen/annotated.html

Lightweight promise-future:
 - [x] Map ternary true/false/other into namespace lightweight_futures.
 - [x] Have future-promise conformance suite also run for std::future.
 - [x] Write thread sanitising fuzz tester to monte carlo for race conditions.
 - [x] Add iostream overloads for basic_monad
 - [x] Return monad_errc::exception_present error code for when get_error() sees an excepted state.

 - [ ] Add monad_errc error code for when a move or copy constructor throws?
 - [ ] Review all throws of exceptions and see if they can be replaced with an error_code set.
 - [ ] Have basic_monad gain an explicit conversion constructor from other basic_monad with different
implementation policies such option can convert to result or monad and so on. Look into having the
implementation policies themselves do the conversion, so some template alias e.g. convert<>().


# Benchmarks with early lightweight future-promise:

All values are CPU cycles on a i7-3770K @ 3.9Ghz.

## clang 3.7:
### libstdc++ 4.9 future promise:
Simple loop: 761
Producer Consumer: 838
  Creation and setting: 674
  Getting from future: 160
  Destruction of future: 4

### lightweight future promise:
Simple loop: 260
Producer Consumer: 378 (2.22x faster)
  Creation and setting: 281
  Getting from future: 51
  Destruction of future: 46

## GCC 5.1:
### libstdc++ 5.1 future promise:
Simple loop: 726
Producer Consumer: 809
  Creation and setting: 654
  Getting from future: 150
  Destruction of future: 4

### lightweight future promise:
Simple loop: 205
Producer Consumer: 323 (2.50x faster)
  Creation and setting: 227
  Getting from future: 49
  Destruction of future: 48

### lightweight future promise (set promise before getting future):
Simple loop: 124
Producer Consumer: 170
  Creation and setting: 102
  Getting from future: 37
  Destruction of future: 30

## VS2015:
### Dinkumware future promise:
Simple loop: 596
Producer Consumer: 1545
  Creation and setting: 752
  Getting from future: 311
  Destruction of future: 482

### lightweight future promise:
Simple loop: 210
Producer Consumer: 311 (4.97x faster)
  Creation and setting: 236
  Getting from future: 37
  Destruction of future: 38

</center>
