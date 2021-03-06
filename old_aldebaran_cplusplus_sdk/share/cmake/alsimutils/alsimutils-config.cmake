# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALSIMUTILS_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALSIMUTILS_INCLUDE_DIRS)
   

find_library(ALSIMUTILS_DEBUG_LIBRARY alsimutils_d)
find_library(ALSIMUTILS_LIBRARY       alsimutils)


if (ALSIMUTILS_DEBUG_LIBRARY)
  set(ALSIMUTILS_LIBRARIES optimized;${ALSIMUTILS_LIBRARY};debug;${ALSIMUTILS_DEBUG_LIBRARY})
else()
  set(ALSIMUTILS_LIBRARIES ${ALSIMUTILS_LIBRARY})
endif()

set(ALSIMUTILS_LIBRARIES ${ALSIMUTILS_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALSIMUTILS DEFAULT_MSG
  ALSIMUTILS_LIBRARIES
  ALSIMUTILS_INCLUDE_DIRS
)
set(ALSIMUTILS_PACKAGE_FOUND ${ALSIMUTILS_FOUND} CACHE INTERNAL "" FORCE)
 
set(ALSIMUTILS_DEPENDS "QT_QTCORE;ZLIB;ALROBOTMODEL;POSTURE;BOOST_SERIALIZATION;ALMODELUTILS;ALVALUE;ALERROR;QIMESSAGING;QITYPE;BOOST_DATE_TIME;ALMATHINTERNAL;ALMATH;EIGEN3;BOOST;ALSERIAL;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_SYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;BOOST_LOCALE;BOOST_THREAD;PTHREAD;DL;RT;TINYXML" CACHE INTERNAL "" FORCE)
 