#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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
from dx12_base_generator import Dx12BaseGenerator, write


class Dx12StructObjectMappersBodyGenerator(Dx12BaseGenerator):
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

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = {
            **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE':
            ['ptr']
        }
        self.structs_with_handle_ptrs = []
        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs_with_handles = []
        self.structs_with_map_data = dict()

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
        # Generate handle adding functions for output structs with handles
        for struct in self.output_structs_with_handles:
            self.newline()
            write(
                self.make_struct_handle_additions(
                    struct, self.structs_with_handles[struct]
                ),
                file=self.outFile
            )

        # Generate handle memory allocation functions for output structs with handles
        for struct in self.output_structs_with_handles:
            if struct in self.structs_with_handle_ptrs:
                self.newline()
                write(
                    self.make_struct_handle_allocations(
                        struct, self.structs_with_handles[struct]
                    ),
                    file=self.outFile
                )

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

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

        platform_type = 'Dx12'
        map_types = 'Objects'
        map_table = ', const graphics::Dx12GpuVaMap& gpu_va_map'

        for struct in self.get_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
                or (struct in self.structs_with_map_data)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                handle_members = list()
                generic_handle_members = dict()

                if struct in self.structs_with_handles:
                    handle_members = self.structs_with_handles[struct].copy()

                if struct in self.structs_with_map_data:
                    handle_members.extend(
                        self.structs_with_map_data[struct].copy()
                    )

                if struct in self.GENERIC_HANDLE_STRUCTS:
                    generic_handle_members = self.GENERIC_HANDLE_STRUCTS[struct
                                                                         ]

                # Determine if the struct only contains members that are structs that contain handles or static arrays of handles,
                # and does not need a temporary variable referencing the struct value.
                needs_value_ptr = False
                if generic_handle_members:
                    needs_value_ptr = True
                else:
                    for member in handle_members:
                        if (
                            (
                                self.is_handle(member.base_type)
                                or self.is_class(member)
                            ) and
                            not (member.is_array and not member.is_dynamic)
                        ) or (member.base_type in self.MAP_STRUCT_TYPE):
                            needs_value_ptr = True
                            break

                body = '\n'
                body += 'void MapStruct{}(Decoded_{}* wrapper, const {}ObjectInfoTable& object_info_table{})\n'.format(
                    map_types, struct, platform_type, map_table
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

                body += self.make_struct_handle_mappings(
                    struct, handle_members, generic_handle_members
                )
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

        header_dict = self.source_dict['header_dict']
        self.structs_with_objects = self.collect_struct_with_objects(
            header_dict
        )
        self.write_struct_member_def()

    def write_struct_member_def(self):
        for k, v in self.structs_with_objects.items():
            # Ignore structs with arrays of objects when generating the AddStructObjects function.  There are currently no structs containing arrays of
            # objects that are used as output parameters, retrieving objects that need to be added to the object map.
            value_expr = ''
            for value in v:
                if self.is_struct(value.base_type):
                    value_expr += '    if(decoded_struct->{0} && new_value->{0})\n'\
                            '    {{\n'\
                            '        AddStructObjects(decoded_struct->{0}, new_value->{0}, object_info_table);\n'\
                            '    }}\n'.format(value.name)

                elif self.is_class(value) and (not value.is_array):
                    value_expr += '    if(decoded_struct->{0} && new_value->{0})\n'\
                            '    {{\n'\
                            '        object_mapping::AddObject(&decoded_struct->{0}, const_cast<{1}**>(&new_value->{0}), &object_info_table);\n'\
                            '    }}\n'.format(value.name, value.base_type)

            if value_expr:
                expr = 'void AddStructObjects(const StructPointerDecoder<Decoded_{0}>* capture_value, const {0}* new_value, Dx12ObjectInfoTable& object_info_table)\n'.format(
                    k
                )
                expr += '{\n'
                expr += '    auto decoded_struct = capture_value->GetMetaStructPointer();\n'

                expr += value_expr

                expr += '}\n'
                write(expr, file=self.outFile)

    def make_struct_handle_mappings(
        self, name, handle_members, generic_handle_members
    ):
        """Generating expressions for mapping struct handles read from the capture file to handles created at replay."""
        map_types = 'Objects'
        map_type = 'Object'
        base_type = 'object'
        object_info_table_get = ''
        given_object = ', gpu_va_map'

        body = ''
        for member in handle_members:
            body += '\n'
            map_func = self.MAP_STRUCT_TYPE.get(member.base_type)

            if map_func:
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
                    body += '        MapStructArray{}<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength(), object_info_table{});\n'.format(
                        map_types,
                        member.base_type,
                        given_object,
                        name=member.name
                    )
                elif member.is_pointer:
                    body += '        MapStructArray{}<Decoded_{}>(wrapper->{}->GetMetaStructPointer(), 1, object_info_table{});\n'.format(
                        map_types, member.base_type, member.name, given_object
                    )
                else:
                    body += '        MapStruct{}(wrapper->{}, object_info_table{});\n'.format(
                        map_types, member.name, given_object
                    )
            else:
                type = member.base_type

                # If it is an array or pointer, map with the utility function.
                if (member.is_array or member.pointer_count > 1):
                    if member.is_dynamic or member.is_pointer:
                        body += '        value->{name} = {}_mapping::Map{}Array<{type}>(&wrapper->{name}, object_info_table{});\n'.format(
                            base_type,
                            map_type,
                            object_info_table_get,
                            type=type,
                            name=member.name
                        )
                    else:
                        body += '        {}_mapping::Map{}Array<{type}>(&wrapper->{name}, object_info_table{});\n'.format(
                            base_type,
                            map_type,
                            object_info_table_get,
                            type=type,
                            name=member.name
                        )
                else:
                    body += '        value->{name} = {}_mapping::Map{}<{type}>(wrapper->{name}, object_info_table{});\n'.format(
                        base_type,
                        map_type,
                        object_info_table_get,
                        type=type,
                        name=member.name
                    )

        for member in generic_handle_members:
            body += '\n'
            body += '        value->{name} = {}_mapping::Map{}(wrapper->{name}, value->{}, object_info_table);\n'.format(
                base_type,
                map_type,
                generic_handle_members[member],
                name=member
            )

        return body

    def make_struct_handle_additions(self, name, members):
        """Generating expressions for adding mappings for handles created at replay that are embedded in structs."""
        object_info_table_add = ''
        platform_type = 'Dx12'
        map_types = 'Objects'
        map_type = 'Object'
        base_type = 'object'
        map_table = ', graphics::Dx12GpuVaMap* gpu_va_map'

        body = 'void AddStruct{}(format::HandleId parent_id, const Decoded_{name}* id_wrapper, const {name}* handle_struct, {}ObjectInfoTable* object_info_table{})\n'.format(
            map_types, platform_type, map_table, name=name
        )
        body += '{\n'
        body += '    if (id_wrapper != nullptr)\n'
        body += '    {\n'

        for member in members:

            if self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        AddStructArray{}<Decoded_{}>(parent_id, id_wrapper->{name}->GetMetaStructPointer(), id_wrapper->{name}->GetLength(), handle_struct->{name}, static_cast<size_t>(handle_struct->{length}), object_info_table);\n'.format(
                        map_types,
                        member.base_type,
                        name=member.name,
                        length=member.array_length
                    )
                elif member.is_pointer:
                    body += '        AddStructArray{}<Decoded_{}>(parent_id, id_wrapper->{name}->GetMetaStructPointer(), 1, handle_struct->{name}, 1, object_info_table);\n'.format(
                        map_types, member.base_type, name=member.name
                    )
                else:
                    body += '        AddStruct{}(parent_id, id_wrapper->{name}, &handle_struct->{name}, object_info_table);\n'.format(
                        map_types, name=member.name
                    )
            else:
                type = member.base_type

                # If it is an array or pointer, add with the utility function.
                if (member.is_array or member.pointer_count > 1):
                    if member.is_array:
                        body += '        {}_mapping::Add{}Array<{type}>(parent_id, id_wrapper->{name}.GetPointer(), id_wrapper->{name}.GetLength(), handle_struct->{name}, handle_struct->{length}, object_info_table{});\n'.format(
                            base_type,
                            map_type,
                            object_info_table_add,
                            type=type,
                            name=member.name,
                            length=member.array_length
                        )
                    else:
                        body += '        {}_mapping::Add{}Array<{type}>(parent_id, id_wrapper->{name}.GetPointer(), 1, handle_struct->{name}, 1, object_info_table{}});\n'.format(
                            base_type,
                            map_type,
                            object_info_table_add,
                            type=type,
                            name=member.name
                        )
                else:
                    body += '        {}_mapping::Add{}<{type}>(parent_id, id_wrapper->{name}, handle_struct->{name}, object_info_table{});\n'.format(
                        base_type,
                        map_type,
                        object_info_table_add,
                        type=type,
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
        map_type = 'Object'

        needs_value_ptr = False
        for member in members:
            if self.is_handle(
                member.base_type
            ) and not (member.is_array and not member.is_dynamic):
                needs_value_ptr = True
                break

        body = 'void SetStruct{}Lengths(Decoded_{name}* wrapper)\n'.format(
            map_type, name=name
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
            if self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        SetStructArray{}Lengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength());\n'.format(
                        map_type, member.base_type, name=member.name
                    )
                elif member.is_pointer:
                    body += '        SetStructArray{}Lengths<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), 1);\n'.format(
                        map_type, member.base_type, name=member.name
                    )
                else:
                    body += '        SetStruct{}Lengths(wrapper->{name});\n'.format(
                        map_type, name=member.name
                    )
            else:
                # If it is an array or pointer, add with the utility function.
                if (member.is_array or member.pointer_count > 1):
                    if member.is_array:
                        body += '        wrapper->{name}.Set{}Length(wrapper->{name}.GetLength());\n'.format(
                            map_type, name=member.name
                        )
                    else:
                        body += '        wrapper->{}.Set{}Length(1);\n'.format(
                            map_type, member.name
                        )

                    if member.is_dynamic or member.is_pointer:
                        body += '        value->{name} = wrapper->{name}.GetHandlePointer();\n'.format(
                            name=member.name
                        )

        body += '    }\n'
        body += '}'
        return body
