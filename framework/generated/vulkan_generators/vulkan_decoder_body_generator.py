#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
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

import os,re,sys
from base_decoder_body_generator import *

class VulkanDecoderBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan API parameter decoding"""
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

# VulkanDecoderBodyGenerator - subclass of BaseGenerator.
# Generates C++ member functions for the VulkanDecoder class responsible for decoding
# Vulkan API call parameter data.
class VulkanDecoderBodyGenerator(BaseDecoderBodyGenerator, BaseGenerator):
    """Generate a C++ class for Vulkan API parameter decoding"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # Names of all Vulkan commands processed by the generator.
        self.cmdNames = []

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/pnext_node.h"', file=self.outFile)
        write('#include "decode/pointer_decoder.h"', file=self.outFile)
        write('#include "decode/string_array_decoder.h"', file=self.outFile)
        write('#include "decode/string_decoder.h"', file=self.outFile)
        write('#include "decode/struct_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/value_decoder.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_decoder.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_decoders_forward.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include <cstddef>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        # Generate the VulkanDecoder::DecodeFunctionCall method for all of the commands processed by the generator.
        self.generateDecodeCases()
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
