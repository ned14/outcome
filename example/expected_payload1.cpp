//! [expected_payload1]
#include "../include/boost/outcome.hpp"

#include <fcntl.h>
#ifdef _MSC_VER
#include <io.h>
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
struct file_error
{
  enum
  {
    no_error = 0,
    out_of_memory,
    failure_to_open,
    io_failure,
    format_corrupt
  } code;
  const char *path;
};

extern outcome::expected<handle_ref, file_error> openfile(const char *path)
{
  int fd = open(path, O_RDONLY);
  if (fd == -1)
  {
    return outcome::make_unexpected(file_error{ file_error::failure_to_open, path });
  }
  try
  {
    handle_ref h = make_handle(fd);
    char temp[1025];
    ssize_t read = h->read(temp, 1024);
    if(-1 == read)
      return outcome::make_unexpected(file_error{ file_error::io_failure, path });
    temp[read] = 0;
    if(strchr(temp, 13) != nullptr)
      return outcome::make_unexpected(file_error{ file_error::format_corrupt, path });
    return h;
  }
  catch (const std::bad_alloc &)
  {
    return outcome::make_unexpected(file_error{ file_error::out_of_memory, nullptr });
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
//! [expected_payload1]
