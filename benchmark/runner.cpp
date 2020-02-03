/* Benchmark test runner
(C) 2017-2020 Niall Douglas <http://www.nedproductions.biz/> (7 commits)
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

#include "timing.h"
#include <stdio.h>
#include "function.h"
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS)
#include <exception>
#endif

#define ITERATIONS 100000

extern volatile int counter;
volatile int counter, forcereturn;

int main(void)
{
#ifdef _WIN32
  SetThreadAffinityMask(GetCurrentThread(), 2ULL);
#endif
  {
    usCount start=GetUsCount();
    while(GetUsCount()-start<1*1000000000000LL);
  }
  auto start = ticksclock();
  for(int n=0; n<ITERATIONS; n++)
  {
#if !defined(_CPPUNWIND) && !defined(__EXCEPTIONS)
    forcereturn += !FUNCTION(n);
#else
    try
    {
      forcereturn += !FUNCTION(n);
    }
    catch(const std::exception &)
    {
    }
#endif
  }
  auto end = ticksclock();
  double ticks=end-start;
  ticks/=ITERATIONS;
  printf("%f\n", ticks);
  return 0;
}
