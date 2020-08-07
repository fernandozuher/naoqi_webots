get_filename_component(_opencv2_flann_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_flann_root "${_opencv2_flann_root}/../../..")
get_filename_component(_opencv2_flann_root "${_opencv2_flann_root}" ABSOLUTE)

set(OPENCV2_FLANN_LIBRARIES
  ${_opencv2_flann_root}/lib/libopencv_flann.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_FLANN_INCLUDE_DIRS
  ${_opencv2_flann_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_FLANN_DEPENDS OPENCV2_CORE)
export_lib(OPENCV2_FLANN)
