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

#define NANOSECONDS_PER_CPU_CYCLE (1000000000000ULL / 3700000000ULL)

#define _CRT_SECURE_NO_WARNINGS 1

#ifdef _MSC_VER
#pragma warning(disable : 4127)  // conditional expression is constant
#pragma warning(disable : 4503)  // decorated name length exceeded
#pragma warning(disable : 4714)  // function marked __forceinline not inlined
#endif

#include "../include/boost/outcome/outcome.hpp"

#define BOOSTLITE_BOOST_UNIT_TEST_CUSTOM_MAIN_DEFINED
#include "../boost-lite/include/boost/test/unit_test.hpp"

#include <algorithm>
#include <cstdio>
#include <functional>
#include <unordered_map>

#ifdef _MSC_VER
#define BOOST_OUTCOME_POSIX_OPEN ::_open
#include <io.h>
#else
#define BOOST_OUTCOME_POSIX_OPEN ::open
#include <fcntl.h>
#endif

#ifdef __cpp_exceptions
#include "../boost-lite/include/allocator_testing.hpp"
#endif

BOOST_AUTO_TEST_SUITE(all)

#ifdef BOOST_OUTCOME_ENABLE_ADVANCED
BOOST_AUTO_TEST_CASE(works / traits, "Tests that the traits work as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::traits;
  {
    int foo = 1;
    // Capturing lambdas
    auto a = [foo](int) -> int { return foo; };
    auto b = [foo](int &&) -> int { return foo; };
    auto c = [foo](const int &) -> int { return foo; };
    auto d = [foo](int &) -> int { return foo; };
    // std function (class with call operator)
    auto e = std::function<int(int)>();
    auto f = std::function<int(int &&)>();
    // plain old functions
    int (*g)(int) = [](int) -> int { return 5; };
    int (*h)(int &&) = [](int &&) -> int { return 5; };
    int (*i)(const int &) = [](const int &) -> int { return 5; };
    int (*j)(int &) = [](int &) -> int { return 5; };
    (void) g;
    (void) h;
    (void) i;
    (void) j;

    static_assert(callable_argument_traits<decltype(a), int>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(b), int &&>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(c), const int &>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(d), int &>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(e), int>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(f), int &&>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(g), int>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(h), int &&>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(i), const int &>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(j), int &>::valid, "callable not recognised as valid");

    static_assert(!callable_argument_traits<decltype(a), int>::is_rvalue, "non-rvalue not recognised");
    static_assert(callable_argument_traits<decltype(b), int &&>::is_rvalue, "rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(c), const int &>::is_rvalue, "non-rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(d), int &>::is_rvalue, "non-rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(e), int>::is_rvalue, "non-rvalue not recognised");
    static_assert(callable_argument_traits<decltype(f), int &&>::is_rvalue, "rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(g), int>::is_rvalue, "non-rvalue not recognised");
    static_assert(callable_argument_traits<decltype(h), int &&>::is_rvalue, "rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(i), const int &>::is_rvalue, "non-rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(j), int &>::is_rvalue, "non-rvalue not recognised");

    static_assert(std::is_same<callable_argument_traits<decltype(a), int>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(b), int &&>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(c), const int &>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(d), int &>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(e), int>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(f), int &&>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(g), int>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(h), int &&>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(i), const int &>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(j), int &>::return_type, int>::value, "return type not deduced");
  }
#ifdef __cpp_generic_lambdas
  {
    int foo = 1;
    // Capturing lambdas with templated call functions
    auto a = [foo](auto) { return foo; };
    auto b = [foo](auto &&) { return foo; };
    auto c = [foo](const auto &) { return foo; };
    auto d = [foo](auto &) { return foo; };

    static_assert(callable_argument_traits<decltype(a), int>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(b), int &&>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(c), const int &>::valid, "callable not recognised as valid");
    static_assert(callable_argument_traits<decltype(d), int &>::valid, "callable not recognised as valid");

    static_assert(!callable_argument_traits<decltype(a), int>::is_rvalue, "non-rvalue not recognised");
    static_assert(callable_argument_traits<decltype(b), int &&>::is_rvalue, "rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(c), const int &>::is_rvalue, "non-rvalue not recognised");
    static_assert(!callable_argument_traits<decltype(d), int &>::is_rvalue, "non-rvalue not recognised");

    static_assert(callable_argument_traits<decltype(a), int>::is_auto, "auto type not deduced");
    static_assert(callable_argument_traits<decltype(b), int &&>::is_auto, "auto type not deduced");
    static_assert(callable_argument_traits<decltype(c), const int &>::is_auto, "auto type not deduced");
    static_assert(callable_argument_traits<decltype(d), int &>::is_auto, "auto type not deduced");

    static_assert(std::is_same<callable_argument_traits<decltype(a), int>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(b), int &&>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(c), const int &>::return_type, int>::value, "return type not deduced");
    static_assert(std::is_same<callable_argument_traits<decltype(d), int &>::return_type, int>::value, "return type not deduced");
  }
#endif
}
#endif

BOOST_AUTO_TEST_CASE(works / error_code_extended, "Tests that error_code_extended works as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  // This was actually broken for a long time and nobody noticed :(
  static_assert(!stl11::is_error_code_enum<stl11::errc>::value, "std::errc is an error code enum!");
  static_assert(stl11::is_error_condition_enum<stl11::errc>::value, "std::errc is not an error condition enum!");
  BOOST_CHECK(make_errored_result(stl11::errc::file_exists).error() == stl11::errc::file_exists);
}

BOOST_AUTO_TEST_CASE(works / monad, "Tests that the monad works as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  using namespace boost_lite::tribool;
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

BOOST_AUTO_TEST_CASE(works / monad / comparison, "Tests that the monad can compare to compatible monads")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  auto p = std::make_exception_ptr(std::runtime_error("hi"));
  // value comparison
  {
    outcome<int> a(1), b(2), c(2);
    BOOST_CHECK(a == a);
    BOOST_CHECK(b == b);
    BOOST_CHECK(c == c);
    BOOST_CHECK(a != b);
    BOOST_CHECK(b == c);
  }
  // homogeneous outcome comparison
  {
    outcome<int> a, b(2), c(make_errored_outcome<int>(EINVAL)), d(make_exceptional_outcome<int>(p));
    BOOST_CHECK(a == a);
    BOOST_CHECK(a != b);
    BOOST_CHECK(a != c);
    BOOST_CHECK(a != d);
    BOOST_CHECK(b == b);
    BOOST_CHECK(b != c);
    BOOST_CHECK(b != d);
    BOOST_CHECK(c == c);
    BOOST_CHECK(c != d);
    BOOST_CHECK(d == d);
    outcome<int> e(make_errored_outcome<int>(EINVAL)), f(make_exceptional_outcome<int>(p));
    BOOST_CHECK(c == e);
    BOOST_CHECK(d == f);
  }
  // heterogeneous outcome comparison, so outcome<int> to outcome<double> etc
  {
    outcome<int> a(1);
    outcome<double> b(1);
    outcome<unsigned short> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    outcome<void> d, e(make_valued_outcome<void>());
    outcome<unsigned short> f(make_errored_outcome<unsigned short>(EINVAL));
    outcome<double> g(make_exceptional_outcome<double>(p));
    BOOST_CHECK(a != d);
    BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    BOOST_CHECK(d != e);
    BOOST_CHECK(d != f);
    BOOST_CHECK(e != f);
    BOOST_CHECK(f != g);
  }
  // upconverting outcome comparison, so outcome<int>==result<int> etc
  {
    outcome<int> a(1);
    result<int> b(1);
    option<int> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    result<void> d, e(make_valued_result<void>()), f(make_errored_result<void>(EINVAL));
    option<bool> g, h(true);
    BOOST_CHECK(a != d);
    BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    BOOST_CHECK(a == h);
  }
  // Should I do outcome<int>(5) == 5? Unsure if it's wise
}


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
  using namespace boost_lite::tribool;

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


BOOST_AUTO_TEST_CASE(works / monad / optional, "Tests that the monad acts as an optional R")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  using boost_lite::tribool::tribool;
  std::cout << "sizeof(outcome<bool>) = " << sizeof(outcome<bool>) << std::endl;
  std::cout << "sizeof(result<bool>) = " << sizeof(result<bool>) << std::endl;
  std::cout << "sizeof(option<bool>) = " << sizeof(option<bool>) << std::endl;
  std::cout << "sizeof(option<tribool>) = " << sizeof(option<tribool>) << std::endl;

  std::cout << "sizeof(outcome<bool>[2]) = " << sizeof(outcome<bool>[2]) << std::endl;
  std::cout << "sizeof(result<bool>[2]) = " << sizeof(result<bool>[2]) << std::endl;
  std::cout << "sizeof(option<bool>[2]) = " << sizeof(option<bool>[2]) << std::endl;
  std::cout << "sizeof(option<tribool>[2]) = " << sizeof(option<tribool>[2]) << std::endl;

  std::cout << "sizeof(option<void>) = " << sizeof(option<void>) << std::endl;
  std::cout << "sizeof(option<void>[2]) = " << sizeof(option<void>[2]) << std::endl;

// Temporarily disable single byte storage until GCC fixes itself
#if !(defined(__GNUC__) && !defined(__clang__) && __GNUC__ < 7)
  BOOST_CHECK(!(sizeof(outcome<bool>) & 3));
  BOOST_CHECK(sizeof(option<void>) <= 1U);
  BOOST_CHECK(sizeof(option<bool>) <= 1U);
  BOOST_CHECK(sizeof(option<tribool>) <= 2U);
  BOOST_CHECK(sizeof(option<void>[2]) <= 2U);
  BOOST_CHECK(sizeof(option<bool>[2]) <= 2U);
  BOOST_CHECK(sizeof(option<tribool>[2]) <= 4U);
#endif

  // Make sure the special compact bool storage works
  BOOST_CHECK(option<bool>(false).get() == false);
  BOOST_CHECK(option<bool>(true).get() == true);

  //! [optional_example]
  auto maybe_getenv = [](const char *n) -> option<const char *> {
    const char *x = std::getenv(n);
    if(x != nullptr)
    {
      return x;
    }
    return {};
  };
  auto a = maybe_getenv("SHOULDNEVEREXIST");
  BOOST_CHECK(!a);
  BOOST_CHECK_THROW(a.value(), const bad_outcome &);
  BOOST_CHECK(a.value_or(nullptr) == nullptr);
#ifdef _WIN32
  auto b = maybe_getenv("HOMEPATH");
#else
  auto b = maybe_getenv("HOME");
#endif
  BOOST_CHECK(b);
  std::cout << "$HOME=" << b.value() << std::endl;
  //! [optional_example]
}

#ifdef __cpp_exceptions
BOOST_AUTO_TEST_CASE(works / monad / fileopen, "Tests that the monad semantically represents opening a file")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;

  //! [monad_example]
  auto openfile = [](std::string path) noexcept->outcome<int>
  {
    int fd;
    do
    {
      fd = BOOST_OUTCOME_POSIX_OPEN(path.c_str(), 0);
    } while(-1 == fd && EINTR == errno);
    try
    {
      if(-1 == fd)
      {
        int code = errno;
        // If a temporary failure, this is an expected unexpected outcome
        if(EBUSY == code || EISDIR == code || ELOOP == code || ENOENT == code || ENOTDIR == code || EPERM == code || EACCES == code)
        {
          return error_code_extended(code, stl11::generic_category());
        }
        // If a non-temporary failure, this is an unexpected outcome
        return std::make_exception_ptr(stl11::system_error(code, stl11::generic_category(), strerror(code)));
      }
      return fd;
    }
    catch(...)
    {
      // Any exception thrown is truly unexpected
      return std::current_exception();
    }
  };
  auto a = openfile("shouldneverexistnotever");
  BOOST_CHECK(!a);
  BOOST_CHECK(!a.empty());
  BOOST_CHECK(!a.has_value());
  BOOST_CHECK(a.has_exception());
  BOOST_CHECK(a.has_error());
  BOOST_CHECK(a.get_error() == error_code_extended(ENOENT, stl11::generic_category()));
  //! [monad_example]
}
#endif

#ifdef __cpp_exceptions
BOOST_AUTO_TEST_SUITE_END()
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
struct throwing_udt
{
  std::string a;
  explicit throwing_udt(std::string _a)
      : a(std::move(_a))
  {
  }
  throwing_udt() = delete;
  throwing_udt(const throwing_udt & /*unused*/) { throw std::logic_error("copy"); }
  throwing_udt(throwing_udt && /*unused*/) noexcept(false) { throw std::logic_error("move"); }
  throwing_udt &operator=(const throwing_udt & /*unused*/) { throw std::logic_error("copy"); }
  throwing_udt &operator=(throwing_udt && /*unused*/) noexcept(false) { throw std::logic_error("move"); }
  ~throwing_udt() { a.clear(); }
};
BOOST_OUTCOME_V1_NAMESPACE_BEGIN
template <> constexpr bool enable_move_throwing_type<Except> = true;
template <> constexpr bool enable_move_throwing_type<throwing_udt> = true;
BOOST_OUTCOME_V1_NAMESPACE_END
BOOST_AUTO_TEST_SUITE(all)

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
#if defined(__c2__) || (!defined(_MSC_VER) || _MSC_FULL_VER != 191025017 /* VS2017 RTM */)
    BOOST_CHECK(type::is_nothrow_destructible == std::is_nothrow_destructible<type>::value);
#endif
    BOOST_CHECK(!std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_assignable<type>::value);
#if defined(__c2__) || (!defined(_MSC_VER) || _MSC_FULL_VER != 191025017 /* VS2017 RTM */)
    BOOST_CHECK(!std::is_nothrow_destructible<type>::value);
#endif
  }
}
#endif

