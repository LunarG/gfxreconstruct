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

class VulkanDecoderHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class declaration for Vulkan API parameter decoding"""
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

# VulkanDecoderHeaderGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanDecoder class responsible for decoding
# Vulkan API call parameter data.
class VulkanDecoderHeaderGenerator(BaseGenerator):
    """Generate a C++ class declaration for Vulkan API parameter decoding"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/vulkan_decoder_base.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write('class VulkanDecoder : public VulkanDecoderBase', file=self.outFile)
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write('    VulkanDecoder() { }\n', file=self.outFile)
        write('    virtual ~VulkanDecoder() override { }\n', file=self.outFile)
        write('    virtual void DecodeFunctionCall(format::ApiCallId             call_id,', file=self.outFile)
        write('                                    const ApiCallInfo&            call_info,', file=self.outFile)
        write('                                    const uint8_t*                parameter_buffer,', file=self.outFile)
        write('                                    size_t                        buffer_size) override;\n', file=self.outFile)
        write('  private:', end='', file=self.outFile)

    # Method override
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for cmd in self.getFilteredCmdNames():
            cmddef = '' if first else '\n'
            cmddef += '    size_t Decode_{}(const uint8_t* parameter_buffer, size_t buffer_size);'.format(cmd)
            write(cmddef, file=self.outFile)
            first = False
