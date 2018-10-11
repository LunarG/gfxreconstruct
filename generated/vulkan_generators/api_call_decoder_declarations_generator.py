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

class ApiCallDecoderDeclarationsGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API parameter decoding C++ code generation"""
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

# ApiCallDecoderDeclarationsGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanDecoder class responsible for decoding
# Vulkan API call parameter data.
class ApiCallDecoderDeclarationsGenerator(BaseGenerator):
    """Generate API parameter decoding C++ member declarations"""
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

        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/vulkan_decoder_base.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        write('BRIMSTONE_BEGIN_NAMESPACE(format)', file=self.outFile)
        self.newline()
        write('class VulkanDecoder : public VulkanDecoderBase', file=self.outFile)
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write('    VulkanDecoder() { }\n', file=self.outFile)
        write('    virtual ~VulkanDecoder() { }\n', file=self.outFile)
        write('    virtual void DecodeFunctionCall(ApiCallId             call_id,', file=self.outFile)
        write('                                    const ApiCallOptions& call_options,', file=self.outFile)
        write('                                    const uint8_t*        parameter_buffer,', file=self.outFile)
        write('                                    size_t                buffer_size) override;\n', file=self.outFile)
        write('  private:', end='', file=self.outFile)

    # Method override
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(format)', file=self.outFile)
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

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
        for cmd in self.featureCmdParams:
            cmddef = '' if first else '\n'
            cmddef += '    size_t Decode_{}(const uint8_t* parameter_buffer, size_t buffer_size);'.format(cmd)
            write(cmddef, file=self.outFile)
            first = False
