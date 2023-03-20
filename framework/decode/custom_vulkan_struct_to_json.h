/*
** Copyright (c) 2022 LunarG, Inc.
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
#ifndef GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H
#define GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H

#include "util/defines.h"
#include "nlohmann/json.hpp"
#include "vulkan/vulkan.h"

#include "decode/vulkan_json_util.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_enum_to_json.h"
#include "generated/generated_vulkan_struct_to_json.h"
#include "generated/generated_vulkan_struct_decoders.h"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DescriptorUpdateTemplateDecoder;

inline void FieldToJson(nlohmann::ordered_json& jdata, short data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, int data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, long data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, long long data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, unsigned short data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, unsigned int data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void FieldToJson(nlohmann::ordered_json& jdata, unsigned long data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void
FieldToJson(nlohmann::ordered_json& jdata, unsigned long long data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

/// Convert floats to JSON, logging information loss when floats with no JSON
/// number type representation are adjusted. The JSON library turns these numbers
/// into JSON nulls otherwise.
void FieldToJson(nlohmann::ordered_json& jdata, float data, const JsonOptions& options = JsonOptions());

/// @note This is unused dead code currently (try placing a breakpoint on it).
inline void FieldToJson(nlohmann::ordered_json& jdata, double data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

inline void
FieldToJson(nlohmann::ordered_json& jdata, const std::string& data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

void FieldToJson(nlohmann::ordered_json&   jdata,
                 const StringArrayDecoder* data,
                 const JsonOptions&        options = JsonOptions());

void FieldToJson(nlohmann::ordered_json& jdata, const StringDecoder* data, const JsonOptions& options = JsonOptions());

void FieldToJson(nlohmann::ordered_json& jdata, const WStringDecoder* data, const JsonOptions& options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&     jdata,
                 const Decoded_VkClearValue* data,
                 const JsonOptions&          options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&          jdata,
                 const Decoded_VkClearColorValue* data,
                 const JsonOptions&               options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 int                                          discriminant,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const JsonOptions&                           options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const Decoded_VkDeviceOrHostAddressConstKHR* data,
                 const JsonOptions&                           options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 int                                     discriminant,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const JsonOptions&                      options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkDeviceOrHostAddressKHR* data,
                 const JsonOptions&                      options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                              jdata,
                 VkPipelineExecutableStatisticFormatKHR               discriminant,
                 const Decoded_VkPipelineExecutableStatisticValueKHR* data,
                 const JsonOptions&                                   options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                         jdata,
                 const Decoded_VkPipelineExecutableStatisticKHR* data,
                 const JsonOptions&                              options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&            jdata,
                 const Decoded_SECURITY_ATTRIBUTES* data,
                 const JsonOptions&                 options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const Decoded_VkAccelerationStructureGeometryDataKHR* data,
                 const JsonOptions&                                    options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                           jdata,
                 const Decoded_VkAccelerationStructureGeometryKHR* data,
                 const JsonOptions&                                options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&              jdata,
                 const Decoded_VkDescriptorImageInfo* data,
                 const JsonOptions&                   options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&             jdata,
                 const Decoded_VkWriteDescriptorSet* data,
                 const JsonOptions&                  options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                jdata,
                 const Decoded_VkPerformanceValueINTEL* data,
                 const JsonOptions&                     options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                 jdata,
                 const Decoded_VkShaderModuleCreateInfo* data,
                 const JsonOptions&                      options = JsonOptions());

void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const Decoded_VkPipelineCacheCreateInfo* data,
                 const JsonOptions&                       options = JsonOptions());

template <typename T>
void FieldToJson(nlohmann::ordered_json& jdata,
                 const T*                data,
                 size_t                  num_elemements,
                 const JsonOptions&      options = JsonOptions())
{
    if (data)
    {
        for (size_t i = 0; i < num_elemements; ++i)
        {
            FieldToJson(jdata[i], data[i], options);
        }
    }
    else
    {
        jdata = nullptr;
    }
}

template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJson(nlohmann::ordered_json&                               jdata,
                 const PointerDecoder<DecodedType, OutputDecodedType>* data,
                 const JsonOptions&                                    options = JsonOptions())
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
                 const JsonOptions&                                    options = JsonOptions())
{
    FieldToJson(jdata, &data, options);
}

template <>
void FieldToJson(nlohmann::ordered_json&                   jdata,
                 const PointerDecoder<uint64_t, uint64_t>& data,
                 const JsonOptions&                        options);

template <typename DecodedType>
void FieldToJson(nlohmann::ordered_json&                  jdata,
                 const StructPointerDecoder<DecodedType>* data,
                 const JsonOptions&                       options = JsonOptions())
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
                 const JsonOptions&                  options = JsonOptions())
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
                  const JsonOptions&                   options = JsonOptions())
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

void HandleToJson(nlohmann::ordered_json& jdata,
                  const format::HandleId* data,
                  size_t                  num_elemements,
                  const JsonOptions&      options = JsonOptions());

/// @brief Thunk to HandleToJson for manual conversion functions which forget to
/// use that for the array form.
template <typename THandle>
void FieldToJson(nlohmann::ordered_json&              jdata,
                 const HandlePointerDecoder<THandle>* data,
                 const JsonOptions&                   options = JsonOptions())
{
    HandleToJson(jdata, data, options);
}

template <typename T>
void FieldToJsonAsHex(nlohmann::ordered_json& jdata, const T data, const JsonOptions& options = JsonOptions())
{
    jdata = to_hex_variable_width(data);
}

// Same as array FieldToJson above but converts elements pointed-to to hexadecimal
template <typename DecodedType, typename OutputDecodedType = DecodedType>
void FieldToJsonAsHex(nlohmann::ordered_json&                               jdata,
                      const PointerDecoder<DecodedType, OutputDecodedType>* data,
                      const JsonOptions&                                    options = JsonOptions())
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
                      const JsonOptions&                                    options = JsonOptions())
{
    FieldToJsonAsHex(jdata, &data, options);
}

// Used by (e.g.) VkMapMemory's ppData
template <>
inline void
FieldToJsonAsHex(nlohmann::ordered_json& jdata, PointerDecoder<uint64_t, void*>* data, const JsonOptions& options)
{
    FieldToJsonAsHex<uint64_t, void*>(jdata, data, options);
}

template <typename T>
void VkBool32ToJson(nlohmann::ordered_json& jdata, const T data, const JsonOptions& options = JsonOptions())
{
    jdata = static_cast<bool>(data);
}

// Convert arrays of and pointers to bools. Since VkBool32 is just a typedef of
// uint32_t we can't use the standard function name and dispatch on the type.
template <typename DecodedType, typename OutputDecodedType = DecodedType>
void VkBool32ToJson(nlohmann::ordered_json&                               jdata,
                    const PointerDecoder<DecodedType, OutputDecodedType>* data,
                    const JsonOptions&                                    options = JsonOptions())
{
    if (data && data->GetPointer())
    {
        const auto decoded_value = data->GetPointer();
        const auto length        = data->GetLength();

        if (data->IsArray())
        {
            for (size_t i = 0; i < length; ++i)
            {
                VkBool32ToJson(jdata[i], decoded_value[i], options);
            }
        }
        else if (length == 1)
        {
            VkBool32ToJson(jdata, *decoded_value, options);
        }
    }
}

void FieldToJson(nlohmann::ordered_json&                      jdata,
                 const DescriptorUpdateTemplateDecoder* const pData,
                 const JsonOptions&                           options = JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H
