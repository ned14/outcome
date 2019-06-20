+++
title = "Extending `OUTCOME_TRY`"
description = "How to informing `OUTCOME_TRY` about foreign Result types."
tags = [ "TRY" ]
+++

Outcome's {{% api "OUTCOME_TRY(var, expr)" %}} operation is fully extensible
to accept as input any foreign types.
It already recognises types matching the {{% api "ValueOrError<T, E>" %}}
concept, which is to say all types which have:

- A public `.has_value()` member function which returns a `bool`.
- In order of preference, a public `.assume_value()`/`.value()` member
function.
- In order of preference, a public `.as_failure()`/`.assume_error()`/`.error()`
member function.

This should automatically handle `std::expected<T, E>` and many others.

`OUTCOME_TRY` has the following free function customisation points:

<dl>
<dt>{{% api "try_operation_has_value(X)" %}}
<dd>Returns a `bool` which is true if the input to TRY has a value.
<dt>{{% api "try_operation_return_as(X)" %}}
<dd>Returns a suitable {{% api "failure_type<EC, EP = void>" %}} which
is returned immediately to cause stack unwind. Ought to preserve rvalue
semantics (i.e. if passed an rvalue, move the error state into the failure
type).
<dt>{{% api "try_operation_extract_value(X)" %}}
<dd>Extracts a value type from the input for the `TRY` to set its variable.
Ought to preserve rvalue semantics (i.e. if passed an rvalue, move the value).
</dl>

The specialisations of these must be injected into the `OUTCOME_V2_NAMESPACE`.
Let us work through an applied example.

---
## A very foreign pseudo-Expected type

This is a paraphrase of a poorly written pseudo-Expected type which I once
encountered in the production codebase of a large multinational. Lots
of the code was already using it, and it was weird enough that it couldn't
be swapped out for something better easily.

{{% snippet "foreign_try.cpp" "foreign_type" %}}

What we would like is for new code to be written using Outcome, but be able
to transparently call old code, like this:

{{% snippet "foreign_try.cpp" "functions" %}}

Telling Outcome about this weird foreign Expected is straightforward:

{{% snippet "foreign_try.cpp" "tell_outcome" %}}

And now `OUTCOME_TRY` works exactly as expected:

{{% snippet "foreign_try.cpp" "example" %}}

... which outputs:

```
new_code(5) returns successful 5

new_code(0) returns failure argument out of domain
```
