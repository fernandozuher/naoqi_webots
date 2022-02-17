get_filename_component(_qtnetwork_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_qtnetwork_root "${_qtnetwork_root}/../../..")
get_filename_component(_qtnetwork_root "${_qtnetwork_root}" ABSOLUTE)

set(QT_QTNETWORK_LIBRARIES
  ${_qtnetwork_root}/lib/libQtNetwork.so
  CACHE INTERNAL "" FORCE
)

set(QT_QTNETWORK_INCLUDE_DIRS
  ${_qtnetwork_root}/include
  ${_qtnetwork_root}/include/QtNetwork
  CACHE INTERNAL "" FORCE
)

export_lib(QT_QTNETWORK)
