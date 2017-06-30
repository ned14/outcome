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

BOOST_AUTO_TEST_CASE(works / monad / propagate, "Tests that the monad propagates errors between different editions of itself")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  {
    auto t0 = [&](int a) { return make_errored_result<long>(a); };
    auto t1 = [&](int a) {
      result<double> f(t0(a));  // double is constructible from long
      return f;
    };
    auto t2 = [&](int a) {
      result<void> f(t1(a).get_error());
      return f;
    };
    auto t3 = [&](int a) {
      outcome<std::string> f(t2(a));
      return f;
    };
    BOOST_CHECK(t3(5).get_error().value() == 5);
    result<int> a1(make_empty_result<void>());
    result<int> a2(make_valued_result<void>());
    result<int> a3(make_errored_result<void>(5));
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(!a1.has_value());
    BOOST_CHECK(!a1.has_error());
    BOOST_CHECK(!a2.empty());
    BOOST_CHECK(a2.has_value());
    BOOST_CHECK(!a2.has_error());
    BOOST_CHECK(!a3.empty());
    BOOST_CHECK(!a3.has_value());
    BOOST_CHECK(a3.has_error());
  }
  {
    auto t0 = [&](int a) { return make_result<long>(a); };
    auto t1 = [&](int a) -> result<std::string> {
      BOOST_OUTCOME_TRY(f, t0(a));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).get() == "5");
  }
  {
    auto t0 = [&](int a) { return make_result<long>(a); };
    auto t1 = [&](int a) -> outcome<std::string> {
      BOOST_OUTCOME_TRY(f, t0(a));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).get() == "5");
  }
  {
    auto t0 = [&](int a) -> result<long> { return make_result<long>(a); };
    auto t1 = [&](int a) -> outcome<void> {
      BOOST_OUTCOME_TRYV(t0(a));
      return make_outcome<void>();
    };
    (void) t1(5);
  }
}
