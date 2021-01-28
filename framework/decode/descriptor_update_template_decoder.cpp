/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "decode/descriptor_update_template_decoder.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DescriptorUpdateTemplateDecoder::DescriptorUpdateTemplateDecoder() : texel_buffer_views_(nullptr) {}

DescriptorUpdateTemplateDecoder::~DescriptorUpdateTemplateDecoder() {}

size_t DescriptorUpdateTemplateDecoder::Decode(const uint8_t* buffer, size_t buffer_size)
{
    size_t bytes_read = DecodeAttributes(buffer, buffer_size);

    // The update template should identify as a struct pointer.
    assert(((GetAttributeMask() & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct) &&
           ((GetAttributeMask() & format::PointerAttributes::kIsSingle) == format::PointerAttributes::kIsSingle));

    if (!IsNull() && HasData())
    {
        // Get the total number of encoded values and allocate memory.
        bytes_read +=
            ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &image_info_count_);
        bytes_read +=
            ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &buffer_info_count_);
        bytes_read += ValueDecoder::DecodeSizeTValue(
            (buffer + bytes_read), (buffer_size - bytes_read), &texel_buffer_view_count_);
        bytes_read += ValueDecoder::DecodeSizeTValue(
            (buffer + bytes_read), (buffer_size - bytes_read), &acceleration_structure_khr_count_);

        size_t buffer_info_offset       = image_info_count_ * sizeof(VkDescriptorImageInfo);
        size_t texel_buffer_view_offset = buffer_info_offset + (buffer_info_count_ * sizeof(VkDescriptorBufferInfo));
        size_t accel_struct_offset      = texel_buffer_view_offset + (texel_buffer_view_count_ * sizeof(VkBufferView));
        size_t total_size =
            accel_struct_offset + (acceleration_structure_khr_count_ * sizeof(VkAccelerationStructureKHR));

        assert(template_memory_ == nullptr);
        template_memory_ = DecodeAllocator::Allocate<uint8_t>(total_size);

        // Read each value type.
        if (image_info_count_ > 0)
        {
            image_info_         = reinterpret_cast<VkDescriptorImageInfo*>(template_memory_);
            decoded_image_info_ = DecodeAllocator::Allocate<Decoded_VkDescriptorImageInfo>(image_info_count_);

            for (size_t i = 0; i < image_info_count_; ++i)
            {
                decoded_image_info_[i].decoded_value = &image_info_[i];
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &decoded_image_info_[i]);
            }
        }

        if (buffer_info_count_ > 0)
        {
            buffer_info_         = reinterpret_cast<VkDescriptorBufferInfo*>(template_memory_ + buffer_info_offset);
            decoded_buffer_info_ = DecodeAllocator::Allocate<Decoded_VkDescriptorBufferInfo>(buffer_info_count_);

            for (size_t i = 0; i < buffer_info_count_; ++i)
            {
                decoded_buffer_info_[i].decoded_value = &buffer_info_[i];
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), &decoded_buffer_info_[i]);
            }
        }

        if (texel_buffer_view_count_ > 0)
        {
            texel_buffer_views_ = reinterpret_cast<VkBufferView*>(template_memory_ + texel_buffer_view_offset);
            decoded_texel_buffer_view_handle_ids_ =
                DecodeAllocator::Allocate<format::HandleId>(texel_buffer_view_count_);

            ValueDecoder::DecodeHandleIdArray((buffer + bytes_read),
                                              (buffer_size - bytes_read),
                                              decoded_texel_buffer_view_handle_ids_,
                                              texel_buffer_view_count_);
        }

        if (acceleration_structure_khr_count_ > 0)
        {
            acceleration_structures_khr_ =
                reinterpret_cast<VkAccelerationStructureKHR*>(template_memory_ + accel_struct_offset);
            decoded_acceleration_structure_khr_handle_ids_ =
                DecodeAllocator::Allocate<format::HandleId>(acceleration_structure_khr_count_);

            ValueDecoder::DecodeHandleIdArray((buffer + bytes_read),
                                              (buffer_size - bytes_read),
                                              decoded_acceleration_structure_khr_handle_ids_,
                                              acceleration_structure_khr_count_);
        }
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
