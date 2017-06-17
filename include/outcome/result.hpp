#ifndef OUTCOME_RESULT_HPP
#define OUTCOME_RESULT_HPP

#include "error_code_extended.hpp"

#include <type_traits>
#include <utility>  // for in_place_type_t

#define QUICKCPPLIB_SYMBOL_VISIBLE

namespace outcome
{
#if __cplusplus >= 201700
  template <class T> using in_place_type_t = std::in_place_type_t<T>;
  using std::in_place_type;
#else
  template <class T> struct in_place_type_t
  {
    explicit in_place_type_t() = default;
  };
  template <class T> constexpr in_place_type_t<T> in_place_type{};
#endif

  class QUICKCPPLIB_SYMBOL_VISIBLE bad_result : public std::logic_error
  {
  public:
    bad_result(const char *what)
        : std::logic_error(what)
    {
    }
  };

  namespace detail
  {
    template <class T> struct is_in_place_type_t : std::false_type
    {
    };
    template <class U> struct is_in_place_type_t<in_place_type_t<U>> : std::true_type
    {
    };

    struct empty_type
    {
    };
    struct void_type
    {
    };
    template <class T> using devoid = std::conditional_t<std::is_void<T>::value, void_type, T>;

    using status_bitfield_type = uint32_t;
    static constexpr status_bitfield_type status_have_value = (1 << 0);
    static constexpr status_bitfield_type status_have_error = (1 << 1);
    static constexpr status_bitfield_type status_result_last = (1 << 2);

    // Used if T is trivial
    template <class T> struct value_storage_trivial
    {
      using value_type = T;
      union {
        empty_type _empty;
        devoid<T> _value;
      };
      status_bitfield_type _status;
      constexpr value_storage_trivial() noexcept : _empty{}, _status(0) {}
      constexpr explicit value_storage_trivial(status_bitfield_type status)
          : _empty()
          , _status(status)
      {
      }
      template <class... Args>
      constexpr value_storage_trivial(in_place_type_t<value_type>, Args &&... args) noexcept(noexcept(T(std::forward<Args>(args)...)))
          : _value(std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
      template <class U, class... Args>
      constexpr value_storage_trivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(T(il, std::forward<Args>(args)...)))
          : _value(il, std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
    };
    // Used if T is non-trivial
    template <class T> struct value_storage_nontrivial
    {
      using value_type = T;
      union {
        empty_type _empty;
        value_type _value;
      };
      status_bitfield_type _status;
      value_storage_nontrivial() noexcept : _empty{}, _status(0) {}
      value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value)
          : value_storage_nontrivial()
      {
        if(this->_status & status_have_value)
        {
          new(&_value) value_type(std::move(o._value));
          _status = o._status;
        }
      }
      value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
          : value_storage_nontrivial()
      {
        if(this->_status & status_have_value)
        {
          new(&_value) value_type(o._value);
          _status = o._status;
        }
      }
      explicit value_storage_nontrivial(status_bitfield_type status)
          : _empty()
          , _status(status)
      {
      }
      template <class... Args>
      value_storage_nontrivial(in_place_type_t<value_type>, Args &&... args) noexcept(noexcept(T(std::forward<Args>(args)...)))
          : _value(std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
      template <class U, class... Args>
      value_storage_nontrivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(T(il, std::forward<Args>(args)...)))
          : _value(il, std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
      ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
      {
        if(this->_status & status_have_value)
        {
          this->_value.~T();
          this->_status &= ~status_have_value;
        }
      }
    };
    template <class Base> struct value_storage_delete_copy_constructor : Base
    {
      using Base::Base;
      using value_type = typename Base::value_type;
      value_storage_delete_copy_constructor() = default;
      value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
      value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default;
    };
    template <class Base> struct value_storage_delete_move_constructor : Base
    {
      using Base::Base;
      using value_type = typename Base::value_type;
      value_storage_delete_move_constructor() = default;
      value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
      value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
    };
    template <class Base> struct value_storage_nontrivial_move_assignment : Base
    {
      using Base::Base;
      using value_type = typename Base::value_type;
      value_storage_nontrivial_move_assignment() = default;
      value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
      value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default;
      value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
      value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value)
      {
        if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
        {
          this->_value = std::move(o._value);
        }
        else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
        {
          this->_value.~value_type();
        }
        else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
        {
          new(&this->_value) value_type(std::move(o._value));
        }
        this->_status = o._status;
        return *this;
      }
    };
    template <class Base> struct value_storage_nontrivial_copy_assignment : Base
    {
      using Base::Base;
      using value_type = typename Base::value_type;
      value_storage_nontrivial_copy_assignment() = default;
      value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
      value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default;
      value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default;
      value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
      {
        if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
        {
          this->_value = o._value;
        }
        else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
        {
          this->_value.~value_type();
        }
        else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
        {
          new(&this->_value) value_type(o._value);
        }
        this->_status = o._status;
        return *this;
      }
    };
    template <class T> using value_storage_select_trivality = std::conditional_t<std::is_trivial<devoid<T>>::value, value_storage_trivial<T>, value_storage_nontrivial<T>>;
    template <class T> using value_storage_select_move_constructor = std::conditional_t<std::is_move_constructible<devoid<T>>::value, value_storage_select_trivality<T>, value_storage_delete_move_constructor<value_storage_select_trivality<T>>>;
    template <class T> using value_storage_select_copy_constructor = std::conditional_t<std::is_copy_constructible<devoid<T>>::value, value_storage_select_move_constructor<T>, value_storage_delete_copy_constructor<value_storage_select_move_constructor<T>>>;
    template <class T> using value_storage_select_move_assignment = std::conditional_t<!std::is_move_assignable<devoid<T>>::value || std::is_trivially_move_assignable<devoid<T>>::value, value_storage_select_copy_constructor<T>, value_storage_nontrivial_move_assignment<value_storage_select_copy_constructor<T>>>;
    template <class T> using value_storage_select_copy_assignment = std::conditional_t<!std::is_copy_assignable<devoid<T>>::value || std::is_trivially_copy_assignable<devoid<T>>::value, value_storage_select_move_assignment<T>, value_storage_nontrivial_copy_assignment<value_storage_select_move_assignment<T>>>;
    template <class T> using value_storage_select_impl = value_storage_select_copy_assignment<T>;

