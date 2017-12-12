+++
title = "Custom payloads"
description = "Success-or-failure return types where extra information in addition to the error code accompanies failure."
weight = 30
+++

So far, type `EC` in `result<T, EC>` has always been a `std::error_code`. But it need
in fact to merely satisfy `trait::has_error_code_v<EC>` for `EC` to be treated as a
`std::error_code`.

In turn, `trait::has_error_code_v<EC>` is true if there exists some ADL discovered free
function:

1. `make_error_code(EC)` returning a `std::error_code`.
2. `make_error_code(std::get<0>(EC))` returning a `std::error_code` (i.e. EC might be
`std::pair<std::error_code, U>` or `std::tuple<std::error_code, ...>`).

... or if `EC` is implicitly convertible into a `std::error_code`.

Thus, we can in fact use any custom `EC` type we like, including one carrying additional
information, or *payload*. This payload can carry anything you like, and you can tell
Outcome to do various things with that payload under various circumstances. For example:

1. If the user tries to observe an unsuccessful `result`, throw a custom exception
containing the cause of failure with accompanying context from the payload.
2. If the user ever constructs an `outcome` from a payload carrying `result`,
set the exception ptr in the constructed `outcome` to a custom exception
containing the cause of the failure with accompanying context from the payload.
3. Transmit a stack backtrace specifying the exact point at which failure occurred,
symbolising that into human readable text at the moment of conversion into human
readable text.
4. Upon a namespace-localised `result` from library A being copy/moved into a
namespace-localised `result` from C bindings library B, set the C `errno` if
the error code and category map onto the `errno` domain.

There are many, many other options of course. This tutorial can only cover a
reasonable subset. This section covers Example 1 above, throwing custom exceptions
with payload upon observation of an unsuccessful `result`.
