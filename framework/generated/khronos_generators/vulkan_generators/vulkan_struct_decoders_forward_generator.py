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
from khronos_struct_decoders_forward_generator import KhronosStructDecodersForwardGenerator
from vulkan_schema_generator import SCHEMA_DRIVEN_STRUCTS


class VulkanStructDecodersForwardGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ function and forward type declarations for Vulkan struct decoding."""

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

        self.begin_end_file_data.specific_headers.append('util/defines.h')
        self.begin_end_file_data.specific_headers.append('util/type_list.h')
        self.begin_end_file_data.system_headers.append('cstdint')
        self.begin_end_file_data.namespaces.extend((
            'gfxrecon',
            'decode',
        ))


class VulkanStructDecodersForwardGenerator(VulkanBaseGenerator, KhronosStructDecodersForwardGenerator):
    """VulkanStructDecodersForwardGenerator - subclass of VulkanBaseGenerator.
    Generates C++ type and function declarations for decoding Vulkan API structures.
    Generate C++ function and forward type declarations for Vulkan struct decoding.
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

    def skip_struct_decoder_prototype(self, struct):
        """Method override. A schema-owned decoder is declared by the constrained template."""
        return struct in SCHEMA_DRIVEN_STRUCTS

    def write_schema_driven_declarations(self):
        """The declaration side of the structures the schema drives.

        These sit beside the prototypes they replace, and in the same file, because they are the same thing: a
        caller needs one declaration per structure either way, and which kind it gets is the only difference. As
        structures migrate, prototypes leave and typelist entries arrive, and no caller's includes change.
        """
        driven = sorted(
            struct for struct in self.get_all_filtered_struct_names()
            if struct in SCHEMA_DRIVEN_STRUCTS
        )

        self.newline()
        write('// The structures whose decoder the schema drives, rather than a body generated for each.', file=self.outFile)
        write('//', file=self.outFile)
        write('// The constraint is for diagnosis, not selection: the template would resolve correctly without it,', file=self.outFile)
        write('// since a non-template beats a template wherever a prototype above still exists. What it buys is', file=self.outFile)
        write('// that a wrapper with no instantiation fails at the call naming its type, rather than at the link', file=self.outFile)
        write('// naming a mangled symbol.', file=self.outFile)
        write('using SchemaDrivenStructs = util::TypeList<', file=self.outFile)

        for index, struct in enumerate(driven):
            comma = ',' if index + 1 < len(driven) else ''
            write('    Decoded_{}{}'.format(struct, comma), file=self.outFile)

        write('>;', file=self.outFile)
        self.newline()
        write('template <typename Wrapper>', file=self.outFile)
        write('concept SchemaDriven = util::TypeListContainsV<SchemaDrivenStructs, Wrapper>;', file=self.outFile)
        self.newline()
        write('// Defined in decode/vulkan_decode_struct_impl.h, which is private to the one translation unit', file=self.outFile)
        write('// that instantiates it. See that header for why.', file=self.outFile)
        write('template <SchemaDriven Wrapper>', file=self.outFile)
        write('size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Wrapper* wrapper);', file=self.outFile)

    def endFile(self):
        """Method override."""
        KhronosStructDecodersForwardGenerator.write_struct_decoder_forward_prototypes(self)
        write('struct Decoded_VkBaseOutStructure;', file=self.outFile)
        write('size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBaseOutStructure* wrapper);', file=self.outFile)

        self.write_schema_driven_declarations()

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
