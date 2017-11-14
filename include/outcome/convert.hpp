/* Says how to convert value, error and exception types
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Nov 2017


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

#ifndef OUTCOME_CONVERT_HPP
#define OUTCOME_CONVERT_HPP

#include "success_failure.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for injected convertibility
namespace convert
{
#ifdef __cpp_concepts
  /* The `ValueOrNone` concept.
  \requires That `U::value_type` exists and that `std::declval<U>().has_value()` returns a `bool` and `std::declval<U>().value()` exists.
  */
  template <class U> concept ValueOrNone = requires(U a)
  {
    {
      a.has_value()
    }
    ->bool;
    {a.value()};
  };
  /* The `ValueOrError` concept.
  \requires That `U::value_type` and `U::error_type` exist;
  that `std::declval<U>().has_value()` returns a `bool`, `std::declval<U>().value()` and  `std::declval<U>().error()` exists.
  */
  template <class U> concept ValueOrError = requires(U a)
  {
    {
      a.has_value()
    }
    ->bool;
    {a.value()};
    {a.error()};
  };
#else
  namespace detail
  {
    struct no_converter
    {
    };
    inline no_converter value_or_none(...);
    inline no_converter value_or_error(...);
    template <class U> static constexpr bool ValueOrNone = std::is_same<no_converter, decltype(value_or_none(std::declval<U>()))>::value;
    template <class U> static constexpr bool ValueOrError = std::is_same<no_converter, decltype(value_or_error(std::declval<U>()))>::value;
  }
  template <class U> static constexpr bool ValueOrNone = detail::ValueOrNone<U>;
  template <class U> static constexpr bool ValueOrError = detail::ValueOrError<U>;
#endif

  namespace detail
  {
    template <class T, class X> struct make_type
    {
      template <class U> static constexpr T value(U &&v) { return T{in_place_type<typename T::value_type>, std::forward<U>(v).value()}; }
      template <class U> static constexpr T error(U &&v) { return T{in_place_type<typename T::error_type>, std::forward<U>(v).error()}; }
      static constexpr T error() { return T{in_place_type<typename T::error_type>}; }
    };
    template <class T> struct make_type<T, void>
    {
      template <class U> static constexpr T value(U && /*unused*/) { return T{in_place_type<typename T::value_type>}; }
      template <class U> static constexpr T error(U && /*unused*/) { return T{in_place_type<typename T::error_type>}; }
      static constexpr T error() { return T{in_place_type<typename T::error_type>}; }
    };
  }

  /*! Converts a something matching the `ValueOrNone` concept.
  \requires `ValueOrNone<U>` and `U`'s `value_type` be constructible into `T`'s `value_type`.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(ValueOrNone<U> && (std::is_void<typename std::decay_t<U>::value_type>::value || OUTCOME_V2_NAMESPACE::detail::is_same_or_constructible<typename T::value_type, typename std::decay_t<U>::value_type>) ))
  constexpr inline T value_or_none(U &&v) { return v.has_value() ? detail::make_type<T, typename T::value_type>::value(std::forward<U>(v)) : detail::make_type<T, void>::error(); }

  /*! Converts a something matching the `ValueOrError` concept.
  \requires `ValueOrNone<U>`, `U`'s `value_type` be constructible into `T`'s `value_type`
  and `U`'s `error_type` be constructible into `T`'s `error_type`.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(ValueOrError<U>                                                                                                                                                                         //
                                  && (std::is_void<typename std::decay_t<U>::value_type>::value || OUTCOME_V2_NAMESPACE::detail::is_same_or_constructible<typename T::value_type, typename std::decay_t<U>::value_type>)  //
                                  &&(std::is_void<typename std::decay_t<U>::error_type>::value || OUTCOME_V2_NAMESPACE::detail::is_same_or_constructible<typename T::error_type, typename std::decay_t<U>::error_type>) ))
  constexpr inline T value_or_error(U &&v) { return v.has_value() ? detail::make_type<T, typename T::value_type>::value(std::forward<U>(v)) : detail::make_type<T, typename std::decay_t<U>::error_type>::error(std::forward<U>(v)); }

}  // namespace convert

OUTCOME_V2_NAMESPACE_END

#endif
