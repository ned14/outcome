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

#include "config.hpp"

OUTCOME_V2_NAMESPACE_BEGIN

/*! Customisation point for changing what the `OUTCOME_TRY` macros
do. This function defaults to returning `std::move(v).as_void()`.
\effects Extracts any state apart from value into a `void` rebound equivalent.
\requires The input value to have a `.as_void()` member function.
*/
template <class T> typename T::template rebind<void> try_operation_return_as(T &&v)
{
  return std::move(v).as_void();
}

OUTCOME_V2_NAMESPACE_END

#define OUTCOME_TRY_GLUE2(x, y) x##y
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(__t, __COUNTER__)

#define OUTCOME_TRYV2(unique, m)                                                                                                                                                                                                                                                                                               \
  decltype(auto) unique = (m);                                                                                                                                                                                                                                                                                                 \
  if(!unique.has_value())                                                                                                                                                                                                                                                                                                      \
  return OUTCOME_V2_NAMESPACE::try_operation_return_as(std::move(unique))
#define OUTCOME_TRY2(unique, v, m)                                                                                                                                                                                                                                                                                             \
  OUTCOME_TRYV2(unique, m);                                                                                                                                                                                                                                                                                                    \
  auto v(std::move(std::move(unique).value()))

/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure state immediately
*/
#define OUTCOME_TRYV(m) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, m)

#if defined(__GNUC__) || defined(__clang__)

/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure state immediately, else become the
unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression
which can be used exactly like the `try` operator in other languages.

\note This macro makes use of a proprietary extension in GCC and clang and is not
portable. The macro is not made available on unsupported compilers,
so you can test for its presence using `#ifdef OUTCOME_TRYX`.
*/
#define OUTCOME_TRYX(m)                                                                                                                                                                                                                                                                                                        \
  ({                                                                                                                                                                                                                                                                                                                           \
    decltype(auto) res = (m);                                                                                                                                                                                                                                                                                                  \
    if(!res.has_value())                                                                                                                                                                                                                                                                                                       \
      return OUTCOME_V2_NAMESPACE::try_operation_return_as(std::move(res));                                                                                                                                                                                                                                                    \
    std::move(res.value());                                                                                                                                                                                                                                                                                                    \
  \
})
#endif

/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure immediately, else set *v( to the unwrapped value
*/
#define OUTCOME_TRY(v, m) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, m)

#endif
