/* The world's most simple C++ monad
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (2 commits)
File Created: Mar 2017


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

#ifndef BOOST_OUTCOME_BASIC_MONAD_NAME
#error Please do not include this directly, include monad.hpp
#endif

public:
//! \brief Default constructor
// template<bool enabled = is_default_constructible, typename = typename std::enable_if<enabled>::type> constexpr BOOST_OUTCOME_BASIC_MONAD_NAME() noexcept(is_nothrow_default_constructible)
//    : implementation_policy::base(typename implementation_policy::base::passthru_t())
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME() noexcept(is_nothrow_default_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t())
{
}
//! \brief Implicit constructor of an empty monad
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(empty_type) noexcept : implementation_policy::base(typename implementation_policy::base::passthru_t())
{
}
//! \brief Implicit constructor of an empty monad
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(empty_t _) noexcept : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
{
}
//! \brief Implicit constructor of a valued monad (default constructed)
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(value_t _) noexcept(std::is_nothrow_default_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
{
}
#if 0
  //! \brief Implicit constructor of an errored monad (default constructed)
  constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(error_t _) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
  {
  }
  //! \brief Implicit constructor of an excepted monad (default constructed)
  constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(exception_t _) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
  {
  }
#endif
//! \brief Implicit constructor from a value_type by copy
// template<bool enabled = std::is_copy_constructible<value_type>::value, typename = typename std::enable_if<enabled>::type> constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
//    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}
//! \brief Implicit constructor from a value_type by move
// template<bool enabled = std::is_move_constructible<value_type>::value, typename = typename std::enable_if<enabled>::type> constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
//    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}
/*! \brief Explicit constructor of a value_type allowing emplacement with no other means of construction. Only available
if value_type which can't be a monad can be constructed from Args and if either there is more than one Arg or the Arg is not a value_type, an
error_type, an exception_type nor an empty_type.
*/
#ifdef DOXYGEN_IS_IN_THE_HOUSE
template <class... Args> explicit constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(in_place_t, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Arg, Args...>::value);
#else
template <class Arg, class... Args>
constexpr explicit BOOST_OUTCOME_BASIC_MONAD_NAME(in_place_t, Arg &&arg, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Arg, Args...>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), typename value_storage_type::emplace_t(), std::forward<Arg>(arg), std::forward<Args>(args)...)
{
}
#endif
//! \brief Implicit constructor from an initializer list
template <class U>
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(in_place_t, std::initializer_list<U> l) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), typename value_storage_type::emplace_t(), std::move(l))
{
}
//! \brief Implicit constructor from an identically configured basic_monad<void> by copy
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const void_rebound &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}
//! \brief Implicit constructor from an identically configured basic_monad<void> by move
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(void_rebound &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}
#if 1  // Seems safe to leave these turned on
//! \brief Implicit constructor from a error_type by copy
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const error_type &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}
//! \brief Implicit constructor from a error_type by move
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(error_type &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}
//! \brief Implicit constructor from a exception_type by copy
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const exception_type &v) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}
//! \brief Implicit constructor from a exception_type by move
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(exception_type &&v) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}
#endif
private:
struct explicit_conversion_from_different_policy
{
};

public:
/*! \brief Explicit move constructor from a basic_monad with a differing implementation policy.
For this constructor to be available, value_type, error_type and exception_type must be identical
or constructible.
*/
template <class Policy, typename = typename std::enable_if<std::is_same<typename implementation_policy::value_type, typename Policy::value_type>::value || std::is_void<typename Policy::value_type>::value || std::is_constructible<typename implementation_policy::value_type, typename Policy::value_type>::value>::type,
          typename = typename std::enable_if<std::is_same<typename implementation_policy::error_type, typename Policy::error_type>::value || std::is_constructible<typename implementation_policy::error_type, typename Policy::error_type>::value>::type,
          typename = typename std::enable_if<std::is_same<typename implementation_policy::exception_type, typename Policy::exception_type>::value || std::is_constructible<typename implementation_policy::exception_type, typename Policy::exception_type>::value>::type>
constexpr explicit BOOST_OUTCOME_BASIC_MONAD_NAME(BOOST_OUTCOME_BASIC_MONAD_NAME<Policy> &&o, explicit_conversion_from_different_policy = explicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(o))
{
}
/*! \brief Explicit conversion constructor from a basic_monad with a differing implementation
policy. For this conversion to be available, value_type must be identical or constructible, error_type must be
identical, constructible or the source monad must have no error_type, and exception_type must be identical,
constructible or the source monad must have no exception_type.
*/
template <class Policy, typename = typename std::enable_if<!std::is_void<typename Policy::value_type>::value && _is_constructible<BOOST_OUTCOME_BASIC_MONAD_NAME<Policy>>::value>::type>
constexpr explicit BOOST_OUTCOME_BASIC_MONAD_NAME(const BOOST_OUTCOME_BASIC_MONAD_NAME<Policy> &o, explicit_conversion_from_different_policy = explicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}

private:
struct implicit_conversion_from_different_policy
{
};

public:
/*! \brief Implicit conversion constructor from a void basic_monad with a differing implementation policy.
For this constructor to be available, source monad's value_type must be void, error_type must be
identical, constructible or the source monad must have no error_type, and exception_type must be identical,
constructible or the source monad must have no exception_type.
*/
template <class Policy, typename = typename std::enable_if<std::is_void<typename Policy::value_type>::value && _is_constructible<BOOST_OUTCOME_BASIC_MONAD_NAME<Policy>>::value>::type>
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const BOOST_OUTCOME_BASIC_MONAD_NAME<Policy> &o, implicit_conversion_from_different_policy = implicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}
//! \brief Move constructor
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(BOOST_OUTCOME_BASIC_MONAD_NAME &&o) noexcept(is_nothrow_move_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(o))
{
}
//! \brief Copy constructor
constexpr BOOST_OUTCOME_BASIC_MONAD_NAME(const BOOST_OUTCOME_BASIC_MONAD_NAME &o) noexcept(is_nothrow_copy_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}
// \brief Move assignment
BOOST_OUTCOME_CONSTEXPR BOOST_OUTCOME_BASIC_MONAD_NAME &operator=(BOOST_OUTCOME_BASIC_MONAD_NAME &&) = default;
// \brief Copy assignment
BOOST_OUTCOME_CONSTEXPR BOOST_OUTCOME_BASIC_MONAD_NAME &operator=(const BOOST_OUTCOME_BASIC_MONAD_NAME &) = default;

#undef BOOST_OUTCOME_BASIC_MONAD_NAME
