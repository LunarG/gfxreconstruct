#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2024 LunarG, Inc.
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
from base_generator_defines import write


class KhronosStructHandleMappersHeaderGenerator():
    """Base class for generating struct handle mappers header code."""

    def endFile(self):
        platform_type = self.get_api_prefix()

        object_table_prefix, map_type, base_type, map_table = self.getMapperObjectInfo(
            True
        )
        map_types = map_type + 's'
        if len(map_table) > 0:
            map_table = f', const {map_table}'

        for struct in self.get_all_filtered_struct_names():
            if (
                struct in self.structs_with_handles or struct
                in self.GENERIC_HANDLE_STRUCTS or self.is_map_struct(struct)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                body = '\n'
                body += 'void MapStruct{}(Decoded_{}* wrapper, const {}ObjectInfoTable& object_info_table{});'.format(
                    map_types, struct, object_table_prefix, map_table
                )
                write(body, file=self.outFile)

        if self.hasExtendedTypeMemberName():
            func_id = self.getExtendedTypeMemberName()[0:1].upper()
            func_id += self.getExtendedTypeMemberName()[1:]
            self.newline()
            write(
                f'void Map{func_id}StructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);',
                file=self.outFile
            )

        self.newline()

        for struct in self.output_structs_with_handles:
            write(
                'void AddStruct{}(format::HandleId parent_id, const Decoded_{type}* id_wrapper, const {type}* handle_struct, {}ObjectInfoTable* object_info_table{});'
                .format(
                    map_types, object_table_prefix, map_table, type=struct
                ),
                file=self.outFile
            )
            self.newline()

        for struct in self.output_structs_with_handles:
            if struct in self.structs_with_handle_ptrs:
                write(
                    'void SetStruct{map_type}Lengths(Decoded_{type}* wrapper);'
                    .format(map_type=map_type, type=struct),
                    file=self.outFile
                )
                self.newline()

        write(
            '#include "decode/common_struct_handle_mappers.h"',
            file=self.outFile
        )

        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)
