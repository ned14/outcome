/* Example of how to marshall Outcomes at namespace boundaries
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

#include "../../../include/outcome.hpp"
#if __has_include("../../../../quickcpplib/include/string_view.hpp")
#include "../../../../quickcpplib/include/string_view.hpp"
#else
#include "../../../include/outcome/quickcpplib/include/string_view.hpp"
#endif
#include <experimental/filesystem>

//! [httplib]
// This is some standalone library implementing high level HTTP
namespace httplib
{
  // These are the error code that this HTTP library can return
  enum class status_code
  {
    success = 0,  // not the HTTP success code of 200

    // A subset of all HTTP status codes for brevity
    bad_request = 400,
    access_denied = 401,
    logon_failed = 402,
    forbidden = 403,
    not_found = 404,
    internal_error = 500
  };
  // This is the error type that this HTTP library can return
  struct failure
  {
    status_code status{status_code::success};
    std::string url{};  // The failing URL
  };
  // Localise a result implementation to this library
  template <class T> using result = OUTCOME_V2_NAMESPACE::result<T, failure>;

  /* Performs a HTTP GET on the url, returning the body if successful,
  a failure with status_code if unsuccessful at the HTTP level, or a
  C++ exception throw if something catastrophic happened e.g. bad_alloc
  */
  result<std::string> get(std::string url);
}
//! [httplib]

namespace httplib
{
  result<std::string> get(std::string url)
  {
    (void) url;
#if 1
    return "hello world";
#else
    return failure{status_code::not_found, url};
#endif
  }
}

namespace filelib
{
  using std::experimental::filesystem::path;
  using std::experimental::filesystem::filesystem_error;
  using QUICKCPPLIB_NAMESPACE::string_view::string_view;
}

namespace app
{
  using QUICKCPPLIB_NAMESPACE::string_view::string_view;
}

//! [filelib]
// You may remember this from the tutorial section on Custom Payloads
namespace filelib
{
  // Error code + paths related to a failure. Also causes ADL discovery to check this namespace.
  struct failure_info
  {
    std::error_code ec;
    path path1{}, path2{};
  };

  // Tell Outcome that failure_info is to be treated as a std::error_code
  inline const std::error_code &make_error_code(const failure_info &fi) { return fi.ec; }

  // Tell Outcome that no-value observation should throw a custom exception
  inline void throw_as_system_error_with_payload(failure_info fi)
  {
    // If the error code is not filesystem related e.g. ENOMEM, throw that as a standard STL exception.
    OUTCOME_V2_NAMESPACE::try_throw_std_exception_from_error(fi.ec);
    // Throw the exact same filesystem_error exception which the throwing copy_file() edition does.
    throw filesystem_error(fi.ec.message(), std::move(fi.path1), std::move(fi.path2), fi.ec);
  }

  // Localise a result implementation specific to this namespace.
  template <class T> using result = OUTCOME_V2_NAMESPACE::result<T, failure_info>;

  // Writes a chunk of data to some file. Returns bytes written, or failure_info. Never throws exceptions.
  result<size_t> write_file(string_view chunk) noexcept;
}
//! [filelib]

namespace filelib
{
  result<size_t> write_file(string_view chunk) noexcept
  {
    (void) chunk;
    return failure_info{make_error_code(std::errc::no_space_on_device), "somepath"};
  }
}

//! [tidylib]
// There actually is a library for tidying HTML into XHTML called HTMLTidy
// See http://www.html-tidy.org/
// HTMLTidy is actually a great tool, I highly recommend it.

// This isn't the API for Tidy, but let's assume it's a C library returning
// errno domained error codes. out must be freed with free() after use.
extern "C" int tidy_html(char **out, size_t *outlen, const char *in, size_t inlen);
//! [tidylib]

extern "C" int tidy_html(char **out, size_t *outlen, const char *in, size_t inlen)
{
#if 1
  *out = const_cast<char *>(in);
  *outlen = inlen;
  return 0;
#else
  // return ENOMEM;
  return EROFS;
#endif
}

