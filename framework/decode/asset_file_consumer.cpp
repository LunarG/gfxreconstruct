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

    FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
    frame_offsets[buffer_id]             = block_header_file_offset_;
    fprintf(debug_, "buffer %" PRIu64 " -> %" PRId64 "\n", buffer_id, block_header_file_offset_);
    fsync(fileno(debug_));
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

    FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
    frame_offsets[image_id]              = block_header_file_offset_;
    fprintf(debug_, "image %" PRIu64 " -> %" PRId64 "\n", image_id, block_header_file_offset_);
    fsync(fileno(debug_));
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

        FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
        frame_offsets[desc_id]               = block_header_file_offset_;
        fprintf(debug_, "AllocateDescSet %" PRIu64 " -> %" PRId64 "\n", desc_id, block_header_file_offset_);
        fsync(fileno(debug_));
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

            FrameAssetFileOffsets& frame_offsets = asset_file_offsets_[current_frame_];
            const auto             new_entry     = frame_offsets.insert({ desc_id, block_header_file_offset_ });
            if (new_entry.second)
            {
                fprintf(debug_, "Update %" PRIu64 " -> %" PRId64 "\n", desc_id, block_header_file_offset_);
                fsync(fileno(debug_));
            }
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
