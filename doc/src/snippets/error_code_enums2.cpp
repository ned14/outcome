/* Example of Outcome used with error code enums
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

//! [declaration]
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
enum class err
{
  success,
  failure1,
  failure2
};

// Tell the standard library that enum err is an error code enum
// by specialising the is_error_code_enum trait. See
// http://en.cppreference.com/w/cpp/error/error_code/is_error_code_enum
namespace std
{
  template <> struct is_error_code_enum<err> : std::true_type
  {
  };
}

// We also must declare a free function make_error_code. This is
// discovered via ADL by the standard library. See
// http://en.cppreference.com/w/cpp/error/errc/make_error_code
inline std::error_code make_error_code(err c)
{
  // We need to inherit from std::error_category to define
  // an error code domain with the standard library for
  // our strongly typed enum. See
  // http://en.cppreference.com/w/cpp/error/error_category
  static struct err_category : std::error_category
  {
    virtual const char *name() const noexcept override final { return "err_category"; };
    virtual std::string message(int c) const override final
    {
      switch(static_cast<err>(c))
      {
      case err::success:
        return "err::success";
      case err::failure1:
        return "err::failure1";
      case err::failure2:
        return "err::failure2";
      }
      return "unknown";
    }
  } category;
  return std::error_code(static_cast<int>(c), category);
}
//! [declaration]

using namespace OUTCOME_V2_NAMESPACE;

int main()
{
  //! [usage]
  result<udt, err> res(err::failure1);

  // What happens here? What exception type is thrown?
  try
  {
    std::cout << *res.value() << std::endl;
  }
  catch(const std::exception &e)
  {
    std::cerr << "Exception thrown was " << e.what() << std::endl;
  }
  //! [usage]
  return 0;
}

void test()
{
  //! [usage2]
  result<udt /*, std::error_code */> res(err::failure1);

  // What happens here? What exception type is thrown?
  try
  {
    std::cout << *res.value() << std::endl;
  }
  catch(const std::exception &e)
  {
    // Prints "Exception thrown was failure1", exactly the same as before
    std::cerr << "Exception thrown was " << e.what() << std::endl;
  }
  //! [usage2]
}

//! [usage3]
result<udt> boo()
{
  return err::failure1;
}
result<udt> foo()
{
  OUTCOME_TRY(auto v, (boo()));
  return udt{5};  // emplace construct udt with 5
}
//! [usage3]
