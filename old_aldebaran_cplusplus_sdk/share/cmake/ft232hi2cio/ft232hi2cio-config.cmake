# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(FT232HI2CIO_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(FT232HI2CIO_INCLUDE_DIRS)
   

find_library(FT232HI2CIO_DEBUG_LIBRARY ft232hi2cio_d)
find_library(FT232HI2CIO_LIBRARY       ft232hi2cio)


if (FT232HI2CIO_DEBUG_LIBRARY)
  set(FT232HI2CIO_LIBRARIES optimized;${FT232HI2CIO_LIBRARY};debug;${FT232HI2CIO_DEBUG_LIBRARY})
else()
  set(FT232HI2CIO_LIBRARIES ${FT232HI2CIO_LIBRARY})
endif()

set(FT232HI2CIO_LIBRARIES ${FT232HI2CIO_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FT232HI2CIO DEFAULT_MSG
  FT232HI2CIO_LIBRARIES
  FT232HI2CIO_INCLUDE_DIRS
)
set(FT232HI2CIO_PACKAGE_FOUND ${FT232HI2CIO_FOUND} CACHE INTERNAL "" FORCE)
 
set(FT232HI2CIO_DEPENDS "HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 