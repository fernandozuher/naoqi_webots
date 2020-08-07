/*
** chestboardmanager.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Thu Jan 22 16:06:42 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	CHESTBOARDMANAGER_HPP_
# define   	CHESTBOARDMANAGER_HPP_


/**
 * each protocol need a version:
 *   - chestboard
 *   - inertial
 *   - motorboard
 */

/*
 * class Msg:
 *   toWrite(&toRead, &toWrite)
 *   read(uint8*, sz)
 *
 */

# include <bn/usb/usb.hpp>
# include <bn/usb/chestboardmessage.hpp>

namespace bn {
  namespace usb {

    typedef enum {
      SingleMessage    = 0,
      PollingMessage   = 1,
      ClearPolling     = 3,
    } MessagePollType;

    class ChestboardManager
    {

    public:
      ChestboardManager(Ptr<ChestboardMessage> cbm, Ptr<Usb> cb);
      static Ptr<ChestboardManager> create(Ptr<ChestboardMessage> cbm, Ptr<Usb> cb);

      sInt32 doRead(uInt32 timeout = 10); // Timeout in ms
      sInt32 doWrite(uInt32 timeout = 10); // Timeout in ms
      sInt32 doCycle(uInt32 sleep = 0, uInt32 timeoutms = 10);

    protected:
      Ptr<ChestboardMessage>                    fCbMsg;
      Ptr<Usb>                                  fCb;
      Int8                                      fBuffer[2048];
    };

  } //namespace usb
}//namespace bn


#endif 	    /* !CHESTBOARDMANAGER_HPP_ */
