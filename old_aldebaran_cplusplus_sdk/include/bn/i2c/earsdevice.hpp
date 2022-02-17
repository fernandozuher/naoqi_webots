/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2010 Aldebaran Robotics
*/

#ifndef   	_EARSI2C_HPP_
# define   	_EARSI2C_HPP_

# include <bn/common.hpp>
# include <bn/i2c/devicei2c.hpp>




namespace bn
{
  namespace i2c
  {

  /**
     * Interface for ears.
     */
    class EarsDevice
    {
      public:
        enum Side {
          Left,
          Right
        };
        virtual sInt32    setLed(Side side, uInt8 led, uInt8 value, uInt8 Immediate = 0) = 0;
        virtual sInt32    update() = 0;
        virtual sInt32    init() = 0;

    };


    EarsDevice          *createEarsDevice();
    bn::Ptr<EarsDevice>  createEarsDevicePtr();

  }
}

#endif 	    /* !EARSI2C_H_ */
