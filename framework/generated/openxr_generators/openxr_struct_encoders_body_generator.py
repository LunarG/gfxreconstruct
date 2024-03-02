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
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_openxr_struct_encoders.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "encode/custom_openxr_struct_encoders.h"',
            file=self.outFile
        )
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    def endFile(self):
        """Method override."""
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
        """Performs C++ code generation for the feature."""
        first = True
        for struct in self.get_filtered_struct_names():
            body = '' if first else '\n'
            body += 'void EncodeStruct(ParameterEncoder* encoder, const {}& value)\n'.format(
                struct
            )
            body += '{\n'
            body += self.make_struct_body(
                struct, self.feature_struct_members[struct], 'value.'
            )
            body += '}'
            write(body, file=self.outFile)

            first = False

    def make_struct_body(self, name, values, prefix):
        """Command definition."""
        # Build array of lines for function body
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by typename
            if 'pNext' in value.name:
                body += '    EncodePNextStruct(encoder, {});\n'.format(
                    prefix + value.name
                )
            else:
                method_call = self.make_encoder_method_call(
                    name, value, values, prefix
                )
                body += '    {};\n'.format(method_call)

        return body
