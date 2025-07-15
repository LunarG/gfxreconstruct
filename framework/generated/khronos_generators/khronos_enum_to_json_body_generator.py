#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2025 LunarG, Inc.
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

import sys, textwrap
from khronos_base_generator import write
from reformat_code import format_cpp_code


# KhronosEnumToJsonBodyGenerator
# Generates C++ functions for stringifying Khronos API enums.
class KhronosEnumToJsonBodyGenerator():
    """Generate C++ functions to serialize Khronos enumaration to JSON"""

    def skip_generating_enum_to_json_for_type(self, type):
        """ Method may be overridden"""
        return False

    def make_decls(self):
        body = format_cpp_code(
            '''
            using util::JsonOptions;
            using util::to_hex_fixed_width;

            template<typename TFlags, typename ToStringFunctionType>
            std::string ExpandFlags(TFlags flags, ToStringFunctionType toString)
            {
                if (flags == 0)
                {
                    return to_hex_fixed_width(flags);
                }
                uint32_t bit_number = 0;
                bool first = true;
                std::ostringstream ostr;
                while (flags != 0)
                {
                    if (flags & 1)
                    {
                        if (!first) ostr << "|";
                        ostr << toString((flags & 1) << bit_number);
                        first = false;
                    }
                    bit_number++;
                    flags = flags >> 1;
                }
                return ostr.str();
            }
        '''
        )
        write(body, file=self.outFile)
        self.newline()
        self.newline()

        # Set of enums that have been processed since we'll encounter enums that are
        #   referenced by extensions multiple times.  This list is prepopulated with
        #   enums that should be skipped.
        processedEnums = set()

        for enum in sorted(self.enum_names):
            if enum in processedEnums or enum in self.enumAliases or self.skip_generating_enum_to_json_for_type(
                enum
            ):
                continue

            processedEnums.add(enum)

            if self.is_flags_enum_64bit(enum):
                body = 'void FieldToJson({0}_t, nlohmann::ordered_json& jdata, const {0}& value, const JsonOptions& options)\n'
            else:
                body = 'void FieldToJson(nlohmann::ordered_json& jdata, const {0}& value, const JsonOptions& options)\n'
            body += '{{\n'
            if len(self.enumEnumerants[enum]):
                body += '    switch (value) {{\n'
                for enumerant in self.enumEnumerants[enum]:
                    body += textwrap.indent(
                        prefix='        ',
                        text=textwrap.dedent(
                            '''\
                    case {0}:
                        jdata = "{0}";
                        break;
                    '''.format(enumerant)
                        )
                    )
                body += '        default:\n'
                body += '            jdata = to_hex_fixed_width(value);\n'
                body += '            break;\n'
                body += '    }}\n'
            else:
                body += '    jdata = to_hex_fixed_width(value);\n'

            body += '}}\n'
            body = body.format(enum)
            write(body, file=self.outFile)

        for flag in sorted(self.flags_types):
            if flag in self.flags_type_aliases or self.skip_generating_enum_to_json_for_type(flag):
                continue

            bittype = None
            if flag in self.flags_to_enum_bits:
                bittype = self.flags_to_enum_bits[flag]

            body = 'void FieldToJson({0}_t, nlohmann::ordered_json& jdata, const {1} flags, const JsonOptions& options)\n'
            body += '{{\n'
            if bittype is not None and len(self.enumEnumerants[bittype]):
                body += "    if (!options.expand_flags)\n"
                body += "    {{\n"
                body += "        jdata = to_hex_fixed_width(flags);\n"
                body += "        return;\n"
                body += "    }}\n"
                body += "    jdata = ExpandFlags(flags, []({1} flags)\n"
                body += "    {{\n"
                body += '        switch (flags)\n'
                body += '        {{\n'
                for enumerant in self.enumEnumerants[bittype]:
                    body += textwrap.indent(
                        prefix='            ',
                        text=textwrap.dedent(
                            '''\
                    case {0}:
                        return std::string("{0}");
                    '''.format(enumerant)
                        )
                    )
                body += '        }}\n'
                body += '        return to_hex_fixed_width(flags);\n'
                body += '    }});\n'
            else:
                body += '    jdata = to_hex_fixed_width(flags);\n'

            body += '}}\n'
            write(body.format(flag, self.flags_types[flag]), file=self.outFile)
