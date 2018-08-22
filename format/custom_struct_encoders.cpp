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

#include <cassert>
#include <vector>

#include "format/custom_struct_encoders.h"
#include "format/struct_pointer_encoder.h"
#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

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

size_t encode_struct(format::ParameterEncoder* encoder, const ACL& value)
{
    size_t result = 0;

    result += encoder->EncodeUInt8Value(value.AclRevision);
    result += encoder->EncodeUInt8Value(value.Sbz1);
    result += encoder->EncodeUInt16Value(value.AclSize);
    result += encoder->EncodeUInt16Value(value.AceCount);
    result += encoder->EncodeUInt16Value(value.Sbz2);

    return result;
}

size_t encode_struct(format::ParameterEncoder* encoder, const SECURITY_DESCRIPTOR& value)
{
    size_t result = 0;

    result += encoder->EncodeUInt8Value(value.Revision);
    result += encoder->EncodeUInt8Value(value.Sbz1);
    result += encoder->EncodeUInt16Value(value.Control);

    // The SID structure has a variable size, so will be packed into an array of bytes.
    std::vector<uint8_t> buffer;

    if (value.Owner != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Owner), &buffer);
        result += encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        result += encoder->EncodeUInt8Array(nullptr, 0);
    }

    buffer.clear();

    if (value.Group != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Group), &buffer);
        result += encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        result += encoder->EncodeUInt8Array(nullptr, 0);
    }

    result += encode_struct_ptr(encoder, value.Sacl);
    result += encode_struct_ptr(encoder, value.Dacl);

    return result;
}

size_t encode_struct(format::ParameterEncoder* encoder, const SECURITY_ATTRIBUTES& value)
{
    size_t   result  = 0;

    result += encoder->EncodeUInt32Value(value.nLength);
    result += encode_struct_ptr(encoder, reinterpret_cast<SECURITY_DESCRIPTOR*>(value.lpSecurityDescriptor));
    result += encoder->EncodeInt32Value(value.bInheritHandle);

    return result;
}

BRIMSTONE_END_NAMESPACE(brimstone)
