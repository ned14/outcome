+++
title = "Custom error codes"
description = "Illustrates how you can hook into the std::error_code system from the Standard Library in order to work with your own set of error codes."
weight = 91
+++


This section illustrates how you can hook into the `std::error_code` system from
the Standard Library in order to work with your own set of error codes. As is usually
the case in C++, doing this is straightforward but requires typing boilerplate
to tell the C++ STL about your custom error type. This is not part of Outcome library, 
but we still provide this short guide here, because how to do this is not well documented [1].

Suppose you want to report all reasons for failure in conveting an `std::string` to a non-negative `int`.
The list is:

* `EmptyString` -- the input string is empty,
* `IllegalChar` -- input contains characters that are not digits,
* `TooLong` -- input represents a number, but this number would not fit into a variable of type `int`.

{{% snippet "error_code_registration.cpp" "error_code_registration" %}}

This might look like a lot of extra boilerplate over simply using your custom
error code enum directly, but look at the advantages:

1. Any code which can speak `std::error_code` can now work with errors from your
   code, AND without being recompiled.
2. `std::system_error` can now wrap your custom error codes seamlessly, allowing
   your custom error code to be converted into a C++ exception *and back out again*
   without losing information.
3. `std::error_code` knows how to print itself, and will print your custom error
   code without extra work from you. As usually you'd need to define a print routine
   for any custom error code you'd write anyway, there is actually very little extra
   boilerplate here.
4. If you implement the `default_error_condition()` override, you can allow code
   exclusively written to understand `std::errc` alone to examine your custom error
   code domain for equivalence to the standard error conditions, AND without being
   recompiled.

[1]: The only documentation I'm aware of is the quite old guide by Chris Kohlhoff, founder of
ASIO and the Networking TS:

- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-1.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-2.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-3.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-4.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-5.html