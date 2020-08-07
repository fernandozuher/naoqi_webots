get_filename_component(_qttest_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_qttest_root "${_qttest_root}/../../..")
get_filename_component(_qttest_root "${_qttest_root}" ABSOLUTE)

set(QT_QTTEST_LIBRARIES
  ${_qttest_root}/lib/libQtTest.so
  CACHE INTERNAL "" FORCE
)

set(QT_QTTEST_INCLUDE_DIRS
  ${_qttest_root}/include
  ${_qttest_root}/include/QtTest
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(QT_QTTEST_DEPENDS QT_QTCORE)
export_lib(QT_QTTEST)
