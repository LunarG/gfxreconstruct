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

/// @note A manual template for the code to be generated:
/*template <> std::string gfxrecon::util::ToString<gfxrecon::decode::Decoded_VkFramebufferCreateInfo>(const gfxrecon::decode::Decoded_VkFramebufferCreateInfo& metaObj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
// <---------------------------------------------------------------------------------------------------------------------------------------------------[BOOKMARK]
{
    //return "gfxrecon::decode::Decoded_VkFramebufferCreateInfo";
    return ObjectToString(toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            assert(metaObj.decoded_value);
            VkFramebufferCreateInfo& obj = *metaObj.decoded_value;
            FieldToString(strStrm, true, "sType", toStringFlags, tabCount, tabSize, '"' + ToString(obj.sType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pNext", toStringFlags, tabCount, tabSize, PNextToString(obj.pNext, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(obj.flags, toStringFlags, tabCount, tabSize));
            // NULL: FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, '"' + VkHandleToString(obj.renderPass) + '"');
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, '"' + ToString(metaObj.renderPass) + '"');
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(obj.attachmentCount, toStringFlags, tabCount, tabSize));
            // EMPTY ARRAY: FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, VkHandleArrayToString(obj.attachmentCount, obj.pAttachments, toStringFlags, tabCount, tabSize));
            assert(metaObj.pAttachments.GetLength() == obj.attachmentCount);
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, VkHandleArrayToString(metaObj.pAttachments.GetLength(), metaObj.pAttachments.GetPointer(), toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(obj.width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(obj.height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "layers", toStringFlags, tabCount, tabSize, ToString(obj.layers, toStringFlags, tabCount, tabSize));
        }
    );
}*/

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanAsciiConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    VulkanAsciiConsumerBase::Process_vkAllocateCommandBuffers(
        call_info, returnValue, device, pAllocateInfo, pCommandBuffers);
}

void VulkanAsciiConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    VulkanAsciiConsumerBase::Process_vkAllocateDescriptorSets(
        call_info, returnValue, device, pAllocateInfo, pDescriptorSets);
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                                                         call_info,
    format::HandleId                                                           commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*                                           pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                                                  pIndirectStrides,
    PointerDecoder<uint32_t*>*                                                 ppMaxPrimitiveCounts)
{
    VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        call_info, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                                                         call_info,
    format::HandleId                                                           commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos)
{
    VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresKHR(
        call_info, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                                                         call_info,
    format::HandleId                                                           device,
    VkAccelerationStructureBuildTypeKHR                                        buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                                                  pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>*    pSizeInfo)
{
    VulkanAsciiConsumerBase::Process_vkGetAccelerationStructureBuildSizesKHR(
        call_info, device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
