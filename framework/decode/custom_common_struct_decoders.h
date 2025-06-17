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

#ifndef GFXRECON_DECODE_CUSTOM_COMMON_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_COMMON_STRUCT_DECODERS_H

#include "format/platform_types.h"
#include "decode/custom_common_struct_decoders_forward.h"
#include "decode/pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Decoded struct wrappers for SECURITY_ATTRIBUTES and related WIN32 structures.
struct Decoded_ACL
{
    using struct_type = ACL;

    ACL* decoded_value{ nullptr };
};

struct Decoded_SECURITY_DESCRIPTOR
{
    using struct_type = SECURITY_DESCRIPTOR;

    SECURITY_DESCRIPTOR* decoded_value{ nullptr };

    uint8_t*                Owner{ nullptr };
    uint8_t*                Group{ nullptr };
    PointerDecoder<uint8_t> PackedOwner;
    PointerDecoder<uint8_t> PackedGroup;

    StructPointerDecoder<Decoded_ACL>* Sacl{ nullptr };
    StructPointerDecoder<Decoded_ACL>* Dacl{ nullptr };
};

struct Decoded_SECURITY_ATTRIBUTES
{
    using struct_type = SECURITY_ATTRIBUTES;

    SECURITY_ATTRIBUTES* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>* lpSecurityDescriptor{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_COMMON_STRUCT_DECODERS_H
