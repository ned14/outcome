# Frequently Asked Questions
\anchor faq


\section dontlike Hard coding error_code and exception_ptr is incredibly restrictive and ruins Outcome for me. Can you not do that please (i.e. make it more like expected<T, E> with its arbitrary type E)?

Outcome isn't a direct substitute for Expected per se. It can substitute for Expected's default
configuration of E = std::error_code and because it's less configurable and less flexible than
Expected, we can achieve much tighter assembler output by the compiler. It's a tradeoff - Outcome
imposes more restrictions but gives you faster, tighter, more predictable code. Expected is the
STL primitive useful for a wide variety of tasks, not just error handling.

One of the *huge* advantages of using `result<T>` in low latency code is precisely the hard coding
of error codes as the error type. Error codes have <a href="http://en.cppreference.com/w/cpp/language/destructor#Trivial_destructor">trivial destructors</a>,
and that means `result<T>` is trivially destructible i.e. the compiler's optimiser can assume that
any storage occupied by `result<T>` needs nothing doing to it when disposing of an instance.
That in turn allows the amazing folding up of long sequences of `result<T>` based operations by
the compiler's optimiser into zero assembler output. There is nothing stopping you using Expected
with its default error type of an error code which achieves much the same thing, but when you
allow programmers to modify the error type then you'll find programmers do so without realising
the consequences. In low latency SG14 type applications you need to **enforce** low latency best
practice in just the same way as such applications invariably globally disable C++ exceptions.
It's not that C++ exceptions are slow, it's rather if you give the programmers the freedom then
they'll use it. Take away that freedom, and they're write better domain specific code with fewer
surprises. This is the use case for Outcomes.

Furthermore, much of the opposition to the hard coded error type is due to not realising how
extended \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended" is.
Above and beyond the integer code and category that `error_code` provides, `error_code_extended`'s
constructor adds:
- Arbitrary `const char *` string describing the error specifically. This string is copied and
without allocating memory, so you can construct your specific description on the stack without
using memory allocation and feed it to a newly constructed extended error code again without
allocating memory. This makes error handling performance predictable.
- Two arbitrary unsigned integers. These could be fused into a `void *`, up to you.
- You can ask for a stack backtrace to be taken, thus allowing identification of what code sequence
resulted in the error. This also does not allocate memory and costs a maximum of about 35
microseconds on a fast Intel CPU if your stack down to seven levels deep is in warm cache.

To make using this extended functionality even easier, in the Quick start
synopsis you may have noticed that the `make_errored_*()` functions accept an optional `const char *`
string. This is simply fed to `error_code_extended`'s constructor. If Outcome ever converts a C++
exception into an error code for you e.g. through you using `BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT`,
the conversion always feeds the exception's `what()` as the extended string description so no
information is lost.

\warning The extended information is stored in a preallocated global threadsafe ringbuffer. It will get garbage
collected at some point when the ring buffer wraps. The garbage collection is not synchronised with
use of that data, so there is small chance that the extended data will get overwritten in mid use if
you leave it too long between the error code being created and making use of its extended data. You
should therefore endeavour to transfer the extended error code information into allocated memory
as soon as you practically can (or increase the size of the ring buffer, this is very easy, examine
the source code).


<hr><br>

\section custom_enum I want to use a custom enum as the error type, not an error_code!

C++ 11 already has you covered. The <a href="http://en.cppreference.com/w/cpp/error/error_code">`std::error_code`</a>,
<a href="http://en.cppreference.com/w/cpp/error/error_condition">`std::error_condition`</a> and 
<a href="http://en.cppreference.com/w/cpp/error/error_category">`std::error_category`</a> STL types
let you define a custom error code category for any custom enum or custom integer error code domain.


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

\section outcome_vs_result When should I use a result<T> instead of an outcome<T>?

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
`result<T>` because it'll auto upconvert to an `outcome<T>` when needed.


<hr><br>

\section result_vs_outcome When should I use Outcome instead of expected<T, E>?

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
