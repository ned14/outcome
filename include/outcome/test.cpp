#include "result.hpp"

#include <iostream>

struct udt
{
  int _v;
  udt()
      : _v(0)
  {
  }
  udt(udt &&o) noexcept : _v(o._v) {}
  udt(const udt &o)
      : _v(o._v)
  {
  }
  udt &operator=(udt &&o) noexcept
  {
    _v = o._v;
    return *this;
  }
  udt &operator=(const udt &o)
  {
    _v = o._v;
    return *this;
  }
  ~udt() { _v = 0; }
};
// No default construction, no copy nor move
struct udt2
{
  udt2() = delete;
  udt2(udt2 &&) = delete;
  udt2(const udt2 &) = delete;
  udt2 &operator=(udt2 &&) = delete;
  udt2 &operator=(const udt2 &) = delete;
  explicit udt2(int) {}
};

int main(void)
{
  outcome::error_code_extended ec(std::make_error_code(std::errc::invalid_argument));
  outcome::result<int> a(5);
  outcome::result<int> b(std::make_error_code(std::errc::invalid_argument));
  std::cout << sizeof(a) << std::endl;  // 32 bytes
  b.assume_value();
  a.assume_error();
  b.value();
  static_assert(!std::is_default_constructible<decltype(a)>::value, "");
  static_assert(!std::is_nothrow_default_constructible<decltype(a)>::value, "");
  static_assert(std::is_copy_constructible<decltype(a)>::value, "");
  static_assert(std::is_trivially_copy_constructible<decltype(a)>::value, "");
  static_assert(std::is_nothrow_copy_constructible<decltype(a)>::value, "");
  static_assert(std::is_copy_assignable<decltype(a)>::value, "");
  static_assert(std::is_trivially_copy_assignable<decltype(a)>::value, "");
  static_assert(std::is_nothrow_copy_assignable<decltype(a)>::value, "");
  static_assert(std::is_trivially_destructible<decltype(a)>::value, "");
  static_assert(std::is_nothrow_destructible<decltype(a)>::value, "");

  // Test void compiles
  outcome::result<void> c(outcome::in_place_type<void>);
  outcome::result<void> c2(c);

  // Test a standard udt compiles
  outcome::result<udt> d(outcome::in_place_type<udt>);
  outcome::result<udt> d2(d);
  static_assert(!std::is_default_constructible<decltype(d)>::value, "");
  static_assert(!std::is_nothrow_default_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_constructible<decltype(d)>::value, "");
  static_assert(!std::is_trivially_copy_constructible<decltype(d)>::value, "");
  static_assert(!std::is_nothrow_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_assignable<decltype(d)>::value, "");
  static_assert(!std::is_trivially_copy_assignable<decltype(d)>::value, "");
  static_assert(!std::is_nothrow_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_move_assignable<decltype(d)>::value, "");
  static_assert(!std::is_trivially_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_nothrow_move_assignable<decltype(d)>::value, "");
  static_assert(!std::is_trivially_destructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_destructible<decltype(d)>::value, "");

  // Test a highly pathological udt compiles
  outcome::result<udt2> e(outcome::in_place_type<udt2>, 5);
  // outcome::result<udt2> e2(e);
  static_assert(!std::is_default_constructible<decltype(e)>::value, "");
  static_assert(!std::is_nothrow_default_constructible<decltype(e)>::value, "");
  static_assert(!std::is_copy_constructible<decltype(e)>::value, "");
  static_assert(!std::is_trivially_copy_constructible<decltype(e)>::value, "");
  static_assert(!std::is_nothrow_copy_constructible<decltype(e)>::value, "");
  static_assert(!std::is_copy_assignable<decltype(e)>::value, "");
  static_assert(!std::is_trivially_copy_assignable<decltype(e)>::value, "");
  static_assert(!std::is_nothrow_copy_assignable<decltype(e)>::value, "");
  static_assert(!std::is_move_assignable<decltype(e)>::value, "");
  static_assert(!std::is_trivially_move_assignable<decltype(e)>::value, "");
  static_assert(!std::is_nothrow_move_assignable<decltype(e)>::value, "");

  // Test value + status info works, and in constexpr
  using cresult_type = outcome::result<int, const char *>;
  constexpr const char *niall = "niall";
  constexpr cresult_type f(5, niall);
  constexpr cresult_type f2(f);
  static_assert(f, "");
  static_assert(f.has_value(), "");
  static_assert(!f.has_error(), "");
  static_assert(f.has_status(), "");
  static_assert(f.assume_value() == 5, "");
  static_assert(f.assume_status() == niall, "");
  static_assert(f.value() == 5, "");
  static_assert(f.status() == niall, "");

  return 0;
}
