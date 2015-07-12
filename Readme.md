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
 - [x] Document synchronisation APIs in promise future.
 - [x] Audit all unlocked state reads with writes for raciness.
 - [x] Refactor the tribool logic mapping such that empty => unknown.
 - [x] Implement N4399 continuations for future.
 - [x] Use of reinterpret_cast to implement future => shared_future is naughty and should be done properly.
 - [x] Have basic_monad gain an explicit conversion constructor from other basic_monad with different
implementation policies such that compatible monads can convert into one another.
 - [x] wait() should sleep the thread as necessary.
 - [x] Split implementation policy for value_storage into separate policy (allows value_storage
to convert without considering future-promise type).
 - [x] Get value_storage<bool> and value_storage<void> to consume 1 byte, not 2 bytes.
 - [x] Fix future operator= and move constructor being racy by placing a locker type at the top of the hierarchy
and an unlocker type at the bottom of the hierarchy.
 - [x] Move value_storage into basic_promise_future_base and separate pointer into a union.
 - [x] typedef basic_future_base and basic_promise_base to a basic_promise_future_base.
 - [x] Now value_storage for both promise and future is visible to both, eliminate vptr.
 - [x] Relocate continuation_future * into basic_promise_future_base so future can build it and promise
can execute it. Also relocate sleeping_waiters.
 - [x] Relocate enable_shared_from_this into basic_future. This should be safe now no type slicing
is done.
 - [x] Fix failing constexpr test min_promise_future_reduce.
 - [x] Implement N4399 continuations for shared_future.
 - [ ] Implement wait_for()/wait_until().
 - [ ] when_any/when_all composure.
 - [ ] Port AFIO's intrusive enqueued_task into a lightweight packaged_task design.

Later:
 - [ ] Loosen explicit basic_monad constructors to allow option => result => monad implicitly, and
monad => result => option explicitly (with potential exception throwing).
 - [ ] Pack bools in basic_promise_future_storage into value_storage_impl, thus saving 8 bytes
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
