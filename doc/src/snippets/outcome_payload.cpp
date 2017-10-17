#include "../../../include/outcome.hpp"
#include <experimental/filesystem>

namespace outcome = OUTCOME_V2_NAMESPACE;

namespace filesystem
{
  using std::experimental::filesystem::path;
  bool copy_file(const path &from, const path &to) { return false; }
  bool copy_file(const path &from, const path &to, std::error_code &ec) noexcept { return false; }
}
namespace filesystem2
{
  using std::experimental::filesystem::path;
  using std::experimental::filesystem::filesystem_error;
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
  \throws Never throws.
  */
  bool copy_file(const path &from, const path &to, std::error_code &ec) noexcept;
}
//! [filesystem_api_problem]

//! [filesystem_api_fixed]
namespace filesystem2
{
  // Paths related to a failure. Also causes ADL discovery to check this namespace.
  struct failure_info
  {
    path path1, path2;
  };

  // Localise an outcome implementation specific to this namespace. Normally would just
  // be `result`, but for clarity we'll use `fs_result`.
  template <class T> using fs_result = outcome::outcome<T, std::error_code, failure_info>;

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
  fs_result<void> copy_file(const path &from, const path &to) noexcept { return {make_error_code(std::errc::no_such_file_or_directory), failure_info{from, to}}; }
}

//! [filesystem_api_custom_throw]
namespace filesystem2
{
  // For outcome's with error_code + payload configuration, this free function is discovered by ADL
  // and called to implement throwing the error code with payload.
  template <class T> inline void throw_as_system_error_with_payload(const fs_result<T> *src)
  {
    // Throw the exact same filesystem_error exception which the throwing copy_file() edition does.
    throw filesystem_error(src->error().message(), src->payload().path1, src->payload().path2, src->error());
  }
}
//! [filesystem_api_custom_throw]

int main()
{
  //! [filesystem_api_custom_throw_demo]
  auto o = filesystem2::copy_file("dontexist", "alsodontexist");
  if(!o)
  {
    std::cerr << "Copy file failed with error " << o.error().message()                          //
              << " (path1 = " << o.payload().path1 << ", path2 = " << o.payload().path2 << ")"  //
              << std::endl;
  }
  try
  {
    // Try to observe the successful value, thus triggering default actions which invokes
    // our throw_as_system_error_with_payload() above which then throws filesystem_error
    // exactly like the Filesystem TS does for its throwing overload.
    filesystem2::copy_file("dontexist", "alsodontexist").value();
  }
  catch(const filesystem2::filesystem_error &e)
  {
    std::cerr << "Copy file failed with exception " << e.what()                 //
              << " (path1 = " << e.path1() << ", path2 = " << e.path2() << ")"  //
              << std::endl;
  }
  //! [filesystem_api_custom_throw_demo]
  return 0;
}