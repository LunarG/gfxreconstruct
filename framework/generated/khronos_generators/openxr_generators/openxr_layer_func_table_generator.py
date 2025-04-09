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
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions
from khronos_layer_func_table_generator import KhronosLayerFuncTableGenerator

class OpenXrLayerFuncTableGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    function table generation .
    Options for OpenXR layer function table C++ code generation.
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
        self.begin_end_file_data.specific_headers.extend((
            'encode/custom_openxr_api_call_encoders.h',
            'generated/generated_openxr_api_call_encoders.h',
            'layer/layer_vulkan_entry.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.system_headers.append('unordered_map')
        self.begin_end_file_data.namespaces.append('gfxrecon')

class OpenXrLayerFuncTableGenerator(OpenXrBaseGenerator, KhronosLayerFuncTableGenerator):
    """LayerFuncTableGenerator - subclass of BaseGenerator.
    Generates C++ function table for the OpenXR API calls exported by the layer.
    Generate OpenXr layer function table C++ type declarations.
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

        # API Calls that the trace layer should ignore
        self.APICALL_BLACKLIST += [
            'xrNegotiateLoaderRuntimeInterface',
            'xrNegotiateLoaderApiLayerInterface',
            'xrInitializeLoaderKHR',
            'xrCreateInstance',
            'xrCreateApiLayerInstance',
        ]

        # These functions are provided directly by the layer, and are not encoded
        self.LAYER_FUNCTIONS = [
            'xrEnumerateInstanceExtensionProperties',
            'xrEnumerateApiLayerProperties',
            'xrCreateApiLayerInstance',
            'xrGetInstanceProcAddr',
        ]

    def endFile(self):
        """Method override."""

        KhronosLayerFuncTableGenerator.write_layer_func_table_contents(self, self.LAYER_FUNCTIONS, 100, 'layer')
        self.newline()

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
