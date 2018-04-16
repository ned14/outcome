/* A very simple result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: June 2017


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

#ifndef OUTCOME_STD_RESULT_HPP
#define OUTCOME_STD_RESULT_HPP

#include "basic_result.hpp"
#include "detail/trait_std_error_code.hpp"
#include "detail/trait_std_exception.hpp"

#include "policy/result_error_code_throw_as_system_error.hpp"
#include "policy/result_exception_ptr_rethrow.hpp"
#include "policy/throw_bad_result_access.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for policies
namespace policy
{
  /*! Default policy selector.
  */
  template <class T, class EC, class E>
  using default_policy = std::conditional_t<  //
  std::is_void<EC>::value && std::is_void<E>::value,
  terminate,                                                                                         //
  std::conditional_t<                                                                                //
  trait::has_error_code_v<EC>, error_code_throw_as_system_error<T, EC, E>,                           //
  std::conditional_t<                                                                                //
  trait::has_exception_ptr_v<EC> || trait::has_exception_ptr_v<E>, exception_ptr_rethrow<T, EC, E>,  //
  all_narrow                                                                                         //
  >>>;
}  // namespace policy

/*! `basic_result` defaulted to use `std::error_code` and a `NoValuePolicy` appropriate for `std` types.

`NoValuePolicy` defaults to a policy selected according to the characteristics of type `S`:

1. If `.value()` called when there is no `value_type` but there is an `error_type`:
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>">}} \end is true,
then `throw std::system_error(error()|make_error_code(error()))` [\verbatim {{<api "policies/result_error_code_throw_as_system_error" "policy::error_code_throw_as_system_error<S>">}} \end]
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<S>">}} \end is true, then `std::rethrow_exception(error()|make_exception_ptr(error()))`
[\verbatim {{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}} \end]
- If `S` is `void`, call `std::terminate()` [\verbatim {{<api "policies/terminate/" "policy::terminate">}} \end]
- If `S` is none of the above, then it is undefined behaviour [\verbatim {{<api "policies/all_narrow/" "policy::all_narrow">}} \end]
2. If `.error()` called when there is no `error_type`:
- If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`,
or if `S` is `void`, do `throw bad_result_access()`
- If `S` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
*/
template <class R, class S = std::error_code, class NoValuePolicy = policy::default_policy<R, S, void>>  //
using std_result = basic_result<R, S, NoValuePolicy>;

/*! An "unchecked" edition of `result<T, E>` which does no special handling of specific `E` types at all.
Attempting to access `T` when there is an `E` results in nothing happening at all, it is treated with a narrow
contract (i.e. undefined behaviour).
*/
template <class R, class S = std::error_code> using std_unchecked = std_result<R, S, policy::all_narrow>;

/*! A "checked" edition of `result<T, E>` which resembles fairly closely a `std::expected<T, E>`.
Attempting to access `T` when there is an `E` results in `bad_result_access<E>` being thrown. Nothing else.

Note that this approximates the proposed `expected<T, E>` up for standardisation, see the FAQ for more
detail.
*/
template <class R, class S = std::error_code> using std_checked = std_result<R, S, policy::throw_bad_result_access<S>>;

OUTCOME_V2_NAMESPACE_END

#endif
