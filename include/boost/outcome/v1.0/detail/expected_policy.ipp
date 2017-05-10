/* Configures basic_monad as a LEWG expected<T, E> implementation
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (10 commits)
File Created: Jan 2017


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

namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)  // forcing value to bool
#pragma warning(disable : 4702)  // unreachable code
#endif
  //! \brief expected<R, EC> personalisation of basic_monad
  template <class monad_storage, class value_type, class error_type> struct expected_policy_base : public monad_storage
  {
    static_assert(!std::is_constructible<value_type, error_type>::value, "value_type cannot be constructible from error_type (Outcome requirement)");
    static_assert(!std::is_constructible<error_type, value_type>::value, "error_type cannot be constructible from value_type (Outcome requirement)");
    static_assert(std::is_default_constructible<value_type>::value, "value_type must be default constructible (LEWG Expected requirement)");
    static_assert(std::is_void<error_type>::value || std::is_nothrow_copy_constructible<error_type>::value, "error_type must be nothrow copy constructible (LEWG Expected requirement)");
    static_assert(std::is_void<error_type>::value || std::is_nothrow_move_constructible<error_type>::value, "error_type must be nothrow move constructible (LEWG Expected requirement)");

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // expected's default constructor constructs a value_type
    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }
    // If storage is packed into a byte, it cannot be referenced
    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:
    //! \brief Returns a pointer to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const { return &monad_storage::_storage.value; }
    //! \brief Returns a pointer to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> () { return &monad_storage::_storage.value; }

    //! \brief Returns a reference to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() & { return monad_storage::_storage.value; }
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
    //! \brief Returns a reference to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const & { return monad_storage::_storage.value; }
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
    //! \brief Returns a reference to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
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
    //! \brief Returns a reference to any value in the transport \warning Same as `reinterpret_cast<value_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
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

    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &get_error() & { return monad_storage::_storage.error; }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &error() & { return monad_storage::_storage.error; }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR error_type &get_error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR error_type &error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_error() const & { return monad_storage::_storage.error; }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &error() const & { return monad_storage::_storage.error; }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR const error_type &get_error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR const error_type &error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&get_error() && { return std::move(monad_storage::_storage.error); }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&error() && { return std::move(monad_storage::_storage.error); }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR error_type &&get_error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR error_type &&error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&get_error() const && { return std::move(monad_storage::_storage.error); }
    //! \brief Returns any errored state in the transport \warning Same as `reinterpret_cast<error_type>`, no check for valued state is performed.
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&error() const && { return std::move(monad_storage::_storage.error); }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR const error_type &&get_error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    //! \brief If contains an error_type, returns that error_type else returns the error_type supplied
    BOOST_OUTCOME_CONSTEXPR const error_type &&error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }

    //! \brief As if make_unexpected<E>(this->error())
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_unexpected() const { return get_error(); }
  };
  // Specialisation for T = void
  template <class monad_storage, class error_type> struct expected_policy_base_valueless : public monad_storage
  {
    static_assert(std::is_void<error_type>::value || std::is_nothrow_copy_constructible<error_type>::value, "error_type must be nothrow copy constructible (LEWG Expected requirement)");
    static_assert(std::is_void<error_type>::value || std::is_nothrow_move_constructible<error_type>::value, "error_type must be nothrow move constructible (LEWG Expected requirement)");

  protected:
    expected_policy_base_valueless() = delete;
    expected_policy_base_valueless(const expected_policy_base_valueless &) = delete;
    expected_policy_base_valueless(expected_policy_base_valueless &&) = delete;
    expected_policy_base_valueless &operator=(const expected_policy_base_valueless &) = default;
    expected_policy_base_valueless &operator=(expected_policy_base_valueless &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base_valueless(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // expected's default constructor constructs a value_type
    constexpr expected_policy_base_valueless(passthru_t)
        : monad_storage(value_t())
    {
    }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &get_error() & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &error() & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR error_type &get_error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR error_type &error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_error() const & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &error() const & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR const error_type &get_error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR const error_type &error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&get_error() && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&error() && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR error_type &&get_error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    BOOST_OUTCOME_CONSTEXPR error_type &&error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&get_error() const && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&error() const && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR const error_type &&get_error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    BOOST_OUTCOME_CONSTEXPR const error_type &&error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_unexpected() const { return get_error(); }
  };
  // Specialisation for E = void
  template <class monad_storage, class value_type> struct expected_policy_base<monad_storage, value_type, void> : public monad_storage
  {
    static_assert(std::is_default_constructible<value_type>::value, "value_type must be default constructible (LEWG Expected requirement)");

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // expected's default constructor constructs a value_type
    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }
    // If storage is packed into a byte, it cannot be referenced
    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const { return &monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> () { return &monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() & { return monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const & { return monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get_error() const {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void error() const {}
  };
  // Specialisation for T = void E = void
  template <class monad_storage> struct expected_policy_base<monad_storage, void, void> : public monad_storage
  {

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }
    // expected's default constructor constructs a value_type
    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }
    // Common preamble to the below
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get_error() const {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void error() const {}
  };

  //! \brief An implementation policy for basic_monad implementing expected<R, EC>
  template <typename R, typename EC> struct expected_policy
  {
    // The final resulting implementation type
    typedef basic_monad<expected_policy> implementation_type;
    // The value type to use. Can be void to disable.
    typedef R value_type;
    // The error code type to use. Can be void to disable.
    typedef EC error_type;
// The exception pointer type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif

    // Ought the monad be default constructible?
    static constexpr bool is_default_constructible = std::is_default_constructible<value_type>::value;
    // Is default construction non-throwing?
    static constexpr bool is_nothrow_default_constructible = std::is_nothrow_default_constructible<value_type>::value;

    // The base class to use to store state
    typedef expected_policy_base<basic_monad_storage<expected_policy>, value_type, error_type> base;

    // The type which basic_monad::rebind<U> should return
    template <typename U> using rebind = basic_monad<expected_policy<U, EC>>;
    // The type which rebinding myself produces
    template <typename U> using rebind_policy = expected_policy<U, EC>;
  };
  // Policy for when T = void
  template <typename EC> struct expected_policy<void, EC>
  {
    // The final resulting implementation type
    typedef basic_monad<expected_policy> implementation_type;
    // The value type to use. Can be void to disable.
    typedef void value_type;
    // The error code type to use. Can be void to disable.
    typedef EC error_type;
// The exception pointer type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif

    // Ought the monad be default constructible?
    static constexpr bool is_default_constructible = true;
    // Is default construction non-throwing?
    static constexpr bool is_nothrow_default_constructible = true;

    // The base class to use to store state
    typedef expected_policy_base_valueless<basic_monad_storage<expected_policy>, error_type> base;

    // The type which basic_monad::rebind<U> should return
    template <typename U> using rebind = basic_monad<expected_policy<U, EC>>;
    // The type which rebinding myself produces
    template <typename U> using rebind_policy = expected_policy<U, EC>;
  };
  // Policy for when T = void E = void
  template <> struct expected_policy<void, void>
  {
    // The final resulting implementation type
    typedef basic_monad<expected_policy> implementation_type;
    // The value type to use. Can be void to disable.
    typedef void value_type;
    // The error code type to use. Can be void to disable.
    typedef void error_type;
// The exception pointer type to use. Can be void to disable.
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif

    // Ought the monad be default constructible?
    static constexpr bool is_default_constructible = true;
    // Is default construction non-throwing?
    static constexpr bool is_nothrow_default_constructible = true;

    // The base class to use to store state
    typedef expected_policy_base<basic_monad_storage<expected_policy>, void, void> base;

    // The type which basic_monad::rebind<U> should return
    template <typename U> using rebind = basic_monad<expected_policy<U, void>>;
    // The type which rebinding myself produces
    template <typename U> using rebind_policy = expected_policy<U, void>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}
