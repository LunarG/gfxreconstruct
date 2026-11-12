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
#include "decode/decoder_util.h"
#include "generated/generated_vulkan_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Base class of every stage. A stage sits between the decoder and the consumers, and decides
// what the next consumers see. The generated VulkanConsumerStage forwards every registry command.
// This class forwards everything else that the decoder sends.
class VulkanConsumerStageBase : public VulkanConsumer
{
  public:
    void AddNext(VulkanConsumer* next) { next_consumers_.push_back(next); }

    // Vulkan calls that VulkanConsumerBase declares by hand. The generator does not see them.
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

    // The stage keeps its own block index and frame number, and passes them on.
    // It is complete when every next consumer is. A finished consumer stops receiving calls.
    void SetCurrentBlockIndex(uint64_t block_index) override
    {
        VulkanConsumer::SetCurrentBlockIndex(block_index);
        Broadcast(&VulkanConsumer::SetCurrentBlockIndex, block_index);
    }

    void SetCurrentFrameNumber(uint64_t frame_number) override
    {
        VulkanConsumer::SetCurrentFrameNumber(frame_number);
        Broadcast(&VulkanConsumer::SetCurrentFrameNumber, frame_number);
    }

    bool IsComplete(uint64_t block_index) override { return decode::IsComplete(next_consumers_, block_index); }

    // Frame and state markers.
    void ProcessStateBeginMarker(uint64_t frame_number) override
    {
        Broadcast(&VulkanConsumer::ProcessStateBeginMarker, frame_number);
    }

    void ProcessStateEndMarker(uint64_t frame_number) override
    {
        Broadcast(&VulkanConsumer::ProcessStateEndMarker, frame_number);
    }

    void ProcessFrameEndMarker(uint64_t frame_number) override
    {
        Broadcast(&VulkanConsumer::ProcessFrameEndMarker, frame_number);
    }

    // Common consumer calls. The recapture hooks are not forwarded, because only the
    // replay consumer calls them, on itself.
    void WaitDevicesIdle() override { Broadcast(&VulkanConsumer::WaitDevicesIdle); }

    void ProcessSetEnvironmentVariablesCommand(const format::SetEnvironmentVariablesCommand& header,
                                               const char*                                   env_string) override
    {
        Broadcast(&VulkanConsumer::ProcessSetEnvironmentVariablesCommand, header, env_string);
    }

    // Metadata commands.
    void Process_ExeFileInfo(const util::filepath::FileInfo& info_record) override
    {
        Broadcast(&VulkanConsumer::Process_ExeFileInfo, info_record);
    }

    void ProcessCaptureStartQueueSubmitIndexCommand(uint64_t queue_submit_index) override
    {
        Broadcast(&VulkanConsumer::ProcessCaptureStartQueueSubmitIndexCommand, queue_submit_index);
    }

    void ProcessDisplayMessageCommand(const std::string& message) override
    {
        Broadcast(&VulkanConsumer::ProcessDisplayMessageCommand, message);
    }

    void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override
    {
        Broadcast(&VulkanConsumer::ProcessFillMemoryCommand, memory_id, offset, size, data);
    }

