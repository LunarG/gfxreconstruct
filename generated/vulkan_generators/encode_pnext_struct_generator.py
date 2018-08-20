#!/usr/bin/python3 -i
#
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

class EncodePNextStructGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API pNext structure encoding C++ code generation"""
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

# EncodePNextStructGenerator - subclass of BaseGenerator.
# Generates C++ code for Vulkan API pNext structure encoding.
class EncodePNextStructGenerator(BaseGenerator):
    """Generate pNext structure encoding C++ code"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False, processStructs=True, featureBreak=False,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # Map to store VkStructureType enum values.
        self.sTypeValues = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        write('#include "format/trace_pnext_util.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        self.newline()
        write('size_t encode_pnext_struct(format::ParameterEncoder* encoder, const void* value)', file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(encoder != nullptr);', file=self.outFile)
        self.newline()
        write('    size_t result = 0;', file=self.outFile)
        self.newline()
        write('    const format::VulkanStructHeader* header = reinterpret_cast<const format::VulkanStructHeader*>(value);', file=self.outFile)
        self.newline()
        write('    // Ignore the structures added to the pnext chain by the loader.', file=self.outFile)
        write('    if ((header != nullptr) &&', file=self.outFile)
        write('        (header->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) &&', file=self.outFile)
        write('        (header->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch (header->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            // TODO: Write metadata message with unrecongized sType?', file=self.outFile)
        write('            break;', file=self.outFile)

    # Method override
    def endFile(self):
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if (result == 0)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        // pNext was either NULL, an ignored loader specific struct, or was unrecongized and no data was written.', file=self.outFile)
        write('        // Write an encoding for a NULL pointer.', file=self.outFile)
        write('        result = encoder->EncodeStructPtrPreamble(nullptr);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return result;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    # Method override
    def genStruct(self, typeinfo, typename, alias):
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        # Ignore the "base" structures
        if (typename not in self.STRUCT_BLACKLIST) and not alias:
            sType = self.makeStructureTypeEnum(typeinfo, typename)
            if sType:
                self.sTypeValues[typename] = sType

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.sTypeValues:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        for struct in self.sTypeValues:
            write('        case {}:'.format(self.sTypeValues[struct]), file=self.outFile)
            write('            result = encode_struct_ptr(encoder, reinterpret_cast<const {}*>(value));'.format(struct), file=self.outFile)
            write('            break;', file=self.outFile)
        self.sTypeValues = dict()
