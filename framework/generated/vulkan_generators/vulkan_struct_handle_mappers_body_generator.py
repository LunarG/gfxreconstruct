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

import os, re, sys
from base_generator import *


class VulkanStructHandleMappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to map Vulkan struct member handles at file replay."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        BaseGeneratorOptions.__init__(
            self, blacklists, platform_types, filename, directory, prefix_text,
            protect_file, protect_feature
        )


class VulkanStructHandleMappersBodyGenerator(BaseGenerator):
    """VulkanStructHandleMappersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions responsible for mapping struct member handles
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
        self.pnext_structs = dict(
        )  # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain.
        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs_with_handles = []

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_vulkan_struct_decoders.h"',
            file=self.outFile
        )
        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write(
            '#include "decode/vulkan_handle_mapping_util.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_decoders.h"',
            file=self.outFile
        )
        self.newline()
        write('#include <algorithm>', file=self.outFile)
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        # Generate the pNext handle mapping code.
        self.newline()
        write(
            'void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectInfoTable& object_info_table)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    if ((value != nullptr) && (wrapper != nullptr))',
            file=self.outFile
        )
        write('    {', file=self.outFile)
        write(
            '        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);',
            file=self.outFile
        )
        write('', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write(
            '            // TODO: Report or raise fatal error for unrecongized sType?',
            file=self.outFile
        )
        write('            break;', file=self.outFile)
        for base_type in self.pnext_structs:
            write(
                '        case {}:'.format(self.pnext_structs[base_type]),
                file=self.outFile
            )
            write(
                '            MapStructHandles(reinterpret_cast<Decoded_{}*>(wrapper), object_info_table);'
                .format(base_type),
                file=self.outFile
            )
            write('            break;', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

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
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            if self.check_struct_member_handles(
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            ):
                # Track this struct if it can be present in a pNext chain, for generating the MapPNextStructHandles code.
                parent_structs = typeinfo.elem.get('structextends')
                if parent_structs:
                    stype = self.make_structure_type_enum(typeinfo, typename)
                    if stype:
                        self.pnext_structs[typename] = stype

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
        for struct in self.get_filtered_struct_names():
            if (struct in self.structs_with_handles
                ) or (struct in self.GENERIC_HANDLE_STRUCTS):
                handle_members = dict()
                generic_handle_members = dict()

                if struct in self.structs_with_handles:
                    handle_members = self.structs_with_handles[struct]
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
                        if self.is_handle(
                            member.base_type
                        ) and not (member.is_array and not member.is_dynamic):
                            needs_value_ptr = True
                            break

                body = '\n'
                body += 'void MapStructHandles(Decoded_{}* wrapper, const VulkanObjectInfoTable& object_info_table)\n'.format(
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

                body += self.make_struct_handle_mappings(
                    struct, handle_members, generic_handle_members
                )
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

    def make_struct_handle_mappings(
        self, name, handle_members, generic_handle_members
    ):
        """Generating expressions for mapping struct handles read from the capture file to handles created at replay."""
        body = ''

        for member in handle_members:
            body += '\n'

            if 'pNext' in member.name:
                body += '        if (wrapper->pNext)\n'
                body += '        {\n'
                body += '            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_info_table);\n'
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        MapStructArrayHandles<Decoded_{}>(wrapper->{name}->GetMetaStructPointer(), wrapper->{name}->GetLength(), object_info_table);\n'.format(
                        member.base_type, name=member.name
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
                # If it is an array or pointer, map with the utility function.
                if (member.is_array or member.is_pointer):
                    if member.is_dynamic or member.is_pointer:
                        body += '        value->{name} = handle_mapping::MapHandleArray<{type}Info>(&wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(
                            type=member.base_type[2:], name=member.name
                        )
                    else:
                        body += '        handle_mapping::MapHandleArray<{type}Info>(&wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(
                            type=member.base_type[2:], name=member.name
                        )
                else:
                    body += '        value->{name} = handle_mapping::MapHandle<{type}Info>(wrapper->{name}, object_info_table, &VulkanObjectInfoTable::Get{type}Info);\n'.format(
                        type=member.base_type[2:], name=member.name
                    )

        for member in generic_handle_members:
            body += '\n'
            body += '        value->{name} = handle_mapping::MapHandle(wrapper->{name}, value->{}, object_info_table);\n'.format(
                generic_handle_members[member], name=member
            )

        return body

    def make_struct_handle_additions(self, name, members):
        """Generating expressions for adding mappings for handles created at replay that are embedded in structs."""
        body = 'void AddStructHandles(format::HandleId parent_id, const Decoded_{name}* id_wrapper, const {name}* handle_struct, VulkanObjectInfoTable* object_info_table)\n'.format(
            name=name
        )
        body += '{\n'
        body += '    if (id_wrapper != nullptr)\n'
        body += '    {\n'

        for member in members:

            if 'pNext' in member.name:
                body += '        if (id_wrapper->pNext)\n'
                body += '        {\n'
                body += '            AddPNextStructHandles(parent_id, id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_info_table);\n'
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
                # If it is an array or pointer, add with the utility function.
                if (member.is_array or member.is_pointer):
                    if member.is_array:
                        body += '        handle_mapping::AddHandleArray<{type}Info>(parent_id, id_wrapper->{name}.GetPointer(), id_wrapper->{name}.GetLength(), handle_struct->{name}, handle_struct->{length}, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(
                            type=member.base_type[2:],
                            name=member.name,
                            length=member.array_length
                        )
                    else:
                        body += '        handle_mapping::AddHandleArray<{type}Info>(parent_id, id_wrapper->{name}.GetPointer(), 1, handle_struct->{name}, 1, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(
                            type=member.base_type[2:], name=member.name
                        )
                else:
                    body += '        handle_mapping::AddHandle<{type}Info>(parent_id, id_wrapper->{name}, handle_struct->{name}, object_info_table, &VulkanObjectInfoTable::Add{type}Info);\n'.format(
                        type=member.base_type[2:], name=member.name
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
                needs_value_ptr = False
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
            if 'pNext' in member.name:
                body += '        if (wrapper->pNext)\n'
                body += '        {\n'
                body += '            SetPNextStructHandleLengths(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer());\n'
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
