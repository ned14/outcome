# Refining Expected<T, E>
\anchor tutorial_outcome

[TOC]

Outcome's design rationale and tutorial is split into three parts:
1. The first part (\ref tutorial_expected "part A") provides a broad overview of error handling in
C++ in general and how the `expected<T, E>` proposed for standardisation will contribute
to that big menu of error handling design patterns available to the C++ programmer.
This part places Outcome the library in context.
2. The second part (\ref tutorial_whynot "part B") describes some design anti-patterns common
with inexperienced usage of `expected<T, E>` in C++ which you ought to avoid.
It shows you how to use `expected<T, E>` in a way which integrates well with the
C++ 11 STL's standard error code facilities `std::error_code` and `std::error_category`.
3. The third part (part C, this part) walks you through using Outcome's
`expected<T, E>` refinements `outcome<T>` and `result<T>`, plus its `extended_error_code`.
Usage is very similar to Expected, but with less typing, less runtime overhead and
more convenient extensions.

<hr><br>

In the previous part of this tutorial, we saw how there is a tension between type
safety and convenience of programming when using the `expected<T, E>` transport. Expected as a STL
primitive reflects a trade off between those two use cases, and as something which can wear
multiple hats it is close to optimal.

What is presented during this last part of Outcome's tutorial are Outcome's convenience
extensions to Expected. We start by assuming that you have no need
for type safety in your type `E`, and furthermore that you only have need for `E` to be
either an error code or an exception pointer *and nothing else*. Such assumptions, as
hopefully demonstrated in the previous part, are not wise for some code bases and use
cases for Expected - in those use cases, do not use these convenience extensions because
the loss of type safety is too big a trade off.

Rather, these convenience extensions are ideally suited for low level systems programming
and other such use cases where errors exclusively come from outside your code and where
therefore enforcing type safety on each particular error type is unnatural. Classic examples
of such code bases would be the Networking TS, the Filesystem TS and so on.

<hr><br>

\section error_code_extended Outcome's extended std::error_code

A lot of people find `std::error_code` too constraining and value their custom error types
precisely because they can carry *payload* e.g. a custom string describing exactly the cause
of the error, or maybe a backtrace of the exact offending call sequence leading to the error.
They therefore reject the restriction to `std::error_code` as unsuitable for their use case.

Outcome provides an \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended"
refinement of `std::error_code` for exactly this situation. `error_code_extended` inherits publicly from `std::error_code`,
adding three new member functions: `extended_message()`, `raw_backtrace()` and `backtrace()`. These *may* provide
additional information about the error code like any `what()` message from the C++ exception
the error code was constructed from (if any), or the stack backtrace of the point at which the
`error_code_extended` was constructed.

~~~{.cpp}
class error_code_extended : public std::error_code
{
public:
  error_code_extended();
  error_code_extended(int ec, const std::error_category &cat,
    const char *msg = nullptr,  // These are the extended payloads available
    unsigned code1 = 0,
    unsigned code2 = 0,
    bool backtrace = false);
  template <class ErrorCodeEnum, typename = typename std::enable_if<std::is_error_code_enum<ErrorCodeEnum>::value>::type>
    error_code_extended(ErrorCodeEnum e);
  explicit error_code_extended(const std::error_code &e,
    const char *msg = nullptr,  // These are the extended payloads available
    unsigned code1 = 0,
    unsigned code2 = 0,
    bool backtrace = false);
  explicit error_code_extended(std::error_code &&e,
    const char *msg = nullptr,  // These are the extended payloads available
    unsigned code1 = 0,
    unsigned code2 = 0,
    bool backtrace = false);
  void assign(int ec, const std::error_category &cat,
    const char *msg = nullptr,  // These are the extended payloads available
    unsigned code1 = 0,
    unsigned code2 = 0,
    bool backtrace = false);
  void clear();
  
  // New member functions follow

  // Fill a buffer with any extended error message and codes, returning bytes of buffer filled (zero if no extended message).
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept;

  // Fill a buffer with any backtrace available, returning items filled if any.
  size_t raw_backtrace(void **buffer, size_t len) const noexcept

  // Returns an array of strings describing the backtrace. You must free() this after use.
  char **backtrace() const noexcept;
};