//! [app]
// This is the namespace of the application which is connecting together the httplib,
// filelib and tidylib libraries into a solution.
namespace app
{
  // Create an ADL bridge so copy/move hooks will be searched for in this namespace
  struct error_code : public std::error_code
  {
    // passthrough
    using std::error_code::error_code;
    error_code() = default;
    error_code(std::error_code ec)
        : std::error_code(ec)
    {
    }
  };
  // Localise a result and outcome implementation for this namespace
  template <class T> using result = OUTCOME_V2_NAMESPACE::result<T, std::exception_ptr>;
  template <class T> using outcome = OUTCOME_V2_NAMESPACE::outcome<T, error_code /*, std::exception_ptr */>;
  using OUTCOME_V2_NAMESPACE::success;
}
//! [app]

//! [app_map_httplib1]
namespace app
{
  // Specialise an exception type for httplib errors
  struct httplib_error : std::runtime_error
  {
    // passthrough
    using std::runtime_error::runtime_error;
    httplib_error(httplib::failure _failure, std::string msg)
        : std::runtime_error(std::move(msg))
        , failure(std::move(_failure))
    {
    }

    // the original failure
    httplib::failure failure;
  };

  // Type erase httplib::result<U> into a httplib_error exception ptr
  template <class U> inline std::exception_ptr make_httplib_exception(const httplib::result<U> &src)
  {
    std::string str("httplib failed with error ");
    switch(src.error().status)
    {
    case httplib::status_code::success:
      str.append("success");
      break;
    case httplib::status_code::bad_request:
      str.append("bad request");
      break;
    case httplib::status_code::access_denied:
      str.append("access denied");
      break;
    case httplib::status_code::logon_failed:
      str.append("logon failed");
      break;
    case httplib::status_code::forbidden:
      str.append("forbidden");
      break;
    case httplib::status_code::not_found:
      str.append("not found");
      break;
    case httplib::status_code::internal_error:
      str.append("internal error");
      break;
    }
    str.append(" [url was ");
    str.append(src.error().url);
    str.append("]");
    return std::make_exception_ptr(httplib_error(std::move(src.error()), std::move(str)));
  }
}
//! [app_map_httplib1]

//! [app_map_httplib2]
// Inject custom ValueOrError conversion
OUTCOME_V2_NAMESPACE_BEGIN
namespace convert
{
  // Provide custom ValueOrError conversion from httplib::result<U> into any result<T, std::exception_ptr>
  template <class T, bool is_result, class U,                                                              //
            typename = std::enable_if_t<std::is_constructible<typename T::value_type, U>::value>,          //
            typename = std::enable_if_t<std::is_same<std::exception_ptr, typename T::error_type>::value>>  //
  constexpr inline T
  value_or_error(httplib::result<U> &&src)
  {
    return src.has_value() ? T{std::move(src.value())} : T{app::make_httplib_exception(src)};
  }
}
OUTCOME_V2_NAMESPACE_END
//! [app_map_httplib2]

namespace app
{
  static auto test_value_or_error = OUTCOME_V2_NAMESPACE::convert::value_or_error<OUTCOME_V2_NAMESPACE::result<int, std::exception_ptr>, false>(httplib::result<int>{5});
}

//! [app_map_filelib]
namespace app
{
  namespace detail
  {
    template <class T, class U> inline void poke_exception(outcome<T> *o, const filelib::result<U> &src)
    {
      if(src.has_error())
      {
        auto &fi = src.error();
        // Synthesise a filesystem_error, exactly as if someone had called src.value()
        OUTCOME_V2_NAMESPACE::try_throw_std_exception_from_error(fi.ec);
        OUTCOME_V2_NAMESPACE::hooks::override_outcome_exception(o, std::make_exception_ptr(filelib::filesystem_error(fi.ec.message(), std::move(fi.path1), std::move(fi.path2), fi.ec)));
      }
    }
  }
  // When a httplib result gets constructed into an app outcome, synthesise this exception ptr
  template <class T, class U> constexpr inline void hook_outcome_copy_construction(outcome<T> *out, const filelib::result<U> &src) { detail::poke_exception(out, src); }
  template <class T, class U> constexpr inline void hook_outcome_move_construction(outcome<T> *out, filelib::result<U> &&src) { detail::poke_exception(out, src); }
}
//! [app_map_filelib]

