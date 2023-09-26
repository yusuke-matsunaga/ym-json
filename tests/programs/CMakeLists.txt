
# ===================================================================
# インクルードパスの設定
# ===================================================================


# ===================================================================
# サブディレクトリの設定
# ===================================================================


# ===================================================================
#  ソースファイルの設定
# ===================================================================


# ===================================================================
#  RandSamplerTest
# ===================================================================

set ( RandSamplerTest_SOURCES
  RandSamplerTest.cc
  )

add_executable ( RandSamplerTest
  ${RandSamplerTest_SOURCES}
  $<TARGET_OBJECTS:ym_base_obj>
  )

target_compile_options ( RandSamplerTest
  PRIVATE "-O3"
  )

target_compile_definitions ( RandSamplerTest
  PRIVATE "-DNDEBUG"
  )

target_link_libraries ( RandSamplerTest
  pthread
  ${YM_LIB_DEPENDS}
  )
