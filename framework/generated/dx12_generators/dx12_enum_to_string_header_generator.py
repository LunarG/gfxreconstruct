#!/usr/bin/env python3
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2021, 2023 LunarG, Inc.
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

import sys, inspect
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from reformat_code import format_cpp_code

class Dx12EnumToStringHeaderGenerator(Dx12BaseGenerator):
    """TODO : Generates C++ functions responsible for Convert to texts."""

    ## A list of suffix substrings which appear at the ends of the names of bitflag enums.
    ## If a name contains one of these substrings, then a function will be generated to convert
    ## a value of that enum type to a string concatenating all the flags it represents.
    ## Like this: "DX12_ENUMX_ENUMERANTY|DX12_ENUMX_ENUMERANTZ|...".
    BITS_LIST = [
        '_FLAGS', '_STATES', '_STATUS', 'D3D12_SHADER_MIN_PRECISION_SUPPORT',
        'D3D12_FORMAT_SUPPORT1', 'D3D12_FORMAT_SUPPORT2'
    ]

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

    def beginFile(self, gen_opts):
        """Method override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)
        write('#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)', file=self.outFile)
        self.newline()

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        enum_dict = self.source_dict['enum_dict']
        for k, v in enum_dict.items():
            # Generate enum handler for all enums
            body = 'std::string ToString({0} value);'

            # Generate flags handler for enums identified as bitmasks
            for bits in self.BITS_LIST:
                if k.find(bits) >= 0:
                    body += '\nstd::string ToString_{0}(uint32_t flags);'
            write(body.format(k), file=self.outFile)

        # Generate REFIID handler
        body = 'std::string ToString(const IID& riid);'
        body += '\ninline std::string ToString(const GUID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize){ return ToString(obj); }'
        write(body, file=self.outFile)

    def write_include(self):
        code = ''
        code += '#ifdef WIN32\n'
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)
        code += '#endif // WIN32\n\n'

        code += '#include "format/platform_types.h"\n'
        code += '#include "util/defines.h"\n'
        code += '#include "util/to_string.h"\n'

        write(code, file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""
        self.newline()
        code = format_cpp_code('''
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)

            #endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
        ''')
        write(code, file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
