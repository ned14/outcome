/* Documentation snippet
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (5 commits) and Andrzej Krzemienski <akrzemi1@gmail.com> (1 commit)
File Created: Mar 2017


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

namespace outcome = OUTCOME_V2_NAMESPACE;

//! [abort_policy]
struct abort_policy : outcome::policy::base
{
  template <class Impl> static constexpr void wide_value_check(Impl &&self)
  {
    if(!base::_has_value(std::forward<Impl>(self)))
      std::abort();
  }

  template <class Impl> static constexpr void wide_error_check(Impl &&self)
  {
    if(!base::_has_error(std::forward<Impl>(self)))
      std::abort();
  }

  template <class Impl> static constexpr void wide_exception_check(Impl &&self)
  {
    if(!base::_has_exception(std::forward<Impl>(self)))
      std::abort();
  }
};
//! [abort_policy]

//! [throwing_policy]
template <typename T, typename EC, typename EP> struct throwing_policy : outcome::policy::base
{
  static_assert(std::is_convertible<EC, std::error_code>::value, "only EC = error_code");

  template <class Impl> static constexpr void wide_value_check(Impl &&self)
  {
    if(!base::_has_value(std::forward<Impl>(self)))
    {
      if(base::_has_error(std::forward<Impl>(self)))
        throw std::system_error(base::_error(std::forward<Impl>(self)));
      else
        std::rethrow_exception(base::_exception<T, EC, EP, throwing_policy>(std::forward<Impl>(self)));
    }
  }

  template <class Impl> static constexpr void wide_error_check(Impl &&self)
  {
    if(!base::_has_error(std::forward<Impl>(self)))
    {
      if(base::_has_exception(std::forward<Impl>(self)))
        std::rethrow_exception(base::_exception<T, EC, EP, throwing_policy>(std::forward<Impl>(self)));
      else
        base::_make_ub(std::forward<Impl>(self));
    }
  }

  template <class Impl> static constexpr void wide_exception_check(Impl &&self)
  {
    if(!base::_has_exception(std::forward<Impl>(self)))
      base::_make_ub(std::forward<Impl>(self));
  }
};
//! [throwing_policy]

//! [outcome_spec]
template <typename T>
using strictOutcome =  //
outcome::basic_outcome<T, std::error_code, std::exception_ptr, abort_policy>;
//! [outcome_spec]

template <typename T, typename EC = std::error_code>
using throwingOutcome =  //
outcome::basic_outcome<T, EC, std::exception_ptr, throwing_policy<T, EC, std::exception_ptr>>;

int main()
{
  try
  {
    throwingOutcome<int> i = std::error_code{};
    i.value();  // throws
    assert(false);
  }
  catch(std::system_error const &)
  {
  }

  strictOutcome<int> i = 1;
  assert(i.value() == 1);
  i.error();  // calls abort()
}
