# Quick start for the expert
\anchor quickstart

This section is for those needing to quickly refresh their memory on Outcome or those very familiar
with `std::experimental::expected<T, E>`. It is not suitable for beginners who should use the \ref tutorial.

It should be stressed that \ref boost::outcome::v1_xxx::basic_monad "basic_monad<>" is a policy driven class where the policy
class has the ability to arbitrarily extend and/or replace member functions listed in this
synopsis. Indeed originally a non-allocating lockfree high performance `promise<T>...future<T>` implementation
simply supplied a policy class implementing the additional features of promise-future to
`basic_monad<>` whereby C++ 17 future continuations were modelled as monadic binds
(it can be still found in the attic directory for anyone interested, though note how stale
it likely is by now). That level of flexibility remains in the design for anyone interested in adding more
`basic_monad<>` specialisations e.g. packed storage.

When using Outcome, you can find its namespace via either of these forms:
~~~{.cpp}
// Traditional: use SOME version Boost.Outcome visible to the compiler/linker
namespace outcome = boost::outcome;

// Better: use EXACTLY the Boost.Outcome visible in the current translation unit
namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;
~~~

The `BOOST_OUTCOME_V1_NAMESPACE` macro encodes a unique hexadecimal value per release. This guarantees
that the linker will not substitute a different version of Outcome than the Outcome you compiled against.
It is therefore recommended that you use the `BOOST_OUTCOME_V1_NAMESPACE` macro.

<hr><br>
\section synopsis Synopsis

The following is a quick reference synopsis for `outcome<T>` which is configured with `value_type = T`,
`error_type = error_code_extended` and `exception_type = std::exception_ptr`. If it were a
`result<T>`, only `value_type` and `error_type` functions would be present, similarly if it were
an `option<T>` only `value_type` functions would be present. \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended"
is a type slice safe subclass of `std::error_code`, it keeps additional information about an error code.

For your convenience, where `std::experimental::expected<T, E = std::error_code>` is drop-in similar to `result<T>`, it
is indicated by comments.

~~~{.cpp}
BOOST_OUTCOME_V1_NAMESPACE_BEGIN

// Tag types for creating empty, valued, errored and excepted basic_monad's
struct empty_t; constexpr empty_t empty;
struct value_t; constexpr value_t value;
struct error_t; constexpr error_t error;
struct exception_t; constexpr exception_t exception;

// Specialise to std::true_type for types you wish to store in a packed single byte
// (void and bool are done for you unless you define BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE)
template <class _value_type> struct enable_single_byte_value_storage;

// Remember basic_monad<Policy<...>> is aliased to outcome<T>, result<T> and option<T>
template <class T, class EC = std::error_code, class E = std::exception_ptr>
class basic_monad<monad_policy<T, EC, E>>
{
public:
  // true if configured to hold a value_type, an error_type or an exception_type
  static constexpr bool has_value_type;
  static constexpr bool has_error_type;
  static constexpr bool has_exception_type;
 
  // If configured with void, set to a helpfully named unusable type 
  using value_type = T | unusable;                                             // similar in expected<> [3]
  using error_type = EC | unusable;                                            // similar in expected<> [3]
  using exception_type = E | unusable;                                         // [3]
  struct empty_type;                                                           // empty tag for this monad, unlike empty_t which is for all monads
  
  // The actual types configured
  using raw_value_type = T | void;                                             // The actual type configured
  using raw_error_type = EC | void;                                            // ditto
  using raw_exception_type = E | void;                                         // ditto

  template <class U> using rebind = basic_monad<U>;                            // also in expected<>

  // The properties of this monad, and relative to other monads
  static constexpr bool is_nothrow_copy_constructible;
  static constexpr bool is_nothrow_move_constructible;
  static constexpr bool is_nothrow_copy_assignable;
  static constexpr bool is_nothrow_move_assignable;
  static constexpr bool is_nothrow_destructible;
  static constexpr bool is_trivially_destructible;
  template <class OtherMonad> static constexpr bool is_constructible;
  template <class OtherMonad> static constexpr bool is_comparable;

