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
#

import sys
from openxr_base_generator import *
from khronos_struct_to_json_body_generator import KhronosStructToJsonBodyGenerator
from reformat_code import format_cpp_code, indent_cpp_code, remove_leading_empty_lines, remove_trailing_newlines


class OpenXrStructToJsonBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating C++ functions for serializing OpenXr structures to JSON"""

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
            'generated_openxr_struct_to_json.h',
            'generated_vulkan_struct_to_json.h',
            'generated_openxr_enum_to_json.h',
            'generated_vulkan_enum_to_json.h',
            'util/to_string.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.begin_end_file_data.common_api_headers = []

# OpenXrStructToJsonBodyGenerator - subclass of OpenXrBaseGenerator.
# Generates C++ functions for serializing OpenXr API structures to JSON.
class OpenXrStructToJsonBodyGenerator(OpenXrBaseGenerator, KhronosStructToJsonBodyGenerator):
    """Generate C++ functions for OpenXr FieldToJson(...) functions"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # The following structures require custom implementations for FieldToJson()
        self.customImplementationRequired = {}

        self.formatAsHex = {}

        # Fields using this name should be output as handles even though they are uint64_t
        self.formatAsHandle = {}

        # Struct types here do not have decoded fields.
        self.notDecoded = {}

    def should_decode_struct(self, struct):
        """Method indended to be overridden.
        Indicates that the provided struct is a struct we want to decode"""
        return not struct in self.customImplementationRequired

    def get_local_type_var_name(self):
        return 'type'

    def decode_as_handle(self, parent_type, member):
        """Method indended to be overridden.
        Indicates that the given type should be decoded as a handle."""
        return (
            (
                self.is_handle_like(member.base_type)
                or member.name in self.formatAsHandle
            ) and not (parent_type in self.notDecoded)
        )

    # Method override
    def endFile(self):
        KhronosStructToJsonBodyGenerator.write_body_contents(self)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