// Prints the extended error code, including any extended information if available
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
~~~

`error_code_extended` is completely API compatible with `std::error_code` and all its
member functions can be used the same way. You can supply a `std::error_code` to an
extended error code, or else construct an extended error code the same way you would a
STL error code. You should note that it is **always safe** to slice `error_code_extended`
into an `std::error_code`, so you can safely feed `error_code_extended` to anything
consuming a `std::error_code`. The important-to-optimisation implicit destructor of
`std::error_code` is retained in `error_code_extended`.

The main big additions are obviously the ability to add a custom string message to an extended
error code, this allows the preservation of the original `what()` message when converting a
thrown exception into an extended error code. You can also add two arbitrary unsigned integer
codes and most interestingly, a backtrace of the stack at the point of construction. The extended message and backtrace can be later
fetched using the new member functions, though note that the storage for these is kept in a
statically allocated threadsafe ring buffer and so may vanish at some arbitrary later point
when the storage gets recycled. If this happens, `extended_message()` will return zero characters
written, `raw_backtrace()` will return zero items filled and `backtrace()` will return a null pointer.

Because the storage for the extended information may be recycled at any arbitrary future
point, you ought to make sure that you copy the extended information as soon as possible
after the `error_code_extended` is constructed. In other words, don't store `error_code_extended`
as-is into say a vector, instead extract the information into a custom struct as soon as you
can.

\note Construction of an extended error code with extended message or codes takes a worst
case maximum of a microsecond on recent hardware. That's a worst case, almost
all of the time construction is in the low hundreds of nanoseconds range. Constructing an extended
error code with backtrace takes a maximum of about 35 microseconds on a recent Ivy Bridge Intel CPU.
**No memory allocation** is ever performed when constructing an extended error code, latency
is always predictable. Construction of an extended error code without using the extended features
is no additional overhead over `std::error_code`.

<hr><br>

\section outcome_overview Outcome's outcome<T>, result<T> and option<T> refinements

Outcome provides additional refinements of `expected<T, E>` designed to make your programming
life easier if you are willing to accept the hard coding of `E` to one of `error_code_extended`
or `std::exception_ptr`. As a rough **semantic** map onto `optional<T>`, `variant<...>` and
`expected<T, E>`:

\code{.cpp}
template<class T> using option = std::optional<T>;

template<class T> using result = std::optional<
  std::experimental::expected<
    T,
    error_code_extended
  >
>;

template<class T> using outcome = std::optional<
  std::experimental::expected<
    T,
    std::variant<
      error_code_extended,
      std::exception_ptr
    >
  >
>;
\endcode

Outcome's `outcome<T>`, `result<T>` and `option<T>` assume the error type is hard coded
to the C++ 11 standard error transport infrastructure, and because they hard code this they
can make a series of optimisations in API design for you the programmer to save boilerplate, at compile time and
at runtime which an `expected<T, E>` implementation can not. To spell it out:
- `option<T>` can be empty, or hold an instance of a type `T`.
- `result<T>` can be empty, or hold an instance of a type `T`, or hold an instance of `error_code_extended`.
- `outcome<T>` can be empty, or hold an instance of a type `T`, or hold an instance of
`error_code_extended`, or hold an instance of `std::exception_ptr`. This saves you having to
wrap an error code into an exception pointer instance, thus also avoiding a memory allocation.

Implicit conversion is permitted for any less representative form into any more
representative form, so `option<T>` auto converts to a `result<T>` preserving exact contents,
as does `result<T>` into an `outcome<T>`.
This turns out to be very useful in large C++ codebases where the lowest layers tend
to be written using `option<T>` and `result<T>`, whilst highest layers tend to be written
using `outcome<T>` and C++ exception throws.

In Outcome's refinements which we shall call *transports*, an *empty* transport is empty,
a *valued* transport contains a `T`, an *errored* transport contains an `error_code_extended` and
an *excepted* transport contains a `std::exception_ptr`. All transports will throw a
\ref boost::outcome::v1_xxx::monad_error "monad_error" type if you try doing something wrong
instead of a `bad_expected_access<E>`. `monad_error` subclasses `std::system_error` with an error
code of custom category `monad_category()`, with corresponding enumeration
\ref boost::outcome::v1_xxx::monad_errc "monad_errc", which can have one of two values:
- `monad_errc::no_state` means you attempted to fetch a value, error or exception from an empty transport.
- `monad_errc::exception_present` is returned as the error code if you retrieve an error
code from an excepted transport.

