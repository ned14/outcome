#include "outcome.hpp"

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
  {
    outcome::error_code_extended ec(std::make_error_code(std::errc::invalid_argument));
    outcome::result<int> a(5);
    outcome::result<int> b(std::make_error_code(std::errc::invalid_argument));
    std::cout << sizeof(a) << std::endl;  // 32 bytes
    b.assume_value();
    a.assume_error();
    try
    {
      b.value();
      std::cerr << "fail" << std::endl;
      std::terminate();
    }
    catch(const std::system_error &e)
    {
    }
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

#if OUTCOME_ENABLE_POSITIVE_STATUS
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
#endif
    // Test compatible results can be constructed from one another
    constexpr outcome::result<int, long> g(outcome::in_place_type<int>, 5);
    constexpr outcome::result<long, int> g2(g);
    static_assert(g.has_value(), "");
    static_assert(!g.has_error(), "");
    static_assert(g.value() == 5, "");
    static_assert(g2.has_value(), "");
    static_assert(!g2.has_error(), "");
    static_assert(g2.value() == 5, "");
    constexpr outcome::result<void, int> g3(outcome::in_place_type<void>);
    constexpr outcome::result<long, int> g4(g3);
    constexpr outcome::result<int, void> g5(outcome::in_place_type<void>);
    constexpr outcome::result<long, int> g6(g5);

    // Test void
    constexpr outcome::result<void, int> h(outcome::in_place_type<void>);
    static_assert(h.has_value(), "");
#if OUTCOME_ENABLE_POSITIVE_STATUS
    static_assert(!h.has_status(), "");
#endif
    constexpr outcome::result<int, void> h2(outcome::in_place_type<void>);
    static_assert(!h2.has_value(), "");
    static_assert(h2.has_error(), "");
    constexpr outcome::result<void, void> h3;
    static_assert(!h3.has_value(), "");
    static_assert(!h3.has_error(), "");

    // Test const
    constexpr outcome::result<const int, void> i(5);
    constexpr outcome::result<const int, void> i2(i);
  }

  {
    outcome::outcome<int> a(5);
    outcome::outcome<int> b(std::make_error_code(std::errc::invalid_argument));
    std::cout << sizeof(a) << std::endl;  // 40 bytes
    b.assume_value();
    a.assume_error();
    try
    {
      b.value();
      std::cerr << "fail" << std::endl;
      std::terminate();
    }
    catch(const std::system_error &e)
    {
    }
    static_assert(!std::is_default_constructible<decltype(a)>::value, "");
    static_assert(!std::is_nothrow_default_constructible<decltype(a)>::value, "");
    static_assert(std::is_copy_constructible<decltype(a)>::value, "");
    static_assert(!std::is_trivially_copy_constructible<decltype(a)>::value, "");
    static_assert(std::is_nothrow_copy_constructible<decltype(a)>::value, "");
    static_assert(std::is_copy_assignable<decltype(a)>::value, "");
    static_assert(!std::is_trivially_copy_assignable<decltype(a)>::value, "");
    static_assert(std::is_nothrow_copy_assignable<decltype(a)>::value, "");
    static_assert(!std::is_trivially_destructible<decltype(a)>::value, "");
    static_assert(std::is_nothrow_destructible<decltype(a)>::value, "");

    // Test void compiles
    outcome::outcome<void> c(outcome::in_place_type<void>);
    outcome::outcome<void> c2(c);
    // Test int, void compiles
    outcome::outcome<int, void> d(outcome::in_place_type<std::exception_ptr>);
#if OUTCOME_ENABLE_POSITIVE_STATUS
    // Test void, status, void compiles
    constexpr outcome::outcome<int, std::errc, void> e(5, std::errc::bad_message);
#endif
  }

  {
    constexpr const char *niall = "niall";
    // error code + matching exception
    outcome::outcome<int> a(std::make_error_code(std::errc::not_enough_memory), std::make_exception_ptr(std::bad_alloc()));
    a.error();
    a.exception();
    // value + payload
    outcome::outcome<int, std::error_code, const char *> b(5, niall);
    b.error();
    b.payload();
#if OUTCOME_ENABLE_POSITIVE_STATUS
    // value + status + payload, constexpr
    constexpr outcome::outcome<int, std::errc, const char *> c(5, std::errc::bad_message, niall);
#endif
  }
  return 0;
}
