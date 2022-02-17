# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(BN-PS_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(BN-PS_INCLUDE_DIRS)
   

find_library(BN-PS_DEBUG_LIBRARY bn-ps_d)
find_library(BN-PS_LIBRARY       bn-ps)


if (BN-PS_DEBUG_LIBRARY)
  set(BN-PS_LIBRARIES optimized;${BN-PS_LIBRARY};debug;${BN-PS_DEBUG_LIBRARY})
else()
  set(BN-PS_LIBRARIES ${BN-PS_LIBRARY})
endif()

set(BN-PS_LIBRARIES ${BN-PS_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BN-PS DEFAULT_MSG
  BN-PS_LIBRARIES
  BN-PS_INCLUDE_DIRS
)
set(BN-PS_PACKAGE_FOUND ${BN-PS_FOUND} CACHE INTERNAL "" FORCE)
 
set(BN-PS_DEPENDS "BOOST;BOOST_FILESYSTEM;BOOST_SYSTEM;PTHREAD" CACHE INTERNAL "" FORCE)
 