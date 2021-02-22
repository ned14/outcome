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

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / containers, "Tests that outcome works as intended inside containers")
{
  using namespace OUTCOME_V2_NAMESPACE;
  outcome<std::vector<int>> a(std::vector<int>{5, 6, 7, 8});
  BOOST_CHECK(a.has_value());
  BOOST_CHECK(a.value().size() == 4U);
  auto b(a);
  BOOST_CHECK(a.has_value());
  BOOST_CHECK(a.value().size() == 4U);
  BOOST_CHECK(b.has_value());
  BOOST_CHECK(b.value().size() == 4U);

  std::vector<outcome<std::vector<int>>> vect;
  vect.push_back(std::vector<int>{5, 6, 7, 8});
  vect.push_back(std::vector<int>{1, 2, 3, 4});
  BOOST_REQUIRE(vect.size() == 2U);  // NOLINT
  BOOST_CHECK(vect[0].has_value());
  BOOST_CHECK(vect[1].has_value());
  BOOST_CHECK(vect[0].value().size() == 4U);
  BOOST_CHECK(vect[1].value().size() == 4U);
  BOOST_CHECK(vect[0].value().front() == 5);
  BOOST_CHECK(vect[0].value().back() == 8);
  BOOST_CHECK(vect[1].value().front() == 1);
  BOOST_CHECK(vect[1].value().back() == 4);
}
