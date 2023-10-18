/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Valve Corporation
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
#ifndef GFXRECON_DECODE_DX12_DECODE_JSON_UTIL_H
#define GFXRECON_DECODE_DX12_DECODE_JSON_UTIL_H

/// @file Utilities for converting DX12 decode subsystem types to JSON.

#include "decode/decode_json_util.h"
#include "generated/generated_dx12_struct_decoders.h"
#include "util/json_util.h"
#include "util/defines.h"

#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// Reach through the decoded GUID and pass the raw type to its JSON converter
/// defined elsewhere.
inline void FieldToJson(nlohmann::ordered_json&  jdata,
                        const Decoded_GUID&      data,
                        const util::JsonOptions& options = util::JsonOptions())
{
    FieldToJson(jdata, *data.decoded_value, options);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DECODE_JSON_UTIL_H
