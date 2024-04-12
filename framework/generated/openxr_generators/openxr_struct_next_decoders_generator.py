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
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class OpenXrStructNextDecodersGeneratorOptions(BaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    next switch statement generation.
    Options for OpenXR API next structure decoding C++ code generation.
    """

    def __init__(
        self,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


class OpenXrStructNextDecodersGenerator(BaseGenerator):
    """OpenXrStructNextDecodersGenerator - subclass of BaseGenerator.
    Generates C++ code for OpenXR API next structure decoding.
    Generate next structure decoding C++ code.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=False,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map to store XrStructureType enum values.
        self.stype_values = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "decode/custom_openxr_struct_decoders.h"',
            file=self.outFile
        )
        write('#include "decode/decode_allocator.h"', file=self.outFile)
        write('#include "decode/openxr_next_node.h"', file=self.outFile)
        write('#include "decode/openxr_next_typed_node.h"', file=self.outFile)
        write(
            '#include "generated/generated_openxr_struct_decoders.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_openxr_enum_to_string.h"',
            file=self.outFile
        )
        write('#include "util/logging.h"', file=self.outFile)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write(
            'size_t DecodeNextStruct(const uint8_t* parameter_buffer, size_t buffer_size,  OpenXrNextNode** next)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(next != nullptr);', file=self.outFile)
        self.newline()
        write('    size_t bytes_read = 0;', file=self.outFile)
        write('    uint32_t attrib = 0;', file=self.outFile)
        self.newline()
        write(
            '    if ((parameter_buffer != nullptr) && (buffer_size >= sizeof(attrib)))',
            file=self.outFile
        )
        write('    {', file=self.outFile)
        write('        size_t type_offset = 0;', file=self.outFile)
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
            '            // Offset to XrStructureType, after the pointer encoding preamble.',
            file=self.outFile
        )
        write('            type_offset = sizeof(attrib);', file=self.outFile)
        self.newline()
        write(
            '            if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)',
            file=self.outFile
        )
        write('            {', file=self.outFile)
        write(
            '                type_offset += sizeof(format::AddressEncodeType);',
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('        }', file=self.outFile)
        self.newline()
        write(
            '        if ((type_offset != 0) && ((buffer_size - type_offset) >= sizeof(XrStructureType)))',
            file=self.outFile
        )
        write('        {', file=self.outFile)
        write(
            '            const XrStructureType* type = reinterpret_cast<const XrStructureType*>(parameter_buffer + type_offset);',
            file=self.outFile
        )
        self.newline()
        write('            switch (*type)', file=self.outFile)
        write('            {', file=self.outFile)
        write('            default:', file=self.outFile)
        write(
            '                // TODO: This may need to be a fatal error',
            file=self.outFile
        )
        write(
            '                GFXRECON_LOG_ERROR("Failed to decode next value with unrecognized XrStructureType = %s", (util::ToString(*type).c_str()));',
            file=self.outFile
        )
        write('                break;', file=self.outFile)

    def endFile(self):
        """Method override."""
        write('            }', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if ((bytes_read == 0) && (attrib != 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        // The encoded pointer attribute mask included kIsNull, or the type was unrecognized.',
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
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        if not alias:
            # Only process struct types that specify a 'structextends' tag, which indicates the struct can be used in a next chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                stype = self.make_structure_type_enum(typeinfo, typename)
                if stype:
                    self.stype_values[typename] = stype

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.stype_values:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for struct in self.stype_values:
            write(
                '            case {}:'.format(self.stype_values[struct]),
                file=self.outFile
            )
            write(
                '                (*next) = DecodeAllocator::Allocate<OpenXrNextTypedNode<Decoded_{}>>();'
                .format(struct),
                file=self.outFile
            )
            write(
                '                bytes_read = (*next)->Decode(parameter_buffer, buffer_size);',
                file=self.outFile
            )
            write('                break;', file=self.outFile)
        self.stype_values = dict()
