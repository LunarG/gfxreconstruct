/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_CONSUMER_STAGE_BASE_H
#define GFXRECON_DECODE_VULKAN_CONSUMER_STAGE_BASE_H

#include <vector>

#include "util/defines.h"
#include "generated/generated_vulkan_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanConsumerStageBase : public VulkanConsumer
{
  public:
    void AddNext(VulkanConsumer* next) { next_consumers_.push_back(next); }

    void Process_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo&                     call_info,
                                                   args::UpdateDescriptorSetWithTemplate& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate(const ApiCallInfo&                      call_info,
                                                    args::CmdPushDescriptorSetWithTemplate& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&                         call_info,
                                                       args::CmdPushDescriptorSetWithTemplateKHR& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo&                        call_info,
                                                      args::UpdateDescriptorSetWithTemplateKHR& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2(const ApiCallInfo&                       call_info,
                                                     args::CmdPushDescriptorSetWithTemplate2& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo&                          call_info,
                                                        args::CmdPushDescriptorSetWithTemplate2KHR& args) override
    {
        Forward(call_info, args);
    }

    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo&                  call_info,
                                                args::CreateRayTracingPipelinesKHR& args) override
    {
        Forward(call_info, args);
    }

    void ProcessSetTlasToBlasRelationCommand(format::HandleId                     tlas,
                                             const std::vector<format::HandleId>& blases) override
    {
        Broadcast(&VulkanConsumer::ProcessSetTlasToBlasRelationCommand, tlas, blases);
    }

    void StartLooping() override { Broadcast(&VulkanConsumer::StartLooping); }

  protected:
    std::vector<VulkanConsumer*>& GetNextConsumers() { return next_consumers_; }

    template <typename ArgsT>
    void Forward(const ApiCallInfo& call_info, ArgsT& args)
    {
        for (auto next : next_consumers_)
        {
            next->Process(call_info, args);
        }
    }

    template <typename Method, typename... Args>
    void Broadcast(Method method, const Args&... args)
    {
        for (auto next : next_consumers_)
        {
            (next->*method)(args...);
        }
    }

  private:
    std::vector<VulkanConsumer*> next_consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CONSUMER_STAGE_BASE_H