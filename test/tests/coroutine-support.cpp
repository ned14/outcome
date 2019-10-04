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

#if defined(__cpp_coroutines)

#include "../../include/outcome/coroutine_support.hpp"
#include "../../include/outcome/outcome.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

inline OUTCOME_V2_NAMESPACE::awaitable<OUTCOME_V2_NAMESPACE::result<int>> awaitable_int(int x)
{
  co_return x + 1;
}
inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::result<int>> task_int(int x)
{
  co_return x + 1;
}
inline OUTCOME_V2_NAMESPACE::awaitable<OUTCOME_V2_NAMESPACE::result<int>> awaitable_error()
{
  co_return std::errc::not_enough_memory;
}
inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::result<int>> task_error()
{
  co_return std::errc::not_enough_memory;
}
inline OUTCOME_V2_NAMESPACE::awaitable<OUTCOME_V2_NAMESPACE::result<void>> awaitable_void()
{
  co_return std::errc::not_enough_memory;
}
inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::result<void>> task_void()
{
  co_return std::errc::not_enough_memory;
}

template <class U, class... Args> inline OUTCOME_V2_NAMESPACE::awaitable<OUTCOME_V2_NAMESPACE::result<std::string>> awaitable_coawait(U &&f, Args... args)
{
  OUTCOME_CO_TRY(co_await f(args...));
  co_return "hi";
}
template <class U, class... Args> inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::result<std::string>> task_coawait(U &&f, Args... args)
{
  OUTCOME_CO_TRY(co_await f(args...));
  co_return "hi";
}

#ifdef __cpp_exceptions
struct custom_exception_type
{
};
inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::result<int, std::exception_ptr>> result_exception(std::exception_ptr e)
{
  std::rethrow_exception(e);
  co_return 5;
}

inline OUTCOME_V2_NAMESPACE::task<OUTCOME_V2_NAMESPACE::outcome<int>> outcome_exception(std::exception_ptr e)
{
  std::rethrow_exception(e);
  co_return 5;
}
#endif

inline OUTCOME_V2_NAMESPACE::awaitable<int> awaitable_int2(int x)
{
  co_return x + 1;
}
inline OUTCOME_V2_NAMESPACE::task<int> task_int2(int x)
{
  co_return x + 1;
}
inline OUTCOME_V2_NAMESPACE::awaitable<void> awaitable_void2()
{
  co_return;
}
inline OUTCOME_V2_NAMESPACE::task<void> task_void2()
{
  co_return;
}

BOOST_OUTCOME_AUTO_TEST_CASE(works / result / coroutine, "Tests that results are awaitable and task awaitable")
{
  using namespace OUTCOME_V2_NAMESPACE;
  auto awaitable_await = [](auto t) { return t.await_resume(); };
  auto task_await = [](auto t) {
    t.await_suspend({});
    return t.await_resume();
  };

  BOOST_CHECK(awaitable_await(awaitable_int(5)).value() == 6);
  BOOST_CHECK(task_await(task_int(5)).value() == 6);
  BOOST_CHECK(awaitable_await(awaitable_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(task_await(task_error()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(awaitable_await(awaitable_void()).error() == std::errc::not_enough_memory);
  BOOST_CHECK(task_await(task_void()).error() == std::errc::not_enough_memory);

  BOOST_CHECK(awaitable_await(awaitable_coawait(awaitable_int, 5)).value() == "hi");
  BOOST_CHECK(task_await(task_coawait(task_int, 5)).value() == "hi");

#ifdef __cpp_exceptions
  auto e = std::make_exception_ptr(custom_exception_type());
  BOOST_CHECK_THROW(task_await(result_exception(e)).value(), custom_exception_type);
  BOOST_CHECK_THROW(task_await(outcome_exception(e)).value(), custom_exception_type);
#endif

  BOOST_CHECK(awaitable_await(awaitable_int2(5)) == 6);
  BOOST_CHECK(task_await(task_int2(5)) == 6);
  awaitable_await(awaitable_void2());
  task_await(task_void2());
}
#endif
