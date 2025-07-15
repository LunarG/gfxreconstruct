#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2025 LunarG, Inc.
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


class KhronosStructEncodersBodyGenerator():
    """KhronosStructEncodersBodyGenerator.
    Generates C++ functions for encoding Khronos API structures.
    """
    def skip_struct_type(self, struct_type):
        """Override as needed"""
        return False

    def write_encoder_content(self):
        api_data = self.get_api_data()
        for struct in self.get_all_filtered_struct_names():
            if self.skip_struct_type(struct):
                continue
            self.generate_struct_bodies(api_data, struct, self.all_struct_members[struct])

    def generate_struct_bodies(self, api_data, struct, struct_members):
        """Performs C++ code generation for the feature."""
        body = '\n'
        value_name = 'value'
        value_ref = value_name + '.'
        array_loop_specialization = None
        struct_type_var = self.get_struct_type_var_name()
        body += 'void EncodeStruct(ParameterEncoder* encoder, const {}& {})\n'.format(
            struct, value_name
        )
        body += '{\n'
        if struct in self.children_structs:
            body += self.make_child_struct_cast_switch(
                struct, value_name, struct_type_var
            )
            array_loop_specialization = self.make_child_loop_cast_switch(
                struct, struct_type_var
            )
        else:
            body += self.makeStructBody(api_data, struct, struct_members, value_ref)
        body += '}'
        if (array_loop_specialization):
            body += '\n\n' + array_loop_specialization
        write(body, file=self.outFile)

    def make_child_struct_cast_switch(self, parent_struct, value, struct_type_var):
        default_case = 'GFXRECON_LOG_WARNING("EncodeStruct({}): unrecognized child structure type %d", {}.{});'.format(
            parent_struct, value, struct_type_var
        )
        break_string = 'break;'
        switch_expression = 'value.{}'.format(struct_type_var)
        fn_emit_default = lambda parent_struct, value_name: [
            default_case, break_string
        ]
        fn_emit_case = lambda parent_struct, child_struct, child_enum, value_name: [
            f'const {child_struct}& child_value = reinterpret_cast<const {child_struct}&>({value_name});',
            f'EncodeStruct(encoder, child_value);', break_string
        ]
        return self.generate_child_struct_switch_statement(
            parent_struct, value, '    ', switch_expression, fn_emit_default,
            fn_emit_case
        )

    def make_child_loop_cast_switch(self, parent_struct, struct_type_var):
        func = 'EncodeStructArrayLoop'
        value = 'value'
        switch_expression = 'value->{}'.format(struct_type_var)
        default_case = 'GFXRECON_LOG_WARNING("{}: unrecognized child structure type %d", {}->{});'.format(
            func, value, struct_type_var
        )
        break_string = 'break;'
        fn_emit_default = lambda parent_struct, value_name: [
            default_case, break_string
        ]
        fn_emit_case = lambda parent_struct, child_struct, child_enum, value_name: [
            f'{func}<{child_struct}>(encoder, reinterpret_cast<const {child_struct} *>({value_name}), len);',
            break_string
        ]
        body = ''
        body += 'template <>\n'
        body += f'void EncodeStructArrayLoop<{parent_struct}>(ParameterEncoder* encoder, const {parent_struct}* {value}, size_t len)\n'
        body += '{\n'
        body += self.generate_child_struct_switch_statement(
            parent_struct, value, '    ', switch_expression, fn_emit_default,
            fn_emit_case
        )

        body += '}\n'
        return body

    def makeStructBody(self, api_data, name, values, prefix):
        """Command definition."""
        # Build array of lines for function body
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by typename
            if self.is_extended_struct_definition(value):
                body += '    Encode{}Struct(encoder, {});\n'.format(
                    api_data.extended_struct_func_prefix, prefix + value.name
                )
            else:
                method_call = self.make_encoder_method_call(
                    name, value, values, prefix
                )
                body += '    {};\n'.format(method_call)

        return body
