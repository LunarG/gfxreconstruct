#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2022 LunarG, Inc.
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

class VulkanStructToStringBodyGeneratorOptions(BaseGeneratorOptions):
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


# VulkanStructToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying Vulkan API structures.
class VulkanStructToStringBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan ToString() functions"""

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
            #include "util/custom_vulkan_to_string.h"
            #include "generated_vulkan_struct_to_string.h"
            #include "generated_vulkan_enum_to_string.h"
            #include "decode/custom_vulkan_ascii_consumer.h"

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
        for struct in self.get_filtered_struct_names():
            if not struct in self.customImplementationRequired:
                body = inspect.cleandoc('''
                    template <> std::string ToString<{0}>(const {0}& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
                    {{
                        return ObjectToString(toStringFlags, tabCount, tabSize,
                            [&](std::stringstream& strStrm)
                            {{
                    '''.format(struct))
                body += '\n'
                body += self.makeStructBody(struct, self.feature_struct_members[struct])
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

        # If the struct has a member which is a handle represented as a uint64_t,
        # remember the name of that member:
        cloakedHandleName = 'NO_MATCH'
        if name in self.GENERIC_HANDLE_STRUCTS:
            for key in self.GENERIC_HANDLE_STRUCTS[name].keys():
                cloakedHandleName = key

        for value in values:
            length_expr = ''
            array_dimension = ''

            # Start with a static_assert() so that if any values make it through the logic
            #   below without being handled the generated code will fail to compile
            toString = 'static_assert(false, "Unhandled value in `vulkan_struct_to_string_body_generator.py`")'

            # pNext requires custom handling
            if 'pNext' in value.name:
                toString = 'PNextToString(obj.pNext, toStringFlags, tabCount, tabSize)'

            # Function pointers and void data pointers simply write the address
            elif 'pfn' in value.name or 'void' in value.full_type:
                toString = 'Quote(PtrToString(obj.{0}))'

            # C strings require custom handling
            elif 'const char*' in value.full_type:
                if 'const char* const*' in value.full_type:
                    toString = 'CStrArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    toString = 'CStrToString(obj.{0})'

            # A handle represented as a uint64_t
            elif cloakedHandleName == value.name:
                toString = 'decode::HandleIdToString(obj.{0})'

            # There's some repeated code in this if/else block...for instance, arrays of
            #   structs, enums, and primitives all route through ArrayToString()...It's
            #   easier (imo) to reason about each case when they're all listed explictly
            elif value.is_pointer:
                if value.is_array:
                    if self.is_handle(value.base_type):
                        toString = 'VkHandleArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_struct(value.base_type):
                        if value.pointer_count > 1:
                            toString = 'Array{}DToString'.format(value.pointer_count)
                            toString += '({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                            length_list = self.make_array2d_length_expression(value, values, 'obj.')
                            first = True
                            for len in length_list:
                                if first == False:
                                    length_expr += ', '
                                else:
                                    first = False
                                length_expr += len
                        else:
                            toString = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = 'VkEnumArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.is_handle(value.base_type):
                        toString = 'static_assert(false, "Unhandled pointer to VkHandle in `vulkan_struct_to_string_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        toString = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
                    elif self.is_enum(value.base_type):
                        toString = 'static_assert(false, "Unhandled pointer to VkEnum in `vulkan_struct_to_string_body_generator.py`")'
                    else:
                        toString = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
            else:
                if value.is_array:
                    if value.array_dimension > 1:
                        array_dimension =  str(value.array_dimension) + 'DMatrix'
                    if self.is_handle(value.base_type):
                        toString = 'VkHandleArray{3}ToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_struct(value.base_type):
                        toString = 'Array{3}ToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = 'Array{3}ToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif 'char' in value.base_type:
                        toString = 'CStr{3}ToString(obj.{0})'
                    elif 'UUID' in value.array_length or 'LUID' in value.array_length:
                        toString = 'Quote{3}(UIDToString({1}, obj.{0}))'
                    else:
                        toString = 'Array{3}ToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.is_handle(value.base_type):
                        toString = 'Quote(VkHandleToString(obj.{0}))'
                    elif self.is_struct(value.base_type):
                        toString = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = 'Quote(ToString(obj.{0}, toStringFlags, tabCount, tabSize))'
                    # Some simple scalar data like an int or a float, or a 32 bit or 64 bit flag set typedef:
                    else:
                        # Check whether we have a set of 64 bit flags:
                        if self.is_64bit_flags(value.base_type):
                            # Synthesize the name of the function to call for this set of flags:
                            toString = 'Quote({2}ToString(obj.{0}))'
                        # ToDo: if self.is_32bit_flags(enum): dispatch the correct call to fix Issue #620
                        else:
                            toString = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'

            firstField = 'true' if not body else 'false'

            if length_expr == '':
                length_expr = self.make_array_length_expression(value, 'obj.')
            if length_expr and ('value' in length_expr):
                length_expr.replace('value', 'obj')
            
            toString = toString.format(value.name, length_expr, value.base_type, array_dimension)
            body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(firstField, value.name, toString)
        return body
    # yapf: enable
