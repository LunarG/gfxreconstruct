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
from khronos_dispatch_table_generator import KhronosDispatchTableGenerator

openxr_load_function="""template <typename GetProcAddr, typename Handle, typename FuncP>
static void LoadOpenXrFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)
{
    XrResult result = gpa(handle, name, reinterpret_cast<PFN_xrVoidFunction*>(funcp));
    if (result != XR_SUCCESS)
    {
        (*funcp) = nullptr;
    }
}"""

class OpenXrDispatchTableGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating a dispatch table for OpenXr API calls."""

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
            'util/defines.h',
            'util/logging.h',
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))

class OpenXrDispatchTableGenerator(OpenXrBaseGenerator, KhronosDispatchTableGenerator):
    """OpenXrDispatchTableGenerator - subclass of OpenXrBaseGenerator.
    Generates a dispatch table for OpenXr API calls.
    Generate dispatch table for OpenXr API calls.
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
        # Map of return types to default return values for no-op functions
        self.RETURN_DEFAULTS = {
            'XrResult': 'XR_SUCCESS',
            'XrBool32': 'XR_TRUE',
            'PFN_xrVoidFunction': 'nullptr',
            'uint32_t': '0',
            'uint64_t': '0'
        }

        self.instance_cmd_names = dict(
        )  # Map of API call names to no-op function declarations
        self.device_cmd_names = dict(
        )  # Map of API call names to no-op function declarations


    def is_instance_command(self, api_data, command, first_value):
        """ Method override """
        return self.is_handle(first_value.base_type)

    def write_layer_table_manual_entries(self):
        """ Method must overridden. """
        write(
            '    PFN_xrCreateApiLayerInstance CreateApiLayerInstance{ nullptr };',
            file=self.outFile
        )

    def create_load_function(self, api_data):
        return openxr_load_function

    def endFile(self):
        """Method override."""
        KhronosDispatchTableGenerator.generateDispatchTable(self, gen_dispatch_key=False)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
