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

    def write_layer_func_table_contents(self, skip_func_list, align_col, name_identifier='', skip_var_definition=False):
        api_data = self.get_api_data()

        table_name = '{}'.format(api_data.api_name.lower())
        get_table_name = 'Get{}'.format(api_data.api_name)
        skip_func_namespace = '{}'.format(api_data.api_name.lower())
        if(name_identifier):
            table_name += '_{}'.format(name_identifier.lower())
            skip_func_namespace += '_{}'.format(name_identifier.lower())
            get_table_name += '{}'.format(name_identifier)
        table_name += '_func_table'
        get_table_name += 'FuncTable'

        # Write the static function to get the table.
        write('// This static function can be used to avoid issues with static variable initialization order.',
            file=self.outFile)
        write(
            'static inline const std::unordered_map<std::string, {}> {}() {{'.format(
                api_data.void_func_pointer_type, get_table_name),
            file=self.outFile)

        write('    return {', file=self.outFile)

        for cmd in self.get_all_filtered_cmd_names():
            align = align_col - len(cmd)
            if (cmd in skip_func_list):
                body = '        {{ "{}",{}reinterpret_cast<{}>({}::{}) }},'.format(
                    cmd, (' ' * align), api_data.void_func_pointer_type,
                    skip_func_namespace, cmd[2:]
                )
            else:
                body = '        {{ "{}",{}reinterpret_cast<{}>(encode::{}) }},'.format(
                    cmd, (' ' * align), api_data.void_func_pointer_type,
                    cmd
                )
            write(body, file=self.outFile)

        self.write_custom_layer_func_table_contents(api_data, align_col)

        write('    };', file=self.outFile)
        write('}', file=self.outFile)

        if not skip_var_definition:
            # Create the global static var using the above function.
            self.newline()
            write('static const auto {} = {}();'.format(
                table_name, get_table_name),
                  file=self.outFile)

    def write_custom_layer_func_table_contents(self, api_data, align_col):
        """ May be overridden """
        return
