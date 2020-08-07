/* -*- Mode: C++;  -*- */
/*
** Login : <ctaf@localhost.localdomain>
** Started on  Tue Nov 18 15:04:21 2008 Cedric GESTES
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008 Aldebaran Robotics
*/

#ifndef   	MSGEXCEPTION_H_
# define   	MSGEXCEPTION_H_

# include <bn/common.hpp>
# include <exception>

namespace bn
{
  /*
   * simple exception with a message
   */
  class MsgException: public std::exception
  {
  public:
    MsgException(const char *msg);
    MsgException(const std::string &msg);
    virtual ~MsgException() throw();
    virtual const char* what() const throw();

  protected:
    std::string fWhat;
  };

};

#endif 	    /* !MSGEXCEPTION_H_ */
