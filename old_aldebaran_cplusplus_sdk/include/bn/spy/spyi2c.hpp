/*
** spyi2c.hpp
** Login : <sam@smartin-de>
** Started on  Wed Sep  1 10:23:21 2010 Samuel MARTIN
** $Id$
**
** Author(s):
**  - Samuel MARTIN <smartin@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#ifndef   	SPYI2C_HPP_
# define   	SPYI2C_HPP_

# include <bn/common.hpp>

# include <bn/spy/spy.hpp>
# include <bn/i2c/i2c-dev.h>


namespace bn
{
  namespace spy
  {
    static const unsigned long int gTriggeredRequest  = I2C_SMBUS;
    static const char              gRequestMnemonic[] = "I2C_SMBUS";

    class SpyI2c{
    public:
      SpyI2c();

      /**
       * Spy callback displaying the content of the ioctl I2C request.
       */
      void dump(const int fd,
                const unsigned long int request,
                const void *data);

      /**
       * Parse filter pass through the environment.
       */
      void parseFilter(const char *filter);

      typedef std::map<std::string, std::string>        OptionsMap;

    protected:
    public:
    protected:
      OptionsMap                fOptions;
      sInt32                    fBacktrace;
      unsigned long int         fRequestTrigger;
      char*                     fRequestMnemonic;
    };

  };
};



#endif	    /* !SPYI2C_HPP_ */
