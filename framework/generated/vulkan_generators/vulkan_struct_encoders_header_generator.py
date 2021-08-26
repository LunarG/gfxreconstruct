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


class VulkanStructEncodersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for Vulkan struct encoding"""
    def __init__(
            self,
            blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
            platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
            filename=None,
            directory='.',
            prefixText='',
            protectFile=False,
            protectFeature=True,
            extraVulkanHeaders=[]):
        BaseGeneratorOptions.__init__(self,
                                      blacklists,
                                      platformTypes,
                                      filename,
                                      directory,
                                      prefixText,
                                      protectFile,
                                      protectFeature,
                                      extraVulkanHeaders=extraVulkanHeaders)


# VulkanStructEncodersHeaderGenerator - subclass of BaseGenerator.
# Generates C++ type and function declarations for encoding Vulkan API structures.
class VulkanStructEncodersHeaderGenerator(BaseGenerator):
    """Generate C++ function declarations for Vulkan struct encoding"""
    def __init__(self,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False,
                               processStructs=True,
                               featureBreak=True,
                               errFile=errFile,
                               warnFile=warnFile,
                               diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(genOpts)
        self.newline()
        write('#include <cstdint>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
        write(
            'void EncodePNextStruct(ParameterEncoder* encoder, const void* value);',
            file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

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
            write(
                'void EncodeStruct(ParameterEncoder* encoder, const {}& value);'
                .format(struct),
                file=self.outFile)
