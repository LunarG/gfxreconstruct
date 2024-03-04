/*
 ** Copyright (c) 2019-2021 LunarG, Inc.
 ** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
#define GFXRECON_ENCODE_VULKAN_STATE_WRITER_H

#include "encode/parameter_encoder.h"
#include "encode/vulkan_handle_wrappers.h"
#include "generated/generated_vulkan_state_table.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_resources_util.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateWriter
{
  public:
    VulkanStateWriter(util::FileOutputStream* output_stream, util::Compressor* compressor, format::ThreadId thread_id);

    ~VulkanStateWriter();

    // Returns number of blocks written to the output_stream.
    uint64_t WriteState(const VulkanStateTable& state_table, uint64_t frame_number);

  private:
    // Data structures for processing resource memory snapshots.
    struct BufferSnapshotInfo
    {
        const vulkan_wrappers::BufferWrapper*       buffer_wrapper{ nullptr };
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper{ nullptr };
        VkMemoryPropertyFlags                       memory_properties{};
        bool                                        need_staging_copy{ false };
    };

    struct ImageSnapshotInfo
    {
        const vulkan_wrappers::ImageWrapper*        image_wrapper{ nullptr };
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper{ nullptr };
        VkMemoryPropertyFlags                       memory_properties{};
        bool                                        need_staging_copy{ false };
        VkImageAspectFlagBits                       aspect{};
        VkDeviceSize                                resource_size{ 0 }; // Combined size of all sub-resources.
        std::vector<uint64_t>                       level_sizes;        // Combined size of all layers in a mip level.
    };

    struct ResourceSnapshotInfo
    {
        std::vector<BufferSnapshotInfo> buffers;
        std::vector<ImageSnapshotInfo>  images;
    };

    typedef std::unordered_map<uint32_t, ResourceSnapshotInfo> ResourceSnapshotQueueFamilyTable;
    typedef std::unordered_map<const vulkan_wrappers::DeviceWrapper*, ResourceSnapshotQueueFamilyTable>
        DeviceResourceTables;

    struct QueryActivationData
    {
        format::HandleId    pool_id{ format::kNullHandleId };
        VkQueryType         type{};
        VkQueryControlFlags flags{ 0 };
        uint32_t            index{ 0 };
        uint32_t            type_index{ 0 };
    };

    typedef std::vector<QueryActivationData>                  QueryActivationList;
    typedef std::unordered_map<uint32_t, QueryActivationList> QueryActivationQueueFamilyTable;

  private:
    void WritePhysicalDeviceState(const VulkanStateTable& state_table);

    void WriteDeviceState(const VulkanStateTable& state_table);

    void WriteCommandBufferState(const VulkanStateTable& state_table);

    void WriteTrimCommandPool(const VulkanStateTable& state_table);

    void WritePrivateDataSlotState(const VulkanStateTable& state_table);

    void WriteFenceState(const VulkanStateTable& state_table);

    void WriteEventState(const VulkanStateTable& state_table);

    void WriteSemaphoreState(const VulkanStateTable& state_table);

    void WriteBufferViewState(const VulkanStateTable& state_table);

    void WriteImageViewState(const VulkanStateTable& state_table);

    void WriteFramebufferState(const VulkanStateTable& state_table);

    void WritePipelineLayoutState(const VulkanStateTable& state_table);

    void WritePipelineCacheState(const VulkanStateTable& state_table);

    void WritePipelineState(const VulkanStateTable& state_table);

    void WriteDescriptorSetState(const VulkanStateTable& state_table);

    void WriteQueryPoolState(const VulkanStateTable& state_table);

    void WriteSurfaceKhrState(const VulkanStateTable& state_table);

    void WriteSwapchainKhrState(const VulkanStateTable& state_table);

    void WriteBufferState(const VulkanStateTable& state_table);

    void WriteDeviceMemoryState(const VulkanStateTable& state_table);

    void WriteAccelerationStructureKHRState(const VulkanStateTable& state_table);

    void WriteDeferredOperationJoinCommand(format::HandleId device_id, format::HandleId deferred_operation_id);

    void
    ProcessHardwareBuffer(format::HandleId memory_id, AHardwareBuffer* hardware_buffer, VkDeviceSize allocation_size);

    void ProcessBufferMemory(const vulkan_wrappers::DeviceWrapper*  device_wrapper,
                             const std::vector<BufferSnapshotInfo>& buffer_snapshot_info,
                             graphics::VulkanResourcesUtil&         resource_util);

    void ProcessImageMemory(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                            const std::vector<ImageSnapshotInfo>& image_snapshot_info,
                            graphics::VulkanResourcesUtil&        resource_util);

    void WriteBufferMemoryState(const VulkanStateTable& state_table,
                                DeviceResourceTables*   resources,
                                VkDeviceSize*           max_resource_size,
                                VkDeviceSize*           max_staging_copy_size);

    void WriteImageMemoryState(const VulkanStateTable& state_table,
                               DeviceResourceTables*   resources,
                               VkDeviceSize*           max_resource_size,
                               VkDeviceSize*           max_staging_copy_size);

    void WriteImageSubresourceLayouts(const vulkan_wrappers::ImageWrapper* image_wrapper,
                                      VkImageAspectFlags                   aspect_flags);

    void WriteResourceMemoryState(const VulkanStateTable& state_table);

    void WriteMappedMemoryState(const VulkanStateTable& state_table);

    void WriteSwapchainImageState(const VulkanStateTable& state_table);

    void WritePhysicalDevicePropertiesMetaData(const vulkan_wrappers::PhysicalDeviceWrapper* physical_device_wrapper);

    template <typename T>
    void WriteGetPhysicalDeviceQueueFamilyProperties(format::ApiCallId call_id,
                                                     format::HandleId  physical_device_id,
                                                     uint32_t          property_count,
                                                     T*                properties);

    void WriteGetPhysicalDeviceSurfaceSupport(format::HandleId physical_device_id,
                                              uint32_t         queue_family_index,
                                              format::HandleId surface_id,
                                              VkBool32         supported);

    void WriteGetPhysicalDeviceSurfaceCapabilities(format::HandleId                            physical_device_id,
                                                   format::HandleId                            surface_id,
                                                   const vulkan_wrappers::SurfaceCapabilities& capabilities,
                                                   const VulkanStateTable&                     state_table);

    void WriteGetPhysicalDeviceSurfaceFormats(format::HandleId                       physical_device_id,
                                              format::HandleId                       surface_id,
                                              const vulkan_wrappers::SurfaceFormats& formats,
                                              const VulkanStateTable&                state_table);

    void WriteGetPhysicalDeviceSurfacePresentModes(format::HandleId                            physical_device_id,
                                                   format::HandleId                            surface_id,
                                                   const vulkan_wrappers::SurfacePresentModes& present_modes,
                                                   const VulkanStateTable&                     state_table);

    void WriteGetDeviceGroupSurfacePresentModes(format::HandleId                                 device_id,
                                                format::HandleId                                 surface_id,
                                                const vulkan_wrappers::GroupSurfacePresentModes& present_modes,
                                                const VulkanStateTable&                          state_table);

    void WriteCommandProcessingCreateCommands(format::HandleId device_id,
                                              uint32_t         queue_family_index,
                                              format::HandleId queue_id,
                                              VkCommandPool    command_pool,
                                              format::HandleId command_buffer_id);

    void WriteCommandBegin(format::HandleId command_buffer_id);

    void WriteCommandEnd(format::HandleId command_buffer_id);

    void WriteCommandExecution(format::HandleId            queue_id,
                               uint32_t                    command_buffer_count,
                               const format::HandleId*     command_buffer_ids,
                               uint32_t                    signal_semaphore_count,
                               const format::HandleId*     signal_semaphore_ids,
                               uint32_t                    wait_semaphore_count,
                               const format::HandleId*     wait_semaphore_ids,
                               const VkPipelineStageFlags* wait_dst_stage_mask);

    void WriteCommandExecution(format::HandleId queue_id, format::HandleId command_buffer_id)
    {
        WriteCommandExecution(queue_id, 1, &command_buffer_id, 0, nullptr, 0, nullptr, nullptr);
    }

    void WriteCommandBufferCommands(const vulkan_wrappers::CommandBufferWrapper* wrapper,
                                    const VulkanStateTable&                      state_table);

    void WriteDescriptorUpdateCommand(format::HandleId                         device_id,
                                      const vulkan_state_info::DescriptorInfo* binding,
                                      VkWriteDescriptorSet*                    write);

    void WriteQueryPoolReset(format::HandleId                                             device_id,
                             const std::vector<const vulkan_wrappers::QueryPoolWrapper*>& query_pool_wrappers);

    void WriteQueryActivation(format::HandleId           device_id,
                              uint32_t                   queue_family_index,
                              const QueryActivationList& active_queries);

    void WriteCreateFence(format::HandleId device_id, format::HandleId fence_id, bool signaled);

    void WriteSetEvent(format::HandleId device_id, format::HandleId event_id);

    void WriteSignalSemaphoreValue(format::ApiCallId api_call_id,
                                   format::HandleId  device_id,
                                   format::HandleId  semaphore,
                                   uint64_t          value);

    void WriteDestroyDeviceObject(format::ApiCallId            call_id,
                                  format::HandleId             device_id,
                                  format::HandleId             object_id,
                                  const VkAllocationCallbacks* allocator);

    void WriteCreatePipelineCache(format::HandleId                 device_id,
                                  const VkPipelineCacheCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks*     allocator,
                                  VkPipelineCache*                 pPipelineCache,
                                  VkResult                         result);

    void DestroyTemporaryDeviceObject(format::ApiCallId               call_id,
                                      format::HandleId                object_id,
                                      const util::MemoryOutputStream* create_parameters);

    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void WriteFillMemoryCmd(format::HandleId memory_id, VkDeviceSize offset, VkDeviceSize size, const void* data);

    void WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height);

    void WriteResizeWindowCmd2(format::HandleId              surface_id,
                               uint32_t                      width,
                               uint32_t                      height,
                               VkSurfaceTransformFlagBitsKHR pre_transform);

    void WriteCreateHardwareBufferCmd(format::HandleId                                    memory_id,
                                      AHardwareBuffer*                                    hardware_buffer,
                                      const std::vector<format::HardwareBufferPlaneInfo>& plane_info);

    void WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                         const VkPhysicalDeviceProperties& properties);

    void WriteSetDeviceMemoryPropertiesCommand(format::HandleId                        physical_device_id,
                                               const VkPhysicalDeviceMemoryProperties& memory_properties);

    void WriteSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, VkDeviceAddress address);

    void WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                     format::HandleId pipeline_id,
                                                     size_t           data_size,
                                                     const void*      data);

    template <typename Wrapper>
    void StandardCreateWrite(const VulkanStateTable& state_table)
    {
        std::set<util::MemoryOutputStream*> processed;
        state_table.VisitWrappers([&](const Wrapper* wrapper) {
            // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
            // all reference the same parameter buffer.
            if (processed.find(wrapper->create_parameters.get()) == processed.end())
            {
                WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
                processed.insert(wrapper->create_parameters.get());
            }
        });
    }

    VkMemoryPropertyFlags GetMemoryProperties(const vulkan_wrappers::DeviceWrapper*       device_wrapper,
                                              const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper);

    void InvalidateMappedMemoryRange(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                     VkDeviceMemory                        memory,
                                     VkDeviceSize                          offset,
                                     VkDeviceSize                          size);

    void GetFenceStatus(const vulkan_wrappers::DeviceWrapper* device_wrapper, VkFence fence, bool* result);

    bool CheckCommandHandles(const vulkan_wrappers::CommandBufferWrapper* wrapper, const VulkanStateTable& state_table);

    bool CheckCommandHandle(vulkan_state_info::CommandHandleType handle_type,
                            format::HandleId                     handle,
                            const VulkanStateTable&              state_table);

    bool CheckDescriptorStatus(const vulkan_state_info::DescriptorInfo* descriptor,
                               uint32_t                                 index,
                               const VulkanStateTable&                  state_table,
                               VkDescriptorType*                        descriptor_type);

    bool IsBufferValid(format::HandleId buffer_id, const VulkanStateTable& state_table);

    bool IsBufferViewValid(format::HandleId view_id, const VulkanStateTable& state_table);

    bool IsImageValid(format::HandleId image_id, const VulkanStateTable& state_table);

    bool IsImageViewValid(format::HandleId view_id, const VulkanStateTable& state_table);

    bool IsFramebufferValid(format::HandleId framebuffer_id, const VulkanStateTable& state_table);

    bool IsFramebufferValid(const vulkan_wrappers::FramebufferWrapper* framebuffer_wrapper,
                            const VulkanStateTable&                    state_table);

    void WriteTlasToBlasDependenciesMetadata(const VulkanStateTable& state_table);

    void WriteAccelerationStructureBuildMetaCommand(const VulkanStateTable& state_table);

    struct AccelerationStructureBuildCommandData
    {
        format::HandleId                                                   device;
        std::vector<VkAccelerationStructureBuildGeometryInfoKHR>           geometry_infos;
        std::vector<HandleUnwrapMemory>                                    geometry_info_memory;
        std::vector<std::vector<VkAccelerationStructureBuildRangeInfoKHR>> build_range_infos;
        std::vector<std::vector<VkAccelerationStructureInstanceKHR>>       instance_buffers_data;
    };
    using AccelerationStructureBuildCommandsContainer =
        std::unordered_map<format::HandleId, AccelerationStructureBuildCommandData>;
    void EncodeAccelerationStructureBuildMetaCommand(const AccelerationStructureBuildCommandData& command);

    struct AccelerationStructureCopyCommandData
    {
        format::HandleId                                device;
        std::vector<VkCopyAccelerationStructureInfoKHR> infos;
    };
    using AccelerationStructureCopyCommandsContainer =
        std::unordered_map<format::HandleId, AccelerationStructureCopyCommandData>;
    void EncodeAccelerationStructureCopyMetaCommand(const AccelerationStructureCopyCommandData& command);

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
    uint64_t                 blocks_written_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
