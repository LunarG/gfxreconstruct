/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_ADDRESS_REPLACER_H
#define GFXRECON_DECODE_VULKAN_ADDRESS_REPLACER_H

#include "util/linear_hashmap.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_device_address_tracker.h"
#include "graphics/vulkan_shader_group_handle.h"
#include "format/platform_types.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief   VulkanAddressReplacer can be used to check and potentially sanitize input-parameters for various cases.
 *
 * Important note: all internal Vulkan-API calls performed by this class are expected to be wrapped by calls to:
 * - decode::BeginInjectedCommands() / decode::EndInjectedCommands()
 */
class VulkanAddressReplacer
{
  public:
    VulkanAddressReplacer() = default;

    VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                          const graphics::VulkanDeviceTable*   device_table,
                          const graphics::VulkanInstanceTable* instance_table,
                          const decode::CommonObjectInfoTable& object_table);

    //! prevent copying
    VulkanAddressReplacer(const VulkanAddressReplacer&) = delete;

    //! allow moving
    VulkanAddressReplacer(VulkanAddressReplacer&& other) noexcept = default;

    ~VulkanAddressReplacer();

    /**
     * @brief   Set raytracing-related properties
     *
     * @param   physical_device_info    a physical-device info struct.
     */
    void SetRaytracingProperties(const decode::VulkanPhysicalDeviceInfo* physical_device_info);

    /**
     * @brief   UpdateBufferAddresses will replace buffer-device-address in gpu-memory,
     *          at locations pointed to by @param addresses.
     *
     * Replacement will be performed using a compute-dispatch injected into @param command_buffer_info.
     *
     * @param   command_buffer_info optional VulkanCommandBufferInfo* or nullptr to use an internal command-buffer
     * @param   addresses           array of device-addresses
     * @param   num_addresses       number of addresses
     * @param   address_tracker     const reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     */
    void UpdateBufferAddresses(const VulkanCommandBufferInfo*            command_buffer_info,
                               const VkDeviceAddress*                    addresses,
                               uint32_t                                  num_addresses,
                               const decode::VulkanDeviceAddressTracker& address_tracker);

    /**
     * @brief   ProcessCmdPushConstants will check and potentially correct input-parameters to 'vkCmdPushConstants',
     *          replacing any used buffer-device-addresses in-place.
     *
     * @param   command_buffer_info a provided const VulkanCommandBufferInfo*
     * @param   stage_flags         provided VkShaderStageFlags
     * @param   offset              data offset
     * @param   size                data size
     * @param   data                provided pointer to push-constant data
     * @param   address_tracker     const reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     */
    void ProcessCmdPushConstants(const VulkanCommandBufferInfo*            command_buffer_info,
                                 VkShaderStageFlags                        stage_flags,
                                 uint32_t                                  offset,
                                 uint32_t                                  size,
                                 void*                                     data,
                                 const decode::VulkanDeviceAddressTracker& address_tracker);

    /**
     * @brief   ProcessCmdBindDescriptorSets will check the bound descriptor-sets for presence of buffer-references
     *          and collect all addresses that will require replacement.
     *
     * The collected VkDeviceAddresses will be stored in @param command_buffer_info and depending on situation:
     *
     * a) if @param command_buffer_info is currently recording commands inside a renderpass:
     * - keep the data, defer replacement until QueueSubmit
     *
     * b) if @param command_buffer_info is outside any renderpass:
     * - consume collected addresses, inject call to UpdateBufferAddresses() into @param command_buffer_info
     *
     * @param   command_buffer_info a provided const VulkanCommandBufferInfo*
     * @param   pipelineBindPoint   the pipeline bind-point
     * @param   firstSet            index of first set
     * @param   descriptorSetCount  number of descriptor-sets
     * @param   pDescriptorSets     provided HandlePointerDecoder, containing descriptor-sets
     * @param   address_tracker     reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     *                              and storing newly created addresses
     */
    void ProcessCmdBindDescriptorSets(VulkanCommandBufferInfo*               command_buffer_info,
                                      VkPipelineBindPoint                    pipelineBindPoint,
                                      uint32_t                               firstSet,
                                      uint32_t                               descriptorSetCount,
                                      HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
                                      decode::VulkanDeviceAddressTracker&    address_tracker);

    /**
     * @brief   ProcessCmdTraceRays will check and potentially correct input-parameters to 'vkCmdTraceRays',
     *          like buffer-device-addresses and shader-group-handles.
     *
     * Depending on capture- and replay-device-properties one of the following strategies will be used:
     *
     * if the shader-binding-table (SBT) layout is compatible and group-handles are also valid:
     * - happy day, nothing to do!
     *
     * if the shader-binding-table (SBT) layout is compatible, but group-handles are invalid:
     * - Apply in-place correction of group-handles contained in SBT
     *
     * if the shader-binding-table (SBT) layout is not compatible:
     * - Create a shadow-SBT matching the replay-device's layout, map/copy group-handles to that, adjust input-addresses
     *
     * @param command_buffer_info   a provided VulkanCommandBufferInfo
     * @param raygen_sbt            ray-generation sbt
     * @param miss_sbt              ray-miss sbt
     * @param hit_sbt               ray-hit sbt
     * @param callable_sbt          ray-callable sbt
     * @param address_tracker       const reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     * @param group_handle_map      a map from capture- to replay-time group-handles
     */
    void ProcessCmdTraceRays(
        const VulkanCommandBufferInfo*                                                              command_buffer_info,
        VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
        const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
        const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map);

    /**
     * @brief   ProcessCmdBuildAccelerationStructuresKHR will check
     *          and potentially correct input-parameters to 'vkCmdBuildAccelerationStructuresKHR'
     *
     * Depending on capture- and replay-device-properties this includes the following:
     *
     * if replaying on same device/driver using the default-allocator (no -m rebind):
     * - happy day, nothing to do!
     *
     * if replaying on a different device/driver and/or using the rebind-allocator (via -m rebind):
     * - remap buffer-device-addresses for triangle-, aabb- and instance-geometries referenced in `build_geometry_infos`
     * - check buffer-sizes for acceleration-structures and scratch-buffers
     *      - if necessary, create shadow acceleration-structures and -buffers, adjust references
     * - apply in-place correction of acceleration-structure device-addresses referenced by top-level builds
     *
     * @param command_buffer_info   a provided VulkanCommandBufferInfo
     * @param info_count            number of elements in 'build_geometry_infos'
     * @param build_geometry_infos  provided array of VkAccelerationStructureBuildGeometryInfoKHR
     * @param build_range_infos     provided array of VkAccelerationStructureBuildRangeInfoKHR*
     * @param address_tracker       const reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     */
    void ProcessCmdBuildAccelerationStructuresKHR(const VulkanCommandBufferInfo*               command_buffer_info,
                                                  uint32_t                                     info_count,
                                                  VkAccelerationStructureBuildGeometryInfoKHR* build_geometry_infos,
                                                  VkAccelerationStructureBuildRangeInfoKHR**   build_range_infos,
                                                  const decode::VulkanDeviceAddressTracker&    address_tracker);

    /**
     * @brief   ProcessCmdCopyAccelerationStructuresKHR will check
     *          and potentially correct input-parameters to 'vkCmdCopyAccelerationStructuresKHR'
     *
     * @param   info                a provided VkCopyAccelerationStructureInfoKHR*
     * @param   address_tracker     const reference to a VulkanDeviceAddressTracker, used for mapping device-addresses
     */
    void ProcessCmdCopyAccelerationStructuresKHR(VkCopyAccelerationStructureInfoKHR*       info,
                                                 const decode::VulkanDeviceAddressTracker& address_tracker);

    /**
     * @brief   ProcessCmdWriteAccelerationStructuresPropertiesKHR will check
     *          and potentially correct input-parameters to 'vkCmdWriteAccelerationStructuresPropertiesKHR'
     *
     * @param   count                   element count in acceleration_structures
     * @param   acceleration_structures provided array of VkAccelerationStructureKHR-handles
     * @param   query_type              the query's type
     * @param   pool                    provided VkQuerypool handle
     * @param   first_query             index of first query
     */
    void ProcessCmdWriteAccelerationStructuresPropertiesKHR(uint32_t                    count,
                                                            VkAccelerationStructureKHR* acceleration_structures,
                                                            VkQueryType                 query_type,
                                                            VkQueryPool                 pool,
                                                            uint32_t                    first_query);

    /**
     * @brief   ProcessUpdateDescriptorSets will check
     *          and potentially correct input-parameters to 'vkUpdateDescriptorSets'
     *
     * @param   descriptor_write_count  element count in descriptor_writes
     * @param   descriptor_writes       provided array of VkWriteDescriptorSet
     * @param   descriptor_copy_count   element count in descriptor_copies
     * @param   descriptor_copies       provided array of VkCopyDescriptorSet
     */
    void ProcessUpdateDescriptorSets(uint32_t              descriptor_write_count,
                                     VkWriteDescriptorSet* descriptor_writes,
                                     uint32_t              descriptor_copy_count,
                                     VkCopyDescriptorSet*  descriptor_copies);

    /**
     * @brief   ProcessGetQueryPoolResults will check for running queries and attempt to extract information
     *          about acceleration-structure compactions-sizes.
     *
     * Should be run after vkGetQueryPoolResults has returned.
     *
     * @param   device      a VkDevice handle
     * @param   query_pool  a VkQueryPool handle
     * @param   firstQuery  index for first query
     * @param   queryCount  number of queries
     * @param   dataSize    datasize in bytes
     * @param   pData       provided data-pointer
     * @param   stride      provided stride in bytes
     * @param   flags       query result-flags
     */
    void ProcessGetQueryPoolResults(VkDevice           device,
                                    VkQueryPool        query_pool,
                                    uint32_t           firstQuery,
                                    uint32_t           queryCount,
                                    size_t             dataSize,
                                    void*              pData,
                                    VkDeviceSize       stride,
                                    VkQueryResultFlags flags);

    /**
     * @brief   Process information contained in a metadata-block in order to build acceleration-structures.
     *
     * Will use an internal command-buffer, submit work to a VkQueue and perform host-synchronization.
     *
     * @param   info_count              element count in 'geometry_infos'
     * @param   geometry_infos          provided array of VkAccelerationStructureBuildGeometryInfoKHR
     * @param   range_infos             provided array of pointers to VkAccelerationStructureBuildRangeInfoKHR
     * @param   address_tracker         const reference to a VulkanDeviceAddressTracker
     */
    void
    ProcessBuildVulkanAccelerationStructuresMetaCommand(uint32_t                                     info_count,
                                                        VkAccelerationStructureBuildGeometryInfoKHR* geometry_infos,
                                                        VkAccelerationStructureBuildRangeInfoKHR**   range_infos,
                                                        const decode::VulkanDeviceAddressTracker&    address_tracker);

    /**
     * @brief   Process information contained in a metadata-block in order to copy acceleration-structures.
     *
     * @param   info_count      element count in 'copy_infos'
     * @param   copy_infos      provided array of VkCopyAccelerationStructureInfoKHR
     * @param   address_tracker const reference to a VulkanDeviceAddressTracker
     */
    void ProcessCopyVulkanAccelerationStructuresMetaCommand(uint32_t                                  info_count,
                                                            VkCopyAccelerationStructureInfoKHR*       copy_infos,
                                                            const decode::VulkanDeviceAddressTracker& address_tracker);
    /**
     * @brief   Process information contained in a metadata-block in order to issue a query on internal an query-pool.
     *
     * Will use an internal command-buffer, submit work to a VkQueue and perform host-synchronization.
     *
     * @param   query_type              type of query
     * @param   acceleration_structure  provided acceleration-structure handle
     */
    void
    ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(VkQueryType                query_type,
                                                                  VkAccelerationStructureKHR acceleration_structure);

    /**
     * @brief   DestroyShadowResources should be called upon destruction of provided VkAccelerationStructureKHR handle,
     *          allowing this class to free potential resources associated with it.
     *
     * @param   handle  a provided VkAccelerationStructureKHR handle
     */
    void DestroyShadowResources(VkAccelerationStructureKHR handle);

    /**
     * @brief   DestroyShadowResources should be called upon destruction of provided VkCommandBuffer handle,
     *          allowing this class to free potential resources associated with it.
     *
     * @param   handle  a provided VkCommandBuffer handle
     */
    void DestroyShadowResources(VkCommandBuffer handle);

  private:
    struct buffer_context_t
    {
        decode::VulkanResourceAllocator*              resource_allocator = nullptr;
        uint32_t                                      num_bytes          = 0;
        VkDeviceMemory                                device_memory      = VK_NULL_HANDLE;
        VkBuffer                                      buffer             = VK_NULL_HANDLE;
        decode::VulkanResourceAllocator::ResourceData allocator_data{};
        decode::VulkanResourceAllocator::MemoryData   memory_data{};
        VkDeviceAddress                               device_address = 0;
        void*                                         mapped_data    = nullptr;
        std::string                                   name;

        buffer_context_t()                        = default;
        buffer_context_t(const buffer_context_t&) = delete;
        buffer_context_t(buffer_context_t&& other) noexcept;
        ~buffer_context_t();
        buffer_context_t& operator=(buffer_context_t other);
        void              swap(buffer_context_t& other);
    };

    struct pipeline_context_t
    {
        buffer_context_t input_handle_buffer  = {};
        buffer_context_t output_handle_buffer = {};

        //! this can hold either a linear hashmap or a sorted array of key/value pairs
        buffer_context_t storage_array = {};
    };

    struct acceleration_structure_asset_t
    {
        VkAccelerationStructureKHR handle  = VK_NULL_HANDLE;
        VkDeviceAddress            address = 0;
        buffer_context_t           storage = {};
        buffer_context_t           scratch = {};

        VkDevice                              device     = VK_NULL_HANDLE;
        PFN_vkDestroyAccelerationStructureKHR destroy_fn = nullptr;
        ~acceleration_structure_asset_t();
    };

    struct bda_element_t
    {
        VkDeviceAddress capture_address = 0;
        VkDeviceAddress replay_address  = 0;
        VkDeviceSize    size            = 0;
        bool            operator<(const bda_element_t& other) const { return capture_address < other.capture_address; }
    };

    [[nodiscard]] bool init_pipeline();

    [[nodiscard]] bool init_queue_assets();

    void update_global_hashmap(VkCommandBuffer command_buffer);

    void run_compute_replace(const VulkanCommandBufferInfo*            command_buffer_info,
                             const VkDeviceAddress*                    addresses,
                             uint32_t                                  num_addresses,
                             const decode::VulkanDeviceAddressTracker& address_tracker,
                             VkPipelineStageFlags                      sync_stage);

    [[nodiscard]] bool create_buffer(buffer_context_t&  buffer_context,
                                     size_t             num_bytes,
                                     uint32_t           usage_flags   = 0,
                                     uint32_t           min_alignment = 0,
                                     bool               use_host_mem  = true,
                                     const std::string& name          = "GFXR VulkanAddressReplacer Buffer");

    [[nodiscard]] bool create_acceleration_asset(acceleration_structure_asset_t& as_asset,
                                                 VkAccelerationStructureTypeKHR  type,
                                                 size_t                          num_buffer_bytes,
                                                 size_t                          num_scratch_bytes);

    void barrier(VkCommandBuffer      command_buffer,
                 VkBuffer             buffer,
                 VkPipelineStageFlags src_stage,
                 VkAccessFlags        src_access,
                 VkPipelineStageFlags dst_stage,
                 VkAccessFlags        dst_access);

    bool swap_acceleration_structure_handle(VkAccelerationStructureKHR& handle);

    const graphics::VulkanDeviceTable*                             device_table_      = nullptr;
    const decode::CommonObjectInfoTable*                           object_table_      = nullptr;
    VkPhysicalDeviceMemoryProperties                               memory_properties_ = {};
    std::optional<VkPhysicalDeviceRayTracingPipelinePropertiesKHR> capture_ray_properties_{}, replay_ray_properties_{};
    std::optional<VkPhysicalDeviceAccelerationStructurePropertiesKHR> replay_acceleration_structure_properties_{};
    bool                                                              valid_sbt_alignment_ = true;

    const decode::VulkanPhysicalDeviceInfo* physical_device_info_ = nullptr;
    VkDevice                                device_               = VK_NULL_HANDLE;
    decode::VulkanResourceAllocator*        resource_allocator_   = nullptr;

    // common layout used for all pipelines
    VkPipelineLayout pipeline_layout_ = VK_NULL_HANDLE;

    // pipeline dealing with shader-binding-table (SBT), replacing group-handles
    VkPipeline pipeline_sbt_ = VK_NULL_HANDLE;

    // pipeline dealing with buffer-device-addresses (BDA), replacing addresses
    VkPipeline pipeline_bda_ = VK_NULL_HANDLE;

    // pipeline enabling rehashing buffer-device-addresses (BDA), utility
    VkPipeline pipeline_bda_rehash_ = VK_NULL_HANDLE;

    // required assets for submitting meta-commands
    VkCommandPool   command_pool_   = VK_NULL_HANDLE;
    VkCommandBuffer command_buffer_ = VK_NULL_HANDLE;
    VkFence         fence_          = VK_NULL_HANDLE;
    VkQueue         queue_          = VK_NULL_HANDLE;
    VkQueryPool     query_pool_     = VK_NULL_HANDLE;

    util::linear_hashmap<graphics::shader_group_handle_t, graphics::shader_group_handle_t> hashmap_sbt_;
    std::unordered_map<VkCommandBuffer, buffer_context_t>                                  shadow_sbt_map_;

    std::vector<bda_element_t> storage_bda_binary_;

    // storage- and control-buffers for a global hashmap acting as address-filter
    buffer_context_t hashmap_storage_bda_binary_       = {};
    buffer_context_t hashmap_control_block_bda_binary_ = {};

    // pipeline-contexts per command-buffer
    std::unordered_map<VkCommandBuffer, std::vector<pipeline_context_t>> pipeline_context_map_;

    // resources related to acceleration-structures
    std::unordered_map<VkAccelerationStructureKHR, acceleration_structure_asset_t> shadow_as_map_;

    // currently running compaction queries. pool -> AS -> query-pool-index
    std::unordered_map<VkQueryPool, std::unordered_map<VkAccelerationStructureKHR, uint32_t>> as_compact_queries_;
    std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize>                              as_compact_sizes_;

    // required function pointers
    PFN_vkGetBufferDeviceAddress       get_device_address_fn_             = nullptr;
    PFN_vkGetPhysicalDeviceProperties2 get_physical_device_properties_fn_ = nullptr;
    PFN_vkSetDebugUtilsObjectNameEXT   set_debug_utils_object_name_fn_    = nullptr;
};
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_ADDRESS_REPLACER_H
