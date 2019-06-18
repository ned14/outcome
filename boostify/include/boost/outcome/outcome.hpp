/* A less simple result type
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (1 commit)
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
