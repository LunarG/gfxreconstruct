#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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
from khronos_base_generator import write


class KhronosStructEncodersBodyGenerator():
    """KhronosStructEncodersBodyGenerator.
    Generates C++ functions for encoding Khronos API structures.
    """

    def write_encoder_content(self):
        api_data = self.get_api_data()
        for struct in self.get_all_filtered_struct_names():
            body = '\n'
            body += 'void EncodeStruct(ParameterEncoder* encoder, const {}& value)\n'.format(
                struct
            )
            body += '{\n'
            body += self.makeStructBody(
                api_data, struct, self.all_struct_members[struct], 'value.'
            )
            body += '}'
            write(body, file=self.outFile)

    def makeStructBody(self, api_data, name, values, prefix):
        """Command definition."""
        # Build array of lines for function body
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by typename
            if api_data.extended_struct_variable == value.name:
                body += '    Encode{}Struct(encoder, {});\n'.format(
                    api_data.extended_struct_func_prefix, prefix + value.name
                )
            else:
                method_call = self.make_encoder_method_call(
                    name, value, values, prefix
                )
                body += '    {};\n'.format(method_call)

        return body
