+++
title = "-- Now what happens?"
description = ""
weight = 28
+++

Let us run the code from the previous page:

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_error_code_enums2
Exception thrown was failure1
ned@lyta:~/outcome/build_posix$
```

Ah so now we are throwing a C++ exception on incorrect observation! This
is because we registered our error code enum with the C++ standard library
and in so doing, we also told the standard library how our error code
interacts with `std::error_code` and thus `std::system_error`.

Outcome's default action when incorrectly observing a `result` or `outcome`
with a `EC` type where `std::is_error_code_enum<EC>` is true, or
`std::is_error_condition_enum<EC>` is true, is to throw a 
`std::system_error(make_error_code(.error()))`. So because `.error()`
is set to `err::failure1`, the free function we defined `make_error_code(err)`
converts that into a `std::error_code`, and from that the `std::system_error`
is constructed and thrown.

On catching a `std::exception`, we print the `what()` which this particular
standard library implementation (libstdc++) has chosen to set to `error_code::message()`.