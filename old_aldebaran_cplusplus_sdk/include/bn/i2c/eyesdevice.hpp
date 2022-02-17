//
// eyesdevice.hpp for libbn
//
// Made by Laurent Lec
// Login   <laurent@lse.epita.fr>
//
// Started on  Wed Dec 17 08:44:50 2008 Laurent Lec
// Last update Wed Jul 15 11:52:20 2009 Cedric GESTES
//
// Copyright (C) 2008 Aldebaran Robotics
//

#ifndef EYESDEVICE_HPP_
# define EYESDEVICE_HPP_

# include <bn/common.hpp>
# include <bn/i2c/devicei2c.hpp>

# include <unistd.h>
# include <sys/time.h>
# include <errno.h>
# include <string.h>


namespace bn
{
  namespace i2c
  {
    uInt32 rgb(uInt8 r, uInt8 g, uInt8 b);
    uInt8 comp(uInt32 c, uInt8 comp);


    class EyesDevice : public DeviceI2c
    {
    private:
      uInt8 map[48];
      static const uInt8 gEyesI2cDevice = 8;

    public:
      static Ptr<EyesDevice> create(uInt8 dev = gEyesI2cDevice, const Int8 *path = gDefaultI2cPath);

      void clear();
      void setComp(uInt8 side, uInt8 no, uInt8 comp, uInt8 intensity, bool immed = true);
      void setLed(uInt8 side, uInt8 no, uInt32 color, bool immed = true);
      void setEye(uInt8 side, uInt32 color, bool immed = true);

      void update();
      void dump();

      EyesDevice(uInt8 dev = gEyesI2cDevice, const Int8 *path = gDefaultI2cPath);
      ~EyesDevice();

      static const sInt32 fLedNB = 48;
      static const sInt32 fLedStart = 20;


      //write IR
      sInt32 writeIr(uInt8 ir);

      enum
      {
        RegReadIR  = 10,
        RegLed0    = 20,
        RegLed1    = 21,
        RegLed2    = 22,
        RegLed3    = 23,
        RegLed4    = 24,
        RegLed5    = 25,
        RegLed6    = 26,
        RegLed7    = 27,
        RegLed8    = 28,
        // ...
        RegLedEnd= 20 + 48
      } e_register;

      enum
      {
	R	= 0,
	G	= 1,
	B	= 2
      } e_components;

      enum
      {
	LEFT	= 0,
	RIGHT	= 1
      } e_sides;

      enum
      {
	INTENSITY_MAX	= 63,
	INTENSITY_MIN	= 0
      } e_intensities;

      enum
      {
	RED	= 0x3f000,
	YELLOW	= 0x3ffc0,
	GREEN	= 0x00fc0,
	CYAN	= 0x00fff,
	BLUE	= 0x0003f,
	ROSE	= 0x3f03f
      } e_colors;
    };
  }
}

#endif /* !EYESDEVICE_HPP_ */
