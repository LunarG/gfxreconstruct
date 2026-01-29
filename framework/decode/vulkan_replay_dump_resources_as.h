/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_AS_H
#define GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_AS_H

#include "decode/vulkan_device_address_tracker.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "util/defines.h"

#include <variant>
#include <unordered_map>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct AccelerationStructureDumpResourcesContext
{
    AccelerationStructureDumpResourcesContext() = delete;

    AccelerationStructureDumpResourcesContext(const VulkanAccelerationStructureKHRInfo* ai,
                                              const graphics::VulkanDeviceTable&        dt,
                                              const CommonObjectInfoTable&              oit,
                                              const VulkanPerDeviceAddressTrackers&     at) :
        as_info(ai),
        device_table(dt), object_info_table(oit), address_trackers(at)
    {}

    ~AccelerationStructureDumpResourcesContext() { ReleaseResources(); }

    struct Triangles
    {
        VkFormat       vertex_format{ VK_FORMAT_UNDEFINED };
        uint32_t       max_vertex{ 0 };
        VkDeviceSize   vertex_buffer_size{ 0 };
        VkDeviceSize   vertex_buffer_stride{ 0 };
        VkBuffer       vertex_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory vertex_buffer_memory{ VK_NULL_HANDLE };

        VkIndexType    index_type{ VK_INDEX_TYPE_NONE_KHR };
        VkDeviceSize   index_buffer_size{ 0 };
        VkBuffer       index_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory index_buffer_memory{ VK_NULL_HANDLE };

        VkDeviceSize   transform_buffer_size{ 0 };
        VkBuffer       transform_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory transform_buffer_memory{ VK_NULL_HANDLE };

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct AABBS
    {
        VkDeviceSize   buffer_size{ 0 };
        VkBuffer       buffer{ VK_NULL_HANDLE };
        VkDeviceMemory buffer_memory{ VK_NULL_HANDLE };

        VkAccelerationStructureBuildRangeInfoKHR range;
    };

    struct Instances
    {
        bool array_of_pointers{ false };

        uint32_t       instance_count{ 0 };
        uint32_t       instance_buffer_size{ 0 };
        VkBuffer       instance_buffer{ VK_NULL_HANDLE };
        VkDeviceMemory instance_buffer_memory{ VK_NULL_HANDLE };

        // Used to fetch the instance buffers in case
        // VkAccelerationStructureGeometryInstancesDataKHR.arrayOfPointers is true
        VkPipeline       compute_ppl{ VK_NULL_HANDLE };
        VkPipelineLayout compute_ppl_layout{ VK_NULL_HANDLE };
    };

    std::vector<std::variant<std::monostate, Triangles, AABBS, Instances>> as_build_objects;

    struct
    {
        VkDeviceSize   size{ 0 };
        VkBuffer       buffer{ VK_NULL_HANDLE };
        VkDeviceMemory memory{ VK_NULL_HANDLE };
    } serialized_data;

    // Clones buffers used as inputs in vkCmdBuildAccelerationStructuresKHR command.
    VkResult CloneBuildAccelerationStructuresInputBuffers(
        VkCommandBuffer                                            original_command_buffer,
        const Decoded_VkAccelerationStructureBuildGeometryInfoKHR* p_infos_meta,
        const VkAccelerationStructureBuildRangeInfoKHR*            range_infos,
        bool                                                       dump_as_build_input_buffers);

    // Clones input buffers from src_context
    VkResult CloneBuildAccelerationStructuresInputBuffers(VkCommandBuffer original_command_buffer,
                                                          const AccelerationStructureDumpResourcesContext& src_context,
                                                          bool dump_as_build_input_buffers);

    void ReleaseResources();

    const graphics::VulkanDeviceTable&        device_table;
    const CommonObjectInfoTable&              object_info_table;
    const VulkanAccelerationStructureKHRInfo* as_info;
    const VulkanPerDeviceAddressTrackers&     address_trackers;
};

using DumpResourcesAccelerationStructuresContext =
    std::unordered_map<const VulkanAccelerationStructureKHRInfo*,
                       std::shared_ptr<AccelerationStructureDumpResourcesContext>>;

void FreeAccelerationStructureContextResources(const graphics::VulkanDeviceTable&         device_table,
                                               VkDevice                                   device,
                                               AccelerationStructureDumpResourcesContext& as_context);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_AS_H
