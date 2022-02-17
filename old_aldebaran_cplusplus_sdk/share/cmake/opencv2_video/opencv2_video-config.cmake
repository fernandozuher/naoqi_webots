get_filename_component(_opencv2_video_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_video_root "${_opencv2_video_root}/../../..")
get_filename_component(_opencv2_video_root "${_opencv2_video_root}" ABSOLUTE)

set(OPENCV2_VIDEO_LIBRARIES
  ${_opencv2_video_root}/lib/libopencv_video.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_VIDEO_INCLUDE_DIRS
  ${_opencv2_video_root}/include
  CACHE INTERNAL "" FORCE
)

export_lib(OPENCV2_VIDEO)
