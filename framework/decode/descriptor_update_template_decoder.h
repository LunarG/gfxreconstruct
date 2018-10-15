/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H
#define BRIMSTONE_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H

#include <memory>

#include "util/defines.h"
#include "decode/pointer_decoder_base.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

class DescriptorUpdateTemplateDecoder : public PointerDecoderBase
{
  public:
    DescriptorUpdateTemplateDecoder();

    ~DescriptorUpdateTemplateDecoder();

    const void* GetPointer() const { return template_memory_.get(); }

    size_t GetImageInfoCount() const { return image_info_count_; }
    size_t GetBufferInfoCount() const { return buffer_info_count_; }
    size_t GetTexelBufferViewCount() const { return texel_buffer_view_count_; }

    const Decoded_VkDescriptorImageInfo*  GetImageInfoMetaStructPointer() const { return decoded_image_info_.get(); }
    const Decoded_VkDescriptorBufferInfo* GetBufferInfoMetaStructPointer() const { return decoded_buffer_info_.get(); }
    const format::HandleId*               GetTexelBufferViewHandleIdsPointer() const
    {
        return decoded_texel_buffer_view_handle_ids_.get();
    }

    VkDescriptorImageInfo*  GetImageInfoPointer() const { return image_info_; }
    VkDescriptorBufferInfo* GetBufferInfoPointer() const { return buffer_info_; }
    VkBufferView*           GetTexelBufferViewPointer() const { return texel_buffer_views_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size);

  private:
    std::unique_ptr<uint8_t[]>                        template_memory_;
    std::unique_ptr<Decoded_VkDescriptorImageInfo[]>  decoded_image_info_;
    std::unique_ptr<Decoded_VkDescriptorBufferInfo[]> decoded_buffer_info_;
    std::unique_ptr<format::HandleId[]>               decoded_texel_buffer_view_handle_ids_;
    size_t                                            image_info_count_;
    size_t                                            buffer_info_count_;
    size_t                                            texel_buffer_view_count_;
    VkDescriptorImageInfo*                            image_info_;
    VkDescriptorBufferInfo*                           buffer_info_;
    VkBufferView*                                     texel_buffer_views_;
};

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H
