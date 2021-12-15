/* A shared library which uses Outcome in order to guarantee its ABI
(C) 2018-2021 Niall Douglas <http://www.nedproductions.biz/> (3 commits)
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

#include "../../single-header/outcome.hpp"

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
  NonTrivialType(NonTrivialType &&) noexcept
      : foo(nullptr)
  {
  }
  NonTrivialType &operator=(const NonTrivialType &) { return *this; }
  NonTrivialType &operator=(NonTrivialType &&) noexcept { return *this; }
  ~NonTrivialType() { foo = nullptr; }
};

// Lock ABI for the internal status bits
extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::status_bitfield_type status_bits()
{
  using status = OUTCOME_V2_NAMESPACE::detail::status;
  return (status)((uint16_t) status::have_value | (uint16_t) status::have_error | (uint16_t) status::have_exception | (uint16_t) status::have_error_is_errno |
                  (uint16_t) status::have_lost_consistency | (uint16_t) status::have_moved_from);
}

// Lock ABI for the internal value storage for trivial types
extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::value_storage_trivial<int, long>
value_storage_int(OUTCOME_V2_NAMESPACE::detail::value_storage_trivial<int, long> &v)
{
  return v;
}

// Lock ABI for the internal value storage for non-trivial types
extern QUICKCPPLIB_SYMBOL_EXPORT OUTCOME_V2_NAMESPACE::detail::value_storage_nontrivial<NonTrivialType, int>
value_storage_NonTrivialType(OUTCOME_V2_NAMESPACE::detail::value_storage_nontrivial<NonTrivialType, int> &v)
{
  return v;
}

template <class T, class EC, class EP, class NoValuePolicy, class... NoValuePolicies>
struct QUICKCPPLIB_SYMBOL_EXPORT abi_stamper : public abi_stamper<T, EC, EP, NoValuePolicies...>
{
  using result = OUTCOME_V2_NAMESPACE::basic_result<T, EC, NoValuePolicy>;
  using outcome = OUTCOME_V2_NAMESPACE::basic_outcome<T, EC, EP, NoValuePolicy>;
  using bad_result_access = OUTCOME_V2_NAMESPACE::bad_result_access_with<EC>;

  virtual ~abi_stamper() {}

  virtual result get(result &v) { return v; }
  virtual outcome get(outcome &v) { return v; }
  virtual bad_result_access get(bad_result_access &v) { return v; }

#ifdef OUTCOME_FOUND_COROUTINE_HEADER
  template <class X> using eager = OUTCOME_V2_NAMESPACE::awaitables::eager<X>;
  template <class X> using lazy = OUTCOME_V2_NAMESPACE::awaitables::lazy<X>;
  template <class X> using atomic_eager = OUTCOME_V2_NAMESPACE::awaitables::atomic_eager<X>;
  template <class X> using atomic_lazy = OUTCOME_V2_NAMESPACE::awaitables::atomic_lazy<X>;

  virtual eager<int> get(eager<int> &v) { return v; }
  virtual eager<result> get(eager<result> &v) { return v; }
  virtual eager<outcome> get(eager<outcome> &v) { return v; }
  virtual lazy<int> get(lazy<int> &v) { return v; }
  virtual lazy<result> get(lazy<result> &v) { return v; }
  virtual lazy<outcome> get(lazy<outcome> &v) { return v; }
  virtual atomic_eager<int> get(atomic_eager<int> &v) { return v; }
  virtual atomic_eager<result> get(atomic_eager<result> &v) { return v; }
  virtual atomic_eager<outcome> get(atomic_eager<outcome> &v) { return v; }
  virtual atomic_lazy<int> get(atomic_lazy<int> &v) { return v; }
  virtual atomic_lazy<result> get(atomic_lazy<result> &v) { return v; }
  virtual atomic_lazy<outcome> get(atomic_lazy<outcome> &v) { return v; }
#endif
};
template <class T, class EC, class EP> struct QUICKCPPLIB_SYMBOL_EXPORT abi_stamper<T, EC, EP, void>
{
};
template <class T, class EC, class EP>
using abi_policies_stamper =
abi_stamper<T, EC, EP, OUTCOME_V2_NAMESPACE::policy::all_narrow, OUTCOME_V2_NAMESPACE::policy::terminate,
            OUTCOME_V2_NAMESPACE::policy::error_code_throw_as_system_error<T, EC, EP>, OUTCOME_V2_NAMESPACE::policy::exception_ptr_rethrow<T, EC, EP>,
            OUTCOME_V2_NAMESPACE::policy::throw_bad_result_access<EC, EP>, void>;

// Lock ABI for trivial types
extern QUICKCPPLIB_SYMBOL_EXPORT auto abi_stamp(abi_policies_stamper<int, std::error_code, double> &v)
{
  return v;
}

// Lock ABI for non-trivial types
extern QUICKCPPLIB_SYMBOL_EXPORT auto abi_stamp(abi_policies_stamper<NonTrivialType, std::error_code, std::exception_ptr> &v)
{
  return v;
}
