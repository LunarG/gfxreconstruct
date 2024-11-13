#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
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


class KhronosStructHandleWrappersHeaderGenerator():
    """KhronosStructHandleWrappersHeaderGeneratorVulk
    Generates C++ function prototypes for wrapping struct member handles
    when recording Khronos API call parameter data.
    """

    def wriate_struct_handle_wrapper_content(self):
        """Method override."""
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
                    for member in self.all_struct_members[value.base_type]:
                        if self.is_struct(member.base_type) and (
                            member.base_type in self.structs_with_handles
                            and member.base_type not in self.output_structs
                        ):
                            self.output_structs.append(member.base_type)

        # Generate unwrap and rewrap code for input structures.
        for struct in self.get_all_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
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

        self.newline()
        write(
            '{0}* Copy{1}Struct(const {0}* base, HandleUnwrapMemory* unwrap_memory);'.format(api_data.base_in_struct, api_data.extended_struct_func_prefix),
            file=self.outFile
        )
        self.newline()
        write(
            '{}void* Unwrap{}StructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);'.format(const_prefix, api_data.extended_struct_func_prefix),
            file=self.outFile
        )
        self.newline()
        write(
            'template <typename ParentWrapper, typename CoParentWrapper, typename T>',
            file=self.outFile
        )
        write(
            'void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id);',
            file=self.outFile
        )
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));',
            file=self.outFile
        )
        self.newline()
        write(
            '    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);',
            file=self.outFile
        )
        write(
            '    size_t         num_bytes = len * sizeof(T);',
            file=self.outFile
        )
        self.newline()
        write(
            '    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));',
            file=self.outFile
        )
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            '{}T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)'.format(const_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    T* unwrapped_struct = nullptr;', file=self.outFile)
        self.newline()
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);',
            file=self.outFile
        )
        write(
            '        UnwrapStructHandles(unwrapped_struct, unwrap_memory);',
            file=self.outFile
        )
        write('    }', file=self.outFile)
        self.newline()
        write('    return unwrapped_struct;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

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
            '{} T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)'.format(const_prefix),
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

    def generate_create_wrapper_funcs(self):
        """Generates functions that wrap struct handle members."""
        for struct in self.output_structs:
            body = 'template <typename ParentWrapper, typename CoParentWrapper>\n'
            body += 'void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, {}* value, PFN_GetHandleId get_id)\n'.format(
                struct
            )
            body += '{\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'

            for member in self.structs_with_handles[struct]:
                wrapper_prefix = self.get_wrapper_prefix_from_type(member.base_type)
                func_target = self.get_handle_like_func_name_modifier(member.base_type)

                if self.is_struct(member.base_type):
                    if member.is_array:
                        body += '        {}::CreateWrappedStructArray{}s<ParentWrapper, CoParentWrapper, {}>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, member.base_type, member.name, member.array_length
                        )
                    elif member.is_pointer:
                        body += '        {}::CreateWrappedStruct{}s<ParentWrapper, CoParentWrapper>(parent, co_parent, value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, member.name
                        )
                    else:
                        body += '        {}::CreateWrappedStruct{}s<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, member.name
                        )
                else:
                    if member.is_array:
                        body += '        {}::CreateWrapped{}s<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, wrapper_prefix, member.base_type[2:], member.name, member.array_length
                        )
                    elif member.is_pointer:
                        body += '        {}::CreateWrapped{}<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, wrapper_prefix, member.base_type[2:], member.name
                        )
                    else:
                        body += '        {}::CreateWrapped{}<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, &value->{}, get_id);\n'.format(
                            wrapper_prefix, func_target, wrapper_prefix, member.base_type[2:], member.name
                        )

            body += '    }\n'
            body += '}\n'
            write(body, file=self.outFile)