BOOST_AUTO_TEST_CASE(works / monad / udts, "Tests that the monad works as intended with user-defined types")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  // No default constructor, no copy/move, no assignment
  {
    struct udt
    {
      int a;
      explicit udt(int _a)
          : a(_a)
      {
      }
      udt() = delete;
      udt(const udt &) = delete;
      udt(udt &&) = delete;
      udt &operator=(const udt &) = delete;
      udt &operator=(udt &&) = delete;
      ~udt() = default;
    };
    outcome<udt> foo(in_place, 5);
    BOOST_CHECK(5 == foo.get().a);
  }
#ifdef __cpp_exceptions
  // Emplace construct, throws during move and copy
  {
    using udt = throwing_udt;
    static_assert(!std::is_default_constructible<udt>::value, "udt is default constructible");
    static_assert(std::is_copy_constructible<udt>::value, "udt is not copy constructible");
    static_assert(std::is_move_constructible<udt>::value, "udt is not move constructible");
    static_assert(value_storage<udt, void, void>::is_copy_constructible, "value_storage<udt> is not copy constructible");
    static_assert(value_storage<udt, void, void>::is_move_constructible, "value_storage<udt> is not move constructible");
    static_assert(std::is_copy_constructible<value_storage<udt, void, void>>::value, "value_storage<udt> is not copy constructible");
    static_assert(std::is_move_constructible<value_storage<udt, void, void>>::value, "value_storage<udt> is not move constructible");
    static_assert(std::is_default_constructible<outcome<udt>>::value, "outcome<udt> is not default constructible");
    static_assert(std::is_copy_constructible<outcome<udt>>::value, "outcome<udt> is not copy constructible");
    static_assert(std::is_move_constructible<outcome<udt>>::value, "outcome<udt> is not move constructible");
    // Emplace constructs
    outcome<udt> foo(in_place, "douglas");
    BOOST_CHECK("douglas" == foo.get().a);
    foo.emplace("niall");
    BOOST_CHECK("niall" == foo.get().a);
    try
    {
      auto foo2(foo);  // NOLINT
      BOOST_CHECK(false);
    }
    catch(const std::logic_error &e)
    {
      BOOST_CHECK(!strcmp(e.what(), "copy"));
    }
    catch(...)
    {
      BOOST_CHECK(false);
    }
    BOOST_CHECK("niall" == foo.get().a);
    try
    {
      auto foo2(std::move(foo));
      BOOST_CHECK(false);
    }
    catch(const std::logic_error &e)
    {
      BOOST_CHECK(!strcmp(e.what(), "move"));
    }
    catch(...)
    {
      BOOST_CHECK(false);
    }
    BOOST_CHECK("niall" == foo.get().a);  // NOLINT
    // Does throwing during copy assignment work?
    {
      outcome<udt> foo2(in_place, "douglas");
      try
      {
        foo2 = foo;
        BOOST_CHECK(false);
      }
      catch(const std::logic_error &e)
      {
        BOOST_CHECK(!strcmp(e.what(), "copy"));
        BOOST_CHECK(foo2.empty());
      }
      catch(...)
      {
        BOOST_CHECK(false);
      }
      BOOST_CHECK("niall" == foo.get().a);
    }
    // Does throwing during move assignment work?
    {
      outcome<udt> foo2(in_place, "douglas");
      try
      {
        foo2 = std::move(foo);
        BOOST_CHECK(false);
      }
      catch(const std::logic_error &e)
      {
        BOOST_CHECK(!strcmp(e.what(), "move"));
        BOOST_CHECK(foo2.empty());
      }
      catch(...)
      {
        BOOST_CHECK(false);
      }
      BOOST_CHECK("niall" == foo.get().a);  // NOLINT
    }
  }
