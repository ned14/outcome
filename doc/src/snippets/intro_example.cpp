#include "../../../include/outcome.hpp"
#include <string>
using std::string;
namespace outcome = OUTCOME_V2_NAMESPACE;

struct string_view
{
  string_view(const char*) {}
  operator string() { return {}; }
};

struct LibError : std::runtime_error
{
  explicit LibError(std::error_code, string_view s) : std::runtime_error(s) {}
};

void use_string(string) {}

//! [signature]
auto read_data_from_file(string_view path) noexcept
  -> outcome::result<string>;
//! [signature]

int main() {
//! [inspect]
if (auto rslt = read_data_from_file("config.cfg"))
  use_string(rslt.value());                   // returns string
else
  throw LibError{rslt.error(), "config.cfg"}; // returns error_code
//! [inspect]
}

//! [implementation]
auto process(const string& content) noexcept
  -> outcome::result<int>;

auto get_int_from_file(string_view path) noexcept
  -> outcome::result<int>
{
  OUTCOME_TRY(str, (read_data_from_file(path)));
  // if control gets here read_data_from_file() has succeeded
  return process(str);  // decltype(str) == string
}
//! [implementation]

auto process(const string&) noexcept
  -> outcome::result<int>
{
  return outcome::success(1);
}

auto read_data_from_file(string_view) noexcept
  -> outcome::result<string>
{
  return outcome::success("1");
}
