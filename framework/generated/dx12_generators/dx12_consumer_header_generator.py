#!/usr/bin/env python3
#
# Copyright (c) 2025 LunarG, Inc.
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
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions, write


class Dx12ConsumerHeaderGeneratorOptions(Dx12GeneratorOptions):
    """Options for generating a C++ class for Dx12 capture file replay."""

    def __init__(
        self,
        constructor_args='',
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        Dx12GeneratorOptions.__init__(
            self, blacklists, platform_types, filename, directory, prefix_text,
            protect_file, protect_feature
        )
        self.constructor_args = constructor_args


class Dx12ConsumerHeaderGenerator(Dx12BaseGenerator):
    """Generates C++ functions responsible for consuming Dx12 API calls."""
    constructor_args = ''

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
        """Method override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)

        if gen_opts.constructor_args:
            self.constructor_args = gen_opts.constructor_args

        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        """Method override."""
        Dx12BaseGenerator.generate_feature(self)
        self.write_dx12_consumer_class('')

    def write_include(self):
        code = (
            "#if defined(D3D12_SUPPORT)\n"
            "\n"
            "#include \"decode/dx12_consumer_base.h\"\n"
            "#include \"generated_dx12_struct_decoders.h\"\n"
            "#include \"decode/custom_dx12_struct_decoders.h\"\n"
            "\n"
            "#endif\n"
        )
        write(code, file=self.outFile)

    def get_consumer_function_body(self, class_name, method_info, return_type, return_value):
        return '{}'

    def change_param_type(self, param):
        value = self.get_value_info(param)
        type_name = self.make_decoded_param_type(value)
        if value.pointer_count > 0 and type_name.find('Decoder') != -1:
            type_name += '*'
        return type_name

    def get_consumer_function(
        self, class_name, method_info, consumer_type, indent, function_class
    ):
        parameters = '        const ApiCallInfo& call_info,\n'
        class_method_name = method_info['name']
        if class_name:
            parameters += '        format::HandleId object_id'
            class_method_name = class_name + '_' + class_method_name

        rtn_type = method_info['rtnType']
        return_value = None
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            rtn_type1 = self.clean_type_define(rtn_type)
            return_value = self.get_return_value_info(
                rtn_type1, class_method_name
            )
            rtn_type1 = self.make_decoded_param_type(return_value)
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

        code = '{}void {}Process{}_{}(\n'\
            '{}){}\n\n'.format(
                indent,
                function_class,
                _class_name,
                method_info['name'],
                parameters,
                self.get_consumer_function_body(class_name, method_info, rtn_type, return_value))
        return code

    def write_constructor_class(self, consumer_type):
        if self.constructor_args:
            arg_list = ', '.join(
                [
                    arg.split(' ')[-1]
                    for arg in self.constructor_args.split(',')
                ]
            )
            return 'class Dx12{0}Consumer : public Dx12{0}ConsumerBase\n'\
                      '{{\n'\
                      '  public:\n'\
                      '    Dx12{0}Consumer({1}) : Dx12{0}ConsumerBase({2}) {{}}\n'\
                      '    virtual ~Dx12{0}Consumer() override {{}}\n'.format(
                          consumer_type, self.constructor_args, arg_list)
        else:
            return 'class Dx12{0}Consumer : public Dx12{0}ConsumerBase\n'\
                      '{{\n'\
                      '  public:\n'\
                      '    Dx12{0}Consumer(){{}}\n'\
                      '    virtual ~Dx12{0}Consumer() override {{}}\n'.format(
                          consumer_type)

    def get_decoder_class_define(self, consumer_type):
        declaration = self.write_constructor_class(consumer_type)

        indent = '    virtual '
        function_class = ''
        class_end = '};\n'
        return (declaration, indent, function_class, class_end)

    def write_dx12_consumer_class(self, consumer_type):
        declaration, indent, function_class, class_end = self.get_decoder_class_define(
            consumer_type
        )
        code = declaration

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code_length = len(code)
            for m in v.functions:
                if self.is_required_function_data(m) and (
                    not self.is_cmd_black_listed(m['name'])
                ):
                    code += self.get_consumer_function(
                        '', m, consumer_type, indent, function_class
                    )

            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value):
                    for m in class_value['methods']['public']:
                        if not self.is_method_black_listed(
                            class_name, m['name']
                        ):
                            code += self.get_consumer_function(
                                class_name, m, consumer_type, indent,
                                function_class
                            )

            code_length2 = len(code)
            if code_length2 > code_length:
                code = code[:code_length] + self.dx12_prefix_strings.format(
                    k
                ) + '\n' + code[code_length:]

        code += class_end
        write(code, file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
