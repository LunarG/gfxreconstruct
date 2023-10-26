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
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class VulkanDRCommandBufferUtilHeaderGeneratorOptions(BaseGeneratorOptions):
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


class VulkanDRCommandBufferUtilHeaderGenerator(BaseGenerator):
    """VulkanDRCommandBufferUtilBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
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

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "encode/vulkan_handle_wrappers.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            values = info[2]
            drFuncExcludeList=['vkBeginCommandBuffer','vkResetCommandBuffer']
            if values and (values[0].base_type == 'VkCommandBuffer') and (cmd not in drFuncExcludeList):
                handles = self.get_param_list_handles(values[1:])

                #@@@Debug output for vkCmdSetBlendConstants
                if cmd == 'vkCmdSetBlendConstants':
                    write('//@@@Debug: cmd=',cmd, file=self.outFile)
                    write('//@@@Debug: info[0]='+info[0], file=self.outFile)  ### THIS IS return type
                    write('//@@@Debug: info[1]='+info[1], file=self.outFile)  ### This is proto  "<type> <entrypoint>"
                    for i in (0,1):
                        write('//@@@Debug: i='+str(i), file=self.outFile)
                        write('//@@@Debug: info[2][i].name='+info[2][i].name, file=self.outFile)  ## This is name of first arg
                        write('//@@@Debug: info[2][i].base_type='+info[2][i].base_type, file=self.outFile)
                        write('//@@@Debug: info[2][i].full_type='+info[2][i].full_type, file=self.outFile)
                        write('//@@@Debug: info[2][i].pointer_count='+str(info[2][i].pointer_count), file=self.outFile)
                        write('//@@@Debug: info[2][i].array_length='+str(info[2][i].array_length), file=self.outFile)
                        write('//@@@Debug: info[2][i].array_capacity='+str(info[2][i].array_capacity), file=self.outFile)
                        write('//@@@Debug: info[2][i].array_dimension='+str(info[2][i].array_dimension), file=self.outFile)
                        write('//@@@Debug: info[2][i].platform_base_type='+str(info[2][i].platform_base_type), file=self.outFile)
                        write('//@@@Debug: info[2][i].is_pointer='+str(info[2][i].is_pointer), file=self.outFile)
                        write('//@@@Debug: info[2][i].is_array='+str(info[2][i].is_array), file=self.outFile)
                        write('//@@@Debug: info[2][i].is_dynamic='+str(info[2][i].is_dynamic), file=self.outFile)
                        write('//@@@Debug: info[2][i].is_const='+str(info[2][i].is_const), file=self.outFile)
                return_type = info[0]
                write('//@@@Debug: return_type = '+return_type, file=self.outFile)
                
                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'
                    cmddef += 'void TrackDR{}Handles(VkCommandBuffer commandBuffer, {});'.format(
                        cmd[2:], self.get_arg_list(handles)
                    )
                    write(cmddef, file=self.outFile)


    def get_param_list_handles(self, values):
        """Create list of parameters that have handle types or are structs that contain handles."""
        handles = []
        for value in values:
            if self.is_handle(value.base_type):
                handles.append(value)
            elif self.is_struct(value.base_type) and (value.base_type in self.structs_with_handles):
                handles.append(value)
        return handles

    def get_arg_list(self, values):
        args = []
        for value in values:
            if value.array_length:
                args.append('uint32_t {}'.format(value.array_length))
            args.append('{} {}'.format(value.full_type, value.name))
        return ', '.join(self.make_unique_list(args))
