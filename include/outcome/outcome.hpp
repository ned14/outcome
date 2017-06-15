#ifndef OUTCOME_OUTCOME_HPP
#define OUTCOME_OUTCOME_HPP

#include "result.hpp"

#include <exception>
#include <memory>

namespace outcome
{
  template <class T, class P = std::shared_ptr<void>, class EC = error_code_extended, class E = std::exception_ptr> class outcome : private result<T, EC>
  {
    using base = result<T, EC>;
    union {
      P _payload;    // 16 bytes
      E _exception;  //  8 bytes
    };

  public:
    // Constructors to be inspired by std::variant's

    // Explicit construction from compatible result<_T, _EC>
    template <class _T, class _EC> explicit outcome(result<_T, _EC>);

    // Narrow observers
    using base::access_value;
    using base::access_error;
    P &access_payload() noexcept;
    E &access_exception() noexcept;

    // Wide observers
    using base::value;
    using base::error;
    P payload();
    E exception();
    // Returns exception state, but if errored, synthesises
    // an exception_ptr of the error code
    E failure();
  };
}

#endif
