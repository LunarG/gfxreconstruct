/*
** Copyright (c) 2019 LunarG, Inc.
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
    VulkanStateWriter(util::FileOutputStream*                               output_stream,
                      util::Compressor*                                     compressor,
                      format::ThreadId                                      thread_id,
                      const std::unordered_map<DispatchKey, InstanceTable>* instance_tables,
                      const std::unordered_map<DispatchKey, DeviceTable>*   device_tables);

    ~VulkanStateWriter();

    // Returns number of bytes written to the output_stream.
    void WriteState(const VulkanStateTable& state_table);

  private:
    // Data structures for processing resource memory snapshots.
    struct BufferSnapshotEntry
    {
        const BufferWrapper*       buffer_wrapper{ nullptr };
        const DeviceMemoryWrapper* memory_wrapper{ nullptr };
        bool                       is_host_visible{ false };
        bool                       is_host_coherent{ false };
    };

    struct ImageSnapshotEntry
    {
        const ImageWrapper*        image_wrapper{ nullptr };
        const DeviceMemoryWrapper* memory_wrapper{ nullptr };
        bool                       is_host_visible{ false };
        bool                       is_host_coherent{ false };
        VkImageAspectFlagBits      aspect{};
        VkDeviceSize               resource_size{ 0 }; // Combined size of all sub-resources.
        std::vector<VkDeviceSize>  level_sizes;        // Combined size of all layers in a mip level.
    };

    typedef std::vector<BufferSnapshotEntry>                 BufferSnapshotList;
    typedef std::unordered_map<uint32_t, BufferSnapshotList> BufferSnapshotQueueFamilyTable;
    typedef std::vector<ImageSnapshotEntry>                  ImageSnapshotList;

    struct ImageSnapshotListPair
    {
        ImageSnapshotList map_copy_wrappers;
        ImageSnapshotList staging_copy_wrappers;
    };

    typedef std::unordered_map<uint32_t, ImageSnapshotListPair> ImageSnapshotQueueFamilyTable;

    struct BufferSnapshotData
    {
        BufferSnapshotList             map_copy_wrappers;
        BufferSnapshotQueueFamilyTable staging_copy_wrappers;
        VkDeviceSize                   max_staging_copy_size{ 0 };
        VkDeviceSize                   max_device_local_buffer_size{ 0 };
        uint32_t                       num_device_local_buffers{ 0 };
    };

    struct ImageSnapshotData
    {
        ImageSnapshotQueueFamilyTable copy_wrappers;
        VkDeviceSize                  max_staging_copy_size{ 0 };
        VkDeviceSize                  max_device_local_image_size{ 0 };
        uint32_t                      num_device_local_images{ 0 };
    };

  private:
    void WritePhysicalDeviceState(const VulkanStateTable& state_table);

    void WriteDeviceState(const VulkanStateTable& state_table);

    void WriteCommandBufferState(const VulkanStateTable& state_table);

    void WriteFenceState(const VulkanStateTable& state_table);

    void WriteEventState(const VulkanStateTable& state_table);

    void WriteSemaphoreState(const VulkanStateTable& state_table);

    void WriteBufferState(const VulkanStateTable& state_table);

    void WriteImageState(const VulkanStateTable& state_table);

    void WriteFramebufferState(const VulkanStateTable& state_table);

    void WritePipelineLayoutState(const VulkanStateTable& state_table);

    void WritePipelineState(const VulkanStateTable& state_table);

    void WriteDescriptorSetState(const VulkanStateTable& state_table);

    void WriteSurfaceKhrState(const VulkanStateTable& state_table);

    void WriteSwapchainKhrState(const VulkanStateTable& state_table);

    void ProcessBufferMemory(VkDevice                  device,
                             const BufferSnapshotData& snapshot_data,
                             const VulkanStateTable&   state_table,
                             const DeviceTable&        dispatch_table);

    void ProcessImageMemory(VkDevice                 device,
                            const ImageSnapshotData& snapshot_data,
                            const VulkanStateTable&  state_table,
                            const DeviceTable&       dispatch_table);

    void WriteMappedMemoryState(const VulkanStateTable& state_table);

    void WriteSwapchainImageState(const VulkanStateTable& state_table);

    template <typename T>
    void WriteGetPhysicalDeviceQueueFamilyProperties(format::ApiCallId call_id,
                                                     VkPhysicalDevice  physical_device,
                                                     uint32_t          property_count,
                                                     T*                properties);

    void WriteGetPhysicalDeviceSurfaceSupport(VkPhysicalDevice physical_device,
                                              uint32_t         queue_family_index,
                                              VkSurfaceKHR     surface,
                                              VkBool32         supported);

    void WriteGetPhysicalDeviceSurfaceCapabilities(VkPhysicalDevice                physical_device,
                                                   VkSurfaceKHR                    surface,
                                                   const VkSurfaceCapabilitiesKHR& capabilities);

    void WriteGetPhysicalDeviceSurfaceFormats(VkPhysicalDevice          physical_device,
                                              VkSurfaceKHR              surface,
                                              uint32_t                  format_count,
                                              const VkSurfaceFormatKHR* formats);

    void WriteGetPhysicalDeviceSurfacePresentModes(VkPhysicalDevice        physical_device,
                                                   VkSurfaceKHR            surface,
                                                   uint32_t                mode_count,
                                                   const VkPresentModeKHR* pPresentModes);

    void WriteStagingBufferCreateCommands(VkDevice                    device,
                                          VkDeviceSize                buffer_size,
                                          VkBuffer                    buffer,
                                          const VkMemoryRequirements& memory_requirements,
                                          uint32_t                    memory_type_index,
                                          VkDeviceMemory              memory);

    void WriteCommandProcessingCreateCommands(VkDevice        device,
                                              uint32_t        queue_family_index,
                                              VkQueue         queue,
                                              VkCommandPool   command_pool,
                                              VkCommandBuffer command_buffer);

    void WriteMappedMemoryCopyCommands(VkDevice           device,
                                       VkDeviceMemory     source_memory,
                                       const void*        source_data,
                                       VkDeviceSize       source_offset,
                                       VkDeviceSize       source_size,
                                       VkDeviceMemory     replay_memory,
                                       VkDeviceSize       replay_offset,
                                       VkDeviceSize       replay_size,
                                       const DeviceTable& dispatch_table);

    void WriteBufferCopyCommandExecution(VkQueue         queue,
                                         VkCommandBuffer command_buffer,
                                         VkBuffer        source,
                                         VkBuffer        destination,
                                         VkDeviceSize    source_offset,
                                         VkDeviceSize    destination_offset,
                                         VkDeviceSize    size);

    void WriteImageCopyCommandExecution(VkQueue                  queue,
                                        VkCommandBuffer          command_buffer,
                                        VkBuffer                 source,
                                        VkImage                  destination,
                                        VkImageLayout            final_layout,
                                        uint32_t                 copy_regions_size,
                                        const VkBufferImageCopy* copy_regions,
                                        VkImageAspectFlags       transition_aspect);

    void WriteImageLayoutTransitionCommand(VkCommandBuffer      command_buffer,
                                           VkImage              image,
                                           VkPipelineStageFlags src_stages,
                                           VkPipelineStageFlags dst_stages,
                                           VkAccessFlags        src_access,
                                           VkAccessFlags        dst_access,
                                           VkImageLayout        src_layout,
                                           VkImageLayout        dst_layout,
                                           uint32_t             mip_levels,
                                           uint32_t             array_layers,
                                           VkImageAspectFlags   aspect);

    void WriteImageLayoutTransitionCommandExecution(VkQueue              queue,
                                                    VkCommandBuffer      command_buffer,
                                                    VkImage              image,
                                                    VkPipelineStageFlags src_stages,
                                                    VkPipelineStageFlags dst_stages,
                                                    VkAccessFlags        src_access,
                                                    VkAccessFlags        dst_access,
                                                    VkImageLayout        src_layout,
                                                    VkImageLayout        dst_layout,
                                                    uint32_t             mip_levels,
                                                    uint32_t             array_layers,
                                                    VkImageAspectFlags   aspect);

    void WriteCommandBegin(VkCommandBuffer command_buffer);

    void WriteCommandEnd(VkCommandBuffer command_buffer);

    void WriteCommandExecution(VkQueue                queue,
                               uint32_t               command_buffer_count,
                               const VkCommandBuffer* command_buffers,
                               uint32_t               signal_semaphore_count,
                               const VkSemaphore*     signal_semaphores,
                               uint32_t               wait_semaphore_count,
                               const VkSemaphore*     wait_semaphores);

    void WriteCommandBufferCommands(const CommandBufferWrapper* wrapper);

    void WriteDescriptorUpdateCommand(VkDevice device, const DescriptorInfo* binding, VkWriteDescriptorSet* write);

    void WriteAcquireNextImage(
        VkDevice device, VkSwapchainKHR swapchain, VkSemaphore semaphore, VkFence fence, uint32_t image_index);

    void WriteQueuePresent(VkQueue queue, VkSwapchainKHR swapchain, uint32_t image_index);

    void WriteCreateFence(VkDevice device, VkFence fence, bool signaled);

    void WriteWaitForFence(VkDevice device, VkFence fence);

    void WriteResetFence(VkDevice device, VkFence fence);

    void WriteSetEvent(VkDevice device, VkEvent event);

    void WriteDestroyDeviceObject(format::ApiCallId            call_id,
                                  format::HandleId             device_id,
                                  format::HandleId             object_id,
                                  const VkAllocationCallbacks* allocator);

    void DestroyTemporaryDeviceObject(format::ApiCallId         call_id,
                                      format::HandleId          object_id,
                                      util::MemoryOutputStream* create_parameters);

    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data);

    void WriteResizeWindowCmd(VkSurfaceKHR surface, uint32_t width, uint32_t height);

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

    void GetFenceStatus(VkDevice device, VkFence fence, bool* result);

    VkMemoryPropertyFlags
    GetMemoryProperties(VkDevice device, VkDeviceMemory memory, const VulkanStateTable& state_table);

    uint32_t FindMemoryTypeIndex(VkDevice                device,
                                 uint32_t                memory_type_bits,
                                 VkMemoryPropertyFlags   memory_property_flags,
                                 const VulkanStateTable& state_table);

    VkQueue
    GetQueue(VkDevice device, uint32_t queue_family_index, uint32_t queue_index, const DeviceTable& dispatch_table);

    VkCommandPool GetCommandPool(VkDevice device, uint32_t queue_family_index, const DeviceTable& dispatch_table);

    VkCommandBuffer GetCommandBuffer(VkDevice device, VkCommandPool command_pool, const DeviceTable& dispatch_table);

    VkResult SubmitCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer, const DeviceTable& dispatch_table);

    VkResult CreateStagingBuffer(VkDevice                device,
                                 VkDeviceSize            size,
                                 VkBuffer*               buffer,
                                 VkMemoryRequirements*   memory_requirements,
                                 uint32_t*               memory_type_index,
                                 VkDeviceMemory*         memory,
                                 const VulkanStateTable& state_table,
                                 const DeviceTable&      dispatch_table);

    VkImageAspectFlags GetFormatAspectMask(VkFormat format);

    VkFormat GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect);

    void GetImageSizes(const ImageWrapper* image_wrapper, ImageSnapshotEntry* entry, const DeviceTable& dispatch_table);

    void UpdateImageSnapshotSizes(VkDeviceSize       size,
                                  bool               is_host_visible,
                                  bool               use_staging_copy,
                                  ImageSnapshotData* snapshot_data);

    void InsertImageSnapshotEntries(const ImageWrapper*        image_wrapper,
                                    const DeviceMemoryWrapper* memory_wrapper,
                                    bool                       is_host_visible,
                                    bool                       is_host_coherent,
                                    bool                       use_staging_copy,
                                    VkImageAspectFlags         aspect_mask,
                                    ImageSnapshotList*         insert_list,
                                    ImageSnapshotData*         snapshot_data,
                                    const DeviceTable&         dispatch_table);

  private:
    util::FileOutputStream*  output_stream_;
    util::Compressor*        compressor_;
    std::vector<uint8_t>     compressed_parameter_buffer_;
    format::ThreadId         thread_id_;
    util::MemoryOutputStream parameter_stream_;
    ParameterEncoder         encoder_;

    // TODO: Dispatch tables should be available from handle wrappers.
    const std::unordered_map<DispatchKey, InstanceTable>* instance_tables_;
    const std::unordered_map<DispatchKey, DeviceTable>*   device_tables_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_WRITER_H
