get_filename_component(_boost_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_boost_root "${_boost_root}/../../..")
get_filename_component(_boost_root ${_boost_root} ABSOLUTE)

set(BOOST_PYTHON_LIBRARIES
  ${_boost_root}/lib/libboost_python.so
  CACHE INTERNAL "" FORCE
)

set(BOOST_PYTHON_INCLUDE_DIRS
  ${_boost_root}/include
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(BOOST_PYTHON_DEPENDS "PYTHON")
export_lib(BOOST_PYTHON)
