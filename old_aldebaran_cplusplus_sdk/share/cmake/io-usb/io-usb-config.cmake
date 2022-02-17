# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(IO-USB_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(IO-USB_INCLUDE_DIRS)
   

find_library(IO-USB_DEBUG_LIBRARY io-usb_d)
find_library(IO-USB_LIBRARY       io-usb)


if (IO-USB_DEBUG_LIBRARY)
  set(IO-USB_LIBRARIES optimized;${IO-USB_LIBRARY};debug;${IO-USB_DEBUG_LIBRARY})
else()
  set(IO-USB_LIBRARIES ${IO-USB_LIBRARY})
endif()

set(IO-USB_LIBRARIES ${IO-USB_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(IO-USB DEFAULT_MSG
  IO-USB_LIBRARIES
  IO-USB_INCLUDE_DIRS
)
set(IO-USB_PACKAGE_FOUND ${IO-USB_FOUND} CACHE INTERNAL "" FORCE)
 
set(IO-USB_DEPENDS "BN-USB;USB;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 