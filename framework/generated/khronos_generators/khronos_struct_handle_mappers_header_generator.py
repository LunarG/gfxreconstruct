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

    # Recursively search a structs members to see if they too belong in the
    # output struct list.  This could be because an including struct is an
    # output struct.
    def process_struct_members_to_output_struct(self, value):
        for member in self.all_struct_members[value.base_type]:
            if (
                self.is_struct(member.base_type)
                and not self.is_struct_black_listed(member.base_type)
                and (member.base_type not in self.all_struct_aliases)
                and (member.base_type in self.structs_with_handles)
                and (member.base_type not in self.output_structs)
            ):
                self.output_structs.append(member.base_type)
                self.process_struct_members_to_output_struct(member)

    def write_struct_handle_mapper_header(self):

        extended_struct_func_name = self.get_extended_struct_func_prefix()

        for struct in self.get_all_filtered_struct_names():
            if (
                (struct in self.structs_with_handles) or
                self.child_struct_has_handles(struct) or
                (struct in self.GENERIC_HANDLE_STRUCTS)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const CommonObjectInfoTable& object_info_table);'.format(
                    struct
                )
                write(body, file=self.outFile)

        self.newline()
        write(
            'void Map{func}StructHandles({node}Node* value, const CommonObjectInfoTable& object_info_table);'.format(
                    func=self.get_extended_struct_func_prefix(),
                    node=self.get_extended_struct_node_prefix()
                ),
            file=self.outFile
        )
        self.newline()

        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs = []

        # Look for output structs that contain handles and add to list
        for cmd in self.get_all_filtered_cmd_names():
            for value_info in self.all_cmd_params[cmd][2]:
                if (
                    self.is_output_parameter(value_info)
                    and self.is_struct(value_info.base_type)
                    and not self.is_struct_black_listed(value_info.base_type)
                    and (value_info.base_type not in self.all_struct_aliases)
                    and (value_info.base_type in self.structs_with_handles)
                    and (value_info.base_type not in self.output_structs)
                ):
                    self.output_structs.append(value_info.base_type)
                    self.process_struct_members_to_output_struct(value_info)

        for struct in self.output_structs:
            write(
                'void AddStructHandles(format::HandleId parent_id, const Decoded_{type}* id_wrapper, const {type}* handle_struct, CommonObjectInfoTable* object_info_table);'
                .format(type=struct),
                file=self.outFile
            )
            self.newline()

        for struct in self.output_structs:
            if struct in self.structs_with_handle_ptrs:
                write(
                    'void SetStructHandleLengths(Decoded_{type}* wrapper);'.
                    format(type=struct),
                    file=self.outFile
                )
                self.newline()

        write(
            '#include "decode/common_struct_handle_mappers.h"',
            file=self.outFile
        )
