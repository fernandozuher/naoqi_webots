
get_filename_component(_eigen_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_eigen_root "${_eigen_root}/../../..")
get_filename_component(_eigen_root "${_eigen_root}" ABSOLUTE)

set(EIGEN3_INCLUDE_DIRS
  ${_eigen_root}/include/eigen3
  CACHE INTERNAL "" FORCE
)

export_header(EIGEN3)
