# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_NAOSPECIAL_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_NAOSPECIAL_INCLUDE_DIRS)
   

find_library(PLUGIN_NAOSPECIAL_DEBUG_LIBRARY plugin_naospecial_d)
find_library(PLUGIN_NAOSPECIAL_LIBRARY       plugin_naospecial)


if (PLUGIN_NAOSPECIAL_DEBUG_LIBRARY)
  set(PLUGIN_NAOSPECIAL_LIBRARIES optimized;${PLUGIN_NAOSPECIAL_LIBRARY};debug;${PLUGIN_NAOSPECIAL_DEBUG_LIBRARY})
else()
  set(PLUGIN_NAOSPECIAL_LIBRARIES ${PLUGIN_NAOSPECIAL_LIBRARY})
endif()

set(PLUGIN_NAOSPECIAL_LIBRARIES ${PLUGIN_NAOSPECIAL_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_NAOSPECIAL DEFAULT_MSG
  PLUGIN_NAOSPECIAL_LIBRARIES
  PLUGIN_NAOSPECIAL_INCLUDE_DIRS
)
set(PLUGIN_NAOSPECIAL_PACKAGE_FOUND ${PLUGIN_NAOSPECIAL_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_NAOSPECIAL_DEPENDS "NAO_DEVICES;PLUGIN_PREFERENCES;ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 