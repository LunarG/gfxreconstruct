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
from dx12_base_generator import DX12BaseGenerator, write


# Generates C++ functions responsible for encoding DX12 API call.
class DX12ApiCallEncodersHeaderGenerator(DX12BaseGenerator):

    # SECURITY_ATTRIBUTES in minwinbase.h has been defined
    # in custom_vulkan_struct_encoders.h
    BLOCK_LIST = ['_SECURITY_ATTRIBUTES']

    def __init__(self, source_dict, dx12_prefix_strings,
                 errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout):
        DX12BaseGenerator.__init__(
            self,
            source_dict,
            dx12_prefix_strings,
            errFile,
            warnFile,
            diagFile)

    # Method override
    def beginFile(self, genOpts):
        DX12BaseGenerator.beginFile(self, genOpts)

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()

    # Method override
    def generateFeature(self):
        DX12BaseGenerator.generateFeature(self)

        self.write_encode_object()
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            self.newline()
            write(self.dx12_prefix_strings.format(k), file=self.outFile)
            self.newline()

            # print for api_call_id
            # print('\n    //', k)

            for m in v.functions:
                if m['parent'] is None and m['name'][:7] != 'DEFINE_'\
                   and m['name'][:8] != 'DECLARE_'\
                   and m['name'] != 'InlineIsEqualGUID'\
                   and m['name'] != 'IsEqualGUID'\
                   and m['name'][:8] != 'operator':
                    self.write_encode_function('', m)

            for k2, v2 in v.classes.items():
                if v2['declaration_method'] == 'class':
                    for m in v2['methods']['public']:
                        self.write_encode_function(k2, m)

                elif v2['declaration_method'] == 'struct'\
                        and k2[-4:] != 'Vtbl'\
                        and k2.find("::<anon-union-") == -1:
                    self.write_encode_struct(k2, v2['properties'])

    def write_include(self):
        code = ''
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        code += ("\n"
                 "#include \"encode/parameter_encoder.h\"\n"
                 "#include \"util/defines.h\"\n"
                 "\n")

        class_list = self.source_dict['class_list']
        for name in class_list:
            code += 'class {}_Wrapper;\n'.format(name)

        write(code, file=self.outFile)

    def write_encode_object(self):
        code = ("void EncodeDxObjectPtr(ParameterEncoder* encoder, void** object, bool omit_output_data = false);\n"  # noqa
                "void EncodeDxObjectPtrArray(ParameterEncoder* encoder, void*** value, size_t len, bool omit_data = false, bool omit_addr = false);\n")  # noqa
        write(code, file=self.outFile)

    def get_encode_struct_body(self, properties):
        return ';'

    def write_encode_struct(self, name, properties):
        if self.is_block('', name):
            return

        function_declaration = ("void EncodeStruct(ParameterEncoder* encoder, const {}& value)"  # noqa
                                .format(name))
        if function_declaration in self.function_declaration_set:
            # print('WARNING:', function_declaration, 'is duplicated.')
            return

        self.function_declaration_set.add(function_declaration)
        body = self.get_encode_struct_body(properties)
        write('{}{}'.format(function_declaration, body), file=self.outFile)
        self.newline()

    def get_encode_function_body(self, class_name, method_info):
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
            parameters = '    format::HandleId wrapper_id'
            class_name = "_" + class_name

        rtn_type = method_info['rtnType']
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            rtn_types1 = self.clean_type_define(rtn_type)

            if class_name:
                parameters += ',\n'
            parameters += '    ' + rtn_types1 + ' result'

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
                        multi_dimensional_array_size = \
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

        function_declaration = 'void Encode{}_{}(\n'\
                               '{})'.format(
                                   class_name, method_info['name'], parameters)

        if function_declaration in self.function_declaration_set:
            # print('WARNING:', function_declaration, 'is duplicated.')
            return

        self.function_declaration_set.add(function_declaration)
        body = self.get_encode_function_body(class_name, method_info)
        write('{}{}'.format(function_declaration, body), file=self.outFile)
        self.newline()

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        DX12BaseGenerator.endFile(self)
