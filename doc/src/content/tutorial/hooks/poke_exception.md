+++
title = "Custom exception ptr"
description = ""
weight = 40
+++

If you merely want `result` to capture stack backtraces without calling a memory allocator
and retaining any triviality of copy which is important for optimisation,
you already have everything you need.

But let's keep going by intercepting any
construction of our localised `outcome` from our localised `result`, retrieving any
stored backtrace and using it to synthesise an exception ptr with a message text
including the backtrace. Firstly let us look at the function which synthesises
the exception ptr:

{{% snippet "error_code_extended.cpp" "error_code_extended4" %}}

If the localised `outcome` being constructed is errored, try fetching the TLS slot
for the unique 16-bit value in its spare storage. If that is valid, symbolise the
stack backtrace into a string and make an exception ptr with a runtime error with
that string. Finally, override the payload/exception member in our just-copy-constructed
localised `outcome` with the new exception ptr.
