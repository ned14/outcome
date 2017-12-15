+++
title = "Limitations"
description = ""
weight = 10
+++

C++ has excellent two-way compatibility with the C ABI, but there are some
limitations you must observe to write C++ code which C code can call without
marshalling at the ABI boundary:

1. A C++ function may not throw exceptions if it is safe to call from C, and
so should always be marked `noexcept`.
2. A C++ function should be annotated with `extern "C"` to prevent its symbol
being mangled, and thus give it the C rather than C++ ABI.
3. You cannot use overloading in your `extern "C"` functions.
4. You may only use types in your C++ function for which these traits are both true:
  - [`std::is_standard_layout_v<T>`](http://en.cppreference.com/w/cpp/types/is_standard_layout)
  - [`std::is_trivially_copyable_v<T>`](http://en.cppreference.com/w/cpp/types/is_trivially_copyable)
  - Note that `std::is_trivially_copyable_v<T>` also requires trivial destruction, but NOT trivial construction.
This means that C++ can do non-trivial construction of otherwise trivial types.
5. Your C++ function should return either a `result<T, E>` or a `result<T>` i.e. with the `EC` defaulted
to `std::error_code` or something with equal layout. Note that `std::error_code`
has standard layout, and is trivially copyable, and thus is a legal type in C.

These type limitations might seem to be showstoppers to C++ programmers, but with a bit of
care during library design, you can actually express a lot of
complex C++ and still meet these requirements. For example, more than 80%
of the APIs in my C++ 17 [AFIO](https://ned14.github.io/afio/) library (which I hope to propose
in 2018 to become the File I/O TS for C++ 24) meets the above restrictions,
and thus can be called directly from C code or any programming language which
speaks the C ABI.

A useful tip is to sprinkle `static_assert()` testing the two traits above around your header files for any types which
can traverse the C ABI boundary, and add `extern "C"` free function thunks for your class
member functions[^1]. You should be ready to go from the C++ side at least.

[^1]: Or simply write a script to do this for you. A starter script can be found at https://github.com/ned14/afio/blob/master/scripts/make_free_functions.py.
