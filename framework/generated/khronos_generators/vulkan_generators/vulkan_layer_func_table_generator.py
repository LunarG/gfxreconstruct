#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2024 LunarG, Inc.
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
from khronos_layer_func_table_generator import KhronosLayerFuncTableGenerator


class VulkanLayerFuncTableGeneratorOptions(VulkanBaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    function table generation.
    Options for Vulkan layer function table C++ code generation.
    """

    def __init__(
        self,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )
        self.begin_end_file_data.specific_headers.extend((
            'encode/custom_vulkan_api_call_encoders.h',
            'generated/generated_vulkan_api_call_encoders.h',
            'layer/trace_layer.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.system_headers.append('unordered_map')
        self.begin_end_file_data.namespaces.append('gfxrecon')

class VulkanLayerFuncTableGenerator(VulkanBaseGenerator, KhronosLayerFuncTableGenerator):
    """LayerFuncTableGenerator - subclass of VulkanBaseGenerator.
    Generates C++ function table for the Vulkan API calls exported by the layer.
    Generate Vulkan layer function table C++ type declarations.
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

        # The trace layer does not currently implement or export the instance version query
        self.APICALL_BLACKLIST = ['vkEnumerateInstanceVersion']

        # These functions are provided directly by the layer, and are not encoded
        self.LAYER_FUNCTIONS = [
            'vkGetInstanceProcAddr', 'vkGetDeviceProcAddr',
            'vkEnumerateInstanceLayerProperties',
            'vkEnumerateDeviceLayerProperties',
            'vkEnumerateInstanceExtensionProperties',
            'vkEnumerateDeviceExtensionProperties'
        ]

    def endFile(self):
        """Method override."""

        KhronosLayerFuncTableGenerator.write_layer_func_table_contents(self, self.LAYER_FUNCTIONS, 100)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def write_custom_layer_func_table_contents(self, api_data, align_col):
        """ Method override """
        # Manually output the physical device proc address function as its name doesn't
        # match the scheme used by skip_func_list:
        align = align_col - len('vk_layerGetPhysicalDeviceProcAddr')
        write('    { "vk_layerGetPhysicalDeviceProcAddr",%sreinterpret_cast<PFN_vkVoidFunction>(vulkan_entry::GetPhysicalDeviceProcAddr) },' % (' ' * align), file=self.outFile)


    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False
