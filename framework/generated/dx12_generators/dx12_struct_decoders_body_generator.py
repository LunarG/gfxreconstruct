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
from dx12_decoder_header_generator import Dx12DecoderHeaderGenerator
from base_struct_decoders_body_generator import BaseStructDecodersBodyGenerator
from base_decoder_body_generator import BaseDecoderBodyGenerator


class Dx12StructDecodersBodyGenerator(
    Dx12DecoderHeaderGenerator, BaseStructDecodersBodyGenerator,
    BaseDecoderBodyGenerator
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
        Dx12DecoderHeaderGenerator.__init__(
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

    def write_include(self):
        """Method override."""
        code = (
            "#include \"generated_dx12_struct_decoders.h\"\n"
            "\n"
            "#include \"decode/custom_dx12_struct_decoders.h\"\n"
            "#include \"decode/decode_allocator.h\"\n"
        )
        write(code, file=self.outFile)

    # Met#include "util/defines.h"hod override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        BaseStructDecodersBodyGenerator.generate_feature(self)

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write('#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
