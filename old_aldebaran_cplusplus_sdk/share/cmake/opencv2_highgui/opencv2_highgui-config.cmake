get_filename_component(_opencv2_highgui_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_highgui_root "${_opencv2_highgui_root}/../../..")
get_filename_component(_opencv2_highgui_root "${_opencv2_highgui_root}" ABSOLUTE)

set(OPENCV2_HIGHGUI_LIBRARIES
  ${_opencv2_highgui_root}/lib/libopencv_highgui.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_HIGHGUI_INCLUDE_DIRS
  ${_opencv2_highgui_root}/include/
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENCV2_HIGHGUI_DEPENDS OPENCV2_CORE OPENCV2_IMGPROC)

export_lib(OPENCV2_HIGHGUI)
