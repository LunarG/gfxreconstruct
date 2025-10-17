#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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


class VulkanCommandBufferUtilHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

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
            'encode/vulkan_handle_wrappers.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))


class VulkanCommandBufferUtilHeaderGenerator(VulkanBaseGenerator):
    """VulkanCommandBufferUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
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


    def endFile(self):
        """Method override."""
        for cmd in self.get_all_filtered_cmd_names():
            wrapper_prefix = self.get_wrapper_prefix_from_command(cmd)
            info = self.all_cmd_params[cmd]
            values = info[2]

            if values and (len(values) >
                           1) and (values[0].base_type == 'VkCommandBuffer'):
                # Check for parameters with handle types, ignoring the first VkCommandBuffer parameter.
                handles = self.get_param_list_handles(values[1:])

                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'
                    cmddef += 'void Track{}Handles({}::CommandBufferWrapper* wrapper, {});'.format(
                        cmd[2:], wrapper_prefix, self.get_arg_list(handles)
                    )
                    write(cmddef, file=self.outFile)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)


    def get_arg_list(self, values):
        args = []
        for value in values:
            if value.array_length:
                args.append('uint32_t {}'.format(value.array_length))
            args.append('{} {}'.format(value.full_type, value.name))
        return ', '.join(self.make_unique_list(args))
