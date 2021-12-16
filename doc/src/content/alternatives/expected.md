+++
title = "C++ expected"
description = "How `std::expected<T, E>` compares to Outcome"
weight = 30
+++

`std::expected<T, E>` came originally from an experimental monadic and generic programming library outside of Boost written by Boost and WG21 developers around 2013. Before Outcome v1, I deployed the then Expected into a large codebase and I was dismayed with the results, especially on build times. [You can read here how those experiences led me to develop Outcome v1]({{% relref "/history" %}}).

`std::expected<T, E>` is a constrained variant type with a strong preference for the successful type `T` which it models like a `std::optional<T>`. If, however, there is no `T` value then it supplies an 'unexpected' `E` value instead. `std::expected<T, E>` was standardised in the C++ 20 standard.

Outcome's Result type [can be configured to act just like Expected if you want that]({{% relref "/faq#how-far-away-from-the-proposed-std-expected-t-e-is-outcome-s-checked-t-e" %}}), however ultimately [Outcome's Result doesn't solve the same problem as Expected]({{% relref "/faq#why-doesn-t-outcome-duplicate-std-expected-t-e-s-design" %}}), plus Outcome models `std::variant<T, E>` rather than `std::optional<T>` which we think much superior for many use cases:

- If you are parsing input which may rarely contain unexpected values, Expected is the right choice here.

- If you want an alternative to C++ exception handling i.e. a generalised whole-program error handling framework, Expected is an inferior choice to alternatives.


Pros:

- Predictable runtime overhead on the happy path.

- Very little bloat added to binaries.

- Variant storage means storage overhead is minimal, except when either `T` or `E` has a throwing move constructor which typically causes storage blowup.

- Works well in all configurations of C++, including C++ exceptions and RTTI globally disabled.

Cons:

- Predictable runtime overhead on the sad path.

- Success-orientated syntax makes doing anything with the `E` type is awkward and clunky.

- Results in branchy code, which is slow -- though predictably so -- for embedded controller CPUs.

- Lack of a `try` operator makes use tedious and verbose.

- Variant storage does have an outsize impact on build times in the same way widespread use of `std::variant` has. This is because implementing exception guarantees during copies and moves of non-trivially-copyable types in union storage involves a lot of work for the compiler on every use of copy and move.
