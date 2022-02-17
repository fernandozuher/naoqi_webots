/*
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#ifndef   	PROCESSSYNCCLIENT_HPP_
# define   	PROCESSSYNCCLIENT_HPP_

#include <bn/ipc/processsync.hpp>

namespace bn {

  /**
   * Sync a client and a server, the client will run when the server allow him to run
   *
   * This work that way:
   *
   * ProcessSyncClient cs("hal::sync");
   *
   * while (1) {
   *   //wait that the server notify us
   *   cs.wait_to_work();
   *   //wait 200us
   *   cs.timed_wait_to_work(200);
   *   //DO THE WORK
   *   cs.notify_end_of_work();
   * }
   */
  class ProcessSyncClient : public detail::ProcessSync {
  public:
    ProcessSyncClient(const std::string &name) :
      detail::ProcessSync(boost::interprocess::open_only, name)
    {
    }
    void notify_end_of_before() {
      cond_before_client.notify_all();
    }
    void notify_end_of_after() {
      cond_after_client.notify_all();
    }
    bool timed_wait_for_before(unsigned long usTimeout) {
      return timed_wait(cond_before_server, usTimeout);
    }
    bool timed_wait_for_after(unsigned long usTimeout) {
      return timed_wait(cond_after_server, usTimeout);
    }
  };
};

#endif	    /* !PROCESSSYNCCLIENT_PP_ */
