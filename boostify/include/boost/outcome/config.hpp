/* Configure Boost.Outcome with Boost
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (24 commits)
File Created: August 2015


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

#ifndef BOOST_OUTCOME_V2_CONFIG_HPP
#define BOOST_OUTCOME_V2_CONFIG_HPP

#include "version.hpp"

// Pull in detection of __MINGW64_VERSION_MAJOR
#if defined(__MINGW32__) && !defined(DOXYGEN_IS_IN_THE_HOUSE)
#include <_mingw.h>
#endif

#include <boost/config.hpp>

#ifdef BOOST_NO_CXX11_VARIADIC_TEMPLATES
#error Boost.Outcome needs variadic template support in the compiler
#endif
#if defined(BOOST_NO_CXX14_CONSTEXPR) && _MSC_FULL_VER < 191100000
#error Boost.Outcome needs constexpr (C++ 14) support in the compiler
#endif
#ifdef BOOST_NO_CXX14_VARIABLE_TEMPLATES
#error Boost.Outcome needs variable template support in the compiler
#endif

#ifndef BOOST_OUTCOME_SYMBOL_VISIBLE
#define BOOST_OUTCOME_SYMBOL_VISIBLE BOOST_SYMBOL_VISIBLE
#endif
// Weird that Boost.Config doesn't define a BOOST_NO_CXX17_NODISCARD
#ifndef BOOST_OUTCOME_NODISCARD
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define BOOST_OUTCOME_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define BOOST_OUTCOME_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define BOOST_OUTCOME_NODISCARD                                                                                                                                                                                                                                                                                                \
  __declspec("SAL_name"                                                                                                                                                                                                                                                                                                        \
             "("                                                                                                                                                                                                                                                                                                               \
             "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                       \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"\""                                                                                                                                                                                                                                                                                                            \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"2\""                                                                                                                                                                                                                                                                                                           \
             ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")
#endif
#endif
#ifndef BOOST_OUTCOME_NODISCARD
#define BOOST_OUTCOME_NODISCARD
#endif
#ifndef BOOST_OUTCOME_THREAD_LOCAL
#ifndef BOOST_NO_CXX11_THREAD_LOCAL
#define BOOST_OUTCOME_THREAD_LOCAL thread_local
#else
#if defined(_MSC_VER)
#define BOOST_OUTCOME_THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__)
#define BOOST_OUTCOME_THREAD_LOCAL __thread
#else
#error Unknown compiler, cannot set BOOST_OUTCOME_THREAD_LOCAL
#endif
#endif
#endif
// Can't use the QuickCppLib preprocessor metaprogrammed Concepts TS support, so ...
#ifndef BOOST_OUTCOME_TEMPLATE
#define BOOST_OUTCOME_TEMPLATE(...) template <__VA_ARGS__
#endif
#ifndef BOOST_OUTCOME_TREQUIRES
#define BOOST_OUTCOME_TREQUIRES(...) , __VA_ARGS__ >
#endif
#ifndef BOOST_OUTCOME_TEXPR
#define BOOST_OUTCOME_TEXPR(...) typename = decltype(__VA_ARGS__)
#endif
#ifndef BOOST_OUTCOME_TPRED
#define BOOST_OUTCOME_TPRED(...) typename = std::enable_if_t<__VA_ARGS__>
#endif
#ifndef BOOST_OUTCOME_REQUIRES
#ifdef __cpp_concepts
#define BOOST_OUTCOME_REQUIRES(...) requires __VA_ARGS__
#else
#define BOOST_OUTCOME_REQUIRES(...)
#endif
#endif

namespace boost
{
#define BOOST_OUTCOME_V2
  //! The Boost.Outcome namespace
  namespace outcome_v2
  {
  }
}
/*! The namespace of this Boost.Outcome v2.
*/
#define BOOST_OUTCOME_V2_NAMESPACE boost::outcome_v2
/*! Expands into the appropriate namespace markup to enter the Boost.Outcome v2 namespace.
*/
#define BOOST_OUTCOME_V2_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                                       \
  namespace boost                                                                                                                                                                                                                                                                                                              \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace outcome_v2                                                                                                                                                                                                                                                                                                       \
    {
/*! Expands into the appropriate namespace markup to enter the C++ module
exported Boost.Outcome v2 namespace.
*/
#define BOOST_OUTCOME_V2_NAMESPACE_EXPORT_BEGIN                                                                                                                                                                                                                                                                                \
  namespace boost                                                                                                                                                                                                                                                                                                              \
  {                                                                                                                                                                                                                                                                                                                            \
    export namespace outcome_v2                                                                                                                                                                                                                                                                                                \
    {
/*! \brief Expands into the appropriate namespace markup to exit the Boost.Outcome v2 namespace.
\ingroup config
*/
#define BOOST_OUTCOME_V2_NAMESPACE_END                                                                                                                                                                                                                                                                                         \
  }                                                                                                                                                                                                                                                                                                                            \
  }

#ifndef BOOST_OUTCOME_THROW_EXCEPTION
#include <boost/throw_exception.hpp>
#define BOOST_OUTCOME_THROW_EXCEPTION(expr) BOOST_THROW_EXCEPTION(expr)
#endif

#ifndef BOOST_OUTCOME_AUTO_TEST_CASE
#define BOOST_OUTCOME_AUTO_TEST_CASE(a, b) BOOST_AUTO_TEST_CASE(a)
#endif

#endif
