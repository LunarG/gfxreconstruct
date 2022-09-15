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

#ifndef GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H
#define GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H

#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"

#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanAsciiConsumerBase : public VulkanConsumer
{
  public:
    VulkanAsciiConsumerBase();

    virtual ~VulkanAsciiConsumerBase() override;

    void Initialize(FILE* file);

    void Destroy();

    bool IsValid() const { return (file_ != nullptr); }

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                                                         call_info,
        format::HandleId                                                           commandBuffer,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        PointerDecoder<VkDeviceAddress>*                                           pIndirectDeviceAddresses,
        PointerDecoder<uint32_t>*                                                  pIndirectStrides,
        PointerDecoder<uint32_t*>*                                                 ppMaxPrimitiveCounts) override;

    virtual void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                                                         call_info,
        format::HandleId                                                           commandBuffer,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos) override;

    virtual void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                               format::HandleId   commandBuffer,
                                                               format::HandleId   descriptorUpdateTemplate,
                                                               format::HandleId   layout,
                                                               uint32_t           set,
                                                               DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkGetAccelerationStructureBuildSizesKHR(
        const ApiCallInfo&                                                         call_info,
        format::HandleId                                                           device,
        VkAccelerationStructureBuildTypeKHR                                        buildType,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
        PointerDecoder<uint32_t>*                                                  pMaxPrimitiveCounts,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>*    pSizeInfo) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&               call_info,
                                                           format::HandleId                 device,
                                                           format::HandleId                 descriptorSet,
                                                           format::HandleId                 descriptorUpdateTemplate,
                                                           DescriptorUpdateTemplateDecoder* pData) override;

    virtual void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&               call_info,
                                                              format::HandleId                 device,
                                                              format::HandleId                 descriptorSet,
                                                              format::HandleId                 descriptorUpdateTemplate,
                                                              DescriptorUpdateTemplateDecoder* pData) override;

  protected:
    template <typename ToStringFunctionType>
    inline void WriteApiCallToFile(util::ToStringFlags  toStringFlags,
                                   uint32_t&            tabCount,
                                   uint32_t             tabSize,
                                   ToStringFunctionType toStringFunction)
    {
        using namespace util;
        fprintf(file_, "%s\n", ObjectToString(toStringFlags, tabCount, tabSize, toStringFunction).c_str());
    }

  private:
    FILE* file_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H
