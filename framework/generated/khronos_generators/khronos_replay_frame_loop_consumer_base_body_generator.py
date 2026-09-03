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

    # Create-info structs (used by REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES)
    # that embed a sub-struct BY VALUE, mapped to the name(s) of the embedding field(s),
    # differ from the common case of a field that is a *pointer* to a nested struct/array (e.g.
    # VkGraphicsPipelineCreateInfo::pStages): for a pointer field, the top-level raw_infos[0]/[i]
    # swap below only swaps the pointer *value*, so the separately-allocated nested decoder object
    # it points to correctly "follows" the swap on its own, and its own decoded_value (which
    # points into ITS OWN independently-allocated buffer) never needs to change.
    #
    # An embedded field (e.g. VkComputePipelineCreateInfo::stage, declared as
    # "VkPipelineShaderStageCreateInfo stage;" rather than a pointer) is different: at decode time
    # its nested Decoded_<SubStructType>::decoded_value is set to point directly into the
    # embedding struct's own storage (&raw_infos[<index>].stage). The raw_infos[0]/[i] swaps
    # swap the embedded storage's *content*, but does not touch the nested decoder's
    # decoded_value pointer, which still targets the pre-swap address. Left uncorrected, handle
    # mapping (e.g. MapStructHandles on the sub-struct) writes the mapped handle through that
    # stale pointer into the wrong raw_infos slot, leaving the slot actually passed to the driver
    # with an unmapped (NULL) handle -- for VkComputePipelineCreateInfo::stage specifically, an
    # incorrect NULL VkShaderModule value.
    #
    # Add an entry here for any future create-info struct in
    # REPLAY_FRAME_LOOP_RESOURCE_ALLOCATE_MULTIPLE_HANDLES_OVERRIDES that embeds a sub-struct
    # field by value; fields that are pointers do not need an entry.
    EMBEDDED_SUBSTRUCT_FIELDS = {
        'VkComputePipelineCreateInfo': ['stage'],
    }

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

            # Generates per-element create/skip logic for batched multi-handle create calls
            # (vkCreateShadersEXT, vkCreateGraphicsPipelines, vkCreateComputePipelines,
            # vkCreateRayTracingPipelinesNV, vkCreateDataGraphPipelinesARM,
            # vkCreateSharedSwapchainsKHR, and any future call with the same
            # (..., count, pCreateInfos, pAllocator, pHandles) trailing shape).
            count_param       = values[-4]
            create_info_param = values[-3]
            handles_param     = values[-1]

            count_name       = count_param.prefixed_name
            createinfo_name  = create_info_param.prefixed_name
            handles_name     = handles_param.prefixed_name

            createinfo_base_type = create_info_param.base_type   # e.g. VkShaderCreateInfoEXT
            handle_base_type     = handles_param.base_type       # e.g. VkShaderEXT
            decoded_type          = 'Decoded_{}'.format(createinfo_base_type)

            # Every parameter whose decoded array length is driven by count_param (typically
            # create_info_param and handles_param, but written generically in case a future
            # command in this override list has additional count_param-sized arrays). Each of
            # these has its own independently-tracked decoded length (GetLength()), which is
            # distinct from count_name and is NOT overridden just by reassigning count_name.
            # Process_{name}() and any code it calls may consult either count_name or a given
            # array's own GetLength() to determine how many elements to operate on, so both
            # must be restricted to a single element for the duration of the singleton call
            # below.
            length_linked_params = [
                value for value in values if value.array_length == count_param.name
            ]

            body = ''
            body += '    // Pass the call along unchanged if we are not looping.\n'
            body += '    if (!getFrameLoopInfo().IsLooping())\n'
            body += '    {\n'
            body += '        ' + self.genCallReplayConsumer(None, name, values)
            body += '        return;\n'
            body += '    }\n\n'

            body += '    format::HandleId* capture_ids = {}.GetPointerMutable();\n\n'.format(handles_name)
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

            body += '    const uint32_t original_count_value = {};\n'.format(count_name)
            for value in length_linked_params:
                body += '    const size_t original_{}_length = {}.GetLength();\n'.format(value.name, value.prefixed_name)
            body += '\n'

            embedded_substruct_fields = self.EMBEDDED_SUBSTRUCT_FIELDS.get(createinfo_base_type, [])

            body += '    for (uint32_t i : to_create)\n'
            body += '    {\n'
            body += '        format::HandleId target_capture_id = capture_ids[i];\n\n'
            body += '        // Move index i into slot 0 so Process_{}/driver code (which\n'.format(name)
            body += '        // always starts at index 0) operates on the {} we actually want.\n'.format(handle_base_type)
            body += '        std::swap(raw_infos[0], raw_infos[i]);\n'
            body += '        std::swap(meta_infos[0], meta_infos[i]);\n'
            body += '        meta_infos[0].decoded_value = &raw_infos[0];\n'
            body += '        meta_infos[i].decoded_value = &raw_infos[i];\n'
            if embedded_substruct_fields:
                body += '        // {} is a pointer to a separately-allocated Decoded_<Type>\n'.format(
                    '/'.join('meta_infos[x].{}'.format(f) for f in embedded_substruct_fields)
                )
                body += '        // with its own decoded_value pointer, set at decode time to\n'
                body += '        // &raw_infos[<original index>].{}. Swapping the outer wrapper above\n'.format(
                    embedded_substruct_fields[0]
                )
                body += '        // does not update this nested pointer, so it must be re-pointed here too, or\n'
                body += '        // handle-mapping code will write the mapped handle into the wrong raw_infos\n'
                body += '        // slot, leaving this slot\'s embedded field unset.\n'
                for field in embedded_substruct_fields:
                    body += '        meta_infos[0].{f}->decoded_value = &raw_infos[0].{f};\n'.format(f=field)
                    body += '        meta_infos[i].{f}->decoded_value = &raw_infos[i].{f};\n'.format(f=field)
            body += '        std::swap(capture_ids[0], capture_ids[i]);\n'
            body += '\n'
            body += '        // Restrict this call to a single create info/handle. Process_{}()\n'.format(name)
            body += '        // and anything it calls may consult either {} or the\n'.format(count_name)
            body += '        // independently-tracked decoded length (GetLength()) of each\n'
            body += '        // {}-sized array to determine how many entries to\n'.format(count_name)
            body += '        // process, so both must be overridden to make this call operate on\n'
            body += '        // only slot 0. Each array\'s length is restored below so that the\n'
            body += '        // full-length raw_infos/meta_infos/capture_ids arrays remain valid\n'
            body += '        // for the swap-based indexing used on the next to_create entry.\n'
            body += '        {} = 1;\n'.format(count_name)
            for value in length_linked_params:
                body += '        {}.SetLength(1);\n'.format(value.prefixed_name)
            body += '\n'
            body += '        ' + self.genCallReplayConsumer(None, name, values)
            body += '\n'
            body += '        {} = original_count_value;\n'.format(count_name)
            for value in length_linked_params:
                body += '        {}.SetLength(original_{}_length);\n'.format(value.prefixed_name, value.name)
            body += '\n'

            body += '        // {}.SetHandleLength(), called internally by Process_{}()\n'.format(handles_name, name)
            body += '        // above, (re)allocates {}\'s handle buffer to exactly {} = 1\n'.format(handles_name, count_name)
            body += '        // elements on every call, so this pointer must be re-fetched here and only\n'
            body += '        // index [0] may ever be read, so do not attempt to swap or index this array by\n'
            body += '        // anything other than 0.\n'
            body += '        {} out_handle = {}.GetHandlePointer()[0];\n'.format(handle_base_type, handles_name)
            body += '\n'
            body += '        if (out_handle != VK_NULL_HANDLE)\n'
            body += '        {\n'
            body += '            allocatedLoopResources.insert(target_capture_id);\n'
            body += '        }\n'
            body += '        else\n'
            body += '        {\n'
            body += '            GFXRECON_LOG_ERROR(\n'
            body += '                "Frame loop: failed to create {} (capture id %" PRIu64 ") during loop repetition",\n'.format(handle_base_type)
            body += '                target_capture_id);\n'
            body += '        }\n'
            body += '\n'
            body += '        // Restore original order before moving to the next index.\n'
            body += '        std::swap(capture_ids[0], capture_ids[i]);\n'
            body += '        std::swap(raw_infos[0], raw_infos[i]);\n'
            body += '        std::swap(meta_infos[0], meta_infos[i]);\n'
            body += '        meta_infos[0].decoded_value = &raw_infos[0];\n'
            body += '        meta_infos[i].decoded_value = &raw_infos[i];\n'
            for field in embedded_substruct_fields:
                body += '        meta_infos[0].{f}->decoded_value = &raw_infos[0].{f};\n'.format(f=field)
                body += '        meta_infos[i].{f}->decoded_value = &raw_infos[i].{f};\n'.format(f=field)
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
