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
from dx12_decoder_header_generator import Dx12DecoderHeaderGenerator
from base_struct_decoders_body_generator import BaseStructDecodersBodyGenerator
from base_decoder_body_generator import BaseDecoderBodyGenerator


class Dx12DecoderBodyGenerator(
    Dx12DecoderHeaderGenerator, BaseStructDecodersBodyGenerator,
    BaseDecoderBodyGenerator
):
    """Generates C++ functions responsible for decoding Dx12 API calls."""
    def __init__(self, source_dict, dx12_prefix_strings, diag_file):
        Dx12DecoderHeaderGenerator.__init__(self, source_dict, dx12_prefix_strings,
            err_file=sys.stderr,
            warn_file=sys.stderr,
            diag_file=sys.stdout,
            feature_break=False
            )
        
        BaseStructDecodersBodyGenerator.__init__(self)
        BaseDecoderBodyGenerator.__init__(self)


    def write_include(self):
        """Method override."""
        code = (
            "\n"
            "#include \"generated_dx12_decoder.h\"\n"
            "#include \"generated_dx12_struct_decoders_forward.h\"\n"
            "#include \"decode/custom_dx12_struct_decoders_forward.h\"\n"
            "\n"
        )
        write(code, file=self.outFile)

    def generate_feature(self):
        """Method override."""
        self.method_names = []
        Dx12BaseGenerator.generate_feature(self)
        self.write_function_call()
        BaseDecoderBodyGenerator.generate_feature(self)
        BaseDecoderBodyGenerator.generate_commands(self) # Dx12 only has one "feature", so no need to push this to endFile
        self.newline()
        self.generate_dx12_method_feature()

    def generate_dx12_method_feature(self):
        first = True
        for method in self.get_filtered_method_names():
            self.method_names.append(method)

            info = self.feature_method_params[method]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += (
                'size_t Dx12Decoder::Decode_{}(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)\n'
                .format(method)
            )
            cmddef += '{\n'
            cmddef += '    size_t bytes_read = 0;\n'
            cmddef += '\n'
            cmddef += self.make_cmd_body(return_type, method, values, True)
            cmddef += '\n'
            cmddef += '    return bytes_read;\n'
            cmddef += '}'
            write(cmddef, file=self.outFile)
            first = False

    def write_function_call(self):
        code = (
            "void Dx12Decoder::DecodeFunctionCall(format::ApiCallId  call_id,\n"
            "                                     const ApiCallInfo& call_info,\n"
            "                                     const uint8_t*     parameter_buffer,\n"
            "                                     size_t             buffer_size){}\n"
            "\n"
            "void Dx12Decoder::DecodeMethodCall(format::ApiCallId  call_id,\n"
            "                                   format::HandleId   object_id,\n"
            "                                   const ApiCallInfo& call_info,\n"
            "                                   const uint8_t*     parameter_buffer,\n"
            "                                   size_t             buffer_size){}\n"
            .format(
                self.get_decode_function_call_body(),
                self.get_decode_method_call_body()
            )
        )
        write(code, file=self.outFile)

    def get_decode_function_call_body(self):
        """Method override."""
        code = '\n'\
               '{\n'\
               '    GFXRECON_UNREFERENCED_PARAMETER(call_info);\n'\
               '    switch (call_id)\n'\
               '    {\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for m in v.functions:
                if self.is_required_function_data(m) and (
                    not self.is_cmd_black_listed(m['name'])
                ):
                    code += (
                        "    case format::ApiCallId::ApiCall_{0}:\n"
                        "        Decode_{0}(call_info, parameter_buffer, buffer_size);\n"
                        "        break;\n".format(m['name'])
                    )

        code += '    default:\n'\
                '        Dx12DecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);\n'\
                '        break;\n'\
                '    }\n'\
                '}\n'
        return code

    def get_decode_method_call_body(self):
        """Method override."""
        code = '\n'\
               '{\n'\
               '    GFXRECON_UNREFERENCED_PARAMETER(call_info);\n'\
               '    switch (call_id)\n'\
               '    {\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value):
                    for m in class_value['methods']['public']:
                        if not self.is_method_black_listed(
                            class_name, m['name']
                        ):
                            code += (
                                "    case format::ApiCallId::ApiCall_{0}_{1}:\n"
                                "        Decode_{0}_{1}(object_id, call_info, parameter_buffer, buffer_size);\n"
                                "        break;\n".format(
                                    class_name, m['name']
                                )
                            )

        code += '    default:\n'\
                '        Dx12DecoderBase::DecodeMethodCall(call_id, object_id, call_info, parameter_buffer, buffer_size);\n'\
                '        break;\n'\
                '    }\n'\
                '}\n'
        return code
