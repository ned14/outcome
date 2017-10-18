+++
title = "Hooking events"
description = "Intercepting useful events such as initial construction, copies and moves so you can capture backtraces, fire debug breakpoints etc."
weight = 50
+++

Outcome provides multiple methods for user code to intercept various events which occur.
The deepest is simply to inherit from `result` or `outcome` and override member functions.
Another possible option is to supply a custom `NoValuePolicy` (see next section).
The final option which this section covers is to use the ADL discovered event hooks
which tell you when a namespace-localised `outcome` or `result` has been:

- Constructed
  - `hook_result_construction(in_place_type_t<T|E>, result<T, E> *)`
  - `hook_outcome_construction(in_place_type_t<T|EC|EP>, outcome<T, EC, EP> *)`
- In-place constructed
  - `hook_result_in_place_construction(in_place_type_t<T|E>, result<T, E> *)`
  - `hook_outcome_in_place_construction(in_place_type_t<T|EC|EP>, outcome<T, EC, EP> *)`
- Copied
  - `hook_result_copy_construction(in_place_type_t<T|E>, result<T, E> *)`
  - `hook_outcome_copy_construction(in_place_type_t<T|EC|EP>, outcome<T, EC, EP> *)`
- Moved
  - `hook_result_move_construction(in_place_type_t<T|E>, result<T, E> *)`
  - `hook_outcome_move_construction(in_place_type_t<T|EC|EP>, outcome<T, EC, EP> *)`

One criticism often levelled against these success-or-failure objects is that they do
not provide as rich a set of facilities as C++ exception throws. This section shows
you how to configure Outcome using the ADL event hooks to take a stack backtrace on
construction of an errored `result<T, error_code>`,
and if that `result<T, error_code>` should ever be converted into an `outcome<T, error_code, std::exception_ptr>`,
a custom `std::exception_ptr` will be synthesised consisting of the `std::system_error`
for the error code, plus an expanded message string containing the stack backtrace of where
the error originally occurred.

