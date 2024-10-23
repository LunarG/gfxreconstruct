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
from dx12_base_generator import Dx12BaseGenerator, write


class Dx12ApiCallEncodersHeaderGenerator(Dx12BaseGenerator):
    """Generates C++ functions responsible for encoding Dx12 API call."""

    # SECURITY_ATTRIBUTES in minwinbase.h has been defined
    # in custom_vulkan_struct_encoders.h
    BLOCK_LIST = ['_SECURITY_ATTRIBUTES']

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
        Dx12BaseGenerator.beginFile(self, gen_opts)

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        """Method override."""
        Dx12BaseGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            self.newline()
            write(self.dx12_prefix_strings.format(k), file=self.outFile)
            self.newline()

            for m in v.functions:
                if self.is_required_function_data(m) and (
                    not self.is_cmd_black_listed(m['name'])
                ):
                    self.write_encode_function('', m)

            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value):
                    for m in class_value['methods']['public']:
                        if not self.is_method_black_listed(
                            class_name, m['name']
                        ):
                            self.write_encode_function(class_name, m)

                elif self.is_required_struct_data(class_name, class_value):
                    self.write_encode_struct(
                        class_name, class_value['properties']
                    )

    def write_include(self):
        code = ''
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        code += (
            "\n"
            "#include \"encode/parameter_encoder.h\"\n"
            "#include \"generated/generated_dx12_wrappers.h\"\n"
            "#include \"util/defines.h\"\n"
            "\n"
        )

        write(code, file=self.outFile)

    def get_encode_struct_body(self, properties):
        return ';'

    def write_encode_struct(self, name, properties):
        if self.is_block('', name):
            return

        code = (
            'void EncodeStruct(ParameterEncoder* encoder, const {}& value)'.
            format(name)
        )

        code += self.get_encode_struct_body(properties)
        write(code, file=self.outFile)
        self.newline()

    def get_encode_function_body(self, class_name, method_info, is_result):
        return ';'

    def is_block(self, class_name, method_name):
        key = class_name
        if key:
            key += '_'
        key += method_name
        return key in self.BLOCK_LIST

    def write_encode_function(self, class_name, method_info):
        parameters = ''
        if class_name:
            parameters = '    {}_Wrapper* wrapper'.format(class_name)

        is_result = False
        rtn_type = method_info['rtnType']
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            rtn_types1 = self.clean_type_define(rtn_type)

            if class_name:
                parameters += ',\n'
            parameters += '    ' + rtn_types1 + ' return_value'
            if rtn_types1 == 'HRESULT':
                is_result = True

        space_index = 0
        for p in method_info['parameters']:
            if parameters:
                parameters += ',\n'
            parameters += '    '
            parameters += self.clean_type_define(p['type'])
            parameters += ' '
            parameters += p['name']

            if 'array_size' in p:
                array_length = p['array_size']
                parameters += ' '

                if 'multi_dimensional_array' in p:
                    p['multi_dimensional_array']

                    if 'multi_dimensional_array_size' in p:
                        multi_dimensional_array_size = p[
                            'multi_dimensional_array_size']

                        array_sizes = multi_dimensional_array_size.split("x")
                        for size in array_sizes:
                            parameters += '['
                            parameters += size
                            parameters += ']'
                else:
                    parameters += '['
                    parameters += array_length
                    parameters += ']'

            while True:
                space_index = parameters.find(' ', space_index) + 1

                if space_index != 0 and (
                    parameters[space_index] == '*'
                    or parameters[space_index - 2] == '('
                    or parameters[space_index] == '('
                    or parameters[space_index] == ')'
                ):
                    parameters = parameters[:space_index
                                            - 1] + parameters[space_index:]
                elif space_index == 0:
                    break

        _class_name = ''
        if class_name:
            _class_name = '_' + class_name

        code = 'void Encode{}_{}(\n'\
            '{})'.format(_class_name, method_info['name'], parameters)

        code += self.get_encode_function_body(
            class_name, method_info, is_result
        )
        write(code, file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
