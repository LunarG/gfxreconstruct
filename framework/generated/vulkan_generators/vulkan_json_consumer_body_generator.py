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

import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from collections import OrderedDict
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class VulkanExportJsonConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to JSON file generation."""

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


class VulkanExportJsonConsumerBodyGenerator(BaseGenerator):
    """VulkanExportJsonConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanExportJsonConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file to JSON file generation.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        self.customImplementationRequired = {
            'vkCmdBuildAccelerationStructuresIndirectKHR',
            'vkCmdPushConstants',
            'vkCreatePipelineCache',
            'vkCreateShaderModule',
            'vkGetPipelineCacheData',
        }

        self.formatAsHex = {
            'VkDeviceAddress',
        }

        # Parameters using this name should be output as handles even though they are uint64_t
        self.formatAsHandle = {
            'objectHandle',
        }

        self.queueSubmit = {
            "vkQueueSubmit",
            "vkQueueSubmit2",
            "vkQueuePresentKHR",
            "vkQueueSubmit2KHR",
            }


        self.flagsType = dict()
        self.flagsTypeAlias = dict()
        self.flagEnumBitsType = dict()

        self.cmd_names = []
        self.cmd_info = OrderedDict()
        self.all_structs = list()         # List of all struct names
        self.all_struct_members = OrderedDict()  # Map of all struct names to lists of per-member ValueInfo
        self.all_struct_aliases = OrderedDict()  # Map of all struct aliases

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        includes = format_cpp_code('''
            #include "util/defines.h"
            #include "generated/generated_vulkan_json_consumer.h"
            #include "decode/custom_vulkan_struct_to_json.h"
        ''')
        write(includes, file=self.outFile)
        self.includeVulkanHeaders(gen_opts)
        namespace = remove_trailing_newlines(indent_cpp_code('''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)

            using util::JsonOptions;
        '''))
        write(namespace, file=self.outFile)

    def endFile(self):
        """Method override."""
        first = True
        self.newline()
        for cmd in self.cmd_names:
            info = self.cmd_info[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_consumer_func_decl(
                return_type, 'VulkanExportJsonConsumer::Process_' + cmd, values
            ) + '\n'
            cmddef += format_cpp_code(
                '''
                {{
                    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "{0}");
                    const JsonOptions& json_options = GetJsonOptions();
                '''.format(cmd)
            )
            cmddef += '\n'
            cmddef += self.make_consumer_func_body(return_type, cmd, values)
            cmddef += format_cpp_code(
                '''
                    WriteBlockEnd();
                }
            ''', 1
            )
            write(cmddef, file=self.outFile)
            first = False

        body = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        ''')
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

        # TODO: Each code generator is passed a blacklist like framework\generated\vulkan_generators\blacklists.json
        # of functions and structures not to generate code for. Once the feature is implemented, the following can be
        # replaced with adding vkCreateRayTracingPipelinesKHR in corresponding blacklist.
        if 'vkCreateRayTracingPipelinesKHR' in self.APICALL_BLACKLIST:
            self.APICALL_BLACKLIST.remove('vkCreateRayTracingPipelinesKHR')

        for cmd in self.get_filtered_cmd_names():
            if cmd in self.customImplementationRequired:
                continue
            self.cmd_names.append(cmd)
            self.cmd_info[cmd] = self.feature_cmd_params[cmd]

        for struct in self.get_filtered_struct_names():
            self.all_structs.append(struct)
            self.all_struct_members[struct] = self.feature_struct_members[struct]

    def is_command_buffer_cmd(self, command):
        if 'vkCmd' in command:
            return True
        return False

    # yapf: disable
    def make_consumer_func_body(self, return_type, name, values):
        """Return VulkanExportJsonConsumer class member function definition."""
        body = ''

        if name in self.queueSubmit:
            body += '    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);\n'
        elif self.is_command_buffer_cmd(name):
            body += '    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);\n'

        # Handle function return value
        if return_type in self.formatAsHex:
            body += '    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options);\n'
        elif 'VkBool32' == return_type:
            # Output as JSON boolean type true/false without quotes:
            body += '            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);\n'
        elif self.is_handle(return_type):
            body += '    HandleToJson(jdata[NameReturn()], returnValue, json_options);\n'
        # Enums, ints, etc. handled by default and static dispatch based on C++ type:
        elif not 'void' in return_type:
            body += '    FieldToJson(jdata[NameReturn()], returnValue, json_options);\n'

        if len(values) > 0:
            body += '    auto& args = jdata[NameArgs()];\n'
            # Handle function arguments
            for value in values:
                flagsEnumType = value.base_type

                # Default to letting the right function overload to be resolved based on argument types,
                # including enums, strings ints, floats etc.:
                # Note there are overloads for scalars and pointers/arrays.
                to_json = 'FieldToJson(args["{0}"], {0}, json_options)'

                # Special cases:
                if 'VkBool32' == value.base_type:
                    to_json = 'Bool32ToJson(args["{0}"], {0}, json_options)'
                elif value.name == 'ppData' or (value.base_type in self.formatAsHex):
                    to_json = 'FieldToJsonAsHex(args["{0}"], {0}, json_options)'
                elif self.is_handle(value.base_type) or value.name in self.formatAsHandle:
                    to_json = 'HandleToJson(args["{0}"], {0}, json_options)'
                elif self.is_flags(value.base_type):
                    if value.base_type in self.flagsTypeAlias:
                            flagsEnumType = self.flagsTypeAlias[value.base_type]
                    if not (value.is_pointer or value.is_array):
                        to_json = 'FieldToJson({2}_t(), args["{0}"], {0}, json_options)'
                    else:
                        # Default to outputting as the raw type but warn:
                        print("Missing conversion of pointers to", flagsEnumType, "in", name,  file=sys.stderr)

                to_json = to_json.format(value.name, value.base_type, flagsEnumType)
                body += '        {0};\n'.format(to_json)
        return body
    # yapf: enable

    def genType(self, typeinfo, name, alias):
        super().genType(typeinfo, name, alias)
        if self.is_flags(name):
            if alias is None:
                self.flagsType[name] = self.flags_types[name]
                bittype = typeinfo.elem.get('requires')
                if bittype is None:
                    bittype = typeinfo.elem.get('bitvalues')
                if bittype is not None:
                    self.flagEnumBitsType[bittype] = name
            else:
                self.flagsTypeAlias[name] = alias
