get_filename_component(_opencv2_calib3d_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_calib3d_root "${_opencv2_calib3d_root}/../../..")
get_filename_component(_opencv2_calib3d_root "${_opencv2_calib3d_root}" ABSOLUTE)

set(OPENCV2_CALIB3D_LIBRARIES
  ${_opencv2_calib3d_root}/lib/libopencv_calib3d.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_CALIB3D_INCLUDE_DIRS
  ${_opencv2_calib3d_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_CALIB3D_DEPENDS OPENCV2_CORE OPENCV2_FEATURES2D)
export_lib(OPENCV2_CALIB3D)
