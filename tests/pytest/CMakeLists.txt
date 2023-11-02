
# ===================================================================
# パッケージの検査
# ===================================================================


# ===================================================================
# インクルードパスの設定
# ===================================================================
include_directories(
  ${Python3_INCLUDE_DIRS}
  )


# ===================================================================
# サブディレクトリの設定
# ===================================================================


# ===================================================================
#  ソースファイルの設定
# ===================================================================

set ( py_ymjson_SOURCES
  py_ymjson.cc
  )


# ===================================================================
#  executable ターゲットの設定
# ===================================================================

add_executable( py_ymjson
  ${py_ymjson_SOURCES}
  $<TARGET_OBJECTS:py_ymjson_obj>
  $<TARGET_OBJECTS:ym_json_obj>
  )

target_compile_options( py_ymjson
  PRIVATE "-O3"
  )

target_compile_definitions( py_ymjson
  PRIVATE "-DNODEBUG"
  )

target_link_libraries ( py_ymjson
  ${YM_LIB_DEPENDS}
  ${Python3_LIBRARIES}
  )

add_executable( py_ymjson_d
  ${py_ymjson_SOURCES}
  $<TARGET_OBJECTS:py_ymjson_obj_d>
  $<TARGET_OBJECTS:ym_json_obj_d>
  )

target_compile_options( py_ymjson_d
  PRIVATE "-g"
  )

target_link_libraries ( py_ymjson_d
  ${YM_LIB_DEPENDS}
  ${Python3_LIBRARIES}
  )


# ===================================================================
# テストターゲット
# ===================================================================

add_test( json_py_ymjson_test
  py_ymjson -m pytest ${CMAKE_CURRENT_SOURCE_DIR}
  )

set_property( TEST json_py_ymjson_test
  PROPERTY ENVIRONMENT TESTDATA_DIR=${TESTDATA_DIR}
  )
