#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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

import sys
from khronos_base_generator import write


class KhronosStructEncodersHeaderGenerator():
    """KhronosStructEncodersHeaderGenerator
    Generates C++ type and function declarations for encoding Khronos API structures.
    """

    def skip_struct_type(self, struct_type):
        """Override as needed"""
        return False

    def write_encoder_content(self):
        ext_struct_prefix = self.get_extended_struct_func_prefix()

        write(
            'void Encode{}Struct(ParameterEncoder* encoder, const void* value);'
            .format(ext_struct_prefix),
            file=self.outFile
        )

        for struct in self.get_all_filtered_struct_names():
            if self.skip_struct_type(struct):
                continue

            write(
                'void EncodeStruct(ParameterEncoder* encoder, const {}& value);'
                .format(struct),
                file=self.outFile
            )

            # If this struct is a parent struct, we need to support encoding an array loop to
            # decipher children information
            if struct in self.children_structs:
                write(
                    '\ntemplate <>\nvoid EncodeStructArrayLoop<{struct}>(ParameterEncoder* encoder, const {struct}* value, size_t len);'
                    .format(struct=struct),
                    file=self.outFile
                )
