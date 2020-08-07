/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010, 2011 Aldebaran Robotics
*/

#ifndef   	PROCESSSYNCCLIENT_PIPE_HPP_
# define   	PROCESSSYNCCLIENT_PIPE_HPP_

namespace bn {

  /**
   * Sync a client and a server, the client will run
   * when the server allow him to run
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
  class ProcessSyncClientPipe {
  public:
    ProcessSyncClientPipe(const std::string &name);

    void notify_end_of_before() {
      notify_end_of(false);
    }
    void notify_end_of_after() {
      notify_end_of(true);
    }
    bool timed_wait_for_before(unsigned long usTimeout) {
      return timed_wait_for(usTimeout, false);
    }
    bool timed_wait_for_after(unsigned long usTimeout) {
      return timed_wait_for(usTimeout, true);
    }

  private:
    static const char NO_SESSION = 0;
    bool timed_wait_for(unsigned long usTimeout, bool wait_for_after);
    void notify_end_of(bool end_of_after);
    char _sessionId;
    int _server;
    int _client;
  };

};

#endif	    /* !PROCESSSYNCCLIENT_PP_ */
