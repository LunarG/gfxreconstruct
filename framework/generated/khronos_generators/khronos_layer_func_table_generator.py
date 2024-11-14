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


class KhronosLayerFuncTableGenerator():
    """KhronosLayerFuncTableGenerator
    Generates C++ function table for Khronos Vulkan API calls exported by the layer.
    """

    def write_layer_func_table_contents(self, skip_func_list, align_col):
        api_data = self.get_api_data()

        write(
            'const std::unordered_map<std::string, {}> {}_func_table = {{'.
            format(api_data.void_func_pointer_type, api_data.api_name.lower()),
            file=self.outFile
        )

        for cmd in self.get_all_filtered_cmd_names():
            align = align_col - len(cmd)
            if (cmd in skip_func_list):
                body = '    {{ "{}",{}reinterpret_cast<{}>({}_entry::{}) }},'.format(
                    cmd, (' ' * align), api_data.void_func_pointer_type,
                    api_data.api_name.lower(), cmd[2:]
                )
            else:
                body = '    {{ "{}",{}reinterpret_cast<{}>(encode::{}) }},'.format(
                    cmd, (' ' * align), api_data.void_func_pointer_type,
                    cmd
                )
            write(body, file=self.outFile)

        self.write_custom_layer_func_table_contents(api_data, align_col)

        write('};', file=self.outFile)

    def write_custom_layer_func_table_contents(self, api_data, align_col):
        """ May be overridden """
        return
