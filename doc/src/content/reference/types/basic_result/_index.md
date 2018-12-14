+++
title = "`basic_result<T, E, NoValuePolicy>`"
description = "A sum type carrying either a successful `T`, or a disappointment `E`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there."
+++

A sum type carrying either a `T` or an `E`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there. Either or both of `T` and `E` can be `void` to indicate no value for that state is present.

*Requires*: Concept requirements if C++ 20, else static asserted:

- That trait {{% api "type_can_be_used_in_basic_result<R>" %}} is true for both `T` and `E`.
- That either `E` is `void` or `DefaultConstructible`.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/basic_result.hpp>`

*Inclusions*: The very lightest weight of C and C++ header files:

1. `<cstdint>`
2. `<initializer_list>`
3. `<iosfwd>`
4. `<new>`
5. `<type_traits>`
6. `<utility>` (C++ 17 or later only, for {{% api "std::in_place_type_t<T>" %}})
7. If C++ exceptions disabled and `OUTCOME_DISABLE_EXECINFO` undefined only (used to print stack backtraces on "exception throw"):
    1. `<sal.h>` (Windows only)
    2. `<stddef.h>` (Windows only)
    3. `<string.h>` (Windows only)
    4. `<execinfo.h>` (POSIX only)
8. `<cstdio>`
9. `<cstdlib>`
10. `<cassert>`

This very light weight inclusion dependencies makes basic result suitable for use in global header files of very large C++ codebases.

*Design rationale*: The basic result type is the main workhorse type of the Outcome library, providing a simple sum type with optional values representing success or disappointment. Unlike {{% api "std::expected<T, E>" %}}, Outcome's result type is designed specifically for convenience when implementing failure handling, and it has a number of API differences to facilitate that.

The first major design difference is that basic result models its constructor design on {{% api "std::variant<...>" %}}, rather than modelling {{% api "std::optional<T>" %}}'s constructor design like `std::expected<T, E>` does. This means that basic result will implicitly construct either a `T` or an `E` if doing so is unambiguous, same as `variant` does. Where implicit construction is ambiguous, the implicit constructors disable and a `T` or `E` can be specified via {{% api "in_place_type_t<T>" %}}, or via {{% api "success_type<T>" %}} or {{% api "failure_type<T>" %}}.

The second major design difference is that union storage is NOT used, as it is assumed that `sizeof(E)` will be small for failure handling. This very considerably reduces load on the compiler, and substantially improves compile times in very large C++ codebases.

{{% children description="true" depth="2" %}}
