+++
title = "Home"
+++

# Outcome 2.0 library

Outcome is a C++14 library for reporting and handling function failures
in contexts where using C++ exception handling is unsuitable.

The reasons for not using exceptions may be different:

   - The high relative cost of throwing and catching a C++ exception,
   - Making some or all control paths explicitly detailed to aid code correctness auditing,
     as opposed to having hidden control paths caused by exceptions potentially thrown from any place,
   - Company's policy to compile with exceptions disabled,
   - Maintaining a code base that was never designed with exception-safety in mind,
   - Parts of the programs/frameworks that themselves implement exception handling and cannot
     afford to use exceptions, like propagating failure reports across threads, tasks, fibers...
   
Outcome can also be used to plug components that potentially throw exceptions into parts of the program
that are not exception-safe while retaining all information from the thrown exception objects.

## Sample usage

Function that may need to report failure needs to reflect that in its return type:

{{% snippet "intro_example.cpp" "signature" %}}

Function `read_int_from_file` will either return an `int` or information about 
the reason for failure.

It is possible to inspect the returned state manualy:

{{% snippet "intro_example.cpp" "inspect" %}}

But most of the time you would inspect the object indirectly through a dedicated control statement. An implementation of `read_int_from_file` that has to (1) open the file, (2) read raw data to a buffer, and (3) interpret it as `int`, using the following three functions

{{% snippet "intro_example.cpp" "aux_signatures" %}}

will look like this:

{{% snippet "intro_example.cpp" "implementation" %}}

Each occurence of `OUTCOME_TRY` is a control statement. If the returned `result<T>` contains an error information, the function is immediatelly returned with `result<U>` containing the same error information; otherwise object of type `T` is move-constructed on the stack.

{{% notice note %}}
This is the v2 Outcome designed in response to feedback from a [Boost peer review held in
May 2017](https://lists.boost.org/boost-announce/2017/06/0510.php). This library
is expected to pass a second Boost peer review, and be submitted to WG21 for standardisation
into the standard C++ library.
{{% /notice %}}
