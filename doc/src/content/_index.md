+++
title = "Home"
+++

# Outcome 2.2 library

{{% boost-copyright %}}

Outcome is a set of tools for reporting and handling function failures in contexts where *directly* using C++ exception handling is unsuitable. Such contexts include:

  - there are programs, or parts thereof, that are compiled with exceptions disabled;

  - there are parts of program that have a lot of branches depending on types of failures,
    where if-statements are cleaner than try-catch blocks;

  - there is a hard requirement that the failure path of execution should not cost more than the successful path of execution;

  - there are situations, like in the [`filesystem`](http://www.boost.org/doc/libs/release/libs/filesystem/doc/index.htm) library, where whether the failure should be handled remotely
    (using a C++ exception throw), or locally cannot be made inside the function and needs to be decided by the caller,
    and in the latter case throwing a C++ exception is not desirable for the aforementioned reasons;

  - there are parts of the program/framework that themselves implement exception handling and prefer
    to not use exceptions to propagate failure reports across threads, tasks, fibers, etc;

  - one needs to propagate exceptions through layers that do not implement exception throw safety;

  - there is an external requirement (such as a company-wide policy) that failure handling paths are explicitly indicated in the code.

  - where interoperation with C code, without having to resort to C++ exception wrapper shims, is important.

Outcome addresses failure handling through returning a special type from functions, which is able to store either a successfully computed value (or `void`), or the information about failure. Outcome also comes with a set of idioms for dealing with such types.

Particular care has been taken to ensure that Outcome has the lowest possible impact on build times,
thus making it suitable for use in the global headers of really large codebases. Storage layout is
guaranteed and is C-compatible for `result<T, E>`[^1], thus making Outcome based code long term ABI-stable.

{{% notice note %}}
Ben Craig's work on [P1886 *Error speed benchmarking*](https://wg21.link/P1886) has led to
a [`better_optimisation`](https://github.com/ned14/outcome/tree/better_optimisation) branch intended
to be merged end of 2020 as Outcome v2.2.0, after twelve months of testing. This branch has a number
of major changes to Outcome v2:

1. A new trait `is_move_bitcopying<T>` is added, which opts types into a library-based emulation of
[P1029 *move = bitcopies*](https://wg21.link/P1029). [Experimental `std::error`](https://wg21.link/P1028) is opted in by default.
If this trait is true for your `T` or `E` type, Outcome will track moved-from status for your type,
and will only call your type's destructor if it was not moved from. If your compiler's optimiser is
sufficiently able to fold code, this improves codegen quality for Experimental Outcome very considerably,
approaching the same gains as P1029 types would have. Note that the empirical performance difference
will likely be nil, but the codegen does look much more elegant.

2. If for `basic_result<T, E>` both `T` and `E` are trivially copyable, union-based rather than
struct-based storage will be used. This significantly improves performance in synthetic benchmarks
which do nothing in deep call stacks of function calls except create and return `result<T, E>`, and
makes Outcome return competitive results to alternative error handling choices, improving comparative
optics. It is not expected that the performance difference will be detectable empirically in real
world code. It is expected that the build time impact of union storage won't be noticeable, as
union storage for trivially copyable types is much easier than for non-TC types.

3. The compile time requirement for `E` types to have a default constructor is removed.

4. `OUTCOME_TRY(var, expr)` no longer always declares `var` as `auto &&var`, but simply uses it
as is. This allows `TRY` to initialise or assign. You can use the macro `OUTCOME21_TRY` if you
want the pre-Outcome v2.2 behaviour. You may find the regular expression `_TRY\((.*?),(.*?)\);` =>
`_TRY(auto &&\1,\2);` of use to you when upgrading code.
{{% /notice %}}

## Sample usage

The main workhorse in the Outcome library is `result<T>`: it represents either a successfully computed value of type `T`, or a `std::error_code`/`boost::system::error_code`[^2] representing the reason for failure. You use it in the function's return type:

{{% snippet "intro_example.cpp" "signature" %}}

It is possible to inspect the state manually:

{{% snippet "intro_example.cpp" "inspect" %}}

Or, if this function is called in another function that also returns `result<T>`, you can use a dedicated control statement:

{{% snippet "intro_example.cpp" "implementation" %}}

`OUTCOME_TRY` is a control statement. If the returned `result<T>` object contains an error information, the enclosing function is immediately returned with `result<U>` containing the same failure information; otherwise an automatic object of type `T`
is available in scope.

{{% notice note %}}
This library joined [the Boost C++ libraries](https://www.boost.org/doc/libs/develop/libs/outcome/doc/html/index.html) in the 1.70 release (Spring 2019). [It can be grafted into much older Boost releases if desired](https://github.com/boostorg/outcome).
{{% /notice %}}

[^1]: If you choose a C-compatible `T` and `E` type.

[^2]: `result<T>` defaults to `std::error_code` for Standalone Outcome, and to `boost::system::error_code` for Boost.Outcome. You can mandate a choice using `std_result<T>` or `boost_result<T>`.
