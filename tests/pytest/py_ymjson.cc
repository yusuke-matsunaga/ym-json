
/// @file py_ymjson.cc
/// @brief py_ymjson の実装ファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2023 Yusuke Matsunaga
/// All rights reserved.

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "pym/ymjson.h"


int
main(
  int argc,
  char** argv
)
{
  PyImport_AppendInittab("ymjson", &YM_NAMESPACE::PyInit_ymjson);

  return Py_BytesMain(argc, argv);
}
