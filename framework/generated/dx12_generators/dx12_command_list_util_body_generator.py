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
from dx12_base_generator import write
from dx12_command_list_util_header_generator import Dx12CommandListUtilHeaderGenerator


class Dx12CommandListUtilBodyGenerator(Dx12CommandListUtilHeaderGenerator):
    """Generate a C++ class for Dx12 Track CommandList objects.
    """
    INDENT = ' ' * 4

    def get_track_function_body(self, class_name, method_info):
        code = '\n'
        code += '{\n'
        code += self.INDENT + 'GFXRECON_ASSERT(wrapper != nullptr);\n'
        code += self.INDENT + 'auto info = wrapper->GetObjectInfo();\n'
        code += self.INDENT + 'GFXRECON_ASSERT(info != nullptr);\n'

        values = self.get_function_arguments(method_info)
        for value in values:
            code_list = self.get_track_code('', value, 1)
            for c in code_list:
                code += c
        code += '}\n'
        return code

    def get_track_code(self, param_name, value, indent):
        code_list = list()
        if param_name:
            param_name2 = param_name + value.name
        else:
            param_name2 = value.name

        param_name3 = param_name2
        if value.is_array:
            param_name3 = param_name2 + '[i]'

        if self.is_class(value):
            code_list.append(
                self.INDENT * indent
                + 'info->command_objects[D3D12GraphicsCommandObjectType::'
                + value.base_type + 'Object].insert(GetDx12WrappedId('
                + param_name3 + '));\n'
            )
        elif value.base_type == 'D3D12_CPU_DESCRIPTOR_HANDLE':
            if value.is_pointer and not value.is_array:
                param_name3 = param_name3 + '->ptr'
            else:
                param_name3 = param_name3 + '.ptr'
            code_list.append(
                self.INDENT * indent
                + 'info->command_cpu_descriptor_handles.insert(' + param_name3
                + ');\n'
            )
        elif value.base_type == 'D3D12_GPU_DESCRIPTOR_HANDLE':
            if value.is_pointer and not value.is_array:
                param_name3 = param_name3 + '->ptr'
            else:
                param_name3 = param_name3 + '.ptr'
            code_list.append(
                self.INDENT * indent
                + 'info->command_gpu_descriptor_handles.insert(' + param_name3
                + ');\n'
            )
        elif value.base_type == 'D3D12_GPU_VIRTUAL_ADDRESS':
            code_list.append(
                self.INDENT * indent
                + 'info->command_gpu_virtual_addresses.insert(' + param_name3
                + ');\n'
            )
        else:
            members = self.get_struct_members(value.base_type)
            if members:
                if value.is_pointer:
                    if value.is_array:
                        param_name3 = param_name3 + '.'
                    else:
                        param_name3 = param_name3 + '->'
                else:
                    param_name3 = param_name3 + '.'
                for v in members:
                    code_list.extend(
                        self.get_track_code(param_name3, v, indent)
                    )

        if len(code_list):
            if value.is_array:
                if param_name:
                    param_length = param_name + '->' + value.array_length
                else:
                    param_length = value.array_length
                self.add_loop_code(code_list, param_length, indent)
            if value.is_pointer:
                self.add_null_check_code(code_list, param_name2, indent)

        return code_list

    def add_null_check_code(self, code_list, param_name, indent):
        for idx, val in enumerate(code_list):
            code_list[idx] = self.INDENT + val

        code_list.insert(
            0, self.INDENT * indent + 'if(' + param_name + ' != nullptr)\n'
        )
        code_list.insert(1, self.INDENT * indent + '{\n')
        code_list.append(self.INDENT * indent + '}\n')

    def add_loop_code(self, code_list, param_length, indent):
        indent2 = indent
        index = 0

        for idx, val in enumerate(code_list):
            code_list[idx] = self.INDENT + val

        code_list.insert(
            index, self.INDENT * indent2 + 'for (UINT i = 0; i < '
            + param_length + '; ++i)\n'
        )
        index += 1
        code_list.insert(index, self.INDENT * indent2 + '{\n')
        code_list.append(self.INDENT * indent2 + '}\n')

    def write_include(self):
        code = (
            "\n"
            "#include \"generated/generated_dx12_command_list_util.h\"\n"
            "#include \"encode/dx12_object_wrapper_util.h\"\n"
            "#include \"util/logging.h\"\n"
            "\n"
        )
        write(code, file=self.outFile)
