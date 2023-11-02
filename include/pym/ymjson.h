#ifndef PYM_YMJSON_H
#define PYM_YMJSON_H

/// @file ymjson.h
/// @brief ymjson の初期化関数のエクスポート
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2023 Yusuke Matsunaga
/// All rights reserved.

#include "ym_config.h"


BEGIN_NAMESPACE_YM

/// @brief ymjson モジュールの初期化関数
extern "C" PyObject* PyInit_ymjson();

END_NAMESPACE_YM

#endif // PYM_YMJSON_H
