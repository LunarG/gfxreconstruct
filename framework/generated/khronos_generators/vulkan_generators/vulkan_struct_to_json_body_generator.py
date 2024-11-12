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
from base_generator import *
from reformat_code import format_cpp_code, indent_cpp_code, remove_leading_empty_lines, remove_trailing_newlines


class VulkanStructToJsonBodyGeneratorOptions(BaseGeneratorOptions):
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
        BaseGeneratorOptions.__init__(
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


# VulkanStructToJsonBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for serializing Vulkan API structures to JSON.
class VulkanStructToJsonBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan FieldToJson(...) functions"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
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

        # Fields using this name should be output as handles even though they are uint64_t
        self.formatAsHandle = {
            'objectHandle',
        }

        # Struct types here do not have decoded fields.
        self.notDecoded = {
            'VkDeviceMemoryReportCallbackDataEXT',
        }

    def shouldDecodeStruct(self, struct):
        """Method indended to be overridden.
        Indicates that the provided struct is a struct we want to decode"""
        return not struct in self.customImplementationRequired

    def decodeAsHandle(self, parent_type, member):
        """Method indended to be overridden.
        Indicates that the given type should be decoded as a handle."""
        return (
            (
                self.is_handle(member.base_type)
                or member.name in self.formatAsHandle
            ) and not (parent_type in self.notDecoded)
        )

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = format_cpp_code('''
            #include "generated_vulkan_struct_to_json.h"
            #include "generated_vulkan_enum_to_json.h"
            #include "util/to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
        ''')
        write(body, file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.writeBodyContents()
        self.newline()

        body = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
            ''')
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    def writeBodyContents(self):
        write('using util::JsonOptions;', file=self.outFile)
        write('using util::to_hex_variable_width;', file=self.outFile)
        write('using util::uuid_to_string;', file=self.outFile)
        self.newline()

        for struct in self.get_all_filtered_struct_names():
            if self.shouldDecodeStruct(struct):
                body = '''
                    void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const JsonOptions& options)
                    {{
                        if (data && data->decoded_value)
                        {{
                            const {0}& decoded_value = *data->decoded_value;
                            const Decoded_{0}& meta_struct = *data;

                    '''.format(struct)
                body += self.makeStructBody(struct, self.all_struct_members[struct])
                body += remove_leading_empty_lines('''
                        }
                    }
                    ''')
                body = remove_trailing_newlines(indent_cpp_code(body))
                write(body, file=self.outFile)

        body = '''
            void FieldToJson(nlohmann::ordered_json& jdata, const PNextNode* data, const JsonOptions& options)
            {
                if (data && data->GetPointer())
                {
                    const auto s_type = reinterpret_cast<const VkBaseInStructure*>(data->GetPointer())->sType;
                    switch (s_type)
                    {'''
        body += self.make_pnext_body()
        body += '''
                        default:
                        {
                            GFXRECON_LOG_WARNING("Unknown pnext node type: %u.", (unsigned) s_type);
                        }
                    }
                }
            }
        '''
        body = remove_trailing_newlines(indent_cpp_code(body))
        write(body, file=self.outFile)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_struct_members:
            return True
        return False

    #
    # Command definition
    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        has_pnext = False
        for value in values:
            type_name = self.make_decoded_param_type(value)
            flagsEnumType = value.base_type

            if value.name == 'pNext':
                # move pnext to be the last member
                has_pnext = True
                continue

            # Default to getting the data from the native Vulkan struct:
            to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'

            if 'pfn' in value.name or 'pUserData' in value.name:
                to_json = 'FieldToJson(jdata["{0}"], to_hex_variable_width(meta_struct.{0}), options)'
            elif value.is_pointer:
                if 'String' in type_name:
                    to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                elif self.is_handle(value.base_type):
                    to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                else:
                    to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
            else:
                if value.is_array:
                    if 'UUID' in value.array_length or 'LUID' in value.array_length:
                        to_json = 'FieldToJson(jdata["{0}"], uuid_to_string(sizeof(decoded_value.{0}), decoded_value.{0}), options)'
                    elif 'String' in type_name:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_handle(value.base_type):
                        to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_struct(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif not value.is_dynamic:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    else:
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                else:
                    if self.decodeAsHandle(name, value):
                        to_json = 'HandleToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif value.base_type in self.formatAsHex:
                        to_json = 'FieldToJson(jdata["{0}"], to_hex_variable_width(decoded_value.{0}), options)'
                    elif self.is_struct(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif self.is_flags(value.base_type):
                        if value.base_type in self.flags_type_aliases:
                            flagsEnumType = self.flags_type_aliases[value.base_type]
                        to_json = 'FieldToJson({2}_t(),jdata["{0}"], decoded_value.{0}, options)'
                    elif self.is_enum(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'
                    elif 'VkBool32' == value.base_type:
                        to_json = 'jdata["{0}"] = static_cast<bool>(decoded_value.{0})'

            to_json = to_json.format(value.name, value.base_type, flagsEnumType)
            body += '        {0};\n'.format(to_json)
        # Save pnext as last member
        if has_pnext:
            body += '        FieldToJson(jdata["pNext"], meta_struct.pNext, options);\n'

        return body
    # yapf: enable

    def make_pnext_body(self):
        body = ''
        for struct in self.all_extended_structs:
            if struct not in self.struct_type_names:
                continue
            body += '''
            case {1}:
            {{
               const auto* pnext = reinterpret_cast<const Decoded_{0}*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }}
            '''.format(struct, self.struct_type_names[struct])
        return body
