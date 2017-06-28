+++
title = "Home"
+++

# Outcome 2.0 library

{{<mermaid>}}
graph TD
    A1{"result#lt;T, E#gt;"} --"Success"--> B1["T value()"]
    A1 --"Failure"--> C1["E error()"]
    A2{"outcome#lt;T, EC, E|P#gt;"} --"Success"--> B2["T value()"]
    A2 --"Failure"--> C2["EC error()"]
    A2 --> D2(("Either"))
    D2 --"Abort"--> E2["E exception()"]
    D2 --"Payload"--> F2["P payload()"]
{{</mermaid>}}


This is the Outcome library. It is a C++ 14 library intended to aid ultra-lightweight
error handling in large C++ codebases, providing a more expressive and type safe
alternative to integer error codes or enums.

Unlike alternative implementations, it works perfectly with exceptions and RTTI
disabled and is thus suitable for low-latency/games/finance/SG14 users. One could
view Outcome as a minimum overhead universal outcome transport mechanism for C++,
hence being named "Outcome".

If you are familiar with Swift's error code throws or Rust's `Result<T, E>`,
you will find almost identical semantics in the transports provided here.
Outcome even has a `OUTCOME_TRY` macro doing most of the
`try` keyword in Rust and Swift!

{{% notice note %}}
This is the v2 Outcome designed in response to feedback from a [Boost peer review held in
May 2017](https://lists.boost.org/boost-announce/2017/06/0510.php). This library
is expected to pass a second Boost peer review, and be submitted to WG21 for standardisation
into the standard C++ library.
{{% /notice %}}

One motivation for this library is to manage errors reported by different means
using a single minimum overhead framework. This
motivating example should clarify:

{{% snippet "motivating_example.cpp" "motivating_example" %}}
