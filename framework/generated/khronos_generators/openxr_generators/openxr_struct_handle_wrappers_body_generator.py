#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019-2025 LunarG, Inc.
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
from khronos_struct_handle_wrappers_body_generator import KhronosStructHandleWrappersBodyGenerator


class OpenXrStructHandleWrappersBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating functions to wrap OpenXr struct member handles at API capture."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
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
            extra_headers=extra_headers
        )

        self.begin_end_file_data.specific_headers.extend((
            'generated/generated_openxr_struct_handle_wrappers.h',
        ))
        self.begin_end_file_data.namespaces.extend((
            'gfxrecon',
            'encode',
            'openxr_wrappers',
        ))
        self.begin_end_file_data.common_api_headers = []

class OpenXrStructHandleWrappersBodyGenerator(OpenXrBaseGenerator, KhronosStructHandleWrappersBodyGenerator):
    """OpenXrStructHandleWrappersBodyGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ functions responsible for wrapping struct member handles
    when recording OpenXr API call parameter data.
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
        KhronosStructHandleWrappersBodyGenerator.write_struct_handle_wrapper_content(self)
        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

    def has_special_case_handle_unwrapping(self, name):
        """Method override."""
        if (name == 'VkGeneratedCommandsMemoryRequirementsInfoEXT'):
            return True
        return False

    def get_special_case_handle_wrapping(self, name):
        """Method override."""
        # Workaround for spec missing const in VkGeneratedCommandsMemoryRequirementsInfoEXT::pNext, should be removed next header update
        if (name == 'VkGeneratedCommandsMemoryRequirementsInfoEXT'):
            return '            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));\n'
        return ''
