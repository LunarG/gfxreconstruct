/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2025 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#include "encode/custom_common_struct_encoders.h"
#include "encode/struct_pointer_encoder.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

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

void EncodeStruct(ParameterEncoder* encoder, const LARGE_INTEGER& value)
{
    encoder->EncodeInt64Value(value.QuadPart);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
