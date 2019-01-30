/* A less simple result type
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Apr 2018


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

#ifndef OUTCOME_EXPERIMENTAL_STATUS_OUTCOME_HPP
#define OUTCOME_EXPERIMENTAL_STATUS_OUTCOME_HPP

#include "../basic_outcome.hpp"

#include "../detail/trait_std_error_code.hpp"  // FIXME needed as the failure observers require trait::has_error_code<T>
#include "../detail/trait_std_exception.hpp"
#include "status_result.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  namespace adl
  {
    template <class DomainType> inline std::exception_ptr basic_outcome_failure_exception_from_error(const SYSTEM_ERROR2_NAMESPACE::status_code<DomainType> &sc, search_detail_adl /*unused*/)
    {
      (void) sc;
#ifdef __cpp_exceptions
      try
      {
        sc.throw_exception();
      }
      catch(...)
      {
        return std::current_exception();
      }
#endif
      return {};
    }
  }  // namespace adl
}  // namespace detail

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class DomainType> struct has_error_code<SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, void>
    {
      static constexpr bool value = true;
    };
    template <class T, class DomainType> struct has_error_code<T, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail
#if 0
  template <class DomainType> struct is_error_type<SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>>
  {
    static constexpr bool value = true;
  };
  template <> struct is_error_type<SYSTEM_ERROR2_NAMESPACE::errc>
  {
    static constexpr bool value = true;
  };
  template <class DomainType, class Enum> struct is_error_type_enum<SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, Enum>
  {
    static constexpr bool value = boost::system::is_error_condition_enum<Enum>::value;
  };
#endif
}  // namespace trait


//! Namespace for experimental features
namespace experimental
{
  //! Namespace for policies
  namespace policy
  {
    /*! Default policy selector.
    */
    template <class T, class EC, class E>
    using default_status_outcome_policy = std::conditional_t<                                                                                                                //
    std::is_void<EC>::value && std::is_void<E>::value,                                                                                                                       //
    OUTCOME_V2_NAMESPACE::policy::terminate,                                                                                                                                 //
    std::conditional_t<(is_status_code<EC>::value || is_errored_status_code<EC>::value) && (std::is_void<E>::value || OUTCOME_V2_NAMESPACE::trait::has_exception_ptr_v<E>),  //
                       status_code_throw<T, EC, E>,                                                                                                                          //
                       OUTCOME_V2_NAMESPACE::policy::fail_to_compile_observers                                                                                               //
                       >>;
  }  // namespace policy

  /*! TODO
  */
  template <class R, class S = system_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_status_outcome_policy<R, S, P>>  //
  using erased_outcome = basic_outcome<R, S, P, NoValuePolicy>;

  /*! TODO
  */
  template <class R, class DomainType = typename generic_code::domain_type, class P = std::exception_ptr, class NoValuePolicy = policy::default_status_outcome_policy<R, status_code<DomainType>, P>>  //
  using status_outcome = basic_outcome<R, status_code<DomainType>, P, NoValuePolicy>;

  //! Namespace for policies
  namespace policy
  {
    /*!
    */
    template <class T, class DomainType, class E> struct status_code_throw<T, status_code<DomainType>, E> : base
    {
      using _base = base;
      /*! Performs a wide check of state, used in the value() functions.
      \effects See description of class for effects.
      */
      template <class Impl> static constexpr void wide_value_check(Impl &&self)
      {
        if(!base::_has_value(static_cast<Impl &&>(self)))
        {
          if(base::_has_exception(static_cast<Impl &&>(self)))
          {
            OUTCOME_V2_NAMESPACE::policy::detail::_rethrow_exception<trait::has_exception_ptr_v<E>>(base::_exception<T, status_code<DomainType>, E, status_code_throw>(static_cast<Impl &&>(self)));  // NOLINT
          }
          if(base::_has_error(static_cast<Impl &&>(self)))
          {
#ifdef __cpp_exceptions
            base::_error(static_cast<Impl &&>(self)).throw_exception();
#else
            OUTCOME_THROW_EXCEPTION("wide value check failed");
#endif
          }
        }
      }
      /*! Performs a wide check of state, used in the error() functions
      \effects TODO
      */
      template <class Impl> static constexpr void wide_error_check(Impl &&self) { _base::narrow_error_check(static_cast<Impl &&>(self)); }
      /*! Performs a wide check of state, used in the exception() functions
      \effects TODO
      */
      template <class Impl> static constexpr void wide_exception_check(Impl &&self) { _base::narrow_exception_check(static_cast<Impl &&>(self)); }
    };
    template <class T, class DomainType, class E> struct status_code_throw<T, errored_status_code<DomainType>, E> : status_code_throw<T, status_code<DomainType>, E>
    {
      status_code_throw() = default;
      using status_code_throw<T, status_code<DomainType>, E>::status_code_throw;
    };
  }  // namespace policy

}  // namespace experimental

OUTCOME_V2_NAMESPACE_END

#endif
