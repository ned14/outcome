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

#include "../../single-header/outcome-experimental.hpp"

struct obj
{
  QUICKCPPLIB_NOINLINE ~obj() {}
};
extern int foo;
int foo;

using namespace OUTCOME_V2_NAMESPACE::experimental;

static_assert(OUTCOME_V2_NAMESPACE::trait::is_move_relocating<status_result<int>::error_type>::value, "system_code is not move relocating!");

static QUICKCPPLIB_NOINLINE status_result<int> src1() noexcept
{
  return errc::argument_out_of_domain;
}

extern QUICKCPPLIB_NOINLINE status_result<int> test1() noexcept
{
  obj x;
  OUTCOME_TRY(auto &&v, src1());
  foo = 0;
  return success(v);
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(test1()) ret=1;
  test2();
  return ret;
}
