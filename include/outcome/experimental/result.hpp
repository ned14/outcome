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

// C compatibility
#define CXX_DECLARE_RESULT(R)                                                                                                                                                                                                                                                                                                  \
  struct result_##R                                                                                                                                                                                                                                                                                                            \
  {                                                                                                                                                                                                                                                                                                                            \
    R value;                                                                                                                                                                                                                                                                                                                   \
    char flags;                                                                                                                                                                                                                                                                                                                \
    int error;                                                                                                                                                                                                                                                                                                                 \
    void *category;                                                                                                                                                                                                                                                                                                            \
  }
#define CXX_RESULT(R) struct result_##R
#define CXX_RESULT_HAS_VALUE(r) (((r).flags & 1) == 1)
#define CXX_RESULT_HAS_ERROR(r) (((r).flags & 1) == 0)


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

        // How to throw an error type
        inline void throw_exception(const std::error_code &ec) { throw std::system_error(ec); }
        inline void throw_exception(const std::exception_ptr &e) { std::rethrow_exception(e); }
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

      // A constexpr error code category
      struct cgeneric_category
      {
        const std::error_category &(*category)(){std::generic_category};
      };
      // A constexpr capable error code matching std::error_code with std::generic_category
      template <class Category> class cerror_code;
      template <> class cerror_code<cgeneric_category>
      {
        int _value;

      public:
        using category_type = cgeneric_category;

        constexpr cerror_code()
            : _value(0)
        {
        }
        constexpr cerror_code(std::errc e)
            : _value(static_cast<int>(e))
        {
        }
        constexpr explicit operator bool() const noexcept { return _value != 0; }
        constexpr void clear() { _value = 0; }
        constexpr int value() const noexcept { return _value; }

        const std::error_category &category() const noexcept { return category_type().category(); }
        std::error_condition default_error_condition() const noexcept { return category().default_error_condition(value()); }
        std::string message() const { return category().message(value()); }
      };

      namespace detail
      {
        // Test if type is a cerror_code
        template <class T> struct is_cerror_code_t : std::false_type
        {
        };
        template <class U> struct is_cerror_code_t<cerror_code<U>> : std::true_type
        {
        };
        template <class T> static constexpr bool is_cerror_code_v = is_cerror_code_t<T>::value;
      }

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

      NOTE: This reference implementation has these deviations from the proposed standard spec:

      1. Due to `std::optional`, triviality of copy and move is not propagated from `T` as per the spec.
      2. Due to `std::optional`, standard layout of `result<T>` is not propagated from `T` as per the spec.
      3. `value()` and `assume_value()` should return `void` when `R` is `void`, not `_void_type`.
      */
      template <class R, class S = std::error_code>             //
      requires(std::is_default_constructible_v<S>               //
               && (std::is_base_of_v<std::error_code, S>        //
                   || std::is_base_of_v<std::exception_ptr, S>  //
                   || detail::is_cerror_code_v<S>)              //
               )                                                //
      class[[nodiscard]] result
      {
        template <class T, class U> friend class result;

      public:
        using value_type = R;
        using error_type = S;

      protected:
        static constexpr bool _implicit_constructors_enabled =  //
        !std::is_constructible_v<value_type, error_type>        //
        && !std::is_constructible_v<error_type, value_type>;
        struct _void_type
        {
        };
        template <class T> using _devoid = std::conditional_t<std::is_void_v<T>, _void_type, T>;
        using _value_type = _devoid<value_type>;

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
        template <class A, class... Args>                                                                                   //
        requires(_implicit_constructors_enabled                                                                             //
                 && (sizeof...(Args) > 0 || (!std::is_same_v<result, std::decay_t<A>> && !detail::is_in_place_type_v<A>) )  //
                 && std::is_constructible_v<value_type, A, Args...>                                                         //
                 && !std::is_constructible_v<error_type, A, Args...>)                                                       //
        constexpr result(A && a, Args && ... args) noexcept(std::is_nothrow_constructible_v<value_type, A, Args...>)        //
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
        constexpr result(const success<void> &v) noexcept : _value(_void_type{}), _error() {}

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
        template <class A, class... Args>                                                                                   //
        requires(_implicit_constructors_enabled                                                                             //
                 && (sizeof...(Args) > 0 || (!std::is_same_v<result, std::decay_t<A>> && !detail::is_in_place_type_v<A>) )  //
                 && std::is_constructible_v<error_type, A, Args...>                                                         //
                 && !std::is_constructible_v<value_type, A, Args...>)                                                       //
        constexpr result(A && a, Args && ... args) noexcept(std::is_nothrow_constructible_v<error_type, A, Args...>)        //
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

#if 0
      // Sample default try operator
      template <class T, class U> auto operator try(const std::exception_ptr &e)
      {
        struct tryer
        {
          const std::exception_ptr &e;

          bool exits_immediately() noexcept { return static_cast<bool>(e); }
          void value()
          {
            if(!e)
              return;
            std::rethrow_exception(e);
          }
        };
        return tryer{std::move(e)};
      }
      // Overload the try operator for result
      template <class T, class U> constexpr auto operator try(const result<T, U> &v) noexcept
      {
        struct tryer
        {
          const result<T, U> &v;

          constexpr bool exits_immediately() noexcept { return true; }
          constexpr failure<U> value() noexcept(noexcept(v.as_failure())) { return v.as_failure(); }
        };
        return tryer{v};
      }
      template <class T, class U> constexpr auto operator try(result<T, U> &&v) noexcept
      {
        struct tryer
        {
          result<T, U> &&v;

          constexpr bool exits_immediately() noexcept { return true; }
          constexpr failure<U> value() noexcept(noexcept(v.as_failure())) { return std::move(v).as_failure(); }
        };
        return tryer{ std::move(v) };
      }
#endif
    }
  }
}

#endif

#endif
