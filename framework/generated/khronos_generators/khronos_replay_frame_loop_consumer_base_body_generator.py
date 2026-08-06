#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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

from khronos_base_generator import write

class KhronosReplayFrameLoopConsumerBaseBodyGenerator():
    """Base class for generating replay frame loop consumers body code."""

    def skip_generating_command(self, command):
        return (command not in
                (self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_SINGLE_HANDLE_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_FREE_SINGLE_HANDLE_OVERRIDES +
                 self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_NOT_FULLY_IMPLEMENTED +
                 self.REPLAY_FRAME_LOOP_RESOURCE_FREE_NOT_FULLY_IMPLEMENTED))

    def genCallReplayConsumer(self, return_type, name, values):
        return f'{self.platform_type}ReplayConsumer::Process_{name}(call_info, args);\n'

    def make_replay_frame_loop_consumer_func_body(self, api_data, return_type, name, values):

        body = ''

        if name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_SINGLE_HANDLE_OVERRIDES:

            body += '    // Check for null cases\n'
            body += '    if (' + values[-1].prefixed_name + '.IsNull())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    format::HandleId handle = *' + values[-1].prefixed_name + '.GetPointer();\n\n'
            body += '    // Pass the call along if we are not looping or\n'
            body += '    // if we are looping and the handle is not in allocatedLoopResources\n'
            body += '    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))\n'
            body += '    {\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '        // If we are looping, save the handle in allocatedLoopResources\n'
            body += '        if (getFrameLoopInfo().IsLooping())\n'
            body += '        {\n'
            body += '            allocatedLoopResources.insert(handle);\n'
            body += '        }\n'
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES:

            """Generates per-element create/skip logic for batched multi-handle create calls
            (vkCreateShadersEXT, vkCreateGraphicsPipelines, vkCreateComputePipelines,
            vkCreateRayTracingPipelinesNV, vkCreateDataGraphPipelinesARM,
            vkCreateSharedSwapchainsKHR, and any future call with the same
            (..., count, pCreateInfos, pAllocator, pHandles) trailing shape).
            """
            base_name         = name[2:]
            count_param       = values[-4]
            create_info_param = values[-3]
            handles_param     = values[-1]

            # Any parameters between the device handle and the count are extra
            # "companion" handles that the Override function needs looked up
            # in the object info table (e.g. VkPipelineCache, VkDeferredOperationKHR).
            # Discovering them positionally means this code keeps working for any
            # future *CreateXxx(device, ..., count, pCreateInfos, pAllocator, pHandles)
            # entry point without needing to special-case it by name below.
            extra_params = values[1:-4]

            count_name       = count_param.prefixed_name
            createinfo_name  = create_info_param.prefixed_name
            handles_name     = handles_param.prefixed_name

            createinfo_base_type = create_info_param.base_type   # e.g. VkShaderCreateInfoEXT
            handle_base_type     = handles_param.base_type       # e.g. VkShaderEXT
            decoded_type          = 'Decoded_{}'.format(createinfo_base_type)
            info_type = '{}{}Info'.format(
                self.get_api_prefix_from_type(handle_base_type), handle_base_type[2:]
            )

            body = ''
            body += '    // Pass the call along unchanged if we are not looping.\n'
            body += '    if (!getFrameLoopInfo().IsLooping())\n'
            body += '    {\n'
            body += '        ' + self.genCallReplayConsumer(None, name, values)
            body += '        return;\n'
            body += '    }\n\n'

            body += '    const format::HandleId* capture_ids = {}.GetPointer();\n\n'.format(handles_name)
            body += '    std::vector<uint32_t> to_create;\n'
            body += '    for (uint32_t i = 0; i < {}; ++i)\n'.format(count_name)
            body += '    {\n'
            body += '        if (!allocatedLoopResources.contains(capture_ids[i]))\n'
            body += '        {\n'
            body += '            to_create.push_back(i);\n'
            body += '        }\n'
            body += '    }\n\n'

            body += '    if (to_create.empty())\n'
            body += '    {\n'
            body += '        // Every handle in this batch already exists from an earlier loop iteration.\n'
            body += '        return;\n'
            body += '    }\n\n'

            body += '    if (to_create.size() == {})\n'.format(count_name)
            body += '    {\n'
            body += '        // Nothing pre-exists; take the normal batched path.\n'
            body += '        ' + self.genCallReplayConsumer(None, name, values) + '\n'
            body += '        for (uint32_t i = 0; i < {}; ++i)\n'.format(count_name)
            body += '        {\n'
            body += '            allocatedLoopResources.insert(capture_ids[i]);\n'
            body += '        }\n'
            body += '        return;\n'
            body += '    }\n\n'

            body += '    // Mixed case: some handles in this batch already exist, others do not.\n'
            body += '    {}* raw_infos  = {}.GetPointer();\n'.format(createinfo_base_type, createinfo_name)
            body += '    {}* meta_infos = {}.GetMetaStructPointer();\n\n'.format(decoded_type, createinfo_name)
            body += '    auto*   device_info = GetObjectInfoTable().GetVkDeviceInfo(args.device);\n'
            body += '    VkDevice in_device  = device_info->handle;\n'
            body += '    for (uint32_t i : to_create)\n'
            body += '    {\n'
            body += '        // Move index i into slot 0 so Override/driver code (which always\n'
            body += '        // starts at index 0) operates on the shader we actually want.\n'
            body += '        std::swap(raw_infos[0], raw_infos[i]);\n'
            body += '        std::swap(meta_infos[0], meta_infos[i]);\n'
            body += '        meta_infos[0].decoded_value = &raw_infos[0];\n'
            body += '        meta_infos[i].decoded_value = &raw_infos[i];\n'
            body += '        {}.SetHandleLength(1);   // (re)allocate a 1-element output slot\n'.format(handles_name)
            body += '\n'
            body += '         VkResult replay_result = Override{}(\n'.format(base_name)
            body += '                                            GetDeviceTable(in_device)->{},\n'.format(base_name)
            body += '                                            args.result,\n'
            body += '                                            device_info,\n'
            for extra_param in extra_params:
                body += '                                            GetObjectInfoTable().Get{}Info({}),\n'.format(
                    extra_param.base_type, extra_param.prefixed_name)
            body += '                                            1,\n'
            body += '                                            &args.pCreateInfos,\n'
            body += '                                            &args.pAllocator,\n'
            body += '                                            &{});\n'.format(handles_name)
            body += '\n'
            body += '        {} out_handle = {}.GetHandlePointer()[0];\n'.format(handle_base_type, handles_name)
            body += '\n'
            body += '        if (replay_result == VK_SUCCESS)\n'
            body += '        {\n'
            body += '            AddHandle<{}>(\n'.format(info_type)
            body += '                args.device, &capture_ids[i], &out_handle, &CommonObjectInfoTable::Add{}Info);\n'.format(handle_base_type)
            body += '            allocatedLoopResources.insert(capture_ids[i]);\n'
            body += '        }\n'
            body += '        else\n'
            body += '        {\n'
            body += '            GFXRECON_LOG_ERROR(\n'
            body += '                "Frame loop: failed to create {} (capture id %" PRIu64 ") during loop repetition, VkResult = %d",\n'.format(handle_base_type)
            body += '                capture_ids[i], replay_result);\n'
            body += '        }\n'
            body += '\n'
            body += '        // Restore original order before moving to the next index.\n'
            body += '        std::swap(raw_infos[0], raw_infos[i]);\n'
            body += '        std::swap(meta_infos[0], meta_infos[i]);\n'
            body += '        meta_infos[0].decoded_value = &raw_infos[0];\n'
            body += '        meta_infos[i].decoded_value = &raw_infos[i];\n'
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_SINGLE_HANDLE_OVERRIDES:

            body += '    // Skip for loop iterations 1-(n-1).\n'
            body += '    // Skip if looping and if not final iteration\n'
            body += '    // Execute if ' + values[-2].prefixed_name + ' is in allocatedLoopResources\n\n'
            body += '    // Call Process_' + name + ' if:\n'
            body += '    //    We are not looping\n'
            body += '    //    We are looping and ' + values[-2].prefixed_name + ' is in allocatedLoopResources\n'
            body += '    //    We are looping and this is the last iteration\n'

            body += '    if (!getFrameLoopInfo().IsLooping())\n'
            body += '    {\n'
            body += '        GFXRECON_ASSERT(!allocatedLoopResources.contains(' + values[-2].prefixed_name + '))\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '    }\n'
            body += '    else if (allocatedLoopResources.contains(' + values[-2].prefixed_name + '))\n'
            body += '    {\n'
            body += '        // Looping special case:\n'
            body += '        // This resource has been allocated WITHIN the loop range.\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '        allocatedLoopResources.erase(' + values[-2].prefixed_name + ');\n'
            body += '    }\n'
            body += '    else if (getFrameLoopInfo().IsFinalIteration())\n'
            body += '    {\n'
            body += '        // Looping special case:\n'
            body += '        // This resource has been allocated BEFORE the loop range.\n'
            body += '        // Since it might still be in use during the loop range, ONLY free it in the last iteration.\n'
            body += '        ' + self.genCallReplayConsumer(return_type, name, values)
            body += '    }\n'

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_NOT_FULLY_IMPLEMENTED:

            body += '    // Not fully implemented yet.\n'
            body += '    // Return if not the first time through loop\n'
            body += '    if (getFrameLoopInfo().IsRepetition())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    ' + self.genCallReplayConsumer(return_type, name, values)

        elif name in self.REPLAY_FRAME_LOOP_RESOURCE_FREE_NOT_FULLY_IMPLEMENTED:

            body += '    // Not fully implemented yet.\n'
            body += '    // Return if looping and we are not executing the last iteration.\n'
            body += '    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())\n'
            body += '    {\n'
            body += '        return;\n'
            body += '    }\n'
            body += '    ' + self.genCallReplayConsumer(return_type, name, values)

        else:
            assert False, "Bad function name in make_replay_frame_loop_consumer_func_body"

        return body


    def generate_replay_frame_loop_consumer_content(self, api_data):
        """Performs C++ code generation for the replay frame loop consumer."""
        self.platform_type = api_data.api_class_prefix

        self.newline()

        for cmd in self.get_all_filtered_cmd_names():

            if self.skip_generating_command(cmd):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '\n'
            cmddef += self.make_consumer_func_decl(
                        return_type,
                        '{}ReplayFrameLoopConsumerBase::Process_'.format(self.platform_type) + cmd,
                        values
                        ) + '\n'
            cmddef += '{\n'
            cmddef += self.make_replay_frame_loop_consumer_func_body(api_data, return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
