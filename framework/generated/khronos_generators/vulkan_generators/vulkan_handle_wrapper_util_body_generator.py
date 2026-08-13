#!/usr/bin/python3 -i
#
# Copyright (c) 2026 LunarG, Inc.
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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write


class VulkanHandleWrapperUtilBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating functions that reach a handle wrapper from an object type."""

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
            '',
            'encode/vulkan_handle_wrappers.h',
            'format/format_util.h',
            'util/logging.h',
        ))
        self.begin_end_file_data.namespaces.extend(
            ('gfxrecon', 'encode', 'vulkan_wrappers')
        )
        self.begin_end_file_data.common_api_headers = []


class VulkanHandleWrapperUtilBodyGenerator(VulkanBaseGenerator):
    """VulkanHandleWrapperUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions responsible for retrieving the wrapped id of a handle
    identified by object type when recording Vulkan API call parameter data.
    Generate C++ functions for Vulkan handle id retrieval by object type at API capture.
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

    def endFile(self):
        """Method override."""
        self.newline()
        write(self.make_get_wrapped_id_body(), file=self.outFile)
        self.newline()
        write(self.make_debug_report_get_wrapped_id_body(), file=self.outFile)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def make_get_wrapped_id_body(self):
        code = 'uint64_t GetWrappedId(uint64_t object, VkObjectType object_type)\n'
        code += '{\n'
        code += '    switch (object_type)\n'
        code += '    {\n'

        for object_type, handle_name, short_name in self.get_object_type_handles():
            code += '        case {}:\n'.format(object_type)
            code += '            return GetWrappedId<{}Wrapper>(format::FromHandleId<{}>(object));\n'.format(
                short_name, handle_name
            )

        code += '        case VK_OBJECT_TYPE_UNKNOWN:\n'
        code += '            // No conversion will be performed for unknown objects.\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown debug marker object type.");\n'
        code += '            return object;\n'
        code += '        default:\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d",\n'
        code += '                                 object_type);\n'
        code += '            return object;\n'
        code += '    }\n'
        code += '}\n'
        return code

    def make_debug_report_get_wrapped_id_body(self):
        code = 'uint64_t GetWrappedId(uint64_t object, VkDebugReportObjectTypeEXT object_type)\n'
        code += '{\n'
        code += '    switch (object_type)\n'
        code += '    {\n'

        for object_type, handle_name, short_name in self.get_object_type_handles():
            report_type = self.get_debug_report_object_type(object_type)
            if report_type is None:
                continue

            code += '        case {}:\n'.format(report_type)
            code += '            return GetWrappedId<{}Wrapper>(format::FromHandleId<{}>(object));\n'.format(
                short_name, handle_name
            )

        code += '        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT:\n'
        code += '            // No conversion will be performed for unknown objects.\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unknown debug marker object type.");\n'
        code += '            return object;\n'
        code += '        default:\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle unwrapping for unrecognized debug marker object type %d",\n'
        code += '                                 object_type);\n'
        code += '            return object;\n'
        code += '    }\n'
        code += '}\n'
        return code
