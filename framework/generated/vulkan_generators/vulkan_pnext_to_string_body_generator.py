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


class VulkanPNextToStringBodyGeneratorOptions(BaseGeneratorOptions):
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


# VulkanPNextToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API structures.
class VulkanPNextToStringBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan ToString() functions"""
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

        # Map to store VkStructureType enum values
        self.sTypeValues = dict()

    # Method override
    def endFile(self):
        body = inspect.cleandoc('''
        #include "decode/custom_vulkan_to_string.h"
        #include "generated_vulkan_struct_to_string.h"

        GFXRECON_BEGIN_NAMESPACE(gfxrecon)
        GFXRECON_BEGIN_NAMESPACE(util)

        std::string PNextToString(const void* pNext, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
        {
            if (pNext)
            {
                switch (reinterpret_cast<const VkBaseInStructure*>(pNext)->sType)
                {
        ''')
        body += '\n'
        for struct in self.sTypeValues:
            body += '        case {0}:\n'.format(self.sTypeValues[struct])
            body += '            return ToString(*reinterpret_cast<const {0}*>(pNext), toStringFlags, tabCount, tabSize);\n'.format(
                struct)
        body += inspect.cleandoc('''
                default: break;
                }
            }
            return "null";
        }

        GFXRECON_END_NAMESPACE(util)
        GFXRECON_END_NAMESPACE(gfxrecon)
        ''')
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    # Method override
    def genStruct(self, typeinfo, typename, alias):
        if not alias:
            # Only process struct types that specify a 'structextends' tag, which indicates the struct can be used in a pNext chain.
            if typeinfo.elem.get('structextends'):
                sType = self.makeStructureTypeEnum(typeinfo, typename)
                if sType:
                    self.sTypeValues[typename] = sType

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        self.featureBreak = False
        if self.featureStructMembers:
            return True
        return False
