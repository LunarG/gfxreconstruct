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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <vulkan/vulkan_core.h>
#if !defined(WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DispatchTraceRaysDumpingContext::DispatchTraceRaysDumpingContext(const std::vector<uint64_t>& dispatch_indices,
                                                                 const std::vector<uint64_t>& trace_rays_indices,
                                                                 CommonObjectInfoTable&       object_info_table,
                                                                 const VulkanReplayOptions&   options,
                                                                 VulkanDumpResourcesDelegate& delegate) :
    original_command_buffer_info(nullptr),
    DR_command_buffer(VK_NULL_HANDLE), dispatch_indices(dispatch_indices), trace_rays_indices(trace_rays_indices),
    dump_resources_before(options.dump_resources_before), device_table(nullptr), parent_device(VK_NULL_HANDLE),
    instance_table(nullptr), object_info_table(object_info_table), replay_device_phys_mem_props(nullptr),
    current_dispatch_index(0), current_trace_rays_index(0), delegate_(delegate),
    dump_immutable_resources(options.dump_resources_dump_immutable_resources), reached_end_command_buffer(false)
{}

DispatchTraceRaysDumpingContext::~DispatchTraceRaysDumpingContext()
{
    Release();
}

void DispatchTraceRaysDumpingContext::Release()
{
    if (original_command_buffer_info)
    {
        if (DR_command_buffer != VK_NULL_HANDLE)
        {
            const VulkanDeviceInfo* device_info =
                object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
            if (device_info != nullptr)
            {
                DestroyMutableResourcesClones();
                ReleaseIndirectParams();

                VkDevice device = device_info->handle;

                assert(device_table);

                const VulkanCommandPoolInfo* pool_info =
                    object_info_table.GetVkCommandPoolInfo(original_command_buffer_info->pool_id);
                assert(pool_info);

                device_table->FreeCommandBuffers(device, pool_info->handle, 1, &DR_command_buffer);
                DR_command_buffer          = VK_NULL_HANDLE;
                reached_end_command_buffer = false;
            }
        }

        original_command_buffer_info = nullptr;
    }

    dispatch_indices.clear();
    trace_rays_indices.clear();
    bound_descriptor_sets_compute.clear();
    bound_descriptor_sets_ray_tracing.clear();
    dispatch_params.clear();
    trace_rays_params.clear();
}

VkResult DispatchTraceRaysDumpingContext::CloneCommandBuffer(VulkanCommandBufferInfo*           orig_cmd_buf_info,
                                                             const encode::VulkanDeviceTable*   dev_table,
                                                             const encode::VulkanInstanceTable* inst_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);
    assert(inst_table);

    const VulkanCommandPoolInfo* cb_pool_info = object_info_table.GetVkCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const VulkanDeviceInfo* dev_info = object_info_table.GetVkDeviceInfo(orig_cmd_buf_info->parent_id);

    VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &DR_command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    dev_table->BeginCommandBuffer(DR_command_buffer, &bi);

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;
    assert(instance_table == nullptr);
    instance_table = inst_table;

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(parent_device == VK_NULL_HANDLE);
    parent_device = device_info->handle;

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties);
    replay_device_phys_mem_props = &phys_dev_info->replay_device_info->memory_properties.value();

    return VK_SUCCESS;
}

void DispatchTraceRaysDumpingContext::FinalizeCommandBuffer(bool is_dispatch)
{
    if (is_dispatch)
    {
        ++current_dispatch_index;
    }
    else
    {
        ++current_trace_rays_index;
    }
}

void DispatchTraceRaysDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                                pipeline_bind_point,
    uint32_t                                           first_set,
    const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                           dynamicOffsetCount,
    const uint32_t*                                    pDynamicOffsets)
{
    if (pipeline_bind_point != VK_PIPELINE_BIND_POINT_COMPUTE &&
        pipeline_bind_point != VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR)
    {
        return;
    }

    uint32_t dynamic_offset_index = 0;
    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        uint32_t set_index = first_set + i;

        VulkanDescriptorSetInfo* bound_descriptor_sets;
        if (pipeline_bind_point == VK_PIPELINE_BIND_POINT_COMPUTE)
        {
            bound_descriptor_sets = &bound_descriptor_sets_compute[set_index];
        }
        else
        {
            bound_descriptor_sets = &bound_descriptor_sets_ray_tracing[set_index];
        }

        *bound_descriptor_sets = *descriptor_sets_infos[i];

        if (dynamicOffsetCount && pDynamicOffsets != nullptr)
        {
            for (const auto& binding : descriptor_sets_infos[i]->descriptors)
            {
                const uint32_t bindind_index = binding.first;

                if (binding.second.desc_type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                    binding.second.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
                {
                    for (size_t ai = 0; ai < bound_descriptor_sets->descriptors[bindind_index].buffer_info.size(); ++ai)
                    {
                        bound_descriptor_sets->descriptors[bindind_index].buffer_info[ai].offset +=
                            pDynamicOffsets[dynamic_offset_index];
                        ++dynamic_offset_index;
                    }
                }
            }
        }
    }

    assert((dynamic_offset_index == dynamicOffsetCount && pDynamicOffsets != nullptr) || (!dynamic_offset_index));
}

