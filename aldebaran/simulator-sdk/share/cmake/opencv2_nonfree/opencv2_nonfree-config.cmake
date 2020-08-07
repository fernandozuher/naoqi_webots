get_filename_component(_opencv2_nonfree_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_nonfree_root "${_opencv2_nonfree_root}/../../..")
get_filename_component(_opencv2_nonfree_root "${_opencv2_nonfree_root}" ABSOLUTE)

set(OPENCV2_NONFREE_LIBRARIES
  ${_opencv2_nonfree_root}/lib/libopencv_nonfree.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_NONFREE_INCLUDE_DIRS
  ${_opencv2_nonfree_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_NONFREE_DEPENDS OPENCV2_CORE OPENCV2_IMGPROC OPENCV2_FEATURES2D OPENCV2_FLANN OPENCV2_OCL)

export_lib(OPENCV2_NONFREE)
