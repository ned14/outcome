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
  return 0;
}
