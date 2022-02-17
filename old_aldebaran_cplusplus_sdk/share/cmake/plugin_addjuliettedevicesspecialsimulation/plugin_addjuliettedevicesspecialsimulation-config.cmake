# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_INCLUDE_DIRS)
   

find_library(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_DEBUG_LIBRARY plugin_addjuliettedevicesspecialsimulation_d)
find_library(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARY       plugin_addjuliettedevicesspecialsimulation)


if (PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_DEBUG_LIBRARY)
  set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARIES optimized;${PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARY};debug;${PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_DEBUG_LIBRARY})
else()
  set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARIES ${PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARY})
endif()

set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARIES ${PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION DEFAULT_MSG
  PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_LIBRARIES
  PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_INCLUDE_DIRS
)
set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_PACKAGE_FOUND ${PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_FOUND} CACHE INTERNAL "" FORCE)
 
set(PLUGIN_ADDJULIETTEDEVICESSPECIALSIMULATION_DEPENDS "NAO_DEVICES;PLUGIN_PREFERENCES;ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 