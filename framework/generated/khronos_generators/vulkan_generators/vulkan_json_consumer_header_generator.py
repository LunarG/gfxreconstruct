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

import sys, inspect
from vulkan_consumer_header_generator import VulkanConsumerHeaderGenerator, VulkanConsumerHeaderGeneratorOptions, write


class VulkanExportJsonConsumerHeaderGeneratorOptions(VulkanConsumerHeaderGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to JSON file generation."""

    def __init__(
        self,
        class_name,
        base_class_header,
        is_override,
        constructor_args='',
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanConsumerHeaderGeneratorOptions.__init__(
            self,
            class_name,
            base_class_header,
            is_override,
            constructor_args,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )


class VulkanExportJsonConsumerHeaderGenerator(VulkanConsumerHeaderGenerator):
    """VulkanExportJsonConsumerHeaderGenerator - subclass of BaseGenerator.
    Generate a C++ class for Vulkan capture file to JSON file generation.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanConsumerHeaderGenerator.__init__(
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

    def beginFile(self, gen_opts):
        VulkanConsumerHeaderGenerator.beginFile(self, gen_opts)

        # TODO: Each code generator is passed a blacklist like framework\generated\vulkan_generators\blacklists.json
        # of functions and structures not to generate code for. Once the feature is implemented, the following can be
        # replaced with adding vkCreateRayTracingPipelinesKHR in corresponding blacklist.
        if 'vkCreateRayTracingPipelinesKHR' in self.APICALL_BLACKLIST:
            self.APICALL_BLACKLIST.remove('vkCreateRayTracingPipelinesKHR')

    def output_header_contents(self):
        """Performs C++ code generation for the header contents."""
        for cmd in self.get_all_filtered_cmd_names():
            if cmd not in self.customImplementationRequired:
                info = self.all_cmd_params[cmd]
                return_type = info[0]
                values = info[2]

                decl = self.make_consumer_func_decl(
                    return_type, 'Process_' + cmd, values
                )

                cmddef = '\n'
                if self.genOpts.is_override:
                    cmddef += self.indent(
                        'virtual ' + decl + ' override;', self.INDENT_SIZE
                    )
                else:
                    cmddef += self.indent(
                        'virtual ' + decl + ' {}', self.INDENT_SIZE
                    )

                write(cmddef, file=self.outFile)
