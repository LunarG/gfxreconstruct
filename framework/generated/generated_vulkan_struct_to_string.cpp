/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "util/custom_vulkan_to_string.h"
#include "generated_vulkan_struct_to_string.h"
#include "generated_vulkan_enum_to_string.h"
#include "decode/custom_vulkan_ascii_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
template <> std::string ToString<VkExtent2D>(const VkExtent2D& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExtent3D>(const VkExtent3D& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depth", toStringFlags, tabCount, tabSize, ToString(obj.depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkOffset2D>(const VkOffset2D& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkOffset3D>(const VkOffset3D& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "z", toStringFlags, tabCount, tabSize, ToString(obj.z, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRect2D>(const VkRect2D& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferMemoryBarrier>(const VkBufferMemoryBarrier& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.srcAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.dstAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.srcQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.dstQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDispatchIndirectCommand>(const VkDispatchIndirectCommand& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "z", toStringFlags, tabCount, tabSize, ToString(obj.z, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrawIndexedIndirectCommand>(const VkDrawIndexedIndirectCommand& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "indexCount", toStringFlags, tabCount, tabSize, ToString(obj.indexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(obj.instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstIndex", toStringFlags, tabCount, tabSize, ToString(obj.firstIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexOffset", toStringFlags, tabCount, tabSize, ToString(obj.vertexOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(obj.firstInstance, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrawIndirectCommand>(const VkDrawIndirectCommand& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "vertexCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(obj.instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstVertex", toStringFlags, tabCount, tabSize, ToString(obj.firstVertex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(obj.firstInstance, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageSubresourceRange>(const VkImageSubresourceRange& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseMipLevel", toStringFlags, tabCount, tabSize, ToString(obj.baseMipLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "levelCount", toStringFlags, tabCount, tabSize, ToString(obj.levelCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseArrayLayer", toStringFlags, tabCount, tabSize, ToString(obj.baseArrayLayer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageMemoryBarrier>(const VkImageMemoryBarrier& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.srcAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.dstAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "oldLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.oldLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "newLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.newLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "srcQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.srcQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.dstQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "subresourceRange", toStringFlags, tabCount, tabSize, ToString(obj.subresourceRange, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryBarrier>(const VkMemoryBarrier& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.srcAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.dstAccessMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCacheHeaderVersionOne>(const VkPipelineCacheHeaderVersionOne& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "headerSize", toStringFlags, tabCount, tabSize, ToString(obj.headerSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "headerVersion", toStringFlags, tabCount, tabSize, Quote(ToString(obj.headerVersion, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "vendorID", toStringFlags, tabCount, tabSize, ToString(obj.vendorID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceID", toStringFlags, tabCount, tabSize, ToString(obj.deviceID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineCacheUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.pipelineCacheUUID)));
        }
    );
}

template <> std::string ToString<VkAllocationCallbacks>(const VkAllocationCallbacks& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pUserData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pUserData)));
            FieldToString(strStrm, false, "pfnAllocation", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnAllocation)));
            FieldToString(strStrm, false, "pfnReallocation", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnReallocation)));
            FieldToString(strStrm, false, "pfnFree", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnFree)));
            FieldToString(strStrm, false, "pfnInternalAllocation", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnInternalAllocation)));
            FieldToString(strStrm, false, "pfnInternalFree", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnInternalFree)));
        }
    );
}

