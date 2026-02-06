#!/usr/bin/python3
#
# Copyright (c) 2024 LunarG, Inc.
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


class KhronosStructTypeUtilGenerator():
    """KhronosStructTypeUtilGenerator
    Generates C++ utility header to do compile-time lookups between Khronos API
    structure types and their corresponding enum values
    """

    @staticmethod
    def update_begin_end_file_data(begin_end):
        begin_end.specific_headers.extend((
        'format/platform_types.h',
        'util/defines.h',
        ))

        begin_end.namespaces.extend((
        'gfxrecon', 'util'
        ))

    def write_struct_type_prefix(self, gen_opts):
        self.newline()

        current_api_data = self.get_api_data()
        write(
            '// Instantiating the primary template indicates that either the template was',
            file=self.outFile
        )
        write(
            '// called with an invalid {} struct type or that the code generation is out'
            .format(current_api_data.api_name),
            file=self.outFile
        )
        write('// of date, both of which are errors', file=self.outFile)
        write(
            'template <typename T> {} Get{}() = delete;'.format(
                current_api_data.struct_type_enum,
                current_api_data.struct_type_func_prefix
            ),
            file=self.outFile
        )
        self.newline()

    # Skip this struct if it is a TRUE parent.  However, if it is a forced one, keep it in this list
    # of structs we want types for.
    def skip_struct_type(self, struct):
        """ Maybe be overridden """
        skip_this = struct in self.children_structs
        for key, value in self.FORCE_STRUCT_PARENTS.items():
            if struct == value:
                skip_this = False
                break
        return skip_this

    def write_struct_type_data(self):
        current_api_data = self.get_api_data()
        for struct in self.all_struct_members.keys():
            if self.skip_struct_type(struct):
                continue

            if struct in self.struct_type_names:
                write(
                    'template <> constexpr {} Get{}<{}>(){{ return {}; }}'.
                    format(
                        current_api_data.struct_type_enum,
                        current_api_data.struct_type_func_prefix, struct,
                        self.struct_type_names[struct]
                    ),
                    file=self.outFile
                )

        self.newline()
