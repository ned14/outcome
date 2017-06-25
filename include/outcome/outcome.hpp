#ifndef OUTCOME_OUTCOME_HPP
#define OUTCOME_OUTCOME_HPP

#include "result.hpp"

#include <exception>
#include <memory>

namespace outcome
{
  //! Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
  class OUTCOME_SYMBOL_VISIBLE bad_outcome_access : public std::logic_error
  {
  public:
    bad_outcome_access(const char *what)
        : std::logic_error(what)
    {
    }
  };

  //! Namespace for traits
  namespace trait
  {
    /*! Trait for whether type `P` is to be considered a pointer to an exception.
    \module Error code interpretation policy
    */
    template <class P> struct is_exception_ptr : std::integral_constant<bool, std::is_constructible<std::exception_ptr, P>::value>
    {
    };
  }

  //! Placeholder type to indicate there is no payload type
  struct no_payload_type
  {
    no_payload_type() = delete;
  };
  //! Placeholder type to indicate there is no exception type
  struct no_exception_type
  {
    no_exception_type() = delete;
  };

  namespace impl
  {
    //! The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    template <class Base, class P, class NoValuePolicy> class outcome_payload_observers : public Base
    {
    public:
      using payload_type = P;
      using Base::Base;

      /// \output_section Narrow state observers
      /*! Access payload without runtime checks.
      \preconditions The outcome to have an payload state, otherwise it is undefined behaviour.
      \returns Reference to the held `payload_type` according to overload.
      \group assume_payload
      */
      constexpr payload_type &assume_payload() & noexcept
      {
        NoValuePolicy::narrow_payload_check(this);
        return this->_ptr;
      }
      /// \group assume_payload
      constexpr const payload_type &assume_payload() const &noexcept
      {
        NoValuePolicy::narrow_payload_check(this);
        return this->_ptr;
      }
      /// \group assume_payload
      constexpr payload_type &&assume_payload() && noexcept
      {
        NoValuePolicy::narrow_payload_check(this);
        return this->_ptr;
      }
      /// \group assume_payload
      constexpr const payload_type &&assume_payload() const &&noexcept
      {
        NoValuePolicy::narrow_payload_check(this);
        return this->_ptr;
      }

      /// \output_section Wide state observers
      /*! Access payload with runtime checks.
      \returns Reference to the held `payload_type` according to overload.
      \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
      \group payload
      */
      constexpr payload_type &payload() &
      {
        NoValuePolicy::wide_payload_check(this);
        return this->_ptr;
      }
      /// \group payload
      constexpr const payload_type &payload() const &
      {
        NoValuePolicy::wide_payload_check(this);
        return this->_ptr;
      }
      /// \group payload
      constexpr payload_type &&payload() &&
      {
        NoValuePolicy::wide_payload_check(this);
        return this->_ptr;
      }
      /// \group payload
      constexpr const payload_type &&payload() const &&
      {
        NoValuePolicy::wide_payload_check(this);
        return this->_ptr;
      }
    };
    template <class Base, class NoValuePolicy> class outcome_payload_observers<Base, void, NoValuePolicy> : public Base
    {
    public:
      using Base::Base;
      /// \output_section Narrow state observers
      /*! Access payload without runtime checks.
      \returns Nothing.
      */
      constexpr void assume_payload() const noexcept { NoValuePolicy::narrow_payload_check(this); }
      /// \output_section Wide state observers
      /*! Access payload with runtime checks.
      \returns Nothing.
      \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
      */
      constexpr void payload() const { NoValuePolicy::wide_payload_check(this); }
    };

