#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2020 LunarG, Inc.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from base_struct_handle_mappers_header_generator import BaseStructHandleMappersHeaderGenerator


class VulkanStructHandleMappersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function prototypes to map Vulkan struct member handles at file replay."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanStructHandleMappersHeaderGenerator(
    BaseStructHandleMappersHeaderGenerator, BaseGenerator
):
    """VulkanStructHandleMappersHeaderGenerator - subclass of BaseGenerator.
    Generates C++ function prototypes for mapping struct member handles
    when replaying decoded Vulkan API call parameter data.
    Generate C++ functions for Vulkan struct member handle mapping at file replay.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.structs_with_handle_ptrs = []
        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs_with_handles = []
        self.structs_with_map_data = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "decode/vulkan_object_info_table.h"', file=self.outFile
        )
        write('#include "decode/vulkan_pnext_node.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write(
            '#include "decode/custom_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_decoders_forward.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        BaseStructHandleMappersHeaderGenerator.endFile(self)
        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            )

    def genCmd(self, cmdinfo, name, alias):
        """Method override."""
        BaseGenerator.genCmd(self, cmdinfo, name, alias)

        # Look for output structs that contain handles and add to list
        if not alias:
            for value_info in self.feature_cmd_params[name][2]:
                if self.is_output_parameter(value_info) and (
                    value_info.base_type in self.get_filtered_struct_names()
                ) and (value_info.base_type in self.structs_with_handles) and (
                    value_info.base_type
                    not in self.output_structs_with_handles
                ):
                    self.output_structs_with_handles.append(
                        value_info.base_type
                    )

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        BaseStructHandleMappersHeaderGenerator.generate_feature(self)
