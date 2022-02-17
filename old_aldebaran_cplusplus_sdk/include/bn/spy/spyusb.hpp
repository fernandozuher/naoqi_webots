/*
** spyusb.h
** Login : <ctaf@localhost.localdomain>
** Started on  Fri Mar 20 18:14:26 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009, 2010 Aldebaran Robotics
*/

#ifndef   	SPYUSB_HPP_
# define   	SPYUSB_HPP_

# include <usb.h>
# include <bn/common.hpp>
# include <bn/spy/spy.hpp>

namespace bn
{
  namespace spy
  {

    class SpyUsb : public Spy {
    public:
      SpyUsb();

      int bulkRead(usb_dev_handle *dev, int ep, char *bytes, int size, int timeout);
      int bulkWrite(usb_dev_handle *dev, int ep, char *bytes, int size, int timeout);
      int controlMsg(usb_dev_handle     *dev,
                     int                 requesttype,
                     int                 request,
                     int                 value,
                     int                 index,
                     char               *bytes,
                     int                 size,
                     int                 timeout);

      void dump(const Int8 *name, Int8 *buffer, sInt32 size, sInt32 dir);

    protected:
      typedef int (*BulkFunction)(usb_dev_handle *dev, int ep, char *bytes, int size, int timeout);
      typedef int (*ControlFunction)(usb_dev_handle     *dev,
                                     int                 requesttype,
                                     int                 request,
                                     int                 value,
                                     int                 index,
                                     char               *bytes,
                                     int                 size,
                                     int                 timeout);

    protected:
      Ptr<SharedLibrary>        fLibUsb;
      BulkFunction              fBulkRead;
      BulkFunction              fBulkWrite;
      ControlFunction           fControlMsg;
      std::map<int, int>        fStatRead;
      std::map<int, int>        fStatWrite;
    };

  };
};


#endif 	    /* !SPYUSB_HPP_ */
