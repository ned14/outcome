/* Unit testing for outcomes
(C) 2013-2026 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

// Three implementations of "a Result", one layout.
//
//   * C++:  status_result<R>
//   * C:    what CXX_DECLARE_RESULT_SYSTEM declares in <outcome/experimental/result.h>
//   * WG14: the Vendored wg14_result proposal's result_with_<name>
//
// The promise of the C and WG14 APIs is that a result built by one is readable
// by the other - the README says the layouts are identical "so you can freely
// switch between them by casting pointers". That promise had never been tested:
// no test in the suite put a WG14 result next to the other two (the WG14 test
// casts status *codes* only), so the WG14 header was free to put its 4 byte
// status word at align_up(sizeof(R), 4) - its flags union held a C enum, which
// is `int` sized - where status_result<R> keeps it at align_up(sizeof(R), 2).
// For bool, char and short that is offset 4 against 2: a WG14 result read
// through the C++ layout came back bitless (except in C23, where the enum gets
// a 16 bit underlying type). This file is the arithmetic which makes that class
// of defect impossible to reintroduce silently:
//
//   1. a compile time matrix, one macro over 15 value types, asserting that the
//      three implementations agree on sizeof, alignof and the offsets of the
//      value, of the status word (both halves) and of the status code, that the
//      C types are standard layout and the parts which decide the bytes are
//      trivially copyable, and that the status *bits* mean the same thing (equal
//      offsets with a different encoding corrupts just as well);
//   2. a runtime interchange test which builds the same state (value, error,
//      moved-from, bitless, exception flag) through each implementation, moves
//      the bytes with memcpy in both directions through both C implementations,
//      and compares only what the state makes meaningful: the interpreted triple
//      (has_value/has_error/has_exception), the value bytes, the two halves of
//      the status word and the status code bytes. Padding *between* fields and
//      the tail padding of the result are never compared - they are not ABI;
//   3. a deterministic, seeded fuzz which writes random-but-valid status words
//      and random value bytes through one implementation and reads them back
//      through the others, and then flips one bit of the status word and
//      requires all three to still classify it identically.

#include "../ndebug.h"

#if !defined(SYSTEM_ERROR2_NOT_POSIX) && __has_include("../../include/outcome/experimental/wg14_result/include/wg14_result/result.h")

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

// The WG14 headers want to know whether they may emit their inline functions.
#define WG14_RESULT_ENABLE_HEADER_ONLY 1

#include "../../include/outcome/experimental/wg14_result/include/wg14_result/result.h"

#include "../../include/outcome/experimental/result.h"
#include "../../include/outcome/experimental/status_result.hpp"

#include "quickcpplib/boost/test/unit_test.hpp"

#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <type_traits>
#include <utility>

// The value types of the matrix. Everything here is trivially copyable (a
// status_result<R> is only trivially copyable, and only memcpy-interchangeable,
// if R is) and none of them has a padding byte inside, so comparing a value's
// sizeof(R) bytes can never be comparing padding.
struct two_field_16
{
  int64_t a, b;
};
static_assert(sizeof(two_field_16) == 16, "the two field struct is the 16 byte shape");
struct struct24
{
  int v[6];
};
static_assert(sizeof(struct24) == 24, "the array struct is the 24 byte shape");
struct struct512
{
  char v[512];
};
static_assert(sizeof(struct512) == 512, "the big struct is the 512 byte shape");
struct alignas(16) overaligned16
{
  char v[16];
};
static_assert(sizeof(overaligned16) == 16 && alignof(overaligned16) == 16, "the overaligned struct is a 16 byte alignment shape");
// Not trivially *constructible* (user provided constructor, so the value is not
// a memcpy of zeroes) but still trivially copyable, which is what the result
// needs. A non-trivially-copyable R would make the result itself non-trivially
// copyable and neither C ABI could copy it at all.
struct nontrivial_value
{
  int v[4];

  nontrivial_value() = default;
  explicit nontrivial_value(int x)
      : v{x, x + 1, x + 2, x + 3}
  {
  }
};
static_assert(std::is_trivially_copyable<nontrivial_value>::value, "the non trivial shape must still be trivially copyable");

// MSVC resolves an elaborated type specifier written inside a namespace as a
// declaration of a *new*, incomplete type in that namespace, so `using x =
// struct y;` - and any other class-key spelling inside cabi_layout or inside a
// row's namespace - is C2027 "use of undefined type" there, where GCC and Clang
// find the declaration in the enclosing scope. The types this file names with a
// class-key are therefore aliased here, once, at global scope, and everything
// below uses the alias instead.
using cabi_flags_word = union WG14_RESULT_PREFIX(result_flags);
using cabi_system_code_word = struct WG14_RESULT_PREFIX(status_code_system_s);

namespace cabi_layout
{
  namespace cxx = OUTCOME_V2_NAMESPACE::experimental;
  namespace sys = SYSTEM_ERROR2_NAMESPACE;

  // The status bit encoding, spelled once. C++'s detail::status and WG14's
  // result_status_flags must equal these, and the C API - which has no enum and
  // writes the bits as literals in its makers - must produce them (its success
  // maker says `1 /* have_value */`; the rest are checked at runtime below).
  // Equal offsets with a different encoding corrupts exactly as well as unequal
  // offsets, which is why these are asserted and not assumed.
  constexpr uint16_t bit_have_value = 1U << 0U;
  constexpr uint16_t bit_have_error = 1U << 1U;
  constexpr uint16_t bit_have_exception = 2U << 1U;
  constexpr uint16_t bit_have_lost_consistency = 1U << 3U;
  constexpr uint16_t bit_have_error_is_errno = 1U << 4U;
  constexpr uint16_t bit_have_moved_from = 1U << 5U;

  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_value) == bit_have_value, "C++ have_value is not bit 1");
  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_error) == bit_have_error, "C++ have_error is not bit 2");
  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_exception) == bit_have_exception, "C++ have_exception is not bits 2-3");
  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_lost_consistency) == bit_have_lost_consistency, "C++ have_lost_consistency is not bit 8");
  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_error_is_errno) == bit_have_error_is_errno, "C++ have_error_is_errno is not bit 16");
  static_assert(static_cast<uint16_t>(OUTCOME_V2_NAMESPACE::detail::status::have_moved_from) == bit_have_moved_from, "C++ have_moved_from is not bit 32");

  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_value)) == bit_have_value, "WG14 have_value is not bit 1");
  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_error)) == bit_have_error, "WG14 have_error is not bit 2");
  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_exception)) == bit_have_exception, "WG14 have_exception is not bits 2-3");
  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_lost_consistency)) == bit_have_lost_consistency,
                "WG14 have_lost_consistency is not bit 8");
  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_error_is_errno)) == bit_have_error_is_errno,
                "WG14 have_error_is_errno is not bit 16");
  static_assert(static_cast<uint16_t>(WG14_RESULT_PREFIX(result_status_flag_have_moved_from)) == bit_have_moved_from, "WG14 have_moved_from is not bit 32");

  // The debugger-facing half of the same promise. The WG14 flags enum has a fixed
  // 16 bit underlying type (`enum result_status_flags : unsigned short`) in C23
  // and in every C++ mode, so the low half of a Result's status word is
  // *declared as that enum* and a debugger prints `result_status_flag_have_error`
  // rather than `2`. It is also the reason the status word stays 2 byte aligned:
  // an `int` sized enum there is what used to put it at align_up(sizeof(R), 4).
  // C11 and C17 cannot express an underlying type; they keep the identical two
  // bytes as `unsigned short` and read them back through
  // result_flags_get_status(), which wg14_result/test/layout_test.c exercises in
  // those two modes.
  static_assert(sizeof(WG14_RESULT_PREFIX(result_status_flags)) == 2, "the WG14 flags enum is not 2 bytes, so a Result's status word cannot be typed with it");
  static_assert(alignof(WG14_RESULT_PREFIX(result_status_flags)) == 2, "the WG14 flags enum is not 2 byte aligned, so it cannot be the status word");
  static_assert(std::is_same<decltype(((cabi_flags_word *) nullptr)->status), WG14_RESULT_PREFIX(result_status_flags)>::value,
                "the WG14 status word's low half is not declared as the flags enum");

  // One view of one implementation's layout. Every number below is read off that
  // implementation's own type by the compiler (sizeof/alignof/offsetof on the
  // members it actually declares, or for C++ off the storage status_result<R>
  // really has) - never from a formula and never from a mirror struct, so a
  // reordering in any of the three cannot agree with a stale copy of itself.
  template <class R> struct cpp_result
  {
    using type = cxx::status_result<R>;
    using layout = OUTCOME_V2_NAMESPACE::detail::cxx_result_cpp_layout<R>;
    // The class which declares the value, the status word and the status code,
    // i.e. the bytes the C layout mirrors (status_result derives from it and adds
    // none), which is where the offsets below are read from.
    using storage = typename layout::state_root_type;

    static constexpr size_t size = sizeof(type);
    static constexpr size_t align = alignof(type);
    static constexpr size_t value_off = layout::value_offset;
    static constexpr size_t flags_off = layout::flags_offset;
    static constexpr size_t error_off = layout::error_offset;
    static constexpr size_t error_size = sizeof(typename type::error_type);

    // Each implementation is asked through its own accessors, so a divergence in
    // the meaning of a status bit shows up as a disagreement here.
    static bool has_value(const void *p) { return static_cast<const type *>(p)->has_value(); }
    static bool has_error(const void *p) { return static_cast<const type *>(p)->has_error(); }
    static bool has_exception(const void *p) { return static_cast<const type *>(p)->has_exception(); }
    // status_result has no default constructor, so a blank is a value state
    // which a byte copy immediately overwrites (status word included).
    static type blank() { return type{OUTCOME_V2_NAMESPACE::success(R{})}; }
  };

  template <class C> struct c_result
  {
    using type = C;

    static constexpr size_t size = sizeof(C);
    static constexpr size_t align = alignof(C);
    static constexpr size_t value_off = offsetof(C, value);
    static constexpr size_t flags_off = offsetof(C, flags);
    static constexpr size_t error_off = offsetof(C, error);
    static constexpr size_t error_size = sizeof(((C *) nullptr)->error);

    static bool has_value(const void *p) { return (static_cast<const C *>(p)->flags & bit_have_value) != 0; }
    static bool has_error(const void *p) { return (static_cast<const C *>(p)->flags & bit_have_error) != 0; }
    static bool has_exception(const void *p) { return (static_cast<const C *>(p)->flags & bit_have_exception) != 0; }
    static type blank() { return type{}; }
  };

  template <class W> struct wg14_result
  {
    using type = W;

    static constexpr size_t size = sizeof(W);
    static constexpr size_t align = alignof(W);
    static constexpr size_t value_off = offsetof(W, value);
    static constexpr size_t flags_off = offsetof(W, _flags_);
    static constexpr size_t error_off = offsetof(W, error);
    static constexpr size_t error_size = sizeof(((W *) nullptr)->error);

    static bool has_value(const void *p) { return static_cast<const W *>(p)->has_value(); }
    static bool has_error(const void *p) { return static_cast<const W *>(p)->has_error(); }
    static bool has_exception(const void *p) { return static_cast<const W *>(p)->has_exception(); }
    static type blank() { return type{}; }
  };

  // The whole claim, in one predicate: same size, same alignment, and the same
  // place for the value, the status word (which carries the spare storage in its
  // upper half) and the status code.
  template <class A, class B>
  constexpr bool same_layout()
  {
    return A::size == B::size && A::align == B::align && A::value_off == B::value_off && A::flags_off == B::flags_off && A::error_off == B::error_off &&
           A::error_size == B::error_size;
  }

  // ---------------------------------------------------------------- runtime

// This file's requirement macro: the suite's test framework has
// BOOST_CHECK_MESSAGE (a real check which reports its message) but no
// BOOST_REQUIRE_MESSAGE, so a failed requirement here reports and stops the
// case rather than carrying on with a state it knows to be wrong.
#define CABI_REQUIRE_MESSAGE(pred, msgall)                                     \
  do                                                                           \
  {                                                                            \
    if(!(pred))                                                                \
    {                                                                          \
      std::ostringstream cabi_what;                                            \
      cabi_what << msgall;                                                     \
      BOOST_CHECK_MESSAGE(false, cabi_what.str());                             \
      return;                                                                  \
    }                                                                          \
    BOOST_CHECK_MESSAGE(true, "");                                             \
  } while(0)

  static void *at(void *p, size_t off) { return static_cast<char *>(p) + off; }
  static const void *at(const void *p, size_t off) { return static_cast<const char *>(p) + off; }

  // A byte copy into a result. status_result<R> and the WG14 result are not
  // trivially copyable (their special members propagate lifetimes / may clone a
  // status code), so copying bytes into them is what the C ABI does and what
  // result.h's own punner does, not a mistake; gcc's -Wclass-memaccess is about
  // the mistake and is not useful here.
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif
  template <class To, class From> static void copy_into(To &to, const From &from)
  {
    static_assert(sizeof(To) == sizeof(From), "a byte copy only makes sense between results of the same size");
    static_assert(alignof(To) == alignof(From), "a byte copy only makes sense between results of the same alignment");
    memcpy(static_cast<void *>(&to), static_cast<const void *>(&from), sizeof to);
  }
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

  // A result of one implementation, holding the bytes of another.
  //
  // Three things are deliberate here. status_result has no default constructor,
  // so a blank starts as a value state which the bytes then overwrite. The status
  // code field is nulled before destruction: when the bytes came from another
  // implementation the field holds that implementation's domain pointer, and when
  // they came from a *success* the source never wrote the field at all - while a
  // non-null domain would be handed to this implementation's status code
  // destructor, which would call the other implementation's domain vtable through
  // its own calling convention (C function pointer struct against C++ vtable) or
  // a garbage pointer. A null domain is the state a moved-from status code is in
  // and every implementation's destructor accepts it. Identical layout does not
  // make the domain *objects* interchangeable, and that is a separate question
  // from this file's.
  template <class Row, class From> struct copy_as
  {
    using To = typename Row::type;
    To obj;

    explicit copy_as(const From &from)
        : obj(Row::blank())
    {
      copy_into(obj, from);
    }
    ~copy_as() { memset(at(&obj, Row::error_off), 0, Row::error_size); }
    copy_as(const copy_as &) = delete;
    copy_as &operator=(const copy_as &) = delete;

    const To &operator*() const { return obj; }
    const void *bytes() const { return &obj; }
  };

  static uint16_t word_at(const void *p, size_t off)
  {
    uint16_t v;
    memcpy(&v, at(p, off), sizeof v);
    return v;
  }
  static uint16_t spare_at(const void *p, size_t off) { return word_at(p, off + 2); }

  // Require that three results holding the same state agree about what that state
  // is (through each implementation's own accessors) and agree byte for byte in
  // exactly the fields that state makes meaningful.
  template <class Cpp, class C, class W, class R>
  static void require_same(const char *tag, const char *state, const void *p_cxx, const void *p_c, const void *p_w, bool value_live, bool error_live)
  {
    const bool cxx_hv = Cpp::has_value(p_cxx), c_hv = C::has_value(p_c), w_hv = W::has_value(p_w);
    const bool cxx_he = Cpp::has_error(p_cxx), c_he = C::has_error(p_c), w_he = W::has_error(p_w);
    const bool cxx_hx = Cpp::has_exception(p_cxx), c_hx = C::has_exception(p_c), w_hx = W::has_exception(p_w);
    CABI_REQUIRE_MESSAGE(cxx_hv == c_hv && cxx_hv == w_hv,
                         tag << " " << state << ": the implementations disagree about has_value() (C++ " << cxx_hv << ", C " << c_hv << ", WG14 " << w_hv << ")");
    CABI_REQUIRE_MESSAGE(cxx_he == c_he && cxx_he == w_he,
                         tag << " " << state << ": the implementations disagree about has_error() (C++ " << cxx_he << ", C " << c_he << ", WG14 " << w_he << ")");
    CABI_REQUIRE_MESSAGE(cxx_hx == c_hx && cxx_hx == w_hx,
                         tag << " " << state << ": the implementations disagree about has_exception() (C++ " << cxx_hx << ", C " << c_hx << ", WG14 " << w_hx << ")");

    const uint16_t cxx_bits = word_at(p_cxx, Cpp::flags_off), c_bits = word_at(p_c, C::flags_off), w_bits = word_at(p_w, W::flags_off);
    CABI_REQUIRE_MESSAGE(c_bits == cxx_bits,
                         tag << " " << state << ": the status word is not where the C++ layout says (C++ " << std::hex << cxx_bits << " at " << std::dec << Cpp::flags_off
                             << ", C " << std::hex << c_bits << " at " << std::dec << C::flags_off << ")");
    CABI_REQUIRE_MESSAGE(w_bits == cxx_bits,
                         tag << " " << state << ": the status word is not where the C++ layout says (C++ " << std::hex << cxx_bits << " at " << std::dec << Cpp::flags_off
                             << ", WG14 " << std::hex << w_bits << " at " << std::dec << W::flags_off << ")");
    const uint16_t cxx_spare = spare_at(p_cxx, Cpp::flags_off), c_spare = spare_at(p_c, C::flags_off), w_spare = spare_at(p_w, W::flags_off);
    CABI_REQUIRE_MESSAGE(c_spare == cxx_spare && w_spare == cxx_spare,
                         tag << " " << state << ": the spare storage half of the status word disagrees (C++ " << cxx_spare << ", C " << c_spare << ", WG14 " << w_spare << ")");

    if(value_live)
    {
      CABI_REQUIRE_MESSAGE(0 == memcmp(at(p_cxx, Cpp::value_off), at(p_c, C::value_off), sizeof(R)), tag << " " << state << ": the C view of the value differs");
      CABI_REQUIRE_MESSAGE(0 == memcmp(at(p_cxx, Cpp::value_off), at(p_w, W::value_off), sizeof(R)), tag << " " << state << ": the WG14 view of the value differs");
    }
    if(error_live)
    {
      CABI_REQUIRE_MESSAGE(0 == memcmp(at(p_cxx, Cpp::error_off), at(p_c, C::error_off), Cpp::error_size), tag << " " << state << ": the C view of the status code differs");
      CABI_REQUIRE_MESSAGE(0 == memcmp(at(p_cxx, Cpp::error_off), at(p_w, W::error_off), Cpp::error_size), tag << " " << state << ": the WG14 view of the status code differs");
    }
  }

  // offsetof() is only meaningful if the member really is there: check that the
  // address of the member the implementation names equals its offset (this is
  // what makes the numbers above non-circular for a type with a base class).
  template <class T> static void require_member_at(const char *tag, const char *what, const T &obj, size_t off, const void *member)
  {
    CABI_REQUIRE_MESSAGE(static_cast<const void *>(at(&obj, off)) == member,
                         tag << ": " << what << " is at offset " << off << " but the compiler put it at "
                             << (static_cast<const char *>(member) - reinterpret_cast<const char *>(&obj)));
  }

  // A random but well defined value of R: random bytes are fine for the
  // aggregates, the integers and the floats (nothing here does arithmetic on
  // them), but a bool may only hold 0 or 1 and a pointer must point at something
  // this test owns.
  template <class R, class Next> static void randomise(R &v, Next &&next)
  {
    if constexpr(std::is_same<R, bool>::value)
    {
      v = (next() & 1U) != 0;
    }
    else if constexpr(std::is_pointer<R>::value)
    {
      void *const ptrs[3] = {nullptr, reinterpret_cast<void *>(0x10), static_cast<void *>(&v)};
      v = static_cast<R>(ptrs[next() % 3]);
    }
    else
    {
      unsigned char bytes[sizeof(R)];
      for(size_t i = 0; i < sizeof bytes; i++)
      {
        bytes[i] = static_cast<unsigned char>(next());
      }
      memcpy(&v, bytes, sizeof v);
    }
  }

  // The runtime body, once per value type: the states the flags word can hold, in
  // both directions through both C implementations, then the fuzz.
  template <class Cpp, class C, class W, class R, class CS, class CF, class WS, class WF>
  static void check_states(const char *tag, const R &sample, CS c_success, CF c_failure, WS w_success, WF w_failure)
  {
    using cxx_t = typename Cpp::type;
    using c_t = typename C::type;
    using w_t = typename W::type;

    // ---- value -----------------------------------------------------------------
    {
      cxx_t from_cxx{OUTCOME_V2_NAMESPACE::success(sample)};
      c_t from_c{c_success(sample)};
      w_t from_w{w_success(sample)};

      require_member_at(tag, "the C value", from_c, C::value_off, &from_c.value);
      require_member_at(tag, "the C status word", from_c, C::flags_off, &from_c.flags);
      require_member_at(tag, "the C spare storage", from_c, C::flags_off + 2, &from_c.spare_storage);
      require_member_at(tag, "the C status code", from_c, C::error_off, &from_c.error);
      require_member_at(tag, "the WG14 value", from_w, W::value_off, &from_w.value);
      require_member_at(tag, "the WG14 status word", from_w, W::flags_off, &from_w._flags_.status_bits);
      require_member_at(tag, "the WG14 spare storage", from_w, W::flags_off + 2, &from_w._flags_.spare_storage_value);
      require_member_at(tag, "the WG14 status code", from_w, W::error_off, &from_w.error);

      // Each implementation's own encoding of "success", not just the same offset.
      CABI_REQUIRE_MESSAGE(word_at(&from_cxx, Cpp::flags_off) == bit_have_value, tag << " value: the C++ status word is not have_value");
      CABI_REQUIRE_MESSAGE(word_at(&from_c, C::flags_off) == bit_have_value, tag << " value: the C status word is not have_value");
      CABI_REQUIRE_MESSAGE(word_at(&from_w, W::flags_off) == bit_have_value, tag << " value: the WG14 status word is not have_value");
      CABI_REQUIRE_MESSAGE(spare_at(&from_cxx, Cpp::flags_off) == 0 && spare_at(&from_c, C::flags_off) == 0 && spare_at(&from_w, W::flags_off) == 0,
                           tag << " value: a freshly made success left the spare storage half set");

      {  // C++ written, read by both C implementations
        const copy_as<C, cxx_t> c_from_cxx{from_cxx};
        const copy_as<W, cxx_t> w_from_cxx{from_cxx};
        require_same<Cpp, C, W, R>(tag, "value (written by C++)", &from_cxx, c_from_cxx.bytes(), w_from_cxx.bytes(), true, false);
        CABI_REQUIRE_MESSAGE(0 == memcmp(&(*c_from_cxx).value, &sample, sizeof sample), tag << " value: the C view of a C++ value is not the value");
        CABI_REQUIRE_MESSAGE(0 == memcmp(&(*w_from_cxx).value, &sample, sizeof sample), tag << " value: the WG14 view of a C++ value is not the value");
      }
      {  // C written, read by C++ and WG14, then written back to C
        const copy_as<Cpp, c_t> cxx_from_c{from_c};
        const copy_as<W, c_t> w_from_c{from_c};
        const copy_as<C, cxx_t> c_rt{cxx_from_c.obj};
        require_same<Cpp, C, W, R>(tag, "value (written by C, through C++)", cxx_from_c.bytes(), c_rt.bytes(), w_from_c.bytes(), true, false);
        CABI_REQUIRE_MESSAGE((*c_rt).flags == from_c.flags && (*c_rt).spare_storage == from_c.spare_storage, tag << " value: the status word did not survive C -> C++ -> C");
      }
      {  // WG14 written, read by C++ and C, then written back to WG14
        const copy_as<Cpp, w_t> cxx_from_w{from_w};
        const copy_as<C, w_t> c_from_w{from_w};
        const copy_as<W, cxx_t> w_rt{cxx_from_w.obj};
        require_same<Cpp, C, W, R>(tag, "value (written by WG14, through C++)", cxx_from_w.bytes(), c_from_w.bytes(), w_rt.bytes(), true, false);
        CABI_REQUIRE_MESSAGE((*w_rt)._flags_.status_bits == from_w._flags_.status_bits && (*w_rt)._flags_.spare_storage_value == from_w._flags_.spare_storage_value,
                             tag << " value: the status word did not survive WG14 -> C++ -> WG14");
        CABI_REQUIRE_MESSAGE((*cxx_from_w).has_value() && 0 == memcmp(&(*cxx_from_w).value(), &sample, sizeof sample),
                             tag << " value: C++ could not read a WG14 value");
      }
    }

    // ---- error -----------------------------------------------------------------
    {
      const intptr_t errcode = EINVAL;
      cxx_t from_cxx{sys::posix_code(static_cast<int>(errcode))};
      c_t from_c{c_failure(errcode)};
      w_t from_w{w_failure(WG14_RESULT_PREFIX(status_code_system_make_from_errc)(WG14_RESULT_PREFIX(status_code_errc_argument_out_of_domain)))};

      CABI_REQUIRE_MESSAGE(word_at(&from_cxx, Cpp::flags_off) == bit_have_error, tag << " error: the C++ status word is not have_error");
      CABI_REQUIRE_MESSAGE(word_at(&from_c, C::flags_off) == bit_have_error, tag << " error: the C status word is not have_error");
      CABI_REQUIRE_MESSAGE(word_at(&from_w, W::flags_off) == bit_have_error, tag << " error: the WG14 status word is not have_error");
      // each implementation's own status code, through its own member: a real
      // code, with a domain and the payload it was told, not a zeroed field
      CABI_REQUIRE_MESSAGE(from_c.error.domain != nullptr && from_c.error.value == errcode, tag << " error: the C status code is not EINVAL");
      CABI_REQUIRE_MESSAGE(from_w.error.base.domain != nullptr && from_w.error.value == static_cast<intptr_t>(WG14_RESULT_PREFIX(status_code_errc_argument_out_of_domain)),
                           tag << " error: the WG14 status code is not argument_out_of_domain");
      require_member_at(tag, "the C status code", from_c, C::error_off, &from_c.error);
      require_member_at(tag, "the WG14 status code", from_w, W::error_off, &from_w.error);

      // Each of the three images below is a byte copy of ONE implementation's
      // result, so the status code bytes (its domain pointer included) must be
      // identical in all three - which is the strongest form of "the status code
      // is where the C++ layout says it is", and needs no canonicalisation.
      {  // C++ written
        const copy_as<C, cxx_t> c_from_cxx{from_cxx};
        const copy_as<W, cxx_t> w_from_cxx{from_cxx};
        require_same<Cpp, C, W, R>(tag, "error (written by C++)", &from_cxx, c_from_cxx.bytes(), w_from_cxx.bytes(), false, true);
        CABI_REQUIRE_MESSAGE((*c_from_cxx).error.domain == static_cast<const void *>(&from_cxx.error().domain()), tag << " error: the C view of a C++ status code is a different code");
        CABI_REQUIRE_MESSAGE(static_cast<const void *>((*w_from_cxx).error.base.domain) == static_cast<const void *>(&from_cxx.error().domain()), tag << " error: the WG14 view of a C++ status code is a different code");
      }
      {  // C written, through C++ and back
        const copy_as<Cpp, c_t> cxx_from_c{from_c};
        const copy_as<W, c_t> w_from_c{from_c};
        const copy_as<C, cxx_t> c_rt{cxx_from_c.obj};
        require_same<Cpp, C, W, R>(tag, "error (written by C, through C++)", cxx_from_c.bytes(), c_rt.bytes(), w_from_c.bytes(), false, true);
        CABI_REQUIRE_MESSAGE((*c_rt).error.value == errcode && (*c_rt).error.domain == from_c.error.domain, tag << " error: the status code did not survive C -> C++ -> C");
      }
      {  // WG14 written, through C++ and back
        const copy_as<Cpp, w_t> cxx_from_w{from_w};
        const copy_as<C, w_t> c_from_w{from_w};
        const copy_as<W, cxx_t> w_rt{cxx_from_w.obj};
        require_same<Cpp, C, W, R>(tag, "error (written by WG14, through C++)", cxx_from_w.bytes(), c_from_w.bytes(), w_rt.bytes(), false, true);
        CABI_REQUIRE_MESSAGE((*w_rt).error.value == from_w.error.value && (*w_rt).error.base.domain == from_w.error.base.domain,
                             tag << " error: the status code did not survive WG14 -> C++ -> WG14");
        CABI_REQUIRE_MESSAGE((*cxx_from_w).has_error() && (*cxx_from_w).error().value() == from_w.error.value, tag << " error: C++ could not read a WG14 failure");
      }
    }

    // ---- moved-from ------------------------------------------------------------
    // Only C++ has move semantics, so the state is made by C++ and read back
    // through the other two: the moved-from flag lives in the same status word,
    // and a reader which looks at the wrong word cannot see it.
    {
      cxx_t source{OUTCOME_V2_NAMESPACE::success(sample)};
      cxx_t moved{std::move(source)};
      CABI_REQUIRE_MESSAGE(word_at(&source, Cpp::flags_off) == (bit_have_value | bit_have_moved_from),
                           tag << " moved-from: the C++ move did not leave have_value|have_moved_from, it left " << std::hex << word_at(&source, Cpp::flags_off));
      CABI_REQUIRE_MESSAGE(moved.has_value() && !moved.has_error(), tag << " moved-from: the destination of the move is not a value");

      const copy_as<C, cxx_t> c_from_moved{source};
      const copy_as<W, cxx_t> w_from_moved{source};
      require_same<Cpp, C, W, R>(tag, "moved-from", &source, c_from_moved.bytes(), w_from_moved.bytes(), true, false);
      CABI_REQUIRE_MESSAGE((*c_from_moved).flags == (bit_have_value | bit_have_moved_from), tag << " moved-from: the C view of the status word is not the moved-from one");
      CABI_REQUIRE_MESSAGE((*w_from_moved)._flags_.status_bits == (bit_have_value | bit_have_moved_from),
                           tag << " moved-from: the WG14 view of the status word is not the moved-from one");
    }

    // ---- bitless ---------------------------------------------------------------
    // A state no maker produces but every reader must agree about (a zeroed or
    // stream-erased buffer): no value, no error, no exception.
    {
      cxx_t from_cxx{OUTCOME_V2_NAMESPACE::success(sample)};
      c_t from_c{c_success(sample)};
      w_t from_w{w_success(sample)};
      const uint16_t none = 0;
      memcpy(at(&from_cxx, Cpp::flags_off), &none, sizeof none);
      memcpy(at(&from_c, C::flags_off), &none, sizeof none);
      memcpy(at(&from_w, W::flags_off), &none, sizeof none);
      require_same<Cpp, C, W, R>(tag, "bitless", &from_cxx, &from_c, &from_w, false, false);
      CABI_REQUIRE_MESSAGE(!from_cxx.has_value() && !from_cxx.has_error() && !from_cxx.has_exception(),
                           tag << " bitless: the C++ accessors do not agree that there is no state");
      CABI_REQUIRE_MESSAGE(!from_w.has_value() && !from_w.has_error() && !from_w.has_exception(), tag << " bitless: the WG14 accessors do not agree that there is no state");
    }

    // ---- exception flag --------------------------------------------------------
    // status_result has no exception payload (there is no C ABI for one), so this
    // is the bit's encoding and placement only: the word must say have_exception
    // and nothing else.
    {
      cxx_t from_cxx{OUTCOME_V2_NAMESPACE::success(sample)};
      c_t from_c{c_success(sample)};
      w_t from_w{w_success(sample)};
      const uint16_t exception = bit_have_exception;
      memcpy(at(&from_cxx, Cpp::flags_off), &exception, sizeof exception);
      memcpy(at(&from_c, C::flags_off), &exception, sizeof exception);
      memcpy(at(&from_w, W::flags_off), &exception, sizeof exception);
      require_same<Cpp, C, W, R>(tag, "exception flag", &from_cxx, &from_c, &from_w, false, false);
      CABI_REQUIRE_MESSAGE(from_cxx.has_exception() && !from_cxx.has_value() && !from_cxx.has_error(),
                           tag << " exception flag: the C++ accessors do not see the exception bit");
      CABI_REQUIRE_MESSAGE(from_w.has_exception() && !from_w.has_value() && !from_w.has_error(),
                           tag << " exception flag: the WG14 accessors do not see the exception bit");
      CABI_REQUIRE_MESSAGE(C::has_exception(&from_c) && !C::has_value(&from_c) && !C::has_error(&from_c),
                           tag << " exception flag: the C bits do not see the exception bit");
    }
  }

  // ---- fuzz -------------------------------------------------------------------
  // Random but *valid* status words and random value bytes, written through the
  // C implementation and read back through C++ and WG14, then one bit of the
  // status word flipped and all three required to agree about the result. 2048
  // iterations: the same seed every run, so a failure is reproducible.
  template <class Cpp, class C, class W, class R>
  static void check_fuzz(const char *tag)
  {
    using c_t = typename C::type;

    uint32_t rng = 0x9E3779B9U;
    auto next = [&rng]() {
      rng ^= rng << 13;
      rng ^= rng >> 17;
      rng ^= rng << 5;
      return rng;
    };
    for(int iteration = 0; iteration < 2048; iteration++)
    {
      R sample{};
      randomise(sample, next);
      const uint16_t bits = static_cast<uint16_t>(next() & 0x3FU);  // bits 0-5 are the ones in use
      const uint16_t spare = static_cast<uint16_t>(next());

      c_t c{};
      memcpy(&c.value, &sample, sizeof sample);
      c.flags = bits;
      c.spare_storage = spare;
      memset(at(&c, C::error_off), 0, C::error_size);  // a null domain: what a moved-from status code holds

      const bool value_live = (bits & bit_have_value) != 0;
      const bool error_live = (bits & bit_have_error) != 0;

      {
        const copy_as<Cpp, c_t> x{c};
        const copy_as<W, c_t> w{c};
        require_same<Cpp, C, W, R>(tag, "fuzz", x.bytes(), &c, w.bytes(), value_live, error_live);
        CABI_REQUIRE_MESSAGE((*x).has_value() == value_live, tag << " fuzz: the C++ has_value() disagrees with the status word " << std::hex << bits);
        CABI_REQUIRE_MESSAGE((*x).has_error() == error_live, tag << " fuzz: the C++ has_error() disagrees with the status word " << std::hex << bits);
        CABI_REQUIRE_MESSAGE((*x).has_exception() == ((bits & bit_have_exception) != 0), tag << " fuzz: the C++ has_exception() disagrees with the status word " << std::hex << bits);
        CABI_REQUIRE_MESSAGE((*w).has_value() == value_live && (*w).has_error() == error_live && (*w).has_exception() == ((bits & bit_have_exception) != 0),
                             tag << " fuzz: the WG14 accessors disagree with the status word " << std::hex << bits);
        CABI_REQUIRE_MESSAGE(c.flags == bits && c.spare_storage == spare, tag << " fuzz: the C view of the status word is not the one that was written");
      }

      // Flip one bit of the status word. All three must still read the same
      // status word, whichever bit it was and whichever state it makes.
      const uint16_t flipped = static_cast<uint16_t>(bits ^ (1U << (next() % 6)));
      c.flags = flipped;
      const copy_as<Cpp, c_t> x2{c};
      const copy_as<W, c_t> w2{c};
      CABI_REQUIRE_MESSAGE((*x2).has_value() == ((flipped & bit_have_value) != 0) && (*w2).has_value() == ((flipped & bit_have_value) != 0),
                           tag << " fuzz: has_value() diverged after flipping a status bit (" << std::hex << flipped << ")");
      CABI_REQUIRE_MESSAGE((*x2).has_error() == ((flipped & bit_have_error) != 0) && (*w2).has_error() == ((flipped & bit_have_error) != 0),
                           tag << " fuzz: has_error() diverged after flipping a status bit (" << std::hex << flipped << ")");
      CABI_REQUIRE_MESSAGE((*x2).has_exception() == ((flipped & bit_have_exception) != 0) && (*w2).has_exception() == ((flipped & bit_have_exception) != 0),
                           tag << " fuzz: has_exception() diverged after flipping a status bit (" << std::hex << flipped << ")");
    }
  }

  /* The matrix below asserts that the C structs are standard layout, because that
  is what makes them a C ABI. MSVC reports the bool row as not standard layout,
  while the char row - whose two C structs have the identical shape, offsets, size
  and padding and differ only in the declared type of the value member - passes,
  and the assertions which actually decide the ABI (sizeof, alignof and every
  member offset against status_result's, in same_layout<>() below) hold for the
  bool row everywhere. So there, and there only, the trait disagrees with the
  layout: naming the disagreement keeps the assertion everywhere else, on every
  other row and on every other compiler, rather than dropping it outright. It is
  std::is_standard_layout's compiler intrinsic __is_standard_layout that is being
  disbelieved here, not the layout. */
  template <class T> struct trait_denies_standard_layout : std::false_type
  {
  };
#if defined(_MSC_VER)
  template <> struct trait_denies_standard_layout<bool> : std::true_type
  {
  };
#endif

}  // namespace cabi_layout

// The matrix, in one place: one row per value type of the shape. Each row
// declares the same R as a C result and as a WG14 result, asserts the three-way
// layout identity at compile time and emits the runtime test for it.
#define CABI_LAYOUT_ROW(name, R, VALUE)                                                                                                                                        \
  CXX_DECLARE_RESULT_SYSTEM(cabi_##name, R);                                                                                                                                  \
  WG14_RESULT_DECLARE(R, cabi_##name);                                                                                                                                        \
  /* Aliased at the scope which declared it: the elaborated spelling cannot be */                                                                                             \
  /* written inside cabi_row_##name on MSVC (see the note above cabi_layout).  */                                                                                             \
  using cabi_c_##name = CXX_RESULT_SYSTEM(cabi_##name);                                                                                                                       \
  namespace cabi_row_##name                                                                                                                                                   \
  {                                                                                                                                                                           \
    using cxx_t = OUTCOME_V2_NAMESPACE::experimental::status_result<R>;                                                                                                       \
    using c_t = cabi_c_##name;                                                                                                                                                \
    using w_t = WG14_RESULT(cabi_##name);                                                                                                                                     \
    using cpp = cabi_layout::cpp_result<R>;                                                                                                                                   \
    using c = cabi_layout::c_result<c_t>;                                                                                                                                     \
    using w = cabi_layout::wg14_result<w_t>;                                                                                                                                  \
                                                                                                                                                                              \
    /* The layout properties each implementation really has, which are not the  */                                                                                            \
    /* same in all three - a test which claimed they were would just be wrong:  */                                                                                            \
    /*   - the C API struct is a plain aggregate and is standard layout and     */                                                                                            \
    /*     trivially copyable, which is what makes it a C ABI at all;           */                                                                                            \
    /*   - the WG14 result is standard layout; its C++ wrapper is deliberately  */                                                                                            \
    /*     not trivially copyable (its status code member's copy constructor    */                                                                                            \
    /*     may clone a payload through the domain), so what is asserted is that */                                                                                            \
    /*     the parts which decide the layout - the status word union, the C     */                                                                                            \
    /*     status code struct and the value type - are;                          */                                                                                            \
    /*   - status_result<R> is neither standard layout nor trivially copyable   */                                                                                            \
    /*     (basic_result has user provided special members; that is how it      */                                                                                            \
    /*     propagates lifetimes), which is exactly why the C API crosses to it  */                                                                                            \
    /*     by punning bytes rather than by assignment, and why the offsets      */                                                                                            \
    /*     below are read off its storage root - so what is asserted for C++ is */                                                                                            \
    /*     that its status word type is a trivially copyable standard layout    */                                                                                            \
    /*     word and that its storage root is the whole object (no member or     */                                                                                            \
    /*     padding lives outside the bytes the C layout mirrors).               */                                                                                            \
    static_assert(std::is_standard_layout<c_t>::value || cabi_layout::trait_denies_standard_layout<R>::value,                                                                    \
                  #name " : the C result is not standard layout");                                                                                                           \
    static_assert(std::is_trivially_copyable<c_t>::value, #name " : the C result is not trivially copyable");                                                                 \
    static_assert(std::is_standard_layout<w_t>::value || cabi_layout::trait_denies_standard_layout<R>::value,                                                                  \
                  #name " : the WG14 result is not standard layout");                                                                                                        \
    static_assert(std::is_trivially_copyable<R>::value, #name " : the value type is not trivially copyable");                                                                 \
    static_assert(std::is_standard_layout<cabi_flags_word>::value, #name " : the WG14 status word is not standard layout");                                                   \
    static_assert(std::is_trivially_copyable<cabi_flags_word>::value, #name " : the WG14 status word is not trivially copyable");                                              \
    static_assert(std::is_trivially_copyable<cabi_system_code_word>::value, #name " : the WG14 C status code is not trivially copyable");                                      \
    static_assert(std::is_standard_layout<OUTCOME_V2_NAMESPACE::detail::status_bitfield_type>::value &&                                                                      \
                  std::is_trivially_copyable<OUTCOME_V2_NAMESPACE::detail::status_bitfield_type>::value,                                                                      \
                  #name " : the C++ status word type is not a trivially copyable standard layout word");                                                                      \
    static_assert(sizeof(cpp::storage) == sizeof(cxx_t) && alignof(cpp::storage) == alignof(cxx_t),                                                                            \
                  #name " : status_result has members outside the storage its layout is read from");                                                                          \
                                                                                                                                                                              \
    static_assert(cabi_layout::same_layout<cpp, c>(), #name " : the C result layout is not status_result's layout (sizeof, alignof or a member offset)");                       \
    static_assert(cabi_layout::same_layout<cpp, w>(), #name " : the WG14 result layout is not status_result's layout (sizeof, alignof or a member offset)");                    \
    static_assert(cabi_layout::same_layout<c, w>(), #name " : the C and WG14 result layouts differ from each other");                                                         \
    static_assert(sizeof(c_t) == sizeof(w_t), #name " : the C and WG14 results are not the same size");                                                                       \
    /* The same claim again, but one property at a time, so that a divergence                                                                                                 \
       names the property and the shape instead of just failing the predicate                                                                                                 \
       above. */                                                                                                                                                              \
    static_assert(w::size == cpp::size, #name " : the WG14 result is not the size status_result is");                                                                         \
    static_assert(w::align == cpp::align, #name " : the WG14 result is not aligned like status_result");                                                                      \
    static_assert(w::value_off == cpp::value_off, #name " : the WG14 value is not where status_result keeps it");                                                             \
    static_assert(w::flags_off == cpp::flags_off, #name " : the WG14 status word is not where status_result keeps it");                                                       \
    static_assert(w::error_off == cpp::error_off, #name " : the WG14 status code is not where status_result keeps it");                                                       \
    static_assert(w::error_size == cpp::error_size, #name " : the WG14 status code is not the size status_result's is");                                                      \
    /* The layout rule itself, asserted off status_result so that it cannot drift                                                                                             \
       from what the WG14 header asserts internally, and so that the C11/C17/C23                                                                                              \
       build of wg14_result/test/layout_test.c (which cannot see status_result at                                                                                             \
       all, and asserts exactly this) is checking the same rule: the value first,                                                                                             \
       the status word at align_up(sizeof(R), 2), the status code at the next                                                                                                 \
       alignment boundary after the 4 byte status word, and the size rounded up                                                                                               \
       to the result's own alignment. */                                                                                                                                      \
    static constexpr size_t cabi_flags_size = sizeof(OUTCOME_V2_NAMESPACE::detail::status_bitfield_type);                                                                     \
    static constexpr size_t cabi_error_align = alignof(cxx_t::error_type);                                                                                                    \
    static_assert(cpp::value_off == 0, #name " : status_result's value is not at offset 0");                                                                                  \
    static_assert(cpp::flags_off == (sizeof(R) + 1) / 2 * 2, #name " : status_result's status word is not at align_up(sizeof(R), 2)");                                        \
    static_assert(cpp::error_off ==                                                                                                                                           \
                  (cpp::flags_off + cabi_flags_size + cabi_error_align - 1) / cabi_error_align * cabi_error_align,                                                            \
                  #name " : status_result's status code is not at the alignment boundary after its status word");                                                             \
    static_assert(cpp::size == (cpp::error_off + cpp::error_size + alignof(cxx_t) - 1) / alignof(cxx_t) * alignof(cxx_t),                                                     \
                  #name " : status_result is padded beyond what its alignment requires");                                                                                     \
                                                                                                                                                                              \
    static void run()                                                                                                                                                         \
    {                                                                                                                                                                         \
      R sample = VALUE;                                                                                                                                                 \
      cabi_layout::check_states<cpp, c, w, R>(#name, sample, outcome_make_result_system_cabi_##name##_success,                                                               \
                                              outcome_make_result_system_cabi_##name##_failure_system, result_cabi_##name##_make_success,                                    \
                                              result_cabi_##name##_make_failure);                                                                                             \
      cabi_layout::check_fuzz<cpp, c, w, R>(#name);                                                                                                                           \
    }                                                                                                                                                                         \
  }

#define CABI_LAYOUT_ROWS(X)                                                                                                                                                   \
  X(b, bool, true)                                                                                                                                                            \
  X(c, char, (char) -1)                                                                                                                                                       \
  X(s, short, (short) -12345)                                                                                                                                                 \
  X(i, int, 0x7fedcba9)                                                                                                                                                       \
  X(l, long, 0x0102030405060708L)                                                                                                                                             \
  X(ll, long long, 0x0102030405060708LL)                                                                                                                                      \
  X(p, intptr_t, (intptr_t) 0x0102030405060708LL)                                                                                                                             \
  X(f, float, 3.5f)                                                                                                                                                           \
  X(d, double, -2.25)                                                                                                                                                         \
  X(vp, void *, (void *) 0x1234)                                                                                                                                              \
  X(two16, two_field_16, (two_field_16{1, 2}))                                                                                                                                \
  X(s24, struct24, (struct24{{0, 1, 2, 3, 4, 5}}))                                                                                                                            \
  X(s512, struct512, (struct512{{1, 2, 3}}))                                                                                                                                  \
  X(oa16, overaligned16, (overaligned16{{7, 8}}))                                                                                                                             \
  X(ntv, nontrivial_value, (nontrivial_value{9}))

CABI_LAYOUT_ROWS(CABI_LAYOUT_ROW)

#define CABI_LAYOUT_RUN(name, R, VALUE) cabi_row_##name::run();

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / cabi layout, "Tests that the C++, C and WG14 result layouts are identical for every shape")
{
  CABI_LAYOUT_ROWS(CABI_LAYOUT_RUN)
}

#else

// In a -noexcept duplicate SYSTEM_ERROR2_NOT_POSIX=1 removes the whole body, so
// this file would otherwise compile to a binary that runs nothing and that CTest
// records as PASSED. Register a skip case instead (see skip_test.hpp).
#include "skip_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / cabi layout, "Skipped: the C ABI needs the POSIX status-code backend")
{
  SKIP_TEST_IF_DISABLED("test/tests/cabi-layout.cpp needs the POSIX status-code backend");
}

#endif
