/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc
**
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECONSTRUCT_VULKAN_CPP_PRE_PROCESS_CONSUMER_BASE_H
#define GFXRECONSTRUCT_VULKAN_CPP_PRE_PROCESS_CONSUMER_BASE_H

#include <generated/generated_vulkan_consumer.h>
#include "decode/file_processor.h"
#include "format/platform_types.h"

#include "util/defines.h"
#include "vulkan/vulkan.h"
#include "vulkan_cpp_utilities.h"
#include "vulkan_cpp_resource_tracker.h"

#include <map>
#include <unordered_set>
#include <queue>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanCppPreProcessConsumerBase : public VulkanConsumer
{
  public:
    VulkanCppPreProcessConsumerBase();

    virtual ~VulkanCppPreProcessConsumerBase() override;

    bool Initialize();

    void SetMaxCommandLimit(uint32_t max) { max_command_limit_ = max; }

    void AddResourceTracker(VulkanCppResourceTracker& resourceTracker) { resource_tracker_ = &resourceTracker; };

    uint32_t GetCaptureWindowWidth() { return capture_window_width_; }
    uint32_t GetCaptureWindowHeight() { return capture_window_height_; }
    uint32_t GetCurrentFrameNumber() { return frame_number_; }
    uint32_t GetCurrentApiCallNumber() { return api_call_number_; }

    std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>>& GetMemoryImageMappings()
    {
        return memory_resource_map_;
    }

    void Intercept_vkCreateSwapchainKHR(VkResult                                                returnValue,
                                        format::HandleId                                        device,
                                        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchain);

    void Intercept_vkBindImageMemory(VkResult         returnValue,
                                     format::HandleId device,
                                     format::HandleId image,
                                     format::HandleId memory,
                                     VkDeviceSize     memoryOffset);

    void Intercept_vkBindImageMemory2(VkResult                                             returnValue,
                                      format::HandleId                                     device,
                                      uint32_t                                             bindInfoCount,
                                      StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos);

    void Intercept_vkBindImageMemory2KHR(VkResult                                             returnValue,
                                         format::HandleId                                     device,
                                         uint32_t                                             bindInfoCount,
                                         StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
    {
        Intercept_vkBindImageMemory2(returnValue, device, bindInfoCount, pBindInfos);
    }

    void Intercept_vkBindBufferMemory(VkResult         returnValue,
                                      format::HandleId device,
                                      format::HandleId buffer,
                                      format::HandleId memory,
                                      VkDeviceSize     memoryOffset);

    void Intercept_vkBindBufferMemory2(VkResult                                              returnValue,
                                       format::HandleId                                      device,
                                       uint32_t                                              bindInfoCount,
                                       StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos);

    void Intercept_vkBindBufferMemory2KHR(VkResult                                              returnValue,
                                          format::HandleId                                      device,
                                          uint32_t                                              bindInfoCount,
                                          StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
    {
        Intercept_vkBindBufferMemory2(returnValue, device, bindInfoCount, pBindInfos);
    }

    void AddHandles_vkEnumeratePhysicalDevices(VkResult                                returnValue,
                                               format::HandleId                        instance,
                                               PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                               HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices);

    void AddHandles_vkUpdateDescriptorSets(format::HandleId                                    device,
                                           uint32_t                                            descriptorWriteCount,
                                           StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                           uint32_t                                            descriptorCopyCount,
                                           StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies);

    void AddHandles_vkUpdateDescriptorSetWithTemplate(format::HandleId                 device,
                                                      format::HandleId                 descriptorSet,
                                                      format::HandleId                 descriptorUpdateTemplate,
                                                      DescriptorUpdateTemplateDecoder* pData);

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

    // Meta data commands
    virtual void ProcessDisplayMessageCommand(const std::string& message) override;

  protected:
    void     Post_APICall(format::ApiCallId callId);
    uint32_t GetCurrentFrameSplitNumber() { return frame_split_number_; }

    VulkanCppResourceTracker* resource_tracker_;
    uint32_t                  max_command_limit_{ 1000 };

    // VkDeviceMemory -> VkImage | VkBuffer
    std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>> memory_resource_map_;

  private:
    uint32_t capture_window_width_;
    uint32_t capture_window_height_;
    uint32_t frame_number_;
    uint32_t frame_split_number_;
    uint32_t frame_api_call_number_;
    uint32_t api_call_number_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
