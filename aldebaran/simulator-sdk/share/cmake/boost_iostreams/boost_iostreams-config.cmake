get_filename_component(_boost_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_boost_root "${_boost_root}/../../..")
get_filename_component(_boost_root ${_boost_root} ABSOLUTE)

set(BOOST_IOSTREAMS_LIBRARIES
  ${_boost_root}/lib/libboost_iostreams.so
  CACHE INTERNAL "" FORCE
)

set(BOOST_IOSTREAMS_INCLUDE_DIRS
  ${_boost_root}/include
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(BOOST_IOSTREAMS_DEPENDS BOOST_SYSTEM)
export_lib(BOOST_IOSTREAMS)
