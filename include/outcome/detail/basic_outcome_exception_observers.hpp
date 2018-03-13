/* Exception observers for outcome type
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

#ifndef OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_HPP
#define OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_HPP

#include "basic_result_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  // Used by later code to implement .failure() observers for some given set of types
  template <class Base, class R, class S, class P, class NoValuePolicy> inline void basic_outcome_failure_exception_from_error(...) {}
  template <class Base, class R, class S, class P, class NoValuePolicy,  //
            typename = std::enable_if_t<trait::has_error_code<S>::value && trait::has_exception_ptr<P>::value>>
  inline P basic_outcome_failure_exception_from_error(const S & /* unused */);

  //! The exception observers implementation of `basic_outcome<R, S, P>`.
  template <class Base, class R, class S, class P, class NoValuePolicy, class FailureImpl = decltype(basic_outcome_failure_exception_from_error<Base, R, S, P, NoValuePolicy>(std::declval<detail::devoid<S>>()))> class basic_outcome_exception_observers;

  // Exception observers present, failure observers not present
  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy, void> : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access exception without runtime checks.
    \preconditions The outcome to have an exception state, otherwise it is undefined behaviour.
    \returns Reference to the held `exception_type` according to overload.
    \group assume_exception
    */
    constexpr inline exception_type &assume_exception() & noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &assume_exception() const &noexcept;
    /// \group assume_exception
    constexpr inline exception_type &&assume_exception() && noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &&assume_exception() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \returns Reference to the held `exception_type` according to overload.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    \group exception
    */
    constexpr inline exception_type &exception() &;
    /// \group exception
    constexpr inline const exception_type &exception() const &;
    /// \group exception
    constexpr inline exception_type &&exception() &&;
    /// \group exception
    constexpr inline const exception_type &&exception() const &&;
  };

  // Exception observers not present, failure observers not present
  template <class Base, class R, class S, class NoValuePolicy> class basic_outcome_exception_observers<Base, R, S, void, NoValuePolicy, void> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access exception without runtime checks.
    */
    constexpr void assume_exception() const noexcept { NoValuePolicy::narrow_exception_check(this); }
    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void exception() const { NoValuePolicy::wide_exception_check(this); }
  };

  // Exception observers present, failure observers present
  template <class Base, class R, class S, class P, class NoValuePolicy, class FailureImpl> class basic_outcome_exception_observers : public basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy, void>
  {
    using _base = basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy, void>;

  public:
    using exception_type = P;
    using _base::_base;

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
        return basic_outcome_failure_exception_from_error<Base, R, S, P, NoValuePolicy>(this->error());
      }
      return exception_type();
    }
  };

}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
