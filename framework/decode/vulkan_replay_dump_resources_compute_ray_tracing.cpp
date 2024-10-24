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
#include "decode/vulkan_replay_dump_resources_common.h"
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

DispatchTraceRaysDumpingContext::DispatchTraceRaysDumpingContext(const std::vector<uint64_t>&   dispatch_indices,
                                                                 const std::vector<uint64_t>&   trace_rays_indices,
                                                                 VulkanObjectInfoTable&         object_info_table,
                                                                 const VulkanReplayOptions&     options,
                                                                 VulkanReplayDumpResourcesJson& dump_json,
                                                                 std::string                    capture_filename) :
    original_command_buffer_info(nullptr),
    DR_command_buffer(VK_NULL_HANDLE), dispatch_indices(dispatch_indices),
    trace_rays_indices(trace_rays_indices), bound_pipelines{ nullptr },
    dump_resources_before(options.dump_resources_before), dump_resource_path(options.dump_resources_output_dir),
    image_file_format(options.dump_resources_image_format), dump_resources_scale(options.dump_resources_scale),
    device_table(nullptr), parent_device(VK_NULL_HANDLE), instance_table(nullptr), object_info_table(object_info_table),
    replay_device_phys_mem_props(nullptr), current_dispatch_index(0), current_trace_rays_index(0), dump_json(dump_json),
    output_json_per_command(options.dump_resources_json_per_command),
    dump_immutable_resources(options.dump_resources_dump_immutable_resources),
    dump_all_image_subresources(options.dump_resources_dump_all_image_subresources), capture_filename(capture_filename),
    reached_end_command_buffer(false), dump_images_raw(options.dump_resources_dump_raw_images)
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

void DispatchTraceRaysDumpingContext::BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline)
{
    PipelineBindPoints point = VkPipelineBindPointToPipelineBindPoint(bind_point);
    bound_pipelines[point]   = pipeline;
}

void DispatchTraceRaysDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                                pipeline_bind_point,
    uint32_t                                           first_set,
    const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                           dynamicOffsetCount,
    const uint32_t*                                    pDynamicOffsets)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    if (bind_point != kBindPoint_compute && bind_point != kBindPoint_ray_tracing)
    {
        return;
    }

    uint32_t dynamic_offset_index = 0;
    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        uint32_t set_index = first_set + i;

        VulkanDescriptorSetInfo* bound_descriptor_sets;
        if (bind_point == kBindPoint_compute)
        {
            bound_descriptor_sets = &bound_descriptor_sets_compute[set_index];
        }
        else
        {
            assert(bind_point == kBindPoint_ray_tracing);
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

    // Scan for mutable resources in the bound pipeline
    const uint32_t      bind_point = static_cast<uint32_t>(is_dispatch ? kBindPoint_compute : kBindPoint_ray_tracing);
    const VulkanPipelineInfo* pipeline   = bound_pipelines[bind_point];
    assert(pipeline != nullptr);

    for (const auto& shader : pipeline->shaders)
    {
        for (const auto& shader_desc_set : shader.second.used_descriptors_info)
        {
            const uint32_t desc_set_index = shader_desc_set.first;

            for (const auto& shader_desc_binding : shader_desc_set.second)
            {
                // Search for resources that are not marked as read only
                if (shader_desc_binding.second.accessed && !shader_desc_binding.second.readonly)
                {
                    const uint32_t binding_index = shader_desc_binding.first;

                    const VulkanDescriptorSetInfo* bound_descriptor_sets =
                        is_dispatch ? &bound_descriptor_sets_compute[desc_set_index]
                                    : &bound_descriptor_sets_ray_tracing[desc_set_index];
                    assert(bound_descriptor_sets != nullptr);

                    const auto& bound_desc_binding = bound_descriptor_sets->descriptors.find(binding_index);
                    assert(bound_desc_binding != bound_descriptor_sets->descriptors.end());
                    assert(CheckDescriptorCompatibility(bound_desc_binding->second.desc_type,
                                                        shader_desc_binding.second.type));

                    switch (shader_desc_binding.second.type)
                    {
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        {
                            uint32_t array_index = 0;
                            for (const auto& img_desc : bound_desc_binding->second.image_info)
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
                                new_entry.stage          = shader.first;
                                new_entry.desc_type      = shader_desc_binding.second.type;
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
                            for (const auto& buf_desc : bound_desc_binding->second.buffer_info)
                            {
                                const VulkanBufferInfo* buf_info = buf_desc.buffer_info;
                                if (buf_info == nullptr)
                                {
                                    continue;
                                }

                                auto& new_entry           = resource_backup_context.buffers.emplace_back();
                                new_entry.original_buffer = buf_info;
                                new_entry.stage           = shader.first;
                                new_entry.desc_type       = shader_desc_binding.second.type;
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
                            GFXRECON_LOG_WARNING_ONCE(
                                "%s(): Descriptor type (%s) not handled",
                                __func__,
                                util::ToString<VkDescriptorType>(shader_desc_binding.second.type).c_str());
                            break;
                    }
                }
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

        GenerateOutputJsonDispatchInfo(qs_index, bcb_index, disp_index, i);
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

        GenerateOutputJsonTraceRaysIndex(qs_index, bcb_index, tr_index, i);
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

std::string DispatchTraceRaysDumpingContext::GenerateDispatchTraceRaysImageFilename(VkFormat              format,
                                                                                    uint32_t              mip,
                                                                                    uint32_t              layer,
                                                                                    VkImageAspectFlagBits aspect,
                                                                                    VkImageTiling         tiling,
                                                                                    VkImageType           type,
                                                                                    bool                  is_dispatch,
                                                                                    uint64_t              qs_index,
                                                                                    uint64_t              bcb_index,
                                                                                    uint64_t              cmd_index,
                                                                                    uint32_t              desc_set,
                                                                                    uint32_t              desc_binding,
                                                                                    uint32_t              array_index,
                                                                                    VkShaderStageFlagBits stage,
                                                                                    bool before_cmd) const
{
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(device_info,
                                                                       device_table,
                                                                       instance_table,
                                                                       object_info_table,
                                                                       format,
                                                                       tiling,
                                                                       type,
                                                                       image_file_format,
                                                                       dump_images_raw);

    const std::string shader_stage_name = ShaderStageToStr(stage);
    const std::string aspect_str        = ImageAspectToStr(aspect);

    std::stringstream filename;
    filename << capture_filename << '_';

    if (before_cmd)
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << cmd_index << "_qs_" << qs_index << "_bcb_"
                 << bcb_index << "_before_stage_" << shader_stage_name << "_set_" << desc_set << "_binding_"
                 << desc_binding << "_index_" << array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }
    else
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << cmd_index << "_qs_" << qs_index << "_bcb_"
                 << bcb_index << "_" << (dump_resources_before ? "after_" : "") << "stage_" << shader_stage_name
                 << "_set_" << desc_set << "_binding_" << desc_binding << "_index_" << array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }

    if (dump_all_image_subresources)
    {
        filename << "_mip_" << mip << "_layer_" << layer;
    }

    filename << ImageFileExtension(output_image_format);

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DispatchTraceRaysDumpingContext::GenerateDispatchTraceRaysBufferFilename(bool                  is_dispatch,
                                                                                     uint64_t              qs_index,
                                                                                     uint64_t              bcb_index,
                                                                                     uint64_t              cmd_index,
                                                                                     uint32_t              desc_set,
                                                                                     uint32_t              desc_binding,
                                                                                     uint32_t              array_index,
                                                                                     VkShaderStageFlagBits stage,
                                                                                     bool before_cmd) const
{
    std::stringstream filename;

    filename << capture_filename << '_';

    const std::string shader_stage_name = ShaderStageToStr(stage);

    if (before_cmd)
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << cmd_index << "_qs_" << qs_index << "_bcb_"
                 << bcb_index << "_before_stage_" << shader_stage_name << "_set_" << desc_set << "_binding_"
                 << desc_binding << "_index_" << array_index << "_buffer.bin";
    }
    else
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << cmd_index << "_qs_" << qs_index << "_bcb_"
                 << bcb_index << "_" << (dump_resources_before ? "after_" : "") << "stage_" << shader_stage_name
                 << "_set_" << desc_set << "_binding_" << desc_binding << "_index_" << array_index << "_buffer.bin";
    }

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
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

    if (dump_resources_before)
    {
        // Dump images
        for (size_t i = 0; i < mutable_resources_clones_before.images.size(); ++i)
        {
            assert(mutable_resources_clones_before.images[i].original_image != nullptr);
            assert(mutable_resources_clones_before.images[i].image != VK_NULL_HANDLE);

            VulkanImageInfo modified_image_info = *mutable_resources_clones_before.images[i].original_image;
            modified_image_info.handle    = mutable_resources_clones_before.images[i].image;

            const uint32_t              desc_set    = mutable_resources_clones_before.images[i].desc_set;
            const uint32_t              binding     = mutable_resources_clones_before.images[i].desc_binding;
            const uint32_t              array_index = mutable_resources_clones_before.images[i].array_index;
            const VkShaderStageFlagBits stage       = mutable_resources_clones_before.images[i].stage;

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(modified_image_info.format, aspects);

            const size_t total_files =
                dump_all_image_subresources
                    ? (aspects.size() * modified_image_info.layer_count * modified_image_info.level_count)
                    : aspects.size();

            std::vector<std::string> filenames(total_files);
            size_t                   f = 0;
            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < modified_image_info.level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < modified_image_info.layer_count; ++layer)
                    {
                        filenames[f++] = GenerateDispatchTraceRaysImageFilename(modified_image_info.format,
                                                                                mip,
                                                                                layer,
                                                                                aspect,
                                                                                modified_image_info.tiling,
                                                                                modified_image_info.type,
                                                                                is_dispatch,
                                                                                qs_index,
                                                                                bcb_index,
                                                                                cmd_index,
                                                                                desc_set,
                                                                                binding,
                                                                                array_index,
                                                                                stage,
                                                                                true);

                        if (!dump_all_image_subresources)
                        {
                            break;
                        }
                    }

                    if (!dump_all_image_subresources)
                    {
                        break;
                    }
                }
            }

            std::vector<bool> scaling_supported(filenames.size());
            VkResult          res = DumpImageToFile(&modified_image_info,
                                           device_info,
                                           device_table,
                                           instance_table,
                                           object_info_table,
                                           filenames,
                                           dump_resources_scale,
                                           scaling_supported,
                                           image_file_format,
                                           false,
                                           dump_images_raw,
                                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping image failed (%s)", util::ToString<VkResult>(res).c_str())
                return res;
            }

            // Keep track of images for which scaling failed
            for (size_t i = 0; i < filenames.size(); ++i)
            {
                if (!scaling_supported[i])
                {
                    images_failed_scaling.insert(filenames[i]);
                }
            }
        }

        // Dump buffers
        for (size_t i = 0; i < mutable_resources_clones_before.buffers.size(); ++i)
        {
            const VulkanBufferInfo* buffer_info = mutable_resources_clones_before.buffers[i].original_buffer;
            assert(buffer_info != nullptr);
            assert(mutable_resources_clones_before.buffers[i].buffer != VK_NULL_HANDLE);

            std::vector<uint8_t> data;

            VkResult res = resource_util.ReadFromBufferResource(mutable_resources_clones_before.buffers[i].buffer,
                                                                buffer_info->size,
                                                                0,
                                                                buffer_info->queue_family_index,
                                                                data);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
                return res;
            }

            const uint32_t              desc_set    = mutable_resources_clones_before.buffers[i].desc_set;
            const uint32_t              binding     = mutable_resources_clones_before.buffers[i].desc_binding;
            const uint32_t              array_index = mutable_resources_clones_before.buffers[i].array_index;
            const VkShaderStageFlagBits stage       = mutable_resources_clones_before.buffers[i].stage;

            std::string filename = GenerateDispatchTraceRaysBufferFilename(
                is_dispatch, qs_index, bcb_index, cmd_index, desc_set, binding, array_index, stage, true);
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    for (size_t i = 0; i < mutable_resources_clones.images.size(); ++i)
    {
        assert(mutable_resources_clones.images[i].original_image != nullptr);
        assert(mutable_resources_clones.images[i].image != VK_NULL_HANDLE);

        VulkanImageInfo modified_image_info = *mutable_resources_clones.images[i].original_image;
        modified_image_info.handle    = mutable_resources_clones.images[i].image;

        const uint32_t              desc_set    = mutable_resources_clones.images[i].desc_set;
        const uint32_t              binding     = mutable_resources_clones.images[i].desc_binding;
        const uint32_t              array_index = mutable_resources_clones.images[i].array_index;
        const VkShaderStageFlagBits stage       = mutable_resources_clones.images[i].stage;

        std::vector<VkImageAspectFlagBits> aspects;
        GetFormatAspects(modified_image_info.format, aspects);

        const size_t total_files =
            dump_all_image_subresources
                ? (aspects.size() * modified_image_info.layer_count * modified_image_info.level_count)
                : aspects.size();

        std::vector<std::string> filenames(total_files);
        size_t                   f = 0;
        for (auto aspect : aspects)
        {
            for (uint32_t mip = 0; mip < modified_image_info.level_count; ++mip)
            {
                for (uint32_t layer = 0; layer < modified_image_info.layer_count; ++layer)
                {
                    filenames[f++] = GenerateDispatchTraceRaysImageFilename(modified_image_info.format,
                                                                            mip,
                                                                            layer,
                                                                            aspect,
                                                                            modified_image_info.tiling,
                                                                            modified_image_info.type,
                                                                            is_dispatch,
                                                                            qs_index,
                                                                            bcb_index,
                                                                            cmd_index,
                                                                            desc_set,
                                                                            binding,
                                                                            array_index,
                                                                            stage,
                                                                            false);

                    if (!dump_all_image_subresources)
                    {
                        break;
                    }
                }

                if (!dump_all_image_subresources)
                {
                    break;
                }
            }
        }

        std::vector<bool> scaling_supported(filenames.size());
        VkResult          res = DumpImageToFile(&modified_image_info,
                                       device_info,
                                       device_table,
                                       instance_table,
                                       object_info_table,
                                       filenames,
                                       dump_resources_scale,
                                       scaling_supported,
                                       image_file_format,
                                       false,
                                       dump_images_raw,
                                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping image failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Keep track of images for which scaling failed
        for (size_t i = 0; i < filenames.size(); ++i)
        {
            if (!scaling_supported[i])
            {
                images_failed_scaling.insert(filenames[i]);
            }
        }
    }

    // Dump buffers
    for (size_t i = 0; i < mutable_resources_clones.buffers.size(); ++i)
    {
        assert(mutable_resources_clones.buffers[i].original_buffer != nullptr);
        assert(mutable_resources_clones.buffers[i].buffer != VK_NULL_HANDLE);
        const VulkanBufferInfo* buffer_info = mutable_resources_clones.buffers[i].original_buffer;
        std::vector<uint8_t> data;

        VkResult res = resource_util.ReadFromBufferResource(
            mutable_resources_clones.buffers[i].buffer, buffer_info->size, 0, buffer_info->queue_family_index, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        const uint32_t              desc_set    = mutable_resources_clones.buffers[i].desc_set;
        const uint32_t              binding     = mutable_resources_clones.buffers[i].desc_binding;
        const uint32_t              array_index = mutable_resources_clones.buffers[i].array_index;
        const VkShaderStageFlagBits stage       = mutable_resources_clones.buffers[i].stage;

        std::string filename = GenerateDispatchTraceRaysBufferFilename(
            is_dispatch, qs_index, bcb_index, cmd_index, desc_set, binding, array_index, stage, false);
        util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
    }

    return VK_SUCCESS;
}

bool DispatchTraceRaysDumpingContext::IsRecording() const
{
    return !reached_end_command_buffer;
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptors(DispatchParameters& disp_params)
{
    const VulkanPipelineInfo* compute_ppl = bound_pipelines[kBindPoint_compute];
    if (compute_ppl == nullptr)
    {
        return;
    }

    assert(compute_ppl->shaders.size() == 1);

    const auto shader_stage_entry = compute_ppl->shaders.find(VK_SHADER_STAGE_COMPUTE_BIT);
    if (shader_stage_entry == compute_ppl->shaders.end())
    {
        return;
    }

    const VulkanShaderModuleInfo& compute_shader = shader_stage_entry->second;
    for (const auto& shader_desc_set : compute_shader.used_descriptors_info)
    {
        const uint32_t desc_set_index             = shader_desc_set.first;
        const auto&    bound_descriptor_set_entry = bound_descriptor_sets_compute.find(desc_set_index);
        if (bound_descriptor_set_entry == bound_descriptor_sets_compute.end())
        {
            continue;
        }

        const VulkanDescriptorSetInfo* bound_descriptor_set = &bound_descriptor_set_entry->second;

        for (const auto& shader_desc_binding : shader_desc_set.second)
        {
            // if (!shader_desc_binding.second.accessed)
            // {
            //     continue;
            // }

            const uint32_t desc_binding_index = shader_desc_binding.first;

            const auto& bound_descriptor_entry = bound_descriptor_set->descriptors.find(desc_binding_index);
            if (bound_descriptor_entry == bound_descriptor_set->descriptors.end())
            {
                continue;
            }

            disp_params.referenced_descriptors[desc_set_index][desc_binding_index] = bound_descriptor_entry->second;
        }
    }
}

void DispatchTraceRaysDumpingContext::SnapshotBoundDescriptors(TraceRaysParameters& tr_params)
{
    const VulkanPipelineInfo* ray_tracing_ppl = bound_pipelines[kBindPoint_ray_tracing];
    if (ray_tracing_ppl == nullptr)
    {
        return;
    }

    for (const auto& shader_stage_entry : ray_tracing_ppl->shaders)
    {
        const VulkanShaderModuleInfo& rt_stage_shader_info = shader_stage_entry.second;
        for (const auto& shader_desc_set : rt_stage_shader_info.used_descriptors_info)
        {
            const uint32_t desc_set_index             = shader_desc_set.first;
            const auto&    bound_descriptor_set_entry = bound_descriptor_sets_ray_tracing.find(desc_set_index);
            if (bound_descriptor_set_entry == bound_descriptor_sets_ray_tracing.end())
            {
                continue;
            }

            const VulkanDescriptorSetInfo* bound_descriptor_set = &bound_descriptor_set_entry->second;

            for (const auto& shader_desc_binding : shader_desc_set.second)
            {
                // if (!shader_desc_binding.second.accessed)
                // {
                //     continue;
                // }

                const uint32_t desc_binding_index = shader_desc_binding.first;

                const auto& bound_descriptor_entry = bound_descriptor_set->descriptors.find(desc_binding_index);
                if (bound_descriptor_entry == bound_descriptor_set->descriptors.end())
                {
                    continue;
                }

                tr_params.referenced_descriptors[shader_stage_entry.first][desc_set_index][desc_binding_index] =
                    bound_descriptor_entry->second;
            }
        }
    }
}

std::string DispatchTraceRaysDumpingContext::GenerateImageDescriptorFilename(VkFormat              format,
                                                                             uint32_t              mip,
                                                                             uint32_t              layer,
                                                                             format::HandleId      image_id,
                                                                             VkImageAspectFlagBits aspect,
                                                                             VkImageTiling         tiling,
                                                                             VkImageType           type,
                                                                             uint64_t              qs_index,
                                                                             uint64_t              bcb_index) const
{
    std::string       aspect_str = ImageAspectToStr(aspect);
    std::stringstream base_filename;

    base_filename << capture_filename << '_';

    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(device_info,
                                                                       device_table,
                                                                       instance_table,
                                                                       object_info_table,
                                                                       format,
                                                                       tiling,
                                                                       type,
                                                                       image_file_format,
                                                                       dump_images_raw);

    if (output_image_format != KFormatRaw && output_image_format != KFormatAstc)
    {
        base_filename << "image_" << image_id << "_qs_" << qs_index << "_bcb_" << bcb_index << "_aspect_" << aspect_str;
    }
    else
    {
        std::string format_name = FormatToStr(format);
        base_filename << "image_" << image_id << "_qs_" << qs_index << "_bcb_" << bcb_index << "_" << format_name
                      << "_aspect_" << aspect_str;
    }

    if (dump_all_image_subresources)
    {
        std::stringstream sub_resources_str;
        sub_resources_str << base_filename.str() << "_mip_" << mip << "_layer_" << layer;
        sub_resources_str << ImageFileExtension(output_image_format);
        std::filesystem::path filedirname(dump_resource_path);
        std::filesystem::path filebasename(sub_resources_str.str());
        return (filedirname / filebasename).string();
    }
    else
    {
        base_filename << ImageFileExtension(output_image_format);
        std::filesystem::path filedirname(dump_resource_path);
        std::filesystem::path filebasename(base_filename.str());
        return (filedirname / filebasename).string();
    }
}

std::string DispatchTraceRaysDumpingContext::GenerateBufferDescriptorFilename(uint64_t         qs_index,
                                                                              uint64_t         bcb_index,
                                                                              format::HandleId buffer_id) const
{
    std::stringstream filename;

    filename << capture_filename << "_buffer_" << buffer_id << "_qs_" << qs_index << "_bcb_" << bcb_index << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DispatchTraceRaysDumpingContext::GenerateInlineUniformBufferDescriptorFilename(uint64_t qs_index,
                                                                                           uint64_t bcb_index,
                                                                                           uint32_t set,
                                                                                           uint32_t binding) const
{
    std::stringstream filename;
    filename << capture_filename << '_' << "inlineUniformBlock_set_" << set << "_binding_" << binding << "_qs_"
             << qs_index << "_bcb_" << bcb_index << ".bin";

    std::filesystem::path filedirname(dump_resource_path);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
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
        for (const auto& shader_stage : tr_params->second.referenced_descriptors)
        {
            for (const auto& desc_set : shader_stage.second)
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
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table.GetVkDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    for (const auto& img_info : image_descriptors)
    {
        std::vector<VkImageAspectFlagBits> aspects;
        GetFormatAspects(img_info->format, aspects);

        const size_t total_files = dump_all_image_subresources
                                       ? (aspects.size() * img_info->layer_count * img_info->level_count)
                                       : aspects.size();

        std::vector<std::string> filenames(total_files);

        size_t f = 0;
        for (auto aspect : aspects)
        {
            for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
            {
                for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                {
                    filenames[f++] = GenerateImageDescriptorFilename(img_info->format,
                                                                     mip,
                                                                     layer,
                                                                     img_info->capture_id,
                                                                     aspect,
                                                                     img_info->tiling,
                                                                     img_info->type,
                                                                     qs_index,
                                                                     bcb_index);

                    if (!dump_all_image_subresources)
                    {
                        break;
                    }
                }

                if (!dump_all_image_subresources)
                {
                    break;
                }
            }
        }

        std::vector<bool> scaling_supported(filenames.size());
        VkResult          res = DumpImageToFile(img_info,
                                       device_info,
                                       device_table,
                                       instance_table,
                                       object_info_table,
                                       filenames,
                                       dump_resources_scale,
                                       scaling_supported,
                                       image_file_format,
                                       dump_all_image_subresources,
                                       dump_images_raw);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping image failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Keep track of images for which scaling failed
        for (size_t i = 0; i < filenames.size(); ++i)
        {
            if (!scaling_supported[i])
            {
                images_failed_scaling.insert(filenames[i]);
            }
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
        const VulkanBufferInfo* buffer_info = buf.first;
        const VkDeviceSize offset      = buf.second.offset;
        const VkDeviceSize range       = buf.second.range;
        const VkDeviceSize size        = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

        std::vector<uint8_t> data;
        VkResult             res = resource_util.ReadFromBufferResource(
            buffer_info->handle, size, offset, buffer_info->queue_family_index, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        const std::string filename = GenerateBufferDescriptorFilename(qs_index, bcb_index, buffer_info->capture_id);
        util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
    }

    for (const auto& iub : inline_uniform_blocks)
    {
        std::string filename =
            GenerateInlineUniformBufferDescriptorFilename(qs_index, bcb_index, iub.second.set, iub.second.binding);
        util::bufferwriter::WriteBuffer(filename, iub.second.data->data(), iub.second.data->size());
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

void DispatchTraceRaysDumpingContext::GenerateOutputJsonDispatchInfo(uint64_t qs_index,
                                                                     uint64_t bcb_index,
                                                                     uint64_t disp_index,
                                                                     uint64_t cmd_index) const
{
    if (dispatch_params.empty())
    {
        return;
    }

    if (output_json_per_command)
    {
        std::stringstream filename;
        filename << "Dispatch_" << disp_index << "_qs_" << qs_index << "_bcb_" << bcb_index << ".json";
        std::filesystem::path filedirname(dump_resource_path);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json.Open(full_filename);
        dump_json.BlockStart();
    }

    auto& current_block         = dump_json.GetCurrentSubEntry();
    auto& dispatch_json_entries = !output_json_per_command ? current_block["dispatchCommands"] : dump_json.GetData();
    auto& dispatch_json_entry   = !output_json_per_command ? dispatch_json_entries[cmd_index] : dump_json.GetData();

    const auto& disp_params = dispatch_params.find(disp_index);

    dispatch_json_entry["dispatchIndex"]           = disp_index;
    dispatch_json_entry["beginCommandBufferIndex"] = bcb_index;
    dispatch_json_entry["queueSubmitIndex"]        = qs_index;

    auto& params_json_entries           = dispatch_json_entry["parameters"];
    params_json_entries["dispatchType"] = DispatchTypeToStr(disp_params->second.type);
    switch (disp_params->second.type)
    {
        case kDispatch:
        {
            const DispatchParameters::DispatchParamsUnion::DispatchParams& ds_params =
                disp_params->second.dispatch_params_union.dispatch;

            params_json_entries["groupCountX"] = ds_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.groupCountZ;
        }
        break;

        case kDispatchIndirect:
        {
            const DispatchParameters::DispatchParamsUnion::DispatchIndirect& ds_params =
                disp_params->second.dispatch_params_union.dispatch_indirect;

            assert(ds_params.dispatch_params != nullptr);
            params_json_entries["groupCountX"] = ds_params.dispatch_params->groupCountX;
            params_json_entries["groupCountY"] = ds_params.dispatch_params->groupCountY;
            params_json_entries["groupCountZ"] = ds_params.dispatch_params->groupCountZ;
        }
        break;

        case kDispatchBase:
        {
            const DispatchParameters::DispatchParamsUnion::DispatchBaseParams& ds_params =
                disp_params->second.dispatch_params_union.dispatch_base;

            params_json_entries["baseGroupX"]  = ds_params.baseGroupX;
            params_json_entries["baseGroupY"]  = ds_params.baseGroupY;
            params_json_entries["baseGroupZ"]  = ds_params.baseGroupZ;
            params_json_entries["groupCountX"] = ds_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.groupCountZ;
        }
        break;

        default:
            assert(0);
    }

    auto& outputs_json_entries = dispatch_json_entry["outputs"];

    if (dump_resources_before)
    {
        const auto& mutable_resource_entry_before = disp_params->second.mutable_resources_clones_before;
        if (!mutable_resource_entry_before.images.empty())
        {
            auto&    before_command_output_image_entries = outputs_json_entries["before"]["images"];
            uint32_t output_image_index                  = 0;

            for (const auto& image : mutable_resource_entry_before.images)
            {
                const uint32_t              desc_set    = image.desc_set;
                const uint32_t              binding     = image.desc_binding;
                const uint32_t              array_index = image.array_index;
                const VkShaderStageFlagBits stage       = image.stage;
                const VulkanImageInfo*      img_info    = image.original_image;
                assert(img_info != nullptr);

                auto& image_json_entry         = before_command_output_image_entries[output_image_index++];
                image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
                image_json_entry["set"]        = desc_set;
                image_json_entry["binding"]    = binding;
                image_json_entry["arrayIndex"] = array_index;
                auto& image_json_entry_desc    = image_json_entry["images"];

                std::vector<VkImageAspectFlagBits> aspects;
                GetFormatAspects(img_info->format, aspects);

                size_t f = 0;
                for (auto aspect : aspects)
                {
                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                    {
                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                        {
                            std::string filename = GenerateDispatchTraceRaysImageFilename(img_info->format,
                                                                                          mip,
                                                                                          layer,
                                                                                          aspect,
                                                                                          img_info->tiling,
                                                                                          img_info->type,
                                                                                          true,
                                                                                          qs_index,
                                                                                          bcb_index,
                                                                                          disp_index,
                                                                                          desc_set,
                                                                                          binding,
                                                                                          array_index,
                                                                                          stage,
                                                                                          true);

                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                        std::max(1u, img_info->extent.height >> mip),
                                                        img_info->extent.depth };

                            dump_json.InsertImageInfo(image_json_entry_desc[f++],
                                                      img_info->format,
                                                      img_info->type,
                                                      img_info->capture_id,
                                                      extent,
                                                      filename,
                                                      aspect,
                                                      ImageFailedScaling(filename),
                                                      mip,
                                                      layer);

                            if (!dump_all_image_subresources)
                            {
                                break;
                            }
                        }

                        if (!dump_all_image_subresources)
                        {
                            break;
                        }
                    }
                }
            }
        }

        if (!mutable_resource_entry_before.buffers.empty())
        {
            auto&    before_command_output_buffer_entries = outputs_json_entries["before"]["buffers"];
            uint32_t output_buffer_index                  = 0;

            for (const auto& buffer : mutable_resource_entry_before.buffers)
            {
                const uint32_t              desc_set    = buffer.desc_set;
                const uint32_t              binding     = buffer.desc_binding;
                const uint32_t              array_index = buffer.array_index;
                const VkShaderStageFlagBits stage       = buffer.stage;
                const VulkanBufferInfo*     buffer_info = buffer.original_buffer;
                assert(buffer_info != nullptr);

                std::string filename = GenerateDispatchTraceRaysBufferFilename(
                    true, qs_index, bcb_index, disp_index, desc_set, binding, array_index, stage, true);

                auto& buffer_json_entry         = before_command_output_buffer_entries[output_buffer_index++];
                buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
                buffer_json_entry["set"]        = desc_set;
                buffer_json_entry["binding"]    = binding;
                buffer_json_entry["arrayIndex"] = array_index;
                dump_json.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
            }
        }
    }

    const auto& mutable_resource_entry = disp_params->second.mutable_resources_clones;
    if (!mutable_resource_entry.images.empty())
    {
        auto& outputs_json_entries_after = dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;
        auto& image_outputs_json_entries = outputs_json_entries_after["images"];

        uint32_t mutable_images_count = 0;
        for (const auto& image : mutable_resource_entry.images)
        {
            const uint32_t              desc_set    = image.desc_set;
            const uint32_t              binding     = image.desc_binding;
            const uint32_t              array_index = image.array_index;
            const VkShaderStageFlagBits stage       = image.stage;
            const VulkanImageInfo*      img_info    = image.original_image;
            assert(img_info != nullptr);

            auto& image_json_entry         = image_outputs_json_entries[mutable_images_count++];
            image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
            image_json_entry["set"]        = desc_set;
            image_json_entry["binding"]    = binding;
            image_json_entry["arrayIndex"] = array_index;
            auto& image_json_entry_desc    = image_json_entry["images"];

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(img_info->format, aspects);

            size_t f = 0;
            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                    {
                        std::string filename = GenerateDispatchTraceRaysImageFilename(img_info->format,
                                                                                      mip,
                                                                                      layer,
                                                                                      aspect,
                                                                                      img_info->tiling,
                                                                                      img_info->type,
                                                                                      true,
                                                                                      qs_index,
                                                                                      bcb_index,
                                                                                      disp_index,
                                                                                      desc_set,
                                                                                      binding,
                                                                                      array_index,
                                                                                      stage,
                                                                                      false);

                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                    std::max(1u, img_info->extent.height >> mip),
                                                    img_info->extent.depth };

                        dump_json.InsertImageInfo(image_json_entry_desc[f++],
                                                  img_info->format,
                                                  img_info->type,
                                                  img_info->capture_id,
                                                  extent,
                                                  filename,
                                                  aspect,
                                                  ImageFailedScaling(filename),
                                                  mip,
                                                  layer);

                        if (!dump_all_image_subresources)
                        {
                            break;
                        }
                    }

                    if (!dump_all_image_subresources)
                    {
                        break;
                    }
                }
            }
        }
    }

    if (!mutable_resource_entry.buffers.empty())
    {
        auto& outputs_json_entries_after = dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;
        auto& buffer_outputs_json_entries = outputs_json_entries_after["buffers"];

        uint32_t mutable_buffers_count = 0;
        for (const auto& buffer : mutable_resource_entry.buffers)
        {
            const uint32_t              desc_set    = buffer.desc_set;
            const uint32_t              binding     = buffer.desc_binding;
            const uint32_t              array_index = buffer.array_index;
            const VkShaderStageFlagBits stage       = buffer.stage;
            const VulkanBufferInfo*     buffer_info = buffer.original_buffer;
            assert(buffer_info != nullptr);

            std::string filename = GenerateDispatchTraceRaysBufferFilename(
                true, qs_index, bcb_index, disp_index, desc_set, binding, array_index, stage, false);

            auto& buffer_json_entry         = buffer_outputs_json_entries[mutable_buffers_count++];
            buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
            buffer_json_entry["set"]        = desc_set;
            buffer_json_entry["binding"]    = binding;
            buffer_json_entry["arrayIndex"] = array_index;
            dump_json.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
        }
    }

    if (dump_immutable_resources)
    {
        uint32_t descriptor_entries_count = 0;
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
                            if (desc_binding.second.image_info[i].image_view_info == nullptr)
                            {
                                continue;
                            }

                            auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                            entry["type"]       = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                            entry["set"]        = desc_set_index;
                            entry["binding"]    = desc_binding_index;
                            entry["arrayIndex"] = i;

                            const VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(
                                desc_binding.second.image_info[i].image_view_info->image_id);
                            assert(img_info);

                            std::vector<VkImageAspectFlagBits> aspects;
                            GetFormatAspects(img_info->format, aspects);

                            size_t f = 0;
                            for (auto aspect : aspects)
                            {
                                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                                {
                                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                                    {
                                        std::string filename = GenerateImageDescriptorFilename(img_info->format,
                                                                                               mip,
                                                                                               layer,
                                                                                               img_info->capture_id,
                                                                                               aspect,
                                                                                               img_info->tiling,
                                                                                               img_info->type,
                                                                                               qs_index,
                                                                                               bcb_index);

                                        auto&            image_descriptor_json_entry = entry["descriptor"];
                                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                                    std::max(1u, img_info->extent.height >> mip),
                                                                    img_info->extent.depth };

                                        dump_json.InsertImageInfo(image_descriptor_json_entry[f++],
                                                                  img_info->format,
                                                                  img_info->type,
                                                                  img_info->capture_id,
                                                                  extent,
                                                                  filename,
                                                                  aspect,
                                                                  ImageFailedScaling(filename),
                                                                  mip,
                                                                  layer);

                                        if (!dump_all_image_subresources)
                                        {
                                            break;
                                        }
                                    }

                                    if (!dump_all_image_subresources)
                                    {
                                        break;
                                    }
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
                            if (desc_binding.second.buffer_info[i].buffer_info != nullptr)
                            {
                                auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                                entry["type"]       = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                                entry["set"]        = desc_set_index;
                                entry["binding"]    = desc_binding_index;
                                entry["arrayIndex"] = i;

                                auto& buffer_descriptor_json_entry = entry["descriptor"];

                                const std::string filename = GenerateBufferDescriptorFilename(
                                    qs_index, bcb_index, desc_binding.second.buffer_info[i].buffer_info->capture_id);
                                dump_json.InsertBufferInfo(buffer_descriptor_json_entry,
                                                           desc_binding.second.buffer_info[i].buffer_info,
                                                           filename);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                        entry["type"]    = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                        entry["set"]     = desc_set_index;
                        entry["binding"] = desc_binding_index;
                        entry["size"]    = desc_binding.second.inline_uniform_block.size();

                        const std::string filename = GenerateInlineUniformBufferDescriptorFilename(
                            qs_index, bcb_index, desc_set_index, desc_binding_index);
                        entry["file"] = filename;
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

    if (output_json_per_command)
    {
        dump_json.BlockEnd();
        dump_json.Close();
    }
}

void DispatchTraceRaysDumpingContext::GenerateOutputJsonTraceRaysIndex(uint64_t qs_index,
                                                                       uint64_t bcb_index,
                                                                       uint64_t tr_index,
                                                                       uint64_t cmd_index) const
{
    auto& current_block = dump_json.GetCurrentSubEntry();

    auto& tr_json_entries = (!trace_rays_params.empty() && !output_json_per_command)
                                ? current_block["traceRaysCommands"]
                                : dump_json.GetData();

    if (output_json_per_command)
    {
        std::stringstream filename;
        filename << "TraceRays_" << tr_index << "_qs_" << qs_index << "_bcb_" << bcb_index << ".json";
        std::filesystem::path filedirname(dump_resource_path);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json.Open(full_filename);
        dump_json.BlockStart();
    }
    const auto& tr_params = trace_rays_params.find(tr_index);

    auto& tr_entry = !output_json_per_command ? tr_json_entries[cmd_index] : dump_json.GetData();

    tr_entry["traceRaysIndex"]          = tr_index;
    tr_entry["beginCommandBufferIndex"] = bcb_index;
    tr_entry["queueSubmitIndex"]        = qs_index;

    auto& params_json_entries            = tr_entry["parameters"];
    params_json_entries["traceRaysType"] = TraceRaysTypeToStr(tr_params->second.type);

    switch (tr_params->second.type)
    {
        case kTraceRays:
        {
            const VkTraceRaysIndirectCommandKHR& params = tr_params->second.trace_rays_params_union.trace_rays;

            params_json_entries["width"]  = params.width;
            params_json_entries["height"] = params.height;
            params_json_entries["depth"]  = params.depth;
        }
        break;

        case kTraceRaysIndirect:
        {
            const TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect& params =
                tr_params->second.trace_rays_params_union.trace_rays_indirect;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        case kTraceRaysIndirect2:
        {
            const TraceRaysParameters::TraceRaysParamsUnion::TraceRaysIndirect2& params =
                tr_params->second.trace_rays_params_union.trace_rays_indirect2;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        default:
            assert(0);
    }

    auto& outputs_json_entries = tr_entry["outputs"];

    if (dump_resources_before)
    {
        const auto& mutable_resource_entry_before = tr_params->second.mutable_resources_clones_before;
        if (!mutable_resource_entry_before.images.empty())
        {
            auto&    before_command_output_image_entries = outputs_json_entries["before"]["images"];
            uint32_t output_image_index                  = 0;

            for (const auto& image : mutable_resource_entry_before.images)
            {
                const uint32_t              desc_set    = image.desc_set;
                const uint32_t              binding     = image.desc_binding;
                const uint32_t              array_index = image.array_index;
                const VkShaderStageFlagBits stage       = image.stage;
                const VulkanImageInfo*      img_info    = image.original_image;
                assert(img_info != nullptr);

                std::vector<VkImageAspectFlagBits> aspects;
                GetFormatAspects(img_info->format, aspects);

                auto& image_json_entry         = before_command_output_image_entries[output_image_index++];
                image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
                image_json_entry["set"]        = desc_set;
                image_json_entry["binding"]    = binding;
                image_json_entry["arrayIndex"] = array_index;
                auto& image_json_entry_desc    = image_json_entry["images"];

                size_t f = 0;
                for (auto aspect : aspects)
                {
                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                    {
                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                        {
                            std::string filename = GenerateDispatchTraceRaysImageFilename(img_info->format,
                                                                                          mip,
                                                                                          layer,
                                                                                          aspect,
                                                                                          img_info->tiling,
                                                                                          img_info->type,
                                                                                          false,
                                                                                          qs_index,
                                                                                          bcb_index,
                                                                                          tr_index,
                                                                                          desc_set,
                                                                                          binding,
                                                                                          array_index,
                                                                                          stage,
                                                                                          true);

                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                        std::max(1u, img_info->extent.height >> mip),
                                                        img_info->extent.depth };

                            dump_json.InsertImageInfo(image_json_entry_desc[f++],
                                                      img_info->format,
                                                      img_info->type,
                                                      img_info->capture_id,
                                                      extent,
                                                      filename,
                                                      aspect,
                                                      ImageFailedScaling(filename),
                                                      mip,
                                                      layer);

                            if (!dump_all_image_subresources)
                            {
                                break;
                            }
                        }

                        if (!dump_all_image_subresources)
                        {
                            break;
                        }
                    }
                }
            }
        }

        if (!mutable_resource_entry_before.buffers.empty())
        {
            auto&    before_command_output_buffer_entries = outputs_json_entries["before"]["buffers"];
            uint32_t output_buffer_index                  = 0;

            for (const auto& buffer : mutable_resource_entry_before.buffers)
            {
                const uint32_t              desc_set    = buffer.desc_set;
                const uint32_t              binding     = buffer.desc_binding;
                const uint32_t              array_index = buffer.array_index;
                const VkShaderStageFlagBits stage       = buffer.stage;
                const VulkanBufferInfo*     buffer_info = buffer.original_buffer;
                assert(buffer_info != nullptr);

                std::string filename = GenerateDispatchTraceRaysBufferFilename(
                    false, qs_index, bcb_index, tr_index, desc_set, binding, array_index, stage, true);

                auto& buffer_json_entry         = before_command_output_buffer_entries[output_buffer_index++];
                buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
                buffer_json_entry["set"]        = desc_set;
                buffer_json_entry["binding"]    = binding;
                buffer_json_entry["arrayIndex"] = array_index;
                dump_json.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
            }
        }
    }

    const auto& mutable_resource_entry = tr_params->second.mutable_resources_clones;
    auto& outputs_json_entries_after   = dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;

    if (!mutable_resource_entry.images.empty())
    {
        uint32_t mutable_images_count = 0;
        for (const auto& image : mutable_resource_entry.images)
        {
            const uint32_t              desc_set    = image.desc_set;
            const uint32_t              binding     = image.desc_binding;
            const uint32_t              array_index = image.array_index;
            const VkShaderStageFlagBits stage       = image.stage;
            const VulkanImageInfo*      img_info    = image.original_image;
            assert(img_info != nullptr);

            auto& image_json_entry         = outputs_json_entries_after["images"][mutable_images_count++];
            image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
            image_json_entry["set"]        = desc_set;
            image_json_entry["binding"]    = binding;
            image_json_entry["arrayIndex"] = array_index;
            auto& image_json_entry_desc    = image_json_entry["image"];

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(img_info->format, aspects);

            size_t f = 0;
            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                    {
                        std::string filename = GenerateDispatchTraceRaysImageFilename(img_info->format,
                                                                                      mip,
                                                                                      layer,
                                                                                      aspect,
                                                                                      img_info->tiling,
                                                                                      img_info->type,
                                                                                      false,
                                                                                      qs_index,
                                                                                      bcb_index,
                                                                                      tr_index,
                                                                                      desc_set,
                                                                                      binding,
                                                                                      array_index,
                                                                                      stage,
                                                                                      false);

                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                    std::max(1u, img_info->extent.height >> mip),
                                                    img_info->extent.depth };

                        dump_json.InsertImageInfo(image_json_entry_desc[f++],
                                                  img_info->format,
                                                  img_info->type,
                                                  img_info->capture_id,
                                                  extent,
                                                  filename,
                                                  aspect,
                                                  ImageFailedScaling(filename),
                                                  mip,
                                                  layer);

                        if (!dump_all_image_subresources)
                        {
                            break;
                        }
                    }

                    if (!dump_all_image_subresources)
                    {
                        break;
                    }
                }
            }
        }
    }

    if (!mutable_resource_entry.buffers.empty())
    {
        uint32_t mutable_buffers_count = 0;
        for (const auto& buffer : mutable_resource_entry.buffers)
        {
            const uint32_t              desc_set    = buffer.desc_set;
            const uint32_t              binding     = buffer.desc_binding;
            const uint32_t              array_index = buffer.array_index;
            const VkShaderStageFlagBits stage       = buffer.stage;
            const VulkanBufferInfo*     buffer_info = buffer.original_buffer;
            assert(buffer_info != nullptr);

            std::string filename = GenerateDispatchTraceRaysBufferFilename(
                false, qs_index, bcb_index, tr_index, desc_set, binding, array_index, stage, false);

            auto& buffer_json_entry         = outputs_json_entries_after["buffers"][mutable_buffers_count++];
            buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
            buffer_json_entry["set"]        = desc_set;
            buffer_json_entry["binding"]    = binding;
            buffer_json_entry["arrayIndex"] = array_index;
            dump_json.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
        }
    }

    if (dump_immutable_resources)
    {
        for (const auto& shader_stage : tr_params->second.referenced_descriptors)
        {
            uint32_t          stage_entry_index = 0;
            const std::string shader_stage_name = ShaderStageToStr(shader_stage.first);
            for (const auto& desc_set : shader_stage.second)
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
                            for (size_t img = 0; img < desc_binding.second.image_info.size(); ++img)
                            {
                                if (desc_binding.second.image_info[img].image_view_info == nullptr)
                                {
                                    continue;
                                }

                                auto& entry = tr_entry["descriptors"][shader_stage_name][stage_entry_index++];

                                const VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(
                                    desc_binding.second.image_info[img].image_view_info->image_id);
                                assert(img_info);

                                entry["type"]       = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                                entry["set"]        = desc_set_index;
                                entry["binding"]    = desc_binding_index;
                                entry["arrayIndex"] = img;

                                std::vector<VkImageAspectFlagBits> aspects;
                                GetFormatAspects(img_info->format, aspects);

                                size_t f = 0;
                                for (auto aspect : aspects)
                                {
                                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                                    {
                                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                                        {
                                            std::string filename = GenerateImageDescriptorFilename(img_info->format,
                                                                                                   mip,
                                                                                                   layer,
                                                                                                   img_info->capture_id,
                                                                                                   aspect,
                                                                                                   img_info->tiling,
                                                                                                   img_info->type,
                                                                                                   qs_index,
                                                                                                   bcb_index);

                                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                                        std::max(1u, img_info->extent.height >> mip),
                                                                        img_info->extent.depth };

                                            auto& image_descriptor_json_entry = entry["descriptor"];

                                            dump_json.InsertImageInfo(image_descriptor_json_entry[f++],
                                                                      img_info->format,
                                                                      img_info->type,
                                                                      img_info->capture_id,
                                                                      extent,
                                                                      filename,
                                                                      aspect,
                                                                      ImageFailedScaling(filename),
                                                                      mip,
                                                                      layer);

                                            if (!dump_all_image_subresources)
                                            {
                                                break;
                                            }
                                        }

                                        if (!dump_all_image_subresources)
                                        {
                                            break;
                                        }
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
                                if (desc_binding.second.buffer_info[i].buffer_info != nullptr)
                                {
                                    auto& entry = tr_entry["descriptors"][shader_stage_name][stage_entry_index++];

                                    entry["type"]    = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                                    entry["set"]     = desc_set_index;
                                    entry["binding"] = desc_binding_index;
                                    entry["arrayIndex"] = i;

                                    const std::string filename = GenerateBufferDescriptorFilename(
                                        qs_index,
                                        bcb_index,
                                        desc_binding.second.buffer_info[i].buffer_info->capture_id);
                                    auto& buffer_descriptor_json_entry = entry["descriptor"];
                                    dump_json.InsertBufferInfo(buffer_descriptor_json_entry,
                                                               desc_binding.second.buffer_info[i].buffer_info,
                                                               filename);
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        {
                            auto& desc_json_entry = tr_entry["descriptors"][shader_stage_name][stage_entry_index++];

                            const std::string filename = GenerateInlineUniformBufferDescriptorFilename(
                                qs_index, bcb_index, desc_set_index, desc_binding_index);

                            desc_json_entry["type"] = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                            desc_json_entry["set"]  = desc_set_index;
                            desc_json_entry["binding"] = desc_binding_index;
                            desc_json_entry["size"]    = desc_binding.second.inline_uniform_block.size();
                            desc_json_entry["file"]    = filename;
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        case VK_DESCRIPTOR_TYPE_SAMPLER:
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
    }

    if (output_json_per_command)
    {
        dump_json.BlockEnd();
        dump_json.Close();
    }
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t index,
                                                                  uint32_t groupCountX,
                                                                  uint32_t groupCountY,
                                                                  uint32_t groupCountZ)
{
    auto new_entry = dispatch_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(
            DispatchTraceRaysDumpingContext::DispatchTypes::kDispatch, groupCountX, groupCountY, groupCountZ));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t                index,
                                                                  const VulkanBufferInfo* buffer_info,
                                                                  VkDeviceSize            offset)
{
    auto new_entry = dispatch_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DispatchTraceRaysDumpingContext::DispatchTypes::kDispatchIndirect, buffer_info, offset));
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
    auto new_entry = trace_rays_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRays, width, height, depth));
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
    auto new_entry = trace_rays_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect,
                              indirectDeviceAddress));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirect2Parameters(uint64_t        index,
                                                                            VkDeviceAddress indirectDeviceAddress)
{
    auto new_entry = trace_rays_params.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(index),
        std::forward_as_tuple(DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect2,
                              indirectDeviceAddress));
    assert(new_entry.second);
}

void DispatchTraceRaysDumpingContext::EndCommandBuffer()
{
    reached_end_command_buffer = true;
    device_table->EndCommandBuffer(DR_command_buffer);
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
