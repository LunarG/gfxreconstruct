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
from base_struct_handle_mappers_body_generator import BaseStructHandleMappersBodyGenerator


class Dx12StructObjectMappersBodyGenerator(
    BaseStructHandleMappersBodyGenerator, Dx12BaseGenerator
):
    """Generates C++ functions responsible for decoding Dx12 API calls."""

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

        BaseStructHandleMappersBodyGenerator.__init__(
            self,
            structs_with_handles={ **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE': ['ptr'] } 
        )

    def beginFile(self, gen_opts):
        """Method override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_dx12_struct_object_mappers.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_dx12_struct_decoders.h"',
            file=self.outFile
        )
        write(
            '#include "decode/custom_dx12_struct_object_mappers.h"',
            file=self.outFile
        )
        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write(
            '#include "decode/dx12_object_mapping_util.h"', file=self.outFile
        )
        write(
            '#include "generated/generated_dx12_struct_decoders.h"',
            file=self.outFile
        )
        self.newline()
        write('#include <algorithm>', file=self.outFile)
        write('#include <cassert>', file=self.outFile)

        self.newline()
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            write('#include <{}>'.format(k), file=self.outFile)

        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        BaseStructHandleMappersBodyGenerator.endFile(self)
        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""

        # The list of structs with handles should include all structs, inlcuding structs on the blacklist.
        self.check_blacklist = False

        Dx12BaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            for struct_name in self.get_filtered_struct_names():
                self.check_struct_member_handles(
                    struct_name, self.structs_with_handles,
                    self.structs_with_handle_ptrs, True,
                    self.structs_with_map_data
                )

    def generate_feature(self):
        """Performs C++ code generation for the feature."""

        # Functions should not be generated for structs on the blacklist.
        self.check_blacklist = True
        BaseStructHandleMappersBodyGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        self.structs_with_objects = self.collect_struct_with_objects(
            header_dict
        )
        self.write_struct_member_def()

    def write_struct_member_def(self):
        for k, v in self.structs_with_objects.items():
            expr = 'void AddStructObjects(const StructPointerDecoder<Decoded_{0}>* capture_value, const {0}* new_value, Dx12ObjectInfoTable& object_info_table)\n'.format(
                k
            )
            expr += '{\n'
            expr += '    auto decoded_struct = capture_value->GetMetaStructPointer();\n'

            for value in v:
                if self.is_struct(value.base_type):
                    expr += '    if(decoded_struct->{0} && new_value->{0})\n'\
                            '    {{\n'\
                            '        AddStructObjects(decoded_struct->{0}, new_value->{0}, object_info_table);\n'\
                            '    }}\n'.format(value.name)

                elif self.is_class(value):
                    expr += '    if(decoded_struct->{0} && new_value->{0})\n'\
                            '    {{\n'\
                            '        object_mapping::AddObject(&decoded_struct->{0}, const_cast<{1}**>(&new_value->{0}), &object_info_table);\n'\
                            '    }}\n'.format(value.name, value.base_type)

            expr += '}\n'
            write(expr, file=self.outFile)
