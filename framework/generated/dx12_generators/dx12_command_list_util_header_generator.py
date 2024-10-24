#!/usr/bin/python3 -i
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


class Dx12CommandListUtilHeaderGenerator(Dx12BaseGenerator):
    """Generate a C++ class for Dx12 Track CommandList objects.
    """

    # Tracked data is union. That's written in custom functions.
    SKIP_COMMAND_METHODS = [
        'ID3D12GraphicsCommandList_ResourceBarrier',
        'ID3D12GraphicsCommandList4_BeginRenderPass',
        'ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure'
    ]

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

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        self.newline()

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(
                    class_value
                ) and 'CommandList' in class_name:
                    for m in class_value['methods']['public']:
                        if not self.is_method_black_listed(
                            class_name, m['name']
                        ):
                            self.write_track_function(class_name, m)

    def write_track_function(self, class_name, method_info):
        if (
            class_name + '_' + method_info['name']
        ) in self.SKIP_COMMAND_METHODS:
            return

        parameters = 'ID3D12CommandList_Wrapper* wrapper'
        required = False

        for p in method_info['parameters']:
            value = self.get_value_info(p)
            value_type = self.clean_type_define(p['type'])

            if value.array_length and (type(value.array_length) == int):
                value_type += '*'

            parameters += ', ' + value_type + ' ' + value.name
            if self.is_track_command_list(value):
                required = True

        if required:
            code = 'void Track_{}_{}({})'.format(
                class_name, method_info['name'], parameters
            )

            code += self.get_track_function_body(class_name, method_info)

            write(code, file=self.outFile)
            self.newline()

    def get_track_function_body(self, class_name, method_info):
        return ';'

    def write_include(self):
        code = ''
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        code += (
            "\n"
            "#include \"generated/generated_dx12_wrappers.h\"\n"
            "\n"
            "#include \"util/defines.h\"\n"
            "\n"
        )
        write(code, file=self.outFile)
