#ifndef OUTCOME_OUTCOME_HPP
#define OUTCOME_OUTCOME_HPP

#include "result.hpp"

#include <exception>
#include <memory>

namespace outcome
{
  namespace policy
  {
#ifdef __cpp_exceptions
    /* \struct error_code_throw_as_system_error_exception_rethrow
    \brief Policy interpreting EC as a type implementing the `std::error_code` contract, E as
    a type implementing the `std::exception_ptr` contract, and any wide attempt to access the
    successful state throws the `exception_ptr` if available, then the `error_code` wrapped
    into a `std::system_error`
    */
    template <class EC, class E> struct error_code_throw_as_system_error_exception_rethrow
    {
      static_assert(std::is_convertible<std::error_code, EC>::value, "error_type must be convertible into a std::error_code to be used with this ECPolicy");
      static_assert(std::is_convertible<std::exception_ptr, E>::value, "exception_type must be convertible into a std::exception_ptr to be used with this ECPolicy");
      //! Returns true if errored
      template <class Impl> static constexpr bool is_errored(Impl *self) noexcept { return self->_error || self->_exception; }
      //! Performs a narrow check of state, used in the assume_value() functions
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if(self->_error || self->_exception)
          __builtin_unreachable();
#endif
      }
      //! Performs a narrow check of state, used in the assume_error() functions
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept { (void) self; }
      //! Performs a narrow check of state, used in the assume_exception() functions
      template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept { (void) self; }
      //! Performs a wide check of state, used in the value() functions
      template <class Impl> static constexpr void wide_value_check(Impl *self)
      {
        if(self->_exception)
        {
          std::rethrow_exception(self->_exception);
        }
        if(self->_error)
        {
          throw std::system_error(self->_error);
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self) noexcept { (void) self; }
      //! Performs a wide check of state, used in the exception() functions
      template <class Impl> static constexpr void wide_exception_check(Impl *self) noexcept { (void) self; }
    };
#endif
    /* \struct error_code_exception_terminate
    \brief Policy interpreting EC as a type implementing the `std::error_code` contract, E as
    a type implementing the `std::exception_ptr` contract, and any wide attempt to access the
    successful state calls `std::terminate`.
    */
    template <class EC, class E> struct error_code_exception_terminate
    {
      static_assert(std::is_convertible<std::error_code, EC>::value, "error_type must be convertible into a std::error_code to be used with this ECPolicy");
      static_assert(std::is_convertible<std::exception_ptr, E>::value, "exception_type must be convertible into a std::exception_ptr to be used with this ECPolicy");
      //! Returns true if errored
      template <class Impl> static constexpr bool is_errored(Impl *self) noexcept { return self->_error || self->_exception; }
      //! Performs a narrow check of state, used in the assume_value() functions
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if(self->_error || self->_exception)
          __builtin_unreachable();
#endif
      }
      //! Performs a narrow check of state, used in the assume_error() functions
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept { (void) self; }
      //! Performs a narrow check of state, used in the assume_exception() functions
      template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept { (void) self; }
      //! Performs a wide check of state, used in the value() functions
      template <class Impl> static constexpr void wide_value_check(Impl *self)
      {
        if(self->_exception)
        {
          std::terminate();
        }
        if(self->_error)
        {
          std::terminate();
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self) noexcept { (void) self; }
      //! Performs a wide check of state, used in the exception() functions
      template <class Impl> static constexpr void wide_exception_check(Impl *self) noexcept { (void) self; }
    };
  }

  /*| \class outcome
  \brief Provides the outcome of a success and/or a failure with optional additional payload
  \tparam R The type of the successful result. Needs to be DefaultConstructible.
  \tparam P The type of the optional payload carryable. Needs to be DefaultConstructible and be boolean testable e.g. `if(p)`
  \tparam EC The type of the coded failure result. Needs to be DefaultConstructible and be boolean testable e.g. `if(ec)`
  \tparam E The type of the uncoded failure result. Needs to be DefaultConstructible and be boolean testable e.g. `if(e)`
  \tparam ECEPolicy Policy on how to interpret types EC and E.
  */
  template <class R,                          //
            class P = std::shared_ptr<void>,  //
            class EC = error_code_extended,   //
            class E = std::exception_ptr,     //
            class ECEPolicy =
#ifdef __cpp_exceptions
            policy::error_code_throw_as_system_error_exception_rethrow<EC, E>
#else
            policy::error_code_exception_terminate<EC, E>
#endif
            >
  class outcome : private result<T, EC, ECEPolicy>
  {
    friend ECPolicy;
    using base = result<T, EC, ECEPolicy>;
    static_assert(std::is_default_constructible<P>::value, "payload_type must be default constructible");
    static_assert(std::is_constructible<bool, P>::value, "payload_type must implement boolean testability");
    static_assert(std::is_default_constructible<E>::value, "exception_type must be default constructible");
    static_assert(std::is_constructible<bool, E>::value, "exception_type must implement boolean testability");

