/*
** Copyright (c) 2018 Valve Corporation
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

#ifndef GFXRECON_DECODE_STRUCT_POINTER_DECODER_NVX_H
#define GFXRECON_DECODE_STRUCT_POINTER_DECODER_NVX_H

#include "decode/struct_pointer_decoder.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/pointer_decoder_base.h"
#include "decode/value_decoder.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <>
class StructPointerDecoder<Decoded_VkObjectTableEntryNVX> : public PointerDecoderBase
{
  public:
    StructPointerDecoder() {}

    virtual ~StructPointerDecoder() override
    {
        if (struct_memory_ != nullptr)
        {
            for (size_t i = 0; i < GetLength(); ++i)
            {
                if (struct_memory_[i] != nullptr)
                {
                    delete struct_memory_[i];
                }
            }
        }

        if (decoded_structs_ != nullptr)
        {
            for (size_t i = 0; i < GetLength(); ++i)
            {
                if (decoded_structs_[i] != nullptr)
                {
                    delete decoded_structs_[i];
                }
            }
        }
    }

    uint32_t* GetAttributes() const { return struct_attributes_.get(); }

    uint64_t* GetAddresses() const { return struct_addresses_.get(); }

    Decoded_VkObjectTableEntryNVX** GetMetaStructPointer() const { return decoded_structs_.get(); }

    VkObjectTableEntryNVX** GetPointer() const { return struct_memory_.get(); }

    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        // We should only be decoding arrays of structs.
        assert(((GetAttributeMask() & format::PointerAttributes::kIsStruct) == format::PointerAttributes::kIsStruct) &&
               ((GetAttributeMask() & format::PointerAttributes::kIsArray) == format::PointerAttributes::kIsArray));

        if (!IsNull() && HasData())
        {
            assert(struct_memory_ == nullptr);

            size_t len         = GetLength();
            decoded_structs_   = std::make_unique<Decoded_VkObjectTableEntryNVX*[]>(len);
            struct_memory_     = std::make_unique<VkObjectTableEntryNVX*[]>(len);
            struct_attributes_ = std::make_unique<uint32_t[]>(len);
            struct_addresses_  = std::make_unique<uint64_t[]>(len);

            for (size_t i = 0; i < len; ++i)
            {
                // Read the pointer attribute and optional address.
                bytes_read += ValueDecoder::DecodeUInt32Value(
                    (buffer + bytes_read), (buffer_size - bytes_read), &struct_attributes_[i]);

                if ((struct_attributes_[i] & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
                {
                    if ((struct_attributes_[i] & format::PointerAttributes::kHasAddress) ==
                        format::PointerAttributes::kHasAddress)
                    {
                        bytes_read += ValueDecoder::DecodeAddress(
                            (buffer + bytes_read), (buffer_size - bytes_read), &struct_addresses_[i]);
                    }
                    else
                    {
                        struct_addresses_[i] = 0;
                    }

                    // Peak at the structure type.
                    const VkObjectTableEntryNVX* base_type =
                        reinterpret_cast<const VkObjectTableEntryNVX*>(buffer + bytes_read);

                    if (base_type->type == VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX)
                    {
                        Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper =
                            new Decoded_VkObjectTableDescriptorSetEntryNVX;
                        VkObjectTableDescriptorSetEntryNVX* value = new VkObjectTableDescriptorSetEntryNVX;

                        decoded_structs_[i] = reinterpret_cast<Decoded_VkObjectTableEntryNVX*>(wrapper);
                        struct_memory_[i]   = reinterpret_cast<VkObjectTableEntryNVX*>(value);
                        wrapper->value      = value;

                        bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper);
                    }
                    else if (base_type->type == VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX)
                    {
                        Decoded_VkObjectTablePipelineEntryNVX* wrapper = new Decoded_VkObjectTablePipelineEntryNVX;
                        VkObjectTablePipelineEntryNVX*         value   = new VkObjectTablePipelineEntryNVX;

                        decoded_structs_[i] = reinterpret_cast<Decoded_VkObjectTableEntryNVX*>(wrapper);
                        struct_memory_[i]   = reinterpret_cast<VkObjectTableEntryNVX*>(value);
                        wrapper->value      = value;

                        bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper);
                    }
                    else if (base_type->type == VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX)
                    {
                        Decoded_VkObjectTableIndexBufferEntryNVX* wrapper =
                            new Decoded_VkObjectTableIndexBufferEntryNVX;
                        VkObjectTableIndexBufferEntryNVX* value = new VkObjectTableIndexBufferEntryNVX;

                        decoded_structs_[i] = reinterpret_cast<Decoded_VkObjectTableEntryNVX*>(wrapper);
                        struct_memory_[i]   = reinterpret_cast<VkObjectTableEntryNVX*>(value);
                        wrapper->value      = value;

                        bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper);
                    }
                    else if (base_type->type == VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX)
                    {
                        Decoded_VkObjectTableVertexBufferEntryNVX* wrapper =
                            new Decoded_VkObjectTableVertexBufferEntryNVX;
                        VkObjectTableVertexBufferEntryNVX* value = new VkObjectTableVertexBufferEntryNVX;

                        decoded_structs_[i] = reinterpret_cast<Decoded_VkObjectTableEntryNVX*>(wrapper);
                        struct_memory_[i]   = reinterpret_cast<VkObjectTableEntryNVX*>(value);
                        wrapper->value      = value;

                        bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper);
                    }
                    else if (base_type->type == VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX)
                    {
                        Decoded_VkObjectTablePushConstantEntryNVX* wrapper =
                            new Decoded_VkObjectTablePushConstantEntryNVX;
                        VkObjectTablePushConstantEntryNVX* value = new VkObjectTablePushConstantEntryNVX;

                        decoded_structs_[i] = reinterpret_cast<Decoded_VkObjectTableEntryNVX*>(wrapper);
                        struct_memory_[i]   = reinterpret_cast<VkObjectTableEntryNVX*>(value);
                        wrapper->value      = value;

                        bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper);
                    }
                    else
                    {
                        assert(true);
                    }
                }
                else
                {
                    decoded_structs_[i] = nullptr;
                    struct_memory_[i]   = nullptr;
                }
            }
        }

        return bytes_read;
    }

  private:
    std::unique_ptr<Decoded_VkObjectTableEntryNVX*[]> decoded_structs_;
    std::unique_ptr<VkObjectTableEntryNVX*[]>         struct_memory_;
    std::unique_ptr<uint32_t[]>                       struct_attributes_;
    std::unique_ptr<uint64_t[]>                       struct_addresses_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_STRUCT_POINTER_DECODER_NVX_H
