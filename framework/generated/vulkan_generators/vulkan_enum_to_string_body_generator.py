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
        protectFeature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platformTypes,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraVulkanHeaders=extraVulkanHeaders
        )


# VulkanEnumToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API enums.
class VulkanEnumToStringBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan ToString() functions"""

    # TODO: VkFlags64's enum need a diffferent way to print
    SKIP_ENUM = [
        "VkFormatFeatureFlagBits2", "VkAccessFlagBits2",
        "VkPipelineStageFlagBits2"
    ]

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Set of enums that have been processed since we'll encounter enums that are
        #   referenced by extensions multiple times.  This list is prepopulated with
        #   enums that should be skipped.
        self.processedEnums = {
            'VkAccessFlagBits2KHR',
            'VkPipelineStageFlagBits2KHR',
        }

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = inspect.cleandoc('''
            #include "generated_vulkan_enum_to_string.h"
            #include "decode/custom_vulkan_to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
            ''')
        write(body, file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        body = inspect.cleandoc('''
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)
            ''')
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        self.feature_break = False
        if self.feature_struct_members:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generate_feature(self):
        for enum in sorted(self.enum_names):
            if not enum in self.processedEnums and not enum in self.enumAliases and not enum in self.SKIP_ENUM:
                self.processedEnums.add(enum)
                body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags, uint32_t, uint32_t)\n'
                body += '{{\n'
                if len(self.enumEnumerants[enum]):
                    body += '    switch (value) {{\n'
                    for enumerant in self.enumEnumerants[enum]:
                        body += '    case {0}: return "{0}";\n'.format(enumerant)
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
    # yapf: enable
