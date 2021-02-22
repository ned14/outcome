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
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / propagate, "Tests that the outcome propagates errors between different editions of itself")
{
  using namespace OUTCOME_V2_NAMESPACE;
  {
    auto t0 = [&](int a) { return result<long>(std::error_code(a, std::generic_category())); };
    auto t1 = [&](int a) {
      result<double> f(t0(a));  // double is constructible from long
      BOOST_CHECK(!f.has_value());
      BOOST_CHECK(f.has_error());
      return f;
    };
    auto t2 = [&](int a) {
      result<void> f(t1(a).error());
      BOOST_CHECK(!f.has_value());
      BOOST_CHECK(f.has_error());
      return f;
    };
    auto t3 = [&](int a) {
      outcome<std::string> f(t2(a));
      BOOST_CHECK(!f.has_value());
      BOOST_CHECK(f.has_error());
      return f;
    };
    BOOST_CHECK(t3(5).error().value() == 5);
    result<int> a2{result<void>(in_place_type<void>)};
    result<int> a3{result<void>(std::error_code(5, std::generic_category()))};
    BOOST_CHECK(a2.has_value());
    BOOST_CHECK(!a2.has_error());
    BOOST_CHECK(!a3.has_value());
    BOOST_CHECK(a3.has_error());
  }
  {
    auto t0 = [&](int a) { return result<long>(a); };
    auto t1 = [&](int a) -> result<std::string> {
      OUTCOME_TRY(auto &&f, (t0(a)));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).value() == "5");
  }
  {
    auto t0 = [&](int a) { return result<long>(a); };
    auto t1 = [&](int a) -> outcome<std::string> {
      OUTCOME_TRY(auto &&f, (t0(a)));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).value() == "5");
  }
  {
    auto t0 = [&](int a) -> result<long> { return result<long>(a); };
    auto t1 = [&](int a) -> outcome<void> {
      OUTCOME_TRY((t0(a)));
      return outcome<void>(in_place_type<void>);
    };
    (void) t1(5);
  }
}
