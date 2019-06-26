#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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

class VulkanCommandBufferUtilBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay"""
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

# VulkanCommandBufferUtilBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReplayConsumer class responsible for
# replaying decoded Vulkan API call parameter data.
class VulkanCommandBufferUtilBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file replay"""
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

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_command_buffer_util.h"', file=self.outFile)
        self.newline()
        write('#include "encode/vulkan_handle_wrapper_util.h"', file=self.outFile)
        write('#include "encode/vulkan_state_info.h"', file=self.outFile)
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
        for cmd in self.getFilteredCmdNames():
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            if values and (len(values) > 1) and (values[0].baseType == 'VkCommandBuffer'):
                # Check for parameters with handle types, ignoring the first VkCommandBuffer parameter.
                handles = self.getParamListHandles(values[1:])

                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'
                    cmddef += 'void Track{}Handles(CommandBufferWrapper* wrapper, {})\n'.format(cmd[2:], self.getArgList(handles))
                    cmddef += '{\n'
                    cmddef += '    assert(wrapper != nullptr);\n'
                    cmddef += '\n'
                    cmddef += self.makeGetHandleValuesBody(handles)
                    cmddef += '}'

                    write(cmddef, file=self.outFile)

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

    #
    #
    def getArgList(self, values):
        args = []
        for value in values:
            if value.arrayLength:
                args.append('uint32_t {}'.format(value.arrayLength))
            args.append('{} {}'.format(value.fullType, value.name))
        return ', '.join(args)

    #
    #
    def makeGetHandleValuesBody(self, values):
        body = ''
        first = True
        for value in values:
            indent = ' ' * self.INDENT_SIZE
            valueName = value.name

            if value.isPointer or value.isArray:
                if not first:
                    body += '\n'
                body += indent + 'if ({} != nullptr)\n'.format(value.name)
                body += indent + '{\n'
                indent += ' ' * self.INDENT_SIZE

                if value.isArray:
                    body += indent + 'for (uint32_t i = 0; i < {}; ++i)\n'.format(value.arrayLength)
                    body += indent + '{\n'
                    indent += ' ' * self.INDENT_SIZE
                    valueName = '{}[i]'.format(valueName)
                else:
                    valueName = '(*{})'.format(valueName)

            if self.isHandle(value.baseType):
                typeEnumValue = '{}Handle'.format(value.baseType[2:])
                body += indent + 'wrapper->command_handles[CommandHandleType::{}].insert(GetWrappedId({}));\n'.format(typeEnumValue, valueName)

            elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
                for entry in self.structsWithHandles[value.baseType]:
                    if self.isHandle(entry.baseType) and not (entry.isPointer or entry.isArray):
                        typeEnumValue = '{}Handle'.format(entry.baseType[2:])
                        body += indent + 'wrapper->command_handles[CommandHandleType::{}].insert(GetWrappedId({}.{}));\n'.format(typeEnumValue, valueName, entry.name)

                    else:
                        # TODO - process handles in structs
                        body += indent + '// TODO: Process handles from parameter "{}" with type "{}"\n'.format(entry.name, entry.fullType)

            if value.isPointer or value.isArray:
                indent = indent[0:-self.INDENT_SIZE]
                body += indent + '}\n'
                if value.isArray:
                    indent = indent[0:-self.INDENT_SIZE]
                    body += indent + '}\n'

            first = False

        return body
