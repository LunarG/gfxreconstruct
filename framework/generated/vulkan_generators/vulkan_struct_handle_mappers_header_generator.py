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

class VulkanStructHandleMappersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function prototypes to map Vulkan struct member handles at file replay"""
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

# VulkanStructHandleMappersHeaderGenerator - subclass of BaseGenerator.
# Generates C++ function prototypes for mapping struct member handles
# when replaying decoded Vulkan API call parameter data.
class VulkanStructHandleMappersHeaderGenerator(BaseGenerator):
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
        # List of structs containing handles that are also used as output parameters for a command
        self.outputStructsWithHandles = []

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/pnext_node.h"', file=self.outFile)
        write('#include "decode/vulkan_object_info_table.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_decoders_forward.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectInfoTable& object_info_table);', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write('void MapStructArrayHandles(T* structs, size_t len, const VulkanObjectInfoTable& object_info_table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (structs != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            MapStructHandles(&structs[i], object_info_table);', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

        for struct in self.outputStructsWithHandles:
            write('void AddStructHandles(const Decoded_{type}* id_wrapper, const {type}* handle_struct, VulkanObjectInfoTable* object_info_table);'.format(type=struct), file=self.outFile)
            self.newline()

        write('template <typename T>', file=self.outFile)
        write('void AddStructArrayHandles(const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, VulkanObjectInfoTable* object_info_table)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (id_wrappers != nullptr && handle_structs != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        // TODO: Improved handling of array size mismatch.', file=self.outFile)
        write('        size_t len = std::min(id_len, handle_len);', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            AddStructHandles(&id_wrappers[i], &handle_structs[i], object_info_table);', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

        for struct in self.outputStructsWithHandles:
            if struct in self.structsWithHandlePtrs:
                write('void SetStructHandleLengths(Decoded_{type}* wrapper);'.format(type=struct), file=self.outFile)
                self.newline()

        write('template <typename T>', file=self.outFile)
        write('void SetStructArrayHandleLengths(T* wrappers, size_t len)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (wrappers != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            SetStructHandleLengths(&wrappers[i]);', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
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
            self.checkStructMemberHandles(typename, self.structsWithHandles, self.structsWithHandlePtrs)

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
                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const VulkanObjectInfoTable& object_info_table);'.format(struct)
                write(body, file=self.outFile)
