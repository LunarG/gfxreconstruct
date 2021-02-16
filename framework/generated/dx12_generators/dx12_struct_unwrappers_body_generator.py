#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator


# Generates functions to unwrap struct members with a COM object type
# before the struct is passed as an argument to a DX12 API call during
# DX12 capture.
class Dx12StructUnwrappersBodyGenerator(Dx12BaseGenerator):
    # Default C++ code indentation size.
    INDENT_SIZE = 4

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

    # Method override
    def beginFile(self, genOpts):
        Dx12BaseGenerator.beginFile(self, genOpts)

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()

        # Table mapping struct names to member values that are either COM
        # objects or structs with COM object members.
        structs_with_objects = {}

        # Find structs with COM object members, which will need to be
        # unwrapped.
        struct_list = self.source_dict['struct_list']
        for struct in struct_list:
            members = self.feature_struct_members[struct]

            # This intentionally ignores structs with anonymous
            # union members, which are processed by the custom
            # unwrap functions.
            union_members = [
                member for member in members
                if 'anon-union' in member.base_type
            ]
            if union_members:
                continue

            for member in members:
                base_type = member.base_type
                full_type = member.full_type
                name = member.name

                # Check for the following:
                # 1. A struct member with a class type.
                # 2. A struct member that is a struct that has members that
                #    require unwrapping.
                if (
                    self.is_class(member) or (
                        self.is_struct(base_type) and
                        (base_type in structs_with_objects) and
                        (not '_Out_' in full_type)
                    )
                ):
                    if struct in structs_with_objects:
                        # If the struct is already in the table, append
                        # the member to the existing list.
                        if member not in structs_with_objects[struct]:
                            structs_with_objects[struct].append(member)
                    else:
                        # Add a new entry to the table for the
                        # current struct.
                        structs_with_objects[struct] = [member]

            # Second pass to check for structs intended to be used as linked
            # lists, which contain a member with the same struct type.
            for member in members:
                base_type = member.base_type
                full_type = member.full_type
                name = member.name

                # If the current member type matches the current struct type,
                # and the current struct type has handles, add it to the list
                # of members that require unwrapping.
                if (base_type
                    == struct) and (struct in structs_with_objects) and (
                        not '_Out_' in full_type
                    ) and (member not in structs_with_objects[struct]):
                    structs_with_objects[struct].append(member)

        # Generate unwrap functions for any structs that were added to
        # the table.
        for key, value in structs_with_objects.items():
            self.write_struct_unwrap_def(key, value, structs_with_objects)

        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)

    def write_struct_unwrap_def(self, struct, members, table, indent=''):
        expr = indent + 'void UnwrapStructObjects({}* value, '\
            'HandleUnwrapMemory* unwrap_memory)\n'.format(struct)

        # Begin function body
        expr += indent + '{\n'
        indent = self.increment_indent(indent)

        expr += indent + 'if (value != nullptr)\n'
        expr += indent + '{\n'
        indent = self.increment_indent(indent)

        for member in members:
            if self.is_class(member):
                # If it is an array or pointer, map with the utility function.
                if member.is_array:
                    if member.is_dynamic:
                        expr += indent + 'value->{name} = UnwrapObjects<{type}_Wrapper, {type}>(value->{name}, value->{}, unwrap_memory);\n'.format(
                            member.array_length,
                            name=member.name,
                            type=member.base_type
                        )
                    else:
                        expr += indent + 'std::transform(value->{name}, value->{name} + value->{}, value->{name}, GetWrappedObject<{type}_Wrapper, {type}>);\n'.format(
                            member.array_length,
                            name=member.name,
                            type=member.base_type
                        )
                else:
                    expr += indent + 'value->{name} = GetWrappedObject<{type}_Wrapper, {type}>(value->{name});\n'.format(
                        name=member.name, type=member.base_type
                    )
            else:
                # This is a struct that includes handles.
                if member.is_array:
                    expr += indent + 'value->{name} = UnwrapStructArrayObjects(value->{name}, value->{}, unwrap_memory);\n'.format(
                        member.array_length, name=member.name
                    )
                elif member.is_pointer:
                    expr += indent + 'value->{name} = UnwrapStructPtrObjects(value->{name}, unwrap_memory);\n'.format(
                        name=member.name
                    )
                else:
                    expr += indent + 'UnwrapStructObjects(&value->{}, unwrap_memory);\n'.format(
                        member.name
                    )

        indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        # End method body
        indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        write(expr, file=self.outFile)

    def write_include(self):
        code = ''

        code += '#include "generated/generated_dx12_struct_unwrappers.h"\n'
        code += '\n'
        code += '#include "encode/dx12_object_wrapper_util.h"\n'
        code += '#include "generated/generated_dx12_wrappers.h"\n'
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        write(code, file=self.outFile)

    def increment_indent(self, indent):
        return indent + (' ' * self.INDENT_SIZE)

    def decrement_indent(self, indent):
        return indent[:-self.INDENT_SIZE]
