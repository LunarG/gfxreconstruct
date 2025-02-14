#!/usr/bin/python3 -i
#
# Copyright (c) 2021 LunarG, Inc.
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

import os, re, sys, inspect
from khronos_base_generator import write


# KhronosEnumToStringHeaderGenerator
# Generates C++ functions for stringifying Khronos API enums.
class KhronosEnumToStringHeaderGenerator():
    """Generate C++ functions for Khronos ToString() functions"""

    def skip_generating_enum_to_string_for_type(self, type):
        """ Method may be overridden"""
        return False

    def write_enum_to_string_header(self, use_flags_for_64bit_enum=False):
        api_data = self.get_api_data()
        flags_type = api_data.flags_type
        flags64_type = api_data.flags_64_type
        flag_variable = api_data.type_prefix.lower() + 'Flags'

        for enum in sorted(self.enum_names):
            if enum in self.enumAliases or self.skip_generating_enum_to_string_for_type(
                enum
            ):
                continue
            if self.is_flags_enum_64bit(enum):
                if use_flags_for_64bit_enum:
                    body = 'std::string {0}ToString(const {1} value);'
                else:
                    body = 'std::string {0}ToString(const {0} value);'
                body += '\nstd::string {1}ToString({2} {3});'
            else:
                body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'
                if 'Bits' in enum:
                    body += '\ntemplate <> std::string ToString<{0}>({4} {3}, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'
            write(
                body.format(enum, self.get_flags_type_from_enum(enum), flags64_type, flag_variable, flags_type),
                file=self.outFile
            )
