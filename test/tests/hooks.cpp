/* Unit testing for outcomes
(C) 2013-2020 Niall Douglas <http://www.nedproductions.biz/> (14 commits)


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

#define _CRT_SECURE_NO_WARNINGS
#define OUTCOME_ENABLE_LEGACY_SUPPORT_FOR 210  // legacy ADL hooks support

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

#include <iostream>

namespace hook_test
{
  using OUTCOME_V2_NAMESPACE::in_place_type;
  // Use static storage to convey extended error info from result construction to outcome conversion
  static char extended_error_info[256];

  // Use the error_code type as the ADL bridge for the hooks by creating a type here
  struct error_code : public std::error_code
  {
    error_code() = default;
    error_code(std::error_code ec)  // NOLINT
    : std::error_code(ec)
    {
    }
  };
  // Localise result to using the local error_code so this namespace gets looked up for the hooks
  template <class R> using result = OUTCOME_V2_NAMESPACE::result<R, error_code>;
  // Specialise the result construction hook for our localised result
  template <class U> constexpr inline void hook_result_construction(result<int> *res, U && /*unused*/) noexcept
  {
    // Write the value in the result into the static storage
    snprintf(extended_error_info, sizeof(extended_error_info), "%d", res->assume_value());  // NOLINT
  }
  template <class U> constexpr inline void hook_result_construction(result<std::string> *res, U && /*unused*/) noexcept
  {
    // Write the value in the result into the static storage
    snprintf(extended_error_info, sizeof(extended_error_info), "%s", res->assume_value().c_str());  // NOLINT
  }
}  // namespace hook_test

BOOST_OUTCOME_AUTO_TEST_CASE(works / result / hooks, "Tests that you can hook result's construction")
{
  using namespace hook_test;
  result<int> a(5);
  BOOST_CHECK(!strcmp(extended_error_info, "5"));  // NOLINT
  result<std::string> b("niall");
  BOOST_CHECK(!strcmp(extended_error_info, "niall"));  // NOLINT
}

//! [extended_error_coding2]
namespace hook_test
{
  // Localise outcome to using the local error_code so this namespace gets looked up for the hooks
  template <class R> using outcome = OUTCOME_V2_NAMESPACE::outcome<R, error_code, std::string>;

  // Specialise the outcome copy and move conversion hook for our localised result
  template <class T, class U> constexpr inline void hook_outcome_copy_construction(outcome<T> *res, const result<U> & /*unused*/) noexcept
  {
    // when copy constructing from a result<T>, place extended_error_coding::extended_error_info into the payload
    std::cout << "hook_outcome_copy_construction fires" << std::endl;
    OUTCOME_V2_NAMESPACE::hooks::override_outcome_exception(res, extended_error_info);
  }
  template <class T, class U> constexpr inline void hook_outcome_move_construction(outcome<T> *res, result<U> && /*unused*/) noexcept
  {
    // when move constructing from a result<T>, place extended_error_coding::extended_error_info into the payload
    std::cout << "hook_outcome_move_construction fires" << std::endl;
    OUTCOME_V2_NAMESPACE::hooks::override_outcome_exception(res, extended_error_info);
  }
}  // namespace hook_test

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / hooks, "Tests that you can hook outcome's conversion from a result")
{
  using namespace hook_test;
  outcome<int> a(result<int>(5));
  BOOST_REQUIRE(a.has_exception());  // NOLINT
  BOOST_CHECK(a.exception() == "5");
  outcome<std::string> b(result<std::string>("niall"));
  BOOST_CHECK(b.exception() == "niall");

  // Make sure hook does not fire for any other kind of outcome copy or move, only when converting from our custom result only
  outcome<int> c(5);
  outcome<long> d(c);  // can't be the same type as source, else copy elision takes place and no ADL hook calling
  BOOST_CHECK(!d.has_exception());
  outcome<int> e(OUTCOME_V2_NAMESPACE::result<int>(5));
  BOOST_CHECK(!e.has_exception());
}
