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

OUTCOME_V2_NAMESPACE_BEGIN

/*! Customisation point for changing what the `OUTCOME_TRY` macros
do. This function defaults to returning `std::forward<T>(v).as_failure()`.
\effects Extracts any state apart from value into a `failure_type`.
\requires The input value to have a `.as_failure()` member function.
*/
template <class T> OUTCOME_REQUIRES(requires(T &&v){{v.as_failure()}}) decltype(auto) try_operation_return_as(T &&v)
{
  return std::forward<T>(v).as_failure();
}

OUTCOME_V2_NAMESPACE_END

//! \exclude
#define OUTCOME_TRY_GLUE2(x, y) x##y
//! \exclude
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
//! \exclude
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(_outcome_try_unique_name_temporary, __COUNTER__)

//! \exclude
#define OUTCOME_TRY_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
//! \exclude
#define OUTCOME_TRY_EXPAND_ARGS(args) OUTCOME_TRY_RETURN_ARG_COUNT args
//! \exclude
#define OUTCOME_TRY_COUNT_ARGS_MAX8(...) OUTCOME_TRY_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO2(name, count) name##count
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO1(name, count) OUTCOME_TRY_OVERLOAD_MACRO2(name, count)
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO(name, count) OUTCOME_TRY_OVERLOAD_MACRO1(name, count)
//! \exclude
#define OUTCOME_TRY_OVERLOAD_GLUE(x, y) x y
//! \exclude
#define OUTCOME_TRY_CALL_OVERLOAD(name, ...) OUTCOME_TRY_OVERLOAD_GLUE(OUTCOME_TRY_OVERLOAD_MACRO(name, OUTCOME_TRY_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))


//! \exclude
#define OUTCOME_TRYV2(unique, ...)                                                                                                                                                                                                                                                                                             \
  auto && (unique) = (__VA_ARGS__);                                                                                                                                                                                                                                                                                            \
  if(!(unique).has_value())                                                                                                                                                                                                                                                                                                    \
  return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique))
//! \exclude
#define OUTCOME_TRY2(unique, v, ...)                                                                                                                                                                                                                                                                                           \
  OUTCOME_TRYV2(unique, __VA_ARGS__);                                                                                                                                                                                                                                                                                          \
  auto && (v) = static_cast<decltype(unique) &&>(unique).value()

/*! If the outcome returned by expression ... is not valued, propagate any
failure by immediately returning that failure state immediately
*/
#define OUTCOME_TRYV(...) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)

/*! If the outcome returned by expression ... is not valued, propagate any
failure by immediately returning that failure state immediately, else become the
unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression
which can be used exactly like the `try` operator in other languages.

\remarks This macro makes use of a proprietary extension in GCC and clang and is not
portable. The macro is not made available on unsupported compilers,
so you can test for its presence using `#ifdef OUTCOME_TRYX`.
*/
#define OUTCOME_TRYX(...)                                                                                                                                                                                                                                                                                                      \
  ({                                                                                                                                                                                                                                                                                                                           \
    auto &&res = (__VA_ARGS__);                                                                                                                                                                                                                                                                                                \
    if(!res.has_value())                                                                                                                                                                                                                                                                                                       \
      return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(res) &&>(res));                                                                                                                                                                                                                                \
    static_cast<decltype(res) &&>(res).value();                                                                                                                                                                                                                                                                                \
  \
})
#endif

/*! If the outcome returned by expression ... is not valued, propagate any
failure by immediately returning that failure immediately, else set *auto v* to the unwrapped value.
*/
#define OUTCOME_TRYA(v, ...) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, __VA_ARGS__)

//! \exclude
#define OUTCOME_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_TRYA(a, b, c, d, e, f, g, h)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_TRYA(a, b, c, d, e, f, g)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_TRYA(a, b, c, d, e, f)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_TRYA(a, b, c, d, e)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME_TRYA(a, b, c, d)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY3(a, b, c) OUTCOME_TRYA(a, b, c)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY2(a, b) OUTCOME_TRYA(a, b)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY1(a) OUTCOME_TRYV(a)
/*! This uses C macro overloading to select between `OUTCOME_TRYV(...)` and `OUTCOME_TRYA(v, ...)`
based on whether there is one or two or more arguments to the macro.

It can surprise people as template parameters are not recognised by the C preprocessor. For example:

```c++
OUTCOME_TRY(foo<int, long>());
```

Here the programmer obviously intends this to be an `OUTCOME_TRYV(...)`, but the C macro overload
mechanism will perceive this as setting the variable `foo<int,` to the result of the function call
`long>()`. This will fail to compile.

One solution is to simply wrap all function calls with brackets so the C preprocessor breaks
them correctly e.g.

```c++
OUTCOME_TRY((foo<int, long>()));
OUTCOME_TRY(foovalue, (foo<int, long>()));
```

This solution also avoids ever exceeding eight C macro input parameters, as overloading is
only implemented up to eight parameters.

The other solution is to call `OUTCOME_TRYV` or `OUTCOME_TRYA` directly as appropriate.
*/
#define OUTCOME_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_INVOKE_TRY, __VA_ARGS__)

#endif
