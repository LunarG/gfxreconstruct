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

#include "decode/vulkan_replay_dump_resources_copy_array_of_pointers.h"
#include "decode/vulkan_replay_dump_resources_as.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "generated/generated_vulkan_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct PushConstantBlock
{
    VkDeviceAddress array_of_pointers;
    VkDeviceAddress out_buffer;
    uint32_t        count;
};

static VkResult CreateComputeResources(const graphics::VulkanDeviceTable& device_table,
                                       VkDevice                           device,
                                       VkPipeline*                        compute_ppl,
                                       VkPipelineLayout*                  ppl_layout)
{
    GFXRECON_ASSERT(compute_ppl != nullptr);
    GFXRECON_ASSERT(ppl_layout != nullptr);

    // We'll be using push constants to upload the device addresses to the compute shader
    const VkPushConstantRange        push_constant_range{ VK_SHADER_STAGE_COMPUTE_BIT, 0, sizeof(PushConstantBlock) };
    const VkPipelineLayoutCreateInfo pipelineLayoutCI{
        VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO, nullptr, 0, 0, nullptr, 1, &push_constant_range
    };

    VkResult res = device_table.CreatePipelineLayout(device, &pipelineLayoutCI, nullptr, ppl_layout);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("vkCreatePipelineLayout failed (%s)", util::ToString(res).c_str());
        return res;
    }

    const VkShaderModuleCreateInfo sci = {
        VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO, nullptr, 0, sizeof(g_CompShaderMain), g_CompShaderMain
    };
    VkShaderModule compute_shader;
    res = device_table.CreateShaderModule(device, &sci, nullptr, &compute_shader);
    if (res != VK_SUCCESS)
    {
        device_table.DestroyPipelineLayout(device, *ppl_layout, nullptr);
        GFXRECON_LOG_WARNING("vkCreateShaderModule failed (%s)", util::ToString(res).c_str());
        return res;
    }

    const VkPipelineShaderStageCreateInfo stage_ci = { VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
                                                       nullptr,
                                                       0,
                                                       VK_SHADER_STAGE_COMPUTE_BIT,
                                                       compute_shader,
                                                       "ComputeMain",
                                                       nullptr };

    const VkComputePipelineCreateInfo ppl_ci = {
        VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO, nullptr, 0, stage_ci, *ppl_layout, VK_NULL_HANDLE, 0
    };

    res = device_table.CreateComputePipelines(device, VK_NULL_HANDLE, 1, &ppl_ci, nullptr, compute_ppl);
    if (res != VK_SUCCESS)
    {
        device_table.DestroyPipelineLayout(device, *ppl_layout, nullptr);
        GFXRECON_LOG_WARNING("vkCreateComputePipelines failed (%s)", util::ToString(res).c_str());
    }

    device_table.DestroyShaderModule(device, compute_shader, nullptr);

    return VK_SUCCESS;
}

