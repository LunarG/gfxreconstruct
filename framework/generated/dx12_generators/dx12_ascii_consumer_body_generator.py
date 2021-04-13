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

from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from dx12_ascii_consumer_header_generator import Dx12AsciiConsumerHeaderGenerator


class Dx12AsciiConsumerBodyGenerator(Dx12AsciiConsumerHeaderGenerator):
    """Generates C++ functions responsible for consuming Dx12 API calls."""

    def write_include(self):
        """Methond override."""
        write('#include "generated_dx12_ascii_consumer.h"', file=self.outFile)

    def generate_feature(self):
        """Methond override."""
        Dx12BaseGenerator.generate_feature(self)
        self.write_dx12_consumer_class('Ascii')

    def get_decoder_class_define(self, consumer_type):
        """Methond override."""
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info):
        """Methond override."""
        if class_name:
            code = '\n'\
                   '{{\n'\
                   '    fprintf(GetFile(), "%s\\n", "{}::{}");\n'\
                   '}}\n'.format(class_name, method_info['name'])
        else:
            code = '\n'\
                   '{{\n'\
                   '    fprintf(GetFile(), "%s\\n", "{}");\n'\
                   '}}\n'.format(method_info['name'])
        return code