    template <class R, class EC, class ECPolicy> struct result_impl_base
    {
      friend ECPolicy;
      static_assert(std::is_default_constructible<EC>::value, "error_type must be default constructible");
      static_assert(std::is_constructible<bool, EC>::value, "error_type must implement boolean testability");

      using value_type = R;
      using error_type = EC;

    protected:
      detail::value_storage_select_impl<value_type> _state;
      error_type _error;

    public:
      //! Default constructor
      result_impl_base() = default;
      //! Move constructor
      result_impl_base(result_impl_base && /*unused*/) = default;
      //! Copy constructor
      result_impl_base(const result_impl_base & /*unused*/) = default;
      //! Move assignment
      result_impl_base &operator=(result_impl_base && /*unused*/) = default;
      //! Copy assignment
      result_impl_base &operator=(const result_impl_base & /*unused*/) = default;

      //! In place constructor to value_type
      template <class... Args, typename = std::enable_if_t<std::is_void<value_type>::value || std::is_constructible<value_type, Args...>::value>>
      constexpr explicit result_impl_base(in_place_type_t<value_type> _, Args &&... args) noexcept(noexcept(value_type(std::forward<Args>(args)...)))
          : _state(_, std::forward<Args>(args)...)
      {
      }
      //! In place constructor to value_type
      template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<value_type, std::initializer_list<U>, Args...>::value>>
      constexpr explicit result_impl_base(in_place_type_t<value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(value_type(il, std::forward<Args>(args)...)))
          : _state(_, il, std::forward<Args>(args)...)
      {
      }
      //! In place constructor to error_type
      template <class... Args, typename = std::enable_if_t<std::is_void<error_type>::value || std::is_constructible<error_type, Args...>::value>>
      constexpr explicit result_impl_base(in_place_type_t<error_type>, Args &&... args) noexcept(noexcept(error_type(std::forward<Args>(args)...)))
          : _state(detail::status_have_error)
          , _error(std::forward<Args>(args)...)
      {
      }
      //! In place constructor to error_type
      template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<error_type, std::initializer_list<U>, Args...>::value>>
      constexpr explicit result_impl_base(in_place_type_t<error_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(error_type(il, std::forward<Args>(args)...)))
          : _state(detail::status_have_error)
          , _error(il, std::forward<Args>(args)...)
      {
      }
    };
    template <class R, class EC, class ECPolicy> struct result_impl : result_impl_base<R, EC, ECPolicy>
    {
      using value_type = R;
      using error_type = EC;
      using result_impl_base<R, EC, ECPolicy>::result_impl_base;

      //! Access value directly
      value_type &assume_value() & noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      const value_type &assume_value() const &noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      value_type &&assume_value() && noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      const value_type &&assume_value() const &&noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      //! Access error directly
      error_type &assume_error() & noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      const error_type &assume_error() const &noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      error_type &&assume_error() && noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      const error_type &&assume_error() const &&noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }

