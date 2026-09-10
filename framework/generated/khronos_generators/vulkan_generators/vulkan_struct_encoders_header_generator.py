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
from khronos_struct_encoders_header_generator import KhronosStructEncodersHeaderGenerator
from vulkan_schema_generator import is_schema_driven_encode


class VulkanStructEncodersHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ function declarations for Vulkan struct encoding."""

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
            'encode/parameter_encoder.h',
            'format/platform_types.h',
            'util/defines.h',
            'util/type_list.h',
        ))
        self.begin_end_file_data.system_headers.append('cstdint')
        self.begin_end_file_data.namespaces.extend((
            'gfxrecon', 'encode',
        ))


class VulkanStructEncodersHeaderGenerator(VulkanBaseGenerator, KhronosStructEncodersHeaderGenerator):
    """VulkanStructEncodersHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ type and function declarations for encoding Vulkan API structures.
    Generate C++ function declarations for Vulkan struct encoding.
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

    def skip_struct_type(self, struct_type):
        """Method override. A schema-owned encoder is declared by the constrained template."""
        return is_schema_driven_encode(self, struct_type)

    def write_schema_driven_declarations(self):
        """The declaration side of the structures the schema drives."""
        self.newline()
        write('// The structures the schema drives. encode/vulkan_encode_struct.h includes this header and declares the', file=self.outFile)
        write('// constrained EncodeStruct over this list beside the prototypes.', file=self.outFile)
        write('using SchemaDrivenStructs = util::TypeList<', file=self.outFile)

        driven = sorted(
            struct for struct in self.get_all_filtered_struct_names()
            if is_schema_driven_encode(self, struct)
        )
        for index, struct in enumerate(driven):
            comma = ',' if index + 1 < len(driven) else ''
            write('    {}{}'.format(struct, comma), file=self.outFile)

        write('>;', file=self.outFile)

    def endFile(self):
        """Method override."""
        KhronosStructEncodersHeaderGenerator.write_encoder_content(self)
        self.write_schema_driven_declarations()

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
