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
        bool                       is_host_visible{ 0 };
    };

    struct ImageSnapshotEntry
    {
        const ImageWrapper*        image_wrapper{ nullptr };
        const DeviceMemoryWrapper* memory_wrapper{ nullptr };
        bool                       is_host_visible{ 0 };
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
    void WriteDeviceState(const VulkanStateTable& state_table);

    void WriteBufferState(const VulkanStateTable& state_table);

    void WriteImageState(const VulkanStateTable& state_table);

    void WriteFramebufferState(const VulkanStateTable& state_table);

    void WritePipelineLayoutState(const VulkanStateTable& state_table);

    void WritePipelineState(const VulkanStateTable& state_table);

    void ProcessBufferMemory(VkDevice                  device,
                             const BufferSnapshotData& snapshot_data,
                             const VulkanStateTable&   state_table,
                             const DeviceTable&        dispatch_table);

    void ProcessImageMemory(VkDevice                 device,
                            const ImageSnapshotData& snapshot_data,
                            const VulkanStateTable&  state_table,
                            const DeviceTable&       dispatch_table);

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
                                        const VkBufferImageCopy* copy_regions);

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

    void WriteCommandExecution(VkQueue queue, VkCommandBuffer command_buffer);

    void WriteDestroyDeviceObject(format::ApiCallId            call_id,
                                  format::HandleId             device_id,
                                  format::HandleId             object_id,
                                  const VkAllocationCallbacks* allocator);

    void DestroyTemporaryDeviceObject(format::ApiCallId         call_id,
                                      format::HandleId          object_id,
                                      util::MemoryOutputStream* create_parameters);

    void WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer);

    void WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data);

    template <typename Wrapper>
    void StandardCreateWrite(const VulkanStateTable& state_table)
    {
        state_table.VisitWrappers([=](const Wrapper* wrapper) {
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        });
    }

    VkMemoryPropertyFlags
    GetMemoryProperties(VkDevice device, VkDeviceMemory memory, const VulkanStateTable& state_table);

    uint32_t FindMemoryTypeIndex(VkDevice                device,
                                 uint32_t                memory_type_bits,
                                 VkMemoryPropertyFlags   memory_property_flags,
                                 const VulkanStateTable& state_table);

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
