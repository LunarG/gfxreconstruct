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


class VulkanStateTrackerDebugUtilBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating the state tracking of debug utils object names and tags."""

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
            'encode/vulkan_state_tracker.h',
            '',
            'encode/vulkan_handle_wrapper_util.h',
            'encode/vulkan_handle_wrappers.h',
            'encode/vulkan_state_writer.h',
            'format/format_util.h',
            'util/logging.h',
        ))
        self.begin_end_file_data.system_headers.append('utility')
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))
        self.begin_end_file_data.common_api_headers = []


class VulkanStateTrackerDebugUtilBodyGenerator(VulkanBaseGenerator):
    """VulkanStateTrackerDebugUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions responsible for storing the debug utils object name and tag
    call parameters on the wrapper for a handle identified by object type, and for writing
    the stored parameters to the initial state.
    Generate C++ functions for Vulkan debug utils object name and tag state at API capture.
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
        write(self.make_assign_debug_to_object_body(), file=self.outFile)
        self.newline()
        write(self.make_write_debug_utils_state_body(), file=self.outFile)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def make_assign_debug_to_object_body(self):
        code = 'void AssignDebugToObject(VkObjectType                        object_type,\n'
        code += '                         uint64_t                            object_handle,\n'
        code += '                         vulkan_state_info::CreateParameters object_name_parameter_buffer,\n'
        code += '                         vulkan_state_info::CreateParameters object_tag_parameter_buffer)\n'
        code += '{\n'
        code += '    switch (object_type)\n'
        code += '    {\n'

        for object_type, handle_name, short_name in self.get_object_type_handles():
            code += '        case {}:\n'.format(object_type)
            code += '        {\n'
            code += '            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::{}Wrapper>(\n'.format(
                short_name
            )
            code += '                format::FromHandleId<{}>(object_handle));\n'.format(handle_name)
            code += '            if (wrapper != nullptr)\n'
            code += '            {\n'
            code += '                if (object_name_parameter_buffer)\n'
            code += '                {\n'
            code += '                    wrapper->debug_name_create_parameters = std::move(object_name_parameter_buffer);\n'
            code += '                }\n'
            code += '\n'
            code += '                if (object_tag_parameter_buffer)\n'
            code += '                {\n'
            code += '                    wrapper->debug_tag_create_parameters = std::move(object_tag_parameter_buffer);\n'
            code += '                }\n'
            code += '            }\n'
            code += '            break;\n'
            code += '        }\n'

        code += '        case VK_OBJECT_TYPE_UNKNOWN:\n'
        code += '        default:\n'
        code += '            break;\n'
        code += '    }\n'
        code += '}\n'
        return code

    def make_write_debug_utils_state_body(self):
        code = 'void VulkanStateWriter::WriteDebugUtilsState(const VulkanStateTable& state_table)\n'
        code += '{\n'
        code += '    auto write_debug_utils_calls = [&](const auto* wrapper) {\n'
        code += '        GFXRECON_ASSERT(wrapper != nullptr);\n'
        code += '        if (wrapper->debug_name_create_parameters)\n'
        code += '        {\n'
        code += '            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectNameEXT,\n'
        code += '                              wrapper->debug_name_create_parameters.get());\n'
        code += '        }\n'
        code += '\n'
        code += '        if (wrapper->debug_tag_create_parameters)\n'
        code += '        {\n'
        code += '            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectTagEXT,\n'
        code += '                              wrapper->debug_tag_create_parameters.get());\n'
        code += '        }\n'
        code += '    };\n'
        code += '\n'
        code += '    // clang-format off\n'

        # The state writer omits the creation call for these object types when a handle the object was created
        # from has been destroyed. Such objects do not exist at replay, so the debug utils calls that reference
        # them must be omitted as well.
        validity_checks = {
            'BufferView': 'IsBufferViewValid',
            'ImageView': 'IsImageViewValid',
            'Framebuffer': 'IsFramebufferValid',
        }

        for _, _, short_name in self.get_object_type_handles():
            validity_check = validity_checks.get(short_name)
            if validity_check is None:
                visit_body = 'write_debug_utils_calls(wrapper);'
            else:
                visit_body = 'if ({}(wrapper->handle_id, state_table)) {{ write_debug_utils_calls(wrapper); }}'.format(
                    validity_check
                )

            code += '    state_table.VisitWrappers([&](const vulkan_wrappers::{}Wrapper* wrapper) {{ {} }});\n'.format(
                short_name, visit_body
            )

        code += '    // clang-format on\n'
        code += '}\n'
        return code
