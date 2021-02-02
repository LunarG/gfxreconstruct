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

from base_generator import *
from dx12_base_generator import *
from dx12_decoder_header_generator import DX12DecoderHeaderGenerator
from base_struct_decoders_body_generator import *
from base_decoder_body_generator import *


# Generates C++ functions responsible for decoding DX12 API calls
class DX12StructDecodersBodyGenerator(
        DX12DecoderHeaderGenerator,
        BaseStructDecodersBodyGenerator, BaseDecoderBodyGenerator):

    # Method override
    def write_include(self):
        code = ("\n"
                "#include \"generated_dx12_struct_decoders.h\"\n"
                "#include \"generated_dx12_struct_decoders_forward.h\"\n"
                "\n")
        write(code, file=self.outFile)

    # Met#include "util/defines.h"hod override
    def generateFeature(self):
        DX12BaseGenerator.generateFeature(self)
        BaseStructDecodersBodyGenerator.generateFeature(self)
