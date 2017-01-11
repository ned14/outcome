


As the following section will contain a lot of new content for most readers including
mention of features coming to C++ 20

\subsection relation-to-cpp17 A small bit of detail before resuming the tutorial

We are finally onto Outcome! 95% of users will not need to know nor care about this,
but readers should be aware (so they know what a debugger is showing them when debugging
code using Outcome [1]) that Outcome is implemented as the policy driven utility class
\ref boost::outcome::v1_xxx::basic_monad "basic_monad<>". The policy supplied has wide
latitude to affect the semantics of the monad, but the policy this tutorial will cover is one
which closely matches `basic_monad<>`'s semantics to the C++ 17/20 utility classes
`std::optional<T>` and `std::experimental::expected<T, E>` (this hasn't been approved
yet by ISO WG21, but it's very close, likely later in 2017). As a quick summary of what
these C++ 17/20 utility classes (will) do:

<dl>
  <dt><a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a></dt>
  <dd>Utility class managing an optional contained value i.e. a value which may or may
  not be present.</dd>
  <dt><a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">`std::experimental::expected<T, E>` (P0323R1)</a></dt>
  <dd>Utility class managing one of three variant states, an expected `T` or an unexpected `E`
  or no value (with the no value semantics matching <a href="http://en.cppreference.com/w/cpp/utility/variant">std::variant<...></a>).</dd>
</dl>

Outcome's near equivalents for these are supersets of the C++ standard utility classes
adding monadic semantics (see \ref advanced), but also with some minor semantic
differences made for the purposes of improved performance and suitability for high performance/low
latency/gaming/trading applications as per <a href="https://github.com/WG21-SG14">WG21 SG14</a>'s mandate.
For a detailed list of the exact semantic differences see \ref std-expected.

The `basic_monad<>` policy this tutorial covers takes this form:
~~~{.cpp}
template<
  class monad_storage,
  class value_type,
  class error_type,
  class exception_type>
struct BOOST_OUTCOME_MONAD_POLICY_BASE_NAME : public monad_storage
{ ... };
~~~
This policy implements variant storage of `value_type`, `error_type` and `exception_type`.
You can use any type `error_type` or `exception_type` you like so long as they act as if a `std::error_code`
and a `std::exception_ptr` respectively e.g. `boost::error_code` and `boost::exception_ptr`.
**Unlike** the `E` in `expected<T, E>`, Outcome hard codes the model of `error_type` and `exception_type` in stone,
so they *must* provide at least the same APIs and behaviours as an error code and an
exception pointer or be `void`, in which case the specialisation doesn't provide the ability
to store an instance of that type. You cannot use a `value_type`, an `error_type` or an `exception_type`
which are constructible into one another.

[1]: Outcome provides a debugging visualiser for Microsoft Visual Studio such that any
`basic_monad<>` displays itself without any internal clutter. Just link into your final binary
the `monad.natvis` file.

\subsection easy_usage Ach my head is hurting, make this easier!

As mentioned earlier, 95% of Outcome's users won't need to know the above because they
will be using these convenience typedefs in their code:
~~~{.cpp}
template<class T> using outcome = basic_monad<  monad_policy<T, std::error_code, std::exception_ptr> >;
template<class T> using result  = basic_monad< result_policy<T, std::error_code, void> >;
template<class T> using option  = basic_monad< option_policy<T, void, void> >;
~~~


\subsection cpp17-stl Standardised optional<T> and expected<T, E>
There are useful improvements coming in C++ 17/20 with which one can implement some
new error handling design patterns in addition to those already covered above:
<dl>
  <dt><a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a></dt>
  <dd>Utility class managing an optional contained value i.e. a value which may or may
  not be present.</dd>
  <dt><a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">`std::experimental::expected<T, E>` (P0323R1)</a></dt>
  <dd>Utility class managing one of three variant states, an expected `T` or an unexpected `E`
  or no value (with the no value semantics matching <a href="http://en.cppreference.com/w/cpp/utility/variant">std::variant<...></a>).</dd>
</dl>

Outcome provides convenience typedefs which map \ref boost::outcome::v1_xxx::basic_monad "basic_monad<>"
as close as is feasible onto the standard utility classes:
- `BOOST_OUTCOME_V1_NAMESPACE::option<T>` => `std::optional<T>`
- `BOOST_OUTCOME_V1_NAMESPACE::result<T>` => `std::experimental::expected<T, E = std::error_code>`
- `BOOST_OUTCOME_V1_NAMESPACE::outcome<T>` => no longer any equivalent in the STL
  - but in an earlier proposal for Expected it would have been `std::experimental::expected<T, E = std::experimental::expected<T = std::error_code, E = std::exception_ptr>>`
  i.e. either an expected `T` or an unexpected `std::error_code` or a really unexpected `std::exception_ptr`.

In 95% of use cases, Outcome's convenience typedefs should be typedef-swappable for `optional<T>`
and `expected<T, E>`, and Outcome has been carefully designed to maximise this.
There are some important semantic differences though, for those interested please see \ref std-expected
for lots of detail. In summary, Outcome is intended as an *ultra lightweight universal 
error handling framework* which lets you the programmer seamlessly transport error states
around without adding any extra overhead nor losing any information, folding everything into
C-style returns of some `basic_monad<>` implementation.
It therefore has a different intent and purpose than Expected which is more of a general
purpose building block primitive intended for much more general (i.e. unknown) use cases than Outcome.

Outcome takes absolute minimum runtime overhead unusually seriously, and generates exceptionally tight code
with recent versions of GCC and clang which a design making more use of potential exception
throws currently can not achieve with current compiler optimiser technology.
To achieve its ultra lightweightness, Outcome is written to enable as much as possible current compiler
optimisers to deduce when to elide the underlying variant storage used by `basic_monad<>`
such that if you do `return outcome<int>(5);` then the compiler generates code exactly as if
you wrote `return 5;` i.e. Outcome disappears entirely from the assembler generated.
And this is not some vague aspiration: Outcome's unit test suite actually tests that outcomes
vanish from runtime overhead per commit.
To achieve this with current optimiser technologies, it needs to be implemented less branchy 
and with a formal constexpr empty state to avoid the potential `valueless_by_exception` state
that `expected<T, E>` requires. Another big goal for Outcome is that it works perfectly with
C++ exceptions and RTTI disabled so it is useful for high performance/gaming/finance applications
such as those studied by ISO WG21 SG14. In fact, it is intended to submit Outcome to SG14 for
standardisation as the low latency/high performance friendly close alternative to `expected<T, E>`.

Whether you choose in your own code to use Outcome or the C++ 17/21 STL is up to you, and there
are pro and cons to choosing either. The rest of this tutorial will focus on Outcome
of course, but please do bear in mind that any of the design patterns mentioned during the
remainder of this tutorial can be implemented almost as easily using `expected<T, E>` and
`variant<...>` as using Outcomes. I think you'll find Outcomes are more convenient to use
for error handling, but it wouldn't require you writing much additional macro and type boilerplate to use
Expected and Variant just as easily as your base transports.

\subsection outcome_example Example function using Outcome's result<T>




\subsection examples Examples of usage

The above synopsis of Outcome looks lengthy and complex, but almost all of it is
convenience overloads of one form or other. In usage Outcome is generally "stupid easy"
to program with, especially if you're already used to `std::optional`. Here is a real
world use case distilled from AFIO v2's source code:

\snippet usecase_example.cpp file_create_example

\todo Add link to whole source code in an online compiler explorer so end users can
play with the use case

Unlike the earlier example functions opening a file, the above is not a toy use case
and it covers almost all of the permutations of creating or opening a file which are
common to POSIX and Windows. We make use of the fact that `basic_monad<>``::``value()`
returns a non-const lvalue ref when the monad instance is a non-const stack allocated
instance, binding it to the convenience lvalue ref `nativeh` which points at a union
containing the `HANDLE` later filled with the opened handle.

We make use of `BOOST_OUTCOME_TRY(var, expr)` which is a macro expanding to:

\code
  auto &&unique = (expr);                                  // "unique" is a preprocessor generated unique temporary identifier
  if(!unique.has_value())
    return BOOST_OUTCOME_V1_NAMESPACE::as_void(unique);
  auto var(std::move(std::move(unique).value()))
\endcode

This gets as close as is possible in C++ to the `try!` facility in Rust or Swift without
using exception throws, and you'll find yourself using it a very great deal when writing
code using Outcome. Like `try!`, the monad returning expression is executed and its returned
monad checked to see if it has a value. If it does, the value is extracted out of the monad
and placed in the variable you asked for. If it did not contain a value, the emptiness/errored/exceptioned
state is converted into a void form monad and returned immediately from the calling function,
thus propagating the empty/errored/exceptioned state up the stack. You'll note we cast the stack allocated monad
instance into a rvalue ref before asking for its value, this returns a rvalue ref to the value.
We then pass that rvalue ref through to the variable instance constructor so the value is moved
and not copied when possible. I have disassembled this sequence on the main compilers and found that where
the compiler knows for a fact that a value is being returned, all runtime overhead over a
straight return of a value is usually eliminated.

We also make use of a convenience overload of the `make_errored_XXX()` functions where a
single `int` is assumed to be a POSIX code in the `errno` domain and a single `DWORD` is assumed to
be a Win32 code in the `GetLastError()` domain. This allows very easy conversion of system
error codes into the appropriate `std::error_code` thusly returned wrapped in a monad.

Finally we also make use of the `BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT` macro which is a long
sequence of STL exception type catch clauses converting STL exception types into their
equivalent error codes:

\code
catch(const std::invalid_argument &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(const std::domain_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EDOM, e.what());
}
catch(const std::length_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(E2BIG, e.what());
}
catch(const std::out_of_range &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what());
}
catch(const std::logic_error &e) /* base class for this group */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(const std::system_error &e) /* also catches ios::failure */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(BOOST_OUTCOME_V1_NAMESPACE::error_code_extended(e.code(), e.what()));
}
catch(const std::overflow_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EOVERFLOW, e.what());
}
catch(const std::range_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what());
}
catch(const std::runtime_error &e) /* base class for this group */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, e.what());
}
catch(const std::bad_alloc &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ENOMEM, e.what());
}
catch(const std::exception &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(...)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, "unknown exception");
}
\endcode

