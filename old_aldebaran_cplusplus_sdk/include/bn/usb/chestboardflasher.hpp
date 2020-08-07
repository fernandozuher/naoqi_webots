/*
** chestboardflasher.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Mon Feb  2 12:02:58 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009, 2011 Aldebaran Robotics
*/

#ifndef   	CHESTBOARDFLASHER_HPP_
# define   	CHESTBOARDFLASHER_HPP_

# include <bn/usb/usb.hpp>
# include <bn/usb/chestboardmessage.hpp>


#ifndef WIN32
#  define PACKED_STRUCT __attribute__((__packed__))
#else
#  define PACKED_STRUCT
#endif
namespace bn {
  namespace usb {


    typedef struct {
      uInt8     md5[16];
      uInt32    size;
      uInt32    sector;
    } PACKED_STRUCT BLStruct;

    /*
     * write on the chestboard flash
     *
     * the buffer should have the following structure:
     * <16octets md5><buffer>
     *
     */
    class ChestboardFlasher
    {
    public:
      ChestboardFlasher();
      ~ChestboardFlasher();
      static Ptr<ChestboardFlasher> create() { return Ptr<ChestboardFlasher>(new ChestboardFlasher()); }

      sInt32 setFile(sInt32 sector, const char *fname);
      sInt32 setData(sInt32 sector, const Int8 *data, const sInt32 size);

      sInt32 flash(Ptr<Usb> cb);

      sInt32 sendFirmwareMode(Ptr<Usb> cb);

    protected:
      sInt32 sendBootloaderMode(Ptr<Usb> cb);
      sInt32 sendProgram(Ptr<Usb> cb);

    protected:
      sInt32            fAlignedSize;
      uInt32            fCrc;
      sInt8             fMd5[16];
      sInt8            *fData;
      sInt32            fSector;
      sInt32            fSpan;
    };

  }
}


#endif 	    /* !CHESTBOARDFLASHER_HPP_ */
