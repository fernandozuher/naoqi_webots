/*
** daemon.hpp
** Login : <ctaf42@speed-core>
** Started on  Sun Apr  5 00:51:56 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Cedric GESTES
*/

#ifndef   	DAEMON_HPP_
# define   	DAEMON_HPP_

# include <bn/common/types.hpp>
# include <bn/common/error.hpp>
# include <cunistd>

namespace bn
{
  /**
   *
   */
  class Daemon
  {
  public:
    Daemon() {;}
    virtual ~Daemon();

    sInt32 setPidFile(const std::string &name)
    {
      fPidFile = name;
    }

    sInt32 removePidFile()
    {
    }

    sInt32 setUniqueInstance()
    {
      //daemon should be unique
      //check the pid file, check that the pid is still valid
      //is pid not valid => daemon
      //is pidfile doesnt not exist => daemon
      //pid still valid ? => error
    }

    sInt32 daemonize()
    {
      //daemon(nochdir, noclose)
      if (daemon(1, 0) != -1)
        return bn::Ok;
      return bn::Error;
    }
  protected:
    std::string fPidFile;
    std::string fName;
  };
}

#endif	    /* !DAEMON_PP_ */
