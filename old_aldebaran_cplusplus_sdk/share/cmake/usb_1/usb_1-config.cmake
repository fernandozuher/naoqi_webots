get_filename_component(_usb_1_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_usb_1_root "${_usb_1_root}/../../..")
get_filename_component(_usb_1_root "${_usb_1_root}" ABSOLUTE)

set(USB_1_LIBRARIES
  ${_usb_1_root}/lib/libusb-1.0.so
  ${_usb_1_root}/lib/libusb-1.0.so.0
  CACHE INTERNAL "" FORCE
)

set(USB_1_INCLUDE_DIRS
  ${_usb_1_root}/include
  CACHE INTERNAL "" FORCE
)

export_lib(USB_1)
