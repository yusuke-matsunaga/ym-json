# ===================================================================
# CMAKE のおまじない
# ===================================================================


# ===================================================================
# プロジェクト名，バージョンの設定
# ===================================================================


# ===================================================================
# オプション
# ===================================================================


# ===================================================================
# パッケージの検査
# ===================================================================


# ===================================================================
# ヘッダファイルの生成
# ===================================================================


# ===================================================================
# インクルードパスの設定
# ===================================================================

include_directories (
  )


# ===================================================================
#  マクロの定義
# ===================================================================


# ===================================================================
# サブディレクトリの設定
# ===================================================================

add_subdirectory ( py_ymjson )
add_subdirectory ( tests )


# ===================================================================
#  ソースの設定
# ===================================================================

set ( ym_json_SOURCES
  c++-srcs/JsonValue.cc
  c++-srcs/JsonObj.cc
  c++-srcs/JsonParser.cc
  c++-srcs/JsonScanner.cc
  )


# ===================================================================
#  ターゲットの設定
# ===================================================================

ym_add_object_library ( ym_json
  ${ym_json_SOURCES}
  )
