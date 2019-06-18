/* Canned codegen quality test sequences
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (9 commits)


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

#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;

extern QUICKCPPLIB_NOINLINE option<int> test1(int n)
{
  return option<int>(n).next([](option<int> m) { return m.get()*3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1(5));
  test2();
  return m.get()!=15;
}
