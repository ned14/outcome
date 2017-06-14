/* Configure Boost.Outcome with Boost.APIBind
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

#ifndef BOOST_OUTCOME_CONFIG_HPP
#define BOOST_OUTCOME_CONFIG_HPP

//! \defgroup config Configuration macros

// Pull in detection of __MINGW64_VERSION_MAJOR
#if defined(__MINGW32__) && !defined(DOXYGEN_IS_IN_THE_HOUSE)
#include <_mingw.h>
#endif

#include "../quickcpplib/include/config.hpp"

#ifndef __cpp_attributes
#error Boost.Outcome needs attributes support in the compiler
#endif
#ifndef __cpp_variadic_templates
#error Boost.Outcome needs variadic template support in the compiler
#endif
#ifndef __cpp_constexpr
#error Boost.Outcome needs constexpr (C++ 11) support in the compiler
#endif
#ifndef __cpp_variable_templates
#error Boost.Outcome needs variable template support in the compiler
#endif
#ifndef __cpp_generic_lambdas
#error Boost.Outcome needs generic lambda support in the compiler
#endif


#include "../quickcpplib/include/import.h"
#undef BOOST_OUTCOME_V1
#undef BOOST_OUTCOME_V1_NAMESPACE
#undef BOOST_OUTCOME_V1_NAMESPACE_BEGIN
#undef BOOST_OUTCOME_V1_NAMESPACE_END

#ifdef BOOST_OUTCOME_UNSTABLE_VERSION
#include "../revision.hpp"
#define BOOST_OUTCOME_V1 (boost), (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, BOOST_OUTCOME_NAMESPACE_VERSION, BOOST_OUTCOME_PREVIOUS_COMMIT_UNIQUE), inline)
#elif BOOST_OUTCOME_LATEST_VERSION == 1
#define BOOST_OUTCOME_V1 (boost), (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, BOOST_OUTCOME_NAMESPACE_VERSION), inline)
#else
#define BOOST_OUTCOME_V1 (boost), (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, BOOST_OUTCOME_NAMESPACE_VERSION))
#endif
/*! \def BOOST_OUTCOME_V1
\ingroup config
\brief The namespace configuration of this Boost.Outcome v1. Consists of a sequence
of bracketed tokens later fused by the preprocessor into namespace and C++ module names.
*/
#if DOXYGEN_SHOULD_SKIP_THIS
//! The Boost namespace
namespace boost
{
  //! The Outcome namespace
  namespace outcome
  {
    //! Inline namespace for this version of Outcome
    inline namespace v1_xxx
    {
      //! Contains ABI and API unstable things
      namespace experimental
      {
      }
    }
  }
}
/*! \brief The namespace of this Boost.Outcome v1 which will be some unknown inline
namespace starting with `v1_` inside the `boost::afio` namespace.
\ingroup config
*/
#define BOOST_OUTCOME_V1_NAMESPACE boost::outcome::v1_xxx
/*! \brief Expands into the appropriate namespace markup to enter the Outcome v1 namespace.
\ingroup config
*/
#define BOOST_OUTCOME_V1_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                                       \
  namespace boost                                                                                                                                                                                                                                                                                                              \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace outcome                                                                                                                                                                                                                                                                                                          \
    {                                                                                                                                                                                                                                                                                                                          \
      inline namespace v1_xxx                                                                                                                                                                                                                                                                                                  \
      {
/*! \brief Expands into the appropriate namespace markup to enter the C++ module
exported Outcome v1 namespace.
\ingroup config
*/
#define BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN                                                                                                                                                                                                                                                                                \
  export namespace boost                                                                                                                                                                                                                                                                                                       \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace outcome                                                                                                                                                                                                                                                                                                          \
    {                                                                                                                                                                                                                                                                                                                          \
      inline namespace v1_xxx                                                                                                                                                                                                                                                                                                  \
      {
/*! \brief Expands into the appropriate namespace markup to exit the Outcome v1 namespace.
\ingroup config
*/
#define BOOST_OUTCOME_V1_NAMESPACE_END                                                                                                                                                                                                                                                                                         \
  }                                                                                                                                                                                                                                                                                                                            \
  }                                                                                                                                                                                                                                                                                                                            \
  }
#elif defined(GENERATING_OUTCOME_MODULE_INTERFACE)
#define BOOST_OUTCOME_V1_NAMESPACE QUICKCPPLIB_BIND_NAMESPACE(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_END QUICKCPPLIB_BIND_NAMESPACE_END(BOOST_OUTCOME_V1)
#else
#define BOOST_OUTCOME_V1_NAMESPACE QUICKCPPLIB_BIND_NAMESPACE(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_END QUICKCPPLIB_BIND_NAMESPACE_END(BOOST_OUTCOME_V1)
#endif

#include <cassert>  // for asserting :)
#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS
#include <ostream>  // for printing
#endif
#include <system_error>

namespace stl11 = std;

// Bring this in now because error_code_extended uses it via ringbuffer_log
#ifdef _WIN32
#include "../quickcpplib/include/execinfo_win64.h"
#else
#include <execinfo.h>
#endif

#ifndef BOOST_OUTCOME_THROW
#ifdef __cpp_exceptions
#define BOOST_OUTCOME_THROW(expr) throw expr
#else
#include <stdio.h>
BOOST_OUTCOME_V1_NAMESPACE_BEGIN
namespace detail
{
  QUICKCPPLIB_NORETURN inline void do_fatal_exit(const char *expr)
  {
    void *bt[16];
    size_t btlen = backtrace(bt, sizeof(bt) / sizeof(bt[0]));
    fprintf(stderr, "FATAL: Boost.Outcome throws exception %s with exceptions disabled\n", expr);
    char **bts = backtrace_symbols(bt, btlen);
    if(bts)
    {
      for(size_t n = 0; n < btlen; n++)
        fprintf(stderr, "  %s\n", bts[n]);
      free(bts);
    }
    std::terminate();
  }
}
BOOST_OUTCOME_V1_NAMESPACE_END
//! \brief Redefine to have something else occur when Outcome throws an exception
#define BOOST_OUTCOME_THROW(expr) BOOST_OUTCOME_V1_NAMESPACE::detail::do_fatal_exit(#expr)
#endif
#endif

#ifndef BOOST_OUTCOME_THROW_DESERIALISATION_FAILURE
//! \brief Predefine to have something else occur when Outcome throws an exception due to a deserialisation failure
#define BOOST_OUTCOME_THROW_DESERIALISATION_FAILURE(m, expr) BOOST_OUTCOME_THROW(expr)
#endif

#ifndef BOOST_OUTCOME_THROW_BAD_OUTCOME
/*! \brief Predefine to have something else occur when Outcome throws a `bad_outcome` due to being asked to do something not possible
\return Can return false to cancel the calling operation (see `_throw_error()` in monad_policy.ipp).
*/
#define BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, expr) BOOST_OUTCOME_THROW(expr), false
#endif

#ifndef BOOST_OUTCOME_THROW_SYSTEM_ERROR
//! \brief Predefine to have something else occur when Outcome throws a system_error with an error_code from the monad
#define BOOST_OUTCOME_THROW_SYSTEM_ERROR(ec, expr) BOOST_OUTCOME_THROW(expr)
#endif

#ifndef BOOST_OUTCOME_RETHROW_EXCEPTION
#ifdef __cpp_exceptions
#define BOOST_OUTCOME_RETHROW_EXCEPTION(ex) std::rethrow_exception(ex)
#else
//! \brief Predefine to have something else occur when Outcome rethrows an exception_ptr from the monad
#define BOOST_OUTCOME_RETHROW_EXCEPTION(ex) BOOST_OUTCOME_THROW(std::rethrow_exception(ex))
#endif
#endif

#ifndef BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS
//! \brief Predefine to what you want the Expected implementation to when throwing a bad_expected_access
#define BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(...) BOOST_OUTCOME_THROW(experimental::make_bad_expected_access(__VA_ARGS__))
#endif

#endif
