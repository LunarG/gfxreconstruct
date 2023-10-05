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

class Dx12StructDecodersToJsonBodyGenerator(Dx12BaseGenerator):
    """Generates C++ functions responsible for converting structs to JSON."""

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

        code = inspect.cleandoc('''
            #include "generated_dx12_struct_decoders_to_json.h"
            #include "generated_dx12_struct_decoders.h"
            
            #include "util/json_util.h"
            
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            
            using util::JsonOptions;
        ''')
        #code += '#include "decode/custom_dx12_to_string.h"\n'
        write(code, file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        for k, v in struct_dict.items():
            if not self.is_struct_black_listed(k):
                body = inspect.cleandoc('''
                    void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const JsonOptions& options)
                    {{
                        if (data && data->decoded_value)
                        {{
                            const {0}& decoded_value = *data->decoded_value;
                            const Decoded_{0}& meta_struct = *data;
                    '''.format(k))
                body += '\n'
                body += self.makeStructBody(k, v)
                body += inspect.cleandoc('''
                        /// @todo Follow the pNext chain, if any.
                    }
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

                # @todo BOOL type?  FieldToJson(jdata["RectsCoalesced"], obj.RectsCoalesced ???
                field_to_json = '        ; ///< @todo Generate for {0}[{1}]: ' + str(value.base_type)
                if not (value.is_pointer or value.is_array or self.is_handle(value.base_type) or self.is_struct(value.base_type) or self.is_enum(value.base_type)):
                    field_to_json = '        FieldToJson(jdata["{0}"], decoded_value.{0}, options); // base case'
                else:
                    if value.is_pointer:
                        field_to_json += " [is_pointer]"
                    if value.is_array:
                            field_to_json += " [is_array]"
                    if self.is_handle(value.base_type):
                        field_to_json += " [is_handle]"
                    elif self.is_struct(value.base_type):
                        field_to_json += " [is_struct]"
                    elif self.is_enum(value.base_type):
                        field_to_json += " [is_enum]"
                field_to_json = field_to_json.format(value.name, value.array_length)
                body += field_to_json + '\n'
        return body
    # yapf: enable

    def endFile(self):
        """Methond override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
