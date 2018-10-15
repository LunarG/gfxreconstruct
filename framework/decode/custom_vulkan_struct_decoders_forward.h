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

#ifndef BRIMSTONE_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H
#define BRIMSTONE_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H

#include "format/platform_types.h"
#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

// Decoded unions.
struct Decoded_VkClearColorValue;
struct Decoded_VkClearValue;

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearColorValue* wrapper);
size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearValue* wrapper);

// Decoded struct wrappers for Vulkan structures that require special processing.
struct Decoded_VkObjectTableEntryNVX;

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL;
struct Decoded_SECURITY_DESCRIPTOR;
struct Decoded_SECURITY_ATTRIBUTES;

size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper);
size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper);
size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper);

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_CUSTOM_STRUCT_DECODER_DECLARATIONS_H
