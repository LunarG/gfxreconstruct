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

#include "decode/vulkan_preload_replayer_base.h"
#include "util/logging.h"

#include "format/packet_call_id.h"
#include "vulkan_preload_replayer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const uint32_t kFirstFrame = 0;

VulkanPreloadReplayerBase::VulkanPreloadReplayerBase() : current_frame_number_(kFirstFrame) {}

VulkanPreloadReplayerBase::~VulkanPreloadReplayerBase() {}

void VulkanPreloadReplayerBase::Replay_DispatchFillMemoryCommand(Packet_DispatchFillMemoryCommand* packet)
{
    vulkan_replay_consumer_->ProcessFillMemoryCommand(packet->memory_id, packet->offset, packet->size, packet->data);
}

void VulkanPreloadReplayerBase::Replay_DispatchFixDeviceAddresCommand(Packet_DispatchFixDeviceAddresCommand* packet)
{
    vulkan_replay_consumer_->ProcessFixDeviceAddressCommand(packet->header, packet->infos);
}

void VulkanPreloadReplayerBase::Replay_DispatchResizeWindowCommand(Packet_DispatchResizeWindowCommand* packet)
{
    vulkan_replay_consumer_->ProcessResizeWindowCommand(packet->surface_id, packet->width, packet->height);
}

void VulkanPreloadReplayerBase::Replay_DispatchResizeWindowCommand2(Packet_DispatchResizeWindowCommand2* packet)
{
    vulkan_replay_consumer_->ProcessResizeWindowCommand2(
        packet->surface_id, packet->width, packet->height, packet->pre_transform);
}

void VulkanPreloadReplayerBase::Replay_DispatchDisplayMessageCommand(Packet_DispatchDisplayMessageCommand* packet)
{
    vulkan_replay_consumer_->ProcessDisplayMessageCommand(packet->message);
}

void VulkanPreloadReplayerBase::Replay_DispatchCreateHardwareBufferCommand(
    Packet_DispatchCreateHardwareBufferCommand* packet)
{
    vulkan_replay_consumer_->ProcessCreateHardwareBufferCommand(packet->memory_id,
                                                                packet->buffer_id,
                                                                packet->format,
                                                                packet->width,
                                                                packet->height,
                                                                packet->stride,
                                                                packet->usage,
                                                                packet->layers,
                                                                packet->plane_info);
}

