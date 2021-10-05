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

import os, re, sys
from base_generator import *


#
# Eliminates JSON blackLists and platformTypes files, which are not necessary for
# function table generation.
class LayerFuncTableGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan layer function table C++ code generation"""

    def __init__(
        self,
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraVulkanHeaders=extraVulkanHeaders
        )


# LayerFuncTableGenerator - subclass of BaseGenerator.
# Generates C++ function table for the Vulkan API calls exported by the layer.
class LayerFuncTableGenerator(BaseGenerator):
    """Generate Vulkan layer function table C++ type declarations"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=True,
            processStructs=False,
            featureBreak=False,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
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

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        write('#include "encode/custom_vulkan_api_call_encoders.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_api_call_encoders.h"', file=self.outFile)
        write('#include "layer/trace_layer.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(genOpts)
        self.newline()
        write('#include <unordered_map>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write('const std::unordered_map<std::string, PFN_vkVoidFunction> func_table = {', file=self.outFile)
    # yapf: enable

    # Method override
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        for cmd in self.getFilteredCmdNames():
            align = 100 - len(cmd)
            if (cmd in self.LAYER_FUNCTIONS):
                body = '    {{ "{}",{}reinterpret_cast<PFN_vkVoidFunction>({}) }},'.format(cmd, (' ' * align), cmd[2:])
            else:
                body = '    {{ "{}",{}reinterpret_cast<PFN_vkVoidFunction>(encode::{}) }},'.format(cmd, (' ' * align), cmd[2:])
            write(body, file=self.outFile)
    # yapf: enable
