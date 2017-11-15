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
#include "quickcpplib/include/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / valueorerror, "Tests that outcome constructs from ValueOrError and ValueOrNone concept inputs")
{
  using namespace OUTCOME_V2_NAMESPACE;
  {
    struct value_or_error
    {
      using value_type = int;
      using error_type = void;
      bool has_value() const { return true; }
      int value() const { return 78; }
      void error() const {}
    } a;
    static_assert(convert::ValueOrNone<value_or_error>, "");
    static_assert(convert::ValueOrError<value_or_error>, "");
    BOOST_CHECK((convert::value_or_error<result<long>, value_or_error>{}(a).value() == 78));

    result<long> b(a);
    BOOST_CHECK(b.has_value());
    BOOST_CHECK(b.value() == 78);
  }
}
