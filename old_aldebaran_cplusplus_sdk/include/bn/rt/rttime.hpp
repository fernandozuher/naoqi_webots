/* -*- C++ -*-  */
/**
 * @author Cedric GESTES, modifications Pierre-Emmanuel VIEL
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef   	RTTIME_HPP_
# define   	RTTIME_HPP_

#include <time.h>
#include <pthread.h>
#include <bn/rt.hpp>

namespace bn {
namespace rt {

static const long gUsecPerSec = 1000000;
static const long gNsecPerSec = 1000000000;

#ifndef CLOCK_MONOTONIC_RAW
#define CLOCK_MONOTONIC_RAW 4 // Bug in this linux version (should be in time.h)
#endif


/**
 * add two timespec
 */
inline struct timespec timespec_add(const struct timespec &ts, const struct timespec &ts2)
{
  struct timespec ret;

  ret.tv_sec = ts.tv_sec + ts2.tv_sec;
  ret.tv_nsec = ts.tv_nsec + ts2.tv_nsec;

  while (ret.tv_nsec >= gNsecPerSec) {
    ret.tv_nsec -= gNsecPerSec;
    ret.tv_sec++;
  }
  return ret;
}

/**
 * return the difference between t1 and t2 in nanosecond
 * t1: stop, t2: start
 */
inline long timespec_diff_ns(const struct timespec &t1, const struct timespec &t2)
{
  long diff;

  diff = (long)((long long)gNsecPerSec * (long long)(t1.tv_sec - t2.tv_sec));
  diff += t1.tv_nsec - t2.tv_nsec;
  return diff;
}

/**
 * return the difference between t1 and t2 in microsecond
 */
inline sInt32 timespec_diff_us(const struct timespec &t1, const struct timespec &t2)
{
  long diff;

  diff = (long)((long long)gUsecPerSec * (long long)(t1.tv_sec - t2.tv_sec));
  diff += ((long)((long long)(t1.tv_nsec - t2.tv_nsec)) / 1000);
  return diff;
}


/**
 * Encapsulation of the clock_gettime() function for precise time operations (nanoseconds).
 */
class RtTime {
public:
  /**
   * Default constructor.
   * @param clockType The type of clock used between
   * 0:CLOCK_REALTIME
   * 1:CLOCK_MONOTONIC
   * 2:CLOCK_PROCESS_CPUTIME_ID
   * 3:CLOCK_THREAD_CPUTIME_ID
   * 4:CLOCK_MONOTONIC_RAW
   *
   * If no argument is provided, the first available clock in this list is checked:
   * monotonic_raw, monotonic, realtime
   */
  RtTime(const int clockType = 0);

public:
  /**
   * Default start clock.
   */
  void          start();
  /**
   * Default stop clock.
   */
  void          stop();
  /**
   * User defined clock.
   * @param t The user defined timespec variable receiving the current time
   */
  void          getTime(timespec &t);
  /**
   * Difference between stop and start in ns.
   */
  uInt32        diffNs();

  /**
   * Difference between stop and start in ns.
   */
  uInt32        diffUs();

  /**
   * Returns the type of clock accepted by the kernel, that might be different from the one asked in the constructor
   */
  uInt32        getUsedClock();

  sInt32        absSleep(const timespec &tm)const;
  static sInt32 mSleep(const unsigned long sleepMs);
  static sInt32 uSleep(const unsigned long sleepUs);
  static sInt32 nSleep(const unsigned long sleepNs);

  static int    checkClock(int pClock);
  static int    getClock(const int clockType = 0);

private:
  uInt32        fUsedClock;
  timespec      fDiffStart;
  timespec      fDiffStop;
};


/**
 * Prints the time spent executing of `f' ; also prints a message `m' before.
 */
# define RTDIFF(m, f)						\
  {								\
    RtTime rtm;							\
    rtm.start();						\
    f;								\
    rtm.stop();							\
    std::cout << m << " " << rtm.diffNs() << "ns" << std::endl;	\
  }

}
}

#endif 	    /* !RTTIME_HPP_ */