#endif
}

BOOST_AUTO_TEST_CASE(works / monad / void, "Tests that the monad works as intended with void")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  // Can't construct a void
  {
    outcome<void> a, b(empty), c(value), d(make_valued_outcome<void>()), e{};
    BOOST_CHECK(a == b);
    BOOST_CHECK(b == e);
    BOOST_CHECK(c == d);
    BOOST_CHECK(a != c);
    BOOST_CHECK(b != c);
    BOOST_CHECK(e != c);
    BOOST_CHECK(a != d);
    BOOST_CHECK(b != d);
    BOOST_CHECK(e != d);
  }
}

BOOST_AUTO_TEST_CASE(works / monad / containers, "Tests that the monad works as intended inside containers")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  std::vector<outcome<std::vector<int>>> vect;
  vect.push_back(std::vector<int>{5, 6, 7, 8});
  vect.push_back(std::vector<int>{1, 2, 3, 4});
  BOOST_REQUIRE(vect.size() == 2U);
  BOOST_CHECK(vect[0].get().size() == 4U);
  BOOST_CHECK(vect[1].get().size() == 4U);
  BOOST_CHECK(vect[0].get().front() == 5);
  BOOST_CHECK(vect[0].get().back() == 8);
  BOOST_CHECK(vect[1].get().front() == 1);
  BOOST_CHECK(vect[1].get().back() == 4);
}

