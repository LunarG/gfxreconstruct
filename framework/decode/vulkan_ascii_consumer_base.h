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

    /// @brief  Initialize the consumer for writing to the file passed in.
    /// @param file A file to output to. The caller retains ownership. Do not close this.
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
    inline void WriteApiCallToFile(const ApiCallInfo& call_info,
                                   const std::string& functionName,
                                   /// @todo Remove toStringFlags, tabCount, tabSize
                                   util::ToStringFlags        toStringFlags,
                                   const uint32_t&            tabCount,
                                   const uint32_t             tabSize,
                                   const ToStringFunctionType toStringFunction,
                                   /// The formatted return string value excluding trailing comma
                                   const char* const return_val = nullptr)
    {
        // Output the start of a function call line, up to the arguments:
        if (nullptr == return_val)
        {
            fprintf(file_,
                    "{\"index\":%llu,\"vkFunc\":{\"name\":\"%s\",\"args\":{",
                    (long long unsigned int)call_info.index,
                    functionName.c_str());
        }
        else
        {
            fprintf(file_,
                    "{\"index\":%llu,\"vkFunc\":{\"name\":\"%s\",\"return\":%s,\"args\":{",
                    (long long unsigned int)call_info.index,
                    functionName.c_str(),
                    return_val);
        }

        // Reset the per-call reusable stringstream and use it to capture the full tree of
        // the function arguments including pNexts and struct pointers:
        strStrm_.str(std::string{});
        toStringFunction(strStrm_);

        // Dump the captured argument string into the file and close the argument,
        // nested, and top-level braces:
        fputs(strStrm_.str().c_str(), file_);
        fputs("}}}\n", file_);

        // Push out the whole line to the next tool in any pipeline we may be chained
        // into so it can start processing it or to file:
        fflush(file_);
    }

  private:
    FILE* file_{ nullptr };
    /// Reusable string stream for formatting top-level objects like vkFuncs into.
    std::stringstream strStrm_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ASCII_CONSUMER_BASE_H
