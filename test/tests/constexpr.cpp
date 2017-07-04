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

#if __cpp_constexpr >= 201304
// Test the underlying storage for constexpr
static constexpr inline BOOST_OUTCOME_V1_NAMESPACE::value_storage<int, void, void> test_constexpr2a(int f)
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  return value_storage<int, void, void>(f);  // NOLINT
}
// Test the underlying storage for constexpr
static constexpr inline BOOST_OUTCOME_V1_NAMESPACE::value_storage<void, void, void> test_constexpr2b()
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  return value_storage<void, void, void>();  // NOLINT
}
// Test option<int> for constexpr
static constexpr inline BOOST_OUTCOME_V1_NAMESPACE::option<int> test_constexpr3a(int f)
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  return make_valued_option<int>(f);
}
// Test option<bool> for constexpr
static constexpr inline BOOST_OUTCOME_V1_NAMESPACE::option<bool> test_constexpr3b()
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  return make_empty_option<bool>();
}

BOOST_AUTO_TEST_CASE(works / monad / constexpr, "Tests that the monad works as intended in a constexpr evaluation context")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  using namespace QUICKCPPLIB_NAMESPACE::tribool;

  static_assert(std::is_literal_type<value_storage<int, void, void>>::value, "value_storage<int, void, void> is not a literal type!");
  static_assert(std::is_literal_type<value_storage<void, void, void>>::value, "value_storage<void, void, void> is not a literal type!");
  static_assert(std::is_literal_type<option<int>>::value, "option<int> is not a literal type!");
  static_assert(std::is_literal_type<option<bool>>::value, "option<bool> is not a literal type!");
  // Unfortunately result<T> can never be a literal type as error_code can never be literal
  //
  // It can however be trivially destructible as error_code is trivially destructible. That
  // makes possible lots of compiler optimisations
  static_assert(!std::is_literal_type<result<int>>::value, "result<int> is a literal type!");
  static_assert(result<int>::is_trivially_destructible, "result<int> is not trivially destructible!");
  static_assert(std::is_trivially_destructible<result<int>>::value, "result<int> is not trivially destructible!");
  static_assert(result<void>::is_trivially_destructible, "result<void> is not trivially destructible!");
  static_assert(std::is_trivially_destructible<result<void>>::value, "result<void> is not trivially destructible!");

  constexpr auto c = test_constexpr2a(5);
  constexpr auto d = test_constexpr2b();
  constexpr auto e = test_constexpr3a(5);
  constexpr auto f = test_constexpr3b();
  (void) c;
  (void) d;
  (void) e;
  (void) f;
}
#endif

