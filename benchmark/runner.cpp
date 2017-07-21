#include "timing.h"
#include "../include/outcome/result.hpp"
#include <stdio.h>
#include <exception>
#include "function.h"

#define ITERATIONS 100000
#define CPU_US_PER_CLOCK (1000000000000.0/(3292.0*1000000.0))

extern volatile int counter;
volatile int counter, forcereturn;

int main(void)
{
  usCount start=GetUsCount();
  while(GetUsCount()-start<1*1000000000000LL);
  start=GetUsCount();
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
  double time=GetUsCount()-start;
  time/=ITERATIONS;
  double ticks=time/CPU_US_PER_CLOCK/*/NESTING*/;
  printf("%f\n", ticks);
  return 0;
}
