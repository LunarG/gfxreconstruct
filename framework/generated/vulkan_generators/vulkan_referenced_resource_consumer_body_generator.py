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

class VulkanReferencedResourceBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for detecting unreferenced resource handles in a capture file"""
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

# VulkanReferencedResourceBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanReferencedResource class responsible for
# determining which resource handles are used or unused in a capture file.
class VulkanReferencedResourceBodyGenerator(BaseGenerator):
    """Generate a C++ class for detecting unreferenced resource handles in a capture file"""
    # All resource and resource associated handle types to be processed.
    RESOURCE_HANDLE_TYPES = ['VkBuffer', 'VkImage', 'VkBufferView', 'VkImageView', 'VkFramebuffer', 'VkDescriptorSet', 'VkCommandBuffer']

    # Handle types that contain resource and child resource handle types.
    CONTAINER_HANDLE_TYPES = ['VkDescriptorSet']

    # Handle types that use resource and child resource handle types.
    USER_HANDLE_TYPES = ['VkCommandBuffer']

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
        self.pNextStructs = dict()    # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain.
        self.commandInfo = dict()     # Map of Vulkan commands to parameter info
        self.restrictHandles = True   # Determines if the 'isHandle' override limits the handle test to only the values conained by RESOURCE_HANDLE_TYPES.

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_referenced_resource_consumer.h"', file=self.outFile)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        for cmd, info in self.commandInfo.items():
            returnType = info[0]
            params = info[2]
            if params and params[0].baseType == 'VkCommandBuffer':
                # Check for parameters with resource handle types.
                handles = self.getParamListHandles(params[1:])

                if (handles):
                    # Generate a function to add handles to the command buffer's referenced handle list.
                    cmddef = '\n'

                    # Temporarily remove resource only matching restriction from isHandle() when generating the function signature.
                    self.restrictHandles = False
                    cmddef += self.makeConsumerFuncDecl(returnType, 'VulkanReferencedResourceConsumer::Process_' + cmd, params) + '\n'
                    self.restrictHandles = True

                    cmddef += '{\n'
                    indent = self.INDENT_SIZE * ' '

                    # Add unreferenced parameter macros.
                    unrefCount = 0
                    for param in params[1:]:
                        if not param in handles:
                            cmddef += indent + 'GFXRECON_UNREFERENCED_PARAMETER({});\n'.format(param.name)
                            unrefCount += 1
                    if unrefCount > 0:
                        cmddef += '\n'

                    for index, handle in enumerate(handles):
                        cmddef += self.trackCommandHandle(index, params[0].name, handle, indent=indent)
                    cmddef += '}'

                    write(cmddef, file=self.outFile)

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

            # Track this struct if it can be present in a pNext chain.
            parentStructs = typeinfo.elem.get('structextends')
            if parentStructs:
                sType = self.makeStructureTypeEnum(typeinfo, typename)
                if sType:
                    self.pNextStructs[typename] = sType

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

    #
    #
    def trackCommandHandle(self, index, commandParamName, value, valuePrefix='', indent=''):
        body = ''
        tail = ''
        indexName = None
        countName = None
        valueName = valuePrefix + value.name
        isHandle = self.isHandle(value.baseType)

        if (value.isPointer or value.isArray) and value.name != 'pnext_value':
            if index > 0:
                body += '\n'

            accessOperator = '->'
            if not valuePrefix:
                # If there is no prefix, this is the pointer parameter received by the function, which should never be null.
                body += indent + 'assert({} != nullptr);\n'.format(value.name)
                body += '\n'
            else:
                # If there is a prefix, this is a struct member.  We need to determine the type of access operator to use
                # for the member of a 'decoded' struct type, where handle member types will be HandlePointerDecoder, but
                # struct member types will be unique_ptr<StructPointerDecoder>.
                if isHandle:
                    accessOperator = '.'

            # Add IsNull and HasData checks for the pointer decoder, before accessing its data.
            # Note that this does not handle the decoded struct member cases for static arrays, which would need to use '.' instead of '->'.
            body += indent + 'if (!{prefix}{name}{op}IsNull() && ({prefix}{name}{op}HasData()))\n'.format(prefix=valuePrefix, name=value.name, op=accessOperator)
            body += indent + '{\n'
            tail = indent + '}\n' + tail
            indent += ' ' * self.INDENT_SIZE

            # Get the pointer from the pointer decoder object.
            valueName = '{}_ptr'.format(value.name)
            if isHandle:
                body += indent + 'auto {} = {}{}{}GetPointer();\n'.format(valueName, valuePrefix, value.name, accessOperator)
            else:
                body += indent + 'auto {} = {}{}{}GetMetaStructPointer();\n'.format(valueName, valuePrefix, value.name, accessOperator)

            # Add a for loop for an array of values.
            if value.isArray:
                indexName = '{}_index'.format(value.name)
                countName = '{}_count'.format(value.name)
                body += indent + 'size_t {} = {}{}{}GetLength();\n'.format(countName, valuePrefix, value.name, accessOperator)
                body += indent + 'for (size_t {i} = 0; {i} < {}; ++{i})\n'.format(countName, i=indexName)
                body += indent + '{\n'
                tail = indent + '}\n' + tail
                indent += ' ' * self.INDENT_SIZE

        # Insert commands to add handles to a container, or to process struct members that contain handles.
        if isHandle:
            if value.isArray:
                valueName = '{}[{}]'.format(valueName, indexName)
            elif value.isPointer:
                valueName = '(*{})'.format(valueName)

            if value.baseType in self.CONTAINER_HANDLE_TYPES:
                body += indent + 'GetTable().AddContainerToUser({}, {});\n'.format(commandParamName, valueName)
            elif value.baseType in self.USER_HANDLE_TYPES:
                body += indent + 'GetTable().AddUserToUser({}, {});\n'.format(commandParamName, valueName)
            else:
                body += indent + 'GetTable().AddResourceToUser({}, {});\n'.format(commandParamName, valueName)

        elif self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles):
            if value.isArray:
                accessOperator = '[{}].'.format(indexName)
            else:
                accessOperator = '->'

            for index, entry in enumerate(self.structsWithHandles[value.baseType]):
                if entry.name == 'pNext':
                    extStructsWithHandles = [extStruct for extStruct in self.registry.validextensionstructs[value.baseType] if extStruct in self.structsWithHandles]
                    if extStructsWithHandles:
                        body += indent + 'const VkBaseInStructure* pnext_header = nullptr;\n'
                        body += indent + 'if ({name}->pNext != nullptr)\n'.format(name=valueName)
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'pnext_header = reinterpret_cast<const VkBaseInStructure*>({}->pNext->GetPointer());\n'.format(valueName)
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                        body += indent + 'while (pnext_header)\n'
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'switch (pnext_header->sType)\n'
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'default:\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'break;\n'
                        indent = indent[:-self.INDENT_SIZE]
                        for extStruct in extStructsWithHandles:
                            body += indent + 'case {}:\n'.format(self.pNextStructs[extStruct])
                            body += indent + '{\n'
                            indent += ' ' * self.INDENT_SIZE
                            body += indent + 'auto pnext_value = reinterpret_cast<const Decoded_{}*>({}->pNext->GetPointer());\n'.format(extStruct, valueName)
                            body += self.trackCommandHandle(index, commandParamName, ValueInfo('pnext_value', extStruct, 'const {} *'.format(extStruct), 1), '', indent=indent)
                            body += indent + 'break;\n'
                            indent = indent[:-self.INDENT_SIZE]
                            body += indent + '}\n'
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                        body += indent + 'pnext_header = pnext_header->pNext;\n'
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                else:
                    body += self.trackCommandHandle(index, commandParamName, entry, valueName + accessOperator, indent)

        return body + tail
