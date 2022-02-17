get_filename_component(_qtsql_root "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(_qtsql_root "${_qtsql_root}/../../..")
get_filename_component(_qtsql_root "${_qtsql_root}" ABSOLUTE)

set(QT_QTSQL_LIBRARIES
  ${_qtsql_root}/lib/libQtSql.so
  CACHE INTERNAL "" FORCE
)

set(QT_QTSQL_INCLUDE_DIRS
  ${_qtsql_root}/include
  ${_qtsql_root}/include/QtSql
  CACHE INTERNAL "" FORCE
)

qi_persistent_set(QT_QTSQL_DEPENDS QT_QTCORE)
export_lib(QT_QTSQL)
