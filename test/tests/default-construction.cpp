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

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / default_construction, "Tests that outcome default constructs when it ought to")
{
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt
  {
    int _v{78};
    udt() = default;
    constexpr explicit udt(int v) noexcept : _v(v) {}
    udt(udt &&o) = delete;
    udt(const udt &) = delete;
    udt &operator=(udt &&o) = delete;
    udt &operator=(const udt &) = delete;
    ~udt() = default;
    constexpr int operator*() const noexcept { return _v; }
  };
  // One path is via success_type<void>
  outcome<udt> a(success());
  BOOST_CHECK(*a.value() == 78);

  // Other path is via empty initialiser list
  outcome<udt> d({});
  BOOST_CHECK(*d.value() == 78);
}
