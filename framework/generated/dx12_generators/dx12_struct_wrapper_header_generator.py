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


class Dx12StructWrapperHeaderGenerator(Dx12BaseGenerator):
    """Generates struct wrappers for DX12 capture."""

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
        self.structs_with_wrap_objects = set()

    def beginFile(self, genOpts):
        """Methond override."""
        Dx12BaseGenerator.beginFile(self, genOpts)
        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    def endFile(self):
        """Methond override."""
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    def generate_feature(self):
        """Methond override."""
        Dx12BaseGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            print_prefix_strings = False
            for k2, v2 in v.classes.items():
                if self.is_required_struct_data(k2, v2):
                    print_prefix_strings = self.write_struct_decl(
                        k2, v2['properties'], print_prefix_strings,
                        self.dx12_prefix_strings.format(k)
                    )

    def write_include(self):
        code = ''
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)
        code += '\n'

        write(code, file=self.outFile)

    def write_struct_decl(
        self, name, properties, print_prefix_strings, dx12_prefix_strings
    ):
        for k, v in properties.items():
            for p in v:
                value = self.get_value_info(p)
                if (
                    self.is_struct(value.base_type) and
                    (value.full_type.find('_Out_') != -1) and
                    (value.base_type in self.structs_with_wrap_objects)
                ) or (self.is_class(value)):
                    if not name in self.structs_with_wrap_objects:
                        if not print_prefix_strings:
                            self.newline()
                            write(dx12_prefix_strings, file=self.outFile)
                            self.newline()
                            print_prefix_strings = True
                        self.structs_with_wrap_objects.add(name)
                        write(
                            'void WrapStruct(const {}* value);\n'.format(name),
                            file=self.outFile
                        )

        return print_prefix_strings
