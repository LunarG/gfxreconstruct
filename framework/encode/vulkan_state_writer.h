/*
 ** Copyright (c) 2019-2025 LunarG, Inc.
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

#include "encode/command_writer.h"
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
#include "util/thread_data.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateWriter
{
  public:
    using AssetFileOffsetsInfo = std::unordered_map<uint64_t, int64_t>;

    VulkanStateWriter(util::FileOutputStream*                  output_stream,
                      util::Compressor*                        compressor,
                      util::ThreadData*                        thread_data,
                      std::function<format::HandleId()>        get_unique_id_fn,
                      util::FileOutputStream*                  asset_file_stream  = nullptr,
                      const std::string*                       asset_file_name    = nullptr,
                      VulkanStateWriter::AssetFileOffsetsInfo* asset_file_offsets = nullptr);

    util::ThreadData* GetThreadData() { return thread_data_; }

    bool OutputStreamWrite(const void* data, size_t len);

    // Returns number of blocks written to the output_stream.
    uint64_t WriteState(const VulkanStateTable& state_table, uint64_t frame_number);

    uint64_t WriteAssets(const VulkanStateTable& state_table);

    void WriteFillMemoryCmd(format::HandleId memory_id, VkDeviceSize offset, VkDeviceSize size, const void* data);

  private:
    // Data structures for processing resource memory snapshots.
    struct BufferSnapshotInfo
    {
        vulkan_wrappers::BufferWrapper*             buffer_wrapper{ nullptr };
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper{ nullptr };
        VkMemoryPropertyFlags                       memory_properties{};
        bool                                        need_staging_copy{ false };
    };

    struct ImageSnapshotInfo
    {
        vulkan_wrappers::ImageWrapper*              image_wrapper{ nullptr };
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

    void WriteDescriptorSetStateWithAssetFile(const VulkanStateTable& state_table);

    void WriteQueryPoolState(const VulkanStateTable& state_table);

    void WriteSurfaceKhrState(const VulkanStateTable& state_table);

    void WriteSwapchainKhrState(const VulkanStateTable& state_table);

    void WriteBufferState(const VulkanStateTable& state_table);

    void WriteBufferDeviceAddressState(const VulkanStateTable& state_table);

    void WriteDeviceMemoryState(const VulkanStateTable& state_table);

    void WriteRayTracingPropertiesState(const VulkanStateTable& state_table);

    void WriteRayTracingShaderGroupHandlesState(const VulkanStateTable& state_table);

    void WriteAccelerationStructureKHRState(const VulkanStateTable& state_table);

    void WriteDeferredOperationJoinCommand(format::HandleId device_id, format::HandleId deferred_operation_id);

    void ProcessBufferMemory(const vulkan_wrappers::DeviceWrapper*  device_wrapper,
                             const std::vector<BufferSnapshotInfo>& buffer_snapshot_infos,
                             graphics::VulkanResourcesUtil&         resource_util);

    void ProcessBufferMemoryWithAssetFile(const vulkan_wrappers::DeviceWrapper*  device_wrapper,
                                          const std::vector<BufferSnapshotInfo>& buffer_snapshot_infos,
                                          graphics::VulkanResourcesUtil&         resource_util);

    void ProcessImageMemory(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                            const std::vector<ImageSnapshotInfo>& image_snapshot_infos,
                            graphics::VulkanResourcesUtil&        resource_util);

    void ProcessImageMemoryWithAssetFile(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                         const std::vector<ImageSnapshotInfo>& image_snapshot_infos,
                                         graphics::VulkanResourcesUtil&        resource_util);

    void WriteBufferMemoryState(const VulkanStateTable& state_table,
                                DeviceResourceTables*   resources,
                                VkDeviceSize*           max_resource_size,
                                VkDeviceSize*           max_staging_copy_size,
                                bool                    write_memory_state);

    void WriteImageMemoryState(const VulkanStateTable& state_table,
                               DeviceResourceTables*   resources,
                               VkDeviceSize*           max_resource_size,
                               VkDeviceSize*           max_staging_copy_size,
                               bool                    write_memory_state);

    void WriteImageSubresourceLayouts(const vulkan_wrappers::ImageWrapper* image_wrapper,
                                      VkImageAspectFlags                   aspect_flags);

    void WriteResourceMemoryState(const VulkanStateTable& state_table, bool write_memory_state);

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
                                      VkWriteDescriptorSet*                    write,
                                      util::FileOutputStream*                  output_stream = nullptr);

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

    void WriteFunctionCall(format::ApiCallId         call_id,
                           util::MemoryOutputStream* parameter_buffer,
                           util::FileOutputStream*   output_stream = nullptr);

    void WriteResizeWindowCmd(format::HandleId surface_id, const vulkan_wrappers::SurfaceCapabilities& capabilities);

    void WriteResizeWindowCmd2(format::HandleId              surface_id,
                               uint32_t                      width,
                               uint32_t                      height,
                               VkSurfaceTransformFlagBitsKHR pre_transform);

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
            // Skip create call for swapchain images, i.e. vkGetSwapchainImagesKHR
            // This call is already emitted by the state setup for the parent swapchain
            if constexpr (std::is_same<Wrapper, vulkan_wrappers::ImageWrapper>::value)
            {
                auto image_wrapper = reinterpret_cast<const vulkan_wrappers::ImageWrapper*>(wrapper);
                if (image_wrapper->is_swapchain_image)
                {
                    return;
                }
            }
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

    void WriteAccelerationStructureStateMetaCommands(const VulkanStateTable& state_table);

    using AccelerationStructureBuildCommandData =
        vulkan_wrappers::AccelerationStructureKHRWrapper::AccelerationStructureKHRBuildCommandData;

    void WriteAccelerationStructureBuildState(const gfxrecon::format::HandleId&      device,
                                              AccelerationStructureBuildCommandData& command);

    void EncodeAccelerationStructureBuildMetaCommand(format::HandleId                             device_id,
                                                     const AccelerationStructureBuildCommandData& command);

    void EncodeAccelerationStructuresCopyMetaCommand(format::HandleId                                       device_id,
                                                     const std::vector<VkCopyAccelerationStructureInfoKHR>& infos);

    struct AccelerationStructureWritePropertiesCommandData
    {
        VkQueryType      query_type;
        format::HandleId acceleration_structure;
    };
    void
    EncodeAccelerationStructureWritePropertiesCommand(format::HandleId                                       device_id,
                                                      const AccelerationStructureWritePropertiesCommandData& command);

    void
    WriteGetAccelerationStructureDeviceAddressKHRCall(const VulkanStateTable& state_table,
                                                      const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper);

    static void UpdateAddresses(AccelerationStructureBuildCommandData& command);

    using ASInputBuffer = vulkan_wrappers::AccelerationStructureKHRWrapper::ASInputBuffer;
    void BeginAccelerationStructuresSection(format::HandleId device_id, uint64_t max_resource_size);
    void WriteASInputBufferState(ASInputBuffer& buffer);
    void WriteASInputMemoryState(ASInputBuffer& buffer);
    void InitializeASInputBuffer(ASInputBuffer& buffer);
    void WriteDestroyASInputBuffer(ASInputBuffer& buffer);
    void EndAccelerationStructureSection(format::HandleId device_id);

    void WriteExecuteFromFile(const std::string& filename, uint32_t n_blocks, int64_t offset);

    void WriteDebugUtilsState(const VulkanStateTable& state_table);

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    util::ThreadData*        thread_data_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
    uint64_t                 blocks_written_{ 0 };

    // helper to retrieve a unique id, e.g. from a CaptureManager
    std::function<format::HandleId()> get_unique_id_;

    util::FileOutputStream* asset_file_stream_;
    std::string             asset_file_name_;
    AssetFileOffsetsInfo*   asset_file_offsets_;

    CommandWriter command_writer_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
