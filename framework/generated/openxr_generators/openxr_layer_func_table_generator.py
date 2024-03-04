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


class OpenXrLayerFuncTableGeneratorOptions(BaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    function table generation.
    Options for OpenXR layer function table C++ code generation.
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


class OpenXrLayerFuncTableGenerator(BaseGenerator):
    """LayerFuncTableGenerator - subclass of BaseGenerator.
    Generates C++ function table for the OpenXR API calls exported by the layer.
    Generate OpenXr layer function table C++ type declarations.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # API Calls that the trace layer should ignore
        self.APICALL_BLACKLIST = []

        # These functions are provided directly by the layer, and are not encoded
        self.LAYER_FUNCTIONS = []

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "encode/custom_openxr_api_call_encoders.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_openxr_api_call_encoders.h"',
            file=self.outFile
        )
        write('#include "layer/trace_layer.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('#include <unordered_map>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write(
            'const std::unordered_map<std::string, PFN_xrVoidFunction> openxr_func_table = {',
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        write('};', file=self.outFile)
        self.newline()
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
        for cmd in self.get_filtered_cmd_names():
            align = 100 - len(cmd)
            if (cmd in self.LAYER_FUNCTIONS):
                body = '    {{ "{}",{}reinterpret_cast<PFN_xrVoidFunction>({}) }},'.format(
                    cmd, (' ' * align), cmd[2:]
                )
            else:
                body = '    {{ "{}",{}reinterpret_cast<PFN_xrVoidFunction>(encode::{}) }},'.format(
                    cmd, (' ' * align), cmd[2:]
                )
            write(body, file=self.outFile)
