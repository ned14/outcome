+++
title = "success<T>"
weight = 10
+++

```cpp
/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <class T> struct success
{
  //! The type of the successful state.
  using value_type = T;
  //! The value of the successful state.
  value_type value;
  constexpr success(T &&v)
      : value(std::move(v))
  {
  }
  constexpr success(const T &v)
      : value(v)
  {
  }
};
/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <> struct success<void>
{
  //! The type of the successful state.
  using value_type = void;
};
template <class T> success(T /*unused*/)->success<T>;
success()->success<void>;
template <class T> using success_type = success<T>;
```
