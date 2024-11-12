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
from base_generator import *
from khronos_enum_to_json_header_generator import KhronosEnumToJsonHeaderGenerator
from reformat_code import format_cpp_code

class VulkanEnumToJsonHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan ToString() functions"""

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
        BaseGeneratorOptions.__init__(
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


# VulkanEnumToStringHeaderGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API enums.
class VulkanEnumToJsonHeaderGenerator(BaseGenerator, KhronosEnumToJsonHeaderGenerator):
    """Generate C++ functions to serialize Vulkan enumaration to JSON"""

    SKIP_ENUM = [
    ]

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        includes = format_cpp_code('''
            #include "format/platform_types.h"
            #include "util/json_util.h"

            '''
        )

        write(includes, file=self.outFile)
        self.write_includes_of_common_api_headers(genOpts)
        write("", file=self.outFile)
        namespace = format_cpp_code('''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            ''')
        write(namespace, file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.newline()
        KhronosEnumToJsonHeaderGenerator.make_decls(self)

        self.newline()
        body = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        ''')
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_struct_members:
            return True
        return False
