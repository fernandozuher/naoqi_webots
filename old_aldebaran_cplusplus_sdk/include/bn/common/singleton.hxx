/*
** singleton.hxx
** Login : <ctaf@localhost.localdomain>
** Started on  Thu Apr  2 11:36:30 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifdef INCLUDE_HXX_TEMPLATE

# ifndef   	SINGLETON_HXX_
#  define   	SINGLETON_HXX_


namespace bn
{
  template <typename T> Ptr<T> Singleton<T>::_singleton = Ptr<T>();
}


# endif	    /* !SINGLETON_HXX_ */

#endif
