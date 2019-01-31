/* Failure observers for outcome type
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

#ifndef OUTCOME_BASIC_OUTCOME_FAILURE_OBSERVERS_HPP
#define OUTCOME_BASIC_OUTCOME_FAILURE_OBSERVERS_HPP

#include "basic_result_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  namespace adl
  {
    struct search_detail_adl
    {
    };
  }
#if defined(_MSC_VER) && _MSC_VER < 1920
  // VS2017 with /permissive- chokes on the correct form due to over eager early instantiation.
  template <class S, class P> inline void basic_outcome_failure_exception_from_error(...) { static_assert(sizeof(S) == 0, "No specialisation for these error and exception types available!"); }
#else
  template <class S, class P> inline void basic_outcome_failure_exception_from_error(...) = delete;  // NOLINT No specialisation for these error and exception types available!
#endif

  //! The failure observers implementation of `basic_outcome<R, S, P>`.
  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_failure_observers : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    /// \output_section Synthesising state observers
    /*! Synthesise exception where possible.
    \requires `trait::has_error_code_v<S>` and `trait::has_exception_ptr_v<P>` to be true, else it does not appear.
    \returns A synthesised exception type: if excepted, `exception()`; if errored, `xxx::make_exception_ptr(xxx::system_error(error()))`;
    otherwise a default constructed exception type.
    */
    exception_type failure() const noexcept
    {
      if((this->_state._status & detail::status_have_exception) != 0)
      {
        return this->exception();
      }
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return basic_outcome_failure_exception_from_error(this->error(), adl::search_detail_adl());
      }
      return exception_type();
    }
  };

}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
