// Copyright 2015-2026 Niall Douglas <http://www.nedproductions.biz/>
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
//
// The smallest program which proves the library can be used: the header is found,
// the target links, and a result carrying a value can be asked for that value.
// Everything else belongs in test/tests.

#include <boost/outcome/result.hpp>

int main()
{
  boost::outcome_v2::result<int> r(42);
  return (r.has_value() && r.value() == 42) ? 0 : 1;
}
