/* Unit testing for outcomes
(C) 2013-2021 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

namespace issues247
{
  namespace outcome = OUTCOME_V2_NAMESPACE;

  outcome::result<int> foo1()
  {
    outcome::result<int> ret(std::errc::invalid_argument);
    outcome::hooks::set_spare_storage(&ret, 43);
    return ret;
  }

  outcome::result<int> test1()
  {
    OUTCOME_TRY(foo1());
    return 7;
  }

  outcome::result<int> foo2() { return outcome::success(5, 43); }

  outcome::result<int> test2() { return foo2(); }

  outcome::outcome<int> foo3()
  {
    outcome::outcome<int> ret(std::make_exception_ptr(std::runtime_error("foo")));
    outcome::hooks::set_spare_storage(&ret, 43);
    return ret;
  }

  outcome::outcome<int> test3()
  {
    OUTCOME_TRY(foo3());
    return 7;
  }

}  // namespace issues247


BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0247 / test, "TRY strips spare storage value")
{
  auto r1 = issues247::test1();
  BOOST_CHECK(issues247::outcome::hooks::spare_storage(&r1) == 43);
  auto r2 = issues247::test2();
  BOOST_CHECK(issues247::outcome::hooks::spare_storage(&r2) == 43);
  auto r3 = issues247::test3();
  BOOST_CHECK(issues247::outcome::hooks::spare_storage(&r3) == 43);
}
