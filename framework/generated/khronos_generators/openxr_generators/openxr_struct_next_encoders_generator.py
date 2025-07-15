#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2025 LunarG, Inc.
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
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_encode_extended_struct_generator import KhronosEncodeExtendedStructGenerator


class OpenXrStructNextEncodersGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    pNext switch statement generation.
    Options for OpenXr API pNext structure encoding C++ code generation.
    """

    def __init__(
        self,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )
        KhronosEncodeExtendedStructGenerator.update_begin_end_file_data('openxr', self.begin_end_file_data)

class OpenXrStructNextEncodersGenerator(OpenXrBaseGenerator, KhronosEncodeExtendedStructGenerator):
    """OpenXrStructNextEncodersGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ code for OpenXr API pNext structure encoding.
    Generate pNext structure encoding C++ code.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        OpenXrBaseGenerator.beginFile(self, gen_opts)
        KhronosEncodeExtendedStructGenerator.write_encode_struct_definition_prefix(self)

    def endFile(self):
        """Method override."""
        KhronosEncodeExtendedStructGenerator.write_encode_struct_definition_data(self)

        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

