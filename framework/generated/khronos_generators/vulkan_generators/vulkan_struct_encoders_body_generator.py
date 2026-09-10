#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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
from khronos_struct_encoders_body_generator import KhronosStructEncodersBodyGenerator
from vulkan_schema_generator import is_schema_driven_encode


class VulkanStructEncodersBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan struct encoding."""

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
            'encode/vulkan_encode_struct.h',
            '',
            'encode/custom_vulkan_struct_encoders.h',
            'encode/parameter_encoder.h',
            'encode/struct_pointer_encoder.h',
            'encode/vulkan_encode_struct_impl.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))

class VulkanStructEncodersBodyGenerator(VulkanBaseGenerator, KhronosStructEncodersBodyGenerator):
    """VulkanStructEncodersBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions for encoding Vulkan API structures.
    Generate C++ functions for Vulkan struct encoding.
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
        """Method override. The schema field walk owns these encoders, so no procedural body is emitted."""
        return is_schema_driven_encode(self, struct_type)

    def write_schema_driven_instantiations(self):
        """One explicit instantiation for each structure the schema drives.

        These sit where the bodies they replace sat. This translation unit already compiles every procedural
        encoder, so making it the one that compiles the walk keeps the schema and the member-trait partitions out
        of every other target rather than following EncodeStruct into each caller.
        """
        driven = sorted(
            struct for struct in self.get_all_filtered_struct_names()
            if is_schema_driven_encode(self, struct)
        )

        write('// The schema drives these encoders. This is the only translation unit that compiles the walk.', file=self.outFile)

        for struct in driven:
            write(
                'template void EncodeStruct<{name}>(ParameterEncoder*, const {name}&);'.format(
                    name=struct
                ),
                file=self.outFile
            )

        self.newline()

    def endFile(self):
        """Method override."""
        KhronosStructEncodersBodyGenerator.write_encoder_content(self)
        self.newline()
        self.write_schema_driven_instantiations()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False
