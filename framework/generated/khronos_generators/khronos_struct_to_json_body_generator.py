#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2024 LunarG, Inc.
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
#

from khronos_base_generator import write
from reformat_code import indent_cpp_code, remove_leading_empty_lines, remove_trailing_newlines


class KhronosStructToJsonBodyGenerator():
    """KhronosStructToJsonBodyGenerator
    Generate C++ function definitions to serialize Khronos structures to JSON"""

    def should_decode_struct(self, struct):
        """Method indended to be overridden.
        Indicates that the provided struct is a struct we want to decode"""
        return True

    def decode_as_handle(self, parent_type, member):
        """ Method which may be overridden.
        Indicates that the given type should be decoded as a handle."""
        return self.is_handle(member.base_type)

    def write_body_contents(self):
        write('using util::JsonOptions;', file=self.outFile)
        write('using util::to_hex_variable_width;', file=self.outFile)
        write('using util::uuid_to_string;', file=self.outFile)
        self.newline()

        for struct in self.get_all_filtered_struct_names():
            if self.should_decode_struct(struct):
                body = '''
                    void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const JsonOptions& options)
                    {{
                        if (data && data->decoded_value)
                        {{
                            const {0}& decoded_value = *data->decoded_value;
                            const Decoded_{0}& meta_struct = *data;

                    '''.format(struct)
                body += self.makeStructBody(
                    struct, self.all_struct_members[struct]
                )
                body += remove_leading_empty_lines(
                    '''
                        }
                    }
                    '''
                )
                body = remove_trailing_newlines(indent_cpp_code(body))
                write(body, file=self.outFile)

        stype_var = self.get_struct_type_var_name()
        base_in_struct = self.get_base_input_structure_name()
        body = '''
            void FieldToJson(nlohmann::ordered_json& jdata, const PNextNode* data, const JsonOptions& options)
            {
                if (data && data->GetPointer())
                {
        '''
        body += '            const auto s_type = reinterpret_cast<const {}*>(data->GetPointer())->{};'.format(
            base_in_struct, stype_var
        )
        body += '''
                    switch (s_type)
                    {'''
        body += self.make_extended_struct_body()
        body = indent_cpp_code(body)
        write(body, file=self.outFile)

    #
    # Command definition
    def makeStructBody(self, name, values):
        body = ''
        has_extended_struct = False
        extended_struct_var_name = self.get_extended_struct_var_name()
        for value in values:
            type_name = self.make_decoded_param_type(value)

            # Determine the appropriate type.  If it's an alias, get
            # the original type
            value_type = value.base_type
            if (self.is_struct(value.base_type) and value.base_type in self.all_struct_aliases):
                value_type = self.all_struct_aliases[value.base_type]
            flagsEnumType = value_type

            if value.name == extended_struct_var_name:
                has_extended_struct = True
                continue

            # Default to getting the data from the native Vulkan struct:
            to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'

            if (
                self.is_function_ptr(value_type)
                or ('pUserData' == value.name or 'userData' == value.name)
            ):
                to_json = 'FieldToJson(jdata["{0}"], to_hex_variable_width(meta_struct.{0}), options)'
            elif value.is_pointer:
                if 'String' in type_name:
                    to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                elif self.is_handle(value_type):
                    to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                else:
                    to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
            else:
                if value.is_array:
                    if 'UUID' in value.array_length or 'LUID' in value.array_length:
                        to_json = 'FieldToJson(jdata["{0}"], uuid_to_string(sizeof(decoded_value.{0}), decoded_value.{0}), options)'
                    elif 'String' in type_name:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_handle(value_type):
                        to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_struct(value_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif not value.is_dynamic:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    else:
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                else:
                    if self.decode_as_handle(name, value):
                        to_json = 'HandleToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif value_type in self.formatAsHex:
                        to_json = 'FieldToJson(jdata["{0}"], to_hex_variable_width(decoded_value.{0}), options)'
                    elif self.is_struct(value_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif self.is_flags(value_type):
                        if value_type in self.flags_type_aliases:
                            flagsEnumType = self.flags_type_aliases[
                                value_type]
                        to_json = 'FieldToJson({2}_t(),jdata["{0}"], decoded_value.{0}, options)'
                    elif self.is_enum(value_type):
                        to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'
                    elif self.is_boolean_type(value_type):
                        to_json = 'jdata["{0}"] = static_cast<bool>(decoded_value.{0})'

            to_json = to_json.format(
                value.name, value_type, flagsEnumType
            )
            body += '        {0};\n'.format(to_json)

        # Handle the extended struct last
        if has_extended_struct:
            body += '        FieldToJson(jdata["{0}"], meta_struct.{0}, options);\n'.format(
                extended_struct_var_name
            )

        return body

    def make_extended_struct_body(self):
        body = ''
        var_name = self.get_extended_struct_var_name().lower()
        for struct in self.all_extended_structs:
            if struct not in self.struct_type_names:
                continue
            body += '''
            case {1}:
            {{
               const auto* {2} = reinterpret_cast<const Decoded_{0}*>(data->GetMetaStructPointer());
               FieldToJson(jdata, {2}, options);
               break;
            }}
            '''.format(struct, self.struct_type_names[struct], var_name)
        body += '\n'
        body += '            default:\n'
        body += '            {\n'
        body += '                GFXRECON_LOG_WARNING("Unknown {} node type: %u.", (unsigned) s_type);\n'.format(
            var_name
        )
        body += '            }\n'
        body += '        }\n'
        body += '    }\n'
        body += '}\n'
        return body