template <> std::string ToString<VkApplicationInfo>(const VkApplicationInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pApplicationName", toStringFlags, tabCount, tabSize, CStrToString(obj.pApplicationName));
            FieldToString(strStrm, false, "applicationVersion", toStringFlags, tabCount, tabSize, ToString(obj.applicationVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEngineName", toStringFlags, tabCount, tabSize, CStrToString(obj.pEngineName));
            FieldToString(strStrm, false, "engineVersion", toStringFlags, tabCount, tabSize, ToString(obj.engineVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "apiVersion", toStringFlags, tabCount, tabSize, ToString(obj.apiVersion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFormatProperties>(const VkFormatProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "linearTilingFeatures", toStringFlags, tabCount, tabSize, ToString(obj.linearTilingFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "optimalTilingFeatures", toStringFlags, tabCount, tabSize, ToString(obj.optimalTilingFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferFeatures", toStringFlags, tabCount, tabSize, ToString(obj.bufferFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageFormatProperties>(const VkImageFormatProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "maxExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMipLevels", toStringFlags, tabCount, tabSize, ToString(obj.maxMipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxResourceSize", toStringFlags, tabCount, tabSize, ToString(obj.maxResourceSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkInstanceCreateInfo>(const VkInstanceCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pApplicationInfo", toStringFlags, tabCount, tabSize, (obj.pApplicationInfo ? ToString(*obj.pApplicationInfo, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "enabledLayerCount", toStringFlags, tabCount, tabSize, ToString(obj.enabledLayerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppEnabledLayerNames", toStringFlags, tabCount, tabSize, CStrArrayToString(obj.enabledLayerCount, obj.ppEnabledLayerNames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "enabledExtensionCount", toStringFlags, tabCount, tabSize, ToString(obj.enabledExtensionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppEnabledExtensionNames", toStringFlags, tabCount, tabSize, CStrArrayToString(obj.enabledExtensionCount, obj.ppEnabledExtensionNames, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryHeap>(const VkMemoryHeap& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryType>(const VkMemoryType& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "propertyFlags", toStringFlags, tabCount, tabSize, ToString(obj.propertyFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(obj.heapIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFeatures>(const VkPhysicalDeviceFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "robustBufferAccess", toStringFlags, tabCount, tabSize, ToString(obj.robustBufferAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fullDrawIndexUint32", toStringFlags, tabCount, tabSize, ToString(obj.fullDrawIndexUint32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCubeArray", toStringFlags, tabCount, tabSize, ToString(obj.imageCubeArray, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "independentBlend", toStringFlags, tabCount, tabSize, ToString(obj.independentBlend, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryShader", toStringFlags, tabCount, tabSize, ToString(obj.geometryShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tessellationShader", toStringFlags, tabCount, tabSize, ToString(obj.tessellationShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleRateShading", toStringFlags, tabCount, tabSize, ToString(obj.sampleRateShading, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dualSrcBlend", toStringFlags, tabCount, tabSize, ToString(obj.dualSrcBlend, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "logicOp", toStringFlags, tabCount, tabSize, ToString(obj.logicOp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiDrawIndirect", toStringFlags, tabCount, tabSize, ToString(obj.multiDrawIndirect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawIndirectFirstInstance", toStringFlags, tabCount, tabSize, ToString(obj.drawIndirectFirstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClamp", toStringFlags, tabCount, tabSize, ToString(obj.depthClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.depthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fillModeNonSolid", toStringFlags, tabCount, tabSize, ToString(obj.fillModeNonSolid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBounds", toStringFlags, tabCount, tabSize, ToString(obj.depthBounds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "wideLines", toStringFlags, tabCount, tabSize, ToString(obj.wideLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "largePoints", toStringFlags, tabCount, tabSize, ToString(obj.largePoints, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "alphaToOne", toStringFlags, tabCount, tabSize, ToString(obj.alphaToOne, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiViewport", toStringFlags, tabCount, tabSize, ToString(obj.multiViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.samplerAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureCompressionETC2", toStringFlags, tabCount, tabSize, ToString(obj.textureCompressionETC2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureCompressionASTC_LDR", toStringFlags, tabCount, tabSize, ToString(obj.textureCompressionASTC_LDR, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureCompressionBC", toStringFlags, tabCount, tabSize, ToString(obj.textureCompressionBC, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "occlusionQueryPrecise", toStringFlags, tabCount, tabSize, ToString(obj.occlusionQueryPrecise, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineStatisticsQuery", toStringFlags, tabCount, tabSize, ToString(obj.pipelineStatisticsQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexPipelineStoresAndAtomics", toStringFlags, tabCount, tabSize, ToString(obj.vertexPipelineStoresAndAtomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentStoresAndAtomics", toStringFlags, tabCount, tabSize, ToString(obj.fragmentStoresAndAtomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderTessellationAndGeometryPointSize", toStringFlags, tabCount, tabSize, ToString(obj.shaderTessellationAndGeometryPointSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderImageGatherExtended", toStringFlags, tabCount, tabSize, ToString(obj.shaderImageGatherExtended, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageExtendedFormats", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageExtendedFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageMultisample", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageMultisample, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageReadWithoutFormat", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageReadWithoutFormat, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageWriteWithoutFormat", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageWriteWithoutFormat, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampledImageArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampledImageArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderClipDistance", toStringFlags, tabCount, tabSize, ToString(obj.shaderClipDistance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderCullDistance", toStringFlags, tabCount, tabSize, ToString(obj.shaderCullDistance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInt64", toStringFlags, tabCount, tabSize, ToString(obj.shaderInt64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInt16", toStringFlags, tabCount, tabSize, ToString(obj.shaderInt16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderResourceResidency", toStringFlags, tabCount, tabSize, ToString(obj.shaderResourceResidency, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderResourceMinLod", toStringFlags, tabCount, tabSize, ToString(obj.shaderResourceMinLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseBinding", toStringFlags, tabCount, tabSize, ToString(obj.sparseBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidencyBuffer", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidencyBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidencyImage2D", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidencyImage2D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidencyImage3D", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidencyImage3D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidency2Samples", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidency2Samples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidency4Samples", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidency4Samples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidency8Samples", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidency8Samples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidency16Samples", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidency16Samples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseResidencyAliased", toStringFlags, tabCount, tabSize, ToString(obj.sparseResidencyAliased, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variableMultisampleRate", toStringFlags, tabCount, tabSize, ToString(obj.variableMultisampleRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inheritedQueries", toStringFlags, tabCount, tabSize, ToString(obj.inheritedQueries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceLimits>(const VkPhysicalDeviceLimits& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "maxImageDimension1D", toStringFlags, tabCount, tabSize, ToString(obj.maxImageDimension1D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageDimension2D", toStringFlags, tabCount, tabSize, ToString(obj.maxImageDimension2D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageDimension3D", toStringFlags, tabCount, tabSize, ToString(obj.maxImageDimension3D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageDimensionCube", toStringFlags, tabCount, tabSize, ToString(obj.maxImageDimensionCube, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxImageArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTexelBufferElements", toStringFlags, tabCount, tabSize, ToString(obj.maxTexelBufferElements, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxUniformBufferRange", toStringFlags, tabCount, tabSize, ToString(obj.maxUniformBufferRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStorageBufferRange", toStringFlags, tabCount, tabSize, ToString(obj.maxStorageBufferRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPushConstantsSize", toStringFlags, tabCount, tabSize, ToString(obj.maxPushConstantsSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMemoryAllocationCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMemoryAllocationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSamplerAllocationCount", toStringFlags, tabCount, tabSize, ToString(obj.maxSamplerAllocationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferImageGranularity", toStringFlags, tabCount, tabSize, ToString(obj.bufferImageGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseAddressSpaceSize", toStringFlags, tabCount, tabSize, ToString(obj.sparseAddressSpaceSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBoundDescriptorSets", toStringFlags, tabCount, tabSize, ToString(obj.maxBoundDescriptorSets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageResources", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageResources, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUniformBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUniformBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetStorageBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetStorageBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexInputAttributes", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexInputAttributes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexInputBindings", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexInputBindings, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexInputAttributeOffset", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexInputAttributeOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexInputBindingStride", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexInputBindingStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationGenerationLevel", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationGenerationLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationPatchSize", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationPatchSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationControlPerVertexInputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationControlPerVertexInputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationControlPerVertexOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationControlPerVertexOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationControlPerPatchOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationControlPerPatchOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationControlTotalOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationControlTotalOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationEvaluationInputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationEvaluationInputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTessellationEvaluationOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxTessellationEvaluationOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryShaderInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryShaderInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryInputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryInputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryOutputVertices", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryOutputVertices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryTotalOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryTotalOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentInputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentInputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentOutputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentOutputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentDualSrcAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentDualSrcAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentCombinedOutputResources", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentCombinedOutputResources, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeSharedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxComputeSharedMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeWorkGroupCount", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxComputeWorkGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxComputeWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxComputeWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subPixelPrecisionBits", toStringFlags, tabCount, tabSize, ToString(obj.subPixelPrecisionBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subTexelPrecisionBits", toStringFlags, tabCount, tabSize, ToString(obj.subTexelPrecisionBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mipmapPrecisionBits", toStringFlags, tabCount, tabSize, ToString(obj.mipmapPrecisionBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawIndexedIndexValue", toStringFlags, tabCount, tabSize, ToString(obj.maxDrawIndexedIndexValue, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawIndirectCount", toStringFlags, tabCount, tabSize, ToString(obj.maxDrawIndirectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSamplerLodBias", toStringFlags, tabCount, tabSize, ToString(obj.maxSamplerLodBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSamplerAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.maxSamplerAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxViewports", toStringFlags, tabCount, tabSize, ToString(obj.maxViewports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxViewportDimensions", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.maxViewportDimensions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportBoundsRange", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.viewportBoundsRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportSubPixelBits", toStringFlags, tabCount, tabSize, ToString(obj.viewportSubPixelBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minMemoryMapAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minMemoryMapAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minTexelBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minTexelBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minUniformBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minUniformBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minStorageBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minStorageBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minTexelOffset", toStringFlags, tabCount, tabSize, ToString(obj.minTexelOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTexelOffset", toStringFlags, tabCount, tabSize, ToString(obj.maxTexelOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minTexelGatherOffset", toStringFlags, tabCount, tabSize, ToString(obj.minTexelGatherOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTexelGatherOffset", toStringFlags, tabCount, tabSize, ToString(obj.maxTexelGatherOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minInterpolationOffset", toStringFlags, tabCount, tabSize, ToString(obj.minInterpolationOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInterpolationOffset", toStringFlags, tabCount, tabSize, ToString(obj.maxInterpolationOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subPixelInterpolationOffsetBits", toStringFlags, tabCount, tabSize, ToString(obj.subPixelInterpolationOffsetBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFramebufferWidth", toStringFlags, tabCount, tabSize, ToString(obj.maxFramebufferWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFramebufferHeight", toStringFlags, tabCount, tabSize, ToString(obj.maxFramebufferHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFramebufferLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxFramebufferLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebufferColorSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.framebufferColorSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebufferDepthSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.framebufferDepthSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebufferStencilSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.framebufferStencilSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebufferNoAttachmentsSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.framebufferNoAttachmentsSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxColorAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxColorAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampledImageColorSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampledImageColorSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampledImageIntegerSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampledImageIntegerSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampledImageDepthSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampledImageDepthSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampledImageStencilSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampledImageStencilSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageImageSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.storageImageSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSampleMaskWords", toStringFlags, tabCount, tabSize, ToString(obj.maxSampleMaskWords, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timestampComputeAndGraphics", toStringFlags, tabCount, tabSize, ToString(obj.timestampComputeAndGraphics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timestampPeriod", toStringFlags, tabCount, tabSize, ToString(obj.timestampPeriod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxClipDistances", toStringFlags, tabCount, tabSize, ToString(obj.maxClipDistances, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxCullDistances", toStringFlags, tabCount, tabSize, ToString(obj.maxCullDistances, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxCombinedClipAndCullDistances", toStringFlags, tabCount, tabSize, ToString(obj.maxCombinedClipAndCullDistances, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "discreteQueuePriorities", toStringFlags, tabCount, tabSize, ToString(obj.discreteQueuePriorities, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pointSizeRange", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.pointSizeRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineWidthRange", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.lineWidthRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pointSizeGranularity", toStringFlags, tabCount, tabSize, ToString(obj.pointSizeGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineWidthGranularity", toStringFlags, tabCount, tabSize, ToString(obj.lineWidthGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "strictLines", toStringFlags, tabCount, tabSize, ToString(obj.strictLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "standardSampleLocations", toStringFlags, tabCount, tabSize, ToString(obj.standardSampleLocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "optimalBufferCopyOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.optimalBufferCopyOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "optimalBufferCopyRowPitchAlignment", toStringFlags, tabCount, tabSize, ToString(obj.optimalBufferCopyRowPitchAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "nonCoherentAtomSize", toStringFlags, tabCount, tabSize, ToString(obj.nonCoherentAtomSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSparseProperties>(const VkPhysicalDeviceSparseProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "residencyStandard2DBlockShape", toStringFlags, tabCount, tabSize, ToString(obj.residencyStandard2DBlockShape, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "residencyStandard2DMultisampleBlockShape", toStringFlags, tabCount, tabSize, ToString(obj.residencyStandard2DMultisampleBlockShape, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "residencyStandard3DBlockShape", toStringFlags, tabCount, tabSize, ToString(obj.residencyStandard3DBlockShape, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "residencyAlignedMipSize", toStringFlags, tabCount, tabSize, ToString(obj.residencyAlignedMipSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "residencyNonResidentStrict", toStringFlags, tabCount, tabSize, ToString(obj.residencyNonResidentStrict, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProperties>(const VkPhysicalDeviceProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "apiVersion", toStringFlags, tabCount, tabSize, ToString(obj.apiVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "driverVersion", toStringFlags, tabCount, tabSize, ToString(obj.driverVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vendorID", toStringFlags, tabCount, tabSize, ToString(obj.vendorID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceID", toStringFlags, tabCount, tabSize, ToString(obj.deviceID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.deviceType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "deviceName", toStringFlags, tabCount, tabSize, CStrToString(obj.deviceName));
            FieldToString(strStrm, false, "pipelineCacheUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.pipelineCacheUUID)));
            FieldToString(strStrm, false, "limits", toStringFlags, tabCount, tabSize, ToString(obj.limits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseProperties", toStringFlags, tabCount, tabSize, ToString(obj.sparseProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyProperties>(const VkQueueFamilyProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queueFlags", toStringFlags, tabCount, tabSize, ToString(obj.queueFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueCount", toStringFlags, tabCount, tabSize, ToString(obj.queueCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timestampValidBits", toStringFlags, tabCount, tabSize, ToString(obj.timestampValidBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minImageTransferGranularity", toStringFlags, tabCount, tabSize, ToString(obj.minImageTransferGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceQueueCreateInfo>(const VkDeviceQueueCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueCount", toStringFlags, tabCount, tabSize, ToString(obj.queueCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueuePriorities", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueCount, obj.pQueuePriorities, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceCreateInfo>(const VkDeviceCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueCreateInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.queueCreateInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueCreateInfos", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueCreateInfoCount, obj.pQueueCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "enabledLayerCount", toStringFlags, tabCount, tabSize, ToString(obj.enabledLayerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppEnabledLayerNames", toStringFlags, tabCount, tabSize, CStrArrayToString(obj.enabledLayerCount, obj.ppEnabledLayerNames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "enabledExtensionCount", toStringFlags, tabCount, tabSize, ToString(obj.enabledExtensionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppEnabledExtensionNames", toStringFlags, tabCount, tabSize, CStrArrayToString(obj.enabledExtensionCount, obj.ppEnabledExtensionNames, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEnabledFeatures", toStringFlags, tabCount, tabSize, (obj.pEnabledFeatures ? ToString(*obj.pEnabledFeatures, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkExtensionProperties>(const VkExtensionProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "extensionName", toStringFlags, tabCount, tabSize, CStrToString(obj.extensionName));
            FieldToString(strStrm, false, "specVersion", toStringFlags, tabCount, tabSize, ToString(obj.specVersion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkLayerProperties>(const VkLayerProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "layerName", toStringFlags, tabCount, tabSize, CStrToString(obj.layerName));
            FieldToString(strStrm, false, "specVersion", toStringFlags, tabCount, tabSize, ToString(obj.specVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "implementationVersion", toStringFlags, tabCount, tabSize, ToString(obj.implementationVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
        }
    );
}

template <> std::string ToString<VkSubmitInfo>(const VkSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.waitSemaphoreCount, obj.pWaitSemaphores, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitDstStageMask", toStringFlags, tabCount, tabSize, ArrayToString(obj.waitSemaphoreCount, obj.pWaitDstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(obj.commandBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBuffers", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.commandBufferCount, obj.pCommandBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.signalSemaphoreCount, obj.pSignalSemaphores, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMappedMemoryRange>(const VkMappedMemoryRange& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryAllocateInfo>(const VkMemoryAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "allocationSize", toStringFlags, tabCount, tabSize, ToString(obj.allocationSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeIndex", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryRequirements>(const VkMemoryRequirements& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "alignment", toStringFlags, tabCount, tabSize, ToString(obj.alignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseMemoryBind>(const VkSparseMemoryBind& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "resourceOffset", toStringFlags, tabCount, tabSize, ToString(obj.resourceOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseBufferMemoryBindInfo>(const VkSparseBufferMemoryBindInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "bindCount", toStringFlags, tabCount, tabSize, ToString(obj.bindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.bindCount, obj.pBinds, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageOpaqueMemoryBindInfo>(const VkSparseImageOpaqueMemoryBindInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "bindCount", toStringFlags, tabCount, tabSize, ToString(obj.bindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.bindCount, obj.pBinds, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageSubresource>(const VkImageSubresource& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mipLevel", toStringFlags, tabCount, tabSize, ToString(obj.mipLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "arrayLayer", toStringFlags, tabCount, tabSize, ToString(obj.arrayLayer, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageMemoryBind>(const VkSparseImageMemoryBind& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "subresource", toStringFlags, tabCount, tabSize, ToString(obj.subresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageMemoryBindInfo>(const VkSparseImageMemoryBindInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "bindCount", toStringFlags, tabCount, tabSize, ToString(obj.bindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.bindCount, obj.pBinds, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindSparseInfo>(const VkBindSparseInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.waitSemaphoreCount, obj.pWaitSemaphores, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferBindCount", toStringFlags, tabCount, tabSize, ToString(obj.bufferBindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.bufferBindCount, obj.pBufferBinds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageOpaqueBindCount", toStringFlags, tabCount, tabSize, ToString(obj.imageOpaqueBindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageOpaqueBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.imageOpaqueBindCount, obj.pImageOpaqueBinds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageBindCount", toStringFlags, tabCount, tabSize, ToString(obj.imageBindCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageBinds", toStringFlags, tabCount, tabSize, ArrayToString(obj.imageBindCount, obj.pImageBinds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.signalSemaphoreCount, obj.pSignalSemaphores, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageFormatProperties>(const VkSparseImageFormatProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageGranularity", toStringFlags, tabCount, tabSize, ToString(obj.imageGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageMemoryRequirements>(const VkSparseImageMemoryRequirements& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "formatProperties", toStringFlags, tabCount, tabSize, ToString(obj.formatProperties, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMipTailFirstLod", toStringFlags, tabCount, tabSize, ToString(obj.imageMipTailFirstLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMipTailSize", toStringFlags, tabCount, tabSize, ToString(obj.imageMipTailSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMipTailOffset", toStringFlags, tabCount, tabSize, ToString(obj.imageMipTailOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMipTailStride", toStringFlags, tabCount, tabSize, ToString(obj.imageMipTailStride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFenceCreateInfo>(const VkFenceCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreCreateInfo>(const VkSemaphoreCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkEventCreateInfo>(const VkEventCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueryPoolCreateInfo>(const VkQueryPoolCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.queryType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(obj.queryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineStatistics", toStringFlags, tabCount, tabSize, ToString(obj.pipelineStatistics, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferCreateInfo>(const VkBufferCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sharingMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sharingMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queueFamilyIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueFamilyIndexCount, obj.pQueueFamilyIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferViewCreateInfo>(const VkBufferViewCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "range", toStringFlags, tabCount, tabSize, ToString(obj.range, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageCreateInfo>(const VkImageCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mipLevels", toStringFlags, tabCount, tabSize, ToString(obj.mipLevels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "arrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.arrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.tiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sharingMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sharingMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queueFamilyIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueFamilyIndexCount, obj.pQueueFamilyIndices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.initialLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSubresourceLayout>(const VkSubresourceLayout& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rowPitch", toStringFlags, tabCount, tabSize, ToString(obj.rowPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "arrayPitch", toStringFlags, tabCount, tabSize, ToString(obj.arrayPitch, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthPitch", toStringFlags, tabCount, tabSize, ToString(obj.depthPitch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkComponentMapping>(const VkComponentMapping& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "r", toStringFlags, tabCount, tabSize, Quote(ToString(obj.r, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "g", toStringFlags, tabCount, tabSize, Quote(ToString(obj.g, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "b", toStringFlags, tabCount, tabSize, Quote(ToString(obj.b, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "a", toStringFlags, tabCount, tabSize, Quote(ToString(obj.a, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImageViewCreateInfo>(const VkImageViewCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "viewType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.viewType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "components", toStringFlags, tabCount, tabSize, ToString(obj.components, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subresourceRange", toStringFlags, tabCount, tabSize, ToString(obj.subresourceRange, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCacheCreateInfo>(const VkPipelineCacheCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialDataSize", toStringFlags, tabCount, tabSize, ToString(obj.initialDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInitialData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pInitialData)));
        }
    );
}

template <> std::string ToString<VkSpecializationMapEntry>(const VkSpecializationMapEntry& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "constantID", toStringFlags, tabCount, tabSize, ToString(obj.constantID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSpecializationInfo>(const VkSpecializationInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "mapEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.mapEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMapEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.mapEntryCount, obj.pMapEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(obj.dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pData)));
        }
    );
}

template <> std::string ToString<VkPipelineShaderStageCreateInfo>(const VkPipelineShaderStageCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stage, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "module", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.module)));
            FieldToString(strStrm, false, "pName", toStringFlags, tabCount, tabSize, CStrToString(obj.pName));
            FieldToString(strStrm, false, "pSpecializationInfo", toStringFlags, tabCount, tabSize, (obj.pSpecializationInfo ? ToString(*obj.pSpecializationInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkComputePipelineCreateInfo>(const VkComputePipelineCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, ToString(obj.stage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.layout)));
            FieldToString(strStrm, false, "basePipelineHandle", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.basePipelineHandle)));
            FieldToString(strStrm, false, "basePipelineIndex", toStringFlags, tabCount, tabSize, ToString(obj.basePipelineIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVertexInputBindingDescription>(const VkVertexInputBindingDescription& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputRate", toStringFlags, tabCount, tabSize, Quote(ToString(obj.inputRate, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkVertexInputAttributeDescription>(const VkVertexInputAttributeDescription& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "location", toStringFlags, tabCount, tabSize, ToString(obj.location, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineVertexInputStateCreateInfo>(const VkPipelineVertexInputStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexBindingDescriptionCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexBindingDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexBindingDescriptions", toStringFlags, tabCount, tabSize, ArrayToString(obj.vertexBindingDescriptionCount, obj.pVertexBindingDescriptions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeDescriptionCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexAttributeDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexAttributeDescriptions", toStringFlags, tabCount, tabSize, ArrayToString(obj.vertexAttributeDescriptionCount, obj.pVertexAttributeDescriptions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineInputAssemblyStateCreateInfo>(const VkPipelineInputAssemblyStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "topology", toStringFlags, tabCount, tabSize, Quote(ToString(obj.topology, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "primitiveRestartEnable", toStringFlags, tabCount, tabSize, ToString(obj.primitiveRestartEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineTessellationStateCreateInfo>(const VkPipelineTessellationStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "patchControlPoints", toStringFlags, tabCount, tabSize, ToString(obj.patchControlPoints, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkViewport>(const VkViewport& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minDepth", toStringFlags, tabCount, tabSize, ToString(obj.minDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportStateCreateInfo>(const VkPipelineViewportStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(obj.viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, ArrayToString(obj.viewportCount, obj.pViewports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(obj.scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, ArrayToString(obj.scissorCount, obj.pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationStateCreateInfo>(const VkPipelineRasterizationStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClampEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthClampEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizerDiscardEnable", toStringFlags, tabCount, tabSize, ToString(obj.rasterizerDiscardEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "polygonMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.polygonMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "cullMode", toStringFlags, tabCount, tabSize, ToString(obj.cullMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, Quote(ToString(obj.frontFace, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthBiasEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthBiasEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasConstantFactor", toStringFlags, tabCount, tabSize, ToString(obj.depthBiasConstantFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasClamp", toStringFlags, tabCount, tabSize, ToString(obj.depthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasSlopeFactor", toStringFlags, tabCount, tabSize, ToString(obj.depthBiasSlopeFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineWidth", toStringFlags, tabCount, tabSize, ToString(obj.lineWidth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkStencilOpState>(const VkStencilOpState& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "failOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.failOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "passOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.passOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthFailOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.compareOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "compareMask", toStringFlags, tabCount, tabSize, ToString(obj.compareMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "writeMask", toStringFlags, tabCount, tabSize, ToString(obj.writeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "reference", toStringFlags, tabCount, tabSize, ToString(obj.reference, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineDepthStencilStateCreateInfo>(const VkPipelineDepthStencilStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthTestEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthWriteEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthWriteEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthCompareOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthBoundsTestEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stencilTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.stencilTestEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "front", toStringFlags, tabCount, tabSize, ToString(obj.front, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "back", toStringFlags, tabCount, tabSize, ToString(obj.back, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minDepthBounds", toStringFlags, tabCount, tabSize, ToString(obj.minDepthBounds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDepthBounds", toStringFlags, tabCount, tabSize, ToString(obj.maxDepthBounds, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineColorBlendAttachmentState>(const VkPipelineColorBlendAttachmentState& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "blendEnable", toStringFlags, tabCount, tabSize, ToString(obj.blendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcColorBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcColorBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstColorBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstColorBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "colorBlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.colorBlendOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "srcAlphaBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcAlphaBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstAlphaBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstAlphaBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "alphaBlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.alphaBlendOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "colorWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.colorWriteMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineColorBlendStateCreateInfo>(const VkPipelineColorBlendStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "logicOpEnable", toStringFlags, tabCount, tabSize, ToString(obj.logicOpEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "logicOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.logicOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "blendConstants", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.blendConstants, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineDynamicStateCreateInfo>(const VkPipelineDynamicStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dynamicStateCount", toStringFlags, tabCount, tabSize, ToString(obj.dynamicStateCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDynamicStates", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.dynamicStateCount, obj.pDynamicStates, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGraphicsPipelineCreateInfo>(const VkGraphicsPipelineCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageCount", toStringFlags, tabCount, tabSize, ToString(obj.stageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStages", toStringFlags, tabCount, tabSize, ArrayToString(obj.stageCount, obj.pStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexInputState", toStringFlags, tabCount, tabSize, (obj.pVertexInputState ? ToString(*obj.pVertexInputState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pInputAssemblyState", toStringFlags, tabCount, tabSize, (obj.pInputAssemblyState ? ToString(*obj.pInputAssemblyState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pTessellationState", toStringFlags, tabCount, tabSize, (obj.pTessellationState ? ToString(*obj.pTessellationState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pViewportState", toStringFlags, tabCount, tabSize, (obj.pViewportState ? ToString(*obj.pViewportState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pRasterizationState", toStringFlags, tabCount, tabSize, (obj.pRasterizationState ? ToString(*obj.pRasterizationState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pMultisampleState", toStringFlags, tabCount, tabSize, (obj.pMultisampleState ? ToString(*obj.pMultisampleState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pDepthStencilState", toStringFlags, tabCount, tabSize, (obj.pDepthStencilState ? ToString(*obj.pDepthStencilState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pColorBlendState", toStringFlags, tabCount, tabSize, (obj.pColorBlendState ? ToString(*obj.pColorBlendState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pDynamicState", toStringFlags, tabCount, tabSize, (obj.pDynamicState ? ToString(*obj.pDynamicState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.layout)));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.renderPass)));
            FieldToString(strStrm, false, "subpass", toStringFlags, tabCount, tabSize, ToString(obj.subpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "basePipelineHandle", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.basePipelineHandle)));
            FieldToString(strStrm, false, "basePipelineIndex", toStringFlags, tabCount, tabSize, ToString(obj.basePipelineIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPushConstantRange>(const VkPushConstantRange& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "stageFlags", toStringFlags, tabCount, tabSize, ToString(obj.stageFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineLayoutCreateInfo>(const VkPipelineLayoutCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "setLayoutCount", toStringFlags, tabCount, tabSize, ToString(obj.setLayoutCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSetLayouts", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.setLayoutCount, obj.pSetLayouts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pushConstantRangeCount", toStringFlags, tabCount, tabSize, ToString(obj.pushConstantRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPushConstantRanges", toStringFlags, tabCount, tabSize, ArrayToString(obj.pushConstantRangeCount, obj.pPushConstantRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerCreateInfo>(const VkSamplerCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "magFilter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.magFilter, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "minFilter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.minFilter, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "mipmapMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mipmapMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "addressModeU", toStringFlags, tabCount, tabSize, Quote(ToString(obj.addressModeU, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "addressModeV", toStringFlags, tabCount, tabSize, Quote(ToString(obj.addressModeV, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "addressModeW", toStringFlags, tabCount, tabSize, Quote(ToString(obj.addressModeW, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "mipLodBias", toStringFlags, tabCount, tabSize, ToString(obj.mipLodBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "anisotropyEnable", toStringFlags, tabCount, tabSize, ToString(obj.anisotropyEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxAnisotropy", toStringFlags, tabCount, tabSize, ToString(obj.maxAnisotropy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compareEnable", toStringFlags, tabCount, tabSize, ToString(obj.compareEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.compareOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "minLod", toStringFlags, tabCount, tabSize, ToString(obj.minLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLod", toStringFlags, tabCount, tabSize, ToString(obj.maxLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "borderColor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.borderColor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "unnormalizedCoordinates", toStringFlags, tabCount, tabSize, ToString(obj.unnormalizedCoordinates, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyDescriptorSet>(const VkCopyDescriptorSet& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcSet", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcSet)));
            FieldToString(strStrm, false, "srcBinding", toStringFlags, tabCount, tabSize, ToString(obj.srcBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcArrayElement", toStringFlags, tabCount, tabSize, ToString(obj.srcArrayElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSet", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstSet)));
            FieldToString(strStrm, false, "dstBinding", toStringFlags, tabCount, tabSize, ToString(obj.dstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstArrayElement", toStringFlags, tabCount, tabSize, ToString(obj.dstArrayElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorBufferInfo>(const VkDescriptorBufferInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "range", toStringFlags, tabCount, tabSize, ToString(obj.range, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorPoolSize>(const VkDescriptorPoolSize& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorPoolCreateInfo>(const VkDescriptorPoolCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSets", toStringFlags, tabCount, tabSize, ToString(obj.maxSets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "poolSizeCount", toStringFlags, tabCount, tabSize, ToString(obj.poolSizeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPoolSizes", toStringFlags, tabCount, tabSize, ArrayToString(obj.poolSizeCount, obj.pPoolSizes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetAllocateInfo>(const VkDescriptorSetAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.descriptorPool)));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSetLayouts", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.descriptorSetCount, obj.pSetLayouts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetLayoutBinding>(const VkDescriptorSetLayoutBinding& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.descriptorType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageFlags", toStringFlags, tabCount, tabSize, ToString(obj.stageFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImmutableSamplers", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.descriptorCount, obj.pImmutableSamplers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetLayoutCreateInfo>(const VkDescriptorSetLayoutCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(obj.bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindings", toStringFlags, tabCount, tabSize, ArrayToString(obj.bindingCount, obj.pBindings, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAttachmentDescription>(const VkAttachmentDescription& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "loadOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.loadOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "storeOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.storeOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilLoadOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilLoadOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilStoreOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilStoreOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "initialLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.initialLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "finalLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.finalLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkAttachmentReference>(const VkAttachmentReference& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "attachment", toStringFlags, tabCount, tabSize, ToString(obj.attachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.layout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkFramebufferCreateInfo>(const VkFramebufferCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.renderPass)));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layers", toStringFlags, tabCount, tabSize, ToString(obj.layers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassDescription>(const VkSubpassDescription& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "inputAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.inputAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInputAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.inputAttachmentCount, obj.pInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.colorAttachmentCount, obj.pColorAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pResolveAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.colorAttachmentCount, obj.pResolveAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDepthStencilAttachment", toStringFlags, tabCount, tabSize, (obj.pDepthStencilAttachment ? ToString(*obj.pDepthStencilAttachment, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "preserveAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.preserveAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPreserveAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.preserveAttachmentCount, obj.pPreserveAttachments, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassDependency>(const VkSubpassDependency& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcSubpass", toStringFlags, tabCount, tabSize, ToString(obj.srcSubpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubpass", toStringFlags, tabCount, tabSize, ToString(obj.dstSubpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(obj.srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(obj.dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.srcAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.dstAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyFlags", toStringFlags, tabCount, tabSize, ToString(obj.dependencyFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassCreateInfo>(const VkRenderPassCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subpassCount", toStringFlags, tabCount, tabSize, ToString(obj.subpassCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpasses", toStringFlags, tabCount, tabSize, ArrayToString(obj.subpassCount, obj.pSubpasses, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyCount", toStringFlags, tabCount, tabSize, ToString(obj.dependencyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencies", toStringFlags, tabCount, tabSize, ArrayToString(obj.dependencyCount, obj.pDependencies, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandPoolCreateInfo>(const VkCommandPoolCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferAllocateInfo>(const VkCommandBufferAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.commandPool)));
            FieldToString(strStrm, false, "level", toStringFlags, tabCount, tabSize, Quote(ToString(obj.level, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(obj.commandBufferCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferInheritanceInfo>(const VkCommandBufferInheritanceInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.renderPass)));
            FieldToString(strStrm, false, "subpass", toStringFlags, tabCount, tabSize, ToString(obj.subpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.framebuffer)));
            FieldToString(strStrm, false, "occlusionQueryEnable", toStringFlags, tabCount, tabSize, ToString(obj.occlusionQueryEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryFlags", toStringFlags, tabCount, tabSize, ToString(obj.queryFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineStatistics", toStringFlags, tabCount, tabSize, ToString(obj.pipelineStatistics, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferBeginInfo>(const VkCommandBufferBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInheritanceInfo", toStringFlags, tabCount, tabSize, (obj.pInheritanceInfo ? ToString(*obj.pInheritanceInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkBufferCopy>(const VkBufferCopy& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageSubresourceLayers>(const VkImageSubresourceLayers& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mipLevel", toStringFlags, tabCount, tabSize, ToString(obj.mipLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseArrayLayer", toStringFlags, tabCount, tabSize, ToString(obj.baseArrayLayer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferImageCopy>(const VkBufferImageCopy& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "bufferOffset", toStringFlags, tabCount, tabSize, ToString(obj.bufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferRowLength", toStringFlags, tabCount, tabSize, ToString(obj.bufferRowLength, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferImageHeight", toStringFlags, tabCount, tabSize, ToString(obj.bufferImageHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageSubresource", toStringFlags, tabCount, tabSize, ToString(obj.imageSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageOffset", toStringFlags, tabCount, tabSize, ToString(obj.imageOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageExtent", toStringFlags, tabCount, tabSize, ToString(obj.imageExtent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkClearDepthStencilValue>(const VkClearDepthStencilValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "depth", toStringFlags, tabCount, tabSize, ToString(obj.depth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stencil", toStringFlags, tabCount, tabSize, ToString(obj.stencil, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkClearAttachment>(const VkClearAttachment& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachment", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "clearValue", toStringFlags, tabCount, tabSize, ToString(obj.clearValue, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkClearRect>(const VkClearRect& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "rect", toStringFlags, tabCount, tabSize, ToString(obj.rect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseArrayLayer", toStringFlags, tabCount, tabSize, ToString(obj.baseArrayLayer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageBlit>(const VkImageBlit& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffsets", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.srcOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffsets", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.dstOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageCopy>(const VkImageCopy& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageResolve>(const VkImageResolve& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassBeginInfo>(const VkRenderPassBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.renderPass)));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.framebuffer)));
            FieldToString(strStrm, false, "renderArea", toStringFlags, tabCount, tabSize, ToString(obj.renderArea, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "clearValueCount", toStringFlags, tabCount, tabSize, ToString(obj.clearValueCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pClearValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.clearValueCount, obj.pClearValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSubgroupProperties>(const VkPhysicalDeviceSubgroupProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedStages", toStringFlags, tabCount, tabSize, ToString(obj.supportedStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedOperations", toStringFlags, tabCount, tabSize, ToString(obj.supportedOperations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "quadOperationsInAllStages", toStringFlags, tabCount, tabSize, ToString(obj.quadOperationsInAllStages, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindBufferMemoryInfo>(const VkBindBufferMemoryInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindImageMemoryInfo>(const VkBindImageMemoryInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevice16BitStorageFeatures>(const VkPhysicalDevice16BitStorageFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageBuffer16BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.storageBuffer16BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformAndStorageBuffer16BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.uniformAndStorageBuffer16BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storagePushConstant16", toStringFlags, tabCount, tabSize, ToString(obj.storagePushConstant16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageInputOutput16", toStringFlags, tabCount, tabSize, ToString(obj.storageInputOutput16, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryDedicatedRequirements>(const VkMemoryDedicatedRequirements& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "prefersDedicatedAllocation", toStringFlags, tabCount, tabSize, ToString(obj.prefersDedicatedAllocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "requiresDedicatedAllocation", toStringFlags, tabCount, tabSize, ToString(obj.requiresDedicatedAllocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryDedicatedAllocateInfo>(const VkMemoryDedicatedAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
        }
    );
}

template <> std::string ToString<VkMemoryAllocateFlagsInfo>(const VkMemoryAllocateFlagsInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupRenderPassBeginInfo>(const VkDeviceGroupRenderPassBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceRenderAreaCount", toStringFlags, tabCount, tabSize, ToString(obj.deviceRenderAreaCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeviceRenderAreas", toStringFlags, tabCount, tabSize, ArrayToString(obj.deviceRenderAreaCount, obj.pDeviceRenderAreas, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupCommandBufferBeginInfo>(const VkDeviceGroupCommandBufferBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupSubmitInfo>(const VkDeviceGroupSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphoreDeviceIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.waitSemaphoreCount, obj.pWaitSemaphoreDeviceIndices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(obj.commandBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBufferDeviceMasks", toStringFlags, tabCount, tabSize, ArrayToString(obj.commandBufferCount, obj.pCommandBufferDeviceMasks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphoreDeviceIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.signalSemaphoreCount, obj.pSignalSemaphoreDeviceIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupBindSparseInfo>(const VkDeviceGroupBindSparseInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "resourceDeviceIndex", toStringFlags, tabCount, tabSize, ToString(obj.resourceDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryDeviceIndex", toStringFlags, tabCount, tabSize, ToString(obj.memoryDeviceIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindBufferMemoryDeviceGroupInfo>(const VkBindBufferMemoryDeviceGroupInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.deviceIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeviceIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.deviceIndexCount, obj.pDeviceIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindImageMemoryDeviceGroupInfo>(const VkBindImageMemoryDeviceGroupInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.deviceIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeviceIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.deviceIndexCount, obj.pDeviceIndices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "splitInstanceBindRegionCount", toStringFlags, tabCount, tabSize, ToString(obj.splitInstanceBindRegionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSplitInstanceBindRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.splitInstanceBindRegionCount, obj.pSplitInstanceBindRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceGroupProperties>(const VkPhysicalDeviceGroupProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "physicalDeviceCount", toStringFlags, tabCount, tabSize, ToString(obj.physicalDeviceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "physicalDevices", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.physicalDeviceCount, obj.physicalDevices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subsetAllocation", toStringFlags, tabCount, tabSize, ToString(obj.subsetAllocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupDeviceCreateInfo>(const VkDeviceGroupDeviceCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "physicalDeviceCount", toStringFlags, tabCount, tabSize, ToString(obj.physicalDeviceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPhysicalDevices", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.physicalDeviceCount, obj.pPhysicalDevices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferMemoryRequirementsInfo2>(const VkBufferMemoryRequirementsInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
        }
    );
}

template <> std::string ToString<VkImageMemoryRequirementsInfo2>(const VkImageMemoryRequirementsInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
        }
    );
}

template <> std::string ToString<VkImageSparseMemoryRequirementsInfo2>(const VkImageSparseMemoryRequirementsInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
        }
    );
}

template <> std::string ToString<VkMemoryRequirements2>(const VkMemoryRequirements2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryRequirements", toStringFlags, tabCount, tabSize, ToString(obj.memoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageMemoryRequirements2>(const VkSparseImageMemoryRequirements2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryRequirements", toStringFlags, tabCount, tabSize, ToString(obj.memoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFeatures2>(const VkPhysicalDeviceFeatures2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "features", toStringFlags, tabCount, tabSize, ToString(obj.features, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProperties2>(const VkPhysicalDeviceProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "properties", toStringFlags, tabCount, tabSize, ToString(obj.properties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFormatProperties2>(const VkFormatProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatProperties", toStringFlags, tabCount, tabSize, ToString(obj.formatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageFormatProperties2>(const VkImageFormatProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageFormatProperties", toStringFlags, tabCount, tabSize, ToString(obj.imageFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageFormatInfo2>(const VkPhysicalDeviceImageFormatInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.tiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyProperties2>(const VkQueueFamilyProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyProperties", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMemoryProperties2>(const VkPhysicalDeviceMemoryProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryProperties", toStringFlags, tabCount, tabSize, ToString(obj.memoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSparseImageFormatProperties2>(const VkSparseImageFormatProperties2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "properties", toStringFlags, tabCount, tabSize, ToString(obj.properties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSparseImageFormatInfo2>(const VkPhysicalDeviceSparseImageFormatInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.tiling, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePointClippingProperties>(const VkPhysicalDevicePointClippingProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pointClippingBehavior", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pointClippingBehavior, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkInputAttachmentAspectReference>(const VkInputAttachmentAspectReference& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "subpass", toStringFlags, tabCount, tabSize, ToString(obj.subpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputAttachmentIndex", toStringFlags, tabCount, tabSize, ToString(obj.inputAttachmentIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassInputAttachmentAspectCreateInfo>(const VkRenderPassInputAttachmentAspectCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "aspectReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.aspectReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAspectReferences", toStringFlags, tabCount, tabSize, ArrayToString(obj.aspectReferenceCount, obj.pAspectReferences, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageViewUsageCreateInfo>(const VkImageViewUsageCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineTessellationDomainOriginStateCreateInfo>(const VkPipelineTessellationDomainOriginStateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "domainOrigin", toStringFlags, tabCount, tabSize, Quote(ToString(obj.domainOrigin, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkRenderPassMultiviewCreateInfo>(const VkRenderPassMultiviewCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subpassCount", toStringFlags, tabCount, tabSize, ToString(obj.subpassCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewMasks", toStringFlags, tabCount, tabSize, ArrayToString(obj.subpassCount, obj.pViewMasks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyCount", toStringFlags, tabCount, tabSize, ToString(obj.dependencyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewOffsets", toStringFlags, tabCount, tabSize, ArrayToString(obj.dependencyCount, obj.pViewOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "correlationMaskCount", toStringFlags, tabCount, tabSize, ToString(obj.correlationMaskCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCorrelationMasks", toStringFlags, tabCount, tabSize, ArrayToString(obj.correlationMaskCount, obj.pCorrelationMasks, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiviewFeatures>(const VkPhysicalDeviceMultiviewFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiview", toStringFlags, tabCount, tabSize, ToString(obj.multiview, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewGeometryShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewGeometryShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewTessellationShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewTessellationShader, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiviewProperties>(const VkPhysicalDeviceMultiviewProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMultiviewViewCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMultiviewViewCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMultiviewInstanceIndex", toStringFlags, tabCount, tabSize, ToString(obj.maxMultiviewInstanceIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVariablePointersFeatures>(const VkPhysicalDeviceVariablePointersFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variablePointersStorageBuffer", toStringFlags, tabCount, tabSize, ToString(obj.variablePointersStorageBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variablePointers", toStringFlags, tabCount, tabSize, ToString(obj.variablePointers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProtectedMemoryFeatures>(const VkPhysicalDeviceProtectedMemoryFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "protectedMemory", toStringFlags, tabCount, tabSize, ToString(obj.protectedMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProtectedMemoryProperties>(const VkPhysicalDeviceProtectedMemoryProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "protectedNoFault", toStringFlags, tabCount, tabSize, ToString(obj.protectedNoFault, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceQueueInfo2>(const VkDeviceQueueInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkProtectedSubmitInfo>(const VkProtectedSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "protectedSubmit", toStringFlags, tabCount, tabSize, ToString(obj.protectedSubmit, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerYcbcrConversionCreateInfo>(const VkSamplerYcbcrConversionCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "ycbcrModel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ycbcrModel, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "ycbcrRange", toStringFlags, tabCount, tabSize, Quote(ToString(obj.ycbcrRange, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "components", toStringFlags, tabCount, tabSize, ToString(obj.components, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "xChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.xChromaOffset, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "yChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.yChromaOffset, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "chromaFilter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.chromaFilter, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "forceExplicitReconstruction", toStringFlags, tabCount, tabSize, ToString(obj.forceExplicitReconstruction, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerYcbcrConversionInfo>(const VkSamplerYcbcrConversionInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conversion", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.conversion)));
        }
    );
}

template <> std::string ToString<VkBindImagePlaneMemoryInfo>(const VkBindImagePlaneMemoryInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "planeAspect", toStringFlags, tabCount, tabSize, Quote(ToString(obj.planeAspect, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImagePlaneMemoryRequirementsInfo>(const VkImagePlaneMemoryRequirementsInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "planeAspect", toStringFlags, tabCount, tabSize, Quote(ToString(obj.planeAspect, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSamplerYcbcrConversionFeatures>(const VkPhysicalDeviceSamplerYcbcrConversionFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerYcbcrConversion", toStringFlags, tabCount, tabSize, ToString(obj.samplerYcbcrConversion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerYcbcrConversionImageFormatProperties>(const VkSamplerYcbcrConversionImageFormatProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "combinedImageSamplerDescriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.combinedImageSamplerDescriptorCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorUpdateTemplateEntry>(const VkDescriptorUpdateTemplateEntry& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "dstBinding", toStringFlags, tabCount, tabSize, ToString(obj.dstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstArrayElement", toStringFlags, tabCount, tabSize, ToString(obj.dstArrayElement, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.descriptorType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorUpdateTemplateCreateInfo>(const VkDescriptorUpdateTemplateCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorUpdateEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorUpdateEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorUpdateEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.descriptorUpdateEntryCount, obj.pDescriptorUpdateEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "templateType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.templateType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "descriptorSetLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.descriptorSetLayout)));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pipelineLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pipelineLayout)));
            FieldToString(strStrm, false, "set", toStringFlags, tabCount, tabSize, ToString(obj.set, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExternalMemoryProperties>(const VkExternalMemoryProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "externalMemoryFeatures", toStringFlags, tabCount, tabSize, ToString(obj.externalMemoryFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exportFromImportedHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.exportFromImportedHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compatibleHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.compatibleHandleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalImageFormatInfo>(const VkPhysicalDeviceExternalImageFormatInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkExternalImageFormatProperties>(const VkExternalImageFormatProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalMemoryProperties", toStringFlags, tabCount, tabSize, ToString(obj.externalMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalBufferInfo>(const VkPhysicalDeviceExternalBufferInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkExternalBufferProperties>(const VkExternalBufferProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalMemoryProperties", toStringFlags, tabCount, tabSize, ToString(obj.externalMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceIDProperties>(const VkPhysicalDeviceIDProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.deviceUUID)));
            FieldToString(strStrm, false, "driverUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.driverUUID)));
            FieldToString(strStrm, false, "deviceLUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_LUID_SIZE, obj.deviceLUID)));
            FieldToString(strStrm, false, "deviceNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceNodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceLUIDValid", toStringFlags, tabCount, tabSize, ToString(obj.deviceLUIDValid, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExternalMemoryImageCreateInfo>(const VkExternalMemoryImageCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExternalMemoryBufferCreateInfo>(const VkExternalMemoryBufferCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExportMemoryAllocateInfo>(const VkExportMemoryAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalFenceInfo>(const VkPhysicalDeviceExternalFenceInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkExternalFenceProperties>(const VkExternalFenceProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exportFromImportedHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.exportFromImportedHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compatibleHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.compatibleHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalFenceFeatures", toStringFlags, tabCount, tabSize, ToString(obj.externalFenceFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExportFenceCreateInfo>(const VkExportFenceCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExportSemaphoreCreateInfo>(const VkExportSemaphoreCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalSemaphoreInfo>(const VkPhysicalDeviceExternalSemaphoreInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkExternalSemaphoreProperties>(const VkExternalSemaphoreProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exportFromImportedHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.exportFromImportedHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compatibleHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.compatibleHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalSemaphoreFeatures", toStringFlags, tabCount, tabSize, ToString(obj.externalSemaphoreFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMaintenance3Properties>(const VkPhysicalDeviceMaintenance3Properties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerSetDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.maxPerSetDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMemoryAllocationSize", toStringFlags, tabCount, tabSize, ToString(obj.maxMemoryAllocationSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetLayoutSupport>(const VkDescriptorSetLayoutSupport& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supported", toStringFlags, tabCount, tabSize, ToString(obj.supported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderDrawParametersFeatures>(const VkPhysicalDeviceShaderDrawParametersFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDrawParameters", toStringFlags, tabCount, tabSize, ToString(obj.shaderDrawParameters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan11Features>(const VkPhysicalDeviceVulkan11Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageBuffer16BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.storageBuffer16BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformAndStorageBuffer16BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.uniformAndStorageBuffer16BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storagePushConstant16", toStringFlags, tabCount, tabSize, ToString(obj.storagePushConstant16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageInputOutput16", toStringFlags, tabCount, tabSize, ToString(obj.storageInputOutput16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiview", toStringFlags, tabCount, tabSize, ToString(obj.multiview, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewGeometryShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewGeometryShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewTessellationShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewTessellationShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variablePointersStorageBuffer", toStringFlags, tabCount, tabSize, ToString(obj.variablePointersStorageBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variablePointers", toStringFlags, tabCount, tabSize, ToString(obj.variablePointers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "protectedMemory", toStringFlags, tabCount, tabSize, ToString(obj.protectedMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerYcbcrConversion", toStringFlags, tabCount, tabSize, ToString(obj.samplerYcbcrConversion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDrawParameters", toStringFlags, tabCount, tabSize, ToString(obj.shaderDrawParameters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan11Properties>(const VkPhysicalDeviceVulkan11Properties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.deviceUUID)));
            FieldToString(strStrm, false, "driverUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.driverUUID)));
            FieldToString(strStrm, false, "deviceLUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_LUID_SIZE, obj.deviceLUID)));
            FieldToString(strStrm, false, "deviceNodeMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceNodeMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceLUIDValid", toStringFlags, tabCount, tabSize, ToString(obj.deviceLUIDValid, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSupportedStages", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSupportedStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSupportedOperations", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSupportedOperations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupQuadOperationsInAllStages", toStringFlags, tabCount, tabSize, ToString(obj.subgroupQuadOperationsInAllStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pointClippingBehavior", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pointClippingBehavior, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "maxMultiviewViewCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMultiviewViewCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMultiviewInstanceIndex", toStringFlags, tabCount, tabSize, ToString(obj.maxMultiviewInstanceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "protectedNoFault", toStringFlags, tabCount, tabSize, ToString(obj.protectedNoFault, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerSetDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.maxPerSetDescriptors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMemoryAllocationSize", toStringFlags, tabCount, tabSize, ToString(obj.maxMemoryAllocationSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan12Features>(const VkPhysicalDeviceVulkan12Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerMirrorClampToEdge", toStringFlags, tabCount, tabSize, ToString(obj.samplerMirrorClampToEdge, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawIndirectCount", toStringFlags, tabCount, tabSize, ToString(obj.drawIndirectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageBuffer8BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.storageBuffer8BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformAndStorageBuffer8BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.uniformAndStorageBuffer8BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storagePushConstant8", toStringFlags, tabCount, tabSize, ToString(obj.storagePushConstant8, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferInt64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedInt64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInt8", toStringFlags, tabCount, tabSize, ToString(obj.shaderInt8, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorIndexing", toStringFlags, tabCount, tabSize, ToString(obj.descriptorIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformTexelBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformTexelBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageTexelBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageTexelBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampledImageArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampledImageArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformTexelBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformTexelBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageTexelBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageTexelBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUniformBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUniformBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingSampledImageUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingSampledImageUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageImageUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageImageUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUniformTexelBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUniformTexelBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageTexelBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageTexelBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUpdateUnusedWhilePending", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUpdateUnusedWhilePending, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingPartiallyBound", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingPartiallyBound, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingVariableDescriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingVariableDescriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "runtimeDescriptorArray", toStringFlags, tabCount, tabSize, ToString(obj.runtimeDescriptorArray, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerFilterMinmax", toStringFlags, tabCount, tabSize, ToString(obj.samplerFilterMinmax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scalarBlockLayout", toStringFlags, tabCount, tabSize, ToString(obj.scalarBlockLayout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imagelessFramebuffer", toStringFlags, tabCount, tabSize, ToString(obj.imagelessFramebuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformBufferStandardLayout", toStringFlags, tabCount, tabSize, ToString(obj.uniformBufferStandardLayout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSubgroupExtendedTypes", toStringFlags, tabCount, tabSize, ToString(obj.shaderSubgroupExtendedTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "separateDepthStencilLayouts", toStringFlags, tabCount, tabSize, ToString(obj.separateDepthStencilLayouts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hostQueryReset", toStringFlags, tabCount, tabSize, ToString(obj.hostQueryReset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timelineSemaphore", toStringFlags, tabCount, tabSize, ToString(obj.timelineSemaphore, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressMultiDevice", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressMultiDevice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModel", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModelDeviceScope", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModelDeviceScope, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModelAvailabilityVisibilityChains", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModelAvailabilityVisibilityChains, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderOutputViewportIndex", toStringFlags, tabCount, tabSize, ToString(obj.shaderOutputViewportIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderOutputLayer", toStringFlags, tabCount, tabSize, ToString(obj.shaderOutputLayer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupBroadcastDynamicId", toStringFlags, tabCount, tabSize, ToString(obj.subgroupBroadcastDynamicId, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkConformanceVersion>(const VkConformanceVersion& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "major", toStringFlags, tabCount, tabSize, ToString(obj.major, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minor", toStringFlags, tabCount, tabSize, ToString(obj.minor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subminor", toStringFlags, tabCount, tabSize, ToString(obj.subminor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "patch", toStringFlags, tabCount, tabSize, ToString(obj.patch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan12Properties>(const VkPhysicalDeviceVulkan12Properties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "driverID", toStringFlags, tabCount, tabSize, Quote(ToString(obj.driverID, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "driverName", toStringFlags, tabCount, tabSize, CStrToString(obj.driverName));
            FieldToString(strStrm, false, "driverInfo", toStringFlags, tabCount, tabSize, CStrToString(obj.driverInfo));
            FieldToString(strStrm, false, "conformanceVersion", toStringFlags, tabCount, tabSize, ToString(obj.conformanceVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "denormBehaviorIndependence", toStringFlags, tabCount, tabSize, Quote(ToString(obj.denormBehaviorIndependence, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "roundingModeIndependence", toStringFlags, tabCount, tabSize, Quote(ToString(obj.roundingModeIndependence, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxUpdateAfterBindDescriptorsInAllPools", toStringFlags, tabCount, tabSize, ToString(obj.maxUpdateAfterBindDescriptorsInAllPools, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformBufferArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformBufferArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampledImageArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampledImageArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageBufferArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageBufferArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustBufferAccessUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.robustBufferAccessUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "quadDivergentImplicitLod", toStringFlags, tabCount, tabSize, ToString(obj.quadDivergentImplicitLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageUpdateAfterBindResources", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageUpdateAfterBindResources, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedDepthResolveModes", toStringFlags, tabCount, tabSize, ToString(obj.supportedDepthResolveModes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedStencilResolveModes", toStringFlags, tabCount, tabSize, ToString(obj.supportedStencilResolveModes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "independentResolveNone", toStringFlags, tabCount, tabSize, ToString(obj.independentResolveNone, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "independentResolve", toStringFlags, tabCount, tabSize, ToString(obj.independentResolve, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterMinmaxSingleComponentFormats", toStringFlags, tabCount, tabSize, ToString(obj.filterMinmaxSingleComponentFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterMinmaxImageComponentMapping", toStringFlags, tabCount, tabSize, ToString(obj.filterMinmaxImageComponentMapping, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTimelineSemaphoreValueDifference", toStringFlags, tabCount, tabSize, ToString(obj.maxTimelineSemaphoreValueDifference, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framebufferIntegerColorSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.framebufferIntegerColorSampleCounts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageFormatListCreateInfo>(const VkImageFormatListCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewFormatCount", toStringFlags, tabCount, tabSize, ToString(obj.viewFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewFormats", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.viewFormatCount, obj.pViewFormats, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAttachmentDescription2>(const VkAttachmentDescription2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "loadOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.loadOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "storeOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.storeOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilLoadOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilLoadOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilStoreOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilStoreOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "initialLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.initialLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "finalLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.finalLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkAttachmentReference2>(const VkAttachmentReference2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachment", toStringFlags, tabCount, tabSize, ToString(obj.attachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.layout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "aspectMask", toStringFlags, tabCount, tabSize, ToString(obj.aspectMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassDescription2>(const VkSubpassDescription2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "viewMask", toStringFlags, tabCount, tabSize, ToString(obj.viewMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.inputAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInputAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.inputAttachmentCount, obj.pInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.colorAttachmentCount, obj.pColorAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pResolveAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.colorAttachmentCount, obj.pResolveAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDepthStencilAttachment", toStringFlags, tabCount, tabSize, (obj.pDepthStencilAttachment ? ToString(*obj.pDepthStencilAttachment, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "preserveAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.preserveAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPreserveAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.preserveAttachmentCount, obj.pPreserveAttachments, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassDependency2>(const VkSubpassDependency2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcSubpass", toStringFlags, tabCount, tabSize, ToString(obj.srcSubpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubpass", toStringFlags, tabCount, tabSize, ToString(obj.dstSubpass, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(obj.srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(obj.dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.srcAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, ToString(obj.dstAccessMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyFlags", toStringFlags, tabCount, tabSize, ToString(obj.dependencyFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewOffset", toStringFlags, tabCount, tabSize, ToString(obj.viewOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassCreateInfo2>(const VkRenderPassCreateInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subpassCount", toStringFlags, tabCount, tabSize, ToString(obj.subpassCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpasses", toStringFlags, tabCount, tabSize, ArrayToString(obj.subpassCount, obj.pSubpasses, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyCount", toStringFlags, tabCount, tabSize, ToString(obj.dependencyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencies", toStringFlags, tabCount, tabSize, ArrayToString(obj.dependencyCount, obj.pDependencies, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "correlatedViewMaskCount", toStringFlags, tabCount, tabSize, ToString(obj.correlatedViewMaskCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCorrelatedViewMasks", toStringFlags, tabCount, tabSize, ArrayToString(obj.correlatedViewMaskCount, obj.pCorrelatedViewMasks, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassBeginInfo>(const VkSubpassBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, Quote(ToString(obj.contents, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSubpassEndInfo>(const VkSubpassEndInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevice8BitStorageFeatures>(const VkPhysicalDevice8BitStorageFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageBuffer8BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.storageBuffer8BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformAndStorageBuffer8BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.uniformAndStorageBuffer8BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storagePushConstant8", toStringFlags, tabCount, tabSize, ToString(obj.storagePushConstant8, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDriverProperties>(const VkPhysicalDeviceDriverProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "driverID", toStringFlags, tabCount, tabSize, Quote(ToString(obj.driverID, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "driverName", toStringFlags, tabCount, tabSize, CStrToString(obj.driverName));
            FieldToString(strStrm, false, "driverInfo", toStringFlags, tabCount, tabSize, CStrToString(obj.driverInfo));
            FieldToString(strStrm, false, "conformanceVersion", toStringFlags, tabCount, tabSize, ToString(obj.conformanceVersion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderAtomicInt64Features>(const VkPhysicalDeviceShaderAtomicInt64Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferInt64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedInt64Atomics, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderFloat16Int8Features>(const VkPhysicalDeviceShaderFloat16Int8Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInt8", toStringFlags, tabCount, tabSize, ToString(obj.shaderInt8, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFloatControlsProperties>(const VkPhysicalDeviceFloatControlsProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "denormBehaviorIndependence", toStringFlags, tabCount, tabSize, Quote(ToString(obj.denormBehaviorIndependence, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "roundingModeIndependence", toStringFlags, tabCount, tabSize, Quote(ToString(obj.roundingModeIndependence, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSignedZeroInfNanPreserveFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderSignedZeroInfNanPreserveFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormPreserveFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormPreserveFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDenormFlushToZeroFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderDenormFlushToZeroFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTEFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTEFloat64, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat16", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat16, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat32", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat32, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderRoundingModeRTZFloat64", toStringFlags, tabCount, tabSize, ToString(obj.shaderRoundingModeRTZFloat64, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetLayoutBindingFlagsCreateInfo>(const VkDescriptorSetLayoutBindingFlagsCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(obj.bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindingFlags", toStringFlags, tabCount, tabSize, ArrayToString(obj.bindingCount, obj.pBindingFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDescriptorIndexingFeatures>(const VkPhysicalDeviceDescriptorIndexingFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformTexelBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformTexelBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageTexelBufferArrayDynamicIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageTexelBufferArrayDynamicIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampledImageArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampledImageArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformTexelBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformTexelBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageTexelBufferArrayNonUniformIndexing", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageTexelBufferArrayNonUniformIndexing, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUniformBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUniformBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingSampledImageUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingSampledImageUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageImageUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageImageUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUniformTexelBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUniformTexelBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingStorageTexelBufferUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingStorageTexelBufferUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingUpdateUnusedWhilePending", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingUpdateUnusedWhilePending, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingPartiallyBound", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingPartiallyBound, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingVariableDescriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingVariableDescriptorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "runtimeDescriptorArray", toStringFlags, tabCount, tabSize, ToString(obj.runtimeDescriptorArray, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDescriptorIndexingProperties>(const VkPhysicalDeviceDescriptorIndexingProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxUpdateAfterBindDescriptorsInAllPools", toStringFlags, tabCount, tabSize, ToString(obj.maxUpdateAfterBindDescriptorsInAllPools, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderUniformBufferArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderUniformBufferArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampledImageArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampledImageArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageBufferArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageBufferArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderStorageImageArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderStorageImageArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderInputAttachmentArrayNonUniformIndexingNative", toStringFlags, tabCount, tabSize, ToString(obj.shaderInputAttachmentArrayNonUniformIndexingNative, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustBufferAccessUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.robustBufferAccessUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "quadDivergentImplicitLod", toStringFlags, tabCount, tabSize, ToString(obj.quadDivergentImplicitLod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindInputAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageUpdateAfterBindResources", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageUpdateAfterBindResources, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindUniformBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindUniformBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindUniformBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageBuffersDynamic", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindSampledImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindSampledImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindStorageImages", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindStorageImages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindInputAttachments", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindInputAttachments, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetVariableDescriptorCountAllocateInfo>(const VkDescriptorSetVariableDescriptorCountAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorCounts", toStringFlags, tabCount, tabSize, ArrayToString(obj.descriptorSetCount, obj.pDescriptorCounts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetVariableDescriptorCountLayoutSupport>(const VkDescriptorSetVariableDescriptorCountLayoutSupport& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVariableDescriptorCount", toStringFlags, tabCount, tabSize, ToString(obj.maxVariableDescriptorCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassDescriptionDepthStencilResolve>(const VkSubpassDescriptionDepthStencilResolve& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthResolveMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthResolveMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilResolveMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilResolveMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pDepthStencilResolveAttachment", toStringFlags, tabCount, tabSize, (obj.pDepthStencilResolveAttachment ? ToString(*obj.pDepthStencilResolveAttachment, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDepthStencilResolveProperties>(const VkPhysicalDeviceDepthStencilResolveProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedDepthResolveModes", toStringFlags, tabCount, tabSize, ToString(obj.supportedDepthResolveModes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedStencilResolveModes", toStringFlags, tabCount, tabSize, ToString(obj.supportedStencilResolveModes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "independentResolveNone", toStringFlags, tabCount, tabSize, ToString(obj.independentResolveNone, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "independentResolve", toStringFlags, tabCount, tabSize, ToString(obj.independentResolve, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceScalarBlockLayoutFeatures>(const VkPhysicalDeviceScalarBlockLayoutFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scalarBlockLayout", toStringFlags, tabCount, tabSize, ToString(obj.scalarBlockLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageStencilUsageCreateInfo>(const VkImageStencilUsageCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stencilUsage", toStringFlags, tabCount, tabSize, ToString(obj.stencilUsage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerReductionModeCreateInfo>(const VkSamplerReductionModeCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "reductionMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.reductionMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSamplerFilterMinmaxProperties>(const VkPhysicalDeviceSamplerFilterMinmaxProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterMinmaxSingleComponentFormats", toStringFlags, tabCount, tabSize, ToString(obj.filterMinmaxSingleComponentFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterMinmaxImageComponentMapping", toStringFlags, tabCount, tabSize, ToString(obj.filterMinmaxImageComponentMapping, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkanMemoryModelFeatures>(const VkPhysicalDeviceVulkanMemoryModelFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModel", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModelDeviceScope", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModelDeviceScope, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vulkanMemoryModelAvailabilityVisibilityChains", toStringFlags, tabCount, tabSize, ToString(obj.vulkanMemoryModelAvailabilityVisibilityChains, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImagelessFramebufferFeatures>(const VkPhysicalDeviceImagelessFramebufferFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imagelessFramebuffer", toStringFlags, tabCount, tabSize, ToString(obj.imagelessFramebuffer, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFramebufferAttachmentImageInfo>(const VkFramebufferAttachmentImageInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewFormatCount", toStringFlags, tabCount, tabSize, ToString(obj.viewFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewFormats", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.viewFormatCount, obj.pViewFormats, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFramebufferAttachmentsCreateInfo>(const VkFramebufferAttachmentsCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentImageInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentImageInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachmentImageInfos", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentImageInfoCount, obj.pAttachmentImageInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassAttachmentBeginInfo>(const VkRenderPassAttachmentBeginInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>(const VkPhysicalDeviceUniformBufferStandardLayoutFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformBufferStandardLayout", toStringFlags, tabCount, tabSize, ToString(obj.uniformBufferStandardLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>(const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSubgroupExtendedTypes", toStringFlags, tabCount, tabSize, ToString(obj.shaderSubgroupExtendedTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>(const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "separateDepthStencilLayouts", toStringFlags, tabCount, tabSize, ToString(obj.separateDepthStencilLayouts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAttachmentReferenceStencilLayout>(const VkAttachmentReferenceStencilLayout& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stencilLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkAttachmentDescriptionStencilLayout>(const VkAttachmentDescriptionStencilLayout& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stencilInitialLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilInitialLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilFinalLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilFinalLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceHostQueryResetFeatures>(const VkPhysicalDeviceHostQueryResetFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hostQueryReset", toStringFlags, tabCount, tabSize, ToString(obj.hostQueryReset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTimelineSemaphoreFeatures>(const VkPhysicalDeviceTimelineSemaphoreFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timelineSemaphore", toStringFlags, tabCount, tabSize, ToString(obj.timelineSemaphore, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTimelineSemaphoreProperties>(const VkPhysicalDeviceTimelineSemaphoreProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTimelineSemaphoreValueDifference", toStringFlags, tabCount, tabSize, ToString(obj.maxTimelineSemaphoreValueDifference, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreTypeCreateInfo>(const VkSemaphoreTypeCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphoreType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.semaphoreType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "initialValue", toStringFlags, tabCount, tabSize, ToString(obj.initialValue, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkTimelineSemaphoreSubmitInfo>(const VkTimelineSemaphoreSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreValueCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreValueCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphoreValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.waitSemaphoreValueCount, obj.pWaitSemaphoreValues, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreValueCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreValueCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphoreValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.signalSemaphoreValueCount, obj.pSignalSemaphoreValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreWaitInfo>(const VkSemaphoreWaitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.semaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.semaphoreCount, obj.pSemaphores, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.semaphoreCount, obj.pValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreSignalInfo>(const VkSemaphoreSignalInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "value", toStringFlags, tabCount, tabSize, ToString(obj.value, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceBufferDeviceAddressFeatures>(const VkPhysicalDeviceBufferDeviceAddressFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressMultiDevice", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressMultiDevice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferDeviceAddressInfo>(const VkBufferDeviceAddressInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
        }
    );
}

template <> std::string ToString<VkBufferOpaqueCaptureAddressCreateInfo>(const VkBufferOpaqueCaptureAddressCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "opaqueCaptureAddress", toStringFlags, tabCount, tabSize, ToString(obj.opaqueCaptureAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryOpaqueCaptureAddressAllocateInfo>(const VkMemoryOpaqueCaptureAddressAllocateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "opaqueCaptureAddress", toStringFlags, tabCount, tabSize, ToString(obj.opaqueCaptureAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceMemoryOpaqueCaptureAddressInfo>(const VkDeviceMemoryOpaqueCaptureAddressInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan13Features>(const VkPhysicalDeviceVulkan13Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustImageAccess", toStringFlags, tabCount, tabSize, ToString(obj.robustImageAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inlineUniformBlock", toStringFlags, tabCount, tabSize, ToString(obj.inlineUniformBlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingInlineUniformBlockUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingInlineUniformBlockUpdateAfterBind, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineCreationCacheControl", toStringFlags, tabCount, tabSize, ToString(obj.pipelineCreationCacheControl, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateData", toStringFlags, tabCount, tabSize, ToString(obj.privateData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDemoteToHelperInvocation", toStringFlags, tabCount, tabSize, ToString(obj.shaderDemoteToHelperInvocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderTerminateInvocation", toStringFlags, tabCount, tabSize, ToString(obj.shaderTerminateInvocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSizeControl", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSizeControl, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeFullSubgroups", toStringFlags, tabCount, tabSize, ToString(obj.computeFullSubgroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "synchronization2", toStringFlags, tabCount, tabSize, ToString(obj.synchronization2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureCompressionASTC_HDR", toStringFlags, tabCount, tabSize, ToString(obj.textureCompressionASTC_HDR, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderZeroInitializeWorkgroupMemory", toStringFlags, tabCount, tabSize, ToString(obj.shaderZeroInitializeWorkgroupMemory, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dynamicRendering", toStringFlags, tabCount, tabSize, ToString(obj.dynamicRendering, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderIntegerDotProduct", toStringFlags, tabCount, tabSize, ToString(obj.shaderIntegerDotProduct, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maintenance4", toStringFlags, tabCount, tabSize, ToString(obj.maintenance4, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVulkan13Properties>(const VkPhysicalDeviceVulkan13Properties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSubgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.minSubgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSubgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.maxSubgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeWorkgroupSubgroups", toStringFlags, tabCount, tabSize, ToString(obj.maxComputeWorkgroupSubgroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "requiredSubgroupSizeStages", toStringFlags, tabCount, tabSize, ToString(obj.requiredSubgroupSizeStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInlineUniformBlockSize", toStringFlags, tabCount, tabSize, ToString(obj.maxInlineUniformBlockSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInlineUniformTotalSize", toStringFlags, tabCount, tabSize, ToString(obj.maxInlineUniformTotalSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageTexelBufferOffsetAlignmentBytes", toStringFlags, tabCount, tabSize, ToString(obj.storageTexelBufferOffsetAlignmentBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageTexelBufferOffsetSingleTexelAlignment", toStringFlags, tabCount, tabSize, ToString(obj.storageTexelBufferOffsetSingleTexelAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformTexelBufferOffsetAlignmentBytes", toStringFlags, tabCount, tabSize, ToString(obj.uniformTexelBufferOffsetAlignmentBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformTexelBufferOffsetSingleTexelAlignment", toStringFlags, tabCount, tabSize, ToString(obj.uniformTexelBufferOffsetSingleTexelAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBufferSize", toStringFlags, tabCount, tabSize, ToString(obj.maxBufferSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCreationFeedback>(const VkPipelineCreationFeedback& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "duration", toStringFlags, tabCount, tabSize, ToString(obj.duration, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCreationFeedbackCreateInfo>(const VkPipelineCreationFeedbackCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelineCreationFeedback", toStringFlags, tabCount, tabSize, (obj.pPipelineCreationFeedback ? ToString(*obj.pPipelineCreationFeedback, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pipelineStageCreationFeedbackCount", toStringFlags, tabCount, tabSize, ToString(obj.pipelineStageCreationFeedbackCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelineStageCreationFeedbacks", toStringFlags, tabCount, tabSize, ArrayToString(obj.pipelineStageCreationFeedbackCount, obj.pPipelineStageCreationFeedbacks, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderTerminateInvocationFeatures>(const VkPhysicalDeviceShaderTerminateInvocationFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderTerminateInvocation", toStringFlags, tabCount, tabSize, ToString(obj.shaderTerminateInvocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceToolProperties>(const VkPhysicalDeviceToolProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, CStrToString(obj.name));
            FieldToString(strStrm, false, "version", toStringFlags, tabCount, tabSize, CStrToString(obj.version));
            FieldToString(strStrm, false, "purposes", toStringFlags, tabCount, tabSize, ToString(obj.purposes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "layer", toStringFlags, tabCount, tabSize, CStrToString(obj.layer));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>(const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDemoteToHelperInvocation", toStringFlags, tabCount, tabSize, ToString(obj.shaderDemoteToHelperInvocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePrivateDataFeatures>(const VkPhysicalDevicePrivateDataFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateData", toStringFlags, tabCount, tabSize, ToString(obj.privateData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDevicePrivateDataCreateInfo>(const VkDevicePrivateDataCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlotRequestCount", toStringFlags, tabCount, tabSize, ToString(obj.privateDataSlotRequestCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPrivateDataSlotCreateInfo>(const VkPrivateDataSlotCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePipelineCreationCacheControlFeatures>(const VkPhysicalDevicePipelineCreationCacheControlFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineCreationCacheControl", toStringFlags, tabCount, tabSize, ToString(obj.pipelineCreationCacheControl, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryBarrier2>(const VkMemoryBarrier2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.srcStageMask)));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.srcAccessMask)));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.dstStageMask)));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.dstAccessMask)));
        }
    );
}

template <> std::string ToString<VkBufferMemoryBarrier2>(const VkBufferMemoryBarrier2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.srcStageMask)));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.srcAccessMask)));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.dstStageMask)));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.dstAccessMask)));
            FieldToString(strStrm, false, "srcQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.srcQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.dstQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageMemoryBarrier2>(const VkImageMemoryBarrier2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.srcStageMask)));
            FieldToString(strStrm, false, "srcAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.srcAccessMask)));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.dstStageMask)));
            FieldToString(strStrm, false, "dstAccessMask", toStringFlags, tabCount, tabSize, Quote(VkAccessFlags2ToString(obj.dstAccessMask)));
            FieldToString(strStrm, false, "oldLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.oldLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "newLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.newLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "srcQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.srcQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstQueueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.dstQueueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "subresourceRange", toStringFlags, tabCount, tabSize, ToString(obj.subresourceRange, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDependencyInfo>(const VkDependencyInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyFlags", toStringFlags, tabCount, tabSize, ToString(obj.dependencyFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(obj.memoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryBarriers", toStringFlags, tabCount, tabSize, ArrayToString(obj.memoryBarrierCount, obj.pMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(obj.bufferMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferMemoryBarriers", toStringFlags, tabCount, tabSize, ArrayToString(obj.bufferMemoryBarrierCount, obj.pBufferMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(obj.imageMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageMemoryBarriers", toStringFlags, tabCount, tabSize, ArrayToString(obj.imageMemoryBarrierCount, obj.pImageMemoryBarriers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreSubmitInfo>(const VkSemaphoreSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "value", toStringFlags, tabCount, tabSize, ToString(obj.value, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.stageMask)));
            FieldToString(strStrm, false, "deviceIndex", toStringFlags, tabCount, tabSize, ToString(obj.deviceIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferSubmitInfo>(const VkCommandBufferSubmitInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.commandBuffer)));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubmitInfo2>(const VkSubmitInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphoreInfos", toStringFlags, tabCount, tabSize, ArrayToString(obj.waitSemaphoreInfoCount, obj.pWaitSemaphoreInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "commandBufferInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.commandBufferInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBufferInfos", toStringFlags, tabCount, tabSize, ArrayToString(obj.commandBufferInfoCount, obj.pCommandBufferInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphoreInfos", toStringFlags, tabCount, tabSize, ArrayToString(obj.signalSemaphoreInfoCount, obj.pSignalSemaphoreInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSynchronization2Features>(const VkPhysicalDeviceSynchronization2Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "synchronization2", toStringFlags, tabCount, tabSize, ToString(obj.synchronization2, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>(const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderZeroInitializeWorkgroupMemory", toStringFlags, tabCount, tabSize, ToString(obj.shaderZeroInitializeWorkgroupMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageRobustnessFeatures>(const VkPhysicalDeviceImageRobustnessFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustImageAccess", toStringFlags, tabCount, tabSize, ToString(obj.robustImageAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferCopy2>(const VkBufferCopy2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyBufferInfo2>(const VkCopyBufferInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcBuffer)));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstBuffer)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageCopy2>(const VkImageCopy2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyImageInfo2>(const VkCopyImageInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcImage)));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstImage)));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferImageCopy2>(const VkBufferImageCopy2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferOffset", toStringFlags, tabCount, tabSize, ToString(obj.bufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferRowLength", toStringFlags, tabCount, tabSize, ToString(obj.bufferRowLength, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferImageHeight", toStringFlags, tabCount, tabSize, ToString(obj.bufferImageHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageSubresource", toStringFlags, tabCount, tabSize, ToString(obj.imageSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageOffset", toStringFlags, tabCount, tabSize, ToString(obj.imageOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageExtent", toStringFlags, tabCount, tabSize, ToString(obj.imageExtent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyBufferToImageInfo2>(const VkCopyBufferToImageInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcBuffer)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstImage)));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyImageToBufferInfo2>(const VkCopyImageToBufferInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcImage)));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstBuffer)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageBlit2>(const VkImageBlit2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffsets", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.srcOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffsets", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.dstOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBlitImageInfo2>(const VkBlitImageInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcImage)));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstImage)));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filter", toStringFlags, tabCount, tabSize, Quote(ToString(obj.filter, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImageResolve2>(const VkImageResolve2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcSubresource", toStringFlags, tabCount, tabSize, ToString(obj.srcSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstSubresource", toStringFlags, tabCount, tabSize, ToString(obj.dstSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkResolveImageInfo2>(const VkResolveImageInfo2& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcImage)));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstImage)));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSubgroupSizeControlFeatures>(const VkPhysicalDeviceSubgroupSizeControlFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subgroupSizeControl", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSizeControl, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeFullSubgroups", toStringFlags, tabCount, tabSize, ToString(obj.computeFullSubgroups, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSubgroupSizeControlProperties>(const VkPhysicalDeviceSubgroupSizeControlProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSubgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.minSubgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSubgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.maxSubgroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxComputeWorkgroupSubgroups", toStringFlags, tabCount, tabSize, ToString(obj.maxComputeWorkgroupSubgroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "requiredSubgroupSizeStages", toStringFlags, tabCount, tabSize, ToString(obj.requiredSubgroupSizeStages, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>(const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "requiredSubgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.requiredSubgroupSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceInlineUniformBlockFeatures>(const VkPhysicalDeviceInlineUniformBlockFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inlineUniformBlock", toStringFlags, tabCount, tabSize, ToString(obj.inlineUniformBlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingInlineUniformBlockUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingInlineUniformBlockUpdateAfterBind, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceInlineUniformBlockProperties>(const VkPhysicalDeviceInlineUniformBlockProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInlineUniformBlockSize", toStringFlags, tabCount, tabSize, ToString(obj.maxInlineUniformBlockSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetInlineUniformBlocks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindInlineUniformBlocks", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkWriteDescriptorSetInlineUniformBlock>(const VkWriteDescriptorSetInlineUniformBlock& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(obj.dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pData)));
        }
    );
}

template <> std::string ToString<VkDescriptorPoolInlineUniformBlockCreateInfo>(const VkDescriptorPoolInlineUniformBlockCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInlineUniformBlockBindings", toStringFlags, tabCount, tabSize, ToString(obj.maxInlineUniformBlockBindings, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTextureCompressionASTCHDRFeatures>(const VkPhysicalDeviceTextureCompressionASTCHDRFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureCompressionASTC_HDR", toStringFlags, tabCount, tabSize, ToString(obj.textureCompressionASTC_HDR, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderingAttachmentInfo>(const VkRenderingAttachmentInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.imageView)));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "resolveMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.resolveMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "resolveImageView", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.resolveImageView)));
            FieldToString(strStrm, false, "resolveImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.resolveImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "loadOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.loadOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "storeOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.storeOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "clearValue", toStringFlags, tabCount, tabSize, ToString(obj.clearValue, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderingInfo>(const VkRenderingInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderArea", toStringFlags, tabCount, tabSize, ToString(obj.renderArea, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewMask", toStringFlags, tabCount, tabSize, ToString(obj.viewMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachments", toStringFlags, tabCount, tabSize, ArrayToString(obj.colorAttachmentCount, obj.pColorAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDepthAttachment", toStringFlags, tabCount, tabSize, (obj.pDepthAttachment ? ToString(*obj.pDepthAttachment, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pStencilAttachment", toStringFlags, tabCount, tabSize, (obj.pStencilAttachment ? ToString(*obj.pStencilAttachment, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkPipelineRenderingCreateInfo>(const VkPipelineRenderingCreateInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewMask", toStringFlags, tabCount, tabSize, ToString(obj.viewMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachmentFormats", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.colorAttachmentCount, obj.pColorAttachmentFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthAttachmentFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthAttachmentFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilAttachmentFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilAttachmentFormat, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDynamicRenderingFeatures>(const VkPhysicalDeviceDynamicRenderingFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dynamicRendering", toStringFlags, tabCount, tabSize, ToString(obj.dynamicRendering, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferInheritanceRenderingInfo>(const VkCommandBufferInheritanceRenderingInfo& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewMask", toStringFlags, tabCount, tabSize, ToString(obj.viewMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachmentFormats", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.colorAttachmentCount, obj.pColorAttachmentFormats, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthAttachmentFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthAttachmentFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stencilAttachmentFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stencilAttachmentFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "rasterizationSamples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rasterizationSamples, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderIntegerDotProductFeatures>(const VkPhysicalDeviceShaderIntegerDotProductFeatures& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderIntegerDotProduct", toStringFlags, tabCount, tabSize, ToString(obj.shaderIntegerDotProduct, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderIntegerDotProductProperties>(const VkPhysicalDeviceShaderIntegerDotProductProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct8BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct8BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct4x8BitPackedMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct4x8BitPackedMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct16BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct16BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct32BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct32BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProduct64BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProduct64BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitUnsignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitSignedAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitSignedAccelerated, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated", toStringFlags, tabCount, tabSize, ToString(obj.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTexelBufferAlignmentProperties>(const VkPhysicalDeviceTexelBufferAlignmentProperties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageTexelBufferOffsetAlignmentBytes", toStringFlags, tabCount, tabSize, ToString(obj.storageTexelBufferOffsetAlignmentBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageTexelBufferOffsetSingleTexelAlignment", toStringFlags, tabCount, tabSize, ToString(obj.storageTexelBufferOffsetSingleTexelAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformTexelBufferOffsetAlignmentBytes", toStringFlags, tabCount, tabSize, ToString(obj.uniformTexelBufferOffsetAlignmentBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "uniformTexelBufferOffsetSingleTexelAlignment", toStringFlags, tabCount, tabSize, ToString(obj.uniformTexelBufferOffsetSingleTexelAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFormatProperties3>(const VkFormatProperties3& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "linearTilingFeatures", toStringFlags, tabCount, tabSize, Quote(VkFormatFeatureFlags2ToString(obj.linearTilingFeatures)));
            FieldToString(strStrm, false, "optimalTilingFeatures", toStringFlags, tabCount, tabSize, Quote(VkFormatFeatureFlags2ToString(obj.optimalTilingFeatures)));
            FieldToString(strStrm, false, "bufferFeatures", toStringFlags, tabCount, tabSize, Quote(VkFormatFeatureFlags2ToString(obj.bufferFeatures)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMaintenance4Features>(const VkPhysicalDeviceMaintenance4Features& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maintenance4", toStringFlags, tabCount, tabSize, ToString(obj.maintenance4, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMaintenance4Properties>(const VkPhysicalDeviceMaintenance4Properties& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBufferSize", toStringFlags, tabCount, tabSize, ToString(obj.maxBufferSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceBufferMemoryRequirements>(const VkDeviceBufferMemoryRequirements& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, (obj.pCreateInfo ? ToString(*obj.pCreateInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkDeviceImageMemoryRequirements>(const VkDeviceImageMemoryRequirements& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, (obj.pCreateInfo ? ToString(*obj.pCreateInfo, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "planeAspect", toStringFlags, tabCount, tabSize, Quote(ToString(obj.planeAspect, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSurfaceCapabilitiesKHR>(const VkSurfaceCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "minImageCount", toStringFlags, tabCount, tabSize, ToString(obj.minImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageCount", toStringFlags, tabCount, tabSize, ToString(obj.maxImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "currentExtent", toStringFlags, tabCount, tabSize, ToString(obj.currentExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.minImageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxImageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxImageArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedTransforms", toStringFlags, tabCount, tabSize, ToString(obj.supportedTransforms, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "currentTransform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.currentTransform, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "supportedCompositeAlpha", toStringFlags, tabCount, tabSize, ToString(obj.supportedCompositeAlpha, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedUsageFlags", toStringFlags, tabCount, tabSize, ToString(obj.supportedUsageFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceFormatKHR>(const VkSurfaceFormatKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "colorSpace", toStringFlags, tabCount, tabSize, Quote(ToString(obj.colorSpace, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSwapchainCreateInfoKHR>(const VkSwapchainCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.surface)));
            FieldToString(strStrm, false, "minImageCount", toStringFlags, tabCount, tabSize, ToString(obj.minImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "imageColorSpace", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageColorSpace, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "imageExtent", toStringFlags, tabCount, tabSize, ToString(obj.imageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.imageArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageUsage", toStringFlags, tabCount, tabSize, ToString(obj.imageUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageSharingMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageSharingMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queueFamilyIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueFamilyIndexCount, obj.pQueueFamilyIndices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "preTransform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.preTransform, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "compositeAlpha", toStringFlags, tabCount, tabSize, Quote(ToString(obj.compositeAlpha, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "presentMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.presentMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "clipped", toStringFlags, tabCount, tabSize, ToString(obj.clipped, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "oldSwapchain", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.oldSwapchain)));
        }
    );
}

template <> std::string ToString<VkPresentInfoKHR>(const VkPresentInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphores", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.waitSemaphoreCount, obj.pWaitSemaphores, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchains", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.swapchainCount, obj.pSwapchains, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.swapchainCount, obj.pImageIndices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pResults", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.swapchainCount, obj.pResults, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageSwapchainCreateInfoKHR>(const VkImageSwapchainCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.swapchain)));
        }
    );
}

template <> std::string ToString<VkBindImageMemorySwapchainInfoKHR>(const VkBindImageMemorySwapchainInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.swapchain)));
            FieldToString(strStrm, false, "imageIndex", toStringFlags, tabCount, tabSize, ToString(obj.imageIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAcquireNextImageInfoKHR>(const VkAcquireNextImageInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.swapchain)));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(obj.timeout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.fence)));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(obj.deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupPresentCapabilitiesKHR>(const VkDeviceGroupPresentCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentMask", toStringFlags, tabCount, tabSize, ArrayToString(VK_MAX_DEVICE_GROUP_SIZE, obj.presentMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "modes", toStringFlags, tabCount, tabSize, ToString(obj.modes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceGroupPresentInfoKHR>(const VkDeviceGroupPresentInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeviceMasks", toStringFlags, tabCount, tabSize, ArrayToString(obj.swapchainCount, obj.pDeviceMasks, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkDeviceGroupSwapchainCreateInfoKHR>(const VkDeviceGroupSwapchainCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "modes", toStringFlags, tabCount, tabSize, ToString(obj.modes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayModeParametersKHR>(const VkDisplayModeParametersKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "visibleRegion", toStringFlags, tabCount, tabSize, ToString(obj.visibleRegion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "refreshRate", toStringFlags, tabCount, tabSize, ToString(obj.refreshRate, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayModeCreateInfoKHR>(const VkDisplayModeCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "parameters", toStringFlags, tabCount, tabSize, ToString(obj.parameters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayModePropertiesKHR>(const VkDisplayModePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "displayMode", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.displayMode)));
            FieldToString(strStrm, false, "parameters", toStringFlags, tabCount, tabSize, ToString(obj.parameters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPlaneCapabilitiesKHR>(const VkDisplayPlaneCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "supportedAlpha", toStringFlags, tabCount, tabSize, ToString(obj.supportedAlpha, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSrcPosition", toStringFlags, tabCount, tabSize, ToString(obj.minSrcPosition, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSrcPosition", toStringFlags, tabCount, tabSize, ToString(obj.maxSrcPosition, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSrcExtent", toStringFlags, tabCount, tabSize, ToString(obj.minSrcExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSrcExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxSrcExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minDstPosition", toStringFlags, tabCount, tabSize, ToString(obj.minDstPosition, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDstPosition", toStringFlags, tabCount, tabSize, ToString(obj.maxDstPosition, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minDstExtent", toStringFlags, tabCount, tabSize, ToString(obj.minDstExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDstExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxDstExtent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPlanePropertiesKHR>(const VkDisplayPlanePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "currentDisplay", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.currentDisplay)));
            FieldToString(strStrm, false, "currentStackIndex", toStringFlags, tabCount, tabSize, ToString(obj.currentStackIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPropertiesKHR>(const VkDisplayPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "display", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.display)));
            FieldToString(strStrm, false, "displayName", toStringFlags, tabCount, tabSize, CStrToString(obj.displayName));
            FieldToString(strStrm, false, "physicalDimensions", toStringFlags, tabCount, tabSize, ToString(obj.physicalDimensions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "physicalResolution", toStringFlags, tabCount, tabSize, ToString(obj.physicalResolution, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedTransforms", toStringFlags, tabCount, tabSize, ToString(obj.supportedTransforms, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "planeReorderPossible", toStringFlags, tabCount, tabSize, ToString(obj.planeReorderPossible, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "persistentContent", toStringFlags, tabCount, tabSize, ToString(obj.persistentContent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplaySurfaceCreateInfoKHR>(const VkDisplaySurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayMode", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.displayMode)));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(obj.planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "planeStackIndex", toStringFlags, tabCount, tabSize, ToString(obj.planeStackIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.transform, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "globalAlpha", toStringFlags, tabCount, tabSize, ToString(obj.globalAlpha, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "alphaMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.alphaMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "imageExtent", toStringFlags, tabCount, tabSize, ToString(obj.imageExtent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPresentInfoKHR>(const VkDisplayPresentInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcRect", toStringFlags, tabCount, tabSize, ToString(obj.srcRect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstRect", toStringFlags, tabCount, tabSize, ToString(obj.dstRect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "persistent", toStringFlags, tabCount, tabSize, ToString(obj.persistent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkXlibSurfaceCreateInfoKHR>(const VkXlibSurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.dpy)));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, ToString(obj.window, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkXcbSurfaceCreateInfoKHR>(const VkXcbSurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connection", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.connection)));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, ToString(obj.window, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkWaylandSurfaceCreateInfoKHR>(const VkWaylandSurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.display)));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.surface)));
        }
    );
}

template <> std::string ToString<VkAndroidSurfaceCreateInfoKHR>(const VkAndroidSurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.window)));
        }
    );
}

template <> std::string ToString<VkWin32SurfaceCreateInfoKHR>(const VkWin32SurfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hinstance", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.hinstance)));
            FieldToString(strStrm, false, "hwnd", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.hwnd)));
        }
    );
}

template <> std::string ToString<VkQueueFamilyQueryResultStatusPropertiesKHR>(const VkQueueFamilyQueryResultStatusPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryResultStatusSupport", toStringFlags, tabCount, tabSize, ToString(obj.queryResultStatusSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyVideoPropertiesKHR>(const VkQueueFamilyVideoPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoCodecOperations", toStringFlags, tabCount, tabSize, ToString(obj.videoCodecOperations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoProfileInfoKHR>(const VkVideoProfileInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoCodecOperation", toStringFlags, tabCount, tabSize, Quote(ToString(obj.videoCodecOperation, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "chromaSubsampling", toStringFlags, tabCount, tabSize, ToString(obj.chromaSubsampling, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lumaBitDepth", toStringFlags, tabCount, tabSize, ToString(obj.lumaBitDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "chromaBitDepth", toStringFlags, tabCount, tabSize, ToString(obj.chromaBitDepth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoProfileListInfoKHR>(const VkVideoProfileListInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "profileCount", toStringFlags, tabCount, tabSize, ToString(obj.profileCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProfiles", toStringFlags, tabCount, tabSize, ArrayToString(obj.profileCount, obj.pProfiles, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoCapabilitiesKHR>(const VkVideoCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minBitstreamBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minBitstreamBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minBitstreamBufferSizeAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minBitstreamBufferSizeAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pictureAccessGranularity", toStringFlags, tabCount, tabSize, ToString(obj.pictureAccessGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minCodedExtent", toStringFlags, tabCount, tabSize, ToString(obj.minCodedExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxCodedExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxCodedExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDpbSlots", toStringFlags, tabCount, tabSize, ToString(obj.maxDpbSlots, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxActiveReferencePictures", toStringFlags, tabCount, tabSize, ToString(obj.maxActiveReferencePictures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdHeaderVersion", toStringFlags, tabCount, tabSize, ToString(obj.stdHeaderVersion, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVideoFormatInfoKHR>(const VkPhysicalDeviceVideoFormatInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageUsage", toStringFlags, tabCount, tabSize, ToString(obj.imageUsage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoFormatPropertiesKHR>(const VkVideoFormatPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "componentMapping", toStringFlags, tabCount, tabSize, ToString(obj.componentMapping, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCreateFlags", toStringFlags, tabCount, tabSize, ToString(obj.imageCreateFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "imageTiling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageTiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "imageUsageFlags", toStringFlags, tabCount, tabSize, ToString(obj.imageUsageFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoPictureResourceInfoKHR>(const VkVideoPictureResourceInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "codedOffset", toStringFlags, tabCount, tabSize, ToString(obj.codedOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "codedExtent", toStringFlags, tabCount, tabSize, ToString(obj.codedExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseArrayLayer", toStringFlags, tabCount, tabSize, ToString(obj.baseArrayLayer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageViewBinding", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.imageViewBinding)));
        }
    );
}

template <> std::string ToString<VkVideoReferenceSlotInfoKHR>(const VkVideoReferenceSlotInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "slotIndex", toStringFlags, tabCount, tabSize, ToString(obj.slotIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPictureResource", toStringFlags, tabCount, tabSize, (obj.pPictureResource ? ToString(*obj.pPictureResource, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoSessionMemoryRequirementsKHR>(const VkVideoSessionMemoryRequirementsKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBindIndex", toStringFlags, tabCount, tabSize, ToString(obj.memoryBindIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryRequirements", toStringFlags, tabCount, tabSize, ToString(obj.memoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindVideoSessionMemoryInfoKHR>(const VkBindVideoSessionMemoryInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBindIndex", toStringFlags, tabCount, tabSize, ToString(obj.memoryBindIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memorySize", toStringFlags, tabCount, tabSize, ToString(obj.memorySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoSessionCreateInfoKHR>(const VkVideoSessionCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVideoProfile", toStringFlags, tabCount, tabSize, (obj.pVideoProfile ? ToString(*obj.pVideoProfile, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pictureFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pictureFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "maxCodedExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxCodedExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "referencePictureFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.referencePictureFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "maxDpbSlots", toStringFlags, tabCount, tabSize, ToString(obj.maxDpbSlots, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxActiveReferencePictures", toStringFlags, tabCount, tabSize, ToString(obj.maxActiveReferencePictures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdHeaderVersion", toStringFlags, tabCount, tabSize, (obj.pStdHeaderVersion ? ToString(*obj.pStdHeaderVersion, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoSessionParametersCreateInfoKHR>(const VkVideoSessionParametersCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoSessionParametersTemplate", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.videoSessionParametersTemplate)));
            FieldToString(strStrm, false, "videoSession", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.videoSession)));
        }
    );
}

template <> std::string ToString<VkVideoSessionParametersUpdateInfoKHR>(const VkVideoSessionParametersUpdateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "updateSequenceCount", toStringFlags, tabCount, tabSize, ToString(obj.updateSequenceCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoBeginCodingInfoKHR>(const VkVideoBeginCodingInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoSession", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.videoSession)));
            FieldToString(strStrm, false, "videoSessionParameters", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.videoSessionParameters)));
            FieldToString(strStrm, false, "referenceSlotCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceSlotCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceSlots", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceSlotCount, obj.pReferenceSlots, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEndCodingInfoKHR>(const VkVideoEndCodingInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoCodingControlInfoKHR>(const VkVideoCodingControlInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeCapabilitiesKHR>(const VkVideoDecodeCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeUsageInfoKHR>(const VkVideoDecodeUsageInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoUsageHints", toStringFlags, tabCount, tabSize, ToString(obj.videoUsageHints, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeInfoKHR>(const VkVideoDecodeInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.srcBuffer)));
            FieldToString(strStrm, false, "srcBufferOffset", toStringFlags, tabCount, tabSize, ToString(obj.srcBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcBufferRange", toStringFlags, tabCount, tabSize, ToString(obj.srcBufferRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstPictureResource", toStringFlags, tabCount, tabSize, ToString(obj.dstPictureResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSetupReferenceSlot", toStringFlags, tabCount, tabSize, (obj.pSetupReferenceSlot ? ToString(*obj.pSetupReferenceSlot, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "referenceSlotCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceSlotCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceSlots", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceSlotCount, obj.pReferenceSlots, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264ProfileInfoKHR>(const VkVideoDecodeH264ProfileInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdProfileIdc", toStringFlags, tabCount, tabSize, ToString(obj.stdProfileIdc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pictureLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pictureLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264CapabilitiesKHR>(const VkVideoDecodeH264CapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLevelIdc", toStringFlags, tabCount, tabSize, ToString(obj.maxLevelIdc, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fieldOffsetGranularity", toStringFlags, tabCount, tabSize, ToString(obj.fieldOffsetGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264SessionParametersAddInfoKHR>(const VkVideoDecodeH264SessionParametersAddInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdSPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdSPSCount, obj.pStdSPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdPPSCount, obj.pStdPPSs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264SessionParametersCreateInfoKHR>(const VkVideoDecodeH264SessionParametersCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParametersAddInfo", toStringFlags, tabCount, tabSize, (obj.pParametersAddInfo ? ToString(*obj.pParametersAddInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264PictureInfoKHR>(const VkVideoDecodeH264PictureInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPictureInfo", toStringFlags, tabCount, tabSize, (obj.pStdPictureInfo ? ToString(*obj.pStdPictureInfo, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "sliceCount", toStringFlags, tabCount, tabSize, ToString(obj.sliceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSliceOffsets", toStringFlags, tabCount, tabSize, ArrayToString(obj.sliceCount, obj.pSliceOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH264DpbSlotInfoKHR>(const VkVideoDecodeH264DpbSlotInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdReferenceInfo", toStringFlags, tabCount, tabSize, (obj.pStdReferenceInfo ? ToString(*obj.pStdReferenceInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkRenderingFragmentShadingRateAttachmentInfoKHR>(const VkRenderingFragmentShadingRateAttachmentInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.imageView)));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "shadingRateAttachmentTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateAttachmentTexelSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderingFragmentDensityMapAttachmentInfoEXT>(const VkRenderingFragmentDensityMapAttachmentInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.imageView)));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageLayout, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkAttachmentSampleCountInfoAMD>(const VkAttachmentSampleCountInfoAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorAttachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.colorAttachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorAttachmentSamples", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.colorAttachmentCount, obj.pColorAttachmentSamples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthStencilAttachmentSamples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.depthStencilAttachmentSamples, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkMultiviewPerViewAttributesInfoNVX>(const VkMultiviewPerViewAttributesInfoNVX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "perViewAttributes", toStringFlags, tabCount, tabSize, ToString(obj.perViewAttributes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "perViewAttributesPositionXOnly", toStringFlags, tabCount, tabSize, ToString(obj.perViewAttributesPositionXOnly, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportMemoryWin32HandleInfoKHR>(const VkImportMemoryWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.handle)));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkExportMemoryWin32HandleInfoKHR>(const VkExportMemoryWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, (obj.pAttributes ? ToString(*obj.pAttributes, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "dwAccess", toStringFlags, tabCount, tabSize, ToString(obj.dwAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkMemoryWin32HandlePropertiesKHR>(const VkMemoryWin32HandlePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryGetWin32HandleInfoKHR>(const VkMemoryGetWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImportMemoryFdInfoKHR>(const VkImportMemoryFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(obj.fd, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryFdPropertiesKHR>(const VkMemoryFdPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryGetFdInfoKHR>(const VkMemoryGetFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkWin32KeyedMutexAcquireReleaseInfoKHR>(const VkWin32KeyedMutexAcquireReleaseInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "acquireCount", toStringFlags, tabCount, tabSize, ToString(obj.acquireCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireSyncs", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.acquireCount, obj.pAcquireSyncs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireKeys", toStringFlags, tabCount, tabSize, ArrayToString(obj.acquireCount, obj.pAcquireKeys, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireTimeouts", toStringFlags, tabCount, tabSize, ArrayToString(obj.acquireCount, obj.pAcquireTimeouts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "releaseCount", toStringFlags, tabCount, tabSize, ToString(obj.releaseCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReleaseSyncs", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.releaseCount, obj.pReleaseSyncs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReleaseKeys", toStringFlags, tabCount, tabSize, ArrayToString(obj.releaseCount, obj.pReleaseKeys, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportSemaphoreWin32HandleInfoKHR>(const VkImportSemaphoreWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.handle)));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkExportSemaphoreWin32HandleInfoKHR>(const VkExportSemaphoreWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, (obj.pAttributes ? ToString(*obj.pAttributes, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "dwAccess", toStringFlags, tabCount, tabSize, ToString(obj.dwAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkD3D12FenceSubmitInfoKHR>(const VkD3D12FenceSubmitInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitSemaphoreValuesCount", toStringFlags, tabCount, tabSize, ToString(obj.waitSemaphoreValuesCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pWaitSemaphoreValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.waitSemaphoreValuesCount, obj.pWaitSemaphoreValues, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "signalSemaphoreValuesCount", toStringFlags, tabCount, tabSize, ToString(obj.signalSemaphoreValuesCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSignalSemaphoreValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.signalSemaphoreValuesCount, obj.pSignalSemaphoreValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreGetWin32HandleInfoKHR>(const VkSemaphoreGetWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImportSemaphoreFdInfoKHR>(const VkImportSemaphoreFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(obj.fd, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreGetFdInfoKHR>(const VkSemaphoreGetFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePushDescriptorPropertiesKHR>(const VkPhysicalDevicePushDescriptorPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPushDescriptors", toStringFlags, tabCount, tabSize, ToString(obj.maxPushDescriptors, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRectLayerKHR>(const VkRectLayerKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extent", toStringFlags, tabCount, tabSize, ToString(obj.extent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layer", toStringFlags, tabCount, tabSize, ToString(obj.layer, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentRegionKHR>(const VkPresentRegionKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "rectangleCount", toStringFlags, tabCount, tabSize, ToString(obj.rectangleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRectangles", toStringFlags, tabCount, tabSize, ArrayToString(obj.rectangleCount, obj.pRectangles, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentRegionsKHR>(const VkPresentRegionsKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.swapchainCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSharedPresentSurfaceCapabilitiesKHR>(const VkSharedPresentSurfaceCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sharedPresentSupportedUsageFlags", toStringFlags, tabCount, tabSize, ToString(obj.sharedPresentSupportedUsageFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportFenceWin32HandleInfoKHR>(const VkImportFenceWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.fence)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.handle)));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkExportFenceWin32HandleInfoKHR>(const VkExportFenceWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, (obj.pAttributes ? ToString(*obj.pAttributes, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "dwAccess", toStringFlags, tabCount, tabSize, ToString(obj.dwAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, (obj.name ? ToString(*obj.name, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkFenceGetWin32HandleInfoKHR>(const VkFenceGetWin32HandleInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.fence)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImportFenceFdInfoKHR>(const VkImportFenceFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.fence)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(obj.fd, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFenceGetFdInfoKHR>(const VkFenceGetFdInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.fence)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePerformanceQueryFeaturesKHR>(const VkPhysicalDevicePerformanceQueryFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "performanceCounterQueryPools", toStringFlags, tabCount, tabSize, ToString(obj.performanceCounterQueryPools, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "performanceCounterMultipleQueryPools", toStringFlags, tabCount, tabSize, ToString(obj.performanceCounterMultipleQueryPools, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePerformanceQueryPropertiesKHR>(const VkPhysicalDevicePerformanceQueryPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "allowCommandBufferQueryCopies", toStringFlags, tabCount, tabSize, ToString(obj.allowCommandBufferQueryCopies, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPerformanceCounterKHR>(const VkPerformanceCounterKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "unit", toStringFlags, tabCount, tabSize, Quote(ToString(obj.unit, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "scope", toStringFlags, tabCount, tabSize, Quote(ToString(obj.scope, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "storage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.storage, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "uuid", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.uuid)));
        }
    );
}

template <> std::string ToString<VkPerformanceCounterDescriptionKHR>(const VkPerformanceCounterDescriptionKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, CStrToString(obj.name));
            FieldToString(strStrm, false, "category", toStringFlags, tabCount, tabSize, CStrToString(obj.category));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
        }
    );
}

template <> std::string ToString<VkQueryPoolPerformanceCreateInfoKHR>(const VkQueryPoolPerformanceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.counterIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.counterIndexCount, obj.pCounterIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAcquireProfilingLockInfoKHR>(const VkAcquireProfilingLockInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(obj.timeout, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPerformanceQuerySubmitInfoKHR>(const VkPerformanceQuerySubmitInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterPassIndex", toStringFlags, tabCount, tabSize, ToString(obj.counterPassIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSurfaceInfo2KHR>(const VkPhysicalDeviceSurfaceInfo2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.surface)));
        }
    );
}

template <> std::string ToString<VkSurfaceCapabilities2KHR>(const VkSurfaceCapabilities2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surfaceCapabilities", toStringFlags, tabCount, tabSize, ToString(obj.surfaceCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceFormat2KHR>(const VkSurfaceFormat2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surfaceFormat", toStringFlags, tabCount, tabSize, ToString(obj.surfaceFormat, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayProperties2KHR>(const VkDisplayProperties2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayProperties", toStringFlags, tabCount, tabSize, ToString(obj.displayProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPlaneProperties2KHR>(const VkDisplayPlaneProperties2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayPlaneProperties", toStringFlags, tabCount, tabSize, ToString(obj.displayPlaneProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayModeProperties2KHR>(const VkDisplayModeProperties2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayModeProperties", toStringFlags, tabCount, tabSize, ToString(obj.displayModeProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPlaneInfo2KHR>(const VkDisplayPlaneInfo2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.mode)));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(obj.planeIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPlaneCapabilities2KHR>(const VkDisplayPlaneCapabilities2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "capabilities", toStringFlags, tabCount, tabSize, ToString(obj.capabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePortabilitySubsetFeaturesKHR>(const VkPhysicalDevicePortabilitySubsetFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "constantAlphaColorBlendFactors", toStringFlags, tabCount, tabSize, ToString(obj.constantAlphaColorBlendFactors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "events", toStringFlags, tabCount, tabSize, ToString(obj.events, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageViewFormatReinterpretation", toStringFlags, tabCount, tabSize, ToString(obj.imageViewFormatReinterpretation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageViewFormatSwizzle", toStringFlags, tabCount, tabSize, ToString(obj.imageViewFormatSwizzle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageView2DOn3DImage", toStringFlags, tabCount, tabSize, ToString(obj.imageView2DOn3DImage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multisampleArrayImage", toStringFlags, tabCount, tabSize, ToString(obj.multisampleArrayImage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mutableComparisonSamplers", toStringFlags, tabCount, tabSize, ToString(obj.mutableComparisonSamplers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pointPolygons", toStringFlags, tabCount, tabSize, ToString(obj.pointPolygons, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerMipLodBias", toStringFlags, tabCount, tabSize, ToString(obj.samplerMipLodBias, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "separateStencilMaskRef", toStringFlags, tabCount, tabSize, ToString(obj.separateStencilMaskRef, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSampleRateInterpolationFunctions", toStringFlags, tabCount, tabSize, ToString(obj.shaderSampleRateInterpolationFunctions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tessellationIsolines", toStringFlags, tabCount, tabSize, ToString(obj.tessellationIsolines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tessellationPointMode", toStringFlags, tabCount, tabSize, ToString(obj.tessellationPointMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "triangleFans", toStringFlags, tabCount, tabSize, ToString(obj.triangleFans, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeAccessBeyondStride", toStringFlags, tabCount, tabSize, ToString(obj.vertexAttributeAccessBeyondStride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePortabilitySubsetPropertiesKHR>(const VkPhysicalDevicePortabilitySubsetPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minVertexInputBindingStrideAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minVertexInputBindingStrideAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderClockFeaturesKHR>(const VkPhysicalDeviceShaderClockFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSubgroupClock", toStringFlags, tabCount, tabSize, ToString(obj.shaderSubgroupClock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderDeviceClock", toStringFlags, tabCount, tabSize, ToString(obj.shaderDeviceClock, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265ProfileInfoKHR>(const VkVideoDecodeH265ProfileInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdProfileIdc", toStringFlags, tabCount, tabSize, ToString(obj.stdProfileIdc, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265CapabilitiesKHR>(const VkVideoDecodeH265CapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLevelIdc", toStringFlags, tabCount, tabSize, ToString(obj.maxLevelIdc, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265SessionParametersAddInfoKHR>(const VkVideoDecodeH265SessionParametersAddInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdVPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdVPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdVPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdVPSCount, obj.pStdVPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdSPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdSPSCount, obj.pStdSPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdPPSCount, obj.pStdPPSs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265SessionParametersCreateInfoKHR>(const VkVideoDecodeH265SessionParametersCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdVPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdVPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParametersAddInfo", toStringFlags, tabCount, tabSize, (obj.pParametersAddInfo ? ToString(*obj.pParametersAddInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265PictureInfoKHR>(const VkVideoDecodeH265PictureInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPictureInfo", toStringFlags, tabCount, tabSize, (obj.pStdPictureInfo ? ToString(*obj.pStdPictureInfo, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "sliceSegmentCount", toStringFlags, tabCount, tabSize, ToString(obj.sliceSegmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSliceSegmentOffsets", toStringFlags, tabCount, tabSize, ArrayToString(obj.sliceSegmentCount, obj.pSliceSegmentOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoDecodeH265DpbSlotInfoKHR>(const VkVideoDecodeH265DpbSlotInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdReferenceInfo", toStringFlags, tabCount, tabSize, (obj.pStdReferenceInfo ? ToString(*obj.pStdReferenceInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkDeviceQueueGlobalPriorityCreateInfoKHR>(const VkDeviceQueueGlobalPriorityCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "globalPriority", toStringFlags, tabCount, tabSize, Quote(ToString(obj.globalPriority, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR>(const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "globalPriorityQuery", toStringFlags, tabCount, tabSize, ToString(obj.globalPriorityQuery, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyGlobalPriorityPropertiesKHR>(const VkQueueFamilyGlobalPriorityPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "priorityCount", toStringFlags, tabCount, tabSize, ToString(obj.priorityCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "priorities", toStringFlags, tabCount, tabSize, ArrayToString(VK_MAX_GLOBAL_PRIORITY_SIZE_KHR, obj.priorities, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkFragmentShadingRateAttachmentInfoKHR>(const VkFragmentShadingRateAttachmentInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFragmentShadingRateAttachment", toStringFlags, tabCount, tabSize, (obj.pFragmentShadingRateAttachment ? ToString(*obj.pFragmentShadingRateAttachment, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "shadingRateAttachmentTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateAttachmentTexelSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineFragmentShadingRateStateCreateInfoKHR>(const VkPipelineFragmentShadingRateStateCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentSize", toStringFlags, tabCount, tabSize, ToString(obj.fragmentSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>(const VkPhysicalDeviceFragmentShadingRateFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineFragmentShadingRate", toStringFlags, tabCount, tabSize, ToString(obj.pipelineFragmentShadingRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveFragmentShadingRate", toStringFlags, tabCount, tabSize, ToString(obj.primitiveFragmentShadingRate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentFragmentShadingRate", toStringFlags, tabCount, tabSize, ToString(obj.attachmentFragmentShadingRate, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShadingRatePropertiesKHR>(const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minFragmentShadingRateAttachmentTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.minFragmentShadingRateAttachmentTexelSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentShadingRateAttachmentTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentShadingRateAttachmentTexelSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentShadingRateAttachmentTexelSizeAspectRatio", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentShadingRateAttachmentTexelSizeAspectRatio, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveFragmentShadingRateWithMultipleViewports", toStringFlags, tabCount, tabSize, ToString(obj.primitiveFragmentShadingRateWithMultipleViewports, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layeredShadingRateAttachments", toStringFlags, tabCount, tabSize, ToString(obj.layeredShadingRateAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateNonTrivialCombinerOps", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateNonTrivialCombinerOps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentSize", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentSizeAspectRatio", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentSizeAspectRatio, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentShadingRateCoverageSamples", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentShadingRateCoverageSamples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentShadingRateRasterizationSamples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.maxFragmentShadingRateRasterizationSamples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "fragmentShadingRateWithShaderDepthStencilWrites", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithShaderDepthStencilWrites, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateWithSampleMask", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithSampleMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateWithShaderSampleMask", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithShaderSampleMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateWithConservativeRasterization", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithConservativeRasterization, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateWithFragmentShaderInterlock", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithFragmentShaderInterlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateWithCustomSampleLocations", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateWithCustomSampleLocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateStrictMultiplyCombiner", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateStrictMultiplyCombiner, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShadingRateKHR>(const VkPhysicalDeviceFragmentShadingRateKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentSize", toStringFlags, tabCount, tabSize, ToString(obj.fragmentSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceProtectedCapabilitiesKHR>(const VkSurfaceProtectedCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportsProtected", toStringFlags, tabCount, tabSize, ToString(obj.supportsProtected, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePresentWaitFeaturesKHR>(const VkPhysicalDevicePresentWaitFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentWait", toStringFlags, tabCount, tabSize, ToString(obj.presentWait, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>(const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineExecutableInfo", toStringFlags, tabCount, tabSize, ToString(obj.pipelineExecutableInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineInfoKHR>(const VkPipelineInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pipeline)));
        }
    );
}

template <> std::string ToString<VkPipelineExecutablePropertiesKHR>(const VkPipelineExecutablePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stages", toStringFlags, tabCount, tabSize, ToString(obj.stages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, CStrToString(obj.name));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "subgroupSize", toStringFlags, tabCount, tabSize, ToString(obj.subgroupSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineExecutableInfoKHR>(const VkPipelineExecutableInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pipeline)));
            FieldToString(strStrm, false, "executableIndex", toStringFlags, tabCount, tabSize, ToString(obj.executableIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineExecutableInternalRepresentationKHR>(const VkPipelineExecutableInternalRepresentationKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "name", toStringFlags, tabCount, tabSize, CStrToString(obj.name));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "isText", toStringFlags, tabCount, tabSize, ToString(obj.isText, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(obj.dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pData)));
        }
    );
}

template <> std::string ToString<VkPipelineLibraryCreateInfoKHR>(const VkPipelineLibraryCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "libraryCount", toStringFlags, tabCount, tabSize, ToString(obj.libraryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLibraries", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.libraryCount, obj.pLibraries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentIdKHR>(const VkPresentIdKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentIds", toStringFlags, tabCount, tabSize, ArrayToString(obj.swapchainCount, obj.pPresentIds, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePresentIdFeaturesKHR>(const VkPhysicalDevicePresentIdFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentId", toStringFlags, tabCount, tabSize, ToString(obj.presentId, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeInfoKHR>(const VkVideoEncodeInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qualityLevel", toStringFlags, tabCount, tabSize, ToString(obj.qualityLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstBitstreamBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstBitstreamBuffer)));
            FieldToString(strStrm, false, "dstBitstreamBufferOffset", toStringFlags, tabCount, tabSize, ToString(obj.dstBitstreamBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstBitstreamBufferMaxRange", toStringFlags, tabCount, tabSize, ToString(obj.dstBitstreamBufferMaxRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcPictureResource", toStringFlags, tabCount, tabSize, ToString(obj.srcPictureResource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSetupReferenceSlot", toStringFlags, tabCount, tabSize, (obj.pSetupReferenceSlot ? ToString(*obj.pSetupReferenceSlot, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "referenceSlotCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceSlotCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceSlots", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceSlotCount, obj.pReferenceSlots, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "precedingExternallyEncodedBytes", toStringFlags, tabCount, tabSize, ToString(obj.precedingExternallyEncodedBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeCapabilitiesKHR>(const VkVideoEncodeCapabilitiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rateControlModes", toStringFlags, tabCount, tabSize, ToString(obj.rateControlModes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rateControlLayerCount", toStringFlags, tabCount, tabSize, ToString(obj.rateControlLayerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qualityLevelCount", toStringFlags, tabCount, tabSize, ToString(obj.qualityLevelCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputImageDataFillAlignment", toStringFlags, tabCount, tabSize, ToString(obj.inputImageDataFillAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeUsageInfoKHR>(const VkVideoEncodeUsageInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoUsageHints", toStringFlags, tabCount, tabSize, ToString(obj.videoUsageHints, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "videoContentHints", toStringFlags, tabCount, tabSize, ToString(obj.videoContentHints, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tuningMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.tuningMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkVideoEncodeRateControlLayerInfoKHR>(const VkVideoEncodeRateControlLayerInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "averageBitrate", toStringFlags, tabCount, tabSize, ToString(obj.averageBitrate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBitrate", toStringFlags, tabCount, tabSize, ToString(obj.maxBitrate, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frameRateNumerator", toStringFlags, tabCount, tabSize, ToString(obj.frameRateNumerator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frameRateDenominator", toStringFlags, tabCount, tabSize, ToString(obj.frameRateDenominator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "virtualBufferSizeInMs", toStringFlags, tabCount, tabSize, ToString(obj.virtualBufferSizeInMs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialVirtualBufferSizeInMs", toStringFlags, tabCount, tabSize, ToString(obj.initialVirtualBufferSizeInMs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeRateControlInfoKHR>(const VkVideoEncodeRateControlInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rateControlMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rateControlMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "layerCount", toStringFlags, tabCount, tabSize, ToString(obj.layerCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLayerConfigs", toStringFlags, tabCount, tabSize, ArrayToString(obj.layerCount, obj.pLayerConfigs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyCheckpointProperties2NV>(const VkQueueFamilyCheckpointProperties2NV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "checkpointExecutionStageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.checkpointExecutionStageMask)));
        }
    );
}

template <> std::string ToString<VkCheckpointData2NV>(const VkCheckpointData2NV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(obj.stage)));
            FieldToString(strStrm, false, "pCheckpointMarker", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pCheckpointMarker)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>(const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShaderBarycentric", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShaderBarycentric, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>(const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "triStripVertexOrderIndependentOfProvokingVertex", toStringFlags, tabCount, tabSize, ToString(obj.triStripVertexOrderIndependentOfProvokingVertex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>(const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSubgroupUniformControlFlow", toStringFlags, tabCount, tabSize, ToString(obj.shaderSubgroupUniformControlFlow, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>(const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "workgroupMemoryExplicitLayout", toStringFlags, tabCount, tabSize, ToString(obj.workgroupMemoryExplicitLayout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "workgroupMemoryExplicitLayoutScalarBlockLayout", toStringFlags, tabCount, tabSize, ToString(obj.workgroupMemoryExplicitLayoutScalarBlockLayout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "workgroupMemoryExplicitLayout8BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.workgroupMemoryExplicitLayout8BitAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "workgroupMemoryExplicitLayout16BitAccess", toStringFlags, tabCount, tabSize, ToString(obj.workgroupMemoryExplicitLayout16BitAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>(const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingMaintenance1", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingMaintenance1, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingPipelineTraceRaysIndirect2", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingPipelineTraceRaysIndirect2, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkTraceRaysIndirectCommand2KHR>(const VkTraceRaysIndirectCommand2KHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "raygenShaderRecordAddress", toStringFlags, tabCount, tabSize, ToString(obj.raygenShaderRecordAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "raygenShaderRecordSize", toStringFlags, tabCount, tabSize, ToString(obj.raygenShaderRecordSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "missShaderBindingTableAddress", toStringFlags, tabCount, tabSize, ToString(obj.missShaderBindingTableAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "missShaderBindingTableSize", toStringFlags, tabCount, tabSize, ToString(obj.missShaderBindingTableSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "missShaderBindingTableStride", toStringFlags, tabCount, tabSize, ToString(obj.missShaderBindingTableStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hitShaderBindingTableAddress", toStringFlags, tabCount, tabSize, ToString(obj.hitShaderBindingTableAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hitShaderBindingTableSize", toStringFlags, tabCount, tabSize, ToString(obj.hitShaderBindingTableSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hitShaderBindingTableStride", toStringFlags, tabCount, tabSize, ToString(obj.hitShaderBindingTableStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "callableShaderBindingTableAddress", toStringFlags, tabCount, tabSize, ToString(obj.callableShaderBindingTableAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "callableShaderBindingTableSize", toStringFlags, tabCount, tabSize, ToString(obj.callableShaderBindingTableSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "callableShaderBindingTableStride", toStringFlags, tabCount, tabSize, ToString(obj.callableShaderBindingTableStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depth", toStringFlags, tabCount, tabSize, ToString(obj.depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDebugReportCallbackCreateInfoEXT>(const VkDebugReportCallbackCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pfnCallback", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnCallback)));
            FieldToString(strStrm, false, "pUserData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pUserData)));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationStateRasterizationOrderAMD>(const VkPipelineRasterizationStateRasterizationOrderAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationOrder", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rasterizationOrder, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkDebugMarkerObjectNameInfoEXT>(const VkDebugMarkerObjectNameInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "object", toStringFlags, tabCount, tabSize, decode::HandleIdToString(obj.object));
            FieldToString(strStrm, false, "pObjectName", toStringFlags, tabCount, tabSize, CStrToString(obj.pObjectName));
        }
    );
}

template <> std::string ToString<VkDebugMarkerObjectTagInfoEXT>(const VkDebugMarkerObjectTagInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "object", toStringFlags, tabCount, tabSize, decode::HandleIdToString(obj.object));
            FieldToString(strStrm, false, "tagName", toStringFlags, tabCount, tabSize, ToString(obj.tagName, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tagSize", toStringFlags, tabCount, tabSize, ToString(obj.tagSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTag", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pTag)));
        }
    );
}

template <> std::string ToString<VkDebugMarkerMarkerInfoEXT>(const VkDebugMarkerMarkerInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMarkerName", toStringFlags, tabCount, tabSize, CStrToString(obj.pMarkerName));
            FieldToString(strStrm, false, "color", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.color, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDedicatedAllocationImageCreateInfoNV>(const VkDedicatedAllocationImageCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dedicatedAllocation", toStringFlags, tabCount, tabSize, ToString(obj.dedicatedAllocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDedicatedAllocationBufferCreateInfoNV>(const VkDedicatedAllocationBufferCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dedicatedAllocation", toStringFlags, tabCount, tabSize, ToString(obj.dedicatedAllocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDedicatedAllocationMemoryAllocateInfoNV>(const VkDedicatedAllocationMemoryAllocateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.image)));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTransformFeedbackFeaturesEXT>(const VkPhysicalDeviceTransformFeedbackFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedback", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedback, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryStreams", toStringFlags, tabCount, tabSize, ToString(obj.geometryStreams, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTransformFeedbackPropertiesEXT>(const VkPhysicalDeviceTransformFeedbackPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackStreams", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackStreams, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackBuffers", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackBufferSize", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackBufferSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackStreamDataSize", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackStreamDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackBufferDataSize", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackBufferDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTransformFeedbackBufferDataStride", toStringFlags, tabCount, tabSize, ToString(obj.maxTransformFeedbackBufferDataStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackQueries", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackQueries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackStreamsLinesTriangles", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackStreamsLinesTriangles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackRasterizationStreamSelect", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackRasterizationStreamSelect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackDraw", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackDraw, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationStateStreamCreateInfoEXT>(const VkPipelineRasterizationStateStreamCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationStream", toStringFlags, tabCount, tabSize, ToString(obj.rasterizationStream, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageViewHandleInfoNVX>(const VkImageViewHandleInfoNVX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.imageView)));
            FieldToString(strStrm, false, "descriptorType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.descriptorType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "sampler", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.sampler)));
        }
    );
}

template <> std::string ToString<VkImageViewAddressPropertiesNVX>(const VkImageViewAddressPropertiesNVX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.deviceAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264CapabilitiesEXT>(const VkVideoEncodeH264CapabilitiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputModeFlags", toStringFlags, tabCount, tabSize, ToString(obj.inputModeFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "outputModeFlags", toStringFlags, tabCount, tabSize, ToString(obj.outputModeFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPPictureL0ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxPPictureL0ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBPictureL0ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxBPictureL0ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxL1ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxL1ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "motionVectorsOverPicBoundariesFlag", toStringFlags, tabCount, tabSize, ToString(obj.motionVectorsOverPicBoundariesFlag, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBytesPerPicDenom", toStringFlags, tabCount, tabSize, ToString(obj.maxBytesPerPicDenom, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBitsPerMbDenom", toStringFlags, tabCount, tabSize, ToString(obj.maxBitsPerMbDenom, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "log2MaxMvLengthHorizontal", toStringFlags, tabCount, tabSize, ToString(obj.log2MaxMvLengthHorizontal, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "log2MaxMvLengthVertical", toStringFlags, tabCount, tabSize, ToString(obj.log2MaxMvLengthVertical, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264SessionParametersAddInfoEXT>(const VkVideoEncodeH264SessionParametersAddInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdSPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdSPSCount, obj.pStdSPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdPPSCount, obj.pStdPPSs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264SessionParametersCreateInfoEXT>(const VkVideoEncodeH264SessionParametersCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParametersAddInfo", toStringFlags, tabCount, tabSize, (obj.pParametersAddInfo ? ToString(*obj.pParametersAddInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264DpbSlotInfoEXT>(const VkVideoEncodeH264DpbSlotInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "slotIndex", toStringFlags, tabCount, tabSize, ToString(obj.slotIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdReferenceInfo", toStringFlags, tabCount, tabSize, (obj.pStdReferenceInfo ? ToString(*obj.pStdReferenceInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264ReferenceListsInfoEXT>(const VkVideoEncodeH264ReferenceListsInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "referenceList0EntryCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceList0EntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceList0Entries", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceList0EntryCount, obj.pReferenceList0Entries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "referenceList1EntryCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceList1EntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceList1Entries", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceList1EntryCount, obj.pReferenceList1Entries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemMgmtCtrlOperations", toStringFlags, tabCount, tabSize, (obj.pMemMgmtCtrlOperations ? ToString(*obj.pMemMgmtCtrlOperations, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264NaluSliceInfoEXT>(const VkVideoEncodeH264NaluSliceInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mbCount", toStringFlags, tabCount, tabSize, ToString(obj.mbCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceFinalLists", toStringFlags, tabCount, tabSize, (obj.pReferenceFinalLists ? ToString(*obj.pReferenceFinalLists, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pSliceHeaderStd", toStringFlags, tabCount, tabSize, (obj.pSliceHeaderStd ? ToString(*obj.pSliceHeaderStd, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264VclFrameInfoEXT>(const VkVideoEncodeH264VclFrameInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceFinalLists", toStringFlags, tabCount, tabSize, (obj.pReferenceFinalLists ? ToString(*obj.pReferenceFinalLists, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "naluSliceEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.naluSliceEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pNaluSliceEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.naluSliceEntryCount, obj.pNaluSliceEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCurrentPictureInfo", toStringFlags, tabCount, tabSize, (obj.pCurrentPictureInfo ? ToString(*obj.pCurrentPictureInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264EmitPictureParametersInfoEXT>(const VkVideoEncodeH264EmitPictureParametersInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "spsId", toStringFlags, tabCount, tabSize, ToString(obj.spsId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "emitSpsEnable", toStringFlags, tabCount, tabSize, ToString(obj.emitSpsEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppsIdEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.ppsIdEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppsIdEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.ppsIdEntryCount, obj.ppsIdEntries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264ProfileInfoEXT>(const VkVideoEncodeH264ProfileInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdProfileIdc", toStringFlags, tabCount, tabSize, ToString(obj.stdProfileIdc, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264RateControlInfoEXT>(const VkVideoEncodeH264RateControlInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "gopFrameCount", toStringFlags, tabCount, tabSize, ToString(obj.gopFrameCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "idrPeriod", toStringFlags, tabCount, tabSize, ToString(obj.idrPeriod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "consecutiveBFrameCount", toStringFlags, tabCount, tabSize, ToString(obj.consecutiveBFrameCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rateControlStructure", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rateControlStructure, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "temporalLayerCount", toStringFlags, tabCount, tabSize, ToString(obj.temporalLayerCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264QpEXT>(const VkVideoEncodeH264QpEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "qpI", toStringFlags, tabCount, tabSize, ToString(obj.qpI, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qpP", toStringFlags, tabCount, tabSize, ToString(obj.qpP, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qpB", toStringFlags, tabCount, tabSize, ToString(obj.qpB, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264FrameSizeEXT>(const VkVideoEncodeH264FrameSizeEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "frameISize", toStringFlags, tabCount, tabSize, ToString(obj.frameISize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framePSize", toStringFlags, tabCount, tabSize, ToString(obj.framePSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frameBSize", toStringFlags, tabCount, tabSize, ToString(obj.frameBSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH264RateControlLayerInfoEXT>(const VkVideoEncodeH264RateControlLayerInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "temporalLayerId", toStringFlags, tabCount, tabSize, ToString(obj.temporalLayerId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useInitialRcQp", toStringFlags, tabCount, tabSize, ToString(obj.useInitialRcQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialRcQp", toStringFlags, tabCount, tabSize, ToString(obj.initialRcQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMinQp", toStringFlags, tabCount, tabSize, ToString(obj.useMinQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minQp", toStringFlags, tabCount, tabSize, ToString(obj.minQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMaxQp", toStringFlags, tabCount, tabSize, ToString(obj.useMaxQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxQp", toStringFlags, tabCount, tabSize, ToString(obj.maxQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMaxFrameSize", toStringFlags, tabCount, tabSize, ToString(obj.useMaxFrameSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFrameSize", toStringFlags, tabCount, tabSize, ToString(obj.maxFrameSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265CapabilitiesEXT>(const VkVideoEncodeH265CapabilitiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputModeFlags", toStringFlags, tabCount, tabSize, ToString(obj.inputModeFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "outputModeFlags", toStringFlags, tabCount, tabSize, ToString(obj.outputModeFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ctbSizes", toStringFlags, tabCount, tabSize, ToString(obj.ctbSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformBlockSizes", toStringFlags, tabCount, tabSize, ToString(obj.transformBlockSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPPictureL0ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxPPictureL0ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBPictureL0ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxBPictureL0ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxL1ReferenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxL1ReferenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSubLayersCount", toStringFlags, tabCount, tabSize, ToString(obj.maxSubLayersCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minLog2MinLumaCodingBlockSizeMinus3", toStringFlags, tabCount, tabSize, ToString(obj.minLog2MinLumaCodingBlockSizeMinus3, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLog2MinLumaCodingBlockSizeMinus3", toStringFlags, tabCount, tabSize, ToString(obj.maxLog2MinLumaCodingBlockSizeMinus3, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minLog2MinLumaTransformBlockSizeMinus2", toStringFlags, tabCount, tabSize, ToString(obj.minLog2MinLumaTransformBlockSizeMinus2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLog2MinLumaTransformBlockSizeMinus2", toStringFlags, tabCount, tabSize, ToString(obj.maxLog2MinLumaTransformBlockSizeMinus2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minMaxTransformHierarchyDepthInter", toStringFlags, tabCount, tabSize, ToString(obj.minMaxTransformHierarchyDepthInter, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMaxTransformHierarchyDepthInter", toStringFlags, tabCount, tabSize, ToString(obj.maxMaxTransformHierarchyDepthInter, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minMaxTransformHierarchyDepthIntra", toStringFlags, tabCount, tabSize, ToString(obj.minMaxTransformHierarchyDepthIntra, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMaxTransformHierarchyDepthIntra", toStringFlags, tabCount, tabSize, ToString(obj.maxMaxTransformHierarchyDepthIntra, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDiffCuQpDeltaDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxDiffCuQpDeltaDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minMaxNumMergeCand", toStringFlags, tabCount, tabSize, ToString(obj.minMaxNumMergeCand, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMaxNumMergeCand", toStringFlags, tabCount, tabSize, ToString(obj.maxMaxNumMergeCand, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265SessionParametersAddInfoEXT>(const VkVideoEncodeH265SessionParametersAddInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdVPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdVPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdVPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdVPSCount, obj.pStdVPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdSPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdSPSCount, obj.pStdSPSs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.stdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdPPSs", toStringFlags, tabCount, tabSize, ArrayToString(obj.stdPPSCount, obj.pStdPPSs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265SessionParametersCreateInfoEXT>(const VkVideoEncodeH265SessionParametersCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdVPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdVPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdSPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdSPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxStdPPSCount", toStringFlags, tabCount, tabSize, ToString(obj.maxStdPPSCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pParametersAddInfo", toStringFlags, tabCount, tabSize, (obj.pParametersAddInfo ? ToString(*obj.pParametersAddInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265DpbSlotInfoEXT>(const VkVideoEncodeH265DpbSlotInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "slotIndex", toStringFlags, tabCount, tabSize, ToString(obj.slotIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStdReferenceInfo", toStringFlags, tabCount, tabSize, (obj.pStdReferenceInfo ? ToString(*obj.pStdReferenceInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265ReferenceListsInfoEXT>(const VkVideoEncodeH265ReferenceListsInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "referenceList0EntryCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceList0EntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceList0Entries", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceList0EntryCount, obj.pReferenceList0Entries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "referenceList1EntryCount", toStringFlags, tabCount, tabSize, ToString(obj.referenceList1EntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceList1Entries", toStringFlags, tabCount, tabSize, ArrayToString(obj.referenceList1EntryCount, obj.pReferenceList1Entries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceModifications", toStringFlags, tabCount, tabSize, (obj.pReferenceModifications ? ToString(*obj.pReferenceModifications, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265NaluSliceSegmentInfoEXT>(const VkVideoEncodeH265NaluSliceSegmentInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ctbCount", toStringFlags, tabCount, tabSize, ToString(obj.ctbCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceFinalLists", toStringFlags, tabCount, tabSize, (obj.pReferenceFinalLists ? ToString(*obj.pReferenceFinalLists, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pSliceSegmentHeaderStd", toStringFlags, tabCount, tabSize, (obj.pSliceSegmentHeaderStd ? ToString(*obj.pSliceSegmentHeaderStd, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265VclFrameInfoEXT>(const VkVideoEncodeH265VclFrameInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReferenceFinalLists", toStringFlags, tabCount, tabSize, (obj.pReferenceFinalLists ? ToString(*obj.pReferenceFinalLists, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "naluSliceSegmentEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.naluSliceSegmentEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pNaluSliceSegmentEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.naluSliceSegmentEntryCount, obj.pNaluSliceSegmentEntries, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCurrentPictureInfo", toStringFlags, tabCount, tabSize, (obj.pCurrentPictureInfo ? ToString(*obj.pCurrentPictureInfo, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265EmitPictureParametersInfoEXT>(const VkVideoEncodeH265EmitPictureParametersInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vpsId", toStringFlags, tabCount, tabSize, ToString(obj.vpsId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "spsId", toStringFlags, tabCount, tabSize, ToString(obj.spsId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "emitVpsEnable", toStringFlags, tabCount, tabSize, ToString(obj.emitVpsEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "emitSpsEnable", toStringFlags, tabCount, tabSize, ToString(obj.emitSpsEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppsIdEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.ppsIdEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppsIdEntries", toStringFlags, tabCount, tabSize, ArrayToString(obj.ppsIdEntryCount, obj.ppsIdEntries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265ProfileInfoEXT>(const VkVideoEncodeH265ProfileInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stdProfileIdc", toStringFlags, tabCount, tabSize, ToString(obj.stdProfileIdc, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265RateControlInfoEXT>(const VkVideoEncodeH265RateControlInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "gopFrameCount", toStringFlags, tabCount, tabSize, ToString(obj.gopFrameCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "idrPeriod", toStringFlags, tabCount, tabSize, ToString(obj.idrPeriod, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "consecutiveBFrameCount", toStringFlags, tabCount, tabSize, ToString(obj.consecutiveBFrameCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rateControlStructure", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rateControlStructure, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "subLayerCount", toStringFlags, tabCount, tabSize, ToString(obj.subLayerCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265QpEXT>(const VkVideoEncodeH265QpEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "qpI", toStringFlags, tabCount, tabSize, ToString(obj.qpI, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qpP", toStringFlags, tabCount, tabSize, ToString(obj.qpP, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qpB", toStringFlags, tabCount, tabSize, ToString(obj.qpB, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265FrameSizeEXT>(const VkVideoEncodeH265FrameSizeEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "frameISize", toStringFlags, tabCount, tabSize, ToString(obj.frameISize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "framePSize", toStringFlags, tabCount, tabSize, ToString(obj.framePSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frameBSize", toStringFlags, tabCount, tabSize, ToString(obj.frameBSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVideoEncodeH265RateControlLayerInfoEXT>(const VkVideoEncodeH265RateControlLayerInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "temporalId", toStringFlags, tabCount, tabSize, ToString(obj.temporalId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useInitialRcQp", toStringFlags, tabCount, tabSize, ToString(obj.useInitialRcQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialRcQp", toStringFlags, tabCount, tabSize, ToString(obj.initialRcQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMinQp", toStringFlags, tabCount, tabSize, ToString(obj.useMinQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minQp", toStringFlags, tabCount, tabSize, ToString(obj.minQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMaxQp", toStringFlags, tabCount, tabSize, ToString(obj.useMaxQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxQp", toStringFlags, tabCount, tabSize, ToString(obj.maxQp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "useMaxFrameSize", toStringFlags, tabCount, tabSize, ToString(obj.useMaxFrameSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFrameSize", toStringFlags, tabCount, tabSize, ToString(obj.maxFrameSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkTextureLODGatherFormatPropertiesAMD>(const VkTextureLODGatherFormatPropertiesAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportsTextureGatherLODBiasAMD", toStringFlags, tabCount, tabSize, ToString(obj.supportsTextureGatherLODBiasAMD, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkShaderResourceUsageAMD>(const VkShaderResourceUsageAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "numUsedVgprs", toStringFlags, tabCount, tabSize, ToString(obj.numUsedVgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numUsedSgprs", toStringFlags, tabCount, tabSize, ToString(obj.numUsedSgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ldsSizePerLocalWorkGroup", toStringFlags, tabCount, tabSize, ToString(obj.ldsSizePerLocalWorkGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ldsUsageSizeInBytes", toStringFlags, tabCount, tabSize, ToString(obj.ldsUsageSizeInBytes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scratchMemUsageInBytes", toStringFlags, tabCount, tabSize, ToString(obj.scratchMemUsageInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkShaderStatisticsInfoAMD>(const VkShaderStatisticsInfoAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "shaderStageMask", toStringFlags, tabCount, tabSize, ToString(obj.shaderStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "resourceUsage", toStringFlags, tabCount, tabSize, ToString(obj.resourceUsage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numPhysicalVgprs", toStringFlags, tabCount, tabSize, ToString(obj.numPhysicalVgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numPhysicalSgprs", toStringFlags, tabCount, tabSize, ToString(obj.numPhysicalSgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numAvailableVgprs", toStringFlags, tabCount, tabSize, ToString(obj.numAvailableVgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numAvailableSgprs", toStringFlags, tabCount, tabSize, ToString(obj.numAvailableSgprs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.computeWorkGroupSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkStreamDescriptorSurfaceCreateInfoGGP>(const VkStreamDescriptorSurfaceCreateInfoGGP& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "streamDescriptor", toStringFlags, tabCount, tabSize, ToString(obj.streamDescriptor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCornerSampledImageFeaturesNV>(const VkPhysicalDeviceCornerSampledImageFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cornerSampledImage", toStringFlags, tabCount, tabSize, ToString(obj.cornerSampledImage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExternalImageFormatPropertiesNV>(const VkExternalImageFormatPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "imageFormatProperties", toStringFlags, tabCount, tabSize, ToString(obj.imageFormatProperties, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalMemoryFeatures", toStringFlags, tabCount, tabSize, ToString(obj.externalMemoryFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exportFromImportedHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.exportFromImportedHandleTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compatibleHandleTypes", toStringFlags, tabCount, tabSize, ToString(obj.compatibleHandleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExternalMemoryImageCreateInfoNV>(const VkExternalMemoryImageCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkExportMemoryAllocateInfoNV>(const VkExportMemoryAllocateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleTypes", toStringFlags, tabCount, tabSize, ToString(obj.handleTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportMemoryWin32HandleInfoNV>(const VkImportMemoryWin32HandleInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, ToString(obj.handleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.handle)));
        }
    );
}

template <> std::string ToString<VkExportMemoryWin32HandleInfoNV>(const VkExportMemoryWin32HandleInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, (obj.pAttributes ? ToString(*obj.pAttributes, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "dwAccess", toStringFlags, tabCount, tabSize, ToString(obj.dwAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkWin32KeyedMutexAcquireReleaseInfoNV>(const VkWin32KeyedMutexAcquireReleaseInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "acquireCount", toStringFlags, tabCount, tabSize, ToString(obj.acquireCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireSyncs", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.acquireCount, obj.pAcquireSyncs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireKeys", toStringFlags, tabCount, tabSize, ArrayToString(obj.acquireCount, obj.pAcquireKeys, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAcquireTimeoutMilliseconds", toStringFlags, tabCount, tabSize, ArrayToString(obj.acquireCount, obj.pAcquireTimeoutMilliseconds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "releaseCount", toStringFlags, tabCount, tabSize, ToString(obj.releaseCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReleaseSyncs", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.releaseCount, obj.pReleaseSyncs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pReleaseKeys", toStringFlags, tabCount, tabSize, ArrayToString(obj.releaseCount, obj.pReleaseKeys, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkValidationFlagsEXT>(const VkValidationFlagsEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "disabledValidationCheckCount", toStringFlags, tabCount, tabSize, ToString(obj.disabledValidationCheckCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisabledValidationChecks", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.disabledValidationCheckCount, obj.pDisabledValidationChecks, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkViSurfaceCreateInfoNN>(const VkViSurfaceCreateInfoNN& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.window)));
        }
    );
}

template <> std::string ToString<VkImageViewASTCDecodeModeEXT>(const VkImageViewASTCDecodeModeEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "decodeMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.decodeMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceASTCDecodeFeaturesEXT>(const VkPhysicalDeviceASTCDecodeFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "decodeModeSharedExponent", toStringFlags, tabCount, tabSize, ToString(obj.decodeModeSharedExponent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePipelineRobustnessFeaturesEXT>(const VkPhysicalDevicePipelineRobustnessFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineRobustness", toStringFlags, tabCount, tabSize, ToString(obj.pipelineRobustness, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePipelineRobustnessPropertiesEXT>(const VkPhysicalDevicePipelineRobustnessPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "defaultRobustnessStorageBuffers", toStringFlags, tabCount, tabSize, Quote(ToString(obj.defaultRobustnessStorageBuffers, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "defaultRobustnessUniformBuffers", toStringFlags, tabCount, tabSize, Quote(ToString(obj.defaultRobustnessUniformBuffers, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "defaultRobustnessVertexInputs", toStringFlags, tabCount, tabSize, Quote(ToString(obj.defaultRobustnessVertexInputs, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "defaultRobustnessImages", toStringFlags, tabCount, tabSize, Quote(ToString(obj.defaultRobustnessImages, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPipelineRobustnessCreateInfoEXT>(const VkPipelineRobustnessCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "storageBuffers", toStringFlags, tabCount, tabSize, Quote(ToString(obj.storageBuffers, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "uniformBuffers", toStringFlags, tabCount, tabSize, Quote(ToString(obj.uniformBuffers, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "vertexInputs", toStringFlags, tabCount, tabSize, Quote(ToString(obj.vertexInputs, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "images", toStringFlags, tabCount, tabSize, Quote(ToString(obj.images, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkConditionalRenderingBeginInfoEXT>(const VkConditionalRenderingBeginInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceConditionalRenderingFeaturesEXT>(const VkPhysicalDeviceConditionalRenderingFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conditionalRendering", toStringFlags, tabCount, tabSize, ToString(obj.conditionalRendering, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inheritedConditionalRendering", toStringFlags, tabCount, tabSize, ToString(obj.inheritedConditionalRendering, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferInheritanceConditionalRenderingInfoEXT>(const VkCommandBufferInheritanceConditionalRenderingInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conditionalRenderingEnable", toStringFlags, tabCount, tabSize, ToString(obj.conditionalRenderingEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkViewportWScalingNV>(const VkViewportWScalingNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "xcoeff", toStringFlags, tabCount, tabSize, ToString(obj.xcoeff, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ycoeff", toStringFlags, tabCount, tabSize, ToString(obj.ycoeff, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportWScalingStateCreateInfoNV>(const VkPipelineViewportWScalingStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportWScalingEnable", toStringFlags, tabCount, tabSize, ToString(obj.viewportWScalingEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(obj.viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportWScalings", toStringFlags, tabCount, tabSize, ArrayToString(obj.viewportCount, obj.pViewportWScalings, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceCapabilities2EXT>(const VkSurfaceCapabilities2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minImageCount", toStringFlags, tabCount, tabSize, ToString(obj.minImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageCount", toStringFlags, tabCount, tabSize, ToString(obj.maxImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "currentExtent", toStringFlags, tabCount, tabSize, ToString(obj.currentExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.minImageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxImageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxImageArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxImageArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedTransforms", toStringFlags, tabCount, tabSize, ToString(obj.supportedTransforms, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "currentTransform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.currentTransform, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "supportedCompositeAlpha", toStringFlags, tabCount, tabSize, ToString(obj.supportedCompositeAlpha, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedUsageFlags", toStringFlags, tabCount, tabSize, ToString(obj.supportedUsageFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedSurfaceCounters", toStringFlags, tabCount, tabSize, ToString(obj.supportedSurfaceCounters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayPowerInfoEXT>(const VkDisplayPowerInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "powerState", toStringFlags, tabCount, tabSize, Quote(ToString(obj.powerState, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkDeviceEventInfoEXT>(const VkDeviceEventInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceEvent", toStringFlags, tabCount, tabSize, Quote(ToString(obj.deviceEvent, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkDisplayEventInfoEXT>(const VkDisplayEventInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayEvent", toStringFlags, tabCount, tabSize, Quote(ToString(obj.displayEvent, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSwapchainCounterCreateInfoEXT>(const VkSwapchainCounterCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surfaceCounters", toStringFlags, tabCount, tabSize, ToString(obj.surfaceCounters, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRefreshCycleDurationGOOGLE>(const VkRefreshCycleDurationGOOGLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "refreshDuration", toStringFlags, tabCount, tabSize, ToString(obj.refreshDuration, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPastPresentationTimingGOOGLE>(const VkPastPresentationTimingGOOGLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "presentID", toStringFlags, tabCount, tabSize, ToString(obj.presentID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "desiredPresentTime", toStringFlags, tabCount, tabSize, ToString(obj.desiredPresentTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "actualPresentTime", toStringFlags, tabCount, tabSize, ToString(obj.actualPresentTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "earliestPresentTime", toStringFlags, tabCount, tabSize, ToString(obj.earliestPresentTime, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentMargin", toStringFlags, tabCount, tabSize, ToString(obj.presentMargin, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentTimeGOOGLE>(const VkPresentTimeGOOGLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "presentID", toStringFlags, tabCount, tabSize, ToString(obj.presentID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "desiredPresentTime", toStringFlags, tabCount, tabSize, ToString(obj.desiredPresentTime, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentTimesInfoGOOGLE>(const VkPresentTimesInfoGOOGLE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimes", toStringFlags, tabCount, tabSize, ArrayToString(obj.swapchainCount, obj.pTimes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "perViewPositionAllComponents", toStringFlags, tabCount, tabSize, ToString(obj.perViewPositionAllComponents, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkViewportSwizzleNV>(const VkViewportSwizzleNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, Quote(ToString(obj.x, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, Quote(ToString(obj.y, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "z", toStringFlags, tabCount, tabSize, Quote(ToString(obj.z, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "w", toStringFlags, tabCount, tabSize, Quote(ToString(obj.w, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPipelineViewportSwizzleStateCreateInfoNV>(const VkPipelineViewportSwizzleStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(obj.viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportSwizzles", toStringFlags, tabCount, tabSize, ArrayToString(obj.viewportCount, obj.pViewportSwizzles, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDiscardRectanglePropertiesEXT>(const VkPhysicalDeviceDiscardRectanglePropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDiscardRectangles", toStringFlags, tabCount, tabSize, ToString(obj.maxDiscardRectangles, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineDiscardRectangleStateCreateInfoEXT>(const VkPipelineDiscardRectangleStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "discardRectangleMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.discardRectangleMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "discardRectangleCount", toStringFlags, tabCount, tabSize, ToString(obj.discardRectangleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDiscardRectangles", toStringFlags, tabCount, tabSize, ArrayToString(obj.discardRectangleCount, obj.pDiscardRectangles, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceConservativeRasterizationPropertiesEXT>(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveOverestimationSize", toStringFlags, tabCount, tabSize, ToString(obj.primitiveOverestimationSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxExtraPrimitiveOverestimationSize", toStringFlags, tabCount, tabSize, ToString(obj.maxExtraPrimitiveOverestimationSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extraPrimitiveOverestimationSizeGranularity", toStringFlags, tabCount, tabSize, ToString(obj.extraPrimitiveOverestimationSizeGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveUnderestimation", toStringFlags, tabCount, tabSize, ToString(obj.primitiveUnderestimation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conservativePointAndLineRasterization", toStringFlags, tabCount, tabSize, ToString(obj.conservativePointAndLineRasterization, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "degenerateTrianglesRasterized", toStringFlags, tabCount, tabSize, ToString(obj.degenerateTrianglesRasterized, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "degenerateLinesRasterized", toStringFlags, tabCount, tabSize, ToString(obj.degenerateLinesRasterized, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fullyCoveredFragmentShaderInputVariable", toStringFlags, tabCount, tabSize, ToString(obj.fullyCoveredFragmentShaderInputVariable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conservativeRasterizationPostDepthCoverage", toStringFlags, tabCount, tabSize, ToString(obj.conservativeRasterizationPostDepthCoverage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationConservativeStateCreateInfoEXT>(const VkPipelineRasterizationConservativeStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "conservativeRasterizationMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.conservativeRasterizationMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "extraPrimitiveOverestimationSize", toStringFlags, tabCount, tabSize, ToString(obj.extraPrimitiveOverestimationSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDepthClipEnableFeaturesEXT>(const VkPhysicalDeviceDepthClipEnableFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthClipEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationDepthClipStateCreateInfoEXT>(const VkPipelineRasterizationDepthClipStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.depthClipEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkXYColorEXT>(const VkXYColorEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkHdrMetadataEXT>(const VkHdrMetadataEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayPrimaryRed", toStringFlags, tabCount, tabSize, ToString(obj.displayPrimaryRed, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayPrimaryGreen", toStringFlags, tabCount, tabSize, ToString(obj.displayPrimaryGreen, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "displayPrimaryBlue", toStringFlags, tabCount, tabSize, ToString(obj.displayPrimaryBlue, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "whitePoint", toStringFlags, tabCount, tabSize, ToString(obj.whitePoint, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxLuminance", toStringFlags, tabCount, tabSize, ToString(obj.maxLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minLuminance", toStringFlags, tabCount, tabSize, ToString(obj.minLuminance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxContentLightLevel", toStringFlags, tabCount, tabSize, ToString(obj.maxContentLightLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFrameAverageLightLevel", toStringFlags, tabCount, tabSize, ToString(obj.maxFrameAverageLightLevel, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkIOSSurfaceCreateInfoMVK>(const VkIOSSurfaceCreateInfoMVK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pView", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pView)));
        }
    );
}

template <> std::string ToString<VkMacOSSurfaceCreateInfoMVK>(const VkMacOSSurfaceCreateInfoMVK& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pView", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pView)));
        }
    );
}

template <> std::string ToString<VkDebugUtilsLabelEXT>(const VkDebugUtilsLabelEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLabelName", toStringFlags, tabCount, tabSize, CStrToString(obj.pLabelName));
            FieldToString(strStrm, false, "color", toStringFlags, tabCount, tabSize, ArrayToString(4, obj.color, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDebugUtilsObjectNameInfoEXT>(const VkDebugUtilsObjectNameInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, decode::HandleIdToString(obj.objectHandle));
            FieldToString(strStrm, false, "pObjectName", toStringFlags, tabCount, tabSize, CStrToString(obj.pObjectName));
        }
    );
}

template <> std::string ToString<VkDebugUtilsMessengerCallbackDataEXT>(const VkDebugUtilsMessengerCallbackDataEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMessageIdName", toStringFlags, tabCount, tabSize, CStrToString(obj.pMessageIdName));
            FieldToString(strStrm, false, "messageIdNumber", toStringFlags, tabCount, tabSize, ToString(obj.messageIdNumber, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMessage", toStringFlags, tabCount, tabSize, CStrToString(obj.pMessage));
            FieldToString(strStrm, false, "queueLabelCount", toStringFlags, tabCount, tabSize, ToString(obj.queueLabelCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueLabels", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueLabelCount, obj.pQueueLabels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cmdBufLabelCount", toStringFlags, tabCount, tabSize, ToString(obj.cmdBufLabelCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCmdBufLabels", toStringFlags, tabCount, tabSize, ArrayToString(obj.cmdBufLabelCount, obj.pCmdBufLabels, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectCount", toStringFlags, tabCount, tabSize, ToString(obj.objectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pObjects", toStringFlags, tabCount, tabSize, ArrayToString(obj.objectCount, obj.pObjects, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDebugUtilsMessengerCreateInfoEXT>(const VkDebugUtilsMessengerCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "messageSeverity", toStringFlags, tabCount, tabSize, ToString(obj.messageSeverity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "messageType", toStringFlags, tabCount, tabSize, ToString(obj.messageType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pfnUserCallback", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnUserCallback)));
            FieldToString(strStrm, false, "pUserData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pUserData)));
        }
    );
}

template <> std::string ToString<VkDebugUtilsObjectTagInfoEXT>(const VkDebugUtilsObjectTagInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, decode::HandleIdToString(obj.objectHandle));
            FieldToString(strStrm, false, "tagName", toStringFlags, tabCount, tabSize, ToString(obj.tagName, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tagSize", toStringFlags, tabCount, tabSize, ToString(obj.tagSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTag", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pTag)));
        }
    );
}

template <> std::string ToString<VkAndroidHardwareBufferUsageANDROID>(const VkAndroidHardwareBufferUsageANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "androidHardwareBufferUsage", toStringFlags, tabCount, tabSize, ToString(obj.androidHardwareBufferUsage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAndroidHardwareBufferPropertiesANDROID>(const VkAndroidHardwareBufferPropertiesANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "allocationSize", toStringFlags, tabCount, tabSize, ToString(obj.allocationSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAndroidHardwareBufferFormatPropertiesANDROID>(const VkAndroidHardwareBufferFormatPropertiesANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "externalFormat", toStringFlags, tabCount, tabSize, ToString(obj.externalFormat, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatFeatures", toStringFlags, tabCount, tabSize, ToString(obj.formatFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "samplerYcbcrConversionComponents", toStringFlags, tabCount, tabSize, ToString(obj.samplerYcbcrConversionComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "suggestedYcbcrModel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYcbcrModel, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedYcbcrRange", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYcbcrRange, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedXChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedXChromaOffset, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedYChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYChromaOffset, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImportAndroidHardwareBufferInfoANDROID>(const VkImportAndroidHardwareBufferInfoANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.buffer)));
        }
    );
}

template <> std::string ToString<VkMemoryGetAndroidHardwareBufferInfoANDROID>(const VkMemoryGetAndroidHardwareBufferInfoANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
        }
    );
}

template <> std::string ToString<VkExternalFormatANDROID>(const VkExternalFormatANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalFormat", toStringFlags, tabCount, tabSize, ToString(obj.externalFormat, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAndroidHardwareBufferFormatProperties2ANDROID>(const VkAndroidHardwareBufferFormatProperties2ANDROID& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "externalFormat", toStringFlags, tabCount, tabSize, ToString(obj.externalFormat, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatFeatures", toStringFlags, tabCount, tabSize, Quote(VkFormatFeatureFlags2ToString(obj.formatFeatures)));
            FieldToString(strStrm, false, "samplerYcbcrConversionComponents", toStringFlags, tabCount, tabSize, ToString(obj.samplerYcbcrConversionComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "suggestedYcbcrModel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYcbcrModel, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedYcbcrRange", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYcbcrRange, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedXChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedXChromaOffset, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "suggestedYChromaOffset", toStringFlags, tabCount, tabSize, Quote(ToString(obj.suggestedYChromaOffset, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSampleLocationEXT>(const VkSampleLocationEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "x", toStringFlags, tabCount, tabSize, ToString(obj.x, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "y", toStringFlags, tabCount, tabSize, ToString(obj.y, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSampleLocationsInfoEXT>(const VkSampleLocationsInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsPerPixel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sampleLocationsPerPixel, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "sampleLocationGridSize", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationGridSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsCount", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSampleLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.sampleLocationsCount, obj.pSampleLocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAttachmentSampleLocationsEXT>(const VkAttachmentSampleLocationsEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "attachmentIndex", toStringFlags, tabCount, tabSize, ToString(obj.attachmentIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsInfo", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassSampleLocationsEXT>(const VkSubpassSampleLocationsEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "subpassIndex", toStringFlags, tabCount, tabSize, ToString(obj.subpassIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsInfo", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassSampleLocationsBeginInfoEXT>(const VkRenderPassSampleLocationsBeginInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentInitialSampleLocationsCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentInitialSampleLocationsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachmentInitialSampleLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentInitialSampleLocationsCount, obj.pAttachmentInitialSampleLocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "postSubpassSampleLocationsCount", toStringFlags, tabCount, tabSize, ToString(obj.postSubpassSampleLocationsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPostSubpassSampleLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.postSubpassSampleLocationsCount, obj.pPostSubpassSampleLocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineSampleLocationsStateCreateInfoEXT>(const VkPipelineSampleLocationsStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsEnable", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationsEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationsInfo", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSampleLocationsPropertiesEXT>(const VkPhysicalDeviceSampleLocationsPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationSampleCounts", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationSampleCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSampleLocationGridSize", toStringFlags, tabCount, tabSize, ToString(obj.maxSampleLocationGridSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationCoordinateRange", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.sampleLocationCoordinateRange, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationSubPixelBits", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationSubPixelBits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "variableSampleLocations", toStringFlags, tabCount, tabSize, ToString(obj.variableSampleLocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMultisamplePropertiesEXT>(const VkMultisamplePropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSampleLocationGridSize", toStringFlags, tabCount, tabSize, ToString(obj.maxSampleLocationGridSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendCoherentOperations", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendCoherentOperations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendMaxColorAttachments", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendMaxColorAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendIndependentBlend", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendIndependentBlend, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendNonPremultipliedSrcColor", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendNonPremultipliedSrcColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendNonPremultipliedDstColor", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendNonPremultipliedDstColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendCorrelatedOverlap", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendCorrelatedOverlap, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "advancedBlendAllOperations", toStringFlags, tabCount, tabSize, ToString(obj.advancedBlendAllOperations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineColorBlendAdvancedStateCreateInfoEXT>(const VkPipelineColorBlendAdvancedStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcPremultiplied", toStringFlags, tabCount, tabSize, ToString(obj.srcPremultiplied, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstPremultiplied", toStringFlags, tabCount, tabSize, ToString(obj.dstPremultiplied, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "blendOverlap", toStringFlags, tabCount, tabSize, Quote(ToString(obj.blendOverlap, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPipelineCoverageToColorStateCreateInfoNV>(const VkPipelineCoverageToColorStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageToColorEnable", toStringFlags, tabCount, tabSize, ToString(obj.coverageToColorEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageToColorLocation", toStringFlags, tabCount, tabSize, ToString(obj.coverageToColorLocation, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCoverageModulationStateCreateInfoNV>(const VkPipelineCoverageModulationStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageModulationMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.coverageModulationMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "coverageModulationTableEnable", toStringFlags, tabCount, tabSize, ToString(obj.coverageModulationTableEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageModulationTableCount", toStringFlags, tabCount, tabSize, ToString(obj.coverageModulationTableCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCoverageModulationTable", toStringFlags, tabCount, tabSize, ArrayToString(obj.coverageModulationTableCount, obj.pCoverageModulationTable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>(const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSMCount", toStringFlags, tabCount, tabSize, ToString(obj.shaderSMCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderWarpsPerSM", toStringFlags, tabCount, tabSize, ToString(obj.shaderWarpsPerSM, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>(const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSMBuiltins", toStringFlags, tabCount, tabSize, ToString(obj.shaderSMBuiltins, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrmFormatModifierPropertiesEXT>(const VkDrmFormatModifierPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "drmFormatModifier", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierPlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierPlaneCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierTilingFeatures", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierTilingFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrmFormatModifierPropertiesListEXT>(const VkDrmFormatModifierPropertiesListEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDrmFormatModifierProperties", toStringFlags, tabCount, tabSize, ArrayToString(obj.drmFormatModifierCount, obj.pDrmFormatModifierProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageDrmFormatModifierInfoEXT>(const VkPhysicalDeviceImageDrmFormatModifierInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifier", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sharingMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sharingMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queueFamilyIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.queueFamilyIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.queueFamilyIndexCount, obj.pQueueFamilyIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageDrmFormatModifierListCreateInfoEXT>(const VkImageDrmFormatModifierListCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDrmFormatModifiers", toStringFlags, tabCount, tabSize, ArrayToString(obj.drmFormatModifierCount, obj.pDrmFormatModifiers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageDrmFormatModifierExplicitCreateInfoEXT>(const VkImageDrmFormatModifierExplicitCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifier", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierPlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierPlaneCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPlaneLayouts", toStringFlags, tabCount, tabSize, ArrayToString(obj.drmFormatModifierPlaneCount, obj.pPlaneLayouts, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageDrmFormatModifierPropertiesEXT>(const VkImageDrmFormatModifierPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifier", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifier, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrmFormatModifierProperties2EXT>(const VkDrmFormatModifierProperties2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "drmFormatModifier", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifier, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierPlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierPlaneCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierTilingFeatures", toStringFlags, tabCount, tabSize, Quote(VkFormatFeatureFlags2ToString(obj.drmFormatModifierTilingFeatures)));
        }
    );
}

template <> std::string ToString<VkDrmFormatModifierPropertiesList2EXT>(const VkDrmFormatModifierPropertiesList2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drmFormatModifierCount", toStringFlags, tabCount, tabSize, ToString(obj.drmFormatModifierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDrmFormatModifierProperties", toStringFlags, tabCount, tabSize, ArrayToString(obj.drmFormatModifierCount, obj.pDrmFormatModifierProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkValidationCacheCreateInfoEXT>(const VkValidationCacheCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "initialDataSize", toStringFlags, tabCount, tabSize, ToString(obj.initialDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInitialData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pInitialData)));
        }
    );
}

template <> std::string ToString<VkShaderModuleValidationCacheCreateInfoEXT>(const VkShaderModuleValidationCacheCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.validationCache)));
        }
    );
}

template <> std::string ToString<VkShadingRatePaletteNV>(const VkShadingRatePaletteNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "shadingRatePaletteEntryCount", toStringFlags, tabCount, tabSize, ToString(obj.shadingRatePaletteEntryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShadingRatePaletteEntries", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.shadingRatePaletteEntryCount, obj.pShadingRatePaletteEntries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportShadingRateImageStateCreateInfoNV>(const VkPipelineViewportShadingRateImageStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateImageEnable", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateImageEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(obj.viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShadingRatePalettes", toStringFlags, tabCount, tabSize, ArrayToString(obj.viewportCount, obj.pShadingRatePalettes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShadingRateImageFeaturesNV>(const VkPhysicalDeviceShadingRateImageFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateImage", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateImage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateCoarseSampleOrder", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateCoarseSampleOrder, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShadingRateImagePropertiesNV>(const VkPhysicalDeviceShadingRateImagePropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateTexelSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRatePaletteSize", toStringFlags, tabCount, tabSize, ToString(obj.shadingRatePaletteSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateMaxCoarseSamples", toStringFlags, tabCount, tabSize, ToString(obj.shadingRateMaxCoarseSamples, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCoarseSampleLocationNV>(const VkCoarseSampleLocationNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pixelX", toStringFlags, tabCount, tabSize, ToString(obj.pixelX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pixelY", toStringFlags, tabCount, tabSize, ToString(obj.pixelY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sample", toStringFlags, tabCount, tabSize, ToString(obj.sample, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCoarseSampleOrderCustomNV>(const VkCoarseSampleOrderCustomNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "shadingRate", toStringFlags, tabCount, tabSize, Quote(ToString(obj.shadingRate, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "sampleCount", toStringFlags, tabCount, tabSize, ToString(obj.sampleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleLocationCount", toStringFlags, tabCount, tabSize, ToString(obj.sampleLocationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSampleLocations", toStringFlags, tabCount, tabSize, ArrayToString(obj.sampleLocationCount, obj.pSampleLocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>(const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampleOrderType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sampleOrderType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "customSampleOrderCount", toStringFlags, tabCount, tabSize, ToString(obj.customSampleOrderCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCustomSampleOrders", toStringFlags, tabCount, tabSize, ArrayToString(obj.customSampleOrderCount, obj.pCustomSampleOrders, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRayTracingShaderGroupCreateInfoNV>(const VkRayTracingShaderGroupCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "generalShader", toStringFlags, tabCount, tabSize, ToString(obj.generalShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "closestHitShader", toStringFlags, tabCount, tabSize, ToString(obj.closestHitShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "anyHitShader", toStringFlags, tabCount, tabSize, ToString(obj.anyHitShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "intersectionShader", toStringFlags, tabCount, tabSize, ToString(obj.intersectionShader, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRayTracingPipelineCreateInfoNV>(const VkRayTracingPipelineCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageCount", toStringFlags, tabCount, tabSize, ToString(obj.stageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStages", toStringFlags, tabCount, tabSize, ArrayToString(obj.stageCount, obj.pStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(obj.groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGroups", toStringFlags, tabCount, tabSize, ArrayToString(obj.groupCount, obj.pGroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.layout)));
            FieldToString(strStrm, false, "basePipelineHandle", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.basePipelineHandle)));
            FieldToString(strStrm, false, "basePipelineIndex", toStringFlags, tabCount, tabSize, ToString(obj.basePipelineIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeometryTrianglesNV>(const VkGeometryTrianglesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexData", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.vertexData)));
            FieldToString(strStrm, false, "vertexOffset", toStringFlags, tabCount, tabSize, ToString(obj.vertexOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexStride", toStringFlags, tabCount, tabSize, ToString(obj.vertexStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.vertexFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "indexData", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.indexData)));
            FieldToString(strStrm, false, "indexOffset", toStringFlags, tabCount, tabSize, ToString(obj.indexOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexCount", toStringFlags, tabCount, tabSize, ToString(obj.indexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.indexType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "transformData", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.transformData)));
            FieldToString(strStrm, false, "transformOffset", toStringFlags, tabCount, tabSize, ToString(obj.transformOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeometryAABBNV>(const VkGeometryAABBNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "aabbData", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.aabbData)));
            FieldToString(strStrm, false, "numAABBs", toStringFlags, tabCount, tabSize, ToString(obj.numAABBs, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeometryDataNV>(const VkGeometryDataNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "triangles", toStringFlags, tabCount, tabSize, ToString(obj.triangles, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "aabbs", toStringFlags, tabCount, tabSize, ToString(obj.aabbs, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeometryNV>(const VkGeometryNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.geometryType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "geometry", toStringFlags, tabCount, tabSize, ToString(obj.geometry, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureInfoNV>(const VkAccelerationStructureInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(obj.instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "geometryCount", toStringFlags, tabCount, tabSize, ToString(obj.geometryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGeometries", toStringFlags, tabCount, tabSize, ArrayToString(obj.geometryCount, obj.pGeometries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureCreateInfoNV>(const VkAccelerationStructureCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compactedSize", toStringFlags, tabCount, tabSize, ToString(obj.compactedSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "info", toStringFlags, tabCount, tabSize, ToString(obj.info, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindAccelerationStructureMemoryInfoNV>(const VkBindAccelerationStructureMemoryInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.accelerationStructure)));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(obj.memoryOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.deviceIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeviceIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.deviceIndexCount, obj.pDeviceIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkWriteDescriptorSetAccelerationStructureNV>(const VkWriteDescriptorSetAccelerationStructureNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.accelerationStructureCount, obj.pAccelerationStructures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureMemoryRequirementsInfoNV>(const VkAccelerationStructureMemoryRequirementsInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.accelerationStructure)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingPropertiesNV>(const VkPhysicalDeviceRayTracingPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupHandleSize", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupHandleSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxShaderGroupStride", toStringFlags, tabCount, tabSize, ToString(obj.maxShaderGroupStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupBaseAlignment", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupBaseAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryCount", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxInstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTriangleCount", toStringFlags, tabCount, tabSize, ToString(obj.maxTriangleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetAccelerationStructures", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetAccelerationStructures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAabbPositionsKHR>(const VkAabbPositionsKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "minX", toStringFlags, tabCount, tabSize, ToString(obj.minX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minY", toStringFlags, tabCount, tabSize, ToString(obj.minY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minZ", toStringFlags, tabCount, tabSize, ToString(obj.minZ, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxX", toStringFlags, tabCount, tabSize, ToString(obj.maxX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxY", toStringFlags, tabCount, tabSize, ToString(obj.maxY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxZ", toStringFlags, tabCount, tabSize, ToString(obj.maxZ, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureInstanceKHR>(const VkAccelerationStructureInstanceKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "transform", toStringFlags, tabCount, tabSize, ToString(obj.transform, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCustomIndex", toStringFlags, tabCount, tabSize, ToString(obj.instanceCustomIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mask", toStringFlags, tabCount, tabSize, ToString(obj.mask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceShaderBindingTableRecordOffset", toStringFlags, tabCount, tabSize, ToString(obj.instanceShaderBindingTableRecordOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureReference", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureReference, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>(const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "representativeFragmentTest", toStringFlags, tabCount, tabSize, ToString(obj.representativeFragmentTest, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRepresentativeFragmentTestStateCreateInfoNV>(const VkPipelineRepresentativeFragmentTestStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "representativeFragmentTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.representativeFragmentTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageViewImageFormatInfoEXT>(const VkPhysicalDeviceImageViewImageFormatInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageViewType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageViewType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkFilterCubicImageViewImageFormatPropertiesEXT>(const VkFilterCubicImageViewImageFormatPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterCubic", toStringFlags, tabCount, tabSize, ToString(obj.filterCubic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterCubicMinmax", toStringFlags, tabCount, tabSize, ToString(obj.filterCubicMinmax, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportMemoryHostPointerInfoEXT>(const VkImportMemoryHostPointerInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pHostPointer", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pHostPointer)));
        }
    );
}

template <> std::string ToString<VkMemoryHostPointerPropertiesEXT>(const VkMemoryHostPointerPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalMemoryHostPropertiesEXT>(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minImportedHostPointerAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minImportedHostPointerAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCompilerControlCreateInfoAMD>(const VkPipelineCompilerControlCreateInfoAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compilerControlFlags", toStringFlags, tabCount, tabSize, ToString(obj.compilerControlFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCalibratedTimestampInfoEXT>(const VkCalibratedTimestampInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeDomain", toStringFlags, tabCount, tabSize, Quote(ToString(obj.timeDomain, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderCorePropertiesAMD>(const VkPhysicalDeviceShaderCorePropertiesAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderEngineCount", toStringFlags, tabCount, tabSize, ToString(obj.shaderEngineCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderArraysPerEngineCount", toStringFlags, tabCount, tabSize, ToString(obj.shaderArraysPerEngineCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeUnitsPerShaderArray", toStringFlags, tabCount, tabSize, ToString(obj.computeUnitsPerShaderArray, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "simdPerComputeUnit", toStringFlags, tabCount, tabSize, ToString(obj.simdPerComputeUnit, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "wavefrontsPerSimd", toStringFlags, tabCount, tabSize, ToString(obj.wavefrontsPerSimd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "wavefrontSize", toStringFlags, tabCount, tabSize, ToString(obj.wavefrontSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sgprsPerSimd", toStringFlags, tabCount, tabSize, ToString(obj.sgprsPerSimd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSgprAllocation", toStringFlags, tabCount, tabSize, ToString(obj.minSgprAllocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSgprAllocation", toStringFlags, tabCount, tabSize, ToString(obj.maxSgprAllocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sgprAllocationGranularity", toStringFlags, tabCount, tabSize, ToString(obj.sgprAllocationGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vgprsPerSimd", toStringFlags, tabCount, tabSize, ToString(obj.vgprsPerSimd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minVgprAllocation", toStringFlags, tabCount, tabSize, ToString(obj.minVgprAllocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVgprAllocation", toStringFlags, tabCount, tabSize, ToString(obj.maxVgprAllocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vgprAllocationGranularity", toStringFlags, tabCount, tabSize, ToString(obj.vgprAllocationGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceMemoryOverallocationCreateInfoAMD>(const VkDeviceMemoryOverallocationCreateInfoAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "overallocationBehavior", toStringFlags, tabCount, tabSize, Quote(ToString(obj.overallocationBehavior, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertexAttribDivisor", toStringFlags, tabCount, tabSize, ToString(obj.maxVertexAttribDivisor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVertexInputBindingDivisorDescriptionEXT>(const VkVertexInputBindingDivisorDescriptionEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "divisor", toStringFlags, tabCount, tabSize, ToString(obj.divisor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineVertexInputDivisorStateCreateInfoEXT>(const VkPipelineVertexInputDivisorStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexBindingDivisorCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexBindingDivisorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexBindingDivisors", toStringFlags, tabCount, tabSize, ArrayToString(obj.vertexBindingDivisorCount, obj.pVertexBindingDivisors, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>(const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeInstanceRateDivisor", toStringFlags, tabCount, tabSize, ToString(obj.vertexAttributeInstanceRateDivisor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeInstanceRateZeroDivisor", toStringFlags, tabCount, tabSize, ToString(obj.vertexAttributeInstanceRateZeroDivisor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPresentFrameTokenGGP>(const VkPresentFrameTokenGGP& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "frameToken", toStringFlags, tabCount, tabSize, ToString(obj.frameToken, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceComputeShaderDerivativesFeaturesNV>(const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeDerivativeGroupQuads", toStringFlags, tabCount, tabSize, ToString(obj.computeDerivativeGroupQuads, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "computeDerivativeGroupLinear", toStringFlags, tabCount, tabSize, ToString(obj.computeDerivativeGroupLinear, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMeshShaderFeaturesNV>(const VkPhysicalDeviceMeshShaderFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "taskShader", toStringFlags, tabCount, tabSize, ToString(obj.taskShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshShader", toStringFlags, tabCount, tabSize, ToString(obj.meshShader, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMeshShaderPropertiesNV>(const VkPhysicalDeviceMeshShaderPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawMeshTasksCount", toStringFlags, tabCount, tabSize, ToString(obj.maxDrawMeshTasksCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxTaskWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskTotalMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskTotalMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskOutputCount", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskOutputCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxMeshWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshTotalMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshTotalMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputVertices", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputVertices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputPrimitives, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshMultiviewViewCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshMultiviewViewCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshOutputPerVertexGranularity", toStringFlags, tabCount, tabSize, ToString(obj.meshOutputPerVertexGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshOutputPerPrimitiveGranularity", toStringFlags, tabCount, tabSize, ToString(obj.meshOutputPerPrimitiveGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrawMeshTasksIndirectCommandNV>(const VkDrawMeshTasksIndirectCommandNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "taskCount", toStringFlags, tabCount, tabSize, ToString(obj.taskCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstTask", toStringFlags, tabCount, tabSize, ToString(obj.firstTask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderImageFootprintFeaturesNV>(const VkPhysicalDeviceShaderImageFootprintFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageFootprint", toStringFlags, tabCount, tabSize, ToString(obj.imageFootprint, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportExclusiveScissorStateCreateInfoNV>(const VkPipelineViewportExclusiveScissorStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exclusiveScissorCount", toStringFlags, tabCount, tabSize, ToString(obj.exclusiveScissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExclusiveScissors", toStringFlags, tabCount, tabSize, ArrayToString(obj.exclusiveScissorCount, obj.pExclusiveScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExclusiveScissorFeaturesNV>(const VkPhysicalDeviceExclusiveScissorFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exclusiveScissor", toStringFlags, tabCount, tabSize, ToString(obj.exclusiveScissor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkQueueFamilyCheckpointPropertiesNV>(const VkQueueFamilyCheckpointPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "checkpointExecutionStageMask", toStringFlags, tabCount, tabSize, ToString(obj.checkpointExecutionStageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCheckpointDataNV>(const VkCheckpointDataNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(ToString(obj.stage, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pCheckpointMarker", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pCheckpointMarker)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>(const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderIntegerFunctions2", toStringFlags, tabCount, tabSize, ToString(obj.shaderIntegerFunctions2, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkInitializePerformanceApiInfoINTEL>(const VkInitializePerformanceApiInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pUserData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pUserData)));
        }
    );
}

template <> std::string ToString<VkQueryPoolPerformanceQueryCreateInfoINTEL>(const VkQueryPoolPerformanceQueryCreateInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "performanceCountersSampling", toStringFlags, tabCount, tabSize, Quote(ToString(obj.performanceCountersSampling, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPerformanceMarkerInfoINTEL>(const VkPerformanceMarkerInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "marker", toStringFlags, tabCount, tabSize, ToString(obj.marker, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPerformanceStreamMarkerInfoINTEL>(const VkPerformanceStreamMarkerInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "marker", toStringFlags, tabCount, tabSize, ToString(obj.marker, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPerformanceOverrideInfoINTEL>(const VkPerformanceOverrideInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "enable", toStringFlags, tabCount, tabSize, ToString(obj.enable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "parameter", toStringFlags, tabCount, tabSize, ToString(obj.parameter, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPerformanceConfigurationAcquireInfoINTEL>(const VkPerformanceConfigurationAcquireInfoINTEL& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePCIBusInfoPropertiesEXT>(const VkPhysicalDevicePCIBusInfoPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pciDomain", toStringFlags, tabCount, tabSize, ToString(obj.pciDomain, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pciBus", toStringFlags, tabCount, tabSize, ToString(obj.pciBus, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pciDevice", toStringFlags, tabCount, tabSize, ToString(obj.pciDevice, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pciFunction", toStringFlags, tabCount, tabSize, ToString(obj.pciFunction, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDisplayNativeHdrSurfaceCapabilitiesAMD>(const VkDisplayNativeHdrSurfaceCapabilitiesAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDimmingSupport", toStringFlags, tabCount, tabSize, ToString(obj.localDimmingSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainDisplayNativeHdrCreateInfoAMD>(const VkSwapchainDisplayNativeHdrCreateInfoAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDimmingEnable", toStringFlags, tabCount, tabSize, ToString(obj.localDimmingEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImagePipeSurfaceCreateInfoFUCHSIA>(const VkImagePipeSurfaceCreateInfoFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imagePipeHandle", toStringFlags, tabCount, tabSize, ToString(obj.imagePipeHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMetalSurfaceCreateInfoEXT>(const VkMetalSurfaceCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLayer", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pLayer)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMapFeaturesEXT>(const VkPhysicalDeviceFragmentDensityMapFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMap", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMap, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMapDynamic", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMapDynamic, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMapNonSubsampledImages", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMapNonSubsampledImages, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMapPropertiesEXT>(const VkPhysicalDeviceFragmentDensityMapPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minFragmentDensityTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.minFragmentDensityTexelSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentDensityTexelSize", toStringFlags, tabCount, tabSize, ToString(obj.maxFragmentDensityTexelSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityInvocations", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityInvocations, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassFragmentDensityMapCreateInfoEXT>(const VkRenderPassFragmentDensityMapCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMapAttachment", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMapAttachment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderCoreProperties2AMD>(const VkPhysicalDeviceShaderCoreProperties2AMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderCoreFeatures", toStringFlags, tabCount, tabSize, ToString(obj.shaderCoreFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "activeComputeUnitCount", toStringFlags, tabCount, tabSize, ToString(obj.activeComputeUnitCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(const VkPhysicalDeviceCoherentMemoryFeaturesAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceCoherentMemory", toStringFlags, tabCount, tabSize, ToString(obj.deviceCoherentMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>(const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderImageInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderImageInt64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseImageInt64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.sparseImageInt64Atomics, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMemoryBudgetPropertiesEXT>(const VkPhysicalDeviceMemoryBudgetPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "heapBudget", toStringFlags, tabCount, tabSize, ArrayToString(VK_MAX_MEMORY_HEAPS, obj.heapBudget, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "heapUsage", toStringFlags, tabCount, tabSize, ArrayToString(VK_MAX_MEMORY_HEAPS, obj.heapUsage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMemoryPriorityFeaturesEXT>(const VkPhysicalDeviceMemoryPriorityFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryPriority", toStringFlags, tabCount, tabSize, ToString(obj.memoryPriority, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryPriorityAllocateInfoEXT>(const VkMemoryPriorityAllocateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "priority", toStringFlags, tabCount, tabSize, ToString(obj.priority, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>(const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dedicatedAllocationImageAliasing", toStringFlags, tabCount, tabSize, ToString(obj.dedicatedAllocationImageAliasing, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>(const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferDeviceAddressMultiDevice", toStringFlags, tabCount, tabSize, ToString(obj.bufferDeviceAddressMultiDevice, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBufferDeviceAddressCreateInfoEXT>(const VkBufferDeviceAddressCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.deviceAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkValidationFeaturesEXT>(const VkValidationFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "enabledValidationFeatureCount", toStringFlags, tabCount, tabSize, ToString(obj.enabledValidationFeatureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEnabledValidationFeatures", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.enabledValidationFeatureCount, obj.pEnabledValidationFeatures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "disabledValidationFeatureCount", toStringFlags, tabCount, tabSize, ToString(obj.disabledValidationFeatureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisabledValidationFeatures", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.disabledValidationFeatureCount, obj.pDisabledValidationFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCooperativeMatrixPropertiesNV>(const VkCooperativeMatrixPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "MSize", toStringFlags, tabCount, tabSize, ToString(obj.MSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "NSize", toStringFlags, tabCount, tabSize, ToString(obj.NSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "KSize", toStringFlags, tabCount, tabSize, ToString(obj.KSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "AType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.AType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "BType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.BType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "CType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.CType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "DType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.DType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "scope", toStringFlags, tabCount, tabSize, Quote(ToString(obj.scope, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCooperativeMatrixFeaturesNV>(const VkPhysicalDeviceCooperativeMatrixFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cooperativeMatrix", toStringFlags, tabCount, tabSize, ToString(obj.cooperativeMatrix, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cooperativeMatrixRobustBufferAccess", toStringFlags, tabCount, tabSize, ToString(obj.cooperativeMatrixRobustBufferAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCooperativeMatrixPropertiesNV>(const VkPhysicalDeviceCooperativeMatrixPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "cooperativeMatrixSupportedStages", toStringFlags, tabCount, tabSize, ToString(obj.cooperativeMatrixSupportedStages, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCoverageReductionModeFeaturesNV>(const VkPhysicalDeviceCoverageReductionModeFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageReductionMode", toStringFlags, tabCount, tabSize, ToString(obj.coverageReductionMode, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineCoverageReductionStateCreateInfoNV>(const VkPipelineCoverageReductionStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageReductionMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.coverageReductionMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkFramebufferMixedSamplesCombinationNV>(const VkFramebufferMixedSamplesCombinationNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "coverageReductionMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.coverageReductionMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "rasterizationSamples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rasterizationSamples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthStencilSamples", toStringFlags, tabCount, tabSize, ToString(obj.depthStencilSamples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorSamples", toStringFlags, tabCount, tabSize, ToString(obj.colorSamples, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>(const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShaderSampleInterlock", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShaderSampleInterlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShaderPixelInterlock", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShaderPixelInterlock, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShaderShadingRateInterlock", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShaderShadingRateInterlock, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>(const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ycbcrImageArrays", toStringFlags, tabCount, tabSize, ToString(obj.ycbcrImageArrays, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProvokingVertexFeaturesEXT>(const VkPhysicalDeviceProvokingVertexFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "provokingVertexLast", toStringFlags, tabCount, tabSize, ToString(obj.provokingVertexLast, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackPreservesProvokingVertex", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackPreservesProvokingVertex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceProvokingVertexPropertiesEXT>(const VkPhysicalDeviceProvokingVertexPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "provokingVertexModePerPipeline", toStringFlags, tabCount, tabSize, ToString(obj.provokingVertexModePerPipeline, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformFeedbackPreservesTriangleFanProvokingVertex", toStringFlags, tabCount, tabSize, ToString(obj.transformFeedbackPreservesTriangleFanProvokingVertex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>(const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "provokingVertexMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.provokingVertexMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSurfaceFullScreenExclusiveInfoEXT>(const VkSurfaceFullScreenExclusiveInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fullScreenExclusive", toStringFlags, tabCount, tabSize, Quote(ToString(obj.fullScreenExclusive, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSurfaceCapabilitiesFullScreenExclusiveEXT>(const VkSurfaceCapabilitiesFullScreenExclusiveEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fullScreenExclusiveSupported", toStringFlags, tabCount, tabSize, ToString(obj.fullScreenExclusiveSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceFullScreenExclusiveWin32InfoEXT>(const VkSurfaceFullScreenExclusiveWin32InfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hmonitor", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.hmonitor)));
        }
    );
}

template <> std::string ToString<VkHeadlessSurfaceCreateInfoEXT>(const VkHeadlessSurfaceCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceLineRasterizationFeaturesEXT>(const VkPhysicalDeviceLineRasterizationFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rectangularLines", toStringFlags, tabCount, tabSize, ToString(obj.rectangularLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bresenhamLines", toStringFlags, tabCount, tabSize, ToString(obj.bresenhamLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "smoothLines", toStringFlags, tabCount, tabSize, ToString(obj.smoothLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stippledRectangularLines", toStringFlags, tabCount, tabSize, ToString(obj.stippledRectangularLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stippledBresenhamLines", toStringFlags, tabCount, tabSize, ToString(obj.stippledBresenhamLines, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stippledSmoothLines", toStringFlags, tabCount, tabSize, ToString(obj.stippledSmoothLines, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceLineRasterizationPropertiesEXT>(const VkPhysicalDeviceLineRasterizationPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineSubPixelPrecisionBits", toStringFlags, tabCount, tabSize, ToString(obj.lineSubPixelPrecisionBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineRasterizationLineStateCreateInfoEXT>(const VkPipelineRasterizationLineStateCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineRasterizationMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.lineRasterizationMode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stippledLineEnable", toStringFlags, tabCount, tabSize, ToString(obj.stippledLineEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineStippleFactor", toStringFlags, tabCount, tabSize, ToString(obj.lineStippleFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineStipplePattern", toStringFlags, tabCount, tabSize, ToString(obj.lineStipplePattern, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>(const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat32Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat32Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat32AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat32AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat64AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat64AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat32Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat32Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat32AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat32AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat64Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat64Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat64AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat64AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderImageFloat32Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderImageFloat32Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderImageFloat32AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderImageFloat32AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseImageFloat32Atomics", toStringFlags, tabCount, tabSize, ToString(obj.sparseImageFloat32Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseImageFloat32AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.sparseImageFloat32AtomicAdd, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceIndexTypeUint8FeaturesEXT>(const VkPhysicalDeviceIndexTypeUint8FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexTypeUint8", toStringFlags, tabCount, tabSize, ToString(obj.indexTypeUint8, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>(const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>(const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat16Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat16Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat16AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat16AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat16AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat16AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat32AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat32AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderBufferFloat64AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderBufferFloat64AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat16Atomics", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat16Atomics, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat16AtomicAdd", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat16AtomicAdd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat16AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat16AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat32AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat32AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderSharedFloat64AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderSharedFloat64AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderImageFloat32AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.shaderImageFloat32AtomicMinMax, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sparseImageFloat32AtomicMinMax", toStringFlags, tabCount, tabSize, ToString(obj.sparseImageFloat32AtomicMinMax, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfacePresentModeEXT>(const VkSurfacePresentModeEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentMode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.presentMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkSurfacePresentScalingCapabilitiesEXT>(const VkSurfacePresentScalingCapabilitiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedPresentScaling", toStringFlags, tabCount, tabSize, ToString(obj.supportedPresentScaling, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedPresentGravityX", toStringFlags, tabCount, tabSize, ToString(obj.supportedPresentGravityX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedPresentGravityY", toStringFlags, tabCount, tabSize, ToString(obj.supportedPresentGravityY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minScaledImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.minScaledImageExtent, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxScaledImageExtent", toStringFlags, tabCount, tabSize, ToString(obj.maxScaledImageExtent, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfacePresentModeCompatibilityEXT>(const VkSurfacePresentModeCompatibilityEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentModeCount", toStringFlags, tabCount, tabSize, ToString(obj.presentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModes", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.presentModeCount, obj.pPresentModes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>(const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainMaintenance1", toStringFlags, tabCount, tabSize, ToString(obj.swapchainMaintenance1, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainPresentFenceInfoEXT>(const VkSwapchainPresentFenceInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.swapchainCount, obj.pFences, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainPresentModesCreateInfoEXT>(const VkSwapchainPresentModesCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentModeCount", toStringFlags, tabCount, tabSize, ToString(obj.presentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModes", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.presentModeCount, obj.pPresentModes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainPresentModeInfoEXT>(const VkSwapchainPresentModeInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(obj.swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModes", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.swapchainCount, obj.pPresentModes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainPresentScalingCreateInfoEXT>(const VkSwapchainPresentScalingCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scalingBehavior", toStringFlags, tabCount, tabSize, ToString(obj.scalingBehavior, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentGravityX", toStringFlags, tabCount, tabSize, ToString(obj.presentGravityX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentGravityY", toStringFlags, tabCount, tabSize, ToString(obj.presentGravityY, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkReleaseSwapchainImagesInfoEXT>(const VkReleaseSwapchainImagesInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.swapchain)));
            FieldToString(strStrm, false, "imageIndexCount", toStringFlags, tabCount, tabSize, ToString(obj.imageIndexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageIndices", toStringFlags, tabCount, tabSize, ArrayToString(obj.imageIndexCount, obj.pImageIndices, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>(const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGraphicsShaderGroupCount", toStringFlags, tabCount, tabSize, ToString(obj.maxGraphicsShaderGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxIndirectSequenceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxIndirectSequenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxIndirectCommandsTokenCount", toStringFlags, tabCount, tabSize, ToString(obj.maxIndirectCommandsTokenCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxIndirectCommandsStreamCount", toStringFlags, tabCount, tabSize, ToString(obj.maxIndirectCommandsStreamCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxIndirectCommandsTokenOffset", toStringFlags, tabCount, tabSize, ToString(obj.maxIndirectCommandsTokenOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxIndirectCommandsStreamStride", toStringFlags, tabCount, tabSize, ToString(obj.maxIndirectCommandsStreamStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSequencesCountBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minSequencesCountBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minSequencesIndexBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minSequencesIndexBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minIndirectCommandsBufferOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minIndirectCommandsBufferOffsetAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>(const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceGeneratedCommands", toStringFlags, tabCount, tabSize, ToString(obj.deviceGeneratedCommands, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGraphicsShaderGroupCreateInfoNV>(const VkGraphicsShaderGroupCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageCount", toStringFlags, tabCount, tabSize, ToString(obj.stageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStages", toStringFlags, tabCount, tabSize, ArrayToString(obj.stageCount, obj.pStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexInputState", toStringFlags, tabCount, tabSize, (obj.pVertexInputState ? ToString(*obj.pVertexInputState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pTessellationState", toStringFlags, tabCount, tabSize, (obj.pTessellationState ? ToString(*obj.pTessellationState, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkGraphicsPipelineShaderGroupsCreateInfoNV>(const VkGraphicsPipelineShaderGroupsCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(obj.groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGroups", toStringFlags, tabCount, tabSize, ArrayToString(obj.groupCount, obj.pGroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineCount", toStringFlags, tabCount, tabSize, ToString(obj.pipelineCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelines", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.pipelineCount, obj.pPipelines, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindShaderGroupIndirectCommandNV>(const VkBindShaderGroupIndirectCommandNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "groupIndex", toStringFlags, tabCount, tabSize, ToString(obj.groupIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkBindIndexBufferIndirectCommandNV>(const VkBindIndexBufferIndirectCommandNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "bufferAddress", toStringFlags, tabCount, tabSize, ToString(obj.bufferAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.indexType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkBindVertexBufferIndirectCommandNV>(const VkBindVertexBufferIndirectCommandNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "bufferAddress", toStringFlags, tabCount, tabSize, ToString(obj.bufferAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSetStateFlagsIndirectCommandNV>(const VkSetStateFlagsIndirectCommandNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "data", toStringFlags, tabCount, tabSize, ToString(obj.data, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkIndirectCommandsStreamNV>(const VkIndirectCommandsStreamNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkIndirectCommandsLayoutTokenNV>(const VkIndirectCommandsLayoutTokenNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tokenType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.tokenType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "stream", toStringFlags, tabCount, tabSize, ToString(obj.stream, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexBindingUnit", toStringFlags, tabCount, tabSize, ToString(obj.vertexBindingUnit, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexDynamicStride", toStringFlags, tabCount, tabSize, ToString(obj.vertexDynamicStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pushconstantPipelineLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pushconstantPipelineLayout)));
            FieldToString(strStrm, false, "pushconstantShaderStageFlags", toStringFlags, tabCount, tabSize, ToString(obj.pushconstantShaderStageFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pushconstantOffset", toStringFlags, tabCount, tabSize, ToString(obj.pushconstantOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pushconstantSize", toStringFlags, tabCount, tabSize, ToString(obj.pushconstantSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indirectStateFlags", toStringFlags, tabCount, tabSize, ToString(obj.indirectStateFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexTypeCount", toStringFlags, tabCount, tabSize, ToString(obj.indexTypeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndexTypes", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.indexTypeCount, obj.pIndexTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndexTypeValues", toStringFlags, tabCount, tabSize, ArrayToString(obj.indexTypeCount, obj.pIndexTypeValues, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkIndirectCommandsLayoutCreateInfoNV>(const VkIndirectCommandsLayoutCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "tokenCount", toStringFlags, tabCount, tabSize, ToString(obj.tokenCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTokens", toStringFlags, tabCount, tabSize, ArrayToString(obj.tokenCount, obj.pTokens, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "streamCount", toStringFlags, tabCount, tabSize, ToString(obj.streamCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStreamStrides", toStringFlags, tabCount, tabSize, ArrayToString(obj.streamCount, obj.pStreamStrides, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeneratedCommandsInfoNV>(const VkGeneratedCommandsInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pipeline)));
            FieldToString(strStrm, false, "indirectCommandsLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.indirectCommandsLayout)));
            FieldToString(strStrm, false, "streamCount", toStringFlags, tabCount, tabSize, ToString(obj.streamCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStreams", toStringFlags, tabCount, tabSize, ArrayToString(obj.streamCount, obj.pStreams, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sequencesCount", toStringFlags, tabCount, tabSize, ToString(obj.sequencesCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "preprocessBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.preprocessBuffer)));
            FieldToString(strStrm, false, "preprocessOffset", toStringFlags, tabCount, tabSize, ToString(obj.preprocessOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "preprocessSize", toStringFlags, tabCount, tabSize, ToString(obj.preprocessSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sequencesCountBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.sequencesCountBuffer)));
            FieldToString(strStrm, false, "sequencesCountOffset", toStringFlags, tabCount, tabSize, ToString(obj.sequencesCountOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sequencesIndexBuffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.sequencesIndexBuffer)));
            FieldToString(strStrm, false, "sequencesIndexOffset", toStringFlags, tabCount, tabSize, ToString(obj.sequencesIndexOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGeneratedCommandsMemoryRequirementsInfoNV>(const VkGeneratedCommandsMemoryRequirementsInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.pipelineBindPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.pipeline)));
            FieldToString(strStrm, false, "indirectCommandsLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.indirectCommandsLayout)));
            FieldToString(strStrm, false, "maxSequencesCount", toStringFlags, tabCount, tabSize, ToString(obj.maxSequencesCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceInheritedViewportScissorFeaturesNV>(const VkPhysicalDeviceInheritedViewportScissorFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inheritedViewportScissor2D", toStringFlags, tabCount, tabSize, ToString(obj.inheritedViewportScissor2D, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCommandBufferInheritanceViewportScissorInfoNV>(const VkCommandBufferInheritanceViewportScissorInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportScissor2D", toStringFlags, tabCount, tabSize, ToString(obj.viewportScissor2D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportDepthCount", toStringFlags, tabCount, tabSize, ToString(obj.viewportDepthCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportDepths", toStringFlags, tabCount, tabSize, (obj.pViewportDepths ? ToString(*obj.pViewportDepths, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>(const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "texelBufferAlignment", toStringFlags, tabCount, tabSize, ToString(obj.texelBufferAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassTransformBeginInfoQCOM>(const VkRenderPassTransformBeginInfoQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.transform, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkCommandBufferInheritanceRenderPassTransformInfoQCOM>(const VkCommandBufferInheritanceRenderPassTransformInfoQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.transform, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "renderArea", toStringFlags, tabCount, tabSize, ToString(obj.renderArea, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>(const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceMemoryReport", toStringFlags, tabCount, tabSize, ToString(obj.deviceMemoryReport, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceMemoryReportCallbackDataEXT>(const VkDeviceMemoryReportCallbackDataEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "memoryObjectId", toStringFlags, tabCount, tabSize, ToString(obj.memoryObjectId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(obj.objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(obj.heapIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceDeviceMemoryReportCreateInfoEXT>(const VkDeviceDeviceMemoryReportCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pfnUserCallback", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnUserCallback)));
            FieldToString(strStrm, false, "pUserData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pUserData)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRobustness2FeaturesEXT>(const VkPhysicalDeviceRobustness2FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustBufferAccess2", toStringFlags, tabCount, tabSize, ToString(obj.robustBufferAccess2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustImageAccess2", toStringFlags, tabCount, tabSize, ToString(obj.robustImageAccess2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "nullDescriptor", toStringFlags, tabCount, tabSize, ToString(obj.nullDescriptor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRobustness2PropertiesEXT>(const VkPhysicalDeviceRobustness2PropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustStorageBufferAccessSizeAlignment", toStringFlags, tabCount, tabSize, ToString(obj.robustStorageBufferAccessSizeAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "robustUniformBufferAccessSizeAlignment", toStringFlags, tabCount, tabSize, ToString(obj.robustUniformBufferAccessSizeAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerCustomBorderColorCreateInfoEXT>(const VkSamplerCustomBorderColorCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "customBorderColor", toStringFlags, tabCount, tabSize, ToString(obj.customBorderColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCustomBorderColorPropertiesEXT>(const VkPhysicalDeviceCustomBorderColorPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxCustomBorderColorSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxCustomBorderColorSamplers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceCustomBorderColorFeaturesEXT>(const VkPhysicalDeviceCustomBorderColorFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "customBorderColors", toStringFlags, tabCount, tabSize, ToString(obj.customBorderColors, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "customBorderColorWithoutFormat", toStringFlags, tabCount, tabSize, ToString(obj.customBorderColorWithoutFormat, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePresentBarrierFeaturesNV>(const VkPhysicalDevicePresentBarrierFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentBarrier", toStringFlags, tabCount, tabSize, ToString(obj.presentBarrier, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSurfaceCapabilitiesPresentBarrierNV>(const VkSurfaceCapabilitiesPresentBarrierNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentBarrierSupported", toStringFlags, tabCount, tabSize, ToString(obj.presentBarrierSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSwapchainPresentBarrierCreateInfoNV>(const VkSwapchainPresentBarrierCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "presentBarrierEnable", toStringFlags, tabCount, tabSize, ToString(obj.presentBarrierEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDiagnosticsConfigFeaturesNV>(const VkPhysicalDeviceDiagnosticsConfigFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "diagnosticsConfig", toStringFlags, tabCount, tabSize, ToString(obj.diagnosticsConfig, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceDiagnosticsConfigCreateInfoNV>(const VkDeviceDiagnosticsConfigCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>(const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "graphicsPipelineLibrary", toStringFlags, tabCount, tabSize, ToString(obj.graphicsPipelineLibrary, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>(const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "graphicsPipelineLibraryFastLinking", toStringFlags, tabCount, tabSize, ToString(obj.graphicsPipelineLibraryFastLinking, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "graphicsPipelineLibraryIndependentInterpolationDecoration", toStringFlags, tabCount, tabSize, ToString(obj.graphicsPipelineLibraryIndependentInterpolationDecoration, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkGraphicsPipelineLibraryCreateInfoEXT>(const VkGraphicsPipelineLibraryCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>(const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderEarlyAndLateFragmentTests", toStringFlags, tabCount, tabSize, ToString(obj.shaderEarlyAndLateFragmentTests, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>(const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentShadingRateEnums", toStringFlags, tabCount, tabSize, ToString(obj.fragmentShadingRateEnums, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supersampleFragmentShadingRates", toStringFlags, tabCount, tabSize, ToString(obj.supersampleFragmentShadingRates, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "noInvocationFragmentShadingRates", toStringFlags, tabCount, tabSize, ToString(obj.noInvocationFragmentShadingRates, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>(const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxFragmentShadingRateInvocationCount", toStringFlags, tabCount, tabSize, Quote(ToString(obj.maxFragmentShadingRateInvocationCount, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPipelineFragmentShadingRateEnumStateCreateInfoNV>(const VkPipelineFragmentShadingRateEnumStateCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shadingRateType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.shadingRateType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "shadingRate", toStringFlags, tabCount, tabSize, Quote(ToString(obj.shadingRate, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, ArrayToString(2, obj.combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureGeometryMotionTrianglesDataNV>(const VkAccelerationStructureGeometryMotionTrianglesDataNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexData", toStringFlags, tabCount, tabSize, ToString(obj.vertexData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureMotionInfoNV>(const VkAccelerationStructureMotionInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInstances", toStringFlags, tabCount, tabSize, ToString(obj.maxInstances, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureMatrixMotionInstanceNV>(const VkAccelerationStructureMatrixMotionInstanceNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "transformT0", toStringFlags, tabCount, tabSize, ToString(obj.transformT0, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformT1", toStringFlags, tabCount, tabSize, ToString(obj.transformT1, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCustomIndex", toStringFlags, tabCount, tabSize, ToString(obj.instanceCustomIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mask", toStringFlags, tabCount, tabSize, ToString(obj.mask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceShaderBindingTableRecordOffset", toStringFlags, tabCount, tabSize, ToString(obj.instanceShaderBindingTableRecordOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureReference", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureReference, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSRTDataNV>(const VkSRTDataNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sx", toStringFlags, tabCount, tabSize, ToString(obj.sx, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "a", toStringFlags, tabCount, tabSize, ToString(obj.a, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "b", toStringFlags, tabCount, tabSize, ToString(obj.b, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pvx", toStringFlags, tabCount, tabSize, ToString(obj.pvx, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sy", toStringFlags, tabCount, tabSize, ToString(obj.sy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "c", toStringFlags, tabCount, tabSize, ToString(obj.c, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pvy", toStringFlags, tabCount, tabSize, ToString(obj.pvy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sz", toStringFlags, tabCount, tabSize, ToString(obj.sz, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pvz", toStringFlags, tabCount, tabSize, ToString(obj.pvz, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qx", toStringFlags, tabCount, tabSize, ToString(obj.qx, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qy", toStringFlags, tabCount, tabSize, ToString(obj.qy, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qz", toStringFlags, tabCount, tabSize, ToString(obj.qz, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "qw", toStringFlags, tabCount, tabSize, ToString(obj.qw, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tx", toStringFlags, tabCount, tabSize, ToString(obj.tx, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ty", toStringFlags, tabCount, tabSize, ToString(obj.ty, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tz", toStringFlags, tabCount, tabSize, ToString(obj.tz, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureSRTMotionInstanceNV>(const VkAccelerationStructureSRTMotionInstanceNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "transformT0", toStringFlags, tabCount, tabSize, ToString(obj.transformT0, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformT1", toStringFlags, tabCount, tabSize, ToString(obj.transformT1, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCustomIndex", toStringFlags, tabCount, tabSize, ToString(obj.instanceCustomIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mask", toStringFlags, tabCount, tabSize, ToString(obj.mask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceShaderBindingTableRecordOffset", toStringFlags, tabCount, tabSize, ToString(obj.instanceShaderBindingTableRecordOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureReference", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureReference, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>(const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingMotionBlur", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingMotionBlur, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingMotionBlurPipelineTraceRaysIndirect", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingMotionBlurPipelineTraceRaysIndirect, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>(const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ycbcr2plane444Formats", toStringFlags, tabCount, tabSize, ToString(obj.ycbcr2plane444Formats, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>(const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMapDeferred", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMapDeferred, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>(const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subsampledLoads", toStringFlags, tabCount, tabSize, ToString(obj.subsampledLoads, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subsampledCoarseReconstructionEarlyAccess", toStringFlags, tabCount, tabSize, ToString(obj.subsampledCoarseReconstructionEarlyAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxSubsampledArrayLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxSubsampledArrayLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetSubsampledSamplers", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetSubsampledSamplers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyCommandTransformInfoQCOM>(const VkCopyCommandTransformInfoQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transform", toStringFlags, tabCount, tabSize, Quote(ToString(obj.transform, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageCompressionControlFeaturesEXT>(const VkPhysicalDeviceImageCompressionControlFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCompressionControl", toStringFlags, tabCount, tabSize, ToString(obj.imageCompressionControl, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageCompressionControlEXT>(const VkImageCompressionControlEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compressionControlPlaneCount", toStringFlags, tabCount, tabSize, ToString(obj.compressionControlPlaneCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFixedRateFlags", toStringFlags, tabCount, tabSize, ArrayToString(obj.compressionControlPlaneCount, obj.pFixedRateFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubresourceLayout2EXT>(const VkSubresourceLayout2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subresourceLayout", toStringFlags, tabCount, tabSize, ToString(obj.subresourceLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageSubresource2EXT>(const VkImageSubresource2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageSubresource", toStringFlags, tabCount, tabSize, ToString(obj.imageSubresource, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageCompressionPropertiesEXT>(const VkImageCompressionPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCompressionFlags", toStringFlags, tabCount, tabSize, ToString(obj.imageCompressionFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCompressionFixedRateFlags", toStringFlags, tabCount, tabSize, ToString(obj.imageCompressionFixedRateFlags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>(const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentFeedbackLoopLayout", toStringFlags, tabCount, tabSize, ToString(obj.attachmentFeedbackLoopLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevice4444FormatsFeaturesEXT>(const VkPhysicalDevice4444FormatsFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatA4R4G4B4", toStringFlags, tabCount, tabSize, ToString(obj.formatA4R4G4B4, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatA4B4G4R4", toStringFlags, tabCount, tabSize, ToString(obj.formatA4B4G4R4, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFaultFeaturesEXT>(const VkPhysicalDeviceFaultFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceFault", toStringFlags, tabCount, tabSize, ToString(obj.deviceFault, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceFaultVendorBinary", toStringFlags, tabCount, tabSize, ToString(obj.deviceFaultVendorBinary, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceFaultCountsEXT>(const VkDeviceFaultCountsEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "addressInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.addressInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vendorInfoCount", toStringFlags, tabCount, tabSize, ToString(obj.vendorInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vendorBinarySize", toStringFlags, tabCount, tabSize, ToString(obj.vendorBinarySize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceFaultAddressInfoEXT>(const VkDeviceFaultAddressInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "addressType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.addressType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "reportedAddress", toStringFlags, tabCount, tabSize, ToString(obj.reportedAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "addressPrecision", toStringFlags, tabCount, tabSize, ToString(obj.addressPrecision, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceFaultVendorInfoEXT>(const VkDeviceFaultVendorInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "vendorFaultCode", toStringFlags, tabCount, tabSize, ToString(obj.vendorFaultCode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vendorFaultData", toStringFlags, tabCount, tabSize, ToString(obj.vendorFaultData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceFaultInfoEXT>(const VkDeviceFaultInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "pAddressInfos", toStringFlags, tabCount, tabSize, (obj.pAddressInfos ? ToString(*obj.pAddressInfos, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pVendorInfos", toStringFlags, tabCount, tabSize, (obj.pVendorInfos ? ToString(*obj.pVendorInfos, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pVendorBinaryData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pVendorBinaryData)));
        }
    );
}

template <> std::string ToString<VkDeviceFaultVendorBinaryHeaderVersionOneEXT>(const VkDeviceFaultVendorBinaryHeaderVersionOneEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "headerSize", toStringFlags, tabCount, tabSize, ToString(obj.headerSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "headerVersion", toStringFlags, tabCount, tabSize, Quote(ToString(obj.headerVersion, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "vendorID", toStringFlags, tabCount, tabSize, ToString(obj.vendorID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "deviceID", toStringFlags, tabCount, tabSize, ToString(obj.deviceID, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "driverVersion", toStringFlags, tabCount, tabSize, ToString(obj.driverVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineCacheUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.pipelineCacheUUID)));
            FieldToString(strStrm, false, "applicationNameOffset", toStringFlags, tabCount, tabSize, ToString(obj.applicationNameOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "applicationVersion", toStringFlags, tabCount, tabSize, ToString(obj.applicationVersion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "engineNameOffset", toStringFlags, tabCount, tabSize, ToString(obj.engineNameOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>(const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationOrderColorAttachmentAccess", toStringFlags, tabCount, tabSize, ToString(obj.rasterizationOrderColorAttachmentAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationOrderDepthAttachmentAccess", toStringFlags, tabCount, tabSize, ToString(obj.rasterizationOrderDepthAttachmentAccess, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationOrderStencilAttachmentAccess", toStringFlags, tabCount, tabSize, ToString(obj.rasterizationOrderStencilAttachmentAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>(const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "formatRgba10x6WithoutYCbCrSampler", toStringFlags, tabCount, tabSize, ToString(obj.formatRgba10x6WithoutYCbCrSampler, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDirectFBSurfaceCreateInfoEXT>(const VkDirectFBSurfaceCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dfb", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.dfb)));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.surface)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>(const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mutableDescriptorType", toStringFlags, tabCount, tabSize, ToString(obj.mutableDescriptorType, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMutableDescriptorTypeListEXT>(const VkMutableDescriptorTypeListEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "descriptorTypeCount", toStringFlags, tabCount, tabSize, ToString(obj.descriptorTypeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorTypes", toStringFlags, tabCount, tabSize, VkEnumArrayToString(obj.descriptorTypeCount, obj.pDescriptorTypes, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMutableDescriptorTypeCreateInfoEXT>(const VkMutableDescriptorTypeCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mutableDescriptorTypeListCount", toStringFlags, tabCount, tabSize, ToString(obj.mutableDescriptorTypeListCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMutableDescriptorTypeLists", toStringFlags, tabCount, tabSize, ArrayToString(obj.mutableDescriptorTypeListCount, obj.pMutableDescriptorTypeLists, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>(const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexInputDynamicState", toStringFlags, tabCount, tabSize, ToString(obj.vertexInputDynamicState, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVertexInputBindingDescription2EXT>(const VkVertexInputBindingDescription2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "inputRate", toStringFlags, tabCount, tabSize, Quote(ToString(obj.inputRate, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "divisor", toStringFlags, tabCount, tabSize, ToString(obj.divisor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkVertexInputAttributeDescription2EXT>(const VkVertexInputAttributeDescription2EXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "location", toStringFlags, tabCount, tabSize, ToString(obj.location, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDrmPropertiesEXT>(const VkPhysicalDeviceDrmPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hasPrimary", toStringFlags, tabCount, tabSize, ToString(obj.hasPrimary, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hasRender", toStringFlags, tabCount, tabSize, ToString(obj.hasRender, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primaryMajor", toStringFlags, tabCount, tabSize, ToString(obj.primaryMajor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primaryMinor", toStringFlags, tabCount, tabSize, ToString(obj.primaryMinor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderMajor", toStringFlags, tabCount, tabSize, ToString(obj.renderMajor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "renderMinor", toStringFlags, tabCount, tabSize, ToString(obj.renderMinor, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(const VkPhysicalDeviceAddressBindingReportFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "reportAddressBinding", toStringFlags, tabCount, tabSize, ToString(obj.reportAddressBinding, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDeviceAddressBindingCallbackDataEXT>(const VkDeviceAddressBindingCallbackDataEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseAddress", toStringFlags, tabCount, tabSize, ToString(obj.baseAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.bindingType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDepthClipControlFeaturesEXT>(const VkPhysicalDeviceDepthClipControlFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClipControl", toStringFlags, tabCount, tabSize, ToString(obj.depthClipControl, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineViewportDepthClipControlCreateInfoEXT>(const VkPipelineViewportDepthClipControlCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "negativeOneToOne", toStringFlags, tabCount, tabSize, ToString(obj.negativeOneToOne, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>(const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveTopologyListRestart", toStringFlags, tabCount, tabSize, ToString(obj.primitiveTopologyListRestart, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveTopologyPatchListRestart", toStringFlags, tabCount, tabSize, ToString(obj.primitiveTopologyPatchListRestart, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImportMemoryZirconHandleInfoFUCHSIA>(const VkImportMemoryZirconHandleInfoFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, ToString(obj.handle, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryZirconHandlePropertiesFUCHSIA>(const VkMemoryZirconHandlePropertiesFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryTypeBits", toStringFlags, tabCount, tabSize, ToString(obj.memoryTypeBits, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryGetZirconHandleInfoFUCHSIA>(const VkMemoryGetZirconHandleInfoFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkImportSemaphoreZirconHandleInfoFUCHSIA>(const VkImportSemaphoreZirconHandleInfoFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "zirconHandle", toStringFlags, tabCount, tabSize, ToString(obj.zirconHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSemaphoreGetZirconHandleInfoFUCHSIA>(const VkSemaphoreGetZirconHandleInfoFUCHSIA& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.semaphore)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>(const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "invocationMask", toStringFlags, tabCount, tabSize, ToString(obj.invocationMask, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMemoryGetRemoteAddressInfoNV>(const VkMemoryGetRemoteAddressInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.memory)));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.handleType, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>(const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalMemoryRDMA", toStringFlags, tabCount, tabSize, ToString(obj.externalMemoryRDMA, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>(const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multisampledRenderToSingleSampled", toStringFlags, tabCount, tabSize, ToString(obj.multisampledRenderToSingleSampled, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassResolvePerformanceQueryEXT>(const VkSubpassResolvePerformanceQueryEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "optimal", toStringFlags, tabCount, tabSize, ToString(obj.optimal, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMultisampledRenderToSingleSampledInfoEXT>(const VkMultisampledRenderToSingleSampledInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multisampledRenderToSingleSampledEnable", toStringFlags, tabCount, tabSize, ToString(obj.multisampledRenderToSingleSampledEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rasterizationSamples", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rasterizationSamples, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>(const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState2", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState2, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState2LogicOp", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState2LogicOp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState2PatchControlPoints", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState2PatchControlPoints, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkScreenSurfaceCreateInfoQNX>(const VkScreenSurfaceCreateInfoQNX& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "context", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.context)));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.window)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceColorWriteEnableFeaturesEXT>(const VkPhysicalDeviceColorWriteEnableFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "colorWriteEnable", toStringFlags, tabCount, tabSize, ToString(obj.colorWriteEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPipelineColorWriteCreateInfoEXT>(const VkPipelineColorWriteCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorWriteEnables", toStringFlags, tabCount, tabSize, ArrayToString(obj.attachmentCount, obj.pColorWriteEnables, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>(const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitivesGeneratedQuery", toStringFlags, tabCount, tabSize, ToString(obj.primitivesGeneratedQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitivesGeneratedQueryWithRasterizerDiscard", toStringFlags, tabCount, tabSize, ToString(obj.primitivesGeneratedQueryWithRasterizerDiscard, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitivesGeneratedQueryWithNonZeroStreams", toStringFlags, tabCount, tabSize, ToString(obj.primitivesGeneratedQueryWithNonZeroStreams, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageViewMinLodFeaturesEXT>(const VkPhysicalDeviceImageViewMinLodFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minLod", toStringFlags, tabCount, tabSize, ToString(obj.minLod, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageViewMinLodCreateInfoEXT>(const VkImageViewMinLodCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minLod", toStringFlags, tabCount, tabSize, ToString(obj.minLod, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiDrawFeaturesEXT>(const VkPhysicalDeviceMultiDrawFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiDraw", toStringFlags, tabCount, tabSize, ToString(obj.multiDraw, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiDrawPropertiesEXT>(const VkPhysicalDeviceMultiDrawPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMultiDrawCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMultiDrawCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMultiDrawInfoEXT>(const VkMultiDrawInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "firstVertex", toStringFlags, tabCount, tabSize, ToString(obj.firstVertex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexCount", toStringFlags, tabCount, tabSize, ToString(obj.vertexCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMultiDrawIndexedInfoEXT>(const VkMultiDrawIndexedInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "firstIndex", toStringFlags, tabCount, tabSize, ToString(obj.firstIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexCount", toStringFlags, tabCount, tabSize, ToString(obj.indexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexOffset", toStringFlags, tabCount, tabSize, ToString(obj.vertexOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>(const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "image2DViewOf3D", toStringFlags, tabCount, tabSize, ToString(obj.image2DViewOf3D, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "sampler2DViewOf3D", toStringFlags, tabCount, tabSize, ToString(obj.sampler2DViewOf3D, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMicromapUsageEXT>(const VkMicromapUsageEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "count", toStringFlags, tabCount, tabSize, ToString(obj.count, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subdivisionLevel", toStringFlags, tabCount, tabSize, ToString(obj.subdivisionLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, ToString(obj.format, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMicromapBuildInfoEXT>(const VkMicromapBuildInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstMicromap", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dstMicromap)));
            FieldToString(strStrm, false, "usageCountsCount", toStringFlags, tabCount, tabSize, ToString(obj.usageCountsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pUsageCounts", toStringFlags, tabCount, tabSize, ArrayToString(obj.usageCountsCount, obj.pUsageCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppUsageCounts", toStringFlags, tabCount, tabSize, Array2DToString(obj.usageCountsCount, 1, obj.ppUsageCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(obj.data, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scratchData", toStringFlags, tabCount, tabSize, ToString(obj.scratchData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "triangleArray", toStringFlags, tabCount, tabSize, ToString(obj.triangleArray, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "triangleArrayStride", toStringFlags, tabCount, tabSize, ToString(obj.triangleArrayStride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMicromapCreateInfoEXT>(const VkMicromapCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "createFlags", toStringFlags, tabCount, tabSize, ToString(obj.createFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "deviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.deviceAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceOpacityMicromapFeaturesEXT>(const VkPhysicalDeviceOpacityMicromapFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "micromap", toStringFlags, tabCount, tabSize, ToString(obj.micromap, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "micromapCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.micromapCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "micromapHostCommands", toStringFlags, tabCount, tabSize, ToString(obj.micromapHostCommands, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceOpacityMicromapPropertiesEXT>(const VkPhysicalDeviceOpacityMicromapPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxOpacity2StateSubdivisionLevel", toStringFlags, tabCount, tabSize, ToString(obj.maxOpacity2StateSubdivisionLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxOpacity4StateSubdivisionLevel", toStringFlags, tabCount, tabSize, ToString(obj.maxOpacity4StateSubdivisionLevel, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkMicromapVersionInfoEXT>(const VkMicromapVersionInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVersionData", toStringFlags, tabCount, tabSize, ArrayToString(2*VK_UUID_SIZE, obj.pVersionData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkCopyMicromapToMemoryInfoEXT>(const VkCopyMicromapToMemoryInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.src)));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, ToString(obj.dst, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkCopyMemoryToMicromapInfoEXT>(const VkCopyMemoryToMicromapInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, ToString(obj.src, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dst)));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkCopyMicromapInfoEXT>(const VkCopyMicromapInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.src)));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dst)));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkMicromapBuildSizesInfoEXT>(const VkMicromapBuildSizesInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "micromapSize", toStringFlags, tabCount, tabSize, ToString(obj.micromapSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buildScratchSize", toStringFlags, tabCount, tabSize, ToString(obj.buildScratchSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "discardable", toStringFlags, tabCount, tabSize, ToString(obj.discardable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureTrianglesOpacityMicromapEXT>(const VkAccelerationStructureTrianglesOpacityMicromapEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.indexType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "indexBuffer", toStringFlags, tabCount, tabSize, ToString(obj.indexBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexStride", toStringFlags, tabCount, tabSize, ToString(obj.indexStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseTriangle", toStringFlags, tabCount, tabSize, ToString(obj.baseTriangle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usageCountsCount", toStringFlags, tabCount, tabSize, ToString(obj.usageCountsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pUsageCounts", toStringFlags, tabCount, tabSize, ArrayToString(obj.usageCountsCount, obj.pUsageCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppUsageCounts", toStringFlags, tabCount, tabSize, Array2DToString(obj.usageCountsCount, 1, obj.ppUsageCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "micromap", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.micromap)));
        }
    );
}

template <> std::string ToString<VkMicromapTriangleEXT>(const VkMicromapTriangleEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "dataOffset", toStringFlags, tabCount, tabSize, ToString(obj.dataOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subdivisionLevel", toStringFlags, tabCount, tabSize, ToString(obj.subdivisionLevel, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, ToString(obj.format, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>(const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "clustercullingShader", toStringFlags, tabCount, tabSize, ToString(obj.clustercullingShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewClusterCullingShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewClusterCullingShader, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>(const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxWorkGroupCount", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxWorkGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxOutputClusterCount", toStringFlags, tabCount, tabSize, ToString(obj.maxOutputClusterCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>(const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "borderColorSwizzle", toStringFlags, tabCount, tabSize, ToString(obj.borderColorSwizzle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "borderColorSwizzleFromImage", toStringFlags, tabCount, tabSize, ToString(obj.borderColorSwizzleFromImage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSamplerBorderColorComponentMappingCreateInfoEXT>(const VkSamplerBorderColorComponentMappingCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "components", toStringFlags, tabCount, tabSize, ToString(obj.components, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srgb", toStringFlags, tabCount, tabSize, ToString(obj.srgb, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>(const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pageableDeviceLocalMemory", toStringFlags, tabCount, tabSize, ToString(obj.pageableDeviceLocalMemory, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>(const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorSetHostMapping", toStringFlags, tabCount, tabSize, ToString(obj.descriptorSetHostMapping, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetBindingReferenceVALVE>(const VkDescriptorSetBindingReferenceVALVE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorSetLayout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.descriptorSetLayout)));
            FieldToString(strStrm, false, "binding", toStringFlags, tabCount, tabSize, ToString(obj.binding, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDescriptorSetLayoutHostMappingInfoVALVE>(const VkDescriptorSetLayoutHostMappingInfoVALVE& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorOffset", toStringFlags, tabCount, tabSize, ToString(obj.descriptorOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorSize", toStringFlags, tabCount, tabSize, ToString(obj.descriptorSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceDepthClampZeroOneFeaturesEXT>(const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthClampZeroOne", toStringFlags, tabCount, tabSize, ToString(obj.depthClampZeroOne, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>(const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "nonSeamlessCubeMap", toStringFlags, tabCount, tabSize, ToString(obj.nonSeamlessCubeMap, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>(const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityMapOffset", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityMapOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>(const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityOffsetGranularity", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityOffsetGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkSubpassFragmentDensityMapOffsetEndInfoQCOM>(const VkSubpassFragmentDensityMapOffsetEndInfoQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fragmentDensityOffsetCount", toStringFlags, tabCount, tabSize, ToString(obj.fragmentDensityOffsetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFragmentDensityOffsets", toStringFlags, tabCount, tabSize, ArrayToString(obj.fragmentDensityOffsetCount, obj.pFragmentDensityOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceLinearColorAttachmentFeaturesNV>(const VkPhysicalDeviceLinearColorAttachmentFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "linearColorAttachment", toStringFlags, tabCount, tabSize, ToString(obj.linearColorAttachment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>(const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageCompressionControlSwapchain", toStringFlags, tabCount, tabSize, ToString(obj.imageCompressionControlSwapchain, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkImageViewSampleWeightCreateInfoQCOM>(const VkImageViewSampleWeightCreateInfoQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterCenter", toStringFlags, tabCount, tabSize, ToString(obj.filterCenter, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filterSize", toStringFlags, tabCount, tabSize, ToString(obj.filterSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "numPhases", toStringFlags, tabCount, tabSize, ToString(obj.numPhases, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageProcessingFeaturesQCOM>(const VkPhysicalDeviceImageProcessingFeaturesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureSampleWeighted", toStringFlags, tabCount, tabSize, ToString(obj.textureSampleWeighted, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureBoxFilter", toStringFlags, tabCount, tabSize, ToString(obj.textureBoxFilter, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "textureBlockMatch", toStringFlags, tabCount, tabSize, ToString(obj.textureBlockMatch, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceImageProcessingPropertiesQCOM>(const VkPhysicalDeviceImageProcessingPropertiesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxWeightFilterPhases", toStringFlags, tabCount, tabSize, ToString(obj.maxWeightFilterPhases, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxWeightFilterDimension", toStringFlags, tabCount, tabSize, ToString(obj.maxWeightFilterDimension, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBlockMatchRegion", toStringFlags, tabCount, tabSize, ToString(obj.maxBlockMatchRegion, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxBoxFilterBlockSize", toStringFlags, tabCount, tabSize, ToString(obj.maxBoxFilterBlockSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>(const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3TessellationDomainOrigin", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3TessellationDomainOrigin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3DepthClampEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3DepthClampEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3PolygonMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3PolygonMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3RasterizationSamples", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3RasterizationSamples, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3SampleMask", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3SampleMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3AlphaToCoverageEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3AlphaToCoverageEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3AlphaToOneEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3AlphaToOneEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3LogicOpEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3LogicOpEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ColorBlendEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ColorBlendEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ColorBlendEquation", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ColorBlendEquation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ColorWriteMask", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ColorWriteMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3RasterizationStream", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3RasterizationStream, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ConservativeRasterizationMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ConservativeRasterizationMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ExtraPrimitiveOverestimationSize", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ExtraPrimitiveOverestimationSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3DepthClipEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3DepthClipEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3SampleLocationsEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3SampleLocationsEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ColorBlendAdvanced", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ColorBlendAdvanced, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ProvokingVertexMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ProvokingVertexMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3LineRasterizationMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3LineRasterizationMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3LineStippleEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3LineStippleEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3DepthClipNegativeOneToOne", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3DepthClipNegativeOneToOne, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ViewportWScalingEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ViewportWScalingEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ViewportSwizzle", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ViewportSwizzle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageToColorEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageToColorEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageToColorLocation", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageToColorLocation, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageModulationMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageModulationMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageModulationTableEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageModulationTableEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageModulationTable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageModulationTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3CoverageReductionMode", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3CoverageReductionMode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3RepresentativeFragmentTestEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3RepresentativeFragmentTestEnable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "extendedDynamicState3ShadingRateImageEnable", toStringFlags, tabCount, tabSize, ToString(obj.extendedDynamicState3ShadingRateImageEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>(const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dynamicPrimitiveTopologyUnrestricted", toStringFlags, tabCount, tabSize, ToString(obj.dynamicPrimitiveTopologyUnrestricted, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkColorBlendEquationEXT>(const VkColorBlendEquationEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "srcColorBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcColorBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstColorBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstColorBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "colorBlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.colorBlendOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "srcAlphaBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.srcAlphaBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstAlphaBlendFactor", toStringFlags, tabCount, tabSize, Quote(ToString(obj.dstAlphaBlendFactor, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "alphaBlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.alphaBlendOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkColorBlendAdvancedEXT>(const VkColorBlendAdvancedEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "advancedBlendOp", toStringFlags, tabCount, tabSize, Quote(ToString(obj.advancedBlendOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "srcPremultiplied", toStringFlags, tabCount, tabSize, ToString(obj.srcPremultiplied, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstPremultiplied", toStringFlags, tabCount, tabSize, ToString(obj.dstPremultiplied, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "blendOverlap", toStringFlags, tabCount, tabSize, Quote(ToString(obj.blendOverlap, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "clampResults", toStringFlags, tabCount, tabSize, ToString(obj.clampResults, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>(const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "subpassMergeFeedback", toStringFlags, tabCount, tabSize, ToString(obj.subpassMergeFeedback, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassCreationControlEXT>(const VkRenderPassCreationControlEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "disallowMerging", toStringFlags, tabCount, tabSize, ToString(obj.disallowMerging, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassCreationFeedbackInfoEXT>(const VkRenderPassCreationFeedbackInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "postMergeSubpassCount", toStringFlags, tabCount, tabSize, ToString(obj.postMergeSubpassCount, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassCreationFeedbackCreateInfoEXT>(const VkRenderPassCreationFeedbackCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRenderPassFeedback", toStringFlags, tabCount, tabSize, (obj.pRenderPassFeedback ? ToString(*obj.pRenderPassFeedback, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkRenderPassSubpassFeedbackInfoEXT>(const VkRenderPassSubpassFeedbackInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "subpassMergeStatus", toStringFlags, tabCount, tabSize, Quote(ToString(obj.subpassMergeStatus, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "description", toStringFlags, tabCount, tabSize, CStrToString(obj.description));
            FieldToString(strStrm, false, "postMergeIndex", toStringFlags, tabCount, tabSize, ToString(obj.postMergeIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRenderPassSubpassFeedbackCreateInfoEXT>(const VkRenderPassSubpassFeedbackCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassFeedback", toStringFlags, tabCount, tabSize, (obj.pSubpassFeedback ? ToString(*obj.pSubpassFeedback, toStringFlags, tabCount, tabSize) : "null"));
        }
    );
}

template <> std::string ToString<VkDirectDriverLoadingInfoLUNARG>(const VkDirectDriverLoadingInfoLUNARG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pfnGetInstanceProcAddr", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pfnGetInstanceProcAddr)));
        }
    );
}

template <> std::string ToString<VkDirectDriverLoadingListLUNARG>(const VkDirectDriverLoadingListLUNARG& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "driverCount", toStringFlags, tabCount, tabSize, ToString(obj.driverCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDrivers", toStringFlags, tabCount, tabSize, ArrayToString(obj.driverCount, obj.pDrivers, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>(const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderModuleIdentifier", toStringFlags, tabCount, tabSize, ToString(obj.shaderModuleIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>(const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderModuleIdentifierAlgorithmUUID", toStringFlags, tabCount, tabSize, Quote(UIDToString(VK_UUID_SIZE, obj.shaderModuleIdentifierAlgorithmUUID)));
        }
    );
}

template <> std::string ToString<VkPipelineShaderStageModuleIdentifierCreateInfoEXT>(const VkPipelineShaderStageModuleIdentifierCreateInfoEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "identifierSize", toStringFlags, tabCount, tabSize, ToString(obj.identifierSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIdentifier", toStringFlags, tabCount, tabSize, ArrayToString(obj.identifierSize, obj.pIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkShaderModuleIdentifierEXT>(const VkShaderModuleIdentifierEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "identifierSize", toStringFlags, tabCount, tabSize, ToString(obj.identifierSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "identifier", toStringFlags, tabCount, tabSize, ArrayToString(VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT, obj.identifier, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceOpticalFlowFeaturesNV>(const VkPhysicalDeviceOpticalFlowFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "opticalFlow", toStringFlags, tabCount, tabSize, ToString(obj.opticalFlow, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceOpticalFlowPropertiesNV>(const VkPhysicalDeviceOpticalFlowPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedOutputGridSizes", toStringFlags, tabCount, tabSize, ToString(obj.supportedOutputGridSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "supportedHintGridSizes", toStringFlags, tabCount, tabSize, ToString(obj.supportedHintGridSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hintSupported", toStringFlags, tabCount, tabSize, ToString(obj.hintSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "costSupported", toStringFlags, tabCount, tabSize, ToString(obj.costSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bidirectionalFlowSupported", toStringFlags, tabCount, tabSize, ToString(obj.bidirectionalFlowSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "globalFlowSupported", toStringFlags, tabCount, tabSize, ToString(obj.globalFlowSupported, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minWidth", toStringFlags, tabCount, tabSize, ToString(obj.minWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minHeight", toStringFlags, tabCount, tabSize, ToString(obj.minHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxWidth", toStringFlags, tabCount, tabSize, ToString(obj.maxWidth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxHeight", toStringFlags, tabCount, tabSize, ToString(obj.maxHeight, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxNumRegionsOfInterest", toStringFlags, tabCount, tabSize, ToString(obj.maxNumRegionsOfInterest, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkOpticalFlowImageFormatInfoNV>(const VkOpticalFlowImageFormatInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(obj.usage, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkOpticalFlowImageFormatPropertiesNV>(const VkOpticalFlowImageFormatPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(obj.format, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkOpticalFlowSessionCreateInfoNV>(const VkOpticalFlowSessionCreateInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.imageFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "flowVectorFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.flowVectorFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "costFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.costFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "outputGridSize", toStringFlags, tabCount, tabSize, ToString(obj.outputGridSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hintGridSize", toStringFlags, tabCount, tabSize, ToString(obj.hintGridSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "performanceLevel", toStringFlags, tabCount, tabSize, Quote(ToString(obj.performanceLevel, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkOpticalFlowSessionCreatePrivateDataInfoNV>(const VkOpticalFlowSessionCreatePrivateDataInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "id", toStringFlags, tabCount, tabSize, ToString(obj.id, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateData", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pPrivateData)));
        }
    );
}

template <> std::string ToString<VkOpticalFlowExecuteInfoNV>(const VkOpticalFlowExecuteInfoNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(obj.regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, ArrayToString(obj.regionCount, obj.pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceLegacyDitheringFeaturesEXT>(const VkPhysicalDeviceLegacyDitheringFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "legacyDithering", toStringFlags, tabCount, tabSize, ToString(obj.legacyDithering, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDevicePipelineProtectedAccessFeaturesEXT>(const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pipelineProtectedAccess", toStringFlags, tabCount, tabSize, ToString(obj.pipelineProtectedAccess, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceTilePropertiesFeaturesQCOM>(const VkPhysicalDeviceTilePropertiesFeaturesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tileProperties", toStringFlags, tabCount, tabSize, ToString(obj.tileProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkTilePropertiesQCOM>(const VkTilePropertiesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tileSize", toStringFlags, tabCount, tabSize, ToString(obj.tileSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "apronSize", toStringFlags, tabCount, tabSize, ToString(obj.apronSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "origin", toStringFlags, tabCount, tabSize, ToString(obj.origin, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceAmigoProfilingFeaturesSEC>(const VkPhysicalDeviceAmigoProfilingFeaturesSEC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "amigoProfiling", toStringFlags, tabCount, tabSize, ToString(obj.amigoProfiling, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAmigoProfilingSubmitInfoSEC>(const VkAmigoProfilingSubmitInfoSEC& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstDrawTimestamp", toStringFlags, tabCount, tabSize, ToString(obj.firstDrawTimestamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "swapBufferTimestamp", toStringFlags, tabCount, tabSize, ToString(obj.swapBufferTimestamp, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>(const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewPerViewViewports", toStringFlags, tabCount, tabSize, ToString(obj.multiviewPerViewViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>(const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingInvocationReorderReorderingHint", toStringFlags, tabCount, tabSize, Quote(ToString(obj.rayTracingInvocationReorderReorderingHint, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>(const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingInvocationReorder", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingInvocationReorder, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>(const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderCoreBuiltins", toStringFlags, tabCount, tabSize, ToString(obj.shaderCoreBuiltins, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>(const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderCoreMask", toStringFlags, tabCount, tabSize, ToString(obj.shaderCoreMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderCoreCount", toStringFlags, tabCount, tabSize, ToString(obj.shaderCoreCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderWarpsPerCore", toStringFlags, tabCount, tabSize, ToString(obj.shaderWarpsPerCore, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureBuildRangeInfoKHR>(const VkAccelerationStructureBuildRangeInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "primitiveCount", toStringFlags, tabCount, tabSize, ToString(obj.primitiveCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveOffset", toStringFlags, tabCount, tabSize, ToString(obj.primitiveOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstVertex", toStringFlags, tabCount, tabSize, ToString(obj.firstVertex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformOffset", toStringFlags, tabCount, tabSize, ToString(obj.transformOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureGeometryTrianglesDataKHR>(const VkAccelerationStructureGeometryTrianglesDataKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexFormat", toStringFlags, tabCount, tabSize, Quote(ToString(obj.vertexFormat, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "vertexData", toStringFlags, tabCount, tabSize, ToString(obj.vertexData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexStride", toStringFlags, tabCount, tabSize, ToString(obj.vertexStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxVertex", toStringFlags, tabCount, tabSize, ToString(obj.maxVertex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.indexType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "indexData", toStringFlags, tabCount, tabSize, ToString(obj.indexData, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "transformData", toStringFlags, tabCount, tabSize, ToString(obj.transformData, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureGeometryAabbsDataKHR>(const VkAccelerationStructureGeometryAabbsDataKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(obj.data, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureGeometryInstancesDataKHR>(const VkAccelerationStructureGeometryInstancesDataKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "arrayOfPointers", toStringFlags, tabCount, tabSize, ToString(obj.arrayOfPointers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(obj.data, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureCreateInfoKHR>(const VkAccelerationStructureCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "createFlags", toStringFlags, tabCount, tabSize, ToString(obj.createFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.buffer)));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(obj.offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "deviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.deviceAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkWriteDescriptorSetAccelerationStructureKHR>(const VkWriteDescriptorSetAccelerationStructureKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.accelerationStructureCount, obj.pAccelerationStructures, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceAccelerationStructureFeaturesKHR>(const VkPhysicalDeviceAccelerationStructureFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructure, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureIndirectBuild", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureIndirectBuild, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureHostCommands", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureHostCommands, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorBindingAccelerationStructureUpdateAfterBind", toStringFlags, tabCount, tabSize, ToString(obj.descriptorBindingAccelerationStructureUpdateAfterBind, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceAccelerationStructurePropertiesKHR>(const VkPhysicalDeviceAccelerationStructurePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxGeometryCount", toStringFlags, tabCount, tabSize, ToString(obj.maxGeometryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxInstanceCount", toStringFlags, tabCount, tabSize, ToString(obj.maxInstanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPrimitiveCount", toStringFlags, tabCount, tabSize, ToString(obj.maxPrimitiveCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorAccelerationStructures", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPerStageDescriptorUpdateAfterBindAccelerationStructures", toStringFlags, tabCount, tabSize, ToString(obj.maxPerStageDescriptorUpdateAfterBindAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetAccelerationStructures", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDescriptorSetUpdateAfterBindAccelerationStructures", toStringFlags, tabCount, tabSize, ToString(obj.maxDescriptorSetUpdateAfterBindAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "minAccelerationStructureScratchOffsetAlignment", toStringFlags, tabCount, tabSize, ToString(obj.minAccelerationStructureScratchOffsetAlignment, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureDeviceAddressInfoKHR>(const VkAccelerationStructureDeviceAddressInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.accelerationStructure)));
        }
    );
}

template <> std::string ToString<VkCopyAccelerationStructureToMemoryInfoKHR>(const VkCopyAccelerationStructureToMemoryInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.src)));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, ToString(obj.dst, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkCopyMemoryToAccelerationStructureInfoKHR>(const VkCopyMemoryToAccelerationStructureInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, ToString(obj.src, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dst)));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkCopyAccelerationStructureInfoKHR>(const VkCopyAccelerationStructureInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.src)));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.dst)));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(obj.mode, toStringFlags, tabCount, tabSize)));
        }
    );
}

template <> std::string ToString<VkAccelerationStructureBuildSizesInfoKHR>(const VkAccelerationStructureBuildSizesInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "accelerationStructureSize", toStringFlags, tabCount, tabSize, ToString(obj.accelerationStructureSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "updateScratchSize", toStringFlags, tabCount, tabSize, ToString(obj.updateScratchSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "buildScratchSize", toStringFlags, tabCount, tabSize, ToString(obj.buildScratchSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRayTracingShaderGroupCreateInfoKHR>(const VkRayTracingShaderGroupCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(obj.type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "generalShader", toStringFlags, tabCount, tabSize, ToString(obj.generalShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "closestHitShader", toStringFlags, tabCount, tabSize, ToString(obj.closestHitShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "anyHitShader", toStringFlags, tabCount, tabSize, ToString(obj.anyHitShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "intersectionShader", toStringFlags, tabCount, tabSize, ToString(obj.intersectionShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShaderGroupCaptureReplayHandle", toStringFlags, tabCount, tabSize, Quote(PtrToString(obj.pShaderGroupCaptureReplayHandle)));
        }
    );
}

template <> std::string ToString<VkRayTracingPipelineInterfaceCreateInfoKHR>(const VkRayTracingPipelineInterfaceCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPipelineRayPayloadSize", toStringFlags, tabCount, tabSize, ToString(obj.maxPipelineRayPayloadSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPipelineRayHitAttributeSize", toStringFlags, tabCount, tabSize, ToString(obj.maxPipelineRayHitAttributeSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkRayTracingPipelineCreateInfoKHR>(const VkRayTracingPipelineCreateInfoKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stageCount", toStringFlags, tabCount, tabSize, ToString(obj.stageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStages", toStringFlags, tabCount, tabSize, ArrayToString(obj.stageCount, obj.pStages, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(obj.groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGroups", toStringFlags, tabCount, tabSize, ArrayToString(obj.groupCount, obj.pGroups, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPipelineRayRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxPipelineRayRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLibraryInfo", toStringFlags, tabCount, tabSize, (obj.pLibraryInfo ? ToString(*obj.pLibraryInfo, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pLibraryInterface", toStringFlags, tabCount, tabSize, (obj.pLibraryInterface ? ToString(*obj.pLibraryInterface, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "pDynamicState", toStringFlags, tabCount, tabSize, (obj.pDynamicState ? ToString(*obj.pDynamicState, toStringFlags, tabCount, tabSize) : "null"));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.layout)));
            FieldToString(strStrm, false, "basePipelineHandle", toStringFlags, tabCount, tabSize, Quote(VkHandleToString(obj.basePipelineHandle)));
            FieldToString(strStrm, false, "basePipelineIndex", toStringFlags, tabCount, tabSize, ToString(obj.basePipelineIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingPipelineFeaturesKHR>(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingPipeline", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingPipeline, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingPipelineShaderGroupHandleCaptureReplay", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingPipelineShaderGroupHandleCaptureReplay, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingPipelineShaderGroupHandleCaptureReplayMixed", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingPipelineShaderGroupHandleCaptureReplayMixed, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTracingPipelineTraceRaysIndirect", toStringFlags, tabCount, tabSize, ToString(obj.rayTracingPipelineTraceRaysIndirect, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayTraversalPrimitiveCulling", toStringFlags, tabCount, tabSize, ToString(obj.rayTraversalPrimitiveCulling, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>(const VkPhysicalDeviceRayTracingPipelinePropertiesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupHandleSize", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupHandleSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxRayRecursionDepth", toStringFlags, tabCount, tabSize, ToString(obj.maxRayRecursionDepth, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxShaderGroupStride", toStringFlags, tabCount, tabSize, ToString(obj.maxShaderGroupStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupBaseAlignment", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupBaseAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupHandleCaptureReplaySize", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupHandleCaptureReplaySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxRayDispatchInvocationCount", toStringFlags, tabCount, tabSize, ToString(obj.maxRayDispatchInvocationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "shaderGroupHandleAlignment", toStringFlags, tabCount, tabSize, ToString(obj.shaderGroupHandleAlignment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxRayHitAttributeSize", toStringFlags, tabCount, tabSize, ToString(obj.maxRayHitAttributeSize, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkStridedDeviceAddressRegionKHR>(const VkStridedDeviceAddressRegionKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "deviceAddress", toStringFlags, tabCount, tabSize, ToString(obj.deviceAddress, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(obj.stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(obj.size, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkTraceRaysIndirectCommandKHR>(const VkTraceRaysIndirectCommandKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depth", toStringFlags, tabCount, tabSize, ToString(obj.depth, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceRayQueryFeaturesKHR>(const VkPhysicalDeviceRayQueryFeaturesKHR& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rayQuery", toStringFlags, tabCount, tabSize, ToString(obj.rayQuery, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMeshShaderFeaturesEXT>(const VkPhysicalDeviceMeshShaderFeaturesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "taskShader", toStringFlags, tabCount, tabSize, ToString(obj.taskShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshShader", toStringFlags, tabCount, tabSize, ToString(obj.meshShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "multiviewMeshShader", toStringFlags, tabCount, tabSize, ToString(obj.multiviewMeshShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "primitiveFragmentShadingRateMeshShader", toStringFlags, tabCount, tabSize, ToString(obj.primitiveFragmentShadingRateMeshShader, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshShaderQueries", toStringFlags, tabCount, tabSize, ToString(obj.meshShaderQueries, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkPhysicalDeviceMeshShaderPropertiesEXT>(const VkPhysicalDeviceMeshShaderPropertiesEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, Quote(ToString(obj.sType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupTotalCount", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskWorkGroupTotalCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupCount", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxTaskWorkGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxTaskWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskPayloadSize", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskPayloadSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskSharedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskSharedMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxTaskPayloadAndSharedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxTaskPayloadAndSharedMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupTotalCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshWorkGroupTotalCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupCount", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxMeshWorkGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshWorkGroupSize", toStringFlags, tabCount, tabSize, ArrayToString(3, obj.maxMeshWorkGroupSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshSharedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshSharedMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshPayloadAndSharedMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshPayloadAndSharedMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshPayloadAndOutputMemorySize", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshPayloadAndOutputMemorySize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputComponents", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputComponents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputVertices", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputVertices, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputPrimitives", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputPrimitives, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshOutputLayers", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshOutputLayers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxMeshMultiviewViewCount", toStringFlags, tabCount, tabSize, ToString(obj.maxMeshMultiviewViewCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshOutputPerVertexGranularity", toStringFlags, tabCount, tabSize, ToString(obj.meshOutputPerVertexGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "meshOutputPerPrimitiveGranularity", toStringFlags, tabCount, tabSize, ToString(obj.meshOutputPerPrimitiveGranularity, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPreferredTaskWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxPreferredTaskWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxPreferredMeshWorkGroupInvocations", toStringFlags, tabCount, tabSize, ToString(obj.maxPreferredMeshWorkGroupInvocations, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "prefersLocalInvocationVertexOutput", toStringFlags, tabCount, tabSize, ToString(obj.prefersLocalInvocationVertexOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "prefersLocalInvocationPrimitiveOutput", toStringFlags, tabCount, tabSize, ToString(obj.prefersLocalInvocationPrimitiveOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "prefersCompactVertexOutput", toStringFlags, tabCount, tabSize, ToString(obj.prefersCompactVertexOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "prefersCompactPrimitiveOutput", toStringFlags, tabCount, tabSize, ToString(obj.prefersCompactPrimitiveOutput, toStringFlags, tabCount, tabSize));
        }
    );
}

template <> std::string ToString<VkDrawMeshTasksIndirectCommandEXT>(const VkDrawMeshTasksIndirectCommandEXT& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "groupCountX", toStringFlags, tabCount, tabSize, ToString(obj.groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(obj.groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(obj.groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
