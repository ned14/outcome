+++
title = "Home"
+++

# Outcome 2.1 library

{{% boost-copyright %}}

Outcome is a set of tools for reporting and handling function failures in contexts where using C++ exception handling is unsuitable. Such contexts include:

  - programs, or parts thereof, that are compiled with exceptions disabled;

  - parts of program that have a lot of branches depending on types of failures,
    where if-statements are cleaner than try-catch blocks;

  - requirement that failure path of execution should not cost more than the successful path of execution;

  - situations, like in [`filesystem`](http://www.boost.org/doc/libs/release/libs/filesystem/doc/index.htm) library, where the decision whether the failure should be handled remotely
    (use exceptions) or locally cannot be made inside the function and needs to be moved onto the caller,
    and in the latter case launching stack unwinding is not desirable for the aforementioned reasons;

  - parts of the programs/frameworks that themselves implement exception handling and prefer
    to not use exceptions to propagate failure reports across thread, tasks, fibers;

  - propagating exceptions trough layers that do not implement exception throw safety;

  - external requirement (such as company-wide policy) that failure handling paths are explicitly indicated in the code.

Outcome addresses failure handling through returning a special type from functions, which is able to store either a successfully computed value (or `void`) or the information about failure. Outcome also comes with a set of idioms for dealing with such types.


## Sample usage

One of the tools in the Outcome library is `result<T>`: it represents either a successfully computed value of type `T` or an `std::error_code` representing the reason for failure. You use it in the function's return type:

{{% snippet "intro_example.cpp" "signature" %}}

It is possible to inspect the state manually:

{{% snippet "intro_example.cpp" "inspect" %}}

Or, if this function is called in another function that also returns `result<T>` you can use a dedicated control statement:

{{% snippet "intro_example.cpp" "implementation" %}}

`OUTCOME_TRY` is a control statement. If the returned `result<T>` object contains an error information, the enclosing function is immediately returned with `result<U>` containing the same failure information; otherwise an automatic object of type `T`
is available in scope.

{{% notice note %}}
This is the v2 Outcome designed in response to feedback from a [Boost peer review held in
May 2017](https://lists.boost.org/boost-announce/2017/06/0510.php). This library has successfully passed the second Boost peer review, and is currently expected to become part of the Boost official release distribution before the 1.70 release (Spring 2019).
{{% /notice %}}
