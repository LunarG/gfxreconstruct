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
from vulkan_base_generator import *
from khronos_enum_to_json_header_generator import KhronosEnumToJsonHeaderGenerator
from reformat_code import format_cpp_code

class VulkanEnumToJsonHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
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
        VulkanBaseGeneratorOptions.__init__(
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

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))



# VulkanEnumToStringHeaderGenerator - subclass of VulkanBaseGenerator.
# Generates C++ functions for stringifying Vulkan API enums.
class VulkanEnumToJsonHeaderGenerator(VulkanBaseGenerator, KhronosEnumToJsonHeaderGenerator):
    """Generate C++ functions to serialize Vulkan enumaration to JSON"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    def endFile(self):
        self.newline()
        KhronosEnumToJsonHeaderGenerator.make_decls(self)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_struct_members:
            return True
        return False
