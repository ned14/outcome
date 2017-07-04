/* Unit testing for outcomes
(C) 2013-2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../../include/outcome/outcome.hpp"
#include "../quickcpplib/include/boost/test/unit_test.hpp"

#ifdef __cpp_exceptions

#ifdef _MSC_VER
#define BOOST_OUTCOME_POSIX_OPEN ::_open
#include <io.h>
#else
#define BOOST_OUTCOME_POSIX_OPEN ::open
#include <fcntl.h>
#endif

BOOST_AUTO_TEST_CASE(works / monad / fileopen, "Tests that the monad semantically represents opening a file")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;

  //! [monad_example]
  auto openfile = [](std::string path) noexcept->outcome<int>
  {
    int fd;
    do
    {
      fd = BOOST_OUTCOME_POSIX_OPEN(path.c_str(), 0);
    } while(-1 == fd && EINTR == errno);
    try
    {
      if(-1 == fd)
      {
        int code = errno;
        // If a temporary failure, this is an expected unexpected outcome
        if(EBUSY == code || EISDIR == code || ELOOP == code || ENOENT == code || ENOTDIR == code || EPERM == code || EACCES == code)
        {
          return error_code_extended(code, stl11::generic_category());
        }
        // If a non-temporary failure, this is an unexpected outcome
        return std::make_exception_ptr(stl11::system_error(code, stl11::generic_category(), strerror(code)));
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
  BOOST_CHECK(!a.empty());
  BOOST_CHECK(!a.has_value());
  BOOST_CHECK(a.has_exception());
  BOOST_CHECK(a.has_error());
  BOOST_CHECK(a.get_error() == error_code_extended(ENOENT, stl11::generic_category()));
  //! [monad_example]
}
#endif

