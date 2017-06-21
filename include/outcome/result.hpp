#ifndef OUTCOME_RESULT_HPP
#define OUTCOME_RESULT_HPP

#include "error_code_extended.hpp"

#include <type_traits>
#include <utility>  // for in_place_type_t

#define QUICKCPPLIB_SYMBOL_VISIBLE

#if !defined(__cpp_exceptions) && defined(_CPPUNWIND)
#define __cpp_exceptions 1
#endif

namespace outcome
{
#if __cplusplus >= 201700
  template <class T> using in_place_type_t = std::in_place_type_t<T>;
  using std::in_place_type;
#else
  //! Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.
  template <class T> struct in_place_type_t
  {
    explicit in_place_type_t() = default;
  };
  //! Aliases `std::in_place_type<T>` if on C++ 17 or later, else defined locally.
  template <class T> constexpr in_place_type_t<T> in_place_type{};
#endif

  //! Thrown when you try to access state in a `result<T, EC>` which isn't present.
  class QUICKCPPLIB_SYMBOL_VISIBLE bad_result_access : public std::logic_error
  {
  public:
    bad_result_access(const char *what)
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
      constexpr value_storage_trivial(in_place_type_t<value_type>, Args &&... args) noexcept(noexcept(value_type(std::forward<Args>(args)...)))
          : _value(std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
      template <class U, class... Args>
      constexpr value_storage_trivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(value_type(il, std::forward<Args>(args)...)))
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
      value_storage_nontrivial(in_place_type_t<value_type>, Args &&... args) noexcept(noexcept(value_type(std::forward<Args>(args)...)))
          : _value(std::forward<Args>(args)...)
          , _status(status_have_value)
      {
      }
      template <class U, class... Args>
      value_storage_nontrivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(value_type(il, std::forward<Args>(args)...)))
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
  }

  namespace policy
  {
#ifdef __cpp_exceptions
    /*! Policy interpreting EC as a type to be thrown directly during wide checks.
    */
    template <class EC> struct throw_directly
    {
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
        if((self->_state._status & detail::status_have_value) == 0)
        {
          if((self->_state._status & detail::status_have_error) != 0)
          {
            throw self->_error;
          }
          throw bad_result_access("no value");
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          throw bad_result_access("no error");
        }
      }
    };
    /*! Policy interpreting EC as a type implementing the `std::error_code` contract
    and any wide attempt to access the successful state throws the `error_code` wrapped into
    a `std::system_error`
    */
    template <class EC> struct error_code_throw_as_system_error
    {
      static_assert(std::is_convertible<std::error_code, EC>::value, "error_type must be convertible into a std::error_code to be used with this policy");
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
        if((self->_state._status & detail::status_have_value) == 0)
        {
          if((self->_state._status & detail::status_have_error) != 0)
          {
            throw std::system_error(self->_error);
          }
          throw bad_result_access("no value");
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          throw bad_result_access("no error");
        }
      }
    };
    /*! Policy interpreting EC as a type implementing the `std::exception_ptr` contract
    and any wide attempt to access the successful state calls `std::rethrow_exception()`.
    */
    template <class EC> struct exception_ptr_rethrow
    {
      static_assert(std::is_convertible<std::exception_ptr, EC>::value, "error_type must be convertible into a std::exception_ptr to be used with this policy");
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
        if((self->_state._status & detail::status_have_value) == 0)
        {
          if((self->_state._status & detail::status_have_error) != 0)
          {
            std::rethrow_exception(self->_error);
          }
          throw bad_result_access("no value");
        }
      }
      //! Performs a wide check of state, used in the error() functions
      template <class Impl> static constexpr void wide_error_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          throw bad_result_access("no error");
        }
      }
    };
