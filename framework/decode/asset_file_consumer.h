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

#ifndef GFXRECON_DECODE_ASSET_FILE_CONSUMER_BASE_H
#define GFXRECON_DECODE_ASSET_FILE_CONSUMER_BASE_H

#include "format/format.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "util/platform.h"

#include <cstdint>
#include <map>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AssetFileConsumer : public VulkanConsumer
{
  public:
    AssetFileConsumer() : current_frame_(0)
    {
        if (util::platform::FileOpen(&debug_, "AssetFileConsumer.txt", "a"))
        {
            assert(0);
        }
    }

    virtual void ProcessFrameBeginMarker(uint64_t frame_number) override;

    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data) override;

    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void
    Process_vkUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                   format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    const format::AssetFileOffsets* GetFrameAssetFileOffsets() { return &asset_file_offsets_; }

  private:
    format::AssetFileOffsets asset_file_offsets_;
    format::FrameNumber      current_frame_;
    FILE*                    debug_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXRECON_DECODE_ASSET_FILE_CONSUMER_BASE_H
