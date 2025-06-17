#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator


class VulkanStructDecodersHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ type declarations for Vulkan struct decoding."""

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
        VulkanBaseGeneratorOptions.__init__(
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
            'decode/custom_common_struct_decoders_forward.h',
            'decode/custom_vulkan_struct_decoders_forward.h',
            'decode/handle_pointer_decoder.h',
            'decode/pointer_decoder.h',
            'decode/string_array_decoder.h',
            'decode/string_decoder.h',
            'decode/struct_pointer_decoder.h',
            'decode/vulkan_pnext_node.h',
            'format/format.h',
            'format/platform_types.h',
            'generated/generated_vulkan_struct_decoders_forward.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.system_headers.append('memory')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))

class VulkanStructDecodersHeaderGenerator(
    KhronosStructDecodersHeaderGenerator, VulkanBaseGenerator
):
    """VulkanStructDecodersHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ type declarations for the decoded Vulkan API structure wrappers.
    Generate C++ type declarations for Vulkan struct decoding.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def endFile(self):
        """Method override."""
        KhronosStructDecodersHeaderGenerator.endFile(self)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members or self.feature_struct_aliases:
            return True
        return False
