#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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
from khronos_dispatch_table_generator import KhronosDispatchTableGenerator

class VulkanDispatchTableGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a dispatch table for Vulkan API calls."""

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
            'format/platform_types.h',
            'util/defines.h',
            'util/logging.h',
            '',
            'vulkan/vk_layer.h',
        ))

        self.begin_end_file_data.pre_namespace_code.extend((
            '#ifdef WIN32',
            '#ifdef CreateEvent',
            '#undef CreateEvent',
            '#endif',
            '#ifdef CreateSemaphore',
            '#undef CreateSemaphore',
            '#endif',
            '#endif',
            ''
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'graphics'))

class VulkanDispatchTableGenerator(VulkanBaseGenerator, KhronosDispatchTableGenerator):
    """VulkanDispatchTableGenerator - subclass of VulkanBaseGenerator.
    Generates a dispatch table for Vulkan API calls.
    Generate dispatch table for Vulkan API calls.
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
        # Map of return types to default return values for no-op functions
        self.RETURN_DEFAULTS = {
            'VkResult': 'VK_SUCCESS',
            'VkBool32': 'VK_TRUE',
            'PFN_vkVoidFunction': 'nullptr',
            'VkDeviceAddress': '0',
            'VkDeviceSize': '0',
            'uint32_t': '0',
            'uint64_t': '0'
        }

        self.instance_cmd_names = dict(
        )  # Map of API call names to no-op function declarations
        self.device_cmd_names = dict(
        )  # Map of API call names to no-op function declarations


    def is_instance_command(self, api_data, command, first_value):
        """ Method override """
        if ((command in ['vkSetDebugUtilsObjectNameEXT', 'vkSetDebugUtilsObjectTagEXT']) or
            (first_value.base_type in ['VkInstance', 'VkPhysicalDevice'])):
            return True
        return False

    def is_device_command(self, api_data, command, first_value):
        """ Method may be overridden. """
        return not self.is_instance_command(api_data, command,first_value)

    def write_layer_table_manual_entries(self):
        """ Method must overridden. """
        write(
            '    PFN_vkCreateInstance CreateInstance{ nullptr };',
            file=self.outFile
        )
        write(
            '    PFN_vkCreateDevice CreateDevice{ nullptr };',
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        KhronosDispatchTableGenerator.generateDispatchTable(self)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False
