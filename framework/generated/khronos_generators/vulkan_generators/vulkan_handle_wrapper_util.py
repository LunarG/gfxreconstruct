#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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
from common import makePrefixObjectType
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

class VulkanHandleWrapperUtilOptions(VulkanBaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

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
        VulkanBaseGeneratorOptions.__init__(
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
            'encode/vulkan_handle_wrapper_util.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode', 'vulkan_wrappers'))
        self.begin_end_file_data.common_api_headers = []

class VulkanHandleWrapperUtil(VulkanBaseGenerator):
    """
    Utilities for retrieving the ID associated with a handle.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def gen_get_wrapped_id(self, prefix, prefix_type, suffix='', debug_report=False):
        ind = self.INDENT_SIZE * " "
        enums = self.enumEnumerants[prefix_type]
        self.write_lines([f'uint64_t GetWrappedId(uint64_t object, {prefix_type} object_type) {{'])
        self.write_lines([f'{ind}switch (object_type) {{'])
        for h_prefix in sorted(self.handle_names):
            if h_prefix in self.handle_aliases.keys():
                # Including aliases in a switch statement will not compile
                continue
            h = h_prefix[2:]  # Remove 'Vk' prefix
            object_type = makePrefixObjectType(h_prefix, prefix) + suffix
            if not debug_report:
                if object_type not in enums.keys():
                    raise ValueError(f'{object_type} was not found as an enumerant in {prefix_type}')
            else:
                if debug_report and object_type not in enums.keys():
                    # Bit of a hack to ensure we only output valid VK_DEBUG_REPORT_OBJECT_TYPE_* enums
                    continue

            self.write_lines([f'{2 * ind}case {object_type}:'])
            self.write_lines([f'{3 * ind}return GetWrappedId<{h}Wrapper>(format::FromHandleId<{h_prefix}>(object));'])

        self.write_lines([f'{2 * ind}{prefix}UNKNOWN:'])
        self.write_lines([f'{3 * ind}GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d", object_type);'])
        self.write_lines([f'{3 * ind}return object;'])

        self.write_lines([f'{2 * ind}default:'])
        self.write_lines([f'{3 * ind}GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d", object_type);'])
        self.write_lines([f'{3 * ind}return object;'])

        self.write_lines([ind + '}']) # End switch block

        self.write_lines(['}']) # End function block

        self.newline()

    def endFile(self):
        self.write_lines(['VulkanStateHandleTable state_handle_table_;'])
        self.gen_get_wrapped_id('VK_OBJECT_TYPE_', 'VkObjectType')
        self.gen_get_wrapped_id('VK_DEBUG_REPORT_OBJECT_TYPE_', 'VkDebugReportObjectTypeEXT', '_EXT', True)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)