BOOST_AUTO_TEST_CASE(works / monad / swap, "Tests that the monad swaps as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  outcome<std::string> a("niall"), b("douglas");
  BOOST_CHECK(a.get() == "niall");
  BOOST_CHECK(b.get() == "douglas");
  std::swap(a, b);
  BOOST_CHECK(a.get() == "douglas");
  BOOST_CHECK(b.get() == "niall");
  a.set_error(error_code_extended());
  std::swap(a, b);
  BOOST_CHECK(a.get() == "niall");
  BOOST_CHECK(b.get_error() == error_code_extended());
}

BOOST_AUTO_TEST_CASE(works / monad / upconvert, "Tests that the monad converts into bigger editions of itself")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  // Same type
  {
    option<int> a1, a10(5);
    result<int> b1(a1), b10(a10);
    outcome<int> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.get() == 5);
    BOOST_CHECK(b10.get() == 5);
    BOOST_CHECK(c10.get() == 5);
    BOOST_CHECK(c11.get() == 5);
  }
  // Converting type
  {
    option<short> a1, a10(5);
    result<float> b1(a1), b10(a10);
    outcome<double> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.get() == 5);
    BOOST_CHECK(b10.get() == 5);
    BOOST_CHECK(c10.get() == 5);
    BOOST_CHECK(c11.get() == 5);
  }
  // Explicit upconversion of void
  {
    option<void> a1, a10(make_valued_option<void>());
    result<void> b1(a1), b10(a10);
    outcome<void> c1(a1), c2(b1), c10(a10), c11(b10);
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(b1.empty());
    BOOST_CHECK(c1.empty());
    BOOST_CHECK(c2.empty());
    BOOST_CHECK(a10.is_ready());
    BOOST_CHECK(b10.is_ready());
    BOOST_CHECK(c10.is_ready());
    BOOST_CHECK(c11.is_ready());
  }
  // Implicit upconversion of void
  {
    auto t0 = []() -> result<int> { return make_result<void>(); };
    auto t1 = []() -> outcome<void> { return make_result<void>(); };
    auto t2 = []() -> outcome<int> { return make_result<void>(); };
    (void) t0;
    (void) t1;
    (void) t2;
  }
}

