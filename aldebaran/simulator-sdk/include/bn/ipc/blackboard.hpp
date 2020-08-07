/*
** shmmodulestore.hpp
** Login : <ctaf42@speed-core>
** Started on  Sat Apr 18 12:31:22 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	BLACKBOARD_HPP_
# define   	BLACKBOARD_HPP_

#include <bn/ipc/shmtypes.hpp>
#include <bn/ipc/shmfactory.hpp>

namespace bn{
  namespace ipc {
    /**
     * Maintain a list of blackboard client
     *
     * there may be one by process
     */
    class Blackboard {
    public:
      Blackboard();

      sInt32                    registerClient(const std::string &name);
      const std::string         client(const sInt32 id);
      const sInt32              count();

    protected:
      ShmFactory                _factory;
    };
  }
}

#endif	    /* !BLACKBOARD_HPP_ */
