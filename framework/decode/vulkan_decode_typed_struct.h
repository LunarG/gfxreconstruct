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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// TypedStructDecoder decodes a command parameter declared VkBaseOutStructure*: a pointer to one structure whose type
// is its own sType, e.g. vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM::pProperties, whose VUID
// 09958 lists the valid types. The args struct holds it by value. Decode reads the pointer preamble, then decodes the
// structure through DecodePNextStruct only if the data was encoded. Readers cast GetPointer/GetMetaStructPointer by
// sType, as for a pNext node. This is not the OpenXR base-header (parentstruct) idiom;
// StructPointerDecoder::DecodeBaseHeader serves that.

#ifndef GFXRECON_DECODE_VULKAN_DECODE_TYPED_STRUCT_H
#define GFXRECON_DECODE_VULKAN_DECODE_TYPED_STRUCT_H

#include "decode/pointer_decoder_base.h"
#include "decode/vulkan_pnext_node.h"
#include "util/defines.h"

#include <cstddef>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class TypedStructDecoder : public PointerDecoderBase
{
  public:
    size_t Decode(const uint8_t* buffer, size_t buffer_size)
    {
        size_t bytes_read = DecodeAttributes(buffer, buffer_size);

        if (!IsNull() && HasData())
        {
            // DecodePNextStruct reads the preamble again, and its count includes it.
            size_t decoded = DecodePNextStruct(buffer, buffer_size, &node_);

            if (node_ != nullptr)
            {
                return decoded;
            }
        }

        // Null, omitted after a failed call, or unrecognized: the preamble alone was consumed.
        return bytes_read;
    }

    // Returns the node DecodePNextStruct allocated, or null when the structure was null, omitted, or unrecognized.
    PNextNode* GetPNextNode() const { return node_; }

    const void* GetPointer() const { return (node_ != nullptr) ? node_->GetPointer() : nullptr; }
    void*       GetPointer() { return (node_ != nullptr) ? node_->GetPointer() : nullptr; }

    const void* GetMetaStructPointer() const { return (node_ != nullptr) ? node_->GetMetaStructPointer() : nullptr; }
    void*       GetMetaStructPointer() { return (node_ != nullptr) ? node_->GetMetaStructPointer() : nullptr; }

  private:
    PNextNode* node_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODE_TYPED_STRUCT_H
