/* Traits for Outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: March 2018


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

#ifndef OUTCOME_TRAIT_SYSTEM_ERROR_HPP
#define OUTCOME_TRAIT_SYSTEM_ERROR_HPP

#include "config.hpp"

#include <exception>
#include <system_error>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  // Customise _set_error_is_errno
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_code &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_condition &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::errc & /*unused*/) { state._status |= status_error_is_errno; }

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

  // std::error_code and std::exception_ptr are error types
  template <> struct is_error_type<std::error_code>
  {
    static constexpr bool value = true;
  };
  template <> struct is_error_type<std::exception_ptr>
  {
    static constexpr bool value = true;
  };
  // For std::error_code, std::is_error_condition_enum<> is the trait we want.
  template <class Enum> struct is_error_type_enum<std::error_code, Enum>
  {
    static constexpr bool value = std::is_error_condition_enum<Enum>::value;
  };

}  // namespace trait


OUTCOME_V2_NAMESPACE_END

#endif
