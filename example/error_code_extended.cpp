/* Example of how to extend result's error code with extra information
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../include/outcome/outcome.hpp"

#include <iostream>
#include <vector>

#ifdef _WIN32
#include "../quickcpplib/include/execinfo_win64.h"
#endif

/* Outcome's hook mechanism works vis ADL, so we will need a custom namespace
*/
namespace error_code_extended
{
  using OUTCOME_V2_NAMESPACE::in_place_type;
  // The extra error information we will keep
  struct extended_error_info
  {
    std::string detail;
    std::vector<void *> backtrace;
  };
  // Use thread local storage to convey a stacktrace from result construction to outcome conversion
  static thread_local std::vector<extended_error_info> extended_error_info_stack;

  // Use the error_code type as the ADL bridge for the hooks by creating a type here
  struct error_code : public std::error_code
  {
    using std::error_code::error_code;
    error_code() = default;
    error_code(std::error_code ec)  // NOLINT
    : std::error_code(ec)
    {
    }
  };

  // Localise result and outcome to using the local error_code so this namespace gets looked up for the hooks
  template <class R> using result = OUTCOME_V2_NAMESPACE::result<R, error_code>;
  template <class R> using outcome = OUTCOME_V2_NAMESPACE::outcome<R, error_code>;

  namespace detail
  {
    // Use inheritance to gain access to state
    template <class R> struct outcome_payload_poker : public outcome<R>
    {
      void _poke_exception()
      {
        extended_error_info eei(std::move(extended_error_info_stack.back()));
        extended_error_info_stack.pop_back();
        // Make a custom string for the exception
        std::string str(std::move(eei.detail));
        str.append(" [");
        char **symbols = ::backtrace_symbols(eei.backtrace.data(), eei.backtrace.size());
        for(size_t n = 0; n < eei.backtrace.size(); n++)
        {
          if(n)
            str.append("; ");
          str.append(symbols[n]);
        }
        str.append("]");
        this->_ptr = std::make_exception_ptr(std::runtime_error(std::move(str)));
        this->_state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_exception;
      }
    };
  }  // namespace detail

  // Specialise the result construction hook for our localised result
  // We hook any non-copy, non-move, non-inplace construction, capturing a stack backtrace
  // if the result is errored.
  template <class T, class R> constexpr inline void hook_result_construction(OUTCOME_V2_NAMESPACE::in_place_type_t<T>, result<R> *res) noexcept
  {
    if(res->has_error())
    {
      extended_error_info eei{"this is a custom message", 64};
      eei.backtrace.resize(::backtrace(eei.backtrace.data(), eei.backtrace.size()));
      extended_error_info_stack.push_back(std::move(eei));
    }
  }
  // Specialise the outcome copy and move conversion hook for our localised result
  template <class T, class R> constexpr inline void hook_outcome_copy_construction(OUTCOME_V2_NAMESPACE::in_place_type_t<const result<T> &>, outcome<R> *res) noexcept
  {
    // when copy constructing from a result<T>, poke in an exception
    static_cast<detail::outcome_payload_poker<R> *>(res)->_poke_exception();
  }
  template <class T, class R> constexpr inline void hook_outcome_move_construction(OUTCOME_V2_NAMESPACE::in_place_type_t<result<T> &&>, outcome<R> *res) noexcept
  {
    // when move constructing from a result<T>, poke in an exception
    static_cast<detail::outcome_payload_poker<R> *>(res)->_poke_exception();
  }
}  // namespace error_code_extended

extern error_code_extended::result<int> func2()
{
  using namespace error_code_extended;
  return result<int>(std::errc::operation_not_permitted);
}

extern error_code_extended::outcome<int> func1()
{
  return func2();
}

int main()
{
  try
  {
    using namespace error_code_extended;
    outcome<int> r = func1();
    r.value();
    std::cerr << "Unfortunately the extension of the local result<> type to track stack backtraces and keep custom messages did not work\n";
    std::cerr << "No exception was ever thrown!" << std::endl;
    return 1;
  }
  catch(const std::system_error &e)
  {
    std::cerr << "Unfortunately the extension of the local result<> type to track stack backtraces and keep custom messages did not work\n";
    std::cerr << "The exception thrown instead says:\n\n";
    std::cerr << e.what() << std::endl;
    return 1;
  }
  catch(const std::runtime_error &e)
  {
    std::cout << "The extension of the local result<> type to track stack backtraces and keep custom messages worked!\n";
    std::cout << "Here is the extended message which should include also a backtrace:\n\n";
    std::cout << e.what() << std::endl;
    return 0;
  }
  return 1;
}