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
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <fcntl.h>
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
  using path_type = filesystem::path;

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
  static inline outcome::result<file_handle> file(path_type path) noexcept;
};
//! [file_handle]

//! [file]
// Phase 2 static member constructor function, which cannot throw
inline outcome::result<file_handle> file_handle::file(file_handle::path_type path) noexcept
{
  // Perform phase 1 of object construction
  file_handle ret;

  // Perform phase 2 of object construction
  ret._fd = ::open(path.u8string().c_str(), O_RDONLY);
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

//! [construct-declaration]
template <class T> struct construct
{
  outcome::result<T> operator()() const noexcept
  {  //
    static_assert(!std::is_same<T, T>::value, "construct<T>() was not specialised for the type T supplied");
  }
};
//! [construct-declaration]

//! [construct-specialisation]
template <> struct construct<file_handle>
{
  file_handle::path_type _path;
  // Any other args, default initialised if necessary, follow here ...
  outcome::result<file_handle> operator()() const noexcept { return file_handle::file(std::move(_path)); }
};
//! [construct-specialisation]

int main()
{
  //! [static-use]
  outcome::result<file_handle> fh1 = file_handle::file("hello");
  if(!fh1)
  {
    std::cerr << "Opening file 'hello' failed with " << fh1.error().message() << std::endl;
  }
  //! [static-use]
  //! [construct-use]
  outcome::result<file_handle> fh2 = construct<file_handle>{"hello"}();
  if(!fh2)
  {
    std::cerr << "Opening file 'hello' failed with " << fh2.error().message() << std::endl;
  }
  //! [construct-use]
  return 0;
}