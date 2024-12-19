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

    def write_struct_type_prefix(self, gen_opts):
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.write_includes_of_common_api_headers(gen_opts)
        self.newline()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
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

    def write_struct_type_data(self):
        current_api_data = self.get_api_data()
        for struct in self.all_struct_members.keys():
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
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)
