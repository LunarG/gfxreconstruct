#!/usr/bin/python3 -i
#
# Copyright (c) 2020 LunarG, Inc.
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

class VulkanReferencedResourceHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating the header to a C++ class for detecting unreferenced resource handles in a capture file"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self, blacklists, platformTypes,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)

# VulkanReferencedResourceHeaderGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReferencedResource class responsible for
# determining which resource handles are used or unused in a capture file.
class VulkanReferencedResourceHeaderGenerator(BaseGenerator):
    """Generate the header to a C++ class for detecting unreferenced resource handles in a capture file"""
    # All resource and resource associated handle types to be processed.
    RESOURCE_HANDLE_TYPES = ['VkBuffer', 'VkImage', 'VkBufferView', 'VkImageView', 'VkFramebuffer', 'VkDescriptorSet', 'VkCommandBuffer']

    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=True, featureBreak=False,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)
        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structsWithHandles = dict()
        self.commandInfo = dict()     # Map of Vulkan commands to parameter info
        self.restrictHandles = True   # Determines if the 'isHandle' override limits the handle test to only the values conained by RESOURCE_HANDLE_TYPES.

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        className = 'VulkanReferencedResourceConsumer'

        write('#include "decode/vulkan_referenced_resource_consumer_base.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write('class {name} : public {name}Base'.format(name=className), file=self.outFile)
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write('    {}() {{ }}\n'.format(className), file=self.outFile)
        write('    virtual ~{}() override {{ }}'.format(className), file=self.outFile)

    # Method override
    def endFile(self):
        for cmd, info in self.commandInfo.items():
            returnType = info[0]
            params = info[2]
            if params and params[0].baseType == 'VkCommandBuffer':
                # Check for parameters with resource handle types.
                handles = self.getParamListHandles(params[1:])

                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'

                    # Temporarily remove resource only matching restriction from isHandle() when generating the function signature.
                    self.restrictHandles = False
                    cmddef += self.makeConsumerFuncDecl(returnType, 'Process_' + cmd, params) + ';\n'
                    self.restrictHandles = True

                    write(cmddef, file=self.outFile)

        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.checkStructMemberHandles(typename, self.structsWithHandles)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        for cmd in self.getFilteredCmdNames():
            self.commandInfo[cmd] = self.featureCmdParams[cmd]

    #
    # Override method to check for handle type, only matching resource handle types.
    def isHandle(self, baseType):
        if self.restrictHandles:
            if baseType in self.RESOURCE_HANDLE_TYPES:
                return True
            return False
        else:
            return BaseGenerator.isHandle(self, baseType)

    #
    # Create list of parameters that have handle types or are structs that contain handles.
    def getParamListHandles(self, values):
        handles = []
        for value in values:
            if self.isHandle(value.baseType):
                handles.append(value)
            elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                handles.append(value)
        return handles
