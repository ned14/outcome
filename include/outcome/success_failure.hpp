/* Type sugar for success and failure
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: July 2017


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
(See accompanying file Licence.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef OUTCOME_SUCCESS_FAILURE_HPP
#define OUTCOME_SUCCESS_FAILURE_HPP

#include "config.hpp"

#include <exception>
#include <system_error>
#include <type_traits>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  // Replace void with constructible void_type
  struct empty_type
  {
  };
  struct void_type
  {
    // We always compare true to another instance of me
    constexpr bool operator==(void_type /*unused*/) const noexcept { return true; }
    constexpr bool operator!=(void_type /*unused*/) const noexcept { return false; }
  };
  template <class T> using devoid = std::conditional_t<std::is_void<T>::value, void_type, T>;

  template <class Output, class Input> using rebind_type5 = Output;
  template <class Output, class Input>
  using rebind_type4 = std::conditional_t<                                   //
  std::is_volatile<Input>::value,                                            //
  std::add_volatile_t<rebind_type5<Output, std::remove_volatile_t<Input>>>,  //
  rebind_type5<Output, Input>>;
  template <class Output, class Input>
  using rebind_type3 = std::conditional_t<                             //
  std::is_const<Input>::value,                                         //
  std::add_const_t<rebind_type4<Output, std::remove_const_t<Input>>>,  //
  rebind_type4<Output, Input>>;
  template <class Output, class Input>
  using rebind_type2 = std::conditional_t<                                            //
  std::is_lvalue_reference<Input>::value,                                             //
  std::add_lvalue_reference_t<rebind_type3<Output, std::remove_reference_t<Input>>>,  //
  rebind_type3<Output, Input>>;
  template <class Output, class Input>
  using rebind_type = std::conditional_t<                                             //
  std::is_rvalue_reference<Input>::value,                                             //
  std::add_rvalue_reference_t<rebind_type2<Output, std::remove_reference_t<Input>>>,  //
  rebind_type2<Output, Input>>;

  // static_assert(std::is_same_v<rebind_type<int, volatile const double &&>, volatile const int &&>, "");
}  // namespace detail

//! Namespace for policies
namespace policy
{
  namespace detail
  {
    struct error_code_passthrough
    {
    };
    /* Pass through `make_error_code` function for anything implicitly convertible to `std::error_code`.
    \requires `T` is implicitly convertible to `std::error_code`.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_convertible<T, std::error_code>::value))
    constexpr inline decltype(auto) make_error_code(T &&v, error_code_passthrough /*unused*/ = {}) { return std::forward<T>(v); }

