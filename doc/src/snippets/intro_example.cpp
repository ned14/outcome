#include "../include/outcome/outcome.hpp"

namespace outcome = OUTCOME_V2_NAMESPACE;

struct string_view
{
	string_view(const char*) {}
};

struct Handle {};
struct Buffer {};

void use_int(int) {}

template <typename EC>
  void report_error(EC) {}

//! [signature]
auto read_int_from_file(string_view path) noexcept
  -> outcome::result<int>;
//! [signature]

//! [aux_signatures]
auto open_file(string_view path) noexcept -> outcome::result<Handle>;
auto read_data(Handle& h)        noexcept -> outcome::result<Buffer>;     
auto parse(const Buffer& b)      noexcept -> outcome::result<int>;
//! [aux_signatures]

auto open_file(string_view) noexcept -> outcome::result<Handle> { return Handle{}; }
auto read_data(Handle&)     noexcept -> outcome::result<Buffer> { return Buffer{}; }    
auto parse(const Buffer&)   noexcept -> outcome::result<int>    { return int{}; }

int main() {
//! [inspect]	
if (auto rslt = read_int_from_file("config.cfg"))
  use_int(rslt.value());
else
  report_error(rslt.error()); // returns std::error_code
//! [inspect]
}


//! [implementation]
auto read_int_from_file(string_view path) noexcept
  -> outcome::result<int>
{
  OUTCOME_TRY(handle, open_file(path));    // decltype(handle) == Handle
  OUTCOME_TRY(buffer, read_data(handle));  // decltype(buffer) == Buffer
  OUTCOME_TRY(val, parse(buffer));         // decltype(val) == int
  return val;
}
//! [implementation]
