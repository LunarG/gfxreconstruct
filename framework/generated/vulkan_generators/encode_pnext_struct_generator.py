#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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


# Eliminates JSON blackLists and platformTypes files, which are not necessary for
# pNext switch statement generation.
class EncodePNextStructGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API pNext structure encoding C++ code generation"""
    def __init__(self,
                 filename=None,
                 directory='.',
                 prefixText='',
                 protectFile=False,
                 protectFeature=True,
                 extraVulkanHeaders=[]):
        BaseGeneratorOptions.__init__(self,
                                      None,
                                      None,
                                      filename,
                                      directory,
                                      prefixText,
                                      protectFile,
                                      protectFeature,
                                      extraVulkanHeaders=extraVulkanHeaders)


# EncodePNextStructGenerator - subclass of BaseGenerator.
# Generates C++ code for Vulkan API pNext structure encoding.
class EncodePNextStructGenerator(BaseGenerator):
    """Generate pNext structure encoding C++ code"""
    def __init__(self,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False,
                               processStructs=False,
                               featureBreak=False,
                               errFile=errFile,
                               warnFile=warnFile,
                               diagFile=diagFile)

        # Map to store VkStructureType enum values.
        self.sTypeValues = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_struct_encoders.h"',
              file=self.outFile)
        self.newline()
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "encode/trace_manager.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(genOpts)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        write('#include <cstdio>', file=self.outFile)
        write('#include <memory>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
        write(
            'void EncodePNextStruct(ParameterEncoder* encoder, const void* value)',
            file=self.outFile)
        write('{', file=self.outFile)
        write('    assert(encoder != nullptr);', file=self.outFile)
        self.newline()
        write(
            '    auto base = reinterpret_cast<const VkBaseInStructure*>(value);',
            file=self.outFile)
        self.newline()
        write(
            '    // Ignore the structures added to the pnext chain by the loader.',
            file=self.outFile)
        write(
            '    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||',
            file=self.outFile)
        write(
            '                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))',
            file=self.outFile)
        write('    {', file=self.outFile)
        write('        base = base->pNext;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if (base != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.',
            file=self.outFile)
        write(
            '                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);',
            file=self.outFile)
        write(
            '                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.',
            file=self.outFile)
        write(
            '                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);',
            file=self.outFile)
        write(
            '                TraceManager::Get()->WriteDisplayMessageCmd(message.get());',
            file=self.outFile)
        write('                GFXRECON_LOG_WARNING("%s", message.get());',
              file=self.outFile)
        write('                EncodePNextStruct(encoder, base->pNext);',
              file=self.outFile)
        write('            }', file=self.outFile)
        write('            break;', file=self.outFile)

    # Method override
    def endFile(self):
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('    else', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.',
            file=self.outFile)
        write('        encoder->EncodeStructPtrPreamble(nullptr);',
              file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    # Method override
    def genStruct(self, typeinfo, typename, alias):
        if not alias:
            # Only process struct types that specify a 'structextends' tag, which indicates the struct can be used in a pNext chain.
            parentStructs = typeinfo.elem.get('structextends')
            if parentStructs:
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
            write('        case {}:'.format(self.sTypeValues[struct]),
                  file=self.outFile)
            write(
                '            EncodeStructPtr(encoder, reinterpret_cast<const {}*>(base));'
                .format(struct),
                file=self.outFile)
            write('            break;', file=self.outFile)
        self.sTypeValues = dict()