VkResult AccelerationStructureDumpResourcesContext::CloneBuildAccelerationStructuresInputBuffers(
    VkCommandBuffer                                            original_command_buffer,
    const Decoded_VkAccelerationStructureBuildGeometryInfoKHR* p_infos_meta,
    const VkAccelerationStructureBuildRangeInfoKHR*            range_infos,
    bool                                                       dump_as_build_input_buffers)
{
    const auto* p_infos = p_infos_meta->decoded_value;

    if (p_infos->pGeometries == nullptr)
    {
        return VK_SUCCESS;
    }

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(as_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    // kVulkanBuildAccelerationStructuresCommand will not have a command buffer like
    // vkCmdBuildAccelerationStructuresKHR. We create one so we can submit our commands.
    TemporaryCommandBuffer temp_cmd_buff;
    if (original_command_buffer == VK_NULL_HANDLE)
    {
        CreateAndBeginCommandBuffer(&FindComputeQueueFamilyIndex, device_info, device_table, temp_cmd_buff);
        GFXRECON_ASSERT(temp_cmd_buff.command_buffer != VK_NULL_HANDLE);
    }

    const VkDevice        device = device_info->handle;
    const VkCommandBuffer command_buffer =
        original_command_buffer == VK_NULL_HANDLE ? temp_cmd_buff.command_buffer : original_command_buffer;

    GFXRECON_ASSERT(p_infos_meta->pGeometries != nullptr);
    const auto* p_geometries_meta = p_infos_meta->pGeometries->GetMetaStructPointer();

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(phys_dev_info != nullptr);

    const VkPhysicalDeviceMemoryProperties& mem_props = phys_dev_info->replay_device_info->memory_properties.value();

    const auto address_tracker_entry = address_trackers.find(device_info);
    if (address_tracker_entry == address_trackers.end())
    {
        GFXRECON_LOG_WARNING("Could not detect address tracker for device %" PRIu64, device_info->capture_id);
        return VK_ERROR_UNKNOWN;
    }

    const VulkanDeviceAddressTracker& device_address_tracker = address_tracker_entry->second;

    for (uint32_t g = 0; g < p_infos->geometryCount; ++g)
    {
        // Either pGeometries or ppGeometries is used. The other one must be NULL
        const VkAccelerationStructureGeometryKHR* const geometry =
            p_infos->pGeometries != nullptr ? &p_infos->pGeometries[g] : p_infos->ppGeometries[g];

        switch (geometry->geometryType)
        {
            case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            {
                // If dumping build input buffers is not requested then we only care about getting the TLAS instance
                // buffer.
                if (!dump_as_build_input_buffers)
                {
                    continue;
                }

                auto& new_variant = as_build_objects.emplace_back(
                    std::in_place_type<AccelerationStructureDumpResourcesContext::Triangles>);
                auto& new_triangles = std::get<AccelerationStructureDumpResourcesContext::Triangles>(new_variant);

                const VkAccelerationStructureBuildRangeInfoKHR&        range     = range_infos[g];
                const VkAccelerationStructureGeometryTrianglesDataKHR& triangles = geometry->geometry.triangles;

                size_t                  buffer_device_address_offset;
                const VulkanBufferInfo* vertex_buffer_info = device_address_tracker.GetBufferByCaptureDeviceAddress(
                    triangles.vertexData.deviceAddress, &buffer_device_address_offset);
                if (vertex_buffer_info == nullptr)
                {
                    continue;
                }

                GFXRECON_ASSERT(vertex_buffer_info->size > buffer_device_address_offset);

                size_t vertex_buffer_size = (triangles.maxVertex + 1) * triangles.vertexStride;
                // Check if we are exceeding the size of the input vertex buffer. This could happen in case of
                // malformed data (too much maxVertex).
                if (buffer_device_address_offset + vertex_buffer_size > vertex_buffer_info->size)
                {
                    vertex_buffer_size = vertex_buffer_info->size - buffer_device_address_offset;
                }

                new_triangles.vertex_format        = triangles.vertexFormat;
                new_triangles.max_vertex           = triangles.maxVertex;
                new_triangles.vertex_buffer_size   = vertex_buffer_size;
                new_triangles.vertex_buffer_stride = triangles.vertexStride;
                new_triangles.range                = range;

                VkResult res = CreateVkBuffer(vertex_buffer_size,
                                              device_table,
                                              device,
                                              nullptr,
                                              nullptr,
                                              &mem_props,
                                              VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                              &new_triangles.vertex_buffer,
                                              &new_triangles.vertex_buffer_memory);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Failed cloning vertex buffer used as input in "
                                       "vkCmdBuildAccelerationstructuresKHR (%s)",
                                       util::ToString(res).c_str());
                    continue;
                }

                // Copy vertex buffer
                const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{
                    static_cast<VkDeviceSize>(buffer_device_address_offset), 0, vertex_buffer_size } };
                CopyBufferAndBarrier(
                    command_buffer, device_table, vertex_buffer_info->handle, new_triangles.vertex_buffer, copy_region);

                // Index buffer
                new_triangles.index_type = triangles.indexType;
                if (triangles.indexType != VK_INDEX_TYPE_NONE_KHR)
                {
                    const VulkanBufferInfo* index_buffer_info = device_address_tracker.GetBufferByCaptureDeviceAddress(
                        triangles.indexData.deviceAddress, &buffer_device_address_offset);

                    if (index_buffer_info != nullptr)
                    {
                        const size_t index_buffer_size =
                            3 * range.primitiveCount * VkIndexTypeToBytes(triangles.indexType);
                        new_triangles.index_type        = triangles.indexType;
                        new_triangles.index_buffer_size = index_buffer_size;

                        res = CreateVkBuffer(index_buffer_size,
                                             device_table,
                                             device,
                                             nullptr,
                                             nullptr,
                                             &mem_props,
                                             VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                             &new_triangles.index_buffer,
                                             &new_triangles.index_buffer_memory);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Failed cloning index buffer used as input in "
                                               "vkCmdBuildAccelerationstructuresKHR (%s)",
                                               util::ToString(res).c_str());

                            continue;
                        }

                        // Copy Index buffer
                        const VkDeviceSize src_offset = static_cast<VkDeviceSize>(range.primitiveOffset) +
                                                        static_cast<VkDeviceSize>(buffer_device_address_offset);
                        const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ src_offset, 0, index_buffer_size } };
                        CopyBufferAndBarrier(command_buffer,
                                             device_table,
                                             index_buffer_info->handle,
                                             new_triangles.index_buffer,
                                             copy_region);
                    }
                }

                // Transformation matrix
                if (triangles.transformData.deviceAddress)
                {
                    const VulkanBufferInfo* transform_buffer_info =
                        device_address_tracker.GetBufferByCaptureDeviceAddress(triangles.transformData.deviceAddress,
                                                                               &buffer_device_address_offset);
                    if (transform_buffer_info == nullptr)
                    {
                        continue;
                    }

                    const size_t transform_buffer_size  = sizeof(VkTransformMatrixKHR);
                    new_triangles.transform_buffer_size = transform_buffer_size;

                    res = CreateVkBuffer(transform_buffer_size,
                                         device_table,
                                         device,
                                         nullptr,
                                         nullptr,
                                         &mem_props,
                                         VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                         &new_triangles.transform_buffer,
                                         &new_triangles.transform_buffer_memory);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Failed cloning transform buffer used as input in "
                                           "vkCmdBuildAccelerationstructuresKHR (%s)",
                                           util::ToString(res).c_str());

                        continue;
                    }

                    // Copy transform buffer
                    const VkDeviceSize src_offset = static_cast<VkDeviceSize>(buffer_device_address_offset);
                    const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{
                        src_offset, 0, static_cast<VkDeviceSize>(transform_buffer_size) } };
                    CopyBufferAndBarrier(command_buffer,
                                         device_table,
                                         transform_buffer_info->handle,
                                         new_triangles.transform_buffer,
                                         copy_region);
                }
            }
            break;

            case VK_GEOMETRY_TYPE_AABBS_KHR:
            {
                // If dumping build input buffers is not requested then we only care about getting the TLAS instance
                // buffer.
                if (!dump_as_build_input_buffers)
                {
                    continue;
                }

                const VkAccelerationStructureGeometryAabbsDataKHR& aabbs = geometry->geometry.aabbs;

                size_t                  buffer_device_address_offset;
                const VulkanBufferInfo* aabb_buffer_info = device_address_tracker.GetBufferByCaptureDeviceAddress(
                    aabbs.data.deviceAddress, &buffer_device_address_offset);
                GFXRECON_ASSERT(aabb_buffer_info != nullptr);
                if (aabb_buffer_info == nullptr)
                {
                    continue;
                }

                auto& new_variant =
                    as_build_objects.emplace_back(std::in_place_type<AccelerationStructureDumpResourcesContext::AABBS>);
                auto& new_aabbs = std::get<AccelerationStructureDumpResourcesContext::AABBS>(new_variant);

                const VkAccelerationStructureBuildRangeInfoKHR& range = range_infos[g];
                new_aabbs.buffer_size = range.primitiveCount * sizeof(VkAabbPositionsKHR);
                new_aabbs.range       = range;

                VkResult res = CreateVkBuffer(new_aabbs.buffer_size,
                                              device_table,
                                              device,
                                              nullptr,
                                              nullptr,
                                              &mem_props,
                                              VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                              &new_aabbs.buffer,
                                              &new_aabbs.buffer_memory);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Failed cloning AABB buffer used as input in "
                                       "vkCmdBuildAccelerationstructuresKHR (%s)",
                                       util::ToString(res).c_str());

                    continue;
                }

                // Copy AABBs
                {
                    // Spec does not explicity state what happens for 0 stride.
                    // We will assume tightly packed data.
                    const size_t region_count =
                        (aabbs.stride == sizeof(VkAabbPositionsKHR) || !aabbs.stride) ? 1 : range.primitiveCount;

                    const VkDeviceSize src_buffer_offset = static_cast<VkDeviceSize>(buffer_device_address_offset) +
                                                           static_cast<VkDeviceSize>(range.primitiveOffset);

                    std::vector<VkBufferCopy> regions(region_count);
                    if (region_count == 1)
                    {
                        regions[0].dstOffset = 0;
                        regions[0].srcOffset = src_buffer_offset;
                        regions[0].size      = new_aabbs.buffer_size;
                    }
                    else
                    {
                        VkDeviceSize       src_region_offset = src_buffer_offset;
                        VkDeviceSize       dst_region_offset = 0;
                        const VkDeviceSize region_size       = static_cast<VkDeviceSize>(sizeof(VkAabbPositionsKHR));
                        for (auto& region : regions)
                        {
                            region.srcOffset = src_region_offset;
                            src_region_offset += aabbs.stride;

                            region.dstOffset = dst_region_offset;
                            dst_region_offset += region_size;

                            region.size = region_size;
                        }
                    }

                    CopyBufferAndBarrier(
                        command_buffer, device_table, aabb_buffer_info->handle, new_aabbs.buffer, regions);
                }
            }
            break;

            case VK_GEOMETRY_TYPE_INSTANCES_KHR:
            {
                const VkAccelerationStructureBuildRangeInfoKHR&        range     = range_infos[g];
                const VkAccelerationStructureGeometryInstancesDataKHR& instances = geometry->geometry.instances;

                auto& new_variant = as_build_objects.emplace_back(
                    std::in_place_type<AccelerationStructureDumpResourcesContext::Instances>);
                auto& new_instances = std::get<AccelerationStructureDumpResourcesContext::Instances>(new_variant);
                new_instances.array_of_pointers = instances.arrayOfPointers;

                // Addresses and VkAccelerationStructureInstanceKHR structures should be tightly packed
                const size_t instance_buffer_stride = sizeof(VkAccelerationStructureInstanceKHR);
                const size_t instance_buffer_size   = range.primitiveCount * instance_buffer_stride;
                new_instances.instance_count        = range.primitiveCount;
                new_instances.instance_buffer_size  = instance_buffer_size;

                size_t                  buffer_device_address_offset;
                const VulkanBufferInfo* instances_buffer_info = device_address_tracker.GetBufferByCaptureDeviceAddress(
                    instances.data.deviceAddress, &buffer_device_address_offset);
                if (instances_buffer_info == nullptr)
                {
                    continue;
                }

                if (!instances.arrayOfPointers)
                {
                    VkResult res = CreateVkBuffer(instance_buffer_size,
                                                  device_table,
                                                  device,
                                                  nullptr,
                                                  nullptr,
                                                  &mem_props,
                                                  VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                                  &new_instances.instance_buffer,
                                                  &new_instances.instance_buffer_memory);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Failed cloning instances buffer used as input in "
                                           "vkCmdBuildAccelerationstructuresKHR (%s)",
                                           util::ToString(res).c_str());
                        continue;
                    }

                    // Copy instance buffer
                    const VkDeviceSize src_offset = static_cast<VkDeviceSize>(buffer_device_address_offset) +
                                                    static_cast<VkDeviceSize>(range.primitiveOffset);
                    const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ src_offset, 0, instance_buffer_size } };
                    CopyBufferAndBarrier(command_buffer,
                                         device_table,
                                         instances_buffer_info->handle,
                                         new_instances.instance_buffer,
                                         copy_region);
                }
                else
                {
                    // If instances.arrayOfPointers is true then we go through a compute path
                    CreateComputeResources(
                        device_table, device, &new_instances.compute_ppl, &new_instances.compute_ppl_layout);

                    // In this case we will also need VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT
                    VkResult res =
                        CreateVkBuffer(instance_buffer_size,
                                       device_table,
                                       device,
                                       nullptr,
                                       nullptr,
                                       &mem_props,
                                       VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                                           VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                       &new_instances.instance_buffer,
                                       &new_instances.instance_buffer_memory);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Failed cloning instances buffer used as input in "
                                           "vkCmdBuildAccelerationstructuresKHR (%s)",
                                           util::ToString(res).c_str());
                        continue;
                    }

                    const VkBufferDeviceAddressInfo bdai = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO,
                                                             nullptr,
                                                             new_instances.instance_buffer };
                    const VkDeviceAddress           output_buffer_device_address =
                        device_table.GetBufferDeviceAddress(device, &bdai);

                    device_table.CmdBindPipeline(
                        command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, new_instances.compute_ppl);

                    const PushConstantBlock references{ instances.data.deviceAddress,
                                                        output_buffer_device_address,
                                                        range.primitiveCount };
                    device_table.CmdPushConstants(command_buffer,
                                                  new_instances.compute_ppl_layout,
                                                  VK_SHADER_STAGE_COMPUTE_BIT,
                                                  0,
                                                  sizeof(PushConstantBlock),
                                                  &references);

                    device_table.CmdDispatch(command_buffer, 1, 1, 1);

                    const VkBufferMemoryBarrier buff_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                                 nullptr,
                                                                 VK_ACCESS_SHADER_WRITE_BIT,
                                                                 VK_ACCESS_TRANSFER_READ_BIT | VK_ACCESS_HOST_READ_BIT,
                                                                 VK_QUEUE_FAMILY_IGNORED,
                                                                 VK_QUEUE_FAMILY_IGNORED,
                                                                 new_instances.instance_buffer,
                                                                 0,
                                                                 VK_WHOLE_SIZE };
                    device_table.CmdPipelineBarrier(command_buffer,
                                                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                                    VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                    0,
                                                    0,
                                                    nullptr,
                                                    1,
                                                    &buff_barrier,
                                                    0,
                                                    nullptr);
                }
            }
            break;

            default:
                GFXRECON_LOG_ERROR("Unhandled acceleration structure geometry type")
        }
    }

    if (original_command_buffer == nullptr)
    {
        SubmitAndDestroyCommandBuffer(temp_cmd_buff);
    }

    return VK_SUCCESS;
}

