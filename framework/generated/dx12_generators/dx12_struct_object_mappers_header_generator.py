#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from base_struct_handle_mappers_header_generator import BaseStructHandleMappersHeaderGenerator


class Dx12StructObjectMappersHeaderGenerator(
    BaseStructHandleMappersHeaderGenerator, Dx12BaseGenerator
):
    """Generates C++ functions responsible for Dx12 struct object mappers."""

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        Dx12BaseGenerator.__init__(
            self, source_dict, dx12_prefix_strings, err_file, warn_file,
            diag_file
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = {
            **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE':
            ['ptr']
        }

    def beginFile(self, gen_opts):
        """Method override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)

        write('#include "format/platform_types.h"', file=self.outFile)
        write(
            '#include "generated/generated_dx12_struct_decoders_forward.h"',
            file=self.outFile
        )
        write(
            '#include "decode/dx12_replay_consumer_base.h"', file=self.outFile
        )
        write('#include "graphics/dx12_gpu_va_map.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def generate_feature(self):
        """Performs C++ code generation for the feature."""

        # Functions should not be generated for structs on the blacklist.
        self.check_blacklist = True
        BaseStructHandleMappersHeaderGenerator.generate_feature(self)
        header_dict = self.source_dict['header_dict']
        self.structs_with_objects = self.collect_struct_with_objects(
            header_dict
        )
        self.newline()
        self.write_struct_member_def()

    def endFile(self):
        """Method override."""
        BaseStructHandleMappersHeaderGenerator.endFile(self)
        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""

        # The list of structs with handles should include all structs, inlcuding structs on the blacklist.
        self.check_blacklist = False

        Dx12BaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            for struct_name in self.all_struct_members:
                self.check_struct_member_handles(
                    struct_name, self.structs_with_handles,
                    self.structs_with_handle_ptrs, True,
                    self.structs_with_map_data
                )

    def write_struct_member_def(self):
        for k, v in self.structs_with_objects.items():
            expr = 'void AddStructObjects(const StructPointerDecoder<Decoded_{0}>* capture_value, const {0}* new_value, Dx12ObjectInfoTable& object_info_table);\n'.format(
                k
            )
            write(expr, file=self.outFile)
