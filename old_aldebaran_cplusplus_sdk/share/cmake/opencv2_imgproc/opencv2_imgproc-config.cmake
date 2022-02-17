get_filename_component(_opencv2_imgproc_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_imgproc_root "${_opencv2_imgproc_root}/../../..")
get_filename_component(_opencv2_imgproc_root "${_opencv2_imgproc_root}" ABSOLUTE)

set(OPENCV2_IMGPROC_LIBRARIES
  ${_opencv2_imgproc_root}/lib/libopencv_imgproc.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_IMGPROC_INCLUDE_DIRS
  ${_opencv2_imgproc_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_IMGPROC_DEPENDS OPENCV2_CORE)
export_lib(OPENCV2_IMGPROC)
