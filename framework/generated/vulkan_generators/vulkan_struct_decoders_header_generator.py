#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
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

class VulkanStructDecodersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ type declarations for Vulkan struct decoding"""
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

# VulkanStructDecodersHeaderGenerator - subclass of BaseGenerator.
# Generates C++ type declarations for the decoded Vulkan API structure wrappers.
class VulkanStructDecodersHeaderGenerator(BaseGenerator):
    """Generate C++ type declarations for Vulkan struct decoding"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/custom_vulkan_struct_decoders_forward.h"', file=self.outFile)
        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/pnext_node.h"', file=self.outFile)
        write('#include "decode/pointer_decoder.h"', file=self.outFile)
        write('#include "decode/string_array_decoder.h"', file=self.outFile)
        write('#include "decode/string_decoder.h"', file=self.outFile)
        write('#include "decode/struct_pointer_decoder.h"', file=self.outFile)
        write('#include "format/format.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_decoders_forward.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include <memory>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers or self.featureStructAliases:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for struct in self.getFilteredStructNames():
            body = '' if first else '\n'
            body += 'struct Decoded_{}\n'.format(struct)
            body += '{\n'
            body += '    using struct_type = {};\n'.format(struct)
            body += '\n'
            body += '    {}* decoded_value{{ nullptr }};\n'.format(struct)

            decls = self.makeMemberDeclarations(struct, self.featureStructMembers[struct])
            if decls:
                body += '\n'
                body += decls

            body += '};'

            write(body, file=self.outFile)
            first = False

        # Write typedefs for any aliases
        for struct in self.featureStructAliases:
            body = '' if first else '\n'
            body += 'typedef Decoded_{} Decoded_{};'.format(self.featureStructAliases[struct], struct)
            write(body, file=self.outFile)
            first = False

    #
    # Determines if a Vulkan struct member needs an associated member delcaration in the decoded struct wrapper.
    def needsMemberDeclaration(self, value):
        if value.isPointer or value.isArray:
            return True
        elif self.isFunctionPtr(value.baseType):
            return True
        elif self.isHandle(value.baseType):
            return True
        elif self.isStruct(value.baseType):
            return True
        return False

    #
    # Determines if the struct member requires default initalization and determines the value to use.
    def getDefaultInitValue(self, type):
        if type == 'format::HandleId':
            # These types represent values recorded for Vulkan handles.
            return 'format::kNullHandleId'
        elif type == 'uint64_t':
            # These types represent values recorded for function pointers and void pointers to non-Vulkan objects.
            return '0'
        return None

    #
    # Generate the struct member declarations for the decoded struct wrapper.
    def makeMemberDeclarations(self, name, values):
        body = ''

        for value in values:
            if value.name == 'pNext':
                # We have a special type to store the pNext chain
                body += '    std::unique_ptr<PNextNode> pNext;\n'
            elif self.needsMemberDeclaration(value):
                typeName = self.makeDecodedParamType(value)
                if self.isStruct(value.baseType):
                    typeName = 'std::unique_ptr<{}>'.format(typeName)

                defaultValue = self.getDefaultInitValue(typeName)
                if defaultValue:
                    body += '    {} {}{{ {} }};\n'.format(typeName, value.name, defaultValue)
                else:
                    body += '    {} {};\n'.format(typeName, value.name)

        return body
