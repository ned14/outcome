//! \file test_expected.cpp

// Copyright Pierre Talbot 2013.
// Copyright Vicente J. Botet Escriba 2013,2014.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)


#include "../include/boost/outcome/outcome.hpp"

namespace stde = BOOST_OUTCOME_V1_NAMESPACE;

struct NoDefaultConstructible
{
  NoDefaultConstructible() = delete;
  NoDefaultConstructible(int)  {};
};

struct NoCopyConstructible
{
  NoCopyConstructible()  {};
  NoCopyConstructible(NoCopyConstructible const&) = delete;
  NoCopyConstructible(NoCopyConstructible &&) = default;
};
struct NoMoveConstructible
{
  NoMoveConstructible()  {};
  NoMoveConstructible(NoMoveConstructible const&) = default;
  NoMoveConstructible(NoMoveConstructible &&) = delete;
  NoMoveConstructible& operator=(NoMoveConstructible const&) = default;
  NoMoveConstructible& operator=(NoMoveConstructible &&) = delete;
};


template<typename T, bool> struct base {
  base() = default;
  base(T v) : v(v) {};
  base(base const&) = default;
  base(base&&) = default;
  T v;
};

template<typename T> struct base<T, false> {
   base() = default;
   base(T v) : v(v) {};
   base(base const&) = default;
   base(base&&) = delete;
   T v;
};

template<typename T>
class optional : public base<T, std::is_move_constructible<T>::value> {
  using base_type = base<T, std::is_move_constructible<T>::value>;
public:
  optional() = default;
  optional(T v) : base_type(v) {};
  optional(const optional&) = default;
  optional(optional &&) = default;
};

int main()
{
  {
    stde::expected<NoDefaultConstructible> x; // FAILS as expected
  }
#if 0
  {
    NoCopyConstructible ncc;
    stde::expected<NoCopyConstructible> x{ncc}; // FAILS as expected
  }
  {
    NoCopyConstructible ncc;
    stde::expected<NoCopyConstructible> x{std::move(ncc)};
    stde::expected<NoCopyConstructible> y{x}; // FAILS as expected

  }
  {
    NoMoveConstructible nmc;
    NoMoveConstructible nmc2 = std::move(nmc); // FAILS as expected

    // fixme
    stde::expected<NoMoveConstructible> x;
    stde::expected<NoMoveConstructible> y =  std::move(x); // DOESN'T FAIL
  }
#endif
  {
    optional<NoMoveConstructible> x;
    optional<NoMoveConstructible> y {std::move(x)}; //FAILS as expected
  }
  static_assert(! std::is_default_constructible<NoDefaultConstructible>::value, "");
  static_assert(! std::is_default_constructible<stde::expected<NoDefaultConstructible>>::value, "");

  static_assert(! std::is_copy_constructible<NoCopyConstructible>::value, "");
  static_assert(! std::is_constructible<stde::expected<NoCopyConstructible>, NoCopyConstructible const& >::value, "");
  static_assert(! std::is_constructible<stde::expected<NoCopyConstructible>, stde::expected<NoCopyConstructible> const& >::value, "");
  static_assert(! std::is_copy_constructible<stde::expected<NoCopyConstructible>>::value, "");

  {
    // fixme
    stde::expected<NoMoveConstructible> x;
    stde::expected<NoMoveConstructible> y =  std::move(x); // DOESN'T FAIL as copy is used instead
  }
  {
    // fixme
    stde::expected<NoMoveConstructible> x;
    stde::expected<NoMoveConstructible> y {stde::expected<NoMoveConstructible>{}}; // DOESN'T FAIL as copy is used instead
  }
  static_assert(! std::is_move_constructible<NoMoveConstructible>::value, "");
  static_assert( std::is_constructible<stde::expected<NoMoveConstructible>, NoMoveConstructible && >::value, "");
  static_assert( std::is_move_constructible<stde::expected<NoMoveConstructible>>::value, "");


  return 0;
}
