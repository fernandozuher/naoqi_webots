# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(NAOSPECIALSIMULATION_RUNNING_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(NAOSPECIALSIMULATION_RUNNING_INCLUDE_DIRS)
   

find_library(NAOSPECIALSIMULATION_RUNNING_DEBUG_LIBRARY naospecialsimulation_running_d)
find_library(NAOSPECIALSIMULATION_RUNNING_LIBRARY       naospecialsimulation_running)


if (NAOSPECIALSIMULATION_RUNNING_DEBUG_LIBRARY)
  set(NAOSPECIALSIMULATION_RUNNING_LIBRARIES optimized;${NAOSPECIALSIMULATION_RUNNING_LIBRARY};debug;${NAOSPECIALSIMULATION_RUNNING_DEBUG_LIBRARY})
else()
  set(NAOSPECIALSIMULATION_RUNNING_LIBRARIES ${NAOSPECIALSIMULATION_RUNNING_LIBRARY})
endif()

set(NAOSPECIALSIMULATION_RUNNING_LIBRARIES ${NAOSPECIALSIMULATION_RUNNING_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NAOSPECIALSIMULATION_RUNNING DEFAULT_MSG
  NAOSPECIALSIMULATION_RUNNING_LIBRARIES
  NAOSPECIALSIMULATION_RUNNING_INCLUDE_DIRS
)
set(NAOSPECIALSIMULATION_RUNNING_PACKAGE_FOUND ${NAOSPECIALSIMULATION_RUNNING_FOUND} CACHE INTERNAL "" FORCE)
 
set(NAOSPECIALSIMULATION_RUNNING_DEPENDS "NAO_RUNNING;PLUGIN_TEST;PLUGIN_IOCOMMUNICATION;PLUGIN_INITMOTORBOARD;PLUGIN_ACTUATORIFNOSTIFFNESS;PLUGIN_FSRTOTALCENTEROFPRESSION;PLUGIN_TESTROBOTVERSION;PLUGIN_MAXCURRENT;PLUGIN_SPECIALJOINTLIMITATION;PLUGIN_CLIENTSYNC;PLUGIN_INITNAODEVICES;NAO-MODULES;PLUGIN_MOTORTEMPERATURE;PLUGIN_CALIBRATION;PLUGIN_LEDIFNODCM;PLUGIN_SIMULATION;BN-IPC;BOOST_DATE_TIME;PLUGIN_SIMULATION_FILL_ATTRIBUTES;PLUGIN_NAOSPECIAL;PLUGIN_NAOAVAILABLEDEVICE;PLUGIN_DCMLOST;PLUGIN_GRIDEYE;PLUGIN_MEMBERIDENTIFICATION;PLUGIN_DIAGNOSIS;IO_HEADUSB;BN-USB;USB;IO_HEADI2C;IO_HUBI2C;PLUGIN_ADDNAODEVICESSPECIALSIMULATION;NAO_DEVICES;PLUGIN_PREFERENCES;ROBOT_DEVICES;HAL_COMMON;HAL_CORE;BN-COMMON;BN-XML;BN-RT;BOOST;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT" CACHE INTERNAL "" FORCE)
 