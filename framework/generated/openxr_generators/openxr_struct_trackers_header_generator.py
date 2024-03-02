#!/usr/bin/python3 -i
#
# Copyright (c) 2023-2024 LunarG, Inc.
# Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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


class OpenXrStructTrackersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function prototypes to track (deepcopy) OpenXR structs at API capture for trimming."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


class OpenXrStructTrackersHeaderGenerator(BaseGenerator):
    """OpenXrStructTrackersHeaderGenerator - subclass of BaseGenerator.
    Generates C++ function prototypes to track (deepcopy) OpenXR structs
    at API capture for trimming.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "encode/handle_unwrap_memory.h"', file=self.outFile)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
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

    def endFile(self):
        """Method override."""
        self.newline()
        write(
            'void* TrackStruct(const void* value, HandleUnwrapMemory* unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if alias:
            return

        if typename in ['XrBaseInStructure', 'XrBaseOutStructure']:
            return

        struct_type_enum = self.make_structure_type_enum(typeinfo, typename)
        if struct_type_enum is None:
            return

        write(
            f'{typename}* TrackStruct(const {typename}* value, HandleUnwrapMemory* unwrap_memory);',
            file=self.outFile
        )
