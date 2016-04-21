<center>
master branch unit test status:

Linux: [![Build Status](https://travis-ci.org/ned14/boost.outcome.svg?branch=master)](https://travis-ci.org/ned14/boost.outcome) Windows: [![Build Status](https://ci.nedprod.com/job/Boost.Monad%20Test%20Win8%20VS2014/badge/icon)](https://ci.nedprod.com/job/Boost.Monad%20Test%20Win8%20VS2014/) Coverage: [![Build status](https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true)](https://ci.appveyor.com/project/ned14/boost-outcome/branch/master)

Documentation: https://ned14.github.io/boost.outcome/

Outcome/Result/Option:
 - [ ] Add constexpr compile unit tests for when <T> is a LiteralType.
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
Simple loop: 141                       - 180
Producer Consumer: 262 (2.95x faster)  - 264
  Creation and setting: 191              - 197
  Getting from future: 53                - 50
  Destruction of future: 18              - 17
Three threads MPSC: 519 (3.70x faster) - 954 (now doing genuine sleep waits)
  Creation: 241                          - 459
  Setting: 189                           - 340
  Getting from future: 63                - 100
  Destruction of future: 26              - 54

### libstdc++ 5.1 shared_future promise:
Simple loop: 788
Producer Consumer: 767
  Creation and setting: 614
  Getting from future: 32
  Destruction of future: 120

### lightweight shared_future promise:
Simple loop: 350                       - 466
Producer Consumer: 377 (2.03x faster)  - 506 (regression is from enable_shared_from_this)
  Creation and setting: 238              - 333
  Getting from future: 31                - 44
  Destruction of future: 109             - 129


## VS2015:
### Dinkumware future promise:
Simple loop: 545                       - 573
Producer Consumer: 1084                - 1114
  Creation and setting: 587
  Getting from future: 215
  Destruction of future: 281
Three threads MPSC: 1772               - 1832
  Creation: 888
  Setting: 534
  Getting from future: 300
  Destruction of future: 51

### lightweight future promise:
Simple loop: 131                         - 137
Producer Consumer: 215 (5.04x faster)    - 209
  Creation and setting: 168                - 165
  Getting from future: 33                  - 32
  Destruction of future: 14                - 12
Three threads MPSC: 742 (2.39x faster)   - 929 (now doing genuine sleep waits)
  Creation: 360                            - 426
  Setting: 234                             - 344
  Getting from future: 83                  - 85
  Destruction of future: 66                - 73

### Dinkumware shared_future promise:
Simple loop: 543                         - 590
Producer Consumer: 1092                  - 1112
  Creation and setting: 600
  Getting from future: 208
  Destruction of future: 284

### lightweight shared_future promise:
Simple loop: 427                         - 564
Producer Consumer: 586 (1.86x faster)    - 751 (regression is from enable_shared_from_this)
  Creation and setting: 332                - 449
  Getting from future: 61                  - 66
  Destruction of future: 194               - 236

</center>
