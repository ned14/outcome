/* WG21 standards reference result implementation
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: June 2017


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

#ifndef WG21_EXPERIMENTAL_RESULT_HPP
#define WG21_EXPERIMENTAL_RESULT_HPP

/***************************** BEGIN WG14 C Programming Language standards part *******************************/
#define CXX_DECLARE_RESULT(R, D)                                                                                                                                                                                                                                                                                               \
  struct result_##R                                                                                                                                                                                                                                                                                                            \
  {                                                                                                                                                                                                                                                                                                                            \
    D value;                                                                                                                                                                                                                                                                                                                   \
    unsigned char flags;                                                                                                                                                                                                                                                                                                       \
    int error;                                                                                                                                                                                                                                                                                                                 \
    void *category;                                                                                                                                                                                                                                                                                                            \
  }
#define CXX_RESULT(R) struct result_##R
#define CXX_RESULT_HAS_VALUE(r) (((r).flags & 1) == 1)
#define CXX_RESULT_HAS_ERROR(r) (((r).flags & 1) == 0)
// Unable to use this in std::optional based result
//#define CXX_RESULT_ERROR_IS_ERRNO(r) (((r).flags & (1 << 4)) == (1 << 4))
#define CXX_RESULT_SET_ERRNO(r) (errno = CXX_RESULT_HAS_ERROR(r) ? (CXX_RESULT_ERROR_IS_ERRNO(r) ? (r).error : EAGAIN) : 0)

/***************************** END WG14 C Programming Language standards part *******************************/

#ifdef __cplusplus

#ifndef __cpp_deduction_guides
#error This WG21 standards reference implementation of result requires C++ 17 template deduction guides support in the compiler.
#endif
#ifndef __cpp_concepts
#error This WG21 standards reference implementation of result requires C++ 20 concepts support in the compiler.
#endif

#include <exception>
#include <optional>
#include <system_error>
#include <type_traits>

#ifndef WG21_EXPERIMENTAL_RESULT_SYMBOL_VISIBLE
#if defined(__GNUC__)
#define WG21_EXPERIMENTAL_RESULT_SYMBOL_VISIBLE __attribute__((visibility("default")))
#else
#define WG21_EXPERIMENTAL_RESULT_SYMBOL_VISIBLE
#endif
#endif

