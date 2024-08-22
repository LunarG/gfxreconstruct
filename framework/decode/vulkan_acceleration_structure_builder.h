/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_ACCELERATION_STRUCTURE_BUILDER_H
#define GFXRECON_DECODE_VULKAN_ACCELERATION_STRUCTURE_BUILDER_H

#include "decode/vulkan_resource_allocator.h"
#include "decode/descriptor_update_template_decoder.h"
#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_buffer_tracker.h"
#include "decode/vulkan_internal_buffer_manager.h"
#include "util/defines.h"

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: Consider support of indirect calls
// TODO: Consider support of CmdPushDescriptorSet/CmdPushDescriptorSetWithTemplate
class VulkanAccelerationStructureBuilder
{
  public:
    VulkanAccelerationStructureBuilder(
        const encode::VulkanDeviceTable*                 device_table,
        const PhysicalDeviceInfo*                        physical_device_info,
        VkDevice                                         device,
        VulkanResourceAllocator*                         allocator,
        const VkPhysicalDeviceMemoryProperties&          properties,
        VkPhysicalDeviceRayTracingPipelinePropertiesKHR  ray_tracing_pipeline_properties,
        VkPhysicalDeviceAccelerationStructureFeaturesKHR acceleration_structure_features,
        VulkanBufferTracker*                             buffer_tracker);

    ~VulkanAccelerationStructureBuilder();

    // Modifies vkUpdateDescriptorSets parameters
    // Descriptior set update may contain acceleration structure references that need an update
    void UpdateDescriptorSets(uint32_t              descriptor_write_count,
                              VkWriteDescriptorSet* descriptor_writes,
                              uint32_t              descriptor_copy_count,
                              VkCopyDescriptorSet*  descriptor_copies);

   void
         StoreDeferredDeviceAddressBufferUpdates(const std::vector<BufferInfo*>&                   buffer_infos,
                                                 const std::vector<const VkDescriptorBufferInfo*>& descriptor_buffer_infos);

    // Modifies vkDescriptorSetWithTemplateKHR parameters
    // Descriptior set update may contain acceleration structure references that need an update
    void UpdateDescriptorSetWithTemplateKHR(VkDescriptorSet                                    descriptor_set,
                                            const VkDescriptorUpdateTemplateEntryKHR&          entry,
                                            gfxrecon::decode::DescriptorUpdateTemplateDecoder* data);

    // Overrides vkCmdBuildAccelerationStructures call
    // Used to recreate all the buffers with correct sizes for AS build process along with the AS itself
    // TODO: Convert this override to pre call 
    void CmdBuildAccelerationStructures(VkCommandBuffer                              command_buffer,
                                        uint32_t                                     info_count,
                                        VkAccelerationStructureBuildGeometryInfoKHR* geometry_infos,
                                        VkAccelerationStructureBuildRangeInfoKHR**   range_infos);

    // Overrides CmdCopyAccelerationStructure call
    // Recreates destination acceleration structure with correct size for compacting copy
    // TODO: Non-compacting copy
    // TODO: Convert this override to pre call 
    void CmdCopyAccelerationStructure(VkCommandBuffer command_buffer, VkCopyAccelerationStructureInfoKHR* copy_info);

    // Overrides CmdWriteAccelerationStructuresProperties call
    // Stores size data required for handling compacted copy commands
    // TODO: Convert this override to pre call
    void CmdWriteAccelerationStructuresProperties(VkCommandBuffer             command_buffer,
                                                  uint32_t                    count,
                                                  VkAccelerationStructureKHR* acceleration_structures,
                                                  VkQueryType                 query_type,
                                                  VkQueryPool                 pool,
                                                  uint32_t                    first_query);

    void OnDestroyBuffer(const BufferInfo* buffer_info);

    // On creation of the acceleration structure, start tracking it by handle and original device address
    void OnCreateAccelerationStructure(VkAccelerationStructureKHR     handle,
                                       VkDeviceAddress                device_address,
                                       VkAccelerationStructureTypeKHR type);

