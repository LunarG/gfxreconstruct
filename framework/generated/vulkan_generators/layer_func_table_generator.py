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
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class LayerFuncTableGeneratorOptions(BaseGeneratorOptions):
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
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class LayerFuncTableGenerator(BaseGenerator):
    """LayerFuncTableGenerator - subclass of BaseGenerator.
    Generates C++ function table for the Vulkan API calls exported by the layer.
    Generate Vulkan layer function table C++ type declarations.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=False,
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

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "encode/custom_vulkan_api_call_encoders.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_api_call_encoders.h"',
            file=self.outFile
        )
        write('#include "layer/trace_layer.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('#include <unordered_map>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write(
            'const std::unordered_map<std::string, PFN_vkVoidFunction> vulkan_func_table = {',
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        # Manually output the physical device proc address function as its name doesn't
        # match the scheme used by self.LAYER_FUNCTIONS:
        align = 100 - len('vk_layerGetPhysicalDeviceProcAddr')
        write('    { "vk_layerGetPhysicalDeviceProcAddr",%sreinterpret_cast<PFN_vkVoidFunction>(VulkanGetPhysicalDeviceProcAddr) },' % (' ' * align), file=self.outFile)

        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for cmd in self.get_filtered_cmd_names():
            align = 100 - len(cmd)
            if (cmd in self.LAYER_FUNCTIONS):
                body = '    {{ "{}",{}reinterpret_cast<PFN_vkVoidFunction>(Vulkan{}) }},'.format(
                    cmd, (' ' * align), cmd[2:]
                )
            else:
                body = '    {{ "{}",{}reinterpret_cast<PFN_vkVoidFunction>(encode::{}) }},'.format(
                    cmd, (' ' * align), cmd[2:]
                )
            write(body, file=self.outFile)
