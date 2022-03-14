/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "decode/vulkan_ascii_consumer_base.h"
#include "decode/custom_vulkan_ascii_consumer.h"
#include "generated/generated_vulkan_ascii_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanAsciiConsumerBase::VulkanAsciiConsumerBase() : file_(nullptr) {}

VulkanAsciiConsumerBase::~VulkanAsciiConsumerBase()
{
    Destroy();
}

void VulkanAsciiConsumerBase::Initialize(FILE* file, gfxrecon::util::ToStringFlags toStringFlags)
{
    // TODO : The formatting logic for Vulkan and D3D12 need a separate PR to refactor them together...
    GFXRECON_UNREFERENCED_PARAMETER(toStringFlags);
    assert(file);
    file_ = file;
    fprintf(file_, "{");
}

void VulkanAsciiConsumerBase::Destroy()
{
    if (file_ != nullptr)
    {
        fprintf(file_, "\n}\n");
        file_ = nullptr;
    }
}

// clang-format off

// NOTE : The following functions' Process_ functions aren't generated due
//  to various reasons...non standard counts for arrays, arguments that need
//  validation to interpret correctly, etc...

void VulkanAsciiConsumerBase::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                                         call_info,
    VkResult returnValue,
    format::HandleId device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAllocateCommandBuffers", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocateInfo, toStringFlags, tabCount, tabSize));
            auto pDecodedAllocateInfo = pAllocateInfo ? pAllocateInfo->GetPointer() : nullptr;
            auto commandBufferCount = pDecodedAllocateInfo ? pDecodedAllocateInfo->commandBufferCount : 0;
            FieldToString(strStrm, false, "[out]pCommandBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(commandBufferCount, pCommandBuffers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult returnValue,
    format::HandleId device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAllocateDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocateInfo, toStringFlags, tabCount, tabSize));
            auto pDecodedAllocateInfo = pAllocateInfo ? pAllocateInfo->GetPointer() : nullptr;
            auto descriptorSetCount = pDecodedAllocateInfo ? pDecodedAllocateInfo->descriptorSetCount : 0;
            FieldToString(strStrm, false, "[out]pDescriptorSets", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(descriptorSetCount, pDescriptorSets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo& call_info,
    format::HandleId commandBuffer,
    uint32_t infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>* pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>* pIndirectStrides,
    PointerDecoder<uint32_t*>* ppMaxPrimitiveCounts
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresIndirectKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "infoCount", toStringFlags, tabCount, tabSize, ToString(infoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(infoCount, pInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndirectDeviceAddresses", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(infoCount, pIndirectDeviceAddresses, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndirectStrides", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(infoCount, pIndirectStrides, toStringFlags, tabCount, tabSize));
            auto pDecodedInfos = pInfos ? pInfos->GetPointer() : nullptr;
            auto ppDecodedMaxPrimitiveCounts = ppMaxPrimitiveCounts ? ppMaxPrimitiveCounts->GetPointer() : nullptr;
            FieldToString(strStrm, false, "ppMaxPrimitiveCounts", toStringFlags, tabCount, tabSize,
                ArrayToString(infoCount, pInfos, toStringFlags, tabCount++, tabSize,
                    [&]()
                    {
                        return infoCount && pDecodedInfos && ppDecodedMaxPrimitiveCounts;
                    },
                    [&](uint32_t info_i)
                    {
                        return ArrayToString(pDecodedInfos[info_i].geometryCount, ppDecodedMaxPrimitiveCounts[info_i], toStringFlags, tabCount--, tabSize);
                    }
                )
            );
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo& call_info,
    format::HandleId commandBuffer,
    uint32_t infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "infoCount", toStringFlags, tabCount, tabSize, ToString(infoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(infoCount, pInfos, toStringFlags, tabCount, tabSize));
            auto pDecodedInfos = pInfos ? pInfos->GetPointer() : nullptr;
            auto ppDecodedBuildRangeInfos = ppBuildRangeInfos ? ppBuildRangeInfos->GetPointer() : nullptr;
            FieldToString(strStrm, false, "ppBuildRangeInfos", toStringFlags, tabCount, tabSize,
                ArrayToString(infoCount, pInfos, toStringFlags, tabCount++, tabSize,
                    [&]()
                    {
                        return infoCount && pDecodedInfos && ppDecodedBuildRangeInfos;
                    },
                    [&](uint32_t info_i)
                    {
                        return ArrayToString(pDecodedInfos[info_i].geometryCount, ppDecodedBuildRangeInfos[info_i], toStringFlags, tabCount--, tabSize);
                    }
                )
            );
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo& call_info,
    format::HandleId device,
    VkAccelerationStructureBuildTypeKHR buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>* pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureBuildSizesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buildType", toStringFlags, tabCount, tabSize, '"' + ToString(buildType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pBuildInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBuildInfo, toStringFlags, tabCount, tabSize));
            auto pDecodedBuildInfo = pBuildInfo ? pBuildInfo->GetPointer() : nullptr;
            auto geometryCount = pDecodedBuildInfo ? pDecodedBuildInfo->geometryCount : 0;
            auto pDecodedMaxPrimitiveCounts = pMaxPrimitiveCounts ? pMaxPrimitiveCounts->GetPointer() : nullptr;
            FieldToString(strStrm, false, "pMaxPrimitiveCounts", toStringFlags, tabCount, tabSize, ArrayToString(geometryCount, pDecodedMaxPrimitiveCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSizeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSizeInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo& call_info,
    format::HandleId commandBuffer,
    format::HandleId descriptorUpdateTemplate,
    format::HandleId layout,
    uint32_t set,
    DescriptorUpdateTemplateDecoder* pData
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdPushDescriptorSetWithTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, HandleIdToString(layout));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DescriptorUpdateTemplateDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkUpdateDescriptorSetWithTemplate(
    const ApiCallInfo& call_info,
    format::HandleId device,
    format::HandleId descriptorSet,
    format::HandleId descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkUpdateDescriptorSetWithTemplate", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSet", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSet));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DescriptorUpdateTemplateDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumerBase::Process_vkUpdateDescriptorSetWithTemplateKHR(
    const ApiCallInfo& call_info,
    format::HandleId device,
    format::HandleId descriptorSet,
    format::HandleId descriptorUpdateTemplate,
    DescriptorUpdateTemplateDecoder* pData
)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkUpdateDescriptorSetWithTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSet", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSet));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DescriptorUpdateTemplateDecoderToString(pData));
        }
    );
}

// clang-format on

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
