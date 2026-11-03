/* Unit testing for outcomes
(C) 2013-2024 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

#include "../ndebug.h"

#ifndef SYSTEM_ERROR2_NOT_POSIX

#include "../../include/outcome/experimental/result.h"

struct custom_value_type
{
  int v[16];

  bool operator==(const custom_value_type &o) const noexcept { return 0 == memcmp(v, o.v, sizeof(v)); }
};

enum c_enum
{
  c_enum_success,
  c_enum_failure
};

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

CXX_DECLARE_RESULT_SYSTEM(test, custom_value_type);
using result_custom = CXX_RESULT_SYSTEM(test);

CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, "{74ceb994-7622-3a21-07f0-b016aa705585}", {c_enum::c_enum_success, "success", {errc::success}},
                                    {c_enum::c_enum_failure, "failure", {errc::invalid_argument}});

// A "system" status code is the PLATFORM's: every CXX_MAKE_RESULT_SYSTEM_* maker
// on Windows goes through win32_code, so its message is the OS's own text (EBADF is
// 9, which Windows calls ERROR_BAD_COMMAND) and not POSIX's. That is what made
// "c_result value types" the one failure in the Windows run's junit: the value was
// right, the message was Windows'. What these checks exist to catch is a status
// code read at the wrong offset, which surfaces as the "(empty)" fallback - so off
// Windows the exact POSIX text is still required, and on Windows the requirement is
// a live message which is not that fallback (pinning the OS's localized text would
// fail on a non-en-US runner).
static bool is_expected_system_message(const char *msg, const char *posix_message)
{
#ifdef _WIN32
  (void) posix_message;
  return msg != nullptr && msg[0] != '\0' && 0 != strcmp(msg, "(empty)");
#else
  return msg != nullptr && 0 == strcmp(msg, posix_message);
#endif
}

// Value types whose flags offset is NOT intptr_t's (8 on LP64) - the shape the C
// result makers used to get wrong, because they punned every result against an
// intptr_t-valued struct. `int` puts its status word at 4, `intptr_t` at 8, and
// both must work.
CXX_DECLARE_RESULT_SYSTEM(cabi_i32, int);
CXX_DECLARE_RESULT_ERRNO(cabi_i32, int);
CXX_DECLARE_RESULT_SYSTEM(cabi_ptr, intptr_t);
CXX_DECLARE_RESULT_ERRNO(cabi_ptr, intptr_t);

// The rest of the layout matrix (works / status_code / c_result layout matrix,
// below): a 1 byte value type, a 2 byte one, an 8 byte struct of two ints and a
// struct with a user provided constructor. `char` and `short` are the shapes which
// used to abort in a debug build and silently corrupt with NDEBUG: the C struct
// put its 4 byte status word at align_up(sizeof(R), 4) while status_result<R> puts
// it at align_up(sizeof(R), 2), so the two layouts only agreed when sizeof(R) % 4
// was 0 or 3.
struct two_field_value_type
{
  int a, b;
};
struct nontrivial_value_type  // user provided constructor: not trivial, still trivially copyable
{
  int v[4];

  nontrivial_value_type() = default;
  explicit nontrivial_value_type(int x)
      : v{x, x + 1, x + 2, x + 3}
  {
  }
};

CXX_DECLARE_RESULT_SYSTEM(cabi_chr, char);
CXX_DECLARE_RESULT_ERRNO(cabi_chr, char);
CXX_DECLARE_RESULT_SYSTEM(cabi_sht, short);
CXX_DECLARE_RESULT_ERRNO(cabi_sht, short);
CXX_DECLARE_RESULT_SYSTEM(cabi_lng, long);
CXX_DECLARE_RESULT_ERRNO(cabi_lng, long);
CXX_DECLARE_RESULT_SYSTEM(cabi_two, two_field_value_type);
CXX_DECLARE_RESULT_ERRNO(cabi_two, two_field_value_type);
CXX_DECLARE_RESULT_SYSTEM(cabi_ntr, nontrivial_value_type);
CXX_DECLARE_RESULT_ERRNO(cabi_ntr, nontrivial_value_type);

enum narrow_enum
{
  narrow_enum_success,
  narrow_enum_failure
};
CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(cabi_chr, narrow_enum, "{2b9a0b16-27c6-309e-4d4f-6f0f59a17c4e}", {narrow_enum::narrow_enum_success, "success", {errc::success}},
                                    {narrow_enum::narrow_enum_failure, "failure", {errc::invalid_argument}});

template <class T> using result = OUTCOME_V2_NAMESPACE::experimental::status_result<T>;

#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / c_result, "Tests that the C result with status_code works as intended")
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  const custom_value_type shouldbe{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  {  // errored with posix code
    result_custom l(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), posix_error);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
    BOOST_CHECK(outcome_status_code_equal(&l.error, &l2.error));
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, EFAULT));
    std::cout << outcome_status_code_message(&l.error) << std::endl;
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&l.error), "Bad address"));
  }
  {  // valued
    result_custom l(outcome_make_result_system_test_success(shouldbe));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(m);
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(!m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK(m.value() == shouldbe);
  }
  if(false)  // correctly contract asserts
  {          // errored from custom C enum 1
    result_custom l(CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, c_enum::c_enum_success));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), status_error<_quick_status_code_from_enum_domain<c_enum>>);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::invalid_argument));
    BOOST_CHECK(!outcome_status_code_equal(&l.error, &l2.error));
  }
  {  // errored from custom C enum 2
    result_custom l(CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(test, c_enum, c_enum::c_enum_failure));
    result<custom_value_type> m(to_result(l));
    BOOST_CHECK(!m);
    BOOST_CHECK(!m.has_value());
    BOOST_CHECK(m.has_error());
    // BOOST_CHECK(!m.has_exception());
    BOOST_CHECK_THROW(m.value(), status_error<_quick_status_code_from_enum_domain<c_enum>>);
    BOOST_CHECK_NO_THROW(m.error());
    result_custom l2(outcome_make_result_system_test_failure_posix((int) errc::invalid_argument));
    BOOST_CHECK(outcome_status_code_equal(&l.error, &l2.error));
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, EINVAL));
    std::cout << outcome_status_code_message(&l.error) << std::endl;
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&l.error), "failure"));
  }
  auto d(outcome_make_result_system_test_failure_posix((int) errc::bad_address));
  static_assert(std::is_default_constructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_default_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_trivially_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_copy_constructible<decltype(d)>::value, "");
  static_assert(std::is_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_nothrow_copy_assignable<decltype(d)>::value, "");
  static_assert(std::is_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_nothrow_move_assignable<decltype(d)>::value, "");
  static_assert(std::is_trivially_destructible<decltype(d)>::value, "");
  static_assert(std::is_nothrow_destructible<decltype(d)>::value, "");

  // Single parameter C try
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(r);
      return will_succeed();
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup on failure
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(printf("failed!\n"), r);
      return will_succeed();
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup and success output
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(custom_value_type v, printf("failed!\n"), r);
      return outcome_make_result_system_test_success(v);
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
  // C try with cleanup and success output and different return type
  {
    auto will_succeed = [&]() -> result_custom { return outcome_make_result_system_test_success(shouldbe); };
    auto will_fail = [&]() -> result_custom { return outcome_make_result_system_test_failure_posix((int) errc::bad_address); };
    auto test = [&](result_custom r) -> result_custom
    {
      CXX_RESULT_SYSTEM_TRY(custom_value_type v, test, printf("failed!\n"), r);
      return outcome_make_result_system_test_success(v);
    };
    auto r1 = test(will_succeed());
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(r1));
    BOOST_CHECK(0 == memcmp(r1.value.v, shouldbe.v, sizeof(shouldbe.v)));
    auto r2 = test(will_fail());
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(r2));
    BOOST_CHECK(outcome_status_code_equal_generic(&r2.error, EFAULT));
  }
}

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / c_result value types, "Tests that a C result works when its value type is not pointer sized")
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  // The C result layout is ABI, so the two value types which matter here are
  // pinned: an int result carries its status word at 4, an intptr_t result right
  // after the value (8 on LP64) - the offsets the pre-fix makers hardcoded for
  // intptr_t, which the fix had to leave alone and give every other R its own.
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_i32), flags) == 4, "an int value type puts the status word at 4");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_ptr), flags) == sizeof(intptr_t), "an intptr_t value type puts the status word after the value");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_ptr), error) == 2 * sizeof(intptr_t), "an intptr_t result's status code starts here");

  {  // R = int: the status code must reach the reader, through both makers
    // ENOENT, not EBADF: the C ABI's system code is the platform's, so on Windows
    // EBADF's 9 is ERROR_BAD_COMMAND, and Win32's own mapping table (detail/
    // win32_code_to_generic_code.ipp) has no entry for it - generic_code() is
    // unknown there, so equal_generic() *cannot* hold, whatever the layout. ENOENT
    // is 2/ERROR_FILE_NOT_FOUND and maps to no_such_file_or_directory on both, so
    // the assertion still says "the reader sees the same code" everywhere.
    auto l(outcome_make_result_system_cabi_i32_failure_system(ENOENT));
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(l));
    BOOST_CHECK(!CXX_RESULT_HAS_VALUE(l));
    BOOST_CHECK_EQUAL(l.flags, 2U);
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, ENOENT));
    BOOST_CHECK(is_expected_system_message(outcome_status_code_message(&l.error), "No such file or directory"));
    // ... and the C++ view of the same bytes must agree
    result<int> m(to_result(l));
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(m.error() == errc::no_such_file_or_directory);
    auto p(outcome_make_result_posix_cabi_i32_failure_posix(ENOENT));
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(p));
    BOOST_CHECK(outcome_status_code_equal_generic(&p.error, ENOENT));
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&p.error), "No such file or directory"));
  }
  {  // R = int: a value with the upper bits set must survive the round trip
    auto l(outcome_make_result_system_cabi_i32_success((int) 0x7fedcba9));
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(l));
    BOOST_CHECK_EQUAL(l.value, (int) 0x7fedcba9);
    result<int> m(to_result(l));
    BOOST_CHECK(m.has_value());
    BOOST_CHECK_EQUAL(m.value(), (int) 0x7fedcba9);
  }
  {  // R = intptr_t: the layout every existing user has, unchanged
    // ENOENT for the reason given above the R = int block: EBADF has no Win32
    // generic mapping, so it cannot be asserted portably through equal_generic().
    auto l(outcome_make_result_system_cabi_ptr_failure_system((intptr_t) ENOENT));
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(l));
    BOOST_CHECK_EQUAL(l.flags, 2U);
    BOOST_CHECK(outcome_status_code_equal_generic(&l.error, ENOENT));
    BOOST_CHECK(is_expected_system_message(outcome_status_code_message(&l.error), "No such file or directory"));
    result<intptr_t> m(to_result(l));
    BOOST_CHECK(m.has_error());
    BOOST_CHECK(m.error() == errc::no_such_file_or_directory);
  }
  {  // R = intptr_t: 64 bit value with non-zero upper bits
    const intptr_t v = (intptr_t) 0x0102030405060708ULL;
    auto l(outcome_make_result_posix_cabi_ptr_success(v));
    BOOST_CHECK(CXX_RESULT_HAS_VALUE(l));
    BOOST_CHECK(l.value == v);
    result<intptr_t> m(to_result(l));
    BOOST_CHECK(m.has_value());
    BOOST_CHECK(m.value() == v);
  }
}

// One value type of the layout matrix: both failure makers and the success maker
// are run, and each result is checked from C (flags, value, status code) and from
// C++ (to_result()) in both directions.
//
// The abort this file exists to catch used to happen in here: this file #undefs
// NDEBUG, so the header's asserts are live, and the pre-fix makers punned every R
// against an intptr_t-shaped struct.
template <class SystemResult, class R, class PosixResult>
static void check_c_result_layout(const char *tag, SystemResult (*make_success)(R), SystemResult (*make_failure_system)(intptr_t),
                                  PosixResult (*make_failure_posix)(int), SystemResult (*to_c)(result<R>), const R &value)
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  const int errcode = ENOENT;
  const char *message = "No such file or directory";

  SystemResult s = make_success(value);
  BOOST_CHECK_MESSAGE(CXX_RESULT_HAS_VALUE(s), tag << ": a success is not flagged as a value");
  BOOST_CHECK_MESSAGE(!CXX_RESULT_HAS_ERROR(s), tag << ": a success is flagged as an error");
  BOOST_CHECK_MESSAGE(0 == memcmp(&s.value, &value, sizeof(R)), tag << ": the success value was not preserved");
  result<R> cs(to_result(s));
  BOOST_CHECK_MESSAGE(cs.has_value(), tag << ": the C++ view of the success has no value");
  BOOST_CHECK_MESSAGE(0 == memcmp(&cs.value(), &value, sizeof(R)), tag << ": the C++ view of the success lost the value");
  SystemResult roundtrip = to_c(std::move(cs));  // status codes are move only
  BOOST_CHECK_MESSAGE(0 == memcmp(&roundtrip.value, &value, sizeof(R)), tag << ": the C++ -> C round trip lost the value");

  SystemResult f = make_failure_system(errcode);
  BOOST_CHECK_MESSAGE(CXX_RESULT_HAS_ERROR(f), tag << ": a system failure is not flagged as an error");
  BOOST_CHECK_MESSAGE(!CXX_RESULT_HAS_VALUE(f), tag << ": a system failure is flagged as a value");
  BOOST_CHECK_MESSAGE(f.flags == 2U, tag << ": a system failure's status word is not have_error, it is " << f.flags);
  BOOST_CHECK_MESSAGE(f.spare_storage == 0, tag << ": a failure left the status word's upper half set");
  BOOST_CHECK_MESSAGE(outcome_status_code_equal_generic(&f.error, errcode) != 0, tag << ": the failure's status code is not errno " << errcode);
  BOOST_CHECK_MESSAGE(is_expected_system_message(outcome_status_code_message(&f.error), message),
                      tag << ": the failure's message is '" << outcome_status_code_message(&f.error) << "'");
  result<R> cf(to_result(f));
  BOOST_CHECK_MESSAGE(cf.has_error(), tag << ": the C++ view of the system failure has no error");
  BOOST_CHECK_MESSAGE(cf.error() == errc::no_such_file_or_directory, tag << ": the C++ view of the system failure has the wrong error");

  PosixResult p = make_failure_posix(errcode);
  BOOST_CHECK_MESSAGE(CXX_RESULT_HAS_ERROR(p), tag << ": a posix failure is not flagged as an error");
  BOOST_CHECK_MESSAGE(p.flags == 2U, tag << ": a posix failure's status word is not have_error, it is " << p.flags);
  BOOST_CHECK_MESSAGE(outcome_status_code_equal_generic(&p.error, errcode) != 0, tag << ": the posix failure's status code is not errno " << errcode);
  BOOST_CHECK_MESSAGE(0 == strcmp(outcome_status_code_message(&p.error), message),
                      tag << ": the posix failure's message is '" << outcome_status_code_message(&p.error) << "'");
  result<R> cp(to_result(p));
  BOOST_CHECK_MESSAGE(cp.has_error(), tag << ": the C++ view of the posix failure has no error");
}

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / c_result layout matrix, "Tests the C result layout for value types of every shape")
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  // The C struct is the description of a C result's layout, so its status word
  // offset is the ABI a C caller compiles against. `char` and `short` used to be
  // 4 here (a 4 byte `unsigned flags`), which is where their abort came from:
  // status_result<char> keeps its status word at 2.
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_chr), flags) == 2, "a char value type puts the status word at 2");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_sht), flags) == 2, "a short value type puts the status word at 2");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_i32), flags) == 4, "an int value type puts the status word at 4");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_lng), flags) == sizeof(long), "a long value type puts the status word after the value");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_ptr), flags) == sizeof(intptr_t), "an intptr_t value type puts the status word after the value");
  static_assert(offsetof(CXX_RESULT_SYSTEM(cabi_two), flags) == sizeof(two_field_value_type), "a two int struct puts the status word after it");

  check_c_result_layout("char", outcome_make_result_system_cabi_chr_success, outcome_make_result_system_cabi_chr_failure_system,
                        outcome_make_result_posix_cabi_chr_failure_posix, to_system_cabi_chr, (char) 0xff);
  check_c_result_layout("short", outcome_make_result_system_cabi_sht_success, outcome_make_result_system_cabi_sht_failure_system,
                        outcome_make_result_posix_cabi_sht_failure_posix, to_system_cabi_sht, (short) -12345);
  check_c_result_layout("int", outcome_make_result_system_cabi_i32_success, outcome_make_result_system_cabi_i32_failure_system,
                        outcome_make_result_posix_cabi_i32_failure_posix, to_system_cabi_i32, (int) 0x7fedcba9);
  check_c_result_layout("long", outcome_make_result_system_cabi_lng_success, outcome_make_result_system_cabi_lng_failure_system,
                        outcome_make_result_posix_cabi_lng_failure_posix, to_system_cabi_lng, (long) 0x0102030405060708L);
  check_c_result_layout("intptr_t", outcome_make_result_system_cabi_ptr_success, outcome_make_result_system_cabi_ptr_failure_system,
                        outcome_make_result_posix_cabi_ptr_failure_posix, to_system_cabi_ptr, (intptr_t) 0x0102030405060708LL);
  check_c_result_layout("two ints", outcome_make_result_system_cabi_two_success, outcome_make_result_system_cabi_two_failure_system,
                        outcome_make_result_posix_cabi_two_failure_posix, to_system_cabi_two, two_field_value_type{-1, 0x7fffffff});
  check_c_result_layout("nontrivial", outcome_make_result_system_cabi_ntr_success, outcome_make_result_system_cabi_ntr_failure_system,
                        outcome_make_result_posix_cabi_ntr_failure_posix, to_system_cabi_ntr, nontrivial_value_type{0x11223344});

  {  // the enum table maker takes the same pun, so it gets the same narrow value type
    auto e = CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(cabi_chr, narrow_enum, narrow_enum::narrow_enum_failure);
    BOOST_CHECK(CXX_RESULT_HAS_ERROR(e));
    BOOST_CHECK(outcome_status_code_equal_generic(&e.error, (int) errc::invalid_argument));
    BOOST_CHECK(0 == strcmp(outcome_status_code_message(&e.error), "failure"));  // the enum table's own text
  }
}
#else

// In a -noexcept duplicate SYSTEM_ERROR2_NOT_POSIX=1 removes the whole body, so
// this file used to compile to a binary that ran nothing and that CTest still
// recorded as PASSED (reviewer P0 r7:T1). Skip instead (see skip_test.hpp).
#include "skip_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / status_code / c_result, "Skipped: c_result needs the POSIX status-code backend")
{
  SKIP_TEST_IF_DISABLED("test/tests/experimental-c-result.cpp needs the POSIX status-code backend");
}

#endif
