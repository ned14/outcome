# Tutorial part C: Outcome's outcome<T>, result<T> and option<T>
\anchor tutorial_outcome

[TOC]

\todo This section is not finished yet and may contain inaccurate or incorrect information.

Outcome provides a number of utility classes useful for ultra lightweight and constant time error
handling in C++ 14 and later. One of these is \ref outcome_expected_reference "a highly conforming expected<T, E> implementation"
which is currently before the ISO C++ standards Library Evolution Working Group for
standardisation. `expected<T, E>` is a very flexible
and generic utility class allowing perhaps too much unwise customisation in the hands
of its users, so Outcome also provides a family of more hard coded and deliberately
less flexible refinements to `expected<T, E>` called `outcome<T>` and `result<T>`
the use of which ought to generate more maintainable code bases and require less
typing of boilerplate by the programmer.

This tutorial is therefore split into three parts:
1. The first part (\ref tutorial_expected "part A") provides a broad overview of error handling in
C++ in general and how the `expected<T, E>` proposed for standardisation will contribute
to that big menu of error handling design patterns available to the C++ programmer.
This part isn't relevant to Outcome the library, but places it in context.
2. The second part (\ref tutorial_whynot "part B") describes why you probably ought
to not use unrestricted `expected<T, E>` in any real world code base and why
you ought to use the refinements of `outcome<T>` or `result<T>` instead.
3. The third part (part C, this part) walks you through using Outcome's refinements `outcome<T>`
and `result<T>`, plus its `extended_error_code`. Usage is very similar to Expected,
but with less typing and more convenient extensions.

<hr><br>

\section error_code_extended Outcome's extended std::error_code

A lot of people find `std::error_code` too constraining and value their custom error types
precisely because they can carry *payload* e.g. a custom string describing exactly the cause
of the error, or maybe a backtrace of the exact offending call sequence leading to the error.
They therefore reject the restriction to `std::error_code` as unsuitable for their use case.

Outcome provides an \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended"
refinement of `std::error_code` for exactly this situation. `error_code_extended` inherits publicly from `std::error_code`,
adding two new member functions: `extended_message()` and `backtrace()`. These *may* provide
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
consuming a `std::error_code`. The implicit destructor of `std::error_code` is retained
in `error_code_extended`.

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
all of the time construction is in the hundreds of nanoseconds range. Constructing an extended
error code with backtrace takes a maximum of about 35 microseconds on a recent Ivy Bridge Intel CPU.
**No memory allocation** is ever performed when constructing an extended error code, latency
is always predictable. Construction of an extended error code without using the extended features
is no additional overhead over `std::error_code`.

<hr><br>

\section outcome_rationale Where Outcome's outcome<T>, result<T> and option<T> come from

Hopefully by now you are persuaded to always *restrict* your use of `expected<T, E>` to
one of:

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::error_code>;
using bad_result_access = outcome::bad_expected_access<std::error_code>;
~~~

... or ...

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::exception_ptr>;
using bad_result_access = outcome::bad_expected_access<std::exception_ptr>;
~~~

If you've been convinced, then you'll be glad that Outcome provides additional
refinements of `expected<T, E>` designed to make your programming life even easier again.
As a rough **semantic** map onto `optional<T>`, `variant<...>` and
`expected<T, E>`:

<pre>
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
</pre>

So Outcome's `outcome<T>`, `result<T>` and `option<T>` assume the error type is hard coded
to the C++ 11 standard error transport infrastructure, and because they hard code this they
can make a series of optimisations both at runtime and for you the programmer during
coding which an `expected<T, E>` implementation can not. In Outcome's refinements,
an *empty* transport is empty, a *valued* transport contains a `T`, an *errored* transport
contains an `error_code_extended` and an *excepted* transport contains a `std::exception_ptr`.
- `.value()` on an errored transport directly throws `std::system_error` with the error code
instead of throwing a wrapper type.
- `.value()` on an excepted transport directly rethrows the exception pointer instead of
throwing a wrapper type.
- Implicit conversion is permitted for any less representative form into any more
representative form, so `option<T>` auto converts to a `result<T>` preserving exact contents.
This turns out to be very useful in large C++ codebases where the lowest layers tend
to be written using `option<T>` and `result<T>`, whilst highest layers tend to be written
using `outcome<T>` and C++ exception throws.


todo
