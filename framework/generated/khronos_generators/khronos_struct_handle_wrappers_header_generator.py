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

import sys
from khronos_base_generator import write


class KhronosStructHandleWrappersHeaderGenerator():
    """KhronosStructHandleWrappersHeaderGeneratorVulk
    Generates C++ function prototypes for wrapping struct member handles
    when recording Khronos API call parameter data.
    """

    def write_struct_handle_wrapper_content(self):
        # Generate unwrap and rewrap code for input structures.
        for struct in self.get_all_filtered_struct_names():
            if (
                (struct in self.structs_with_handles) or
                self.child_struct_has_handles(struct) or
                (struct in self.GENERIC_HANDLE_STRUCTS)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory);'.format(
                    struct
                )
                write(body, file=self.outFile)

        api_data = self.get_api_data()
        const_prefix = ''
        if api_data.return_const_ptr_on_extended:
            const_prefix = 'const '
        func_prefix = api_data.extended_struct_func_prefix
        in_struct   = api_data.base_in_struct

        lines = ['']
        lines.append(f'{in_struct}* Copy{func_prefix}Struct(const {in_struct}* base, HandleUnwrapMemory* unwrap_memory);')
        lines.append('')
        lines.append(f'{const_prefix}void* Unwrap{func_prefix}StructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);')
        lines.append('')
        lines.append('template <typename ParentWrapper, typename CoParentWrapper, typename T>')
        lines.append( 'void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id);')
        lines.append('')
        lines.append('template <typename T>')
        lines.append('T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)')
        lines.append('{')
        lines.append('    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));')
        lines.append('')
        lines.append('    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);')
        lines.append('    size_t         num_bytes = len * sizeof(T);')
        lines.append('')
        lines.append('    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));')
        lines.append('}')
        lines.append('')
        lines.append('template <typename T>')
        lines.append(f'{const_prefix}T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)')
        lines.append('{')
        lines.append('    T* unwrapped_struct = nullptr;')
        lines.append('')
        lines.append('    if (value != nullptr)')
        lines.append('    {')
        lines.append('        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);')
        lines.append('        UnwrapStructHandles(unwrapped_struct, unwrap_memory);')
        lines.append('    }')
        lines.append('')
        lines.append('    return unwrapped_struct;')
        lines.append('}')
        lines.append('')
        write('\n'.join(lines), file=self.outFile)

        self.generate_create_wrapper_funcs()

        write(
            'template <typename ParentWrapper, typename CoParentWrapper, typename T>',
            file=self.outFile
        )
        write(
            'void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

        write('template <typename T>', file=self.outFile)
        write(
            f'{const_prefix}T* UnwrapStructArrayHandles({const_prefix}T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if ((values != nullptr) && (len > 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        self.newline()
        write('        return unwrapped_structs;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write(
            '    // Leave the original memory in place when the pointer is not null, but size is zero.',
            file=self.outFile
        )
        write('    return values;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'T* UnwrapStructPtrArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if ((values != nullptr) && (len > 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            UnwrapStructHandles(unwrapped_structs[i], unwrap_memory);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        self.newline()
        write('        return unwrapped_structs;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write(
            '    // Leave the original memory in place when the pointer is not null, but size is zero.',
            file=self.outFile
        )
        write('    return values;', file=self.outFile)
        write('}', file=self.outFile)

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

    def generate_create_wrapper_funcs(self):
        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.output_structs = [
        ]  # Output structures that retrieve handles, which need to be wrapped.

        # Check for output structures, which retrieve handles that need to be wrapped.
        for cmd in self.all_cmd_params:
            info = self.all_cmd_params[cmd]
            values = info[2]

            for value in values:
                if self.is_output_parameter(value) and self.is_struct(
                    value.base_type
                ) and (value.base_type in self.structs_with_handles
                       ) and (value.base_type not in self.output_structs):
                    self.output_structs.append(value.base_type)
                    self.process_struct_members_to_output_struct(value)

        """Generates functions that wrap struct handle members."""
        for struct in self.output_structs:
            body = 'template <typename ParentWrapper, typename CoParentWrapper>\n'
            body += 'void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, {}* value, PFN_GetHandleId get_id)\n'.format(
                struct
            )
            body += '{\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'

            default_info = {
                    'indent': '        ',
                    'struct': '',
                    'plural': '',
                    'length': '',
                    'coparent_wrapper': '',
                    'coparent_arg': '',
                    'dref_value': '&',
                }
            for member in self.structs_with_handles[struct]:
                # Set up the information needed to generation the createwrapper call
                info = { **default_info }
                info['prefix'] = self.get_wrapper_prefix_from_type(member.base_type)
                info['target'] = self.get_handle_like_func_name_modifier(member.base_type)
                info['name'] = member.name
                if not (self.is_atom(member.base_type) or self.is_opaque(member.base_type)):
                    info['coparent_wrapper'] = ', CoParentWrapper'
                    info['coparent_arg'] = 'co_parent, '

                if member.is_array or member.is_pointer:
                    info['dref_value'] = ''

                if self.is_struct(member.base_type):
                    info['type'] = member.base_type
                    info['plural'] = 's'
                    if member.is_array:
                        info['wrapper'] = ', ' + member.base_type
                        info['struct'] = 'StructArray'
                    else:
                        info['wrapper'] = ''
                        info['struct'] =  'Struct'
                else:
                    info['type'] = member.base_type[2:]
                    info['wrapper'] = ', {}::{}Wrapper'.format(info['prefix'], info['type'])

                if member.is_array:
                    info['length'] = 'value->{}, '.format(member.array_length)
                    info['plural'] = 's'

                wrapper_name ='        {prefix}::CreateWrapped{struct}{target}{plural}'.format(**info)
                wrapper_template = '<ParentWrapper{coparent_wrapper}{wrapper}>'.format(**info)
                wrapper_args ='(parent, {coparent_arg}{dref_value}value->{name}, {length}get_id);\n'.format(**info)
                body += wrapper_name + wrapper_template + wrapper_args

            body += '    }\n'
            body += '}\n'
            write(body, file=self.outFile)
