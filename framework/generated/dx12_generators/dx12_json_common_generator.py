#!/usr/bin/env python3
#
# Copyright (c) 2023 LunarG, Inc.
# Copyright (c) 2023 Valve Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_enum_to_string_header_generator import Dx12EnumToStringHeaderGenerator  # For the list of substrings in bitflag enums.


# returns true if any of the strings in the list appear at the end of the string.
def ends_with_any(string, suffixes):
    for suffix in suffixes:
        if string.endswith(suffix):
            return True
    return False


# Base class with features shared by multiple DX12 JSON Generators.
class Dx12JsonCommonGenerator(Dx12BaseGenerator):

    BIT_FLAG_SUFFIXES = Dx12EnumToStringHeaderGenerator.BITS_LIST

    ## A set of strings which are the types of arguments and struct fields which should be output as hexadecimal.
    ## @todo Expand this to include more types.
    HEX_TYPES = {"D3D12_GPU_VIRTUAL_ADDRESS"}

    ## @param value_info A ValueInfo object from base_generator.py.
    def is_raw_bitflags(self, value_info):
        if (not ends_with_any(value_info.base_type, self.BIT_FLAG_SUFFIXES)
            ) and value_info.base_type.upper(
            ).startswith('UINT') and value_info.name.upper().endswith("MASK"):
            return True
        return False

    ## @param value_info A ValueInfo object from base_generator.py.
    def choose_field_to_json_name(self, value_info):
        if value_info != None:
            if value_info.base_type in self.HEX_TYPES:
                return "FieldToJsonAsHex"
            if "BOOL" in value_info.base_type:
                return "Bool32ToJson"
            if self.is_handle(value_info.base_type):
                return "HandleToJson"
            if ("HRESULT" in value_info.base_type):
                return "HresultToJson"
            if ends_with_any(value_info.base_type, self.BIT_FLAG_SUFFIXES):
                return "FieldToJson_" + value_info.base_type
            if self.is_raw_bitflags(value_info):
                return "FieldToJsonAsFixedWidthBinary"
        return "FieldToJson"

    pass
