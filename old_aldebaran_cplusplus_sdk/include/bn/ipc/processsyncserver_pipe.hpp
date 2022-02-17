/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010, 2011 Aldebaran Robotics
*/

#ifndef   	PROCESSSYNCSERVER_PIPE_HPP_
# define   	PROCESSSYNCSERVER_PIPE_HPP_

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
  class ProcessSyncServerPipe {
  public:
    ProcessSyncServerPipe(const std::string &name);
    void send_before() {
      send(false);
    };
    void send_after() {
      send(true);
    };
    void resend_before() {
      resend(false);
    };
    void resend_after() {
      resend(true);
    };
    bool timed_wait_for_before(unsigned long usTimeout) {
      return timed_wait_for(usTimeout, false);
    }
    bool timed_wait_for_after(unsigned long usTimeout) {
      return timed_wait_for(usTimeout, true);
    }

  private:
    static const char NO_SESSION = 0;
    void send(bool send_after);
    void resend(bool send_after);
    bool timed_wait_for(unsigned long usTimeout, bool wait_for_after);
    char _sessionId;
    int _client;
    int _server;
  };

};

#endif	    /* !PROCESSSYNCSERVER_PP_ */
