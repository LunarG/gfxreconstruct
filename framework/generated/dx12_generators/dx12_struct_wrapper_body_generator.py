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
from dx12_base_generator import Dx12BaseGenerator, write


class Dx12StructWrapperBodyGenerator(Dx12BaseGenerator):
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

    def beginFile(self, genOpts):
        """Method override."""
        Dx12BaseGenerator.beginFile(self, genOpts)
        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

        self.newline()

    def endFile(self):
        """Method override."""
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    def generate_feature(self):
        """Method override."""
        Dx12BaseGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        self.structs_with_objects = self.collect_struct_with_objects(
            header_dict
        )
        self.write_struct_member_def()

    def write_struct_member_def(self):
        for k, v in self.structs_with_objects.items():
            expr = 'void WrapStruct(const {}* value)\n'.format(k)
            expr += '{\n'

            for value in v:
                if self.is_struct(value.base_type):
                    expr += '    if(value->{0})\n'\
                            '    {{\n'\
                            '        WrapStruct(value->{0});\n'\
                            '    }}\n'.format(value.name)

                elif self.is_class(value):
                    if value.is_const:
                        expr += '    if(value->{1})\n'\
                                '    {{\n' \
                                '        {0}* casted = const_cast<{0}*>(value->{1});\n' \
                                '        WrapObject(IID_{0}, reinterpret_cast<void**>(&casted), nullptr);\n' \
                                '    }}\n'.format(value.base_type, value.name)
                    else:
                        expr += '    if(value->{1})\n'\
                                '    {{\n'\
                                '        WrapObject(IID_{0}, reinterpret_cast<void**>(value->{1}), nullptr);\n'\
                                '    }}\n'.format(value.base_type, value.name)

            expr += '}\n'
            write(expr, file=self.outFile)

    def write_include(self):
        code = ''

        code += '#include "generated/generated_dx12_struct_wrappers.h"\n'
        code += '\n'
        code += '#include "generated/generated_dx12_wrapper_creators.h"\n'
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        write(code, file=self.outFile)
