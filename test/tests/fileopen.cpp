/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (7 commits)


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

#define _CRT_SECURE_NO_WARNINGS

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

#ifdef __cpp_exceptions

#ifdef _MSC_VER
#define OUTCOME_POSIX_OPEN ::_open
#include <io.h>
#else
#define OUTCOME_POSIX_OPEN ::open
#include <fcntl.h>
#endif

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / fileopen, "Tests that the outcome semantically represents opening a file")
{
  using namespace OUTCOME_V2_NAMESPACE;

  //! [file_open_example]
  auto openfile = [](std::string path) noexcept->outcome<int>
  {
    int fd;
    do
    {
      fd = OUTCOME_POSIX_OPEN(path.c_str(), 0);  // NOLINT
    } while(-1 == fd && EINTR == errno);
    try
    {
      if(-1 == fd)
      {
        int code = errno;
        // If a temporary failure, this is an expected unexpected outcome
        if(EBUSY == code || EISDIR == code || ELOOP == code || ENOENT == code || ENOTDIR == code || EPERM == code || EACCES == code)
        {
          return std::error_code(code, std::generic_category());
        }
        // If a non-temporary failure, this is an unexpected outcome
        return std::make_exception_ptr(std::system_error(code, std::generic_category(), strerror(code)));
      }
      return fd;
    }
    catch(...)
    {
      // Any exception thrown is truly unexpected
      return std::current_exception();
    }
  };
  auto a = openfile("shouldneverexistnotever");
  BOOST_CHECK(!a);
  BOOST_CHECK(!a.has_value());
  BOOST_CHECK(!a.has_exception());
  BOOST_CHECK(a.has_error());
  BOOST_CHECK(a.error() == std::error_code(ENOENT, std::generic_category()));
  //! [file_open_example]
}
#endif
