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

class Dx12EnumToStringHeaderGenerator(Dx12BaseGenerator):
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

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        enum_dict = self.source_dict['enum_dict']
        for k, v in enum_dict.items():
            body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags to_string_flags, uint32_t tab_count, uint32_t tab_size);'
            for bits in self.BITS_LIST:
                if k.find(bits) >= 0:
                    body += '\ntemplate <> std::string ToString<{0}>(uint32_t flags, ToStringFlags to_string_flags, uint32_t tab_count, uint32_t tab_size);'
            write(body.format(k), file=self.outFile)

        #### for enum in sorted(self.enumNames):
        ####     if not enum in self.processedEnums:
        ####         self.processedEnums.add(enum)
        ####         if not enum in self.enumAliases:
        ####             body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'
        ####             if 'Bits' in enum:
        ####                 body += '\ntemplate <> std::string ToString<{0}>(VkFlags vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'
        ####             write(body.format(enum), file=self.outFile)


        #### """Methond override."""
        #### Dx12BaseGenerator.generate_feature(self)
        #### self.colloect_iid_list = list()

        #### self.write_enum_covert_to_text()
        #### self.write_iid_covert_to_text()

    def write_include(self):
        code = ''
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        code += '#include "format/platform_types.h"\n'
        code += '#include "util/defines.h"\n'
        code += '#include "util/to_string.h"\n'
        write(code, file=self.outFile)




    #### def write_enum_covert_to_text(self):
    ####     enum_dict = self.source_dict['enum_dict']
    ####     for k, v in enum_dict.items():
    ####         code = 'static const std::string ConverttoText(const {} value)\n'\
    ####                '{{\n'.format(k)

    ####         is_bits = False
    ####         for bits in self.BITS_LIST:
    ####             if k.find(bits) >= 0:
    ####                 is_bits = True
    ####                 break
    ####         if is_bits:
    ####             code += '    std::string code = "";\n'
    ####             for value in v['values']:
    ####                 if value['value'] == 0:
    ####                     code += '    if (value == {})\n'.format(value['name'])
    ####                     code += '    {\n'
    ####                     code += '        return "{}";\n'.format(value['name'])
    ####                 else:
    ####                     code += '    if ({} & value)\n'.format(value['name'])
    ####                     code += '    {\n'
    ####                     code += '        if (code.length() > 0) code.append(" | ");\n'
    ####                     code += '        code.append("{}");\n'.format(
    ####                         value['name']
    ####                     )
    ####                 code += '    }\n'
    ####             code += '    if (code.length() == 0)\n'
    ####             code += '    {\n'
    ####             code += '        code.append("Invalid {}(");\n'.format(k)
    ####             code += '        code.append(std::to_string(value));\n'
    ####             code += '        code.append(")");\n'
    ####             code += '    }\n'
    ####             code += '    return code;\n'
    ####         else:
    ####             value_set = set()
    ####             code += '    switch(value)\n'
    ####             code += '    {\n'
    ####             for value in v['values']:
    ####                 if (
    ####                     (type(value['value']) == int) or
    ####                     (('+ 1') in value['value'])
    ####                 ) and (not value['value'] in value_set):
    ####                     code += '        case({0}):\n'\
    ####                             '            return "{0}";\n'.format(value['name'])
    ####                     value_set.add(value['value'])

    ####             code += '        default:\n'\
    ####                     '            {{\n'\
    ####                     '                std::string code = "Invalid {}(";\n'\
    ####                     '                code.append(std::to_string(value));\n'\
    ####                     '                code.append(")");\n'\
    ####                     '                return code;\n'\
    ####                     '            }}\n'\
    ####                     '    }}\n'.format(k)
    ####         code += '}\n'
    ####         write(code, file=self.outFile)




    #### def write_iid_covert_to_text(self):
    ####     self.colloect_iid_list = list()
    ####     header_dict = self.source_dict['header_dict']
    ####     for k, v in header_dict.items():
    ####         if hasattr(v, 'variables'):
    ####             for m in v.variables:
    ####                 if 'DEFINE_GUID' in m['type']:
    ####                     index = m['type'].find(',')
    ####                     self.colloect_iid_list.append(
    ####                         m['type'][len('DEFINE_GUID ( '):index]
    ####                     )

    ####     code = 'static std::string ConverttoText(REFIID value)\n'\
    ####            '{\n'\

    ####     for iid in self.colloect_iid_list:
    ####         code += '    if(value == {0})\n'\
    ####                 '    {{\n'\
    ####                 '        return "{0}";\n'\
    ####                 '    }}\n'.format(iid)

    ####     code += '    return "Invalid IID";\n'\
    ####             '}\n'
    ####     write(code, file=self.outFile)




    def endFile(self):
        """Methond override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
