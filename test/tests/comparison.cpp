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

BOOST_AUTO_TEST_CASE(works / outcome / comparison, "Tests that the outcome can compare to compatible outcomes")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  auto p = std::make_exception_ptr(std::runtime_error("hi"));
  // value comparison
  {
    outcome<int> a(1), b(2), c(2);
    BOOST_CHECK(a == a);
    BOOST_CHECK(b == b);
    BOOST_CHECK(c == c);
    BOOST_CHECK(a != b);
    BOOST_CHECK(b == c);
  }
  // homogeneous outcome comparison
  {
    outcome<int> a, b(2), c(make_errored_outcome<int>(EINVAL)), d(make_exceptional_outcome<int>(p));
    BOOST_CHECK(a == a);
    BOOST_CHECK(a != b);
    BOOST_CHECK(a != c);
    BOOST_CHECK(a != d);
    BOOST_CHECK(b == b);
    BOOST_CHECK(b != c);
    BOOST_CHECK(b != d);
    BOOST_CHECK(c == c);
    BOOST_CHECK(c != d);
    BOOST_CHECK(d == d);
    outcome<int> e(make_errored_outcome<int>(EINVAL)), f(make_exceptional_outcome<int>(p));
    BOOST_CHECK(c == e);
    BOOST_CHECK(d == f);
  }
  // heterogeneous outcome comparison, so outcome<int> to outcome<double> etc
  {
    outcome<int> a(1);
    outcome<double> b(1);
    outcome<unsigned short> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    outcome<void> d, e(make_valued_outcome<void>());
    outcome<unsigned short> f(make_errored_outcome<unsigned short>(EINVAL));
    outcome<double> g(make_exceptional_outcome<double>(p));
    BOOST_CHECK(a != d);
    BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    BOOST_CHECK(d != e);
    BOOST_CHECK(d != f);
    BOOST_CHECK(e != f);
    BOOST_CHECK(f != g);
  }
  // upconverting outcome comparison, so outcome<int>==result<int> etc
  {
    outcome<int> a(1);
    result<int> b(1);
    option<int> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    result<void> d, e(make_valued_result<void>()), f(make_errored_result<void>(EINVAL));
    option<bool> g, h(true);
    BOOST_CHECK(a != d);
    BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    BOOST_CHECK(a == h);
  }
  // Should I do outcome<int>(5) == 5? Unsure if it's wise
}
