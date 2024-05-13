/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VULKAN_DETECTION_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_DETECTION_CONSUMER_H

#include "decode/vulkan_consumer_base.h"
#include "util/defines.h"
#include "generated/generated_vulkan_consumer.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDetectionConsumer : public VulkanConsumer
{
  public:
    static const uint64_t kDefaultBlockLimit = 1000;
    static const uint64_t kNoBlockLimit      = 0;

    VulkanDetectionConsumer(uint64_t block_limit = kDefaultBlockLimit) :
        block_limit_(block_limit), vulkan_consumer_usage_(false)
    {}
    bool         WasVulkanAPIDetected() { return vulkan_consumer_usage_; }
    virtual void Process_vkCreateDevice(const ApiCallInfo&         call_info,
                                        VkResult                   returnValue,
                                        gfxrecon::format::HandleId physicalDevice,
                                        StructPointerDecoder<Decoded_VkDeviceCreateInfo>*,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*,
                                        HandlePointerDecoder<VkDevice>*) override
    {
        vulkan_consumer_usage_ = true;
    }
    virtual bool IsComplete(uint64_t block_index) override
    {
        return ((block_limit_ != kNoBlockLimit) && (block_index > block_limit_)) || WasVulkanAPIDetected();
    }

  private:
    const uint64_t block_limit_;
    bool           vulkan_consumer_usage_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DETECTION_CONSUMER_H
