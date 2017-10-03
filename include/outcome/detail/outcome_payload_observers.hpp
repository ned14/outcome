/* Payload observers for outcome type
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

#ifndef OUTCOME_OUTCOME_PAYLOAD_OBSERVERS_HPP
#define OUTCOME_OUTCOME_PAYLOAD_OBSERVERS_HPP

#include "result_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  //! The payload observers implementation of `outcome<R, S, P>`.
  template <class Base, class R, class S, class P, class NoValuePolicy> class outcome_payload_observers : public Base
  {
  public:
    using payload_type = P;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access payload without runtime checks.
    \preconditions The outcome to have an payload state, otherwise it is undefined behaviour.
    \returns Reference to the held `payload_type` according to overload.
    \group assume_payload
    */
    inline constexpr payload_type &assume_payload() & noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &assume_payload() const &noexcept;
    /// \group assume_payload
    inline constexpr payload_type &&assume_payload() && noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &&assume_payload() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
    \returns Reference to the held `payload_type` according to overload.
    \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
    \group payload
    */
    inline constexpr payload_type &payload() &;
    /// \group payload
    inline constexpr const payload_type &payload() const &;
    /// \group payload
    inline constexpr payload_type &&payload() &&;
    /// \group payload
    inline constexpr const payload_type &&payload() const &&;
  };

  template <class Base, class R, class S, class NoValuePolicy> class outcome_payload_observers<Base, R, S, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access payload without runtime checks.
    */
    constexpr void assume_payload() const noexcept { NoValuePolicy::narrow_payload_check(this); }
    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
    \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void payload() const { NoValuePolicy::wide_payload_check(this); }
  };
}

OUTCOME_V2_NAMESPACE_END

#endif