      //! Access value if no error
      value_type &value() &
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      const value_type &value() const &
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      value_type &&value() &&
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      const value_type &&value() const &&
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      //! Access error
      error_type &error() &
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      const error_type &error() const &
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      error_type &&error() &&
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      const error_type &&error() const &&
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
    };
    template <class EC, class ECPolicy> struct result_impl<void, EC, ECPolicy> : result_impl_base<void, EC, ECPolicy>
    {
      using value_type = void;
      using error_type = EC;
      using result_impl_base<void, EC, ECPolicy>::result_impl_base;

      //! Access value directly
      void assume_value() noexcept { ECPolicy::narrow_value_check(this); }
      //! Access error directly
      error_type &assume_error() & noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      const error_type &assume_error() const &noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      error_type &&assume_error() && noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }
      const error_type &&assume_error() const &&noexcept
      {
        ECPolicy::narrow_error_check(this);
        return this->_error;
      }

      //! Access value if no error
      void value() { ECPolicy::wide_value_check(this); }
      //! Access error
      error_type &error() &
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      const error_type &error() const &
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      error_type &&error() &&
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
      const error_type &&error() const &&
      {
        ECPolicy::wide_error_check(this);
        return this->_error;
      }
    };
    template <class R, class ECPolicy> struct result_impl<R, void, ECPolicy> : result_impl_base<R, void, ECPolicy>
    {
      using value_type = R;
      using error_type = void;
      using result_impl_base<R, void, ECPolicy>::result_impl_base;

      //! Access value directly
      value_type &assume_value() & noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      const value_type &assume_value() const &noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      value_type &&assume_value() && noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      const value_type &&assume_value() const &&noexcept
      {
        ECPolicy::narrow_value_check(this);
        return this->_state._value;
      }
      //! Access error directly
      void assume_error() noexcept { ECPolicy::narrow_error_check(this); }

      //! Access value if no error
      value_type &value() &
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      const value_type &value() const &
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      value_type &&value() &&
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      const value_type &&value() const &&
      {
        ECPolicy::wide_value_check(this);
        return this->_state._value;
      }
      //! Access error
      void error() { ECPolicy::wide_error_check(this); }
    };
    template <class ECPolicy> struct result_impl<void, void, ECPolicy> : result_impl_base<void, void, ECPolicy>
    {
      using value_type = void;
      using error_type = void;
      using result_impl_base<void, void, ECPolicy>::result_impl_base;

      //! Access value directly
      void assume_value() noexcept { ECPolicy::narrow_value_check(this); }
      //! Access error directly
      void assume_error() noexcept { ECPolicy::narrow_error_check(this); }

      //! Access value if no error
      void value() { ECPolicy::wide_value_check(this); }
      //! Access error
      void error() { ECPolicy::wide_error_check(this); }
    };
  }

  namespace policy
  {
#ifdef __cpp_exceptions
    /* \struct error_code_throw_as_system_error
    \brief Policy interpreting EC as a type implementing the `std::error_code` contract
    and any wide attempt to access the successful state throws the `error_code` wrapped into
    a `std::system_error`
    */
    template <class EC> struct error_code_throw_as_system_error
    {
      static_assert(std::is_convertible<std::error_code, EC>::value, "error_type must be convertible into a std::error_code to be used with this ECPolicy");
      //! Performs a narrow check of state, used in the assume_value() functions
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_value) == 0)
          __builtin_unreachable();