    template <size_t N, class T> constexpr inline void get(const T & /*unused*/);
    struct tuple_passthrough
    {
    };
    /* Pass through `make_error_code` function for any pair or tuple returning the first item.
    \requires That `make_error_code(std::get<0>(std::declval<T>()))` is a valid expression.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(make_error_code(get<0>(std::declval<T>()))))
    constexpr inline decltype(auto) make_error_code(T &&v, tuple_passthrough /* unused */ = {}) { return make_error_code(get<0>(std::forward<T>(v))); }

    /* Pass through `make_exception_ptr` function for `std::exception_ptr`.
    */
    inline std::exception_ptr make_exception_ptr(std::exception_ptr v) { return v; }

    template <class T> constexpr inline decltype(auto) error_code(T &&v) { return make_error_code(std::forward<T>(v)); }
    template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return make_exception_ptr(std::forward<T>(v)); }
  }  // namespace detail
  //! Used by policies to extract a `std::error_code` from some input `T` via ADL discovery of some `make_error_code(T)` function.
  template <class T> constexpr inline decltype(auto) error_code(T &&v) { return detail::error_code(std::forward<T>(v)); }
  //! Used by policies to extract a `std::exception_ptr` from some input `T` via ADL discovery of some `make_exception_ptr(T)` function.
  template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return detail::exception_ptr(std::forward<T>(v)); }

  //! Override to define what the policies which throw a system error with payload ought to do for some particular `result.error()`.
  template <class Error> constexpr inline void throw_as_system_error_with_payload(const Error &error)
  {
    (void) error;
    static_assert(std::is_convertible<Error, std::error_code>::value || std::is_error_code_enum<std::decay_t<Error>>::value || std::is_error_condition_enum<std::decay_t<Error>>::value,
                  "To use the error_code_throw_as_system_error policy with a custom Error type, you must define a throw_as_system_error_with_payload() free function to say how to handle the payload");
    OUTCOME_THROW_EXCEPTION(std::system_error(error_code(error)));
  }
}  // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;
    template <size_t N, class T> constexpr inline void get(const T & /*unused*/);
    constexpr inline void make_error_code(...);
    // Also enable for any pair or tuple whose first item satisfies make_error_code()
    template <class T,                                                        //
              class R = decltype(make_error_code(get<0>(std::declval<T>())))  //
              >
    constexpr inline R make_error_code(T &&);
    template <class T, typename V = decltype(make_error_code(std::declval<devoid<T>>()))> struct has_error_code : std::integral_constant<bool, std::is_base_of<std::error_code, std::decay_t<V>>::value || std::is_convertible<T, std::error_code>::value>
    {
    };
    constexpr inline void make_exception_ptr(...);
    template <class T, typename V = decltype(make_exception_ptr(std::declval<devoid<T>>()))> struct has_exception_ptr : std::integral_constant<bool, std::is_base_of<std::exception_ptr, std::decay_t<V>>::value || std::is_convertible<T, std::exception_ptr>::value>
    {
    };
  }  // namespace detail
  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */
  template <class T> struct has_error_code : detail::has_error_code<T>
  {
  };
  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */
  template <class T> constexpr bool has_error_code_v = has_error_code<T>::value;

  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */
  template <class T> struct has_exception_ptr : detail::has_exception_ptr<T>
  {
  };
  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */
  template <class T> constexpr bool has_exception_ptr_v = has_exception_ptr<T>::value;

}  // namespace trait

/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <class T> struct success_type
{
  //! The type of the successful state.
  using value_type = T;

private:
  //! The value of the successful state.
  value_type _value;

public:
  //! Default constructor
  constexpr success_type() = default;
  //! Copy constructor
  constexpr success_type(const success_type &) = default;
  //! Move constructor
  constexpr success_type(success_type &&) = default;
  //! Initialising constructor
  template <class U>
  constexpr explicit success_type(U &&v)
      : _value(std::forward<U>(v))
  {
  }

  /*! Access value.
  \returns Reference to the held `value_type` according to overload.
  \group value
  */
  constexpr value_type &value() & { return _value; }
  /// \group value
  constexpr const value_type &value() const & { return _value; }
  /// \group value
  constexpr value_type &&value() && { return std::move(_value); }
  /// \group value
  constexpr const value_type &&value() const && { return std::move(_value); }
};
/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <> struct success_type<void>
{
  //! The type of the successful state.
  using value_type = void;
};
/*! Returns type sugar for implicitly constructing a `result<T>` with a successful state,
default constructing `T` if necessary.
*/
inline constexpr success_type<void> success() noexcept
{
  return success_type<void>{};
}
/*! Returns type sugar for implicitly constructing a `result<T>` with a successful state.
\effects Copies or moves the successful state supplied into the returned type sugar.
*/
template <class T> inline constexpr success_type<std::decay_t<T>> success(T &&v)
{
  return success_type<std::decay_t<T>>{std::forward<T>(v)};
}

/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code and exception.
*/
template <class EC = std::error_code, class E = void> struct failure_type
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the exception
  using exception_type = E;

private:
  //! The error code
  error_type _error;
  //! The exception
  exception_type _exception;