    void ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                               const uint8_t*                                      data) override
    {
        Broadcast(&VulkanConsumer::ProcessFillMemoryResourceValueCommand, command_header, data);
    }

    void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) override
    {
        Broadcast(&VulkanConsumer::ProcessResizeWindowCommand, surface_id, width, height);
    }

    void ProcessResizeWindowCommand2(format::HandleId surface_id,
                                     uint32_t         width,
                                     uint32_t         height,
                                     uint32_t         pre_transform) override
    {
        Broadcast(&VulkanConsumer::ProcessResizeWindowCommand2, surface_id, width, height, pre_transform);
    }

    void ProcessCreateHardwareBufferCommand(format::HandleId                                    device_id,
                                            format::HandleId                                    memory_id,
                                            uint64_t                                            buffer_id,
                                            uint32_t                                            format,
                                            uint32_t                                            width,
                                            uint32_t                                            height,
                                            uint32_t                                            stride,
                                            uint64_t                                            usage,
                                            uint32_t                                            layers,
                                            const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override
    {
        Broadcast(&VulkanConsumer::ProcessCreateHardwareBufferCommand,
                  device_id,
                  memory_id,
                  buffer_id,
                  format,
                  width,
                  height,
                  stride,
                  usage,
                  layers,
                  plane_info);
    }

    void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) override
    {
        Broadcast(&VulkanConsumer::ProcessDestroyHardwareBufferCommand, buffer_id);
    }

    void ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size) override
    {
        Broadcast(&VulkanConsumer::ProcessCreateHeapAllocationCommand, allocation_id, allocation_size);
    }

    void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                           uint32_t           api_version,
                                           uint32_t           driver_version,
                                           uint32_t           vendor_id,
                                           uint32_t           device_id,
                                           uint32_t           device_type,
                                           const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                           const std::string& device_name) override
    {
        Broadcast(&VulkanConsumer::ProcessSetDevicePropertiesCommand,
                  physical_device_id,
                  api_version,
                  driver_version,
                  vendor_id,
                  device_id,
                  device_type,
                  pipeline_cache_uuid,
                  device_name);
    }

    void ProcessSetDeviceMemoryPropertiesCommand(format::HandleId                             physical_device_id,
                                                 const std::vector<format::DeviceMemoryType>& memory_types,
                                                 const std::vector<format::DeviceMemoryHeap>& memory_heaps) override
    {
        Broadcast(
            &VulkanConsumer::ProcessSetDeviceMemoryPropertiesCommand, physical_device_id, memory_types, memory_heaps);
    }

    void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address) override
    {
        Broadcast(&VulkanConsumer::ProcessSetOpaqueAddressCommand, device_id, object_id, address);
    }

    void ProcessSetOpaqueDescriptorDataCommand(format::HandleId device_id,
                                               format::HandleId object_id,
                                               uint32_t         data_size,
                                               const uint8_t*   data) override
    {
        Broadcast(&VulkanConsumer::ProcessSetOpaqueDescriptorDataCommand, device_id, object_id, data_size, data);
    }

    void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                       format::HandleId pipeline_id,
                                                       size_t           data_size,
                                                       const uint8_t*   data) override
    {
        Broadcast(
            &VulkanConsumer::ProcessSetRayTracingShaderGroupHandlesCommand, device_id, pipeline_id, data_size, data);
    }

    void ProcessSetSwapchainImageStateCommand(format::HandleId                                    device_id,
                                              format::HandleId                                    swapchain_id,
                                              uint32_t                                            last_presented_image,
                                              const std::vector<format::SwapchainImageStateInfo>& image_state) override
    {
        Broadcast(&VulkanConsumer::ProcessSetSwapchainImageStateCommand,
                  device_id,
                  swapchain_id,
                  last_presented_image,
                  image_state);
    }

    void ProcessBeginResourceInitCommand(format::HandleId device_id,
                                         uint64_t         total_copy_size,
                                         uint64_t         max_copy_size) override
    {
        Broadcast(&VulkanConsumer::ProcessBeginResourceInitCommand, device_id, total_copy_size, max_copy_size);
    }

    void ProcessEndResourceInitCommand(format::HandleId device_id) override
    {
        Broadcast(&VulkanConsumer::ProcessEndResourceInitCommand, device_id);
    }

    void ProcessInitBufferCommand(format::HandleId device_id,
                                  format::HandleId buffer_id,
                                  uint64_t         data_size,
                                  const uint8_t*   data) override
    {
        Broadcast(&VulkanConsumer::ProcessInitBufferCommand, device_id, buffer_id, data_size, data);
    }

    void ProcessInitTensorCommand(format::HandleId device_id,
                                  format::HandleId tensor_id,
                                  uint64_t         data_size,
                                  const uint8_t*   data) override
    {
        Broadcast(&VulkanConsumer::ProcessInitTensorCommand, device_id, tensor_id, data_size, data);
    }

    void ProcessInitImageCommand(format::HandleId             device_id,
                                 format::HandleId             image_id,
                                 uint64_t                     data_size,
                                 uint32_t                     aspect,
                                 uint32_t                     layout,
                                 const std::vector<uint64_t>& level_sizes,
                                 const uint8_t*               data) override
    {
        Broadcast(&VulkanConsumer::ProcessInitImageCommand,
                  device_id,
                  image_id,
                  data_size,
                  aspect,
                  layout,
                  level_sizes,
                  data);
    }

    void ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                       const uint8_t*                              data) override
    {
        Broadcast(&VulkanConsumer::ProcessInitSubresourceCommand, command_header, data);
    }

    void ProcessExecuteBlocksFromFile(uint32_t n_blocks, int64_t offset, const std::string& filename) override
    {
        Broadcast(&VulkanConsumer::ProcessExecuteBlocksFromFile, n_blocks, offset, filename);
    }

    void ProcessVulkanBuildAccelerationStructuresCommand(
        format::HandleId                                                           device_id,
        uint32_t                                                                   info_count,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* geometry_infos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   range_infos) override
    {
        Broadcast(&VulkanConsumer::ProcessVulkanBuildAccelerationStructuresCommand,
                  device_id,
                  info_count,
                  geometry_infos,
                  range_infos);
    }

    void ProcessVulkanCopyAccelerationStructuresCommand(
        format::HandleId                                                  device_id,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* copy_infos) override
    {
        Broadcast(&VulkanConsumer::ProcessVulkanCopyAccelerationStructuresCommand, device_id, copy_infos);
    }

    void ProcessVulkanWriteAccelerationStructuresPropertiesCommand(format::HandleId device_id,
                                                                   VkQueryType      query_type,
                                                                   format::HandleId acceleration_structure_id) override
    {
        Broadcast(&VulkanConsumer::ProcessVulkanWriteAccelerationStructuresPropertiesCommand,
                  device_id,
                  query_type,
                  acceleration_structure_id);
    }

    void ProcessResourceAliasingGroupsCommand(format::HandleId                          device_id,
                                              const std::vector<ResourceAliasingGroup>& groups) override
    {
        Broadcast(&VulkanConsumer::ProcessResourceAliasingGroupsCommand, device_id, groups);
    }

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