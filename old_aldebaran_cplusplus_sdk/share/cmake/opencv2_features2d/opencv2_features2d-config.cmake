get_filename_component(_opencv2_features2d_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_features2d_root "${_opencv2_features2d_root}/../../..")
get_filename_component(_opencv2_features2d_root "${_opencv2_features2d_root}" ABSOLUTE)

set(OPENCV2_FEATURES2D_LIBRARIES
  ${_opencv2_features2d_root}/lib/libopencv_features2d.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_FEATURES2D_INCLUDE_DIRS
  ${_opencv2_features2d_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_FEATURES2D_DEPENDS OPENCV2_CORE OPENCV2_FLANN)
export_lib(OPENCV2_FEATURES2D)
