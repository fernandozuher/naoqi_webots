# This is an autogenerated file. Do not edit

get_filename_component(_cur_dir ${CMAKE_CURRENT_LIST_FILE} PATH)
set(_root_dir "${_cur_dir}/../../../")
get_filename_component(ROOT_DIR ${_root_dir} ABSOLUTE)

 
set(BN-I2C_INCLUDE_DIRS "${ROOT_DIR}/include;" CACHE STRING "" FORCE)
mark_as_advanced(BN-I2C_INCLUDE_DIRS)
   

find_library(BN-I2C_DEBUG_LIBRARY bn-i2c_d)
find_library(BN-I2C_LIBRARY       bn-i2c)


if (BN-I2C_DEBUG_LIBRARY)
  set(BN-I2C_LIBRARIES optimized;${BN-I2C_LIBRARY};debug;${BN-I2C_DEBUG_LIBRARY})
else()
  set(BN-I2C_LIBRARIES ${BN-I2C_LIBRARY})
endif()

set(BN-I2C_LIBRARIES ${BN-I2C_LIBRARIES} CACHE INTERNAL "" FORCE)
 
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BN-I2C DEFAULT_MSG
  BN-I2C_LIBRARIES
  BN-I2C_INCLUDE_DIRS
)
set(BN-I2C_PACKAGE_FOUND ${BN-I2C_FOUND} CACHE INTERNAL "" FORCE)
 
set(BN-I2C_DEPENDS "BOOST" CACHE INTERNAL "" FORCE)
 