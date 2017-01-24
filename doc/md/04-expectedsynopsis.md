# Detail: Outcome's implementation of Expected
\anchor outcome_expected_reference

You should read <a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">P0323R1</a>
if you want a C++ standards level of detail regarding exactly what each member function's
preconditions, effects and postconditions are. For your convenience we copy and paste P0323R1's
Expected synopsis here with added comments indicating where something is not implemented
or implemented differently in Outcome's implementation.

\todo This section is not finished yet and may contain inaccurate or incorrect information.

<hr><br>

\section synopsis_unexpected_type unexpected_type<E>

<table>
<tr><th>LEWG's Expected implementation</th><th>Outcome's Expected implementation</th></tr>
<tr><td>
~~~{.cpp}
namespace std {
namespace experimental {
inline namespace fundamentals_v3 {
  // X.Y.3, Unexpected object type
  template <class E>
    class unexpected_type;

  // X.Y.4, Unexpected factories
  template <class E>
    constexpr unexpected_type<decay_t<E>> make_unexpected(E&& v);
    
    

  // X.Y.5, unexpected_type relational operators
  template <class E>
    constexpr bool
    operator==(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator!=(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator<(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator>(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator<=(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator>=(const unexpected_type<E>&, const unexpected_type<E>&);

}}}
~~~

~~~{.cpp}
template <class E>
class unexpected_type {
public:
  unexpected_type() = delete;
  constexpr explicit unexpected_type(const E&);
  constexpr explicit unexpected_type(E&&);
  constexpr const E& value() const;
  constexpr E & value();
private:
  E val; // exposition only
};
~~~
</td><td>
~~~{.cpp}
namespace boost {
namespace outcome {
inline namespace v1_xxx {
  // X.Y.3, Unexpected object type
  template <class E>
    using unexpected_type = expected<void, E>;

  // X.Y.4, Unexpected factories
  template <class E>
    constexpr unexpected_type<E> make_unexpected(const E& v);
  template <class E>
    constexpr unexpected_type<E> make_unexpected(E&& v);

  // X.Y.5, unexpected_type relational operators
  template <class E>
    constexpr bool
    operator==(const unexpected_type<E>&, const unexpected_type<E>&);
  template <class E>
    constexpr bool
    operator!=(const unexpected_type<E>&, const unexpected_type<E>&);










    
    
    
}}}
~~~

~~~{.cpp}
template <class E>
class unexpected_type {                           // Actually expected<void, E>
public:
  unexpected_type() = default;
  constexpr explicit unexpected_type(const E&);
  constexpr explicit unexpected_type(E&&);
  constexpr const E& value() const;
  constexpr E & value();
private:
  E val; // exposition only
};
~~~
</td></tr>
</table>


\section synopsis_expected expected<T, E>

<table>
<tr><th>LEWG's Expected implementation</th><th>Outcome's Expected implementation</th></tr>
<tr><td>
~~~{.cpp}
namespace std {
namespace experimental {
inline namespace fundamentals_v3 {
  // X.Z.4, expected for object types
  template <class T, class E= error_condition>
    class expected;

  // X.Z.5, Specialization for void.
  template <class E>
    class expected<void, E>;

  // X.Z.6, unexpect tag
  struct unexpect_t{
    unexpect_t() = delete;
  };
  constexpr unexpect_t unexpect{'implementation defined'};

  // X.Z.7, class bad_expected_access
  class bad_expected_access;

  // X.Z.8, Expected relational operators
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const expected<T,E>&);

  // X.Z.9, Comparison with T
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator==(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator!=(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator<(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator<=(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator>(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator>=(const T&, const expected<T,E>&);

  // X.Z.10, Comparison with unexpected_type<E>
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator==(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator!=(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator<(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const unexpected_type<E>&);

  template <class T, class E>
    constexpr bool operator<=(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator>(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator>=(const unexpected_type<E>&, const expected<T,E>&);

  // X.Z.11, Specialized algorithms
  void swap(expected<T,E>&, expected<T,E>&) noexcept(see below);

  // X.Z.12, Factories
  template <class T> constexpr expected<decay_t<T>> make_expected(T&& v);
  expected<void> make_expected();
  template <class T, class E>
    constexpr expected<T, decay_t<E>> make_expected_from_error(E&& e);
  template <class T, class E, class U>
    constexpr expected<T, E> make_expected_from_error(U&& u);
  template <class F>
    constexpr expected<typename result_type<F>::type>
  make_expected_from_call(F f);

  // X.Z.13, hash support
  template <class T, class E> struct hash<expected<T,E>>;
  template <class E> struct hash<expected<void,E>>;
}}}
~~~
</td><td>
~~~{.cpp}
namespace std {
namespace experimental {
inline namespace fundamentals_v3 {
  // X.Z.4, expected for object types
  template <class T, class E= error_condition>
    class expected;

  // X.Z.5, Specialization for void.
  template <class E>
    class expected<void, E>;

  // X.Z.6, unexpect tag
  struct unexpect_t{
    unexpect_t() = delete;
  };
  constexpr unexpect_t unexpect{'implementation defined'};

  // X.Z.7, class bad_expected_access
  class bad_expected_access;

  // X.Z.8, Expected relational operators
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const expected<T,E>&);

  // X.Z.9, Comparison with T
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator==(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator!=(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator<(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator<=(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator>(const T&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const T&);
  template <class T, class E>
    constexpr bool operator>=(const T&, const expected<T,E>&);

  // X.Z.10, Comparison with unexpected_type<E>
  template <class T, class E>
    constexpr bool operator==(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator==(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator!=(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator!=(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator<(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator<=(const expected<T,E>&, const unexpected_type<E>&);

  template <class T, class E>
    constexpr bool operator<=(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator>(const unexpected_type<E>&, const expected<T,E>&);
  template <class T, class E>
    constexpr bool operator>=(const expected<T,E>&, const unexpected_type<E>&);
  template <class T, class E>
    constexpr bool operator>=(const unexpected_type<E>&, const expected<T,E>&);

  // X.Z.11, Specialized algorithms
  void swap(expected<T,E>&, expected<T,E>&) noexcept(see below);

  // X.Z.12, Factories
  template <class T> constexpr expected<decay_t<T>> make_expected(T&& v);
  expected<void> make_expected();
  template <class T, class E>
    constexpr expected<T, decay_t<E>> make_expected_from_error(E&& e);
  template <class T, class E, class U>
    constexpr expected<T, E> make_expected_from_error(U&& u);
  template <class F>
    constexpr expected<typename result_type<F>::type>
  make_expected_from_call(F f);

  // X.Z.13, hash support
  template <class T, class E> struct hash<expected<T,E>>;
  template <class E> struct hash<expected<void,E>>;
}}}
~~~
</td></tr>
<tr><td>
~~~{.cpp}
template <class T, class E>
class expected
{
public:
  typedef T value_type;
  typedef E error_type;
  template <class U>
    struct rebind {
      using type = expected<U, error_type>;
    };
    
  // X.Z.4.1, constructors
  constexpr expected() noexcept(see below);
  expected(const expected&);
  expected(expected&&) noexcept(see below);
  constexpr expected(const T&);
  constexpr expected(T&&);
  template <class... Args>
    constexpr explicit expected(in_place_t, Args&&...);
  template <class U, class... Args>
    constexpr explicit expected(in_place_t, initializer_list<U>, Args&&...);
  constexpr expected(unexpected_type<E> const&);
  template <class Err>
    constexpr expected(unexpected_type<Err> const&);
  template <class... Args>
    constexpr explicit expected(unexpect_t, Args&&...);
  template <class U, class... Args>
    constexpr explicit expected(unexpect_t, initializer_list<U>, Args&&...);

  // X.Z.4.2, destructor
  ~expected();

  // X.Z.4.3, assignment
  expected& operator=(const expected&);
  expected& operator=(expected&&) noexcept(see below);
  template <class U> expected& operator=(U&&);
    expected& operator=(const unexpected_type<E>&);
  expected& operator=(unexpected_type<E>&&) noexcept(see below);
  template <class... Args>
    void emplace(Args&&...);
  template <class U, class... Args>
    void emplace(initializer_list<U>, Args&&...);

  // X.Z.4.4, swap
  void swap(expected&) noexcept(see below);

  // X.Z.4.5, observers
  constexpr const T* operator ->() const;
  T* operator ->();
  constexpr const T& operator *() const&;
  T& operator *() &;
  constexpr const T&& operator *() const &&;
  constexpr T&& operator *() &&;
  constexpr explicit operator bool() const noexcept;
  constexpr bool has_value() const noexcept;
  constexpr const T& value() const&;
  constexpr T& value() &;
  constexpr const T&& value() const &&;
  constexpr T&& value() &&;
  constexpr const E& error() const&;
  E& error() &;
  constexpr E&& error() &&;
  constexpr const E&& error() const &&;
  constexpr unexpected_type<E> get_unexpected() const;
  template <class U>
    constexpr T value_or(U&&) const&;
  template <class U>
    T value_or(U&&) &&;

private:
  bool has_value; // exposition only
  union
  {
    value_type val; // exposition only
    error_type err; // exposition only
  };
};
~~~
</td><td>
~~~{.cpp}
template <class T, class E>
class expected
{
public:
  typedef T value_type;
  typedef E error_type;
  template <class U>
    struct rebind {
      using type = expected<U, error_type>;
    };
    
  // X.Z.4.1, constructors
  constexpr expected() noexcept(see below);
  expected(const expected&);
  expected(expected&&) noexcept(see below);
  constexpr expected(const T&);
  constexpr expected(T&&);
  template <class... Args>
    constexpr explicit expected(in_place_t, Args&&...);
  template <class U, class... Args>
    constexpr explicit expected(in_place_t, initializer_list<U>, Args&&...);
  constexpr expected(unexpected_type<E> const&);
  template <class Err>
    constexpr expected(unexpected_type<Err> const&);
  template <class... Args>
    constexpr explicit expected(unexpect_t, Args&&...);
  template <class U, class... Args>
    constexpr explicit expected(unexpect_t, initializer_list<U>, Args&&...);

  // X.Z.4.2, destructor
  ~expected();

  // X.Z.4.3, assignment
  expected& operator=(const expected&);
  expected& operator=(expected&&) noexcept(see below);
  template <class U> expected& operator=(U&&);
    expected& operator=(const unexpected_type<E>&);
  expected& operator=(unexpected_type<E>&&) noexcept(see below);
  template <class... Args>
    void emplace(Args&&...);
  template <class U, class... Args>
    void emplace(initializer_list<U>, Args&&...);

  // X.Z.4.4, swap
  void swap(expected&) noexcept(see below);

  // X.Z.4.5, observers
  constexpr const T* operator ->() const;
  T* operator ->();
  constexpr const T& operator *() const&;
  T& operator *() &;
  constexpr const T&& operator *() const &&;
  constexpr T&& operator *() &&;
  constexpr explicit operator bool() const noexcept;
  constexpr bool has_value() const noexcept;
  constexpr const T& value() const&;
  constexpr T& value() &;
  constexpr const T&& value() const &&;
  constexpr T&& value() &&;
  constexpr const E& error() const&;
  E& error() &;
  constexpr E&& error() &&;
  constexpr const E&& error() const &&;
  constexpr unexpected_type<E> get_unexpected() const;
  template <class U>
    constexpr T value_or(U&&) const&;
  template <class U>
    T value_or(U&&) &&;

private:
  bool has_value; // exposition only
  union
  {
    value_type val; // exposition only
    error_type err; // exposition only
  };
};
~~~
</td></tr>
</table>

\section synopsis_bad_expected_access bad_expected_access<E>

<table>
<tr><th>LEWG's Expected implementation</th><th>Outcome's Expected implementation</th></tr>
<tr><td>
~~~{.cpp}
template <class E>
class bad_expected_access : public logic_error {
public:
  explicit bad_expected_access(E);

  constexpr error_type const& error() const;
  error_type& error();
};
~~~
</td><td>
~~~{.cpp}
template <class E>
class bad_expected_access : public logic_error {
public:
  explicit bad_expected_access(E) noexcept;       // noexcept as this type is thrown as a C++ exception

  const error_type &error() const & noexcept;     // No point in these being constexpr due to inheriting logic_error
  error_type &error() & noexcept;
  const error_type &&error() const && noexcept;
  error_type &&error() && noexcept;
};
~~~
</td></tr>
</table>
