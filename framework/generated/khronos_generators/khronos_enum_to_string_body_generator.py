#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2024 LunarG, Inc.
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
from khronos_base_generator import write


# KhronosEnumToStringBodyGenerator
# Generates C++ functions for stringifying Khronos API enums.
class KhronosEnumToStringBodyGenerator():
    """Generate C++ functions for Khronos ToString() functions"""

    def skip_generating_enum_to_string_for_type(self, type):
        """ Method may be overridden"""
        return False

    def write_enum_to_string_body(self):
        for enum in sorted(self.enum_names):
            if enum in self.enumAliases or self.skip_generating_enum_to_string_for_type(enum):
                continue
            if self.is_flags_enum_64bit(enum):
                # Since every caller needs to know exactly what it is calling, we may as well
                # dispense with the parameters that are always ignored:
                body = 'std::string {0}ToString(const {0} value)\n'
            else:
                body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags, uint32_t, uint32_t)\n'
            body += '{{\n'
            enumerants = self.enumEnumerants[enum]
            if len(enumerants):
                body += '    switch (value) {{\n'
                for enumerant in enumerants:
                    body += '    case {0}: return "{0}";\n'.format(
                        enumerant
                    )
                body += '    default: break;\n'
                body += '    }}\n'
            body += '    return "Unhandled {0}";\n'
            body += '}}\n'
            if 'Bits' in enum:
                if self.is_flags_enum_64bit(enum):
                    body += '\nstd::string {1}ToString(VkFlags64 vkFlags)\n'
                    body += '{{\n'
                    body += '    std::string   str;\n'
                    body += '    VkFlags64     index = 0U;\n'
                    body += '    while (vkFlags)\n'
                    body += '    {{\n'
                    body += '        if (vkFlags & 1U)\n'
                    body += '        {{\n'
                    body += '            if (!str.empty())\n'
                    body += '            {{\n'
                    body += '                str += \'|\';\n'
                    body += '            }}\n'
                    body += '            str.append({0}ToString(static_cast<{0}>(1U) << index));\n'
                    body += '        }}\n'
                    body += '        ++index;\n'
                    body += '        vkFlags >>= 1U;\n'
                    body += '    }}\n'
                    body += '    if (str.empty())\n'
                    body += '    {{\n'
                    body += '        str.append({0}ToString(0U));\n'
                    body += '    }}\n'
                    body += '    return str;\n'
                    body += '}}\n'
                else:
                    # Original version(these are never actually being called which is part of issue #620):
                    body += '\ntemplate <> std::string ToString<{0}>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)\n'
                    # Simpler, non-template version that matches the 64 bit version above. Changing
                    # to these signatures actually compiles fine, showing the originals were never
                    # called anywhere. Leaving this commented-out but ready for the PR that fixes
                    # issue #620 to use.
                    # body += '\nstd::string {1}ToString(VkFlags vkFlags)\n'
                    body += '{{\n'
                    body += '    return BitmaskToString<{0}>(vkFlags);\n'
                    body += '}}\n'
            write(
                body.format(enum, self.get_flags_type_from_enum(enum)),
                file=self.outFile
            )