  public:
    //! The result type
    using value_type = R;
    //! The coded failure type
    using error_type = EC;
    //! The uncoded failure type
    using exception_type = E;
    //! The payload type
    using payload_type = P;

  private:
    exception_type _exception;
    payload_type _payload;

    struct result_converting_constructor_tag
    {
    };
    struct exception_converting_constructor_tag
    {
    };

  public:
    //! Default constructor
    outcome() = default;
    //! Move constructor
    outcome(outcome && /*unused*/) = default;
    //! Copy constructor
    outcome(const outcome & /*unused*/) = default;
    //! Move assignment
    outcome &operator=(outcome && /*unused*/) = default;
    //! Copy assignment
    outcome &operator=(const outcome & /*unused*/) = default;

    //! \brief Explicit construction from compatible result<_T, _EC>
    template <class _T, class _EC, class _ECPolicy>
    explicit constexpr outcome(result<_T, _EC, _ECPolicy> &&o)
        : base(std::move(o))
    {
    }
    //! \brief Explicit construction from compatible result<_T, _EC>
    template <class _T, class _EC, class _ECPolicy>
    explicit constexpr outcome(const result<_T, _EC, _ECPolicy> &o)
        : base(o)
    {
    }

    //! Converting constructor to result<value_type, error_type>
    template <class T, typename enable_value_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && std::is_constructible<base, T>::value && !std::is_constructible<exception_type, T>::value>>
    constexpr outcome(T &&t, result_converting_constructor_tag = result_converting_constructor_tag()) noexcept(noexcept(base(std::forward<T>(t))))
        : base(std::forward<T>(t))
    {
    }
    //! Converting constructor to exception_type
    template <class T, typename enable_error_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && !std::is_constructible<base, T>::value && std::is_constructible<exception_type, T>::value>>
    constexpr outcome(T &&t, exception_converting_constructor_tag = exception_converting_constructor_tag()) noexcept(noexcept(exception_type(std::forward<T>(t))))
        : _exception(std::forward<T>(t))
    {
    }
    //! In place constructor to value_type
    template <class... Args, typename = std::enable_if_t<std::is_constructible<value_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<value_type> _, Args &&... args) noexcept(noexcept(base(_, std::forward<Args>(args)...)))
        : base(_, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to value_type
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<value_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(base(_, il, std::forward<Args>(args)...)))
        : base(_, il, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to error_type
    template <class... Args, typename = std::enable_if_t<std::is_constructible<error_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<error_type> _, Args &&... args) noexcept(noexcept(base(_, std::forward<Args>(args)...)))
        : base(_, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to error_type
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<error_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<error_type> _, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(base(_, il, std::forward<Args>(args)...)))
        : base(_, il, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to exception_type
    template <class... Args, typename = std::enable_if_t<std::is_constructible<exception_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<exception_type>, Args &&... args) noexcept(noexcept(exception_type(std::forward<Args>(args)...)))
        : _exception(std::forward<Args>(args)...)
    {
    }
    //! In place constructor to exception_type
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<exception_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<exception_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(exception_type(il, std::forward<Args>(args)...)))
        : _exception(il, std::forward<Args>(args)...)
    {
    }

    using base::operator bool();
    using base::has_value;
    using base::has_error;

    using base::assume_value;
    using base::assume_error;
    E &assume_exception() noexcept;
    P &assume_payload() noexcept;

    // Wide observers
    using base::value;
    using base::error;
    E exception();
    P payload();
    // Returns exception state, but if errored, synthesises
    // an exception_ptr of the error code
    E failure();
  };
}

#endif