This leads to the following differences to `expected<T, E>`:
- Outcome's refinements constexpr default construct to **empty**, not to a default constructed
`T`. There is no "almost never empty" guarantee like with `expected<T, E>` or `variant<...>`,
instead there is a formal empty state to do with as you please (in some situations, a function
returning a value OR empty OR an error makes a lot of sense and Outcome supports a `tribool`
extension for ternary logics for those who need such a thing). Attempting to retrieve a value,
error or exception from an empty transport throws a `monad_error::no_state` [1].
- `.value()` on an errored transport directly throws a `std::system_error` with the error code [2]
instead of throwing a wrapper type like `bad_expected_access<E>` from which you need to manually
extract the `E` instance later.
- `.value()` on an excepted transport directly rethrows the contents of the exception pointer [3] instead of
throwing a wrapper type like `bad_expected_access` from which you need to manually
extract later.
- `.error()` returns any `error_code_extended` as you'd expect, returning a default constructed
(null) error code if the transport is valued, or `monad_errc::exception_present` if the
transport is excepted.
- `.exception()` returns any `std::exception_ptr` as you'd expect. If the transport is valued,
it returns a default constructed (null) exception pointer. If the transport is errored, it
returns an exception pointer to a `std::system_error` wrapping the error code.

And finally, if your compiler is in C++ 17 mode or later, transports are marked with the
<a href="http://en.cppreference.com/w/cpp/language/attributes">`[[nodiscard]]`</a> attribute.
This means the compiler ought to warn if you forget to examine transports returned by functions.
If you really mean to throw away a returned transport, make sure you cast it to `(void)` to tell
the compiler you specifically intend to throw it away.

[1]: Actually the `BOOST_OUTCOME_THROW_MONAD_ERROR(monad_error(monad_errc::no_state))` macro is executed
where `ec` is the `std::error_code` contained by the monad. This can be user redefined to do anything,
but the default implementation throws a C++ exception of type
\ref boost::outcome::v1_xxx::monad_error "monad_error" with code
\ref boost::outcome::v1_xxx::monad_errc "monad_errc::no_state" if C++ exceptions are enabled
by the compiler. If they are not, it prints a stack backtrace to stderr and aborts the process.

[2]: Similarly the `BOOST_OUTCOME_THROW_SYSTEM_ERROR(std::system_error(ec))` macro is actually
executed where `ec` is the `error_code_extended` contained by the monad.

[3]: Similarly the `BOOST_OUTCOME_RETHROW_EXCEPTION(e)` macro is actually executed where `e` is
the `std::exception_ptr` contained by the monad.

<hr><br>

\section outcome_helpers Outcome's helper free functions

As with Expected, Outcome supplies helper free functions to make your life writing code with
`option<T>`, `result<T>` and `expected<T>` easier. They are named a bit differently however,
though the naming convention is straightforward.
As with `expected<void, E>`, it is legal to be valued and of type `void`. Because a
transport of type `void` is always considered less representative than any type `T`, any
void transport will implicitly convert into any non-void transport, preserving any empty,
errored or excepted state. This lets you conveniently write:

~~~{.cpp}
result<Foo> somefunction()
{
  ...
  if(bad)
    return make_errored_result</* void */>(...);  // Note we didn't specify <Foo>
  else
    return Foo(...);
}
~~~

The full set of free functions is as follows:
<dl>
  <dt>`make_(option|result|outcome)(T v)`</dt>
  <dd>Makes a valued transport with value `v`.</dd>
  <dt>`make_(option|result|outcome)<T = void>()`</dt>
  <dd>Makes a valued transport default constructing a `T`.</dd>
  <dt>`make_empty_(option|result|outcome)<T = void>()`</dt>
  <dd>Makes an empty transport.</dd>
  <dt>`make_errored_(result|outcome)<T = void>(error_code_extended ec)`</dt>
  <dd>Makes an errored transport.</dd>
  <dt>`make_errored_(result|outcome)<T = void>(int code, const char *extendedmsg = nullptr)`</dt>
  <dd>Makes an errored transport with the given error code of generic POSIX category and optionally some
