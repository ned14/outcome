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
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  using namespace QUICKCPPLIB_NAMESPACE::tribool;
  static_assert(std::is_constructible<outcome<long>, int>::value, "Sanity check that monad can be constructed from a value_type");
  static_assert(std::is_constructible<outcome<outcome<long>>, int>::value, "Sanity check that outer monad can be constructed from an inner monad's value_type");
  static_assert(!std::is_constructible<outcome<outcome<outcome<long>>>, int>::value, "Sanity check that outer monad can not be constructed from an inner inner monad's value_type");
  static_assert(!std::is_constructible<outcome<outcome<outcome<outcome<long>>>>, int>::value, "Sanity check that outer monad can not be constructed from an inner inner monad's value_type");

  static_assert(std::is_constructible<outcome<int>, outcome<long>>::value, "Sanity check that compatible monads can be constructed from one another");
  static_assert(std::is_constructible<outcome<outcome<int>>, outcome<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<outcome<outcome<outcome<int>>>, outcome<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<outcome<outcome<outcome<outcome<int>>>>, outcome<long>>::value, "Sanity check that outer monad cannot be constructed from a compatible monad three or more nestings deep");
  static_assert(!std::is_constructible<outcome<std::string>, outcome<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(std::is_constructible<outcome<int>, outcome<void>>::value, "Sanity check that all monads can be constructed from a void monad");
  static_assert(std::is_constructible<outcome<outcome<int>>, outcome<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<outcome<outcome<outcome<int>>>, outcome<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<outcome<void>, outcome<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

  static_assert(!outcome<void>::has_value_type, "Sanity check that outcome<void> does not have a value_type");
  static_assert(outcome<void>::has_error_type, "Sanity check that outcome<void> has an error_type");
  static_assert(outcome<void>::has_exception_type, "Sanity check that outcome<void> has an exception_type");
  // static_assert(std::is_void<outcome<void>::value_type>::value, "Sanity check that outcome<void> has a void value_type");

  static_assert(!result<void>::has_value_type, "Sanity check that result<void> does not have a value_type");
  static_assert(result<void>::has_error_type, "Sanity check that result<void> has an error_type");
  static_assert(!result<void>::has_exception_type, "Sanity check that result<void> has an exception_type");
  // static_assert(std::is_void<result<void>::value_type>::value, "Sanity check that result<void> has a void value_type");
  // static_assert(std::is_void<result<void>::exception_type>::value, "Sanity check that result<void> has a void exception_type");

  static_assert(!option<void>::has_value_type, "Sanity check that option<void> does not have a value_type");
  static_assert(!option<void>::has_error_type, "Sanity check that option<void> has an error_type");
  static_assert(!option<void>::has_exception_type, "Sanity check that option<void> has an exception_type");
  // static_assert(std::is_void<option<void>::value_type>::value, "Sanity check that option<void> has a void value_type");
  // static_assert(std::is_void<option<void>::error_type>::value, "Sanity check that option<void> has a void error_type");
  // static_assert(std::is_void<option<void>::exception_type>::value, "Sanity check that option<void> has a void exception_type");
  {
    outcome<int> m;
    BOOST_CHECK(!m);
    BOOST_CHECK(unknown(tribool(m)));
    BOOST_CHECK(!m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.get(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_error(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_exception(), const bad_outcome &);
  }
  {
    outcome<void> m;
    BOOST_CHECK(!m);
    BOOST_CHECK(unknown(tribool(m)));
    BOOST_CHECK(!m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(([&m]() -> void { return m.get(); }()), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_error(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_exception(), const bad_outcome &);
  }
  {
    outcome<int> m(5);
    BOOST_CHECK(m);
    BOOST_CHECK(true_(tribool(m)));
    BOOST_CHECK(m.is_ready());
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.get() == 5);
    m.get() = 6;
    BOOST_CHECK(m.get() == 6);
    BOOST_CHECK(!m.get_error());
    BOOST_CHECK(!m.get_exception());
    m.clear();
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.get(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_error(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_exception(), const bad_outcome &);
  }
  {
    outcome<std::string> m("niall");
    BOOST_CHECK(m);
    BOOST_CHECK(m.is_ready());
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.get() == "niall");
    m.get() = "NIALL";
    BOOST_CHECK(m.get() == "NIALL");
    auto temp(std::move(m).get());
    BOOST_CHECK(temp == "NIALL");
    BOOST_CHECK(m.get().empty());  // NOLINT
    BOOST_CHECK(!m.get_error());
    BOOST_CHECK(!m.get_exception());
    m.clear();
    BOOST_CHECK(!m);
  }
  {
    outcome<void> m;
    m.set_value();
    BOOST_CHECK(m);
    BOOST_CHECK(true_(tribool(m)));
    BOOST_CHECK(m.is_ready());
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_NO_THROW(m.get());  // works, but type returned is unusable
    BOOST_CHECK(!m.get_error());
    BOOST_CHECK(!m.get_exception());
    m.clear();
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.get(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_error(), const bad_outcome &);
    BOOST_CHECK_THROW(m.get_exception(), const bad_outcome &);
  }
  {
    error_code_extended ec(5, stl11::system_category());
    auto e = std::make_exception_ptr(stl11::system_error(ec));  // NOLINT
    outcome<int> m(ec);
    BOOST_CHECK(!m);
    BOOST_CHECK(false_(tribool(m)));
    BOOST_CHECK(m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.get(), const stl11::system_error &);
    BOOST_CHECK(m.get_error() == ec);
#ifdef __cpp_exceptions
    BOOST_CHECK(m.get_exception());
    try
    {
      std::rethrow_exception(m.get_exception());
    }
    catch(const stl11::system_error &ex)
    {
      BOOST_CHECK(ex.code() == ec);
      BOOST_CHECK(ex.code().value() == 5);
    }
#endif
  }
  {
    struct Foo
    {
    };
    auto e = std::make_exception_ptr(Foo());
    outcome<int> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(false_(tribool(m)));
    BOOST_CHECK(m.is_ready());
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.get(), const Foo &);
    BOOST_CHECK(m.get_error());
    BOOST_CHECK(m.get_exception() == e);
  }
}
