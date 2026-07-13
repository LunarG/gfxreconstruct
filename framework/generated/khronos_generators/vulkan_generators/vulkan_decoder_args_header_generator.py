#!/usr/bin/python3 -i
#
# Copyright (c) 2026 LunarG, Inc.
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

"""Decoder args generator"""

import sys
from khronos_base_generator import ValueInfo
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator


class VulkanDecoderArgsHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ type declarations for Vulkan decoder args."""

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
            'decode/custom_vulkan_struct_decoders.h',
            'decode/handle_pointer_decoder.h',
            'decode/pointer_decoder.h',
            'decode/string_array_decoder.h',
            'decode/string_decoder.h',
            'decode/struct_pointer_decoder.h',
            'decode/vulkan_pnext_node.h',
            'format/format.h',
            'generated/generated_vulkan_struct_decoders.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.system_headers.append('tuple')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode', 'args'))

        self.begin_end_file_data.pre_namespace_code.extend((
            '#ifdef WIN32',
            '#ifdef CreateEvent',
            '#undef CreateEvent',
            '#endif',
            '#ifdef CreateSemaphore',
            '#undef CreateSemaphore',
            '#endif',
            '#endif',
            ''
        ))

class VulkanDecoderArgsHeaderGenerator(
    KhronosStructDecodersHeaderGenerator, VulkanBaseGenerator
):
    """VulkanDecodersArgsHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ type declarations for the decoded Vulkan API structure wrappers.
    Generate C++ type declarations for Vulkan decoder args.
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
            # Skip commands that are decoded by hand-written code.
            if self.is_manually_generated_cmd_name(cmd):
                continue

            args_struct_name = VulkanBaseGenerator.make_args_struct_name(cmd)
            info = self.all_cmd_params[cmd]
            return_type = info[0]
            params: list[ValueInfo] = info[2]

            body = "\n"
            body += f"struct {args_struct_name}\n"
            body += "{\n"

            if return_type and return_type != 'void':
                body += f"    {return_type} result;\n"

            for param in params:
                decoded_type = self.make_decoded_param_type(param)
                body += f"    {decoded_type} {param.name};\n"

            body += "\n    auto GetTuple() const { return std::tie("
            if return_type and return_type != 'void':
                body += "result, "
            for param in params:
                body += f"{param.name}, "
            body = body[:-2]  # Remove the trailing comma and space.
            body += "); }\n"

            body += "};\n"

            write(body, file=self.outFile)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
