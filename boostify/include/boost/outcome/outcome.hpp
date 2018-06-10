/* A less simple result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: June 2017
*/

#ifndef BOOST_OUTCOME_OUTCOME_HPP
#define BOOST_OUTCOME_OUTCOME_HPP

#include "result.hpp"
#include "boost_outcome.hpp"

BOOST_OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

/*! In standalone Outcome, this aliases `std_outcome<>`. In Boost.Outcome, this aliases `boost_outcome<>`.
*/
template <class R, class S = boost::system::error_code, class P = boost::exception_ptr, class NoValuePolicy = policy::default_policy<R, S, P>>  //
using outcome = boost_outcome<R, S, P, NoValuePolicy>;

BOOST_OUTCOME_V2_NAMESPACE_END

#endif
