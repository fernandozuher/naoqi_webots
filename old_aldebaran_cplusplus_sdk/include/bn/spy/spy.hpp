/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009, 2010 Aldebaran Robotics
*/

#ifndef   	SPY_HPP_
# define   	SPY_HPP_

# include <usb.h>
# include <bn/common.hpp>

namespace bn
{
  namespace spy
  {

    class Spy {
    public:
      Spy();
      virtual ~Spy();


      void dump(const Int8 *name, Int8 *buffer, sInt32 size, sInt32 dir);
      void rawDump(const Int8 *name, Int8 *buffer, sInt32 size, sInt32 dir);
      void statDump();

    protected:
      sInt32 match(const char *b);
      void parseFilter(const char *filter);

      typedef std::map<std::string, std::string>        OptionsMap;

    protected:
      std::map<int, int>        fStatRead;
      std::map<int, int>        fStatWrite;
      OptionsMap                fOptions;

      sInt32                    fContext;
      sInt32                    fStats;
      sInt32                    fAssert;
    };

  };
};


#endif 	    /* !SPYUSB_HPP_ */
