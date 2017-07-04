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

BOOST_AUTO_TEST_CASE(works / outcome, "Tests that the outcome works as intended")
{
  using namespace OUTCOME_V2_NAMESPACE;

  static_assert(trait::is_exception_ptr<std::exception_ptr>::value, "Trait for detecting exception_ptr is broken");

  static_assert(std::is_constructible<outcome<long>, int>::value, "Sanity check that monad can be constructed from a value_type");
  static_assert(std::is_constructible<outcome<outcome<long>>, int>::value, "Sanity check that outer monad can be constructed from an inner monad's value_type");
  static_assert(std::is_constructible<outcome<outcome<outcome<long>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");
  static_assert(std::is_constructible<outcome<outcome<outcome<outcome<long>>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");

  static_assert(std::is_constructible<outcome<int>, outcome<long>>::value, "Sanity check that compatible monads can be constructed from one another");
  static_assert(std::is_constructible<outcome<outcome<int>>, outcome<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<outcome<outcome<outcome<int>>>, outcome<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(std::is_constructible<outcome<outcome<outcome<outcome<int>>>>, outcome<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad three or more nestings deep");
  static_assert(!std::is_constructible<outcome<std::string>, outcome<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(std::is_constructible<outcome<int>, outcome<void>>::value, "Sanity check that all monads can be constructed from a void monad");
  static_assert(std::is_constructible<outcome<outcome<int>>, outcome<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<outcome<outcome<outcome<int>>>, outcome<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<outcome<void>, outcome<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(std::is_void<result<void>::value_type>::value, "Sanity check that result<void> has a void value_type");
  static_assert(std::is_void<result<void, void>::error_type>::value, "Sanity check that result<void, void> has a void error_type");
  // static_assert(std::is_void<outcome<void, void, void>::exception_type>::value, "Sanity check that outcome<void, void, void> has a void exception_type");

  static_assert(std::is_same<outcome<int>::value_type, int>::value, "Sanity check that outcome<int> has a int value_type");
  static_assert(std::is_same<outcome<int>::error_type, std::error_code>::value, "Sanity check that outcome<int> has a error_code error_type");
  static_assert(std::is_same<outcome<int>::exception_type, std::exception_ptr>::value, "Sanity check that outcome<int> has a exception_ptr exception_type");


  {  // errored int
    outcome<int> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK_NO_THROW(m.error());
    BOOST_CHECK_THROW(m.exception(), const bad_outcome_access &);
    BOOST_CHECK_THROW(std::rethrow_exception(m.failure()), const std::system_error &);
  }
  {  // errored void
    outcome<void> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(([&m]() -> void { return m.value(); }()), const std::system_error &);
    BOOST_CHECK_NO_THROW(m.error());
    BOOST_CHECK_THROW(m.exception(), const bad_outcome_access &);
    BOOST_CHECK_THROW(std::rethrow_exception(m.failure()), const std::system_error &);
  }
  {  // valued int
    outcome<int> m(5);
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.value() == 5);
    m.value() = 6;
    BOOST_CHECK(m.value() == 6);
    BOOST_CHECK_THROW(m.error(), const bad_outcome_access &);
    BOOST_CHECK_THROW(m.exception(), const bad_outcome_access &);
    BOOST_CHECK(!m.failure());
  }
  {  // moves do not clear state
    outcome<std::string> m("niall");
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.value() == "niall");
    m.value() = "NIALL";
    BOOST_CHECK(m.value() == "NIALL");
    auto temp(std::move(m).value());
    BOOST_CHECK(temp == "NIALL");
    BOOST_CHECK(m.value().empty());  // NOLINT
  }
  {  // valued void
    outcome<void> m(in_place_type<void>);
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_NO_THROW(m.value());  // works, but type returned is unusable
    BOOST_CHECK_THROW(m.error(), const bad_outcome_access &);
    BOOST_CHECK_THROW(m.exception(), const bad_outcome_access &);
    BOOST_CHECK(!m.failure());
  }
  {  // errored
    std::error_code ec(5, std::system_category());
    outcome<int> m(ec);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK(m.error() == ec);
    BOOST_CHECK_THROW(m.exception(), const bad_outcome_access &);
#ifdef __cpp_exceptions
    BOOST_CHECK(m.failure());
    try
    {
      std::rethrow_exception(m.failure());
    }
    catch(const std::system_error &ex)
    {
      BOOST_CHECK(ex.code() == ec);
      BOOST_CHECK(ex.code().value() == 5);
    }
#endif
  }
  {  // excepted
    std::error_code ec(5, std::system_category());
    auto e = std::make_exception_ptr(std::system_error(ec));  // NOLINT
    outcome<int> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK_THROW(m.error(), const bad_outcome_access &);
    BOOST_CHECK(m.exception() == e);
#ifdef __cpp_exceptions
    BOOST_CHECK(m.failure());
    try
    {
      std::rethrow_exception(m.failure());
    }
    catch(const std::system_error &ex)
    {
      BOOST_CHECK(ex.code() == ec);
      BOOST_CHECK(ex.code().value() == 5);
    }
#endif
  }
  {  // custom error type
    struct Foo
    {
    };
    auto e = std::make_exception_ptr(Foo());
    outcome<int> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.value(), const Foo &);
    BOOST_CHECK_THROW(m.error(), const bad_outcome_access &);
    BOOST_CHECK(m.exception() == e);
  }
}
