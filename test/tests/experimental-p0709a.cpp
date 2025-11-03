/* Unit testing for outcomes
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (7 commits)


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

#define SYSTEM_ERROR2_FATAL(msg) abort()

#include "../../include/outcome/experimental/status_result.hpp"

#include <climits>  // for INT_MAX
#include <cstdio>

// status_code<erased<intptr_t>>
using error = SYSTEM_ERROR2_NAMESPACE::error;
// Outcome's result must be told when it is dealing with an erased status code
template <class T, class E>
using result = OUTCOME_V2_NAMESPACE::experimental::status_result<T, E, OUTCOME_V2_NAMESPACE::policy::all_narrow>;

enum class arithmetic_errc
{
  success,
  divide_by_zero,
  integer_divide_overflows,
  not_integer_division
};

class _arithmetic_errc_domain;
using arithmetic_errc_error = SYSTEM_ERROR2_NAMESPACE::status_code<_arithmetic_errc_domain>;

class _arithmetic_errc_domain : public SYSTEM_ERROR2_NAMESPACE::status_code_domain
{
  using _base = SYSTEM_ERROR2_NAMESPACE::status_code_domain;

public:
  using value_type = arithmetic_errc;

  constexpr explicit _arithmetic_errc_domain(typename _base::unique_id_type id = 0x290f170194f0c6c7) noexcept
      : _base(id)
  {
  }
  static inline constexpr const _arithmetic_errc_domain &get();

protected:
  virtual int _do_name(_vtable_name_args &args) const noexcept override final
  {
    args.ret = string_ref("arithmetic error domain");
    return 0;
  }
  virtual void _do_payload_info(_vtable_payload_info_args &args) const noexcept override final
  {
    args.ret = {sizeof(value_type), sizeof(status_code_domain *) + sizeof(value_type),
                (alignof(value_type) > alignof(status_code_domain *)) ? alignof(value_type) :
                                                                        alignof(status_code_domain *)};
  }
  virtual bool
  _do_failure(const SYSTEM_ERROR2_NAMESPACE::status_code<void> &code) const noexcept override final  // NOLINT
  {
    assert(code.domain() == *this);                                     // NOLINT
    const auto &c1 = static_cast<const arithmetic_errc_error &>(code);  // NOLINT
    return c1.value() != arithmetic_errc::success;
  }
  virtual bool _do_equivalent(const SYSTEM_ERROR2_NAMESPACE::status_code<void> &,
                              const SYSTEM_ERROR2_NAMESPACE::status_code<void> &) const noexcept override final
  {
    return false;
  }  // NOLINT
  virtual void _do_generic_code(_vtable_generic_code_args &args) const noexcept override final { args.ret = {}; }
  virtual int _do_message(_vtable_message_args &args) const noexcept override final
  {
    assert(args.code.domain() == *this);                                     // NOLINT
    const auto &c1 = static_cast<const arithmetic_errc_error &>(args.code);  // NOLINT
    switch(c1.value())
    {
    case arithmetic_errc::success:
      args.ret = _base::string_ref("success");
      return 0;
    case arithmetic_errc::divide_by_zero:
      args.ret = _base::string_ref("divide by zero");
      return 0;
    case arithmetic_errc::integer_divide_overflows:
      args.ret = _base::string_ref("integer divide overflows");
      return 0;
    case arithmetic_errc::not_integer_division:
      args.ret = _base::string_ref("not integer division");
      return 0;
    }
    args.ret = _base::string_ref("unknown");
    return 0;
  }
  SYSTEM_ERROR2_NORETURN virtual void
  _do_throw_exception(const SYSTEM_ERROR2_NAMESPACE::status_code<void> &) const override final
  {
    abort();
  }  // NOLINT
};

constexpr _arithmetic_errc_domain arithmetic_errc_domain;
inline constexpr const _arithmetic_errc_domain &_arithmetic_errc_domain::get()
{
  return arithmetic_errc_domain;
}


// Tell status code about the available implicit conversion
inline arithmetic_errc_error make_status_code(arithmetic_errc e)
{
  return arithmetic_errc_error(SYSTEM_ERROR2_NAMESPACE::in_place, e);
}

OUTCOME_V2_NAMESPACE_BEGIN
namespace trait
{
  // Tell Outcome that arithmetic_errc is convertible into std::error
  template <> struct is_error_type_enum<error, arithmetic_errc>
  {
    static constexpr bool value = true;
  };
}  // namespace trait
OUTCOME_V2_NAMESPACE_END
// And tell Outcome how to perform the implicit conversion
inline error make_error_code(arithmetic_errc e)
{
  return arithmetic_errc_error(SYSTEM_ERROR2_NAMESPACE::in_place, e);
}


result<int, error> safe_divide(int i, int j)
{
  if(j == 0)
  {
    return arithmetic_errc::divide_by_zero;
  }
  if(i == INT_MIN && j == -1)
  {
    return arithmetic_errc::integer_divide_overflows;
  }
  if(i % j != 0)
  {
    return arithmetic_errc::not_integer_division;
  }
  return i / j;
}

int caller2(int i, int j)
{
  auto r = safe_divide(i, j);
  if(r)
  {
    return r.value();
  }
  if(r.error() == arithmetic_errc::divide_by_zero)
  {
    return 0;
  }
  if(r.error() == arithmetic_errc::not_integer_division)
  {
    return i / j;  // ignore
  }
  if(r.error() == arithmetic_errc::integer_divide_overflows)
  {
    return INT_MIN;
  }
  return 0;
}

int main()
{
  printf("%d\n", caller2(5, 6));  // NOLINT
  return 0;
}
