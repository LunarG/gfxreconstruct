#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2021 LunarG, Inc.
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


class VulkanAsciiConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to ASCII file generation"""

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


# VulkanAsciiConsumerBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanAsciiConsumer class responsible for
# generating a textfile containing decoded Vulkan API call parameter data.
class VulkanAsciiConsumerBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file to ASCII file generation"""

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

        # The following functions require custom implementations for to ASCII
        self.customImplementationRequired = {
            'vkAllocateCommandBuffers',
            'vkAllocateDescriptorSets',
            'vkCmdBuildAccelerationStructuresIndirectKHR',
            'vkCmdBuildAccelerationStructuresKHR',
            'vkGetAccelerationStructureBuildSizesKHR',
        }

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = inspect.cleandoc(
            '''
            #include "generated/generated_vulkan_ascii_consumer.h"
            #include "decode/custom_vulkan_ascii_consumer.h"
            #include "decode/custom_vulkan_to_string.h"
            #include "generated/generated_vulkan_enum_to_string.h"
            #include "generated/generated_vulkan_struct_to_string.h"
            #include "util/defines.h"

            #include "vulkan/vulkan.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            '''
        )
        write(body, file=self.outFile)

    # Method override
    def endFile(self):
        body = inspect.cleandoc(
            '''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
            '''
        )
        write(body, file=self.outFile)

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
            if not cmd in self.customImplementationRequired:
                info = self.featureCmdParams[cmd]
                returnType = info[0]
                values = info[2]

                cmddef = '' if first else '\n'
                cmddef += self.makeConsumerFuncDecl(
                    returnType, 'VulkanAsciiConsumer::Process_' + cmd, values
                ) + '\n'
                cmddef += inspect.cleandoc(
                    '''
                    {{
                        using namespace gfxrecon::util;
                        ToStringFlags toStringFlags = kToString_Default;
                        uint32_t tabCount = 0;
                        uint32_t tabSize = 4;
                        WriteApiCallToFile("{0}", toStringFlags, tabCount, tabSize,
                            [&](std::stringstream& strStrm)
                            {{
                    '''.format(cmd)
                )
                cmddef += '\n'
                cmddef += self.makeConsumerFuncBody(returnType, cmd, values)
                cmddef += inspect.cleandoc(
                    '''
                            }
                        );
                    }
                    '''
                )
                write(cmddef, file=self.outFile)
                first = False

    #
    # Return VulkanAsciiConsumer class member function definition.
    def makeConsumerFuncBody(self, returnType, name, values):
        body = ''

        # Handle function return value
        if not 'void' in returnType:
            body = '            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, \'"\' + ToString(returnValue, toStringFlags, tabCount, tabSize) + \'"\');\n'

        # Handle function arguments
        for value in values:

            # Start with a static_assert() so that if any values make it through the logic
            #   below without being handled the generated code will fail to compile
            toString = 'static_assert(false, "Unhandled value in `vulkan_ascii_consumer_body_generator.py`")'

            # void data PointerDecoder requires custom handling
            if 'void' in value.fullType:
                toString = 'DataPointerDecoderToString({0})'

            # StringDecoder requires custom handling
            elif 'const char*' in value.fullType:
                toString = 'StringDecoderToString({0})'

            # There's some repeated code in this if/else block...It's easier (imo) to reason
            #   about each case when they're all listed explictly
            elif value.isPointer:
                if value.isArray:
                    if self.isHandle(value.baseType):
                        toString = 'HandlePointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    elif self.isStruct(value.baseType):
                        toString = 'PointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = 'EnumPointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'PointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.isHandle(value.baseType):
                        toString = 'HandlePointerDecoderToString({0})'
                    elif self.isStruct(value.baseType):
                        toString = 'PointerDecoderToString({0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = 'EnumPointerDecoderToString({0})'
                    else:
                        toString = 'PointerDecoderToString({0}, toStringFlags, tabCount, tabSize)'
            else:
                if value.isArray:
                    if self.isHandle(value.baseType):
                        toString = 'static_assert(false, "Unhandled static array of VkHandles in `vulkan_ascii_consumer_body_generator.py`")'
                    elif self.isStruct(value.baseType):
                        toString = 'static_assert(false, "Unhandled static array of VkStructures in `vulkan_ascii_consumer_body_generator.py`")'
                    elif self.isEnum(value.baseType):
                        toString = 'EnumPointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'PointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.isHandle(value.baseType):
                        toString = 'HandleIdToString({0})'
                    elif self.isStruct(value.baseType):
                        toString = 'ToString({0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = '\'"\' + ToString({0}, toStringFlags, tabCount, tabSize) + \'"\''
                    else:
                        toString = 'ToString({0}, toStringFlags, tabCount, tabSize)'

            firstField = 'true' if not body else 'false'
            valueName = (
                '[out]' if self.isOutputParameter(value) else ''
            ) + value.name
            toString = toString.format(value.name, value.arrayLength)
            body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(
                firstField, valueName, toString
            )
        return body