  // Default implicit construction and copy and move construction
  constexpr basic_monad() noexcept([1]);                                       // also in expected<>, use make_empty_monad<T>() instead
  constexpr basic_monad(const basic_monad&) noexcept([1]);                     // also in expected<>
  constexpr basic_monad(basic_monad&&) noexcept([1]);                          // also in expected<>

  // Implicit constructing empty or with a value_type
  constexpr basic_monad(empty_t) noexcept;                                     // use make_empty_XXX<T>() instead
  constexpr basic_monad(value_t) noexcept(T);                                  // use make_ready_XXX<T>() instead
  constexpr basic_monad(const value_type&) noexcept(T);                        // also in expected<>
  constexpr basic_monad(value_type&&) noexcept(T);                             // also in expected<>
  
  // Explicit emplacement of a value_type
  template <class... Args>
    constexpr explicit basic_monad(in_place_t, Args&&...) noexcept(T);         // also in expected<>
  template <class U>
    constexpr basic_monad(in_place_t, std::initializer_list<U>) noexcept(T);   // also in expected<>

  // Implicit construction from emptiness, error or excepted state of a void basic_monad
  constexpr basic_monad(const rebind<void>&) noexcept([1]);                    // use as_void() to create a void monad
  constexpr basic_monad(rebind<void>&&) noexcept([1]);                         // use as_void() to create a void monad
  
  // Implicit construction with error_type or exception_type
  constexpr basic_monad(const error_type&) noexcept(EC);                       // use make_errored_XXX() instead
  constexpr basic_monad(error_type&&) noexcept(EC);                            // use make_errored_XXX() instead
  constexpr basic_monad(const exception_type&) noexcept(E);                    // use make_exceptional_XXX() instead
  constexpr basic_monad(exception_type&&) noexcept(E);                         // use make_exceptional_XXX() instead
  
  // Explicit up converting move and copy constructors, only
  // available if T, EC and E are constructible from T2, EC2 and E2
  // and no information can ever be lost
  template <class T2, class EC2, class E2>
    constexpr explicit basic_monad(basic_monad<monad_policy<T2, EC2, E2>> &&) noexcept([1]);
  template <class T2, class EC2, class E2>
    constexpr explicit basic_monad(const basic_monad<monad_policy<T2, EC2, E2>> &) noexcept([1]);
  
  // Not implemented if value_type, error_type and exception_type are all trivially destructible
  // thus making basic_monad a LiteralType (i.e. constexpr usable)
  ~basic_monad() noexcept([1]);

  // Assignment. Note exception throws during assignment leave the monad empty
  constexpr basic_monad& operator=(const basic_monad&) noexcept([1]);          // also in expected<>
  constexpr basic_monad& operator=(basic_monad&&) noexcept([1]);               // also in expected<>

  // Observers
  constexpr explicit operator bool() const noexcept;                           // also in expected<>
  constexpr explicit operator boost_lite::tribool::tribool() const noexcept;   // other if monad empty, false if monad errored/excepted
  constexpr bool is_ready() const noexcept;                                    // i.e. not empty
  constexpr bool empty() const noexcept;
  constexpr bool has_value() const noexcept;                                   // also in expected<>
  constexpr bool has_error() const noexcept;
  constexpr bool has_exception(bool only_exception = false) const noexcept;    // NOTE defaults to true also if has_error()

  // For compatibility with expected<T, E> and optional<T>
  constexpr const value_type* operator ->() const;                             // also in expected<>, missing if [2]
  constexpr value_type* operator ->();                                         // also in expected<>, missing if [2]
  constexpr const value_type& operator *() const&;                             // also in expected<>, returns by value if [2]
  constexpr value_type& operator *() &;                                        // also in expected<>, returns by value if [2]
  constexpr const value_type&& operator *() const&&;                           // also in expected<>, returns by value if [2]
  constexpr value_type&& operator *() &&;                                      // also in expected<>, returns by value if [2]

