/* Traits for Outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: March 2018


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

#ifndef OUTCOME_TRAIT_HPP
#define OUTCOME_TRAIT_HPP

#include "config.hpp"

OUTCOME_V2_NAMESPACE_BEGIN

//! Namespace for traits
namespace trait
{
  /*! Requirements predicate for permitting type to be used in `basic_result`/`basic_outcome`.

  - Is not a reference.
  - Is not an `in_place_type_t<>`.
  - Is not a `success_type<>`.
  - Is not a `failure_type<>`.
  - Is not an array.
  - Is `void`, or else is an Object and is Destructible.
  */
  template <class R>                                                             //
  static constexpr bool type_can_be_used_in_basic_result =                       //
  (!std::is_reference<R>::value                                                  //
   && !OUTCOME_V2_NAMESPACE::detail::is_in_place_type_t<std::decay_t<R>>::value  //
   && !is_success_type<R>                                                        //
   && !is_failure_type<R>                                                        //
   && !std::is_array<R>::value                                                   //
   && (std::is_void<R>::value || (std::is_object<R>::value                       //
                                  && std::is_destructible<R>::value))            //
   );

  /*! Trait for whether a type is an error type or not. This is specialised by
  later code to enable implicit conversion for when the value type is `bool` and the
  error type is convertible to `bool`, something which ordinarily would disable
  all implicit constructors.
  */
  template <class E> struct is_error_type
  {
    static constexpr bool value = false;
  };

  /*! Trait for whether a type is an error type enum or not. This is specialised by
  later code to enable implicit conversion from such enum types.
  \tparam E The error type.
  \tparam Enum The enum type.
  */
  template <class E, class Enum> struct is_error_type_enum
  {
    static constexpr bool value = false;
  };

  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;
    template <class T> std::add_rvalue_reference_t<devoid<T>> declval() noexcept;

    // From http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf
    namespace detector_impl
    {
      template <class...> using void_t = void;
      template <class Default, class, template <class...> class Op, class... Args> struct detector
      {
        static constexpr bool value = false;
        using type = Default;
      };
      template <class Default, template <class...> class Op, class... Args> struct detector<Default, void_t<Op<Args...>>, Op, Args...>
      {
        static constexpr bool value = true;
        using type = Op<Args...>;
      };
    }  // namespace detector_impl
    template <template <class...> class Op, class... Args> using is_detected = detector_impl::detector<void, void, Op, Args...>;

    template <class Arg> using result_of_make_error_code = decltype(make_error_code(declval<Arg>()));
    template <class Arg> using introspect_make_error_code = is_detected<result_of_make_error_code, Arg>;

    template <class Arg> using result_of_make_exception_ptr = decltype(make_exception_ptr(declval<Arg>()));
    template <class Arg> using introspect_make_exception_ptr = is_detected<result_of_make_exception_ptr, Arg>;

    template <class T> struct _is_error_code_available
    {
      static constexpr bool value = detail::introspect_make_error_code<T>::value;
    };
    template <class T> struct _is_exception_ptr_available
    {
      static constexpr bool value = detail::introspect_make_exception_ptr<T>::value;
    };
  }  // namespace detail

  /*! Trait for whether a free function `make_error_code(T)` exists or not.
  Also true for `std::error_code` and `boost::system::error_code`.
  */
  template <class T> struct is_error_code_available
  {
    static constexpr bool value = detail::_is_error_code_available<std::decay_t<T>>::value;
  };
  template <class T> constexpr bool is_error_code_available_v = detail::_is_error_code_available<std::decay_t<T>>::value;

  /*! Trait for whether a free function `make_exception_ptr(T)` exists or not.
  Also true for `std::exception_ptr` and `boost::exception_ptr`.
  */
  template <class T> struct is_exception_ptr_available
  {
    static constexpr bool value = detail::_is_exception_ptr_available<std::decay<T>>::value;
  };
  template <class T> constexpr bool is_exception_ptr_available_v = detail::_is_exception_ptr_available<std::decay<T>>::value;


}  // namespace trait

OUTCOME_V2_NAMESPACE_END

#endif