    //! The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    template <class Base, class P, class NoValuePolicy> class outcome_exception_observers : public Base
    {
    public:
      using exception_type = P;
      using Base::Base;

      /// \output_section Narrow state observers
      /*! Access exception without runtime checks.
      \preconditions The outcome to have an exception state, otherwise it is undefined behaviour.
      \returns Reference to the held `exception_type` according to overload.
      \group assume_exception
      */
      constexpr exception_type &assume_exception() & noexcept
      {
        NoValuePolicy::narrow_exception_check(this);
        return this->_ptr;
      }
      /// \group assume_exception
      constexpr const exception_type &assume_exception() const &noexcept
      {
        NoValuePolicy::narrow_exception_check(this);
        return this->_ptr;
      }
      /// \group assume_exception
      constexpr exception_type &&assume_exception() && noexcept
      {
        NoValuePolicy::narrow_exception_check(this);
        return this->_ptr;
      }
      /// \group assume_exception
      constexpr const exception_type &&assume_exception() const &&noexcept
      {
        NoValuePolicy::narrow_exception_check(this);
        return this->_ptr;
      }

      /// \output_section Wide state observers
      /*! Access exception with runtime checks.
      \returns Reference to the held `exception_type` according to overload.
      \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
      \group exception
      */
      constexpr exception_type &exception() &
      {
        NoValuePolicy::wide_exception_check(this);
        return this->_ptr;
      }
      /// \group exception
      constexpr const exception_type &exception() const &
      {
        NoValuePolicy::wide_exception_check(this);
        return this->_ptr;
      }
      /// \group exception
      constexpr exception_type &&exception() &&
      {
        NoValuePolicy::wide_exception_check(this);
        return this->_ptr;
      }
      /// \group exception
      constexpr const exception_type &&exception() const &&
      {
        NoValuePolicy::wide_exception_check(this);
        return this->_ptr;
      }
    };
    template <class Base, class NoValuePolicy> class outcome_exception_observers<Base, void, NoValuePolicy> : public Base
    {
    public:
      using Base::Base;
      /// \output_section Narrow state observers
      /*! Access exception without runtime checks.
      \returns Nothing.
      */
      constexpr void assume_exception() const noexcept { NoValuePolicy::narrow_exception_check(this); }
      /// \output_section Wide state observers
      /*! Access exception with runtime checks.
      \returns Nothing.
      \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
      */
      constexpr void exception() const { NoValuePolicy::wide_exception_check(this); }
    };
  }

  namespace policy
  {
#ifdef __cpp_exceptions
    template <class R, class S, class P> struct error_code_throw_as_system_error_exception_rethrow;
    /*! Default `outcome<R, S, P>` policy selector.
    \module Error code interpretation policy
    */
    template <class R, class S, class P>
    using default_outcome_policy = std::conditional_t<                                                                                                       //
    detail::is_same_or_constructible<std::error_code, S> && trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_exception_rethrow<R, S, P>,  //
    terminate                                                                                                                                                //
    >;
#else
    template <class R, class S, class P> using default_outcome_policy = terminate;
#endif
  }

  namespace detail
  {
    template <class Base, class P, class NoValuePolicy> using select_outcome_observers_payload_or_exception = std::conditional_t<trait::is_exception_ptr<P>::value, impl::outcome_exception_observers<Base, P, NoValuePolicy>, impl::outcome_payload_observers<Base, P, NoValuePolicy>>;
    template <class R, class S, class P, class NoValuePolicy> using select_outcome_impl = select_outcome_observers_payload_or_exception<impl::result_final<R, S, NoValuePolicy>, P, NoValuePolicy>;
  }

  /*! Used to return from functions (i) a value and (a positive status and/or a payload) or
  (ii) no value and (a negative status and/or a payload). `constexpr` capable.
  \module outcome<R, S, P> implementation
  \tparam R The optional type of the successful result (use `void` to disable).
  \tparam S The optional type of the status result (use `void` to disable). Must be either `void` or DefaultConstructible.
  \tparam P The optional type of the pointer/payload/exception result (use `void` to disable). Must be either `void` or DefaultConstructible.
  \tparam NoValuePolicy Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.
  */
  template <class R,                        //
            class S = error_code_extended,  //
            class P = std::exception_ptr,   //
            class NoValuePolicy = policy::default_outcome_policy<R, S, P>>
  class OUTCOME_NODISCARD outcome : public detail::select_outcome_impl<R, S, P, NoValuePolicy>
  {
    friend NoValuePolicy;
    using base = detail::select_outcome_impl<R, S, P, NoValuePolicy>;
    static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "pointer_type must be default constructible");
    // static_assert(!trait::is_exception_ptr<P>::value || trait::status_type_is_negative<S>::value, "trait::status_type_is_negative<S> must be true if trait::is_exception_ptr<P> is true");