bool DispatchTraceRaysDumpingContext::MustDumpDispatch(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(dispatch_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_dispatch_index / 2 : current_dispatch_index;
         i < dispatch_indices.size();
         ++i)
    {
        if (index == dispatch_indices[i])
        {
            return true;
        }
        else if (index > dispatch_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

bool DispatchTraceRaysDumpingContext::MustDumpTraceRays(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(trace_rays_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_trace_rays_index / 2 : current_trace_rays_index;
         i < trace_rays_indices.size();
         ++i)
    {
        if (index == trace_rays_indices[i])
        {
            return true;
        }
        else if (index > trace_rays_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

void DispatchTraceRaysDumpingContext::CopyBufferResource(const VulkanBufferInfo* src_buffer_info,
                                                         VkDeviceSize            offset,
                                                         VkDeviceSize            range,
                                                         VkBuffer                dst_buffer)
{
    assert(src_buffer_info);
    assert(range);
    assert(dst_buffer != VK_NULL_HANDLE);

    const VkDeviceSize size = (range == VK_WHOLE_SIZE ? src_buffer_info->size - offset : range);

    VkBufferMemoryBarrier buf_barrier;
    buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    buf_barrier.pNext               = nullptr;
    buf_barrier.srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
    buf_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    buf_barrier.buffer              = src_buffer_info->handle;
    buf_barrier.offset              = offset;
    buf_barrier.size                = size;

    assert(device_table != nullptr);
    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     1,
                                     &buf_barrier,
                                     0,
                                     nullptr);

    VkBufferCopy region = { offset, 0, size };
    device_table->CmdCopyBuffer(DR_command_buffer, src_buffer_info->handle, dst_buffer, 1, &region);
}

void DispatchTraceRaysDumpingContext::CopyImageResource(const VulkanImageInfo* src_image_info, VkImage dst_image)
{
    assert(src_image_info != nullptr);
    assert(dst_image != VK_NULL_HANDLE);

    VkImageLayout old_layout;
    assert(original_command_buffer_info != nullptr);
    const auto img_layout_entry = original_command_buffer_info->image_layout_barriers.find(src_image_info->capture_id);
    if (img_layout_entry != original_command_buffer_info->image_layout_barriers.end())
    {
        old_layout = img_layout_entry->second;
    }
    else
    {
        old_layout = VK_IMAGE_LAYOUT_GENERAL;
    }

    // Make sure any potential writes are complete and transition image to TRANSFER_SRC_OPTIMAL layout
    VkImageMemoryBarrier img_barrier;
    img_barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    img_barrier.pNext               = nullptr;
    img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.oldLayout           = old_layout;
    img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.srcQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.dstQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.image               = src_image_info->handle;
    img_barrier.subresourceRange    = {
           graphics::GetFormatAspectMask(src_image_info->format), 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
    };

    assert(device_table != nullptr);
    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    // Transition destination image
    img_barrier.srcAccessMask = VK_ACCESS_NONE;
    img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    img_barrier.image         = dst_image;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    assert(src_image_info->level_count);
    assert(src_image_info->layer_count);

    std::vector<VkImageCopy> copies(src_image_info->level_count, VkImageCopy());
    VkImageCopy              copy;
    copy.srcSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.srcSubresource.baseArrayLayer = 0;
    copy.srcSubresource.layerCount     = src_image_info->layer_count;
    copy.srcOffset.x                   = 0;
    copy.srcOffset.y                   = 0;
    copy.srcOffset.z                   = 0;

    copy.dstSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.dstSubresource.baseArrayLayer = 0;
    copy.dstSubresource.layerCount     = src_image_info->layer_count;
    copy.dstOffset.x                   = 0;
    copy.dstOffset.y                   = 0;
    copy.dstOffset.z                   = 0;

    for (uint32_t i = 0; i < src_image_info->level_count; ++i)
    {
        copy.srcSubresource.mipLevel = i;
        copy.dstSubresource.mipLevel = i;
        copy.extent.width            = (src_image_info->extent.width << i);
        copy.extent.height           = (src_image_info->extent.height << i);
        copy.extent.depth            = (src_image_info->extent.depth << i);

        copies[i] = copy;
    }

    device_table->CmdCopyImage(DR_command_buffer,
                               src_image_info->handle,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               dst_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               copies.size(),
                               copies.data());

    // Wait for transfer and transition source image back to previous layout
    img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.newLayout     = old_layout;
    img_barrier.image         = src_image_info->handle;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);
}

VkResult DispatchTraceRaysDumpingContext::CloneDispatchMutableResources(uint64_t index, bool cloning_before_cmd)
{
    auto entry = dispatch_params.find(index);
    assert(entry != dispatch_params.end());

    DispatchParameters& params = entry->second;
    return CloneMutableResources(
        cloning_before_cmd ? params.mutable_resources_clones_before : params.mutable_resources_clones, true);
}

VkResult DispatchTraceRaysDumpingContext::CloneTraceRaysMutableResources(uint64_t index, bool cloning_before_cmd)
{
    auto entry = trace_rays_params.find(index);
    assert(entry != trace_rays_params.end());

    TraceRaysParameters& params = entry->second;
    return CloneMutableResources(
        cloning_before_cmd ? params.mutable_resources_clones_before : params.mutable_resources_clones, false);
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptorsDispatch(uint64_t index)
{
    auto params_entry = dispatch_params.find(index);
    assert(params_entry != dispatch_params.end());
    SnapshotBoundDescriptors(params_entry->second);
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptorsTraceRays(uint64_t index)
{
    auto params_entry = trace_rays_params.find(index);
    assert(params_entry != trace_rays_params.end());
    SnapshotBoundDescriptors(params_entry->second);
}

VkResult DispatchTraceRaysDumpingContext::CloneMutableResources(MutableResourcesBackupContext& resource_backup_context,
                                                                bool                           is_dispatch)
{
    assert(IsRecording());

    auto& bound_descriptor_sets = is_dispatch ? bound_descriptor_sets_compute : bound_descriptor_sets_ray_tracing;
    for (const auto& desc_set : bound_descriptor_sets)
    {
        const uint32_t desc_set_index = desc_set.first;
        for (const auto& desc : desc_set.second.descriptors)
        {
            const uint32_t           binding_index = desc.first;
            const VkDescriptorType   desc_type     = desc.second.desc_type;
            const VkShaderStageFlags stage_flags   = desc.second.stage_flags;
            switch (desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    uint32_t array_index = 0;
                    for (const auto& img_desc : desc.second.image_info)
                    {
                        if (img_desc.image_view_info == nullptr)
                        {
                            continue;
                        }

                        const VulkanImageInfo* img_info =
                            object_info_table.GetVkImageInfo(img_desc.image_view_info->image_id);
                        assert(img_info);

                        auto& new_entry          = resource_backup_context.images.emplace_back();
                        new_entry.original_image = img_info;
                        new_entry.stages         = stage_flags;
                        new_entry.desc_type      = desc_type;
                        new_entry.desc_set       = desc_set_index;
                        new_entry.desc_binding   = binding_index;
                        new_entry.array_index    = array_index++;

                        VkResult res = CloneImage(object_info_table,
                                                  device_table,
                                                  replay_device_phys_mem_props,
                                                  img_info,
                                                  &new_entry.image,
                                                  &new_entry.image_memory);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Cloning image resource %" PRIu64 " failed (%s)",
                                               img_info->capture_id,
                                               util::ToString<VkResult>(res).c_str())
                            return res;
                        }

                        CopyImageResource(img_info, new_entry.image);
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    uint32_t array_index = 0;
                    for (const auto& buf_desc : desc.second.buffer_info)
                    {
                        const VulkanBufferInfo* buf_info = buf_desc.buffer_info;
                        if (buf_info == nullptr)
                        {
                            continue;
                        }

                        auto& new_entry           = resource_backup_context.buffers.emplace_back();
                        new_entry.original_buffer = buf_info;
                        new_entry.stages          = stage_flags;
                        new_entry.desc_type       = desc_type;
                        new_entry.desc_set        = desc_set_index;
                        new_entry.desc_binding    = binding_index;
                        new_entry.array_index     = array_index++;

                        VkResult res = CloneBuffer(object_info_table,
                                                   device_table,
                                                   replay_device_phys_mem_props,
                                                   buf_info,
                                                   &new_entry.buffer,
                                                   &new_entry.buffer_memory);

                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Cloning buffer resource %" PRIu64 " failed (%s)",
                                               buf_info->capture_id,
                                               util::ToString<VkResult>(res).c_str())
                            return res;
                        }

                        CopyBufferResource(buf_info, buf_desc.offset, buf_desc.range, new_entry.buffer);
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    // These are read only resources
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(desc_type).c_str());
                    break;
            }
        }
    }

    return VK_SUCCESS;
}

void DispatchTraceRaysDumpingContext::DestroyMutableResourcesClones()
{
    for (auto& dis_params : dispatch_params)
    {
        for (size_t i = 0; i < dis_params.second.mutable_resources_clones.images.size(); ++i)
        {
            assert(dis_params.second.mutable_resources_clones.images[i].original_image != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(
                dis_params.second.mutable_resources_clones.images[i].original_image->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(
                device, dis_params.second.mutable_resources_clones.images[i].image_memory, nullptr);
            device_table->DestroyImage(device, dis_params.second.mutable_resources_clones.images[i].image, nullptr);

            if (dump_resources_before)
            {
                device_table->FreeMemory(
                    device, dis_params.second.mutable_resources_clones_before.images[i].image_memory, nullptr);
                device_table->DestroyImage(
                    device, dis_params.second.mutable_resources_clones_before.images[i].image, nullptr);
            }
        }

        for (size_t i = 0; i < dis_params.second.mutable_resources_clones.buffers.size(); ++i)
        {
            assert(dis_params.second.mutable_resources_clones.buffers[i].original_buffer != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(
                dis_params.second.mutable_resources_clones.buffers[i].original_buffer->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(
                device, dis_params.second.mutable_resources_clones.buffers[i].buffer_memory, nullptr);
            device_table->DestroyBuffer(device, dis_params.second.mutable_resources_clones.buffers[i].buffer, nullptr);
            if (dump_resources_before)
            {
                device_table->FreeMemory(
                    device, dis_params.second.mutable_resources_clones_before.buffers[i].buffer_memory, nullptr);
                device_table->DestroyBuffer(
                    device, dis_params.second.mutable_resources_clones_before.buffers[i].buffer, nullptr);
            }
        }
    }

    for (auto& tr_params : trace_rays_params)
    {
        for (size_t i = 0; i < tr_params.second.mutable_resources_clones.images.size(); ++i)
        {
            assert(tr_params.second.mutable_resources_clones.images[i].original_image != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(
                tr_params.second.mutable_resources_clones.images[i].original_image->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, tr_params.second.mutable_resources_clones.images[i].image_memory, nullptr);
            device_table->DestroyImage(device, tr_params.second.mutable_resources_clones.images[i].image, nullptr);

            if (dump_resources_before)
            {
                device_table->FreeMemory(
                    device, tr_params.second.mutable_resources_clones_before.images[i].image_memory, nullptr);
                device_table->DestroyImage(
                    device, tr_params.second.mutable_resources_clones_before.images[i].image, nullptr);
            }
        }

        for (size_t i = 0; i < tr_params.second.mutable_resources_clones.buffers.size(); ++i)
        {
            assert(tr_params.second.mutable_resources_clones.buffers[i].original_buffer != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(
                tr_params.second.mutable_resources_clones.buffers[i].original_buffer->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(
                device, tr_params.second.mutable_resources_clones.buffers[i].buffer_memory, nullptr);
            device_table->DestroyBuffer(device, tr_params.second.mutable_resources_clones.buffers[i].buffer, nullptr);
            if (dump_resources_before)
            {
                device_table->FreeMemory(
                    device, tr_params.second.mutable_resources_clones_before.buffers[i].buffer_memory, nullptr);
                device_table->DestroyBuffer(
                    device, tr_params.second.mutable_resources_clones_before.buffers[i].buffer, nullptr);
            }
        }
    }
}

void DispatchTraceRaysDumpingContext::ReleaseIndirectParams()
{
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    for (auto& dis_params : dispatch_params)
    {
        if (dis_params.second.type != kDispatchIndirect)
        {
            continue;
        }

        if (dis_params.second.dispatch_params_union.dispatch_indirect.new_params_buffer != VK_NULL_HANDLE)
        {
            device_table->DestroyBuffer(device_info->handle,
                                        dis_params.second.dispatch_params_union.dispatch_indirect.new_params_buffer,
                                        nullptr);
            dis_params.second.dispatch_params_union.dispatch_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (dis_params.second.dispatch_params_union.dispatch_indirect.new_params_memory != VK_NULL_HANDLE)
        {
            device_table->FreeMemory(device_info->handle,
                                     dis_params.second.dispatch_params_union.dispatch_indirect.new_params_memory,
                                     nullptr);
            dis_params.second.dispatch_params_union.dispatch_indirect.new_params_memory = VK_NULL_HANDLE;
        }
    }

    for (auto& tr_params : trace_rays_params)
    {
        if (tr_params.second.type != kTraceRaysIndirect)
        {
            continue;
        }

        if (tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer != VK_NULL_HANDLE)
        {
            device_table->DestroyBuffer(device_info->handle,
                                        tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer,
                                        nullptr);
            tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory != VK_NULL_HANDLE)
        {
            device_table->FreeMemory(
                device_info->handle,
                tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory,
                nullptr);
            tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory = VK_NULL_HANDLE;
        }

        if (tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address != VK_NULL_HANDLE)
        {
            device_table->DestroyBuffer(
                device_info->handle,
                tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address,
                nullptr);
            tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address = VK_NULL_HANDLE;
        }

        if (tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory !=
            VK_NULL_HANDLE)
        {
            device_table->FreeMemory(
                device_info->handle,
                tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory,
                nullptr);
            tr_params.second.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory =
                VK_NULL_HANDLE;
        }
    }
}

VkResult DispatchTraceRaysDumpingContext::DumpDispatchTraceRays(
    VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence)
{
    VkSubmitInfo si;
    si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    si.pNext                = nullptr;
    si.waitSemaphoreCount   = submit_info.waitSemaphoreCount;
    si.pWaitSemaphores      = submit_info.pWaitSemaphores;
    si.pWaitDstStageMask    = submit_info.pWaitDstStageMask;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &DR_command_buffer;
    si.signalSemaphoreCount = submit_info.signalSemaphoreCount;
    si.pSignalSemaphores    = submit_info.pSignalSemaphores;

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    VkResult res = VK_SUCCESS;

    const VkFenceCreateInfo ci               = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkFence                 submission_fence = VK_NULL_HANDLE;
    if (fence == VK_NULL_HANDLE)
    {
        res = device_table->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }
    else
    {
        submission_fence = fence;
    }

    res = device_table->QueueSubmit(queue, 1, &si, submission_fence);
    if (res != VK_SUCCESS)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Wait
    res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
    if (res != VK_SUCCESS)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    if (fence == VK_NULL_HANDLE)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
    }

    res = FetchIndirectParams();
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Fetching params for indirect calls failed (%s).", util::ToString<VkResult>(res).c_str())
        return res;
    }

    for (size_t i = 0; i < dispatch_indices.size(); ++i)
    {
        const uint64_t disp_index = dispatch_indices[i];

        GFXRECON_LOG_INFO("Dumping mutable resources for dispatch index %" PRIu64, disp_index);

        res = DumpMutableResources(bcb_index, qs_index, disp_index, true);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping compute mutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        if (dump_immutable_resources)
        {
            res = DumpImmutableDescriptors(qs_index, bcb_index, disp_index, true);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        VulkanDumpDrawCallInfo draw_call_info{};
        draw_call_info.type                         = DumpResourceType::kDispatchInfo;
        draw_call_info.instance_table               = instance_table;
        draw_call_info.device_table                 = device_table;
        draw_call_info.object_info_table            = &object_info_table;
        draw_call_info.device_info                  = device_info;
        draw_call_info.original_command_buffer_info = original_command_buffer_info;
        draw_call_info.bcb_index                    = bcb_index;
        draw_call_info.qs_index                     = qs_index;
        draw_call_info.cmd_index                    = disp_index;

        const auto& dispatch_param_entry = dispatch_params.find(disp_index);
        GFXRECON_ASSERT(dispatch_param_entry != dispatch_params.end());
        draw_call_info.disp_param = &dispatch_param_entry->second;

        delegate_.DumpDrawCallInfo(draw_call_info);
    }

    for (size_t i = 0; i < trace_rays_indices.size(); ++i)
    {
        const uint64_t tr_index = trace_rays_indices[i];

        GFXRECON_LOG_INFO("Dumping mutable resources for trace rays index %" PRIu64, tr_index);

        res = DumpMutableResources(bcb_index, qs_index, tr_index, false);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping ray tracing mutable resources failed. (%s)",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }

        if (dump_immutable_resources)
        {
            res = DumpImmutableDescriptors(qs_index, bcb_index, tr_index, false);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        VulkanDumpDrawCallInfo draw_call_info{};
        draw_call_info.type                         = DumpResourceType::kTraceRaysIndex;
        draw_call_info.instance_table               = instance_table;
        draw_call_info.device_table                 = device_table;
        draw_call_info.object_info_table            = &object_info_table;
        draw_call_info.device_info                  = device_info;
        draw_call_info.original_command_buffer_info = original_command_buffer_info;
        draw_call_info.bcb_index                    = bcb_index;
        draw_call_info.qs_index                     = qs_index;
        draw_call_info.cmd_index                    = tr_index;

        const auto& trace_rays_param_entry = trace_rays_params.find(tr_index);
        GFXRECON_ASSERT(trace_rays_param_entry != trace_rays_params.end());
        draw_call_info.tr_param = &trace_rays_param_entry->second;

        delegate_.DumpDrawCallInfo(draw_call_info);
    }

    // Clean up references to dumped descriptors in case this command buffer is submitted again
    dispatch_dumped_descriptors.buffer_descriptors.clear();
    dispatch_dumped_descriptors.image_descriptors.clear();
    dispatch_dumped_descriptors.inline_uniform_blocks.clear();

    trace_rays_dumped_descriptors.buffer_descriptors.clear();
    trace_rays_dumped_descriptors.image_descriptors.clear();
    trace_rays_dumped_descriptors.inline_uniform_blocks.clear();

    assert(res == VK_SUCCESS);
    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::DumpMutableResources(uint64_t bcb_index,
                                                               uint64_t qs_index,
                                                               uint64_t cmd_index,
                                                               bool     is_dispatch)
{
    const auto dis_params = dispatch_params.find(cmd_index);
    const auto tr_params  = trace_rays_params.find(cmd_index);

    if (is_dispatch && (dis_params == dispatch_params.end()))
    {
        assert(0);
        return VK_SUCCESS;
    }
    else if (!is_dispatch && (tr_params == trace_rays_params.end()))
    {
        assert(0);
        return VK_SUCCESS;
    }

    const MutableResourcesBackupContext& mutable_resources_clones =
        is_dispatch ? dis_params->second.mutable_resources_clones : tr_params->second.mutable_resources_clones;

    const MutableResourcesBackupContext& mutable_resources_clones_before =
        is_dispatch ? dis_params->second.mutable_resources_clones_before
                    : tr_params->second.mutable_resources_clones_before;

    if (mutable_resources_clones.images.empty() && mutable_resources_clones.buffers.empty())
    {
        assert(mutable_resources_clones_before.images.empty() && mutable_resources_clones_before.buffers.empty());
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);
    VulkanDumpResourceInfo        res_info_base{};
    res_info_base.device_info                  = device_info;
    res_info_base.device_table                 = device_table;
    res_info_base.instance_table               = instance_table;
    res_info_base.object_info_table            = &object_info_table;
    res_info_base.original_command_buffer_info = original_command_buffer_info;
    res_info_base.cmd_index                    = cmd_index;
    res_info_base.qs_index                     = qs_index;
    res_info_base.bcb_index                    = bcb_index;

    if (dump_resources_before)
    {
        // Dump images
        for (size_t i = 0; i < mutable_resources_clones_before.images.size(); ++i)
        {
            assert(mutable_resources_clones_before.images[i].original_image != nullptr);
            assert(mutable_resources_clones_before.images[i].image != VK_NULL_HANDLE);

            VulkanImageInfo modified_image_info = *mutable_resources_clones_before.images[i].original_image;
            modified_image_info.handle          = mutable_resources_clones_before.images[i].image;

            VulkanDumpResourceInfo res_info = res_info_base;
            res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
            res_info.is_dispatch            = is_dispatch;
            res_info.before_cmd             = true;
            res_info.image_info             = &modified_image_info;
            res_info.set                    = mutable_resources_clones_before.images[i].desc_set;
            res_info.binding                = mutable_resources_clones_before.images[i].desc_binding;
            res_info.array_index            = mutable_resources_clones_before.images[i].array_index;
            res_info.stages                 = mutable_resources_clones_before.images[i].stages;
            auto res                        = delegate_.DumpResource(res_info);
            if (res != VK_SUCCESS)
            {
                return res;
            }
        }

        // Dump buffers
        for (size_t i = 0; i < mutable_resources_clones_before.buffers.size(); ++i)
        {
            const VulkanBufferInfo* buffer_info = mutable_resources_clones_before.buffers[i].original_buffer;
            assert(buffer_info != nullptr);
            assert(mutable_resources_clones_before.buffers[i].buffer != VK_NULL_HANDLE);

            VulkanDumpResourceInfo res_info = res_info_base;
            VkResult res = resource_util.ReadFromBufferResource(mutable_resources_clones_before.buffers[i].buffer,
                                                                buffer_info->size,
                                                                0,
                                                                buffer_info->queue_family_index,
                                                                res_info.data);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
                return res;
            }

            res_info.type        = DumpResourceType::kDispatchTraceRaysBuffer;
            res_info.is_dispatch = is_dispatch;
            res_info.before_cmd  = true;
            res_info.set         = mutable_resources_clones_before.buffers[i].desc_set;
            res_info.binding     = mutable_resources_clones_before.buffers[i].desc_binding;
            res_info.array_index = mutable_resources_clones_before.buffers[i].array_index;
            res_info.stages      = mutable_resources_clones_before.buffers[i].stages;
            res                  = delegate_.DumpResource(res_info);
            if (res != VK_SUCCESS)
            {
                return res;
            }
        }
    }

    for (size_t i = 0; i < mutable_resources_clones.images.size(); ++i)
    {
        assert(mutable_resources_clones.images[i].original_image != nullptr);
        assert(mutable_resources_clones.images[i].image != VK_NULL_HANDLE);

        VulkanImageInfo modified_image_info = *mutable_resources_clones.images[i].original_image;
        modified_image_info.handle          = mutable_resources_clones.images[i].image;

        VulkanDumpResourceInfo res_info = res_info_base;
        res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
        res_info.is_dispatch            = is_dispatch;
        res_info.before_cmd             = false;
        res_info.image_info             = &modified_image_info;
        res_info.set                    = mutable_resources_clones.images[i].desc_set;
        res_info.binding                = mutable_resources_clones.images[i].desc_binding;
        res_info.array_index            = mutable_resources_clones.images[i].array_index;
        res_info.stages                 = mutable_resources_clones.images[i].stages;
        auto res                        = delegate_.DumpResource(res_info);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    // Dump buffers
    for (size_t i = 0; i < mutable_resources_clones.buffers.size(); ++i)
    {
        assert(mutable_resources_clones.buffers[i].original_buffer != nullptr);
        assert(mutable_resources_clones.buffers[i].buffer != VK_NULL_HANDLE);
        const VulkanBufferInfo* buffer_info = mutable_resources_clones.buffers[i].original_buffer;

        VulkanDumpResourceInfo res_info = res_info_base;
        VkResult               res = resource_util.ReadFromBufferResource(mutable_resources_clones.buffers[i].buffer,
                                                            buffer_info->size,
                                                            0,
                                                            buffer_info->queue_family_index,
                                                            res_info.data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        res_info.type        = DumpResourceType::kDispatchTraceRaysBuffer;
        res_info.is_dispatch = is_dispatch;
        res_info.before_cmd  = false;
        res_info.set         = mutable_resources_clones.buffers[i].desc_set;
        res_info.binding     = mutable_resources_clones.buffers[i].desc_binding;
        res_info.array_index = mutable_resources_clones.buffers[i].array_index;
        res_info.stages      = mutable_resources_clones.buffers[i].stages;
        res                  = delegate_.DumpResource(res_info);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    return VK_SUCCESS;
}

bool DispatchTraceRaysDumpingContext::IsRecording() const
{
    return !reached_end_command_buffer;
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptors(DispatchParameters& disp_params)
{
    for (const auto& desc_set : bound_descriptor_sets_compute)
    {
        const uint32_t desc_set_index = desc_set.first;
        for (const auto& desc : desc_set.second.descriptors)
        {
            const uint32_t desc_binding_index                                      = desc.first;
            disp_params.referenced_descriptors[desc_set_index][desc_binding_index] = desc.second;
        }
    }
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptors(TraceRaysParameters& tr_params)
{
    for (const auto& desc_set : bound_descriptor_sets_ray_tracing)
    {
        const uint32_t desc_set_index = desc_set.first;
        for (const auto& desc : desc_set.second.descriptors)
        {
            const uint32_t desc_binding_index                                    = desc.first;
            tr_params.referenced_descriptors[desc_set_index][desc_binding_index] = desc.second;
        }
    }
}

VkResult DispatchTraceRaysDumpingContext::DumpImmutableDescriptors(uint64_t qs_index,
                                                                   uint64_t bcb_index,
                                                                   uint64_t cmd_index,
                                                                   bool     is_dispatch)
{
    // Create a list of all descriptors referenced by all commands
    std::unordered_set<const VulkanImageInfo*> image_descriptors;

    struct buffer_descriptor_info
    {
        VkDeviceSize offset;
        VkDeviceSize range;
    };
    std::unordered_map<const VulkanBufferInfo*, buffer_descriptor_info> buffer_descriptors;

    struct inline_uniform_block_info
    {
        uint32_t                    set;
        uint32_t                    binding;
        const std::vector<uint8_t>* data;
    };
    std::unordered_map<const std::vector<uint8_t>*, inline_uniform_block_info> inline_uniform_blocks;

    DumpedDescriptors& dumped_descriptors = is_dispatch ? dispatch_dumped_descriptors : trace_rays_dumped_descriptors;

    if (is_dispatch)
    {
        const auto disp_params = dispatch_params.find(cmd_index);
        assert(disp_params != dispatch_params.end());
        for (const auto& desc_set : disp_params->second.referenced_descriptors)
        {
            const uint32_t desc_set_index = desc_set.first;

            for (const auto& desc_binding : desc_set.second)
            {
                const uint32_t desc_binding_index = desc_binding.first;

                switch (desc_binding.second.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (size_t i = 0; i < desc_binding.second.image_info.size(); ++i)
                        {
                            if (desc_binding.second.image_info[i].image_view_info != nullptr)
                            {
                                const VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(
                                    desc_binding.second.image_info[i].image_view_info->image_id);
                                if (img_info != nullptr && dumped_descriptors.image_descriptors.find(img_info) ==
                                                               dumped_descriptors.image_descriptors.end())
                                {
                                    image_descriptors.insert(img_info);
                                    dumped_descriptors.image_descriptors.insert(img_info);
                                }
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        for (size_t i = 0; i < desc_binding.second.buffer_info.size(); ++i)
                        {
                            const VulkanBufferInfo* buffer_info = desc_binding.second.buffer_info[i].buffer_info;
                            if (buffer_info != nullptr && dumped_descriptors.buffer_descriptors.find(buffer_info) ==
                                                              dumped_descriptors.buffer_descriptors.end())
                            {
                                buffer_descriptors.emplace(std::piecewise_construct,
                                                           std::forward_as_tuple(buffer_info),
                                                           std::forward_as_tuple(buffer_descriptor_info{
                                                               desc_binding.second.buffer_info[i].offset,
                                                               desc_binding.second.buffer_info[i].range }));
                                dumped_descriptors.buffer_descriptors.insert(buffer_info);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        if (dumped_descriptors.inline_uniform_blocks.find(
                                &(desc_binding.second.inline_uniform_block)) ==
                            dumped_descriptors.inline_uniform_blocks.end())
                        {
                            inline_uniform_blocks[&(desc_binding.second.inline_uniform_block)] = {
                                desc_set_index, desc_binding_index, &(desc_binding.second.inline_uniform_block)
                            };
                            dumped_descriptors.inline_uniform_blocks.insert(
                                &(desc_binding.second.inline_uniform_block));
                        }
                    }
                    break;

                    default:
                        GFXRECON_LOG_WARNING_ONCE(
                            "%s(): Descriptor type (%s) not handled",
                            __func__,
                            util::ToString<VkDescriptorType>(desc_binding.second.desc_type).c_str());
                        break;
                }
            }
        }
    }
    else
    {
        const auto tr_params = trace_rays_params.find(cmd_index);
        assert(tr_params != trace_rays_params.end());
        for (const auto& desc_set : tr_params->second.referenced_descriptors)
        {
            const uint32_t desc_set_index = desc_set.first;

            for (const auto& desc_binding : desc_set.second)
            {
                const uint32_t desc_binding_index = desc_binding.first;

                switch (desc_binding.second.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (size_t i = 0; i < desc_binding.second.image_info.size(); ++i)
                        {
                            if (desc_binding.second.image_info[i].image_view_info != nullptr)
                            {
                                const VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(
                                    desc_binding.second.image_info[i].image_view_info->image_id);
                                if (img_info != nullptr && dumped_descriptors.image_descriptors.find(img_info) ==
                                                               dumped_descriptors.image_descriptors.end())
                                {
                                    image_descriptors.insert(img_info);
                                    dumped_descriptors.image_descriptors.insert(img_info);
                                }
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        for (size_t i = 0; i < desc_binding.second.buffer_info.size(); ++i)
                        {
                            const VulkanBufferInfo* buffer_info = desc_binding.second.buffer_info[i].buffer_info;
                            if (buffer_info != nullptr && dumped_descriptors.buffer_descriptors.find(buffer_info) ==
                                                              dumped_descriptors.buffer_descriptors.end())
                            {
                                buffer_descriptors.emplace(
                                    std::piecewise_construct,
                                    std::forward_as_tuple(desc_binding.second.buffer_info[i].buffer_info),
                                    std::forward_as_tuple(
                                        buffer_descriptor_info{ desc_binding.second.buffer_info[i].offset,
                                                                desc_binding.second.buffer_info[i].range }));
                                dumped_descriptors.buffer_descriptors.insert(buffer_info);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        if (dumped_descriptors.inline_uniform_blocks.find(
                                &(desc_binding.second.inline_uniform_block)) ==
                            dumped_descriptors.inline_uniform_blocks.end())
                        {
                            inline_uniform_blocks[&(desc_binding.second.inline_uniform_block)] = {
                                desc_set_index, desc_binding_index, &(desc_binding.second.inline_uniform_block)
                            };
                            dumped_descriptors.inline_uniform_blocks.insert(
                                &(desc_binding.second.inline_uniform_block));
                        }
                    }
                    break;

                    default:
                        GFXRECON_LOG_WARNING_ONCE(
                            "%s(): Descriptor type (%s) not handled",
                            __func__,
                            util::ToString<VkDescriptorType>(desc_binding.second.desc_type).c_str());
                        break;
                }
            }
        }
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    VulkanDumpResourceInfo res_info_base{};
    res_info_base.device_info                  = device_info;
    res_info_base.device_table                 = device_table;
    res_info_base.instance_table               = instance_table;
    res_info_base.object_info_table            = &object_info_table;
    res_info_base.original_command_buffer_info = original_command_buffer_info;
    res_info_base.cmd_index                    = cmd_index;
    res_info_base.qs_index                     = qs_index;
    res_info_base.bcb_index                    = bcb_index;
    res_info_base.is_dispatch                  = is_dispatch;

    for (const auto& img_info : image_descriptors)
    {
        VulkanDumpResourceInfo res_info = res_info_base;
        res_info.type                   = DumpResourceType::kDispatchTraceRaysImageDescriptor;
        res_info.image_info             = img_info;
        auto res                        = delegate_.DumpResource(res_info);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    for (const auto& buf : buffer_descriptors)
    {
        VulkanDumpResourceInfo res_info = res_info_base;
        res_info.buffer_info            = buf.first;
        const VkDeviceSize offset       = buf.second.offset;
        const VkDeviceSize range        = buf.second.range;
        const VkDeviceSize size         = range == VK_WHOLE_SIZE ? res_info.buffer_info->size - offset : range;

        VkResult res = resource_util.ReadFromBufferResource(
            res_info.buffer_info->handle, size, offset, res_info.buffer_info->queue_family_index, res_info.data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        res_info.type = DumpResourceType::kDispatchTraceRaysBufferDescriptor;
        res           = delegate_.DumpResource(res_info);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    for (const auto& iub : inline_uniform_blocks)
    {
        VulkanDumpResourceInfo res_info = res_info_base;
        res_info.type                   = DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor;
        res_info.set                    = iub.second.set;
        res_info.binding                = iub.second.binding;
        res_info.data                   = *iub.second.data;
        auto res                        = delegate_.DumpResource(res_info);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::CopyDispatchIndirectParameters(uint64_t index)
{
    auto entry = dispatch_params.find(index);
    assert(entry != dispatch_params.end());
    DispatchParameters& disp_params = entry->second;

    assert(disp_params.type == kDispatchIndirect);
    assert(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info != nullptr);
    assert(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->handle != VK_NULL_HANDLE);

    const VkDeviceSize size = sizeof(VkDispatchIndirectCommand);
    VkResult           res  = CloneBuffer(object_info_table,
                               device_table,
                               replay_device_phys_mem_props,
                               disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info,
                               &disp_params.dispatch_params_union.dispatch_indirect.new_params_buffer,
                               &disp_params.dispatch_params_union.dispatch_indirect.new_params_memory,
                               size);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Cloning buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
        return res;
    }

    // Inject a cmdCopyBuffer to copy the dispatch params into the new buffer
    {
        const VkDeviceSize offset  = disp_params.dispatch_params_union.dispatch_indirect.params_buffer_offset;
        const VkBufferCopy region  = { offset, 0, size };
        VkCommandBuffer    cmd_buf = DR_command_buffer;
        device_table->CmdCopyBuffer(cmd_buf,
                                    disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->handle,
                                    disp_params.dispatch_params_union.dispatch_indirect.new_params_buffer,
                                    1,
                                    &region);

        VkBufferMemoryBarrier buf_barrier;
        buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
        buf_barrier.pNext               = nullptr;
        buf_barrier.buffer              = disp_params.dispatch_params_union.dispatch_indirect.new_params_buffer;
        buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
        buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
        buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
        buf_barrier.size                = size;
        buf_barrier.offset              = 0;

        device_table->CmdPipelineBarrier(cmd_buf,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         VkDependencyFlags{ 0 },
                                         0,
                                         nullptr,
                                         1,
                                         &buf_barrier,
                                         0,
                                         nullptr);
    }

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::CopyTraceRaysIndirectParameters(uint64_t index)
{
    auto entry = trace_rays_params.find(index);
    assert(entry != trace_rays_params.end());
    TraceRaysParameters& params = entry->second;

    assert(params.type == kTraceRaysIndirect || params.type == kTraceRaysIndirect2);
    if (params.trace_rays_params_union.trace_rays_indirect.indirect_device_address == 0)
    {
        return VK_SUCCESS;
    }

    const VkDeviceSize    size = params.type == kTraceRaysIndirect ? sizeof(VkTraceRaysIndirectCommandKHR)
                                                                   : sizeof(VkTraceRaysIndirectCommand2KHR);
    const VkDeviceAddress indirect_device_address =
        params.type == kTraceRaysIndirect ? params.trace_rays_params_union.trace_rays_indirect.indirect_device_address
                                          : params.trace_rays_params_union.trace_rays_indirect2.indirect_device_address;
    // Create a buffer using the provided device address
    VkBufferDeviceAddressCreateInfoEXT bdaci;
    bdaci.sType         = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT;
    bdaci.pNext         = nullptr;
    bdaci.deviceAddress = indirect_device_address;

    VkBuffer       buffer_on_device_address;
    VkDeviceMemory buffer_on_device_address_memory;
    VkResult       res = CreateVkBuffer(size,
                                  device_table,
                                  parent_device,
                                  reinterpret_cast<VkBaseInStructure*>(&bdaci),
                                  replay_device_phys_mem_props,
                                  &buffer_on_device_address,
                                  &buffer_on_device_address_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): Failed to create a buffer using device address (%s)",
                           __func__,
                           util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Create a new buffer where the parameters will be copied into from the buffer we created above
    VkBuffer       new_params_buffer;
    VkDeviceMemory new_params_buffer_memory;
    res = CreateVkBuffer(size,
                         device_table,
                         parent_device,
                         reinterpret_cast<VkBaseInStructure*>(&bdaci),
                         replay_device_phys_mem_props,
                         &new_params_buffer,
                         &new_params_buffer_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): Failed to create buffer (%s)", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Copy the parameters from one buffer into the other
    const VkBufferCopy region = { 0, 0, size };
    assert(device_table);
    device_table->CmdCopyBuffer(DR_command_buffer, buffer_on_device_address, new_params_buffer, 1, &region);

    VkBufferMemoryBarrier buf_barrier;
    buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    buf_barrier.pNext               = nullptr;
    buf_barrier.buffer              = new_params_buffer;
    buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
    buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    buf_barrier.size                = size;
    buf_barrier.offset              = 0;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags{ 0 },
                                     0,
                                     nullptr,
                                     1,
                                     &buf_barrier,
                                     0,
                                     nullptr);

    if (params.type == kTraceRaysIndirect)
    {
        TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect& itr_params =
            params.trace_rays_params_union.trace_rays_indirect;

        itr_params.buffer_on_device_address        = buffer_on_device_address;
        itr_params.buffer_on_device_address_memory = buffer_on_device_address_memory;

        itr_params.new_params_buffer        = new_params_buffer;
        itr_params.new_params_buffer_memory = new_params_buffer_memory;
    }
    else
    {
        TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect2& itr_params =
            params.trace_rays_params_union.trace_rays_indirect2;

        itr_params.buffer_on_device_address        = buffer_on_device_address;
        itr_params.buffer_on_device_address_memory = buffer_on_device_address_memory;

        itr_params.new_params_buffer        = new_params_buffer;
        itr_params.new_params_buffer_memory = new_params_buffer_memory;
    }

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::FetchIndirectParams()
{
    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table,
                                                *instance_table,
                                                *phys_dev_info->replay_device_info->memory_properties);

    for (auto& dis_params : dispatch_params)
    {
        if (dis_params.second.type != kDispatchIndirect)
        {
            continue;
        }

        DispatchParameters::DispatchParamsUnion::DispatchIndirect& i_params =
            dis_params.second.dispatch_params_union.dispatch_indirect;

        const VkDeviceSize   size = sizeof(VkDispatchIndirectCommand);
        std::vector<uint8_t> data;
        VkResult             res =
            resource_util.ReadFromBufferResource(i_params.new_params_buffer, size, 0, VK_QUEUE_FAMILY_IGNORED, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(data.size() == sizeof(VkDispatchIndirectCommand));
        util::platform::MemoryCopy(&i_params.dispatch_params, size, data.data(), size);
    }

    for (auto& tr_params : trace_rays_params)
    {
        if (tr_params.second.type != kTraceRaysIndirect && tr_params.second.type != kTraceRaysIndirect2)
        {
            continue;
        }

        const VkBuffer new_params_buffer =
            tr_params.second.type == kTraceRaysIndirect
                ? tr_params.second.trace_rays_params_union.trace_rays_indirect.new_params_buffer
                : tr_params.second.trace_rays_params_union.trace_rays_indirect2.new_params_buffer;
        const VkDeviceSize   size = tr_params.second.type == kTraceRaysIndirect ? sizeof(VkTraceRaysIndirectCommandKHR)
                                                                                : sizeof(VkTraceRaysIndirectCommand2KHR);
        std::vector<uint8_t> data;
        VkResult res = resource_util.ReadFromBufferResource(new_params_buffer, size, 0, VK_QUEUE_FAMILY_IGNORED, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(data.size() == size);
        if (tr_params.second.type == kTraceRaysIndirect)
        {
            TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect& i_params =
                tr_params.second.trace_rays_params_union.trace_rays_indirect;
            util::platform::MemoryCopy(&i_params.trace_rays_params, size, data.data(), size);
        }
        else
        {
            TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect2& i_params =
                tr_params.second.trace_rays_params_union.trace_rays_indirect2;
            util::platform::MemoryCopy(&i_params.trace_rays_params, size, data.data(), size);
        }
    }

    return VK_SUCCESS;
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t index,
                                                                  uint32_t groupCountX,
                                                                  uint32_t groupCountY,
                                                                  uint32_t groupCountZ)
{
    auto new_entry =
        dispatch_params.emplace(std::piecewise_construct,
                                std::forward_as_tuple(index),
                                std::forward_as_tuple(DispatchTypes::kDispatch, groupCountX, groupCountY, groupCountZ));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t                index,
                                                                  const VulkanBufferInfo* buffer_info,
                                                                  VkDeviceSize            offset)
{
    auto new_entry =
        dispatch_params.emplace(std::piecewise_construct,
                                std::forward_as_tuple(index),
                                std::forward_as_tuple(DispatchTypes::kDispatchIndirect, buffer_info, offset));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysParameters(
    uint64_t                               index,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    uint32_t                               width,
    uint32_t                               height,
    uint32_t                               depth)
{
    auto new_entry = trace_rays_params.emplace(std::piecewise_construct,
                                               std::forward_as_tuple(index),
                                               std::forward_as_tuple(TraceRaysTypes::kTraceRays, width, height, depth));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirectParameters(
    uint64_t                               index,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    auto new_entry =
        trace_rays_params.emplace(std::piecewise_construct,
                                  std::forward_as_tuple(index),
                                  std::forward_as_tuple(TraceRaysTypes::kTraceRaysIndirect, indirectDeviceAddress));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirect2Parameters(uint64_t        index,
                                                                            VkDeviceAddress indirectDeviceAddress)
{
    auto new_entry =
        trace_rays_params.emplace(std::piecewise_construct,
                                  std::forward_as_tuple(index),
                                  std::forward_as_tuple(TraceRaysTypes::kTraceRaysIndirect2, indirectDeviceAddress));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::EndCommandBuffer()
{
    reached_end_command_buffer = true;
    device_table->EndCommandBuffer(DR_command_buffer);
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
