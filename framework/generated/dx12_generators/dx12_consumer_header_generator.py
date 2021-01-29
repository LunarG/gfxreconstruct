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
from base_generator import *
from dx12_base_generator import *


# Generates C++ functions responsible for consuming DX12 API calls
class DX12ConsumerHeaderGenerator(DX12BaseGenerator):

    def __init__(self, source_dict, dx12_prefix_strings,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        DX12BaseGenerator.__init__(
            self, source_dict, dx12_prefix_strings,
            errFile, warnFile, diagFile)

    # Method override
    def beginFile(self, gen_opts):
        BaseGenerator.beginFile(self, gen_opts)

        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

    # Method override
    def generateFeature(self):
        DX12BaseGenerator.generateFeature(self)
        self.write_dx12_consumer_class('')

    def write_include(self):
        code = ("\n"
                "#include \"decode/dx12_consumer_base.h\"\n"
                "#include \"generated_dx12_struct_decoders.h\"\n"
                "\n")
        write(code, file=self.outFile)

    def get_consumer_function_body(self, class_name, method_info):
        return '{}'

    def change_param_type(self, param):
        value = self.get_value_info(param)
        type_name = self.makeDecodedParamType(value)
        if value.pointerCount > 0 and type_name.find('Decoder') != -1:
            type_name += '*'
        return type_name

    def get_consumer_function(self, class_name, method_info,
                              consumer_type, indent, function_class):
        parameters = ''
        if class_name:
            parameters = '        format::HandleId object_id'
            class_name = "_" + class_name

        rtn_type = method_info['rtnType']
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            rtn_type1 = self.clean_type_define(rtn_type)
            return_value = self.get_value_info2('returnValue', rtn_type1)
            rtn_type1 = self.makeDecodedParamType(return_value)
            if rtn_type1.find('Decoder') != -1:
                rtn_type1 += '*'

            if class_name:
                parameters += ',\n'
            parameters += '        ' + rtn_type1 + ' ' + return_value.name

        space_index = 0
        for p in method_info['parameters']:
            if parameters:
                parameters += ',\n'
            parameters += '        '
            parameters += self.change_param_type(p)
            parameters += ' '
            parameters += p['name']

            if 'array_size' in p:
                array_length = p['array_size']
                parameters += ' '

                if 'multi_dimensional_array' in p:
                    p['multi_dimensional_array']

                    if 'multi_dimensional_array_size' in p:
                        multi_dimensional_array_size =\
                            p['multi_dimensional_array_size']

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

                if space_index != 0 and (parameters[space_index] == '*'
                                         or parameters[space_index - 2] == '('
                                         or parameters[space_index] == '('
                                         or parameters[space_index] == ')'):
                    parameters = parameters[:space_index -
                                            1] + parameters[space_index:]
                elif space_index == 0:
                    break

        code = '{}void {}Process{}_{}(\n'\
               '{}){}\n\n'.format(
                   indent,
                   function_class,
                   class_name,
                   method_info['name'],
                   parameters,
                   self.get_consumer_function_body(class_name, method_info))
        return code

    def get_decoder_class_define(self, consumer_type):
        declaration = 'class DX12{0}Consumer : public DX12{0}ConsumerBase\n'\
                      '{{\n'\
                      '  public:\n'\
                      '    DX12{0}Consumer(){{}}\n'\
                      '    virtual ~DX12{0}Consumer() override {{}}\n'.format(
                          consumer_type)

        indent = '    virtual '
        function_class = ''
        class_end = '};\n'
        return (declaration, indent, function_class, class_end)

    def write_dx12_consumer_class(self, consumer_type):
        declaration, indent, function_class, class_end =\
            self.get_decoder_class_define(consumer_type)
        code = declaration

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code_length = len(code)
            for m in v.functions:
                if self.is_required_function_data(m):
                    code += self.get_consumer_function('',
                                                       m,
                                                       consumer_type,
                                                       indent,
                                                       function_class)

            for k2, v2 in v.classes.items():
                if self.is_required_class_data(v2):
                    for m in v2['methods']['public']:
                        code += self.get_consumer_function(
                            k2, m, consumer_type, indent, function_class)

            code_length2 = len(code)
            if code_length2 > code_length:
                code = code[:code_length] + \
                    self.dx12_prefix_strings.format(
                        k) + '\n' + code[code_length:]

        code += class_end
        write(code, file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
