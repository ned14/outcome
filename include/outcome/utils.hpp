/* Tries to convert an exception ptr into its equivalent error code
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: July 2017


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

#ifndef OUTCOME_ERROR_FROM_EXCEPTION_HPP
#define OUTCOME_ERROR_FROM_EXCEPTION_HPP

#include "config.hpp"

#include <exception>
#include <system_error>

OUTCOME_V2_NAMESPACE_BEGIN

/*! Utility function which tries to match the exception in the pointer provided
to an equivalent error code. Ought to work for all standard STL types.
param e The pointer to an exception to convert. If matched, on exit this is
reset to a null pointer.
param not_matched The error code to return if we could not match the exception.
Note that a null pointer in returns a null error code.

effects Rethrows the exception in the pointer, and via a long sequence of `catch`
clauses attempts to match the equivalent error code. If a match is found, the
pointer is reset to null. If a match is not found, *not_matched* is returned instead
and the pointer is left unmodified.
*/
inline std::error_code error_from_exception(std::exception_ptr &&ep = std::current_exception(), std::error_code not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept
{
  if(!ep)
  {
    return {};
  }
  try
  {
    std::rethrow_exception(ep);
  }
  catch(const std::invalid_argument & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::invalid_argument);
  }
  catch(const std::domain_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::argument_out_of_domain);
  }
  catch(const std::length_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::argument_list_too_long);
  }
  catch(const std::out_of_range & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::result_out_of_range);
  }
  catch(const std::logic_error & /*unused*/) /* base class for this group */
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::invalid_argument);
  }
  catch(const std::system_error &e) /* also catches ios::failure */
  {
    ep = std::exception_ptr();
    return e.code();
  }
  catch(const std::overflow_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::value_too_large);
  }
  catch(const std::range_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::result_out_of_range);
  }
  catch(const std::runtime_error & /*unused*/) /* base class for this group */
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::resource_unavailable_try_again);
  }
  catch(const std::bad_alloc & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::not_enough_memory);
  }
  catch(...)
  {
  }
  return not_matched;
}

OUTCOME_V2_NAMESPACE_END

#endif
