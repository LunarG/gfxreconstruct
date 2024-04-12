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
from base_generator import BaseGenerator, write
from dx12_base_generator import Dx12BaseGenerator
from base_struct_decoders_header_generator import BaseStructDecodersHeaderGenerator
from reformat_code import format_cpp_code

class Dx12StructDecodersForwardGenerator(
    Dx12BaseGenerator, BaseStructDecodersHeaderGenerator
):
    """Generates C++ functions responsible for decoding Dx12 API calls."""

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
        self.check_blacklist = True

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)
        write('#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)', file=self.outFile)
        self.newline()

        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        """Method override."""
        code = ''
        struct_dict = self.source_dict['struct_dict']
        for name in struct_dict:
            code += 'struct Decoded_{};\n'.format(name)
        code += 'struct Decoded_LARGE_INTEGER;\n'
        write(code, file=self.outFile)

        Dx12BaseGenerator.generate_feature(self)
        self.write_struct()

    def write_include(self):
        """Method override."""
        code = ("#include \"util/defines.h\"\n")
        code += "\n"
        code += ("#include <cstdint>\n")
        code += "\n#ifndef WIN32\n"
        code += ("#include <cstddef>\n")
        code += "#endif\n\n"
        write(code, file=self.outFile)

    def get_struct_function_body(self, properties):
        return ';'

    def get_struct_function(self, name, properties):
        code = (
            'size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_{}* wrapper)'
            .format(name)
        )
        code += self.get_struct_function_body(properties)
        code += '\n\n'
        return code

    def write_struct(self):
        code = ''
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code_length = len(code)
            for class_name, class_value in v.classes.items():
                if self.is_required_struct_data(class_name, class_value):
                    code += self.get_struct_function(
                        class_name, class_value['properties']
                    )

            code_length2 = len(code)
            if code_length2 > code_length:
                code = code[:code_length] + self.dx12_prefix_strings.format(
                    k
                ) + '\n' + code[code_length:]

        write(code, file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        code = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)

            #endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
        ''')
        write(code, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
