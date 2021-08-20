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

import sys
from base_generator import write
from dx12_command_list_util_header_generator import Dx12CommandListUtilHeaderGenerator


class Dx12CommandListUtilBodyGenerator(Dx12CommandListUtilHeaderGenerator):
    """Generate a C++ class for Dx12 Track CommandList objects.
    """
    INDENT = ' ' * 4

    def get_track_function_body(self, class_name, method_info):
        code = '\n'
        code += '{\n'
        code += self.INDENT + 'assert(wrapper != nullptr);\n'
        code += self.INDENT + 'auto info = wrapper->GetObjectInfo();\n'
        code += self.INDENT + 'assert(info != nullptr);\n'
        for p in method_info['parameters']:
            value = self.get_value_info(p)
            if self.is_class(value):
                code += self.get_track_object('', value, 1)

            elif self.has_class_in_struct(value.base_type, False):
                code += self.get_track_struct('', value, 1)

        code += '}\n'
        return code

    def get_track_object(self, param_name, value, indent):
        if param_name:
            param_name2 = param_name + '->' + value.name
        else:
            param_name2 = value.name

        code = '\n' + self.INDENT * indent + 'if(' + param_name2 + ' != nullptr)\n'
        code += self.INDENT * indent + '{\n'
        indent_track = indent + 1

        if value.is_array:
            code += self.INDENT * (
                indent + 1
            ) + 'for (UINT i = 0; i < {}; ++i)\n'.format(value.array_length)
            code += self.INDENT * (indent + 1) + '{\n'
            indent_track += 1
            param_name2 += '[i]'

        code += self.INDENT * indent_track + 'info->command_objects[D3D12GraphicsCommandObjectType::' + value.base_type + 'Object].insert(GetWrappedId(' + param_name2 + '));\n'

        if value.is_array:
            code += self.INDENT * (indent + 1) + '}\n'

        code += self.INDENT * indent + '}\n'
        return code

    def get_track_struct(self, param_name, value, indent):
        if value.is_array:
            print(
                "ERROR: Code generation doesn't deal with array struct {}{} for track command objects",
                value.name, value.base_type
            )
        struct_info = self.get_struct_info(value.base_type)

        if param_name:
            param_name2 = param_name + '->' + value.name
        else:
            param_name2 = value.name

        code = '\n' + self.INDENT * indent + 'if(' + param_name2 + ' != nullptr)\n'
        code += self.INDENT * indent + '{'
        properties = struct_info['properties']
        for k, v in properties.items():
            for p in v:
                value = self.get_value_info(p)
                if self.is_class(value):
                    code += self.get_track_object(
                        param_name2, value, indent + 1
                    )

                elif self.has_class_in_struct(value.base_type, False):
                    code += self.get_track_struct(
                        param_name2, value, indent + 1
                    )

        code += self.INDENT * indent + '}\n'
        return code

    def write_include(self):
        code = (
            "\n"
            "#include \"generated/generated_dx12_command_list_util.h\"\n"
            "#include \"encode/dx12_object_wrapper_util.h\"\n"
            "\n"
        )
        write(code, file=self.outFile)
