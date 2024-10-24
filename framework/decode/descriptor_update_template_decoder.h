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

    const void* GetPointer() const { return template_memory_; }

    size_t GetImageInfoCount() const { return image_info_count_; }
    size_t GetBufferInfoCount() const { return buffer_info_count_; }
    size_t GetTexelBufferViewCount() const { return texel_buffer_view_count_; }
    size_t GetAccelerationStructureKHRCount() const { return acceleration_structure_khr_count_; }
    size_t GetInlineUniformBlockCount() const { return inline_uniform_block_count_; }

    Decoded_VkDescriptorImageInfo*  GetImageInfoMetaStructPointer() { return decoded_image_info_; }
    Decoded_VkDescriptorBufferInfo* GetBufferInfoMetaStructPointer() { return decoded_buffer_info_; }
    format::HandleId* GetTexelBufferViewHandleIdsPointer() { return decoded_texel_buffer_view_handle_ids_; }
    format::HandleId* GetAccelerationStructureKHRHandleIdsPointer()
    {
        return decoded_acceleration_structure_khr_handle_ids_;
    }

    const Decoded_VkDescriptorImageInfo*  GetImageInfoMetaStructPointer() const { return decoded_image_info_; }
    const Decoded_VkDescriptorBufferInfo* GetBufferInfoMetaStructPointer() const { return decoded_buffer_info_; }
    const format::HandleId* GetTexelBufferViewHandleIdsPointer() const { return decoded_texel_buffer_view_handle_ids_; }
    const format::HandleId* GetAccelerationStructureKHRHandleIdsPointer() const
    {
        return decoded_acceleration_structure_khr_handle_ids_;
    }

    VkDescriptorImageInfo*      GetImageInfoPointer() { return image_info_; }
    VkDescriptorBufferInfo*     GetBufferInfoPointer() { return buffer_info_; }
    VkBufferView*               GetTexelBufferViewPointer() { return texel_buffer_views_; }
    VkAccelerationStructureKHR* GetAccelerationStructureKHRPointer() { return acceleration_structures_khr_; }
    uint8_t*                    GetInlineUniformBlockPointer() { return inline_uniform_block_; }

    const VkDescriptorImageInfo*      GetImageInfoPointer() const { return image_info_; }
    const VkDescriptorBufferInfo*     GetBufferInfoPointer() const { return buffer_info_; }
    const VkBufferView*               GetTexelBufferViewPointer() const { return texel_buffer_views_; }
    const VkAccelerationStructureKHR* GetAccelerationStructureKHRPointer() const
    {
        return acceleration_structures_khr_;
    }
    const uint8_t* GetInlineUniformBlockPointer() const { return inline_uniform_block_; }

    size_t Decode(const uint8_t* buffer, size_t buffer_size);

  private:
    uint8_t* template_memory_;

    Decoded_VkDescriptorImageInfo*  decoded_image_info_;
    Decoded_VkDescriptorBufferInfo* decoded_buffer_info_;
    format::HandleId*               decoded_texel_buffer_view_handle_ids_;
    size_t                          image_info_count_;
    size_t                          buffer_info_count_;
    size_t                          texel_buffer_view_count_;
    VkDescriptorImageInfo*          image_info_;
    VkDescriptorBufferInfo*         buffer_info_;
    VkBufferView*                   texel_buffer_views_;

    // The decode data buffer may not contain data for these fields, depending on whether they were used by the captured
    // application.
    format::HandleId*           decoded_acceleration_structure_khr_handle_ids_;
    size_t                      acceleration_structure_khr_count_;
    VkAccelerationStructureKHR* acceleration_structures_khr_;

    // inline uniform blocks
    size_t   inline_uniform_block_count_;
    uint8_t* inline_uniform_block_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DESCRIPTOR_UPDATE_TEMPLATE_DECODER_H
