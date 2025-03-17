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


class KhronosStructHandleMappersBodyGenerator():
    """Base class for generating struct handle mappers body code."""

    # Recursively search a structs members to see if they too belong in the
    # output struct list.  This could be because an including struct is an
    # output struct.
    def process_struct_members_to_output_struct(self, value):
        for member in self.all_struct_members[value.base_type]:
            if (
                self.is_struct(member.base_type)
                and not self.is_struct_black_listed(member.base_type)
                and (member.base_type in self.structs_with_handles)
                and (member.base_type not in self.output_structs)
            ):
                self.output_structs.append(member.base_type)
                self.process_struct_members_to_output_struct(member)

    def write_struct_handle_wrapper_content(self):
        for struct in self.get_all_filtered_struct_names():
            if struct in self.STRUCT_MAPPERS_BLACKLIST:
                continue

            child_has_handles = self.child_struct_has_handles(struct)
            if ( child_has_handles or
                (struct in self.structs_with_handles) or
                (struct in self.GENERIC_HANDLE_STRUCTS)
            ):
                handle_members = list()
                generic_handle_members = dict()

                if struct in self.structs_with_handles:
                    handle_members = self.structs_with_handles[struct].copy()

                if struct in self.GENERIC_HANDLE_STRUCTS:
                    generic_handle_members = self.GENERIC_HANDLE_STRUCTS[struct
                                                                         ]

                # Determine if the struct only contains members that are structs that contain handles or static arrays of handles,
                # and does not need a temporary variable referencing the struct value.
                needs_value_ptr = False
                if generic_handle_members or child_has_handles:
                    needs_value_ptr = True
                else:
                    for member in handle_members:
                        if (
                            (self.is_handle_like(member.base_type)) and
                            not (member.is_array and not member.is_dynamic)
                        ) or (member.base_type in self.MAP_STRUCT_TYPE):
                            needs_value_ptr = True
                            break

                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const CommonObjectInfoTable& object_info_table)\n'.format(
                    struct
                )
                body += '{\n'

                if not needs_value_ptr:
                    body += '    if (wrapper != nullptr)\n'
                    body += '    {'
                else:
                    body += '    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))\n'
                    body += '    {\n'
                    body += '        {}* value = wrapper->decoded_value;\n'.format(
                        struct
                    )

                    # Add handling for parent/child structs since this actually might be one of the children.
                    if child_has_handles:
                        type_var = self.get_struct_type_var_name()
                        body += '\n'
                        body += f'        switch (value->{type_var})\n'
                        body += '        {\n'
                        body += '            default:\n'
                        body += '                // Handle as base-type below\n'
                        body += '                break;\n'

                        for child in self.children_structs[struct]:
                            if child not in self.structs_with_handles:
                                continue
                            switch_type = self.struct_type_names[child]

                            body += f'            case {switch_type}:\n'
                            body += f'                MapStructHandles(reinterpret_cast<Decoded_{child}*>(wrapper),\n'
                            body += f'                                 object_info_table);\n'
                            body += '                // Return here because we processed the appropriate data in\n'
                            body += '                // the correct structure type\n'
                            body += '                return;\n'
                        body += '        }\n'

                body += self.make_struct_handle_mappings(
                    struct, handle_members, generic_handle_members
                )
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

        # Print out a function to handle mapping the extended struct types
        self.newline()
        next_field = self.get_extended_struct_var_name()
        next_var = next_field.lower()
        type_var = self.get_struct_type_var_name()
        cast_type = 'const {}MetaStructHeader*'.format(self.get_api_prefix())

        lines = []
        lines.append('void Map{func}StructHandles({node}Node* {var}, const CommonObjectInfoTable& object_info_table)'.format(
                func=self.get_extended_struct_func_prefix(),
                node=self.get_extended_struct_node_prefix(),
                var=next_var
            )
        )
        lines.append('{')
        lines.append(f'    while ({next_var})')
        lines.append('    {')
        lines.append(f'        void *wrapper = {next_var}->GetMetaStructPointer();')
        lines.append(f'        const auto* header = reinterpret_cast<{cast_type}>({next_var}->GetMetaStructPointer());')
        lines.append('')
        lines.append(f'        switch (*header->{type_var})')
        lines.append('        {')
        lines.append('        default:')
        lines.append(f'            // TODO: Report or raise fatal error for unrecognized {type_var}?')
        lines.append('            break;')
        write('\n'.join(lines), file=self.outFile)

        extended_list = []
        for struct in self.all_extended_structs:
            for ext_struct in self.all_extended_structs[struct]:
                if ext_struct not in extended_list and ext_struct not in self.all_struct_aliases:
                    extended_list.append(ext_struct)

        for base_type in sorted(extended_list):
            if base_type in self.structs_with_handles:
                write(
                    '        case {}:'.format(self.struct_type_names[base_type]),
                    file=self.outFile
                )
                write(
                    '            MapStructHandles(reinterpret_cast<Decoded_{}*>(wrapper), object_info_table);'
                    .format(base_type),
                    file=self.outFile
                )
                write('            break;', file=self.outFile)

        write('        }', file=self.outFile)
        write(f'        {next_var} = header->{next_field};', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs = []

        # Look for output structs that contain handles and add to list
        for cmd in self.get_all_filtered_cmd_names():
            for value_info in self.all_cmd_params[cmd][2]:
                if self.is_output_parameter(value_info) and self.is_struct(
                    value_info.base_type
                ) and (value_info.base_type in self.structs_with_handles
                       ) and (value_info.base_type not in self.output_structs):
                    self.output_structs.append(value_info.base_type)
                    self.process_struct_members_to_output_struct(value_info)

        # Generate handle adding functions for output structs with handles
        for struct in self.output_structs:
            self.newline()
            write(
                self.make_struct_handle_additions(
                    struct, self.structs_with_handles[struct]
                ),
                file=self.outFile
            )

        # Generate handle memory allocation functions for output structs with handles
        for struct in self.output_structs:
            if struct in self.structs_with_handle_ptrs:
                self.newline()
                write(
                    self.make_struct_handle_allocations(
                        struct, self.structs_with_handles[struct]
                    ),
                    file=self.outFile
                )

    def make_struct_handle_mappings(
        self, name, handle_members, generic_handle_members
    ):
        """Generating expressions for mapping struct handles read from the capture file to handles created at replay."""
        prefix_from_type = self.get_api_prefix_from_type(name)

        body = ''
        for member in handle_members:
            body += '\n'
            map_func = self.MAP_STRUCT_TYPE.get(member.base_type)

            if self.is_extended_struct_definition(member):
                func_id = self.get_extended_struct_func_prefix()
                body += f'        if (wrapper->{member.name})\n'
                body += '        {\n'
                body += f'            Map{func_id}StructHandles(wrapper->{member.name}, object_info_table);\n'
                body += '        }\n'
            elif map_func:
                if member.is_array:
                    body += '    if ({0})\n'\
                            '    {{\n'\
                            '        object_mapping::{2}(value->{0}->GetPointer(), {1}, {3});\n'\
                            '    }}\n'.format(
                        member.name, member.array_length, map_func[1], map_func[2]
                    )
                else:
                    if member.is_pointer:
                        body += '    if ({0})\n'\
                                '    {{\n'\
                                '        object_mapping::{1}(value->{0}->GetPointer(), {2});\n'\
                                '    }}\n'.format(
                            member.name, map_func[0], map_func[2]
                        )
                    else:
                        body += '        object_mapping::{}(value->{}, {});\n'.format(
                            map_func[0], member.name, map_func[2]
                        )
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    length_exprs = member.array_length.split(',')
                    length_count = len(length_exprs)

                    if member.pointer_count > 1 and length_count < member.pointer_count:
                        unwrap_function = f'MapStructPtrArrayHandles<Decoded_{member.base_type}*>'
                    else:
                        unwrap_function = f'MapStructArrayHandles<Decoded_{member.base_type}>'

                    body += '        {func}(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength(), object_info_table);\n'.format(
                        func=unwrap_function,
                        name=member.name
                    )
                elif member.is_pointer:
                    body += '        MapStructArrayHandles<Decoded_{}>(wrapper->{}->GetMetaStructPointer(), 1, object_info_table);\n'.format(
                        member.base_type, member.name
                    )
                else:
                    body += '        MapStructHandles(wrapper->{}, object_info_table);\n'.format(
                        member.name
                    )
            else:
                type = member.base_type
                prefix_from_type = self.get_api_prefix_from_type(member.base_type)
                func_id = member.base_type + 'Info'
                type = prefix_from_type + member.base_type[2:] + 'Info'
                object_info_table_get = ', &CommonObjectInfoTable::Get{}'.format(
                    func_id
                )

                # If it is an array or pointer, map with the utility function.
                if (member.is_array or member.is_pointer):
                    if member.is_dynamic or member.is_pointer:
                        body += '        value->{name} = handle_mapping::MapHandleArray<{type}>(&wrapper->{name}, object_info_table{});\n'.format(
                            object_info_table_get,
                            type=type,
                            name=member.name
                        )
                    else:
                        body += '        handle_mapping::MapHandleArray<{type}>(&wrapper->{name}, object_info_table{});\n'.format(
                            object_info_table_get,
                            type=type,
                            name=member.name
                        )
                else:
                    body += '        value->{name} = handle_mapping::MapHandle<{type}>(wrapper->{name}, object_info_table{});\n'.format(
                        object_info_table_get,
                        type=type,
                        name=member.name
                    )

        for member in generic_handle_members:
            body += '\n'
            body += '        value->{name} = handle_mapping::MapHandle(wrapper->{name}, value->{}, object_info_table);\n'.format(
                generic_handle_members[member],
                name=member
            )

        return body

    def make_struct_handle_additions(self, name, members):
        """Generating expressions for adding mappings for handles created at replay that are embedded in structs."""
        platform_type = self.get_api_prefix()

        body = 'void AddStructHandles(format::HandleId parent_id, const Decoded_{name}* id_wrapper, const {name}* handle_struct, CommonObjectInfoTable* object_info_table)\n'.format(
            name=name
        )
        body += '{\n'
        body += '    if (id_wrapper != nullptr)\n'
        body += '    {\n'

        for member in members:
            if self.is_extended_struct_definition(member):
                func_id = self.get_extended_struct_func_prefix()
                body += f'        if (id_wrapper->{member.name})\n'
                body += '        {\n'
                body += f'            Add{func_id}StructHandles(parent_id, id_wrapper->{member.name}->GetPointer(), id_wrapper->{member.name}->GetMetaStructPointer(), handle_struct->{member.name}, object_info_table);\n'
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        AddStructArrayHandles<Decoded_{}>(parent_id, id_wrapper->{name}->GetMetaStructPointer(), id_wrapper->{name}->GetLength(), handle_struct->{name}, static_cast<size_t>(handle_struct->{length}), object_info_table);\n'.format(
                        member.base_type,
                        name=member.name,
                        length=member.array_length
                    )
                elif member.is_pointer:
                    body += '        AddStructArrayHandles<Decoded_{}>(parent_id, id_wrapper->{name}->GetMetaStructPointer(), 1, handle_struct->{name}, 1, object_info_table);\n'.format(
                        member.base_type, name=member.name
                    )
                else:
                    body += '        AddStructHandles(parent_id, id_wrapper->{name}, &handle_struct->{name}, object_info_table);\n'.format(
                        name=member.name
                    )
            else:
                type = member.base_type
                func_id = member.base_type + 'Info'
                type = platform_type + member.base_type[2:] + 'Info'
                object_info_table_add = ', &CommonObjectInfoTable::Add{}'.format(
                    func_id
                )

                # If it is an array or pointer, add with the utility function.
                if (member.is_array or member.is_pointer):
                    if member.is_array:
                        body += '        handle_mapping::AddHandleArray<{}>(parent_id, id_wrapper->{name}.GetPointer(), id_wrapper->{name}.GetLength(), handle_struct->{name}, handle_struct->{length}, object_info_table{});\n'.format(
                            type,
                            object_info_table_add,
                            name=member.name,
                            length=member.array_length
                        )
                    else:
                        body += '        handle_mapping::AddHandleArray<{}>(parent_id, id_wrapper->{name}.GetPointer(), 1, handle_struct->{name}, 1, object_info_table{}});\n'.format(
                            type,
                            object_info_table_add,
                            name=member.name
                        )
                else:
                    body += '        handle_mapping::AddHandle<{}>(parent_id, id_wrapper->{name}, handle_struct->{name}, object_info_table{});\n'.format(
                        type,
                        object_info_table_add,
                        name=member.name
                    )

        body += '    }\n'
        body += '}'
        return body

    def make_struct_handle_allocations(self, name, members):
        """Generate expressions to allocate memory for handles created at replay that are embedded in structs.
        Determine if the struct only contains members that are structs that contain handles or static arrays of handles,
        and does not need a temporary variable referencing the struct value.
        """
        needs_value_ptr = False
        for member in members:
            if self.is_handle(
                member.base_type
            ) and not (member.is_array and not member.is_dynamic):
                needs_value_ptr = True
                break

        body = 'void SetStructHandleLengths(Decoded_{name}* wrapper)\n'.format(
            name=name
        )
        body += '{\n'

        if not needs_value_ptr:
            body += '    if (wrapper != nullptr)\n'
            body += '    {\n'
        else:
            body += '    if ((wrapper != nullptr) && (wrapper->decoded_value != nullptr))\n'
            body += '    {\n'
            body += '        {}* value = wrapper->decoded_value;\n'.format(
                name
            )
            body += '\n'

        for member in members:
            if self.is_extended_struct_definition(member):
                func_id = self.get_extended_struct_func_prefix()
                body += f'        if (wrapper->{member.name})\n'
                body += '        {\n'
                body += f'            Set{func_id}StructHandleLengths(wrapper->{member.name}->GetPointer(), wrapper->{member.name}->GetMetaStructPointer());\n'
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        SetStructArrayHandleLengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength());\n'.format(
                        member.base_type, name=member.name
                    )
                elif member.is_pointer:
                    body += '        SetStructArrayHandleLengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), 1);\n'.format(
                        member.base_type, name=member.name
                    )
                else:
                    body += '        SetStructHandleLengths(wrapper->{name});\n'.format(
                        name=member.name
                    )
            else:
                # If it is an array or pointer, add with the utility function.
                if (member.is_array or member.is_pointer):
                    if member.is_array:
                        body += '        wrapper->{name}.SetHandleLength(wrapper->{name}.GetLength());\n'.format(
                            name=member.name
                        )
                    else:
                        body += '        wrapper->{}.SetHandleLength(1);\n'.format(
                            member.name
                        )

                    if member.is_dynamic or member.is_pointer:
                        body += '        value->{name} = wrapper->{name}.GetHandlePointer();\n'.format(
                            name=member.name
                        )

        body += '    }\n'
        body += '}'
        return body