VkResult AccelerationStructureDumpResourcesContext::CloneBuildAccelerationStructuresInputBuffers(
    VkCommandBuffer                                  original_command_buffer,
    const AccelerationStructureDumpResourcesContext& src_context,
    bool                                             dump_as_build_input_buffers)
{
    GFXRECON_ASSERT(original_command_buffer != VK_NULL_HANDLE);

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(as_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(phys_dev_info != nullptr);

    const VkPhysicalDeviceMemoryProperties& mem_props = phys_dev_info->replay_device_info->memory_properties.value();

    // Clone serialized data
    if (src_context.serialized_data.buffer != VK_NULL_HANDLE)
    {
        VkResult res = CreateVkBuffer(src_context.serialized_data.size,
                                      device_table,
                                      device_info->handle,
                                      nullptr,
                                      nullptr,
                                      &mem_props,
                                      VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                                          VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT,
                                      &serialized_data.buffer,
                                      &serialized_data.memory);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        serialized_data.size = src_context.serialized_data.size;

        // Clone buffer's content
        const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, serialized_data.size } };
        CopyBufferAndBarrier(original_command_buffer,
                             device_table,
                             src_context.serialized_data.buffer,
                             serialized_data.buffer,
                             copy_region);
    }

    for (const auto& build_object : src_context.as_build_objects)
    {
        if (const auto* triangles = std::get_if<Triangles>(&build_object))
        {
            GFXRECON_ASSERT(triangles->vertex_buffer != VK_NULL_HANDLE &&
                            triangles->vertex_buffer_memory != VK_NULL_HANDLE &&
                            triangles->vertex_format != VK_FORMAT_UNDEFINED);

            auto& new_variant =
                as_build_objects.emplace_back(std::in_place_type<AccelerationStructureDumpResourcesContext::Triangles>);
            auto& new_triangles = std::get<AccelerationStructureDumpResourcesContext::Triangles>(new_variant);

            VkResult res = CreateVkBuffer(triangles->vertex_buffer_size,
                                          device_table,
                                          device_info->handle,
                                          nullptr,
                                          nullptr,
                                          &mem_props,
                                          VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          &new_triangles.vertex_buffer,
                                          &new_triangles.vertex_buffer_memory);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            new_triangles.vertex_buffer_size   = triangles->vertex_buffer_size;
            new_triangles.vertex_format        = triangles->vertex_format;
            new_triangles.vertex_buffer_stride = triangles->vertex_buffer_stride;
            new_triangles.max_vertex           = triangles->max_vertex;

            if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR)
            {
                GFXRECON_ASSERT(triangles->index_buffer_size);

                res = CreateVkBuffer(triangles->index_type,
                                     device_table,
                                     device_info->handle,
                                     nullptr,
                                     nullptr,
                                     &mem_props,
                                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                     &new_triangles.index_buffer,
                                     &new_triangles.index_buffer_memory);
                if (res != VK_SUCCESS)
                {
                    return res;
                }

                new_triangles.index_type        = triangles->index_type;
                new_triangles.index_buffer_size = triangles->index_buffer_size;

                const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, triangles->index_buffer_size } };
                CopyBufferAndBarrier(original_command_buffer,
                                     device_table,
                                     triangles->index_buffer,
                                     new_triangles.index_buffer,
                                     copy_region);
            }

            if (triangles->transform_buffer != VK_NULL_HANDLE)
            {
                GFXRECON_ASSERT(triangles->transform_buffer_size);

                res = CreateVkBuffer(triangles->transform_buffer_size,
                                     device_table,
                                     device_info->handle,
                                     nullptr,
                                     nullptr,
                                     &mem_props,
                                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                     &new_triangles.transform_buffer,
                                     &new_triangles.transform_buffer_memory);
                if (res != VK_SUCCESS)
                {
                    return res;
                }

                new_triangles.transform_buffer_size = triangles->transform_buffer_size;

                const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, triangles->transform_buffer_size } };
                CopyBufferAndBarrier(original_command_buffer,
                                     device_table,
                                     triangles->transform_buffer,
                                     new_triangles.transform_buffer,
                                     copy_region);
            }
        }
        else if (const auto* aabbs = std::get_if<AABBS>(&build_object))
        {
            GFXRECON_ASSERT(aabbs->buffer != VK_NULL_HANDLE);

            auto& new_variant =
                as_build_objects.emplace_back(std::in_place_type<AccelerationStructureDumpResourcesContext::AABBS>);
            auto& new_aabbs = std::get<AccelerationStructureDumpResourcesContext::AABBS>(new_variant);

            VkResult res = CreateVkBuffer(aabbs->buffer_size,
                                          device_table,
                                          device_info->handle,
                                          nullptr,
                                          nullptr,
                                          &mem_props,
                                          VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          &new_aabbs.buffer,
                                          &new_aabbs.buffer_memory);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            new_aabbs.buffer_size = aabbs->buffer_size;

            const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, aabbs->buffer_size } };
            CopyBufferAndBarrier(original_command_buffer, device_table, aabbs->buffer, new_aabbs.buffer, copy_region);
        }
        else if (const auto* instance = std::get_if<Instances>(&build_object))
        {
            GFXRECON_ASSERT(instance->instance_buffer != VK_NULL_HANDLE);

            auto& new_variant =
                as_build_objects.emplace_back(std::in_place_type<AccelerationStructureDumpResourcesContext::Instances>);
            auto& new_instance = std::get<AccelerationStructureDumpResourcesContext::Instances>(new_variant);

            VkResult res = CreateVkBuffer(instance->instance_buffer_size,
                                          device_table,
                                          device_info->handle,
                                          nullptr,
                                          nullptr,
                                          &mem_props,
                                          VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          &new_instance.instance_buffer,
                                          &new_instance.instance_buffer_memory);
            if (res != VK_SUCCESS)
            {
                return res;
            }

            new_instance.instance_buffer_size = instance->instance_buffer_size;
            new_instance.instance_count       = instance->instance_count;

            const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, instance->instance_buffer_size } };
            CopyBufferAndBarrier(original_command_buffer,
                                 device_table,
                                 instance->instance_buffer,
                                 new_instance.instance_buffer,
                                 copy_region);
        }
        else
        {
            GFXRECON_LOG_ERROR("Unexpected build input buffer");
            GFXRECON_ASSERT(0);
            return VK_ERROR_UNKNOWN;
        }
    }

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
