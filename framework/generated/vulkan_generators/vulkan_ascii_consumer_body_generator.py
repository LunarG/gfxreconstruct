#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2022 LunarG, Inc.
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

import sys, inspect
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class VulkanAsciiConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to ASCII file generation."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanAsciiConsumerBodyGenerator(BaseGenerator):
    """VulkanAsciiConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanAsciiConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file to ASCII file generation.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # The following functions require custom implementations for to ASCII
        self.customImplementationRequired = {
            'vkAllocateCommandBuffers',
            'vkAllocateDescriptorSets',
            'vkCmdBuildAccelerationStructuresIndirectKHR',
            'vkCmdBuildAccelerationStructuresKHR',
            'vkGetAccelerationStructureBuildSizesKHR',
        }

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        includes = inspect.cleandoc(
            '''
            #include "generated/generated_vulkan_ascii_consumer.h"
            #include "decode/custom_vulkan_ascii_consumer.h"
            #include "util/custom_vulkan_to_string.h"
            #include "generated/generated_vulkan_enum_to_string.h"
            #include "generated/generated_vulkan_struct_to_string.h"
            #include "util/defines.h"
            '''
        )
        write(includes, file=self.outFile)
        self.includeVulkanHeaders(gen_opts)
        namespace = inspect.cleandoc(
            '''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            '''
        )
        write(namespace, file=self.outFile)

    def endFile(self):
        """Method override."""
        body = inspect.cleandoc(
            '''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
            '''
        )
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.get_filtered_cmd_names():
            if not cmd in self.customImplementationRequired:
                info = self.feature_cmd_params[cmd]
                return_type = info[0]
                values = info[2]

                cmddef = '' if first else '\n'
                cmddef += self.make_consumer_func_decl(
                    return_type, 'VulkanAsciiConsumer::Process_' + cmd, values
                ) + '\n'
                cmddef += inspect.cleandoc(
                    '''
                    {{
                        using namespace gfxrecon::util;
                        ToStringFlags toStringFlags = kToString_Default;
                        uint32_t tabCount = 0;
                        uint32_t tabSize = 4;
                        WriteApiCallToFile(toStringFlags, tabCount, tabSize,
                            [&](std::stringstream& strStrm)
                            {{
                                FieldToString(strStrm, true, "type", toStringFlags, tabCount, tabSize, "\\"vkCall\\"");
                                FieldToString(strStrm, false, "index", toStringFlags, tabCount, tabSize, std::to_string(call_info.index));
                                FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, "\\"{0}\\"");
                    '''.format(cmd)
                )
                cmddef += '\n'

                # Handle function return value
                if not 'void' in return_type:
                    cmddef += '            FieldToString(strStrm, false, "return", toStringFlags, tabCount, tabSize, \'"\' + ToString(returnValue, toStringFlags, tabCount, tabSize) + \'"\');\n'

                # Start a nested parameter block
                cmddef += '''            FieldToString(strStrm, false, "params", toStringFlags, tabCount, tabSize, "{\\n");\n'''

                # Fill in all the arguments in the parameter block
                cmddef += self.make_consumer_func_args(
                    values
                )

                # Close the nested parameter block and end the function body
                cmddef += inspect.cleandoc(
                    '''
                                strStrm << GetNewlineString(toStringFlags);
                                strStrm << GetTabString(toStringFlags, tabCount, tabSize);
                                strStrm << "}";

                            }
                        );
                    }
                    '''
                )
                write(cmddef, file=self.outFile)
                first = False

    # yapf: disable
    def make_consumer_func_args(self, values):
        """Return VulkanAsciiConsumer class member function argument block."""
        body = '            tabCount += 1;\n'
        firstField = 'true'
        # Handle function arguments
        for value in values:

            # Start with a static_assert() so that if any values make it through the logic
            #   below without being handled the generated code will fail to compile
            toString = 'static_assert(false, "Unhandled value in `vulkan_ascii_consumer_body_generator.py`")'

            # void data PointerDecoder requires custom handling
            if 'void' in value.full_type:
                toString = 'DataPointerDecoderToString({0})'

            # StringDecoder requires custom handling
            elif 'const char*' in value.full_type:
                toString = 'StringDecoderToString({0})'

            # Handle the majority of parameters: handles, structs, enums, and pointers to
            # them, arrays of them, and pointers to arrays of them
            elif value.is_pointer:
                if value.is_array:
                    if self.is_handle(value.base_type):
                        toString = 'HandlePointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_struct(value.base_type):
                        toString = 'PointerDecoderArrayToString(*{0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = 'EnumPointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'PointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.is_handle(value.base_type):
                        toString = 'HandlePointerDecoderToString({0})'
                    elif self.is_struct(value.base_type):
                        toString = 'PointerDecoderToString({0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = 'EnumPointerDecoderToString({0})'
                    else:
                        toString = 'PointerDecoderToString({0}, toStringFlags, tabCount, tabSize)'
            else:
                if value.is_array:
                    if self.is_handle(value.base_type):
                        toString = 'static_assert(false, "Unhandled static array of VkHandles in `vulkan_ascii_consumer_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        toString = 'static_assert(false, "Unhandled static array of VkStructures in `vulkan_ascii_consumer_body_generator.py`")'
                    elif self.is_enum(value.base_type):
                        toString = 'EnumPointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                    else:
                        toString = 'PointerDecoderArrayToString({1}, {0}, toStringFlags, tabCount, tabSize)'
                else:
                    if self.is_handle(value.base_type):
                        toString = 'HandleIdToString({0})'
                    elif self.is_struct(value.base_type):
                        # @note This never happens, as we don't pass structs into Vulkan by value.
                        toString = 'ToString({0}, toStringFlags, tabCount, tabSize)'
                    elif self.is_enum(value.base_type):
                        toString = '\'"\' + ToString({0}, toStringFlags, tabCount, tabSize) + \'"\''
                    else:
                        toString = 'ToString({0}, toStringFlags, tabCount, tabSize)'

            valueName = ('[out]' if self.is_output_parameter(value) else '') + value.name
            toString = toString.format(value.name, value.array_length)
            body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(firstField, valueName, toString)
            firstField = 'false'
        body += '            tabCount -= 1;\n'
        return body

    # yapf: enable
