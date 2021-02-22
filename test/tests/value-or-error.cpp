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
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / valueorerror, "Tests that outcome constructs from value_or_error and value_or_none concept inputs")
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
    static_assert(concepts::value_or_none<value_or_error>, "");
    static_assert(concepts::value_or_error<value_or_error>, "");
    static_assert(!concepts::basic_result<value_or_error>, "");
    static_assert(!concepts::basic_outcome<value_or_error>, "");
    BOOST_CHECK((convert::value_or_error<result<long>, value_or_error>{}(a).value() == 78));

    result<long> b(a);
    BOOST_CHECK(b.has_value());
    BOOST_CHECK(b.value() == 78);

    struct local_basic_result1 : result<int>
    {
    };
    static_assert(concepts::value_or_none<local_basic_result1>, "");
    static_assert(concepts::value_or_error<local_basic_result1>, "");
    static_assert(concepts::basic_result<result<int>>, "");
    static_assert(concepts::basic_result<local_basic_result1>, "");
    static_assert(!concepts::basic_outcome<result<int>>, "");
    static_assert(!concepts::basic_outcome<local_basic_result1>, "");

    struct local_basic_result2 : protected result<int>
    {
      using _base = result<int>;
      using value_type = _base::value_type;
      using error_type = _base::error_type;
      using _base::has_value;
      using _base::value;
      using _base::error;
    };
    static_assert(concepts::value_or_none<local_basic_result2>, "");
    static_assert(concepts::value_or_error<local_basic_result2>, "");
    static_assert(!concepts::basic_result<local_basic_result2>, "");
    static_assert(!concepts::basic_outcome<local_basic_result2>, "");

    struct local_basic_outcome1 : outcome<int>
    {
    };
    static_assert(!std::is_convertible<outcome<int>, result<int>>::value, "");
    static_assert(!std::is_convertible<local_basic_outcome1, result<int>>::value, "");
    static_assert(concepts::value_or_none<local_basic_outcome1>, "");
    static_assert(concepts::value_or_error<local_basic_outcome1>, "");
    static_assert(!concepts::basic_result<outcome<int>>, "");
    static_assert(!concepts::basic_result<local_basic_outcome1>, "");
    static_assert(concepts::basic_outcome<local_basic_outcome1>, "");

    struct local_basic_outcome2 : protected outcome<int>
    {
      using _base = outcome<int>;
      using value_type = _base::value_type;
      using error_type = _base::error_type;
      using exception_type = _base::exception_type;
      using _base::error;
      using _base::has_value;
      using _base::value;
    };
    static_assert(concepts::value_or_none<local_basic_outcome2>, "");
    static_assert(concepts::value_or_error<local_basic_outcome2>, "");
    static_assert(!concepts::basic_result<local_basic_outcome2>, "");
    static_assert(!concepts::basic_outcome<local_basic_outcome2>, "");
  }
}
