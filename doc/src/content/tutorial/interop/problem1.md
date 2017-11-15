+++
title = "Incommensurate E types"
weight = 5
+++

Back in the tutorial section on Default Actions, we studied a likely very common
initial choice of `E` type: [a strongly typed enum](../../default-actions/enums).
We saw how by marking up strongly typed enums to tell the C++ standard library
what they are, they gain implicit convertibility into `std::error_code`, and we
then pointed out that you might as well now set `E = std::error_code` as that
comes with the enormous advantage that you can use the boilerplate saving
`OUTCOME_TRY` macro when the `E` type is always the same.

We thus strongly recommend to users that for any given piece of code, always
using the same `E` type across the codebase is very wise, except where you explicitly want
to prevent implicit propagation of failure up a call stack e.g. local failures in
some domain specific piece of code.

However it is unreasonable to expect that any non-trivial codebase can make do
with `E = std::error_code`. This is why Outcome allows you to use [custom `E`
types which carry payload](../../payload) in addition to an error code, yet
still have the Default Actions of `std::error_code`, including [lazy custom exception
throw synthesis](../../payload/copy_file3).

All this is good, but if library A uses `result<T, libraryA::failure_info>`
and library B uses `result<T, libraryB::error_info>` and so on, there becomes
a problem for the application writer who is bringing in these third party
dependencies and tying them together into an application.

Does the application writer have to wrap every call to a third party library
in a macro which translates the library-specific failure into something that
the application understands? Pretty much, yes they do. At least if the third
party library uses Outcome, calling `.value()` may throw a third party library
specific C++ exception type, which forces the exception handling part of the
application to become aware of the C++ exception types throwable by the third
party libraries in use. This may not be desirable, either.

Things get even more complication in the presence of callbacks. If in the
callback you supply to library A, you call library B, you may need to insert
switch statement maps or other mechanisms to convert library B's failures into
something library A can understand, and then somehow extract that out -- preferably
without loss of original information -- into the application's failure handling
mechanism if library A subsequently returns failure as well.

There is also a huge ecosystem of code out there which does not use a `T|E`
return mechanism. Let us look at some common design patterns next.
