#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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

from khronos_base_generator import write


class KhronosStructDecodersHeaderGenerator():
    """Base class for generating struct decoder header code."""

    # @note decoded_value must always be the first member of a decode struct so that
    # generated code following extended struct chains can use it to get to the sType in the raw
    # struct despite the type erasure.
    def endFile(self):
        """Performs C++ code generation."""
        for struct in self.get_all_filtered_struct_names():
            if (
                struct in self.all_struct_aliases
                or struct in self.all_union_aliases
                or struct in self.children_structs
            ):
                continue

            body = '\n'
            body += 'struct Decoded_{}\n'.format(struct)
            body += '{\n'
            body += '    using struct_type = {};\n'.format(struct)
            body += '\n'
            body += '    {}* decoded_value{{ nullptr }};\n'.format(struct)

            decls = self.make_member_declarations(
                struct, self.all_struct_members[struct]
            )
            if decls:
                body += '\n'
                body += decls

            body += '};'
            write(body, file=self.outFile)

        # Write typedefs for any aliases
        for struct in self.all_struct_aliases:
            body = '\n'
            body += 'typedef Decoded_{} Decoded_{};'.format(
                self.all_struct_aliases[struct], struct
            )
            write(body, file=self.outFile)

        api_data = self.get_api_data()
        var_name = api_data.type_prefix.lower() + '_type'
        struct_type = api_data.struct_type_enum

        for struct in self.get_all_filtered_struct_names():
            if (
                struct in self.all_struct_aliases
                or struct in self.all_union_aliases
                or struct not in self.children_structs
            ):
                continue

            size_union_name = f'{struct}SizeUnion'
            body = '\n'
            body += 'union {}\n'.format(size_union_name)
            body += '{\n'
            current_char = 'a'
            for child in self.base_header_structs[struct]:
                body += '    {} {};\n'.format(child, current_char)
                current_char = chr(ord(current_char) + 1)
            body += '};\n\n'

            body += 'struct Decoded_{}\n'.format(struct)
            body += '{\n'
            body += '    using struct_type = {};\n'.format(struct)
            body += '    using union_size_type = {};\n'.format(size_union_name)
            body += '\n'
            body += '    {}* decoded_value{{ nullptr }};\n'.format(struct)
            body += '\n'
            body += '    static Decoded_{}* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)\n'.format(
                struct
            )
            body += '    {\n'
            body += '        Decoded_{}* return_type = nullptr;\n'.format(
                struct
            )
            body += '\n'
            body += '        // Peek at the actual structure type\n'
            body += '        uint32_t peek_structure_type = 0;\n'
            body += '        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);\n'
            body += '        {struct_type} {} = static_cast<{struct_type}>(peek_structure_type);\n'.format(
                var_name, struct_type=struct_type
            )
            body += '\n'
            body += '        switch ({})\n'.format(var_name)
            body += '        {\n'
            body += '            default:\n'
            body += '                return_type = DecodeAllocator::Allocate<Decoded_{}>(len, initialize);\n'.format(
                struct
            )
            body += '                break;\n'
            for child in self.base_header_structs[struct]:
                switch_type = self.generate_structure_type(child)

                body += '         case {}:\n'.format(switch_type)
                body += '             return_type = reinterpret_cast<Decoded_{}*>(DecodeAllocator::Allocate<Decoded_{}>(len, initialize));\n'.format(
                    struct, child
                )
                body += '             break;\n'
            body += '        }\n'
            body += '        return return_type;\n'
            body += '    }\n'
            body += '\n'
            body += '    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_{}* dest)\n'.format(
                struct
            )
            body += '    {\n'
            body += '        size_t   bytes_read          = 0;\n'
            body += '\n'
            body += '        // Peek at the actual structure type\n'
            body += '        uint32_t peek_structure_type = 0;\n'
            body += '        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);\n'
            body += '        {struct_type} {} = static_cast<{struct_type}>(peek_structure_type);\n'.format(
                var_name, struct_type=struct_type
            )
            body += '\n'
            body += '        switch ({})\n'.format(var_name)
            body += '        {\n'
            body += '            default:\n'
            body += '                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);\n'
            body += '                break;\n'
            for child in self.base_header_structs[struct]:
                switch_type = self.generate_structure_type(child)

                body += '            case {}:\n'.format(switch_type)
                body += '            {\n'
                body += '                Decoded_{}* local_dest = reinterpret_cast<Decoded_{}*>(dest);\n'.format(
                    child, child
                )
                body += '                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);\n'
                body += '                break;\n'
                body += '            }\n'
            body += '        }\n'
            body += '        return bytes_read;\n'
            body += '    }\n'
            body += '\n'
            body += '    {} *AllocateOutputData(size_t len)\n'.format(struct)
            body += '    {\n'
            body += '        assert(decoded_value);\n'
            body += '        {} struct_type = decoded_value->{};\n'.format(
                struct_type, api_data.struct_type_variable
            )
            body += '        {} *output_data = nullptr;\n'.format(struct)
            body += '\n'
            body += '        switch (struct_type)\n'
            body += '        {\n'
            body += '            default:\n'
            body += '                output_data = DecodeAllocator::Allocate<{}>(len);\n'.format(
                struct
            )
            body += '                break;\n'
            for child in self.base_header_structs[struct]:
                switch_type = self.generate_structure_type(child)

                body += '            case {}:\n'.format(switch_type)
                body += '            {\n'
                body += '                auto *allocation = DecodeAllocator::Allocate<{}>(len);\n'.format(
                    child
                )
                body += '                for (size_t i=0; i < len; i++)\n'
                body += '                {\n'
                body += '                    allocation[i] = {}{{ {} }};\n'.format(
                    child, switch_type
                )
                body += '                }\n'
                body += '                output_data = reinterpret_cast<{}*>(allocation);\n'.format(
                    struct
                )
                body += '                break;\n'
                body += '            }\n'
            body += '        }\n'
            body += '        return output_data;\n'
            body += '    }\n'

            decls = self.make_member_declarations(
                struct, self.all_struct_members[struct]
            )
            if decls:
                body += '\n'
                body += decls

            body += '};\n'
            write(body, file=self.outFile)

    def needs_member_declaration(self, name, value):
        """Determines if a struct member needs an associated member
        delcaration in the decoded struct wrapper.
        """
        if value.is_pointer or value.is_array:
            return True
        elif self.is_function_ptr(value.base_type):
            return True
        elif self.is_handle_like(value.base_type):
            return True
        elif self.is_struct(value.base_type):
            return True
        elif self.is_generic_struct_handle_value(name, value.name):
            return True
        return False

    def get_default_init_value(self, type):
        """Determines if the struct member requires default initalization and
        determines the value to use.
        """
        if type == 'format::HandleId':
            # These types represent values recorded for handles.
            return 'format::kNullHandleId'
        elif type == 'uint64_t':
            # These types represent values recorded for function pointers and void pointers to non-khronos objects.
            return '0'
        return None

    def make_member_declarations(self, name, values):
        """Generate the struct member declarations for the decoded struct wrapper."""
        body = ''

        for value in values:
            # If it is an extended struct name, it requires special treatment
            if self.is_extended_struct_definition(value):
                extended_struct_name = self.get_extended_struct_var_name()
                extended_struct_func_prefix = self.get_extended_struct_func_prefix(
                )
                body += '    {}Node* {}{{ nullptr }};\n'.format(
                    extended_struct_func_prefix, extended_struct_name
                )
            elif self.needs_member_declaration(name, value):
                type_name = self.make_decoded_param_type(value)
                if self.is_struct(value.base_type):
                    type_name = '{}*'.format(type_name)

                default_value = self.get_default_init_value(type_name)
                if default_value:
                    body += '    {} {}{{ {} }};\n'.format(
                        type_name, value.name, default_value
                    )
                else:
                    if self.is_struct(value.base_type):
                        body += '    {} {}{{ nullptr }};\n'.format(
                            type_name, value.name
                        )
                    else:
                        body += '    {} {};\n'.format(type_name, value.name)

        return body
