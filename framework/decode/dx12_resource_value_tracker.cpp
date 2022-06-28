/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "decode/dx12_resource_value_tracker.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace /* anonymous */
{

static uint64_t GetResourceValueSize(ResourceValueType type)
{
    switch (type)
    {
        case ResourceValueType::kGpuVirtualAddress:
            return sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
        case ResourceValueType::kGpuDescriptorHandle:
            return sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr);
        case ResourceValueType::kShaderRecord:
            return D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES;
        default:
            GFXRECON_ASSERT(false && "Unrecognized resource value type.");
            return 0;
    }
}

} // namespace

void Dx12ResourceValueTracker::AddTrackedResourceValue(
    format::HandleId resource_id, ResourceValueType type, uint64_t offset, uint64_t size, uint64_t orig_value)
{
    // Using the offset, determine which fill command wrote this value.
    bool     found_fill_command_block_index = false;
    uint64_t fill_command_block_index       = 0;
    auto&    resource_fill_commands         = tracked_fill_commands_[resource_id];
    auto     iter                           = resource_fill_commands.upper_bound(offset);
    if (iter != resource_fill_commands.begin())
    {
        --iter;
        GFXRECON_ASSERT(iter->second.offset <= offset);
        if ((offset + size) <= (iter->second.offset + iter->second.size))
        {
            found_fill_command_block_index = true;
            fill_command_block_index       = iter->second.fill_command_block_index;
        }
    }

    // If the fill command block index was found, save the info that can be used to map the value during the fill
    // memory command.
    if (found_fill_command_block_index)
    {
        auto& block_resource_values = tracked_resource_values_[fill_command_block_index];

        auto original_offset = iter->second.original_offset + offset - iter->second.offset;

        // Erase any existing values that overlap with the new value.
        auto begin_iter = block_resource_values.lower_bound(original_offset);
        if (begin_iter != block_resource_values.begin())
        {
            // Erase the value at the previous offset if its size overlaps with the current offset.
            --begin_iter;
            auto begin_iter_offset = begin_iter->first;
            auto begin_iter_size   = GetResourceValueSize(begin_iter->second.type);
            if (original_offset >= (begin_iter_offset + begin_iter_size))
            {
                ++begin_iter;
            }
        }
        auto end_iter = block_resource_values.lower_bound(original_offset + size);
        if (begin_iter != end_iter)
        {
            block_resource_values.erase(begin_iter, end_iter);
        }

        // Insert the new value.
        block_resource_values[original_offset].type  = type;
        block_resource_values[original_offset].value = orig_value;
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE("Failed to find the fill memory command associated with resource data that required "
                                "mapping for replay. Tracked resource values may be incorrect.");
    }
}

void Dx12ResourceValueTracker::PostProcessExecuteCommandLists(
    DxObjectInfo*                             command_queue_object_info,
    UINT                                      num_command_lists,
    HandlePointerDecoder<ID3D12CommandList*>* command_lists_decoder)
{
    auto command_queue_extra_info = GetExtraInfo<D3D12CommandQueueInfo>(command_queue_object_info);

    GFXRECON_ASSERT(command_queue_extra_info != nullptr);

    auto& pending_events = command_queue_extra_info->pending_events;

    ProcessExecuteCommandListArgs process_args{};

    for (UINT i = 0; i < num_command_lists; ++i)
    {
        auto command_list_extra_info =
            GetExtraInfo<D3D12CommandListInfo>(get_object_info_func_(command_lists_decoder->GetPointer()[i]));
        GFXRECON_ASSERT(command_list_extra_info != nullptr);

        process_args.resource_copies.insert(process_args.resource_copies.end(),
                                            command_list_extra_info->resource_copies.begin(),
                                            command_list_extra_info->resource_copies.end());
    }

    if (!process_args.resource_copies.empty())
    {
        // Run (or queue) resource value mapping process.
        if (pending_events.empty())
        {
            ProcessExecuteCommandList(std::move(process_args));
        }
        else
        {
            command_queue_extra_info->pending_events.push_back(
                CreateProcessExecuteCommandListSyncEvent(std::move(process_args)));
        }
    }
}

void Dx12ResourceValueTracker::PostProcessFillMemoryCommand(uint64_t resource_id,
                                                            uint64_t offset,
                                                            uint64_t size,
                                                            uint64_t block_index)
{
    TrackedFillCommandInfo tracked_fill_command;
    tracked_fill_command.fill_command_block_index = block_index;
    tracked_fill_command.original_offset          = offset;
    tracked_fill_command.offset                   = offset;
    tracked_fill_command.size                     = size;
    UpdateFillCommandState(resource_id, tracked_fill_command);
}

