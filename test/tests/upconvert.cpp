/* Unit testing for outcomes
(C) 2013-2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../../include/outcome/outcome.hpp"
#include "../quickcpplib/include/boost/test/unit_test.hpp"

BOOST_AUTO_TEST_CASE(works / monad / upconvert, "Tests that the monad converts into bigger editions of itself")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  // Same type
  {
    option<int> a1, a10(5);
    result<int> b1(a1), b10(a10);
    outcome<int> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.get() == 5);
    BOOST_CHECK(b10.get() == 5);
    BOOST_CHECK(c10.get() == 5);
    BOOST_CHECK(c11.get() == 5);
  }
  // Converting type
  {
    option<short> a1, a10(5);
    result<float> b1(a1), b10(a10);
    outcome<double> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.get() == 5);
    BOOST_CHECK(b10.get() == 5);
    BOOST_CHECK(c10.get() == 5);
    BOOST_CHECK(c11.get() == 5);
  }
  // Explicit upconversion of void
  {
    option<void> a1, a10(make_valued_option<void>());
    result<void> b1(a1), b10(a10);
    outcome<void> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.is_ready());
    BOOST_CHECK(b10.is_ready());
    BOOST_CHECK(c10.is_ready());
    BOOST_CHECK(c11.is_ready());
  }
  // Implicit upconversion of void
  {
    auto t0 = []() -> result<int> { return make_result<void>(); };
    auto t1 = []() -> outcome<void> { return make_result<void>(); };
    auto t2 = []() -> outcome<int> { return make_result<void>(); };
    (void) t0;
    (void) t1;
    (void) t2;
  }
}

