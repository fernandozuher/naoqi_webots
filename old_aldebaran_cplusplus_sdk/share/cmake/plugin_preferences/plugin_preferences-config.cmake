# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_PREFERENCES_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_PREFERENCES_INCLUDE_DIRS)
   

find_library(PLUGIN_PREFERENCES_DEBUG_LIBRARY plugin_preferences_d)
find_library(PLUGIN_PREFERENCES_LIBRARY       plugin_preferences)


if (PLUGIN_PREFERENCES_DEBUG_LIBRARY)
  set(PLUGIN_PREFERENCES_LIBRARIES optimized;${PLUGIN_PREFERENCES_LIBRARY};debug;${PLUGIN_PREFERENCES_DEBUG_LIBRARY})
else()
  set(PLUGIN_PREFERENCES_LIBRARIES ${PLUGIN_PREFERENCES_LIBRARY})
endif()

set(PLUGIN_PREFERENCES_LIBRARIES ${PLUGIN_PREFERENCES_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_PREFERENCES DEFAULT_MSG
  PLUGIN_PREFERENCES_LIBRARIES
  PLUGIN_PREFERENCES_INCLUDE_DIRS
)
set(PLUGIN_PREFERENCES_PACKAGE_FOUND ${PLUGIN_PREFERENCES_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_PREFERENCES_DEPENDS "ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 