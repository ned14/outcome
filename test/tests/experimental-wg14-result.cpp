/* Unit testing for outcomes
(C) 2013-2025 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

#if !defined(SYSTEM_ERROR2_NOT_POSIX) && __has_include("../../include/outcome/experimental/wg14_result/include/wg14_result/status_code.h")

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#ifdef _MSC_VER
#pragma warning(disable : 4505)  // unreferenced function has been removed
#endif

#define WG14_RESULT_ENABLE_HEADER_ONLY 1

#include "../../include/outcome/experimental/wg14_result/include/wg14_result/status_code.h"
#include "../../include/outcome/experimental/wg14_result/include/wg14_result/status_code_generic.h"

#include "../../include/outcome/experimental/status-code/include/status-code/config.hpp"
#include "../../include/outcome/experimental/status-code/include/status-code/status_code_domain.hpp"
#include "../../include/outcome/experimental/status_result.hpp"

#include "quickcpplib/boost/test/unit_test.hpp"


BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / wg14_status_code, "Tests that the WG14 C status_code works as intended")
{
  // The C ones need to be ABI compatible with the C++ ones
  static_assert(sizeof(SYSTEM_ERROR2_NAMESPACE::generic_code) == sizeof(WG14_RESULT_PREFIX(status_code_generic)),
                "WG14 C status code is not the same size as the C++ status code!");
  static_assert(alignof(SYSTEM_ERROR2_NAMESPACE::generic_code) == alignof(WG14_RESULT_PREFIX(status_code_generic)),
                "WG14 C status code is not the same alignment as the C++ status code!");
  static_assert(sizeof(SYSTEM_ERROR2_NAMESPACE::status_code_domain) == sizeof(WG14_RESULT_PREFIX(status_code_domain)),
                "WG14 C status code domain is not the same size as the C++ status code domain!");
  static_assert(alignof(SYSTEM_ERROR2_NAMESPACE::status_code_domain) == alignof(WG14_RESULT_PREFIX(status_code_domain)),
                "WG14 C status code domain is not the same alignment as the C++ status code domain!");
  static_assert(sizeof(SYSTEM_ERROR2_NAMESPACE::status_code_domain::string_ref) == sizeof(WG14_RESULT_PREFIX(status_code_domain_string_ref)),
                "WG14 C status code domain string ref is not the same size as the C++ status code domain string ref!");
  static_assert(alignof(SYSTEM_ERROR2_NAMESPACE::status_code_domain::string_ref) == alignof(WG14_RESULT_PREFIX(status_code_domain_string_ref)),
                "WG14 C status code domain string ref is not the same alignment as the C++ status code domain string ref!");

  // Construct with C edition, use with C++ edition
  {
    WG14_RESULT_CONSTEXPR_OR_CONST WG14_RESULT_PREFIX(status_code_generic)
    empty1 = {{WG14_RESULT_NULLPTR}, WG14_RESULT_PREFIX(status_code_errc_success)},
    success1 = WG14_RESULT_PREFIX(status_code_generic_make)(WG14_RESULT_PREFIX(status_code_errc_success)),
    failure1 = WG14_RESULT_PREFIX(status_code_generic_make)(WG14_RESULT_PREFIX(status_code_errc_permission_denied));
    BOOST_CHECK(status_code_is_empty(empty1));
    BOOST_CHECK(!status_code_is_empty(success1));
    BOOST_CHECK(!status_code_is_empty(failure1));
    BOOST_CHECK(status_code_is_success(success1));
    BOOST_CHECK(status_code_is_failure(failure1));
    printf("generic_code empty has value %d (%s) is success %d is failure %d\n", empty1.value, status_code_message(empty1).c_str,
           status_code_is_success(empty1), status_code_is_failure(empty1));
    printf("generic_code success has value %d (%s) is success %d is failure %d\n", success1.value, status_code_message(success1).c_str,
           status_code_is_success(success1), status_code_is_failure(success1));
    printf("generic_code failure has value %d (%s) is success %d is failure %d\n", failure1.value, status_code_message(failure1).c_str,
           status_code_is_success(failure1), status_code_is_failure(failure1));

#if !QUICKCPPLIB_IN_UNDEFINED_SANITIZER
    // For obvious reasons, ubsan really doesn't like C manufactured vptrs
    const SYSTEM_ERROR2_NAMESPACE::generic_code *empty1a = (const SYSTEM_ERROR2_NAMESPACE::generic_code *) &empty1,
                                                *success1a = (const SYSTEM_ERROR2_NAMESPACE::generic_code *) &success1,
                                                *failure1a = (const SYSTEM_ERROR2_NAMESPACE::generic_code *) &failure1;
    BOOST_CHECK(empty1a->empty());
    BOOST_CHECK(!success1a->empty());
    BOOST_CHECK(!failure1a->empty());
    BOOST_CHECK(success1a->success());
    BOOST_CHECK(failure1a->failure());
    printf("generic_code empty has value %d (%s) is success %d is failure %d\n", (int) empty1a->value(), empty1a->message().c_str(), empty1a->success(),
           empty1a->failure());
    printf("generic_code success has value %d (%s) is success %d is failure %d\n", (int) success1a->value(), success1a->message().c_str(), success1a->success(),
           success1a->failure());
    printf("generic_code failure has value %d (%s) is success %d is failure %d\n", (int) failure1a->value(), failure1a->message().c_str(), failure1a->success(),
           failure1a->failure());
#endif
  }

  // Construct with C++ edition, use with C edition
  {
    constexpr SYSTEM_ERROR2_NAMESPACE::generic_code empty1, success1(SYSTEM_ERROR2_NAMESPACE::errc::success),
    failure1(SYSTEM_ERROR2_NAMESPACE::errc::permission_denied);
    BOOST_CHECK(empty1.empty());
    BOOST_CHECK(!success1.empty());
    BOOST_CHECK(!failure1.empty());
    BOOST_CHECK(success1.success());
    BOOST_CHECK(failure1.failure());
    printf("generic_code empty has value %d (%s) is success %d is failure %d\n", static_cast<int>(empty1.value()), empty1.message().c_str(),
           static_cast<int>(empty1.success()), static_cast<int>(empty1.failure()));
    printf("generic_code success has value %d (%s) is success %d is failure %d\n", static_cast<int>(success1.value()), success1.message().c_str(),
           static_cast<int>(success1.success()), static_cast<int>(success1.failure()));
    printf("generic_code failure has value %d (%s) is success %d is failure %d\n", static_cast<int>(failure1.value()), failure1.message().c_str(),
           static_cast<int>(failure1.success()), static_cast<int>(failure1.failure()));

    const WG14_RESULT_PREFIX(status_code_generic) &empty1a = *(const WG14_RESULT_PREFIX(status_code_generic) *) &empty1,
                                                  &success1a = *(const WG14_RESULT_PREFIX(status_code_generic) *) &success1,
                                                  &failure1a = *(const WG14_RESULT_PREFIX(status_code_generic) *) &failure1;
    BOOST_CHECK(status_code_is_empty(empty1a));
    BOOST_CHECK(!status_code_is_empty(success1a));
    BOOST_CHECK(!status_code_is_empty(failure1a));
    BOOST_CHECK(status_code_is_success(success1a));
    BOOST_CHECK(status_code_is_failure(failure1a));
    printf("generic_code empty has value %d (%s) is success %d is failure %d\n", empty1a.value, status_code_message(empty1a).c_str,
           status_code_is_success(empty1a), status_code_is_failure(empty1a));
    printf("generic_code success has value %d (%s) is success %d is failure %d\n", success1a.value, status_code_message(success1a).c_str,
           status_code_is_success(success1a), status_code_is_failure(success1a));
    printf("generic_code failure has value %d (%s) is success %d is failure %d\n", failure1a.value, status_code_message(failure1a).c_str,
           status_code_is_success(failure1a), status_code_is_failure(failure1a));
  }
}
#else
int main(void)
{
  return 0;
}
#endif
