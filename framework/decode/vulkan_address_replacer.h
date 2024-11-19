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

#ifndef GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H
#define GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H

#include "util/linear_hashmap.h"
#include "decode/common_object_info_table.h"
#include "graphics/vulkan_shader_group_handle.h"
#include "format/platform_types.h"
#include "vulkan_device_address_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanAddressReplacer
{
  public:
    VulkanAddressReplacer() = default;

    VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                          const encode::VulkanDeviceTable*     device_table,
                          const decode::CommonObjectInfoTable& object_table);

    //! prevent copying
    VulkanAddressReplacer(const VulkanAddressReplacer&) = delete;

    //! allow moving
    VulkanAddressReplacer(VulkanAddressReplacer&& other) noexcept;

    ~VulkanAddressReplacer();

    void ProcessCmdTraceRays(
        const VulkanCommandBufferInfo*                                                              command_buffer_info,
        VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
        VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
        const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
        const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map);

    void ProcessCmdBuildAccelerationStructuresKHR(const VulkanCommandBufferInfo*               command_buffer_info,
                                                  uint32_t                                     info_count,
                                                  VkAccelerationStructureBuildGeometryInfoKHR* build_geometry_infos,
                                                  const decode::VulkanDeviceAddressTracker&    address_tracker);

    friend void swap(VulkanAddressReplacer& lhs, VulkanAddressReplacer& rhs) noexcept;

  private:
    struct buffer_context_t
    {
        decode::VulkanResourceAllocator*              resource_allocator = nullptr;
        VkDeviceMemory                                device_memory      = VK_NULL_HANDLE;
        VkBuffer                                      buffer             = VK_NULL_HANDLE;
        decode::VulkanResourceAllocator::ResourceData allocator_data{};
        decode::VulkanResourceAllocator::MemoryData   memory_data{};
        VkDeviceAddress                               device_address = 0;
        uint32_t                                      num_bytes      = 0;
        void*                                         mapped_data    = nullptr;
        ~buffer_context_t();
    };

    void init_pipeline();

    bool create_buffer(size_t num_bytes, buffer_context_t& buffer_context);

    void barrier(VkCommandBuffer      command_buffer,
                 VkBuffer             buffer,
                 VkPipelineStageFlags src_stage,
                 VkAccessFlags        src_access,
                 VkPipelineStageFlags dst_stage,
                 VkAccessFlags        dst_access);

    const encode::VulkanDeviceTable*                device_table_      = nullptr;
    VkPhysicalDeviceMemoryProperties                memory_properties_ = {};
    VkPhysicalDeviceRayTracingPipelinePropertiesKHR capture_ray_properties_{}, replay_ray_properties_{};
    bool                                            valid_sbt_alignment_ = true;

    VkDevice                         device_                = VK_NULL_HANDLE;
    PFN_vkGetBufferDeviceAddress     get_device_address_fn_ = nullptr;
    decode::VulkanResourceAllocator* resource_allocator_    = nullptr;
    VkPipelineLayout                 pipeline_layout_       = VK_NULL_HANDLE;
    VkPipeline                       pipeline_              = VK_NULL_HANDLE;

    buffer_context_t input_handle_buffer_  = {};
    buffer_context_t output_handle_buffer_ = {};
    buffer_context_t hashmap_storage_      = {};

    util::linear_hashmap<graphics::shader_group_handle_t, graphics::shader_group_handle_t> handle_hashmap_;
    util::linear_hashmap<VkDeviceAddress, VkDeviceAddress>                                 address_hashmap_;
    std::unordered_map<VkStridedDeviceAddressRegionKHR*, buffer_context_t>                 shadow_sbt_map_;
};
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_ADDRESS_REPLACER_H
