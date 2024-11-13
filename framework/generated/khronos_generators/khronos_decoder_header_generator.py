#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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


class KhronosDecoderHeaderGenerator():
    """KhronosDecoderHeaderGenerator
    Generates C++ member declarations for the Khronos-API specific Decoder class
    responsible for decoding the appropriate Khronos API call parameter data.
    """

    def skip_generating_command(self, command):
        """ Method may be overridden. """
        return False

    def write_decoder_header_content(self):
        api_data = self.get_api_data()

        write(
            'class {0}Decoder : public {0}DecoderBase'.format(
                api_data.api_class_prefix
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write(
            '    {}Decoder() {{ }}\n'.format(api_data.api_class_prefix),
            file=self.outFile
        )
        write(
            '    virtual ~{}Decoder() override {{ }}\n'.format(
                api_data.api_class_prefix
            ),
            file=self.outFile
        )
        write(
            '    virtual void DecodeFunctionCall(format::ApiCallId             call_id,',
            file=self.outFile
        )
        write(
            '                                    const ApiCallInfo&            call_info,',
            file=self.outFile
        )
        write(
            '                                    const uint8_t*                parameter_buffer,',
            file=self.outFile
        )
        write(
            '                                    size_t                        buffer_size) override;\n',
            file=self.outFile
        )
        write('  private:', end='', file=self.outFile)

        for cmd in self.get_all_filtered_cmd_names():
            if self.skip_generating_command(cmd):
                continue

            cmddef = '\n'
            cmddef += '    size_t Decode_{}(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);'.format(
                cmd
            )
            write(cmddef, file=self.outFile)

        write('};', file=self.outFile)
