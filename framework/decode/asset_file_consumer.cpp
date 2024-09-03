/*
** Copyright (c) 2024 Valve Corporation
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/custom_vulkan_struct_decoders.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"
#include <cstdio>
#include "asset_file_consumer.h"

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void AssetFileConsumer::ProcessFrameBeginMarker(uint64_t frame_number)
{
    current_frame_ = frame_number;

    if (!asset_file_offsets_.empty())
    {
        auto entry = asset_file_offsets_.find(frame_number);
        if (entry != asset_file_offsets_.end())
        {
            GFXRECON_LOG_ERROR("Dublicate asset file entries for frame %" PRIu64 "?", frame_number);
        }

        // Copy all entries from previous frame
        auto last_frame_entry             = asset_file_offsets_.rbegin();
        asset_file_offsets_[frame_number] = last_frame_entry->second;
    }

    fprintf(debug_, "%s() %" PRId64 "\n", __func__, frame_number);
    fsync(fileno(debug_));
}

void AssetFileConsumer::ProcessInitBufferCommand(format::HandleId device_id,
                                                 format::HandleId buffer_id,
                                                 uint64_t         data_size,
                                                 const uint8_t*   data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_id);
    GFXRECON_UNREFERENCED_PARAMETER(data_size);
    GFXRECON_UNREFERENCED_PARAMETER(data);

    format::FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
    frame_offsets[buffer_id]                     = block_header_file_offset_;
    fprintf(debug_, "buffer %" PRIu64 " -> %" PRId64 "\n", buffer_id, block_header_file_offset_);
    fsync(fileno(debug_));

    if (buffer_id > greatest_id_)
    {
        greatest_id_ = buffer_id;
    }
}

void AssetFileConsumer::ProcessInitImageCommand(format::HandleId             device_id,
                                                format::HandleId             image_id,
                                                uint64_t                     data_size,
                                                uint32_t                     aspect,
                                                uint32_t                     layout,
                                                const std::vector<uint64_t>& level_sizes,
                                                const uint8_t*               data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_id);
    GFXRECON_UNREFERENCED_PARAMETER(data_size);
    GFXRECON_UNREFERENCED_PARAMETER(aspect);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(level_sizes);
    GFXRECON_UNREFERENCED_PARAMETER(data);

    format::FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
    frame_offsets[image_id]                      = block_header_file_offset_;
    fprintf(debug_, "image %" PRIu64 " -> %" PRId64 "\n", image_id, block_header_file_offset_);
    fsync(fileno(debug_));

    if (image_id > greatest_id_)
    {
        greatest_id_ = image_id;
    }
}

void AssetFileConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(returnValue);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocateInfo);

    if (pDescriptorSets != nullptr && pDescriptorSets->GetPointer() != nullptr)
    {
        // Get only the first one
        const format::HandleId desc_id = pDescriptorSets->GetPointer()[0];

        format::FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
        frame_offsets[desc_id]                       = block_header_file_offset_;
        fprintf(debug_, "%" PRIu64 " -> %" PRId64 "\n", desc_id, block_header_file_offset_);
        fsync(fileno(debug_));

        if (desc_id > greatest_id_)
        {
            greatest_id_ = desc_id;
        }
    }
}

void AssetFileConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                                  call_info,
    format::HandleId                                    device,
    uint32_t                                            descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                            descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies)
{
    if (descriptorWriteCount && pDescriptorWrites != nullptr)
    {
        Decoded_VkWriteDescriptorSet* writes_meta = pDescriptorWrites->GetMetaStructPointer();
        if (writes_meta != nullptr)
        {
            const format::HandleId desc_id = writes_meta->dstSet;

            format::FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
            const auto                     new_entry     = frame_offsets.insert({ desc_id, block_header_file_offset_ });
            if (new_entry.second)
            {
                fprintf(debug_, "%" PRIu64 " -> %" PRId64 "\n", desc_id, block_header_file_offset_);
                fsync(fileno(debug_));
            }

            if (desc_id > greatest_id_)
            {
                greatest_id_ = desc_id;
            }
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
