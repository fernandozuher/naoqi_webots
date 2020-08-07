/* -*- C++ -*-  */
/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 */

#ifndef   	RTPERIOD_H_
# define   	RTPERIOD_H_

# include <bn/rt.hpp>
# include <time.h>

namespace bn {
namespace rt {

/**
 * @brief this class allow to create periodic loop or thread
 * set the period, then before the loop call periodInit
 * and loop on periodWait
 */
class RtPeriod {
public:
  RtPeriod();


  void setPeriod(const sInt32 uSec);


  /**
   * init the period
   */
  void periodInit();

/**
 * wait for the end of the timeslice (interval)
 * if the timeslice is already elapsed, it doesnt wait and return a negative value
 * @return the delta between the current time and the time we wanted (microsec)
 *
 * 1) get the current time, verify that we dont missed the deadline
 * 2) if (waittime > 1000us) wait till the end of the timeslice (if needed)
 * 3) update values for the next time
 */
  int periodWait();

/**
 * Call this function if you do not want a minimal wait of 1ms at every periodWait
 */
  void noMinimalWait();

protected:
  void computeStat();

protected:
  struct timespec       fNow;
  struct timespec       fNext;
  struct timespec       fInterval;
  int                   fUsedClock;

  ///stat
protected:
  sInt32                fCurrentDiff;
  sInt32                fCurrentWait;

  sInt32                fMinDiff;
  sInt32                fMinWait;

  sInt32                fMaxDiff;
  sInt32                fMaxWait;

  sInt32                fAvgDiff;
  sInt32                fAvgWait;

  uInt32                fTickCount;

  sInt32                fNoMinimanWait;

};

}
}

#endif 	    /* !RTPERIOD_H_ */
