# Frequently Asked Questions
\anchor faq

<hr><br>

\section error_chains How do I implement chains of errors to transport errors happening whilst handling another error?

C++ 11 already has you covered. <a href="http://en.cppreference.com/w/cpp/error/nested_exception">`std::nested_exception`</a>
lets you nest exceptions of arbitrary types within each other. It returns a standard `std::exception_ptr`
so Outcome won't even know.

If that's too heavyweight for you, \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended"
lets you attach an arbitrary pointer (via two unsigned integers) to an error code. You could use this to
chain error codes, though note that the extended error code information can be garbage collected at any time
so you'll need your own method of cleaning up. 


<hr><br>

\section outcome_vs_result If outcome<T> is a strict superset of result<T>, why ever use result<T>?

`outcome<T>` has the potential to carry a `std::exception_ptr` which is implemented
by any STL I can think of as something very similar to a `std::shared_ptr` i.e. it
uses atomics to manage the reference count, and requires a non trivial destructor. Atomics are unavoidably a *compiler fence*
i.e. the compiler **must** emit code at the point of the fence. Outcome has been
very carefully written to let the compiler's optimiser *not* emit code whenever possible. Whilst recent versions of GCC and clang seem
reasonably good at eliding compiler fences caused by use of atomics in `std::exception_ptr`
when the compiler is absolutely sure that no `std::exception_ptr` can be transported,
where there is doubt the compiler has no choice but to generate a lot more assembler
to cover all the possible outcomes because any potential use of an atomic forces the
emission of all code which could affect memory.
`result<T>` cannot transport a `std::exception_ptr` and therefore doesn't force the
compiler to generate output (except unfortunately on the Dinkumware STL where fetching
a STL error category e.g. `std::generic_category()` uses atomics).

So in short, always use `result<T>` instead of `outcome<T>` where doing so does not
impact negatively on your codebase.


<hr><br>

\section examples_of_use Are there some real world code bases using Outcome I can study?

The main reason I designed and wrote
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
