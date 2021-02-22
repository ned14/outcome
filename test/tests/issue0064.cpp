/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (4 commits)


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

#include "../../include/outcome/iostream_support.hpp"
#include "../../include/outcome.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0064 / outcome, "OUTCOME_TRY on excepted outcome is propagating a null error rather than just an exception")
{
#ifdef __cpp_exceptions
  using namespace OUTCOME_V2_NAMESPACE;
  auto f = []() -> outcome<int> {
    auto h = []() -> outcome<int> { return std::make_exception_ptr(std::runtime_error("hello")); };
    OUTCOME_TRY((h()));
    return 0;
  }();
  std::cout << print(f) << std::endl;
  BOOST_CHECK(!f.has_value());
  BOOST_CHECK(!f.has_error());
  BOOST_CHECK(f.has_exception());
#endif
}
