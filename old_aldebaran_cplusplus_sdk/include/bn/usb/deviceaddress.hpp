/*
** deviceaddress.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Fri Jan 30 14:17:23 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	DEVICEADDRESS_HPP_
# define   	DEVICEADDRESS_HPP_

namespace bn {
  namespace usb {

    static const Int8      NA = 0;

    class DeviceAddress : Ptr<DeviceAddress>
    {
    public:
      static Ptr<DeviceAddress> create(const uInt8 &bus = NA,
                                       const uInt8 &dev = NA,
                                       const uInt8 &reg = NA)
      {
        return Ptr<DeviceAddress>(new DeviceAddress( bus, dev, reg));
      }

      uInt8     bus(void)const { return fBus; }
      uInt8     dev(void)const { return fDev; }
      uInt8     reg(void)const { return fReg; }


    protected:
      DeviceAddress(const uInt8 &bus,
                    const uInt8 &dev,
                    const uInt8 &reg)
        : fBus(bus),
          fDev(dev),
          fReg(reg)
      { ; }

    protected:
      uInt8     fBus;
      uInt8     fDev;
      uInt8     fReg;
    };


  } //namespace usb
} //namespace bn

#endif	    /* !DEVICEADDRESS_PP_ */
