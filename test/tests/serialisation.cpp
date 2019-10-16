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

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / serialisation, "Tests that the outcome serialises and deserialises as intended")
{
#if !defined(__APPLE__) || defined(__cpp_exceptions)
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
#endif
}
