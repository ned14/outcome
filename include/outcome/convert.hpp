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

#include "detail/result_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for injected convertibility
namespace convert
{
#ifdef __cpp_concepts
  /* The `ValueOrNone` concept.
  \requires That `U::value_type` exists and that `std::declval<U>().has_value()` returns a `bool` and `std::declval<U>().value()` exists.
  */
  template <class U> concept bool ValueOrNone = requires(U a)
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
  template <class U> concept bool ValueOrError = requires(U a)
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
    struct no_match
    {
    };
    inline no_match match_value_or_none(...);
    inline no_match match_value_or_error(...);
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<U>().has_value()), OUTCOME_TEXPR(std::declval<U>().value()))
    inline U match_value_or_none(U &&);
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<U>().has_value()), OUTCOME_TEXPR(std::declval<U>().value()), OUTCOME_TEXPR(std::declval<U>().error()))
    inline U match_value_or_error(U &&);

    template <class U> static constexpr bool ValueOrNone = !std::is_same<no_match, decltype(match_value_or_none(std::declval<OUTCOME_V2_NAMESPACE::detail::devoid<U>>()))>::value;
    template <class U> static constexpr bool ValueOrError = !std::is_same<no_match, decltype(match_value_or_error(std::declval<OUTCOME_V2_NAMESPACE::detail::devoid<U>>()))>::value;
  }  // namespace detail
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
  }  // namespace detail

  /*! Default converter for types matching the `ValueOrError` concept.
  You can partially or fully specialise this converter for your own user defined types by
  injecting specialisations into the `convert` namespace.
  */
  template <class T, class U> struct value_or_error
  {
    //! False to indicate that this converter wants `result`/`outcome` to reject all other `result`
    static constexpr bool enable_result_inputs = false;
    //! False to indicate that this converter wants `outcome` to reject all other `outcome`
    static constexpr bool enable_outcome_inputs = false;
    /*! Default converter for types matching the `ValueOrError` concept.
    \requires `std::decay_t<X>` to be the same type as `U`;
    `ValueOrError<U>` to be true, `U`'s `value_type` be constructible into `T`'s `value_type`
    and `U`'s `error_type` be constructible into `T`'s `error_type`.
    */
    OUTCOME_TEMPLATE(class X)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_same<U, std::decay_t<X>>::value                                                                                                                                                 //
                                    &&ValueOrError<U>                                                                                                                                                                       //
                                    && (std::is_void<typename std::decay_t<X>::value_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::value_type, typename std::decay_t<X>::value_type>)  //
                                    &&(std::is_void<typename std::decay_t<X>::error_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::error_type, typename std::decay_t<X>::error_type>) ))
    constexpr T operator()(X &&v) { return v.has_value() ? detail::make_type<T, typename T::value_type>::value(std::forward<X>(v)) : detail::make_type<T, typename U::error_type>::error(std::forward<X>(v)); }
  };
}  // namespace convert

OUTCOME_V2_NAMESPACE_END

#endif
