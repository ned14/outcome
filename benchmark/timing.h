/* Benchmark test runner
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (3 commits)
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

#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <intrin.h>
#include <windows.h>
typedef unsigned __int64 usCount;
inline usCount GetUsCount()
{
  static LARGE_INTEGER ticksPerSec;
  static double scalefactor;
  LARGE_INTEGER val;
  if(!scalefactor)
  {
    if(QueryPerformanceFrequency(&ticksPerSec))
      scalefactor = ticksPerSec.QuadPart / 1000000000000.0;
    else
      scalefactor = 1;
  }
  if(!QueryPerformanceCounter(&val))
    return (usCount) GetTickCount() * 1000000000;
  return (usCount)(val.QuadPart / scalefactor);
}
#else
#include <sys/time.h>
#include <time.h>
typedef unsigned long long usCount;
inline usCount GetUsCount()
{
#ifdef CLOCK_MONOTONIC
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ((usCount) ts.tv_sec * 1000000000000LL) + ts.tv_nsec * 1000LL;
#else
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((usCount) tv.tv_sec * 1000000000000LL) + tv.tv_usec * 1000000LL;
#endif
}
#endif


inline uint64_t ticksclock()
{
#ifdef _MSC_VER
  auto rdtscp = [] {
    unsigned x;
    return (uint64_t) __rdtscp(&x);
  };
#else
#if defined(__x86_64__)
  auto rdtscp = [] {
    unsigned lo, hi, aux;
    asm volatile("rdtscp" : "=a"(lo), "=d"(hi), "=c"(aux));
    return (uint64_t) lo | ((uint64_t) hi << 32);
  };
#elif defined(__i386__)
  auto rdtscp = [] {
    unsigned lo, hi, aux;
    asm volatile("rdtscp" : "=a"(lo), "=d"(hi), "=c"(aux));
    return (uint64_t) lo | ((uint64_t) hi << 32);
  };
#endif
#if __ARM_ARCH >= 6
  auto rdtscp = [] {
    unsigned count;
    asm volatile("MRC p15, 0, %0, c9, c13, 0" : "=r"(count));
    return (uint64_t) count * 64;
  };
#endif
#endif
  return rdtscp();
}

#if defined(__cplusplus) && 0
#include <chrono>
#include <iostream>

inline uint64_t nanoclock()
{
  static double ticks_per_sec;
  static uint64_t offset;
  if(ticks_per_sec == 0)
  {
    auto end = std::chrono::high_resolution_clock::now(), begin = std::chrono::high_resolution_clock::now();
    uint64_t _begin = ticksclock(), _end;
    do
    {
      end = std::chrono::high_resolution_clock::now();
    } while(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() < 1);
    _end = ticksclock();
    double x = (double) (_end - _begin);
    ticks_per_sec = x / 1000000000.0;
    volatile uint64_t a = ticksclock();
    volatile uint64_t b = ticksclock();
    offset = b - a;
#if 1
    std::cout << "There are " << ticks_per_sec << " TSCs in 1 nanosecond and it takes " << offset << " ticks per nanoclock()." << std::endl;
#endif
  }
  return (uint64_t)((ticksclock() - offset) / ticks_per_sec);
}
#endif

#endif
