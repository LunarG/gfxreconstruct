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
from base_replay_consumer_body_generator import BaseReplayConsumerBodyGenerator


class VulkanReplayConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

    def __init__(
        self,
        replay_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
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
        self.replay_overrides = replay_overrides


class VulkanReplayConsumerBodyGenerator(
    BaseReplayConsumerBodyGenerator, BaseGenerator
):
    """VulkanReplayConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
    """

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    REPLAY_OVERRIDES = {}

    # Map of pool object types associating the pool type with the allocated type and the allocated type with the pool type.
    POOL_OBJECT_ASSOCIATIONS = {
        'VkCommandBuffer': 'VkCommandPool',
        'VkDescriptorSet': 'VkDescriptorPool',
        'VkCommandPool': 'VkCommandBuffer',
        'VkDescriptorPool': 'VkDescriptorSet'
    }

    SKIP_PNEXT_STRUCT_TYPES = [ 'VK_STRUCTURE_TYPE_BASE_IN_STRUCTURE', 'VK_STRUCTURE_TYPE_BASE_OUT_STRUCTURE' ]

    NOT_SKIP_FUNCTIONS_OFFSCREEN = ['Create', 'Destroy', 'GetSwapchainImages', 'AcquireNextImage', 'QueuePresent']
    
    SKIP_FUNCTIONS_OFFSCREEN = ['Surface', 'Swapchain', 'Present']

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.structs_with_handle_ptrs = []
        # Map of struct types to associated VkStructureType.
        self.stype_values = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        if gen_opts.replay_overrides:
            self.__load_replay_overrides(gen_opts.replay_overrides)

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
        write(
            '#include "generated/generated_vulkan_dr_command_buffer_util.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode) //@@@HYH', file=self.outFile)

        self.newline()
        write('#define TESTCODE 1', file=self.outFile)

        self.newline()
        write('template <typename T>', file=self.outFile)
        write('void InitializeOutputStructPNext(StructPointerDecoder<T> *decoder);//@@@EZA', file=self.outFile)

        self.newline()
        write('class CmdBuffApiCall //@@@WPK    This could be struct instead and then could omit public: below', file=self.outFile)
        write('{', file=self.outFile)
        write('public:', file=self.outFile)
        write('    gfxrecon::format::ApiCallId apiCall;', file=self.outFile)
        write('    format::ThreadId            thread_id;', file=self.outFile)
        write('    std::vector<uint8_t>        parameter_buffer_data;', file=self.outFile)
        write('    size_t                      parameter_buffer_size;', file=self.outFile)
        write('    ApiDecoder                  *decoder;', file=self.outFile)
        write('};', file=self.outFile)

        self.newline()
        write('std::list<CmdBuffApiCall> savedDRCmdBuff; //@@@DSX', file=self.outFile)

        self.newline()
        write('// Initialization of these should be done at replay startup during first pass through capture file.', file=self.outFile)
        write('// For now we hard code these for turning on command buffer saving code', file=self.outFile)
        write('uint64_t g_saveCmdBuf_BeginCommandBuffer_Index = 105;   //@@@ Index of vkBeginCommandBuffer command which will trigger saving of command buffer commands', file=self.outFile)
        write('uint64_t g_dumpResourses_CmdDraw_Index = 111;           //@@@ Index of vkCmdDraw which will trigger dump resources', file=self.outFile)
        write('uint64_t g_dumpResourses_QueueSubmit_Index = 154;       //@@@ Index of vkQueueSubmit in which we dump resources', file=self.outFile)
        self.newline()
        write('static format::HandleId  g_savingCommandBuffer = 0;                     //@@@ commandBuffer we are current saving', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write('static void InitializeOutputStructPNextImpl(const VkBaseInStructure* in_pnext, VkBaseOutStructure* output_struct)', file=self.outFile)
        write('{', file=self.outFile)
        write('    while(in_pnext)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch(in_pnext->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        for struct in self.stype_values:
            struct_type = self.stype_values[struct]
            if not struct_type in self.SKIP_PNEXT_STRUCT_TYPES:
                write('            case {}:'.format(struct_type), file=self.outFile)
                write('            {', file=self.outFile)
                write('                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<{}>());'
                    .format(struct),
                    file=self.outFile
                )
                write('                break;', file=self.outFile)
                write('            }', file=self.outFile)
        write('            default:', file=self.outFile)
        write('                break;', file=self.outFile)
        write('        }', file=self.outFile)
        write('        output_struct = output_struct->pNext;', file=self.outFile)
        write('        output_struct->sType = in_pnext->sType;',file=self.outFile)
        write('        in_pnext = in_pnext->pNext;', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        write('template <typename T>', file=self.outFile)
        write('void InitializeOutputStructPNext(StructPointerDecoder<T> *decoder)/*@@@IYQ*/', file=self.outFile)
        write('{', file=self.outFile)
        write('    if(decoder->IsNull()) return;', file=self.outFile)
        write('    size_t len = decoder->GetOutputLength();', file=self.outFile)
        write('    auto input = decoder->GetPointer();', file=self.outFile)
        write('    auto output = decoder->GetOutputPointer();', file=self.outFile)
        write('    for( size_t i = 0 ; i < len; ++i )', file=self.outFile)
        write('    {', file=self.outFile)
        write('        const auto* in_pnext = reinterpret_cast<const VkBaseInStructure*>(input[i].pNext);', file=self.outFile)
        write('        if( in_pnext == nullptr ) continue;', file=self.outFile)
        write('        auto* output_struct = reinterpret_cast<VkBaseOutStructure*>(&output[i]);', file=self.outFile)
        write('        InitializeOutputStructPNextImpl(in_pnext, output_struct);', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
       
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
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            )

            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                self.stype_values[typename] = stype

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        BaseReplayConsumerBodyGenerator.generate_feature(self)

    def use_instance_table(self, name, typename):
        """Check for dispatchable handle types associated with the instance dispatch table."""
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        # vkSetDebugUtilsObjectNameEXT and vkSetDebugUtilsObjectTagEXT
        # need to be probed from GetInstanceProcAddress due to a loader issue.
        # https://github.com/KhronosGroup/Vulkan-Loader/issues/1109
        # TODO : When loader with fix for issue is widely available, remove this
        # special case.
        if name in ['vkSetDebugUtilsObjectNameEXT', 'vkSetDebugUtilsObjectTagEXT']:
            return True
        return False

    def get_parent_id(self, value, values):
        """Get the ID of the parent object when creating a Vulkan handle.  VkInstance is does not have a parent object."""
        if value.base_type != "VkInstance":
            return values[0].name
        return 'format::kNullHandleId'

    def is_pool_allocation(self, name):
        """Determine if an API call is perfroming a pool allocation."""
        if name.startswith('vkAllocate') and (name != 'vkAllocateMemory'):
            return True
        return False

    def get_param_list_handles(self, values):
            """Create list of parameters that have handle types or are structs that contain handles."""
            handles = []
            for value in values:
                if self.is_handle(value.base_type):
                    handles.append(value)
                elif self.is_struct(value.base_type) and (value.base_type in self.structs_with_handles):
                    handles.append(value)     #@@@ TODO: Fix this if/elif/else
            return handles

    def make_get_command_handles_expr(self, cmd, handle_params):
        """Generate an expression for a get command buffer handles utility function."""
        args = ["in_commandBuffer"]
        for value in handle_params:
            if value.array_length:
                args.append(value.array_length)
            if self.is_handle(value.base_type):
                args.append('in_'+value.name)
            elif value.is_pointer:
                args.append('in_'+value.name)
            else:
                args.append(value.name)
        return 'TrackDR{}Handles({});'.format(cmd[2:], ', '.join(self.make_unique_list(args)))

    def make_consumer_func_body(self, return_type, name, values):
        """Return VulkanReplayConsumer class member function definition."""
        body=''

        is_override = name in self.REPLAY_OVERRIDES

        is_skip_offscreen = True
        
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

        args, preexpr, postexpr = self.make_body_expressions(
            return_type, name, values, is_override
        )
        arglist = ', '.join(args)

        dispatchfunc = ''
        if name not in ['vkCreateInstance', 'vkCreateDevice']:
            object_name = args[0]
            if self.use_instance_table(name, values[0].base_type):
                dispatchfunc = 'GetInstanceTable'
                if values[0].base_type == 'VkDevice':
                    object_name = 'physical_device'
                    preexpr.append("DeviceInfo* device_info = GetObjectInfoTable().GetDeviceInfo(device);")
                    preexpr.append("VkPhysicalDevice             physical_device = device_info->parent;")
            else:
                dispatchfunc = 'GetDeviceTable'

            if is_override:
                dispatchfunc += '({}->handle)->{}'.format(object_name, name[2:])
            else:
                dispatchfunc += '({})->{}'.format(object_name, name[2:])

        if is_override:
            if name in ['vkCreateInstance', 'vkCreateDevice']:
                call_expr = '{}(returnValue, {})/*@@@ADH*/'.format(
                    self.REPLAY_OVERRIDES[name], arglist
                )
            elif return_type == 'VkResult':
                # Override functions receive the decoded return value in addition to parameters.
                call_expr = '{}({}, returnValue, {})/*@@@HNM*/'.format(
                    self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                )
            else:
                call_expr = '{}({}, {})/*@@@PKQ*/'.format(
                    self.REPLAY_OVERRIDES[name], dispatchfunc, arglist)
        else:
            call_expr = '{}({})/*@@@ABC*/'.format(dispatchfunc, arglist)

        if preexpr:
            body += '\n'.join(
                ['    ' + val if val else val for val in preexpr]
            )
            body += '//@@@DFK\n'
        if return_type == 'VkResult':
            if name == 'vkBeginCommandBuffer':
                body += '#if TESTCODE\n'
                body += '    if (call_info.index != g_saveCmdBuf_BeginCommandBuffer_Index)\n'
                body += '    {\n'
                body += '#endif\n'
            if name == 'vkEndCommandBuffer':
                body += '#if TESTCODE\n'
                body += '    if (g_savingCommandBuffer != commandBuffer)\n'
                body += '    {\n'
                body += '#endif\n'
            body += '    VkResult replay_result = {};\n'.format(call_expr)
            body += '    CheckResult("{}", returnValue, replay_result, call_info);\n'.format(
                name
            )
            if name == 'vkBeginCommandBuffer' or name == 'vkEndCommandBuffer':
                body += '#if TESTCODE\n'
                body += '    }\n'
                body += '#endif\n'
        else:
            if values[0].full_type == 'VkCommandBuffer':
                body += '#if TESTCODE\n'
                body += '    if (g_savingCommandBuffer != commandBuffer)\n'
                body += '#endif\n'
                body += '        {};//@@@HQA\n'.format(call_expr)
            else:
                body += '    {};//@@@HQA\n'.format(call_expr)
        if postexpr:
            body += '\n'.join(
                ['    ' + val if val else val for val in postexpr]
            )
            body += '\n'

        if values[0].full_type == 'VkCommandBuffer':
            body += '\n'
            body += '    {\n'
            body += '        VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);\n'
            body += '\n'

            if name =='vkBeginCommandBuffer':
                body += '        //@@@WTN Enable saving of command buffer if we have reached the designated BeginCmdBuffer cmd\n'
                body += '        if (call_info.index == g_saveCmdBuf_BeginCommandBuffer_Index)\n'
                body += '        {\n'
                body += '            g_savingCommandBuffer = commandBuffer;\n'
                body += '        }\n'
                body += '\n'

            body += '        //@@@ECH Save this command if we are currently saving commands\n'
            body += '        //       TODO: should reset clear the current command buffer??\n'
            body += '        //       TODO: What should we do when we encounter the draw command that is to trigger the resource dump??\n'
            body += '        if (g_savingCommandBuffer == commandBuffer)\n'
            body += '        {\n'
            body += '            //@@@AWP TODO: Can this be made into a function? It would reduce code size for all the replay funcs.\n'
            body += '            CmdBuffApiCall s;\n'
            body += '            s.apiCall = format::ApiCall_'+name+';\n'
            body += '            s.thread_id = call_info.thread_id;\n'
            body += '            s.parameter_buffer_data.resize(call_info.parameter_buffer_size);\n'
            body += '            s.parameter_buffer_size = call_info.parameter_buffer_size;\n'
            body += '            memcpy(s.parameter_buffer_data.data(), call_info.parameter_buffer_data, call_info.parameter_buffer_size);\n'
            body += '            s.decoder = call_info.decoder;\n'
            body += '            savedDRCmdBuff.push_back(s);\n'
            if name =='vkEndCommandBuffer':
                body += '#if TESTCODE\n'
                body += '            // Playback the saved cmd buffer\n'
                body += '            g_savingCommandBuffer = 0;\n'
                body += '            for (auto it = savedDRCmdBuff.begin(); it != savedDRCmdBuff.end(); it++)\n'
                body += '            {\n'
                body += '                ApiCallInfo replay_call_info;\n'
                body += '                replay_call_info.index = 0; //@@@ZXC Set to 0 to keep from triggering another cmdbuf save\n'
                body += '                replay_call_info.thread_id = it->thread_id;\n'
                body += '                replay_call_info.parameter_buffer_data = it->parameter_buffer_data.data(); // Not really needed since cmd will not be saved,\n'
                body += '                replay_call_info.parameter_buffer_size = it->parameter_buffer_size;        // but they are set here for completeness.\n'
                body += '                replay_call_info.thread_id = it->thread_id;\n'
                body += '                it->decoder->DecodeFunctionCall(it->apiCall, replay_call_info, it->parameter_buffer_data.data(), it->parameter_buffer_size);\n'
                body += '            }\n'
                body += '            savedDRCmdBuff.clear();\n'
                body += '#endif\n'
            body += '        }\n'

        drFuncExcludeList=['vkBeginCommandBuffer','vkResetCommandBuffer']
        handle_params = self.get_param_list_handles(values)
        if values[0].full_type == 'VkCommandBuffer' and len(handle_params) > 1 and (name not in drFuncExcludeList):
            body += '        //@@@XZP Log all handles associated with command buffers\n'
            if name == 'vkCmdPipelineBarrier':
                body += '        const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = pBufferMemoryBarriers->GetPointer();\n'
                body += '        const VkImageMemoryBarrier* in_pImageMemoryBarriers = pImageMemoryBarriers->GetPointer();\n'
            if name == 'vkCmdBeginRenderPass':
                body += '        const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();\n'
            get_handles_expr = self.make_get_command_handles_expr(name, handle_params[1:])
            body += '        ' + get_handles_expr + '\n'
            body += '\n'
        if values[0].full_type == 'VkCommandBuffer':
            body += '    }\n'

        cleanup_expr = self.make_remove_handle_expression(name, values)
        if cleanup_expr:
            body += '    {}\n'.format(cleanup_expr)

        return body

    def make_variable_length_array_post_expr(
        self, name, value, values, length_name
    ):
        """Generate expressions to store the result of the count query for an array containing a variable number of values."""
        handle_value = values[0]
        if self.is_handle(values[1].base_type):
            handle_value = values[1]

        index_id = 'k{}Array{}'.format(handle_value.base_type[2:], name[2:])
        handle_type = '{}Info'.format(handle_value.base_type[2:])
        info_func = '&VulkanObjectInfoTable::Get{}Info'.format(
            handle_value.base_type[2:]
        )

        return 'if ({}->IsNull()) {{ SetOutputArrayCount<{}>({}, {}, {}, {}); }}'.format(
            value.name, handle_type, handle_value.name, index_id, length_name,
            info_func
        )

    def make_variable_length_array_get_count_call(
        self, return_type, name, value, values
    ):
        """Generate expressions to call a function that retrieves the count of an array containing a variable number of values."""
        return_value = 'VK_SUCCESS'
        if (return_type == 'VkResult'):
            return_value = 'returnValue'

        handle_value = values[0]
        if self.is_handle(values[1].base_type):
            handle_value = values[1]

        array_name = None
        for v in values:
            if v.array_length == value.name:
                array_name = v.name

        if not array_name:
            print(
                "WARNING: Could not determine the name of the array parameter associate with function {} count parameter {}."
                .format(name, value.name)
            )

        index_id = 'k{}Array{}'.format(handle_value.base_type[2:], name[2:])
        handle_type = '{}Info'.format(handle_value.base_type[2:])
        info_func = '&VulkanObjectInfoTable::Get{}Info'.format(
            handle_value.base_type[2:]
        )

        return 'GetOutputArrayCount<{}, {}>("{}", {}, {}, {}, {}, {}, {})'.format(
            value.base_type, handle_type, name, return_value,
            handle_value.name, index_id, value.name, array_name, info_func
        )

    def make_body_expressions(self, return_type, name, values, is_override):
        """"Generating expressions for mapping decoded parameters to arguments used in the API call.
        For array lengths that are stored in pointers, this will map the original parameter name
        to the temporary parameter name that was created to store the value to be provided to the Vulkan API call.
        """
        array_lengths = dict()
        is_variable_length = False

        args = []  # List of arguments to the API call.
        preexpr = [
        ]  # Variable declarations for handle mappings, temporary output allocations, and input pointers.
        postexpr = [
        ]  # Expressions to add new handles to the handle map and delete temporary allocations.

        for value in values:
            need_initialize_output_pnext_struct = ''
            if value.is_pointer or value.is_array:
                full_type = value.full_type if not value.platform_full_type else value.platform_full_type
                is_input = self.is_input_pointer(value)
                is_extenal_object = False
                need_temp_value = True
                expr = ''

                if (
                    value.base_type in self.EXTERNAL_OBJECT_TYPES
                ) and not value.is_array:
                    # Currently, all arrays of external object types are 'void*' values that represent arrays of bytes, so we only have a
                    # pointer to an external object when the value is not an array.
                    is_extenal_object = True

                if (value.is_array and not value.is_dynamic):
                    # Use dynamic pointer syntax for static arrays.
                    full_type += '*'

                if is_override and not is_extenal_object:
                    # Overrides receive the PointerDecoder object instead of the actual Vulkan pointer, so the temporary value used to hold the pointer returned by
                    # PointerDecoder::GetPointer() is not needed for most cases.  Pointers to external (non-Vulkan) objects are subject to separate pre/post
                    # processing, so continue to use a temporary value that is passed to the override function instead of the PointerDecoder object.
                    need_temp_value = False

                # Determine name of variable specifying the length of an array.  An override may be required to
                # replace the original length value with a temporary pointer variable.
                length_name = value.array_length
                if length_name:
                    if length_name in array_lengths:
                        # Array lengths with pointer types are received by the consumer as PointerDecoder<T> objects, so
                        # an intermediate value of type T is created to hold the value that will be provided to the Vulkan
                        # API call.  The 'array_lengths' dictionary contains a mapping of the original parameter name to the
                        # intermediate value name.  For this case, we need to use the intermediate value for array allocations.
                        length_name = array_lengths[length_name]
                        is_variable_length = True
                    elif '->' in length_name:
                        # Some counts are members of an allocate info struct.  Similar to the above PointerDecoder<T> case,
                        # Pointers to structures are received in a StructPointerDecoder<T> object and an intermediate value is   //@@@WSQ
                        # created to store the pointer encapsulated by the object.  This case also requires using the intermediate
                        # value to access the array length.  Prepending 'in_' to the 'arraylen' value is currently sufficient to
                        # handle this case.
                        if need_temp_value:
                            length_name = 'in_' + length_name
                        else:
                            length_name = length_name.replace(
                                '->', '->GetPointer()->'
                            )

                if not need_temp_value:
                    args.append(value.name)
                else:
                    # Generate temporary variable to reference a pointer value that is encapsulated within a PointerDecoder object.
                    if is_input:
                        arg_name = '/*@@@AZI*/in_' + value.name
                    else:
                        arg_name = '/*@@@USD*/out_' + value.name

                    args.append(arg_name)

                    # Assign PointerDecoder pointer to temporary variable.
                    expr = '/*@@@HPA*/{} {} = '.format(full_type, arg_name)

                if is_input:
                    # Assign avalue to the temporary variable based on type.  Some array variables require temporary allocations.
                    if is_extenal_object:
                        # If this was an array with the 'void*' type, it was encoded as an array of bytes.
                        # If not (this case), it is a pointer to an unknown object type that was encoded as a uint64_t ID value.
                        # If possible, we will map the ID to an object previously created during replay.  Otherwise, we will
                        # need to report a warning that we may have a case that replay cannot handle.
                        if value.platform_full_type:
                            expr += '/*@@@WSX*/static_cast<{}>(PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}"));'.format(
                                value.platform_full_type,
                                value.name,
                                name=name
                            )
                        else:
                            expr += '/*@@@WPX*/PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}");'.format(
                                value.name, name=name
                            )
                    elif value.base_type == 'VkAllocationCallbacks':
                        if need_temp_value:
                            # The replay consumer needs to override the allocation callbacks used by the captured application.
                            expr += '/*@@@USX*/GetAllocationCallbacks({});'.format(
                                value.name
                            )
                    elif self.is_handle(value.base_type):
                        # We received an array of 64-bit integer IDs from the decoder.
                        expr += '/*@@@EDO*/MapHandles<{type}Info>({}, {}, &VulkanObjectInfoTable::Get{type}Info);'.format(
                            value.name, length_name, type=value.base_type[2:]
                        )
                    else:
                        if need_temp_value:
                            expr += '/*@@@HUY*/{}->GetPointer();'.format(value.name)

                        if (value.base_type in self.structs_with_handles) or (
                            value.base_type in self.GENERIC_HANDLE_STRUCTS
                        ):
                            preexpr.append(expr)
                            if value.is_array:
                                expr = '/*@@@HWC*/MapStructArrayHandles({name}->GetMetaStructPointer(), {name}->GetLength(), GetObjectInfoTable());'.format(
                                    name=value.name
                                )
                            else:
                                # If surface was not created, need to automatically ignore for non-overrides queries
                                # Swapchain also need to check if a dummy swapchain was created instead
                                if value.name == "pSurfaceInfo":
                                    expr = '/*@@@EWC*/if ({}->GetPointer()->surface == VK_NULL_HANDLE) {{ return; }}'.format(
                                        value.name
                                    )
                                    preexpr.append(expr)

                                expr = 'MapStructHandles({}->GetMetaStructPointer(), GetObjectInfoTable());'.format(
                                    value.name
                                )

                                # If surface was not created, need to automatically ignore for non-overrides queries
                                if value.name == "pSurfaceInfo":
                                    preexpr.append(expr)

                                    var_name = '/*@@@UIW*/in_' + value.name + '_meta'
                                    expr = 'auto {} = {}->GetMetaStructPointer();'.format(
                                        var_name, value.name
                                    )
                                    preexpr.append(expr)
                                    expr = '/*@@@HSW*/if (GetObjectInfoTable().GetSurfaceKHRInfo({}->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo({}->surface)->surface_creation_skipped) {{ return; }}'.format(
                                        var_name,
                                        var_name
                                    )
                                    preexpr.append(expr)
                                    expr = ''
                else:
                    # Initialize output pointer.
                    if value.is_array:
                        if is_variable_length:
                            # Store the result of an array size query.
                            postexpr.append(
                                self.make_variable_length_array_post_expr(
                                    name, value, values, length_name
                                )
                            )

                        if value.base_type in self.EXTERNAL_OBJECT_TYPES:
                            # This is effectively an array with type void*, which was encoded as an array of bytes.
                            if need_temp_value:
                                expr += '{name}->IsNull() ? nullptr : {name}->AllocateOutputData({});//@@@EJH'.format(
                                    length_name, name=value.name
                                )
                            else:
                                expr = 'if (!{name}->IsNull()) {{ {name}->AllocateOutputData({}); }}//@@@ENH'.format(
                                    length_name, name=value.name
                                )
                        elif self.is_handle(value.base_type):
                            # Add mappings for the newly created handles.
                            preexpr.append(
                                'if (!{paramname}->IsNull()) {{ {paramname}->SetHandleLength({}); }}//@@@UAZ'
                                .format(length_name, paramname=value.name)
                            )
                            if name == 'vkCreateGraphicsPipelines' or name == 'vkCreateComputePipelines' or name == 'vkCreateRayTracingPipelinesNV':
                                preexpr.append('if (omitted_pipeline_cache_data_) {{AllowCompileDuringPipelineCreation({}, in_pCreateInfos);}}'.format(length_name))
                            if need_temp_value:
                                expr += '{}->GetHandlePointer();'.format(
                                    value.name
                                )
                                if self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{pooltype}Info, {basetype}Info>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Add{basetype}Info);//@@@CCI'
                                        .format(
                                            self.get_parent_id(value, values),
                                            values[1].name,
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:],
                                            pooltype=self.
                                            POOL_OBJECT_ASSOCIATIONS[
                                                value.base_type][2:]
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'AddHandles<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &VulkanObjectInfoTable::Add{basetype}Info);//@@@UPQ'
                                        .format(
                                            self.get_parent_id(value, values),
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:]
                                        )
                                    )
                            else:
                                preexpr.append(
                                    'std::vector<{}Info> handle_info({});'.
                                    format(value.base_type[2:], length_name)
                                )
                                expr = 'for (size_t i = 0; i < {}; ++i) {{ {}->SetConsumerData(i, &handle_info[i]); }}'.format(
                                    length_name, value.name
                                )
                                if self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{pooltype}Info, {basetype}Info>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Add{basetype}Info);//@@@JKU'
                                        .format(
                                            self.get_parent_id(value, values),
                                            values[1].name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:],
                                            pooltype=self.
                                            POOL_OBJECT_ASSOCIATIONS[
                                                value.base_type][2:]
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'AddHandles<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &VulkanObjectInfoTable::Add{basetype}Info);//@@@ZZA'
                                        .format(
                                            self.get_parent_id(value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:]
                                        )
                                    )

                        elif self.is_struct(value.base_type):
                            # Generate the expression to allocate the output array.
                            alloc_expr = ''
                            if value.base_type in self.stype_values:
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                # TODO: recreate pNext value read from the capture file.
                                alloc_expr += 'AllocateOutputData({}, {}{{ {}, nullptr }}); /*@@@FFA*/ '.format(
                                    length_name, value.base_type,
                                    self.stype_values[value.base_type]
                                )
                            else:
                                alloc_expr += 'AllocateOutputData({});'.format(
                                    length_name
                                )

                            if need_temp_value:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->{} /*@@@DRW*/'.format(
                                    alloc_expr, paramname=value.name
                                )
                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    if value.base_type in self.structs_with_handle_ptrs:
                                        preexpr.append(
                                            'SetStructArrayHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength()); //@@@JHH'
                                            .format(
                                                value.base_type,
                                                paramname=value.name
                                            )
                                        )
                                    postexpr.append(
                                        'AddStructArrayHandles<Decoded_{basetype}>({}, {paramname}->GetMetaStructPointer(), {paramname}->GetLength(), {}, {}, &GetObjectInfoTable()); //@@@IOH'
                                        .format(
                                            self.get_parent_id(value, values),
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )
                            else:
                                expr += 'if (!{paramname}->IsNull()) {{ {paramname}->{} }}'.format(
                                    alloc_expr, paramname=value.name
                                )
                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    if value.base_type in self.structs_with_handle_ptrs:
                                        preexpr.append(
                                            'SetStructArrayHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength()); //@@@HAW'
                                            .format(
                                                value.base_type,
                                                paramname=value.name
                                            )
                                        )
                                    postexpr.append(
                                        'AddStructArrayHandles<Decoded_{basetype}>({}, {paramname}->GetMetaStructPointer(), {paramname}->GetLength(), {paramname}->GetOutputPointer(), {}, &GetObjectInfoTable()); //@@@LPI'
                                        .format(
                                            self.get_parent_id(value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )
                        else:
                            if need_temp_value:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData({}); //@@@DEA'.format(
                                    length_name, paramname=value.name
                                )
                            else:
                                expr = 'if ({paramname}->IsNull()) {{ {paramname}->AllocateOutputData({}); }} //@@@WPA'.format(
                                    length_name, paramname=value.name
                                )
                    else:
                        if is_extenal_object:
                            # Map the object ID to the new object
                            if value.platform_full_type:
                                expr += '{paramname}->IsNull() ? nullptr : reinterpret_cast<{}>({paramname}->AllocateOutputData(1));//@@CCC'.format(
                                    full_type, paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");//@@HPP'
                                        .format(value.name, arg_name, name=name)
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject(VK_SUCCESS, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");//@@ABC'
                                        .format(value.name, arg_name, name=name)
                                    )                                    
                            else:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);//@@@PEA'.format(
                                    paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");//@@EDS'
                                        .format(paramname=value.name, name=name)
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject(VK_SUCCESS, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");//@@OSH'
                                        .format(paramname=value.name, name=name)
                                    )                                    
                        elif self.is_handle(value.base_type):
                            # Add mapping for the newly created handle
                            preexpr.append(
                                'if (!{paramname}->IsNull()) {{ {paramname}->SetHandleLength(1); }}//@@@HET'
                                .format(paramname=value.name)
                            )
                            if need_temp_value:
                                expr += '{}->GetHandlePointer();'.format(
                                    value.name
                                )
                                postexpr.append(
                                    'AddHandle<{basetype}Info>({}, {}->GetPointer(), {}, &VulkanObjectInfoTable::Add{basetype}Info);'
                                    .format(
                                        self.get_parent_id(value, values),
                                        value.name,
                                        arg_name,
                                        basetype=value.base_type[2:]
                                    )
                                )
                            else:
                                preexpr.append(
                                    '{}Info handle_info;'.format(
                                        value.base_type[2:]
                                    )
                                )
                                expr = '{}->SetConsumerData(0, &handle_info);'.format(
                                    value.name
                                )
                                postexpr.append(
                                    'AddHandle<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::Add{basetype}Info);'
                                    .format(
                                        self.get_parent_id(value, values),
                                        paramname=value.name,
                                        basetype=value.base_type[2:]
                                    )
                                )
                        else:
                            if self.is_array_len(value.name, values):
                                # If this is an array length, it is an in/out parameter and we need to assign the input value.
                                array_len_expr = self.make_variable_length_array_get_count_call(
                                    return_type, name, value, values
                                )
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, {});'.format(
                                    array_len_expr, paramname=value.name
                                )
                                # Need to store the name of the intermediate value for use with allocating the array associated with this length.
                                if need_temp_value:
                                    array_lengths[value.name
                                                  ] = '*{}'.format(arg_name)
                                else:
                                    array_lengths[
                                        value.name
                                    ] = '*{}->GetOutputPointer()'.format(
                                        value.name
                                    )
                            elif self.is_struct(value.base_type):
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                if value.base_type in self.stype_values:
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, {{ {}, nullptr }});'.format(
                                        self.stype_values[value.base_type],
                                        paramname=value.name
                                    )
                                    need_initialize_output_pnext_struct = value.name
                                else:
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);'.format(
                                        paramname=value.name
                                    )

                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    if need_temp_value:
                                        if value.base_type in self.structs_with_handle_ptrs:
                                            preexpr.append(
                                                'SetStructHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength()); //@@@HAQ'
                                                .format(
                                                    value.base_type,
                                                    paramname=value.name
                                                )
                                            )
                                        postexpr.append(
                                            'AddStructHandles<Decoded_{basetype}>({}, {name}->GetMetaStructPointer(), {}, &GetObjectInfoTable()); //@@@VCW'
                                            .format(
                                                self.get_parent_id(
                                                    value, values
                                                ),
                                                arg_name,
                                                name=value.name,
                                                basetype=value.base_type
                                            )
                                        )
                                    else:
                                        if value.base_type in self.structs_with_handle_ptrs:
                                            preexpr.append(
                                                'SetStructHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength()); //@@@AZX'
                                                .format(
                                                    value.base_type,
                                                    paramname=value.name
                                                )
                                            )
                                        postexpr.append(
                                            'AddStructHandles<Decoded_{basetype}>({}, {name}->GetMetaStructPointer(), {name}->GetOutputPointer(), &GetObjectInfoTable()); //@@@UQA'
                                            .format(
                                                self.get_parent_id(
                                                    value, values
                                                ),
                                                name=value.name,
                                                basetype=value.base_type
                                            )
                                        )
                            else:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, static_cast<{}>(0));'.format(
                                    value.base_type, paramname=value.name
                                )
                if expr:
                    preexpr.append(expr)
            elif self.is_handle(value.base_type):
                # Handles need to be mapped.
                arg_name = 'in_' + value.name
                args.append(arg_name)
                if is_override:
                    # We use auto in case the compiler can determine if the value should be const or non-const based on the override function signature.
                    expr = 'auto {} = GetObjectInfoTable().Get{}Info({});'.format(
                        arg_name, value.base_type[2:], value.name
                    )
                    preexpr.append(expr)

                    # If surface was not created, need to automatically ignore for non-overrides queries
                    # Swapchain also need to check if a dummy swapchain was created instead
                    if value.name == "surface":
                        expr = 'if ({} == nullptr || {}->surface_creation_skipped) {{ return; }}'.format(
                            arg_name,
                            arg_name
                        )
                        preexpr.append(expr)
                else:
                    expr = '{} {} = '.format(value.full_type, arg_name)
                    expr += '/*@@@QKJ*/MapHandle<{type}Info>({}, &VulkanObjectInfoTable::Get{type}Info);'.format(
                        value.name, type=value.base_type[2:]
                    )
                    preexpr.append(expr)

                    # If surface was not created, need to automatically ignore for non-overrides queries
                    # Swapchain also need to check if a dummy swapchain was created instead
                    if value.name == "surface":
                        expr = 'if (GetObjectInfoTable().GetSurfaceKHRInfo({}) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo({})->surface_creation_skipped) {{ return; }}'.format(
                            value.name,
                            value.name
                        )
                        preexpr.append(expr)
                    elif value.name == "swapchain":
                        expr = 'if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().Get{}Info({})->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().Get{}Info({})->surface_id)->surface_creation_skipped) {{ return; }}'.format(
                            value.base_type[2:], value.name,
                            value.base_type[2:], value.name
                        )
                        preexpr.append(expr)
            elif self.is_generic_cmd_handle_value(name, value.name):
                # Handles need to be mapped.
                arg_name = 'in_' + value.name
                args.append(arg_name)
                expr = '{} {} = '.format(value.full_type, arg_name)
                expr += '/*@@@REX*/MapHandle({}, {});'.format(
                    value.name,
                    self.get_generic_cmd_handle_type_value(name, value.name)
                )
                preexpr.append(expr)
            elif self.is_function_ptr(value.base_type):
                # Function pointers are encoded as a 64-bit address value.
                # TODO: Check for cases that need to be handled.
                print(
                    "WARNING: Generating replay code for a function {} with a {} parameter that is undefined."
                    .format(name, value.base_type)
                )
            else:
                # Only need to append the parameter name to the args list; no other expressions are necessary.
                args.append(value.name)

            if len(need_initialize_output_pnext_struct) > 0:
                preexpr.append('InitializeOutputStructPNext({});'.format(need_initialize_output_pnext_struct))
        return args, preexpr, postexpr

    def make_remove_handle_expression(self, name, values):
        expr = None
        if name.startswith('vkDestroy') or (name == 'vkFreeMemory'):
            # For functions starting with 'vkDestroy' and vkFreeMemory, the handle being destroyed/freed is the second parameter, except for.
            # vkDestroyInstance and vkDestroyDevice, where there is no parent object and the handle being destroyed is the first parameter.
            value = values[0] if name in [
                'vkDestroyInstance', 'vkDestroyDevice'
            ] else values[1]
            if value.base_type not in self.POOL_OBJECT_ASSOCIATIONS:
                expr = 'RemoveHandle({}, &VulkanObjectInfoTable::Remove{basetype}Info);'.format(
                    value.name, basetype=value.base_type[2:]
                )
            else:
                # Pools require special case processing to cleanup objects allocated from them.
                expr = 'RemovePoolHandle<{basetype}Info>({}, &VulkanObjectInfoTable::Get{basetype}Info, &VulkanObjectInfoTable::Remove{basetype}Info, &VulkanObjectInfoTable::Remove{}Info);'.format(
                    value.name,
                    self.POOL_OBJECT_ASSOCIATIONS[value.base_type][2:],
                    basetype=value.base_type[2:]
                )
        elif name.startswith('vkFree'):
            # For pool based vkFreeCommandBuffers and vkFreeDescriptorSets, the pool handle is the second parameter, the array count is the third parameter and the array of handles to free is the fourth parameter.
            value = values[3]
            expr = 'RemovePoolHandles<{pooltype}Info, {basetype}Info>({}, {}, {}, &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Remove{basetype}Info);'.format(
                values[1].name,
                value.name,
                values[2].name,
                basetype=value.base_type[2:],
                pooltype=self.POOL_OBJECT_ASSOCIATIONS[value.base_type][2:]
            )

        return expr

    def __load_replay_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.REPLAY_OVERRIDES = overrides['functions']
