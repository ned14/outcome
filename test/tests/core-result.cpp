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

#ifdef TESTING_WG21_EXPERIMENTAL_RESULT
#include "../../include/outcome/experimental/result.hpp"
#else
#include "../../include/outcome/result.h"
#include "../../include/outcome/result.hpp"
#endif
#include "quickcpplib/include/boost/test/unit_test.hpp"

BOOST_AUTO_TEST_CASE(works / result, "Tests that the result works as intended")
{
#ifdef TESTING_WG21_EXPERIMENTAL_RESULT
  using namespace std::experimental;
  using std::in_place_type;
#else
  using namespace OUTCOME_V2_NAMESPACE;
#endif

  static_assert(std::is_constructible<result<long>, int>::value, "Sanity check that monad can be constructed from a value_type");
  static_assert(!std::is_constructible<result<result<long>>, int>::value, "Sanity check that outer monad can be constructed from an inner monad's value_type");
  static_assert(!std::is_constructible<result<result<result<long>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");
  static_assert(!std::is_constructible<result<result<result<result<long>>>>, int>::value, "Sanity check that outer monad can be constructed from an inner inner monad's value_type");

  static_assert(std::is_constructible<result<int>, result<long>>::value, "Sanity check that compatible monads can be constructed from one another");
  static_assert(std::is_constructible<result<result<int>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<result<result<result<int>>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<result<result<result<result<int>>>>, result<long>>::value, "Sanity check that outer monad can be constructed from a compatible monad three or more nestings deep");
  static_assert(!std::is_constructible<result<std::string>, result<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");

#ifndef TESTING_WG21_EXPERIMENTAL_RESULT
  static_assert(std::is_constructible<result<int>, result<void>>::value, "Sanity check that all monads can be constructed from a void monad");
  static_assert(std::is_constructible<result<result<int>>, result<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad");
  static_assert(std::is_constructible<result<result<result<int>>>, result<void>>::value, "Sanity check that outer monad can be constructed from a compatible monad up to two nestings deep");
  static_assert(!std::is_constructible<result<void>, result<int>>::value, "Sanity check that incompatible monads cannot be constructed from one another");
#endif
  static_assert(std::is_void<result<void>::value_type>::value, "Sanity check that result<void> has a void value_type");
#ifndef TESTING_WG21_EXPERIMENTAL_RESULT
  static_assert(std::is_void<result<void, void>::error_type>::value, "Sanity check that result<void, void> has a void error_type");
#endif

  static_assert(std::is_same<result<int>::value_type, int>::value, "Sanity check that result<int> has a int value_type");
  static_assert(std::is_same<result<int>::error_type, std::error_code>::value, "Sanity check that result<int> has a error_code error_type");


  {  // errored int
    result<int> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK_NO_THROW(m.error());
  }
  {  // errored void
    result<void> m(std::errc::bad_address);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
// BOOST_CHECK(!m.has_exception());
#ifndef TESTING_WG21_EXPERIMENTAL_RESULT
    BOOST_CHECK_THROW(([&m]() -> void { return m.value(); }()), const std::system_error &);
#endif
    BOOST_CHECK_NO_THROW(m.error());
  }
  {  // valued int
    result<int> m(5);
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    // BOOST_CHECK(!m.has_exception());
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
    // BOOST_CHECK(!m.has_exception());
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
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_NO_THROW(m.value());  // works, but type returned is unusable
    BOOST_CHECK_THROW(m.error(), const bad_result_access &);
  }
  {  // errored
    std::error_code ec(5, std::system_category());
    result<int> m(ec);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
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
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const std::system_error &);
    BOOST_CHECK(m.error() == e);
  }
#ifndef TESTING_WG21_EXPERIMENTAL_RESULT
  {  // custom error type
    struct Foo
    {
    };
    result<int, Foo> m(in_place_type<Foo>);
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), const bad_result_access &);
    BOOST_CHECK_NO_THROW(m.error());
  }
  if(false)  // NOLINT
  {          // void, void is permitted, but is not constructible
    result<void, void> *m = nullptr;
    m->value();
    m->error();
  }
#endif

  {
    // Deliberately define non-trivial operations
    struct udt
    {
      int _v{0};
      udt() = default;
      udt(udt &&o) noexcept : _v(o._v) {}
      udt(const udt &o)  // NOLINT
      : _v(o._v)
      {
      }
      udt &operator=(udt &&o) noexcept
      {
        _v = o._v;
        return *this;
      }
      udt &operator=(const udt &o)  // NOLINT
      {
        _v = o._v;
        return *this;
      }
      ~udt() { _v = 0; }
    };
    // No default construction, no copy nor move
    struct udt2
    {
      udt2() = delete;
      udt2(udt2 &&) = delete;
      udt2(const udt2 &) = delete;
      udt2 &operator=(udt2 &&) = delete;
      udt2 &operator=(const udt2 &) = delete;
      explicit udt2(int /*unused*/) {}
      ~udt2() = default;
    };
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


    result<int> a(5);
    result<int> b(std::make_error_code(std::errc::invalid_argument));
    std::cout << sizeof(a) << std::endl;  // 32 bytes
    if(false)                             // NOLINT
    {
      b.assume_value();
      a.assume_error();
    }
    try
    {
      b.value();
      std::cerr << "fail" << std::endl;
      std::terminate();
    }
    catch(const std::system_error & /*unused*/)
    {
    }
    static_assert(!std::is_default_constructible<decltype(a)>::value, "");
    static_assert(!std::is_nothrow_default_constructible<decltype(a)>::value, "");
    static_assert(std::is_copy_constructible<decltype(a)>::value, "");
// Quality of implementation of std::optional is poor :(
#ifndef TESTING_WG21_EXPERIMENTAL_RESULT
    static_assert(std::is_trivially_copy_constructible<decltype(a)>::value, "");
    static_assert(std::is_nothrow_copy_constructible<decltype(a)>::value, "");
    static_assert(std::is_copy_assignable<decltype(a)>::value, "");
    static_assert(std::is_trivially_copy_assignable<decltype(a)>::value, "");
    static_assert(std::is_nothrow_copy_assignable<decltype(a)>::value, "");
#endif
    static_assert(std::is_trivially_destructible<decltype(a)>::value, "");
    static_assert(std::is_nothrow_destructible<decltype(a)>::value, "");

    // Test void compiles
    result<void> c(in_place_type<void>);
    result<void> c2(c);
    (void) c2;

    // Test a standard udt compiles
    result<udt> d(in_place_type<udt>);
    result<udt> d2(d);
    static_assert(!std::is_default_constructible<decltype(d)>::value, "");
    static_assert(!std::is_nothrow_default_constructible<decltype(d)>::value, "");
    static_assert(std::is_copy_constructible<decltype(d)>::value, "");
    static_assert(!std::is_trivially_copy_constructible<decltype(d)>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<decltype(d)>::value, "");
    static_assert(std::is_copy_assignable<decltype(d)>::value, "");
    static_assert(!std::is_trivially_copy_assignable<decltype(d)>::value, "");
    static_assert(!std::is_nothrow_copy_assignable<decltype(d)>::value, "");
    static_assert(std::is_move_assignable<decltype(d)>::value, "");
    static_assert(!std::is_trivially_move_assignable<decltype(d)>::value, "");
    static_assert(std::is_nothrow_move_assignable<decltype(d)>::value, "");
    static_assert(!std::is_trivially_destructible<decltype(d)>::value, "");
    static_assert(std::is_nothrow_destructible<decltype(d)>::value, "");

    // Test a highly pathological udt compiles
    result<udt2> e(in_place_type<udt2>, 5);
    // result<udt2> e2(e);
    static_assert(!std::is_default_constructible<decltype(e)>::value, "");
    static_assert(!std::is_nothrow_default_constructible<decltype(e)>::value, "");
    static_assert(!std::is_copy_constructible<decltype(e)>::value, "");
    static_assert(!std::is_trivially_copy_constructible<decltype(e)>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<decltype(e)>::value, "");
    static_assert(!std::is_copy_assignable<decltype(e)>::value, "");
    static_assert(!std::is_trivially_copy_assignable<decltype(e)>::value, "");
    static_assert(!std::is_nothrow_copy_assignable<decltype(e)>::value, "");
    static_assert(!std::is_move_assignable<decltype(e)>::value, "");
    static_assert(!std::is_trivially_move_assignable<decltype(e)>::value, "");
    static_assert(!std::is_nothrow_move_assignable<decltype(e)>::value, "");

#if OUTCOME_ENABLE_POSITIVE_STATUS
    // Test value + status info works, and in constexpr
    using cresult_type = result<int, const char *>;
    constexpr const char *niall = "niall";
    constexpr cresult_type f(5, niall);
    constexpr cresult_type f2(f);
    static_assert(f, "");
    static_assert(f.has_value(), "");
    static_assert(!f.has_error(), "");
    static_assert(f.has_status(), "");
    static_assert(f.assume_value() == 5, "");
    static_assert(f.assume_status() == niall, "");
    static_assert(f.value() == 5, "");
    static_assert(f.status() == niall, "");
#endif

    // Test a udt which can only be constructed in place compiles
    result<udt3> g(in_place_type<udt3>, 5, static_cast<const char *>("niall"), nullptr);
    // Does converting inplace construction also work?
    result<udt3> h(5, static_cast<const char *>("niall"), nullptr);
    result<udt3> i(ENOMEM, std::generic_category());
    BOOST_CHECK(h.has_value());
    BOOST_CHECK(i.has_error());
  }

  // Test direct use of error code enum works
  {
    constexpr result<int, std::errc> a(5), b(std::errc::invalid_argument);
    static_assert(a.value() == 5, "a is not 5");
    static_assert(b.error() == std::errc::invalid_argument, "b is not errored");
    BOOST_CHECK_THROW(b.value(), const std::system_error &);
  }

  // Test C compatibility
  {
    CXX_DECLARE_RESULT(int, int);
    CXX_RESULT(int) c_result = {5, 1, 0, nullptr};
    result<int> cxx_result{5};
    static_assert(sizeof(c_result) == sizeof(cxx_result), "Sizes of C and C++ results do not match!");

    union test_t {
      result<int> cxx;
      CXX_RESULT(int) c;
    };
    test_t a{5};
    BOOST_CHECK(a.cxx.has_value());          // NOLINT
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(a.c));  // NOLINT
    BOOST_CHECK(a.c.value == 5);             // NOLINT

    test_t b{std::errc::invalid_argument};
    BOOST_CHECK(b.cxx.has_error());          // NOLINT
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(b.c));  // NOLINT
    BOOST_CHECK(b.c.error == EINVAL);        // NOLINT
  }
}
