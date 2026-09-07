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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_struct_decoders_body_generator import KhronosStructDecodersBodyGenerator
from vulkan_schema_generator import SCHEMA_DRIVEN_STRUCTS


class VulkanStructDecodersBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan struct decoding."""

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
            'decode/vulkan_decode_struct_impl.h',
            'generated/generated_vulkan_struct_decoders.h',
            '',
            'decode/custom_vulkan_struct_decoders.h',
            'decode/decode_allocator.h',
        ))
        self.begin_end_file_data.system_headers.append( 'cassert')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))
        self.begin_end_file_data.common_api_headers = []


class VulkanStructDecodersBodyGenerator(
    KhronosStructDecodersBodyGenerator, VulkanBaseGenerator
):
    """VulkanStructDecodersBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions for decoding Vulkan API structures.
    Generate C++ functions for Vulkan struct decoding."""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def skip_struct_decoder(self, struct):
        """Method override. The schema field walk owns these decoders, so no procedural body is emitted."""
        return struct in SCHEMA_DRIVEN_STRUCTS

    def write_base_out_struct_decoder(self):
        body = '\n'
        body += 'size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkBaseOutStructure* wrapper)\n'
        body += '{\n'
        body += '    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));\n'
        body += '\n'
        body += '    size_t              bytes_read = 0;\n'
        body += '    VkBaseOutStructure* value      = wrapper->decoded_value;\n'
        body += '\n'
        body += '    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));\n'
        body += '    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));\n'
        body += '    value->pNext = wrapper->pNext ? reinterpret_cast<VkBaseOutStructure*>(wrapper->pNext->GetPointer()) : nullptr;\n'
        body += '\n'
        body += '    return bytes_read;\n'
        body += '}\n'
        write(body, file=self.outFile)

    def write_schema_driven_instantiations(self):
        """One explicit instantiation for each structure the schema drives.

        These sit where the bodies they replace sat. This translation unit already compiles every procedural
        decoder, so making it the one that compiles the walk keeps the schema and the member-trait partitions out
        of every other target rather than following DecodeStruct into each caller.
        """
        driven = sorted(
            struct for struct in self.get_all_filtered_struct_names()
            if struct in SCHEMA_DRIVEN_STRUCTS
        )

        write('// The schema drives these decoders. This is the only translation unit that compiles the walk.', file=self.outFile)

        for struct in driven:
            write(
                'template size_t DecodeStruct<Decoded_{name}>(const uint8_t*, size_t, Decoded_{name}*);'.format(
                    name=struct
                ),
                file=self.outFile
            )

        self.newline()

    def endFile(self):
        """Method override."""
        KhronosStructDecodersBodyGenerator.generate_struct_decoder_content(self)
        self.write_base_out_struct_decoder()
        self.newline()
        self.write_schema_driven_instantiations()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
