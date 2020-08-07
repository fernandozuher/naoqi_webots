/*
** earsi2c.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Fri Dec 12 10:40:44 2008 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2010 Aldebaran Robotics
*/

#ifndef   	_TOUCHI2C_HPP_
# define   	_TOUCHI2C_HPP_

# include <bn/common.hpp>
# include <bn/i2c/devicei2c.hpp>

namespace bn
{
  namespace i2c
  {
    class TouchDevice : public DeviceI2c
    {
    protected:
    public:
      TouchDevice(uInt8 dev = gTouchI2cDevice, const Int8 *path = gDefaultI2cPath);
      void setLed(uInt8 led, uInt8 value);
      void setAllLed(uInt8 * value);

      static Ptr<TouchDevice> create(uInt8 dev = gTouchI2cDevice, const Int8 *path = gDefaultI2cPath);
      /**
       * hardware init, need to be done once at boot (at least)
       */
      sInt32    init();
    public:
      static const Int8 gTouchI2cDevice;

    public:
      sInt32 wakeup();
      sInt32 version(std::string &version);


    protected:
      uInt8     fBuffer[6];
    };

  }
}

#endif 	    /* !EARSI2C_H_ */
