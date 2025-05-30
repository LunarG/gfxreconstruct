#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2023 LunarG, Inc.
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
from openxr_base_generator import *
from khronos_enum_to_json_header_generator import KhronosEnumToJsonHeaderGenerator
from reformat_code import format_cpp_code

class OpenXrEnumToJsonHeaderGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating C++ functions for OpenXr ToString() functions"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extra_headers=[]
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extra_headers=extra_headers
        )
        
        self.begin_end_file_data.specific_headers.extend((
            'format/platform_types.h',
            'util/json_util.h',
        ))
        self.begin_end_file_data.system_headers.append('nlohmann/json.hpp')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))



# OpenXrEnumToStringHeaderGenerator - subclass of OpenXrBaseGenerator.
# Generates C++ functions for stringifying OpenXr API enums.
class OpenXrEnumToJsonHeaderGenerator(OpenXrBaseGenerator, KhronosEnumToJsonHeaderGenerator):
    """Generate C++ functions to serialize OpenXr enumaration to JSON"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def skip_generating_enum_to_json_for_type(self, type):
        return type.startswith('Vk') or 'Bits' in type

    # Method override
    def endFile(self):
        self.newline()
        KhronosEnumToJsonHeaderGenerator.make_decls(self)
        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
