get_filename_component(_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_root "${_root}/../../..")
get_filename_component(_root ${_root} ABSOLUTE)

set(OPENSSL_LIBRARIES
  ${_root}/lib/libssl.so
  ${_root}/lib/libcrypto.so
  CACHE INTERNAL "" FORCE
)

set(OPENSSL_INCLUDE_DIRS
  ${_root}/include
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(OPENSSL_DEPENDS "DL")
export_lib(OPENSSL)