    struct value_converting_constructor_tag
    {
    };
    struct value_status_converting_constructor_tag
    {
    };
    struct value_status_pointer_converting_constructor_tag
    {
    };
    struct error_converting_constructor_tag
    {
    };
    struct error_pointer_converting_constructor_tag
    {
    };
    struct pointer_converting_constructor_tag
    {
    };

  public:
    /// \output_section Member types
    //! The success type.
    using value_type = typename base::value_type;
    //! The S type configured
    using status_error_type = typename base::status_error_type;
#if OUTCOME_ENABLE_POSITIVE_STATUS
    //! The status type, always `no_status_type` if `trait::status_type_is_negative<S>` is true.
    using status_type = typename base::status_type;
#endif
    //! The failure type, always `no_error_type` if `trait::status_type_is_negative<S>` is false.
    using error_type = typename base::error_type;
    //! The pointer type.
    using pointer_type = P;
    //! The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.
    using payload_type = std::conditional_t<!trait::is_exception_ptr<P>::value, no_payload_type, P>;
    //! The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.
    using exception_type = std::conditional_t<trait::is_exception_ptr<P>::value, no_exception_type, P>;

  protected:
    detail::devoid<pointer_type> _ptr;

  public:
    /// \output_section Converting constructors
    /*! Converting constructor to a successful outcome.
    \tparam enable_value_converting_constructor
    \exclude
    \param 1
    \exclude
    \param t The value from which to initialise the `value_type`.

    \effects Initialises the outcome with a `value_type`.
    \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `pointer_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
    \throws Any exception the construction of `value_type(T)` might throw.
    */
    template <class T, typename enable_value_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value && !std::is_constructible<pointer_type, T>::value>>
    constexpr outcome(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)
        : base(in_place_type<value_type>, std::forward<T>(t))
        , _ptr()
    {
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Converting constructor to a successful outcome + status.
\tparam enable_value_status_converting_constructor
\exclude
\param 2
\exclude
\param t The value from which to initialise the `value_type`.
\param u The value from which to initialise the `status_type`.

\effects Initialises the outcome with a `value_type` and an additional `status_type`.
\requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_type`
is not constructible to `pointer_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
Type `U` is constructible to `status_type`, is not constructible to `value_type`, and is not constructible to `pointer_type`.
\throws Any exception the construction of `value_type(T)` and `status_type(U)` might throw.
*/
    template <class T, class U, typename enable_value_status_converting_constructor = std::enable_if_t<                                                                                //
                                !std::is_same<std::decay_t<T>, outcome>::value                                                                                                         // not my type
                                && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                 // not in place construction
                                && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && !std::is_constructible<pointer_type, T>::value  //
                                && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<pointer_type, U>::value>>
    constexpr outcome(T &&t, U &&u, value_status_converting_constructor_tag = value_status_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value)
        : base(typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u))
        , _ptr()
    {
    }
    /*! Converting constructor to a successful outcome + status + pointer.
    \tparam enable_value_status_pointer_converting_constructor
    \exclude
    \param 3
    \exclude
    \param t The value from which to initialise the `value_type`.
    \param u The value from which to initialise the `status_type`.
    \param v The value from which to initialise the `pointer_type`.

    \effects Initialises the outcome with a `value_type`, a `status_type` and a `pointer_type`.
    \requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_type`
    is not constructible to `pointer_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
    Type `U` is constructible to `status_type`, is not constructible to `value_type`, and is not constructible to `pointer_type`;
    Type `V` is constructible to `pointer_type`, is not constructible to `value_type`, and is not constructible to `status_type`.
    \throws Any exception the construction of `value_type(T)`, `status_type(U)` and `pointer_type(V)` might throw.
    */
    template <class T, class U, class V, typename enable_value_status_pointer_converting_constructor = std::enable_if_t<                                                                        //
                                         !std::is_same<std::decay_t<T>, outcome>::value                                                                                                         // not my type
                                         && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                 // not in place construction
                                         && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && !std::is_constructible<pointer_type, T>::value  //
                                         && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<pointer_type, U>::value  //
                                         && detail::is_same_or_constructible<pointer_type, V> && !std::is_constructible<value_type, V>::value && !std::is_constructible<status_type, V>::value  //
                                         >>
    constexpr outcome(T &&t, U &&u, V &&v, value_status_pointer_converting_constructor_tag = value_status_pointer_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value &&std::is_nothrow_constructible<pointer_type, V>::value)
        : base(typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u))
        , _ptr(std::forward<V>(v))
    {
      this->_state._status |= detail::status_have_payload;
    }
