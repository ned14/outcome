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

#include "../../include/outcome/result.hpp"
#include "../quickcpplib/include/boost/test/unit_test.hpp"

BOOST_AUTO_TEST_CASE(works / result, "Tests that the result works as intended")
{
  using namespace OUTCOME_V2_NAMESPACE;

  static_assert(std::is_constructible<result<long>, int>::value, "Sanity check that monad can be constructed from a value_type");
  static_assert(std::is_constructible<result<result<long>>, int>::value, "Sanity check that outer monad can be constructed from an inner monad's value_type");
  static_assert(std::is_constructible<result<result<result<long>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");
  static_assert(std::is_constructible<result<result<result<result<long>>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");

  static_assert(std::is_constructible<result<int>, result<long>>::value, "Sanity check that compatible monads can be constructed from one another");
  static_assert(std::is_constructible<result<result<int>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<result<result<result<int>>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(std::is_constructible<result<result<result<result<int>>>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad three or more nestings deep");
  static_assert(!std::is_constructible<result<std::string>, result<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(std::is_constructible<result<int>, result<void>>::value, "Sanity check that all monads can be constructed from a void monad");
  static_assert(std::is_constructible<result<result<int>>, result<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<result<result<result<int>>>, result<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<result<void>, result<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(std::is_void<result<void>::value_type>::value, "Sanity check that result<void> has a void value_type");
  static_assert(std::is_void<result<void, void>::error_type>::value, "Sanity check that result<void, void> has a void error_type");

  static_assert(std::is_same<result<int>::value_type, int>::value, "Sanity check that result<int> has a int value_type");
  static_assert(std::is_same<result<int>::error_type, std::error_code>::value, "Sanity check that result<int> has a error_code error_type");


  {  // errored int
    result<int> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK_NO_THROW(m.error());
  }
  {  // errored void
    result<void> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(([&m]() -> void { return m.value(); }()), const std::system_error &);
    BOOST_CHECK_NO_THROW(m.error());
  }
  {  // valued int
    result<int> m(5);
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.value() == 5);
    m.value() = 6;
    BOOST_CHECK(m.value() == 6);
    BOOST_CHECK_THROW(m.error(), const bad_result_access &);
  }
  {  // moves do not clear state
    result<std::string> m("niall");
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
    result<void> m(in_place_type<void>);
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_NO_THROW(m.value());  // works, but type returned is unusable
    BOOST_CHECK_THROW(m.error(), const bad_result_access &);
  }
  {  // errored
    std::error_code ec(5, std::system_category());
    result<int> m(ec);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK(m.error() == ec);
  }
  {  // errored, custom
    std::error_code ec(5, std::system_category());
    auto e = std::make_exception_ptr(std::system_error(ec));  // NOLINT
    result<int, std::exception_ptr> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK(m.error() == e);
  }
  {  // custom error type
    struct Foo
    {
    };
    result<int, Foo> m(in_place_type<Foo>);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const Foo &);
    BOOST_CHECK_NO_THROW(m.error());
  }
  if(false)  // NOLINT
  {          // void, void is permitted, but is not constructible
    result<void, void> *m = nullptr;
    m->value();
    m->error();
  }
}
