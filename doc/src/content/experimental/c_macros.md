+++
title = "C macro API"
weight = 50
+++

The C macro API permits C code to call C++ functions which return the subset
of possible {{< api "basic_result<T, E, NoValuePolicy>" >}} which are C-compatible,
so specifically:

1. `T` and `E` must be trivially copyable or move relocating[^1].
2. `T` and `E` must have standard layout[^2].

P1028 status code guarantees that it is both of the above if its domain's
`value_type` meets the above, which is the case for all of the status code
domains bundled with https://ned14.github.io/status-code/. Thus, if
you return from C++ a result which is wholly configured with C-compatible
types, C functions may return that result type.

The C macro API header `<outcome/experimental/result.h>` consists of these macros:

<dl>
<dt><code>CXX_DECLARE_STATUS_CODE(ident, value_type)</code>
<dd>Declares to C a status code type with domain <code>value_type</code>
available at the member variable <code>.value</code>. The <code>ident</code>
must be any identifier fragment unique in this translation unit. It is
used to uniquely identify this status code type in other macros.

<dt><code>CXX_STATUS_CODE(ident)</code>
<dd>A reference to a previously declared status code type with unique
<code>ident</code>.

<dt><code>CXX_DECLARE_RESULT(ident, T, E)</code>
<dd>Declares to C a <code>basic_result<T, E></code> type uniquely
identified by <code>ident</code>. <code>T</code> is available at the
member variable <code>.value</code>, and <code>E</code> is available
at the member variable <code>.error</code>.

<dt><code>CXX_RESULT(ident)</code>
<dd>A reference to a previously declared <code>result</code> type with
unique <code>ident</code>.

<dt><code>CXX_RESULT_HAS_VALUE(r)</code>
<dd>Evaluates to 1 (true) if the input <code>result</code> has a value.

<dt><code>CXX_RESULT_HAS_ERROR(r)</code>
<dd>Evaluates to 1 (true) if the input <code>result</code> has an error.

<dt><code>CXX_RESULT_ERROR_IS_ERRNO(r)</code>
<dd>Evaluates to 1 (true) if the input <code>result</code>'s error value
is a code in the POSIX <code>errno</code> domain.
</dl>

The above let you work, somewhat awkwardly, with any C-compatible
`basic_result<T, E>`. There is a high likelihood that C++ functions
regularly called by C code will return their failures in the `errno`
code domain, which is understood natively by C and can be compared
against, fed to `strerror()` and so on. Therefore there are
convenience macro APIs for that particular use case.

<dl>
<dt><code>CXX_DECLARE_RESULT_ERRNO(ident, T)</code>
<dd>Declares to C a <code>basic_result<T, posix_code></code>
type uniquely identified by <code>ident</code>.

<dt><code>CXX_RESULT_ERRNO(ident)</code>
<dd>A reference to a previously declared <code>basic_result<T, posix_code>></code>
type with unique <code>ident</code>.
</dl>
<br>

### Example of use

We first declare the `result` type returned by the C++ function `to_string()`,
and then the C++ function itself as an extern function (note the Itanium ABI
mangling).

{{< snippet "c_api.c" "preamble" >}}

As an example of using the C macro API:

{{< snippet "c_api.c" "example" >}}

And finally, if we run this test program:

{{< snippet "c_api.c" "test" >}}

The program outputs:

```
to_string(9) fills buffer with '9' of 1 characters
to_string(99) fills buffer with '99' of 2 characters
to_string(999) fills buffer with '999' of 3 characters
to_string(9999) failed with error code 105 (No buffer space available)
```


[^1]: As mentioned earlier, move relocating types are not in the standard. As currently proposed for standardisation, they would have the ability to *pass through* C code whereby it would be standards defined behaviour for a move relocating type to begin and end lifetime within C++, but spend some of its lifetime within C. In other words, C can safely bit-copy move relocating types, so long as the final destination returns to C++ so it can be destructed appropriately.

[^2]: Many C and C++ compilers waive the standard layout requirement for C and C++ interop, but standards conforming code should meet it.
