
# ===================================================================
# インクルードパスの設定
# ===================================================================

include_directories (
  ../../c++-srcs/
  )


# ===================================================================
# サブディレクトリの設定
# ===================================================================


# ===================================================================
#  ソースファイルの設定
# ===================================================================


# ===================================================================
#  テスト用のターゲットの設定
# ===================================================================

ym_add_gtest ( json_JsonObjTest
  JsonObjTest.cc
  $<TARGET_OBJECTS:ym_json_obj_d>
  )

ym_add_gtest ( json_JsonValueTest
  JsonValueTest.cc
  $<TARGET_OBJECTS:ym_json_obj_d>
  )

ym_add_gtest ( json_JsonScannerTest
  JsonScannerTest.cc
  $<TARGET_OBJECTS:ym_json_obj_d>
  )

ym_add_gtest ( json_JsonParserTest
  JsonParserTest.cc
  $<TARGET_OBJECTS:ym_json_obj_d>
  )

ym_add_gtest ( json_JsonTest
  JsonTest.cc
  $<TARGET_OBJECTS:ym_json_obj_d>
  DEFINITIONS
  "-DTESTDATA_DIR=\"${TESTDATA_DIR}\""
  )
