#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2020 LunarG, Inc.
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

class VulkanStructHandleMappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to map Vulkan struct member handles at file replay"""
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

# VulkanStructHandleMappersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for mapping struct member handles
# when replaying decoded Vulkan API call parameter data.
class VulkanStructHandleMappersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan struct member handle mapping at file replay"""
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
        self.structsWithHandlePtrs = []
        self.pNextStructs = dict()          # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain.
        # List of structs containing handles that are also used as output parameters for a command
        self.outputStructsWithHandles = []

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_struct_handle_mappers.h"', file=self.outFile)
        self.newline()
        write('#include "decode/custom_vulkan_struct_decoders.h"', file=self.outFile)
        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/vulkan_handle_mapping_util.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_decoders.h"', file=self.outFile)
        self.newline()
        write('#include <algorithm>', file=self.outFile)
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        # Generate the pNext handle mapping code.
        self.newline()
        write('void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectInfoTable& object_info_table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if ((value != nullptr) && (wrapper != nullptr))', file=self.outFile)
        write('    {', file=self.outFile)
        write('        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);', file=self.outFile)
        write('', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            // TODO: Report or raise fatal error for unrecongized sType?', file=self.outFile)
        write('            break;', file=self.outFile)
        for baseType in self.pNextStructs:
            write('        case {}:'.format(self.pNextStructs[baseType]), file=self.outFile)
            write('            MapStructHandles(reinterpret_cast<Decoded_{}*>(wrapper), object_info_table);'.format(baseType), file=self.outFile)
            write('            break;', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        # Generate handle adding functions for output structs with handles
        for struct in self.outputStructsWithHandles:
            self.newline()
            write(self.makeStructHandleAdditions(struct, self.structsWithHandles[struct]), file=self.outFile)

        # Generate handle memory allocation functions for output structs with handles
        for struct in self.outputStructsWithHandles:
            if struct in self.structsWithHandlePtrs:
                self.newline()
                write(self.makeStructHandleAllocations(struct, self.structsWithHandles[struct]), file=self.outFile)

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
            if self.checkStructMemberHandles(typename, self.structsWithHandles, self.structsWithHandlePtrs):
                # Track this struct if it can be present in a pNext chain, for generating the MapPNextStructHandles code.
                parentStructs = typeinfo.elem.get('structextends')
                if parentStructs:
                    sType = self.makeStructureTypeEnum(typeinfo, typename)
                    if sType:
                        self.pNextStructs[typename] = sType

    #
    # Method override
    def genCmd(self, cmdinfo, name, alias):
        BaseGenerator.genCmd(self, cmdinfo, name, alias)

        # Look for output structs that contain handles and add to list
        if not alias:
            for valueInfo in self.featureCmdParams[name][2]:
                if self.isOutputParameter(valueInfo) and \
                (valueInfo.baseType in self.getFilteredStructNames()) and \
                (valueInfo.baseType in self.structsWithHandles) and \
                (valueInfo.baseType not in self.outputStructsWithHandles):
                    self.outputStructsWithHandles.append(valueInfo.baseType)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        for struct in self.getFilteredStructNames():
            if struct in self.structsWithHandles:
                members = self.structsWithHandles[struct]

                # Determine if the struct only contains members that are structs that contain handles or static arrays of handles,
                # and does not need a temporary variable referencing the struct value.
                needsValuePtr = False
                for member in members:
                    if self.isHandle(member.baseType) and not (member.isArray and not member.isDynamic):
                        needsValuePtr = True
                        break

                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const VulkanObjectInfoTable& object_info_table)\n'.format(struct)
                body += '{\n'

                if not needsValuePtr:
                    body += '    if (wrapper != nullptr)\n'
                    body += '    {'
                else:
                    body += '    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))\n'
                    body += '    {\n'
                    body += '        {}* value = wrapper->decoded_value;\n'.format(struct)

                body += self.makeStructHandleMappings(struct, members)
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

    #
    # Generating expressions for mapping struct handles read from the capture file to handles created at replay.
    def makeStructHandleMappings(self, name, members):
        body = ''

        for member in members:
            body += '\n'

            if 'pNext' in member.name:
                body += '        if (wrapper->pNext)\n'
                body += '        {\n'
                body += '            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        MapStructArrayHandles<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength(), object_info_table);\n'.format(member.baseType, name=member.name)
                elif member.isPointer:
                    body += '        MapStructArrayHandles<Decoded_{}>(wrapper->{}->GetMetaStructPointer(), 1, object_info_table);\n'.format(member.baseType, member.name)
                else:
                    body += '        MapStructHandles(wrapper->{}.get(), object_info_table);\n'.format(member.name)
            else:
                # If it is an array or pointer, map with the utility function.
                if (member.isArray or member.isPointer):
                    if member.isDynamic or member.isPointer:
                        body += '        value->{name} = handle_mapping::MapHandleArray<{type}Info>(&wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(type=member.baseType[2:], name=member.name)
                    else:
                        body += '        handle_mapping::MapHandleArray<{type}Info>(&wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(type=member.baseType[2:], name=member.name)
                else:
                    body += '        value->{name} = handle_mapping::MapHandle<{type}Info>(wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(type=member.baseType[2:], name=member.name)

        return body

    #
    # Generating expressions for adding mappings for handles created at replay that are embedded in structs
    def makeStructHandleAdditions(self, name, members):
        body = 'void AddStructHandles(const Decoded_{name}* id_wrapper, const {name}* handle_struct, VulkanObjectInfoTable* object_info_table)\n'.format(name=name)
        body +='{\n'
        body +='    if (id_wrapper != nullptr)\n'
        body +='    {\n'

        for member in members:

            if 'pNext' in member.name:
                body += '        if (id_wrapper->pNext)\n'
                body += '        {\n'
                body += '            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_info_table);\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        AddStructArrayHandles<Decoded_{}>(id_wrapper->{name}->GetMetaStructPointer(), id_wrapper->{name}->GetLength(), handle_struct->{name}, static_cast<size_t>(handle_struct->{length}), object_info_table);\n'.format(member.baseType, name=member.name, length=member.arrayLength)
                elif member.isPointer:
                    body += '        AddStructArrayHandles<Decoded_{}>(id_wrapper->{name}->GetMetaStructPointer(), 1, handle_struct->{name}, 1, object_info_table);\n'.format(member.baseType, name=member.name)
                else:
                    body += '        AddStructHandles(id_wrapper->{name}.get(), &handle_struct->{name}, object_info_table);\n'.format(name=member.name)
            else:
                # If it is an array or pointer, add with the utility function.
                if (member.isArray or member.isPointer):
                    if member.isArray:
                        body += '        handle_mapping::AddHandleArray<{type}Info>(id_wrapper->{name}.GetPointer(), id_wrapper->{name}.GetLength(), handle_struct->{name}, handle_struct->{length}, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(type=member.baseType[2:], name=member.name, length=member.arrayLength)
                    else:
                        body += '        handle_mapping::AddHandleArray<{type}Info>(id_wrapper->{name}.GetPointer(), 1, handle_struct->{name}, 1, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(type=member.baseType[2:], name=member.name)
                else:
                    body += '        handle_mapping::AddHandle<{type}Info>(id_wrapper->{name}, handle_struct->{name}, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(type=member.baseType[2:], name=member.name)

        body += '    }\n'
        body += '}'
        return body

    #
    # Generate expressions to allocate memory for handles created at replay that are embedded in structs
    def makeStructHandleAllocations(self, name, members):
        # Determine if the struct only contains members that are structs that contain handles or static arrays of handles,
        # and does not need a temporary variable referencing the struct value.
        needsValuePtr = False
        for member in members:
            if self.isHandle(member.baseType) and not (member.isArray and not member.isDynamic):
                needsValuePtr = False
                break

        body = 'void SetStructHandleLengths(Decoded_{name}* wrapper)\n'.format(name=name)
        body +='{\n'

        if not needsValuePtr:
            body += '    if (wrapper != nullptr)\n'
            body += '    {\n'
        else:
            body += '    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))\n'
            body += '    {\n'
            body += '        {}* value = wrapper->decoded_value;\n'.format(name)
            body += '\n'

        for member in members:
            if 'pNext' in member.name:
                body += '        if (wrapper->pNext)\n'
                body += '        {\n'
                body += '            SetPNextStructHandleLengths(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer());\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        SetStructArrayHandleLengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength());\n'.format(member.baseType, name=member.name)
                elif member.isPointer:
                    body += '        SetStructArrayHandleLengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), 1);\n'.format(member.baseType, name=member.name)
                else:
                    body += '        SetStructHandleLengths(wrapper->{name}.get());\n'.format(name=member.name)
            else:
                # If it is an array or pointer, add with the utility function.
                if (member.isArray or member.isPointer):
                    if member.isArray:
                        body += '        wrapper->{name}.SetHandleLength(wrapper->{name}.GetLength());\n'.format(name=member.name)
                    else:
                        body += '        wrapper->{}.SetHandleLength(1);\n'.format(member.name)

                    if member.isDynamic or member.isPointer:
                        body += '        value->{name} = wrapper->{name}.GetHandlePointer();\n'.format(name=member.name)

        body += '    }\n'
        body += '}'
        return body
