/*
** time-osxp.h
** Login : <ctaf@localhost.localdomain>
** Started on  Wed Dec 10 18:04:54 2008 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2011 Aldebaran Robotics
*/

#ifndef   	TIME_OSXP_H_
# define   	TIME_OSXP_H_

# include <bn/rt.hpp>

/**
 * missing function under mac
 */
# ifdef __APPLE__
#include <sys/time.h>
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
  struct timeval tv;
  gettimeofday(&tv, 0);
  tm->tv_sec = tv.tv_sec;
  tm->tv_nsec = tv.tv_usec * 1000;
  return 0;
}

inline int clock_nanosleep(int clk, int flag, const struct timespec *tm, struct timespec *tm2)
{
  struct timespec t1;
  long diff;
  int diffus = 0;

  clock_gettime(0, &t1);
  diff = bn::rt::timespec_diff_ns(*tm, t1);
  diffus = diff / 1000;
  if (diffus > 0)
    usleep(diffus);
  return 0;
}

# endif

#endif 	    /* !TIME_OSXP_H_ */
