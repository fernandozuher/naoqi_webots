/* -*- Mode: C++;  -*- */
/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef USB_HPP_
# define USB_HPP_

# include <usb.h>
# include <bn/common.hpp>
# include <bn/usb/chestboardmessage.hpp>

namespace bn {
  namespace usb {


  /*
    class connection_exception : public std::exception
    class data_exception : public std::exception
  */

    class Usb : public bn::AnyPtr<Usb>
    {
    protected:
    public:
      enum { dontclaim = 0, claim = 1 };

      Usb();

    public:
      static Ptr<Usb> create() { return Ptr<Usb>(new Usb()); }

      /**
       * connect to the chestboard
       */
      bool connect(sInt32 pVendorId = -1, sInt32 pProductId = -1, sInt32 claiminterface = claim);
      bool connectHid(sInt32 pVendorId = -1, sInt32 pProductId = -1, sInt32 interface = -1);

      /**
       * disconnect from the chestboard
       */
      void disconnect();

      bool isOpen() { return fUsb != 0; }

    public:
      void setDefaultEpOut(sInt32 ep) { fDefaultEpOut = ep; }
      void setDefaultEpIn(sInt32 ep) { fDefaultEpIn = ep; }
      void setDefaultInterface(sInt32 intf) {fInterface = intf;}
      void setDefaultDevice(sInt32 vendor, sInt32 product) { fVendor = vendor; fProduct = product; }
      void setDefaultHidDevice(sInt32 vendor, sInt32 product, sInt32 intf) { fVendor = vendor; fProduct = product; fInterface = intf;}


      sInt32 getDefaultEpOut() { return fDefaultEpOut; }
      sInt32 getDefaultEpIn() { return fDefaultEpIn; }

      /// raw access to the usb end point
#ifdef _WIN32
      int read(uInt8 *bytes, uInt32 size, uInt32 timeout = 20000, sInt32 ep = -1);
      int write(uInt8 *bytes, uInt32 size, uInt32 timeout = 20000, sInt32 ep = -1);
#else
      int read(uInt8 *bytes, uInt32 size, uInt32 timeout = 0, sInt32 ep = -1);
      int write(uInt8 *bytes, uInt32 size, uInt32 timeout = 0, sInt32 ep = -1);
#endif

      /**
       * read a control message
       */
#ifdef _WIN32
      int controlRead(uInt32 pRequest, uInt8 *pBuffer, uInt32 pBufferSize, uInt32 pTimeout = 20000);
#else
      int controlRead(uInt32 pRequest, uInt8 *pBuffer, uInt32 pBufferSize, uInt32 pTimeout = 0);
#endif
      /**
       * send a control message
       */
#ifdef _WIN32
      int controlWrite(uInt32 pRequest, uInt8 *pBuffer, uInt32 pBufferSize, uInt32 pTimeout = 20000);
#else
      int controlWrite(uInt32 pRequest, uInt8 *pBuffer, uInt32 pBufferSize, uInt32 pTimeout = 0);
#endif

      /**
        * write interrupt (for hid device)
        */
      int writeInterrupt(uInt8 *bytes, uInt32 size, uInt32 timeout = 0, sInt32 ep = -1);

      /**
        * read interrupt (for hid device)
        */
      int readInterrupt(uInt8 *bytes, uInt32 size, uInt32 timeout = 0, sInt32 ep = -1);


      /**
       * flush the usb (ask the chestboard til she dont answer)
       */
      void flush(void);

      static struct usb_device* findDevice(int    iVendor,
                                           int    iProduct);

    protected:
      /** find the device */
      void dump(const Int8 *name, Int8 *buffer, sInt32 size);

    protected:
      struct usb_dev_handle *fUsb;

    protected:
      uInt32                fDefaultEpIn;
      uInt32                fDefaultEpOut;
      uInt32                fInterface;
      uInt32                fVendor;
      uInt32                fProduct;
    };

  } //namespace hw
} //namespace bn

#endif /* !USB_H_ */
