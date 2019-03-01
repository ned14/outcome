/* Try operation macros
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

#ifndef OUTCOME_TRY_HPP
#define OUTCOME_TRY_HPP

#include "success_failure.hpp"

namespace std  // NOLINT
{
  namespace experimental
  {
    template <class T, class E> class expected;
    template <class E> class unexpected;
  }  // namespace experimental
}  // namespace std

OUTCOME_V2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().as_failure()))
inline decltype(auto) try_operation_return_as(T &&v)
{
  return static_cast<T &&>(v).as_failure();
}
/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
template <class T, class E> inline auto try_operation_return_as(const std::experimental::expected<T, E> &v)
{
  return std::experimental::unexpected<E>(v.error());
}
/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
template <class T, class E> inline auto try_operation_return_as(std::experimental::expected<T, E> &&v)
{
  return std::experimental::unexpected<E>(static_cast<std::experimental::expected<T, E> &&>(v).error());
}

namespace detail
{
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().assume_value()))
  inline decltype(auto) try_extract_value(T &&v) { return static_cast<T &&>(v).assume_value(); }

  template <class T, class... Args> inline decltype(auto) try_extract_value(T &&v, Args &&... /*unused*/) { return static_cast<T &&>(v).value(); }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#define OUTCOME_TRY_GLUE2(x, y) x##y
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(_outcome_try_unique_name_temporary, __COUNTER__)

#define OUTCOME_TRY_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define OUTCOME_TRY_EXPAND_ARGS(args) OUTCOME_TRY_RETURN_ARG_COUNT args
#define OUTCOME_TRY_COUNT_ARGS_MAX8(...) OUTCOME_TRY_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define OUTCOME_TRY_OVERLOAD_MACRO2(name, count) name##count
#define OUTCOME_TRY_OVERLOAD_MACRO1(name, count) OUTCOME_TRY_OVERLOAD_MACRO2(name, count)
#define OUTCOME_TRY_OVERLOAD_MACRO(name, count) OUTCOME_TRY_OVERLOAD_MACRO1(name, count)
#define OUTCOME_TRY_OVERLOAD_GLUE(x, y) x y
#define OUTCOME_TRY_CALL_OVERLOAD(name, ...) OUTCOME_TRY_OVERLOAD_GLUE(OUTCOME_TRY_OVERLOAD_MACRO(name, OUTCOME_TRY_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))

#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#endif

#define OUTCOME_TRYV2(unique, ...)                                                                                                                                                                                                                                                                                             \
  auto && (unique) = (__VA_ARGS__);                                                                                                                                                                                                                                                                                            \
  if(!(unique).has_value())                                                                                                                                                                                                                                                                                                    \
  return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique))
#define OUTCOME_TRY2(unique, v, ...)                                                                                                                                                                                                                                                                                           \
  OUTCOME_TRYV2(unique, __VA_ARGS__);                                                                                                                                                                                                                                                                                          \
  auto && (v) = OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(unique) &&>(unique))

#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic pop
#endif

/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV(...) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)

/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYX(...)                                                                                                                                                                                                                                                                                                      \
  ({                                                                                                                                                                                                                                                                                                                           \
    auto &&res = (__VA_ARGS__);                                                                                                                                                                                                                                                                                                \
    if(!res.has_value())                                                                                                                                                                                                                                                                                                       \
      return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(res) &&>(res));                                                                                                                                                                                                                                \
    OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(res) &&>(res));                                                                                                                                                                                                                                       \
  \
})
#endif

/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYA(v, ...) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, __VA_ARGS__)

#define OUTCOME_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_TRYA(a, b, c, d, e, f, g, h)
#define OUTCOME_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_TRYA(a, b, c, d, e, f, g)
#define OUTCOME_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_TRYA(a, b, c, d, e, f)
#define OUTCOME_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_TRYA(a, b, c, d, e)
#define OUTCOME_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME_TRYA(a, b, c, d)
#define OUTCOME_TRY_INVOKE_TRY3(a, b, c) OUTCOME_TRYA(a, b, c)
#define OUTCOME_TRY_INVOKE_TRY2(a, b) OUTCOME_TRYA(a, b)
#define OUTCOME_TRY_INVOKE_TRY1(a) OUTCOME_TRYV(a)
/*! AWAITING HUGO JSON CONVERSION TOOL 
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_INVOKE_TRY, __VA_ARGS__)

#endif
