# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(ALMATH_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(ALMATH_INCLUDE_DIRS)
   

find_library(ALMATH_DEBUG_LIBRARY almath_d)
find_library(ALMATH_LIBRARY       almath)


if (ALMATH_DEBUG_LIBRARY)
  set(ALMATH_LIBRARIES optimized;${ALMATH_LIBRARY};debug;${ALMATH_DEBUG_LIBRARY})
else()
  set(ALMATH_LIBRARIES ${ALMATH_LIBRARY})
endif()

set(ALMATH_LIBRARIES ${ALMATH_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALMATH DEFAULT_MSG
  ALMATH_LIBRARIES
  ALMATH_INCLUDE_DIRS
)
set(ALMATH_PACKAGE_FOUND ${ALMATH_FOUND} CACHE INTERNAL "" FORCE)
 
set(ALMATH_DEPENDS "" CACHE INTERNAL "" FORCE)
 