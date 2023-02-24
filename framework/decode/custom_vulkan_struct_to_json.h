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

inline void FieldToJson(nlohmann::ordered_json& jdata, float data, const JsonOptions& options = JsonOptions())
{
    jdata = data;
}

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
void FieldToJson(nlohmann::ordered_json&              jdata,
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
                FieldToJson(jdata[i], handle_to_string(decoded_value[i]), options);
            }
        }
        else if (length == 1)
        {
            FieldToJson(jdata, handle_to_string(*decoded_value), options);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_VULKAN_STRUCT_TO_JSON_H
