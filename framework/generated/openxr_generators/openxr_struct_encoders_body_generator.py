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
        self.all_feature_struct_members = []

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
        for feature_struct_members in self.all_feature_struct_members:
            self.generate_struct_bodies(feature_struct_members)

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

    def generate_feature(self):
        """Gather up struct names for processing deferred to endFile"""
        self.all_feature_struct_members.append(self.feature_struct_members)

    def generate_struct_bodies(self, feature_struct_members):
        """Performs C++ code generation for the feature."""

        for struct in [ key for key in feature_struct_members if not self.is_struct_black_listed(key)]:
            body = '\n'
            value_name = 'value'
            value_ref  = value_name + '.'
            body += 'void EncodeStruct(ParameterEncoder* encoder, const {}& {})\n'.format(
                struct, value_name
            )
            body += '{\n'
            if struct in self.base_header_structs:
                body += self.make_child_struct_cast_switch(struct, value_name)
            else:
                body += self.make_struct_body(
                    struct, feature_struct_members[struct], value_ref
            )
            body += '}'
            write(body, file=self.outFile)

    def make_child_struct_cast_switch(self, base_struct, value):
        """ Base structs are abstract, need to case to specific child struct based on type """
        indent = '    '
        indent2 = indent + indent
        indent3 = indent2 + indent
        body = ''
        body += f'{indent}// Cast and call the appropriate encoder based on the structure type\n'
        body += f'{indent}switch({value}.type)\n'

         
        body += f'{indent}{{\n'
        body += f'{indent2}default:\n'
        body += f'{indent2}{{\n'
        body += f'{indent3}GFXRECON_LOG_WARNING("EncodeStruct: unrecognized Base Header child structure type %d", {value}.type);\n'
        body += f'{indent3}break;\n'
        body += f'{indent2}}}\n'

        for child_struct in self.base_header_structs[base_struct]:
            struct_type_name = self.struct_type_enums[child_struct]
            body += f'{indent2}case {struct_type_name}:\n'
            body += f'{indent2}{{\n'
            body += f'{indent3}const {child_struct}& child_value = reinterpret_cast<const {child_struct}&>({value});\n'
            body += f'{indent3}EncodeStruct(encoder, child_value);\n'
            body += f'{indent3}break;\n'
            body += f'{indent2}}}\n'
 
        body += f'{indent}}}\n'
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
