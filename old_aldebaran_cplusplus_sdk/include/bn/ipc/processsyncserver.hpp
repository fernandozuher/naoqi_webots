/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#ifndef   	PROCESSSYNCSERVER_HPP_
# define   	PROCESSSYNCSERVER_HPP_

# include <bn/ipc/processsync.hpp>

namespace bn {

  /**
   * Sync a client and a server, the server allow the client to run
   * a timeout can be used to return before the end of the client run
   *
   * This work that way:
   *
   * ProcessSyncServer pss("hal::sync");
   *
   * while (1) {
   *   //ask client to run
   *   pss.run_client();
   *   //wait the client
   *   pss.wait_client();
   *   //wait the client (with a 2ms timeout)
   *   pss.timed_wait_client(2000);
   * }
   */
  class ProcessSyncServer : public detail::ProcessSync {
  public:
    ProcessSyncServer(const std::string &name) :
      detail::ProcessSync(boost::interprocess::create_only, name)
    {
    }
    void send_before() {
      cond_before_server.notify_all();
    }
    void send_after() {
      cond_after_server.notify_all();
    }
    void resend_before() {
      send_before();
    }
    void resend_after() {
      send_after();
    }
    bool timed_wait_for_before(unsigned long usTimeout) {
      return timed_wait(cond_before_client, usTimeout);
    }
    bool timed_wait_for_after(unsigned long usTimeout) {
      return timed_wait(cond_after_client, usTimeout);
    }
  };
}


#endif	    /* !PROCESSSYNCSERVER_PP_ */
