/* Exception types throwable
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

#ifndef OUTCOME_BAD_ACCESS_HPP
#define OUTCOME_BAD_ACCESS_HPP

#include "config.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Thrown when you try to access state in a `result<R, S>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_result_access : public std::logic_error
{
public:
  bad_result_access(const char *what)
      : std::logic_error(what)
  {
  }
};

//! Thrown when you try to access a vlue in a `result<R, S>` which isn't present.
template <class S> class OUTCOME_SYMBOL_VISIBLE bad_result_access_with : public bad_result_access
{
  S _error;

public:
  bad_result_access_with(S v)
      : bad_result_access("no value")
      , _error(std::move(v))
  {
  }
  //! Observes the error
  const S &error() const & { return _error; }
  //! Observes the error
  S &error() & { return _error; }
  //! Observes the error
  const S &&error() const && { return _error; }
  //! Observes the error
  S &&error() && { return _error; }
};

//! Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_outcome_access : public std::logic_error
{
public:
  bad_outcome_access(const char *what)
      : std::logic_error(what)
  {
  }
};

//! Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
template <class S, class P> class OUTCOME_SYMBOL_VISIBLE bad_outcome_access_with : public bad_outcome_access
{
  S _error;
  P _payload;

public:
  bad_outcome_access_with(S x, P y)
      : bad_result_access("no value")
      , _error(std::move(x))
      , _payload(std::move(y))
  {
  }
  //! Observes the error
  const S &error() const & { return _error; }
  //! Observes the error
  S &error() & { return _error; }
  //! Observes the error
  const S &&error() const && { return _error; }
  //! Observes the error
  S &&error() && { return _error; }

  //! Observes the payload
  const P &payload() const & { return _payload; }
  //! Observes the payload
  P &payload() & { return _payload; }
  //! Observes the payload
  const P &&payload() const && { return _payload; }
  //! Observes the payload
  P &&payload() && { return _payload; }
};


OUTCOME_V2_NAMESPACE_END

#endif
