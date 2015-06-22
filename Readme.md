<center>
master branch unit test status:

Linux: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/) Windows: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.spinlock/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.spinlock?branch=master)

Documentation: https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/doxygen/annotated.html

Boost review feedback work items:
 - [ ] Add template aliases for different configurations of monad<T> (one of maybe, result, holder, value, retval, potential, likely). Add two additional aliases, one for a monad without exception_ptr, and another for a monad with neither error_code nor exception_ptr (option<T>?).
 - [ ] Make how error_type is converted into exception_type configurable.
 - [ ] As .then() is defined in a future as executing the callable when the value is set, and monad<T>.then() executes immediately and does not execute when the value is next changed, does this make monad<T>.then() deceptively named? (I think yes). Perhaps next() is a better name for then()? What about simply operator() i.e. make the monad callable?
 - [ ] Add match() function which visits a callable on the contents.
 
</center>
