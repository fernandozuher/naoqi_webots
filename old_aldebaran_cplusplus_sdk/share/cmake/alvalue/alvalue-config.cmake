# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALVALUE_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALVALUE_INCLUDE_DIRS)
   

find_library(ALVALUE_DEBUG_LIBRARY alvalue_d)
find_library(ALVALUE_LIBRARY       alvalue)


if (ALVALUE_DEBUG_LIBRARY)
  set(ALVALUE_LIBRARIES optimized;${ALVALUE_LIBRARY};debug;${ALVALUE_DEBUG_LIBRARY})
else()
  set(ALVALUE_LIBRARIES ${ALVALUE_LIBRARY})
endif()

set(ALVALUE_LIBRARIES ${ALVALUE_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALVALUE DEFAULT_MSG
  ALVALUE_LIBRARIES
  ALVALUE_INCLUDE_DIRS
)
set(ALVALUE_PACKAGE_FOUND ${ALVALUE_FOUND} CACHE INTERNAL "" FORCE)
 
set(ALVALUE_DEPENDS "ALERROR;QIMESSAGING;QITYPE;QI;BOOST_CHRONO;BOOST_FILESYSTEM;BOOST_PROGRAM_OPTIONS;BOOST_REGEX;DL;RT;BOOST;BOOST_DATE_TIME;BOOST_SYSTEM;BOOST_LOCALE;BOOST_THREAD;PTHREAD" CACHE INTERNAL "" FORCE)
 