#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2020 LunarG, Inc.
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
from khronos_struct_handle_mappers_body_generator import KhronosStructHandleMappersBodyGenerator


class VulkanStructHandleMappersBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating functions to map Vulkan struct member handles at file replay."""

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
            'generated/generated_vulkan_struct_handle_mappers.h',
            '',
            'decode/custom_vulkan_struct_decoders.h',
            'decode/handle_pointer_decoder.h',
            'decode/vulkan_handle_mapping_util.h',
            'generated/generated_vulkan_struct_decoders.h',
        ))
        self.begin_end_file_data.system_headers.extend((
            'algorithm',
            'cassert',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.begin_end_file_data.common_api_headers = []

class VulkanStructHandleMappersBodyGenerator(
    KhronosStructHandleMappersBodyGenerator, VulkanBaseGenerator
):
    """VulkanStructHandleMappersBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions responsible for mapping struct member handles
    when replaying decoded Vulkan API call parameter data.
    Generate C++ functions for Vulkan struct member handle mapping at file replay.
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
        KhronosStructHandleMappersBodyGenerator.write_struct_handle_wrapper_content(self)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False
