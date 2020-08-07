/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2010 Aldebaran Robotics
*/

#ifndef   	_EARSI2CV33_HPP_
# define   	_EARSI2CV33_HPP_

# include <bn/common.hpp>
# include <bn/i2c/devicei2c.hpp>
# include <bn/i2c/earsdevice.hpp>


namespace bn
{
  namespace i2c
  {
    namespace hw_v3_3
    {

      const uInt8 gEarsI2cDevice = 0x60;


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
        class EarSubDev : public DeviceI2c
        {
        public:
          EarSubDev(const uInt8 dev = gEarsI2cDevice,
                    const Int8 *path = bn::i2c::DeviceI2c::gDefaultI2cPath);
          enum I2cWriteMode{
            I2C_BLOCK_DATA,
            BLOCK_DATA
          };
          sInt32 _write(uInt8 address, uInt8 *command,
                       sInt32 size, const uInt8 *buffer,
                       I2cWriteMode writeMode=I2C_BLOCK_DATA);
        protected:
        public:
        protected:
        };
      public:
        EarsDevice(const uInt8 dev  = gEarsI2cDevice,
                   const Int8 *path = bn::i2c::DeviceI2c::gDefaultI2cPath);
        /**
         *  value range: 0 - 255
         */
        virtual sInt32    setLed(Side side, uInt8 led, uInt8 value, uInt8 Immediate = 0);
        virtual sInt32    update();

        /**
         * hardware init, need to be done once at boot (at least)
         */
        virtual sInt32    init();

      public:
      protected:
        EarSubDev  fDev;
        uInt8      fBuffer[32];
        uInt8      fEarLeft[32];
        uInt8      fEarRight[32];

      };

    }
  }
}

#endif 	    /* !EARSI2CV33_HPP_ */
