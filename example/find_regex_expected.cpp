#if defined(_MSC_VER) || __has_include(<experimental/filesystem>)
#include <iostream>
#include <regex>
#if __has_include(<string_view>)
#include <string_view>
#elif __has_include(<experimental/string_view>)
#include <experimental/string_view>
namespace std
{
  using std::experimental::string_view;
}
#endif

#include <vector>

#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;

#include "../include/boost/outcome.hpp"
namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

#ifdef _WIN32
#include <Windows.h>
#else
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

//! [find_regex_expected]
class mapped_string_view : public std::string_view
{
  bool _disabled;
public:
  constexpr mapped_string_view() noexcept : _disabled(true) {}
  mapped_string_view(char *s, size_t l) noexcept : std::string_view(s, l), _disabled(false) {}
  mapped_string_view(mapped_string_view &&o) noexcept : std::string_view(std::move(o)), _disabled(o._disabled) { o._disabled = true; }
  mapped_string_view &operator=(mapped_string_view &&) = delete;
  ~mapped_string_view()
  {
    if (!_disabled)
    {
#ifdef _WIN32
      UnmapViewOfFile(this->data());
#else
      munmap((void *) this->data(), this->size());
#endif
    }
  }
};
static outcome::expected<mapped_string_view> map_file_into_memory(filesystem::path p) noexcept
{
#ifdef _WIN32
  HANDLE fh, mh;
  DWORD ec;
  fh = CreateFile(p.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
  if (INVALID_HANDLE_VALUE == fh)
  {
    return outcome::make_unexpected(std::error_code(GetLastError(), std::system_category()));
  }
  BY_HANDLE_FILE_INFORMATION bhfi;
  memset(&bhfi, 0, sizeof(bhfi));
  if (!GetFileInformationByHandle(fh, &bhfi))
  {
    ec = GetLastError();
    CloseHandle(fh);
    return outcome::make_unexpected(std::error_code(ec, std::system_category()));
  }
  uint64_t length = ((uint64_t) bhfi.nFileSizeHigh << 32) | bhfi.nFileSizeLow;
  mh = CreateFileMapping(fh, nullptr, PAGE_READONLY, 0, 0, nullptr);
  ec = GetLastError();
  CloseHandle(fh);
  if (INVALID_HANDLE_VALUE == mh)
  {
    return outcome::make_unexpected(std::error_code(ec, std::system_category()));
  }
  char *addr = (char *) MapViewOfFile(mh, FILE_MAP_READ, 0, 0, 0);
  ec = GetLastError();
  CloseHandle(mh);
  if (!addr)
  {
    return outcome::make_unexpected(std::error_code(ec, std::system_category()));
  }
  return mapped_string_view(addr, (size_t) length);
#else
  int fh, ec;
  fh = open(p.c_str(), O_RDONLY);
  if (-1 == fh)
  {
    return outcome::make_unexpected(std::error_code(errno, std::system_category()));
  }
  struct stat st;
  memset(&st, 0, sizeof(st));
  if (-1 == fstat(fh, &st))
  {
    ec = errno;
    close(fh);
    return outcome::make_unexpected(std::error_code(ec, std::system_category()));
  }
  uint64_t length = st.st_size;
  char *addr = (char *)mmap(nullptr, length, PROT_READ, MAP_SHARED, fh, 0);
  ec = errno;
  close(fh);
  if (!addr)
  {
    return outcome::make_unexpected(std::error_code(ec, std::system_category()));
  }
  return mapped_string_view(addr, (size_t)length);
#endif
}

static outcome::expected<std::vector<filesystem::path>> find_regex_in_files(const std::regex &re, filesystem::directory_iterator dit, size_t depth = 0) noexcept
{
  std::vector<filesystem::path> ret;
  try
  {
    for (auto &p : dit)
    {
      if (filesystem::is_directory(p.status()))
      {
        std::error_code ec;
        filesystem::directory_iterator nit(p.path(), ec);
        if (ec)
          return outcome::make_unexpected(ec);
        BOOST_OUTCOME_TRY(results, find_regex_in_files(re, std::move(nit), depth + 1));
        // Merge found results from subdirectory into me
        ret.reserve(ret.size() + results.size());
        std::move(results.begin(), results.end(), std::back_inserter(ret));
      }
      // Try to map the file into memory
      BOOST_OUTCOME_TRY(view, map_file_into_memory(p.path()));
      // regex doesn't have a string_view overload yet ...
      if(std::regex_search(view.data(), re))
        ret.push_back(p.path());
    }
    return ret;
  }
  catch (const std::bad_alloc &)
  {
    return outcome::make_unexpected(std::make_error_code(std::errc::not_enough_memory));
  }
  catch (...)
  {
    return outcome::make_unexpected(std::make_error_code(std::errc::resource_unavailable_try_again));
  }
}
//! [find_regex_expected]

int main(int argc, char *argv[])
{
  int errcode = 0;
  if (argc < 3)
  {
    std::cerr << "Usage: " << argv[0] << " <regex> <path>" << std::endl;
    return 1;
  }
  std::regex regex;
  try
  {
    regex.assign(argv[1]);
  }
  catch (const std::regex_error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  filesystem::directory_iterator dit;
  filesystem::path path = filesystem::absolute(argv[2]);
  try
  {
    dit = filesystem::directory_iterator(path);
  }
  catch (const filesystem::filesystem_error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  std::cout << "Searching for regular expression " << argv[1] << " in path " << path << " ..." << std::endl;
  auto res = find_regex_in_files(regex, dit);
  if (!res)
  {
    std::cerr << "\nERROR: " << res.error() << std::endl;
    return 1;
  }
  std::cout << "\nFound " << res.value().size() << " files containing " << argv[1] << ":\n";
  for (const auto &i : res.value())
    std::cout << "  " << i << "\n";
  std::cout << std::flush;
  return 0;
}
#endif
