+++
title = "result<T, EC>"
weight = 30
+++

```cpp
template <
  class R,
  class S = std::error_code,
  class NoValuePolicy = policy::default_result_policy<S>
>
requires std::is_void<EC>::value || std::is_default_constructible<EC>::value
class [[nodiscard]] result
{
public:
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The S type configured
  using status_error_type = S;
  //! The failure type.
  using error_type = S;

  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using value_type_if_enabled = typename base::_value_type;
  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using error_type_if_enabled = typename base::_error_type;

  //! Used to rebind this result to a different result type.
  template <class T, class U = S> using rebind = result<T, U>;

  /// \output_section Default, copy/move constructors and assignment
  //! Default construction is not permitted.
  result() = delete;
  //! Move construction available if `value_type` and `status_error_type` implement it.
  result(result && /*unused*/) = default;
  //! Copy construction available if `value_type` and `status_error_type` implement it.
  result(const result & /*unused*/) = default;
  //! Move assignment available if `value_type` and `status_error_type` implement it.
  result &operator=(result && /*unused*/) = default;
  //! Copy assignment available if `value_type` and `status_error_type` implement it.
  result &operator=(const result & /*unused*/) = default;

  /// \output_section Converting constructors
  /*! Implicit converting constructor to a successful result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the result with a `value_type`.
  \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`,
  and is not `result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr result(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value);

  /*! Implicit converting constructor to a failure result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
  is not constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr result(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) 
  noexcept(std::is_nothrow_constructible<error_type, T>::value);

  /*! Implicit special error condition converting constructor to a failure result.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the result with a `error_type` constructed via `make_error_code(t)`.
  \requires `trait::status_type_is_negative<EC>` must be true; `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not constructible to `value_type` nor `error_type`, and is not `result<R, S>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */
  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr result(ErrorCondEnum &&t, error_condition_converting_constructor_tag = error_condition_converting_constructor_tag())
  noexcept(noexcept(error_type(make_error_code(std::forward<ErrorCondEnum>(t)))));

  
  /*! Explicit converting copy constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the result with a copy of the compatible result.
  \requires Both result's `value_type`, `error_type` and `status_type` need to be constructible,
  or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit result(const result<T, U, V> &o, explicit_compatible_conversion_tag = explicit_compatible_conversion_tag())
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value);

  /*! Explicit converting move constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the result with a move of the compatible result.
  \requires Both result's `value_type`, `error_type` and `status_type` need to be constructible,
  or the source `status_error_type` can be `void`.
  \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit result(result<T, U, V> &&o, explicit_compatible_conversion_tag = explicit_compatible_conversion_tag()) 
  noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value);

  
  /// \output_section In place constructors
  /*! Explicit inplace constructor to a successful result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `value_type`.
  \requires `value_type` is void or `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit result(in_place_type_t<value_type_if_enabled>, Args &&... args) 
  noexcept(std::is_nothrow_constructible<value_type, Args...>::value);

  /*! Explicit inplace constructor to a successful result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `value_type`.
  \requires The initializer list + `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit result(in_place_type_t<value_type_if_enabled>, std::initializer_list<U> il, Args &&... args) 
  noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value);

  /*! Explicit inplace constructor to a failure result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit result(in_place_type_t<error_type_if_enabled>, Args &&... args) 
  noexcept(std::is_nothrow_constructible<error_type, Args...>::value);

  /*! Explicit inplace constructor to a failure result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit result(in_place_type_t<error_type_if_enabled>, std::initializer_list<U> il, Args &&... args) 
  noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value);

  /*! Implicit inplace constructor to successful or failure result.
  \tparam 3
  \exclude
  \param args Arguments with which to in place construct.

  \effects Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.
  \requires That the args can construct exactly one of `value_type` or `error_type`.
  \throws Any exception the `in_place_type_t<...>` constructor might throw.
  */
  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_constructor<A1, A2, Args...>))
  constexpr result(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)));

  
  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful result.
  \param o The compatible success type sugar.

  \effects Initialises the result with a default constructed success type.
  \requires `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */
  constexpr result(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value);
  
  /*! Implicit tagged constructor of a successful result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the result with a copy of the value in the type sugar.
  \requires Both result and success' `value_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, void, void>))
  constexpr result(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value);
  
  /*! Implicit tagged constructor of a successful result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the result with a move of the value in the type sugar.
  \requires Both result and success' `value_type` need to be constructible. The source cannot be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void>))
  constexpr result(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value);
  
  /*! Implicit tagged constructor of a failure result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the result with a copy of the error in the type sugar.
  \requires Both result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr result(const failure_type<T> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value);
  
  /*! Implicit tagged constructor of a failure result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the result with a move of the error in the type sugar.
  \requires Both result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr result(failure_type<T> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value);
  
  
  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  */
  void swap(result &o) noexcept(detail::is_nothrow_swappable<value_type>::value  //
                                &&detail::is_nothrow_swappable<status_error_type>::value);

  /// \output_section Converters
  /*! Returns this result as a `failure_type` with any errored state copied.
  \requires This result to have a failed state, else whatever `assume_error()` would do.
  */
  auto as_failure() const &;
  /*! Returns this result as a `failure_type` with any errored state moved.
  \requires This result to have a failed state, else whatever `assume_error()` would do.
  */
  auto as_failure() &&;
  
  
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

  /// \output_section Comparison operators
  /*! True if equal to the other result.
  \param o The other result to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on each
  of the two stored items returning true if both are true. Otherwise returns false.
  \throws Any exception the individual `operator==` operations might throw.
  */
  template <class T, class U, class V>
  constexpr bool operator==(const result<T, U, V> &o) const noexcept(                                   //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())));

  /*! True if equal to the success type sugar.
  \param o The success type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
  \throws Any exception the `operator==` operation might throw.
  */
  template <class T> constexpr bool operator==(const success_type<T> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())));

  /*! True if equal to the success type sugar.
  \param o The success type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
  \throws Any exception the `operator==` operation might throw.
  */
  constexpr bool operator==(const success_type<void> & /*unused*/) const noexcept;

  /*! True if equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.
  \throws Any exception the `operator==` operation might throw.
  */
  template <class T> constexpr bool operator==(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())));

  /*! True if not equal to the other result.
  \param o The other result to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on each
  of the two stored items, returning true if any are not equal. Otherwise returns true.
  \throws Any exception the individual `operator!=` operations might throw.
  */
  template <class T, class U, class V>
  constexpr bool operator!=(const result<T, U, V> &o) const noexcept(                                      //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())));

  /*! True if not equal to the success type sugar.
  \param o The success type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
  \throws Any exception the `operator!=` operation might throw.
  */
  template <class T> constexpr bool operator!=(const success_type<T> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())));

  /*! True if not equal to the success type sugar.
  \param o The success type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
  \throws Any exception the `operator!=` operation might throw.
  */
  constexpr bool operator!=(const success_type<void> & /*unused*/) const noexcept;

  /*! True if not equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.
  \throws Any exception the `operator!=` operation might throw.
  */
  template <class T> constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())));
};
//! Calls b == a
template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const result<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
//! Calls b == a
template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const result<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
//! Calls b != a
template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const result<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
//! Calls b != a
template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const result<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
```