  // Retrieving value_type
  constexpr const value_type& value() const&;                                  // also in expected<>
  constexpr value_type& value() &;                                             // also in expected<>
  constexpr const value_type&& value() const&&;                                // also in expected<>
  constexpr value_type&& value() &&;                                           // also in expected<>
  constexpr const value_type &value_or(const value_type &) noexcept const&;    // similar in expected<>
  constexpr value_type& value_or(value_type&) noexcept &;                      // similar in expected<>
  constexpr const value_type&& value_or(const value_type&&) noexcept const&&;  // similar in expected<>
  constexpr value_type&& value_or(value_type&&) noexcept &&;                   // similar in expected<>

  // Setting value_type, disposes any previous state
  constexpr void set_value(const value_type&);
  constexpr void set_value(value_type&&);
  constexpr void set_value();
  template <class... Args>
    constexpr void emplace(Args&&...) noexcept([1]);                           // also in expected<>
  
  // Retrieving and setting error_type and exception_type
  constexpr error_type error() const;                                          // similar in expected<>
  constexpr error_type error_or(error_type) noexcept const;
  constexpr void set_error(error_type);
  constexpr exception_type exception() const;
  constexpr exception_type exception_or(exception_type) noexcept const;
  constexpr void set_exception(exception_type);
  template<class E> void set_exception(E&&);                                   // via std::make_exception_ptr

  // Swap and clear to empty
  void swap(basic_monad&) noexcept([1]);                                       // also in expected<>
  void clear() noexcept([1]);

#ifdef BOOST_OUTCOME_ENABLE_ADVANCED                                           // defaults to disabled (documented in Advanced Usage)
  basic_monad<...> unwrap() const &;                                           // return innermost monad
  basic_monad<...> unwrap() &&;
  template<class F> basic_monad<...> bind(F &&f);                              // traditional monad bind operation
  template<class F> basic_monad<...> operator>>(F &&f);                        // alias for bind() to keep Haskell folk happy
  template<class F> basic_monad<...> map(F &&f);                               // traditional monad map operation
  template<class F> basic_monad(F(contents)).unwrap() match(F &&f);            // call callable with contents of monad
  template<class... Args> decltype(value_type(Args...)) operator()(Args &&...);// as if value()(Args...)
  
  template<class U> constexpr basic_monad operator|(U &&) &;                   // if the monad is not valued, return monad with U
  template<class U> constexpr basic_monad operator|(U &&) const&;
  template<class U> constexpr basic_monad operator|(U &&) &&;
  template<class U> constexpr basic_monad operator&(U &&) &;                   // if the monad is valued, return monad with U
  template<class U> constexpr basic_monad operator&(U &&) const&;
  template<class U> constexpr basic_monad operator&(U &&) &&;
#endif
};

// NOTE requires state to be set to valued beforehand (and can only deserialise a value)
template<class Policy> inline std::istream &operator>>(std::istream &s, basic_monad<Policy> &v);
// Intended for printing rather than serialisation to storage
template<class Policy> inline std::ostream &operator<<(std::ostream &s, const basic_monad<Policy> &v);

// Equality operators
template<class Policy1, class Policy2> constexpr inline bool operator==(const basic_monad<Policy1> &, const basic_monad<Policy2> &);
template<class Policy1, class Policy2> constexpr inline bool operator!=(const basic_monad<Policy1> &, const basic_monad<Policy2> &);

// Outcome makers
template <class T> constexpr inline outcome<T> make_outcome(T &&v);
template <class T> constexpr inline outcome<T> make_outcome(const T &v);
template <class T = void> inline outcome<T> make_outcome(error_code_extended v);
template <class T = void> inline outcome<T> make_outcome(std::exception_ptr v);
template <class T = void> constexpr inline outcome<T> make_outcome();
template <class T = void> constexpr inline outcome<T> make_empty_outcome();
template <class T> constexpr inline outcome<T> make_ready_outcome(T &&v);
template <class T> constexpr inline outcome<T> make_ready_outcome(const T &v);
template <class T = void> constexpr inline outcome<T> make_ready_outcome();  // can be specialised for some type T, defaults to refusing to compile except for void
template <> inline outcome<void> make_ready_outcome<void>();
template <class T = void> inline outcome<T> make_errored_outcome(error_code_extended v);
template <class T = void> inline outcome<T> make_errored_outcome(int e, const char *extended = nullptr);                      // errno consumer
#if defined(_WIN32)
template <class T = void> constexpr inline outcome<T> make_errored_outcome(unsigned long e, const char *extended = nullptr);  // GetLastError() consumer
#endif
template <class T = void> inline outcome<T> make_exceptional_outcome(std::exception_ptr v);

