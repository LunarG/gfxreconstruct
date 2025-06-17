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

#include "decode/custom_common_struct_decoders.h"

#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// The WIN32 SID structure has a variable size, so was encoded as an array of bytes instead of a struct.
static uint8_t* unpack_sid_struct(const PointerDecoder<uint8_t>& packed_value)
{
    uint8_t* unpacked_memory = nullptr;

    if (!packed_value.IsNull())
    {
        const uint8_t* bytes = packed_value.GetPointer();

        // Allocate memory for variable length SID struct, to use for unpacking.
        // SidAuthorityCount is the second byte of the packed array.
        size_t sid_authority_size = bytes[1] * sizeof(uint32_t);

        // sizeof(SID) already includes the size of one of the SidAuthority elements,
        // so we can subtract 4 bytes from sid_authority_size.
        size_t allocation_size = sizeof(SID) + (sid_authority_size - sizeof(uint32_t));
        unpacked_memory        = DecodeAllocator::Allocate<uint8_t>(allocation_size);

        SID* sid               = reinterpret_cast<SID*>(unpacked_memory);
        sid->Revision          = bytes[0];
        sid->SubAuthorityCount = bytes[1];
        memcpy(sid->IdentifierAuthority.Value, &bytes[2], 6);
        memcpy(sid->SubAuthority, &bytes[8], sid_authority_size);
    }

    return unpacked_memory;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    ACL*   value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AclRevision));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz1));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AclSize));
    bytes_read +=
        ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AceCount));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz2));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    SECURITY_DESCRIPTOR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz1));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Control));

    // The SID structure has a variable size, so has been packed into an array of bytes.
    bytes_read += wrapper->PackedOwner.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->Owner = unpack_sid_struct(wrapper->PackedOwner);
    value->Owner   = wrapper->Owner;

    bytes_read += wrapper->PackedGroup.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->Group = unpack_sid_struct(wrapper->PackedOwner);
    value->Group   = wrapper->Group;

    wrapper->Sacl = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_ACL>>();
    bytes_read += wrapper->Sacl->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Sacl = wrapper->Sacl->GetPointer();

    wrapper->Dacl = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_ACL>>();
    bytes_read += wrapper->Dacl->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Dacl = wrapper->Dacl->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    SECURITY_ATTRIBUTES* value      = wrapper->decoded_value;

    uint32_t nLength = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &nLength);
    value->nLength = nLength;

    wrapper->lpSecurityDescriptor = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>>();
    bytes_read += wrapper->lpSecurityDescriptor->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->lpSecurityDescriptor = wrapper->lpSecurityDescriptor->GetPointer();

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bInheritHandle));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
