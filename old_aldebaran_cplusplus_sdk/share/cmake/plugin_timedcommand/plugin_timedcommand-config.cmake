# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_TIMEDCOMMAND_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_TIMEDCOMMAND_INCLUDE_DIRS)
   

find_library(PLUGIN_TIMEDCOMMAND_DEBUG_LIBRARY plugin_timedcommand_d)
find_library(PLUGIN_TIMEDCOMMAND_LIBRARY       plugin_timedcommand)


if (PLUGIN_TIMEDCOMMAND_DEBUG_LIBRARY)
  set(PLUGIN_TIMEDCOMMAND_LIBRARIES optimized;${PLUGIN_TIMEDCOMMAND_LIBRARY};debug;${PLUGIN_TIMEDCOMMAND_DEBUG_LIBRARY})
else()
  set(PLUGIN_TIMEDCOMMAND_LIBRARIES ${PLUGIN_TIMEDCOMMAND_LIBRARY})
endif()

set(PLUGIN_TIMEDCOMMAND_LIBRARIES ${PLUGIN_TIMEDCOMMAND_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_TIMEDCOMMAND DEFAULT_MSG
  PLUGIN_TIMEDCOMMAND_LIBRARIES
  PLUGIN_TIMEDCOMMAND_INCLUDE_DIRS
)
set(PLUGIN_TIMEDCOMMAND_PACKAGE_FOUND ${PLUGIN_TIMEDCOMMAND_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_TIMEDCOMMAND_DEPENDS "LIB_DCM;ALPROXIES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;ALTHREAD;ALCOMMON;ALVALUE;ALERROR;QIMESSAGING;QITYPE;BOOST;BOOST_DATE_TIME;BOOST_SIGNALS;RTTOOLS;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;RT;DL" CACHE INTERNAL "" FORCE)
 