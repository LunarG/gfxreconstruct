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

class VulkanStructHandleWrappersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function prototypes to wrap Vulkan struct member handles at API capture"""
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

# VulkanStructHandleWrappersHeaderGenerator - subclass of BaseGenerator.
# Generates C++ function prototypes for wrapping struct member handles
# when recording Vulkan API call parameter data.
class VulkanStructHandleWrappersHeaderGenerator(BaseGenerator):
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
        self.outputStructs = []           # Output structures that retrieve handles, which need to be wrapped.

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "encode/custom_vulkan_struct_handle_wrappers.h"', file=self.outFile)
        write('#include "encode/vulkan_handle_wrapper_util.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);', file=self.outFile)
        self.newline()
        self.generateCreateWrapperFuncs()
        write('template <typename ParentWrapper, typename CoParentWrapper, typename T>', file=self.outFile)
        write('void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write('T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));', file=self.outFile)
        self.newline()
        write('    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);', file=self.outFile)
        write('    size_t         num_bytes = len * sizeof(T);', file=self.outFile)
        self.newline()
        write('    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write('const T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    T* unwrapped_struct = nullptr;', file=self.outFile)
        self.newline()
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);', file=self.outFile)
        write('        UnwrapStructHandles(unwrapped_struct, unwrap_memory);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return unwrapped_struct;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write('const T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if ((values != nullptr) && (len > 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write('        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);', file=self.outFile)
        self.newline()
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);', file=self.outFile)
        write('        }', file=self.outFile)
        self.newline()
        write('        return unwrapped_structs;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    // Leave the original memory in place when the pointer is not null, but size is zero.', file=self.outFile)
        write('    return values;', file=self.outFile)
        write('}', file=self.outFile)
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
        if self.featureStructMembers or self.featureCmdParams:
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

        # Generate unwrap and rewrap code for input structures.
        for struct in self.getFilteredStructNames():
            if struct in self.structsWithHandles:
                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory);'.format(struct)
                write(body, file=self.outFile)

    #
    # Generates functions that wrap struct handle members.
    def generateCreateWrapperFuncs(self):
        for struct in self.outputStructs:
            body = 'template <typename ParentWrapper, typename CoParentWrapper>\n'
            body += 'void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, {}* value, PFN_GetHandleId get_id)\n'.format(struct)
            body += '{\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'

            members = self.structsWithHandles[struct]
            for member in members:
                if self.isStruct(member.baseType):
                    if member.isArray:
                        body += '        CreateWrappedStructArrayHandles<ParentWrapper, CoParentWrapper, {}>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(member.baseType, member.name, member.arrayLength)
                    elif member.isPointer:
                        body += '        CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, value->{}, get_id);\n'.format(member.name)
                    else:
                        body += '        CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->{}, get_id);\n'.format(member.name)
                else:
                    if member.isArray:
                        body += '        CreateWrappedHandles<ParentWrapper, CoParentWrapper, {}Wrapper>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(member.baseType[2:], member.name, member.arrayLength)
                    elif member.isPointer:
                        body += '        CreateWrappedHandle<ParentWrapper, CoParentWrapper, {}Wrapper>(parent, co_parent, value->{}, get_id);\n'.format(member.baseType[2:], member.name)
                    else:
                        body += '        CreateWrappedHandle<ParentWrapper, CoParentWrapper, {}Wrapper>(parent, co_parent, &value->{}, get_id);\n'.format(member.baseType[2:], member.name)

            body += '    }\n'
            body += '}\n'
            write(body, file=self.outFile)