// Result makers
template <class T> constexpr inline result<T> make_result(T &&v);
template <class T> constexpr inline result<T> make_result(const T &v);
template <class T = void> inline result<T> make_result(error_code_extended v);
template <class T = void> constexpr inline result<T> make_result();
template <class T = void> constexpr inline result<T> make_empty_result();
template <class T> constexpr inline result<T> make_ready_result(T &&v);
template <class T> constexpr inline result<T> make_ready_result(const T &v);
template <class T = void> constexpr inline result<T> make_ready_result();    // can be specialised for some type T, defaults to refusing to compile except for void
template <> inline result<void> make_ready_result<void>();
template <class T = void> inline result<T> make_errored_result(error_code_extended v);
template <class T = void> constexpr inline result<T> make_errored_result(int e, const char *extended = nullptr);              // errno consumer
#if defined(_WIN32)
template <class T = void> constexpr inline result<T> make_errored_result(unsigned long e, const char *extended = nullptr);    // GetLastError() consumer
#endif

// Option makers
template <class T> constexpr inline option<T> make_option(T &&v);
template <class T> constexpr inline option<T> make_option(const T &v);
template <class T = void> constexpr inline option<T> make_option();
template <class T = void> constexpr inline option<T> make_empty_option();
template <class T> constexpr inline option<T> make_ready_option(T &&v);
template <class T> constexpr inline option<T> make_ready_option(const T &v);
template <class T = void> constexpr inline option<T> make_ready_option();    // can be specialised for some type T, defaults to refusing to compile except for void
template <> constexpr inline option<void> make_ready_option<void>();

// Upconverters
template <class T> constexpr inline outcome<T> as_outcome(result<T> &&v);
template <class T> constexpr inline outcome<T> as_outcome(const result<T> &v);
template <class T> constexpr inline outcome<T> as_outcome(option<T> &&v);
template <class T> constexpr inline outcome<T> as_outcome(const option<T> &v);
template <class T> constexpr inline result<T> as_result(option<T> &&v);
template <class T> constexpr inline result<T> as_result(const option<T> &v);

// Emptiness, errored and excepted state extractors
template <class T> inline outcome<void> as_void(const outcome<T> &v);
template <class T> inline result<void> as_void(const result<T> &v);
template <class T> constexpr inline option<void> as_void(const option<T> &v);

BOOST_OUTCOME_V1_NAMESPACE_END
~~~

Outcome also provides some very useful helper macros you'll find yourself using a lot:

~~~{.cpp}
// Equivalent to try! in Rust and Swift (see below for docs)
#define BOOST_OUTCOME_TRY(variable_to_initialise, monad)

// Boilerplate catching all the STL exceptions, returning an equivalent result<void> (see below for docs)
#define BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT
~~~

[1]: The `noexcept` for each of these is determined by calculating the `noexcept`
for the same operation in each of `T`, `EC` and `E`. If the same operation on any
of those types can throw, so can the basic_monad's operation.

[2]: The trait \ref boost::outcome::v1_xxx::enable_single_byte_value_storage determines if
a single byte is used to store `T`, in which case you will not be returned a pointer
nor reference to `T`. It is enabled for `bool` and `void` unless the
macro \ref BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE is defined.

[3]: If the monad was configured with `void` in this place, this is configured with an
internal non-accessible type usefully named to indicate you are trying to use
something not possible which will generate a very obvious descriptive compiler error.

