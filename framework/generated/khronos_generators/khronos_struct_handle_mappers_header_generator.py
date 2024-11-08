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
from khronos_base_generator import write


class KhronosStructHandleMappersHeaderGenerator():
    """Base class for generating struct handle mappers header code."""

    def endFile(self):

        # List of structs containing handles that are also used as output parameters for a command
        output_structs_with_handles = []

        # Look for output structs that contain handles and add to list
        for cmd in self.get_all_filtered_cmd_names():
            for value_info in self.all_cmd_params[cmd][2]:
                if self.is_output_parameter(value_info) and (
                    value_info.base_type in self.get_all_filtered_struct_names()
                ) and (value_info.base_type in self.structs_with_handles) and (
                    value_info.base_type
                    not in output_structs_with_handles
                ):
                    output_structs_with_handles.append(
                        value_info.base_type
                    )

        extended_struct_func_name = self.get_extended_struct_func_prefix()

        for struct in self.get_all_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const CommonObjectInfoTable& object_info_table);'.format(
                    struct
                )
                write(body, file=self.outFile)

        self.newline()
        write(
            'void Map{}StructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);'.format(extended_struct_func_name),
            file=self.outFile
        )
        self.newline()

        for struct in output_structs_with_handles:
            write(
                'void AddStructHandles(format::HandleId parent_id, const Decoded_{type}* id_wrapper, const {type}* handle_struct, CommonObjectInfoTable* object_info_table);'
                .format(type=struct),
                file=self.outFile
            )
            self.newline()

        for struct in output_structs_with_handles:
            if struct in self.structs_with_handle_ptrs:
                write(
                    'void SetStructHandleLengths(Decoded_{type}* wrapper);'
                    .format(type=struct),
                    file=self.outFile
                )
                self.newline()

        write('#include "decode/common_struct_handle_mappers.h"', file=self.outFile)
