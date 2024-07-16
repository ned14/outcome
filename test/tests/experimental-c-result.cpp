/* Unit testing for outcomes
(C) 2013-2024 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

#ifndef SYSTEM_ERROR2_NOT_POSIX

#include "../../include/outcome/experimental/result.h"

struct custom_value_type
{
  int v[16];

  bool operator==(const custom_value_type &o) const noexcept { return 0 == memcmp(v, o.v, sizeof(v)); }
};

enum c_enum
{
  c_enum_success,
  c_enum_failure
};

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

CXX_DECLARE_RESULT_SYSTEM(test, custom_value_type);
using result_custom = CXX_RESULT_SYSTEM(test);

CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, "{74ceb994-7622-3a21-07f0-b016aa705585}", {c_enum::c_enum_success, "success", {errc::success}},
                                    {c_enum::c_enum_failure, "failure", {errc::invalid_argument}});

template <class T> using result = OUTCOME_V2_NAMESPACE::experimental::status_result<T>;

#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / c_result, "Tests that the C result with status_code works as intended")
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  const custom_value_type shouldbe{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  {  // errored with posix code
    result_custom l(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), posix_error);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
    BOOST_CHECK(outcome_status_code_equal(&l.error, &l2.error));
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, EFAULT));
    std::cout << outcome_status_code_message(&l.error) << std::endl;
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&l.error), "Bad address"));
  }
  {  // valued
    result_custom l(outcome_make_result_system_test_success(shouldbe));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.value() == shouldbe);
  }
  if(false)  // correctly contract asserts
  {          // errored from custom C enum 1
    result_custom l(CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, c_enum::c_enum_success));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), status_error<_quick_status_code_from_enum_domain<c_enum>>);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::invalid_argument));
    BOOST_CHECK(!outcome_status_code_equal(&l.error, &l2.error));
  }
  {  // errored from custom C enum 2
    result_custom l(CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, c_enum::c_enum_failure));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), status_error<_quick_status_code_from_enum_domain<c_enum>>);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::invalid_argument));
    BOOST_CHECK(outcome_status_code_equal(&l.error, &l2.error));
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, EINVAL));
    std::cout << outcome_status_code_message(&l.error) << std::endl;
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&l.error), "failure"));
  }
  auto d(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
  static_assert(std::is_default_constructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_default_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_trivially_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_nothrow_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_nothrow_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_destructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_destructible<decltype(d)>::value, "");

  // Single parameter C try
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(r);
      return will_succeed();
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup on failure
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(printf("failed!\n"), r);
      return will_succeed();
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup and success output
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(custom_value_type v, printf("failed!\n"), r);
      return outcome_make_result_system_test_success(v);
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup and success output and different return type
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(custom_value_type v, test, printf("failed!\n"), r);
      return outcome_make_result_system_test_success(v);
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
}
#else
int main(void)
{
  return 0;
}
#endif
