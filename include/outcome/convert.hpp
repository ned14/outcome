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
  /*! Converts a value type.
  \requires That `U::value_type` exists and `std::is_constructible<typename T::value_type, typename U::value_type>::value` is true;
  That `std::declval<U>().value()` exists.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_constructible<typename T::value_type, typename std::decay_t<U>::value_type>::value),  //
                    OUTCOME_TEXPR(std::declval<U>().value()))
  constexpr inline typename T::value_type value_type(U &&v) { return typename T::value_type(std::forward<U>(v).value()); }

  /*! Converts a value type.
  \requires That `U::value_type` exists and `std::is_void<typename U::value_type>::value` and
  `std::is_default_constructible<typename T::value_type>::value` is true.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_default_constructible<typename T::value_type>::value &&std::is_void<typename std::decay_t<U>::value_type>::value))
  constexpr inline detail::void_type value_type(U && /* unused */) { return detail::void_type{}; }

  /*! Converts an error type.
  \requires That `U::error_type` exists and `std::is_constructible<typename T::error_type, typename U::error_type>::value` is true;
  That `std::declval<U>().error()` exists.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_constructible<typename T::error_type, typename std::decay_t<U>::error_type>::value),  //
                    OUTCOME_TEXPR(std::declval<U>().error()))
  constexpr inline typename T::error_type error_type(U &&v) { return typename T::error_type(std::forward<U>(v).error()); }

  /*! Converts an error type.
  \requires That `U::error_type` exists and `std::is_void<typename U::error_type>::value` and
  `std::is_default_constructible<typename T::error_type>::value` is true.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_default_constructible<typename T::error_type>::value &&std::is_void<typename std::decay_t<U>::error_type>::value))
  constexpr inline detail::void_type error_type(U && /* unused */) { return detail::void_type{}; }

  /*! Converts an exception type.
  \requires That `U::exception_type` exists and `std::is_constructible<typename T::exception_type, typename U::exception_type>::value` is true;
  That `std::declval<U>().exception()` exists.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_constructible<typename T::exception_type, typename std::decay_t<U>::exception_type>::value),  //
                    OUTCOME_TEXPR(std::declval<U>().exception()))
  constexpr inline typename T::exception_type exception_type(U &&v) { return typename T::exception_type(std::forward<U>(v).exception()); }

  /*! Converts an exception type.
  \requires That `U::exception_type` exists and `std::is_void<typename U::exception_type>::value` and
  `std::is_default_constructible<typename T::exception_type>::value` is true.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_default_constructible<typename T::exception_type>::value &&std::is_void<typename std::decay_t<U>::exception_type>::value))
  constexpr inline detail::void_type exception_type(U && /* unused */) { return detail::void_type{}; }
}  // namespace convert

OUTCOME_V2_NAMESPACE_END

#endif
