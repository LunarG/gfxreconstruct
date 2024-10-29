#!/usr/bin/python3 -i
#
# Copyright (c) 2020 LunarG, Inc.
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


class VulkanReferencedResourceBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for detecting unreferenced resource handles in a capture file."""

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


class VulkanReferencedResourceBodyGenerator(BaseGenerator):
    """VulkanReferencedResourceBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReferencedResource class responsible for
    determining which resource handles are used or unused in a capture file.
    Generate a C++ class for detecting unreferenced resource handles in a capture file.
    """

    # All resource and resource associated handle types to be processed.
    RESOURCE_HANDLE_TYPES = [
        'VkBuffer', 'VkImage', 'VkBufferView', 'VkImageView', 'VkFramebuffer',
        'VkDescriptorSet', 'VkCommandBuffer', 'VkAccelerationStructureKHR'
    ]

    # Handle types that contain resource and child resource handle types.
    CONTAINER_HANDLE_TYPES = ['VkDescriptorSet']

    # Handle types that use resource and child resource handle types.
    USER_HANDLE_TYPES = ['VkCommandBuffer']

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
        self.restrict_handles = True  # Determines if the 'is_handle' override limits the handle test to only the values conained by RESOURCE_HANDLE_TYPES.

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_referenced_resource_consumer.h"',
            file=self.outFile
        )
        self.newline()
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        for cmd, info in self.command_info.items():
            return_type = info[0]
            params = info[2]
            if params and params[0].base_type == 'VkCommandBuffer':
                # Check for parameters with resource handle types.
                handles = self.get_param_list_handles(params[1:])

                if (handles):
                    # Generate a function to add handles to the command buffer's referenced handle list.
                    cmddef = '\n'

                    # Temporarily remove resource only matching restriction from is_handle() when generating the function signature.
                    self.restrict_handles = False
                    cmddef += self.make_consumer_func_decl(
                        return_type,
                        'VulkanReferencedResourceConsumer::Process_' + cmd,
                        params
                    ) + '\n'
                    self.restrict_handles = True

                    cmddef += '{\n'
                    indent = self.INDENT_SIZE * ' '

                    # Add unreferenced parameter macros.
                    unref_count = 0
                    for param in params[1:]:
                        if param not in handles:
                            cmddef += indent + 'GFXRECON_UNREFERENCED_PARAMETER({});\n'.format(
                                param.name
                            )
                            unref_count += 1
                    if unref_count > 0:
                        cmddef += '\n'

                    for index, handle in enumerate(handles):
                        cmddef += self.track_command_handle(
                            index, params[0].name, handle, indent=indent
                        )
                    cmddef += '}'

                    write(cmddef, file=self.outFile)

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
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

    def is_handle(self, base_type):
        """Override method to check for handle type, only matching resource handle types."""
        if self.restrict_handles:
            if base_type in self.RESOURCE_HANDLE_TYPES:
                return True
            return False
        else:
            return BaseGenerator.is_handle(self, base_type)

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

    def track_command_handle(
        self, index, command_param_name, value, value_prefix='', indent=''
    ):
        body = ''
        tail = ''
        index_name = None
        count_name = None
        value_name = value_prefix + value.name
        is_handle = self.is_handle(value.base_type)

        if (
            value.is_pointer or value.is_array
        ) and value.name != 'ext_struct_info':
            if index > 0:
                body += '\n'

            access_operator = '->'
            if not value_prefix:
                # If there is no prefix, this is the pointer parameter received by the function, which should never be null.
                body += indent + 'assert({} != nullptr);\n'.format(value.name)
                body += '\n'
                # Add IsNull and HasData checks for the pointer decoder, before accessing its data.
                # Note that this does not handle the decoded struct member cases for static arrays, which would need to use '.' instead of '->'.
                body += indent + 'if (!{prefix}{name}{op}IsNull() && ({prefix}{name}{op}HasData()))\n'.format(
                    prefix=value_prefix, name=value.name, op=access_operator
                )
                body += indent + '{\n'
                tail = indent + '}\n' + tail
                indent += ' ' * self.INDENT_SIZE
            else:
                # If there is a prefix, this is a struct member.  We need to determine the type of access operator to use
                # for the member of a 'decoded' struct type, where handle member types will be HandlePointerDecoder, but
                # struct member types will be unique_ptr<StructPointerDecoder>.
                if is_handle:
                    access_operator = '.'

                body += indent + 'if (!{prefix}{name}{op}IsNull() && ({prefix}{name}{op}HasData()))\n'.format(
                    prefix=value_prefix, name=value.name, op=access_operator
                )

                body += indent + '{\n'
                tail = indent + '}\n' + tail
                indent += ' ' * self.INDENT_SIZE

            # Get the pointer from the pointer decoder object.
            value_name = '{}_ptr'.format(value.name)
            if is_handle:
                body += indent + 'auto {} = {}{}{}GetPointer();\n'.format(
                    value_name, value_prefix, value.name, access_operator
                )
            else:
                body += indent + 'auto {} = {}{}{}GetMetaStructPointer();\n'.format(
                    value_name, value_prefix, value.name, access_operator
                )

            # Add a for loop for an array of values.
            if value.is_array:
                index_name = '{}_index'.format(value.name)
                count_name = '{}_count'.format(value.name)
                body += indent + 'size_t {} = {}{}{}GetLength();\n'.format(
                    count_name, value_prefix, value.name, access_operator
                )
                body += indent + 'for (size_t {i} = 0; {i} < {}; ++{i})\n'.format(
                    count_name, i=index_name
                )

                body += indent + '{\n'
                tail = indent + '}\n' + tail
                indent += ' ' * self.INDENT_SIZE

        # Insert commands to add handles to a container, or to process struct members that contain handles.
        if is_handle:
            if value.is_array:
                value_name = '{}[{}]'.format(value_name, index_name)
            elif value.is_pointer:
                value_name = '(*{})'.format(value_name)

            if value.base_type in self.CONTAINER_HANDLE_TYPES:
                body += indent + 'GetTable().AddContainerToUser({}, {});\n'.format(
                    command_param_name, value_name
                )
            elif value.base_type in self.USER_HANDLE_TYPES:
                body += indent + 'GetTable().AddUserToUser({}, {});\n'.format(
                    command_param_name, value_name
                )
            else:
                body += indent + 'GetTable().AddResourceToUser({}, {});\n'.format(
                    command_param_name, value_name
                )

        elif self.is_struct(
            value.base_type
        ) and (value.base_type in self.structs_with_handles):
            if value.is_array:
                access_operator = '[{}].'.format(index_name)
            else:
                access_operator = '->'

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
                        for ext_struct in ext_structs_with_handles:
                            body += indent + '{\n'
                            indent += ' ' * self.INDENT_SIZE
                            body += indent + 'const auto* ext_struct_info = GetPNextMetaStruct<Decoded_{}>({}->pNext);\n'.format(
                                 ext_struct, value_name
                             )

                            body += indent + 'if (ext_struct_info != nullptr)\n'
                            body += indent + '{\n'
                            indent += ' ' * self.INDENT_SIZE
                            body += self.track_command_handle(
                                index,
                                command_param_name,
                                ValueInfo(
                                    'ext_struct_info', ext_struct,
                                    'const {} *'.format(ext_struct), 1
                                ),
                                '',
                                indent=indent
                            )
                            indent = indent[:-self.INDENT_SIZE]
                            body += indent + '}\n'

                            indent = indent[:-self.INDENT_SIZE]
                            body += indent + '}\n'
                else:
                    body += self.track_command_handle(
                        index, command_param_name, entry,
                        value_name + access_operator, indent
                    )

        return body + tail
