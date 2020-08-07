get_filename_component(_opencv2_objdetect_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_objdetect_root "${_opencv2_objdetect_root}/../../..")
get_filename_component(_opencv2_objdetect_root "${_opencv2_objdetect_root}" ABSOLUTE)

set(OPENCV2_OBJDETECT_LIBRARIES
  ${_opencv2_objdetect_root}/lib/libopencv_objdetect.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_OBJDETECT_INCLUDE_DIRS
  ${_opencv2_objdetect_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_OBJDETECT_DEPENDS OPENCV2_CORE OPENCV2_FEATURES2D)
export_lib(OPENCV2_OBJDETECT)
