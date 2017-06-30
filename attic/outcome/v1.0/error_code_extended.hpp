/* Extend std::error_code with the most common extensions
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (6 commits)
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

#ifndef BOOST_OUTCOME_ERROR_CODE_EXTENDED_H
#define BOOST_OUTCOME_ERROR_CODE_EXTENDED_H

#include "config.hpp"

#include "../quickcpplib/include/ringbuffer_log.hpp"

#ifndef BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE
#define BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE 4096
#endif

BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN

// Slight misuse of ringbuffer_log to keep extended error code information
inline QUICKCPPLIB_NAMESPACE::ringbuffer_log::simple_ringbuffer_log<BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE> &extended_error_code_log()
{
  static QUICKCPPLIB_NAMESPACE::ringbuffer_log::simple_ringbuffer_log<BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE> log(QUICKCPPLIB_NAMESPACE::ringbuffer_log::level::error);
  return log;
}

//! \brief De-atomiced error categories, prevents the STL inlining an atomic fence when fetching these
//! error categories
namespace deatomiced_categories
{
  namespace detail
  {
    QUICKCPPLIB_NOINLINE inline const std::error_category &_generic_category()
    {
      const std::error_category &c = stl11::generic_category();
      return c;
    }

    QUICKCPPLIB_NOINLINE inline const std::error_category &_system_category()
    {
      const std::error_category &c = stl11::system_category();
      return c;
    }
  }
  //! \brief De-atomic fascade for std::generic_category()
  inline const std::error_category &generic_category()
  {
    const std::error_category &c = detail::_generic_category();
    return c;
  }

  //! \brief De-atomic fascade for std::system_category()
  inline const std::error_category &system_category()
  {
    const std::error_category &c = detail::_system_category();
    return c;
  }
}

#ifndef BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK
#define BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK
#endif

/*! \class error_code_extended
\brief Keeps additional information about a std::error_code like custom error message,
backtrace etc. Can be safely type sliced into a std::error_code.
*/
class error_code_extended : public stl11::error_code
{
  friend inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
  using unique_id = QUICKCPPLIB_NAMESPACE::ringbuffer_log::simple_ringbuffer_log<4096>::unique_id;
  size_t _unique_id;  // into extended_error_code_log
public:
  //! Default construction
  error_code_extended()
      : _unique_id((size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }
  //! Construct from the usual int and error_category, but with optional additional message, two 32 bit codes and backtrace
  error_code_extended(int ec, const stl11::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : error_code_extended(stl11::error_code(ec, cat), msg, code1, code2, backtrace)
  {
  }
  //! Construct from error code enum
  template <class ErrorCodeEnum, typename = typename std::enable_if<stl11::is_error_code_enum<ErrorCodeEnum>::value>::type>
  error_code_extended(ErrorCodeEnum e)
      : stl11::error_code(e)
      , _unique_id((size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }
  //! Explicit copy construction from error_code
  explicit error_code_extended(const stl11::error_code &e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : error_code_extended(stl11::error_code(e), msg, code1, code2, backtrace)
  {
  }
  //! Explicit move construction from error_code
  explicit error_code_extended(stl11::error_code &&e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : stl11::error_code(std::move(e))
      , _unique_id(msg ? extended_error_code_log().emplace_back(QUICKCPPLIB_NAMESPACE::ringbuffer_log::level::error, msg, code1, code2, backtrace ? nullptr : "", 0) : (size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }
  //! Assign
  void assign(int ec, const stl11::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false) { *this = error_code_extended(ec, cat, msg, code1, code2, backtrace); }
  //! Clear contents
  void clear()
  {
    stl11::error_code::clear();
    _unique_id = (size_t) -1;
  }
  //! Fill a buffer with any extended error message and codes, returning bytes of buffer filled (zero if no extended message).
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    strncpy(buffer, item.message, len - 1);
    buffer[len - 1] = 0;
    code1 = item.code32[0];
    code2 = item.code32[1];
    if(!log.valid(unique_id(_unique_id)))
    {
      buffer[0] = 0;
      return 0;
    }
    return strlen(buffer);
  }
  //! Fill a buffer with any backtrace available, returning items filled if any.
  size_t raw_backtrace(void **buffer, size_t len) const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    size_t written = 0;
    void **_backtrace = (void **) item.backtrace;
    for(size_t n = 0; n < len && n < sizeof(item.backtrace) / sizeof(item.backtrace[0]); n++)
    {
      buffer[n] = _backtrace[n];
      written++;
    }
    return written;
  }
  //! Returns an array of strings describing the backtrace. You must free() the pointer returned, not the individual char *'s, after use.
  char **backtrace() const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    char **ret = nullptr;
    if(!item.using_backtrace)
    {
      ret = (char **) calloc(2 * sizeof(char *) + sizeof(item.function) + 1, 1);
      if(!ret)
        return nullptr;
      ret[0] = (char *) ret + 2 * sizeof(char *);
      strncpy(ret[0], item.function, sizeof(item.function));
      return ret;
    }
    else
      ret = backtrace_symbols((void **) item.backtrace, sizeof(item.backtrace) / sizeof(item.backtrace[0]));
    if(!log.valid(unique_id(_unique_id)))
    {
      free(ret);
      return 0;
    }
    return ret;
  }
};
#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec)
{
  s << ec.category().name() << " code " << ec.value() << ": " << ec.message();
  auto &log = extended_error_code_log();
  if(log.valid(error_code_extended::unique_id(ec._unique_id)))
  {
    auto &item = log[error_code_extended::unique_id(ec._unique_id)];
    s << " { " << item.message << ", " << item.code32[0] << ", " << item.code32[1] << " }";
  }
  return s;
}
#endif

BOOST_OUTCOME_V1_NAMESPACE_END

#endif
