/*
** headi2c.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Thu Dec 11 18:09:09 2008 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008 Aldebaran Robotics
*/

#ifndef _DEVICEI2C_HPP_
# define _DEVICEI2C_HPP_

# include <bn/common.hpp>
# include <bn/i2c/i2c-dev.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

namespace bn
{
  namespace i2c
  {
    /**
     * basic i2c class
     *
     * open/close are done automagically in constructor/destructor when possible
     *
     * read/write handle smbus message
     * rawRead/rawWrite handle i2c message
     */
    class DeviceI2c
    {
    public:
      DeviceI2c(const DeviceI2c &dev);
      DeviceI2c(uInt8 dev = gDefaultI2cDevice, const Int8 *path = gDefaultI2cPath, uInt32 mode = O_RDWR);
      ~DeviceI2c();

      /** return <0 on error */
      virtual sInt32    open(sInt32 mode = O_RDWR);
      virtual sInt32    close();
      virtual sInt32    setDevice(uInt8 dev);

      /** return 1 if opened */
      virtual sInt32    isOpen()const { return fFd != -1; }

      sInt32    rawWrite(sInt32 size, const uInt8 *data)const;
      sInt32    rawRead(sInt32 size, uInt8 *data);

      sInt32    write(uInt8 reg, sInt32 size, const uInt8 *data)const;
      sInt32    writeByte(const uInt8 command, const uInt8 value)const;
      sInt32    writeBlockBroken(uInt8 reg, sInt32 size, const uInt8 *data)const;
      sInt32    read(uInt8 reg, sInt32 size, uInt8 *data);


    public:
      static const Int8  *gDefaultI2cPath;
      static const Int8  gDefaultI2cDevice;


    protected:
      uInt8     fDev;
      sInt32    fFd;
      Int8     *fPath;
    };

  }
}

#endif
