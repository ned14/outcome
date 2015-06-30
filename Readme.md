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
 - [x] Implement shared_future_policy and a conformance suite for shared_future.
 - [x] Implement shared_future_ptr which thunks a shared_future API through a shared_ptr to
basic_future<shared_future_policy>.

 - [ ] Add monad_errc error code for when a move or copy constructor throws?
 - [ ] Review all throws of exceptions and see if they can be replaced with an error_code set.
 - [ ] Have basic_monad gain an explicit conversion constructor from other basic_monad with different
implementation policies such option can convert to result or monad and so on. Look into having the
implementation policies themselves do the conversion, so some template alias e.g. convert<>().


# Benchmarks with early lightweight future-promise:

All values are CPU cycles on a i7-3770K @ 3.9Ghz.

## clang 3.7:
### libstdc++ 4.9 future promise:
Simple loop: 719
Producer Consumer: 793
  Creation and setting: 637
  Getting from future: 153
  Destruction of future: 4
Three threads MPSC: 2619
  Creation: 1348
  Setting: 1139
  Getting from future: 98
  Destruction of future: 34

### lightweight future promise:
Simple loop: 178
Producer Consumer: 264 (3.00x faster)
  Creation and setting: 200
  Getting from future: 51
  Destruction of future: 13
Three threads MPSC: 801 (3.27x faster)
  Creation: 375
  Setting: 226
  Getting from future: 127
  Destruction of future: 73

### libstdc++ 4.9 shared_future promise:
Simple loop: 699
Producer Consumer: 769
  Creation and setting: 612
  Getting from future: 33
  Destruction of future: 124

### lightweight shared_future promise:
Simple loop: 260
Producer Consumer: 378 (2.03x faster)
  Creation and setting: 281
  Getting from future: 51
  Destruction of future: 46


## GCC 5.1:
### libstdc++ 5.1 future promise:
Simple loop: 732
Producer Consumer: 774
  Creation and setting: 625
  Getting from future: 145
  Destruction of future: 4
Three threads MPSC: 1921
  Creation: 819
  Setting: 993
  Getting from future: 79
  Destruction of future: 30

### lightweight future promise:
Simple loop: 141
Producer Consumer: 262 (2.95x faster)
  Creation and setting: 191
  Getting from future: 53
  Destruction of future: 18
Three threads MPSC: 519 (3.70x faster)
  Creation: 241
  Setting: 189
  Getting from future: 63
  Destruction of future: 26

### libstdc++ 5.1 shared_future promise:
Simple loop: 788
Producer Consumer: 767
  Creation and setting: 614
  Getting from future: 32
  Destruction of future: 120

### lightweight shared_future promise:
Simple loop: 350
Producer Consumer: 377 (2.03x faster)
  Creation and setting: 238
  Getting from future: 31
  Destruction of future: 109


## VS2015:
### Dinkumware future promise:
Simple loop: 575
Producer Consumer: 1583
  Creation and setting: 870
  Getting from future: 281
  Destruction of future: 432

### lightweight future promise:
Simple loop: 151
Producer Consumer: 231 (6.85x faster)
  Creation and setting: 179
  Getting from future: 35
  Destruction of future: 16

### Dinkumware shared_future promise:
Simple loop: 584
Producer Consumer: 1433
  Creation and setting: 706
  Getting from future: 266
  Destruction of future: 460

### lightweight shared_future promise:
Simple loop: 481
Producer Consumer: 747 (1.92x faster)
  Creation and setting: 403
  Getting from future: 74
  Destruction of future: 270

</center>
