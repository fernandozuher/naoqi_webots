/* -*- Mode: C++;  -*- */
/**
 * @author Cedric GESTES <gestes@aldebaran-robotics.com>
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef   	CHESTUSB_H_
# define   	CHESTUSB_H_

# include <bn/common.hpp>

namespace bn
{
namespace usb
{

/**
 * BEGIN : IMPORTED FROM CHESTBOARD CODE
 */

///usb type
#define USB_MSG_SINGLE_CHANNEL  0
#define USB_MSG_POLLED_CHANNEL  1
#define USB_MSG_POLLED_ANSWER   2
#define USB_MSG_CLEAR_BUFFER    3

///usb bus
#define BUS_RS485_UP            0
#define BUS_RS485_DOWN          1
#define BUS_I2C                 2
#define BUS_CHEST               3

///usb device
#define CHEST_DEVICE_LED        0
#define CHEST_DEVICE_POWER      1
#define CHEST_DEVICE_BATTERY    2
#define CHEST_DEVICE_CHARGE     3
#define CHEST_DEVICE_CHAINING   4
#define CHEST_DEVICE_BUTTON     5
#define CHEST_DEVICE_DATA_READ  6
#define CHEST_DEVICE_DATA_WRITE 7

///chestboard request
#define REQ_RESET               0
#define REQ_FLASH_UPDATE        1
#define REQ_VERSION             2
#define REQ_BOOTLOADER_STATE    4
#define REQ_SHUTDOWN            5
#define REQ_DATA_CLEAR          6
#define REQ_DATA_FLUSH          7
#define REQ_STATS0              0x8
#define REQ_STATS1              0x9
#define REQ_STATS2              0x10
#define REQ_STATS3              0x11
#define REQ_STATSMSGTOLOG       0x12

//bootloader state
#define BOOTLOADER_STATE_NOP            0x0
#define BOOTLOADER_STATE_WAITING        0x1
#define BOOTLOADER_STATE_WRITING        0x2
#define BOOTLOADER_STATE_FINISH         0x3
#define BOOTLOADER_STATE_BADCRC         0x4
#define BOOTLOADER_STATE_ERROR          0x5

//bootloader request
#define REQ_BL_FIRMWARE_UPDATE          0x1
#define REQ_BL_SEND_FIRMWARE            0x3
#define REQ_BL_BOOTLOADER_STATE         0x4
#define REQ_BL_GO_TO_FIRMWARE           0x43


/**
 * END   : IMPORTED FROM CHESTBOARD CODE
 */


sInt32  StringToUsbBus(const char *bus);

}
}

#endif 	    /* !CHESTUSB_H_ */
