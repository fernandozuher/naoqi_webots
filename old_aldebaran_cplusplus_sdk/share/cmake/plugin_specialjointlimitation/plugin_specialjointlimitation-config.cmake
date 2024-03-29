# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_SPECIALJOINTLIMITATION_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_SPECIALJOINTLIMITATION_INCLUDE_DIRS)
   

find_library(PLUGIN_SPECIALJOINTLIMITATION_DEBUG_LIBRARY plugin_specialjointlimitation_d)
find_library(PLUGIN_SPECIALJOINTLIMITATION_LIBRARY       plugin_specialjointlimitation)


if (PLUGIN_SPECIALJOINTLIMITATION_DEBUG_LIBRARY)
  set(PLUGIN_SPECIALJOINTLIMITATION_LIBRARIES optimized;${PLUGIN_SPECIALJOINTLIMITATION_LIBRARY};debug;${PLUGIN_SPECIALJOINTLIMITATION_DEBUG_LIBRARY})
else()
  set(PLUGIN_SPECIALJOINTLIMITATION_LIBRARIES ${PLUGIN_SPECIALJOINTLIMITATION_LIBRARY})
endif()

set(PLUGIN_SPECIALJOINTLIMITATION_LIBRARIES ${PLUGIN_SPECIALJOINTLIMITATION_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_SPECIALJOINTLIMITATION DEFAULT_MSG
  PLUGIN_SPECIALJOINTLIMITATION_LIBRARIES
  PLUGIN_SPECIALJOINTLIMITATION_INCLUDE_DIRS
)
set(PLUGIN_SPECIALJOINTLIMITATION_PACKAGE_FOUND ${PLUGIN_SPECIALJOINTLIMITATION_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_SPECIALJOINTLIMITATION_DEPENDS "NAO_DEVICES;PLUGIN_PREFERENCES;ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 