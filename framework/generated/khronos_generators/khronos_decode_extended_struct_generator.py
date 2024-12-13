#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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


class KhronosDecodeExtendedStructGenerator():
    """KhronosDecodeExtendedStructGenerator.
    Generates C++ code for a Khronos API's extended structure decoding.
    """

    def write_common_headers(self, gen_opts):
        # Get the current API and generate the items relavent to that
        current_api_data = self.get_api_data()
        lower_api_name = current_api_data.api_name.lower()

        write(
            '#include "decode/custom_{}_struct_decoders.h"'.
            format(lower_api_name),
            file=self.outFile
        )
        write('#include "decode/decode_allocator.h"', file=self.outFile)
        write(
            '#include "decode/{}_{}_node.h"'.format(
                lower_api_name,
                current_api_data.extended_struct_variable.lower()
            ),
            file=self.outFile
        )
        write(
            '#include "decode/{}_{}_typed_node.h"'.format(
                lower_api_name,
                current_api_data.extended_struct_variable.lower()
            ),
            file=self.outFile
        )
        write(
            '#include "generated/generated_{}_struct_decoders.h"'.
            format(lower_api_name),
            file=self.outFile
        )
        write(
            '#include "generated/generated_{}_enum_to_string.h"'.
            format(lower_api_name),
            file=self.outFile
        )
        write('#include "util/logging.h"', file=self.outFile)
        self.newline()
        write('#include <cassert>', file=self.outFile)

    def write_decode_struct_definition_prefix(self):
        current_api_data = self.get_api_data()

        write(
            'size_t Decode{prefix}Struct(const uint8_t* parameter_buffer, size_t buffer_size, {prefix}Node** {})'
            .format(
                current_api_data.extended_struct_variable,
                prefix=current_api_data.extended_struct_func_prefix
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    assert({} != nullptr);'.format(
                current_api_data.extended_struct_variable,
            ),
            file=self.outFile
        )
        self.newline()
        write('    size_t bytes_read = 0;', file=self.outFile)
        write('    uint32_t attrib = 0;', file=self.outFile)
        self.newline()

        offset_var = current_api_data.struct_type_variable.lower() + '_offset'
        write(
            '    if ((parameter_buffer != nullptr) && (buffer_size >= sizeof(attrib)))',
            file=self.outFile
        )
        write('    {', file=self.outFile)
        write('        size_t {} = 0;'.format(offset_var), file=self.outFile)
        self.newline()
        write(
            '        // Peek at the pointer attribute mask to make sure we have a non-NULL value that can be decoded.',
            file=self.outFile
        )
        write(
            '        attrib = *(reinterpret_cast<const uint32_t*>(parameter_buffer));',
            file=self.outFile
        )
        self.newline()
        write(
            '        if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)',
            file=self.outFile
        )
        write('        {', file=self.outFile)
        write(
            '            // Offset to {}, after the pointer encoding preamble.'
            .format(current_api_data.struct_type_enum),
            file=self.outFile
        )
        write(
            '            {} = sizeof(attrib);'.format(offset_var),
            file=self.outFile
        )
        self.newline()
        write(
            '            if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)',
            file=self.outFile
        )
        write('            {', file=self.outFile)
        write(
            '                {} += sizeof(format::AddressEncodeType);'.
            format(offset_var),
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('        }', file=self.outFile)
        self.newline()
        write(
            '        if (({offset} != 0) && ((buffer_size - {offset}) >= sizeof({})))'
            .format(current_api_data.struct_type_enum, offset=offset_var),
            file=self.outFile
        )
        write('        {', file=self.outFile)
        write(
            '            const {struct_type}* {} = reinterpret_cast<const {struct_type}*>(parameter_buffer + {});'
            .format(
                current_api_data.struct_type_variable,
                offset_var,
                struct_type=current_api_data.struct_type_enum
            ),
            file=self.outFile
        )
        self.newline()
        write(
            '            switch (*{})'.format(
                current_api_data.struct_type_variable
            ),
            file=self.outFile
        )
        write('            {', file=self.outFile)
        write('            default:', file=self.outFile)
        write(
            '                // TODO: This may need to be a fatal error',
            file=self.outFile
        )
        write(
            '                GFXRECON_LOG_ERROR("Failed to decode {} value with unrecognized {} = %s", (util::ToString(*{}).c_str()));'
            .format(
                current_api_data.extended_struct_variable,
                current_api_data.struct_type_enum,
                current_api_data.struct_type_variable,
            ),
            file=self.outFile
        )
        write('                break;', file=self.outFile)

    def write_decode_struct_definition_data(self):
        current_api_data = self.get_api_data()

        for struct in self.all_extended_structs:
            if struct in self.struct_type_names:
                stype = self.struct_type_names[struct]
                write('            case {}:'.format(stype), file=self.outFile)
                write(
                    '                (*{}) = DecodeAllocator::Allocate<{}TypedNode<Decoded_{}>>();'
                    .format(
                        current_api_data.extended_struct_variable,
                        current_api_data.extended_struct_func_prefix, struct
                    ),
                    file=self.outFile
                )
                write(
                    '                bytes_read = (*{})->Decode(parameter_buffer, buffer_size);'
                    .format(current_api_data.extended_struct_variable),
                    file=self.outFile
                )
                write('                break;', file=self.outFile)

        write('            }', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if ((bytes_read == 0) && (attrib != 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        // The encoded pointer attribute mask included kIsNull, or the {} was unrecognized.'
            .format(current_api_data.struct_type_variable),
            file=self.outFile
        )
        write(
            '        // We will report that we read the attribute mask, but nothing else was decoded.',
            file=self.outFile
        )
        write('        bytes_read = sizeof(attrib);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return bytes_read;', file=self.outFile)
        write('}', file=self.outFile)
