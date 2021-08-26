#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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


class VulkanCommandBufferUtilHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay"""
    def __init__(
            self,
            blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
            platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
            filename=None,
            directory='.',
            prefixText='',
            protectFile=False,
            protectFeature=True,
            extraVulkanHeaders=[]):
        BaseGeneratorOptions.__init__(self,
                                      blacklists,
                                      platformTypes,
                                      filename,
                                      directory,
                                      prefixText,
                                      protectFile,
                                      protectFeature,
                                      extraVulkanHeaders=extraVulkanHeaders)


# VulkanCommandBufferUtilBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReplayConsumer class responsible for
# replaying decoded Vulkan API call parameter data.
class VulkanCommandBufferUtilHeaderGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file replay"""
    def __init__(self,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True,
                               processStructs=True,
                               featureBreak=False,
                               errFile=errFile,
                               warnFile=warnFile,
                               diagFile=diagFile)

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structsWithHandles = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "encode/vulkan_handle_wrappers.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
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
        first = True
        for cmd in self.getFilteredCmdNames():
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            if values and (len(values) > 1) and (values[0].baseType
                                                 == 'VkCommandBuffer'):
                # Check for parameters with handle types, ignoring the first VkCommandBuffer parameter.
                handles = self.getParamListHandles(values[1:])

                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'
                    cmddef += 'void Track{}Handles(CommandBufferWrapper* wrapper, {});'.format(
                        cmd[2:], self.getArgList(handles))
                    write(cmddef, file=self.outFile)
                    first = False

    #
    # Create list of parameters that have handle types or are structs that contain handles.
    def getParamListHandles(self, values):
        handles = []
        for value in values:
            if self.isHandle(value.baseType):
                handles.append(value)
            elif self.isStruct(
                    value.baseType) and (value.baseType
                                         in self.structsWithHandles):
                handles.append(value)
        return handles

    #
    #
    def getArgList(self, values):
        args = []
        for value in values:
            if value.arrayLength:
                args.append('uint32_t {}'.format(value.arrayLength))
            args.append('{} {}'.format(value.fullType, value.name))
        return ', '.join(self.makeUniqueList(args))