    // On destroy acceleration structure, clean up the internal replacement structure
    void OnDestroyAccelerationStructure(const AccelerationStructureKHRInfo* acceleration_structure_info);

    // Recreates acceleration structures built before the trim range
    void ProcessBuildVulkanAccelerationStructuresMetaCommand(
        uint32_t                                                      info_count,
        VkAccelerationStructureBuildGeometryInfoKHR*                  geometry_infos,
        VkAccelerationStructureBuildRangeInfoKHR**                    range_infos,
        std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers_data);

    // Recreates acceleration structures copy targets executed before the trim range
    void ProcessCopyVulkanAccelerationStructuresMetaCommand(uint32_t                            info_count,
                                                            VkCopyAccelerationStructureInfoKHR* copy_infos);

    void
    ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(VkQueryType                query_type,
                                                                  VkAccelerationStructureKHR acceleration_structure);

    // For each submitted buffer, if it contains a TLAS build command, update its instance buffer
    // with replacement BLAS address
    // Also check whether there are descriptor sets the needs the acceleration structure handle replaced
    void OnQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits);

    // Execute actions post queue present
    void PostQueuePresent();

    // Update VkStridedDeviceAddressRegionKHR:
    // pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable
    // Updates buffer device addresses
    // TODO: strides and offsets
    void OnCmdTraceRaysKHR(VkCommandBuffer                  command_buffer,
                           VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                           VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                           VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                           VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable);

    // called before command gets executed
    // the query pool results contain the AS compacted sizes
    // inject duplicate of this command that puts the results in internal buffer
    void OnCmdCopyQueryPoolResults(const CommandBufferInfo* command_buffer_info, const QueryPoolInfo* query_pool_info);

    // called before command gets executed
    // inject duplicate of this command to retrieve compact sizes
    void OnGetQueryPoolResults(const DeviceInfo* device_info, const QueryPoolInfo* query_pool_info);

    void RegisterShaderGroupHandleEntry(uint32_t group_count,
                                        size_t   data_size,
                                        uint8_t* original_data,
                                        uint8_t* runtime_data);

    VkDeviceAddress GetActualDeviceAddress(VkAccelerationStructureKHR handle);

    void RegisterInstanceBufferStagingUpdate(VkCommandBuffer                       command_buffer,
                                             VulkanResourceAllocator::ResourceData src_buffer_allocator_data,
                                             VkDeviceSize                          src_offset,
                                             VkBuffer                              dst_buffer);

  private:
    // TODO: Just use device table?
    void InitializeFunctionPointers(const encode::VulkanDeviceTable* device_table);
    struct Functions
    {
        PFN_vkGetAccelerationStructureBuildSizesKHR       get_acceleration_structure_build_sizes{ nullptr };
        PFN_vkCreateAccelerationStructureKHR              create_acceleration_structure{ nullptr };
        PFN_vkCmdBuildAccelerationStructuresKHR           cmd_build_acceleration_structures{ nullptr };
        PFN_vkGetAccelerationStructureDeviceAddressKHR    get_acceleration_structure_device_address{ nullptr };
        PFN_vkCmdCopyAccelerationStructureKHR             cmd_copy_acceleration_structure{ nullptr };
        PFN_vkCmdWriteAccelerationStructuresPropertiesKHR cmd_write_acceleration_structures_properties{ nullptr };
        PFN_vkDestroyAccelerationStructureKHR             destroy_acceleration_structure{ nullptr };
        PFN_vkCreateCommandPool                           create_command_pool{ nullptr };
        PFN_vkDestroyCommandPool                          destroy_command_pool{ nullptr };
        PFN_vkAllocateCommandBuffers                      allocate_command_buffers{ nullptr };
        PFN_vkFreeCommandBuffers                          free_command_buffers{ nullptr };
        PFN_vkGetDeviceQueue                              get_device_queue{ nullptr };
        PFN_vkBeginCommandBuffer                          begin_command_buffer{ nullptr };
        PFN_vkEndCommandBuffer                            end_command_buffer{ nullptr };
        PFN_vkResetCommandBuffer                          reset_command_buffer{ nullptr };
        PFN_vkQueueSubmit                                 queue_submit{ nullptr };
        PFN_vkQueueWaitIdle                               queue_wait_idle{ nullptr };
        PFN_vkUpdateDescriptorSets                        update_descriptor_sets{ nullptr };
        PFN_vkGetQueryPoolResults                         get_query_pool_results{ nullptr };
        PFN_vkCmdCopyQueryPoolResults                     cmd_copy_query_pool_results{ nullptr };
        PFN_vkCmdPipelineBarrier                          cmd_pipeline_barrier{ nullptr };
        PFN_vkCreateQueryPool                             create_query_pool{ nullptr };
    };

  private:
    struct ShaderGroupHandleEntry
    {
        std::vector<uint8_t> original_data_;
        std::vector<uint8_t> runtime_data_;
        ShaderGroupHandleEntry(uint8_t* original_data, uint8_t* runtime_data, size_t size) :
            original_data_(original_data, original_data + size), runtime_data_(runtime_data, runtime_data + size)
        {}
    };
    std::vector<ShaderGroupHandleEntry> shader_group_handle_entries_;

    // Stores basic information about the tracked acceleration structures
    struct AccelerationStructureEntry
    {
        // Device address of acceleration structure recorded at capture
        VkDeviceAddress                             original_address_;
        // Device address of acceleration structure recorded at replay
        VkDeviceAddress                             new_address_;
        std::set<VkAccelerationStructureKHR>        handles_;
        VkAccelerationStructureTypeKHR              type_;
        VkAccelerationStructureBuildSizesInfoKHR    size_info_;
        // Stores AS that should be used instead of the one pointed by handle_
        std::unique_ptr<AccelerationStructureEntry> replacement_acceleration_struct_;

        std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper> storage_;

        AccelerationStructureEntry(VkDeviceAddress                          original_address,
                                   VkDeviceAddress                          new_address,
                                   VkAccelerationStructureKHR               handle,
                                   VkAccelerationStructureTypeKHR           type,
                                   VkAccelerationStructureBuildSizesInfoKHR size_info) :
            original_address_(original_address),
            new_address_(new_address), type_(type), size_info_(size_info)
        {
            handles_.insert(handle);
        }

        bool IsAlias(VkAccelerationStructureKHR handle) { return handles_.count(handle) > 0; }
    };

    // Store the minimum required data to perform vkUpdateDescriptorSets with correct acceleration
    // structure handle OnQueueSubmit
    struct DescriptorWriteData
    {
        VkWriteDescriptorSet                         write_;
        VkWriteDescriptorSetAccelerationStructureKHR p_next_data;
        std::vector<VkAccelerationStructureKHR>      acc_structs_data;

        DescriptorWriteData(const VkWriteDescriptorSet& descriptor_write)
        {
            p_next_data =
                *reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(descriptor_write.pNext);

            write_       = descriptor_write;
            write_.pNext = &p_next_data;

            acc_structs_data.reserve(p_next_data.accelerationStructureCount);
            std::copy(p_next_data.pAccelerationStructures,
                      p_next_data.pAccelerationStructures + p_next_data.accelerationStructureCount,
                      std::back_inserter(acc_structs_data));
            p_next_data.pAccelerationStructures = acc_structs_data.data();
        }

        DescriptorWriteData(VkDescriptorSet                                    descriptor_set,
                            const VkDescriptorUpdateTemplateEntryKHR&          template_update_entry,
                            gfxrecon::decode::DescriptorUpdateTemplateDecoder* data)
        {
            write_ = VkWriteDescriptorSet{ .sType           = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
                                           .pNext           = nullptr,
                                           .dstSet          = descriptor_set,
                                           .dstBinding      = template_update_entry.dstBinding,
                                           .dstArrayElement = template_update_entry.dstArrayElement,
                                           .descriptorCount =
                                               static_cast<uint32_t>(data->GetAccelerationStructureKHRCount()),
                                           .descriptorType = VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR };

            p_next_data = VkWriteDescriptorSetAccelerationStructureKHR{
                .sType                      = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR,
                .pNext                      = nullptr,
                .accelerationStructureCount = write_.descriptorCount,
                .pAccelerationStructures    = nullptr
            };

            acc_structs_data.reserve(p_next_data.accelerationStructureCount);
            std::copy(data->GetAccelerationStructureKHRPointer(),
                      data->GetAccelerationStructureKHRPointer() + p_next_data.accelerationStructureCount,
                      std::back_inserter(acc_structs_data));

            p_next_data.pAccelerationStructures = acc_structs_data.data();
            write_.pNext                        = &p_next_data;
        }
    };

    struct DescriptorUpdateBufferEntries
    {
        DescriptorUpdateBufferEntries() = default;
        DescriptorUpdateBufferEntries(uint32_t size) : size_(size), infos_(size), offsets_(size), ranges_(size) {}

        uint32_t                  size_{};
        std::vector<BufferInfo*>  infos_;
        std::vector<VkDeviceSize> offsets_;
        std::vector<VkDeviceSize> ranges_;
    };

    // This objects are internal and responsible for executing the state recreation meta commands
    struct CommandExecuteObjects
    {
        CommandExecuteObjects() = default;
        ~CommandExecuteObjects()
        {
            if (initialized_)
            {
                free_command_buffers_(device_, pool_, 1, &command_buffer_);
                destroy_command_pool_(device_, pool_, nullptr);
            }
        }
        PFN_vkFreeCommandBuffers free_command_buffers_{ nullptr };
        PFN_vkDestroyCommandPool destroy_command_pool_{ nullptr };

        VkDevice        device_{ VK_NULL_HANDLE };
        VkCommandPool   pool_{ VK_NULL_HANDLE };
        VkCommandBuffer command_buffer_{ VK_NULL_HANDLE };
        VkQueue         queue_{ VK_NULL_HANDLE };
        bool            initialized_{ false };
    };

  private:
    Functions                        functions_;
    const PhysicalDeviceInfo*        physical_device_info_;
    VkDevice                         device_;
    VulkanResourceAllocator*         allocator_;
    VkPhysicalDeviceMemoryProperties physical_device_memory_properties_;

    VulkanBufferTracker* buffer_tracker_;
    // TODO: buffers_ is only used by fast forwarding flow. Check if it's necessary and remove if possible
    std::vector<BufferInfo*>* buffers_;

    VulkanInternalBufferManager internal_buffer_manager_;

    VkQueue                                                  queue_with_buffer_write_ = VK_NULL_HANDLE;
    std::vector<std::unique_ptr<AccelerationStructureEntry>> acceleration_structures_;

    std::unordered_map<VkAccelerationStructureKHR, DescriptorWriteData> cached_descriptor_write_;
    std::vector<DescriptorUpdateBufferEntries>                          deferred_inspection_buffers_;

    struct DoubleBufferScratch
    {
        std::unordered_map<format::HandleId,
                           std::vector<std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>>>
            scratches_previous;
        std::unordered_map<format::HandleId,
                           std::vector<std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>>>
            scratches_current;
    } scratch_double_buffer_;

    struct RaytracingPipelineProperties
    {
        const uint32_t shader_group_handle_size;
        const uint32_t shader_group_handle_alignment;
        const uint32_t shader_group_handle_size_aligned;
        RaytracingPipelineProperties(const uint32_t handle_size, const uint32_t handle_alignment) :
            shader_group_handle_size(handle_size), shader_group_handle_alignment(handle_alignment),
            shader_group_handle_size_aligned((shader_group_handle_size + shader_group_handle_alignment - 1) &
                                             ~(shader_group_handle_alignment - 1))
        {}
    } raytracing_pipeline_properties_;

    struct CmdTraceRaysEntry
    {
        VkStridedDeviceAddressRegionKHR raygen;
        VkStridedDeviceAddressRegionKHR miss;
        VkStridedDeviceAddressRegionKHR hit;
        VkStridedDeviceAddressRegionKHR callable;
    };
    std::unordered_map<VkCommandBuffer, std::vector<CmdTraceRaysEntry>> trace_rays_;

    std::unordered_map<
        VkCommandBuffer,
        std::vector<
            std::tuple<VulkanResourceAllocator::ResourceData, VkDeviceSize, VkAccelerationStructureBuildRangeInfoKHR>>>
        instance_buffer_updates_;

    // holds data needed in the scenario of instance data being passed through a staging buffer:
    // instance data gets written to buffer A and then copied via vkCmdCopyBuffer to buffer B, whilst being in
    // the same command buffer as the tlas build command using that data
    std::unordered_map<VkCommandBuffer,
                       std::vector<std::tuple<VulkanResourceAllocator::ResourceData, VkDeviceSize, VkBuffer>>>
        instance_buffer_staging_updates_;

    // holds information gathered during vkCmdCopyQueryPoolResults that needs to be processed before
    // vkCmdCopyAccelerationStructureKHR in order to know replacement AS compressed sizes
    std::unordered_map<VkQueryPool,
                       std::vector<std::tuple<uint32_t,
                                              std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>,
                                              std::vector<VkAccelerationStructureKHR>>>>
        compacted_sizes_unprocessed_;
    // map containing relation between uncompacted AS capture id and the size of compacted AS
    std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize> compacted_sizes_processed_;

    // This object is internal and responsible for executing the state recreation meta commands
    CommandExecuteObjects cmd_execute_obj_;

    VkPhysicalDeviceRayTracingPipelinePropertiesKHR  ray_tracing_pipeline_properties_;
    VkPhysicalDeviceAccelerationStructureFeaturesKHR acceleration_structure_features_;

  private:
    AccelerationStructureEntry* GetAccelerationStructureEntry(VkAccelerationStructureKHR acceleration_struct);
    bool                        UpdateAccelerationStructDeviceAddress(VkDeviceAddress& address);
    void                        UpdateDeviceAddress(VkCommandBuffer                              command_buffer,
                                                    VkAccelerationStructureBuildGeometryInfoKHR& build_geometry,
                                                    VkAccelerationStructureBuildRangeInfoKHR*    range_infos);

    VkDeviceAddress GetAccelerationStructureDeviceAddress(VkAccelerationStructureKHR acceleration_structure);

    VkAccelerationStructureKHR CreateAccelerationStructure(VkAccelerationStructureBuildGeometryInfoKHR& geometry_info,
                                                           VkAccelerationStructureBuildRangeInfoKHR*    range_info,
                                                           const VkAccelerationStructureBuildSizesInfoKHR& size_info,
                                                           VkBuffer                                        storage);

    VkAccelerationStructureBuildSizesInfoKHR
    GetAccelerationStructureSizeInfo(VkAccelerationStructureBuildGeometryInfoKHR* geometry_info,
                                     VkAccelerationStructureBuildRangeInfoKHR*    range_info);

    void UpdateInstanceBuffer(VkCommandBuffer                                  command_buffer,
                              VkAccelerationStructureGeometryInstancesDataKHR& instances,
                              const VkAccelerationStructureBuildRangeInfoKHR&  build_range);

    void UpdateInstanceBufferContent(VulkanResourceAllocator::ResourceData    instance_buffer_allocator_data,
                                     VkDeviceSize                             offset,
                                     VkAccelerationStructureBuildRangeInfoKHR build_range);

    void InitializeInternalExecObjects();
    void BeginCommandBuffer();
    void ExecuteCommandBuffer();
    void UpdateShaderBindingTable(const VkStridedDeviceAddressRegionKHR& sbt_entry);
    void UpdateScratchDeviceAddress(VkAccelerationStructureBuildGeometryInfoKHR& geometry_infos,
                                    VkDeviceSize                                 scratch_size);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ACCELERATION_STRUCTURE_BUILDER_H
