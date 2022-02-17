/*
** facedevice.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Fri Feb  6 12:31:34 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	FACEDEVICE_HPP_
# define   	FACEDEVICE_HPP_

namespace bn
{
  namespace i2c
  {

    class FaceDevice : public DeviceI2c, public AnyPtr<FaceDevice>
    {
    protected:
      FaceDevice(uInt8 dev = gFaceI2cDevice, const Int8 *path = gDefaultI2cPath);

    public:
      ~FaceDevice();
      static Ptr<FaceDevice> create(uInt8 dev = gFaceI2cDevice, const Int8 *path = gDefaultI2cPath);

    private:
      static const uInt8 gFaceI2cDevice = 8;

    public:
      sInt32 wakeup();
      sInt32 version(std::string &version);
    };
  }
}



#endif	    /* !FACEDEVICE_HPP_ */
