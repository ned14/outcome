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

#include "../../include/outcome/experimental/status_result.hpp"

#include "quickcpplib/boost/test/unit_test.hpp"

#if __cplusplus >= 202000L || _HAS_CXX20

namespace issues255
{
  namespace outcome_e = OUTCOME_V2_NAMESPACE::experimental;

  static_assert(outcome_e::traits::is_move_bitcopying<outcome_e::error>::value, "outcome_e::error is not move bitcopying!");

  constexpr outcome_e::status_result<int> test() { return outcome_e::success(42); }
}

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0255 / test, "status_result<int> not usable from constexpr in C++ 20")
{
  BOOST_CHECK(issues255::test().value() == 42);
}

#else

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0255 / test, "status_result<int> not usable from constexpr in C++ 20")
{
  BOOST_CHECK(true);
}

#endif
