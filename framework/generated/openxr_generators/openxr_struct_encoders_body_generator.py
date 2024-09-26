#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from reformat_code import format_cpp_code


class OpenXrStructEncodersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for OpenXR API struct encoding."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


class OpenXrStructEncodersBodyGenerator(BaseGenerator):
    """OpenXrStructEncodersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions for encoding OpenXR API structures.
    Generate C++ functions for OpenXr struct encoding.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            format_cpp_code(
                '''
            #include "generated/generated_openxr_struct_encoders.h"
            #include "generated/generated_vulkan_api_call_encoders.h"

            #include "encode/custom_dx12_struct_encoders.h"
            #include "encode/custom_openxr_struct_encoders.h"
            #include "encode/custom_vulkan_struct_encoders.h"
            #include "encode/parameter_encoder.h"
            #include "encode/openxr_handle_wrappers.h"
            #include "encode/struct_pointer_encoder.h"
            #include "util/defines.h"

        '''
            ),
            file=self.outFile
        )

        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

        self.newline()
        write(
            format_cpp_code(
                '''
            #ifndef D3D12_SUPPORT
            void EncodeStruct(ParameterEncoder* encoder, const LUID& value)
            {
                encoder->EncodeUInt32Value(value.LowPart);
                encoder->EncodeInt32Value(value.HighPart);
            }
            #endif /* D3D12_SUPPORT */
        '''
            ),
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        for struct in self.get_all_filtered_struct_names():
            self.generate_struct_bodies(
                struct, self.all_struct_members[struct]
            )

        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False

    def generate_struct_bodies(self, struct, struct_members):
        """Performs C++ code generation for the feature."""
        body = '\n'
        value_name = 'value'
        value_ref = value_name + '.'
        array_loop_specialization = None
        body += 'void EncodeStruct(ParameterEncoder* encoder, const {}& {})\n'.format(
            struct, value_name
        )
        body += '{\n'
        if struct in self.base_header_structs:
            body += self.make_child_struct_cast_switch(struct, value_name)
            array_loop_specialization = self.make_child_loop_cast_switch(
                struct
            )
        else:
            body += self.make_struct_body(struct, struct_members, value_ref)
        body += '}'
        if (array_loop_specialization):
            body += '\n\n' + array_loop_specialization
        write(body, file=self.outFile)

    def make_child_struct_cast_switch(self, base_struct, value):
        default_case = f'GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", {value}.type);'
        break_string = 'break;'
        switch_expression = 'value.type'
        fn_emit_default = lambda base_struct, value_name: [
            default_case, break_string
        ]
        fn_emit_case = lambda base_struct, child_struct, child_enum, value_name: [
            f'const {child_struct}& child_value = reinterpret_cast<const {child_struct}&>({value_name});',
            f'EncodeStruct(encoder, child_value);', break_string
        ]
        return self.make_child_struct_switch(
            base_struct, value, '    ', switch_expression, fn_emit_default,
            fn_emit_case
        )

    def make_child_loop_cast_switch(self, base_struct):
        func = 'EncodeStructArrayLoop'
        value = 'value'
        switch_expression = 'value->type'
        default_case = f'GFXRECON_LOG_WARNING("{func}: unrecognized Base Header child structure type %d", {value}->type);'
        break_string = 'break;'
        fn_emit_default = lambda base_struct, value_name: [
            default_case, break_string
        ]
        fn_emit_case = lambda base_struct, child_struct, child_enum, value_name: [
            f'{func}<{child_struct}>(encoder, reinterpret_cast<const {child_struct} *>({value_name}), len);',
            break_string
        ]
        body = ''
        body += 'template <>\n'
        body += f'void EncodeStructArrayLoop<{base_struct}>(ParameterEncoder* encoder, const {base_struct}* {value}, size_t len)\n'
        body += '{\n'
        body += self.make_child_struct_switch(
            base_struct, value, '    ', switch_expression, fn_emit_default,
            fn_emit_case
        )

        body += '}\n'
        return body

    def make_struct_body(self, name, values, prefix):
        """Command definition."""
        # Build array of lines for function body
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by typename
            if 'next' == value.name and value.base_type == 'void':
                body += '    EncodeNextStruct(encoder, {});\n'.format(
                    prefix + value.name
                )
            else:
                method_call = self.make_encoder_method_call(
                    name, value, values, prefix
                )
                body += '    {};\n'.format(method_call)

        return body
