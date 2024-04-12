#!/usr/bin/env python3
#
# Copyright (c) 2021-2023 LunarG, Inc.
# Copyright (c) 2023 Valve Corporation
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
from dx12_enum_to_string_header_generator import Dx12EnumToStringHeaderGenerator
from reformat_code import format_cpp_code

class Dx12EnumToJsonHeaderGenerator(Dx12BaseGenerator):
    """Generates C++ functions which build JSON representations of enums."""

    BITS_LIST = Dx12EnumToStringHeaderGenerator.BITS_LIST

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

        code = format_cpp_code('''
            #if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

            /// @file Functions to convert enums to JSON. While trivial these do tidy up
            /// the FieldToJsons of structs which use them and the JSON consumer too.
            /// They also mean that generators don't need separate cases for enums.

            #include "util/json_util.h"
            #include "generated/generated_dx12_enum_to_string.h"
            #include "util/defines.h"
            #include "util/to_string.h"
            #include "format/platform_types.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
        ''')
        write(code, file=self.outFile)
        self.newline()

    def generate_feature(self):
        enum_dict = self.source_dict['enum_dict']
        enum_prototypes = ''
        flag_prototypes = ''

        for k, v in enum_dict.items():
            # Generate enum handler for all enums
            enum_prototypes += format_cpp_code('''inline void FieldToJson(nlohmann::ordered_json& jdata, const {0} value, const JsonOptions& options = JsonOptions())
            {{
                FieldToJson(jdata, ToString(value), options);
            }}
            inline void FieldToJson(nlohmann::ordered_json& jdata, const {0}* pEnum, const JsonOptions& options = JsonOptions())
            {{
                FieldToJson(jdata, *pEnum, options);
            }}
            '''.format(k))
            enum_prototypes += '\n\n'

            # Generate flags handler for enums identified as bitmasks
            for bits in self.BITS_LIST:
                if k.find(bits) >= 0:
                    flag_prototypes += format_cpp_code('''inline void FieldToJson_{0}(nlohmann::ordered_json& jdata, const uint32_t flags, const JsonOptions& options = JsonOptions())
                    {{
                        std::string representation;
                        if (!options.expand_flags)
                        {{
                            representation = to_hex_fixed_width(flags);
                        }}
                        else
                        {{
                            representation = ToString_{0}(flags);
                        }}
                        FieldToJson(jdata, representation, options);
                    }}
                    \n'''.format(k))
                    flag_prototypes += '\n'

        write(enum_prototypes, file=self.outFile)
        write(flag_prototypes, file=self.outFile)

        write(format_cpp_code('''
        // IID struct-as-enum special case:
        inline void FieldToJson(nlohmann::ordered_json& jdata, const IID& value, const JsonOptions& options = JsonOptions())
        {
            FieldToJson(jdata, ToString(value), options);
        }
        '''), file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        code = format_cpp_code('''
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)

            #endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
        ''')
        write(code, file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
