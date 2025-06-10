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
    original_command_buffer_info_(nullptr),
    DR_command_buffer_(VK_NULL_HANDLE), dispatch_indices_(dispatch_indices), trace_rays_indices_(trace_rays_indices),
    dump_resources_before_(options.dump_resources_before), delegate_(delegate),
    dump_immutable_resources_(options.dump_resources_dump_immutable_resources), bound_pipeline_compute_(nullptr),
    bound_pipeline_trace_rays_(nullptr), command_buffer_level_(DumpResourcesCommandBufferLevel::kPrimary),
    device_table_(nullptr), parent_device_(VK_NULL_HANDLE), instance_table_(nullptr),
    object_info_table_(object_info_table), replay_device_phys_mem_props_(nullptr), current_dispatch_index_(0),
    current_trace_rays_index_(0), reached_end_command_buffer_(false)
{}

DispatchTraceRaysDumpingContext::~DispatchTraceRaysDumpingContext()
{
    Release();
}

void DispatchTraceRaysDumpingContext::Release()
{
    if (original_command_buffer_info_)
    {
        if (DR_command_buffer_ != VK_NULL_HANDLE)
        {
            const VulkanDeviceInfo* device_info =
                object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
            if (device_info != nullptr)
            {
                DestroyMutableResourcesClones();
                ReleaseIndirectParams();

                VkDevice device = device_info->handle;

                assert(device_table_);

                const VulkanCommandPoolInfo* pool_info =
                    object_info_table_.GetVkCommandPoolInfo(original_command_buffer_info_->pool_id);
                assert(pool_info);

                device_table_->FreeCommandBuffers(device, pool_info->handle, 1, &DR_command_buffer_);
                DR_command_buffer_          = VK_NULL_HANDLE;
                reached_end_command_buffer_ = false;
            }
        }

        original_command_buffer_info_ = nullptr;
    }

    dispatch_indices_.clear();
    trace_rays_indices_.clear();
    bound_descriptor_sets_compute_.clear();
    bound_descriptor_sets_ray_tracing_.clear();
    dispatch_params_.clear();
    trace_rays_params_.clear();
}

VkResult DispatchTraceRaysDumpingContext::CloneCommandBuffer(VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                                             const graphics::VulkanDeviceTable*   dev_table,
                                                             const graphics::VulkanInstanceTable* inst_table,
                                                             const VkCommandBufferBeginInfo*      begin_info)
{
    GFXRECON_ASSERT(orig_cmd_buf_info != nullptr);
    GFXRECON_ASSERT(dev_table != nullptr);
    GFXRECON_ASSERT(inst_table != nullptr);
    GFXRECON_ASSERT(begin_info != nullptr);

    const VulkanCommandPoolInfo* cb_pool_info = object_info_table_.GetVkCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary
                                              ? VK_COMMAND_BUFFER_LEVEL_PRIMARY
                                              : VK_COMMAND_BUFFER_LEVEL_SECONDARY,
                                          1 };

    const VulkanDeviceInfo* dev_info = object_info_table_.GetVkDeviceInfo(orig_cmd_buf_info->parent_id);

    VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &DR_command_buffer_);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    dev_table->BeginCommandBuffer(DR_command_buffer_, begin_info);

    assert(original_command_buffer_info_ == nullptr);
    original_command_buffer_info_ = orig_cmd_buf_info;

    assert(device_table_ == nullptr);
    device_table_ = dev_table;
    assert(instance_table_ == nullptr);
    instance_table_ = inst_table;

    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(parent_device_ == VK_NULL_HANDLE);
    parent_device_ = device_info->handle;

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties);
    replay_device_phys_mem_props_ = &phys_dev_info->replay_device_info->memory_properties.value();

    return VK_SUCCESS;
}

