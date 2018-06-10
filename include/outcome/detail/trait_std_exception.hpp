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

#ifndef OUTCOME_TRAIT_STD_EXCEPTION_HPP
#define OUTCOME_TRAIT_STD_EXCEPTION_HPP

#include "../config.hpp"

#include <exception>

OUTCOME_V2_NAMESPACE_BEGIN

//! Namespace for policies
namespace policy
{
  namespace detail
  {
    /* Pass through `make_exception_ptr` function for `std::exception_ptr`.
    */
    inline std::exception_ptr make_exception_ptr(std::exception_ptr v) { return v; }

    // Try ADL, if not use fall backs above
    template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return make_exception_ptr(std::forward<T>(v)); }
  }  // namespace detail

  //! Used by policies to extract a `std::exception_ptr` from some input `T` via ADL discovery of some `make_exception_ptr(T)` function.
  template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return detail::exception_ptr(std::forward<T>(v)); }

  namespace detail
  {
    template <bool has_error_payload> struct _rethrow_exception
    {
      template <class Exception> explicit _rethrow_exception(Exception && /*unused*/)  // NOLINT
      {
      }
    };
    template <> struct _rethrow_exception<true>
    {
      template <class Exception> explicit _rethrow_exception(Exception &&excpt)  // NOLINT
      {
        // ADL
        rethrow_exception(policy::exception_ptr(std::forward<Exception>(excpt)));
      }
    };
  }  // namespace detail
}  // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;

    constexpr inline void make_exception_ptr(...);
    template <class T, typename V = std::decay_t<decltype(make_exception_ptr(std::declval<devoid<T>>()))>> struct has_exception_ptr
    {
      static constexpr bool value = false;
    };
    template <> struct has_exception_ptr<std::exception_ptr, void>
    {
      static constexpr bool value = true;
    };
    template <class T> struct has_exception_ptr<T, std::exception_ptr>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail

  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */
  template <class T> struct has_exception_ptr : detail::has_exception_ptr<std::decay_t<T>>
  {
  };
  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */
  template <class T> constexpr bool has_exception_ptr_v = has_exception_ptr<std::decay_t<T>>::value;

  // std::exception_ptr is an error type
  template <> struct is_error_type<std::exception_ptr>
  {
    static constexpr bool value = true;
  };

}  // namespace trait

OUTCOME_V2_NAMESPACE_END

#endif
