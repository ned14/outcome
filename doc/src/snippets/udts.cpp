/* Example of Outcome used with UDTs
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (3 commits)


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

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  //! [udts]
  struct udt
  {
    int a{0};
    explicit udt(int _a)
        : a(_a)
    {
    }
    udt() = default;
    int operator*() const { return a; }
  };

  struct err
  {
    int a{0};
    explicit err(int _a)
        : a(_a)
    {
    }
    err() = default;
  };
//! [udts]
#if 0
//! [implicit]
  result<udt, err> res(5);  // fails to compile, cannot convert 'int' to result
//! [implicit]
  //! [explicit]
  // When it is not unambiguous which to construct, we must say which we want same as with std::variant<>
  result<udt, err> res(in_place_type<err>, 5);
  //! [explicit]
#endif
  //! [access]
  result<udt, err, policy::terminate> res(in_place_type<err>, 5);

  // What happens here? What exception type is thrown?
  try
  {
    std::cout << *res.value() << std::endl;
  }
  catch(const std::exception &e)
  {
    std::cerr << "Exception thrown was " << e.what() << std::endl;
  }
  //! [access]
  return 0;
}