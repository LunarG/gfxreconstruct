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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_COMMAND_BUFFER_BASE_H
#define GFXRECON_DECODE_VULKAN_STAGE_COMMAND_BUFFER_BASE_H

#include "generated/generated_vulkan_consumer_stage.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanStageCommandBufferBase : public VulkanConsumerStage
{
  public:
    virtual void OnCommand(const ApiCallInfo& call_info, format::HandleId& command_buffer) {}

    template <typename ArgsT>
    void ProcessCommand(const ApiCallInfo& call_info, ArgsT& args)
    {
        OnCommand(call_info, args.commandBuffer);
        Forward(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate(const ApiCallInfo&                      call_info,
                                                    args::CmdPushDescriptorSetWithTemplate& args) override
    {
        ProcessCommand(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo&                         call_info,
                                                       args::CmdPushDescriptorSetWithTemplateKHR& args) override
    {
        ProcessCommand(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2(const ApiCallInfo&                       call_info,
                                                     args::CmdPushDescriptorSetWithTemplate2& args) override
    {
        ProcessCommand(call_info, args);
    }

    void Process_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo&                          call_info,
                                                        args::CmdPushDescriptorSetWithTemplate2KHR& args) override
    {
        ProcessCommand(call_info, args);
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_COMMAND_BUFFER_BASE_H
