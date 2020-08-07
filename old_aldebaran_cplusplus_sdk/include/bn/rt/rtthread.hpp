/* -*- C++ -*-  */
/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef   	__RTTHREAD_HPP_
# define   	__RTTHREAD_HPP_

# include <pthread.h>
# include <time.h>
# include <bn/rt.hpp>

namespace bn {
namespace rt {

class RtThread : public RtPeriod {
public:
  typedef void *(funcptr)(void *);

public:
  RtThread();

  /**
   * set the realtime capability of the thread
   * scheduler maybe:
   * SCHED_OTHER: system scheduler
   * SCHED_FIFO : execute the thread til a blocking function (or preemption by a higher priority function)
   * SCHED_RR   : same as FIFO, but dont execute for more than a timeslice (less agressive for the system)
   * rtprio have no impact when using SCHED_OTHER
   */
  int setRealtime(int scheduler, int rtprio);

  /**
   *  set the thread name (only available on linux > 2.6.9)
   */
  int setName(const char *name);

  /**
   * Create the thread
   */
  int create();

  /**
   * Join the thread
   */
  int join();


public:
  virtual void *execute() = 0;
  virtual void postExecute() {;}
  virtual void preExecute() {;}

protected:
  int                   fUsedClock;
  pthread_attr_t        fAttr;
  pthread_t             fThread;
};

}
}

#endif