public:
  //! Default constructor
  constexpr failure_type() = default;
  //! Copy constructor
  constexpr failure_type(const failure_type &) = default;
  //! Move constructor
  constexpr failure_type(failure_type &&) = default;
  //! Initialising constructor
  template <class U, class V>
  constexpr explicit failure_type(U &&u, V &&v)
      : _error(std::forward<U>(u))
      , _exception(std::forward<V>(v))
  {
  }

  /*! Access error.
  \returns Reference to the held `error_type` according to overload.
  \group error
  */
  constexpr error_type &error() & { return _error; }
  /// \group error
  constexpr const error_type &error() const & { return _error; }
  /// \group error
  constexpr error_type &&error() && { return std::move(_error); }
  /// \group error
  constexpr const error_type &&error() const && { return std::move(_error); }

  /*! Access exception.
  \returns Reference to the held `exception_type` according to overload.
  \group exception
  */
  constexpr exception_type &exception() & { return _exception; }
  /// \group exception
  constexpr const exception_type &exception() const & { return _exception; }
  /// \group exception
  constexpr exception_type &&exception() && { return std::move(_exception); }
  /// \group exception
  constexpr const exception_type &&exception() const && { return std::move(_exception); }
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code.
*/
template <class EC> struct failure_type<EC, void>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the exception
  using exception_type = void;

private:
  //! The error code
  error_type _error;

public:
  //! Default constructor
  constexpr failure_type() = default;
  //! Copy constructor
  constexpr failure_type(const failure_type &) = default;
  //! Move constructor
  constexpr failure_type(failure_type &&) = default;
  //! Initialising constructor
  template <class U>
  constexpr explicit failure_type(U &&u)
      : _error(std::forward<U>(u))
  {
  }

  /*! Access error.
  \returns Reference to the held `error_type` according to overload.
  \group error2
  */
  constexpr error_type &error() & { return _error; }
  /// \group error2
  constexpr const error_type &error() const & { return _error; }
  /// \group error2
  constexpr error_type &&error() && { return std::move(_error); }
  /// \group error2
  constexpr const error_type &&error() const && { return std::move(_error); }
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of exception.
*/
template <class E> struct failure_type<void, E>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the exception
  using exception_type = E;

private:
  //! The exception
  exception_type _exception;

public:
  //! Default constructor
  constexpr failure_type() = default;
  //! Copy constructor
  constexpr failure_type(const failure_type &) = default;
  //! Move constructor
  constexpr failure_type(failure_type &&) = default;
  //! Initialising constructor
  template <class V>
  constexpr explicit failure_type(V &&v)
      : _exception(std::forward<V>(v))
  {
  }

  /*! Access exception.
  \returns Reference to the held `exception_type` according to overload.
  \group exception2
  */
  constexpr exception_type &exception() & { return _exception; }
  /// \group exception2
  constexpr const exception_type &exception() const & { return _exception; }
  /// \group exception2
  constexpr exception_type &&exception() && { return std::move(_exception); }
  /// \group exception2
  constexpr const exception_type &&exception() const && { return std::move(_exception); }
};
/*! Returns type sugar for implicitly constructing a `result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
*/
template <class EC> inline constexpr failure_type<std::decay_t<EC>> failure(EC &&v)
{
  return failure_type<std::decay_t<EC>>{std::forward<EC>(v)};
}
/*! Returns type sugar for implicitly constructing a `result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
*/
template <class EC, class E> inline constexpr failure_type<std::decay_t<EC>, std::decay_t<E>> failure(EC &&v, E &&w)
{
  return failure_type<std::decay_t<EC>, std::decay_t<E>>{std::forward<EC>(v), std::forward<E>(w)};
}

namespace detail
{
  template <class T> struct is_success_type : std::false_type
  {
  };
  template <class T> struct is_success_type<success_type<T>> : std::true_type
  {
  };
  template <class T> struct is_failure_type : std::false_type
  {
  };
  template <class EC, class E> struct is_failure_type<failure_type<EC, E>> : std::true_type
  {
  };
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
