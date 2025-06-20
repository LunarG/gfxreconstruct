#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2025 LunarG, Inc.
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
import inspect
from openxr_base_generator import *
from khronos_enum_to_string_body_generator import KhronosEnumToStringBodyGenerator


class OpenXrEnumToStringBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating C++ functions for OpenXr ToString() functions"""

    def __init__(
        self,
        # Path to JSON file listing apicalls and structs to ignore.
        blacklists=None,
        # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        platform_types=None,
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

        self.begin_end_file_data.specific_headers.append('generated_openxr_enum_to_string.h')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'util'))
        self.begin_end_file_data.common_api_headers = []

# OpenXrEnumToStringBodyGenerator - subclass of OpenXrBaseGenerator.
# Generates C++ functions for stringifying OpenXr API enums.
class OpenXrEnumToStringBodyGenerator(OpenXrBaseGenerator, KhronosEnumToStringBodyGenerator):
    """Generate C++ functions for OpenXr ToString() functions"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    def endFile(self):
        KhronosEnumToStringBodyGenerator.write_enum_to_string_body(self, use_flags_for_64bit_enum=True)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

    def skip_generating_enum_to_string_for_type(self, enum_name):
        """ Override for OpenXr to suppress Vulkan types """
        return enum_name.startswith('Vk') or ('Bits' in enum_name and not self.is_flags_enum_64bit(enum_name))