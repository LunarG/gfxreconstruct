#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2025 LunarG, Inc.
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
from khronos_consumer_header_generator import KhronosConsumerHeaderGenerator


class OpenXrConsumerHeaderGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Adds the following new option:
    is_override - Specify whether the member function declarations are
                  virtual function overrides or pure virtual functions.
    Options for generating C++ class declarations for OpenXr parameter processing.
    """

    def __init__(
        self,
        class_name,
        base_class_header,
        is_override,
        constructor_args='',
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[],
        extra_manual_commands=[],
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers,
            extra_manual_commands=extra_manual_commands,
        )
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.is_override = is_override
        self.constructor_args = constructor_args

        self.begin_end_file_data.specific_headers.extend((
            'decode/{}'.format(self.base_class_header),
            'generated/generated_openxr_struct_decoders.h',
            'util/defines.h',
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))

class OpenXrConsumerHeaderGenerator(OpenXrBaseGenerator, KhronosConsumerHeaderGenerator):
    """OpenXrConsumerHeaderGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ member declarations for the OpenXrConsumer class responsible for processing
    OpenXr API call parameter data.
    Generate C++ class declarations for OpenXr parameter processing.
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


    def endFile(self):
        """Method override."""
        KhronosConsumerHeaderGenerator.output_header_contents(
            self, self.genOpts.class_name, self.genOpts.constructor_args)

        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
