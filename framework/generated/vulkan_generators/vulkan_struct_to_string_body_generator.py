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

import os,re,sys,inspect
from base_generator import *

class VulkanStructToStringBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan ToString() functions"""
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

# VulkanStructToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API structures.
class VulkanStructToStringBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan ToString() functions"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=False, processStructs=True, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

        # The following structures require custom implementations for ToString()
        self.customImplementationRequired = {
            'VkAccelerationStructureBuildGeometryInfoKHR',
            'VkAccelerationStructureVersionInfoKHR',
            'VkPhysicalDeviceMemoryProperties',
            'VkPipelineExecutableStatisticKHR',
            'VkPipelineMultisampleStateCreateInfo',
            'VkShaderModuleCreateInfo',
            'VkTransformMatrixKHR',
        }

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = inspect.cleandoc('''
            #include "decode/custom_vulkan_to_string.h"
            #include "generated_vulkan_struct_to_string.h"
            #include "generated_vulkan_enum_to_string.h"

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
    def needFeatureGeneration(self):
        self.featureBreak = False
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        for struct in self.getFilteredStructNames():
            if not struct in self.customImplementationRequired:
                body = inspect.cleandoc('''
                    template <> std::string ToString<{0}>(const {0}& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
                    {{
                        return ObjectToString(toStringFlags, tabCount, tabSize,
                            [&](std::stringstream& strStrm)
                            {{
                    '''.format(struct))
                body += '\n'
                body += self.makeStructBody(struct, self.featureStructMembers[struct])
                body += inspect.cleandoc('''
                            }
                        );
                    }
                    ''')
                body += '\n'
                write(body, file=self.outFile)
    # yapf: enable

    #
    # Command definition
    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        for value in values:

            # Start with a static_assert() so that if any values make it through the logic
            #   below without being handled the generated code will fail to compile
            toString = 'static_assert(false, "Unhandled value in `vulkan_struct_to_string_body_generator.py`")'

            # pNext requires custom handling
            if 'pNext' in value.name:
                toString = 'PNextToString(obj.pNext, toStringFlags, tabCount, tabSize)'

            # Function pointers and void data pointers simply write the address
            elif 'pfn' in value.name or 'void' in value.fullType:
                toString = '"\\"" + PtrToString(obj.{0}) + "\\""'

            # C strings require custom handling
            elif 'const char*' in value.fullType:
                if 'const char* const*' in value.fullType:
                    toString = 'CStrArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    toString = '(obj.{0} ? ("\\"" + std::string(obj.{0}) + "\\"") : "null")'

            # There's some repeated code in this if/else block...for instance, arrays of
            #   structs, enums, and primitives all route through ArrayToString()...It's
            #   easier (imo) to reason about each case when they're all listed explictly
            elif value.isPointer:
                if value.isArray:
                    if self.isHandle(value.baseType):
                        toString = 'VkHandleArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.isStruct(value.baseType):
                        toString = 'ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = 'VkEnumArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.isHandle(value.baseType):
                        toString = 'static_assert(false, "Unhandled pointer to VkHandle in `vulkan_struct_to_string_body_generator.py`")'
                    elif self.isStruct(value.baseType):
                        toString = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
                    elif self.isEnum(value.baseType):
                        toString = 'static_assert(false, "Unhandled pointer to VkEnum in `vulkan_struct_to_string_body_generator.py`")'
                    else:
                        toString = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
            else:
                if value.isArray:
                    if self.isHandle(value.baseType):
                        toString = 'VkHandleArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.isStruct(value.baseType):
                        toString = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif 'char' in value.baseType:
                        toString = '\'"\' + std::string(obj.{0}) + \'"\''
                    elif 'UUID' in value.arrayLength or 'LUID' in value.arrayLength:
                        toString = '\'"\' + UIDToString({1}, obj.{0}) + \'"\''
                    else:
                        toString = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.isHandle(value.baseType):
                        toString = '\'"\' + VkHandleToString(obj.{0}) + \'"\''
                    elif self.isStruct(value.baseType):
                        toString = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.isEnum(value.baseType):
                        toString = '\'"\' + ToString(obj.{0}, toStringFlags, tabCount, tabSize) + \'"\''
                    else:
                        toString = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'

            firstField = 'true' if not body else 'false'
            toString = toString.format(value.name, value.arrayLength)
            body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(firstField, value.name, toString)
        return body
    # yapf: enable
