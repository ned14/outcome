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
 - [ ] Document synchronisation APIs in promise future.
 - [ ] Audit all unlocked state reads with writes for raciness.
 - [ ] Implement N4399 continuations.
 - [ ] wait() should sleep the thread as necessary.
 - [ ] Implement wait_for()/wait_until().
 - [ ] when_any/when_all composure.

Later:
 - [ ] Add monad_errc error code for when a move or copy constructor throws? If so, what about option<T>?
 - [ ] Have basic_monad gain an explicit conversion constructor from other basic_monad with different
implementation policies such option can convert to result or monad and so on. Look into having the
implementation policies themselves do the conversion, so some template alias e.g. convert<>().
 - [ ] Lightweight packaged_task? I think an intrusive design like AFIO's enqueued_task makes for a
far more efficient implementation. Maybe try relocating AFIO's enqueued_task into a lightweight
packaged_task design?
 - [ ] option<bool> et al should really be 1 byte storage, not 2 bytes.
 - [ ] Use of reinterpret_cast to implement future => shared_future is naughty and should be done properly.


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
Simple loop: 545
Producer Consumer: 1084
  Creation and setting: 587
  Getting from future: 215
  Destruction of future: 281
Three threads MPSC: 1772
  Creation: 888
  Setting: 534
  Getting from future: 300
  Destruction of future: 51

### lightweight future promise:
Simple loop: 131
Producer Consumer: 215 (5.04x faster)
  Creation and setting: 168
  Getting from future: 33
  Destruction of future: 14
Three threads MPSC: 742 (2.39x faster)
  Creation: 360
  Setting: 234
  Getting from future: 83
  Destruction of future: 66

### Dinkumware shared_future promise:
Simple loop: 543
Producer Consumer: 1092
  Creation and setting: 600
  Getting from future: 208
  Destruction of future: 284

### lightweight shared_future promise:
Simple loop: 427
Producer Consumer: 586 (1.86x faster)
  Creation and setting: 332
  Getting from future: 61
  Destruction of future: 194

</center>
