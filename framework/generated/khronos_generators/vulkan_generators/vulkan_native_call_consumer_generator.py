#!/usr/bin/python3 -i
#
# Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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


class VulkanNativeCallConsumerGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options shared by the native-call consumer header and body generators."""

    def __init__(
        self,
        header,
        blacklists=None,
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        permission_line = '** Permission is hereby granted, free of charge, to any person obtaining a'
        if permission_line in prefix_text:
            permission_index = prefix_text.index(permission_line)
            prefix_text = [
                '/*',
                '** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>',
                '**',
            ] + prefix_text[permission_index:]
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
        self.header = header
        if header:
            self.begin_end_file_data.specific_headers.extend((
                'decode/vulkan_native_call_consumer_base.h',
                'util/defines.h',
            ))
        else:
            self.begin_end_file_data.specific_headers.extend((
                'generated/generated_vulkan_native_call_consumer.h',
                '',
                'format/format_util.h',
            ))
            self.begin_end_file_data.system_headers.append('cstring')
            self.begin_end_file_data.common_api_headers = []
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))


class VulkanNativeCallConsumerGenerator(VulkanBaseGenerator):
    """Generate a consumer that invokes registered functions with native Vulkan parameters."""

    CUSTOM_COMMANDS = (
        'vkUpdateDescriptorSetWithTemplate',
        'vkUpdateDescriptorSetWithTemplateKHR',
        'vkCreateRayTracingPipelinesKHR',
    )

    # These commands are not currently part of the native export interface.
    NATIVE_COMMAND_BLACKLIST = (
        'vkCmdBeginGpaSampleAMD',
        'vkCmdBeginGpaSessionAMD',
        'vkCmdCopyGpaSessionResultsAMD',
        'vkCmdEndGpaSampleAMD',
        'vkCmdEndGpaSessionAMD',
        'vkCreateGpaSessionAMD',
        'vkDestroyGpaSessionAMD',
        'vkGetGpaDeviceClockInfoAMD',
        'vkGetGpaSessionResultsAMD',
        'vkGetGpaSessionStatusAMD',
        'vkResetGpaSessionAMD',
        'vkSetGpaDeviceClockModeAMD',
    )

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        self.all_commands = {}
        self.generated_commands = {}

    def beginFile(self, gen_opts):
        VulkanBaseGenerator.beginFile(self, gen_opts)
        if self.genOpts.header:
            write(
                'class VulkanNativeCallConsumer : public VulkanNativeCallConsumerBase',
                file=self.outFile
            )
            write('{', file=self.outFile)
            write('  public:', file=self.outFile)
            write(
                '    explicit VulkanNativeCallConsumer(VulkanNativeCallCallbacks& callbacks) :\n'
                '        VulkanNativeCallConsumerBase(callbacks)\n'
                '    {}',
                file=self.outFile
            )
            write('    ~VulkanNativeCallConsumer() override = default;', file=self.outFile)

    def need_feature_generation(self):
        return True

    def generate_feature(self):
        for command in self.feature_cmd_params:
            self.record_command(self.all_commands, command)

        for command in self.CUSTOM_COMMANDS:
            if command in self.feature_cmd_params:
                self.record_command(self.generated_commands, command)
                if self.genOpts.header:
                    if command == 'vkCreateRayTracingPipelinesKHR':
                        declaration = self.make_create_ray_tracing_pipelines_khr_decl(command)
                    else:
                        declaration = self.make_descriptor_update_template_decl(command)
                    write(
                        '\n' + self.indent(
                            declaration + ' override;',
                            self.INDENT_SIZE
                        ),
                        file=self.outFile
                    )
                else:
                    if command == 'vkCreateRayTracingPipelinesKHR':
                        write(self.make_create_ray_tracing_pipelines_khr_body(command), file=self.outFile)
                    else:
                        write(self.make_descriptor_update_template_body(command), file=self.outFile)

        commands = [
            command for command in self.get_filtered_cmd_names()
            if command not in self.NATIVE_COMMAND_BLACKLIST
        ]
        commands.sort()
        for command in commands:
            if self.is_manually_generated_cmd_name(command):
                continue
            self.record_command(self.generated_commands, command)
            return_type, _, values = self.feature_cmd_params[command]
            if self.genOpts.header:
                declaration = self.make_consumer_func_decl(
                    return_type, 'Process_' + command, values
                )
                write(
                    '\n' + self.indent(declaration + ' override;', self.INDENT_SIZE),
                    file=self.outFile
                )
            else:
                write(
                    self.make_command_body(command, return_type, values),
                    file=self.outFile
                )

    def endFile(self):
        self.handle_names.discard('VkGpaSessionAMD')
        if self.genOpts.header:
            self.generate_handle_declarations()
            self.generate_command_info_declarations()
        else:
            self.generate_handle_definitions()
            self.generate_command_info_definitions()

        self.newline()
        VulkanBaseGenerator.endFile(self)

    def generate_handle_declarations(self):
        write('\n  private:', file=self.outFile)
        for handle in sorted(self.handle_names):
            write(
                '    {} Materialize{}(format::HandleId id);'.format(handle, handle),
                file=self.outFile
            )
        write('};', file=self.outFile)

    def record_command(self, command_map, command):
        protect = self.featureExtraProtect
        if command not in command_map or command_map[command] is not None:
            command_map[command] = protect

    def generate_command_info_declarations(self):
        write(
            '\nconst VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(const char* name);',
            file=self.outFile
        )
        write(
            '\nconst VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(uint32_t call_id);',
            file=self.outFile
        )
        write('\nconst char* GetVulkanApiCallName(uint32_t call_id);', file=self.outFile)

    def make_native_arg(self, command, index, value):
        name = value.name
        arg = 'args.{}'.format(name)
        if self.is_handle_like(value.base_type):
            if value.is_pointer or value.is_array:
                expression = (
                    'MaterializeHandlePointer({0}, [this](format::HandleId id) '
                    '{{ return Materialize{1}(id); }})'
                ).format('&' + arg, value.base_type)
            else:
                expression = 'Materialize{}({})'.format(value.base_type, arg)
        elif self.is_struct(value.base_type):
            if value.is_pointer or value.is_array:
                if (
                    value.base_type not in ('VkBaseInStructure', 'VkBaseOutStructure')
                    and (
                        self.child_struct_has_handles(value.base_type)
                        or self.struct_might_have_handles(value.base_type)
                    )
                ):
                    expression = 'MaterializeStructPointer({})'.format('&' + arg)
                else:
                    expression = 'GetStructPointer({})'.format('&' + arg)
            else:
                expression = '{}.decoded_value'.format(arg)
        elif value.base_type == 'void' and value.pointer_count > 1:
            expression = 'MaterializeVoidPointer({})'.format('&' + arg)
        elif value.base_type == 'void' and value.pointer_count == 1 and not value.is_array:
            expression = 'MaterializeCallbackArgument<PFN_{}, {}>({})'.format(
                command, index, '&' + arg
            )
        elif self.is_function_ptr(value.base_type) or value.platform_full_type:
            expression = 'MaterializeCallbackArgument<PFN_{}, {}>({})'.format(
                command, index, arg
            )
        elif value.is_pointer or value.is_array:
            expression = '{}.GetPointer()'.format(arg)
        else:
            expression = arg

        return 'native_' + name, expression

    def make_command_body(self, command, return_type, values):
        declaration = self.make_consumer_func_decl(
            return_type, 'VulkanNativeCallConsumer::Process_' + command, values
        )
        lines = ['\n' + declaration, '{']
        native_args = []
        for index, value in enumerate(values):
            native_name, expression = self.make_native_arg(command, index, value)
            lines.append('    auto {} = {};'.format(native_name, expression))
            native_args.append(native_name)

        if return_type == 'void':
            return_pointer = 'nullptr'
            return_size = '0'
        else:
            return_pointer = '&args.result'
            return_size = 'sizeof(args.result)'

        lines.extend((
            '    const auto context = MakeCallContext(call_info,',
            '                                         format::ApiCallId::ApiCall_{},'.format(command),
            '                                         "{}",'.format(command),
            '                                         {},'.format(return_pointer),
            '                                         {});'.format(return_size),
        ))

        if command in (
            'vkCreateDescriptorUpdateTemplate',
            'vkCreateDescriptorUpdateTemplateKHR'
        ):
            lines.append(
                '    TrackDescriptorUpdateTemplate(args.result, &args.pCreateInfo, &args.pDescriptorUpdateTemplate);'
            )

        if command == 'vkMapMemory':
            lines.append('    TrackMappedMemory(args.result, native_memory, native_offset);')
        elif command in ('vkMapMemory2', 'vkMapMemory2KHR'):
            lines.extend((
                '    if (native_pMemoryMapInfo != nullptr)',
                '    {',
                '        TrackMappedMemory(args.result, native_pMemoryMapInfo->memory, native_pMemoryMapInfo->offset);',
                '    }',
            ))
        elif command == 'vkUnmapMemory':
            lines.append('    TrackUnmappedMemory(native_memory);')
        elif command in ('vkUnmapMemory2', 'vkUnmapMemory2KHR'):
            lines.extend((
                '    if (native_pMemoryUnmapInfo != nullptr)',
                '    {',
                '        TrackUnmappedMemory(args.result, native_pMemoryUnmapInfo->memory);',
                '    }',
            ))

        lines.extend((
            '    auto registered_native_function =',
            '        reinterpret_cast<PFN_{}>(callbacks_.Resolve(context));'.format(command),
            '    if (registered_native_function == nullptr)',
            '    {',
            '        return;',
            '    }',
            '',
            '    callbacks_.PreCall(context);',
            '    (void)registered_native_function({});'.format(', '.join(native_args)),
            '    callbacks_.PostCall(context);',
            '}',
        ))
        return '\n'.join(lines)

    def make_descriptor_update_template_decl(self, command):
        return (
            'void Process_{0}(\n'
            '    const ApiCallInfo&               call_info,\n'
            '    args::{1}& args)'
        ).format(command, self.make_args_struct_name(command))

    def make_create_ray_tracing_pipelines_khr_decl(self, command):
        return (
            'void Process_{0}(\n'
            '    const ApiCallInfo&                  call_info,\n'
            '    args::{1}& args)'
        ).format(command, self.make_args_struct_name(command))

    def make_create_ray_tracing_pipelines_khr_body(self, command):
        declaration = self.make_create_ray_tracing_pipelines_khr_decl(command).replace(
            'Process_', 'VulkanNativeCallConsumer::Process_', 1
        )
        return '\n'.join((
            '\n' + declaration,
            '{',
            '    const auto context = MakeCallContext(call_info,',
            '                                         format::ApiCallId::ApiCall_{0},'.format(command),
            '                                         "{0}",'.format(command),
            '                                         &args.result,',
            '                                         sizeof(args.result));',
            '    if (args.deferredOperation != format::kNullHandleId)',
            '    {',
            '        callbacks_.UnsupportedCall(context);',
            '        return;',
            '    }',
            '',
            '    auto registered_native_function =',
            '        reinterpret_cast<PFN_{0}>(callbacks_.Resolve(context));'.format(command),
            '    if (registered_native_function == nullptr)',
            '    {',
            '        return;',
            '    }',
            '',
            '    auto native_device = MaterializeVkDevice(args.device);',
            '    auto native_pipelineCache = MaterializeVkPipelineCache(args.pipelineCache);',
            '    auto native_pCreateInfos = MaterializeStructPointer(&args.pCreateInfos);',
            '    auto native_pAllocator = GetStructPointer(&args.pAllocator);',
            '    auto native_pPipelines = MaterializeHandlePointer(',
            '        &args.pPipelines, [this](format::HandleId id) { return MaterializeVkPipeline(id); });',
            '',
            '    callbacks_.PreCall(context);',
            '    (void)registered_native_function(native_device,',
            '                                     VK_NULL_HANDLE,',
            '                                     native_pipelineCache,',
            '                                     args.createInfoCount,',
            '                                     native_pCreateInfos,',
            '                                     native_pAllocator,',
            '                                     native_pPipelines);',
            '    callbacks_.PostCall(context);',
            '}',
        ))

    def make_descriptor_update_template_body(self, command):
        declaration = self.make_descriptor_update_template_decl(command).replace(
            'Process_', 'VulkanNativeCallConsumer::Process_', 1
        )
        return '\n'.join((
            '\n' + declaration,
            '{',
            '    auto native_device = MaterializeVkDevice(args.device);',
            '    auto native_descriptorSet = MaterializeVkDescriptorSet(args.descriptorSet);',
            '    auto native_descriptorUpdateTemplate =',
            '        MaterializeVkDescriptorUpdateTemplate(args.descriptorUpdateTemplate);',
            '    const auto context = MakeCallContext(call_info,',
            '                                         format::ApiCallId::ApiCall_{0},'.format(command),
            '                                         "{0}",'.format(command),
            '                                         nullptr,',
            '                                         0);',
            '    auto registered_native_function =',
            '        reinterpret_cast<PFN_{0}>(callbacks_.Resolve(context));'.format(command),
            '    if (registered_native_function == nullptr)',
            '    {',
            '        return;',
            '    }',
            '',
            '    std::vector<uint8_t> native_data;',
            '    if (!MaterializeDescriptorUpdateTemplateData(',
            '            args.descriptorUpdateTemplate, &args.pData, &native_data))',
            '    {',
            '        callbacks_.UnsupportedCall(context);',
            '        return;',
            '    }',
            '    const void* native_pData = args.pData.IsNull() ? nullptr : native_data.data();',
            '',
            '    callbacks_.PreCall(context);',
            '    (void)registered_native_function(native_device,',
            '                                     native_descriptorSet,',
            '                                     native_descriptorUpdateTemplate,',
            '                                     native_pData);',
            '    callbacks_.PostCall(context);',
            '}',
        ))

    def generate_handle_definitions(self):
        opaque_address_object_types = {
            'VkBuffer': 'VK_OBJECT_TYPE_BUFFER',
            'VkDeviceMemory': 'VK_OBJECT_TYPE_DEVICE_MEMORY',
            'VkAccelerationStructureKHR': 'VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR',
            'VkMicromapEXT': 'VK_OBJECT_TYPE_MICROMAP_EXT',
        }
        for handle in sorted(self.handle_names):
            alias = self.handle_aliases.get(handle)
            lines = [
                '',
                '{} VulkanNativeCallConsumer::Materialize{}(format::HandleId id)'.format(handle, handle),
                '{',
            ]
            if alias:
                lines.append('    return Materialize{}(id);'.format(alias))
            else:
                info_type = 'Vulkan{}Info'.format(handle[2:])
                lines.extend((
                    '    if (id == format::kNullHandleId)',
                    '    {',
                    '        return format::FromHandleId<{}>(id);'.format(handle),
                    '    }',
                    '',
                    '    const auto* existing = object_info_table_.Get{}Info(id);'.format(handle),
                    '    if (existing != nullptr)',
                    '    {',
                ))
                if handle in opaque_address_object_types:
                    lines.append(
                        '        ResolvePendingOpaqueAddresses(id, {}, existing->handle);'.format(
                            opaque_address_object_types[handle]
                        )
                    )
                lines.extend((
                    '        return existing->handle;',
                    '    }',
                    '',
                    '    {} info;'.format(info_type),
                    '    info.capture_id = id;',
                    '    info.handle = format::FromHandleId<{}>(id);'.format(handle),
                    '    const {} handle = info.handle;'.format(handle),
                    '    object_info_table_.Add{}Info(std::move(info));'.format(handle),
                ))
                if handle in opaque_address_object_types:
                    lines.append(
                        '    ResolvePendingOpaqueAddresses(id, {}, handle);'.format(
                            opaque_address_object_types[handle]
                        )
                    )
                lines.append('    return handle;')
            lines.append('}')
            write('\n'.join(lines), file=self.outFile)

    def write_guarded_line(self, line, protect):
        if protect:
            write('#ifdef {}'.format(protect), file=self.outFile)
        write(line, file=self.outFile)
        if protect:
            write('#endif /* {} */'.format(protect), file=self.outFile)

    def generate_command_info_definitions(self):
        write('\nnamespace', file=self.outFile)
        write('{', file=self.outFile)
        write('const VulkanNativeCommandInfo kVulkanNativeCommands[] = {', file=self.outFile)
        for command in sorted(self.generated_commands):
            protect = self.generated_commands[command]
            line = '    {{ "{}", static_cast<uint32_t>(format::ApiCallId::ApiCall_{}) }},'.format(
                command, command
            )
            self.write_guarded_line(line, protect)
        write('};', file=self.outFile)
        write('} // namespace', file=self.outFile)

        write('\nconst VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(const char* name)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (name == nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        return nullptr;', file=self.outFile)
        write('    }', file=self.outFile)
        write('    for (const auto& command : kVulkanNativeCommands)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        if (std::strcmp(command.name, name) == 0)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            return &command;', file=self.outFile)
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('    return nullptr;', file=self.outFile)
        write('}', file=self.outFile)

        write('\nconst VulkanNativeCommandInfo* GetVulkanNativeCommandInfo(uint32_t call_id)', file=self.outFile)
        write('{', file=self.outFile)
        write('    switch (static_cast<format::ApiCallId>(call_id))', file=self.outFile)
        write('    {', file=self.outFile)
        for command in sorted(self.generated_commands):
            protect = self.generated_commands[command]
            lines = (
                '        case format::ApiCallId::ApiCall_{}:'.format(command),
                '        {',
                '            static const VulkanNativeCommandInfo command =',
                '                {{ "{}", static_cast<uint32_t>(format::ApiCallId::ApiCall_{}) }};'.format(
                    command, command
                ),
                '            return &command;',
                '        }',
            )
            if protect:
                write('#ifdef {}'.format(protect), file=self.outFile)
            for line in lines:
                write(line, file=self.outFile)
            if protect:
                write('#endif /* {} */'.format(protect), file=self.outFile)
        write('        default:', file=self.outFile)
        write('            return nullptr;', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        write('\nconst char* GetVulkanApiCallName(uint32_t call_id)', file=self.outFile)
        write('{', file=self.outFile)
        write('    switch (static_cast<format::ApiCallId>(call_id))', file=self.outFile)
        write('    {', file=self.outFile)
        for command in sorted(self.all_commands):
            write('        case format::ApiCallId::ApiCall_{}:'.format(command), file=self.outFile)
            write('            return "{}";'.format(command), file=self.outFile)
        write('        default:', file=self.outFile)
        write('            return "unknown Vulkan command";', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
