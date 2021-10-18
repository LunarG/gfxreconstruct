#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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


class VulkanStructHandleWrappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to wrap Vulkan struct member handles at API capture"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platformTypes,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraVulkanHeaders=extraVulkanHeaders
        )


# VulkanStructHandleWrappersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for wrapping struct member handles
# when recording Vulkan API call parameter data.
class VulkanStructHandleWrappersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan struct member handle wrapping at API capture"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=False,
            processStructs=True,
            featureBreak=False,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structsWithHandles = dict()
        self.pNextStructsWithHandles = dict(
        )  # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain and contain handles.
        self.pNextStructsWithoutHandles = dict(
        )  # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain and do not contain handles.

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_struct_handle_wrappers.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vk_layer.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        # Generate the pNext shallow copy code, for pNext structs that don't have handles, but need to be preserved in the overall copy for handle wrapping.
        self.newline()
        write('static VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(base != nullptr);', file=self.outFile)
        self.newline()
        write('    VkBaseInStructure* copy = nullptr;', file=self.outFile)
        write('    switch (base->sType)', file=self.outFile)
        write('    {', file=self.outFile)
        write('    default:', file=self.outFile)
        write('        GFXRECON_LOG_WARNING("Failed to copy entire pNext chain when unwrapping handles due to unrecognized sType %d", base->sType);', file=self.outFile)
        write('        break;', file=self.outFile)
        write('    case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO:', file=self.outFile)
        write('        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerInstanceCreateInfo*>(base), 1, unwrap_memory));', file=self.outFile)
        write('        break;', file=self.outFile)
        write('    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO:', file=self.outFile)
        write('        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerDeviceCreateInfo*>(base), 1, unwrap_memory));', file=self.outFile)
        write('        break;', file=self.outFile)
        for baseType in self.pNextStructsWithoutHandles:
            write('    case {}:'.format(self.pNextStructsWithoutHandles[baseType]), file=self.outFile)
            write('        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const {}*>(base), 1, unwrap_memory));'.format(baseType), file=self.outFile)
            write('        break;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return copy;', file=self.outFile)
        write('}', file=self.outFile)

        # Generate the pNext handle wrapping code.
        self.newline()
        write('const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);', file=self.outFile)
        self.newline()
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('        {', file=self.outFile)
        write('            // This structure does not contain handles, but may point to a structure that does.', file=self.outFile)
        write('            VkBaseInStructure* copy = CopyPNextStruct(base, unwrap_memory);', file=self.outFile)
        write('            if (copy != nullptr)', file=self.outFile)
        write('            {', file=self.outFile)
        write('                copy->pNext = reinterpret_cast<const VkBaseInStructure*>(UnwrapPNextStructHandles(base->pNext, unwrap_memory));', file=self.outFile)
        write('            }', file=self.outFile)
        write('            return copy;', file=self.outFile)
        write('        }', file=self.outFile)
        for baseType in self.pNextStructsWithHandles:
            write('        case {}:'.format(self.pNextStructsWithHandles[baseType]), file=self.outFile)
            write('            return UnwrapStructPtrHandles(reinterpret_cast<const {}*>(base), unwrap_memory);'.format(baseType), file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return nullptr;', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            hasHandles = self.checkStructMemberHandles(
                typename, self.structsWithHandles
            )

            # Track this struct if it can be present in a pNext chain.
            parentStructs = typeinfo.elem.get('structextends')
            if parentStructs:
                sType = self.makeStructureTypeEnum(typeinfo, typename)
                if sType:
                    if hasHandles:
                        self.pNextStructsWithHandles[typename] = sType
                    else:
                        self.pNextStructsWithoutHandles[typename] = sType

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        for struct in self.getFilteredStructNames():
            if (struct in self.structsWithHandles) or (struct in self.GENERIC_HANDLE_STRUCTS):
                handleMembers = dict()
                genericHandleMembers = dict()

                if struct in self.structsWithHandles:
                    handleMembers = self.structsWithHandles[struct]
                if struct in self.GENERIC_HANDLE_STRUCTS:
                    genericHandleMembers = self.GENERIC_HANDLE_STRUCTS[struct]

                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory)\n'.format(struct)
                body += '{\n'
                body += '    if (value != nullptr)\n'
                body += '    {'
                body += self.makeStructHandleUnwrappings(struct, handleMembers, genericHandleMembers)
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)
    # yapf: enable

    #
    # Generating expressions for unwrapping struct handles before an API call.
    # yapf: disable
    def makeStructHandleUnwrappings(self, name, handleMembers, genericHandleMembers):
        body = ''

        for member in handleMembers:
            body += '\n'

            if 'pNext' in member.name:
                body += '        if (value->pNext != nullptr)\n'
                body += '        {\n'
                body += '            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);\n'
                body += '        }\n'
            elif self.isStruct(member.baseType):
                # This is a struct that includes handles.
                if member.isArray:
                    body += '        value->{name} = UnwrapStructArrayHandles(value->{name}, value->{}, unwrap_memory);\n'.format(member.arrayLength, name=member.name)
                elif member.isPointer:
                    body += '        value->{name} = UnwrapStructPtrHandles(value->{name}, unwrap_memory);\n'.format(name=member.name)
                else:
                    body += '        UnwrapStructHandles(&value->{}, unwrap_memory);\n'.format(member.name)
            else:
                # If it is an array or pointer, map with the utility function.
                if member.isArray:
                    if member.isDynamic:
                        body += '        value->{name} = UnwrapHandles<{}>(value->{name}, value->{}, unwrap_memory);\n'.format(member.baseType, member.arrayLength, name=member.name);
                    else:
                        body += '        std::transform(value->{name}, value->{name} + value->{}, value->{name}, GetWrappedHandle<{}>);\n'.format(member.arrayLength, member.baseType, name=member.name);
                elif member.isPointer:
                    body += '        value->{name} = UnwrapHandles<{}>(value->{name}, 1, unwrap_memory);\n'.format(member.baseType, name=member.name);
                else:
                    body += '        value->{name} = GetWrappedHandle<{}>(value->{name});\n'.format(member.baseType, name=member.name);

        for member in genericHandleMembers:
            body += '\n'
            body += '        value->{name} = GetWrappedHandle(value->{name}, value->{});\n'.format(genericHandleMembers[member], name=member);

        return body
    # yapf: enable
