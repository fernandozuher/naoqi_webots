get_filename_component(_boost_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_boost_root "${_boost_root}/../../..")
get_filename_component(_boost_root ${_boost_root} ABSOLUTE)

set(BOOST_SYSTEM_LIBRARIES
  ${_boost_root}/lib/libboost_system.so
  CACHE INTERNAL "" FORCE
)

set(BOOST_SYSTEM_INCLUDE_DIRS
  ${_boost_root}/include
  CACHE INTERNAL "" FORCE
)

export_lib(BOOST_SYSTEM)
