+++
title = "Mapping the HTTP library into the Application 2/2"
weight = 35
+++

If you remember the tutorial section on the [`ValueOrError` Concept](../../value-or-error),
this is an example of how to implement a custom `ValueOrError` Concept converter
in Outcome:

{{% snippet "finale.cpp" "app_map_httplib2" %}}

The first thing that you should note is that these custom converters must be injected
directly into the `OUTCOME_V2_NAMESPACE::convert` namespace, and they must partially
or completely specialise `struct value_or_error<DEST, SRC>`.

The second thing to note is that you need to set `enable_result_inputs` and `enable_outcome_inputs`
appropriately. The reason that these are here is because of a chicken-or-egg problem
whereby the `ValueOrError` infrastructure needs to be defined before `result` can be defined, and
we also wish to permit inclusion of `result` without needing to include `outcome`.
So this is a slightly irritating workaround, but one with low impact.

The third thing to note is the SFINAE on `operator()`. If the SFINAE fails, the `ValueOrError`
converting constructor disables. Obviously, if you are using Concept requirements,
that works too. Note the requirement that SFINAEd `X` matches `httplib::result<U>`, and that
`T` is constructible from `U`.

If `operator()` is available, it naturally converts a `httplib::result<U>` into an
`app::outcome<T>` by either forwarding any success as-is, or calling `app::make_httplib_exception()`
to type erase the `httplib::failure` into an `app::httplib_error`.