namespace std
{
  namespace experimental
  {
    inline namespace fundamentals_v3
    {
      namespace detail
      {
        // Test if type is an in_place_type_t
        template <class T> struct is_in_place_type_t : std::false_type
        {
        };
        template <class U> struct is_in_place_type_t<std::in_place_type_t<U>> : std::true_type
        {
        };
        template <class T> static constexpr bool is_in_place_type_v = is_in_place_type_t<T>::value;

        // Used to make optional<void> work
        struct void_type
        {
          // We always compare true to another instance of me
          constexpr bool operator==(void_type /*unused*/) const noexcept { return true; }
          constexpr bool operator!=(void_type /*unused*/) const noexcept { return false; }
        };

        // How to throw an error type
        inline void throw_exception(const std::error_code &ec) { throw std::system_error(ec); }
        inline void throw_exception(const std::exception_ptr &e) { std::rethrow_exception(e); }
        template <class T>                                                                   //
        requires(is_error_code_enum_v<decay_t<T>> || is_error_condition_enum_v<decay_t<T>>)  //
        inline void throw_exception(T &&v)
        {
          throw std::system_error(make_error_code(v));
        }
      }

      // Type sugar to indicate success
      template <class T> struct success
      {
        using value_type = T;
        value_type value;
      };
      template <> struct success<void>
      {
        using value_type = void;
      };
      template <class T> success(T /*unused*/)->success<T>;
      success()->success<void>;

      // Type sugar to indicate failure
      template <class T> struct failure
      {
        using error_type = T;
        error_type error;
      };
      template <class T> failure(T /*unused*/)->failure<T>;
      failure()->failure<void>;

      // Thrown when you try to access state in a `result<R, S>` which isn't present.
      class WG21_EXPERIMENTAL_RESULT_SYMBOL_VISIBLE bad_result_access : public std::logic_error
      {
      public:
        bad_result_access(const char *what)
            : std::logic_error(what)
        {
        }
      };

      /* The proposed result type for standardardisation.

         Requires:

         1. `std::optional` must preserve triviality of copy and move from `T`.
         2. `std::optional` must preserve standard layout of `T`.
         3. `std::optional<T>` must have layout `struct { T value; unsigned char has_value; }`

         NOTE: This reference implementation has these deviations from the proposed standard spec:

         - `value()` and `assume_value()` should return `void` when `R` is `void`, not `_void_type`.
         - We do not set bit 4 of the optional's has_value when error type is errno domain as any
         STL optional implementation would misoperate.
      */
      template <class R, class S = std::error_code>               //
      requires(                                                   //
      (!std::is_reference_v<R>                                    //
       && !std::is_same_v<nullopt_t, std::decay_t<R>>             //
       && !std::is_same_v<in_place_t, std::decay_t<R>>            //
       && !detail::is_in_place_type_v<std::decay_t<R>>            //
       && !std::is_array_v<R>                                     //
       && (std::is_void_v<R> || (std::is_object_v<R>              //
                                 && std::is_destructible_v<R>) )  //
       ) &&
      (std::is_default_constructible_v<S>               //
       && !std::is_reference_v<S>                       //
       && (std::is_base_of_v<std::error_code, S>        //
           || std::is_base_of_v<std::exception_ptr, S>  //
           || std::is_error_code_enum_v<S>              //
           || std::is_error_condition_enum_v<S>)        //
       )                                                //
      )                                                 //
      class[[nodiscard]] result
      {
        template <class T, class U> friend class result;

      public:
        using value_type = R;
        using error_type = S;

      protected:
        static constexpr bool _implicit_constructors_enabled =                                                //
        (std::is_same_v<bool, std::decay_t<value_type>> || !std::is_constructible_v<value_type, error_type>)  //
        &&!std::is_constructible_v<error_type, value_type>;
        template <class T> using _devoid = std::conditional_t<std::is_void_v<T>, detail::void_type, T>;
        using _value_type = _devoid<value_type>;

        // All the deviations from proposed spec stem from the use of std::optional here, but it's close enough
        std::optional<_value_type> _value;
        error_type _error;

      public:
        // Note default construction is deleted
        result() = delete;
        result(result && /*unused*/) = default;
        result(const result & /*unused*/) = default;
        result &operator=(result && /*unused*/) = default;
        result &operator=(const result & /*unused*/) = default;

        // Explicit in place construction
        template <class... Args>                                                                                               //
        requires(std::is_constructible_v<value_type, Args...> || (sizeof...(Args) == 0 && std::is_void_v<value_type>) )        //
        constexpr explicit result(std::in_place_type_t<value_type>, Args && ... args)                                          //
        noexcept(std::is_nothrow_constructible_v<value_type, Args...> && std::is_nothrow_default_constructible_v<error_type>)  //
        : _value(std::in_place, std::forward<Args>(args)...),
          _error()
        {
        }
        // Implicit in place construction, disables if ambiguous
        template <class A, class... Args>                                                                                                 //
        requires(_implicit_constructors_enabled                                                                                           //
                 && (sizeof...(Args) > 0 || (!std::is_same_v<result, std::decay_t<A>> && !detail::is_in_place_type_v<std::decay_t<A>>) )  //
                 && std::is_constructible_v<value_type, A, Args...>                                                                       //
                 && !std::is_constructible_v<error_type, A, Args...>)                                                                     //
        constexpr result(A && a, Args && ... args) noexcept(std::is_nothrow_constructible_v<value_type, A, Args...>)                      //
        : result(std::in_place_type<value_type>, std::forward<A>(a), std::forward<Args>(args)...)
        {
        }
        // Implicit tagged construction
        template <class T>                                                                                      //
        requires(std::is_constructible_v<value_type, T>)                                                        //
        constexpr result(const success<T> &v) noexcept(std::is_nothrow_constructible_v<value_type, const T &>)  //
        : _value(std::in_place, v.value),
          _error()
        {
        }
        template <class T>                                                                             //
        requires(std::is_constructible_v<value_type, T>)                                               //
        constexpr result(success<T> && v) noexcept(std::is_nothrow_constructible_v<value_type, T &&>)  //
        : _value(std::in_place, std::move(v.value)),
          _error()
        {
        }
        constexpr result(const success<void> &v) noexcept : _value(detail::void_type{}), _error() {}

        // Explicit in place construction
        template <class... Args>                                                       //
        requires(std::is_constructible_v<error_type, Args...>)                         //
        constexpr explicit result(std::in_place_type_t<error_type>, Args && ... args)  //
        noexcept(std::is_nothrow_constructible_v<error_type, Args...>)                 //
        : _value(),
          _error(std::forward<Args>(args)...)
        {
        }
        // Implicit in place construction, disables if ambiguous
        template <class A, class... Args>                                                                                                 //
        requires(_implicit_constructors_enabled                                                                                           //
                 && (sizeof...(Args) > 0 || (!std::is_same_v<result, std::decay_t<A>> && !detail::is_in_place_type_v<std::decay_t<A>>) )  //
                 && std::is_constructible_v<error_type, A, Args...>                                                                       //
                 && !std::is_constructible_v<value_type, A, Args...>)                                                                     //
        constexpr result(A && a, Args && ... args) noexcept(std::is_nothrow_constructible_v<error_type, A, Args...>)                      //
        : result(std::in_place_type<error_type>, std::forward<A>(a), std::forward<Args>(args)...)
        {
        }
        // Implicit tagged construction
        template <class T>                                                                                      //
        requires(std::is_constructible_v<value_type, T>)                                                        //
        constexpr result(const failure<T> &v) noexcept(std::is_nothrow_constructible_v<error_type, const T &>)  //
        : _value(),
          _error(v.error)
        {
        }
        template <class T>                                                                             //
        requires(std::is_constructible_v<error_type, T>)                                               //
        constexpr result(failure<T> && v) noexcept(std::is_nothrow_constructible_v<error_type, T &&>)  //
        : _value(),
          _error(std::move(v.error))
        {
        }

        // Special error condition implicit constructor
        template <class ErrorCondEnum>
        requires(_implicit_constructors_enabled                                                                //
                 && std::is_error_condition_enum_v<ErrorCondEnum>                                              //
                 && !std::is_constructible_v<value_type, ErrorCondEnum>                                        //
                 && !std::is_constructible_v<error_type, ErrorCondEnum>                                        //
                 && !std::is_same_v<result, std::decay_t<ErrorCondEnum>>                                       //
                 && !detail::is_in_place_type_v<std::decay_t<ErrorCondEnum>>                                   //
                 && requires { error_type(make_error_code(ErrorCondEnum())); })                                //
        constexpr result(ErrorCondEnum && e) noexcept(noexcept(error_type(make_error_code(ErrorCondEnum()))))  //
        : _value(),
          _error(make_error_code(std::forward<ErrorCondEnum>(e)))
        {
        }

        // Explicit converting construction from compatible results
        template <class T, class U>                                  //
        requires(std::is_constructible_v<value_type, T>              //
                 && std::is_constructible_v<error_type, U>)          //
        constexpr explicit result(const result<T, U> &o)             //
        noexcept(std::is_nothrow_constructible_v<value_type, T>      //
                 && std::is_nothrow_constructible_v<error_type, U>)  //
        : _value(std::in_place, *o._value),
          _error(o._error)
        {
        }
        template <class T, class U>                                  //
        requires(std::is_constructible_v<value_type, T>              //
                 && std::is_constructible_v<error_type, U>)          //
        constexpr explicit result(result<T, U> && o)                 //
        noexcept(std::is_nothrow_constructible_v<value_type, T>      //
                 && std::is_nothrow_constructible_v<error_type, U>)  //
        : _value(std::in_place, std::move(*o._value)),
          _error(std::move(o._error))
        {
        }

        // State check observers
        constexpr explicit operator bool() const noexcept { return _value.has_value(); }
        constexpr bool has_value() const noexcept { return _value.has_value(); }
        constexpr bool has_error() const noexcept { return !_value.has_value(); }

        // Narrow state observers
        constexpr const _value_type &assume_value() const &noexcept
        {
          if(!has_value())
            __builtin_unreachable();
          return *_value;
        }
        constexpr _value_type &assume_value() & noexcept
        {
          if(!has_value())
            __builtin_unreachable();
          return *_value;
        }
        constexpr const _value_type &&assume_value() const &&noexcept
        {
          if(!has_value())
            __builtin_unreachable();
          return std::move(*_value);
        }
        constexpr _value_type &&assume_value() && noexcept
        {
          if(!has_value())
            __builtin_unreachable();
          return std::move(*_value);
        }

        constexpr const error_type &assume_error() const &noexcept
        {
          if(!has_error())
            __builtin_unreachable();
          return _error;
        }
        constexpr error_type &assume_error() & noexcept
        {
          if(!has_error())
            __builtin_unreachable();
          return _error;
        }
        constexpr const error_type &&assume_error() const &&noexcept
        {
          if(!has_error())
            __builtin_unreachable();
          return std::move(_error);
        }
        constexpr error_type &&assume_error() && noexcept
        {
          if(!has_error())
            __builtin_unreachable();
          return std::move(_error);
        }

        // Wide state observers
        constexpr const _value_type &value() const &
        {
          if(has_error())
            detail::throw_exception(_error);
          return *_value;
        }
        constexpr _value_type &value() &
        {
          if(has_error())
            detail::throw_exception(_error);
          return *_value;
        }
        constexpr const _value_type &&value() const &&
        {
          if(has_error())
            detail::throw_exception(_error);
          return std::move(*_value);
        }
        constexpr _value_type &&value() &&
        {
          if(has_error())
            detail::throw_exception(_error);
          return std::move(*_value);
        }

        constexpr const error_type &error() const &
        {
          if(!has_error())
            throw bad_result_access("no error");
          return _error;
        }
        constexpr error_type &error() &
        {
          if(!has_error())
            throw bad_result_access("no error");
          return _error;
        }
        constexpr const error_type &&error() const &&
        {
          if(!has_error())
            throw bad_result_access("no error");
          return std::move(_error);
        }
        constexpr error_type &&error() &&
        {
          if(!has_error())
            throw bad_result_access("no error");
          return std::move(_error);
        }

        // Modifiers
        constexpr void swap(result & o) noexcept(std::is_nothrow_swappable_v<value_type> && std::is_nothrow_swappable_v<error_type>)
        {
          swap(_value, o._value);
          swap(_error, o._error);
        }
        constexpr failure<error_type> as_failure() const &noexcept(std::is_nothrow_copy_constructible_v<error_type>) { return failure(_error); }
        constexpr failure<error_type> as_failure() && noexcept(std::is_nothrow_copy_constructible_v<error_type>) { return failure(std::move(_error)); }

        // Comparison to compatible results
        template <class T, class U>  //
        requires(requires {
          _value_type() == _devoid<T>();
          error_type() == U();
        })  //
        constexpr bool
        operator==(const result<T, U> &o) const noexcept(noexcept(_value_type() == _devoid<T>()) && noexcept(error_type() == U()))
        {
          return _value == o._value && _error == o._error;
        }
        template <class T, class U>  //
        requires(!requires {
          _value_type() == _devoid<T>();
          error_type() == U();
        })  //
        constexpr bool
        operator==(const result<T, U> & /*unused*/) const noexcept
        {
          return false;
        }

        template <class T>                                     //
        requires(requires { _value_type() == _devoid<T>(); })  //
        constexpr bool
        operator==(const success<T> &o) const noexcept(noexcept(_value_type() == _devoid<T>()))
        {
          return _value == o.value;
        }
        template <class T>                                      //
        requires(!requires { _value_type() == _devoid<T>(); })  //
        constexpr bool
        operator==(const success<T> & /*unused*/) const noexcept
        {
          return false;
        }

        template <class T>                           //
        requires(requires { error_type() == T(); })  //
        constexpr bool
        operator==(const failure<T> &o) const noexcept(noexcept(error_type() == T()))
        {
          return _error == o.error;
        }
        template <class T>                            //
        requires(!requires { error_type() == T(); })  //
        constexpr bool
        operator==(const failure<T> & /*unused*/) const noexcept
        {
          return false;
        }

        template <class T, class U>
        requires(requires {
          _value_type() != _devoid<T>();
          error_type() != U();
        })  //
        constexpr bool
        operator!=(const result<T, U> &o) const noexcept(noexcept(_value_type() != _devoid<T>()) && noexcept(error_type() != U()))
        {
          return _value != o._value || _error != o._error;
        }
        template <class T, class U>
        requires(!requires {
          _value_type() != _devoid<T>();
          error_type() != U();
        })  //
        constexpr bool
        operator!=(const result<T, U> &o) const noexcept
        {
          return true;
        }

        template <class T>                                     //
        requires(requires { _value_type() != _devoid<T>(); })  //
        constexpr bool
        operator!=(const success<T> &o) const noexcept(noexcept(_value_type() != _devoid<T>()))
        {
          return _value != o.value;
        }
        template <class T>                                      //
        requires(!requires { _value_type() != _devoid<T>(); })  //
        constexpr bool
        operator!=(const success<T> & /*unused*/) const noexcept
        {
          return true;
        }

        template <class T>                           //
        requires(requires { error_type() != T(); })  //
        constexpr bool
        operator!=(const failure<T> &o) const noexcept(noexcept(error_type() != T()))
        {
          return _error != o.error;
        }
        template <class T>                            //
        requires(!requires { error_type() != T(); })  //
        constexpr bool
        operator!=(const failure<T> & /*unused*/) const noexcept
        {
          return true;
        }
      };
      //! Calls b == a
      template <class T, class U, class V> constexpr inline bool operator==(const success<V> &a, const result<T, U> &b) noexcept(noexcept(b == a)) { return b == a; }
      //! Calls b == a
      template <class T, class U, class V> constexpr inline bool operator==(const failure<V> &a, const result<T, U> &b) noexcept(noexcept(b == a)) { return b == a; }
      //! Calls b != a
      template <class T, class U, class V> constexpr inline bool operator!=(const success<V> &a, const result<T, U> &b) noexcept(noexcept(b == a)) { return b != a; }
      //! Calls b != a
      template <class T, class U, class V> constexpr inline bool operator!=(const failure<V> &a, const result<T, U> &b) noexcept(noexcept(b == a)) { return b != a; }

      /*! Utility function which tries to match the exception in the pointer provided
      to an equivalent error code. Ought to work for all standard STL types.
      \param e The pointer to an exception to convert. If matched, on exit this is
      reset to a null pointer.
      \param not_matched The error code to return if we could not match the exception.
      Note that a null pointer in returns a null error code.

      \effects Rethrows the exception in the pointer, and via a long sequence of `catch`
      clauses attempts to match the equivalent error code. If a match is found, the
      pointer is reset to null. If a match is not found, *not_matched* is returned instead
      and the pointer is left unmodified.
      */
      inline std::error_code error_from_exception(std::exception_ptr &&ep = std::current_exception(), std::error_code not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept
      {
        if(!ep)
        {
          return {};
        }
        try
        {
          std::rethrow_exception(ep);
        }
        catch(const std::invalid_argument & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::invalid_argument);
        }
        catch(const std::domain_error & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::argument_out_of_domain);
        }
        catch(const std::length_error & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::argument_list_too_long);
        }
        catch(const std::out_of_range & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::result_out_of_range);
        }
        catch(const std::logic_error & /*unused*/) /* base class for this group */
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::invalid_argument);
        }
        catch(const std::system_error &e) /* also catches ios::failure */
        {
          ep = std::exception_ptr();
          return e.code();
        }
        catch(const std::overflow_error & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::value_too_large);
        }
        catch(const std::range_error & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::result_out_of_range);
        }
        catch(const std::runtime_error & /*unused*/) /* base class for this group */
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::resource_unavailable_try_again);
        }
        catch(const std::bad_alloc & /*unused*/)
        {
          ep = std::exception_ptr();
          return std::make_error_code(std::errc::not_enough_memory);
        }
        catch(...)
        {
        }
        return not_matched;
      }

