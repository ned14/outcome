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
