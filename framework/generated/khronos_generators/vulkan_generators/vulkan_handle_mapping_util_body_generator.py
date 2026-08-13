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


class VulkanHandleMappingUtilBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating functions that map a captured handle from an object type."""

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
            'decode/vulkan_handle_mapping_util.h',
            '',
            'decode/vulkan_object_info.h',
            'format/format_util.h',
            'util/logging.h',
        ))
        self.begin_end_file_data.namespaces.extend(
            ('gfxrecon', 'decode', 'handle_mapping')
        )
        self.begin_end_file_data.common_api_headers = []


class VulkanHandleMappingUtilBodyGenerator(VulkanBaseGenerator):
    """VulkanHandleMappingUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions responsible for mapping a captured handle
    identified by object type when replaying Vulkan API calls.
    Generate C++ functions for Vulkan handle mapping by object type at API replay.
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
        write(self.make_map_handle_body(), file=self.outFile)
        self.newline()
        write(self.make_debug_report_map_handle_body(), file=self.outFile)

        VulkanBaseGenerator.endFile(self)

    def make_map_case(self, object_type_case, handle_name, short_name):
        api_data = self.get_api_data()
        info_type = '{}{}Info'.format(api_data.api_class_prefix, short_name)

        code = '        case {}:\n'.format(object_type_case)
        code += '            return format::ToHandleId(MapHandle<{}>(\n'.format(info_type)
        code += '                object, object_info_table, &CommonObjectInfoTable::Get{}Info));\n'.format(
            handle_name
        )
        return code

    def make_map_handle_body(self):
        code = 'uint64_t MapHandle(uint64_t object, VkObjectType object_type, const CommonObjectInfoTable& object_info_table)\n'
        code += '{\n'
        code += '    switch (object_type)\n'
        code += '    {\n'

        for object_type, handle_name, short_name in self.get_object_type_handles():
            code += self.make_map_case(object_type, handle_name, short_name)

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

    def make_debug_report_map_handle_body(self):
        code = 'uint64_t\n'
        code += 'MapHandle(uint64_t object, VkDebugReportObjectTypeEXT object_type, const CommonObjectInfoTable& object_info_table)\n'
        code += '{\n'
        code += '    switch (object_type)\n'
        code += '    {\n'

        for object_type, handle_name, short_name in self.get_object_type_handles():
            report_type = self.get_debug_report_object_type(object_type)
            if report_type is None:
                continue

            code += self.make_map_case(report_type, handle_name, short_name)

        code += '        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT:\n'
        code += '            // No conversion will be performed for unknown objects.\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle mapping for unknown debug marker object type.");\n'
        code += '            return object;\n'
        code += '        default:\n'
        code += '            GFXRECON_LOG_WARNING("Skipping handle mapping for unrecognized debug marker object type %d", object_type);\n'
        code += '            return object;\n'
        code += '    }\n'
        code += '}\n'
        return code
