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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, ValueInfo, write


class VulkanCommandBufferUtilBodyGeneratorOptions(VulkanBaseGeneratorOptions):
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
            'generated/generated_vulkan_command_buffer_util.h',
            '',
            'encode/vulkan_handle_wrapper_util.h',
            'encode/vulkan_state_info.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'encode'))
        self.begin_end_file_data.common_api_headers = []


class VulkanCommandBufferUtilBodyGenerator(VulkanBaseGenerator):
    """VulkanCommandBufferUtilBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
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

        # The following functions require custom implementations
        self.customImplementationRequired = {
            'CmdPushDescriptorSetKHR'
        }


    def endFile(self):
        """Method override."""
        command_info = dict()  # Map of Vulkan commands to parameter info
        for cmd in self.get_all_filtered_cmd_names():
            command_info[cmd] = self.all_cmd_params[cmd]

        for cmd, info in command_info.items():
            wrapper_prefix = self.get_wrapper_prefix_from_command(cmd)
            if not cmd[2:] in self.customImplementationRequired:
                params = info[2]
                if params and params[0].base_type == 'VkCommandBuffer':
                    # Check for parameters with handle types, ignoring the first VkCommandBuffer parameter.
                    handles = self.get_param_list_handles(params[1:])

                    if (handles):
                        # Generate a function to build a list of handle types and values.
                        cmddef = '\n'
                        cmddef += 'void Track{}Handles({}::CommandBufferWrapper* wrapper, {})\n'.format(
                            cmd[2:], wrapper_prefix, self.get_arg_list(handles)
                        )
                        cmddef += '{\n'
                        indent = self.INDENT_SIZE * ' '
                        cmddef += indent + 'assert(wrapper != nullptr);\n'
                        cmddef += '\n'
                        for index, handle in enumerate(handles):
                            cmddef += self.insert_command_handle(
                                index, handle, indent=indent
                            )
                        cmddef += '}'

                        write(cmddef, file=self.outFile)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def get_arg_list(self, values):
        args = []
        for value in values:
            if value.array_length:
                args.append('uint32_t {}'.format(value.array_length))
            args.append('{} {}'.format(value.full_type, value.name))
        return ', '.join(self.make_unique_list(args))

    def insert_command_handle(self, index, value, value_prefix='', indent=''):
        body = ''
        tail = ''
        index_name = None
        if (
            value.is_pointer or value.is_array
        ) and value.name != 'pnext_value':
            if index > 0:
                body += '\n'
            body += indent + 'if ({}{} != nullptr)\n'.format(
                value_prefix, value.name
            )
            body += indent + '{\n'
            tail = indent + '}\n' + tail
            indent += ' ' * self.INDENT_SIZE

            if value.is_array:
                index_name = '{}_index'.format(value.name)
                body += indent + 'for (uint32_t {i} = 0; {i} < {}{}; ++{i})\n'.format(
                    value_prefix, value.array_length, i=index_name
                )
                body += indent + '{\n'
                tail = indent + '}\n' + tail
                indent += ' ' * self.INDENT_SIZE

        if self.is_handle(value.base_type):
            type_enum_value = '{}Handle'.format(value.base_type[2:])
            wrapper_prefix = self.get_wrapper_prefix_from_type(value.base_type)
            value_name = value_prefix + value.name
            if value.is_array:
                value_name = '{}[{}]'.format(value_name, index_name)
            elif value.is_pointer:
                value_name = '(*{})'.format(value_name)
            body += indent + 'if({} != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::{}].insert(vulkan_wrappers::GetWrappedId<{}>({}));\n'.format(
                value_name, type_enum_value, wrapper_prefix + '::' + value.base_type[2:] + 'Wrapper' ,value_name
            )

        elif self.is_struct(
            value.base_type
        ) and (value.base_type in self.structs_with_handles):
            if value.is_array:
                access_operator = '[{}].'.format(index_name)
            elif value.is_pointer:
                access_operator = '->'
            else:
                access_operator = '.'

            for index, entry in enumerate(
                self.structs_with_handles[value.base_type]
            ):
                if entry.name == 'pNext':
                    ext_structs_with_handles = [
                        ext_struct for ext_struct in
                        self.registry.validextensionstructs[value.base_type]
                        if ext_struct in self.structs_with_handles
                    ]
                    if ext_structs_with_handles:
                        body += indent + 'auto pnext_header_{} = reinterpret_cast<const VkBaseInStructure*>({}{}->pNext);\n'.format(
                            value.name, value_prefix, value.name
                        )
                        body += indent + 'while (pnext_header_{})\n'.format(value.name)
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'switch (pnext_header_{}->sType)\n'.format(value.name)
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'default:\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'break;\n'
                        indent = indent[:-self.INDENT_SIZE]
                        for ext_struct in ext_structs_with_handles:
                            body += indent + 'case {}:\n'.format(
                                self.struct_type_names[ext_struct]
                            )
                            body += indent + '{\n'
                            indent += ' ' * self.INDENT_SIZE
                            body += indent + 'auto pnext_value = reinterpret_cast<const {}*>(pnext_header_{});\n'.format(
                                ext_struct, value.name
                            )
                            body += self.insert_command_handle(
                                index,
                                ValueInfo(
                                    'pnext_value', ext_struct,
                                    'const {} *'.format(ext_struct), 1
                                ),
                                '',
                                indent=indent
                            )
                            body += indent + 'break;\n'
                            indent = indent[:-self.INDENT_SIZE]
                            body += indent + '}\n'
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                        body += indent + 'pnext_header_{0} = pnext_header_{0}->pNext;\n'.format(value.name)
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                else:
                    body += self.insert_command_handle(
                        index, entry,
                        value_prefix + value.name + access_operator, indent
                    )

        return body + tail
