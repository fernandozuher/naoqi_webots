get_filename_component(_opencv2_ocl_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_opencv2_ocl_root "${_opencv2_ocl_root}/../../..")
get_filename_component(_opencv2_ocl_root "${_opencv2_ocl_root}" ABSOLUTE)

set(OPENCV2_OCL_LIBRARIES
  ${_opencv2_ocl_root}/lib/libopencv_ocl.so
  CACHE INTERNAL "" FORCE
)

set(OPENCV2_OCL_INCLUDE_DIRS
  ${_opencv2_ocl_root}/include/
  CACHE INTERNAL "" FORCE
)

export_lib(OPENCV2_OCL)
