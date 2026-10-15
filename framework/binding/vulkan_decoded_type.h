/*
** Copyright (c) 2026 LunarG, Inc.
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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// The Vulkan DecodedType rows, a visitor invoked across the inventory: every decodable structure to its Decoded_
// wrapper, and every command to its args structure. A structure without the HAS_DECODED_TYPE property has no wrapper
// the rows reach (findings BR-6). Every command gets a row, including the one whose args structure is hand-written
// because its decoder is, since that structure must have the canonical shape.

#ifndef GFXRECON_BINDING_VULKAN_DECODED_TYPE_H
#define GFXRECON_BINDING_VULKAN_DECODED_TYPE_H

#include "binding/decoded_type_of.h"
#include "decode/vulkan_decoder_args.h"
#include "generated/generated_vulkan_decoder_args.h"
#include "generated/generated_vulkan_schema_types.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "util/inventory_utils.h"

#ifdef WIN32
#ifdef CreateEvent
#undef CreateEvent
#endif
#ifdef CreateSemaphore
#undef CreateSemaphore
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// A struct visitor: it yields a specialization, a type, so this lives in a header.
#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_DECODED_TYPE
#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) \
    GFXRECON_INVENTORY_DECODED_TYPE(schema::vulkan::api_types::Name, decode::Decoded_##Name);
#define GFXRECON_INVENTORY_VISIT_COMMAND(Name) \
    GFXRECON_INVENTORY_DECODED_TYPE(schema::vulkan::commands::Name, decode::args::Name);
#include "generated/generated_vulkan_inventory.h"

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_VULKAN_DECODED_TYPE_H
