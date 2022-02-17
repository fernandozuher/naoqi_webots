/*
** chestboardfactory.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Thu Apr  2 17:21:24 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	CHESTBOARDFACTORY_HPP_
# define   	CHESTBOARDFACTORY_HPP_

# include <bn/common.hpp>
# include <bn/usb/usb.hpp>

namespace bn {
  namespace usb {

    class ChestboardFactory
    {
    public:
      static sInt32 detect();
      static Ptr<Usb> create();
    };

  }
}


#endif	    /* !CHESTBOARDFACTORY_PP_ */
