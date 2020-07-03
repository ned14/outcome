/* Documentation snippet
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (8 commits)
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

#if __has_include(<filesystem>) && (__cplusplus >= 201700 || _HAS_CXX17)
#include <filesystem>
namespace std_filesystem = std::filesystem;
#else
#include <experimental/filesystem>
namespace std_filesystem = std::experimental::filesystem;
#endif

namespace outcome = OUTCOME_V2_NAMESPACE;

namespace filesystem
{
  using std_filesystem::path;
  bool copy_file(const path &from, const path &to) { return false; }
  bool copy_file(const path &from, const path &to, std::error_code &ec) { return false; }
}
namespace filesystem2
{
  using std_filesystem::path;
  using std_filesystem::filesystem_error;
}

//! [filesystem_api_problem]
namespace filesystem
{
  /*! Copies the file at path `from` to path `to`.
  \returns True if file was successfully copied.
  \throws On failure throws `filesystem_error(ec.message(), from, to, ec)` with
  `ec` being the error code reported by the operating system.
  */
  bool copy_file(const path &from, const path &to);

  /*! Copies the file at path `from` to path `to`.
  \returns True if file was successfully copied. If false, `ec` is written with
  the error code reported by the operating system.
  \throws May throw an exception if there is some "catastrophic" failure
  e.g. failure to allocate memory.
  */
  bool copy_file(const path &from, const path &to, std::error_code &ec);
}
//! [filesystem_api_problem]

//! [filesystem_api_fixed]
namespace filesystem2
{
  // Error code + paths related to a failure. Also causes ADL discovery to check this namespace.
  struct failure_info
  {
    std::error_code ec;
    path path1, path2;
  };

  // Tell Outcome that failure_info is to be treated as a std::error_code
  inline const std::error_code &make_error_code(const failure_info &fi) { return fi.ec; }

  // Localise an outcome implementation specific to this namespace. Normally would just
  // be `result`, but for clarity we'll use `fs_result`.
  template <class T> using fs_result = outcome::result<T, failure_info>;

  /*! Copies the file at path `from` to path `to`.
  \returns Successful if file was successfully copied, otherwise the error code reported
  by the operating system plus a payload of the paths involved.
  \throws Never throws.
  */
  fs_result<void> copy_file(const path &from, const path &to) noexcept;
}
//! [filesystem_api_fixed]

namespace filesystem2
{
  fs_result<void> copy_file(const path &from, const path &to) noexcept { return failure_info{make_error_code(std::errc::no_such_file_or_directory), from, to}; }
}

//! [filesystem_api_custom_throw]
namespace filesystem2
{
  // If we would like Outcome to do something other than the default action (see next
  // section), we can declare this ADL discovered free function to customise what
  // to do instead.
  //
  // Note that rvalue semantics are propagated internally by Outcome, so if the user
  // called .value() on a rvalued result, failure_info will be moved rather than
  // copied from the result. That means we can overload once with value semantics,
  // and not need to overload for lvalue and rvalue situations unless we really feel
  // we need to for some reason.
  inline void outcome_throw_as_system_error_with_payload(failure_info fi)
  {
    // If the error code is not filesystem related e.g. ENOMEM, throw that as a
    // standard STL exception.
    outcome::try_throw_std_exception_from_error(fi.ec);
    // Throw the exact same filesystem_error exception which the throwing copy_file()
    // edition does.
    throw filesystem_error(fi.ec.message(), std::move(fi.path1),  //
                           std::move(fi.path2), fi.ec);
  }
}
//! [filesystem_api_custom_throw]

int main()
{
  //! [filesystem_api_custom_throw_demo]
  // Non-throwing use case
  auto o = filesystem2::copy_file("dontexist", "alsodontexist");
  if(!o)
  {
    std::cerr << "Copy file failed with error " << o.error().ec.message()                   //
              << " (path1 = " << o.error().path1 << ", path2 = " << o.error().path2 << ")"  //
              << std::endl;
  }

  // Throwing use case
  try
  {
    // Try to observe the successful value, thus triggering default actions which invokes
    // our outcome_throw_as_system_error_with_payload() above which then throws filesystem_error
    // exactly like the Filesystem TS does for its throwing overload.
    filesystem2::copy_file("dontexist", "alsodontexist").value();
  }
  catch(const filesystem2::filesystem_error &e)
  {
    std::cerr << "Copy file failed with exception " << e.what()                 //
              << " (path1 = " << e.path1() << ", path2 = " << e.path2() << ")"  //
              << std::endl;
  }
  catch(const std::exception &e)
  {
    std::cerr << "Copy file failed with exception " << e.what()  //
              << std::endl;
  }
  //! [filesystem_api_custom_throw_demo]
  return 0;
}