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

#ifndef BRIMSTONE_CUSTOM_STRUCT_DECODERS_H
#define BRIMSTONE_CUSTOM_STRUCT_DECODERS_H

#include <memory>

#include "vulkan/vulkan.h"

#include "format/custom_struct_decoders_forward.h"
#include "format/platform_types.h"
#include "format/pointer_decoder.h"
#include "format/struct_pointer_decoder.h"
#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

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
    PointerDecoder<uint8_t> PackedOwner;
    PointerDecoder<uint8_t> PackedGroup;

    StructPointerDecoder<Decoded_ACL> Sacl;
    StructPointerDecoder<Decoded_ACL> Dacl;
};

struct Decoded_SECURITY_ATTRIBUTES
{
    using struct_type = SECURITY_ATTRIBUTES;

    SECURITY_ATTRIBUTES* value{ nullptr };

    StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR> lpSecurityDescriptor;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_CUSTOM_STRUCT_DECODERS_H
