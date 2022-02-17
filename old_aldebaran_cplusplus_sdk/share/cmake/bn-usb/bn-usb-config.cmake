# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(BN-USB_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(BN-USB_INCLUDE_DIRS)
   

find_library(BN-USB_DEBUG_LIBRARY bn-usb_d)
find_library(BN-USB_LIBRARY       bn-usb)


if (BN-USB_DEBUG_LIBRARY)
  set(BN-USB_LIBRARIES optimized;${BN-USB_LIBRARY};debug;${BN-USB_DEBUG_LIBRARY})
else()
  set(BN-USB_LIBRARIES ${BN-USB_LIBRARY})
endif()

set(BN-USB_LIBRARIES ${BN-USB_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BN-USB DEFAULT_MSG
  BN-USB_LIBRARIES
  BN-USB_INCLUDE_DIRS
)
set(BN-USB_PACKAGE_FOUND ${BN-USB_FOUND} CACHE INTERNAL "" FORCE)
 
set(BN-USB_DEPENDS "USB;BN-COMMON;BOOST_FILESYSTEM;BOOST_SYSTEM;DL;BN-RT;BOOST;PTHREAD;RT" CACHE INTERNAL "" FORCE)
 