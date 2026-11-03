/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (7 commits)


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
#include "quickcpplib/boost/test/unit_test.hpp"

// The body only builds under the condition below. Guarding INSIDE the case left the
// configurations that do not satisfy it registering a case with zero assertions, which
// CTest recorded as PASSED (reviewer P0 r1:T6). Guard the whole case instead and let
// those configurations report SKIPPED.
#if !defined(__APPLE__) || defined(__cpp_exceptions)
BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / serialisation, "Tests that the outcome serialises and deserialises as intended")
{
  using namespace OUTCOME_V2_NAMESPACE;
  outcome<std::string> a("niall"), b(std::error_code(5, std::generic_category())), c(std::make_exception_ptr(std::ios_base::failure("A test failure message")));
  std::cout << "a contains " << print(a) << " and b contains " << print(b) << " and c contains " << print(c) << std::endl;

  std::stringstream ss;
  outcome<int, std::string, long> d(success(5));
  ss << d;
  ss.seekg(0);
  outcome<int, std::string, long> e(failure(""));
  ss >> e;
  BOOST_CHECK(d == e);
}
#else
#include "skip_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / serialisation, "Tests that the outcome serialises and deserialises as intended")
// Two arguments: BOOST_AUTO_TEST_CASE takes a name and a description only, so
// the third (skip reason) argument this used to carry made the branch
// unbuildable. See the same fix in comparison.cpp.
{
  SKIP_TEST_IF_DISABLED("test/tests/serialisation.cpp does not build in this configuration");
}
#endif
