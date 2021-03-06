# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(NAO-MODULES_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(NAO-MODULES_INCLUDE_DIRS)
   

find_library(NAO-MODULES_DEBUG_LIBRARY nao-modules_d)
find_library(NAO-MODULES_LIBRARY       nao-modules)


if (NAO-MODULES_DEBUG_LIBRARY)
  set(NAO-MODULES_LIBRARIES optimized;${NAO-MODULES_LIBRARY};debug;${NAO-MODULES_DEBUG_LIBRARY})
else()
  set(NAO-MODULES_LIBRARIES ${NAO-MODULES_LIBRARY})
endif()

set(NAO-MODULES_LIBRARIES ${NAO-MODULES_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NAO-MODULES DEFAULT_MSG
  NAO-MODULES_LIBRARIES
  NAO-MODULES_INCLUDE_DIRS
)
set(NAO-MODULES_PACKAGE_FOUND ${NAO-MODULES_FOUND} CACHE INTERNAL "" FORCE)
 
set(NAO-MODULES_DEPENDS "IO_HEADUSB;BN-USB;USB;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 