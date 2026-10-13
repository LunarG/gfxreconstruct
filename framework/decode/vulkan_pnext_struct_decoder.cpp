/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include "decode/api_element_traits.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/decode_allocator.h"
#include "decode/vulkan_pnext_node.h"
#include "decode/vulkan_pnext_typed_node.h"
#include "generated/generated_vulkan_decode_api_element_traits.h"
#include "generated/generated_vulkan_schema_catalog.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "schema/structure_type_index.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, PNextNode** pNext)
{
    GFXRECON_ASSERT(pNext != nullptr);

    size_t   bytes_read = 0;
    size_t   peek_bytes = 0;
    uint32_t attrib     = 0;

    if ((buffer != nullptr) && (buffer_size >= sizeof(attrib)))
    {
        // Peek at the pointer attribute mask to make sure we have a non-NULL value that can be decoded.
        size_t             dummy_len     = 0;
        uint64_t           dummy_address = 0;
        constexpr uint32_t kRequiredAttribMask =
            format::PointerAttributes::kIsStruct | format::PointerAttributes::kHasData;
        peek_bytes = DecodePointerAttributes(buffer, buffer_size, dummy_len, dummy_address, attrib);

        if (((attrib & kRequiredAttribMask) == kRequiredAttribMask) &&
            ((buffer_size - peek_bytes) >= sizeof(VkStructureType)))
        {
            VkStructureType structure_type;
            // The sType isn't part of the attributes, so we exclude it from the fail condition byte count.
            ValueDecoder::DecodeEnumValue((buffer + peek_bytes), (buffer_size - peek_bytes), &structure_type);

            auto on_find = [&bytes_read, &pNext, buffer, buffer_size]<decode::HasDecodedType Descriptor>() {
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded<Descriptor>>>();
                // The Decode() starts from the beginning of the buffer, so we can ignore the peeked bytes.
                bytes_read = (*pNext)->Decode(buffer, buffer_size);
            };
            auto on_miss = [&structure_type]() {
                // TODO: This may need to be a fatal error
                GFXRECON_LOG_ERROR("Failed to decode pNext value with unrecognized VkStructureType = %s",
                                   (util::ToString(structure_type).c_str()));
            };
            using List = schema::vulkan::catalog::extensible_structures;
            schema::StructureTypeVisit<List>(structure_type, on_find, on_miss);
        }
    }

    if ((bytes_read == 0) && (attrib != 0))
    {
        // The encoded pointer attribute mask included kIsNull, or the sType was unrecognized.
        // We will report that we read the attribute mask, but nothing else was decoded.
        bytes_read = peek_bytes;
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
