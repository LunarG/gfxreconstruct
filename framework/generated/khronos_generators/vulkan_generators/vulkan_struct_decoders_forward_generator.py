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
from vulkan_schema_generator import is_schema_driven


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
        return is_schema_driven(self, struct)

    def write_schema_driven_declarations(self):
        """The declaration side of the structures the schema drives.

        These sit beside the prototypes they replace, and in the same file, because they are the same thing: a
        caller needs one declaration per structure either way, and which kind it gets is the only difference. As
        structures migrate, prototypes leave and exclusions leave with them, and no caller's includes change.

        The list names what the schema does NOT drive, rather than what it does. Both spellings pick out the same
        template, but this one is a handful of entries where the other was the whole population, and that matters
        here: this header is included nearly everywhere, and every use of the concept expands the list as a fold,
        so the list's length is multiplied by the number of call sites.

        Custom decoders are not listed. They are declared in decode/custom_vulkan_struct_decoders.h as
        non-template overloads, which beat this template wherever they are visible, and their wrappers are not
        declared in this file at all.
        """
        excluded = sorted(
            struct for struct in self.get_all_filtered_struct_names()
            if not is_schema_driven(self, struct)
            and struct not in self.all_struct_aliases
            and struct not in self.all_union_aliases
        )

        # VkBaseOutStructure keeps a generated body, written by hand above, so it belongs to this category too.
        excluded.append('VkBaseOutStructure')

        self.newline()
        write('// The structures the schema does not drive: each keeps a generated body and a prototype above.', file=self.outFile)
        write('//', file=self.outFile)
        write('// Stated as an exclusion because this header is included nearly everywhere and the concept', file=self.outFile)
        write('// expands the list at every use. Naming the driven population instead would put a fold over', file=self.outFile)
        write('// every structure at every call site, to decide a question the exclusions answer in a step.', file=self.outFile)
        write('using NonSchemaDrivenStructs = util::TypeList<', file=self.outFile)

        for index, struct in enumerate(excluded):
            comma = ',' if index + 1 < len(excluded) else ''
            write('    Decoded_{}{}'.format(struct, comma), file=self.outFile)

        write('>;', file=self.outFile)
        self.newline()
        write('// The constraint is for diagnosis, not selection: the template would resolve correctly without', file=self.outFile)
        write('// it, since a non-template beats a template wherever a prototype above still exists. What it', file=self.outFile)
        write('// buys is that a structure with a body of its own fails at the call naming its type, rather', file=self.outFile)
        write('// than at the link naming a mangled symbol.', file=self.outFile)
        write('template <typename Wrapper>', file=self.outFile)
        write('concept SchemaDriven = !util::TypeListContainsV<NonSchemaDrivenStructs, Wrapper>;', file=self.outFile)
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
