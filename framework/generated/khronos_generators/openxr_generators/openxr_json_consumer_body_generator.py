#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2025 LunarG, Inc.
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
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_json_consumer_body_generator import KhronosExportJsonConsumerBodyGenerator
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class OpenXrExportJsonConsumerBodyGeneratorOptions(OpenXrBaseGeneratorOptions, KhronosExportJsonConsumerBodyGenerator):
    """Options for generating a C++ class for OpenXr capture file to JSON file generation."""

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
        OpenXrBaseGeneratorOptions.__init__(
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
            'util/defines.h',
            'generated/generated_openxr_json_consumer.h',
            'decode/custom_openxr_struct_to_json.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.extra_manual_commands.extend(['xrPollEvent', 'xrEnumerateSwapchainImages'])

class OpenXrExportJsonConsumerBodyGenerator(OpenXrBaseGenerator, KhronosExportJsonConsumerBodyGenerator):
    """OpenXrExportJsonConsumerBodyGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ member definitions for the OpenXrExportJsonConsumer class responsible for
    generating a textfile containing decoded OpenXr API call parameter data.
    Generate a C++ class for OpenXr capture file to JSON file generation.
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

        self.formatAsHex = {}

        # Parameters using this name should be output as handles even though they are uint64_t
        self.formatAsHandle = {}

        self.external_structs = set(['LARGE_INTEGER', 'LUID'])

    def endFile(self):
        """Method override."""
        # TODO: Each code generator is passed a blacklist like framework\generated\openxr_generators\blacklists.json
        # of functions and structures not to generate code for. Once the feature is implemented, the following can be
        # replaced with adding vkCreateRayTracingPipelinesKHR in corresponding blacklist.
        if 'vkCreateRayTracingPipelinesKHR' in self.APICALL_BLACKLIST:
            self.APICALL_BLACKLIST.remove('vkCreateRayTracingPipelinesKHR')

        KhronosExportJsonConsumerBodyGenerator.generate_json_content(self)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

    def skip_generating_command_json(self, command):
        """Method override"""
        return self.is_manually_generated_cmd_name(command)

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

    def has_special_case_json_export(self, name):
        """Method may be overridden."""
        return name in self.external_structs

    def get_special_case_json_export(self, name):
        """Method may be overridden."""
        to_json = ''
        if self.has_special_case_json_export(name):
            to_json = 'FieldToJson(args["{0}"], *{0}->GetPointer(), json_options)'

        return to_json
    # yapf: disable
    def make_consumer_func_body(self, return_type, name, values):
        """Return class member function definition."""
        body = KhronosExportJsonConsumerBodyGenerator.make_consumer_func_body(self, return_type, name, values)
        return body
    # yapf: enable
