/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_DECODER_BASE_H
#define GFXRECON_DECODE_VULKAN_DECODER_BASE_H

#include "decode/api_decoder.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDecoderBase : public ApiDecoder
{
  public:
    VulkanDecoderBase() {}

    virtual ~VulkanDecoderBase() override {}

    void AddConsumer(VulkanConsumer* consumer) { consumers_.push_back(consumer); }

    void RemoveConsumer(VulkanConsumer* consumer)
    {
        consumers_.erase(std::remove(consumers_.begin(), consumers_.end(), consumer));
    }

    virtual bool SupportsApiCall(format::ApiCallId call_id) override
    {
        return ((call_id >= format::ApiCallId::ApiCall_vkCreateInstance) &&
                (call_id < format::ApiCallId::ApiCall_VulkanLast));
    }

    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override;

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) override;

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height) override;

    virtual void
    DispatchSetSwapchainImageStateCommand(format::ThreadId                                     thread_id,
                                          format::HandleId                                     device_id,
                                          format::HandleId                                     swapchain_id,
                                          uint32_t                                             queue_family_index,
                                          const std::vector<format::SwapchainImageStateEntry>& image_state) override;

  protected:
    const std::vector<VulkanConsumer*>& GetConsumers() const { return consumers_; }

  private:
    size_t Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterObjectsNVX(const uint8_t* parameter_buffer, size_t buffer_size);

  private:
    std::vector<VulkanConsumer*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODER_BASE_H
