/* A less simple result type
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

#ifndef OUTCOME_BOOST_OUTCOME_HPP
#define OUTCOME_BOOST_OUTCOME_HPP

#include "std_outcome.hpp"

#include "boost_result.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  // Enable the .failure() observer for types matching `trait::has_error_code_v<S>` and `trait::has_exception_ptr_v<P>`
  template <class Base, class R, class S, class P, class NoValuePolicy,  //
            typename /* predicate */>
  inline P basic_outcome_failure_exception_from_error(const S &ec)
  {
    return std::make_exception_ptr(std::system_error(policy::detail::make_error_code(ec)));
  }
}

//! Namespace for policies
namespace policy
{
  namespace detail
  {
    /* Pass through `make_exception_ptr` function for `boost::exception_ptr`.
    */
    inline boost::exception_ptr make_exception_ptr(boost::exception_ptr v) { return v; }
  }  // namespace detail
}  // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <> struct has_exception_ptr<boost::exception_ptr, void>
    {
      static constexpr bool value = true;
    };
    template <class T> struct has_exception_ptr<T, boost::exception_ptr>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail

  // boost::exception_ptr are error types
  template <> struct is_error_type<boost::exception_ptr>
  {
    static constexpr bool value = true;
  };

}  // namespace trait


/*! `basic_outcome` defaulted to use `boost::system::error_code`, `boost::exception_ptr` and a `NoValuePolicy` appropriate for `boost` types.

`NoValuePolicy` defaults to a policy selected according to the characteristics of types `S` and `P`:

1. If `.value()` called when there is no `value_type` but there is an `exception_type`:
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<P>" >}} \end is true,
then `std::rethrow_exception(exception()|make_exception_ptr(exception()))`
[\verbatim {{<api "policies/outcome_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, P>">}} \end]
2. If `.value()` called when there is no `value_type` but there is an `error_type`:
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>" >}} \end is true,
then `throw std::system_error(error()|make_error_code(error()))`
[\verbatim {{<api "policies/outcome_error_code_throw_as_system_error/" "policy::error_code_throw_as_system_error<S>">}} \end]
- If `trait::has_exception_ptr_v<S>`, then `std::rethrow_exception(error()|make_exception_ptr(error()))`
[\verbatim {{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}} \end]
- If `S` is `void`, call `std::terminate()` [\verbatim {{<api "policies/terminate/" "policy::terminate">}} \end]
- If `S` is none of the above, then it is undefined behaviour [\verbatim {{<api "policies/all_narrow/" "policy::all_narrow">}} \end]
3. If `.exception()` called when there is no `exception_type`:
- If `trait::has_exception_ptr_v<P>`,
or if `P` is `void`, do `throw bad_outcome_access()`
- If `P` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
4. If `.error()` called when there is no `error_type`:
- If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`,
or if `S` is `void`, do `throw bad_outcome_access()`
- If `S` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
*/
template <class R, class S = boost::system::error_code, class P = boost::exception_ptr, class NoValuePolicy = policy::default_policy<R, S, P>>  //
using boost_outcome = basic_outcome<R, S, P, NoValuePolicy>;

OUTCOME_V2_NAMESPACE_END

#endif
