#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
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
from khronos_base_generator import ValueInfo
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions
from khronos_decoder_body_generator import KhronosDecoderBodyGenerator

class VulkanDecoderBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan API parameter decoding."""

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
            'decode/handle_pointer_decoder.h',
            'decode/pointer_decoder.h',
            'decode/string_array_decoder.h',
            'decode/string_decoder.h',
            'decode/struct_pointer_decoder.h',
            'decode/value_decoder.h',
            'decode/vulkan_decoder_args.h',
            'decode/vulkan_pnext_node.h',
            'generated/generated_vulkan_decoder.h',
            'generated/generated_vulkan_struct_decoders_forward.h',
            'generated/generated_vulkan_decoder_args.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.system_headers.append('cstddef')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))


class VulkanDecoderBodyGenerator(VulkanBaseGenerator, KhronosDecoderBodyGenerator):
    """VulkanDecoderBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member functions for the VulkanDecoder class responsible for decoding
    Vulkan API call parameter data.
    Generate a C++ class for Vulkan API parameter decoding.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        KhronosDecoderBodyGenerator.__init__(self)

        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def endFile(self):
        """Method override."""
        self.newline()
        self.generate_commands()

        self.newline()
        # Generate the VulkanDecoder::DecodeFunctionCall method for all of the commands processed by the generator.
        self.generate_decode_cases()
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)


    def make_cmd_body(self, return_type, name, values):
        """Generate C++ code for the decoder method body."""
        preamble = ''
        main_body = ''
        epilogue = ''
        arg_names = []
        has_base_header_to_peak = False

        # Declare args.
        args_struct_name = VulkanBaseGenerator.make_args_struct_name(name, namespace='args::')
        main_body += f'    {args_struct_name} args;\n'

        if len(values) > 0 or (return_type and return_type != 'void'):
            arg_names.append('args')

        # Blank line after declarations.
        if values or return_type:
            main_body += '\n'

        if has_base_header_to_peak:
            main_body += '    bool     peak_is_null    = false;\n'
            main_body += '    bool     peak_is_struct  = false;\n'
            main_body += '    bool     peak_has_length = false;\n'
            main_body += '    size_t   peak_length{};\n'
            main_body += '    uint32_t peak_structure_type = 0;\n'

        # Decode() method calls for pointer decoder wrappers.
        prefix = self.get_param_prefix()
        for value in values:
            preamble, main_body, epilogue = KhronosDecoderBodyGenerator.make_decode_invocation(
                self, value, preamble, main_body, epilogue, target_prefix=prefix
            )
        if return_type and return_type != 'void':
            preamble, main_body, epilogue = KhronosDecoderBodyGenerator.make_decode_invocation(
                self, ValueInfo('args.result', return_type, return_type, prefix=prefix), preamble, main_body, epilogue
            )

        # Blank line after Decode() method invocations.
        if values or return_type:
            main_body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([arg_name for arg_name in arg_names])

        if arglist[-2:] == ', ':
            arglist = arglist[:-2]
        arglist = 'call_info, ' + arglist

        main_body += '    for (auto consumer : GetConsumers())\n'
        main_body += '    {\n'
        main_body += f'        consumer->Process_{name}({arglist});\n'
        main_body += '    }\n'

        if len(preamble) > 0:
            preamble += '\n'
        body = preamble + main_body + epilogue

        return body
