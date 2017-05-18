/* Provides a custom bad_outcome error code
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Jan 2017


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

#ifndef BOOST_OUTCOME_MONAD_ERROR_H
#define BOOST_OUTCOME_MONAD_ERROR_H

#include "config.hpp"

BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN

//! \brief Enumeration of the ways in which a monad operation may fail \ingroup monad
enum class bad_outcome_errc
{
  // already_set = 1,        //!< Attempt to store a value into the monad twice
  no_state = 2,           //!< Attempt to use without a state
  exception_present = 3,  //!< Attempt to fetch an error state when the monad is in an exceptioned state
};

namespace _detail
{
  class bad_outcome_category : public stl11::error_category
  {
  public:
    virtual const char *name() const noexcept { return "basic_monad"; }
    virtual std::string message(int c) const
    {
      switch(c)
      {
      case 1:
        return "already set";
      case 2:
        return "no state";
      case 3:
        return "exception present";
      default:
        return "unknown";
      }
    }
  };
}

/*! \brief Returns a reference to a monad error category. Note the address
of one of these may not be constant throughout the process as per the ISO spec.
\ingroup monad
*/
inline const _detail::bad_outcome_category &bad_outcome_category()
{
  static _detail::bad_outcome_category c;
  return c;
}

//! \brief A monad exception object \ingroup monad
class BOOSTLITE_SYMBOL_VISIBLE bad_outcome : public stl11::system_error
{
public:
  bad_outcome(stl11::error_code ec)
      : std::system_error(ec)
  {
  }
};

//! \brief ADL looked up by the STL to convert a bad_outcome_errc into an error_code. \ingroup monad
inline stl11::error_code make_error_code(bad_outcome_errc e)
{
  return stl11::error_code(static_cast<int>(e), bad_outcome_category());
}

//! \brief ADL looked up by the STL to convert a bad_outcome_errc into an error_condition. \ingroup monad
inline stl11::error_condition make_error_condition(bad_outcome_errc e)
{
  return stl11::error_condition(static_cast<int>(e), bad_outcome_category());
}

BOOST_OUTCOME_V1_NAMESPACE_END

#if BOOST_OUTCOME_USE_BOOST_ERROR_CODE
namespace boost
{
  namespace system
  {
    //! \brief Tells the STL this is an error code enum \ingroup monad
    template <> struct is_error_code_enum<BOOST_OUTCOME_V1_NAMESPACE::bad_outcome_errc> : std::true_type
    {
    };
    //! \brief Tells the STL this is an error condition enum \ingroup monad
    template <> struct is_error_condition_enum<BOOST_OUTCOME_V1_NAMESPACE::bad_outcome_errc> : std::true_type
    {
    };
  }
}
#else
namespace std
{
  //! \brief Tells the STL this is an error code enum \ingroup monad
  template <> struct is_error_code_enum<BOOST_OUTCOME_V1_NAMESPACE::bad_outcome_errc> : std::true_type
  {
  };
  //! \brief Tells the STL this is an error condition enum \ingroup monad
  template <> struct is_error_condition_enum<BOOST_OUTCOME_V1_NAMESPACE::bad_outcome_errc> : std::true_type
  {
  };
}
#endif

#endif
