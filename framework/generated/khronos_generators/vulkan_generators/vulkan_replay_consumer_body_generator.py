#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

import json
import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from khronos_replay_consumer_body_generator import KhronosReplayConsumerBodyGenerator


class VulkanReplayConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

    def __init__(
        self,
        replay_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
        dump_resources_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
        replay_async_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
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
            replay_overrides=replay_overrides,
            dump_resources_overrides=dump_resources_overrides,
            replay_async_overrides=replay_async_overrides,
            extra_headers=extra_headers
        )


class VulkanReplayConsumerBodyGenerator(
    KhronosReplayConsumerBodyGenerator, BaseGenerator
):
    """VulkanReplayConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
    """

    # Map of pool object types associating the pool type with the allocated type and the allocated type with the pool type.
    POOL_OBJECT_ASSOCIATIONS = {
        'VkCommandBuffer': 'VkCommandPool',
        'VkDescriptorSet': 'VkDescriptorPool',
        'VkCommandPool': 'VkCommandBuffer',
        'VkDescriptorPool': 'VkDescriptorSet'
    }

    NOT_SKIP_FUNCTIONS_OFFSCREEN = ['Create', 'Destroy', 'GetSwapchainImages', 'AcquireNextImage', 'QueuePresent']

    SKIP_FUNCTIONS_OFFSCREEN = ['Surface', 'Swapchain', 'Present']

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_replay_consumer.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        write(
            '#include "decode/vulkan_handle_mapping_util.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_dispatch_table.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        api_data = self.get_api_data()

        KhronosReplayConsumerBodyGenerator.generate_replay_consumer_content(self, api_data)
        KhronosReplayConsumerBodyGenerator.generate_extended_struct_handling(self, api_data)

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def is_instance_type(self, typename):
        ''' Method overide. '''
        api_data = self.get_api_data()
        if typename == api_data.instance_type or typename in ['VkPhysicalDevice']:
            return True
        return False

    def use_instance_table(self, name, typename):
        ''' Method overide. '''
        if self.is_instance_type(typename):
            return True
        # vkSetDebugUtilsObjectNameEXT and vkSetDebugUtilsObjectTagEXT
        # need to be probed from GetInstanceProcAddress due to a loader issue.
        # https://github.com/KhronosGroup/Vulkan-Loader/issues/1109
        # TODO : When loader with fix for issue is widely available, remove this
        # special case.
        if name in ['vkSetDebugUtilsObjectNameEXT', 'vkSetDebugUtilsObjectTagEXT']:
            return True
        return False

    def is_pool_allocation(self, command):
        """
        Method override.
        Determine if an API call is perfroming a pool allocation.
        """
        if command.startswith('vkAllocate') and (command != 'vkAllocateMemory'):
            return True
        return False

    def get_pool_allocation_type(self, value):
        """Method may be overridden"""
        if value.base_type in self.POOL_OBJECT_ASSOCIATIONS:
            return self.POOL_OBJECT_ASSOCIATIONS[value.base_type]
        return None

    def make_consumer_func_body(self, api_data, return_type, name, values):
        """
        Method override.
        Return VulkanReplayConsumer class member function definition.
        """
        body = ''
        is_override = name in self.REPLAY_OVERRIDES
        is_dump_resources = self.is_dump_resources_api_call(name)

        is_skip_offscreen = True

        # function 'can' use asynchronous control-flow
        is_async = name in self.REPLAY_ASYNC_OVERRIDES

        for key in self.NOT_SKIP_FUNCTIONS_OFFSCREEN:
            if key in name:
                is_skip_offscreen = False
                break

        if is_skip_offscreen:
            is_print = False
            for value in values:
                for key in self.SKIP_FUNCTIONS_OFFSCREEN:
                    if self.is_has_specific_key_word_in_type(value, key):
                        if name == 'vkAcquireFullScreenExclusiveModeEXT':
                            body += '    if ((options_.swapchain_option == util::SwapchainOption::kOffscreen) || (options_.force_windowed_origin == true) || (options_.force_windowed == true))\n'
                        else:
                            body += '    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)\n'
                        body += '    {\n'
                        if name == 'vkAcquireFullScreenExclusiveModeEXT':
                            body += '        GFXRECON_LOG_DEBUG("Skip ' + name + ' for offscreen or force windowed mode.");\n'
                        else:
                            body += '        GFXRECON_LOG_DEBUG("Skip ' + name + ' for offscreen.");\n'
                        body += '        return;\n'
                        body += '    }\n'
                        is_print = True
                        break
                if is_print:
                    break

        args, preexpr, postexpr = self.make_body_expression(
            api_data, return_type, name, values, is_override
        )
        arglist = ', '.join(args)

        dispatchfunc = ''
        if not self.is_core_type(name):
            object_name = args[0]
            if self.use_instance_table(name, values[0].base_type):
                dispatchfunc = 'GetInstanceTable'
                if api_data.has_device and values[0].base_type == api_data.device_type:
                    object_name = 'physical_device'
                    preexpr.append("VulkanDeviceInfo* device_info     = GetObjectInfoTable().GetVkDeviceInfo(device);")
                    preexpr.append("VkPhysicalDevice  physical_device = device_info->parent;")
            else:
                dispatchfunc = 'GetDeviceTable'

            if is_override:
                dispatchfunc += '({}->handle)->{}'.format(object_name, name[2:])
            else:
                dispatchfunc += '({})->{}'.format(object_name, name[2:])

        call_expr = ''
        if is_override:
            if self.is_core_create_command(name):
                call_expr = '{}(returnValue, {})'.format(
                    self.REPLAY_OVERRIDES[name], arglist
                )
            elif return_type == api_data.return_type_enum or return_type == 'VkDeviceAddress':
                # Override functions receive the decoded return value in addition to parameters.
                if name not in ['vkQueueSubmit', 'vkBeginCommandBuffer']:
                    call_expr = '{}({}, returnValue, {})'.format(
                        self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                    )
                else:
                    call_expr = '{}({}, call_info.index, returnValue, {})'.format(
                        self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                    )
            else:
                call_expr = '{}({}, {})'.format(
                    self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                )
        else:
            call_expr = '{}({})'.format(dispatchfunc, arglist)

        if preexpr:
            body += '\n'.join(
                ['    ' + val if val else val for val in preexpr]
            )
            body += '\n'
            body += '\n'
        if return_type == api_data.return_type_enum:
            if is_async:
                body += '    if (UseAsyncOperations())\n'
                body += '    {\n'
                body += '        auto task = {}({}, returnValue, call_info, {});\n'.format(self.REPLAY_ASYNC_OVERRIDES[name], dispatchfunc, arglist)
                body += '        if(task)\n'
                body += '        {\n'
                body += '           {}\n'.format(postexpr[0])
                body += '           return;\n'
                body += '        }\n'
                body += '    }\n'
                postexpr = postexpr[1:]  # drop async post-expression, don't repeat later

            body += '    {} replay_result = {};\n'.format(api_data.return_type_enum, call_expr)
            body += '    CheckResult("{}", returnValue, replay_result, call_info);\n'.format(name)
        else:
            body += '    {};\n'.format(call_expr)

        # Dump resources code generation
        if is_dump_resources:
            is_dr_override = name in self.DUMP_RESOURCES_OVERRIDES

            dump_resource_arglist = ''
            if is_override:
                for val in values:
                    if val.is_pointer and self.is_struct(val.base_type):
                        if is_dr_override:
                            dump_resource_arglist += val.name
                        else:
                            dump_resource_arglist += val.name + '->GetPointer()'
                    elif self.is_handle(val.base_type):
                        if val.is_pointer:
                            dump_resource_arglist += val.name + '->GetHandlePointer()'
                        elif val.base_type in ["VkPipeline"]:
                            dump_resource_arglist += 'in_' + val.name
                        else:
                            dump_resource_arglist += 'in_' + val.name + '->handle'
                    else:
                        if val.is_pointer and val.base_type == "void":
                            # avoids passing a PointerDecoder* here (which is wrong but compiles fine, yikes)
                            # -> dump-resource API expects raw void*
                            dump_resource_arglist += val.name + '->GetPointer()'
                        else:
                            dump_resource_arglist += val.name
                    dump_resource_arglist += ', '
                dump_resource_arglist = dump_resource_arglist[:-2]
            else:
                if is_dr_override:
                    for val in values:
                        if val.is_pointer and not self.is_handle(val.base_type):
                            if self.is_struct(val.base_type):
                                dump_resource_arglist += val.name
                            else:
                                dump_resource_arglist += 'in_' + val.name
                        elif val.base_type == 'VkPipeline':
                            dump_resource_arglist += 'GetObjectInfoTable().GetVkPipelineInfo(pipeline)'
                        elif self.is_handle(val.base_type) and not val.is_pointer and val.base_type == 'VkCommandBuffer':
                            dump_resource_arglist += 'in_' + val.name
                        elif self.is_handle(val.base_type) and not val.is_pointer and val.base_type != 'VkCommandBuffer':
                            dump_resource_arglist += 'GetObjectInfoTable().Get' + val.base_type + "Info(" + val.name + ")"
                        else:
                            dump_resource_arglist += val.name
                        dump_resource_arglist += ', '
                    dump_resource_arglist = dump_resource_arglist[:-2]
                else:
                    dump_resource_arglist = arglist

            body += '\n'
            body += '    if (options_.dumping_resources)\n'
            body += '    {\n'
            if return_type == api_data.return_type_enum:
                body += '        resource_dumper_->Process_{}(call_info, {}, returnValue, {});\n'.format(name, dispatchfunc, dump_resource_arglist)
            else:
                body += '        resource_dumper_->Process_{}(call_info, {}, {});\n'.format(name, dispatchfunc, dump_resource_arglist)

            body += '    }\n'

        if postexpr:
            body += '\n'
            body += '\n'.join(
                ['    ' + val if val else val for val in postexpr]
            )
            body += '\n'

        cleanup_expr = self.generate_remove_handle_expression(name, values)
        if cleanup_expr:
            body += '    {}\n'.format(cleanup_expr)

        return body

    def needs_remove_handle_expression(self, command):
        """Method override."""
        if (KhronosReplayConsumerBodyGenerator.needs_remove_handle_expression(self, command) or
            command == 'vkFreeMemory'):
            return True
        return False

    def generate_remove_handle_expression(self, name, values):
        """Method override."""
        expr = None
        if self.needs_remove_handle_expression(name):
            value = self.determine_handle_to_remove_value(name, values)
            if value.base_type not in self.POOL_OBJECT_ASSOCIATIONS:
                expr = KhronosReplayConsumerBodyGenerator.generate_remove_handle_expression(self, name, values)
            else:
                # Pools require special case processing to cleanup objects allocated from them.
                expr = 'RemovePoolHandle<Vulkan{type}Info>({}, &CommonObjectInfoTable::Get{basetype}Info, &CommonObjectInfoTable::Remove{basetype}Info, &CommonObjectInfoTable::Remove{}Info);'.format(
                    value.name,
                    self.POOL_OBJECT_ASSOCIATIONS[value.base_type],
                    type=value.base_type[2:],
                    basetype=value.base_type
                )
        elif name.startswith('vkFree'):
            # For pool based vkFreeCommandBuffers and vkFreeDescriptorSets, the pool handle is the second parameter, the array count is the third parameter and the array of handles to free is the fourth parameter.
            value = values[3]
            expr = 'RemovePoolHandles<Vulkan{pooltype}Info, Vulkan{type}Info>({}, {}, {}, &CommonObjectInfoTable::Get{poolbasetype}Info, &CommonObjectInfoTable::Remove{basetype}Info);'.format(
                values[1].name,
                value.name,
                values[2].name,
                type=value.base_type[2:],
                basetype=value.base_type,
                pooltype=self.POOL_OBJECT_ASSOCIATIONS[value.base_type][2:],
                poolbasetype=self.POOL_OBJECT_ASSOCIATIONS[value.base_type]
            )

        return expr

    def is_async_handle_type(self, basetype):
        return basetype in ["VkPipeline", "VkShaderExt"]

    def is_allocation_callback_type(self, struct):
        """Method override."""
        return struct == 'VkAllocationCallbacks'

    def is_special_case_value(self, value):
        """Method override."""
        if ((value.name == 'pSurfaceInfo' and value.base_type != 'VkSurfaceKHR') or
             value.name == 'surface' or value.name == 'swapchain'):
            return True
        return False

    def handle_special_case_pointer_array(self, value, is_override):
        """Method override."""
        preexpr = []
        # If surface was not created, need to automatically ignore for non-overrides queries
        # Swapchain also need to check if a dummy swapchain was created instead
        if value.name == 'pSurfaceInfo' and value.base_type != 'VkSurfaceKHR':
            expr = 'if ({}->GetPointer()->surface == VK_NULL_HANDLE) {{ return; }}'.format(
                value.name
            )
            preexpr.append(expr)

            expr = 'MapStructHandles({}->GetMetaStructPointer(), GetObjectInfoTable());'.format(
                value.name
            )
            preexpr.append(expr)

            var_name = 'in_' + value.name + '_meta'
            expr = 'auto {} = {}->GetMetaStructPointer();'.format(
                var_name, value.name
            )
            preexpr.append(expr)

            expr = 'if (GetObjectInfoTable().GetVkSurfaceKHRInfo({}->surface) == nullptr || '.format(
                var_name
            )
            expr += 'GetObjectInfoTable().GetVkSurfaceKHRInfo({}->surface)->surface_creation_skipped) {{ return; }}'.format(
                var_name
            )
            preexpr.append(expr)
        # If surface was not created, need to automatically ignore for non-overrides queries
        # Swapchain also need to check if a dummy swapchain was created instead
        elif value.name == "surface":
            if is_override:
                arg_name = 'in_' + value.name
                expr = 'if ({} == nullptr || {}->surface_creation_skipped) {{ return; }}'.format(
                    arg_name, arg_name
                )
                preexpr.append(expr)
            else:
                expr = 'if (GetObjectInfoTable().GetVkSurfaceKHRInfo({}) == nullptr || '.format(
                    value.name
                )
                expr += 'GetObjectInfoTable().GetVkSurfaceKHRInfo({})->surface_creation_skipped) {{ return; }}'.format(
                    value.name
                )
                preexpr.append(expr)
        elif value.name == "swapchain":
            expr = 'if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().Get{}Info({})->surface_id) == nullptr || '.format(
                value.base_type, value.name
            )
            expr += 'GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().Get{}Info({})->surface_id)->surface_creation_skipped) {{ return; }}'.format(
                value.base_type, value.name
            )
            preexpr.append(expr)
        return preexpr


    def needs_pipeline_customization(self, name):
        """Method override."""
        return (name == 'vkCreateGraphicsPipelines' or name == 'vkCreateComputePipelines' or name == 'vkCreateRayTracingPipelinesNV')

    def handle_pipeline_customization(self, length_name):
        """Method override."""
        return 'if (omitted_pipeline_cache_data_) {{AllowCompileDuringPipelineCreation({}, pCreateInfos->GetPointer());}}'.format(length_name)
