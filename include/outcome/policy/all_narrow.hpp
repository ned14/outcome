/* Policies for result and outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_POLICY_ALL_NARROW_HPP
#define OUTCOME_POLICY_ALL_NARROW_HPP

#include "detail/common.hpp"

#include <utility>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy which treats wide checks as narrow checks.

  Can be used in both `result` and `outcome`.
  */
  struct all_narrow : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects None.
    */
    template <class Impl> static constexpr void wide_value_check(Impl &&self) { detail::base::narrow_value_check(std::forward<Impl>(self)); }
    /*! Performs a wide check of state, used in the error() functions
    \effects None.
    */
    template <class Impl> static constexpr void wide_error_check(Impl &&self) { detail::base::narrow_error_check(std::forward<Impl>(self)); }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If outcome does not have an exception, calls `std::terminate()`.
    */
    template <class Impl> static constexpr void wide_exception_check(Impl &&self) { detail::base::narrow_exception_check(std::forward<Impl>(self)); }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
