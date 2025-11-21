/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

DescriptorUpdateTemplateDecoder::DescriptorUpdateTemplateDecoder() :
    template_memory_(nullptr), decoded_image_info_(nullptr), decoded_buffer_info_(nullptr),
    decoded_texel_buffer_view_handle_ids_(nullptr), image_info_count_(0), buffer_info_count_(0),
    texel_buffer_view_count_(0), image_info_(nullptr), buffer_info_(nullptr), texel_buffer_views_(nullptr),
    decoded_acceleration_structure_khr_handle_ids_(nullptr), acceleration_structure_khr_count_(0),
    acceleration_structures_khr_(nullptr), inline_uniform_block_count_(0), inline_uniform_block_(nullptr)
{}

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

        // Offsets of the various result structures in the allocated block that is used to store the decoded
        // descriptor template information.
        const size_t buffer_info_offset = image_info_count_ * sizeof(VkDescriptorImageInfo);
        const size_t texel_buffer_view_offset =
            buffer_info_offset + (buffer_info_count_ * sizeof(VkDescriptorBufferInfo));
        size_t total_size = texel_buffer_view_offset + (texel_buffer_view_count_ * sizeof(VkBufferView));

        // Calculate how many bytes we will read for obligatory information.
        //   - Image descriptors are composed of 2 handle IDs and an enum
        //       (see "DecodeStruct" for Decoded_VkDescriptorBufferInfo in generated_custom_vulkan_struct_decoders.cpp)
        //   - Buffer descriptors are composed of 1 handle ID and 2 sizes
        //       (see "DecodeStruct" for Decoded_VkDescriptorImageInfo in custom_vulkan_struct_decoder.cpp)
        //   - Texture descriptors are composed of 1 handle ID (for the VkBufferView)
        size_t bytes_to_read = image_info_count_ * ((sizeof(format::HandleId) * 2) + sizeof(format::EnumEncodeType));
        bytes_to_read += buffer_info_count_ * (sizeof(format::HandleId) + (2 * sizeof(format::DeviceSizeEncodeType)));
        bytes_to_read += texel_buffer_view_count_ * sizeof(format::HandleId);

        // If there is room still left, then it indicates that there might be optional descriptor types in the capture
        // file.  It is easier to look forward now and calculate all the memory that is needed to allocate the storage
        // memory for all the descriptor templates.
        struct OptionalDescriptorInfo
        {
            VkDescriptorType type;
            size_t           offset;
            size_t           count;
        };
        std::vector<OptionalDescriptorInfo> optional_info{};
        while ((bytes_read + bytes_to_read) < buffer_size)
        {
            // Calculate the size of the optional data and make sure we don't exceed
            const size_t optional_start             = bytes_read + bytes_to_read;
            size_t       required_alloc_memory_size = 0;
            size_t       required_read_memory_size  = 0;
            size_t       optional_data_count        = 0;
            size_t       optional_read_len          = ValueDecoder::DecodeSizeTValue(
                (buffer + optional_start), (buffer_size - optional_start), &optional_data_count);
            if (optional_start + optional_read_len == buffer_size)
            {
                optional_data_count = 0;
                // A few captures in the wild were written with an uninitialized
                // struct_count and no additional bytes. Commit 7d190ac9 fixed the encoding format.
                GFXRECON_LOG_WARNING_ONCE(
                    "A deprecated incorrect encoding of DescriptorUpdateTemplate was detected.  This "
                    "capture is probably invalid.  Replay may subsequently fail or crash.");
                break;
            }
            else if (optional_data_count > 0)
            {
                OptionalDescriptorInfo cur_type{};
                cur_type.count = optional_data_count;

                const size_t offset_to_type = optional_start + optional_read_len;
                optional_read_len += ValueDecoder::DecodeEnumValue(
                    (buffer + offset_to_type), (buffer_size - offset_to_type), &cur_type.type);
                bool invalid_optional_desc = false;
                switch (cur_type.type)
                {
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        // The start of the data in the allocated block will be at the end of all the
                        // previous data.
                        cur_type.offset = total_size;

                        // We will read HandleIds but produce VkAccelerationStructureKHR in the allocated
                        // memory block.  They should be the same, but just make sure that the calculations
                        // are correct.
                        required_read_memory_size  = sizeof(format::HandleId) * cur_type.count;
                        required_alloc_memory_size = sizeof(VkAccelerationStructureKHR) * cur_type.count;
                        break;
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        cur_type.offset  = total_size;
                        size_t num_bytes = cur_type.count;

                        // We will read/write raw bytes in the allocated memory block, they should be the same
                        required_read_memory_size  = num_bytes;
                        required_alloc_memory_size = num_bytes;
                        break;
                    }
                    default:
                        invalid_optional_desc = true;
                        // If descriptor_type is not recognized, it is possible the capture file was created with a
                        // newer version of the capture layer that had support for additional optional descriptor types.
                        // Display a warning and exit the processing loop.
                        GFXRECON_LOG_ERROR_ONCE(
                            "Unrecognized VkDescriptorType %d found when decoding data for descriptor "
                            "update with template.",
                            static_cast<int>(cur_type.type));
                        break;
                }

                if (invalid_optional_desc)
                {
                    // We can not continue because we don't know how large the actual unknown block is.
                    break;
                }

                // Update the total size of what we need to allocate
                total_size += required_alloc_memory_size;

                // Update the bytes to read to include this block of data so we can get to the next block.
                bytes_to_read += optional_read_len + required_read_memory_size;

                // Save the new optional info to the end of the vector so it stays in order
                optional_info.push_back(cur_type);
            }
        }

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

            bytes_read += ValueDecoder::DecodeHandleIdArray((buffer + bytes_read),
                                                            (buffer_size - bytes_read),
                                                            decoded_texel_buffer_view_handle_ids_,
                                                            texel_buffer_view_count_);
        }

        // If we discovered valid optional descriptor types after the standard ones, handle them appropriately.
        // They have to be in order because if the above code hits an invalid one, it and anything after
        // the invalid block will not be appended to the vector.
        for (auto& cur_type : optional_info)
        {
            // Read the descriptor count and type again and verify it matches what was pre-read.
            // This is just to make sure the previous read actual read the data properly.
            size_t current_count = 0;
            bytes_read +=
                ValueDecoder::DecodeSizeTValue((buffer + bytes_read), (buffer_size - bytes_read), &current_count);
            VkDescriptorType current_descriptor_type;
            bytes_read += ValueDecoder::DecodeEnumValue(
                (buffer + bytes_read), (buffer_size - bytes_read), &current_descriptor_type);
            assert(current_count == cur_type.count);
            assert(current_descriptor_type == cur_type.type);

            switch (cur_type.type)
            {
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                {
                    // Just double check that we haven't already created an acceleration struct section
                    assert(acceleration_structure_khr_count_ == 0);

                    acceleration_structure_khr_count_ = cur_type.count;
                    acceleration_structures_khr_ =
                        reinterpret_cast<VkAccelerationStructureKHR*>(template_memory_ + cur_type.offset);
                    decoded_acceleration_structure_khr_handle_ids_ =
                        DecodeAllocator::Allocate<format::HandleId>(acceleration_structure_khr_count_);

                    bytes_read += ValueDecoder::DecodeHandleIdArray((buffer + bytes_read),
                                                                    (buffer_size - bytes_read),
                                                                    decoded_acceleration_structure_khr_handle_ids_,
                                                                    acceleration_structure_khr_count_);
                    break;
                }
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                {
                    // double check that we haven't already created an inline-uniform-block section
                    assert(inline_uniform_block_count_ == 0);
                    inline_uniform_block_count_ = cur_type.count;
                    inline_uniform_block_       = template_memory_ + cur_type.offset;

                    bytes_read += ValueDecoder::DecodeUInt8Array((buffer + bytes_read),
                                                                 (buffer_size - bytes_read),
                                                                 inline_uniform_block_,
                                                                 inline_uniform_block_count_);
                    break;
                }
                default:
                    // This should only trigger if someone added a type to the above while loop and not down here.
                    assert(false);
                    break;
            }
        }
    }
    assert(bytes_read <= buffer_size);
    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
