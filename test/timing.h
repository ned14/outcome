/* timing.h

*/

#ifndef TIMING_H
#define TIMING_H

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
typedef unsigned __int64 usCount;
static usCount GetUsCount()
{
	static LARGE_INTEGER ticksPerSec;
	static double scalefactor;
	LARGE_INTEGER val;
	if(!scalefactor)
	{
		if(QueryPerformanceFrequency(&ticksPerSec))
			scalefactor=ticksPerSec.QuadPart/1000000000000.0;
		else
			scalefactor=1;
	}
	if(!QueryPerformanceCounter(&val))
		return (usCount) GetTickCount() * 1000000000;
	return (usCount) (val.QuadPart/scalefactor);
}
#else
#include <sys/time.h>
#include <time.h>
typedef unsigned long long usCount;
static usCount GetUsCount()
{
#ifdef CLOCK_MONOTONIC
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ((usCount) ts.tv_sec*1000000000000LL)+ts.tv_nsec*1000LL;
#else
	struct timeval tv;
	gettimeofday(&tv, 0);
	return ((usCount) tv.tv_sec*1000000000000LL)+tv.tv_usec*1000000LL;
#endif
}
#endif
#endif
