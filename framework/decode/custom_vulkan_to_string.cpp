/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "custom_vulkan_to_string.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_to_string.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// clang-format off

// NOTE : The following structures' ToString() functions aren't generated due
//  to various reasons...ie unions, non standard counts for arrays, fields that
//  need validation to interpret correctly, etc...

template <>
std::string ToString<SECURITY_ATTRIBUTES>(const SECURITY_ATTRIBUTES& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "nLength", toStringFlags, tabCount, tabSize, ToString(obj.nLength, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lpSecurityDescriptor", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.lpSecurityDescriptor) + '"');
            FieldToString(strStrm, false, "bInheritHandle", toStringFlags, tabCount, tabSize, ToString(obj.bInheritHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkAccelerationStructureGeometryKHR>(const VkAccelerationStructureGeometryKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.geometryType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "geometry", toStringFlags, tabCount, tabSize, ToString(obj.geometry, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkAccelerationStructureGeometryDataKHR>(const VkAccelerationStructureGeometryDataKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "triangles", toStringFlags, tabCount, tabSize, ToString(obj.triangles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "aabbs", toStringFlags, tabCount, tabSize, ToString(obj.aabbs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instances", toStringFlags, tabCount, tabSize, ToString(obj.instances, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkAccelerationStructureMotionInstanceDataNV>(const VkAccelerationStructureMotionInstanceDataNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "staticInstance", toStringFlags, tabCount, tabSize, ToString(obj.staticInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "matrixMotionInstance", toStringFlags, tabCount, tabSize, ToString(obj.matrixMotionInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srtMotionInstance", toStringFlags, tabCount, tabSize, ToString(obj.srtMotionInstance, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkClearColorValue>(const VkClearColorValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "float32", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.float32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "int32", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.int32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uint32", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.uint32, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkClearValue>(const VkClearValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "color", toStringFlags, tabCount, tabSize, ToString(obj.color, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthStencil", toStringFlags, tabCount, tabSize, ToString(obj.depthStencil, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkDescriptorImageInfo>(const VkDescriptorImageInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sampler", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.sampler) + '"');
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.imageView) + '"');
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"'+ ToString(obj.imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

template <>
std::string ToString<VkDeviceOrHostAddressConstKHR>(const VkDeviceOrHostAddressConstKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "deviceAddress", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.deviceAddress) + '"');
            FieldToString(strStrm, false, "hostAddress", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.hostAddress) + '"');
        }
    );
}

template <>
std::string ToString<VkDeviceOrHostAddressKHR>(const VkDeviceOrHostAddressKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "deviceAddress", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.deviceAddress) + '"');
            FieldToString(strStrm, false, "hostAddress", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.hostAddress) + '"');
        }
    );
}

template <>
std::string ToString<VkPerformanceCounterResultKHR>(const VkPerformanceCounterResultKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "int32", toStringFlags, tabCount, tabSize, ToString(obj.int32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "int64", toStringFlags, tabCount, tabSize, ToString(obj.int64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uint32", toStringFlags, tabCount, tabSize, ToString(obj.uint32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uint64", toStringFlags, tabCount, tabSize, ToString(obj.uint64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "float32", toStringFlags, tabCount, tabSize, ToString(obj.float32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "float64", toStringFlags, tabCount, tabSize, ToString(obj.float64, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkPerformanceValueDataINTEL>(const VkPerformanceValueDataINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "value32", toStringFlags, tabCount, tabSize, ToString(obj.value32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "value64", toStringFlags, tabCount, tabSize, ToString(obj.value64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "valueFloat", toStringFlags, tabCount, tabSize, ToString(obj.valueFloat, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "valueBool", toStringFlags, tabCount, tabSize, ToString(obj.valueBool, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "valueString", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.valueString) + '"');
        }
    );
}

template <>
std::string ToString<VkPerformanceValueINTEL>(const VkPerformanceValueINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(obj.data, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkPipelineExecutableStatisticValueKHR>(const VkPipelineExecutableStatisticValueKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "b32", toStringFlags, tabCount, tabSize, ToString(obj.b32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "i64", toStringFlags, tabCount, tabSize, ToString(obj.i64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "u64", toStringFlags, tabCount, tabSize, ToString(obj.u64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "f64", toStringFlags, tabCount, tabSize, ToString(obj.f64, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkWriteDescriptorSet>(const VkWriteDescriptorSet& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSet", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.dstSet) + '"');
            FieldToString(strStrm, false, "dstBinding", toStringFlags, tabCount, tabSize, ToString(obj.dstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstArrayElement", toStringFlags, tabCount, tabSize, ToString(obj.dstArrayElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.descriptorType, toStringFlags, tabCount, tabSize) + '"');
            const VkDescriptorImageInfo* pImageInfo = nullptr;
            const VkDescriptorBufferInfo* pBufferInfo = nullptr;
            const VkBufferView* pTexelBufferView = nullptr;
            switch (obj.descriptorType)
            {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                pImageInfo = obj.pImageInfo;
            } break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                pBufferInfo = obj.pBufferInfo;
            } break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            {
                pTexelBufferView = obj.pTexelBufferView;
            } break;
            default: break;
            }
            FieldToString(strStrm, false, "pImageInfo", toStringFlags, tabCount, tabSize, ArrayToString(obj.descriptorCount, pImageInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferInfo", toStringFlags, tabCount, tabSize, ArrayToString(obj.descriptorCount, pBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTexelBufferView", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.descriptorCount, pTexelBufferView, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkAccelerationStructureBuildGeometryInfoKHR>(const VkAccelerationStructureBuildGeometryInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(obj.type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, '"' + ToString(obj.mode, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "srcAccelerationStructure", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.srcAccelerationStructure) + '"');
            FieldToString(strStrm, false, "dstAccelerationStructure", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.dstAccelerationStructure) + '"');
            FieldToString(strStrm, false, "geometryCount", toStringFlags, tabCount, tabSize, ToString(obj.geometryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGeometries", toStringFlags, tabCount, tabSize, ArrayToString(obj.geometryCount, obj.pGeometries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppGeometries", toStringFlags, tabCount, tabSize,
                ArrayToString(obj.geometryCount, obj.pGeometries, toStringFlags, tabCount, tabSize,
                    [&]()
                    {
                        return obj.geometryCount && obj.ppGeometries != nullptr;
                    },
                    [&](uint32_t i)
                    {
                        return obj.ppGeometries[i] ? ToString(*obj.ppGeometries[i], toStringFlags, tabCount, tabSize) : "null";
                    }
                )
            );
            FieldToString(strStrm, false, "scratchData", toStringFlags, tabCount, tabSize, ToString(obj.scratchData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkAccelerationStructureVersionInfoKHR>(const VkAccelerationStructureVersionInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVersionData", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.pVersionData) + '"');
        }
    );
}

template <>
std::string ToString<VkPhysicalDeviceMemoryProperties>(const VkPhysicalDeviceMemoryProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "memoryTypeCount", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypes", toStringFlags, tabCount, tabSize, ArrayToString(obj.memoryTypeCount, obj.memoryTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryHeapCount", toStringFlags, tabCount, tabSize, ToString(obj.memoryHeapCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryHeaps", toStringFlags, tabCount, tabSize, ArrayToString(obj.memoryHeapCount, obj.memoryHeaps, toStringFlags, tabCount, tabSize));
        }
    );
}

template <>
std::string ToString<VkPipelineMultisampleStateCreateInfo>(const VkPipelineMultisampleStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
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

template <>
std::string ToString<VkShaderModuleCreateInfo>(const VkShaderModuleCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "codeSize", toStringFlags, tabCount, tabSize, ToString(obj.codeSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCode", toStringFlags, tabCount, tabSize, '"' + PtrToString(obj.pCode) + '"');
        }
    );
}

template <>
std::string ToString<VkTransformMatrixKHR>(const VkTransformMatrixKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            std::string strs[3][4];
            size_t maxStrLength = 0;
            for (size_t y = 0; y < 3; ++y)
            {
                for (size_t x = 0; x < 4; ++x)
                {
                    strs[y][x] = std::to_string(obj.matrix[y][x]);
                    maxStrLength = std::max(maxStrLength, strs[y][x].size());
                }
            }
            FieldToString(strStrm, true, "matrix", toStringFlags, tabCount, tabSize,
                ArrayToString(3, obj.matrix, toStringFlags, tabCount, tabSize,
                    [&]()
                    {
                        return true;
                    },
                    [&](uint32_t y)
                    {
                        std::stringstream rowStrStrm;
                        rowStrStrm << '[' << GetWhitespaceString(toStringFlags);
                        for (size_t x = 0; x < 4; ++x)
                        {
                            if (x)
                            {
                                rowStrStrm << ',' << GetWhitespaceString(toStringFlags);
                            }
                            if (strs[y][x].size() < maxStrLength)
                            {
                                strs[y][x].insert(0, maxStrLength - strs[y][x].size(), ' ');
                            }
                            rowStrStrm << strs[y][x];
                        }
                        rowStrStrm << GetWhitespaceString(toStringFlags) << ']';
                        return rowStrStrm.str();
                    }
                )
            );
        }
    );
}

// clang-format on

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
