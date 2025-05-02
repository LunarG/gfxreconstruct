#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_replay_consumer_body_generator import KhronosReplayConsumerBodyGenerator


class OpenXrReplayConsumerBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating a C++ class for OpenXr capture file replay."""

    def __init__(
        self,
        replay_overrides=None,  # Path to JSON file listing OpenXr API calls to override on replay.
        dump_resources_overrides=None,  # Path to JSON file listing OpenXr API calls to override on replay.
        replay_async_overrides=None,  # Path to JSON file listing OpenXr API calls to override on replay.
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            replay_overrides=replay_overrides,
            dump_resources_overrides=dump_resources_overrides,
            replay_async_overrides=replay_async_overrides,
            extra_headers=extra_headers
        )

        self.begin_end_file_data.specific_headers.extend((
            'decode/custom_openxr_struct_handle_mappers.h',
            'decode/custom_vulkan_struct_handle_mappers.h',
            'decode/openxr_handle_mapping_util.h',
            'decode/vulkan_handle_mapping_util.h',
            'generated/generated_openxr_dispatch_table.h',
            'generated/generated_openxr_replay_consumer.h',
            'generated/generated_openxr_struct_handle_mappers.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))

class OpenXrReplayConsumerBodyGenerator(
    KhronosReplayConsumerBodyGenerator, OpenXrBaseGenerator
):
    """OpenXrReplayConsumerBodyGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ member definitions for the OpenXrReplayConsumer class responsible for
    replaying decoded OpenXr API call parameter data.
    Generate a C++ class for OpenXr capture file replay.
    """


    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # These functions should be manual if anything, not code-gened
        # TODO: Check on whether improvements to codegen could make these
        #       possible to codegen
        self.APICALL_BLACKLIST += [
            'xrNegotiateLoaderRuntimeInterface',
            'xrNegotiateLoaderApiLayerInterface',
            'xrCreateInstance',
            'xrCreateApiLayerInstance',
            'xrPollEvent',
            'xrCreateSwapchain',
            'xrReleaseSwapchainImage',
            'xrEndFrame',
            'xrInitializeLoaderKHR',
            'xrCreateVulkanInstanceKHR',
            'xrCreateVulkanDeviceKHR',
            'xrCreateDebugUtilsMessengerEXT',
            'xrEnumerateEnvironmentBlendModes',
        ]

        # These structures require a customized manager when they are an output struct
        # in a `Next` chain
        self.OUTPUT_NEXT_OVERRIDES = [
            'XrBindingModificationsKHR',
        ]
        self.NOT_SKIP_FUNCTIONS_OFFSCREEN = []
        self.SKIP_FUNCTIONS_OFFSCREEN = []
        self.types_treated_as_struct = set(['LARGE_INTEGER'])

    def use_instance_table(self, name, typename):
        """OpenXr always uses the instance table"""
        return True

    def determine_handle_to_remove_value(self, command, values):
        if self.needs_remove_handle_expression(command):
            return values[0]
        return None # Must be handled by caller if this isn't a destroy call

    def needs_remove_handle_expression(self, command):
        return command.startswith('xrDestroy')

    def generate_custom_call(self, name, return_type, values):
        # add custom call to replay consumer body

        api_call = 'format::ApiCallId::ApiCall_{}'.format(name)
        custom_update_args = ["this", "call_info"]

        if return_type != 'void':
            custom_update_args.append("returnValue")
        custom_update_args.extend([value.name for value in values])

        if return_type == 'XrResult':
            custom_update_args.append("replay_result")

        call = "    CustomProcess<{}>::UpdateState({});\n".format(
            api_call, ", ".join(custom_update_args)
        )

        return call


    def process_other_khronos_api_handles(self, value, values):
        """ Add handle association """
        process_text = ''
        if self.is_handle(value.base_type) and not value.base_type.startswith('Vk'):
            process_text = '\n    AssociateParent(*out_{}, in_{});'.format(
                    value.name,
                    self.get_parent_id(self.get_api_data(), value, values)
                )

        return process_text

    def treat_as_struct(self, value):
        return value.base_type in self.types_treated_as_struct
    def check_skip_extended_struct_handling(self, struct, struct_type):
        """ OpenXR Base header don't appear on next chains """
        return  'BASE_HEADER' in struct_type

    def generate_custom_extended_struct_handling(self, struct, struct_type):
        """ Method may be overriden.
            None implies no customization
        """

        if struct not in self.OUTPUT_NEXT_OVERRIDES:
            return None

        content = []
        indent = 12*' '
        add = lambda x: content.append(indent + x)
        add(f'case {struct_type}:')
        add('{')
        add(f'    output_struct->next = OverrideOutputStructNext_{struct}(in_next, output_struct);')
        add(f'    break;')
        add('}')
        return '\n'.join(content)

    def endFile(self):
        """Method override."""
        api_data = self.get_api_data()

        KhronosReplayConsumerBodyGenerator.generate_replay_consumer_content(self, api_data)
        KhronosReplayConsumerBodyGenerator.generate_extended_struct_handling(self, api_data)

        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