#endif
    /*! Converting constructor to an errored outcome.
    \tparam enable_error_converting_constructor
    \exclude
    \param 1
    \exclude
    \param t The value from which to initialise the `error_type`.

    \effects Initialises the outcome with a `error_type`.
    \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
    is not constructible to `value_type`, is not constructible to `pointer_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
    \throws Any exception the construction of `error_type(T)` might throw.
    */
    template <class T, typename enable_error_converting_constructor = std::enable_if_t<  //
                       !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                       && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                       && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T> && !std::is_constructible<pointer_type, T>::value>>
    constexpr outcome(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)
        : base(in_place_type<error_type>, std::forward<T>(t))
        , _ptr()
    {
    }
    /*! Converting constructor to an errored outcome + pointer.
    \tparam enable_error_pointer_converting_constructor
    \exclude
    \param 2
    \exclude
    \param t The value from which to initialise the `error_type`.
    \param u The value from which to initialise the `pointer_type`.

    \effects Initialises the outcome with a `error_type` and a `pointer_type`.
    \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
    is not constructible to `value_type`, is not constructible to `pointer_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
    Type `U` is constructible to `pointer_type`, is not constructible to `value_type`, and is not constructible to `error_type`.
    \throws Any exception the construction of `error_type(T)` and `pointer_type(U)` might throw.
    */
    template <class T, class U, typename enable_error_pointer_converting_constructor = std::enable_if_t<                                                                              //
                                !std::is_same<std::decay_t<T>, outcome>::value                                                                                                        // not my type
                                && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                // not in place construction
                                && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T> && !std::is_constructible<pointer_type, T>::value  //
                                && detail::is_same_or_constructible<pointer_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<error_type, U>::value>>
    constexpr outcome(T &&t, U &&u, error_pointer_converting_constructor_tag = error_pointer_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<pointer_type, U>::value)
        : base(in_place_type<error_type>, std::forward<T>(t))
        , _ptr(std::forward<U>(u))
    {
      this->_state._status |= trait::is_exception_ptr<pointer_type>::value ? detail::status_have_exception : detail::status_have_payload;
    }
#if 0
    /*! Converting copy constructor from a compatible outcome type.
    \tparam enable_compatible_conversion
    \exclude
    \param o The compatible outcome.

    \effects Initialises the outcome with a copy of the compatible outcome.
    \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
    \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
    */
    template <class T, class U, class V, typename enable_compatible_conversion = std::enable_if_t<                                                            //
                                         !std::is_same<outcome<T, U, V>, outcome>::value                                                                      // not my type
                                         && (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V>::value_type>)   // if our value types are constructible
                                         &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V>::error_type>)    // if our error types are constructible
                                         &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename outcome<T, U, V>::status_type>)  // if our status types are constructible
                                         >>
    constexpr explicit outcome(const outcome<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value)
        : base(typename base::compatible_conversion_tag(), o)
    {
    }
    /*! Converting move constructor from a compatible outcome type.
    \tparam enable_compatible_conversion
    \exclude
    \param o The compatible outcome.

    \effects Initialises the outcome with a move of the compatible outcome.
    \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
    \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
    */
    template <class T, class U, class V, typename enable_compatible_conversion = std::enable_if_t<                                                            //
                                         !std::is_same<outcome<T, U, V>, outcome>::value                                                                      // not my type
                                         && (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V>::value_type>)   // if our value types are constructible
                                         &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V>::error_type>)    // if our error types are constructible
                                         &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename outcome<T, U, V>::status_type>)  // if our status types are constructible
                                         >>
    constexpr explicit outcome(outcome<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value)
        : base(typename base::compatible_conversion_tag(), std::move(o))
    {
    }
