/* Unit testing for outcomes
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (10 commits)


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

#include "../ndebug.h"

#include "../../include/outcome/result.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

#include <iostream>

BOOST_OUTCOME_AUTO_TEST_CASE(works / success - failure, "Tests that the success and failure type sugars work as intended")
{
  using namespace OUTCOME_V2_NAMESPACE;
#ifdef __cpp_deduction_guides
  std::cout << "__cpp_deduction_guides = 1" << std::endl;
#endif
  {
    auto a = success(5);
    auto b = success();
    auto c = success("hello");
    static_assert(std::is_same<decltype(a), success_type<int>>::value, "");
    static_assert(std::is_same<decltype(b), success_type<void>>::value, "");
    static_assert(std::is_same<decltype(c), success_type<const char *>>::value, "");
    static_assert(std::is_same<decltype(a)::value_type, int>::value, "");
    // static_assert(std::is_same<decltype(b.value), int>::value, "");
    static_assert(std::is_same<decltype(c)::value_type, const char *>::value, "");
  }
#if !defined(__APPLE__) || defined(__cpp_exceptions)
  {
    auto e = std::make_exception_ptr(std::exception());
    auto a = failure(5);
    auto b = failure(5, e);
    auto c = failure(5, 5);
    static_assert(std::is_same<decltype(a), failure_type<int, void>>::value, "");
    static_assert(std::is_same<decltype(b), failure_type<int, std::exception_ptr>>::value, "");
    static_assert(std::is_same<decltype(c), failure_type<int, int>>::value, "");
    static_assert(std::is_same<decltype(a)::error_type, int>::value, "");
    static_assert(std::is_same<decltype(b)::error_type, int>::value, "");
    static_assert(std::is_same<decltype(b)::exception_type, std::exception_ptr>::value, "");
    static_assert(std::is_same<decltype(c)::error_type, int>::value, "");
    static_assert(std::is_same<decltype(c)::exception_type, int>::value, "");
  }
#endif
}

// A result holding an error is never equal to a success sugar, so `!=` must be
// true for it. This used to return false, which made a failed result compare
// both equal AND unequal to the same success value (reviewer P0
// r2:core-headers-1 / r6:H1).
BOOST_OUTCOME_AUTO_TEST_CASE(works / success - failure - compare, "Tests that a failed result never compares equal to a success sugar")
{
  using namespace OUTCOME_V2_NAMESPACE;
  using E = std::error_code;
  const auto err = std::make_error_code(std::errc::invalid_argument);

  result<int, E> val(5);
  result<int, E> bad(err);

  // value against a success sugar
  BOOST_CHECK(val == success(5));
  BOOST_CHECK(!(val != success(5)));
  BOOST_CHECK(val != success(6));
  BOOST_CHECK(!(val == success(6)));

  // error against a success sugar: the case that was wrong
  BOOST_CHECK(bad != success(5));
  BOOST_CHECK(!(bad == success(5)));
  BOOST_CHECK(success(5) != bad);
  BOOST_CHECK(!(success(5) == bad));

  // void success sugar behaves the same way
  BOOST_CHECK(bad != success());
  BOOST_CHECK(!(bad == success()));
  BOOST_CHECK(val == success());

  // and a value never compares equal to a failure sugar
  BOOST_CHECK(val != failure(err));
  BOOST_CHECK(!(val == failure(err)));
  BOOST_CHECK(bad == failure(err));
  BOOST_CHECK(!(bad != failure(err)));
}
