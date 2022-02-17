get_filename_component(_opencv2_core_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_core_root "${_opencv2_core_root}/../../..")
get_filename_component(_opencv2_core_root "${_opencv2_core_root}" ABSOLUTE)

set(OPENCV2_CORE_LIBRARIES
  ${_opencv2_core_root}/lib/libopencv_core.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_CORE_INCLUDE_DIRS
  ${_opencv2_core_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_CORE_DEPENDS ZLIB)
export_lib(OPENCV2_CORE)
