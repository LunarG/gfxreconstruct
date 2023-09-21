#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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

class Dx12EnumToStringBodyGenerator(Dx12BaseGenerator):
    """TODO : Generates C++ functions responsible for Convert to texts."""

    BITS_LIST = [
        '_FLAGS', '_STATES', '_STATUS', 'D3D12_SHADER_MIN_PRECISION_SUPPORT',
        'D3D12_FORMAT_SUPPORT1', 'D3D12_FORMAT_SUPPORT2', 'D3D11_SHADER_MIN_PRECISION_SUPPORT',
        'D3D11_FORMAT_SUPPORT'
    ]

    # The code for filtering duplicate enum values can't easily detect a case like the following, where
    # the enum value is calculated from another enum that includes duplicate values:
    #   D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_Y	= ( 1 << D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_Y )
    ALIAS_DICT = {
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_R':
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_Y',
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_G':
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_U',
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_B':
        'D3D11_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAG_V'
    }

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

        code = '#include "generated_dx12_enum_to_string.h"\n'
        write(code, file=self.outFile)

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()

    def generate_feature(self):
        for k, v in self.source_dict['enum_dict'].items():
            # Generate enum handler for all enums
            body = 'std::string ToString(const {0}& value)\n'
            body += '{{\n'
            body += '    switch (value) {{\n'
            processed_values = set()
            for value in v['values']:
                if (not value['value'] in processed_values) and (not value['name'] in self.ALIAS_DICT):
                    body += '    case {0}: return "{0}";\n'.format(value['name'])
                    processed_values.add(value['name'])
                    processed_values.add(value['value'])
            body += '    default: break;\n'
            body += '    }}\n'
            body += '    return "Unhandled {0}";\n'
            body += '}}\n'

            # Generate flags handler for enums identified as bitmasks
            for bits in self.BITS_LIST:
                if k.find(bits) >= 0:
                    body += '\nstd::string ToString_{0}(uint32_t flags)\n'
                    body += '{{\n'
                    body += '    return BitmaskToString<{0}>(flags);\n'
                    body += '}}\n'
            write(body.format(k), file=self.outFile)

        # Generate REFIID handler
        iids = list()
        for k, v in self.source_dict['header_dict'].items():
            if hasattr(v, 'variables'):
                for m in v.variables:
                    if 'DEFINE_GUID' in m['type']:
                        index = m['type'].find(',')
                        iids.append(m['type'][len('DEFINE_GUID ( '):index])
        body = 'template <> std::string ToString<IID>(const IID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize) { return ToString(obj); }\n'
        body += 'std::string ToString(const IID& iid)\n'
        body += '{\n'
        if not "IID_IUnknown" in iids:
            iids.append("IID_IUnknown")
        for iid in iids:
            body += '    if (iid == {0}) return "\\\"{0}\\\"";\n'.format(iid)
        body += '    return "\\\"Invalid IID\\\"";\n'
        body += '}\n'
        write(body, file=self.outFile)

    def endFile(self):
        """Methond override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
