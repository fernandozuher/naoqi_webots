# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(DCM_HAL_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(DCM_HAL_INCLUDE_DIRS)
   

find_library(DCM_HAL_DEBUG_LIBRARY dcm_hal_d PATH_SUFFIXES naoqi)
find_library(DCM_HAL_LIBRARY       dcm_hal   PATH_SUFFIXES naoqi)


if (DCM_HAL_DEBUG_LIBRARY)
  set(DCM_HAL_LIBRARIES optimized;${DCM_HAL_LIBRARY};debug;${DCM_HAL_DEBUG_LIBRARY})
else()
  set(DCM_HAL_LIBRARIES ${DCM_HAL_LIBRARY})
endif()

set(DCM_HAL_LIBRARIES ${DCM_HAL_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DCM_HAL DEFAULT_MSG
  DCM_HAL_LIBRARIES
  DCM_HAL_INCLUDE_DIRS
)
set(DCM_HAL_PACKAGE_FOUND ${DCM_HAL_FOUND} CACHE INTERNAL "" FORCE)
 
set(DCM_HAL_DEPENDS "BN-IPC;DCM_PLUGINS;PLUGIN_ALMEMORY;PLUGIN_TIMEDCOMMAND;LIB_DCM;ALPROXIES;ALTHREAD;ALCOMMON;ALVALUE;ALERROR;QIMESSAGING;QITYPE;BOOST_DATE_TIME;BOOST_SIGNALS;RTTOOLS;NAO_DEVICES;ROMEO_DEVICES;JULIETTE_DEVICES;PLUGIN_PREFERENCES;PLUGIN_CHANGE_SPECIAL;ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 