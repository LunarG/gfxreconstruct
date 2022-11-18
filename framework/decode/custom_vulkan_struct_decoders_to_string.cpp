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

#include "custom_vulkan_struct_decoders_to_string.h"
#include "custom_vulkan_ascii_consumer.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_to_string.h"
#include "generated/generated_vulkan_struct_decoders_to_string.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// clang-format off

// NOTE : The following structures' ToString() functions aren't generated due
//  to various reasons...ie unions, non standard counts for arrays, fields that
//  need validation to interpret correctly, etc...

// Call through to the version for the raw struct.
template <>
std::string ToString<decode::Decoded_SECURITY_ATTRIBUTES>(const decode::Decoded_SECURITY_ATTRIBUTES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

// Follow the decoded struct pointers.
template<>
std::string ToString<decode::Decoded_VkAccelerationStructureGeometryKHR>(const decode::Decoded_VkAccelerationStructureGeometryKHR& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkAccelerationStructureGeometryKHR& obj = *decoded_obj.decoded_value;
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.geometryType, toStringFlags, tabCount, tabSize) + '"'); // Just an enum
            FieldToString(strStrm, false, "geometry", toStringFlags, tabCount, tabSize, // The structs in the union have pNexts that we have to traverse through the decoded versions.
                ObjectToString(toStringFlags, tabCount, tabSize,
                    [&](std::stringstream& subStrStrm)
                    {
                        switch (obj.geometryType)
                        {
                        case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                        {
                            FieldToString(subStrStrm, true, "triangles", toStringFlags, tabCount, tabSize, ToString(*(decoded_obj.geometry->triangles), toStringFlags, tabCount, tabSize));
                        } break;
                        case VK_GEOMETRY_TYPE_AABBS_KHR:
                        {
                            FieldToString(subStrStrm, true, "aabbs", toStringFlags, tabCount, tabSize, ToString(*(decoded_obj.geometry->aabbs), toStringFlags, tabCount, tabSize));
                        } break;
                        case VK_GEOMETRY_TYPE_INSTANCES_KHR:
                        {
                            FieldToString(subStrStrm, true, "instances", toStringFlags, tabCount, tabSize, ToString(*(decoded_obj.geometry->instances), toStringFlags, tabCount, tabSize));
                        } break;
                        default:
                        {
                        } break;
                        }
                    }
                )
            );
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

