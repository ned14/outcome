/* Example of Outcome try used with foreign object
(C) 2019 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

#include "../../../include/outcome.hpp"

#include <iostream>

namespace outcome = OUTCOME_V2_NAMESPACE;

//! [foreign_type]
enum Errc
{
  kBadValue
};
template <class T, class E = Errc> struct ForeignExpected
{
  T Value;
  E Error;
  int IsErrored;

  ForeignExpected(T v)
      : Value(v)
      , Error()
      , IsErrored(0)
  {
  }
  ForeignExpected(E e)
      : Value()
      , Error(e)
      , IsErrored(1)
  {
  }
};
//! [foreign_type]

//! [tell_outcome]
OUTCOME_V2_NAMESPACE_BEGIN
template <class T, class E>  //
inline bool try_operation_has_value(const ForeignExpected<T, E> &v)
{
  return 0 == v.IsErrored;
}
template <class T, class E>  //
inline auto try_operation_return_as(const ForeignExpected<T, E> &v)
{
  switch(v.Error)
  {
  case kBadValue:
    return failure(make_error_code(std::errc::argument_out_of_domain));
  }
  abort();
}
template <class T, class E>  //
inline auto try_operation_extract_value(const ForeignExpected<T, E> &v)
{
  return v.Value;
}
OUTCOME_V2_NAMESPACE_END
//! [tell_outcome]

//! [functions]
ForeignExpected<int> old_code(int a)  // old code
{
  if(0 == a)
    return kBadValue;
  return a;
}

outcome::result<int> new_code(int a)  // new code
{
  OUTCOME_TRY(auto x, old_code(a));
  return x;
}
//! [functions]

int main()
{
  //! [example]
  auto printresult = [](const char *desc, auto x) {
    if(x)
    {
      std::cout << desc << " returns successful " << x.value() << std::endl;
    }
    else
    {
      std::cout << desc << " returns failure " << x.error().message() << std::endl;
    }
  };
  printresult("\nnew_code(5)", new_code(5));
  printresult("\nnew_code(0)", new_code(0));
  //! [example]
  return 0;
}
