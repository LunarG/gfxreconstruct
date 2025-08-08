#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2024 LunarG, Inc.
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
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class KhronosExportJsonConsumerBodyGenerator():
    """KhronosExportJsonConsumerBodyGenerator
    Generates C++ member definitions for the KhronosExportJsonConsumer class responsible for
    generating a textfile containing decoded Khronos API call parameter data.
    """

    def generate_json_content(self):
        """Method may be overridden"""
        api_data = self.get_api_data()
        export_prefix = '{}ExportJsonConsumer::Process_'.format(
            api_data.api_class_prefix
        )

        write(
            remove_trailing_newlines(
                indent_cpp_code(
                    '''
            using util::JsonOptions;
        '''
                )
            ),
            file=self.outFile
        )

        for cmd in self.get_all_filtered_cmd_names():
            if self.skip_generating_command_json(cmd):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '\n'
            cmddef += self.make_consumer_func_decl(
                return_type, export_prefix + cmd, values
            ) + '\n'
            cmddef += format_cpp_code(
                '''
                {{
                    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "{0}");
                    const JsonOptions& json_options = GetJsonOptions();
                '''.format(cmd)
            )
            cmddef += '\n'
            cmddef += self.make_consumer_func_body(return_type, cmd, values)
            cmddef += format_cpp_code(
                '''
                    WriteBlockEnd();
                }
            ''', 1
            )
            write(cmddef, file=self.outFile)

    def skip_generating_command_json(self, command):
        """Method may be overriden"""
        return False

    def decode_as_handle(self, command, value):
        """Method may be overridden.
        Indicates that the given type should be decoded as a handle."""
        return self.is_handle_like(value.base_type)

    def decode_as_hex(self, value):
        """Method may be overriden"""
        return False


    def has_special_case_json_export(self, name):
        """Method may be overridden."""
        return False

    def get_special_case_json_export(self, name):
        """Method may be overridden."""
        return

    def make_consumer_func_body(self, return_type, name, values):
        """Return ExportJsonConsumer class member function definition."""
        body = ''

        # Handle function return value
        if return_type in self.formatAsHex:
            body += '    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);\n'
        elif self.is_boolean_type(return_type):
            # Output as JSON boolean type true/false without quotes:
            body += '            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);\n'
        elif self.is_handle_like(return_type):
            body += '    HandleToJson(jdata[NameReturn()], returnValue, json_options);\n'
        # Enums, ints, etc. handled by default and static dispatch based on C++ type:
        elif not 'void' in return_type:
            body += '    FieldToJson(jdata[NameReturn()], returnValue, json_options);\n'

        if len(values) > 0:
            body += '    auto& args = jdata[NameArgs()];\n'
            # Handle function arguments
            for value in values:
                flagsEnumType = value.base_type

                # Default to letting the right function overload to be resolved based on argument types,
                # including enums, strings ints, floats etc.:
                # Note there are overloads for scalars and pointers/arrays.
                to_json = 'FieldToJson(args["{0}"], {0}, json_options)'

                # Special cases:
                if self.has_special_case_json_export(value.base_type):
                    to_json = self.get_special_case_json_export(value.base_type)
                elif not (value.is_pointer or value.is_array) and self.is_struct(value.base_type):
                    to_json = 'FieldToJson(args["{0}"], &{0}, json_options)'
                elif value.is_array and value.base_type in self.children_structs:
                    to_json = 'ParentChildFieldToJson(args["{0}"], {0}, json_options)'
                elif self.is_boolean_type(value.base_type):
                    to_json = 'Bool32ToJson(args["{0}"], {0}, json_options)'
                elif value.name == 'ppData' or self.decode_as_hex(value):
                    to_json = 'FieldToJsonAsHex(args["{0}"], {0}, json_options)'
                elif self.decode_as_handle(name, value):
                    to_json = 'HandleToJson(args["{0}"], {0}, json_options)'
                elif self.is_flags(value.base_type):
                    if value.base_type in self.flags_type_aliases:
                        flagsEnumType = self.flags_type_aliases[value.base_type
                                                                ]
                    if not (value.is_pointer or value.is_array):
                        to_json = 'FieldToJson({2}_t(), args["{0}"], {0}, json_options)'
                    else:
                        # Default to outputting as the raw type but warn:
                        print(
                            "Missing conversion of pointers to",
                            flagsEnumType,
                            "in",
                            name,
                            file=sys.stderr
                        )

                to_json = to_json.format(
                    value.name, value.base_type, flagsEnumType
                )
                body += '        {0};\n'.format(to_json)
        return body
