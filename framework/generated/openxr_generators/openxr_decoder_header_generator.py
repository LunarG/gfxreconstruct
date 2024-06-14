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


class OpenXrDecoderHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class declaration for OpenXR API parameter decoding."""

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


class OpenXrDecoderHeaderGenerator(BaseGenerator):
    """OpenXrDecoderHeaderGenerator - subclass of BaseGenerator.
    Generates C++ member declarations for the OpenXrDecoder class responsible for decoding
    OpenXR API call parameter data.
    Generate a C++ class declaration for OpenXR API parameter decoding.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Names of any OpenXR commands whose decoders are manually generated
        self.MANUALLY_GENERATED_COMMANDS = [
            'xrEnumerateSwapchainImages',
        ]

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "decode/openxr_decoder_base.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write(
            'class OpenXrDecoder : public OpenXrDecoderBase',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write('    OpenXrDecoder() { }\n', file=self.outFile)
        write('    virtual ~OpenXrDecoder() override { }\n', file=self.outFile)
        write(
            '    virtual void DecodeFunctionCall(format::ApiCallId             call_id,',
            file=self.outFile
        )
        write(
            '                                    const ApiCallInfo&            call_info,',
            file=self.outFile
        )
        write(
            '                                    const uint8_t*                parameter_buffer,',
            file=self.outFile
        )
        write(
            '                                    size_t                        buffer_size) override;\n',
            file=self.outFile
        )
        write('  private:', end='', file=self.outFile)

    def endFile(self):
        """Method override."""
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.get_filtered_cmd_names():
            if self.is_manually_generated_cmd_name(cmd):
                continue

            cmddef = '' if first else '\n'
            cmddef += '    size_t Decode_{}(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);'.format(
                cmd
            )
            write(cmddef, file=self.outFile)
            first = False
