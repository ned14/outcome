/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (6 commits)


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

#include "../../include/outcome/coroutine_support.hpp"
#include "../../include/outcome/outcome.hpp"
#include "../../include/outcome/try.hpp"

#if OUTCOME_FOUND_COROUTINE_HEADER

#include "quickcpplib/boost/test/unit_test.hpp"

namespace coroutines
{
  template <class T> using eager = OUTCOME_V2_NAMESPACE::awaitables::eager<T>;
  template <class T> using lazy = OUTCOME_V2_NAMESPACE::awaitables::lazy<T>;
  template <class T, class E = std::error_code> using result = OUTCOME_V2_NAMESPACE::result<T, E>;

  inline eager<result<int>> eager_int(int x) { co_return x + 1; }
  inline lazy<result<int>> lazy_int(int x) { co_return x + 1; }
  inline eager<result<int>> eager_error() { co_return std::errc::not_enough_memory; }
  inline lazy<result<int>> lazy_error() { co_return std::errc::not_enough_memory; }
  inline eager<result<void>> eager_void() { co_return std::errc::not_enough_memory; }
  inline lazy<result<void>> lazy_void() { co_return std::errc::not_enough_memory; }

  template <class U, class... Args> inline eager<result<std::string>> eager_coawait(U &&f, Args... args)
  {
    OUTCOME_CO_TRY(co_await f(args...));
    co_return "hi";
  }
  template <class U, class... Args> inline lazy<result<std::string>> lazy_coawait(U &&f, Args... args)
  {
    OUTCOME_CO_TRY(co_await f(args...));
    co_return "hi";
  }

#ifdef __cpp_exceptions
  struct custom_exception_type
  {
  };
  inline lazy<result<int, std::exception_ptr>> result_exception(std::exception_ptr e)
  {
    std::rethrow_exception(e);
    co_return 5;
  }

  inline lazy<OUTCOME_V2_NAMESPACE::outcome<int>> outcome_exception(std::exception_ptr e)
  {
    std::rethrow_exception(e);
    co_return 5;
  }
#endif

  inline eager<int> eager_int2(int x) { co_return x + 1; }
  inline lazy<int> lazy_int2(int x) { co_return x + 1; }
  inline eager<void> eager_void2() { co_return; }
  inline lazy<void> lazy_void2() { co_return; }
}  // namespace coroutines

BOOST_OUTCOME_AUTO_TEST_CASE(works / result / coroutine, "Tests that results are eager and lazy awaitable")
{
  using namespace coroutines;
  auto eager_await = [](auto t) { return t.await_resume(); };
  auto lazy_await = [](auto t) {
    t.await_suspend({});
    return t.await_resume();
  };

  BOOST_CHECK(eager_await(eager_int(5)).value() == 6);
  BOOST_CHECK(lazy_await(lazy_int(5)).value() == 6);
  BOOST_CHECK(eager_await(eager_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(lazy_await(lazy_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(eager_await(eager_void()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(lazy_await(lazy_void()).error() == std::errc::not_enough_memory);

  BOOST_CHECK(eager_await(eager_coawait(eager_int, 5)).value() == "hi");
  BOOST_CHECK(lazy_await(lazy_coawait(lazy_int, 5)).value() == "hi");

#ifdef __cpp_exceptions
  auto e = std::make_exception_ptr(custom_exception_type());
  BOOST_CHECK_THROW(lazy_await(result_exception(e)).value(), custom_exception_type);
  BOOST_CHECK_THROW(lazy_await(outcome_exception(e)).value(), custom_exception_type);
#endif

  BOOST_CHECK(eager_await(eager_int2(5)) == 6);
  BOOST_CHECK(lazy_await(lazy_int2(5)) == 6);
  eager_await(eager_void2());
  lazy_await(lazy_void2());
}
#else
int main(void)
{
  return 0;
}
#endif