//! [app_map_tidylib]
namespace app
{
  // Specialise an exception type for tidylib errors
  struct tidylib_error : std::system_error
  {
    // passthrough
    using std::system_error::system_error;
    tidylib_error() = default;
    explicit tidylib_error(int c)
        : std::system_error(c, std::generic_category())
    {
    }
  };

  // Create a C++ invoking wrapper for the tidylib C API, modifying data with the returned data,
  // returing a unique_ptr to release storage on scope exit.
  struct call_free
  {
    template <class T> void operator()(T *p) { ::free(p); }
  };
  inline outcome<std::unique_ptr<char, call_free>> tidy_html(string_view &data)
  {
    char *out = nullptr;
    size_t outlen = 0;
    int errcode = ::tidy_html(&out, &outlen, data.data(), data.size());
    if(errcode != 0)
    {
      // If the error code matches a standard STL exception, throw as that.
      OUTCOME_V2_NAMESPACE::try_throw_std_exception_from_error(std::error_code(errcode, std::generic_category()));
      // Otherwise wrap the error code into a tidylib_error exception throw
      return std::make_exception_ptr(tidylib_error(errcode));
    }
    // Reset input view to tidied html
    data = string_view(out, outlen);
    // Return a unique ptr to release storage on scope exit
    return std::unique_ptr<char, call_free>(out);
  }
}
//! [app_map_tidylib]

//! [app_go]
namespace app
{
  result<void> go()
  {
    // Note that explicit construction is required when converting between differing types
    // of outcome and result. This makes it explicit what you intend to do.
    result<std::string> a(httplib::get("http://www.nedproductions.biz/"));

    // Try to GET this URL. If an unsuccessful HTTP status is returned, serialise a string
    // containing a description of the HTTP status code and the URL which failed, storing
    // that into a httplib_error exception type which is stored as an exception ptr. The
    // TRY operation below will return that exception ptr to be rethrown in the caller.
    // Otherwise the fetched data is returned in a std::string data.
    OUTCOME_TRY(data, result<std::string>(httplib::get("http://www.nedproductions.biz/")));
    string_view data_view(data);

    // HTML tidy the fetched data. If the C library fails due to an error corresponding to
    // a standard library exception type, throw that. Otherwise, synthesise an exception
    // ptr of type tidylib_error which stores the error code returned in an error code with
    // generic category (i.e. errno domain).
    // TRY operation below will return that exception ptr to be rethrown in the caller.
    // Otherwise the tidied data is returned into holdmem, with the string view updated to
    // point at the tidied data.
    OUTCOME_TRY(holdmem, tidy_html(data_view));

    // Write the tidied data to some file. If the write fails, synthesise a filesystem_error
    // exception ptr exactly as if one called filelib::write_file(data_view).value().
    OUTCOME_TRY(written, result<size_t>(filelib::write_file(data_view)));
    return success();
  }
}
//! [app_go]

int main()
{
  try
  {
    app::go().value();
  }
  catch(const filelib::filesystem_error &e)
  {
    std::cerr << "Exception thrown, " << e.what()                               //
              << " (path1 = " << e.path1() << ", path2 = " << e.path2() << ")"  //
              << std::endl;
    return 1;
  }
  catch(const std::exception &e)
  {
    std::cerr << "Exception thrown, " << e.what() << std::endl;
    return 1;
  }
  return 0;
}