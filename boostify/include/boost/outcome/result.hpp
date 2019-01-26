/* A very simple result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: June 2017
*/

#ifndef BOOST_OUTCOME_RESULT_HPP
#define BOOST_OUTCOME_RESULT_HPP

#include "boost_result.hpp"

BOOST_OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

/*! In standalone Outcome, this aliases `std_result<>`. In Boost.Outcome, this aliases `boost_result<>`.
*/
template <class R, class S = boost::system::error_code, class NoValuePolicy = policy::default_policy<R, S, void>>  //
using result = boost_result<R, S, NoValuePolicy>;

/*! In standalone Outcome, this aliases `std_unchecked<>`. In Boost.Outcome, this aliases `boost_checked<>`.
*/
template <class R, class S = boost::system::error_code> using unchecked = result<R, S, policy::all_narrow>;

/*! In standalone Outcome, this aliases `std_checked<>`. In Boost.Outcome, this aliases `boost_checked<>`.
*/
template <class R, class S = boost::system::error_code> using checked = result<R, S, policy::throw_bad_result_access<S, void>>;

BOOST_OUTCOME_V2_NAMESPACE_END

#endif
