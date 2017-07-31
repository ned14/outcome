+++
title = "failure<EC, E>"
weight = 20
+++

```cpp
template <class EC, class E, bool e_is_exception_ptr = trait::is_exception_ptr<E>::value> struct failure;
template <class EC, class E> using failure_type = failure<EC, E>;
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code and payload.
*/
template <class EC, class P> struct failure<EC, P, false>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = P;
  //! The type of the exception
  using exception_type = void;
  //! The error code
  error_type error;
  //! The payload
  payload_type payload;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code and exception.
*/
template <class EC, class E> struct failure<EC, E, true>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = E;
  //! The error code
  error_type error;
  //! The exception
  exception_type exception;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code.
*/
template <class EC> struct failure<EC, void, false>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = void;
  //! The error code
  error_type error;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of payload.
*/
template <class P> struct failure<void, P, false>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the payload
  using payload_type = P;
  //! The type of the exception
  using exception_type = void;
  //! The payload
  payload_type payload;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of exception.
*/
template <class E> struct failure<void, E, true>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = E;
  //! The exception
  exception_type exception;
};
```
