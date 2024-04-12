#!/usr/bin/env python3
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2021-2023 LunarG, Inc.
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
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_empty_lines

class Dx12StructDecodersToJsonHeaderGenerator(Dx12BaseGenerator):
    """Convert Struct Decoders to JSON."""

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
        """Method override."""
        Dx12BaseGenerator.beginFile(self, gen_opts)
        write('#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)', file=self.outFile)
        self.newline()

        code = inspect.cleandoc('''
            /// @file Functions to convert decoded structs to JSON.
            /// Note these Decoded_StructX versions have the pointer tree linking the
            /// structs set-up during decode, unlike the raw structs, which is why they
            /// should be used when dumping a JSON representation while following the
            /// pointers.

            #include "generated/generated_dx12_struct_decoders_forward.h"
            #include "decode/custom_dx12_struct_decoders_forward.h"
            #include "generated_dx12_enum_to_json.h"
            #include "util/defines.h"
            #include "nlohmann/json.hpp"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
            struct JsonOptions;
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_BEGIN_NAMESPACE(decode)
        ''')
        write(code, file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        ref_wrappers = remove_trailing_empty_lines(indent_cpp_code('''
          // Reference versions of above which simply pipe through to the pointer versions.
        '''))
        for k, v in struct_dict.items():
            if not self.is_struct_black_listed(k):
                body = 'void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* pObj, const util::JsonOptions& options);'.format(k)
                ref_wrappers += 'inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}& obj, const util::JsonOptions& options){{ FieldToJson(jdata, &obj, options); }}\n'.format(k)
                write(body, file=self.outFile)
        write(ref_wrappers, file=self.outFile)

    def endFile(self):
        """Method override."""
        custom_to_fields = '''

        // Custom, manually written implementations whose prototypes haven't been generated above:

        /// <winnt.h> Named union type with two structs and a uint64_t inside.
        void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* pObj, const util::JsonOptions& options);
        inline void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER& obj, const util::JsonOptions& options){ FieldToJson(jdata, &obj, options); }
        '''
        custom_to_fields = format_cpp_code(custom_to_fields)
        write(custom_to_fields, file=self.outFile)
        self.newline()
        code = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)

            #endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
        ''')
        write(code, file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

