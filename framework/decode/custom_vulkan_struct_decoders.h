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

#ifndef GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H

#include "format/platform_types.h"
#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/pnext_node.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decoded union wrappers.
struct Decoded_VkClearColorValue
{
    using struct_type = VkClearColorValue;
    VkClearColorValue*       decoded_value{ nullptr };
    PointerDecoder<uint32_t> uint32;
};

struct Decoded_VkClearValue
{
    using struct_type = VkClearValue;
    VkClearValue*                              decoded_value{ nullptr };
    std::unique_ptr<Decoded_VkClearColorValue> color;
};

struct Decoded_VkPipelineExecutableStatisticValueKHR
{
    using struct_type = VkPipelineExecutableStatisticValueKHR;
    VkPipelineExecutableStatisticValueKHR* decoded_value{ nullptr };
};

// This union wrapper does not have a DecodeStruct function.  It is decoded by the Decoded_VkPerformanceValueINTEL
// DecodeStruct function, based on the value of VkPerformanceValueINTEL::type.
struct Decoded_VkPerformanceValueDataINTEL
{
    using struct_type = VkPerformanceValueDataINTEL;

    VkPerformanceValueDataINTEL* decoded_value{ nullptr };

    StringDecoder valueString;
};

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkDescriptorImageInfo
{
    using struct_type = VkDescriptorImageInfo;

    VkDescriptorImageInfo* decoded_value{ nullptr };

    format::HandleId sampler{ 0 };
    format::HandleId imageView{ 0 };
};

struct Decoded_VkWriteDescriptorSet
{
    using struct_type = VkWriteDescriptorSet;

    VkWriteDescriptorSet* decoded_value{ nullptr };

    std::unique_ptr<PNextNode>                                            pNext;
    format::HandleId                                                      dstSet{ 0 };
    std::unique_ptr<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>  pImageInfo;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDescriptorBufferInfo>> pBufferInfo;
    HandlePointerDecoder<VkBufferView>                                    pTexelBufferView;
};

struct Decoded_VkPerformanceValueINTEL
{
    using struct_type = VkPerformanceValueINTEL;

    VkPerformanceValueINTEL* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkPerformanceValueDataINTEL> data;
};

struct Decoded_VkObjectTableEntryNVX
{
    VkObjectTableEntryNVX* decoded_value{ nullptr };
};

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL
{
    using struct_type = ACL;

    ACL* decoded_value{ nullptr };
};

struct Decoded_SECURITY_DESCRIPTOR
{
    using struct_type = SECURITY_DESCRIPTOR;

    SECURITY_DESCRIPTOR* decoded_value{ nullptr };

    std::unique_ptr<uint8_t[]> Owner;
    std::unique_ptr<uint8_t[]> Group;
    PointerDecoder<uint8_t>    PackedOwner;
    PointerDecoder<uint8_t>    PackedGroup;

    std::unique_ptr<StructPointerDecoder<Decoded_ACL>> Sacl;
    std::unique_ptr<StructPointerDecoder<Decoded_ACL>> Dacl;
};

struct Decoded_SECURITY_ATTRIBUTES
{
    using struct_type = SECURITY_ATTRIBUTES;

    SECURITY_ATTRIBUTES* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>> lpSecurityDescriptor;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H