BOOST_AUTO_TEST_CASE(works / monad / propagate, "Tests that the monad propagates errors between different editions of itself")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  {
    auto t0 = [&](int a) { return make_errored_result<long>(a); };
    auto t1 = [&](int a) {
      result<double> f(t0(a));  // double is constructible from long
      return f;
    };
    auto t2 = [&](int a) {
      result<void> f(t1(a).get_error());
      return f;
    };
    auto t3 = [&](int a) {
      outcome<std::string> f(t2(a));
      return f;
    };
    BOOST_CHECK(t3(5).get_error().value() == 5);
    result<int> a1(make_empty_result<void>());
    result<int> a2(make_valued_result<void>());
    result<int> a3(make_errored_result<void>(5));
    BOOST_CHECK(a1.empty());
    BOOST_CHECK(!a1.has_value());
    BOOST_CHECK(!a1.has_error());
    BOOST_CHECK(!a2.empty());
    BOOST_CHECK(a2.has_value());
    BOOST_CHECK(!a2.has_error());
    BOOST_CHECK(!a3.empty());
    BOOST_CHECK(!a3.has_value());
    BOOST_CHECK(a3.has_error());
  }
  {
    auto t0 = [&](int a) { return make_result<long>(a); };
    auto t1 = [&](int a) -> result<std::string> {
      BOOST_OUTCOME_TRY(f, t0(a));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).get() == "5");
  }
  {
    auto t0 = [&](int a) { return make_result<long>(a); };
    auto t1 = [&](int a) -> outcome<std::string> {
      BOOST_OUTCOME_TRY(f, t0(a));
      return std::to_string(f);
    };
    BOOST_CHECK(t1(5).get() == "5");
  }
  {
    auto t0 = [&](int a) -> result<long> { return make_result<long>(a); };
    auto t1 = [&](int a) -> outcome<void> {
      BOOST_OUTCOME_TRYV(t0(a));
      return make_outcome<void>();
    };
    (void) t1(5);
  }
}

BOOST_AUTO_TEST_CASE(works / monad / serialisation, "Tests that the monad serialises and deserialises as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  outcome<std::string> a("niall"), b(error_code_extended(5, stl11::generic_category())), c(std::make_exception_ptr(std::ios_base::failure("A test failure message")));
  std::cout << "a contains " << a << " and b contains " << b << " and c contains " << c << std::endl;
  std::string buffer("hello");
  std::stringstream ss(buffer);
  ss >> a;
  BOOST_CHECK(a.get() == "hello");
}

#ifdef BOOST_OUTCOME_ENABLE_ADVANCED
BOOST_AUTO_TEST_CASE(works / monad / then, "Tests that the monad continues with next() as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  error_code_extended ec;
  outcome<std::string> a("niall"), b(ec);
  // Does auto unwrapping work?
  auto c(a.next([](outcome<std::string> v) { return v; }));
  BOOST_CHECK(c.get() == "niall");
  BOOST_CHECK(a.get() == "niall");
  // Does auto wrapping work?
  auto d(a.next([](outcome<std::string> &&) { return 5; }));
  BOOST_CHECK(d.get() == 5);
  BOOST_CHECK(a.get() == "niall");
#ifdef __cpp_generic_lambdas
  // Do auto lambdas work?
  auto e(a.next([](auto v) { return v; }));
  BOOST_CHECK(e.get() == "niall");
  BOOST_CHECK(a.get() == "niall");
#endif
  // Does error propagation work?
  auto f(b.next([](outcome<std::string> v) { return v; }));
  BOOST_CHECK(f.has_error());

  // Does automatic move semantics work?
  auto j(a.next([](outcome<std::string> &&v) { return std::move(v); }));
  BOOST_CHECK(j.get() == "niall");
  BOOST_CHECK(a.get().empty());
#ifdef __cpp_generic_lambdas
  // Does automatic move semantics with auto lambdas work?
  a.emplace("niall");
  auto k(a.next([](auto &&v) { return std::move(v); }));  // NOLINT
  BOOST_CHECK(k.get() == "niall");
  BOOST_CHECK(a.get().empty());
#endif
}

BOOST_AUTO_TEST_CASE(works / monad / callable, "Tests that the monad works as intended holding callables")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  auto a = make_outcome([](int a) { return 5 + a; });
  BOOST_CHECK(a.get()(1) == 6);
  BOOST_CHECK(a(2) == 7);
#ifdef __cpp_generic_lambdas
  auto b = make_outcome([](auto a) { return 5 + a; });
  BOOST_CHECK(b.get()(1) == 6);
  BOOST_CHECK(b(2) == 7);
#endif
}

BOOST_AUTO_TEST_CASE(works / monad / unwrap, "Tests that the monad unwraps as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  error_code_extended ec;
  outcome<std::string> a("niall"), b(ec);
  outcome<outcome<std::string>> c(std::move(a)), d(std::move(b));
  outcome<outcome<outcome<std::string>>> e(std::move(c)), f(std::move(d));
  outcome<outcome<outcome<outcome<std::string>>>> g(std::move(e)), h(std::move(f));
  auto i(g.unwrap()), j(h.unwrap());
  BOOST_CHECK((std::is_same<decltype(a), decltype(i)>::value));
  BOOST_CHECK((std::is_same<decltype(b), decltype(j)>::value));
  BOOST_CHECK(i.get() == "niall");
  BOOST_CHECK(j.get_error() == ec);
  BOOST_CHECK(g.get().get().get().get() == "niall");
  BOOST_CHECK(h.get().get().get().get_error() == ec);
  auto k(std::move(g).unwrap()), l(std::move(h).unwrap());
  BOOST_CHECK((std::is_same<decltype(a), decltype(k)>::value));
  BOOST_CHECK((std::is_same<decltype(b), decltype(l)>::value));
  BOOST_CHECK(k.get() == "niall");
  BOOST_CHECK(l.get_error() == ec);
  BOOST_CHECK(g.get().get().get().get().empty());  // NOLINT
}

