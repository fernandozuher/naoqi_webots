get_filename_component(_qtgui_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_qtgui_root "${_qtgui_root}/../../..")
get_filename_component(_qtgui_root "${_qtgui_root}" ABSOLUTE)

set(QT_QTGUI_LIBRARIES
  ${_qtgui_root}/lib/libQtGui.so
  CACHE INTERNAL "" FORCE
)

set(QT_QTGUI_INCLUDE_DIRS
  ${_qtgui_root}/include
  ${_qtgui_root}/include/QtGui
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(QT_QTGUI_DEPENDS QT_QTCORE)
export_lib(QT_QTGUI)
