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
        write(
            '#include "generated_dx12_convert_to_texts.h"', file=self.outFile
        )
        write(
            '#include "decode/custom_dx12_struct_ascii_consumers.h"',
            file=self.outFile
        )
        write('#include "decode/dx12_enum_util.h"', file=self.outFile)
        write('#include "util/interception/injection.h"', file=self.outFile)
        self.newline()

    def generate_feature(self):
        """Methond override."""
        Dx12BaseGenerator.generate_feature(self)
        self.write_struct_functions()
        self.write_dx12_consumer_class('Ascii')

    def get_decoder_class_define(self, consumer_type):
        """Methond override."""
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info, return_type):
        """Methond override."""
        code = '\n{\n'\
               '    std::ostringstream oss;\n'

        class_method_name = method_info['name']
        if class_name:
            code += '    oss << "{}_id" << object_id << "->";\n'.format(
                class_name
            )
            class_method_name = class_name + '_' + class_method_name

        code += '    oss << "{}(\\n    /* ";\n\n'.format(method_info['name'])

        if return_type.find('void ') == -1 or return_type.find('void *') != -1:
            return_value = self.get_return_value_info(
                return_type, class_method_name
            )
            code += '    oss << "return = " ;\n'
            code += self.add_argument(
                return_value, '    ', '                ', True
            )
            code += '    oss << ",\\n       ";\n\n'

        # TODO: Add thread_id
        code += '    oss << "thread_id = WIP */'
        params = method_info['parameters']

        if params:
            code += '\\n";\n\n'
        else:
            code += ');\\n\\n";\n\n'

        index = 0
        for p in params:
            index += 1
            value = self.get_value_info(p)
            comma = '",\\n"'
            if index == len(method_info['parameters']):
                comma = '");\\n\\n"'
            code += self.add_argument(value, '    ', '    ', False)
            code += '    oss << {};\n\n'.format(comma)

        code += '    fprintf(GetFile(), "%s\\n", oss.str().c_str());\n'\
                '}\n'
        return code

    def add_argument(self, value, indent_code, indent_file, prefix):
        type_name = value.base_type
        indent_base = '    '
        indent_code2 = indent_code + indent_base

        output = ''
        output_string = 'false'
        is_output = self.is_output(value)
        if is_output:
            output = '&'
            output_string = 'true'

        if prefix:
            prefix_string = 'true'
            prefix11 = self.trim_generate_write_empty(indent_code + 'oss << "' + output + '" << ')
            prefix21 = self.trim_generate_write_empty(indent_code2 + 'oss << "' + output + '" << ')
        else:
            prefix_string = 'false'
            prefix11 = self.trim_generate_write_empty(indent_code + 'oss << "' + indent_file + '" << "' + output + '" << ')
            prefix21 = self.trim_generate_write_empty(indent_code2 + 'oss << "' + indent_file + '" << "' + output + '" << ')

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_class(value):
                if value.is_array:
                    pass
                elif count > 1:
                    pass
                else:
                    return prefix11 + '"{}_id" << '.format(value.base_type) + value.name + ';\n'

            elif type_name == 'void':
                if value.is_array:
                    pass
                elif count > 1:
                    pass
                else:
                    return prefix11 + value.name + ';\n'

            code = indent_code + 'if (WriteCheckPointerDecoderNull(oss, {}, "{}", {}))\n'.format(
                value.name, indent_file, output_string
            )
            code += indent_code + '{\n'
            if 'LARGE_INTEGER' == type_name:
                code += prefix21 + value.name + '->GetPointer()->QuadPart;\n'

            elif self.is_enum(type_name):
                if value.is_array:
                    code += self.add_array_argument(
                        value, indent_code, indent_file, is_output
                    )
                elif count > 1:
                    pass
                else:
                    code += prefix21 + 'ConverttoText(*{}->GetPointer());\n'.format(
                        value.name
                    )

            elif type_name == 'GUID':
                if value.is_array:
                    code += self.add_array_argument(
                        value, indent_code, indent_file, is_output
                    )
                elif count > 1:
                    pass
                else:
                    pass

            elif self.is_struct(type_name):
                if value.is_array:
                    code += self.add_array_argument(
                        value, indent_code, indent_file, is_output
                    )
                elif count > 1:
                    code += indent_code2 + 'WriteStructString(oss, *{}->GetMetaStructPointer(), "{}", {}, {});\n'.format(
                        value.name, indent_file, prefix_string, output_string
                    )
                else:
                    code += indent_code2 + 'WriteStructString(oss, {}->GetMetaStructPointer(), "{}", {}, {});\n'.format(
                        value.name, indent_file, prefix_string, output_string
                    )

            elif self.is_class(value):
                if value.is_array:
                    code += self.add_array_argument(
                        value, indent_code, indent_file, is_output
                    )
                elif count > 1:
                    code += prefix21 + '"{}_id" << '.format(
                        value.base_type
                    ) + '*' + value.name + '->GetPointer();\n'
                else:
                    pass

            elif type_name == 'wchar_t' or type_name == 'char':
                if count > 1:
                    pass
                else:
                    if type_name == 'char':
                        code += prefix21 + '"\\"" << ' + value.name + '->GetPointer() << "\\"";\n'
                    else:
                        code += prefix21 + '"\\"" << util::interception::WideStringToString(' + value.name + '->GetPointer()) << "\\"";\n'

            elif type_name == 'void':
                if value.is_array:
                    code += prefix21 + '"' + value.name + '" << " /* value = " << static_cast<uint16_t>(*' + value.name + '->GetPointer()) << " */";\n'
                elif count > 1:
                    code += prefix21 + '"' + value.name + '" << " /* address = " << *' + value.name + '->GetPointer() << " */";\n'
                else:
                    pass

            elif (type_name == 'UINT8') or (type_name == 'INT8'):
                pass

            else:
                if value.is_array:
                    code += self.add_array_argument(
                        value, indent_code, indent_file, is_output
                    )
                elif count > 1:
                    pass
                else:
                    code += prefix21 + "*" + value.name + '->GetPointer();\n'
            code += indent_code + '}\n'
            return code

        elif 'HRESULT' == type_name:
            return prefix11 + 'enumutil::GetResultValueString({});\n'.format(
                value.name
            )

        elif self.is_enum(type_name):
            return prefix11 + 'ConverttoText({})'.format(value.name) + ';\n'

        elif type_name == 'GUID':
            return prefix11 + 'ConverttoText(*{}.decoded_value)'.format(
                value.name
            ) + ';\n'

        elif self.is_function_ptr(type_name):
            return prefix11 + '"{}'.format(
                value.name
            ) + ' /* address = " << ' + value.name + ' << " */";\n'

        elif self.is_struct(type_name):
            return indent_code + 'WriteStructString(oss, &{}, "{}", {}, {});\n'.format(
                value.name, indent_file, prefix_string, output_string
            )

        elif self.is_handle(type_name):
            return prefix11 + value.name + ';\n'

        elif type_name == 'UINT8':
            return prefix11 + 'static_cast<uint16_t>(' + value.name + ');\n'

        elif type_name == 'INT8':
            return prefix11 + 'static_cast<int16_t>(' + value.name + ');\n'

        elif type_name == 'BOOL':
            return indent_code + 'WriteBOOLString(oss, {}, "{}", {});\n'.format(
                value.name, indent_file, output_string
            )

        return prefix11 + value.name + ';\n'

    def add_array_argument(self, value, indent_code, indent_file, is_output):
        if not value.is_array:
            return ''
        type_name = value.base_type
        indent_base = '    '
        indent_code2 = indent_code + indent_base
        code = ''
        output_string = 'false'
        if is_output:
            output_string = 'true'

        if self.is_enum(type_name) or type_name == 'GUID':
            code += indent_code2 + 'WriteArrayConvertsString(oss, {}, "{}", {});\n'.format(
                value.name, indent_file, output_string
            )
        elif self.is_struct(type_name):
            code += indent_code2 + 'WriteArrayStructsString(oss, {}, "{}", {});\n'.format(
                value.name, indent_file, output_string
            )
        elif self.is_class(value):
            code += indent_code2 + 'WriteArrayClassesString(oss, {}, "{}", "{}", {});\n'.format(
                value.name, value.base_type, indent_file, output_string
            )
        elif type_name == 'BOOL':
            code += indent_code2 + 'WriteArrayBOOLsString(oss, {}, "{}", {});\n'.format(
                value.name, indent_file, output_string
            )
        else:
            code += indent_code2 + 'WriteArrayValuesString(oss, {}, "{}", {});\n'.format(
                value.name, indent_file, output_string
            )
        return code

    def write_struct_functions(self):
        struct_dict = self.source_dict['struct_dict']
        indent = '    '
        prefix = '    oss << '

        for k, v in struct_dict.items():
            if self.is_struct_black_listed(k):
                continue
            code = 'void WriteStructString(std::ostringstream& oss, const Decoded_{}* value, const char* indent, const bool prefix, const bool output)\n'.format(
                k
            )
            code += '{\n'
            code += indent + 'std::string indent2 = indent;\n'
            code += indent + 'indent2.append("    ");\n'
            code += indent + 'std::string indent_first = indent;\n'
            code += indent + 'if (prefix)\n'
            code += indent + '{\n'
            code += indent + '    indent_first = "   ";\n'
            code += indent + '}\n'
            code += indent + 'std::string output_string = "";\n'
            code += indent + 'if (output)\n'
            code += indent + '{\n'
            code += indent + '    output_string = "/* out */ ";\n'
            code += indent + '}\n'
            code += prefix + 'indent_first << output_string << "' + k + '{\\n";\n'

            index = 0
            props_len = 0
            for prop_type, props in v['properties'].items():
                props_len += len(props)

            for prop_type, props in v['properties'].items():
                for p in props:
                    value = self.get_value_info(p)
                    index += 1
                    comma = '",\\n"'
                    if index == props_len:
                        comma = '"}"'
                    code += self.add_struct_argument(value)
                    code += '    oss << {};\n\n'.format(comma)

            code += '}\n'
            write(code, file=self.outFile)

    def add_struct_argument(self, value):
        type_name = value.base_type
        indent_base = '    '
        indent_code = indent_base
        indent_code2 = indent_code + indent_base
        prefix12 = self.trim_generate_write_empty(indent_code + 'oss << indent2 << ')
        prefix22 = self.trim_generate_write_empty(indent_code2 + 'oss << indent2 << ')

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_class(value):
                if value.is_array:
                    pass
                elif count > 1:
                    pass
                else:
                    return prefix12 + '"{}_id" << '.format(
                        value.base_type
                    ) + 'value->' + value.name + ';\n'

            elif type_name == 'void':
                if value.is_array:
                    pass
                elif count > 1:
                    pass
                else:
                    return prefix12 + 'value->' + value.name + ';\n'

            if self.is_struct(type_name):
                code = indent_code + 'if (WriteCheckPointerDecoderNull(oss, value->{}, indent2.c_str()))\n'.format(
                    value.name
                )
            else:
                code = indent_code + 'if (WriteCheckPointerDecoderNull(oss, &value->{}, indent2.c_str()))\n'.format(
                    value.name
                )

            code += indent_code + '{\n'

            if self.is_enum(type_name):
                if value.is_array:
                    code += self.add_struct_array_argument(value)
                elif count > 1:
                    pass
                else:
                    code += prefix22 + 'ConverttoText(*{}->GetPointer());\n'.format(
                        value.name
                    )

            elif type_name == 'GUID':
                if value.is_array:
                    code += self.add_struct_array_argument(value)
                elif count > 1:
                    pass
                else:
                    pass

            elif self.is_struct(type_name):
                if value.is_array:
                    code += self.add_struct_array_argument(value)
                elif count > 1:
                    code += indent_code2 + 'WriteStructString(oss, *value->{}->GetMetaStructPointer(), indent2.c_str());\n'.format(
                        value.name
                    )
                else:
                    code += indent_code2 + 'WriteStructString(oss, value->{}->GetMetaStructPointer(), indent2.c_str());\n'.format(
                        value.name
                    )

            elif self.is_class(value):
                if value.is_array:
                    pass
                elif count > 1:
                    pass
                else:
                    pass

            elif type_name == 'wchar_t' or type_name == 'char':
                if count > 1:
                    code += self.add_struct_array_argument(value)
                else:
                    if type_name == 'char':
                        code += prefix22 + '"\\"" << value->' + value.name + '.GetPointer() << "\\"";\n'
                    else:
                        code += prefix22 + '"\\"" << util::interception::WideStringToString(value->' + value.name + '.GetPointer()) << "\\"";\n'

            elif type_name == 'void':
                if value.is_array:
                    code += prefix22 + '"' + value.name + '" << " /* value = " << static_cast<uint16_t>(*value->' + value.name + '.GetPointer()) << " */";\n'
                elif count > 1:
                    pass
                else:
                    pass

            elif (type_name == 'UINT8') or (type_name == 'INT8'):
                pass

            else:
                if value.is_array:
                    code += self.add_struct_array_argument(value)
                elif count > 1:
                    pass
                else:
                    code += prefix22 + '*value->' + value.name + '.GetPointer();\n'
            code += indent_code + '}\n'
            return code

        elif 'HRESULT' == type_name:
            return prefix12 + 'enumutil::GetResultValueString(value->decoded_value->{});\n'.format(
                value.name
            )

        elif 'LARGE_INTEGER' == type_name:
            return prefix12 + 'value->' + value.name + '->decoded_value->QuadPart;\n'

        elif self.is_enum(type_name):
            return prefix12 + 'ConverttoText(value->decoded_value->{})'.format(
                value.name
            ) + ';\n'

        elif type_name == 'GUID':
            return prefix12 + 'ConverttoText(*value->{}->decoded_value)'.format(
                value.name
            ) + ';\n'

        elif self.is_function_ptr(type_name):
            return prefix12 + '"{}'.format(
                value.name
            ) + ' /* address = " << ' + value.name + ' << " */";\n'

        elif self.is_struct(type_name):
            return indent_code + 'WriteStructString(oss, value->{}, indent2.c_str());\n'.format(
                value.name
            )

        elif self.is_handle(type_name):
            return prefix12 + 'value->decoded_value->' + value.name + ';\n'

        elif type_name == 'UINT8':
            return prefix12 + 'static_cast<uint16_t>(value->decoded_value->' + value.name + ');\n'

        elif type_name == 'INT8':
            return prefix12 + 'static_cast<int16_t>(value->decoded_value->' + value.name + ');\n'

        elif type_name == 'BOOL':
            return indent_code + 'WriteBOOLString(oss, value->decoded_value->{}, indent2.c_str());\n'.format(
                value.name
            )

        return prefix12 + 'value->decoded_value->' + value.name + ';\n'

    def add_struct_array_argument(self, value):
        if not value.is_array:
            return ''
        type_name = value.base_type
        indent_base = '    '
        indent_code = indent_base
        indent_code2 = indent_code + indent_base
        code = ''

        if self.is_enum(type_name):
            code += indent_code2 + 'WriteArrayConvertsString(oss, &value->{}, indent2.c_str());\n'.format(
                value.name
            )
        elif type_name == 'GUID':
            code += indent_code2 + 'WriteArrayConvertsString(oss, value->{}, indent2.c_str());\n'.format(
                value.name
            )
        elif self.is_struct(type_name):
            code += indent_code2 + 'WriteArrayStructsString(oss, value->{}, indent2.c_str());\n'.format(
                value.name
            )
        elif self.is_class(value):
            code += indent_code2 + 'WriteArrayClassesString(oss, value->{}, "{}", indent2.c_str());\n'.format(
                value.name, value.base_type
            )
        elif type_name == 'BOOL':
            code += indent_code2 + 'WriteArrayBOOLsString(oss, value->{}, indent2.c_str());\n'.format(
                value.name
            )
        elif type_name == 'wchar_t':
            code += indent_code2 + 'WriteArrayWStringsString(oss, &value->{}, indent2.c_str());\n'.format(
                value.name
            )
        else:
            code += indent_code2 + 'WriteArrayValuesString(oss, &value->{}, indent2.c_str());\n'.format(
                value.name
            )
        return code

    def trim_generate_write_empty(self, value):
        return value.replace('"" << ', '')