BOOST_AUTO_TEST_CASE(works / monad / bind, "Tests that the monad continues with bind() as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  error_code_extended ec;
  {
    outcome<std::string> a("niall"), b(ec);
    // Does bind work?
    auto c(a.bind([](std::string &&) { return 5; }));
    auto c2(a.bind([](std::string &&) -> outcome<int> { return 5; }));
    BOOST_CHECK(c.get() == 5);
    BOOST_CHECK(c2.get() == 5);
    BOOST_CHECK(a.get() == "niall");
    auto d(b.bind([](std::string &&) { return 5; }));
    auto d2(b.bind([](std::string &&) -> outcome<int> { return 5; }));
    BOOST_CHECK(d.has_error());
    BOOST_CHECK(d2.has_error());
#ifdef __cpp_generic_lambdas
    auto e(a.bind([](auto) { return 5; }));
    auto e2(a.bind([](auto) -> outcome<int> { return 5; }));
    BOOST_CHECK(e.get() == 5);
    BOOST_CHECK(e2.get() == 5);
    BOOST_CHECK(a.get() == "niall");
    auto f(b.bind([](auto) { return 5; }));
    auto f2(b.bind([](auto) -> outcome<int> { return 5; }));
    BOOST_CHECK(f.has_error());
    BOOST_CHECK(f2.has_error());
#endif
    auto g(a.bind([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(g.get() == "niall");
    BOOST_CHECK(a.get().empty());
    auto h(b.bind([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(h.has_error());
    a.emplace("niall");
#ifdef __cpp_generic_lambdas
    auto i(a.bind([](auto &&v) { return std::move(v); }));  // NOLINT
    BOOST_CHECK(i.get() == "niall");
    BOOST_CHECK(a.get().empty());
    auto j(b.bind([](auto &&v) { return std::move(v); }));  // NOLINT
    BOOST_CHECK(j.has_error());
    a.emplace("niall");
#endif

    // Does bind work with chains of value, error, exception and empty?
    auto x(a.bind([ec](std::string) { return ec; }).bind([](error_code_extended) { return std::make_exception_ptr(5); }).bind([](std::exception_ptr) { return; }).bind([](outcome<std::string>::empty_type) { return std::string("douglas"); }));
    BOOST_CHECK(x.get() == "douglas");
    auto y(a.bind([ec](std::string) -> outcome<int> { return ec; }).bind([](error_code_extended) { return std::make_exception_ptr(5); }).bind([](std::exception_ptr) { return; }).bind([](outcome<int>::empty_type) { return 5; }));
    BOOST_CHECK(y.get() == 5);
    auto z(a.bind([](std::string &&v) { return std::move(v); }).bind([](std::string &&v) { return std::move(v); }).bind([](std::string &&v) { return std::move(v); }).bind([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(z.get() == "niall");
    BOOST_CHECK(a.get().empty());
  }
}

BOOST_AUTO_TEST_CASE(works / monad / map, "Tests that the monad continues with map() as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  error_code_extended ec;
  {
    outcome<std::string> a("niall"), b(ec);
    // Does map work?
    auto c(a.map([](std::string &&) { return 5; }));
    auto c2(a.map([](std::string &&) -> outcome<int> { return 5; }));
    BOOST_CHECK(c.get() == 5);
    BOOST_CHECK(c2.get().get() == 5);
    BOOST_CHECK(a.get() == "niall");
    auto d(b.map([](std::string &&) { return 5; }));
    auto d2(b.map([](std::string &&) -> outcome<int> { return 5; }));
    BOOST_CHECK(d.has_error());
    BOOST_CHECK(d2.has_error());
#ifdef __cpp_generic_lambdas
    auto e(a.map([](auto) { return 5; }));
    auto e2(a.map([](auto) -> outcome<int> { return 5; }));
    BOOST_CHECK(e.get() == 5);
    BOOST_CHECK(e2.get().get() == 5);
    BOOST_CHECK(a.get() == "niall");
    auto f(b.map([](auto) { return 5; }));
    auto f2(b.map([](auto) -> outcome<int> { return 5; }));
    BOOST_CHECK(f.has_error());
    BOOST_CHECK(f2.has_error());
#endif
    auto g(a.map([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(g.get() == "niall");
    BOOST_CHECK(a.get().empty());
    auto h(b.map([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(h.has_error());
    a.emplace("niall");
#ifdef __cpp_generic_lambdas
    auto i(a.map([](auto &&v) { return std::move(v); }));  // NOLINT
    BOOST_CHECK(i.get() == "niall");
    BOOST_CHECK(a.get().empty());
    auto j(b.map([](auto &&v) { return std::move(v); }));  // NOLINT
    BOOST_CHECK(j.has_error());
    a.emplace("niall");
#endif

    // Does map work with chains of value, error, exception and empty?
    auto x(a.map([ec](std::string) { return ec; }).map([](error_code_extended) { return std::make_exception_ptr(5); }).map([](std::exception_ptr) { return; }).map([](outcome<std::string>::empty_type) { return std::string("douglas"); }));
    BOOST_CHECK(x.get() == "douglas");
    auto y(a
           .map([ec](std::string) -> outcome<long> { return ec; })
           // Type is now outcome<outcome<long>> where the inner monad is errored
           .map([](error_code_extended) { return std::make_exception_ptr(5); })
           .map([](std::exception_ptr) { return; })
           .map([](outcome<outcome<long>>::empty_type) -> outcome<long> { return 5; })
           // Type is now outcome<outcome<long>> where the inner monad is errored
           );
    // None of the above maps fire after the first as the first returns a outcome<outcome<int>>,
    // so it's always un-erroroed.
    BOOST_CHECK(y.has_value());
    BOOST_CHECK(y.unwrap().has_error());
    auto y2(a
            .map([ec](std::string) -> outcome<long> { return ec; })
            // Type is now outcome<outcome<long>>
            .map([](outcome<long> v) { return v.map([](error_code_extended) { return std::make_exception_ptr(5); }); })
            .map([](outcome<long> v) { return v.map([](std::exception_ptr) { return; }); })
            .map([](outcome<long> v) { return v.map([](outcome<long>::empty_type) { return 5L; }); }));
    BOOST_CHECK(y2.unwrap().get() == 5);
    auto z(a.map([](std::string &&v) { return std::move(v); }).map([](std::string &&v) { return std::move(v); }).map([](std::string &&v) { return std::move(v); }).map([](std::string &&v) { return std::move(v); }));
    BOOST_CHECK(z.get() == "niall");
    BOOST_CHECK(a.get().empty());
  }
}

BOOST_AUTO_TEST_CASE(works / monad / match, "Tests that the monad matches as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  //! [monad_match_example]
  struct o_type
  {
    int expected{0};
    // monad.match() will call an overload for each possible content it might have
    void operator()(int /*unused*/) const { BOOST_CHECK(expected == 1); }
    void operator()(error_code_extended /*unused*/) const { BOOST_CHECK(expected == 2); }
    void operator()(std::exception_ptr /*unused*/) const { BOOST_CHECK(expected == 3); }  // NOLINT
    void operator()(outcome<int>::empty_type /*unused*/) const { BOOST_CHECK(expected == 4); }
  } o;
  error_code_extended ec;
  std::exception_ptr e;
  outcome<int> a(5);
  o.expected = 1;
  (void) a.match(o);
  o.expected = 2;
  a = ec;
  (void) a.match(o);
  o.expected = 3;
  a = e;
  (void) a.match(o);
  o.expected = 4;
  a.clear();
  (void) a.match(o);
  //! [monad_match_example]
}

BOOST_AUTO_TEST_CASE(works / monad / operators, "Tests that the monad custom operators work as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  //! [monad_operators_example]
  {
    error_code_extended ec;
    outcome<int> a(5);
    outcome<int> b(a & 6);   // a has a value, so become 6
    outcome<int> c(b | 4);   // b has a value, so remain at 6
    outcome<int> d(a & ec);  // a has a value, so become errored
    outcome<int> e(d & 2);   // d does not have a value, so remain errored
    outcome<int> f(d | 2);   // d does not have a value, so become 2
    BOOST_CHECK(b.get() == 6);
    BOOST_CHECK(c.get() == 6);
    BOOST_CHECK(d.has_error());
    BOOST_CHECK(e.has_error());
    BOOST_CHECK(f.get() == 2);
  }

  error_code_extended ec;
  {
    outcome<std::string> a("niall");
    // Does bind work with chains of value, error, exception and empty?
    auto x(a >> [ec](std::string) { return ec; }                              //
           >> [](error_code_extended) { return std::make_exception_ptr(5); }  //
           >> [](std::exception_ptr) { return; }                              //
           >> [](outcome<std::string>::empty_type) { return std::string("douglas"); });
    BOOST_CHECK(x.get() == "douglas");
    auto y(a >> [ec](std::string) -> outcome<int> { return ec; }                                        //
                                     >> [](error_code_extended) { return std::make_exception_ptr(5); }  //
                                     >> [](std::exception_ptr) { return; }                              //
                                     >> [](outcome<int>::empty_type) { return 5; });
    BOOST_CHECK(y.get() == 5);
    auto z(a >> [](std::string &&v) { return std::move(v); }  //
           >> [](std::string &&v) { return std::move(v); }    //
           >> [](std::string &&v) { return std::move(v); }    //
           >> [](std::string &&v) { return std::move(v); });
    BOOST_CHECK(z.get() == "niall");
    BOOST_CHECK(a.get().empty());
  }
  //! [monad_operators_example]
}
#endif


/****************************************************** Tests for issues reported ***********************************************************/

BOOST_AUTO_TEST_CASE(issues / 7, "BOOST_OUTCOME_TRYV(expr) in a function whose return monad's type has no default constructor fails to compile")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  struct udt  // NOLINT
  {
    explicit udt(int /*unused*/) {}
    //    udt() = delete;
    udt(const udt &) = default;
    udt(udt &&) = default;
  };
  auto f = []() -> result<udt> {
    auto g = [] { return result<int>(5); };
    /* This fails because BOOST_OUTCOME_TRYV() returns a result<void>
    which if it were valued void, would implicitly convert into a
    default constructed udt which is not possible, hence the compile error.
    */
    BOOST_OUTCOME_TRYV(g());
    return udt(5);
  };
  (void) f();
}

#ifdef BOOST_OUTCOME_TRYX
BOOST_AUTO_TEST_CASE(issues / 9, "Alternative TRY macros?")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  struct udt  // NOLINT
  {
    explicit udt(int /*unused*/) {}
    //    udt() = delete;
    udt(const udt &) = default;
    udt(udt &&) = default;
  };
  auto f = []() -> result<udt> {
    auto g = [] { return result<int>(5); };
    return udt(BOOST_OUTCOME_TRYX(g()));
  };
  (void) f();
}
#endif

BOOST_AUTO_TEST_CASE(issues / 10, "Expected's operator->(), operator*() and .error() throw exceptions when they should not")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  const char *a = "hi", *b = "bye";
  struct udt1  // NOLINT
  {
    const char *_v{nullptr};
    udt1() = default;
    constexpr explicit udt1(const char *v) noexcept : _v(v) {}
    BOOST_OUTCOME_CONSTEXPR udt1(udt1 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt1(const udt1 &) = default;
    BOOST_OUTCOME_CONSTEXPR udt1 &operator=(udt1 &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt1 &operator=(const udt1 &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  struct udt2  // NOLINT
  {
    const char *_v{nullptr};
    udt2() = default;
    constexpr explicit udt2(const char *v) noexcept : _v(v) {}
    BOOST_OUTCOME_CONSTEXPR udt2(udt2 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt2(const udt2 &) = default;
    BOOST_OUTCOME_CONSTEXPR udt2 &operator=(udt2 &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt1 &operator=(const udt1 &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  expected<udt1, udt2> p(udt1{a});
  expected<udt1, udt2> n(make_unexpected(udt2(b)));
  // State check
  BOOST_CHECK(p.has_value());
  BOOST_CHECK(!n.has_value());
  // These should behave as expected (!)
  BOOST_CHECK_NO_THROW(p.value());
  BOOST_CHECK_THROW(n.value(), const bad_expected_access<udt2> &);
  // And state is not destroyed
  BOOST_CHECK(p.has_value() && **p == a);
  BOOST_CHECK(!n.has_value() && *n.error() == b);
  // LEWG Expected requires these to work as if reinterpret_cast irrespective of state
  BOOST_CHECK_NO_THROW(p.error());  // error from valued state
  BOOST_CHECK_NO_THROW(*n);         // value from errored state
  // LEWG Expected provides rvalue ref semantics for operator*(), error() and error_or()
  udt1 a1(std::move(*p));
  BOOST_CHECK(*a1 == a);
  BOOST_CHECK(**p == nullptr);
  udt2 e2(std::move(n).error());
  BOOST_CHECK(*e2 == b);
  BOOST_CHECK(*n.error() == nullptr);  // NOLINT
  n.set_error(udt2(b));
  e2 = std::move(n).error_or(udt2(a));
  BOOST_CHECK(*e2 == b);
  BOOST_CHECK(*n.error() == nullptr);  // NOLINT
}

#if 0  // Known bug, will be fixed when we refactor Expected storage to never have empty state
BOOST_AUTO_TEST_CASE(issues / 12, "basic_monad's copy assignment gets instantiated even when type T cannot be copied")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  const char *s = "hi";
  struct udt
  {
    const char *_v{ null[tr };
    udt() = default;
    constexpr explicit udt(const char *v) noexcept : _v(v) {}
    BOOST_OUTCOME_CONSTEXPR udt(udt &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt(const udt &) = delete;
    BOOST_OUTCOME_CONSTEXPR udt &operator=(udt &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt &operator=(const udt &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  static_assert(expected<udt>::is_move_constructible, "expected<udt> is not move constructible!");
  static_assert(!expected<udt>::is_copy_constructible, "expected<udt> is copy constructible!");
  expected<udt> p(s), n(make_unexpected(std::error_code(ENOMEM, std::generic_category())));
  n = make_unexpected(std::error_code(EINVAL, std::generic_category()));
}

BOOST_AUTO_TEST_CASE(issues / 16, "Default constructor of T is sometimes compiled when T has no default constructor")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  struct udt
  {
    const char *_v{ nullptr };
    udt() = delete;
    constexpr explicit udt(const char *v) noexcept : _v(v) {}
    BOOST_OUTCOME_CONSTEXPR udt(udt &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt(const udt &) = delete;
    BOOST_OUTCOME_CONSTEXPR udt &operator=(udt &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt &operator=(const udt &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  expected<udt> n(make_unexpected(std::error_code(ENOMEM, std::generic_category())));
}
#endif

BOOST_AUTO_TEST_SUITE_END()

#ifndef BOOST_MEMORY_TRANSACTIONS_DISABLE_CATCH
int main(int argc, char *argv[])
{
#ifdef _OPENMP
  printf("These unit tests have been compiled with parallel support. I will use as many threads as CPU cores.\n");
#else
  printf("These unit tests have not been compiled with parallel support and will execute only those which are sequential.\n");
#endif
#ifdef BOOST_HAVE_TRANSACTIONAL_MEMORY_COMPILER
  printf("These unit tests have been compiled using a transactional compiler. I will use __transaction_relaxed.\n");
#else
  printf("These unit tests have not been compiled using a transactional compiler.\n");
#endif
#if 0
  printf("Please attach debugger now ...\n");
  getchar();
#endif
#if 0
  cpu_set_t *cpuset=CPU_ALLOC(2);
  CPU_ZERO_S(CPU_ALLOC_SIZE(2), cpuset);
  CPU_SET_S(0, 2, cpuset);
  CPU_SET_S(1, 2, cpuset);
  pthread_setaffinity_np(pthread_self(), CPU_ALLOC_SIZE(2), cpuset);
#endif
  int result = BOOSTLITE_BOOST_UNIT_TEST_RUN_TESTS(argc, argv);
  return result;
}
#endif
