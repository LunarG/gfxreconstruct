#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019-2025 LunarG, Inc.
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

import json
from khronos_base_generator import ValueInfo

class KhronosApiCallEncodersGenerator():
    """KhronosApiCallEncodersGenerator
    Common functions for Api Call Encoding generation
    """
    def __init__(self, check_write=None):
        if check_write:
            self.CHECK_WRITE = check_write
        else:
            self.CHECK_WRITE = []

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def make_encoder_cmd_decl(self, proto, values, is_header):
        """Generate function declaration for a command."""
        param_decls = []

        for value in values:
            value_name = value.name
            value_type = value.full_type if not value.platform_full_type else value.platform_full_type

            if value.is_array and not value.is_dynamic:
                value_name += '[{}]'.format(value.array_capacity)

            param_decl = self.make_aligned_param_decl(
                value_type, value_name, self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        eol = ';' if is_header else ''
        if param_decls:
            return '{}(\n{}){}'.format(proto, ',\n'.join(param_decls), eol)

        return '{}(){}'.format(proto, eol)

    def make_parameter_encoding(
        self, name, values, return_type, indent, omit_output_param
    ):
        body = '\n'
        body += indent + self.make_begin_api_call(name, values)
        body += indent + 'if (encoder'

        if self.CHECK_WRITE:
            if name in self.CHECK_WRITE: 
                body += ' && manager->CheckWrite' + name[2:] + '(result'
                for value in values:
                    body += ', ' + value.name
                body += ')'            

        body += ')\n'
        body += indent + '{\n'
        indent += ' ' * self.INDENT_SIZE

        for value in values:
            method_call = self.make_encoder_method_call(
                name, value, values, '', omit_output_param
            )
            body += indent + '{};\n'.format(method_call)

        if return_type and return_type != 'void':
            method_call = self.make_encoder_method_call(
                name, ValueInfo('result', return_type, return_type), [], ''
            )
            body += indent + '{};\n'.format(method_call)

        # Determine the appropriate end call: Create handle call, destroy handle call, or general call.
        body += indent + self.make_end_api_call(name, values, return_type)
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'
        return body

    def get_struct_handle_member_info(self, members):
        member_handle_type = None
        member_handle_name = None
        member_array_length = None

        for member in members:
            if self.is_handle(member.base_type):
                member_handle_type = member.base_type
                member_handle_name = member.name
                if member.is_array:
                    member_array_length = member.array_length
                break
            elif self.is_struct(member.base_type):
                # This can't handle the case where 'member' is an array of structs
                member_handle_type, member_handle_name, member_array_length = self.get_struct_handle_member_info(
                    self.structs_with_handles[member.base_type]
                )
                member_handle_name = '{}.{}'.format(
                    member.name, member_handle_name
                )

        return member_handle_type, member_handle_name, member_array_length

    def make_get_command_handles_expr(self, cmd, values):
        """Generate an expression for a get command buffer handles utility function."""
        handle_params = self.get_param_list_handles(values)
        if handle_params:
            args = []
            for value in handle_params:
                if value.array_length:
                    args.append(value.array_length)
                args.append(value.name)
            return 'Track{}Handles, {}'.format(
                cmd[2:], ', '.join(self.make_unique_list(args))
            )
        else:
            return None

    def has_outputs(self, return_value, parameter_values):
        for value in parameter_values:
            if self.is_output_parameter(value):
                return True
        return False

    def load_capture_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.CAPTURE_OVERRIDES = overrides['functions']

    def write_api_call_encoders_contents(self, make_cmd_body=None):
        body = []
        is_header = not bool(make_cmd_body)

        for cmd in self.get_all_filtered_cmd_names():
            info = self.all_cmd_params[cmd]
            return_type = info[0]
            proto = info[1]
            values = info[2]

            body.append('')
            body.append(self.make_encoder_cmd_decl(proto, values, is_header=is_header))
            if make_cmd_body:
                body.extend(('{', make_cmd_body(return_type, cmd, values), '}'))

        body.append('')
        self.write_lines(body)
