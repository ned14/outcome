/* Configures basic_monad as an option<T>, result<T> and outcome<T>.
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (12 commits)
File Created: July 2015


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

#ifndef BOOST_OUTCOME_MONAD_NAME
#error BOOST_OUTCOME_MONAD_NAME needs to be defined
#endif
#define BOOST_OUTCOME_GLUE2(a, b) a##b
#define BOOST_OUTCOME_GLUE(a, b) BOOST_OUTCOME_GLUE2(a, b)
#ifndef BOOST_OUTCOME_MONAD_POLICY_NAME
#define BOOST_OUTCOME_MONAD_POLICY_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy)
#endif
#ifndef BOOST_OUTCOME_MONAD_POLICY_BASE_NAME
#define BOOST_OUTCOME_MONAD_POLICY_BASE_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy_base)
#endif

namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)  // forcing value to bool
#pragma warning(disable : 4702)  // unreachable code
#endif
  //! \brief outcome<T>, result<T> and option<T> personalisation of basic_monad
  template <class monad_storage, class value_type, class error_type = void, class exception_type = void> struct BOOST_OUTCOME_MONAD_POLICY_BASE_NAME : public monad_storage
  {
  protected:
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME() = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(const BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &) = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &&) = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &operator=(const BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &) = default;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &operator=(BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // Must handle error situation ec. Can return false to cancel the calling operation.
    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);
#if defined(BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE) || defined(BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE)
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));
#endif
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
#endif
    }
    // If storage is packed into a byte, it cannot be referenced
    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:
    //! \brief Returns a pointer to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }
    //! \brief Returns a pointer to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> ()
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }

    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    //! \brief Returns a reference to any value in the transport, throwing an exception if none present
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
    //! \brief Returns any errored state in the transport, throwing an exception if empty
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
      if(monad_storage::has_exception())
        return error_type((int) bad_outcome_errc::exception_present, bad_outcome_category());
#endif
      return error_type();
    }
    //! \brief Returns any errored state in the transport, throwing an exception if empty
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }
    //! \brief Disposes of any existing state, setting the monad to the error_type
    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }
#endif
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
    //! \brief Returns any excepted state in the transport, throwing an exception if empty
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type get_exception() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return exception_type();
      }
      if(!monad_storage::has_error() && !monad_storage::has_exception())
        return exception_type();
      if(monad_storage::has_error())
        return std::make_exception_ptr(stl11::system_error(monad_storage::_storage.error));
      if(monad_storage::has_exception())
        return monad_storage::_storage.exception;
      return exception_type();
    }
    //! \brief Returns any excepted state in the transport, throwing an exception if empty
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type exception() const { return get_exception(); }
    //! \brief If contains an exception_type, returns that exception_type else returns the exception_type supplied
    BOOST_OUTCOME_CONSTEXPR exception_type exception_or(exception_type e) const noexcept { return monad_storage::has_exception() ? monad_storage::_storage.exception : std::move(e); }
    //! \brief Disposes of any existing state, setting the monad to the exception_type
    BOOST_OUTCOME_CONSTEXPR void set_exception(exception_type v) { monad_storage::_storage.emplace_exception(std::move(v)); }
    //! \brief Disposes of any existing state, setting the monad to make_exception_type(forward<E>(e))
    template <typename E, typename = typename std::enable_if<std::is_same<E, E>::value && !std::is_void<exception_type>::value>::type> BOOST_OUTCOME_CONSTEXPR void set_exception(E &&e) { set_exception(make_exception_type(std::forward<E>(e))); }
#endif
  };
  template <class monad_storage, class error_type, class exception_type> struct BOOST_OUTCOME_MONAD_POLICY_BASE_NAME<monad_storage, void, error_type, exception_type> : public monad_storage
  {
  protected:
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME() = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(const BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &) = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &&) = delete;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &operator=(const BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &) = default;
    BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &operator=(BOOST_OUTCOME_MONAD_POLICY_BASE_NAME &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr BOOST_OUTCOME_MONAD_POLICY_BASE_NAME(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // Must handle error situation ec. Can return false to cancel the calling operation.
    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);
#if defined(BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE) || defined(BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE)
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));
#endif
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
#endif
    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
      if(monad_storage::has_exception())
        return error_type((int) bad_outcome_errc::exception_present, bad_outcome_category());
#endif
      return error_type();
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }
    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }
    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }
#endif
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type get_exception() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return exception_type();
      }
      if(!monad_storage::has_error() && !monad_storage::has_exception())
        return exception_type();
      if(monad_storage::has_error())
        return std::make_exception_ptr(stl11::system_error(monad_storage::_storage.error));
      if(monad_storage::has_exception())
        return monad_storage::_storage.exception;
      return exception_type();
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type exception() const { return get_exception(); }
    BOOST_OUTCOME_CONSTEXPR exception_type exception_or(exception_type e) const noexcept { return monad_storage::has_exception() ? monad_storage::_storage.exception : std::move(e); }
    BOOST_OUTCOME_CONSTEXPR void set_exception(exception_type v) { monad_storage::_storage.emplace_exception(std::move(v)); }
    template <typename E, typename = typename std::enable_if<std::is_same<E, E>::value && !std::is_void<exception_type>::value>::type> BOOST_OUTCOME_CONSTEXPR void set_exception(E &&e) { set_exception(make_exception_type(std::forward<E>(e))); }
#endif
  };

  //! \brief An implementation policy for basic_monad implementing outcome<T>, result<T> and option<T>
  template <typename R> struct BOOST_OUTCOME_MONAD_POLICY_NAME
  {
    // The final resulting implementation type
    typedef basic_monad<BOOST_OUTCOME_MONAD_POLICY_NAME> implementation_type;
    // The value type to use. Can be void to disable.
    typedef R value_type;
// The error code type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
    typedef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE error_type;
#else
    typedef void error_type;
#endif
// The exception pointer type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif

    // Ought the monad be default constructible?
    static constexpr bool is_default_constructible = true;
    // Is default construction non-throwing?
    static constexpr bool is_nothrow_default_constructible = true;

    // The base class to use to store state
    typedef BOOST_OUTCOME_MONAD_POLICY_BASE_NAME<basic_monad_storage<BOOST_OUTCOME_MONAD_POLICY_NAME>, value_type, error_type, exception_type> base;

    // The type which basic_monad::rebind<U> should return
    template <typename U> using rebind = basic_monad<BOOST_OUTCOME_MONAD_POLICY_NAME<U>>;
    // The type which rebinding myself produces
    template <typename U> using rebind_policy = BOOST_OUTCOME_MONAD_POLICY_NAME<U>;
  };
  template <> struct BOOST_OUTCOME_MONAD_POLICY_NAME<void>
  {
    // The final resulting implementation type
    typedef basic_monad<BOOST_OUTCOME_MONAD_POLICY_NAME> implementation_type;
    // The value type to use. Can be void to disable.
    typedef void value_type;
// The error code type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
    typedef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE error_type;
#else
    typedef void error_type;
#endif
// The exception pointer type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif

    // Ought the monad be default constructible?
    static constexpr bool is_default_constructible = true;
    // Is default construction non-throwing?
    static constexpr bool is_nothrow_default_constructible = true;

    // The base class to use to store state
    typedef BOOST_OUTCOME_MONAD_POLICY_BASE_NAME<basic_monad_storage<BOOST_OUTCOME_MONAD_POLICY_NAME>, value_type, error_type, exception_type> base;

    // The type which basic_monad::rebind<U> should return
    template <typename U> using rebind = basic_monad<BOOST_OUTCOME_MONAD_POLICY_NAME<U>>;
    // The type which rebinding myself produces
    template <typename U> using rebind_policy = BOOST_OUTCOME_MONAD_POLICY_NAME<U>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}

#undef BOOST_OUTCOME_GLUE
#undef BOOST_OUTCOME_GLUE2
#undef BOOST_OUTCOME_PROMISE_NAME
#undef BOOST_OUTCOME_MONAD_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
#undef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