void VulkanPreloadReplayerBase::Replay_DispatchDestroyHardwareBufferCommand(
    Packet_DispatchDestroyHardwareBufferCommand* packet)
{
    vulkan_replay_consumer_->ProcessDestroyHardwareBufferCommand(packet->buffer_id);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetDevicePropertiesCommand(
    Packet_DispatchSetDevicePropertiesCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetDevicePropertiesCommand(packet->physical_device_id,
                                                               packet->api_version,
                                                               packet->driver_version,
                                                               packet->vendor_id,
                                                               packet->device_id,
                                                               packet->device_type,
                                                               packet->pipeline_cache_uuid,
                                                               packet->device_name);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetDeviceMemoryPropertiesCommand(
    Packet_DispatchSetDeviceMemoryPropertiesCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetDeviceMemoryPropertiesCommand(
        packet->physical_device_id, packet->memory_types, packet->memory_heaps);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetOpaqueAddressCommand(Packet_DispatchSetOpaqueAddressCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetOpaqueAddressCommand(packet->device_id, packet->object_id, packet->address);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetRayTracingShaderGroupHandlesCommand(
    Packet_DispatchSetRayTracingShaderGroupHandlesCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetRayTracingShaderGroupHandlesCommand(
        packet->device_id, packet->pipeline_id, packet->data_size, packet->data);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetSwapchainImageStateCommand(
    Packet_DispatchSetSwapchainImageStateCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetSwapchainImageStateCommand(
        packet->device_id, packet->swapchain_id, packet->last_presented_image, packet->image_state);
}

void VulkanPreloadReplayerBase::Replay_DispatchBeginResourceInitCommand(Packet_DispatchBeginResourceInitCommand* packet)
{
    vulkan_replay_consumer_->ProcessBeginResourceInitCommand(
        packet->device_id, packet->max_resource_size, packet->max_copy_size);
}

void VulkanPreloadReplayerBase::Replay_DispatchEndResourceInitCommand(Packet_DispatchEndResourceInitCommand* packet)
{
    vulkan_replay_consumer_->ProcessEndResourceInitCommand(packet->device_id);
}

void VulkanPreloadReplayerBase::Replay_DispatchInitBufferCommand(Packet_DispatchInitBufferCommand* packet)
{
    vulkan_replay_consumer_->ProcessInitBufferCommand(
        packet->device_id, packet->buffer_id, packet->data_size, packet->data);
}

void VulkanPreloadReplayerBase::Replay_DispatchInitImageCommand(Packet_DispatchInitImageCommand* packet)
{
    vulkan_replay_consumer_->ProcessInitImageCommand(packet->device_id,
                                                     packet->image_id,
                                                     packet->data_size,
                                                     packet->aspect,
                                                     packet->layout,
                                                     packet->level_sizes,
                                                     packet->data);
}

void VulkanPreloadReplayerBase::Replay_DispatchSetTlasToBlasDependencyCommand(
    Packet_DispatchSetTlasToBlasDependencyCommand* packet)
{
    vulkan_replay_consumer_->ProcessSetTlasToBlasRelationCommand(packet->tlas, packet->blases);
}

void VulkanPreloadReplayerBase::Replay_DispatchVulkanAccelerationStructuresBuildMetaCommand(
    Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand* packet)
{
    vulkan_replay_consumer_->ProcessBuildVulkanAccelerationStructuresMetaCommand(
        packet->device, packet->info_count, &(packet->pInfos), &(packet->ppRangeInfos), packet->instance_buffers_data);
}

void VulkanPreloadReplayerBase::Replay_DispatchVulkanAccelerationStructuresCopyMetaCommand(
    Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand* packet)
{
    vulkan_replay_consumer_->ProcessCopyVulkanAccelerationStructuresMetaCommand(packet->device, &(packet->copy_infos));
}

void VulkanPreloadReplayerBase::Replay_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
    Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand* packet)
{
    vulkan_replay_consumer_->ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(
        packet->device_id, packet->copy_query_typeinfos, packet->acceleration_structure_id);
}

void VulkanPreloadReplayerBase::Replay_vkUpdateDescriptorSetWithTemplate(
    Packet_vkUpdateDescriptorSetWithTemplate* packet)
{
    vulkan_replay_consumer_->Process_vkUpdateDescriptorSetWithTemplate(
        packet->call_info, packet->device, packet->descriptorSet, packet->descriptorUpdateTemplate, &(packet->pData));
}

void VulkanPreloadReplayerBase::Replay_vkCmdPushDescriptorSetWithTemplateKHR(
    Packet_vkCmdPushDescriptorSetWithTemplateKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushDescriptorSetWithTemplateKHR(packet->call_info,
                                                                           packet->commandBuffer,
                                                                           packet->descriptorUpdateTemplate,
                                                                           packet->layout,
                                                                           packet->set,
                                                                           &(packet->pData));
}

void VulkanPreloadReplayerBase::Replay_vkUpdateDescriptorSetWithTemplateKHR(
    Packet_vkUpdateDescriptorSetWithTemplateKHR* packet)
{
    vulkan_replay_consumer_->Process_vkUpdateDescriptorSetWithTemplate(
        packet->call_info, packet->device, packet->descriptorSet, packet->descriptorUpdateTemplate, &(packet->pData));
}

void VulkanPreloadReplayerBase::Replay_vkCreateRayTracingPipelinesKHR(Packet_vkCreateRayTracingPipelinesKHR* packet)
{
    vulkan_replay_consumer_->Process_vkCreateRayTracingPipelinesKHR(packet->call_info,
                                                                    packet->returnValue,
                                                                    packet->device,
                                                                    packet->deferredOperation,
                                                                    packet->pipelineCache,
                                                                    packet->createInfoCount,
                                                                    &(packet->pCreateInfos),
                                                                    &(packet->pAllocator),
                                                                    &(packet->pPipelines));

    if (packet->deferredOperation)
    {
        DecodeAllocator::TurnOffEndCanClear();
        DeferredOperationFunctionCallData record;
        record.pCreateInfos                                                = std::move(packet->pCreateInfos);
        record.pAllocator                                                  = std::move(packet->pAllocator);
        record.pPipelines                                                  = std::move(packet->pPipelines);
        record_deferred_operation_function_call[packet->deferredOperation] = std::move(record);
    }
}

void VulkanPreloadReplayerBase::Replay_vkCmdPushDescriptorSetWithTemplate2KHR(
    Packet_vkCmdPushDescriptorSetWithTemplate2KHR* packet)
{
    vulkan_replay_consumer_->Process_vkCmdPushDescriptorSetWithTemplate2KHR(
        packet->call_info, packet->commandBuffer, &(packet->pPushDescriptorSetWithTemplateInfo));
}

void VulkanPreloadReplayerBase::Replay_vkDeferredOperationJoinKHR(Packet_vkDeferredOperationJoinKHR* packet)
{
    vulkan_replay_consumer_->Process_vkDeferredOperationJoinKHR(
        packet->call_info, packet->return_value, packet->device, packet->operation);

    DecodeAllocator::TurnOnEndCanClear();
    auto it = record_deferred_operation_function_call.find(packet->operation);
    if (it != record_deferred_operation_function_call.end())
    {
        record_deferred_operation_function_call.erase(it);
    }
}

bool VulkanPreloadReplayerBase::ReplayPackets(VulkanPreloadDecoder* vulkan_preload_decoder)
{
    std::vector<void*> container     = vulkan_preload_decoder->GetPackets();
    size_t             packet_number = container.size();
    size_t             packet_index  = 0;
    while (packet_index < packet_number)
    {
        void* packet           = container[packet_index];
        auto  packet_call_id   = *reinterpret_cast<format::PacketCallId*>(packet);
        auto  packet_family_id = GetPacketCallFamily(packet_call_id);
        if (packet_family_id == format::PacketFamilyId::PacketFamily_Vulkan_Functional_Call)
        {
            DecodeAllocator::Begin();
            ReplayFunctionCall(packet_call_id, packet);
            DecodeAllocator::End();
        }
        else
        {
            switch (packet_call_id)
            {
                case gfxrecon::format::PacketCall_DispatchFillMemoryCommand:
                    Replay_DispatchFillMemoryCommand(reinterpret_cast<Packet_DispatchFillMemoryCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchFixDeviceAddresCommand:
                    Replay_DispatchFixDeviceAddresCommand(
                        reinterpret_cast<Packet_DispatchFixDeviceAddresCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchResizeWindowCommand:
                    Replay_DispatchResizeWindowCommand(reinterpret_cast<Packet_DispatchResizeWindowCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchResizeWindowCommand2:
                    Replay_DispatchResizeWindowCommand2(reinterpret_cast<Packet_DispatchResizeWindowCommand2*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchDisplayMessageCommand:
                    Replay_DispatchDisplayMessageCommand(
                        reinterpret_cast<Packet_DispatchDisplayMessageCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchCreateHardwareBufferCommand:
                    Replay_DispatchCreateHardwareBufferCommand(
                        reinterpret_cast<Packet_DispatchCreateHardwareBufferCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchDestroyHardwareBufferCommand:
                    Replay_DispatchDestroyHardwareBufferCommand(
                        reinterpret_cast<Packet_DispatchDestroyHardwareBufferCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetDevicePropertiesCommand:
                    Replay_DispatchSetDevicePropertiesCommand(
                        reinterpret_cast<Packet_DispatchSetDevicePropertiesCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetDeviceMemoryPropertiesCommand:
                    Replay_DispatchSetDeviceMemoryPropertiesCommand(
                        reinterpret_cast<Packet_DispatchSetDeviceMemoryPropertiesCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetOpaqueAddressCommand:
                    Replay_DispatchSetOpaqueAddressCommand(
                        reinterpret_cast<Packet_DispatchSetOpaqueAddressCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetRayTracingShaderGroupHandlesCommand:
                    Replay_DispatchSetRayTracingShaderGroupHandlesCommand(
                        reinterpret_cast<Packet_DispatchSetRayTracingShaderGroupHandlesCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetSwapchainImageStateCommand:
                    Replay_DispatchSetSwapchainImageStateCommand(
                        reinterpret_cast<Packet_DispatchSetSwapchainImageStateCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchBeginResourceInitCommand:
                    Replay_DispatchBeginResourceInitCommand(
                        reinterpret_cast<Packet_DispatchBeginResourceInitCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchEndResourceInitCommand:
                    Replay_DispatchEndResourceInitCommand(
                        reinterpret_cast<Packet_DispatchEndResourceInitCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchInitBufferCommand:
                    Replay_DispatchInitBufferCommand(reinterpret_cast<Packet_DispatchInitBufferCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchInitImageCommand:
                    Replay_DispatchInitImageCommand(reinterpret_cast<Packet_DispatchInitImageCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchSetTlasToBlasDependencyCommand:
                    Replay_DispatchSetTlasToBlasDependencyCommand(
                        reinterpret_cast<Packet_DispatchSetTlasToBlasDependencyCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresBuildMetaCommand:
                    Replay_DispatchVulkanAccelerationStructuresBuildMetaCommand(
                        reinterpret_cast<Packet_DispatchVulkanAccelerationStructuresBuildMetaCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresCopyMetaCommand:
                    Replay_DispatchVulkanAccelerationStructuresCopyMetaCommand(
                        reinterpret_cast<Packet_DispatchVulkanAccelerationStructuresCopyMetaCommand*>(packet));
                    break;
                case gfxrecon::format::PacketCall_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand:
                    Replay_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
                        reinterpret_cast<Packet_DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand*>(
                            packet));
                    break;

                default:
                    break;
            }
        }
        packet_index++;
    }
    return false;
}

void VulkanPreloadReplayerBase::ReplayFunctionCall(format::PacketCallId& packet_call_id, void* packet)
{
    switch (packet_call_id)
    {
        case gfxrecon::format::PacketCall_vkCreateRayTracingPipelinesKHR:
            break;
        default:
            break;
    }
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)