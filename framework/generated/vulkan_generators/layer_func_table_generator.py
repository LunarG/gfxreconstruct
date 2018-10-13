#!/usr/bin/python3 -i
#
# Copyright (c) 2018 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os,re,sys
from base_generator import *

#
# Eliminates JSON blackLists and platformTypes files, which are not necessary for
# function table generation.
class LayerFuncTableGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan layer function table C++ code generation"""
    def __init__(self,
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self, None, None,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)

# LayerFuncTableGenerator - subclass of BaseGenerator.
# Generates C++ function table for the Vulkan API calls exported by the layer.
class LayerFuncTableGenerator(BaseGenerator):
    """Generate Vulkan layer function table C++ type declarations"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=False,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # The trace layer does not currently implement or export the instance version query
        self.APICALL_BLACKLIST = ['vkEnumerateInstanceVersion']

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include <unordered_map>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_api_call_encoders.h"', file=self.outFile)
        write('#include "layer/custom_vulkan_api_call_encoders.h"', file=self.outFile)
        write('#include "layer/trace_layer.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        self.newline()
        write('const std::unordered_map<std::string, PFN_vkVoidFunction> func_table = {', file=self.outFile)

    # Method override
    def endFile(self):
        # Add the special-case internal loader/layer command 'vk_layerGetPhysicalDeviceProcAddr'
        self.newline()
        write('    // Special case handling of "vk_layerGetPhysicalDeviceProcAddr"', file=self.outFile)
        align = 100 - len('vk_layerGetPhysicalDeviceProcAddr')
        write('    { "vk_layerGetPhysicalDeviceProcAddr",%sreinterpret_cast<PFN_vkVoidFunction>(GetPhysicalDeviceProcAddr) },' % (' ' * align), file=self.outFile)
        write('};', file=self.outFile)
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

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
    def generateFeature(self):
        for cmd in self.featureCmdParams:
            align = 100 - len(cmd)
            body = '    {{ "{}",{}reinterpret_cast<PFN_vkVoidFunction>({}) }},'.format(cmd, (' ' * align), cmd[2:])
            write(body, file=self.outFile)

