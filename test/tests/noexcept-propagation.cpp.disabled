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

#ifdef __cpp_exceptions
// std nothrow traits seem to return random values if exceptions are disabled on MSVC
BOOST_AUTO_TEST_CASE(works / monad / noexcept, "Tests that the monad correctly inherits noexcept from its type R")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  {
    using type = outcome<int>;
    std::cout << "outcome<int> is_nothrow_copy_constructible=" << type::is_nothrow_copy_constructible << std::endl;
    std::cout << "outcome<int> is_nothrow_move_constructible=" << type::is_nothrow_move_constructible << std::endl;
    std::cout << "outcome<int> is_nothrow_copy_assignable=" << type::is_nothrow_copy_assignable << std::endl;
    std::cout << "outcome<int> is_nothrow_move_assignable=" << type::is_nothrow_move_assignable << std::endl;
    std::cout << "outcome<int> is_nothrow_destructible=" << type::is_nothrow_destructible << std::endl;
    BOOST_CHECK(type::is_nothrow_copy_constructible == std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_move_constructible == std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_copy_assignable == std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(type::is_nothrow_move_assignable == std::is_nothrow_move_assignable<type>::value);
// VS2015 is randomly flipping std::is_nothrow_destructible for outcome<int>. I'd assume memory corruption.
#ifndef _MSC_VER
    BOOST_CHECK(type::is_nothrow_destructible == std::is_nothrow_destructible<type>::value);
#endif
    BOOST_CHECK(std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(std::is_nothrow_move_assignable<type>::value);
// VS2015 is randomly flipping std::is_nothrow_destructible for outcome<int>. I'd assume memory corruption.
#ifndef _MSC_VER
    BOOST_CHECK(std::is_nothrow_destructible<type>::value);
#endif
  }
  {
    using type = outcome<std::string>;
    std::cout << "string is_nothrow_copy_constructible=" << std::is_nothrow_copy_constructible<std::string>::value << std::endl;
    std::cout << "string is_nothrow_move_constructible=" << std::is_nothrow_move_constructible<std::string>::value << std::endl;
    std::cout << "string is_nothrow_copy_assignable=" << std::is_nothrow_copy_assignable<std::string>::value << std::endl;
    std::cout << "string is_nothrow_move_assignable=" << std::is_nothrow_move_assignable<std::string>::value << std::endl;
    std::cout << "string is_nothrow_destructible=" << std::is_nothrow_destructible<std::string>::value << std::endl;
    std::cout << "outcome<string> is_nothrow_copy_constructible=" << type::is_nothrow_copy_constructible << std::endl;
    std::cout << "outcome<string> is_nothrow_move_constructible=" << type::is_nothrow_move_constructible << std::endl;
    std::cout << "outcome<string> is_nothrow_copy_assignable=" << type::is_nothrow_copy_assignable << std::endl;
    std::cout << "outcome<string> is_nothrow_move_assignable=" << type::is_nothrow_move_assignable << std::endl;
    std::cout << "outcome<string> is_nothrow_destructible=" << type::is_nothrow_destructible << std::endl;
    BOOST_CHECK(type::is_nothrow_copy_constructible == std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_move_constructible == std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_copy_assignable == std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(type::is_nothrow_move_assignable == std::is_nothrow_move_assignable<type>::value);
    BOOST_CHECK(type::is_nothrow_destructible == std::is_nothrow_destructible<type>::value);
    BOOST_CHECK(std::is_nothrow_copy_constructible<type>::value == std::is_nothrow_copy_constructible<std::string>::value);
    BOOST_CHECK(std::is_nothrow_move_constructible<type>::value == std::is_nothrow_move_constructible<std::string>::value);
    BOOST_CHECK(std::is_nothrow_copy_assignable<type>::value == std::is_nothrow_copy_assignable<std::string>::value);
    BOOST_CHECK(std::is_nothrow_move_assignable<type>::value == std::is_nothrow_move_assignable<std::string>::value);
    BOOST_CHECK(std::is_nothrow_destructible<type>::value == std::is_nothrow_destructible<std::string>::value);
  }
  {
    struct Except
    {
      int n;
      Except() = delete;
      Except(const Except & /*unused*/) noexcept(false)
          : n(0)
      {
      }
      Except(Except && /*unused*/) noexcept(false)
          : n(0)
      {
      }
      Except &operator=(const Except & /*unused*/) noexcept(false) { return *this; }
      Except &operator=(Except && /*unused*/) noexcept(false) { return *this; }
      ~Except() noexcept(false) { n = 0; }
    };
    using type = outcome<Except>;
    std::cout << "outcome<Except> is_nothrow_copy_constructible=" << type::is_nothrow_copy_constructible << std::endl;
    std::cout << "outcome<Except> is_nothrow_move_constructible=" << type::is_nothrow_move_constructible << std::endl;
    std::cout << "outcome<Except> is_nothrow_copy_assignable=" << type::is_nothrow_copy_assignable << std::endl;
    std::cout << "outcome<Except> is_nothrow_move_assignable=" << type::is_nothrow_move_assignable << std::endl;
    std::cout << "outcome<Except> is_nothrow_destructible=" << type::is_nothrow_destructible << std::endl;
    BOOST_CHECK(type::is_nothrow_copy_constructible == std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_move_constructible == std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(type::is_nothrow_copy_assignable == std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(type::is_nothrow_move_assignable == std::is_nothrow_move_assignable<type>::value);
#if defined(__c2__) || (!defined(_MSC_VER) || (_MSC_FULL_VER != 191025017 /* VS2017 RTM */ && _MSC_FULL_VER != 191025019 /* VS2017 Update 1 */))
    BOOST_CHECK(type::is_nothrow_destructible == std::is_nothrow_destructible<type>::value);
#endif
    BOOST_CHECK(!std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_assignable<type>::value);
#if defined(__c2__) || (!defined(_MSC_VER) || (_MSC_FULL_VER != 191025017 /* VS2017 RTM */ && _MSC_FULL_VER != 191025019 /* VS2017 Update 1 */))
    BOOST_CHECK(!std::is_nothrow_destructible<type>::value);
#endif
  }
}
#endif

