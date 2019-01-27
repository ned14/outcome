+++
title = "`erased_status_result` and `erased_status_outcome`"
weight = 40
+++

`erased_status_result` and `erased_status_outcome` are also type aliases to {{< api "basic_result<T, E, NoValuePolicy>" >}}
and {{< api "basic_outcome<T, EC, EP, NoValuePolicy>" >}}, however they
alias a basic result or outcome with an `error_type` of `status_code<erased<E>>` instead
of `status_code<DomainType>`. You will remember from the introduction that erased status
codes are move-only.

The specifications are:

```c++
experimental::erased_result<T, E = experimental::system_code>
experimental::erased_outcome<T, E = experimental::system_code, EP = std::exception_ptr>
```

Which of the typed versus erased typed result or outcome you use depends on your
use cases. Outcome replicates faithfully the implicit and explicit conversion
semantics of its underlying types, so you can mix results and outcomes of
`<system_error2>` types exactly as you can the `<system_error2>` types themselves
e.g. typed forms will implicitly convert into erased forms if the source type
is trivially copyable or move relocating.

{{% notice note %}}
As `status_code<erased<T>>` is move-only, so is any `erased_result` or `erased_outcome`.
For some reason this surprises a lot of people, and they tend to react by not using the erased
form because it seems "difficult".
{{% /notice %}}

It is actually, in fact, a wise discipline to follow to make all functions return
move-only types if you care about determinism and performance. Whilst C++ 17 onwards
does much to have the compiler avoid copying of identical function return values thanks to
guaranteed copy elision, when a chain of functions return different types, if the
programmer forgets to scatter `std::move()` appropriately, copies rather than moves
tend to occur in non-obvious ways. No doubt future C++ standards will improve on the
automatic use of moves instead of copies where possible, but until then making all
your `result` and `outcome` types move-only is an excellent discipline.

Note that move-only `result` and `outcome` capable code also compiles fine when
`result` and `outcome` are copyable, albeit sometimes with a few compiler warnings
about unnecessary use of `std::move()`.
