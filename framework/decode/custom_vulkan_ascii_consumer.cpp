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

#include "decode/custom_vulkan_ascii_consumer.h"
#include "generated/generated_vulkan_ascii_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanAsciiConsumer::Process_vkAllocateCommandBuffers(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    VulkanAsciiConsumerBase::Process_vkAllocateCommandBuffers(returnValue, device, pAllocateInfo, pCommandBuffers);
}

void VulkanAsciiConsumer::Process_vkAllocateDescriptorSets(
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    VulkanAsciiConsumerBase::Process_vkAllocateDescriptorSets(returnValue, device, pAllocateInfo, pDescriptorSets);
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    format::HandleId                                                           commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*                                           pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                                                  pIndirectStrides,
    PointerDecoder<uint32_t*>*                                                 ppMaxPrimitiveCounts)
{
    VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    format::HandleId                                                           commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos)
{
    VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresKHR(
        commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    format::HandleId                                                           device,
    VkAccelerationStructureBuildTypeKHR                                        buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                                                  pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>*    pSizeInfo)
{
    VulkanAsciiConsumerBase::Process_vkGetAccelerationStructureBuildSizesKHR(
        device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
