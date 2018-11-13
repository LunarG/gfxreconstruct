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
#include "decode/pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decoded union wrappers.
struct Decoded_VkClearColorValue
{
    using struct_type = VkClearColorValue;
    VkClearColorValue*       value{ nullptr };
    PointerDecoder<uint32_t> uint32;
};

struct Decoded_VkClearValue
{
    using struct_type = VkClearValue;
    VkClearValue*             value{ nullptr };
    Decoded_VkClearColorValue color;
};

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkObjectTableEntryNVX
{
    VkObjectTableEntryNVX* value{ nullptr };
};

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL
{
    using struct_type = ACL;

    ACL* value{ nullptr };
};

struct Decoded_SECURITY_DESCRIPTOR
{
    using struct_type = SECURITY_DESCRIPTOR;

    SECURITY_DESCRIPTOR* value{ nullptr };

    std::unique_ptr<uint8_t[]> Owner;
    std::unique_ptr<uint8_t[]> Group;
    PointerDecoder<uint8_t>    PackedOwner;
    PointerDecoder<uint8_t>    PackedGroup;

    StructPointerDecoder<Decoded_ACL> Sacl;
    StructPointerDecoder<Decoded_ACL> Dacl;
};

struct Decoded_SECURITY_ATTRIBUTES
{
    using struct_type = SECURITY_ATTRIBUTES;

    SECURITY_ATTRIBUTES* value{ nullptr };

    StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR> lpSecurityDescriptor;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_STRUCT_DECODERS_H
