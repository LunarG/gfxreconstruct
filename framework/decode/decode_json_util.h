/*
** Copyright (c) 2022-2023 LunarG, Inc.
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
#ifndef GFXRECON_DECODE_DECODE_JSON_UTIL_H
#define GFXRECON_DECODE_DECODE_JSON_UTIL_H

/// @file API-independent utilities for converting decode-module types to JSON.

#include "decode/pointer_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/string_decoder.h"
#include "decode/string_array_decoder.h"

#include "util/json_util.h"
#include "util/defines.h"

#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void FieldToJson(nlohmann::ordered_json&   jdata,
                 const StringArrayDecoder* data,
                 const util::JsonOptions&  options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const StringDecoder*     data,
                 const util::JsonOptions& options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const StringDecoder&     data,
                 const util::JsonOptions& options = util::JsonOptions());

void FieldToJson(nlohmann::ordered_json&  jdata,
                 const WStringDecoder*    data,
                 const util::JsonOptions& options = util::JsonOptions());

template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const PointerDecoder<DecodedType, OutputDecodedType>* data,
                 const util::JsonOptions&                              options = util::JsonOptions())
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                FieldToJson(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            FieldToJson(jdata, *decoded_value, options);
        }
    }
}

// Reference to pointer version wraps pointer to pointer version above.
template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const PointerDecoder<DecodedType, OutputDecodedType>& data,
                 const util::JsonOptions&                              options = util::JsonOptions())
{
    FieldToJson(jdata, &data, options);
}

template <>
void FieldToJson(nlohmann::ordered_json&                   jdata,
                 const PointerDecoder<uint64_t, uint64_t>& data,
                 const util::JsonOptions&                  options);

template <typename DecodedType>
void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const StructPointerDecoder<DecodedType>* data,
                 const util::JsonOptions&                 options = util::JsonOptions())
{
    if (data)
    {
        const auto meta_struct = data->GetMetaStructPointer();
        const auto length      = data->GetLength();
        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                FieldToJson(jdata[i], &meta_struct[i], options);
            }
        }
        else if (length == 1)
        {
            FieldToJson(jdata, meta_struct, options);
        }
    }
}

template <typename DecodedType>
void FieldToJson(nlohmann::ordered_json&             jdata,
                 StructPointerDecoder<DecodedType*>* data,
                 const util::JsonOptions&            options = util::JsonOptions())
{
    if (data)
    {
        const auto meta_struct = data->GetMetaStructPointer();
        const auto length      = data->GetLength();
        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                FieldToJson(jdata[i], meta_struct[i], options);
            }
        }
        else if (length == 1)
        {
            FieldToJson(jdata, *meta_struct, options);
        }
    }
}

template <typename THandle>
void HandleToJson(nlohmann::ordered_json&              jdata,
                  const HandlePointerDecoder<THandle>* data,
                  const util::JsonOptions&             options = util::JsonOptions())
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                HandleToJson(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            HandleToJson(jdata, *decoded_value, options);
        }
    }
}

/// @brief Thunk to HandleToJson for manual conversion functions which forget to
/// use that for the array form.
template <typename THandle>
void FieldToJson(nlohmann::ordered_json&              jdata,
                 const HandlePointerDecoder<THandle>* data,
                 const util::JsonOptions&             options = util::JsonOptions())
{
    HandleToJson(jdata, data, options);
}

// Same as array FieldToJson above but converts elements pointed-to to hexadecimal
template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJsonAsHex(nlohmann::ordered_json&                               jdata,
                      const PointerDecoder<DecodedType, OutputDecodedType>* data,
                      const util::JsonOptions&                              options = util::JsonOptions())
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                FieldToJsonAsHex(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            FieldToJsonAsHex(jdata, *decoded_value, options);
        }
    }
}

template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJsonAsHex(nlohmann::ordered_json&                               jdata,
                      const PointerDecoder<DecodedType, OutputDecodedType>& data,
                      const util::JsonOptions&                              options = util::JsonOptions())
{
    FieldToJsonAsHex(jdata, &data, options);
}

// Used by (e.g.) VkMapMemory's ppData
inline void
FieldToJsonAsHex(nlohmann::ordered_json& jdata, PointerDecoder<uint64_t, void*>* data, const util::JsonOptions& options)
{
    FieldToJsonAsHex<uint64_t, void*>(jdata, data, options);
}

// Convert arrays of and pointers to bools. Since VkBool32 is just a typedef of
// uint32_t we can't use the standard function name and dispatch on the type.
void Bool32ToJson(nlohmann::ordered_json&                   jdata,
                  const PointerDecoder<uint32_t, uint32_t>* data,
                  const util::JsonOptions&                  options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DECODE_JSON_UTIL_H
