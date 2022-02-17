/*
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#ifndef   	BN_IPC_SYNCBASE_HPP_
# define   	BN_IPC_SYNCBASE_HPP_

#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>

namespace bn {

  namespace detail {

    class RemoveSync;

    /**
     * internal class, do not use
     */
    class ProcessSync {
    public:

      // For client side
      ProcessSync(boost::interprocess::open_only_t, const std::string &name);

      // For server side
      ProcessSync(boost::interprocess::create_only_t, const std::string &name);

      static int remove(const std::string &name);

    protected:
      bool timed_wait(boost::interprocess::named_condition &cond, unsigned long timeout);

    protected:

      int fake;

      boost::interprocess::named_mutex      mutex;
      boost::interprocess::named_condition  cond_after_client;
      boost::interprocess::named_condition  cond_after_server;
      boost::interprocess::named_condition  cond_before_client;
      boost::interprocess::named_condition  cond_before_server;


    };
  } //detail

}; //bn

#endif	    /* !SYNCBASE_PP_ */