#endif

    /// \output_section In place constructors
    /*! Inplace constructor to a successful value.
    \tparam 1
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `value_type`.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `value_type`.
    \requires `value_type` is void or `Args...` are constructible to `value_type`.
    \throws Any exception the construction of `value_type(Args...)` might throw.
    */
    template <class... Args, typename = std::enable_if_t<std::is_void<value_type>::value || std::is_constructible<value_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : base(_, std::forward<Args>(args)...)
        , _ptr()
    {
    }
    /*! Inplace constructor to a successful value.
    \tparam 2
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `value_type`.
    \param il An initializer list with which to in place construct.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `value_type`.
    \requires The initializer list + `Args...` are constructible to `value_type`.
    \throws Any exception the construction of `value_type(il, Args...)` might throw.
    */
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<value_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : base(_, il, std::forward<Args>(args)...)
        , _ptr()
    {
    }
    /*! Inplace constructor to an unsuccessful error.
    \tparam 1
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `error_type`.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `error_type`.
    \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
    \throws Any exception the construction of `error_type(Args...)` might throw.
    */
    template <class... Args, typename = std::enable_if_t<std::is_void<error_type>::value || std::is_constructible<error_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<error_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
        : base(_, std::forward<Args>(args)...)
        , _ptr()
    {
    }
    /*! Inplace constructor to an unsuccessful error.
    \tparam 2
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `error_type`.
    \param il An initializer list with which to in place construct.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `error_type`.
    \requires `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.
    \throws Any exception the construction of `error_type(il, Args...)` might throw.
    */
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<error_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<error_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
        : base(_, il, std::forward<Args>(args)...)
        , _ptr()
    {
    }
    /*! Inplace constructor to an unsuccessful pointer.
    \tparam 1
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `pointer_type`.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `pointer_type`.
    \requires `pointer_type` is void or `Args...` are constructible to `pointer_type`.
    \throws Any exception the construction of `pointer_type(Args...)` might throw.
    */
    template <class... Args, typename = std::enable_if_t<std::is_void<pointer_type>::value || std::is_constructible<pointer_type, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<pointer_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<pointer_type, Args...>::value)
        : base()
        , _ptr(std::forward<Args>(args)...)
    {
      this->_state._status |= trait::is_exception_ptr<pointer_type>::value ? detail::status_have_exception : detail::status_have_payload;
    }
    /*! Inplace constructor to an unsuccessful pointer.
    \tparam 2
    \exclude
    \param _ Tag type to indicate we are doing in place construction of `pointer_type`.
    \param il An initializer list with which to in place construct.
    \param args Arguments with which to in place construct.

    \effects Initialises the outcome with a `pointer_type`.
    \requires The initializer list + `Args...` are constructible to `pointer_type`.
    \throws Any exception the construction of `pointer_type(il, Args...)` might throw.
    */
    template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<pointer_type, std::initializer_list<U>, Args...>::value>>
    constexpr explicit outcome(in_place_type_t<pointer_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<pointer_type, std::initializer_list<U>, Args...>::value)
        : base()
        , _ptr(il, std::forward<Args>(args)...)
    {
      this->_state._status |= trait::is_exception_ptr<pointer_type>::value ? detail::status_have_exception : detail::status_have_payload;
    }
  };

  namespace policy
  {
#ifdef __cpp_exceptions
    /*! Policy interpreting S as a type implementing the `std::error_code` contract, E as
    a type implementing the `std::exception_ptr` contract, and any wide attempt to access the
    successful state throws the `exception_ptr` if available, then the `error_code` wrapped
    into a `std::system_error`.
    \module Error code interpretation policy
    */
    template <class R, class S, class P> struct error_code_throw_as_system_error_exception_rethrow
    {
      static_assert(std::is_convertible<std::error_code, S>::value, "error_type must be convertible into a std::error_code to be used with this policy");
      static_assert(std::is_convertible<std::exception_ptr, P>::value, "exception_type must be convertible into a std::exception_ptr to be used with this policy");
      /*! Performs a narrow check of state, used in the assume_value() functions.
      \effects None.
      */
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_value) == 0)
          __builtin_unreachable();
