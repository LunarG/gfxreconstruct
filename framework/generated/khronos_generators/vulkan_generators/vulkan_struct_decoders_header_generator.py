#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator


class VulkanStructDecodersHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ type declarations for Vulkan struct decoding."""

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
            'decode/custom_vulkan_struct_decoders_forward.h',
            'decode/handle_pointer_decoder.h',
            'decode/pointer_decoder.h',
            'decode/string_array_decoder.h',
            'decode/string_decoder.h',
            'decode/struct_pointer_decoder.h',
            'decode/vulkan_pnext_node.h',
            'format/format.h',
            'format/platform_types.h',
            'generated/generated_vulkan_struct_decoders_forward.h',
            'util/defines.h',
            'util/logging.h',
        ))
        self.begin_end_file_data.system_headers.append('memory')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))

class VulkanStructDecodersHeaderGenerator(
    KhronosStructDecodersHeaderGenerator, VulkanBaseGenerator
):
    """VulkanStructDecodersHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ type declarations for the decoded Vulkan API structure wrappers.
    Generate C++ type declarations for Vulkan struct decoding.
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

    def write_base_out_struct_definition(self):
        entries = self.get_base_out_structure_type_info_list()
        api_data = self.get_api_data()
        var_name = api_data.type_prefix.lower() + '_type'

        body = '\n'
        body += 'struct Decoded_VkBaseOutStructure\n'
        body += '{\n'
        body += '    using struct_type = VkBaseOutStructure;\n'
        body += '\n'
        body += '    union VkBaseOutStructureSizeUnion\n'
        body += '    {\n'
        if entries:
            current_char = 'a'
            for child, _ in entries:
                body += '        {} {};\n'.format(child, current_char)
                current_char = chr(ord(current_char) + 1)
        else:
            body += '        VkBaseOutStructure value;\n'
        body += '    };\n'
        body += '\n'
        body += '    using union_size_type = VkBaseOutStructureSizeUnion;\n'
        body += '\n'
        body += '    VkBaseOutStructure* decoded_value{ nullptr };\n'
        body += '    PNextNode*          pNext{ nullptr };\n'
        body += '\n'
        body += '    static Decoded_VkBaseOutStructure* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)\n'
        body += '    {\n'
        body += '        Decoded_VkBaseOutStructure* return_type = nullptr;\n'
        body += '\n'
        body += '        uint32_t peek_structure_type = 0;\n'
        body += '        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);\n'
        body += '        {struct_type} {var_name} = static_cast<{struct_type}>(peek_structure_type);\n'.format(
            struct_type=api_data.struct_type_enum, var_name=var_name
        )
        body += '\n'
        body += '        switch ({})\n'.format(var_name)
        body += '        {\n'
        body += '            default:\n'
        body += '                GFXRECON_LOG_WARNING_ONCE("Decoded_VkBaseOutStructure::AllocateAppropriate: unrecognized sType 0x%x", peek_structure_type);\n'
        body += '                return_type = DecodeAllocator::Allocate<Decoded_VkBaseOutStructure>(len, initialize);\n'
        body += '                break;\n'
        for child, struct_type in entries:
            body += '            case {}:\n'.format(struct_type)
            body += '                return_type = reinterpret_cast<Decoded_VkBaseOutStructure*>(DecodeAllocator::Allocate<Decoded_{}>(len, initialize));\n'.format(
                child
            )
            body += '                break;\n'
        body += '        }\n'
        body += '        return return_type;\n'
        body += '    }\n'
        body += '\n'
        body += '    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_VkBaseOutStructure* dest)\n'
        body += '    {\n'
        body += '        size_t bytes_read = 0;\n'
        body += '\n'
        body += '        uint32_t peek_structure_type = 0;\n'
        body += '        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);\n'
        body += '        {struct_type} {var_name} = static_cast<{struct_type}>(peek_structure_type);\n'.format(
            struct_type=api_data.struct_type_enum, var_name=var_name
        )
        body += '\n'
        body += '        switch ({})\n'.format(var_name)
        body += '        {\n'
        body += '            default:\n'
        body += '                GFXRECON_LOG_WARNING_ONCE("Decoded_VkBaseOutStructure::DecodeAppropriate: unrecognized sType 0x%x", peek_structure_type);\n'
        body += '                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);\n'
        body += '                break;\n'
        for child, struct_type in entries:
            body += '            case {}:\n'.format(struct_type)
            body += '            {\n'
            body += '                Decoded_{}* local_dest = reinterpret_cast<Decoded_{}*>(dest);\n'.format(
                child, child
            )
            body += '                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);\n'
            body += '                break;\n'
            body += '            }\n'
        body += '        }\n'
        body += '        return bytes_read;\n'
        body += '    }\n'
        body += '\n'
        body += '    VkBaseOutStructure* AllocateOutputData(size_t len)\n'
        body += '    {\n'
        body += '        assert(decoded_value != nullptr);\n'
        body += '\n'
        body += '        switch (decoded_value->sType)\n'
        body += '        {\n'
        body += '            default:\n'
        body += '                return DecodeAllocator::Allocate<VkBaseOutStructure>(len);\n'
        for child, struct_type in entries:
            body += '            case {}:\n'.format(struct_type)
            body += '            {\n'
            body += '                auto* allocation = DecodeAllocator::Allocate<{}>(len);\n'.format(child)
            body += '                for (size_t i = 0; i < len; ++i)\n'
            body += '                {\n'
            body += '                    allocation[i] = {}{{ {}, nullptr }};\n'.format(child, struct_type)
            body += '                }\n'
            body += '                return reinterpret_cast<VkBaseOutStructure*>(allocation);\n'
            body += '            }\n'
        body += '        }\n'
        body += '    }\n'
        body += '};\n'
        write(body, file=self.outFile)

    def endFile(self):
        """Method override."""
        KhronosStructDecodersHeaderGenerator.endFile(self)
        self.write_base_out_struct_definition()
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

