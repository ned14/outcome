/* Example of Outcome used with policies
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../../../include/outcome.hpp"

#include <iostream>

using namespace OUTCOME_V2_NAMESPACE;

//! [blank]
struct blank_policy
{
  //! Performs a narrow check of state, used in the assume_value() functions.
  template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept;

  //! Performs a narrow check of state, used in the assume_error() functions.
  template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept;

  //! Performs a wide check of state, used in the value() functions.
  template <class Impl> static constexpr void wide_value_check(Impl *self);

  //! Performs a wide check of state, used in the error() functions.
  template <class Impl> static constexpr void wide_error_check(Impl *self);


  /******** These only used if the policy is used in Outcome ********/

  //! Performs a narrow check of state, used in the assume_payload() functions.
  template <class Impl> static constexpr void narrow_payload_check(Impl *self) noexcept;

  //! Performs a narrow check of state, used in the assume_exception() functions.
  template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept;

  //! Performs a wide check of state, used in the payload() functions.
  template <class Impl> static constexpr void wide_payload_check(Impl *self);

  //! Performs a wide check of state, used in the exception() functions.
  template <class Impl> static constexpr void wide_exception_check(Impl *self);
};
//! [blank]

//! [cast]
template <class R, class S, class P> struct outcome_policy
{
  /*! Performs a wide check of state, used in the value() functions.

  \effects If outcome does not have a value, if it has an exception it rethrows it via `std::rethrow_exception()`,
  if has an error it throws a `std::system_error(error())`, else it throws `bad_outcome_access`.
  */
  template <class Impl> static constexpr void wide_value_check(Impl *self)
  {
    // All of the have_*() state check functions are always present in all Impl types
    if(!self->have_value())
    {
      if(self->have_exception())
      {
        // .value() is implemented by the result part of Outcome. It knows nothing
        // of outcome, so we need to cast to the derived type first.
        auto *_self = static_cast<const outcome<R, S, P, outcome_policy> *>(self);

        // Note this will invoke narrow_exception_check() in this policy
        std::rethrow_exception(_self->assume_exception());
      }
      if(self->have_error())
      {
        throw std::system_error(make_error_code(self->assume_error()));
      }
      throw bad_outcome_access("no value");
    }
  }
};
//! [cast]

int main()
{
  return 0;
}