#endif
    /*! Policy implementing any wide attempt to access the successful state as calling `std::terminate`
    */
    template <class EC> struct terminate
    {
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

#ifdef __cpp_exceptions
    //! Default result policy selector
    template <class EC>
    using default_result_policy = std::conditional_t<                                         //
    std::is_void<EC>::value,                                                                  //
    terminate<EC>,                                                                            //
    std::conditional_t<                                                                       //
    std::is_constructible<std::error_code, EC>::value, error_code_throw_as_system_error<EC>,  //
    std::conditional_t<                                                                       //
    std::is_constructible<std::exception_ptr, EC>::value, exception_ptr_rethrow<EC>,          //
    throw_directly<EC>                                                                        //
    >>>;
#else
    template <class EC> using default_result_policy = terminate<EC>;
#endif
  }

  /*! The base implementation of `result<R, EC>`. You should not construct this directly.
  \see [result]()
  */
  template <class Impl, class R, class EC, class NoValuePolicy> class result_base
  {
    friend NoValuePolicy;

  public:
    /// \output_section Member types
    //! The result type.
    using value_type = R;
    //! The failure type.
    using error_type = EC;

  private:
    static_assert(std::is_default_constructible<error_type>::value, "error_type must be default constructible");
    static_assert(std::is_constructible<bool, error_type>::value, "error_type must implement boolean testability");

    struct value_converting_constructor_tag
    {
    };
    struct error_converting_constructor_tag
    {
    };
    struct value_error_converting_constructor_tag
    {
    };

  protected:
    detail::value_storage_select_impl<value_type> _state;
    error_type _error;

  public:
    /// \output_section Default, copy/move constructors and assignment
    //! Default construction is not permitted.
    result_base() = delete;
    //! Move construction available if `value_type` and `error_type` implement it.
    result_base(result_base && /*unused*/) = default;
    //! Copy construction available if `value_type` and `error_type` implement it.
    result_base(const result_base & /*unused*/) = default;
    //! Move assignment available if `value_type` and `error_type` implement it.
    result_base &operator=(result_base && /*unused*/) = default;
    //! Copy assignment available if `value_type` and `error_type` implement it.
    result_base &operator=(const result_base & /*unused*/) = default;

    /// \output_section Converting constructors
    /*! Converting constructor to a successful result.
    \param enable_value_converting_constructor
    \exclude
    \param 1
    \exclude
    \param t The value from which to initialise the `value_type`.
    \effects Initialises the result with a `value_type`.
    \requires Type T is constructible to `value_type`, is not constructible to `error_type`, and is not `result<R, EC>` and not `in_place_type<>`.
    \throws Any exception the move or copy construction of `value_type(T)` might throw.
    */
    template <class T, typename enable_value_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, Impl>::value                       // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && std::is_constructible<value_type, T>::value && !std::is_constructible<error_type, T>::value>>
    constexpr result_base(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(noexcept(value_type(std::forward<T>(t))))
        : _state(in_place_type<value_type>, std::forward<T>(t))
    {
    }
    //! Converting constructor to error_type
    template <class T, typename enable_error_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, Impl>::value                       // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && !std::is_constructible<value_type, T>::value && std::is_constructible<error_type, T>::value>>
    constexpr result_base(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(noexcept(error_type(std::forward<T>(t))))
        : _state(detail::status_have_error)
        , _error(std::forward<T>(t))
    {
    }
    //! Converting constructor to value_type + error_type
    template <class T, class U, typename enable_error_converting_constructor = std::enable_if_t<  //
                                !std::is_same<std::decay_t<T>, Impl>::value                       // not my type
                                && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                                && std::is_constructible<value_type, T>::value && !std::is_constructible<error_type, T>::value && std::is_constructible<error_type, U>::value && !std::is_constructible<value_type, U>::value>>
    constexpr result_base(T &&t, U &&u, value_error_converting_constructor_tag = value_error_converting_constructor_tag()) noexcept(noexcept(value_type(std::forward<T>(t))) && noexcept(error_type(std::forward<U>(u))))
        : _state(in_place_type<value_type>, std::forward<T>(t))
        , _error(std::forward<U>(u))
    {
      _state._status |= detail::status_have_error;
    }

    /// \output_section In place constructors
    //! In place constructor to value_type
    template <class... Args, typename = std::enable_if_t<std::is_void<value_type>::value || std::is_constructible<value_type, Args...>::value>>
    constexpr explicit result_base(in_place_type_t<value_type> _, Args &&... args) noexcept(noexcept(value_type(std::forward<Args>(args)...)))
        : _state(_, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to value_type
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<value_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit result_base(in_place_type_t<value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(value_type(il, std::forward<Args>(args)...)))
        : _state(_, il, std::forward<Args>(args)...)
    {
    }
    //! In place constructor to error_type
    template <class... Args, typename = std::enable_if_t<std::is_void<error_type>::value || std::is_constructible<error_type, Args...>::value>>
    constexpr explicit result_base(in_place_type_t<error_type>, Args &&... args) noexcept(noexcept(error_type(std::forward<Args>(args)...)))
        : _state(detail::status_have_error)
        , _error(std::forward<Args>(args)...)
    {
    }
    //! In place constructor to error_type
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<error_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit result_base(in_place_type_t<error_type>, std::initializer_list<U> il, Args &&... args) noexcept(noexcept(error_type(il, std::forward<Args>(args)...)))
        : _state(detail::status_have_error)
        , _error(il, std::forward<Args>(args)...)
    {
    }

    /// \output_section State check observers
    //! True if has value
    constexpr explicit operator bool() const noexcept { return (_state._status & detail::status_have_value) != 0; }
    //! True if has value
    constexpr bool has_value() const noexcept { return (_state._status & detail::status_have_value) != 0; }
    //! True if has error
    constexpr bool has_error() const noexcept { return (_state._status & detail::status_have_error) != 0; }
  };

  /*! Provides the result of a success, a success with additional information, or a failure.
  \group result
  \tparam R The type of the successful result.
  \tparam EC The type of the failure/info result.
  \requires Must be DefaultConstructible and BooleanTestable e.g. `if(ec)`
  \tparam NoValuePolicy Policy on how to interpret type `EC` when a wide observation of a not present value occurs.
  Default is:
  - If C++ exceptions are enabled:
      - If `EC` convertible to a `std::error_code`, `throw std::system_error(error())`.
      - If `EC` convertible to a `std::exception_ptr`, `std::rethrow_exception(error())`.
      - If `EC` is `void`, call `std::terminate()`.
      - Else `throw error()`.
  - If C++ exceptions are not enabled, call `std::terminate()`.
  */
  template <class R, class EC = error_code_extended, class NoValuePolicy = policy::default_result_policy<EC>> class result : public result_base<result<R, EC, NoValuePolicy>, R, EC, NoValuePolicy>
  {
  public:
    using value_type = R;
    using error_type = EC;
    using result_base<result<R, EC, NoValuePolicy>, R, EC, NoValuePolicy>::result_base;

    /// \output_section Narrow state observers
    /// \group assume_value
    //! Access value directly
    constexpr value_type &assume_value() & noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr const value_type &assume_value() const &noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr value_type &&assume_value() && noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr const value_type &&assume_value() const &&noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_error
    //! Access error directly
    constexpr error_type &assume_error() & noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &assume_error() const &noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr error_type &&assume_error() && noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &&assume_error() const &&noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }

    /// \output_section Wide state observers
    /// \group value
    //! Access value if no error
    constexpr value_type &value() &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr const value_type &value() const &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr value_type &&value() &&
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr const value_type &&value() const &&
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group error
    //! Access error
    constexpr error_type &error() &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr const error_type &error() const &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr error_type &&error() &&
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr const error_type &&error() const &&
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
  };

  //! \group result
  template <class NoValuePolicy> struct result<void, void, NoValuePolicy> : result_base<result<void, void, NoValuePolicy>, void, void, NoValuePolicy>
  {
  public:
    using value_type = void;
    using error_type = void;
    using result_base<result<void, void, NoValuePolicy>, void, void, NoValuePolicy>::result_base;

    /// \output_section Narrow state observers
    //! Access value directly
    constexpr void assume_value() noexcept { NoValuePolicy::narrow_value_check(this); }
    //! Access error directly
    constexpr void assume_error() noexcept { NoValuePolicy::narrow_error_check(this); }

    /// \output_section Wide state observers
    //! Access value if no error
    constexpr void value() { NoValuePolicy::wide_value_check(this); }
    //! Access error
    constexpr void error() { NoValuePolicy::wide_error_check(this); }
  };

  //! \group result
  template <class EC, class NoValuePolicy> class result<void, EC, NoValuePolicy> : public result_base<result<void, EC, NoValuePolicy>, void, EC, NoValuePolicy>
  {
  public:
    using value_type = void;
    using error_type = EC;
    using result_base<result<void, EC, NoValuePolicy>, void, EC, NoValuePolicy>::result_base;

    /// \output_section Narrow state observers
    /// \group assume_error
    //! Access error directly
    constexpr error_type &assume_error() & noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &assume_error() const &noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr error_type &&assume_error() && noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &&assume_error() const &&noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }

    /// \output_section Wide state observers
    /// \group error
    //! Access error
    constexpr error_type &error() &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr const error_type &error() const &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr error_type &&error() &&
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr const error_type &&error() const &&
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
  };

  //! \group result
  template <class R, class NoValuePolicy> struct result<R, void, NoValuePolicy> : public result_base<result<R, void, NoValuePolicy>, R, void, NoValuePolicy>
  {
  public:
    using value_type = R;
    using error_type = void;
    using result_base<result<R, void, NoValuePolicy>, R, void, NoValuePolicy>::result_base;

    /// \output_section Narrow state observers
    /// \group assume_value
    //! Access value directly
    constexpr value_type &assume_value() & noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr const value_type &assume_value() const &noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr value_type &&assume_value() && noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr const value_type &&assume_value() const &&noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }

    /// \output_section Wide state observers
    /// \group value
    //! Access value if no error
    constexpr value_type &value() &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr const value_type &value() const &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr value_type &&value() &&
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr const value_type &&value() const &&
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
  };
}
#endif
