#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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
        self.STRUCT_BLACKLIST.append('DXGI_DISPLAY_COLOR_SPACE')
        self.STRUCT_BLACKLIST.append('D3D12_RAYTRACING_INSTANCE_DESC')
        self.STRUCT_BLACKLIST.append('D3D12_CPU_DESCRIPTOR_HANDLE')
        self.STRUCT_BLACKLIST.append('D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION')
        self.STRUCT_BLACKLIST.append('D3D12_GPU_DESCRIPTOR_HANDLE')
        self.STRUCT_BLACKLIST.append('_SECURITY_ATTRIBUTES')
        self.STRUCT_BLACKLIST.append('GUID')
        Dx12BaseGenerator.beginFile(self, gen_opts)

        code = '#include "generated_dx12_struct_to_string.h"\n'
        code += '#include "decode/custom_dx12_ascii_consumer.h"\n'
        code += '#include "decode/custom_dx12_to_string.h"\n'
        code += '#include "generated_dx12_enum_to_string.h"\n'
        write(code, file=self.outFile)

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        for k, v in struct_dict.items():
            if (not self.is_struct_black_listed(k)) and (not '<anon-' in k):
                body = inspect.cleandoc('''
                    std::string ToString(const {0}& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
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
        for property_type, properties in values['properties'].items():
            for p in properties:
                value = self.get_value_info(p)

                # Start with a static_assert() so that if any values make it through the logic
                #   below without being handled the generated code will fail to compile
                to_string = 'static_assert(false, "Unhandled value in `dx12_struct_to_string_body_generator.py`")'

                # There's some repeated code in this if/else block...for instance, arrays of
                #   structs, enums, and primitives all route through ArrayToString()...It's
                #   easier (imo) to reason about each case when they're all listed explictly
                if value.is_pointer:
                    if value.is_array:
                        if self.is_handle(value.base_type):
                            to_string = 'static_assert(false, "Unhandled pointer to dynamic array of handles in `dx12_struct_to_string_body_generator.py`")'
                        elif self.is_struct(value.base_type):
                            to_string = 'ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                        elif self.is_enum(value.base_type):
                            to_string = 'EnumArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                        elif self.get_category_type(value.base_type) == 'class' or value.base_type == 'void':
                            to_string = 'HandleIdToString(obj.{0})'
                        else:
                            to_string = 'ArrayToString(obj.{1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    else:
                        if self.is_handle(value.base_type):
                            to_string = 'static_assert(false, "Unhandled pointer to handle in `dx12_struct_to_string_body_generator.py`")'
                        elif self.is_struct(value.base_type):
                            to_string = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
                        elif self.is_enum(value.base_type):
                            to_string = 'static_assert(false, "Unhandled pointer to enum in `dx12_struct_to_string_body_generator.py`")'
                        elif self.get_category_type(value.base_type) == 'class' or value.base_type == 'void':
                            to_string = 'HandleIdToString(obj.{0})'
                        else:
                            to_string = '(obj.{0} ? ToString(*obj.{0}, toStringFlags, tabCount, tabSize) : "null")'
                else:
                    if value.is_array:
                        if self.is_handle(value.base_type):
                            to_string = 'static_assert(false, "Unhandled static array of handles in `dx12_struct_to_string_body_generator.py`")'
                        elif self.is_struct(value.base_type):
                            to_string = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                        elif self.is_enum(value.base_type):
                            to_string = 'EnumArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                        elif 'wchar' in value.base_type:
                            to_string = 'Quote(WCharArrayToString(obj.{0}))'
                        else:
                            to_string = 'ArrayToString({1}, obj.{0}, toStringFlags, tabCount, tabSize)'
                    else:
                        if self.is_handle(value.base_type):
                            to_string = 'static_assert(false, "Unhandled handle in `dx12_struct_to_string_body_generator.py`")'
                        elif self.is_struct(value.base_type):
                            to_string = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'
                        elif self.is_enum(value.base_type):
                            to_string = 'Quote(ToString(obj.{0}))'
                        else:
                            to_string = 'ToString(obj.{0}, toStringFlags, tabCount, tabSize)'

                first_field = 'true' if not body else 'false'
                to_string = to_string.format(value.name, value.array_length)
                body += '            FieldToString(strStrm, {0}, "{1}", toStringFlags, tabCount, tabSize, {2});\n'.format(first_field, value.name, to_string)
        return body
    # yapf: enable

    def endFile(self):
        """Methond override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
