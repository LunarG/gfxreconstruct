#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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

class VulkanStructHandleWrappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to wrap Vulkan struct member handles at API capture"""
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

# VulkanStructHandleWrappersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for wrapping struct member handles
# when recording Vulkan API call parameter data.
class VulkanStructHandleWrappersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan struct member handle wrapping at API capture"""
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
        self.pNextStructs = dict()          # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain.
        self.outputStructs = []          # Output structures that retrieve handles, which need to be wrapped.

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_struct_handle_wrappers.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        # Generate the pNext handle mapping code.
        self.newline()
        write('void UnwrapPNextStructHandles(const void* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);', file=self.outFile)
        self.newline()
        write('    // Ignore the structures added to the pnext chain by the loader.', file=self.outFile)
        write('    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||', file=self.outFile)
        write('                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))', file=self.outFile)
        write('    {', file=self.outFile)
        write('        base = reinterpret_cast<const VkBaseInStructure*>(base->pNext);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if (base != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            // This structure does not contain handles, but may point to a structure that does.', file=self.outFile)
        write('            UnwrapPNextStructHandles(base->pNext, handle_store, handle_array_store, handle_unwrap_memory);', file=self.outFile)
        write('            break;', file=self.outFile)
        for baseType in self.pNextStructs:
            write('        case {}:'.format(self.pNextStructs[baseType]), file=self.outFile)
            write('            UnwrapStructHandles(reinterpret_cast<const {}*>(base), handle_store, handle_array_store, handle_unwrap_memory);'.format(baseType), file=self.outFile)
            write('            break;', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('void RewrapPNextStructHandles(const void* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)', file=self.outFile)
        write('{', file=self.outFile)
        write('    const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);', file=self.outFile)
        self.newline()
        write('    // Ignore the structures added to the pnext chain by the loader.', file=self.outFile)
        write('    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||', file=self.outFile)
        write('                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))', file=self.outFile)
        write('    {', file=self.outFile)
        write('        base = reinterpret_cast<const VkBaseInStructure*>(base->pNext);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if (base != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            // This structure does not contain handles, but may point to a structure that does.', file=self.outFile)
        write('            RewrapPNextStructHandles(base->pNext, handle_store_iter, handle_array_store_iter);', file=self.outFile)
        write('            break;', file=self.outFile)
        for baseType in self.pNextStructs:
            write('        case {}:'.format(self.pNextStructs[baseType]), file=self.outFile)
            write('            RewrapStructHandles(reinterpret_cast<const {}*>(base), handle_store_iter, handle_array_store_iter);'.format(baseType), file=self.outFile)
            write('            break;', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        self.generateCreateWrapperFuncs()

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
            if self.checkStructMemberHandles(typename, self.structsWithHandles):
                # Track this struct if it can be present in a pNext chain, for generating the MapPNextStructHandles code.
                parentStructs = typeinfo.elem.get('structextends')
                if parentStructs:
                    sType = self.makeStructureTypeEnum(typeinfo, typename)
                    if sType:
                        self.pNextStructs[typename] = sType

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        # Check for output structures, which retrieve handles that need to be wrapped.
        for cmd in self.featureCmdParams:
            info = self.featureCmdParams[cmd]
            values = info[2]

            for value in values:
                if self.isOutputParameter(value) and self.isStruct(value.baseType) and (value.baseType in self.structsWithHandles) and (value.baseType not in self.outputStructs):
                    self.outputStructs.append(value.baseType)

        for struct in self.getFilteredStructNames():
            if struct in self.structsWithHandles:
                members = self.structsWithHandles[struct]

                body = '\n'
                body += 'void UnwrapStructHandles(const {}* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)\n'.format(struct)
                body += '{\n'
                body += '    if (value != nullptr)\n'
                body += '    {'
                body += self.makeStructHandleUnwrappings(struct, members)
                body += '    }\n'
                body += '}\n'

                body += '\n'
                body += 'void RewrapStructHandles(const {}* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)\n'.format(struct)
                body += '{\n'
                body += '    if (value != nullptr)\n'
                body += '    {'
                body += self.makeStructHandleRewrappings(struct, members)
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

    #
    # Generating expressions for unwrapping struct handles before an API call.
    def makeStructHandleUnwrappings(self, name, members):
        body = ''

        for member in members:
            body += '\n'

            if 'pNext' in member.name:
                body += '        if (value->pNext != nullptr)\n'
                body += '        {\n'
                body += '            UnwrapPNextStructHandles(value->pNext, handle_store, handle_array_store, handle_unwrap_memory);\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        UnwrapStructArrayHandles(value->{}, value->{}, handle_store, handle_array_store, handle_unwrap_memory);\n'.format(member.name, member.arrayLength)
                elif member.isPointer:
                    body += '        UnwrapStructHandles(value->{}, handle_store, handle_array_store, handle_unwrap_memory);\n'.format(member.name)
                else:
                    body += '        UnwrapStructHandles(&value->{}, handle_store, handle_array_store, handle_unwrap_memory);\n'.format(member.name)
            elif not self.isDispatchableHandle(member.baseType):
                # If it is an array or pointer, map with the utility function.
                if member.isArray:
                    if member.isDynamic:
                        body += '        UnwrapHandles<{}Wrapper>(&value->{}, value->{}, handle_array_store, handle_unwrap_memory);\n'.format(member.baseType[2:], member.name, member.arrayLength);
                    else:
                        body += '        UnwrapHandles<{}Wrapper>(value->{}, value->{}, handle_store);\n'.format(member.baseType[2:], member.name, member.arrayLength);
                elif member.isPointer:
                    body += '        UnwrapHandle<{}Wrapper>(value->{}, handle_store);\n'.format(member.baseType[2:], member.name);
                else:
                    body += '        UnwrapHandle<{}Wrapper>(&value->{}, handle_store);\n'.format(member.baseType[2:], member.name);

        return body

    #
    # Generating expressions for rewrapping struct handles after to an API call.
    def makeStructHandleRewrappings(self, name, members):
        body = ''

        for member in members:
            body += '\n'

            if 'pNext' in member.name:
                body += '        if (value->pNext != nullptr)\n'
                body += '        {\n'
                body += '            RewrapPNextStructHandles(value->pNext, handle_store_iter, handle_array_store_iter);\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        RewrapStructArrayHandles(value->{}, value->{}, handle_store_iter, handle_array_store_iter);\n'.format(member.name, member.arrayLength)
                elif member.isPointer:
                    body += '        RewrapStructHandles(value->{}, handle_store_iter, handle_array_store_iter);\n'.format(member.name)
                else:
                    body += '        RewrapStructHandles(&value->{}, handle_store_iter, handle_array_store_iter);\n'.format(member.name)
            elif not self.isDispatchableHandle(member.baseType):
                # If it is an array or pointer, map with the utility function.
                if member.isArray:
                    if member.isDynamic:
                        body += '        RewrapHandles<{}Wrapper>(&value->{}, value->{}, handle_array_store_iter);\n'.format(member.baseType[2:], member.name, member.arrayLength);
                    else:
                        body += '        RewrapHandles<{}Wrapper>(value->{}, value->{}, handle_store_iter);\n'.format(member.baseType[2:], member.name, member.arrayLength);
                elif member.isPointer:
                    body += '        RewrapHandle<{}Wrapper>(value->{}, handle_store_iter);\n'.format(member.baseType[2:], member.name);
                else:
                    body += '        RewrapHandle<{}Wrapper>(&value->{}, handle_store_iter);\n'.format(member.baseType[2:], member.name);

        return body

    #
    # Generates functions that wrap struct handle members.
    def generateCreateWrapperFuncs(self):
        for struct in self.outputStructs:
            body = ''
            body += 'void CreateWrappedStructHandles({}* value, PFN_GetHandleId get_id)\n'.format(struct)
            body += '{\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'

            members = self.structsWithHandles[struct]
            for member in members:
                if self.isStruct(member.baseType):
                    if member.isArray:
                        body += '        CreateWrappedStructArrayHandles<{}>(value->{}, value->{}, get_id);\n'.format(member.baseType, member.name, member.arrayLength)
                    elif member.isPointer:
                        body += '        CreateWrappedStructHandles(value->{}, get_id);\n'.format(member.name)
                    else:
                        body += '        CreateWrappedStructHandles(&value->{}, get_id);\n'.format(member.name)
                elif not self.isDispatchableHandle(member.baseType):
                    if member.isArray:
                        body += '        CreateWrappedHandles<{}Wrapper>(value->{}, value->{}, get_id);\n'.format(member.baseType[2:], member.name, member.arrayLength)
                    elif member.isPointer:
                        body += '        CreateWrappedHandle<{}Wrapper>(value->{}, get_id);\n'.format(member.baseType[2:], member.name)
                    else:
                        body += '        CreateWrappedHandle<{}Wrapper>(&value->{}, get_id);\n'.format(member.baseType[2:], member.name)

            body += '    }\n'
            body += '}\n'
            write(body, file=self.outFile)
