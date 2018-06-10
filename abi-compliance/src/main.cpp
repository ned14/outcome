/* A shared library which uses Outcome in order to guarantee its ABI
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Mar 2018


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

#include "../../single-header/abi.hpp"

struct NonTrivialType
{
  void *foo{nullptr};
  NonTrivialType()
      : foo(nullptr)
  {
  }
  NonTrivialType(const NonTrivialType &)
      : foo(nullptr)
  {
  }
  NonTrivialType(NonTrivialType &&) noexcept : foo(nullptr) {}
  NonTrivialType &operator=(const NonTrivialType &) { return *this; }
  NonTrivialType &operator=(NonTrivialType &&) noexcept { return *this; }
  ~NonTrivialType() { foo = nullptr; }
};

template <class T> using result = OUTCOME_V2_NAMESPACE::basic_result<T, long, OUTCOME_V2_NAMESPACE::policy::terminate>;
template <class T> using outcome = OUTCOME_V2_NAMESPACE::basic_outcome<T, long, double, OUTCOME_V2_NAMESPACE::policy::terminate>;

extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::status_bitfield_type status_bits()
{
  using namespace OUTCOME_V2_NAMESPACE::detail;
  return (status_have_value | status_have_error | status_have_exception | status_error_is_errno) & status_2byte_mask;
}

extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::value_storage_trivial<int> value_storage_int(OUTCOME_V2_NAMESPACE::detail::value_storage_trivial<int> &v)
{
  return v;
}

extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::value_storage_nontrivial<NonTrivialType> value_storage_NonTrivialType(OUTCOME_V2_NAMESPACE::detail::value_storage_nontrivial<NonTrivialType> &v)
{
  return v;
}

extern QUICKCPPLIB_SYMBOL_EXPORT result<int> result_int(result<int> &v)
{
  return v;
}

extern QUICKCPPLIB_SYMBOL_EXPORT result<NonTrivialType> result_NonTrivialType(result<NonTrivialType> &v)
{
  return v;
}

extern QUICKCPPLIB_SYMBOL_EXPORT outcome<int> outcome_int(outcome<int> &v)
{
  return v;
}

extern QUICKCPPLIB_SYMBOL_EXPORT outcome<NonTrivialType> outcome_NonTrivialType(outcome<NonTrivialType> &v)
{
  return v;
}
