/* -*- C++ -*-  */
/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 * time.h => Windows Is Not Posix version
 */
#ifndef   	TIME_WINU_H_
# define   	TIME_WINU_H_

# include <bn/rt/rttime.hpp>
# include <pthread.h>


/**
 * missing function under windows
 *
 * for windows: use QueryPerformanceCounter/QueryPerformanceFrequency to get precise time
 *
 */

# ifdef WIN32
#  include <sys/timeb.h>
#  include <sys/types.h>
#  include <winsock.h>

#  define CLOCK_MONOTONIC (0)
#  define CLOCK_REALTIME (0)
#  define CLOCK_PROCESS_CPUTIME_ID (0)
#  define CLOCK_THREAD_CPUTIME_ID (0)

#  define TIMER_ABSTIME (0)

inline int clock_getres(int clk, struct timespec *tm)
{
  return 0;
}

inline int clock_gettime(int clk, struct timespec *tm)
{
  struct _timeb timebuffer;

  _ftime64_s(&timebuffer);
  tm->tv_sec = (long)timebuffer.time;
  tm->tv_nsec = timebuffer.millitm * 1000 * 1000;
  return 0;
}

inline int clock_nanosleep(int clk, int flag, const struct timespec *tm, struct timespec *tm2)
{
  struct timespec t1;
  long diff;
  int diffms = 0;

  clock_gettime(0, &t1);
  diff = bn::rt::timespec_diff_ns(*tm, t1);
  diffms = diff / 1000 / 1000;
  if (diffms > 0)
    Sleep(diffms);
  return 0;
}

inline int nanosleep(const struct timespec *tm, const struct timespec *tm2)
{
  Sleep((tm->tv_nsec / (1000 * 1000)) + (tm->tv_sec*1000));
  return 0;
}
# endif

#endif
