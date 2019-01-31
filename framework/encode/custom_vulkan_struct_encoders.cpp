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

#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const VkClearColorValue& value)
{
    encoder->EncodeUInt32Array(value.uint32, 4);
}

void EncodeStruct(ParameterEncoder* encoder, const VkClearValue& value)
{
    // VkClearColorValue is used becaue it is the larger of the two union members.
    EncodeStruct(encoder, value.color);
}

void EncodeStruct(ParameterEncoder* encoder, const VkObjectTableEntryNVX* value)
{
    if (value != nullptr)
    {
        switch (value->type)
        {
            case VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX:
                EncodeStructPtr(encoder, reinterpret_cast<const VkObjectTableDescriptorSetEntryNVX*>(value));
                break;
            case VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX:
                EncodeStructPtr(encoder, reinterpret_cast<const VkObjectTablePipelineEntryNVX*>(value));
                break;
            case VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX:
                EncodeStructPtr(encoder, reinterpret_cast<const VkObjectTableIndexBufferEntryNVX*>(value));
                break;
            case VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX:
                EncodeStructPtr(encoder, reinterpret_cast<const VkObjectTableVertexBufferEntryNVX*>(value));
                break;
            case VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX:
                EncodeStructPtr(encoder, reinterpret_cast<const VkObjectTablePushConstantEntryNVX*>(value));
                break;
            default:
                GFXRECON_LOG_WARNING("Skipping custom struct encoding for unrecognized VkObjectEntryTypeNVX %u",
                                     value->type);
                assert(true);
                break;
        }
    }
    else
    {
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

// The WIN32 SID structure has a variable size, so will be encoded as an array of bytes instead of a struct.
static void pack_sid_struct(const SID* sid, std::vector<uint8_t>* buffer)
{
    assert((sid != nullptr) && (buffer != nullptr));

    const uint8_t* sub_authority      = reinterpret_cast<const uint8_t*>(sid->SubAuthority);
    size_t         sub_authority_size = sid->SubAuthorityCount * sizeof(uint32_t);

    // sizeof(SID) already includes the size of one of the SidAuthority elements,
    // so we can subtract 4 bytes from sid_authority_size.
    buffer->reserve(sizeof(SID) + (sub_authority_size - sizeof(uint32_t)));

    buffer->push_back(sid->Revision);
    buffer->push_back(sid->SubAuthorityCount);
    buffer->insert(buffer->end(), sid->IdentifierAuthority.Value, sid->IdentifierAuthority.Value + 6);
    buffer->insert(buffer->end(), sub_authority, sub_authority + sub_authority_size);
}

void EncodeStruct(ParameterEncoder* encoder, const ACL& value)
{
    encoder->EncodeUInt8Value(value.AclRevision);
    encoder->EncodeUInt8Value(value.Sbz1);
    encoder->EncodeUInt16Value(value.AclSize);
    encoder->EncodeUInt16Value(value.AceCount);
    encoder->EncodeUInt16Value(value.Sbz2);
}

void EncodeStruct(ParameterEncoder* encoder, const SECURITY_DESCRIPTOR& value)
{
    encoder->EncodeUInt8Value(value.Revision);
    encoder->EncodeUInt8Value(value.Sbz1);
    encoder->EncodeUInt16Value(value.Control);

    // The SID structure has a variable size, so will be packed into an array of bytes.
    std::vector<uint8_t> buffer;

    if (value.Owner != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Owner), &buffer);
        encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        encoder->EncodeUInt8Array(nullptr, 0);
    }

    buffer.clear();

    if (value.Group != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Group), &buffer);
        encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        encoder->EncodeUInt8Array(nullptr, 0);
    }

    EncodeStructPtr(encoder, value.Sacl);
    EncodeStructPtr(encoder, value.Dacl);
}

void EncodeStruct(ParameterEncoder* encoder, const SECURITY_ATTRIBUTES& value)
{
    encoder->EncodeUInt32Value(value.nLength);
    EncodeStructPtr(encoder, reinterpret_cast<SECURITY_DESCRIPTOR*>(value.lpSecurityDescriptor));
    encoder->EncodeInt32Value(value.bInheritHandle);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
