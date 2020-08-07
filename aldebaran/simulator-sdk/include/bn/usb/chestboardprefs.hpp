/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/

#ifndef   	CHESTBOARDPREFS_HPP_
# define   	CHESTBOARDPREFS_HPP_

# include <bn/common.hpp>
# include <bn/usb/usb.hpp>
# include <bn/usb/chestboardmessage.hpp>
# include <bn/usb/chestboardmanager.hpp>
# include <boost/crc.hpp>

namespace bn {
  namespace usb {

    enum DCMSubPRefALALValueTypeNumber {
      DCMTypeInt        = 250,
      DCMTypeFloat      = 251,
      DCMTypeString     = 252
    };

    typedef std::map< std::string, std::pair<int, std::string> > PrefsMap;

    sInt32 readPrefs(const std::string &buffer, PrefsMap &map);


    class ChestboardPrefs
    {
    public:
      ChestboardPrefs(Ptr<Usb> usb)
        : _usb(usb)
      {}

      int load(std::string &buffer);

    protected:
      Ptr<Usb> _usb;
    };

  }
}


#endif	    /* !CHESTBOARDPREFS_PP_ */
