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
