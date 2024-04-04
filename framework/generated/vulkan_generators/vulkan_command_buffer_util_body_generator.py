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
from base_generator import BaseGenerator, BaseGeneratorOptions, ValueInfo, write


class VulkanCommandBufferUtilBodyGeneratorOptions(BaseGeneratorOptions):
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
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanCommandBufferUtilBodyGenerator(BaseGenerator):
    """VulkanCommandBufferUtilBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.pnext_structs = dict(
        )  # Map of Vulkan structure types to sType value for structs that can be part of a pNext chain.
        self.command_info = dict()  # Map of Vulkan commands to parameter info
        # The following functions require custom implementations
        self.customImplementationRequired = {
            'CmdPushDescriptorSetKHR'
        }

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_command_buffer_util.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "encode/vulkan_handle_wrapper_util.h"',
            file=self.outFile
        )
        write('#include "encode/vulkan_state_info.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        wrapper_prefix = self.get_wrapper_prefix_from_type()
        for cmd, info in self.command_info.items():
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
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

            # Track this struct if it can be present in a pNext chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                stype = self.make_structure_type_enum(typeinfo, typename)
                if stype:
                    self.pnext_structs[typename] = stype

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for cmd in self.get_filtered_cmd_names():
            self.command_info[cmd] = self.feature_cmd_params[cmd]

    def get_param_list_handles(self, values):
        """Create list of parameters that have handle types or are structs that contain handles."""
        handles = []
        for value in values:
            if self.is_handle(value.base_type):
                handles.append(value)
            elif self.is_struct(
                value.base_type
            ) and (value.base_type in self.structs_with_handles):
                handles.append(value)
        return handles

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
            wrapper_prefix = self.get_wrapper_prefix_from_type()
            value_name = value_prefix + value.name
            if value.is_array:
                value_name = '{}[{}]'.format(value_name, index_name)
            elif value.is_pointer:
                value_name = '(*{})'.format(value_name)
            body += indent + 'if({} != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::{}].insert(GetVulkanWrappedId<{}>({}));\n'.format(
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
                        body += indent + 'auto pnext_header = reinterpret_cast<const VkBaseInStructure*>({}{}->pNext);\n'.format(
                            value_prefix, value.name
                        )
                        body += indent + 'while (pnext_header)\n'
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'switch (pnext_header->sType)\n'
                        body += indent + '{\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'default:\n'
                        indent += ' ' * self.INDENT_SIZE
                        body += indent + 'break;\n'
                        indent = indent[:-self.INDENT_SIZE]
                        for ext_struct in ext_structs_with_handles:
                            body += indent + 'case {}:\n'.format(
                                self.pnext_structs[ext_struct]
                            )
                            body += indent + '{\n'
                            indent += ' ' * self.INDENT_SIZE
                            body += indent + 'auto pnext_value = reinterpret_cast<const {}*>(pnext_header);\n'.format(
                                ext_struct
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
                        body += indent + 'pnext_header = pnext_header->pNext;\n'
                        indent = indent[:-self.INDENT_SIZE]
                        body += indent + '}\n'
                else:
                    body += self.insert_command_handle(
                        index, entry,
                        value_prefix + value.name + access_operator, indent
                    )

        return body + tail
