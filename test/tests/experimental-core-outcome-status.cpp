/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (4 commits)


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

#include "../../include/outcome/experimental/status_outcome.hpp"

#define OUTCOME_PREVENT_CONVERSION_WORKAROUND std
template <class T, class S = SYSTEM_ERROR2_NAMESPACE::system_code, class P = OUTCOME_PREVENT_CONVERSION_WORKAROUND::exception_ptr> using outcome = OUTCOME_V2_NAMESPACE::experimental::status_outcome<T, S, P>;
using OUTCOME_V2_NAMESPACE::in_place_type;

#include "quickcpplib/boost/test/unit_test.hpp"

#include <iostream>

#ifdef _MSC_VER
#pragma warning(disable : 4702)  // unreachable code
#endif

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / outcome, "Tests that the outcome with status_code works as intended")
{
  using namespace SYSTEM_ERROR2_NAMESPACE;

  {  // errored int
    outcome<int> m(generic_code{errc::bad_address});
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), status_error<void>);
    BOOST_CHECK_NO_THROW(m.error());
    BOOST_CHECK_THROW(OUTCOME_PREVENT_CONVERSION_WORKAROUND::rethrow_exception(m.failure()), generic_error);
  }
  {  // errored void
    outcome<void> m(generic_code{errc::bad_address});
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(([&m]() -> void { return m.value(); }()), generic_error);
    BOOST_CHECK_NO_THROW(m.error());
    BOOST_CHECK_THROW(OUTCOME_PREVENT_CONVERSION_WORKAROUND::rethrow_exception(m.failure()), generic_error);
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
    BOOST_CHECK(!m.failure());
  }
  {  // errored
    error ec(errc::no_link);
    outcome<int> m(ec.clone());
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), generic_error);
    BOOST_CHECK(m.error() == ec);
#ifdef __cpp_exceptions
    BOOST_CHECK(m.failure());
    try
    {
      OUTCOME_PREVENT_CONVERSION_WORKAROUND::rethrow_exception(m.failure());
    }
    catch(const generic_error &ex)
    {
      BOOST_CHECK(ex.code() == ec);
      BOOST_CHECK(ex.code().value() == errc::no_link);
    }
#endif
  }
#if !defined(__APPLE__) || defined(__cpp_exceptions)
  {  // excepted
    OUTCOME_PREVENT_CONVERSION_WORKAROUND::error_code ec(5, OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_category());
    auto e = OUTCOME_PREVENT_CONVERSION_WORKAROUND::make_exception_ptr(OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_error(ec));  // NOLINT
    outcome<int> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.value(), OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_error);
    BOOST_CHECK(m.exception() == e);
#ifdef __cpp_exceptions
    BOOST_CHECK(m.failure());
    try
    {
      OUTCOME_PREVENT_CONVERSION_WORKAROUND::rethrow_exception(m.failure());
    }
    catch(const OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_error &ex)
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
    auto e = OUTCOME_PREVENT_CONVERSION_WORKAROUND::make_exception_ptr(Foo());
    outcome<int> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
    BOOST_CHECK_THROW(m.value(), Foo);
    BOOST_CHECK(m.exception() == e);
  }
  {  // outcome<void, void> should work
    OUTCOME_PREVENT_CONVERSION_WORKAROUND::error_code ec(5, OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_category());
    auto e = OUTCOME_PREVENT_CONVERSION_WORKAROUND::make_exception_ptr(OUTCOME_PREVENT_CONVERSION_WORKAROUND::system_error(ec));
    outcome<void, void> m(e);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(!m.has_error());
    BOOST_CHECK(m.has_exception());
  }
#endif


  {
    outcome<int> a(5);
    outcome<int> b(generic_code{errc::invalid_argument});
    std::cout << sizeof(a) << std::endl;  // 40 bytes
    a.assume_value();
    b.assume_error();
#ifdef __cpp_exceptions
    try
    {
      b.value();
      std::cerr << "fail" << std::endl;
      std::terminate();
    }
    catch(const generic_error & /*unused*/)
    {
    }
#endif
    static_assert(!std::is_default_constructible<decltype(a)>::value, "");
    static_assert(!std::is_nothrow_default_constructible<decltype(a)>::value, "");
    static_assert(!std::is_copy_constructible<decltype(a)>::value, "");
    static_assert(!std::is_trivially_copy_constructible<decltype(a)>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<decltype(a)>::value, "");
    static_assert(!std::is_copy_assignable<decltype(a)>::value, "");
    static_assert(!std::is_trivially_copy_assignable<decltype(a)>::value, "");
    static_assert(!std::is_nothrow_copy_assignable<decltype(a)>::value, "");
    static_assert(!std::is_trivially_destructible<decltype(a)>::value, "");
    static_assert(std::is_nothrow_destructible<decltype(a)>::value, "");

    // Test void compiles
    outcome<void> c(in_place_type<void>);
    // Test int, void compiles
    outcome<int, void> d(in_place_type<OUTCOME_PREVENT_CONVERSION_WORKAROUND::exception_ptr>);
  }

  {
    // Can only be constructed via multiple args
    struct udt3
    {
      udt3() = delete;
      udt3(udt3 &&) = delete;
      udt3(const udt3 &) = delete;
      udt3 &operator=(udt3 &&) = delete;
      udt3 &operator=(const udt3 &) = delete;
      explicit udt3(int /*unused*/, const char * /*unused*/, std::nullptr_t /*unused*/) {}
      ~udt3() = default;
    };
    // Test a udt which can only be constructed in place compiles
    outcome<udt3> g(in_place_type<udt3>, 5, static_cast<const char *>("niall"), nullptr);
    // Does converting inplace construction also work?
    outcome<udt3> h(5, static_cast<const char *>("niall"), nullptr);
    BOOST_CHECK(h.has_value());
  }
}