You will surely note that the `make_errored_XXX()` functions actually take an `int` and an optional
`const char *`. This is the purpose of `error_code_extended` which extends `std::error_code` with
the following synposis:

\code
class error_code_extended : public std::error_code
{
public:
  error_code_extended();
  error_code_extended(int ec, const std::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  template <class ErrorCodeEnum, typename = typename std::enable_if<std::is_error_code_enum<ErrorCodeEnum>::value>::type>
    error_code_extended(ErrorCodeEnum e);
  explicit error_code_extended(const std::error_code &e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  explicit error_code_extended(std::error_code &&e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  void assign(int ec, const std::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  void clear();
  
  // New member functions
  // Fill a char buffer with the extended message, retrieving the two extended unsigned integer codes
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept;
  // Return an array of strings describing the stack at the time of construction. MUST call free() on this returned pointer.
  char **backtrace() const noexcept;
};
// Prints the extended error code, including any extended information if available
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
\endcode

`error_code_extended` is completely API compatible with `std::error_code` and all its
member functions can be used the same way. You can supply a `std::error_code` to an
extended error code, or else construct an extended error code the same way you would a
STL error code. You should note that it is **always safe** to slice `error_code_extended`
into an `std::error_code`, so you can safely feed `error_code_extended` to anything
consuming a `std::error_code`.

The main big additions are obviously the ability to add a custom string message to an extended
error code, this allows the preservation of the original `what()` message when converting a
thrown exception into an extended error code. You can also add two arbitrary unsigned integer
codes and most interestingly, a backtrace of the stack at the point of construction. The extended message and backtrace can be later
fetched using the new member functions, though note that the storage for these is kept in a
statically allocated threadsafe ring buffer and so may vanish at some arbitrary later point
when the storage gets recycled. If this happens, `extended_message()` will return zero characters
written and `backtrace()` will return a null pointer.

If you are throwing your own custom types with custom information, you should note that
you can create your own custom extended error code type using the same reusable
microsecond fast threadsafe logging framework that Outcome uses. This won't be documented
here as that framework (`ringbuffer_log`) lives in Boost-lite, but it's fairly easy to study
Outcome's and Boost-lite's source code all of which is on github.









