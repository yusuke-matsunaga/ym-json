#! /usr/bin/env python3

"""py_ymjson のテストプログラム

:file: json_test.py
:author: Yusuke Matsunaga (松永 裕介)
:copyright: Copyright (C) 2023 Yusuke Matsunaga, All rights reserved.
"""

import pytest
import os
import os.path
from ymjson import JsonValue


def test_null():
    val = JsonValue()

    assert val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

def test_string():
    str_val = "abcde"
    val = JsonValue(str_val)

    assert not val.is_null()
    assert val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

    assert str_val == val.get_string()

def test_int():
    int_val = 99
    val = JsonValue(int_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert val.is_number()
    assert val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

    assert int_val == val.get_int()

def test_float():
    float_val = 1.2345
    val = JsonValue(float_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert val.is_number()
    assert not val.is_int()
    assert val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

    assert float_val == val.get_float()

def test_bool_true():
    bool_val = True
    val = JsonValue(bool_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

    assert bool_val == val.get_bool()

def test_bool_false():
    bool_val = False
    val = JsonValue(bool_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert val.is_bool()
    assert not val.is_object()
    assert not val.is_array()

    assert bool_val == val.get_bool()

def test_array1():
    array_val = ["xyz", 2, 0.99]
    val = JsonValue(array_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert val.is_array()

    assert len(val) == 3
    elem0 = val[0]
    assert elem0.is_string()
    assert elem0.get_string() == "xyz"
    elem1 = val[1]
    assert elem1.is_int()
    assert elem1.get_int() == 2
    elem2 = val[2]
    assert elem2.is_float()
    assert elem2.get_float == 0.99

    elem_1 = val[-1]
    assert elem_1.is_float()
    elem_2 = val[-2]
    assert elem_2.is_int()
    elem_3 = val[-3]
    assert elem_3.is_string()
    
def test_array1():
    array_val = ("xyz", 2, 0.99)
    val = JsonValue(array_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert not val.is_object()
    assert val.is_array()

    assert len(val) == 3
    elem0 = val[0]
    assert elem0.is_string()
    assert elem0.get_string() == "xyz"
    elem1 = val[1]
    assert elem1.is_int()
    assert elem1.get_int() == 2
    elem2 = val[2]
    assert elem2.is_float()
    assert elem2.get_float() == 0.99

    elem_1 = val[-1]
    assert elem_1.is_float()
    elem_2 = val[-2]
    assert elem_2.is_int()
    elem_3 = val[-3]
    assert elem_3.is_string()

def test_object():
    dict_val = {
        "key1": "xyz",
        "key2": 2,
        "key3": 0.99
        }
    val = JsonValue(dict_val)
    
    assert not val.is_null()
    assert not val.is_string()
    assert not val.is_number()
    assert not val.is_int()
    assert not val.is_float()
    assert not val.is_bool()
    assert val.is_object()
    assert not val.is_array()

    elem1 = val["key1"]
    assert elem1.is_string()
    assert elem1.get_string() == "xyz"
    elem2 = val["key2"]
    assert elem2.is_int()
    assert elem2.get_int() == 2
    elem3 = val["key3"]
    assert elem3.is_float()
    assert elem3.get_float() == 0.99
    
def test_parse_int():

    source_str = '{ "key1": 123 }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")
    
def test_parse_float():

    source_str = '{ "key1": 123.456 }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_string():

    source_str = '{ "key1": "abcdefg" }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_true():

    source_str = '{ "key1": true }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_false():

    source_str = '{ "key1": false }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_null():

    source_str = '{ "key1": null }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_object():

    source_str = '{ "key1": 1, "key2" : 2 }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_parse_array():

    source_str = '{ "key1": [1, 0.5, true, "abc"] }'
    val = JsonValue.parse(source_str)

    assert val.is_object()
    assert val.has_key("key1")

def test_read():
    filename = "test.json"
    DATA_DIR = os.environ.get('TESTDATA_DIR')
    path = os.path.join(DATA_DIR, filename)

    val = JsonValue.read(path)

    assert val.is_object()
    assert val.has_key("str_key")

