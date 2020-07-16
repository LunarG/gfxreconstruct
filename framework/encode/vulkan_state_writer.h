/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
#define GFXRECON_ENCODE_VULKAN_STATE_WRITER_H

#include "encode/parameter_encoder.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_table.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_dispatch_table.h"
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

    // Returns number of bytes written to the output_stream.
    void WriteState(const VulkanStateTable& state_table, uint64_t frame_number);

  private:
    // Data structures for processing resource memory snapshots.
    struct BufferSnapshotInfo
    {
        const BufferWrapper*       buffer_wrapper{ nullptr };
        const DeviceMemoryWrapper* memory_wrapper{ nullptr };
        VkMemoryPropertyFlags      memory_properties{};
        bool                       need_staging_copy{ false };
    };

    struct ImageSnapshotInfo
    {
        const ImageWrapper*        image_wrapper{ nullptr };
        const DeviceMemoryWrapper* memory_wrapper{ nullptr };
        VkMemoryPropertyFlags      memory_properties{};
        bool                       need_staging_copy{ false };
        VkImageAspectFlagBits      aspect{};
        VkDeviceSize               resource_size{ 0 }; // Combined size of all sub-resources.
        std::vector<uint64_t>      level_sizes;        // Combined size of all layers in a mip level.
    };

    struct ResourceSnapshotInfo
    {
        std::vector<BufferSnapshotInfo> buffers;
        std::vector<ImageSnapshotInfo>  images;
    };

    typedef std::unordered_map<uint32_t, ResourceSnapshotInfo>                         ResourceSnapshotQueueFamilyTable;
    typedef std::unordered_map<const DeviceWrapper*, ResourceSnapshotQueueFamilyTable> DeviceResourceTables;

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

    void WriteFenceState(const VulkanStateTable& state_table);

    void WriteEventState(const VulkanStateTable& state_table);

    void WriteSemaphoreState(const VulkanStateTable& state_table);

    void WriteBufferViewState(const VulkanStateTable& state_table);

    void WriteImageViewState(const VulkanStateTable& state_table);

    void WriteFramebufferState(const VulkanStateTable& state_table);

    void WritePipelineLayoutState(const VulkanStateTable& state_table);

    void WritePipelineState(const VulkanStateTable& state_table);

    void WriteDescriptorSetState(const VulkanStateTable& state_table);

    void WriteQueryPoolState(const VulkanStateTable& state_table);

    void WriteSurfaceKhrState(const VulkanStateTable& state_table);

    void WriteSwapchainKhrState(const VulkanStateTable& state_table);

    void WriteDeviceMemoryState(const VulkanStateTable& state_table);

    void
    ProcessHardwareBuffer(format::HandleId memory_id, AHardwareBuffer* hardware_buffer, VkDeviceSize allocation_size);

    void ProcessBufferMemory(const DeviceWrapper*                   device_wrapper,
                             const std::vector<BufferSnapshotInfo>& buffer_snapshot_info,
                             uint32_t                               queue_family_index,
                             VkQueue                                queue,
                             VkCommandBuffer                        command_buffer,
                             VkBuffer                               staging_buffer,
                             VkDeviceMemory                         staging_memory,
                             bool                                   is_staging_memory_coherent);

    void ProcessImageMemory(const DeviceWrapper*                  device_wrapper,
                            const std::vector<ImageSnapshotInfo>& image_snapshot_info,
                            uint32_t                              queue_family_index,
                            VkQueue                               queue,
                            VkCommandBuffer                       command_buffer,
                            VkBuffer                              staging_buffer,
                            VkDeviceMemory                        staging_memory,
                            bool                                  is_staging_memory_coherent,
                            const VulkanStateTable&               state_table);

    void WriteBufferMemoryState(const VulkanStateTable& state_table,
                                DeviceResourceTables*   resources,
                                VkDeviceSize*           max_resource_size,
                                VkDeviceSize*           max_staging_copy_size);

    void WriteImageMemoryState(const VulkanStateTable& state_table,
                               DeviceResourceTables*   resources,
                               VkDeviceSize*           max_resource_size,
                               VkDeviceSize*           max_staging_copy_size);

    void WriteImageSubresourceLayouts(const ImageWrapper* image_wrapper, VkImageAspectFlags aspect_flags);

    void WriteResourceMemoryState(const VulkanStateTable& state_table);

    void WriteMappedMemoryState(const VulkanStateTable& state_table);

    void WriteSwapchainImageState(const VulkanStateTable& state_table);

    void WritePhysicalDevicePropertiesMetaData(const PhysicalDeviceWrapper* physical_device_wrapper);

    template <typename T>
    void WriteGetPhysicalDeviceQueueFamilyProperties(format::ApiCallId call_id,
                                                     format::HandleId  physical_device_id,
                                                     uint32_t          property_count,
                                                     T*                properties);

    void WriteGetPhysicalDeviceSurfaceSupport(format::HandleId physical_device_id,
                                              uint32_t         queue_family_index,
                                              format::HandleId surface_id,
                                              VkBool32         supported);

    void WriteGetPhysicalDeviceSurfaceCapabilities(format::HandleId                physical_device_id,
                                                   format::HandleId                surface_id,
                                                   const VkSurfaceCapabilitiesKHR& capabilities);

    void WriteGetPhysicalDeviceSurfaceFormats(format::HandleId          physical_device_id,
                                              format::HandleId          surface_id,
                                              uint32_t                  format_count,
                                              const VkSurfaceFormatKHR* formats);

    void WriteGetPhysicalDeviceSurfacePresentModes(format::HandleId        physical_device_id,
                                                   format::HandleId        surface_id,
                                                   uint32_t                mode_count,
                                                   const VkPresentModeKHR* pPresentModes);

    void WriteCommandProcessingCreateCommands(format::HandleId device_id,
                                              uint32_t         queue_family_index,
                                              format::HandleId queue_id,
                                              format::HandleId command_pool_id,
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

    void WriteCommandBufferCommands(const CommandBufferWrapper* wrapper, const VulkanStateTable& state_table);

    void WriteDescriptorUpdateCommand(format::HandleId      device_id,
                                      const DescriptorInfo* binding,
                                      VkWriteDescriptorSet* write);

    void WriteQueryPoolReset(format::HandleId                            device_id,
                             const std::vector<const QueryPoolWrapper*>& query_pool_wrappers);

    void WriteQueryActivation(format::HandleId           device_id,
                              uint32_t                   queue_family_index,
                              const QueryActivationList& active_queries);

    void WriteCreateFence(format::HandleId device_id, format::HandleId fence_id, bool signaled);

    void WriteSetEvent(format::HandleId device_id, format::HandleId event_id);

    void WriteDestroyDeviceObject(format::ApiCallId            call_id,
                                  format::HandleId             device_id,
                                  format::HandleId             object_id,
                                  const VkAllocationCallbacks* allocator);

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

    VkMemoryPropertyFlags GetMemoryProperties(const DeviceWrapper*       device_wrapper,
                                              const DeviceMemoryWrapper* memory_wrapper,
                                              const VulkanStateTable&    state_table);

    bool FindMemoryTypeIndex(const DeviceWrapper*    device_wrapper,
                             uint32_t                memory_type_bits,
                             VkMemoryPropertyFlags   desired_flags,
                             uint32_t*               found_index,
                             VkMemoryPropertyFlags*  found_flags,
                             const VulkanStateTable& state_table) const;

    void InvalidateMappedMemoryRange(const DeviceWrapper* device_wrapper,
                                     VkDeviceMemory       memory,
                                     VkDeviceSize         offset,
                                     VkDeviceSize         size);

    void GetFenceStatus(const DeviceWrapper* device_wrapper, VkFence fence, bool* result);

    VkQueue GetQueue(const DeviceWrapper* device_wrapper, uint32_t queue_family_index, uint32_t queue_index);

    VkCommandPool GetCommandPool(const DeviceWrapper* device_wrapper, uint32_t queue_family_index);

    VkCommandBuffer GetCommandBuffer(const DeviceWrapper* device_wrapper, VkCommandPool command_pool);

    VkResult SubmitCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer, const DeviceTable* device_table);

    VkResult CreateStagingBuffer(const DeviceWrapper*    device_wrapper,
                                 VkDeviceSize            size,
                                 VkBuffer*               buffer,
                                 VkDeviceMemory*         memory,
                                 VkMemoryPropertyFlags*  memory_property_flags,
                                 const VulkanStateTable& state_table);

    VkResult ResolveImage(const DeviceWrapper*    device_wrapper,
                          const ImageWrapper*     image_wrapper,
                          VkQueue                 queue,
                          VkCommandBuffer         command_buffer,
                          VkImage*                resolve_image,
                          VkDeviceMemory*         resolve_memory,
                          const VulkanStateTable& state_table);

    VkImageAspectFlags GetFormatAspectMask(VkFormat format);

    void GetFormatAspects(VkFormat format, std::vector<VkImageAspectFlagBits>* aspects, bool* combined_depth_stencil);

    VkFormat GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect);

    void GetImageSizes(const ImageWrapper* image_wrapper, ImageSnapshotInfo* info);

    bool CheckCommandHandles(const CommandBufferWrapper* wrapper, const VulkanStateTable& state_table);

    bool
    CheckCommandHandle(CommandHandleType handle_type, format::HandleId handle, const VulkanStateTable& state_table);

    bool CheckDescriptorStatus(const DescriptorInfo* descriptor, uint32_t index, const VulkanStateTable& state_table);

    bool IsBufferValid(format::HandleId buffer_id, const VulkanStateTable& state_table);

    bool IsBufferViewValid(format::HandleId view_id, const VulkanStateTable& state_table);

    bool IsImageValid(format::HandleId image_id, const VulkanStateTable& state_table);

    bool IsImageViewValid(format::HandleId view_id, const VulkanStateTable& state_table);

    bool IsFramebufferValid(format::HandleId framebuffer_id, const VulkanStateTable& state_table);

    bool IsFramebufferValid(const FramebufferWrapper* framebuffer_wrapper, const VulkanStateTable& state_table);

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
