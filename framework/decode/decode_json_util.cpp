/*
** Copyright (c) 2022-2023 LunarG, Inc.
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

#include "decode/decode_json_util.h"
#include "util/defines.h"
#include "nlohmann/json.hpp"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;

void FieldToJson(nlohmann::ordered_json& jdata, const StringDecoder& data, const JsonOptions& options)
{
    const char* const decoded_data = data.GetPointer();
    if (decoded_data)
    {
        FieldToJson(jdata, decoded_data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StringDecoder* data, const JsonOptions& options)
{
    if (data)
    {
        FieldToJson(jdata, *data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StringArrayDecoder* data, const JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        const auto decoded_data = data->GetPointer();
        for (size_t i = 0; i < data->GetLength(); ++i)
        {
            jdata[i] = std::string(decoded_data[i]);
        }
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const WStringDecoder& data, const JsonOptions& options)
{
    const wchar_t* const decoded_data = data.GetPointer();
    if (decoded_data)
    {
        FieldToJson(jdata, decoded_data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const WStringDecoder* data, const JsonOptions& options)
{
    if (data)
    {
        FieldToJson(jdata, *data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const WStringArrayDecoder& data, const JsonOptions& options)
{
    const auto decoded_data = data.GetPointer();
    if (decoded_data)
    {
        for (size_t i = 0; i < data.GetLength(); ++i)
        {
            FieldToJson(jdata[i], decoded_data[i], options);
        }
    }
}

template <>
void FieldToJson(nlohmann::ordered_json&                   jdata,
                 const PointerDecoder<uint32_t, uint32_t>& data,
                 const JsonOptions&                        options)
{
    if (data.GetPointer())
    {
        const auto decoded_value = data.GetPointer();
        const auto length        = data.GetLength();
        if (length > 1)
        {
            for (size_t i = 0; i < length; ++i)
            {
                jdata[i] = decoded_value[i];
            }
        }
        else
        {
            jdata = *decoded_value;
        }
    }
}

template <>
void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const PointerDecoder<int32_t, int32_t>& data,
                 const JsonOptions&                      options)
{
    if (data.GetPointer())
    {
        const auto decoded_value = data.GetPointer();
        const auto length        = data.GetLength();
        if (length > 1)
        {
            for (size_t i = 0; i < length; ++i)
            {
                jdata[i] = decoded_value[i];
            }
        }
        else
        {
            jdata = *decoded_value;
        }
    }
}

template <>
void FieldToJson(nlohmann::ordered_json&                   jdata,
                 const PointerDecoder<uint64_t, uint64_t>& data,
                 const JsonOptions&                        options)
{
    if (data.GetPointer())
    {
        const auto decoded_value = data.GetPointer();
        const auto length        = data.GetLength();
        if (length > 1)
        {
            for (size_t i = 0; i < length; ++i)
            {
                jdata[i] = decoded_value[i];
            }
        }
        else
        {
            jdata = *decoded_value;
        }
    }
}

template <>
void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const PointerDecoder<int64_t, int64_t>& data,
                 const JsonOptions&                      options)
{
    if (data.GetPointer())
    {
        const auto decoded_value = data.GetPointer();
        const auto length        = data.GetLength();
        if (length > 1)
        {
            for (size_t i = 0; i < length; ++i)
            {
                jdata[i] = decoded_value[i];
            }
        }
        else
        {
            jdata = *decoded_value;
        }
    }
}

void Bool32ToJson(nlohmann::ordered_json&                   jdata,
                  const PointerDecoder<uint32_t, uint32_t>* data,
                  const util::JsonOptions&                  options)
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                util::Bool32ToJson(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            util::Bool32ToJson(jdata, *decoded_value, options);
        }
    }
}

void Bool32ToJson(nlohmann::ordered_json& jdata, const PointerDecoder<int, int>* data, const util::JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                util::Bool32ToJson(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            util::Bool32ToJson(jdata, *decoded_value, options);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
