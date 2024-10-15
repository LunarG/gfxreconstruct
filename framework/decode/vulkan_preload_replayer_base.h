/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_DECODE_VULKAN_PRELOAD_REPLAYER_BASE_H
#define GFXRECON_DECODE_VULKAN_PRELOAD_REPLAYER_BASE_H

#include "vulkan_struct_packet.h"
#include "generated/generated_vulkan_consumer.h"
#include "generated/generated_vulkan_struct_packet.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_preload_decoder.h"

#include "format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanPreloadReplayerBase
{
  public:
    VulkanPreloadReplayerBase();
    virtual ~VulkanPreloadReplayerBase();
    bool ReplayPackets(VulkanPreloadDecoder* vulkan_preload_decoder);

    virtual void ReplayFunctionCall(format::PacketCallId& packet_call_id, void* packet);

    void AddConsumer(VulkanReplayConsumer* consumer) { vulkan_replay_consumer_ = consumer; }

    virtual void Replay_DispatchFillMemoryCommand(Packet_DispatchFillMemoryCommand* packet);
    virtual void Replay_DispatchFixDeviceAddresCommand(Packet_DispatchFixDeviceAddresCommand* packet);
    virtual void Replay_DispatchResizeWindowCommand(Packet_DispatchResizeWindowCommand* packet);
    virtual void Replay_DispatchResizeWindowCommand2(Packet_DispatchResizeWindowCommand2* packet);
    virtual void Replay_DispatchDisplayMessageCommand(Packet_DispatchDisplayMessageCommand* packet);
    virtual void Replay_DispatchCreateHardwareBufferCommand(Packet_DispatchCreateHardwareBufferCommand* packet);
    virtual void Replay_DispatchDestroyHardwareBufferCommand(Packet_DispatchDestroyHardwareBufferCommand* packet);
    virtual void Replay_DispatchSetDevicePropertiesCommand(Packet_DispatchSetDevicePropertiesCommand* packet);
    virtual void
    Replay_DispatchSetDeviceMemoryPropertiesCommand(Packet_DispatchSetDeviceMemoryPropertiesCommand* packet);
    virtual void Replay_DispatchSetOpaqueAddressCommand(Packet_DispatchSetOpaqueAddressCommand* packet);
    virtual void Replay_DispatchSetRayTracingShaderGroupHandlesCommand(
        Packet_DispatchSetRayTracingShaderGroupHandlesCommand* packet);
    virtual void Replay_DispatchSetSwapchainImageStateCommand(Packet_DispatchSetSwapchainImageStateCommand* packet);
    virtual void Replay_DispatchBeginResourceInitCommand(Packet_DispatchBeginResourceInitCommand* packet);
    virtual void Replay_DispatchEndResourceInitCommand(Packet_DispatchEndResourceInitCommand* packet);
    virtual void Replay_DispatchInitBufferCommand(Packet_DispatchInitBufferCommand* packet);
    virtual void Replay_DispatchInitImageCommand(Packet_DispatchInitImageCommand* packet);
    virtual void Replay_DispatchSetTlasToBlasDependencyCommand(Packet_DispatchSetTlasToBlasDependencyCommand* packet);
    virtual void Replay_DispatchVulkanAccelerationStructuresBuildMetaCommand(
        Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand* packet);
    virtual void Replay_DispatchVulkanAccelerationStructuresCopyMetaCommand(
        Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand* packet);
    virtual void Replay_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
        Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand* packet);

    virtual void Replay_vkUpdateDescriptorSetWithTemplate(Packet_vkUpdateDescriptorSetWithTemplate* packet);
    virtual void Replay_vkCmdPushDescriptorSetWithTemplateKHR(Packet_vkCmdPushDescriptorSetWithTemplateKHR* packet);
    virtual void Replay_vkUpdateDescriptorSetWithTemplateKHR(Packet_vkUpdateDescriptorSetWithTemplateKHR* packet);
    virtual void Replay_vkCreateRayTracingPipelinesKHR(Packet_vkCreateRayTracingPipelinesKHR* packet);
    virtual void Replay_vkCmdPushDescriptorSetWithTemplate2KHR(Packet_vkCmdPushDescriptorSetWithTemplate2KHR* packet);
    virtual void Replay_vkDeferredOperationJoinKHR(Packet_vkDeferredOperationJoinKHR* packet);

  protected:
    VulkanReplayConsumer* vulkan_replay_consumer_;

  private:
    uint64_t current_frame_number_;

    struct DeferredOperationFunctionCallData
    {
        StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR> pCreateInfos;
        StructPointerDecoder<Decoded_VkAllocationCallbacks>             pAllocator;
        HandlePointerDecoder<VkPipeline>                                pPipelines;
    };
    std::unordered_map<format::HandleId, DeferredOperationFunctionCallData> record_deferred_operation_function_call;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_PRELOADER_BASE_H