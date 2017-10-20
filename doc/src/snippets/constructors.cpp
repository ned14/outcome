/* Example of Outcome used with constructors
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#ifdef _WIN32
#include <io.h>
#else
#define file_handle linux_file_handle
#include <fcntl.h>
#include <unistd.h>
#undef file_handle
#endif
#include <cstring>  // for strerror
#include <sys/stat.h>
#include <sys/types.h>

#include "../../../include/outcome.hpp"
#include <experimental/filesystem>

namespace outcome = OUTCOME_V2_NAMESPACE;
namespace filesystem = std::experimental::filesystem;

//! [file_handle]
class file_handle
{
  int _fd{-1};  // file descriptor
  struct stat _stat
  {
    0
  };  // stat of the fd at open

  // Phase 1 private constexpr constructor
  constexpr file_handle() {}

public:
  // Moves but not copies permitted
  file_handle(const file_handle &) = delete;
  file_handle(file_handle &&o) noexcept : _fd(o._fd) { o._fd = -1; }
  file_handle &operator=(const file_handle &) = delete;
  file_handle &operator=(file_handle &&o) noexcept
  {
    this->~file_handle();
    new(this) file_handle(std::move(o));
    return *this;
  }
  // Destruction closes the handle
  ~file_handle()
  {
    if(_fd != -1)
    {
      if(-1 == ::close(_fd))
      {
        int e = errno;
        std::cerr << "FATAL: Closing the fd during destruction failed due to " << strerror(e) << std::endl;
        std::terminate();
      }
      _fd = -1;
    }
  }

  // Phase 2 static member constructor function, which cannot throw
  static inline outcome::result<file_handle> file(filesystem::path path) noexcept;
};
//! [file_handle]

//! [file]
// Phase 2 static member constructor function, which cannot throw
inline outcome::result<file_handle> file_handle::file(filesystem::path path) noexcept
{
  // Perform phase 1 of object construction
  file_handle ret;

  // Perform phase 2 of object construction
  ret._fd = ::open(path.c_str(), O_RDONLY);
  if(-1 == ret._fd)
  {
    // Note that if we bail out here, ~file_handle() will correctly not call ::close()
    return {errno, std::system_category()};
  }
  if(-1 == ::fstat(ret._fd, &ret._stat))
  {
    // Note that if we bail out here, ~file_handle() will correctly call ::close()
    return {errno, std::system_category()};
  }

  // Returning ret directly is an area full of compiler specific behaviour quirks,
  // so be explicit by wrapping into an initialiser list with embedded move.
  return {std::move(ret)};
}
//! [file]

int main()
{
  outcome::result<file_handle> fh = file_handle::file("hello");
  return 0;
}