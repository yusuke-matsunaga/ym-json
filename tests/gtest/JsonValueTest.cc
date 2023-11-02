
/// @file JsonValueTest.cc
/// @brief JsonValueTest の実装ファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2023 Yusuke Matsunaga
/// All rights reserved.

#include <gtest/gtest.h>
#include "ym/JsonValue.h"


BEGIN_NAMESPACE_YM

TEST(JsonValueTest, null)
{
  JsonValue json_obj;

  EXPECT_TRUE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );
  EXPECT_EQ( "null", json_obj.to_json() );
}

TEST(JsonValueTest, string1)
{
  const char* value = "abcde";
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_TRUE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_string() );
  ostringstream buf;
  buf << '"' << value << '"';
  EXPECT_EQ( buf.str(), json_obj.to_json() );
}

TEST(JsonValueTest, string2)
{
  string value = "abcde";
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_TRUE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_string() );
  ostringstream buf;
  buf << '"' << value << '"';
  EXPECT_EQ( buf.str(), json_obj.to_json() );
}

TEST(JsonValueTest, string_dq)
{
  string value = "\"abcde\"";
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_TRUE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_string() );
  EXPECT_EQ( "'\"abcde\"'", json_obj.to_json() );
}

TEST(JsonValueTest, string_sq)
{
  string value = "'abcde'";
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_TRUE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_string() );
  EXPECT_EQ( "\"'abcde'\"", json_obj.to_json() );
}

TEST(JsonValueTest, string_dqsq)
{
  string value = "\"'abcde'\"";
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_TRUE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_string() );
  EXPECT_EQ( R"("\"'abcde'\"")", json_obj.to_json() );
}

TEST(JsonValueTest, int)
{
  int value = 99;
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_TRUE( json_obj.is_number() );
  EXPECT_TRUE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_int() );
  ostringstream buf;
  buf << value;
  EXPECT_EQ( buf.str(), json_obj.to_json() );
}

TEST(JsonValueTest, float)
{
  double value = 1.2345;
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_TRUE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_TRUE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_float() );
  ostringstream buf;
  buf << value;
  EXPECT_EQ( buf.str(), json_obj.to_json() );
}

TEST(JsonValueTest, bool)
{
  bool value = true;
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_TRUE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_EQ( value, json_obj.get_bool() );
  EXPECT_EQ( "true", json_obj.to_json() );
}

TEST(JsonValueTest, array1)
{
  string value1 = "xyz";
  JsonValue json1{value1};

  int value2 = 2;
  JsonValue json2{value2};

  float value3 = 0.99;
  JsonValue json3{value3};

  vector<JsonValue> value{json1, json2, json3};
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_FALSE( json_obj.is_object() );
  EXPECT_TRUE( json_obj.is_array() );

  EXPECT_EQ( value.size(), json_obj.array_size() );
  EXPECT_EQ( json1, json_obj.at(0) );
  EXPECT_EQ( json2, json_obj.at(1) );
  EXPECT_EQ( json3, json_obj.at(2) );
}

TEST(JsonValueTest, object1)
{
  string value1 = "xyz";
  JsonValue json1{value1};

  int value2 = 2;
  JsonValue json2{value2};

  float value3 = 0.99;
  JsonValue json3{value3};

  unordered_map<string, JsonValue> value{
    {"key1", json1},
    {"key2", json2},
    {"key3", json3}
  };
  JsonValue json_obj{value};

  EXPECT_FALSE( json_obj.is_null() );
  EXPECT_FALSE( json_obj.is_string() );
  EXPECT_FALSE( json_obj.is_number() );
  EXPECT_FALSE( json_obj.is_int() );
  EXPECT_FALSE( json_obj.is_float() );
  EXPECT_FALSE( json_obj.is_bool() );
  EXPECT_TRUE( json_obj.is_object() );
  EXPECT_FALSE( json_obj.is_array() );

  EXPECT_TRUE( json_obj.has_key("key1") );
  EXPECT_EQ( json1, json_obj.at("key1") );
  EXPECT_TRUE( json_obj.has_key("key2") );
  EXPECT_EQ( json2, json_obj.at("key2") );
  EXPECT_TRUE( json_obj.has_key("key3") );
  EXPECT_EQ( json3, json_obj.at("key3") );
}

END_NAMESPACE_YM
