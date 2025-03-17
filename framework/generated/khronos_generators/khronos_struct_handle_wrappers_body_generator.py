#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019-2025 LunarG, Inc.
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

import re, sys
from khronos_base_generator import write


class KhronosStructHandleWrappersBodyGenerator():
    """KhronosStructHandleWrappersBodyGenerator
    Generates C++ functions responsible for wrapping struct member handles
    when recording Khrosos API call parameter data.
    """

    def write_special_case_struct_handling(self):
        """Method may be overridden"""
        return

    def generate_parent_child_handling(self, api_data, type):
        body = ''
        has_case = False
        if type in self.children_structs:
            type_var_name = api_data.struct_type_variable
            body += '        switch (value->{})\n'.format(type_var_name)
            body += '        {\n'
            body += '            default:\n'
            body += '                // Handle as parent-type below\n'
            body += '                break;\n'

            # Loop over each possible child
            has_case = False
            for child in self.children_structs[type]:
                if child not in self.structs_with_handles:
                    continue
                has_case = True
                switch_type = self.struct_type_names[child]

                body += f'            case {switch_type}:\n'
                body += f'                UnwrapStructHandles(reinterpret_cast<{child}*>(value),\n'
                body += f'                                 unwrap_memory);\n'
                body += '                // Return here because we processed the appropriate data in\n'
                body += '                // the correct structure type\n'
                body += '                return;\n'
            body += '        }\n'
            body += '\n'

        return body if has_case else ''

    def write_struct_handle_wrapper_content(self):
        api_data = self.get_api_data()
        ext_struct_name = api_data.extended_struct_func_prefix
        ext_var_name = api_data.extended_struct_variable
        type_var_name = api_data.struct_type_variable
        const_prefix = ''
        if api_data.return_const_ptr_on_extended:
            const_prefix = 'const '

        for struct in self.get_all_filtered_struct_names():
            if (
                (struct in self.structs_with_handles) or
                self.child_struct_has_handles(struct) or
                (struct in self.GENERIC_HANDLE_STRUCTS)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                handle_members = dict()
                generic_handle_members = dict()

                if struct in self.structs_with_handles:
                    handle_members = self.structs_with_handles[struct]
                if struct in self.GENERIC_HANDLE_STRUCTS:
                    generic_handle_members = self.GENERIC_HANDLE_STRUCTS[struct
                                                                         ]

                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory)\n'.format(
                    struct
                )
                
                body += '{\n'

                unwrapping = self.generate_parent_child_handling(api_data, struct)
                unwrapping += self.make_struct_handle_unwrappings(api_data, struct, handle_members, generic_handle_members)
                
                if unwrapping:
                    body += '    if (value != nullptr)\n'
                    body += '    {\n'
                    body += unwrapping
                    body += '    }\n'

                body += '}'

                write(body, file=self.outFile)

        # Generate the pNext shallow copy code, for pNext structs that don't have handles, but need to be preserved in the overall copy for handle wrapping.
        self.newline()
        write(
            '{0}* Copy{1}Struct(const {0}* base, HandleUnwrapMemory* unwrap_memory)'
            .format(api_data.base_in_struct, ext_struct_name),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(base != nullptr);', file=self.outFile)
        self.newline()
        write(
            '    {}* copy = nullptr;'.format(api_data.base_in_struct),
            file=self.outFile
        )
        write('    switch (base->{})'.format(type_var_name), file=self.outFile)
        write('    {', file=self.outFile)
        write('    default:', file=self.outFile)
        write(
            '        GFXRECON_LOG_WARNING("Failed to copy entire {0} chain when unwrapping handles due to unrecognized {1} %d", base->{1});'
            .format(ext_var_name, type_var_name),
            file=self.outFile
        )
        write('        break;', file=self.outFile)
        self.write_special_case_struct_handling()

        extended_list = []
        for struct in self.all_extended_structs:
            for ext_struct in self.all_extended_structs[struct]:
                if ext_struct not in extended_list and ext_struct not in self.all_struct_aliases:
                    extended_list.append(ext_struct)

        for base_type in sorted(extended_list):
            if base_type not in self.struct_type_names:
                continue

            stype = self.struct_type_names[base_type]
            write('    case {}:'.format(stype), file=self.outFile)
            write(
                '        copy = reinterpret_cast<{}*>(MakeUnwrapStructs(reinterpret_cast<const {}*>(base), 1, unwrap_memory));'
                .format(api_data.base_in_struct, base_type),
                file=self.outFile
            )
            write('        break;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return copy;', file=self.outFile)
        write('}', file=self.outFile)

        # Generate the extended struct handle wrapping code.
        self.newline()
        write(
            '{const}void* Unwrap{struct}StructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)'
            .format(const=const_prefix, struct=ext_struct_name),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        const {0}* base = reinterpret_cast<const {0}*>(value);'.
            format(api_data.base_in_struct),
            file=self.outFile
        )
        self.newline()
        write(
            '        switch (base->{})'.format(type_var_name),
            file=self.outFile
        )
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            // This structure does not contain handles, but may point to a structure that does.',
            file=self.outFile
        )
        write(
            '            {}* copy = Copy{}Struct(base, unwrap_memory);'.format(
                api_data.base_in_struct, ext_struct_name
            ),
            file=self.outFile
        )
        write('            if (copy != nullptr)', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                copy->{2} = reinterpret_cast<const {0}*>(Unwrap{1}StructHandles(base->{2}, unwrap_memory));'
            .format(api_data.base_in_struct, ext_struct_name, ext_var_name),
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('            return copy;', file=self.outFile)
        write('        }', file=self.outFile)
        for base_type in sorted(extended_list):
            if (
                base_type in self.structs_with_handles
                and base_type in self.struct_type_names
            ):
                stype = self.struct_type_names[base_type]
                write('        case {}:'.format(stype), file=self.outFile)
                write(
                    '            return UnwrapStructPtrHandles(reinterpret_cast<const {}*>(base), unwrap_memory);'
                    .format(base_type),
                    file=self.outFile
                )
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return nullptr;', file=self.outFile)
        write('}', file=self.outFile)

    def has_special_case_handle_unwrapping(self, name):
        """Method may be overridden."""
        return False

    def get_special_case_handle_wrapping(self, name):
        """Method may be overridden."""
        return

    def make_struct_handle_unwrappings(
        self, api_data, name, handle_members, generic_handle_members
    ):
        """Generating expressions for unwrapping struct handles before an API call."""
        body = ''

        for member in handle_members:
            if member.name == api_data.extended_struct_variable:
                body += '        if (value->{} != nullptr)\n'.format(
                    member.name
                )
                body += '        {\n'
                if self.has_special_case_handle_unwrapping(name):
                    body += self.get_special_case_handle_wrapping(name)
                else:
                    body += '            value->{0} = Unwrap{1}StructHandles(value->{0}, unwrap_memory);\n'.format(
                        member.name, api_data.extended_struct_func_prefix
                    )
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    if api_data.return_const_ptr_on_extended:
                        body += '        value->{name} = UnwrapStructArrayHandles(value->{name}, value->{}, unwrap_memory);\n'.format(
                            member.array_length, name=member.name
                        )
                    else:
                        if 'const' in member.full_type:
                            temp_type = member.full_type
                            full_type_non_const = re.sub(' const ', '', temp_type)
                            full_type_non_const = re.sub(
                                'const ', '', full_type_non_const
                            )
                            full_type_non_const = re.sub(
                                ' const', '', full_type_non_const
                            )
                            variable_name = f'const_cast<{full_type_non_const}>(value->{member.name})'
                        else:
                            variable_name = f'value->{member.name}'

                        length_exprs = member.array_length.split(',')
                        length_count = len(length_exprs)

                        if member.pointer_count > 1 and length_count < member.pointer_count:
                            unwrap_function = 'UnwrapStructPtrArrayHandles'
                        else:
                            unwrap_function = 'UnwrapStructArrayHandles'

                        body += f'        value->{member.name} = {unwrap_function}({variable_name}, value->{member.array_length}, unwrap_memory);\n'
                elif member.is_pointer:
                    body += '        value->{name} = UnwrapStructPtrHandles(value->{name}, unwrap_memory);\n'.format(
                        name=member.name
                    )
                else:
                    body += '        UnwrapStructHandles(&value->{}, unwrap_memory);\n'.format(
                        member.name
                    )
        return body
