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


class VulkanDecoderHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class declaration for Vulkan API parameter decoding"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True
    ):
        BaseGeneratorOptions.__init__(
            self, blacklists, platformTypes, filename, directory, prefixText,
            protectFile, protectFeature
        )


# VulkanDecoderHeaderGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanDecoder class responsible for decoding
# Vulkan API call parameter data.
class VulkanDecoderHeaderGenerator(BaseGenerator):
    """Generate a C++ class declaration for Vulkan API parameter decoding"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=True,
            processStructs=False,
            featureBreak=True,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
        )

    # Method override
    # yapf: disable
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
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        first = True
        for cmd in self.getFilteredCmdNames():
            cmddef = '' if first else '\n'
            cmddef += '    size_t Decode_{}(const uint8_t* parameter_buffer, size_t buffer_size);'.format(cmd)
            write(cmddef, file=self.outFile)
            first = False
    # yapf: enable
