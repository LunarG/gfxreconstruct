#!/usr/bin/python3 -i
#
# Copyright (c) 2021 LunarG, Inc.
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

import os, re, sys, inspect
from base_generator import *


class VulkanEnumToStringBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan ToString() functions"""

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


# VulkanEnumToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API enums.
class VulkanEnumToStringBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan ToString() functions"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=False,
            processStructs=True,
            featureBreak=True,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
        )

        # Set of enums that have been processed since we'll encounter enums that are
        #   referenced by extensions multiple times.  This list is prepopulated with
        #   enums that should be skipped.
        self.processedEnums = {
            'VkAccessFlagBits2KHR',
            'VkPipelineStageFlagBits2KHR',
        }

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = inspect.cleandoc(
            '''
            #include "generated_vulkan_enum_to_string.h"
            #include "decode/custom_vulkan_to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
            '''
        )
        write(body, file=self.outFile)

    # Method override
    def endFile(self):
        body = inspect.cleandoc(
            '''
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)
            '''
        )
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        self.featureBreak = False
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        for enum in sorted(self.enumNames):
            if not enum in self.processedEnums and not enum in self.enumAliases:
                self.processedEnums.add(enum)
                body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags, uint32_t, uint32_t)\n'
                body += '{{\n'
                if len(self.enumEnumerants[enum]):
                    body += '    switch (value) {{\n'
                    for enumerant in self.enumEnumerants[enum]:
                        body += '    case {0}: return "{0}";\n'.format(
                            enumerant
                        )
                    body += '    default: break;\n'
                    body += '    }}\n'
                body += '    return "Unhandled {0}";\n'
                body += '}}\n'
                if 'Bits' in enum:
                    body += '\ntemplate <> std::string ToString<{0}>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)\n'
                    body += '{{\n'
                    body += '    return BitmaskToString<{0}>(vkFlags);\n'
                    body += '}}\n'
                write(body.format(enum), file=self.outFile)