void Dx12ResourceValueTracker::UpdateFillCommandState(format::HandleId              resource_id,
                                                      const TrackedFillCommandInfo& new_fill_command)
{
    auto& resource_fill_commands = tracked_fill_commands_[resource_id];

    auto new_fill_cmd_begin = new_fill_command.offset;
    auto new_fill_cmd_end   = new_fill_cmd_begin + new_fill_command.size;

    // Find previous fill commands that overlap with the new fill command.
    auto begin_iter = resource_fill_commands.lower_bound(new_fill_cmd_begin);
    if (begin_iter != resource_fill_commands.begin())
    {
        --begin_iter;
        auto begin_iter_offset = begin_iter->first;
        auto begin_iter_size   = begin_iter->second.size;
        if (new_fill_cmd_begin >= (begin_iter_offset + begin_iter_size))
        {
            ++begin_iter;
        }
    }
    auto end_iter = resource_fill_commands.lower_bound(new_fill_cmd_end);

    // Fixup/erase overlapping fill commands.
    auto iter = begin_iter;
    while (iter != end_iter)
    {
        TrackedFillCommandInfo existing_fill_cmd = iter->second;
        resource_fill_commands.erase(iter++);

        // If the new fill command only partially overwrote existing commands, add new fill commands back into the map.
        auto existing_fill_cmd_begin = existing_fill_cmd.offset;
        auto existing_fill_cmd_end   = existing_fill_cmd_begin + existing_fill_cmd.size;
        if (new_fill_cmd_begin > existing_fill_cmd_begin)
        {
            TrackedFillCommandInfo fill_cmd         = existing_fill_cmd;
            fill_cmd.size                           = new_fill_cmd_begin - existing_fill_cmd_begin;
            resource_fill_commands[fill_cmd.offset] = fill_cmd;
        }
        if (new_fill_cmd_end < existing_fill_cmd_end)
        {
            TrackedFillCommandInfo fill_cmd = existing_fill_cmd;
            fill_cmd.offset                 = new_fill_cmd_end;
            fill_cmd.original_offset += new_fill_cmd_end - existing_fill_cmd_begin;
            fill_cmd.size                           = existing_fill_cmd_end - new_fill_cmd_end;
            resource_fill_commands[fill_cmd.offset] = fill_cmd;
        }
    }

    // Add the new command.
    resource_fill_commands[new_fill_command.offset] = new_fill_command;
}

void Dx12ResourceValueTracker::ProcessExecuteCommandList(ProcessExecuteCommandListArgs args)
{
    for (auto& copy : args.resource_copies)
    {
        const auto& src_tracked_fill_commands = tracked_fill_commands_[copy.src_resource_object_info->capture_id];

        auto begin_iter = src_tracked_fill_commands.begin();
        auto end_iter   = src_tracked_fill_commands.end();

        if (copy.num_bytes != 0)
        {
            // If this was a partial resource copy (CopyBufferRegion), only apply sub range of fill commands from src.
            begin_iter = src_tracked_fill_commands.lower_bound(copy.src_offset);
            if (begin_iter != src_tracked_fill_commands.begin())
            {
                --begin_iter;
                if (copy.src_offset >= (begin_iter->first + begin_iter->second.size))
                {
                    ++begin_iter;
                }
            }
            end_iter = src_tracked_fill_commands.lower_bound(copy.src_offset + copy.num_bytes);
        }
        else
        {
            // If this was a full copy, fill in num_bytes struct value.
            auto resource_size = static_cast<ID3D12Resource*>(copy.dst_resource_object_info->object)->GetDesc().Width;
            copy.num_bytes     = resource_size;
        }

        // Update tracked fill commands on dst.
        for (; begin_iter != end_iter; ++begin_iter)
        {
            auto& src_fill_command = begin_iter->second;

            TrackedFillCommandInfo dst_fill_command;
            dst_fill_command.fill_command_block_index = src_fill_command.fill_command_block_index;

            uint64_t original_offset_delta = 0;
            uint64_t dest_offset_delta     = 0;
            if (copy.src_offset >= src_fill_command.offset)
            {
                original_offset_delta = copy.src_offset - src_fill_command.offset;
            }
            else
            {
                dest_offset_delta = src_fill_command.offset - copy.src_offset;
            }

            dst_fill_command.original_offset = src_fill_command.original_offset + original_offset_delta;
            dst_fill_command.offset          = copy.dst_offset + dest_offset_delta;
            dst_fill_command.size =
                std::min(copy.num_bytes - dest_offset_delta, src_fill_command.size - original_offset_delta);

            UpdateFillCommandState(copy.dst_resource_object_info->capture_id, dst_fill_command);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
