/* -*- Mode: C++;  -*- */
/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef CHESTBOARD_HPP_
# define CHESTBOARD_HPP_

namespace bn
{
  namespace usb
  {
    namespace hw
    {
      #define LIBUSB_ENDPOINT_IN (0x80)

      namespace arm7 {
        const sInt32    VendorId  = 0xFFFF;
        const sInt32    ProductId = 0x0004;
        const sInt32    EPOut     = 0x05;
        const sInt32    EPIn      = 0x2 | LIBUSB_ENDPOINT_IN;
      }

      namespace arm9 {
        const sInt32    VendorId  = 0xFFFF;
        const sInt32    ProductId = 0x0005;
        const sInt32    EPOut     = 0x01;
        const sInt32    EPIn      = 0x2 | LIBUSB_ENDPOINT_IN;
      }

      /*
       * Handle v3.2 / v3.3 hardware changes
       */
      namespace arm9v3_3 {
        const sInt32    VendorId  = 0xFFFF;
        const sInt32    ProductId = 0x0006;
        const sInt32    EPOut     = 0x01;
        const sInt32    EPIn      = 0x2 | LIBUSB_ENDPOINT_IN;
      }

    }
  }
}


#endif /* !CHESTBOARD_H_ */



