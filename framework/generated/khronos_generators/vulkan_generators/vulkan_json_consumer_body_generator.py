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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_json_consumer_body_generator import KhronosExportJsonConsumerBodyGenerator
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class VulkanExportJsonConsumerBodyGeneratorOptions(VulkanBaseGeneratorOptions, KhronosExportJsonConsumerBodyGenerator):
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


class VulkanExportJsonConsumerBodyGenerator(VulkanBaseGenerator, KhronosExportJsonConsumerBodyGenerator):
    """VulkanExportJsonConsumerBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member definitions for the VulkanExportJsonConsumer class responsible for
    generating a textfile containing decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file to JSON file generation.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
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

    def beginFile(self, gen_opts):
        """Method override."""
        VulkanBaseGenerator.beginFile(self, gen_opts)

        includes = format_cpp_code('''
            #include "util/defines.h"
            #include "generated/generated_vulkan_json_consumer.h"
            #include "decode/custom_vulkan_struct_to_json.h"
        ''')
        write(includes, file=self.outFile)
        self.write_includes_of_common_api_headers(gen_opts)
        namespace = remove_trailing_newlines(indent_cpp_code('''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)

        '''))
        write(namespace, file=self.outFile)

    def endFile(self):
        """Method override."""
        # TODO: Each code generator is passed a blacklist like framework\generated\vulkan_generators\blacklists.json
        # of functions and structures not to generate code for. Once the feature is implemented, the following can be
        # replaced with adding vkCreateRayTracingPipelinesKHR in corresponding blacklist.
        if 'vkCreateRayTracingPipelinesKHR' in self.APICALL_BLACKLIST:
            self.APICALL_BLACKLIST.remove('vkCreateRayTracingPipelinesKHR')

        KhronosExportJsonConsumerBodyGenerator.generate_json_content(self)

        body = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        ''')
        write(body, file=self.outFile)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def is_command_buffer_cmd(self, command):
        if 'vkCmd' in command:
            return True
        return False

    def skip_generating_command_json(self, command):
        """Method override"""
        return command in self.customImplementationRequired

    def decode_as_handle(self, value):
        """Method override
        Indicates that the given type should be decoded as a handle."""
        return (
            (
                self.is_handle_like(value.base_type)
                or value.name in self.formatAsHandle
            )
        )

    def decode_as_hex(self, value):
        """Method override"""
        return value.base_type in self.formatAsHex

    # yapf: disable
    def make_consumer_func_body(self, return_type, name, values):
        """Return class member function definition."""
        body = ''

        if name in self.queueSubmit:
            body += '    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options);\n'
        elif self.is_command_buffer_cmd(name):
            body += '    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options);\n'

        body += KhronosExportJsonConsumerBodyGenerator.make_consumer_func_body(self, return_type, name, values)
        return body
    # yapf: enable
