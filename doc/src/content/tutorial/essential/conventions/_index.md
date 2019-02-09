+++
title = "Conventions"
description = "Why you should avoid custom `E` types in library code."
weight = 80
tags = [ "best-practice", "conventions", "idioms" ]
+++

You now know everything you need to get started with using Outcome
immediately.

The initial temptation for most beginners will be to use a bespoke
strongly typed enumeration on a case by case basis i.e. a "once off"
custom `E` type. This is usually due to experience in other languages
with sum types e.g. Rust, Haskell, Swift etc.

However this is C++! Not Rust, not Swift, not Haskell! I must caution you to always avoid using
custom `E` types in library code. The reason is that every time
library A using custom `E1` type must interface with library B
using custom `E2` type, you must map between those `E1` and `E2`
types.

This is information lossy, i.e. fidelity of failure gets lost
after multiple translations. It also involves writing, and then
*maintaining*, a lot of annoying boilerplate. It leaks internal
implementation detail, and fails to separate concerns.

All this may be acceptable in application code, but please avoid
doing this in library code. Moreover, the C++ 11 standard library
specifically ships `<system_error>` for the purpose of wrapping up
individual custom `E` types into a generic framework where disparate
custom `E` types can discover and interact with one another.
That ships with every C++ compiler. Please use it.

---

### tl;dr;

Please [plug your library into `std::error_code`]({{< relref "/motivation/plug_error_code" >}}),
or [equivalent]({{< relref "/experimental" >}}), and do not expose custom `E` types in ANY public API.
