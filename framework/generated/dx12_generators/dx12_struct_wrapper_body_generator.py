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
        self.structs_with_wrap_objects = set()

    def beginFile(self, genOpts):
        """Methond override."""
        Dx12BaseGenerator.beginFile(self, genOpts)
        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

        self.newline()

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
        self.collect_struct_with_wrap_objects(header_dict)

        for k, v in header_dict.items():
            print_prefix_strings = False
            for k2, v2 in v.classes.items():
                if k2 in self.structs_with_wrap_objects:

                    if not print_prefix_strings:
                        self.newline()
                        write(
                            self.dx12_prefix_strings.format(k),
                            file=self.outFile
                        )
                        self.newline()
                        print_prefix_strings = True

                    self.write_struct_member_def(k2, v2['properties'])

    def collect_struct_with_wrap_objects(self, header_dict):
        for k, v in header_dict.items():
            for k2, v2 in v.classes.items():
                if self.is_required_struct_data(k2, v2):
                    for k, v in v2['properties'].items():
                        for p in v:
                            value = self.get_value_info(p)

                            if (
                                self.is_struct(value.base_type) and
                                (value.full_type.find('_Out_') != -1) and (
                                    value.base_type
                                    in self.structs_with_wrap_objects
                                )
                            ) or (self.is_class(value)):
                                #print('   22222', k2)
                                self.structs_with_wrap_objects.add(k2)

    def write_struct_member_def(self, name, properties):
        expr = 'void WrapStruct(const {}* value)\n'.format(name)
        expr += '{\n'

        for k, v in properties.items():
            for p in v:
                value = self.get_value_info(p)

                if self.is_struct(value.base_type) and (
                    value.full_type.find('_Out_') != -1
                ) and (value.base_type in self.structs_with_wrap_objects):
                    expr += '    if(value->{0})\n'\
                            '    {{\n'\
                            '        WrapStruct(value->{0});\n'\
                            '    }}\n'.format(value.name)

                elif self.is_class(value):
                    if value.is_const:
                        expr += '    if(value->{1})\n'\
                                '    {{\n'\
                                '        WrapObject(IID_{0}, reinterpret_cast<void**>(&const_cast<{0}*>(value->{1})), nullptr);\n'\
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
