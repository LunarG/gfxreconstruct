#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2023 LunarG, Inc.
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
#

import sys
from vulkan_base_generator import *
from khronos_struct_to_json_body_generator import KhronosStructToJsonBodyGenerator
from reformat_code import format_cpp_code, indent_cpp_code, remove_leading_empty_lines, remove_trailing_newlines


class VulkanStructToJsonBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ functions for serializing Vulkan structures to JSON"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )
        self.begin_end_file_data.specific_headers.extend((
            'generated_vulkan_struct_to_json.h',
            'generated_vulkan_enum_to_json.h',
            'util/to_string.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.begin_end_file_data.common_api_headers = []

# VulkanStructToJsonBodyGenerator - subclass of VulkanBaseGenerator.
# Generates C++ functions for serializing Vulkan API structures to JSON.
class VulkanStructToJsonBodyGenerator(VulkanBaseGenerator, KhronosStructToJsonBodyGenerator):
    """Generate C++ functions for Vulkan FieldToJson(...) functions"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # The following structures require custom implementations for FieldToJson()
        self.customImplementationRequired = {
            'VkPipelineCacheCreateInfo',
            'VkShaderModuleCreateInfo',
            'VkPipelineExecutableStatisticKHR',
        }

        self.formatAsHex = {
            'VkDeviceAddress',
        }

    def should_decode_struct(self, struct):
        """Method indended to be overridden.
        Indicates that the provided struct is a struct we want to decode"""
        return not struct in self.customImplementationRequired

    def write_base_out_to_json_func(self):
        entries = self.get_base_out_structure_type_info_list()

        body = '\n'
        body += 'void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBaseOutStructure* data)\n'
        body += '{\n'
        body += '    if (data && data->decoded_value)\n'
        body += '    {\n'
        body += '        const auto& decoded_value = *data->decoded_value;\n'
        body += '        switch (decoded_value.sType)\n'
        body += '        {\n'
        for child, struct_type in entries:
            body += '            case {}:\n'.format(struct_type)
            body += '                FieldToJson(jdata, reinterpret_cast<const Decoded_{}*>(data));\n'.format(child)
            body += '                return;\n'
        body += '            default:\n'
        body += '                break;\n'
        body += '        }\n'
        body += '\n'
        body += '        const auto& meta_struct = *data;\n'
        body += '        jdata["sType"] = decoded_value.sType;\n'
        body += '        FieldToJson(jdata["pNext"], meta_struct.pNext);\n'
        body += '    }\n'
        body += '}\n'
        write(body, file=self.outFile)

    # Method override
    def endFile(self):
        KhronosStructToJsonBodyGenerator.write_body_contents(self)
        self.write_base_out_to_json_func()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
