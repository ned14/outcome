# Frequently Asked Questions
\anchor faq

\warning This section is still a work in progress and may be out of date, incorrect or make no sense!

\section when_use When am I supposed to use what when?

The total available permutations provided by Outcome may seem overwhelming, because as with any
fundamental primitive the possibilities are endless. However, here are some quick notes
to help you decide what design pattern to use for your particular code base:

\subsection outcome_vs_result When should I use a result<T> instead of an outcome<T>?

`outcome<T>` has the potential to carry a `std::exception_ptr` which is implemented
by any STL I can think of as something very similar to a `std::shared_ptr` i.e. it
uses atomics to manage the reference count. Atomics are unavoidably a *compiler fence*
i.e. the compiler **must** emit code at the point of the fence. Outcome has been
very carefully written to let the compiler's optimiser *not* emit code thus leading
to its stellar low runtime overhead. Whilst recent versions of GCC and clang seem
reasonably good at eliding compiler fences caused by use of atomics in `std::exception_ptr`
when the compiler is absolutely sure that no `std::exception_ptr` can be transported,
where there is doubt the compiler has no choice but to generate a lot more assembler
to cover all the possible outcomes.
`result<T>` cannot transport a `std::exception_ptr` and therefore doesn't force the
compiler to generate output (except unfortunately on the Dinkumware STL where fetching
a STL error category e.g. `std::generic_category()` uses atomics).

So in short, always use `result<T>` instead of `outcome<T>` where doing so does not
impact negatively on your codebase, and remember one bit of your code can use
`result<T>` and another `outcome<T>` just fine.

\subsection result_vs_outcome When should I use an outcome<T> instead of a result<T>?

The main reason to use an `outcome<T>` is in the "sea of noexcept" design pattern
where implementations may throw exceptions internally, but all public extern APIs are always
noexcept. `outcome<T>` provides a lossless method of exporting the thrown exception
but without loading the programmer with dealing with unexpected control flow reversal,
thus helping the programmer write correct exception safe code faster.

One can implement the "exceptions are exceptional" design pattern easily with the standards proposed `expected<T, E>`:
expected errors are returned via `expected<T, E> = E` and aborting errors are returned via
an exception throw. However the role where using `outcome<T>` really shines is in the "exceptions
are exceptional" combined with "sea of noexcept" design pattern where the errored state
means an expected error which was handled inline, but the exceptioned state means an operation
was aborted, yet the programmer still can easily write exception safe forward-only-execution
code not having to worry about unexpected control flow inversion. This is where using Outcome
adds significant value over using Expected.

Finally, there is a third big reason to use Outcome. The main reason I designed and wrote
Outcome was to implement a universal error handling framework which could express *in the
minimum possible overhead*, and without losing information, the many C++ error handling design patterns possible, and even
more importantly that individual libraries could use the design pattern which best suited
them whilst seamlessly interoperating with other libraries using different error handling
designs. To go into a bit more detail:
* Proposed <a href="https://ned14.github.io/boost.afio/">Boost.AFIO v2</a> is a very low
level very thin file i/o and filesystem library which sits just above the raw kernel syscalls.
Throwing exceptions in such a library is overkill, so AFIO v2 uses the "sea of noexcept"
design pattern both in its public API and in its internal implementation (i.e. it doesn't
use C++ exceptions at all).
* Proposed <a href="https://github.com/ned14/boost.kerneltest">Boost.KernelTest</a> is a
kernel based testing infrastructure which uses Outcomes as the storage for each kernel
permutation run in its permutation tables of preconditions, postconditions, parameters
and outcomes. KernelTest itself is written using the
"exceptions are exceptional" design pattern where expected errors are returned via
outcomes but unexpected errors which abort the test use thrown exceptions which are
collected into `outcome<T>`'s. AFIO v2's test suite is written using KernelTest.
* Planned Boost.BLOBStore will be a versioned, ACID transactional key to BLOB store written
using AFIO v2 which will use both the "sea of noexcept" and the "exceptions are exceptional"
design patterns together. This allows user supplied callbacks to throw exceptions which aborts
the current transaction and for those exceptions to be propagated, if desired, out of BLOBStore
whilst the internal implementation of BLOBStore and indeed its public API is all noexcept
and never throws exceptions (writing correct filesystem code is hard enough without dealing
with unexpected control flow reversal). BLOBStore will also use KernelTest for its test suite.
