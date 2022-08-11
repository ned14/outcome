/* Example of Outcome used with C APIs
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (2 commits)


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

#include <cstring>  // for memcpy
#include <string>

#include "../../../include/outcome/experimental/status-code/include/status-code/system_code_from_exception.hpp"
#include "../../../include/outcome/experimental/status_result.hpp"

//! [function]
namespace outcome_e = OUTCOME_V2_NAMESPACE::experimental;

// Fill the supplied buffer with the integer v converted to a string,
// returning length of string minus null terminator
outcome_e::status_result<size_t> to_string(char *buffer, size_t bufferlen, int v) noexcept
{
  try
  {
    // Could throw an exception!
    std::string temp(std::to_string(v));

    // Will this string exceed the supplied buffer?
    if(temp.size() + 1 > bufferlen)
      return outcome_e::errc::no_buffer_space;

    // Copy the string into the supplied buffer, and return length of string
    memcpy(buffer, temp.data(), temp.size() + 1);
    return temp.size();
  }
  catch(...)
  {
    // This is the <system_error2> analogue of Standard Outcome's
    // error_from_exception() utility function. It consumes an exception
    // ptr (defaulted to current exception), and tries to match it to a
    // standard C++ library exception type, returning a system_code
    // with an appropriate code domain (generic_code, posix_code,
    // win32_code).
    //
    // Note that using this function requires including
    // <outcome/experimental/status-code/include/system_code_from_exception.hpp>
    // It is NOT included by Experimental Outcome by default.
    return outcome_e::system_code_from_exception();
  }
}
//! [function]

int main()
{
  return 0;
}
