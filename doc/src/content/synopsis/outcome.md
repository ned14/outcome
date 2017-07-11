+++
title = "outcome<T, EC, E>"
weight = 20
+++

```cpp
template <
  class R,
  class S = std::error_code,
  class P = std::exception_ptr,
  class NoValuePolicy = policy::default_outcome_policy<R, S, P>
>
requires
  (std::is_void<EC>::value || std::is_default_constructible<EC>::value) 
  && (std::is_void<P>::value || std::is_default_constructible<P>::value)
class [[nodiscard]] outcome
{
public:
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The S type configured
  using status_error_type = S;
  //! The failure type.
  using error_type = S;
  //! The P type configured.
  using payload_exception_type = P;
  //! The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.
  using payload_type = std::conditional_t<trait::is_exception_ptr<P>::value, no_payload_type, P>;
  //! The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.
  using exception_type = std::conditional_t<!trait::is_exception_ptr<P>::value, no_exception_type, P>;

  //! Used to rebind this outcome to a different outcome type
  template <class T, class U = S, class V = P> using rebind = outcome<T, U, P>;

  //! Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `payload_exception_type`.
  using value_type_if_enabled = std::conditional_t<std::is_same<value_type, error_type>::value || std::is_same<value_type, payload_exception_type>::value, typename base::_value_type, value_type>;
  //! Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `payload_exception_type`.
  using error_type_if_enabled = std::conditional_t<std::is_same<error_type, value_type>::value || std::is_same<error_type, payload_exception_type>::value, typename base::_error_type, error_type>;
  //! Used to disable in place type construction when `payload_exception_type` is ambiguous with `value_type` or `error_type`.
  using exception_type_if_enabled = std::conditional_t<std::is_same<exception_type, value_type>::value || std::is_same<exception_type, error_type>::value, disable_in_place_payload_exception_type, exception_type>;

  /// \output_section Converting constructors
  /*! Converting constructor to a successful outcome.
  \tparam enable_value_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the outcome with a `value_type`.
  \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr outcome(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value);
  
  /*! Converting constructor to an errored outcome.
  \tparam enable_error_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
  is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr outcome(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<error_type, T>::value);

  /*! Converting constructor to an errored outcome + payload/exception.
  \tparam enable_error_payload_converting_constructor
  \exclude
  \param 2
  \exclude
  \param t The value from which to initialise the `error_type`.
  \param u The value from which to initialise the `payload_exception_type`.

  \effects Initialises the outcome with a `error_type` and a `payload_exception_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
  is not constructible to `value_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `payload_exception_type`, is not constructible to `value_type`.
  \throws Any exception the construction of `error_type(T)` and `payload_exception_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_payload_converting_constructor<T, U>))
  constexpr outcome(T &&t, U &&u, error_payload_converting_constructor_tag = error_payload_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<payload_exception_type, U>::value);

  /*! Special error condition converting constructor to an errored outcome.
  \tparam enable_error_condition_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type` constructed via `make_error_code(t)`.
  \requires `trait::status_type_is_negative<EC>` must be true; `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not constructible to `value_type`, `error_type` nor `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */
  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr outcome(ErrorCondEnum &&t, error_condition_converting_constructor_tag = error_condition_converting_constructor_tag()) 
  noexcept(noexcept(error_type(make_error_code(std::forward<ErrorCondEnum>(t)))));

  /*! Converting constructor to an excepted outcome.
  \tparam enable_exception_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `exception_type`.

  \effects Initialises the outcome with a `exception_type`.
  \requires `trait::is_exception_ptr<P>` must be true; Type T is constructible to `exception_type`,
  is not constructible to `value_type`, is not constructible to `status_error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `exception_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_exception_converting_constructor<T>))
  constexpr outcome(T &&t, exception_converting_constructor_tag = exception_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<exception_type, T>::value);

  
  /*! Explicit converting copy constructor from a compatible outcome type.
  \tparam enable_explicit_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a copy of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  The source `value_type` cannot be `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_explicit_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(const outcome<T, U, V, W> &o,
                             explicit_compatible_conversion_tag = explicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value);

  /*! Implicit converting copy constructor from a compatible outcome type.
  \tparam enable_implicit_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a copy of the compatible outcome.
  \requires Both outcome's `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  The source `value_type` must be `void`.
  \throws Any exception the construction of `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_implicit_compatible_conversion<T, U, V, W>))
  constexpr outcome(const outcome<T, U, V, W> &o, implicit_compatible_conversion_tag = implicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<payload_exception_type, V>::value);

  /*! Explicit converting move constructor from a compatible outcome type.
  \tparam enable_explicit_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a move of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  The source `value_type` cannot be `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_explicit_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(outcome<T, U, V, W> &&o, explicit_compatible_conversion_tag = explicit_compatible_conversion_tag())
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value);

  /*! Implicit converting move constructor from a compatible outcome type.
  \tparam enable_implicit_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a move of the compatible outcome.
  \requires Both outcome's `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  The source `value_type` must be `void`.
  \throws Any exception the construction of `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_implicit_compatible_conversion<T, U, V, W>))
  constexpr outcome(outcome<T, U, V, W> &&o, implicit_compatible_conversion_tag = implicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value);

  /*! Explicit converting copy constructor from a compatible result type.
  \tparam enable_explicit_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a copy of the compatible result.
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  The source `value_type` cannot be `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_explicit_compatible_conversion<T, U, V>))
  constexpr explicit outcome(const result<T, U, V> &o, explicit_compatible_conversion_tag = explicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value);

  /*! Implicit converting copy constructor from a compatible result type.
  \tparam enable_implicit_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a copy of the compatible result.
  \requires Both outcome's`error_type` and `status_type` need to be constructible, or the source `void`.
  The source `value_type` must be `void`.
  \throws Any exception the construction of`status_error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_implicit_compatible_conversion<T, U, V>))
  constexpr outcome(const result<T, U, V> &o, implicit_compatible_conversion_tag = implicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value);

  /*! Explicit converting move constructor from a compatible result type.
  \tparam enable_explicit_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a move of the compatible result.
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  The source `value_type` cannot be `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_explicit_compatible_conversion<T, U, V>))
  constexpr explicit outcome(result<T, U, V> &&o, explicit_compatible_conversion_tag = explicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value);

  /*! Implicit converting move constructor from a compatible result type.
  \tparam enable_implicit_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a move of the compatible result.
  \requires Both outcome's `error_type` and `status_type` need to be constructible, or the source `void`.
  The source `value_type` must be `void`.
  \throws Any exception the construction of `status_error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_implicit_compatible_conversion<T, U, V>))
  constexpr outcome(result<T, U, V> &&o, implicit_compatible_conversion_tag = implicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value);

  

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
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<value_type_if_enabled> _, Args &&... args) 
  noexcept(std::is_nothrow_constructible<value_type, Args...>::value);

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
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) 
  noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value);

  /*! Inplace constructor to an unsuccessful error.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<error_type_if_enabled> _, Args &&... args) 
  noexcept(std::is_nothrow_constructible<error_type, Args...>::value);

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
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) 
  noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value);

  /*! Inplace constructor to an unsuccessful exception.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `exception_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with an `exception_type`.
  \requires `exception_type` is void or `Args...` are constructible to `exception_type`.
  \throws Any exception the construction of `exception_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<exception_type_if_enabled>, Args &&... args) 
  noexcept(std::is_nothrow_constructible<exception_type, Args...>::value);

  /*! Inplace constructor to an unsuccessful exception.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `exception_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with an `exception_type`.
  \requires The initializer list + `Args...` are constructible to `exception_type`.
  \throws Any exception the construction of `exception_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<exception_type_if_enabled>, std::initializer_list<U> il, Args &&... args) 
  noexcept(std::is_nothrow_constructible<exception_type, std::initializer_list<U>, Args...>::value);

  /*! Implicit inplace constructor to successful value, or unsuccessful error, or unsuccessful exception.
  \tparam 3
  \exclude
  \param args Arguments with which to in place construct.

  \effects Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.
  \requires That the args can construct exactly one of `value_type` or `error_type` or `exception_type`.
  \throws Any exception the `in_place_type_t<...>` constructor might throw.
  */
  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_exception_constructor<A1, A2, Args...>))
  constexpr outcome(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)));

  
  /// \output_section Comparison operators
  /*! True if equal to the other outcome.
  \tparam 4
  \exclude
  \tparam 5
  \exclude
  \tparam 6
  \exclude
  \param o The other outcome to compare to.

  \effects Calls the `operator==` operation on each of the three stored items until one returns false.
  \requires That the expression of calling `operator==` on each of the three stored items is a valid expression.
  \throws Any exception the individual `operator==` operations might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(                                      //
  OUTCOME_TEXPR(std::declval<R>() == std::declval<T>()),  //
  OUTCOME_TEXPR(std::declval<S>() == std::declval<U>()),  //
  OUTCOME_TEXPR(std::declval<P>() == std::declval<V>())   //
  )
  constexpr bool operator==(const outcome<T, U, V, W> &o) const noexcept(  //
  noexcept(std::declval<R>() == std::declval<T>())                         //
  && noexcept(std::declval<S>() == std::declval<U>())                      //
  && noexcept(std::declval<P>() == std::declval<V>()));
  /*! True if not equal to the other outcome.
  \tparam 4
  \exclude
  \tparam 5
  \exclude
  \tparam 6
  \exclude
  \param o The other outcome to compare to.

  \effects Calls the `operator!=` operation on each of the three stored items until one returns true.
  \requires That the expression of calling `operator!=` on each of the three stored items is a valid expression.
  \throws Any exception the individual `operator!=` operations might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(                                      //
  OUTCOME_TEXPR(std::declval<R>() != std::declval<T>()),  //
  OUTCOME_TEXPR(std::declval<S>() != std::declval<U>()),  //
  OUTCOME_TEXPR(std::declval<P>() != std::declval<V>())   //
  )
  constexpr bool operator!=(const outcome<T, U, V, W> &o) const noexcept(  //
  noexcept(std::declval<R>() != std::declval<T>())                         //
  && noexcept(std::declval<S>() != std::declval<U>())                      //
  && noexcept(std::declval<P>() != std::declval<V>()));
  /*! True if equal to the other result.
  \tparam 4
  \exclude
  \tparam 5
  \exclude
  \param o The other result to compare to.

  \effects Calls the `operator==` operation on each of the two stored items until one returns false.
  \requires That the expression of calling `operator==` on each of the two stored items is a valid expression.
  \throws Any exception the individual `operator==` operations might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(                                      //
  OUTCOME_TEXPR(std::declval<R>() == std::declval<T>()),  //
  OUTCOME_TEXPR(std::declval<S>() == std::declval<U>())   //
  )
  constexpr bool operator==(const result<T, U, V> &o) const noexcept(  //
  noexcept(std::declval<R>() == std::declval<T>())                     //
  && noexcept(std::declval<S>() == std::declval<U>()));
  /*! True if not equal to the other result.
  \tparam 4
  \exclude
  \tparam 5
  \exclude
  \param o The other result to compare to.

  \effects Calls the `operator!=` operation on each of the two stored items until one returns true.
  \requires That the expression of calling `operator!=` on each of the two stored items is a valid expression.
  \throws Any exception the individual `operator!=` operations might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(                                      //
  OUTCOME_TEXPR(std::declval<R>() != std::declval<T>()),  //
  OUTCOME_TEXPR(std::declval<S>() != std::declval<U>())   //
  )
  constexpr bool operator!=(const result<T, U, V> &o) const noexcept(  //
  noexcept(std::declval<R>() != std::declval<T>())                     //
  && noexcept(std::declval<S>() != std::declval<U>()));

  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  */
  void swap(outcome &o) noexcept(detail::is_nothrow_swappable<value_type>::value           //
                                 &&detail::is_nothrow_swappable<status_error_type>::value  //
                                 &&detail::is_nothrow_swappable<payload_exception_type>::value);

  /// \output_section Converters
  /*! Returns this outcome rebound to void with any errored and payload state copied.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */
  rebind<void> as_void() const &;
  /*! Returns this outcome rebound to void with any errored and payload state moved.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */
  rebind<void> as_void() &&;


  
  /// \output_section Narrow state observers
  /*! Access value without runtime checks.
  \preconditions The result to have a successful state, otherwise it is undefined behaviour.
  \returns Reference to the held `value_type` according to overload.
  \group assume_value
  */
  constexpr value_type &assume_value() & noexcept;
  /// \group assume_value
  constexpr const value_type &assume_value() const &noexcept;
  /// \group assume_value
  constexpr value_type &&assume_value() && noexcept;
  /// \group assume_value
  constexpr const value_type &&assume_value() const &&noexcept;

  /// \output_section Wide state observers
  /*! Access value with runtime checks.
  \returns Reference to the held `value_type` according to overload.
  \requires The result to have a successful state, else whatever `NoValuePolicy` says ought to happen.
  \group value
  */
  constexpr value_type &value() &;
  /// \group value
  constexpr const value_type &value() const &;
  /// \group value
  constexpr value_type &&value() &&;
  /// \group value
  constexpr const value_type &&value() const &&;

  /// \output_section Narrow state observers
  /*! Access error without runtime checks.
  \preconditions The result to have a failed state, otherwise it is undefined behaviour.
  \returns Reference to the held `error_type` according to overload.
  \group assume_error
  */
  constexpr error_type &assume_error() & noexcept;
  /// \group assume_error
  constexpr const error_type &assume_error() const &noexcept;
  /// \group assume_error
  constexpr error_type &&assume_error() && noexcept;
  /// \group assume_error
  constexpr const error_type &&assume_error() const &&noexcept;

  /// \output_section Wide state observers
  /*! Access error with runtime checks.
  \returns Reference to the held `error_type` according to overload.
  \requires The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.
  \group error
  */
  constexpr error_type &error() &;
  /// \group error
  constexpr const error_type &error() const &;
  /// \group error
  constexpr error_type &&error() &&;
  /// \group error
  constexpr const error_type &&error() const &&;

