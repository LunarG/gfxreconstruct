/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H
#define GFXRECON_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/pointer_decoder_base.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DescriptorUpdateTemplateDecoder : public PointerDecoderBase
{
  public:
    DescriptorUpdateTemplateDecoder();

    ~DescriptorUpdateTemplateDecoder();

    const void* GetPointer() const { return template_memory_.get(); }

    size_t GetImageInfoCount() const { return image_info_count_; }
    size_t GetBufferInfoCount() const { return buffer_info_count_; }
    size_t GetTexelBufferViewCount() const { return texel_buffer_view_count_; }

    Decoded_VkDescriptorImageInfo*  GetImageInfoMetaStructPointer() { return decoded_image_info_.get(); }
    Decoded_VkDescriptorBufferInfo* GetBufferInfoMetaStructPointer() { return decoded_buffer_info_.get(); }
    format::HandleId* GetTexelBufferViewHandleIdsPointer() { return decoded_texel_buffer_view_handle_ids_.get(); }

    const Decoded_VkDescriptorImageInfo*  GetImageInfoMetaStructPointer() const { return decoded_image_info_.get(); }
    const Decoded_VkDescriptorBufferInfo* GetBufferInfoMetaStructPointer() const { return decoded_buffer_info_.get(); }
    const format::HandleId*               GetTexelBufferViewHandleIdsPointer() const
    {
        return decoded_texel_buffer_view_handle_ids_.get();
    }

    VkDescriptorImageInfo*  GetImageInfoPointer() { return image_info_; }
    VkDescriptorBufferInfo* GetBufferInfoPointer() { return buffer_info_; }
    VkBufferView*           GetTexelBufferViewPointer() { return texel_buffer_views_; }

    const VkDescriptorImageInfo*  GetImageInfoPointer() const { return image_info_; }
    const VkDescriptorBufferInfo* GetBufferInfoPointer() const { return buffer_info_; }
    const VkBufferView*           GetTexelBufferViewPointer() const { return texel_buffer_views_; }

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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H
