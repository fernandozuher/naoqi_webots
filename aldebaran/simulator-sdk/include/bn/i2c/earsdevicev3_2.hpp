/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2010 Aldebaran Robotics
*/

#ifndef   	_EARSI2CV32_HPP_
# define   	_EARSI2CV32_HPP_

# include <bn/common.hpp>
# include <bn/i2c/devicei2c.hpp>
# include <bn/i2c/earsdevice.hpp>


namespace bn
{
  namespace i2c
  {
    namespace hw_v3_2
    {

      /**
       * Base address of the i2c device
       */
      const uInt8 gEarsI2cDevice = 65;


      /**
       * TODO:
       *  - dump
       *  - support immediate for setRight/setLeft
       *
       * General Consideration:
       *  - dump/update are used get/set all value in one shot
       *  - setLed can be used with immediate to set the led immediately
       *    or without to set the led and let update effectively change the led
       */
      class EarsDevice : public bn::i2c::EarsDevice
      {
      protected:
      public:
        EarsDevice(uInt8 dev = gEarsI2cDevice, const Int8 *path = bn::i2c::DeviceI2c::gDefaultI2cPath);

        /**
         * value range: 0 - 255
         */
        virtual sInt32    setLed(Side side, uInt8 led, uInt8 value, uInt8 Immediate = 0);
        virtual sInt32    update();

        /**
         * hardware init, need to be done once at boot (at least)
         */
        virtual sInt32    init();


      public:
      protected:
        DeviceI2c fEars;
        sInt8     fLeds[32];
        uInt8     fBuffer[32];
      };
    }
  }
}

#endif 	    /* !EARSI2CV32_HPP_ */