// Either of these two is present depending on this trait
#if !trait::is_exception_ptr<payload_exception_type>

    /// \output_section Narrow state observers
    /*! Access payload without runtime checks.
    \preconditions The outcome to have an payload state, otherwise it is undefined behaviour.
    \returns Reference to the held `payload_type` according to overload.
    \group assume_payload
    */
    inline constexpr payload_type &assume_payload() & noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &assume_payload() const &noexcept;
    /// \group assume_payload
    inline constexpr payload_type &&assume_payload() && noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &&assume_payload() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
    \returns Reference to the held `payload_type` according to overload.
    \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
    \group payload
    */
    inline constexpr payload_type &payload() &;
    /// \group payload
    inline constexpr const payload_type &payload() const &;
    /// \group payload
    inline constexpr payload_type &&payload() &&;
    /// \group payload
    inline constexpr const payload_type &&payload() const &&;

#else

    /// \output_section Narrow state observers
    /*! Access exception without runtime checks.
    \preconditions The outcome to have an exception state, otherwise it is undefined behaviour.
    \returns Reference to the held `exception_type` according to overload.
    \group assume_exception
    */
    constexpr inline exception_type &assume_exception() & noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &assume_exception() const &noexcept;
    /// \group assume_exception
    constexpr inline exception_type &&assume_exception() && noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &&assume_exception() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \returns Reference to the held `exception_type` according to overload.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    \group exception
    */
    constexpr inline exception_type &exception() &;
    /// \group exception
    constexpr inline const exception_type &exception() const &;
    /// \group exception
    constexpr inline exception_type &&exception() &&;
    /// \group exception
    constexpr inline const exception_type &&exception() const &&;

#endif


  /// \output_section State check observers
  /*! Checks if has value.
  \returns True if has value.
  */
  constexpr explicit operator bool() const noexcept;
  /*! Checks if has value.
  \returns True if has value.
  */
  constexpr bool has_value() const noexcept;
  /*! Checks if has error.
  \returns True if has error.
  */
  constexpr bool has_error() const noexcept;
  /*! Checks if has payload.
  \returns True if has payload.
  */
  constexpr bool has_payload() const noexcept;
  /*! Checks if has exception.
  \returns True if has exception.
  */
  constexpr bool has_exception() const noexcept;
  /*! Checks if has error or exception.
  \returns True if has error or exception.
  */
  constexpr bool has_failure() const noexcept;
};
```
