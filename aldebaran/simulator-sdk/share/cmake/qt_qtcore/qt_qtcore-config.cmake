get_filename_component(_qtcore_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_qtcore_root "${_qtcore_root}/../../..")
get_filename_component(_qtcore_root "${_qtcore_root}" ABSOLUTE)

set(QT_QTCORE_LIBRARIES
  ${_qtcore_root}/lib/libQtCore.so
  CACHE INTERNAL "" FORCE
)

set(QT_QTCORE_INCLUDE_DIRS
  ${_qtcore_root}/include
  ${_qtcore_root}/include/QtCore
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(QT_QTCORE_DEPENDS ZLIB)
export_lib(QT_QTCORE)
