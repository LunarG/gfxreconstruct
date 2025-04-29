#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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
from reformat_code import format_cpp_code
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_struct_encoders_body_generator import KhronosStructEncodersBodyGenerator


class OpenXrStructEncodersBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating C++ functions for OpenXr struct encoding."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )

        self.begin_end_file_data.specific_headers.extend((
            'generated/generated_openxr_struct_encoders.h',
            'generated/generated_vulkan_api_call_encoders.h',
            '',
            'encode/custom_openxr_struct_encoders.h',
            'encode/custom_vulkan_struct_encoders.h',
            'encode/parameter_encoder.h',
            'encode/openxr_handle_wrappers.h',
            'encode/struct_pointer_encoder.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))

class OpenXrStructEncodersBodyGenerator(OpenXrBaseGenerator, KhronosStructEncodersBodyGenerator):
    """OpenXrStructEncodersBodyGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ functions for encoding OpenXr API structures.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def skip_struct_type(self, struct_type):
        """Override as needed"""
        return struct_type == "XrEventDataBuffer"

    def beginFile(self, gen_opts):
        """Method override."""
        OpenXrBaseGenerator.beginFile(self, gen_opts)
        self.newline()
        write(
            format_cpp_code('''
            #ifndef D3D12_SUPPORT
            void EncodeStruct(ParameterEncoder* encoder, const LUID& value)
            {
                encoder->EncodeUInt32Value(value.LowPart);
                encoder->EncodeInt32Value(value.HighPart);
            }
            #endif /* D3D12_SUPPORT */
            '''),
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        KhronosStructEncodersBodyGenerator.write_encoder_content(self)
        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
