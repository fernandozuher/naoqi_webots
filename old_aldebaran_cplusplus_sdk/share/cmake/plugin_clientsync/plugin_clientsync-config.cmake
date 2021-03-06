# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_CLIENTSYNC_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_CLIENTSYNC_INCLUDE_DIRS)
   

find_library(PLUGIN_CLIENTSYNC_DEBUG_LIBRARY plugin_clientsync_d)
find_library(PLUGIN_CLIENTSYNC_LIBRARY       plugin_clientsync)


if (PLUGIN_CLIENTSYNC_DEBUG_LIBRARY)
  set(PLUGIN_CLIENTSYNC_LIBRARIES optimized;${PLUGIN_CLIENTSYNC_LIBRARY};debug;${PLUGIN_CLIENTSYNC_DEBUG_LIBRARY})
else()
  set(PLUGIN_CLIENTSYNC_LIBRARIES ${PLUGIN_CLIENTSYNC_LIBRARY})
endif()

set(PLUGIN_CLIENTSYNC_LIBRARIES ${PLUGIN_CLIENTSYNC_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_CLIENTSYNC DEFAULT_MSG
  PLUGIN_CLIENTSYNC_LIBRARIES
  PLUGIN_CLIENTSYNC_INCLUDE_DIRS
)
set(PLUGIN_CLIENTSYNC_PACKAGE_FOUND ${PLUGIN_CLIENTSYNC_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_CLIENTSYNC_DEPENDS "ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;DL;RT;PTHREAD;BN-IPC;BOOST;BOOST_DATE_TIME;BOOST_SYSTEM" CACHE INTERNAL "" FORCE)
 