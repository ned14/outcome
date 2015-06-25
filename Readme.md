<center>
master branch unit test status:

Linux: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/) Windows: [![Build Status](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/badge/icon)](https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Win8%20VS2014/) Coverage: [![Coverage Status](https://coveralls.io/repos/ned14/boost.spinlock/badge.svg?branch=master)](https://coveralls.io/r/ned14/boost.spinlock?branch=master)

Documentation: https://ci.nedprod.com/job/Boost.Spinlock%20Test%20Linux%20GCC%204.8/doxygen/annotated.html

Boost review feedback work items:
 - [x] Documentation incorrectly says exceptions thrown are future_error when they are in fact monad_error.
 - [x] Add a tribool, and have monad return that instead of bool.
 - [x] In addition to value_or(), error_or() etc add value_and(), error_and() etc.
 - [x] Expose detail::value_storage such that it can be specialised for optimal space e.g. for bool.
 - [x] Add null_exception_ptr, null_error_code.
 - [x] Make how error_type is converted into exception_type configurable.
 - [x] Add monad<void>.
 - [x] Add template aliases for different configurations of monad<T> (one of maybe, result, holder, value, retval, potential, likely). Add two additional aliases, one for a monad without exception_ptr, and another for a monad with neither error_code nor exception_ptr (option<T>?).
 - [x] If monad type is a callable, let the monad be callable.
 - [x] Rename .then() to .next().
 - [x] Add match() function which visits a callable on the contents.
 - [x] Look into member operator overloads for bind() and map() e.g. monad<int> &m; auto r = m >> [](int a){return a;}; Can't use operator >>=() from Haskell as has same precedence to operator=().
 
</center>