#endif
      }
      /*! Performs a narrow check of state, used in the assume_error() functions.
      \effects None.
      */
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_error) == 0)
          __builtin_unreachable();
#endif
      }
#if OUTCOME_ENABLE_POSITIVE_STATUS
      /*! Performs a narrow check of state, used in the assume_status() functions
  \effects None.
  */
      template <class Impl> static constexpr void narrow_status_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_status) == 0)
          __builtin_unreachable();
#endif
      }
#endif
      /*! Performs a narrow check of state, used in the assume_payload() functions.
      \effects None.
      */
      template <class Impl> static constexpr void narrow_payload_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_payload) == 0)
          __builtin_unreachable();
#endif
      }
      /*! Performs a narrow check of state, used in the assume_exception() functions.
      \effects None.
      */
      template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept
      {
#if defined(__GNUC__) || defined(__clang__)
        if((self->_state._status & detail::status_have_exception) == 0)
          __builtin_unreachable();
#endif
      }
      /*! Performs a wide check of state, used in the value() functions.
      \effects If outcome does not have a value, if it has an exception it rethrows it via `std::rethrow_exception()`,
      if has an error it throws a `std::system_error(error())`, else it throws `bad_outcome_access`.
      */
      template <class Impl> static constexpr void wide_value_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_value) == 0)
        {
          if((self->_state._status & detail::status_have_exception) != 0)
          {
            auto *_self = static_cast<const outcome<R, S, P, error_code_throw_as_system_error_exception_rethrow> *>(self);
            std::rethrow_exception(_self->_ptr);
          }
          if((self->_state._status & detail::status_have_error) != 0)
          {
            throw std::system_error(self->_error);
          }
          throw bad_outcome_access("no value");
        }
      }
      /*! Performs a wide check of state, used in the error() functions
      \effects If outcome does not have an error, it throws `bad_outcome_access`.
      */
      template <class Impl> static constexpr void wide_error_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_error) == 0)
        {
          throw bad_outcome_access("no error");
        }
      }
#if OUTCOME_ENABLE_POSITIVE_STATUS
      /*! Performs a wide check of state, used in the status() functions
  \effects If outcome does not have an status, it throws `bad_outcome_access`.
  */
      template <class Impl> static constexpr void wide_status_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_status) == 0)
        {
          throw bad_outcome_access("no status");
        }
      }
#endif
      /*! Performs a wide check of state, used in the pointer() functions
      \effects If outcome does not have a pointer, it throws `bad_outcome_access`.
      */
      template <class Impl> static constexpr void wide_payload_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_payload) == 0)
        {
          throw bad_outcome_access("no payload");
        }
      }
      /*! Performs a wide check of state, used in the exception() functions
      \effects If outcome does not have an exception, it throws `bad_outcome_access`.
      */
      template <class Impl> static constexpr void wide_exception_check(Impl *self)
      {
        if((self->_state._status & detail::status_have_exception) == 0)
        {
          throw bad_outcome_access("no exception");
        }
      }
    };
#endif
  }
}

#endif
