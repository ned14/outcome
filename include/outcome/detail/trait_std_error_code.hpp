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

#ifndef OUTCOME_TRAIT_STD_ERROR_CODE_HPP
#define OUTCOME_TRAIT_STD_ERROR_CODE_HPP

#include "../config.hpp"

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
    struct std_enum_overload_tag
    {
    };
  }  // namespace detail

  //! Override to define what the policies which throw a system error with payload ought to do for some particular `result.error()`.
  // inline void outcome_throw_as_system_error_with_payload(...) = delete;  // To use the error_code_throw_as_system_error policy with a custom Error type, you must define a outcome_throw_as_system_error_with_payload() free function to say how to handle the payload
  inline void outcome_throw_as_system_error_with_payload(const std::error_code &error) { OUTCOME_THROW_EXCEPTION(std::system_error(error)); }
  OUTCOME_TEMPLATE(class Error)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_error_code_enum<std::decay_t<Error>>::value || std::is_error_condition_enum<std::decay_t<Error>>::value))
  inline void outcome_throw_as_system_error_with_payload(Error &&error, detail::std_enum_overload_tag = detail::std_enum_overload_tag()) { OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error))); }
}  // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;

    constexpr inline void make_error_code(...);
    // Also enable for any pair or tuple whose first item satisfies make_error_code()
    template <size_t N, class T> constexpr inline void get(const T & /*unused*/);
    template <class T,                                                        //
              class R = decltype(make_error_code(get<0>(std::declval<T>())))  //
              >
    constexpr inline R make_error_code(T &&);

    template <class T, typename V = std::decay_t<decltype(make_error_code(std::declval<devoid<T>>()))>> struct has_error_code
    {
      static constexpr bool value = false;
    };
    template <> struct has_error_code<std::error_code, void>
    {
      static constexpr bool value = true;
    };
    template <class T> struct has_error_code<T, std::error_code>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail

  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */
  template <class T> struct has_error_code : detail::has_error_code<std::decay_t<T>>
  {
  };
  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */
  template <class T> constexpr bool has_error_code_v = has_error_code<std::decay_t<T>>::value;

  // std::error_code is an error type
  template <> struct is_error_type<std::error_code>
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