// Dispatch to the raw vulkan version as there are no pNexts or handles reachable through this.
template <>
std::string ToString<decode::Decoded_VkAccelerationStructureMotionInstanceNV>(const decode::Decoded_VkAccelerationStructureMotionInstanceNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

// Dispatch to the raw vulkan version as there are no pNexts or handles reachable through this.
template <>
std::string ToString<decode::Decoded_VkClearColorValue>(const decode::Decoded_VkClearColorValue& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize)
{
    if(obj.decoded_value)
    {
        return ToString<VkClearColorValue>(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

// Dispatch to the raw vulkan version as there are no pNexts or handles reachable through this.
template <>
std::string ToString<decode::Decoded_VkClearValue>(const decode::Decoded_VkClearValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString<VkClearValue>(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
std::string ToString<decode::Decoded_VkDescriptorImageInfo>(const decode::Decoded_VkDescriptorImageInfo& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkDescriptorImageInfo& obj = *decoded_obj.decoded_value;
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true,  "sampler",     toStringFlags, tabCount, tabSize, ToString(decoded_obj.sampler));
            FieldToString(strStrm, false, "imageView",   toStringFlags, tabCount, tabSize, ToString(decoded_obj.imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(obj.imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <>
std::string ToString<decode::Decoded_VkDeviceOrHostAddressConstKHR>(const decode::Decoded_VkDeviceOrHostAddressConstKHR& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
std::string ToString<decode::Decoded_VkDeviceOrHostAddressKHR>(const decode::Decoded_VkDeviceOrHostAddressKHR& obj,
                                               ToStringFlags                   toStringFlags,
                                               uint32_t                        tabCount,
                                               uint32_t                        tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

// Call through to raw vulkan struct version as there are no handles reachable through this.
template <>
std::string ToString<decode::Decoded_VkPerformanceValueINTEL>(const decode::Decoded_VkPerformanceValueINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

template <>
std::string ToString<decode::Decoded_VkPipelineExecutableStatisticKHR>(const decode::Decoded_VkPipelineExecutableStatisticKHR& decoded_obj,
                                           ToStringFlags               toStringFlags,
                                           uint32_t                    tabCount,
                                           uint32_t                    tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkPipelineExecutableStatisticKHR& obj = *decoded_obj.decoded_value;

    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true,  "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, CStrToString(obj.name));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(obj.format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "value", toStringFlags, tabCount, tabSize,
                ObjectToString(toStringFlags, tabCount, tabSize,
                    [&](std::stringstream& subStrStrm)
                    {
                        switch (obj.format)
                        {
                        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR:
                        {
                            FieldToString(subStrStrm, true, "b32", toStringFlags, tabCount, tabSize, ToString(obj.value.b32, toStringFlags, tabCount, tabSize));
                        } break;
                        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR:
                        {
                            FieldToString(subStrStrm, true, "i64", toStringFlags, tabCount, tabSize, ToString(obj.value.i64, toStringFlags, tabCount, tabSize));
                        } break;
                        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR:
                        {
                            FieldToString(subStrStrm, true, "u64", toStringFlags, tabCount, tabSize, ToString(obj.value.u64, toStringFlags, tabCount, tabSize));
                        } break;
                        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR:
                        {
                            FieldToString(subStrStrm, true, "f64", toStringFlags, tabCount, tabSize, ToString(obj.value.f64, toStringFlags, tabCount, tabSize));
                        } break;
                        default:
                        {
                        } break;
                        }
                    }
                )
            );
        }
    );
}

// Use the DecodedStruct to properly traverse pNext and get the dstSet
template <>
std::string ToString<decode::Decoded_VkWriteDescriptorSet>(const decode::Decoded_VkWriteDescriptorSet& decoded_obj,
                                           ToStringFlags               toStringFlags,
                                           uint32_t                    tabCount,
                                           uint32_t                    tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkWriteDescriptorSet& obj = *decoded_obj.decoded_value;
    
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSet", toStringFlags, tabCount, tabSize, ToString(decoded_obj.dstSet));
            FieldToString(strStrm, false, "dstBinding", toStringFlags, tabCount, tabSize, ToString(obj.dstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstArrayElement", toStringFlags, tabCount, tabSize, ToString(obj.dstArrayElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.descriptorType, toStringFlags, tabCount, tabSize) + '"');

            switch (obj.descriptorType)
            {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
            case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
            {
                FieldToString(strStrm, false, "pImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(decoded_obj.pImageInfo, toStringFlags, tabCount, tabSize));
            } break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                FieldToString(strStrm, false, "pBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(decoded_obj.pBufferInfo, toStringFlags, tabCount, tabSize));
            } break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                FieldToString(strStrm, false, "pTexelBufferView", toStringFlags, tabCount, tabSize, ArrayToString(decoded_obj.pTexelBufferView.GetLength(), decoded_obj.pTexelBufferView.GetPointer(), toStringFlags, tabCount, tabSize));
            } break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            {
                // NOP, The data was output in the pNext chain above.
            } break;
            /// @todo This should be fine as the data was output in the pNext chain above
            //  via generated code but needs checking on RADV.
            case VK_DESCRIPTOR_TYPE_MUTABLE_VALVE:
            /// @todo This should also be fine, as the code to output the related data via
            /// the pNext chain above is all generated but needs checking with a trace using
            /// the old NV RT extension:
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            {
                GFXRECON_LOG_WARNING_ONCE("Untested descriptorType in VkWriteDescriptorSet: %s.", ToString(obj.descriptorType, 0, 0, 0).c_str());
            } break;
            default: 
            {
                GFXRECON_LOG_ERROR("Unknown descriptorType in VkWriteDescriptorSet: %s.", ToString(obj.descriptorType, 0, 0, 0).c_str());
            }
            break;
            }
        }
    );
}

template <>
std::string ToString<decode::Decoded_VkAccelerationStructureBuildGeometryInfoKHR>(const decode::Decoded_VkAccelerationStructureBuildGeometryInfoKHR& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkAccelerationStructureBuildGeometryInfoKHR& obj = *decoded_obj.decoded_value;

    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.mode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "srcAccelerationStructure", toStringFlags, tabCount, tabSize, ToString(decoded_obj.srcAccelerationStructure));
            FieldToString(strStrm, false, "dstAccelerationStructure", toStringFlags, tabCount, tabSize, ToString(decoded_obj.dstAccelerationStructure));
            FieldToString(strStrm, false, "geometryCount", toStringFlags, tabCount, tabSize, ToString(obj.geometryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGeometries", toStringFlags, tabCount, tabSize, decode::PointerDecoderArrayToString(*decoded_obj.pGeometries, toStringFlags, tabCount, tabSize));
            // If ppGeometries is non-null, step through and process the decoded struct pointed-to by any non-null elements in it:
            FieldToString(strStrm, false, "ppGeometries", toStringFlags, tabCount, tabSize,
                decoded_obj.ppGeometries ? ArrayToString(decoded_obj.ppGeometries->GetLength(), decoded_obj.ppGeometries->GetMetaStructPointer(), toStringFlags, tabCount, tabSize,
                    // Lambda for checking whether to turn the array into a string at all:
                    [&]()
                    {
                        return decoded_obj.ppGeometries != nullptr && decoded_obj.ppGeometries->GetLength() > 0u && decoded_obj.ppGeometries->GetMetaStructPointer() != nullptr;
                    },
                    // Lambda for turning one element of the array into a string:
                    [&](uint32_t i)
                    {
                        decode::Decoded_VkAccelerationStructureGeometryKHR* geom = decoded_obj.ppGeometries->GetMetaStructPointer()[i];
                        if(nullptr != geom)
                        {
                            return ToString(*geom, toStringFlags, tabCount, tabSize);
                        }
                        else
                        {
                            return std::string(decode::GFXRECON_TOJSON_NULL);
                        }
                    }
                )
                : decode::GFXRECON_TOJSON_NULL
            );
            FieldToString(strStrm, false, "scratchData", toStringFlags, tabCount, tabSize, ToString(obj.scratchData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<decode::Decoded_VkAccelerationStructureVersionInfoKHR>(const decode::Decoded_VkAccelerationStructureVersionInfoKHR& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkAccelerationStructureVersionInfoKHR& obj = *decoded_obj.decoded_value;

    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVersionData", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.pVersionData) + '"');
        }
    );
}


// Call through to raw Vulkan struct as no handles are reachable.
template <>
std::string ToString<decode::Decoded_VkPhysicalDeviceMemoryProperties>(const decode::Decoded_VkPhysicalDeviceMemoryProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}


// Mostly POD but we need to traverse the pNext on the Decoded side.
template <>
std::string ToString<decode::Decoded_VkPipelineMultisampleStateCreateInfo>(const decode::Decoded_VkPipelineMultisampleStateCreateInfo& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkPipelineMultisampleStateCreateInfo& obj = *decoded_obj.decoded_value;
    
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationSamples", toStringFlags, tabCount, tabSize, '"' + ToString(obj.rasterizationSamples, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "sampleShadingEnable", toStringFlags, tabCount, tabSize, ToString(obj.sampleShadingEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSampleShading", toStringFlags, tabCount, tabSize, ToString(obj.minSampleShading, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSampleMask", toStringFlags, tabCount, tabSize, ArrayToString(std::min(1, static_cast<int>(obj.rasterizationSamples) / 32), obj.pSampleMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "alphaToCoverageEnable", toStringFlags, tabCount, tabSize, ToString(obj.alphaToCoverageEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "alphaToOneEnable", toStringFlags, tabCount, tabSize, ToString(obj.alphaToOneEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

// Mostly POD but we need to traverse the pNext on the Decoded side.
template <>
std::string ToString<decode::Decoded_VkShaderModuleCreateInfo>(const decode::Decoded_VkShaderModuleCreateInfo& decoded_obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(decoded_obj.decoded_value == nullptr)
    {
        return "null";
    }
    const VkShaderModuleCreateInfo& obj = *decoded_obj.decoded_value;

    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextDecodedToString(decoded_obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "codeSize", toStringFlags, tabCount, tabSize, ToString(obj.codeSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCode", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(&decoded_obj.pCode));
        }
    );
}

// It is just twelve floats so call through to the raw vulkan struct version.
template <>
std::string ToString<decode::Decoded_VkTransformMatrixKHR>(const decode::Decoded_VkTransformMatrixKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "null";
}

// clang-format on

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