void DispatchTraceRaysDumpingContext::FinalizeCommandBuffer(bool is_dispatch)
{
    if (is_dispatch)
    {
        ++current_dispatch_index_;
    }
    else
    {
        ++current_trace_rays_index_;
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

        VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo& bound_descriptor_sets =
            pipeline_bind_point == VK_PIPELINE_BIND_POINT_COMPUTE ? bound_descriptor_sets_compute_[set_index]
                                                                  : bound_descriptor_sets_ray_tracing_[set_index];

        bound_descriptor_sets = descriptor_sets_infos[i]->descriptors;

        if (dynamicOffsetCount && pDynamicOffsets != nullptr)
        {
            for (const auto& binding : descriptor_sets_infos[i]->descriptors)
            {
                const uint32_t bindind_index = binding.first;

                if (binding.second.desc_type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                    binding.second.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
                {
                    for (size_t ai = 0; ai < bound_descriptor_sets[bindind_index].buffer_info.size(); ++ai)
                    {
                        bound_descriptor_sets[bindind_index].buffer_info[ai].offset +=
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
    if (!IsInsideRange(dispatch_indices_, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before_ ? current_dispatch_index_ / 2 : current_dispatch_index_;
         i < dispatch_indices_.size();
         ++i)
    {
        if (index == dispatch_indices_[i])
        {
            return true;
        }
        else if (index > dispatch_indices_[i])
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
    if (!IsInsideRange(trace_rays_indices_, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before_ ? current_trace_rays_index_ / 2 : current_trace_rays_index_;
         i < trace_rays_indices_.size();
         ++i)
    {
        if (index == trace_rays_indices_[i])
        {
            return true;
        }
        else if (index > trace_rays_indices_[i])
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

    assert(device_table_ != nullptr);
    device_table_->CmdPipelineBarrier(DR_command_buffer_,
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
    device_table_->CmdCopyBuffer(DR_command_buffer_, src_buffer_info->handle, dst_buffer, 1, &region);
}

void DispatchTraceRaysDumpingContext::CopyImageResource(const VulkanImageInfo* src_image_info, VkImage dst_image)
{
    assert(src_image_info != nullptr);
    assert(dst_image != VK_NULL_HANDLE);

    VkImageLayout old_layout;
    assert(original_command_buffer_info_ != nullptr);
    const auto img_layout_entry = original_command_buffer_info_->image_layout_barriers.find(src_image_info->capture_id);
    if (img_layout_entry != original_command_buffer_info_->image_layout_barriers.end())
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

    assert(device_table_ != nullptr);
    device_table_->CmdPipelineBarrier(DR_command_buffer_,
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

    device_table_->CmdPipelineBarrier(DR_command_buffer_,
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

    device_table_->CmdCopyImage(DR_command_buffer_,
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

    device_table_->CmdPipelineBarrier(DR_command_buffer_,
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
    auto entry = dispatch_params_.find(index);
    GFXRECON_ASSERT(entry != dispatch_params_.end());
    GFXRECON_ASSERT(entry->second);

    DispatchParams& params = *entry->second.get();
    return CloneMutableResources(params.referenced_descriptors,
                                 cloning_before_cmd ? params.mutable_resources_clones_before
                                                    : params.mutable_resources_clones);
}

VkResult DispatchTraceRaysDumpingContext::CloneTraceRaysMutableResources(uint64_t index, bool cloning_before_cmd)
{
    auto entry = trace_rays_params_.find(index);
    GFXRECON_ASSERT(entry != trace_rays_params_.end());
    GFXRECON_ASSERT(entry->second);

    TraceRaysParams& params = *entry->second;
    return CloneMutableResources(params.referenced_descriptors,
                                 cloning_before_cmd ? params.mutable_resources_clones_before
                                                    : params.mutable_resources_clones);
}

static void SnapshotBoundDescriptorsDispatch(DispatchTraceRaysDumpingContext::DispatchParams& disp_params,
                                             const VulkanPipelineInfo*                        bound_pipeline_compute,
                                             const BoundDescriptorSets& compute_bound_descriptor_sets)
{
    if (disp_params.updated_referenced_descriptors || compute_bound_descriptor_sets.empty())
    {
        return;
    }

    // Copy descriptors that are compatible with the current pipeline layout
    if (bound_pipeline_compute != nullptr)
    {
        for (const auto& [desc_set_index, set_info] : compute_bound_descriptor_sets)
        {
            // Check against pipeline layout
            if (bound_pipeline_compute->desc_set_layouts.size() <= desc_set_index)
            {
                continue;
            }

            for (const auto& [desc_binding_index, binding_info] : set_info)
            {
                // Check against pipeline layout
                const auto layout_entry =
                    bound_pipeline_compute->desc_set_layouts[desc_set_index].find(desc_binding_index);
                if (layout_entry == bound_pipeline_compute->desc_set_layouts[desc_set_index].end())
                {
                    continue;
                }

                disp_params.referenced_descriptors[desc_set_index][desc_binding_index].desc_type =
                    binding_info.desc_type;
                disp_params.referenced_descriptors[desc_set_index][desc_binding_index].stage_flags =
                    binding_info.stage_flags;

                switch (binding_info.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& [array_idx, img_info] : binding_info.image_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            disp_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .image_info[array_idx] = img_info;
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
                        for (const auto& [array_idx, buf_info] : binding_info.buffer_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            disp_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .buffer_info[array_idx] = buf_info;
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        disp_params.referenced_descriptors[desc_set_index][desc_binding_index].inline_uniform_block =
                            binding_info.inline_uniform_block;
                    }
                    break;

                    default:
                        break;
                }
            }
        }
    }

    disp_params.updated_referenced_descriptors = true;
}

static void SnapshotBoundDescriptorsTraceRays(DispatchTraceRaysDumpingContext::TraceRaysParams& tr_params,
                                              const VulkanPipelineInfo* bound_pipeline_trace_rays,
                                              const BoundDescriptorSets trace_rays_bound_descriptor_sets)
{
    if (tr_params.updated_referenced_descriptors || trace_rays_bound_descriptor_sets.empty())
    {
        return;
    }

    // Copy descriptors that are compatible with the current pipeline layout
    if (bound_pipeline_trace_rays != nullptr)
    {
        for (const auto& [desc_set_index, set_info] : trace_rays_bound_descriptor_sets)
        {
            // Check against pipeline layout
            if (bound_pipeline_trace_rays->desc_set_layouts.size() <= desc_set_index)
            {
                continue;
            }

            for (const auto& [desc_binding_index, binding_info] : set_info)
            {
                // Check against pipeline layout
                const auto layout_entry =
                    bound_pipeline_trace_rays->desc_set_layouts[desc_set_index].find(desc_binding_index);
                if (layout_entry == bound_pipeline_trace_rays->desc_set_layouts[desc_set_index].end())
                {
                    continue;
                }

                tr_params.referenced_descriptors[desc_set_index][desc_binding_index].desc_type = binding_info.desc_type;
                tr_params.referenced_descriptors[desc_set_index][desc_binding_index].stage_flags =
                    binding_info.stage_flags;

                switch (binding_info.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& [array_idx, img_info] : binding_info.image_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            tr_params.referenced_descriptors[desc_set_index][desc_binding_index].image_info[array_idx] =
                                img_info;
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
                        for (const auto& [array_idx, buf_info] : binding_info.buffer_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            tr_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .buffer_info[array_idx] = buf_info;
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        tr_params.referenced_descriptors[desc_set_index][desc_binding_index].inline_uniform_block =
                            binding_info.inline_uniform_block;
                    }
                    break;

                    default:
                        break;
                }
            }
        }
    }

    tr_params.updated_referenced_descriptors = true;
}

void DispatchTraceRaysDumpingContext::SnapshotDispatchState(DispatchParams& disp_params)
{
    SnapshotBoundDescriptorsDispatch(disp_params, bound_pipeline_compute_, bound_descriptor_sets_compute_);

    if (IsDispatchIndirect(disp_params.type))
    {
        CopyDispatchIndirectParameters(disp_params);
    }
}

void DispatchTraceRaysDumpingContext::SnapshotTraceRaysState(TraceRaysParams& tr_params)
{
    SnapshotBoundDescriptorsTraceRays(tr_params, bound_pipeline_trace_rays_, bound_descriptor_sets_ray_tracing_);

    if (IsTraceRaysIndirect(tr_params.type))
    {
        CopyTraceRaysIndirectParameters(tr_params);
    }
}

VkResult DispatchTraceRaysDumpingContext::CloneMutableResources(const BoundDescriptorSets&     referenced_descriptors,
                                                                MutableResourcesBackupContext& resource_backup_context)
{
    assert(IsRecording());

    for (const auto& [desc_set_index, desc_set_info] : referenced_descriptors)
    {
        for (const auto& [binding_index, desc_info] : desc_set_info)
        {
            const VkDescriptorType   desc_type   = desc_info.desc_type;
            const VkShaderStageFlags stage_flags = desc_info.stage_flags;
            switch (desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    for (const auto& [array_index, img_desc] : desc_info.image_info)
                    {
                        if (img_desc.image_view_info == nullptr)
                        {
                            continue;
                        }

                        const VulkanImageInfo* img_info =
                            object_info_table_.GetVkImageInfo(img_desc.image_view_info->image_id);
                        assert(img_info);

                        auto& new_entry          = resource_backup_context.images.emplace_back();
                        new_entry.original_image = img_info;
                        new_entry.stages         = stage_flags;
                        new_entry.desc_type      = desc_type;
                        new_entry.desc_set       = desc_set_index;
                        new_entry.desc_binding   = binding_index;
                        new_entry.array_index    = array_index;

                        VkResult res = CloneImage(object_info_table_,
                                                  device_table_,
                                                  replay_device_phys_mem_props_,
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
                    for (const auto& [array_index, buf_desc] : desc_info.buffer_info)
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
                        new_entry.array_index     = array_index;
                        new_entry.cloned_size =
                            buf_desc.range == VK_WHOLE_SIZE ? (buf_info->size - buf_desc.offset) : buf_desc.range;

                        VkResult res = CloneBuffer(object_info_table_,
                                                   device_table_,
                                                   replay_device_phys_mem_props_,
                                                   buf_info,
                                                   &new_entry.buffer,
                                                   &new_entry.buffer_memory,
                                                   new_entry.cloned_size);

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
    for (auto& params : dispatch_params_)
    {
        GFXRECON_ASSERT(params.second);

        DispatchParams& dis_params = *params.second;
        for (size_t i = 0; i < dis_params.mutable_resources_clones.images.size(); ++i)
        {
            assert(dis_params.mutable_resources_clones.images[i].original_image != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(
                dis_params.mutable_resources_clones.images[i].original_image->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table_->FreeMemory(device, dis_params.mutable_resources_clones.images[i].image_memory, nullptr);
            device_table_->DestroyImage(device, dis_params.mutable_resources_clones.images[i].image, nullptr);

            if (dump_resources_before_)
            {
                device_table_->FreeMemory(
                    device, dis_params.mutable_resources_clones_before.images[i].image_memory, nullptr);
                device_table_->DestroyImage(
                    device, dis_params.mutable_resources_clones_before.images[i].image, nullptr);
            }
        }

        for (size_t i = 0; i < dis_params.mutable_resources_clones.buffers.size(); ++i)
        {
            assert(dis_params.mutable_resources_clones.buffers[i].original_buffer != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(
                dis_params.mutable_resources_clones.buffers[i].original_buffer->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table_->FreeMemory(device, dis_params.mutable_resources_clones.buffers[i].buffer_memory, nullptr);
            device_table_->DestroyBuffer(device, dis_params.mutable_resources_clones.buffers[i].buffer, nullptr);
            if (dump_resources_before_)
            {
                device_table_->FreeMemory(
                    device, dis_params.mutable_resources_clones_before.buffers[i].buffer_memory, nullptr);
                device_table_->DestroyBuffer(
                    device, dis_params.mutable_resources_clones_before.buffers[i].buffer, nullptr);
            }
        }
    }

    for (auto& params : trace_rays_params_)
    {
        GFXRECON_ASSERT(params.second);

        TraceRaysParams& tr_params = *params.second;
        for (size_t i = 0; i < tr_params.mutable_resources_clones.images.size(); ++i)
        {
            assert(tr_params.mutable_resources_clones.images[i].original_image != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(
                tr_params.mutable_resources_clones.images[i].original_image->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table_->FreeMemory(device, tr_params.mutable_resources_clones.images[i].image_memory, nullptr);
            device_table_->DestroyImage(device, tr_params.mutable_resources_clones.images[i].image, nullptr);

            if (dump_resources_before_)
            {
                device_table_->FreeMemory(
                    device, tr_params.mutable_resources_clones_before.images[i].image_memory, nullptr);
                device_table_->DestroyImage(device, tr_params.mutable_resources_clones_before.images[i].image, nullptr);
            }
        }

        for (size_t i = 0; i < tr_params.mutable_resources_clones.buffers.size(); ++i)
        {
            assert(tr_params.mutable_resources_clones.buffers[i].original_buffer != nullptr);
            const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(
                tr_params.mutable_resources_clones.buffers[i].original_buffer->parent_id);
            assert(device_info != nullptr);
            VkDevice device = device_info->handle;

            device_table_->FreeMemory(device, tr_params.mutable_resources_clones.buffers[i].buffer_memory, nullptr);
            device_table_->DestroyBuffer(device, tr_params.mutable_resources_clones.buffers[i].buffer, nullptr);
            if (dump_resources_before_)
            {
                device_table_->FreeMemory(
                    device, tr_params.mutable_resources_clones_before.buffers[i].buffer_memory, nullptr);
                device_table_->DestroyBuffer(
                    device, tr_params.mutable_resources_clones_before.buffers[i].buffer, nullptr);
            }
        }
    }
}

void DispatchTraceRaysDumpingContext::ReleaseIndirectParams()
{
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    for (auto& params : dispatch_params_)
    {
        GFXRECON_ASSERT(params.second);

        DispatchParams& dis_params = *params.second;
        if (dis_params.type != kDispatchIndirect)
        {
            continue;
        }

        if (dis_params.dispatch_params_union.dispatch_indirect.new_params_buffer != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(
                device_info->handle, dis_params.dispatch_params_union.dispatch_indirect.new_params_buffer, nullptr);
            dis_params.dispatch_params_union.dispatch_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (dis_params.dispatch_params_union.dispatch_indirect.new_params_memory != VK_NULL_HANDLE)
        {
            device_table_->FreeMemory(
                device_info->handle, dis_params.dispatch_params_union.dispatch_indirect.new_params_memory, nullptr);
            dis_params.dispatch_params_union.dispatch_indirect.new_params_memory = VK_NULL_HANDLE;
        }
    }

    for (auto& params : trace_rays_params_)
    {
        GFXRECON_ASSERT(params.second);

        TraceRaysParams& tr_params = *params.second;
        if (tr_params.type != kTraceRaysIndirect)
        {
            continue;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(
                device_info->handle, tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer, nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory != VK_NULL_HANDLE)
        {
            device_table_->FreeMemory(device_info->handle,
                                      tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory,
                                      nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(device_info->handle,
                                         tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address,
                                         nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory != VK_NULL_HANDLE)
        {
            device_table_->FreeMemory(
                device_info->handle,
                tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory,
                nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory = VK_NULL_HANDLE;
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
    si.pCommandBuffers      = &DR_command_buffer_;
    si.signalSemaphoreCount = submit_info.signalSemaphoreCount;
    si.pSignalSemaphores    = submit_info.pSignalSemaphores;

    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    VkResult res = VK_SUCCESS;

    const VkFenceCreateInfo ci               = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkFence                 submission_fence = VK_NULL_HANDLE;
    if (fence == VK_NULL_HANDLE)
    {
        res = device_table_->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
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

    res = device_table_->QueueSubmit(queue, 1, &si, submission_fence);
    if (res != VK_SUCCESS)
    {
        device_table_->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Wait
    res = device_table_->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
    if (res != VK_SUCCESS)
    {
        device_table_->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    if (fence == VK_NULL_HANDLE)
    {
        device_table_->DestroyFence(device_info->handle, submission_fence, nullptr);
    }

    res = FetchIndirectParams();
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Fetching params for indirect calls failed (%s).", util::ToString<VkResult>(res).c_str())
        return res;
    }

    for (size_t i = 0; i < dispatch_indices_.size(); ++i)
    {
        const uint64_t disp_index = dispatch_indices_[i];

        GFXRECON_LOG_INFO("Dumping mutable resources for dispatch index %" PRIu64, disp_index);

        res = DumpMutableResources(bcb_index, qs_index, disp_index, true);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping compute mutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        if (dump_immutable_resources_)
        {
            res = DumpDescriptors(qs_index, bcb_index, disp_index, true);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        VulkanDumpDrawCallInfo draw_call_info{};
        draw_call_info.type                         = DumpResourceType::kDispatchInfo;
        draw_call_info.instance_table               = instance_table_;
        draw_call_info.device_table                 = device_table_;
        draw_call_info.object_info_table            = &object_info_table_;
        draw_call_info.device_info                  = device_info;
        draw_call_info.original_command_buffer_info = original_command_buffer_info_;
        draw_call_info.bcb_index                    = bcb_index;
        draw_call_info.qs_index                     = qs_index;
        draw_call_info.cmd_index                    = disp_index;

        const auto& dispatch_param_entry = dispatch_params_.find(disp_index);
        GFXRECON_ASSERT(dispatch_param_entry != dispatch_params_.end());
        draw_call_info.disp_param = dispatch_param_entry->second.get();

        delegate_.DumpDrawCallInfo(draw_call_info, instance_table_);
    }

    for (size_t i = 0; i < trace_rays_indices_.size(); ++i)
    {
        const uint64_t tr_index = trace_rays_indices_[i];

        GFXRECON_LOG_INFO("Dumping mutable resources for trace rays index %" PRIu64, tr_index);

        res = DumpMutableResources(bcb_index, qs_index, tr_index, false);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping ray tracing mutable resources failed. (%s)",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }

        if (dump_immutable_resources_)
        {
            res = DumpDescriptors(qs_index, bcb_index, tr_index, false);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        VulkanDumpDrawCallInfo draw_call_info{};
        draw_call_info.type                         = DumpResourceType::kTraceRaysIndex;
        draw_call_info.instance_table               = instance_table_;
        draw_call_info.device_table                 = device_table_;
        draw_call_info.object_info_table            = &object_info_table_;
        draw_call_info.device_info                  = device_info;
        draw_call_info.original_command_buffer_info = original_command_buffer_info_;
        draw_call_info.bcb_index                    = bcb_index;
        draw_call_info.qs_index                     = qs_index;
        draw_call_info.cmd_index                    = tr_index;

        const auto& trace_rays_param_entry = trace_rays_params_.find(tr_index);
        GFXRECON_ASSERT(trace_rays_param_entry != trace_rays_params_.end());
        draw_call_info.tr_param = trace_rays_param_entry->second.get();

        delegate_.DumpDrawCallInfo(draw_call_info, instance_table_);
    }

    // Clean up references to dumped descriptors in case this command buffer is submitted again
    dispatch_dumped_descriptors_.buffer_descriptors.clear();
    dispatch_dumped_descriptors_.image_descriptors.clear();
    dispatch_dumped_descriptors_.inline_uniform_blocks.clear();

    trace_rays_dumped_descriptors_.buffer_descriptors.clear();
    trace_rays_dumped_descriptors_.image_descriptors.clear();
    trace_rays_dumped_descriptors_.inline_uniform_blocks.clear();

    assert(res == VK_SUCCESS);
    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::DumpMutableResources(uint64_t bcb_index,
                                                               uint64_t qs_index,
                                                               uint64_t cmd_index,
                                                               bool     is_dispatch)
{
    const auto dis_params = dispatch_params_.find(cmd_index);
    const auto tr_params  = trace_rays_params_.find(cmd_index);

    if (is_dispatch && (dis_params == dispatch_params_.end()))
    {
        assert(0);
        return VK_SUCCESS;
    }
    else if (!is_dispatch && (tr_params == trace_rays_params_.end()))
    {
        assert(0);
        return VK_SUCCESS;
    }

    const MutableResourcesBackupContext& mutable_resources_clones =
        is_dispatch ? dis_params->second->mutable_resources_clones : tr_params->second->mutable_resources_clones;

    const MutableResourcesBackupContext& mutable_resources_clones_before =
        is_dispatch ? dis_params->second->mutable_resources_clones_before
                    : tr_params->second->mutable_resources_clones_before;

    if (mutable_resources_clones.images.empty() && mutable_resources_clones.buffers.empty())
    {
        assert(mutable_resources_clones_before.images.empty() && mutable_resources_clones_before.buffers.empty());
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table_,
                                                *instance_table_,
                                                *phys_dev_info->replay_device_info->memory_properties);
    VulkanDumpResourceInfo        res_info_base{};
    res_info_base.device_info                  = device_info;
    res_info_base.device_table                 = device_table_;
    res_info_base.instance_table               = instance_table_;
    res_info_base.object_info_table            = &object_info_table_;
    res_info_base.original_command_buffer_info = original_command_buffer_info_;
    res_info_base.cmd_index                    = cmd_index;
    res_info_base.qs_index                     = qs_index;
    res_info_base.bcb_index                    = bcb_index;

    if (dump_resources_before_)
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
                                                                mutable_resources_clones_before.buffers[i].cloned_size,
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
    return !reached_end_command_buffer_;
}

VkResult DispatchTraceRaysDumpingContext::DumpDescriptors(uint64_t qs_index,
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

    DumpedDescriptors& dumped_descriptors = is_dispatch ? dispatch_dumped_descriptors_ : trace_rays_dumped_descriptors_;

    if (is_dispatch)
    {
        const auto disp_params_entry = dispatch_params_.find(cmd_index);
        GFXRECON_ASSERT(disp_params_entry != dispatch_params_.end());

        const DispatchParams* disp_params = disp_params_entry->second.get();
        for (const auto& [desc_set_index, desc_set_info] : disp_params->referenced_descriptors)
        {
            for (const auto& [desc_binding_index, desc_binding_info] : desc_set_info)
            {
                switch (desc_binding_info.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& img_desc : desc_binding_info.image_info)
                        {
                            if (img_desc.second.image_view_info != nullptr)
                            {
                                const VulkanImageInfo* img_info =
                                    object_info_table_.GetVkImageInfo(img_desc.second.image_view_info->image_id);
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
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        for (const auto& buf_desc : desc_binding_info.buffer_info)
                        {
                            const VulkanBufferInfo* buffer_info = buf_desc.second.buffer_info;
                            if (buffer_info != nullptr && dumped_descriptors.buffer_descriptors.find(buffer_info) ==
                                                              dumped_descriptors.buffer_descriptors.end())
                            {
                                buffer_descriptors.emplace(std::piecewise_construct,
                                                           std::forward_as_tuple(buffer_info),
                                                           std::forward_as_tuple(buffer_descriptor_info{
                                                               buf_desc.second.offset, buf_desc.second.range }));
                                dumped_descriptors.buffer_descriptors.insert(buffer_info);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        if (dumped_descriptors.inline_uniform_blocks.find(&(desc_binding_info.inline_uniform_block)) ==
                            dumped_descriptors.inline_uniform_blocks.end())
                        {
                            inline_uniform_blocks[&(desc_binding_info.inline_uniform_block)] = {
                                desc_set_index, desc_binding_index, &(desc_binding_info.inline_uniform_block)
                            };
                            dumped_descriptors.inline_uniform_blocks.insert(&(desc_binding_info.inline_uniform_block));
                        }
                    }
                    break;

                    default:
                        GFXRECON_LOG_WARNING_ONCE(
                            "%s(): Descriptor type (%s) not handled",
                            __func__,
                            util::ToString<VkDescriptorType>(desc_binding_info.desc_type).c_str());
                        break;
                }
            }
        }
    }
    else
    {
        const auto tr_params_entry = trace_rays_params_.find(cmd_index);
        GFXRECON_ASSERT(tr_params_entry != trace_rays_params_.end());

        const TraceRaysParams* tr_params = tr_params_entry->second.get();
        for (const auto& [desc_set_index, desc_set_info] : tr_params->referenced_descriptors)
        {
            for (const auto& [desc_binding_index, desc_binding_info] : desc_set_info)
            {
                switch (desc_binding_info.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& img_desc : desc_binding_info.image_info)
                        {
                            if (img_desc.second.image_view_info != nullptr)
                            {
                                const VulkanImageInfo* img_info =
                                    object_info_table_.GetVkImageInfo(img_desc.second.image_view_info->image_id);
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
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        for (const auto& buf_desc : desc_binding_info.buffer_info)
                        {
                            const VulkanBufferInfo* buffer_info = buf_desc.second.buffer_info;
                            if (buffer_info != nullptr && dumped_descriptors.buffer_descriptors.find(buffer_info) ==
                                                              dumped_descriptors.buffer_descriptors.end())
                            {
                                buffer_descriptors.emplace(std::piecewise_construct,
                                                           std::forward_as_tuple(buf_desc.second.buffer_info),
                                                           std::forward_as_tuple(buffer_descriptor_info{
                                                               buf_desc.second.offset, buf_desc.second.range }));
                                dumped_descriptors.buffer_descriptors.insert(buffer_info);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        if (dumped_descriptors.inline_uniform_blocks.find(&(desc_binding_info.inline_uniform_block)) ==
                            dumped_descriptors.inline_uniform_blocks.end())
                        {
                            inline_uniform_blocks[&(desc_binding_info.inline_uniform_block)] = {
                                desc_set_index, desc_binding_index, &(desc_binding_info.inline_uniform_block)
                            };
                            dumped_descriptors.inline_uniform_blocks.insert(&(desc_binding_info.inline_uniform_block));
                        }
                    }
                    break;

                    default:
                        GFXRECON_LOG_WARNING_ONCE(
                            "%s(): Descriptor type (%s) not handled",
                            __func__,
                            util::ToString<VkDescriptorType>(desc_binding_info.desc_type).c_str());
                        break;
                }
            }
        }
    }

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    VulkanDumpResourceInfo res_info_base{};
    res_info_base.device_info                  = device_info;
    res_info_base.device_table                 = device_table_;
    res_info_base.instance_table               = instance_table_;
    res_info_base.object_info_table            = &object_info_table_;
    res_info_base.original_command_buffer_info = original_command_buffer_info_;
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

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table_,
                                                *instance_table_,
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

VkResult DispatchTraceRaysDumpingContext::CopyDispatchIndirectParameters(DispatchParams& disp_params)
{
    GFXRECON_ASSERT(IsDispatchIndirect(disp_params.type));
    GFXRECON_ASSERT(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info != nullptr);
    GFXRECON_ASSERT(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->handle != VK_NULL_HANDLE);

    const VkDeviceSize size = sizeof(VkDispatchIndirectCommand);
    VkResult           res  = CloneBuffer(object_info_table_,
                               device_table_,
                               replay_device_phys_mem_props_,
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
        VkCommandBuffer    cmd_buf = DR_command_buffer_;
        device_table_->CmdCopyBuffer(cmd_buf,
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

        device_table_->CmdPipelineBarrier(cmd_buf,
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

VkResult DispatchTraceRaysDumpingContext::CopyTraceRaysIndirectParameters(TraceRaysParams& params)
{
    GFXRECON_ASSERT(IsTraceRaysIndirect(params.type));

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
                                  device_table_,
                                  parent_device_,
                                  reinterpret_cast<VkBaseInStructure*>(&bdaci),
                                  replay_device_phys_mem_props_,
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
                         device_table_,
                         parent_device_,
                         reinterpret_cast<VkBaseInStructure*>(&bdaci),
                         replay_device_phys_mem_props_,
                         &new_params_buffer,
                         &new_params_buffer_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): Failed to create buffer (%s)", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Copy the parameters from one buffer into the other
    const VkBufferCopy region = { 0, 0, size };
    assert(device_table_);
    device_table_->CmdCopyBuffer(DR_command_buffer_, buffer_on_device_address, new_params_buffer, 1, &region);

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

    device_table_->CmdPipelineBarrier(DR_command_buffer_,
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
        TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect& itr_params =
            params.trace_rays_params_union.trace_rays_indirect;

        itr_params.buffer_on_device_address        = buffer_on_device_address;
        itr_params.buffer_on_device_address_memory = buffer_on_device_address_memory;

        itr_params.new_params_buffer        = new_params_buffer;
        itr_params.new_params_buffer_memory = new_params_buffer_memory;
    }
    else
    {
        TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect2& itr_params =
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
    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                *device_table_,
                                                *instance_table_,
                                                *phys_dev_info->replay_device_info->memory_properties);

    for (auto& params : dispatch_params_)
    {
        GFXRECON_ASSERT(params.second);

        DispatchParams& dis_params = *params.second;
        if (dis_params.type != kDispatchIndirect)
        {
            continue;
        }

        DispatchParams::DispatchParamsUnion::DispatchIndirect& i_params =
            dis_params.dispatch_params_union.dispatch_indirect;

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

    for (auto& params : trace_rays_params_)
    {
        GFXRECON_ASSERT(params.second);

        TraceRaysParams& tr_params = *params.second;
        if (tr_params.type != kTraceRaysIndirect && tr_params.type != kTraceRaysIndirect2)
        {
            continue;
        }

        const VkBuffer new_params_buffer =
            tr_params.type == kTraceRaysIndirect
                ? tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer
                : tr_params.trace_rays_params_union.trace_rays_indirect2.new_params_buffer;
        const VkDeviceSize   size = tr_params.type == kTraceRaysIndirect ? sizeof(VkTraceRaysIndirectCommandKHR)
                                                                         : sizeof(VkTraceRaysIndirectCommand2KHR);
        std::vector<uint8_t> data;
        VkResult res = resource_util.ReadFromBufferResource(new_params_buffer, size, 0, VK_QUEUE_FAMILY_IGNORED, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(data.size() == size);
        if (tr_params.type == kTraceRaysIndirect)
        {
            TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect& i_params =
                tr_params.trace_rays_params_union.trace_rays_indirect;
            util::platform::MemoryCopy(&i_params.trace_rays_params, size, data.data(), size);
        }
        else
        {
            TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect2& i_params =
                tr_params.trace_rays_params_union.trace_rays_indirect2;
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
    auto new_entry = dispatch_params_.insert(
        { index, std::make_unique<DispatchParams>(DispatchTypes::kDispatch, groupCountX, groupCountY, groupCountZ) });
    assert(new_entry.second);

    SnapshotDispatchState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t                index,
                                                                  const VulkanBufferInfo* buffer_info,
                                                                  VkDeviceSize            offset)
{
    auto new_entry = dispatch_params_.insert(
        { index, std::make_unique<DispatchParams>(DispatchTypes::kDispatchIndirect, buffer_info, offset) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotDispatchState(*new_entry.first->second);
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
    auto new_entry = trace_rays_params_.insert(
        { index, std::make_unique<TraceRaysParams>(TraceRaysTypes::kTraceRays, width, height, depth) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotTraceRaysState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirectParameters(
    uint64_t                               index,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    auto new_entry = trace_rays_params_.insert(
        { index, std::make_unique<TraceRaysParams>(TraceRaysTypes::kTraceRaysIndirect, indirectDeviceAddress) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotTraceRaysState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirect2Parameters(uint64_t        index,
                                                                            VkDeviceAddress indirectDeviceAddress)
{
    auto new_entry = trace_rays_params_.insert(
        { index, std::make_unique<TraceRaysParams>(TraceRaysTypes::kTraceRaysIndirect2, indirectDeviceAddress) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotTraceRaysState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::EndCommandBuffer()
{
    reached_end_command_buffer_ = true;
    device_table_->EndCommandBuffer(DR_command_buffer_);
}

void DispatchTraceRaysDumpingContext::AssignSecondary(uint64_t                         execute_commands_index,
                                                      DispatchTraceRaysDumpingContext* secondary_context)
{
    GFXRECON_ASSERT(secondary_context);

    secondaries_[execute_commands_index].push_back(secondary_context);
    secondary_context->command_buffer_level_ = DumpResourcesCommandBufferLevel::kSecondary;
}

bool DispatchTraceRaysDumpingContext::ShouldHandleExecuteCommands(uint64_t index) const
{
    return secondaries_.find(index) != secondaries_.end();
}

void DispatchTraceRaysDumpingContext::UpdateSecondaries()
{
    // The purpose of this function is to transfer rendering context from a primary to its secondaries.
    // This function must be called only for primary command buffer contexes, even if a secondary has secondaries.
    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary);

    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            secondary_context->SecondaryUpdateContextFromPrimary(bound_descriptor_sets_compute_,
                                                                 bound_descriptor_sets_ray_tracing_);
        }
    }

    // Move secondary dispatch and trace rays parameters to primary.
    // When DumpDispatchTraceRays is called it's better to have all parameters available in the primary which is
    // submitted.
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            DispatchParameters& secondary_disp_params = secondary_context->GetDispatchParameters();
            for (auto& secondary_disp_param : secondary_disp_params)
            {
                const auto new_entry = dispatch_params_.insert(
                    std::make_pair(secondary_disp_param.first, std::move(secondary_disp_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_disp_params.clear();

            TraceRaysParameters& secondary_tr_params = secondary_context->GetTraceRaysParameters();
            for (auto& secondary_tr_param : secondary_tr_params)
            {
                const auto new_entry = trace_rays_params_.insert(
                    std::make_pair(secondary_tr_param.first, std::move(secondary_tr_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_tr_params.clear();
        }
    }
}

void DispatchTraceRaysDumpingContext::SecondaryUpdateContextFromPrimary(
    const BoundDescriptorSets& dispatch_descriptor_sets, const BoundDescriptorSets& tr_descriptor_sets)
{
    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kSecondary);

    // Recursively update secondaries of secondary
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            secondary_context->SecondaryUpdateContextFromPrimary(dispatch_descriptor_sets, tr_descriptor_sets);
        }
    }

    // Having updated all secondary's context attributes update its dispatch/trace rays params.
    // Secondary command buffer can inherit state from the primary. Part of that state that we care about are the bound
    // descriptors. If that state is missing from the secondary then we get it from the primary. The best time to do
    // this is when vkCmdExecuteCommands is called.
    for (auto& params : dispatch_params_)
    {
        GFXRECON_ASSERT(params.second);

        gfxrecon::decode::SnapshotBoundDescriptorsDispatch(
            *params.second, bound_pipeline_compute_, dispatch_descriptor_sets);
    }

    for (auto& params : trace_rays_params_)
    {
        GFXRECON_ASSERT(params.second);

        gfxrecon::decode::SnapshotBoundDescriptorsTraceRays(
            *params.second, bound_pipeline_trace_rays_, tr_descriptor_sets);
    }

    // Move secondary draw dispatch and trace rays parameters to primary.
    // When DumpDispatchTraceRays is called it's better to have all  parameters available in the primary which is
    // submitted.
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            DispatchParameters& secondary_disp_params = secondary_context->GetDispatchParameters();
            for (auto& secondary_disp_param : secondary_disp_params)
            {
                const auto new_entry = dispatch_params_.insert(
                    std::make_pair(secondary_disp_param.first, std::move(secondary_disp_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_disp_params.clear();

            TraceRaysParameters& secondary_tr_params = secondary_context->GetTraceRaysParameters();
            for (auto& secondary_tr_param : secondary_tr_params)
            {
                const auto new_entry = trace_rays_params_.insert(
                    std::make_pair(secondary_tr_param.first, std::move(secondary_tr_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_tr_params.clear();
        }
    }
}

void DispatchTraceRaysDumpingContext::BindPipeline(VkPipelineBindPoint bind_point, const VulkanPipelineInfo* pipeline)
{
    switch (bind_point)
    {
        case VK_PIPELINE_BIND_POINT_COMPUTE:
            bound_pipeline_compute_ = pipeline;
            break;

        case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
            bound_pipeline_trace_rays_ = pipeline;
            break;

        default:
            break;
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
