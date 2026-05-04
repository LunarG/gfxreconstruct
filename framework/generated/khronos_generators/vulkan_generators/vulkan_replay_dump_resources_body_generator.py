#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
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

import json
import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_replay_consumer_body_generator import KhronosReplayConsumerBodyGenerator


class VulkanReplayDumpResourcesBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

    def __init__(
        self,
        dump_resources_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
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
        self.dump_resources_overrides = dump_resources_overrides

        self.begin_end_file_data.specific_headers.extend((
            'generated/generated_vulkan_replay_dump_resources.h',
            '',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.begin_end_file_data.common_api_headers = []


class VulkanReplayDumpResourcesBodyGenerator(
    KhronosReplayConsumerBodyGenerator, VulkanBaseGenerator
):
    """VulkanReplayDumpResourcesBodyGenerator - subclass of VulkanBaseGenerator.
    """

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    DUMP_RESOURCES_OVERRIDES = {}

    # Map of pool object types associating the pool type with the allocated type and the allocated type with the pool type.
    POOL_OBJECT_ASSOCIATIONS = {
        'VkCommandBuffer': 'VkCommandPool',
        'VkDescriptorSet': 'VkDescriptorPool',
        'VkCommandPool': 'VkCommandBuffer',
        'VkDescriptorPool': 'VkDescriptorSet'
    }

    NOT_SKIP_FUNCTIONS_OFFSCREEN = ['Create', 'Destroy', 'GetSwapchainImages', 'AcquireNextImage', 'QueuePresent']

    SKIP_FUNCTIONS_OFFSCREEN = ['Surface', 'Swapchain', 'Present']

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
        api_data = self.get_api_data()

        KhronosReplayConsumerBodyGenerator.generate_replay_consumer_content(self, api_data)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def make_consumer_func_body(self, api_data, return_type, name, values):
        """
        Method override.
        Return VulkanReplayConsumer class member function definition.
        """
        body = ''

        is_override = name in self.DUMP_RESOURCES_OVERRIDES
        is_transfer = name in self.DUMP_RESOURCES_TRANSFER_API_CALLS

        if not is_override:
            body += '    if (IsRecording())\n'
            body += '    {\n'
            body += '        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);\n'
            body += '        for (auto dc_context : dc_contexts)\n'
            body += '        {\n'
            body += '            CommandBufferIterator first, last;\n'
            body += '            dc_context->GetDrawCallActiveCommandBuffers(first, last);\n'
            body += '            for (CommandBufferIterator it = first; it < last; ++it)\n'
            body += '            {\n'

            dispatchfunc = 'func(*it, '

            call_expr = ''
            for val in values[1:]:
                call_expr += '{}, '.format(val.name)

            dispatchfunc += call_expr
            body += '                ' + dispatchfunc[:-2] + ');\n'
            body += '            }\n'
            body += '        }\n'
            body += '\n'
            body += '        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);\n'
            body += '        for (auto dr_context : dr_contexts)\n'
            body += '        {\n'
            body += '            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();\n'
            body += '            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)\n'
            body += '            {\n'

            dispatchfunc = 'func(dispatch_rays_command_buffer, ' + call_expr
            body += '                ' + dispatchfunc[:-2] + ');\n'
            body += '            }\n'
            body += '        }\n'
            body += '    }\n'
        else:
            override_call_expr = 'call_info, func, '
            for val in values:
                if val.is_pointer or val.is_array:
                    count = val.pointer_count
                    if self.is_handle(val.base_type) and val.base_type != 'VkCommandBuffer':
                        override_call_expr += '{}->GetPointer(), '.format(val.name)
                    else:
                        override_call_expr += '{}, '.format(val.name)
                else:
                    override_call_expr += '{}, '.format(val.name)

            if is_transfer:
                override_call_expr += 'before_command'
            else:
                override_call_expr = override_call_expr[:-2]

            body += '    if (IsRecording())\n'
            body += '    {\n'
            body += '        {}({});\n'.format(self.DUMP_RESOURCES_OVERRIDES[name], override_call_expr)
            body += '    }\n'


        return body
