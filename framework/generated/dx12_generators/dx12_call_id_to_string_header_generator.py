#!/usr/bin/env python3
#
# Copyright (c) 2023 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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


class Dx12CallIdToStringHeaderGenerator(Dx12BaseGenerator):
    """Generates C++ function responsible for converting Dx12 ApiCallId to string."""

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
        BaseGenerator.beginFile(self, gen_opts)

        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        self.write_function_call()

    def write_include(self):
        code = (
            "\n"
            "#include \"format/api_call_id.h\"\n"
            "#include <string>\n"
            "\n"
        )
        write(code, file=self.outFile)

    def write_function_call(self):
        code = (
            "inline std::wstring GetDx12CallIdString(format::ApiCallId call_id){}\n"
            "\n".format(self.get_function_call_body())
        )
        write(code, file=self.outFile)

    def get_function_call_body(self):
        code = '\n'\
               '{\n'\
               '    std::wstring out = L"Unknown_ApiCallId";\n'\
               '    switch (call_id)\n'\
               '    {\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for m in v.functions:
                if self.is_required_function_data(m):
                    code += (
                        "    case format::ApiCallId::ApiCall_{0}:\n"
                        "        out = L\"{0}\";\n"
                        "        break;\n".format(m['name'])
                    )

            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value):
                    for m in class_value['methods']['public']:
                        code += (
                            "    case format::ApiCallId::ApiCall_{0}_{1}:\n"
                            "        out = L\"{0}_{1}\";\n"
                            "        break;\n".format(class_name, m['name'])
                        )


        code += '    default:\n'\
                '        break;\n'\
                '    }\n'\
                '    return out;\n'\
                '}'

        return code

    def endFile(self):
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
