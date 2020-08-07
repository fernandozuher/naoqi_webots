/*
** error.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Fri Apr  3 10:53:53 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	ERROR_HPP_
# define   	ERROR_HPP_

# include <cstdlib>
# include <bn/common/types.hpp>

namespace bn
{
  /**
   * status <  0 is error
   * status >= 0 is OK
   *
   * follow unix convention
   *  1 .. ++ = error
   *  0 .. -- = success
   *
   * status is a sInt32
   */
  typedef enum {
    StatusOk      = 0,
    StatusError   = 1,
  } StatusType;

  namespace detail {
    /**
     * return an Error
     * always return a negative value
     */
    class ErrorImpl {
    public:
      sInt32 operator()(const sInt32 &error) const
      {
        if (error == 0)
          return bn::StatusError;
        return abs(error);
      }

      operator sInt32()const
      {
        return bn::StatusError;
      }
    };

    /**
     * return a good status
     * always return a positive or zero value
     */
    class OkImpl {
    public:
      sInt32 operator()(const sInt32 &ok) const
      {
        return -abs(ok);
      }

      operator sInt32()const
      {
        return bn::StatusOk;
      }
    };
  } //!namespace detail

  extern class detail::OkImpl           Ok;
  extern class detail::ErrorImpl        Error;

  //return a posix status
  inline sInt32 mainReturn(sInt32 error)
  {
    if (error < 0)
      return 0;
    return error;
  }

  inline sInt32 isError(sInt32 error)
  {
    return error > 0;
  }

  inline sInt32 isOk(sInt32 error)
  {
    return error <= 0;
  }

  ///only return when is <a> an error
#define returnIfError(a)                          \
  {                                               \
    sInt32 ret;                                   \
    ret = a;                                      \
    if (bn::isError(ret))                         \
      return ret;                                 \
  }

  ///only return if <a> is ok
#define returnIfOk(a)                           \
  {                                             \
    sInt32 ret;                                 \
    ret = a;                                    \
    if (bn::isOk(ret))                          \
      return ret;                               \
  }

///if <a> is an error , throw <b>
#define throwIfError(a, b)                        \
  {                                               \
    sInt32 ret;                                   \
    ret = a;                                      \
    if (bn::isError(ret))                         \
    {                                             \
      throw b;                                    \
    }                                             \
  }

///if a is a valid status , throw b
#define throwIfOk(a, b)                           \
  {                                               \
    sInt32 ret;                                   \
    ret = a;                                      \
    if (bn::isOk(ret))                            \
    {                                             \
      throw b;                                    \
    }                                             \
  }
}

#endif	    /* !ERROR_PP_ */
