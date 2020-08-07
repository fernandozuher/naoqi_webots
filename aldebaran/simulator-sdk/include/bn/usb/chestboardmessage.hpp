/*
** chestboardmessage.hpp
** Login : <ctaf@localhost.localdomain>
** Started on  Tue Jan 27 09:11:15 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	CHESTBOARDMESSAGE_HPP_
# define   	CHESTBOARDMESSAGE_HPP_

#include <bn/usb/deviceaddress.hpp>


namespace bn
{
  namespace usb
  {


    #define MAX_PACKET_SIZE (4096)

    static const uInt8        ChestProtocolEscape = 0xAA;
    static const uInt8        ChestProtocolAck    = 0x30;
    static const uInt8        ChestProtocolNAck   = 0x20;


    typedef struct UsbMessageType {
      uInt8         type;
      uInt8         bus;
      uInt8         dev;
      uInt8         reg;
      uInt8         size;
      uInt8         ack;
      uInt8        *buffer;
    } UsbMessage;

    typedef enum {
      BusRs485Up,
      BusRs485Down,
      BusI2c,
      BusChest,
    } BusType;

    typedef enum {
      Read,
      Write
    } RWType;

    typedef enum {
      NAck          = 0,
      Ack           = 1,
      Msg           = 2
    } AckType;

    typedef enum {
      Single = 0,
      PollingRequest,
      PollingAnswer,
      PollingClear
    } MessageType;

    /*
     *
     */
    class ChestboardMessage : public bn::AnyPtr<ChestboardMessage>
    {
      friend class ChestboardManager;


    public:
      ChestboardMessage();
      static Ptr<ChestboardMessage> create(void);

    public:

    public:
      virtual void addMessage(uInt8                    type,
                              uInt8                    bus,
                              uInt8                    dev,
                              uInt8                    reg,
                              uInt8                    toRead);

      virtual void addMessage(uInt8                     type,
                              Ptr<DeviceAddress>        dev,
                              uInt8                     toRead);

      virtual void setMessageData(const Int8     *pMsg,
                                  uInt32          pMsgSize);


      virtual uInt32 messageCount()const { return fReadMsgCount; }
      //should we return a DeviceAddress too?
      virtual const Int8 *message(sInt32 index, sInt32 *pSize)const;

      virtual UsbMessage *message(sInt32 index);

    protected:
      virtual Int8     *stageOut(sInt32 *availableSize);
      virtual void      stageIn(Int8 *data, sInt32 size);

    protected:
      /**
       * decode the special usb char (0xAA)
       * the AA is duplicate
       */
      void decodeAA();

      void decodeMessages();
      void decodeMessage(sInt32 index);

      /**
       * copy the footer into the buffer
       */
      void setFooter();

    protected:
      Int8                  fBuffer[MAX_PACKET_SIZE];
      Int8                 *fBufferRead;

      //read message
      UsbMessage            fReadUsbMessage[255];
      Int8                 *fReadMsgStart[255];
      sInt32                fReadMsgSize[255];
      sInt32                fReadMsgCount;

      sInt32                fToReadSize;
      sInt32                fReadSize;

      sInt32                fReadCount;

      sInt32                fMsgCount;
      sInt32                fIndex;

      const uInt8           fReadHeaderSize;
      const uInt8           fReadFooterSize;
      const uInt8           fHeaderSize;
      const uInt8           fFooterSize;
    };

  }
}


#endif	    /* !CHESTBOARDMESSAGE_PP_ */
