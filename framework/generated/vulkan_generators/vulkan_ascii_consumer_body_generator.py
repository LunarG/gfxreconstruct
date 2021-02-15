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

import os,re,sys
from base_generator import *


class VulkanAsciiConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to ASCII file generation."""

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


class VulkanAsciiConsumerBodyGenerator(BaseGenerator):
    """VulkanAsciiConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanAsciiConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file to ASCII file generation.
    """

    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

    def beginFile(self, genOpts):
        """Method override."""
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_ascii_consumer.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def needFeatureGeneration(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.featureCmdParams:
            return True
        return False

    def generateFeature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.getFilteredCmdNames():
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeConsumerFuncDecl(returnType, 'VulkanAsciiConsumer::Process_' + cmd, values) + '\n'
            cmddef += '{\n'
            cmddef += self.makeConsumerFuncBody(returnType, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    def makeConsumerFuncBody(self, returnType, name, values):
        """Return VulkanAsciiConsumer class member function definition."""
        body = '    fprintf(GetFile(), "%s\\n", "' + name + '");\n'
        return body
