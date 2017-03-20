//! [expected_payload2]
#include "../include/boost/outcome.hpp"

#include <fcntl.h>
#ifdef _MSC_VER
#include <io.h>
using ssize_t = long long;
#else
#include <unistd.h>
#endif

#include <iostream>
#include <memory>

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

// RAII for an open file handle
class handle
{
  int _fd;
public:
  handle() : _fd(-1) {}
  handle(int fd) : _fd(fd) {}
  handle(handle &&o) noexcept : _fd(o._fd) { o._fd = -1; }
  handle &operator=(handle &&o) noexcept { this->~handle(); new(this) handle(std::move(o)); return *this; }
  virtual ~handle() { if (-1 != _fd) ::close(_fd); }
  ssize_t read(void *buffer, size_t len) { return ::read(_fd, buffer, len); }
};
using handle_ref = std::shared_ptr<handle>;
inline handle_ref make_handle(int fd) { return std::make_shared<handle>(fd); }

// Custom error type
enum class extended_error
{
  format_corrupt
};
namespace detail
{
  class extended_error_category : public std::error_category
  {
  public:
    virtual const char *name() const noexcept override final { return "extended_error"; }
    virtual std::string message(int c) const override final
    {
      switch (static_cast<extended_error>(c))
      {
      case extended_error::format_corrupt:
        return "format corrupt";
      default:
        return "unknown";
      }
    }
  };
}
extern const detail::extended_error_category &extended_error_category()
{
  static detail::extended_error_category c;
  return c;
}
struct file_error
{
  std::error_code code;
  const char *path;
  file_error() : code(), path(nullptr) {}
  // Construct from a generic problem
  file_error(std::errc problem, const char *_path) : code(std::make_error_code(problem)), path(_path) {}
  // Construct from an errno
#ifdef _MSC_VER  // On MSVC the POSIX open()/read() etc functions are generic_category
  file_error(int _errno, const char *_path) : code(_errno, std::generic_category()), path(_path) {}
#else
  file_error(int _errno, const char *_path) : code(_errno, std::system_category()), path(_path) {}
#endif
  // Construct from an extended error code
  file_error(extended_error ec, const char *_path) : code(static_cast<int>(ec), detail::extended_error_category()), path(_path) {}
};

extern outcome::expected<handle_ref, file_error> openfile(const char *path)
{
  int fd = open(path, O_RDONLY);
  if (fd == -1)
  {
    // NOTE that we lose no information here, whatever error the system returned is what we return
    return outcome::make_unexpected(file_error(errno, path));
  }
  try
  {
    handle_ref h = make_handle(fd);
    char temp[1025];
    ssize_t read = h->read(temp, 1024);
    // NOTE that we lose no information here, whatever error the system returned is what we return
    if(-1 == read)
      return outcome::make_unexpected(file_error(errno, path));
    temp[read] = 0;
    if(strchr(temp, 13) != nullptr)
      return outcome::make_unexpected(file_error(extended_error::format_corrupt, path));
    return h;
  }
  catch (const std::bad_alloc &)
  {
    return outcome::make_unexpected(file_error(std::errc::not_enough_memory, nullptr));
  }
  // All other exceptions thrown upwards to abort
}

int main(void)
{
  auto h = openfile("somefile");
  if (h)
    std::cout << "File opened successfully" << std::endl;
  else
    std::cerr << "Failed to open file " << h.error().path << " due to " << h.error().code << std::endl;
  return 0;
}
//! [expected_payload2]