#endif
      }
      //! Performs a narrow check of state, used in the assume_error() functions
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_error) == 0)
          __builtin_unreachable();
#endif
      }
      //! Performs a wide check of state, used in the value() functions
      template <class Impl> static constexpr void wide_value_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) != 0)
        {
          throw std::system_error(self->_error);
        }
        if((self->_state._status & detail::status_have_value) == 0)
        {
          throw bad_result("no value");
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          throw bad_result("no error");
        }
      }
    };
#endif
    /* \struct error_code_terminate
    \brief Policy interpreting EC as a type implementing the `std::error_code` contract
    and any wide attempt to access the successful state calls `std::terminate`
    */
    template <class EC> struct error_code_terminate
    {
      static_assert(std::is_convertible<std::error_code, EC>::value, "error_type must be convertible into a std::error_code to be used with this ECPolicy");
      //! Performs a narrow check of state, used in the assume_value() functions
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_value) == 0)
          __builtin_unreachable();
#endif
      }
      //! Performs a narrow check of state, used in the assume_error() functions
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_error) == 0)
          __builtin_unreachable();
#endif
      }
      //! Performs a wide check of state, used in the value() functions
      template <class Impl> static constexpr void wide_value_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) != 0)
        {
          std::terminate();
        }
        if((self->_state._status & detail::status_have_value) == 0)
        {
          std::terminate();
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self) noexcept
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          std::terminate();
        }
      }
    };
  }

  /* \class result
  \brief Provides the result of a success and/or a failure
  \tparam R The type of the successful result.
  \tparam EC The type of the failure result. Needs to be DefaultConstructible and be boolean testable e.g. `if(ec)`
  \tparam ECPolicy Policy on how to interpret type EC.
  */
  template <class R, class EC = error_code_extended, class ECPolicy =
#ifdef __cpp_exceptions
                                                     policy::error_code_throw_as_system_error<EC>
#else
                                                     policy::error_code_terminate<EC>
#endif
            >
  class result : public detail::result_impl<R, EC, ECPolicy>
  {
    friend ECPolicy;
    using base = detail::result_impl<R, EC, ECPolicy>;
    struct value_converting_constructor_tag
    {
    };
    struct error_converting_constructor_tag
    {
    };

  public:
    //! The result type
    using value_type = R;
    //! The failure type
    using error_type = EC;

    //! Default constructor
    result() = delete;
    //! Move constructor
    result(result && /*unused*/) = default;
    //! Copy constructor
    result(const result & /*unused*/) = default;
    //! Move assignment
    result &operator=(result && /*unused*/) = default;
    //! Copy assignment
    result &operator=(const result & /*unused*/) = default;
    using base::base;

    //! Converting constructor to value_type
    template <class T, typename enable_value_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, result>::value                     // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && std::is_constructible<value_type, T>::value && !std::is_constructible<error_type, T>::value>>
    constexpr result(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(noexcept(value_type(std::forward<T>(t))))
        : base(in_place_type<value_type>, std::forward<T>(t))
    {
    }
    //! Converting constructor to error_type
    template <class T, typename enable_error_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, result>::value                     // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && !std::is_constructible<value_type, T>::value && std::is_constructible<error_type, T>::value>>
    constexpr result(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(noexcept(error_type(std::forward<T>(t))))
        : base(in_place_type<error_type>, std::forward<T>(t))
    {
    }

    //! True if has value
    constexpr explicit operator bool() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    //! True if has value
    constexpr bool has_value() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    //! True if has error
    constexpr bool has_error() const noexcept { return (this->_state._status & detail::status_have_error) != 0; }
  };
}
#endif
