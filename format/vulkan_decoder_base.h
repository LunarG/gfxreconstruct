/*
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

#ifndef BRIMSTONE_VULKAN_DECODER_BASE_H
#define BRIMSTONE_VULKAN_DECODER_BASE_H

#include <algorithm>
#include <vector>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/decoder.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class VulkanDecoderBase : public Decoder
{
public:
    VulkanDecoderBase() { }

    virtual ~VulkanDecoderBase() { }

    void AddConsumer(VulkanConsumer* consumer) { consumers_.push_back(consumer); }

    void RemoveConsumer(VulkanConsumer* consumer) { consumers_.erase(std::remove(consumers_.begin(), consumers_.end(), consumer)); }

    virtual bool SupportsApiCall(ApiCallId call_id) override { return ((call_id >= 0x1000) && (call_id <= 0x112b)) ? true : false; }

    virtual void DecodeFunctionCall(ApiCallId             call_id,
                                    const ApiCallOptions& call_options,
                                    const uint8_t*        parameter_buffer,
                                    size_t                buffer_size) override;

    virtual void DispatchDisplayMessageCommand(const std::string& message) override;

    virtual void
    DispatchFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height) override;

protected:
    const std::vector<VulkanConsumer*>& GetConsumers() const { return consumers_; }

private:
    size_t Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_vkRegisterObjectsNVX(const uint8_t* parameter_buffer, size_t buffer_size);

private:
    std::vector<VulkanConsumer*>        consumers_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_VULKAN_DECODER_BASE_H