#if 0
      /* Sample try operator overload (see Pxxxx)

         result<int> foo();
         result<std::string> func()
         {
           int g = try foo();  --> operator try(decltype(foo())) overload available?
                                   If so then:
                                   auto &&a = operator try(decltype(foo()));
                                   if(a.return_immediately())
                                     return a.return_value();
                               g = std::move(a).value();
           return std::to_string(g);
         }
      */
      auto operator try(const std::exception_ptr &e)
      {
        struct tryer
        {
          const std::exception_ptr &e;

          bool return_immediately() noexcept { return static_cast<bool>(e); }
          void return_value()  // void return only causes compile error if this function can return
          {
            std::rethrow_exception(e);
          }
          void value() {}  // void return prevents assignment of try result
        };
        return tryer{std::move(e)};
      }
      // Overload the try operator for result
      template <class T, class U> constexpr auto operator try(const result<T, U> &v) noexcept
      {
        struct tryer
        {
          const result<T, U> &v;

          // Note the constexpr, this makes operator try constexpr too
          constexpr bool return_immediately() noexcept { return v.has_error(); }
          // Extract the error, return it wrapped in failure type sugar
          constexpr failure<U> return_value() { return v.as_failure(); }
          // Extract the value
          constexpr const T &value() { return v.assume_value(); }
        };
        return tryer{v};
      }
      template <class T, class U> constexpr auto operator try(result<T, U> &&v) noexcept
      {
        struct tryer
        {
          result<T, U> &&v;

          constexpr bool return_immediately() noexcept { return v.has_error(); }
          constexpr failure<U> return_value() { return std::move(v).as_failure(); }
          constexpr T &&value() { return std::move(v).assume_value(); }
        };
        return tryer{std::move(v)};
      }
      template <class T> constexpr auto operator try(optional<T> &&v) noexcept
      {
        struct tryer
        {
          optional<T> &&v;

          constexpr bool return_immediately() noexcept { return !v.has_value(); }
          constexpr failure<void> return_value() { return failure<void>{}; }
          constexpr T &&value() { return *v; }
        };
        return tryer{std::move(v)};
      }
      template<typename T>
      concept ValueOrError = requires(T a) {
        { a.has_value(); a.value(); a.error(); };
      };
      template <ValueOrError T>
      constexpr auto operator try(T &&v) noexcept
      {
        struct tryer
        {
          T &&v;

          constexpr bool try_return_immediately() const noexcept { return !v.has_value(); }
          constexpr auto try_return_value() { return std::move(v).error(); }
          constexpr auto try_value() { return std::move(v).value(); }
        };
        return tryer{ std::move(v) };
      }
#endif
    }
  }
}

#endif

#endif
