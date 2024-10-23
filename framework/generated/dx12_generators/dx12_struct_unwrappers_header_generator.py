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
from dx12_base_generator import Dx12BaseGenerator, write


# Generates declarations for functions to unwrap struct members with a
# COM object type before the struct is passed as an argument to a DX12
# API call during DX12 capture.
class Dx12StructUnwrappersHeaderGenerator(Dx12BaseGenerator):
    # Default C++ code indentation size.
    INDENT_SIZE = 4

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

    # Method override
    def beginFile(self, genOpts):
        Dx12BaseGenerator.beginFile(self, genOpts)

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()

        # List containing names of structs with COM object members.
        structs_with_objects = {
            **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE':
            ['ptr']
        }

        # Find structs with COM object members, which will need to be
        # unwrapped.
        struct_dict = self.source_dict['struct_dict']
        for struct in struct_dict:
            self.check_struct_member_handles(
                struct, structs_with_objects, None, True
            )

        # Generate unwrap functions for any structs that were added to
        # the list.
        for key in structs_with_objects:
            if not self.is_struct_black_listed(key):
                self.write_struct_unwrap_def(key)

        write('template <typename T>', file=self.outFile)
        write(
            'T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));',
            file=self.outFile
        )
        self.newline()
        write(
            '    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);',
            file=self.outFile
        )
        write(
            '    size_t         num_bytes = len * sizeof(T);',
            file=self.outFile
        )
        self.newline()
        write(
            '    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));',
            file=self.outFile
        )
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'const T* UnwrapStructPtrObjects(const T* value, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    T* unwrapped_struct = nullptr;', file=self.outFile)
        self.newline()
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);',
            file=self.outFile
        )
        write(
            '        UnwrapStructObjects(unwrapped_struct, unwrap_memory);',
            file=self.outFile
        )
        write('    }', file=self.outFile)
        self.newline()
        write('    return unwrapped_struct;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'const T* UnwrapStructArrayObjects(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if ((values != nullptr) && (len > 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            UnwrapStructObjects(&unwrapped_structs[i], unwrap_memory);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        self.newline()
        write('        return unwrapped_structs;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write(
            '    // Leave the original memory in place when the pointer is not null, but size is zero.',
            file=self.outFile
        )
        write('    return values;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)

    def write_struct_unwrap_def(self, struct, indent=''):
        expr = indent + 'void UnwrapStructObjects({}* value, '\
            'HandleUnwrapMemory* unwrap_memory);\n'.format(struct)

        write(expr, file=self.outFile)

    def write_include(self):
        code = ''

        code += '#include "encode/handle_unwrap_memory.h"\n'
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        write(code, file=self.outFile)

    def increment_indent(self, indent):
        return indent + (' ' * self.INDENT_SIZE)

    def decrement_indent(self, indent):
        return indent[:-self.INDENT_SIZE]