extended custom message which is copied into storage as per `error_code_extended`. This is
very convenient for writing:
 ~~~{.cpp}
 result<Foo> somefunction()
 {
   if(-1 == open(...))  // Any POSIX system call setting errno on failure
     return make_errored_result<>(errno);
 }
 ~~~
 </dd>
  <dt>`make_errored_(result|outcome)<T = void>(DWORD code, const char *extendedmsg = nullptr)`
(Windows only)</dt>
  <dd>Makes an errored transport with the given error code of Win32 system category and optionally some
extended custom message which is copied into storage as per `error_code_extended`. This is
very convenient for writing:
 ~~~{.cpp}
 result<Foo> somefunction()
 {
   if(INVALID_HANDLE_VALUE == CreateFile(...))  // Any Win32 call setting GetLastError() on failure
     return make_errored_result<>(GetLastError());
 }
 ~~~
 </dd>
  <dt>`make_excepted_outcome<T = void>(std::exception_ptr v = std::current_exception())`</dt>
  <dd>Makes an excepted transport. This lets you conveniently write:
 ~~~{.cpp}
 outcome<Foo> somefunction()
 {
   try
   {
     ...
   }
   catch(...)  // catch all
   {
     return make_excepted_outcome</* void */>(/* std::current_exception() */);
   }
 }
 ~~~
  </dd>
  <dt>`as_(result|outcome)(option|result)`</dt>
  <dd>Lets you formally annotate an implicit conversion from less representative to more representative.</dd>
  <dt>`as_void(const (option<T>|result<T>|outcome<T>|expected<T, E>) &)`</dt>
  <dd>Returns a copy of any input transport
as a void version of the same transport, preserving any empty/errored/excepted state. If the input
was valued, the returned copy will be valued **void**.</dd>
</dl>

<hr><br>

\section outcome_macros Outcome's helper macros

We've already seen in part B the helper macro `BOOST_OUTCOME_TRY(var, expr)` which also works
with `expected<T, E>` when the error type in the returned Expected is the same. Something
unique to Outcome's refinements due to using `error_code_extended` is the convenience macro
`BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT` which is a long
sequence of STL exception type catch clauses converting STL exception types into their
equivalent generic category error codes, preserving any custom `what()` message:

~~~{.cpp}
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
~~~

This macro is particularly useful when you are calling into the STL from a noexcept
function which returns a `result<T>` and not an `outcome<T>`. So long as the code you
call only **ever** will throw STL exception types, using this macro is safe and information
loss free. Note that the above sequence does not include a catch all clause, so if
you want one of those then use the `BOOST_OUTCOME_CATCH_ALL_EXCEPTION_TO_RESULT` macro
which adds to the end of the catch sequence:

~~~{.cpp}
... all the stuff from BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT and then ...
catch(...)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, "unknown exception");
}
~~~

<hr><br>

\section outcome_usage Example of usage of Outcome's expected<T, E> refinements

The final code example is a reasonably long one which places, side by side, an
implementation written using `expected<T, E>` beside one using `result<T>`.
The program is a find regex in files utility written using C++ 14 and the Filesystem TS.

<table>
<tr>
<td valign="top">
\snippet find_regex_expected.cpp find_regex_expected
</td>
<td valign="top">
\snippet find_regex_result.cpp find_regex_result
</td>
</tr>
</table>

As you can see, in the above use case there is not much difference between using
`expected<T, E = std::error_code>` or `result<T>`:

1. Instead of typing `outcome::make_unexpected(std::error_code(GetLastError(), std::system_category()))`
you can type `outcome::make_errored_result<>(GetLastError())`.
2. Instead of typing out a sequence of exception catch clauses, you can use `BOOST_OUTCOME_CATCH_ALL_EXCEPTION_TO_RESULT`.

Much of the time, code using `expected<T, E = std::error_code>` and `result<T>`
will look very similar, especially when you are avoiding "default actions" by
being careful to always explicitly check state of a transport before using it.
If on the other hand you don't bother with those manual checks and instead rely
on the default actions performed when you try something not possible, you gets
quite different code outcomes:

\todo In progress
