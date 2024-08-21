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

#include <algorithm>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12ResourceValueTracker::GetTrackedResourceValues(Dx12FillCommandResourceValueMap& tracked_values)
{
    tracked_values = std::move(tracked_resource_values_);
    tracked_resource_values_.clear();
}

bool Dx12ResourceValueTracker::AddTrackedResourceValue(format::HandleId              resource_id,
                                                       ResourceValueType             type,
                                                       uint64_t                      offset,
                                                       const uint8_t*                resource_value_data,
                                                       const graphics::Dx12GpuVaMap& gpu_va_map)
{
    // Using the offset, determine which fill command wrote this value.
    bool     found_fill_command_block_index = false;
    uint64_t fill_command_block_index       = 0;
    uint64_t fill_command_offset            = 0;
    auto&    resource_fill_commands         = tracked_fill_commands_[resource_id];
    auto     size                           = GetResourceValueSize(type);

    {
        // `resource_fill_commands.upper_bound(offset + size)` finds the first iter past the end of the added tracked
        // value. Check whether the previous iter's fill command contained the added value.
        auto iter = resource_fill_commands.lower_bound(offset + size);
        if (iter != resource_fill_commands.begin())
        {
            --iter;
        }
        if ((iter != resource_fill_commands.end()) && ((offset + size) <= (iter->second.offset + iter->second.size)))
        {
            // If the value was written by a single fill command.
            if (offset >= iter->second.offset)
            {
                // If the data was originally written by an init subresource command (used during trimmed resource state
                // load), then check whether the incoming resource value matches the source data value.
                bool mismatch_init_subresource_data = false;
                if ((iter->second.init_subresource_data != nullptr) && (!iter->second.init_subresource_data->empty()))
                {
                    auto data_offset_u64 = iter->second.original_offset + offset - iter->second.offset;
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_offset_u64);
                    auto data_offset = static_cast<size_t>(data_offset_u64);
                    auto value_size  = GetResourceValueSize(type);
                    for (size_t i = 0; i < value_size; ++i)
                    {
                        mismatch_init_subresource_data =
                            mismatch_init_subresource_data ||
                            ((*iter->second.init_subresource_data)[data_offset + i] != resource_value_data[i]);
                    }
                }

                if (!mismatch_init_subresource_data)
                {
                    found_fill_command_block_index = true;
                    fill_command_block_index       = iter->second.fill_command_block_index;
                    fill_command_offset            = iter->second.original_offset + offset - iter->second.offset;
                }
            }
            // Else the value may have been written by multiple fill commands.
            else
            {
                // It is possible that a value was written by multiple fill commands. In this case, use the most recent
                // fill command to do the mapping.
                while (offset < (iter->second.offset + iter->second.size))
                {
                    if (iter->second.fill_command_block_index >= fill_command_block_index)
                    {
                        found_fill_command_block_index = true;
                        fill_command_block_index       = iter->second.fill_command_block_index;
                        fill_command_offset            = iter->second.original_offset + offset - iter->second.offset;
                    }

                    // Get next iter.
                    if (iter != resource_fill_commands.begin())
                    {
                        // Break if the fill commands don't cover the full value.
                        auto next_iter = iter;
                        --next_iter;
                        if ((next_iter->second.offset + next_iter->second.size) == iter->second.offset)
                        {
                            iter = next_iter;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        // Break once we've reached the beginning.
                        break;
                    }
                }
            }
        }
    }

    // If the fill command block index was found, save the info that can be used to map the value during the fill
    // memory command.
    if (found_fill_command_block_index)
    {
        AddBlockResourceValue(fill_command_block_index, fill_command_offset, type);
        return true;
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE(
            "Failed to find the required data for DXR optimization. The optimized result may be invalid.");
        return false;
    }
}

void Dx12ResourceValueTracker::AddBlockResourceValue(uint64_t          fill_command_block_index,
                                                     uint64_t          fill_command_offset,
                                                     ResourceValueType type)
{
    auto& block_resource_values = tracked_resource_values_[fill_command_block_index];

    // Find the insert position sorted by fill_command_offset, erasing any existing values that overlap with
    // the new value.
    auto iter = std::upper_bound(
        block_resource_values.begin(),
        block_resource_values.end(),
        fill_command_offset,
        [](uint64_t offset, const auto& val) { return offset < (val.offset + GetResourceValueSize(val.type)); });
    auto insert_iter = block_resource_values.end();
    bool do_insert   = true;
    if (iter != block_resource_values.end())
    {
        if ((iter->offset != fill_command_offset) || (iter->type != type))
        {
            bool erase_prev = false;
            bool erase_next = false;

            if ((fill_command_offset >= iter->offset) &&
                (fill_command_offset < (iter->offset + GetResourceValueSize(iter->type))))
            {
                erase_prev = true;
            }

            auto next_iter = iter + 1;
            while ((next_iter != block_resource_values.end()) &&
                   (next_iter->offset < (fill_command_offset + GetResourceValueSize(type))))
            {
                erase_next = true;
                ++next_iter;
            }

            if (erase_prev || erase_next)
            {
                auto erase_begin = erase_prev ? iter : iter + 1;
                auto erase_end   = next_iter;
                insert_iter      = block_resource_values.erase(erase_begin, erase_end);
            }
            else
            {
                insert_iter = iter;
            }
        }
        else
        {
            // Same element. Nothing will be changed.
            do_insert = false;
        }
    }

    if (do_insert)
    {
        // Insert the new value at the sorted position.
        block_resource_values.insert(insert_iter, { fill_command_offset, type });
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
        auto command_list_id         = command_lists_decoder->GetPointer()[i];
        auto command_list_extra_info = GetExtraInfo<D3D12CommandListInfo>(get_object_info_func_(command_list_id));
        GFXRECON_ASSERT(command_list_extra_info != nullptr);

        process_args.resource_copies.insert(process_args.resource_copies.end(),
                                            command_list_extra_info->resource_copies.begin(),
                                            command_list_extra_info->resource_copies.end());
    }

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

void Dx12ResourceValueTracker::PostProcessFillMemoryCommand(uint64_t       resource_id,
                                                            uint64_t       offset,
                                                            uint64_t       size,
                                                            const uint8_t* data)
{
    TrackedFillCommandInfo tracked_fill_command;
    tracked_fill_command.fill_command_block_index = get_current_block_index_func_();
    tracked_fill_command.original_offset          = offset;
    tracked_fill_command.offset                   = offset;
    tracked_fill_command.size                     = size;
    UpdateFillCommandState(resource_id, tracked_fill_command);
}

void Dx12ResourceValueTracker::PostProcessInitSubresourceCommand(
    ID3D12Resource* resource, const format::InitSubresourceCommandHeader& command_header, const uint8_t* data)
{
    GFXRECON_ASSERT(resource != nullptr);

    // Only support buffer resources.
    if (resource->GetDesc().Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        // Buffer resources only have subresource 0.
        GFXRECON_ASSERT(command_header.subresource == 0);

        TrackedFillCommandInfo tracked_fill_command;
        tracked_fill_command.fill_command_block_index = get_current_block_index_func_();
        tracked_fill_command.original_offset          = 0;
        tracked_fill_command.offset                   = 0;
        tracked_fill_command.size                     = command_header.data_size;
        tracked_fill_command.init_subresource_data =
            std::make_shared<std::vector<uint8_t>>(std::vector<uint8_t>(data, data + command_header.data_size));
        UpdateFillCommandState(command_header.resource_id, tracked_fill_command);
    }
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
    // Process command list copies.
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
