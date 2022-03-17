/* Unit testing for outcomes
(C) 2013-2022 Niall Douglas <http://www.nedproductions.biz/> (6 commits)


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
#include "../../include/outcome/coroutine_support.hpp"
#include "../../include/outcome/try.hpp"

#if OUTCOME_FOUND_COROUTINE_HEADER

#include "quickcpplib/boost/test/unit_test.hpp"

namespace coroutines
{
  template <class T> using eager = OUTCOME_V2_NAMESPACE::awaitables::eager<T>;
  template <class T> using lazy = OUTCOME_V2_NAMESPACE::awaitables::lazy<T>;
  template <class T> using generator = OUTCOME_V2_NAMESPACE::awaitables::generator<T>;
  template <class T, class E = std::error_code> using result = OUTCOME_V2_NAMESPACE::result<T, E>;

  inline eager<result<int>> eager_int(int x) { co_return x + 1; }
  inline lazy<result<int>> lazy_int(int x) { co_return x + 1; }
  inline eager<result<int>> eager_error() { co_return std::errc::not_enough_memory; }
  inline lazy<result<int>> lazy_error() { co_return std::errc::not_enough_memory; }
  inline eager<result<void>> eager_void() { co_return std::errc::not_enough_memory; }
  inline lazy<result<void>> lazy_void() { co_return std::errc::not_enough_memory; }
  inline generator<result<int>> generator_int(int x)
  {
    co_yield x;
    co_yield x + 1;
    co_yield x + 2;
  }
  inline generator<result<int>> generator_error(int x)
  {
    co_yield x;
    co_yield x + 1;
    co_yield std::errc::not_enough_memory;
  }

  template <class U, class... Args> inline eager<result<std::string>> eager_coawait(U &&f, Args... args)
  {
    OUTCOME_CO_TRYV2(auto &&, co_await f(args...));
    co_return "hi";
  }
  template <class U, class... Args> inline lazy<result<std::string>> lazy_coawait(U &&f, Args... args)
  {
    OUTCOME_CO_TRYV2(auto &&, co_await f(args...));
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

  inline generator<OUTCOME_V2_NAMESPACE::outcome<int>> generator_exception(std::exception_ptr e)
  {
    co_yield 5;
    co_yield 6;
    std::rethrow_exception(e);
  }
#endif

  inline eager<int> eager_int2(int x) { co_return x + 1; }
  inline lazy<int> lazy_int2(int x) { co_return x + 1; }
  inline eager<void> eager_void2() { co_return; }
  inline lazy<void> lazy_void2() { co_return; }
}  // namespace coroutines

BOOST_OUTCOME_AUTO_TEST_CASE(works / coroutine / eager_lazy, "Tests that results are eager and lazy awaitable")
{
  using namespace coroutines;
  auto ensure_coroutine_completed_immediately = [](auto t)
  {
    BOOST_CHECK(t.await_ready());  // must have eagerly evaluated
    return t.await_resume();       // fetch the value returned into the promise by the coroutine
  };
  auto ensure_coroutine_needs_resuming_once = [](auto t)
  {
    BOOST_CHECK(!t.await_ready());  // must not have eagerly evaluated
#if OUTCOME_HAVE_NOOP_COROUTINE
    t.await_suspend({}).resume();  // resume execution, which sets the promise
#else
    t.await_suspend({});  // resume execution, which sets the promise
#endif
    BOOST_CHECK(t.await_ready());  // must now be ready
    return t.await_resume();       // fetch the value returned into the promise by the coroutine
  };

  // eager_int never suspends, sets promise immediately, must be able to retrieve immediately
  BOOST_CHECK(ensure_coroutine_completed_immediately(eager_int(5)).value() == 6);
  // lazy_int suspends before execution, needs resuming to set the promise
  BOOST_CHECK(ensure_coroutine_needs_resuming_once(lazy_int(5)).value() == 6);
  BOOST_CHECK(ensure_coroutine_completed_immediately(eager_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(ensure_coroutine_needs_resuming_once(lazy_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(ensure_coroutine_completed_immediately(eager_void()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(ensure_coroutine_needs_resuming_once(lazy_void()).error() == std::errc::not_enough_memory);

  // co_await eager_int realises it has already completed, does not suspend.
  BOOST_CHECK(ensure_coroutine_completed_immediately(eager_coawait(eager_int, 5)).value() == "hi");
  // co_await lazy_int resumes the suspended coroutine.
  BOOST_CHECK(ensure_coroutine_needs_resuming_once(lazy_coawait(lazy_int, 5)).value() == "hi");

#ifdef __cpp_exceptions
  auto e = std::make_exception_ptr(custom_exception_type());
  BOOST_CHECK_THROW(ensure_coroutine_needs_resuming_once(result_exception(e)).value(), custom_exception_type);
  BOOST_CHECK_THROW(ensure_coroutine_needs_resuming_once(outcome_exception(e)).value(), custom_exception_type);
#endif

  BOOST_CHECK(ensure_coroutine_completed_immediately(eager_int2(5)) == 6);
  BOOST_CHECK(ensure_coroutine_needs_resuming_once(lazy_int2(5)) == 6);
  ensure_coroutine_completed_immediately(eager_void2());
  ensure_coroutine_needs_resuming_once(lazy_void2());
}

BOOST_OUTCOME_AUTO_TEST_CASE(works / coroutine / generator, "Tests that results can be generated")
{
  using namespace coroutines;
  auto check_generator = [](auto t) -> OUTCOME_V2_NAMESPACE::outcome<int>
  {
#ifdef __cpp_exceptions
    try
#endif
    {
      int count = 0, ret = 0;
      while(t)
      {
        auto r = t();
        count++;
        if(r)
        {
          ret = r.value();
          BOOST_CHECK(ret == 4 + count);
        }
        else
        {
          BOOST_CHECK(count == 3);
          OUTCOME_TRY(std::move(r));
        }
      }
      return ret;
    }
#ifdef __cpp_exceptions
    catch(...)
    {
      BOOST_CHECK(false);  // exception must be put into outcome, nothing must throw here
      throw;
    }
#endif
  };
  BOOST_CHECK(check_generator(generator_int(5)).value() == 7);
  BOOST_CHECK(check_generator(generator_error(5)).error() == std::errc::not_enough_memory);

#ifdef __cpp_exceptions
  auto e = std::make_exception_ptr(custom_exception_type());
  BOOST_CHECK_THROW(check_generator(generator_exception(e)).value(), custom_exception_type);
#endif
}
#else
int main(void)
{
  return 0;
}
#endif
