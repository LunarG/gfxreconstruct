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

import sys, inspect
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator

class Dx12StructToStringBodyGenerator(Dx12BaseGenerator):
    """TODO : Generates C++ functions responsible for Convert to texts."""

    BITS_LIST = [
        '_FLAGS', '_STATES', '_STATUS', 'D3D12_SHADER_MIN_PRECISION_SUPPORT',
        'D3D12_FORMAT_SUPPORT1', 'D3D12_FORMAT_SUPPORT2'
    ]

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
        """Methond override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)

        code = '#include "generated_dx12_struct_to_string.h"\n'
        code += '#include "generated_dx12_enum_to_string.h"\n'
        write(code, file=self.outFile)

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        for k, v in struct_dict.items():
            if not self.is_struct_black_listed(k):
                body = inspect.cleandoc('''
                    template <> std::string ToString<{0}>(const {0}& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
                    {{
                        return ObjectToString(toStringFlags, tabCount, tabSize,
                            [&](std::stringstream& strStrm)
                            {{
                    '''.format(k))
                body += '\n'
                body += self.makeStructBody(k, v)
                body += inspect.cleandoc('''
                            }
                        );
                    }
                    ''')
                body += '\n'
                write(body, file=self.outFile)

    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        for propertyType, properties in values['properties'].items():
            for p in properties:
                value = self.get_value_info(p)

                # Start with a static_assert() so that if any values make it through the logic
                #   below without being handled the generated code will fail to compile
                toString = 'static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`")'

                #### # pNext requires custom handling
                #### if 'pNext' in value.name:
                ####     toString = 'PNextToString(obj.pNext, toStringFlags, tabCount, tabSize)'

                #### # Function pointers and void data pointers simply write the address
                #### elif 'pfn' in value.name or 'void' in value.fullType:
                ####     toString = '"\\"" + PtrToString(obj.{0}) + "\\""'

                #### # C strings require custom handling
                #### elif 'const char*' in value.fullType:
                ####     if 'const char* const*' in value.fullType:
                ####         toString = 'CStrArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                ####     else:
                ####         toString = '(obj.{0} ? ("\\"" + std::string(obj.{0}) + "\\"") : "null")'

                # There's some repeated code in this if/else block...for instance, arrays of
                #   structs, enums, and primitives all route through ArrayToString()...It's
                #   easier (imo) to reason about each case when they're all listed explictly
                if value.is_pointer:
                    if value.is_array:
                        if self.is_handle(value.base_type):
                            toString = '" TODO : VkHandleArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        elif self.is_struct(value.base_type):
                            toString = '" TODO : ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        elif self.is_enum(value.base_type):
                            toString = '" TODO : VkEnumArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        else:
                            toString = '" TODO : ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                    else:
                        if self.is_handle(value.base_type):
                            toString = '" TODO : static_assert(false, "Unhandled pointer to VkHandle in `dx12_struct_to_string_body_generator.py`") "'
                        elif self.is_struct(value.base_type):
                            # toString = '" TODO : (obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null") "'
                            toString = '" TODO :"'
                        elif self.is_enum(value.base_type):
                            toString = '" TODO : static_assert(false, "Unhandled pointer to VkEnum in `dx12_struct_to_string_body_generator.py`") "'
                        else:
                            # toString = '" TODO : (obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null") "'
                            toString = '" TODO :"'
                else:
                    if value.is_array:
                        if self.is_handle(value.base_type):
                            toString = '" TODO : VkHandleArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        elif self.is_struct(value.base_type):
                            toString = '" TODO : ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        elif self.is_enum(value.base_type):
                            toString = '" TODO : ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                        elif 'char' in value.base_type:
                            # toString = '" TODO : \'"\' + std::string(obj.{0}) + \'"\' "'
                            toString = '" TODO :"'
                        #### elif 'UUID' in value.array_length or 'LUID' in value.array_length:
                        ####     toString = '" TODO : \'"\' + UIDToString({1}, obj.{0}) + \'"\' "'
                        else:
                            toString = '" TODO : ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize) "'
                    else:
                        if self.is_handle(value.base_type):
                            toString = '" TODO : \'"\' + VkHandleToString(obj.{0}) + \'"\'"'
                        elif self.is_struct(value.base_type):
                            toString = '" TODO : ToString(obj.{0}, toStringFlags, tabCount, tabSize)"'
                        elif self.is_enum(value.base_type):
                            # toString = '" TODO : \'"\' + ToString(obj.{0}, toStringFlags, tabCount, tabSize) + \'"\' "'
                            toString = '" TODO :"'
                        else:
                            toString = '" TODO : ToString(obj.{0}, toStringFlags, tabCount, tabSize) "'

                firstField = 'true' if not body else 'false'
                # toString = toString.format(value.name, value.arrayLength)
                toString = toString.format(value.name, value.array_length)
                # body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(firstField, value.name, toString)
                body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(firstField, value.name, toString)
        return body
    # yapf: enable

    def endFile(self):
        """Methond override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
