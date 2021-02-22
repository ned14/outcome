/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (3 commits)


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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0065 / outcome, "OUTCOME_TRY does not preserve the exception_ptr")
{
#ifdef __cpp_exceptions
  using namespace OUTCOME_V2_NAMESPACE;
  auto g = []() -> outcome<int> {
    auto f = []() -> outcome<int> {
      try
      {
        throw std::runtime_error{"XXX"};
      }
      catch(...)
      {
        return std::current_exception();
      }
    };
    OUTCOME_TRY(auto &&ans, (f()));
    return ans;
  };
  outcome<int> o = g();
  BOOST_CHECK(!o);
  BOOST_CHECK(o.has_exception());
  try
  {
    o.value();
    BOOST_CHECK(false);
  }
  catch(const std::runtime_error &e)
  {
    BOOST_CHECK(!strcmp(e.what(), "XXX"));
  }
#endif
}
