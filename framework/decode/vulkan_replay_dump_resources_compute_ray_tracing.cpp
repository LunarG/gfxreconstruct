/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_descriptor_utils.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_replay_dump_resources_windows.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_resources_util.h"
#include "graphics/vulkan_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#if !defined(_WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DispatchTraceRaysDumpingContext::DispatchTraceRaysDumpingContext(
    std::shared_ptr<DumpingContextWindows>            windows,
    const CommandImageSubresource&                    disp_subresources,
    decode::Index                                     bcb_index,
    decode::Index                                     qs_index,
    const CommandImageSubresource&                    tr_subresources,
    CommonObjectInfoTable&                            object_info_table,
    const VulkanReplayOptions&                        options,
    VulkanDumpResourcesDelegate&                      delegate,
    const util::Compressor*                           compressor,
    const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
    const VulkanPerDeviceContexts&                    device_contexts) :
    DumpingContextBase(std::move(windows),
                       bcb_index,
                       qs_index,
                       object_info_table,
                       options,
                       delegate,
                       compressor,
                       acceleration_structures_context,
                       device_contexts),
    disp_subresources_(disp_subresources), tr_subresources_(tr_subresources), bound_pipeline_compute_(nullptr),
    bound_pipeline_trace_rays_(nullptr), parent_device_(VK_NULL_HANDLE)
{}

DispatchTraceRaysDumpingContext::~DispatchTraceRaysDumpingContext()
{
    Release();
}

void DispatchTraceRaysDumpingContext::Release()
{
    if (original_command_buffer_info_)
    {
        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        if (device_info != nullptr)
        {
            ReleaseIndirectParams();
        }

        original_command_buffer_info_ = nullptr;
    }

    bound_descriptor_sets_compute_.clear();
    bound_descriptor_sets_ray_tracing_.clear();
    dispatch_params_.clear();
    trace_rays_params_.clear();
}

// Every dumped dispatch/trace rays command is a slot of the windows: the command ends the clone taking work
// (window), so that the referenced resources can be dumped right after that window executed, before the next
// one runs. With --dump-resources-before the window that ends right before the command is finalized as well.
//
// The command itself is recorded by VulkanReplayDumpResourcesBase, between Before*() and After*().
//
// The parameters are inserted ahead of the before-window finalization because, for indirect commands, inserting
// them records the copy of the indirect parameters into the clone taking work: that copy then lands in the "before"
// window and is read back once that window executed.
void DispatchTraceRaysDumpingContext::FinalizeBeforeWindow()
{
    if (options_.dump_resources_before)
    {
        windows_->FinalizeWindow();
    }
}

void DispatchTraceRaysDumpingContext::BeforeDispatch(uint64_t disp_index,
                                                     uint32_t groupCountX,
                                                     uint32_t groupCountY,
                                                     uint32_t groupCountZ)
{
    if (MustDumpDispatch(disp_index))
    {
        InsertNewDispatchParameters(disp_index, groupCountX, groupCountY, groupCountZ);
        FinalizeBeforeWindow();
    }
}

void DispatchTraceRaysDumpingContext::BeforeDispatchIndirect(uint64_t                disp_index,
                                                             const VulkanBufferInfo* buffer_info,
                                                             VkDeviceSize            offset)
{
    if (MustDumpDispatch(disp_index))
    {
        InsertNewDispatchParameters(disp_index, buffer_info, offset);
        FinalizeBeforeWindow();
    }
}

void DispatchTraceRaysDumpingContext::AfterDispatch(uint64_t disp_index)
{
    if (MustDumpDispatch(disp_index))
    {
        windows_->FinalizeWindow();
    }
}

void DispatchTraceRaysDumpingContext::BeforeTraceRays(
    uint64_t                               tr_index,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    uint32_t                               width,
    uint32_t                               height,
    uint32_t                               depth)
{
    if (MustDumpTraceRays(tr_index))
    {
        InsertNewTraceRaysParameters(tr_index,
                                     pRaygenShaderBindingTable,
                                     pMissShaderBindingTable,
                                     pHitShaderBindingTable,
                                     pCallableShaderBindingTable,
                                     width,
                                     height,
                                     depth);
        FinalizeBeforeWindow();
    }
}

void DispatchTraceRaysDumpingContext::BeforeTraceRaysIndirect(
    uint64_t                               tr_index,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    if (MustDumpTraceRays(tr_index))
    {
        InsertNewTraceRaysIndirectParameters(tr_index,
                                             pRaygenShaderBindingTable,
                                             pMissShaderBindingTable,
                                             pHitShaderBindingTable,
                                             pCallableShaderBindingTable,
                                             indirectDeviceAddress);
        FinalizeBeforeWindow();
    }
}

void DispatchTraceRaysDumpingContext::BeforeTraceRaysIndirect2(uint64_t tr_index, VkDeviceAddress indirectDeviceAddress)
{
    if (MustDumpTraceRays(tr_index))
    {
        InsertNewTraceRaysIndirect2Parameters(tr_index, indirectDeviceAddress);
        FinalizeBeforeWindow();
    }
}

void DispatchTraceRaysDumpingContext::AfterTraceRays(uint64_t tr_index)
{
    if (MustDumpTraceRays(tr_index))
    {
        windows_->FinalizeWindow();
    }
}

VkResult DispatchTraceRaysDumpingContext::BeginCommandBuffer(const VulkanCommandBufferInfo* orig_cmd_buf_info,
                                                             const graphics::VulkanInjectedDeviceCalls& dev_table,
                                                             const graphics::VulkanInstanceTable*       inst_table)
{
    // The windows' clones are the only execution of this command buffer, so there is nothing to allocate here
    const VkResult res = DumpingContextBase::BeginCommandBuffer(orig_cmd_buf_info, dev_table, inst_table);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);

    assert(parent_device_ == VK_NULL_HANDLE);
    parent_device_ = device_info->handle;

    return VK_SUCCESS;
}

VkCommandBuffer DispatchTraceRaysDumpingContext::RecordingCommandBuffer() const
{
    return windows_->GetWorkCommandBuffer();
}

void DispatchTraceRaysDumpingContext::PushDescriptorSet(
    VkShaderStageFlags                                        stage_flags,
    uint32_t                                                  set,
    uint32_t                                                  descriptor_write_count,
    const StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes)
{
    const std::vector<VkPipelineBindPoint> pipeline_bind_points =
        graphics::ShaderStageFlagsToPipelineBindPoints(stage_flags);

    const bool has_compute =
        std::find(pipeline_bind_points.begin(), pipeline_bind_points.end(), VK_PIPELINE_BIND_POINT_COMPUTE) !=
        pipeline_bind_points.end();
    const bool has_ray_tracing =
        std::find(pipeline_bind_points.begin(), pipeline_bind_points.end(), VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR) !=
        pipeline_bind_points.end();

    if (!has_compute && !has_ray_tracing)
    {
        return;
    }

    if (has_compute)
    {
        HandleDescriptorUpdate(object_info_table_,
                               descriptor_write_count,
                               p_descriptor_writes,
                               &bound_descriptor_sets_compute_[set],
                               stage_flags);
    }

    if (has_ray_tracing)
    {
        HandleDescriptorUpdate(object_info_table_,
                               descriptor_write_count,
                               p_descriptor_writes,
                               &bound_descriptor_sets_ray_tracing_[set],
                               stage_flags);
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
        const auto set_index = GFXRECON_NARROWING_CAST(uint32_t, (first_set + i));

        VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo& bound_descriptor_sets =
            pipeline_bind_point == VK_PIPELINE_BIND_POINT_COMPUTE ? bound_descriptor_sets_compute_[set_index]
                                                                  : bound_descriptor_sets_ray_tracing_[set_index];

        bound_descriptor_sets = descriptor_sets_infos[i]->descriptors;

        if (dynamicOffsetCount && pDynamicOffsets != nullptr)
        {
            for (const auto& [binding_index, binding] : descriptor_sets_infos[i]->descriptors)
            {
                if (binding.desc_type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                    binding.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
                {
                    for (auto& [array_index, buf_desc] : bound_descriptor_sets[binding_index].buffer_info)
                    {
                        buf_desc.offset += pDynamicOffsets[dynamic_offset_index];
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
    return windows_->IsNextSlot(index, WindowSlot::Kind::kDispatch);
}

bool DispatchTraceRaysDumpingContext::MustDumpTraceRays(uint64_t index) const
{
    return windows_->IsNextSlot(index, WindowSlot::Kind::kTraceRays);
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
                if (layout_entry == bound_pipeline_compute->desc_set_layouts[desc_set_index].end() ||
                    !(bound_pipeline_compute->shader_stages & binding_info.stage_flags))
                {
                    continue;
                }

                disp_params.referenced_descriptors[desc_set_index][desc_binding_index].desc_type =
                    binding_info.desc_type;
                disp_params.referenced_descriptors[desc_set_index][desc_binding_index].stage_flags =
                    (bound_pipeline_compute->shader_stages & binding_info.stage_flags);

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
                    {
                        for (const auto& [array_idx, buf_info] : binding_info.texel_buffer_view_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            disp_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .texel_buffer_view_info[array_idx] = buf_info;
                        }
                    }
                    break;

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
                if (layout_entry == bound_pipeline_trace_rays->desc_set_layouts[desc_set_index].end() ||
                    !(bound_pipeline_trace_rays->shader_stages & binding_info.stage_flags))
                {
                    continue;
                }

                tr_params.referenced_descriptors[desc_set_index][desc_binding_index].desc_type = binding_info.desc_type;
                tr_params.referenced_descriptors[desc_set_index][desc_binding_index].stage_flags =
                    (bound_pipeline_trace_rays->shader_stages & binding_info.stage_flags);

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
                    {
                        for (const auto& [array_idx, buf_info] : binding_info.texel_buffer_view_info)
                        {
                            // Check against pipeline layout
                            if (layout_entry->second.count <= array_idx)
                            {
                                continue;
                            }

                            tr_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .texel_buffer_view_info[array_idx] = buf_info;
                        }
                    }
                    break;

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

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        for (const auto& [array_idx, as_info] : binding_info.acceleration_structs_khr_info)
                        {
                            tr_params.referenced_descriptors[desc_set_index][desc_binding_index]
                                .acceleration_structs_khr_info[array_idx] = as_info;
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

void DispatchTraceRaysDumpingContext::ReleaseIndirectParams()
{
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    auto                    injected    = device_table_.Open();
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
            injected->DestroyBuffer(
                device_info->handle, dis_params.dispatch_params_union.dispatch_indirect.new_params_buffer, nullptr);
            dis_params.dispatch_params_union.dispatch_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (dis_params.dispatch_params_union.dispatch_indirect.new_params_memory != VK_NULL_HANDLE)
        {
            injected->FreeMemory(
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
            injected->DestroyBuffer(
                device_info->handle, tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer, nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory != VK_NULL_HANDLE)
        {
            injected->FreeMemory(device_info->handle,
                                 tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory,
                                 nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.new_params_buffer_memory = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address != VK_NULL_HANDLE)
        {
            injected->DestroyBuffer(device_info->handle,
                                    tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address,
                                    nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address = VK_NULL_HANDLE;
        }

        if (tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory != VK_NULL_HANDLE)
        {
            injected->FreeMemory(device_info->handle,
                                 tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory,
                                 nullptr);
            tr_params.trace_rays_params_union.trace_rays_indirect.buffer_on_device_address_memory = VK_NULL_HANDLE;
        }
    }
}

VkResult DispatchTraceRaysDumpingContext::DumpMutableResources(const DumpedResourceBase& dumped_resource_base,
                                                               bool                      is_dispatch,
                                                               bool                      before_command)
{
    const Index cmd_index  = dumped_resource_base.cmd_index;
    auto        dis_params = dispatch_params_.find(cmd_index);
    auto        tr_params  = trace_rays_params_.find(cmd_index);

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

    const auto& command_subresources = is_dispatch ? disp_subresources_ : tr_subresources_;

    const decode::CommandLocation command_location(bcb_index_, qs_index_, cmd_index);
    const auto&                   cmd_subresources_entry = command_subresources.find(command_location);

    // If there is no entry for this command index then we should dump all referenced descriptors
    const bool cull_resources = cmd_subresources_entry != command_subresources.end();

    // An empty descriptors array in the input json means that we don't want to dump any descriptors for this call
    if (cull_resources && cmd_subresources_entry->second.empty())
    {
        return VK_SUCCESS;
    }

    const BoundDescriptorSets& referenced_descriptors =
        is_dispatch ? dis_params->second->referenced_descriptors : tr_params->second->referenced_descriptors;

    DumpedResourcesInfo& dumped_resources =
        is_dispatch ? dis_params->second->dumped_resources : tr_params->second->dumped_resources;

    dumped_resources.bcb_index = bcb_index_;
    dumped_resources.cmd_index = cmd_index;
    dumped_resources.qs_index  = qs_index_;

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    const DumpResourcesPipelineStage ppl_stage =
        is_dispatch ? DumpResourcesPipelineStage::kCompute : DumpResourcesPipelineStage::kRayTracing;

    const VulkanDelegateDumpResourceContext res_info_base(instance_table_, device_table_, compressor_, before_command);

    // The entry of a descriptor is created on the first window of the command: the only one, or the "before" one
    // with --dump-resources-before. The "after" window finds it again by its location.
    const bool insert_new_resource_entry = before_command || !options_.dump_resources_before;

    const auto find_dumped_descriptor = [&dumped_resources](const DescriptorLocation& desc_tuple,
                                                            DumpResourceType          type) -> DumpedDescriptor* {
        const auto entry = std::find_if(dumped_resources.dumped_descriptors.begin(),
                                        dumped_resources.dumped_descriptors.end(),
                                        [&desc_tuple, type](const DumpedDescriptor& dumped_desc) {
                                            return dumped_desc.type == type && dumped_desc.desc_tuple == desc_tuple;
                                        });
        return entry != dumped_resources.dumped_descriptors.end() ? &*entry : nullptr;
    };

    const DescriptorImageSubresourcesVector* requested_descriptors =
        cull_resources ? &cmd_subresources_entry->second : nullptr;
    DescriptorImageSubresourcesVector descriptors_to_dump;
    CullDescriptors(object_info_table_,
                    referenced_descriptors,
                    requested_descriptors,
                    cmd_index,
                    options_.dump_resources_dump_all_image_subresources,
                    descriptors_to_dump);

    for (const auto& [desc_tuple, img_subresource_range] : descriptors_to_dump)
    {
        const auto desc_set_entry = referenced_descriptors.find(desc_tuple.set);
        GFXRECON_ASSERT(desc_set_entry != referenced_descriptors.end());
        const auto& desc_set = desc_set_entry->second;

        const auto desc_binding_entry = desc_set.find(desc_tuple.binding);
        GFXRECON_ASSERT(desc_binding_entry != desc_set.end());
        const auto& desc_binding = desc_binding_entry->second;

        switch (desc_binding.desc_type)
        {
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            {
                const auto img_desc_entry = desc_binding.image_info.find(desc_tuple.array_index);
                GFXRECON_ASSERT(img_desc_entry != desc_binding.image_info.end());
                const VulkanDescriptorTypeImageInfo& img_desc = img_desc_entry->second;
                if (img_desc.image_view_info == nullptr)
                {
                    continue;
                }

                const VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_desc.image_view_info->image_id);
                if (img_info == nullptr)
                {
                    continue;
                }

                const ImageDumpResult can_dump_image = CanDumpImage(instance_table_,
                                                                    device_info->parent,
                                                                    img_info,
                                                                    device_info->property_feature_info,
                                                                    device_info->version_extension_info);

                DumpedDescriptor* dumped_desc = nullptr;
                if (insert_new_resource_entry)
                {
                    dumped_desc =
                        &dumped_resources.dumped_descriptors.emplace_back(dumped_resource_base,
                                                                          DumpResourceType::kDispatchTraceRaysImage,
                                                                          desc_binding.stage_flags,
                                                                          desc_binding.desc_type,
                                                                          desc_tuple,
                                                                          img_info,
                                                                          can_dump_image,
                                                                          ppl_stage);
                    if (before_command)
                    {
                        dumped_desc->has_before             = true;
                        dumped_desc->dumped_resource_before = DumpedImage(img_info, can_dump_image);
                    }
                }
                else
                {
                    dumped_desc = find_dumped_descriptor(desc_tuple, DumpResourceType::kDispatchTraceRaysImage);
                    GFXRECON_ASSERT(dumped_desc != nullptr);
                    if (dumped_desc == nullptr)
                    {
                        continue;
                    }
                }

                if (can_dump_image != ImageDumpResult::kCanDump)
                {
                    continue;
                }

                // The layout the application declared for the dispatch/trace rays in the descriptor. DumpImage
                // transitions the image to TRANSFER_SRC_OPTIMAL and back to it, so the following windows find the
                // image as the command left it.
                const VkImageLayout layout = img_desc.image_layout != VK_IMAGE_LAYOUT_UNDEFINED
                                                 ? img_desc.image_layout
                                                 : VK_IMAGE_LAYOUT_GENERAL;

                VulkanDelegateDumpResourceContext res_info = res_info_base;
                res_info.dumped_resource                   = dumped_desc;
                res_info.dumped_data                       = VulkanDelegateImageDumpedData();
                auto& dumped_image_data = std::get<VulkanDelegateImageDumpedData>(res_info.dumped_data);

                DumpedImage& dumped_image = before_command ? std::get<DumpedImage>(dumped_desc->dumped_resource_before)
                                                           : std::get<DumpedImage>(dumped_desc->dumped_resource);

                VkResult res = DumpImage(dumped_image,
                                         layout,
                                         options_.dump_resources_scale,
                                         options_.dump_resources_dump_raw_images,
                                         img_subresource_range,
                                         dumped_image_data.data,
                                         device_info,
                                         device_table_,
                                         instance_table_,
                                         object_info_table_);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Reading from image descriptor %" PRIu64 " failed (%s)",
                                       img_info->capture_id,
                                       util::ToString(res).c_str());

                    if (insert_new_resource_entry)
                    {
                        dumped_resources.dumped_descriptors.pop_back();
                    }

                    return res;
                }

                delegate_.DumpResource(res_info);
            }
            break;

            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            {
                const VulkanBufferInfo* buffer_info = nullptr;
                VkDeviceSize            offset      = 0;
                VkDeviceSize            range       = 0;
                if (desc_binding.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER)
                {
                    const auto buf_desc_entry = desc_binding.texel_buffer_view_info.find(desc_tuple.array_index);
                    GFXRECON_ASSERT(buf_desc_entry != desc_binding.texel_buffer_view_info.end());
                    const VulkanBufferViewInfo* buf_desc = buf_desc_entry->second;
                    if (buf_desc == nullptr)
                    {
                        continue;
                    }

                    buffer_info = object_info_table_.GetVkBufferInfo(buf_desc->buffer_id);
                    offset      = buf_desc->offset;
                    range       = buf_desc->range;
                }
                else
                {
                    const auto buf_desc_entry = desc_binding.buffer_info.find(desc_tuple.array_index);
                    GFXRECON_ASSERT(buf_desc_entry != desc_binding.buffer_info.end());
                    const VulkanDescriptorTypeBufferInfo& buf_desc = buf_desc_entry->second;

                    buffer_info = buf_desc.buffer_info;
                    offset      = buf_desc.offset;
                    range       = buf_desc.range;
                }

                if (buffer_info == nullptr)
                {
                    continue;
                }

                const VkDeviceSize size = (range == VK_WHOLE_SIZE) ? (buffer_info->size - offset) : range;
                if (size == 0)
                {
                    continue;
                }

                DumpedDescriptor* dumped_desc = nullptr;
                if (insert_new_resource_entry)
                {
                    dumped_desc =
                        &dumped_resources.dumped_descriptors.emplace_back(dumped_resource_base,
                                                                          DumpResourceType::kDispatchTraceRaysBuffer,
                                                                          desc_binding.stage_flags,
                                                                          desc_binding.desc_type,
                                                                          desc_tuple,
                                                                          buffer_info->handle,
                                                                          buffer_info->capture_id,
                                                                          offset,
                                                                          size,
                                                                          ppl_stage);
                    if (before_command)
                    {
                        dumped_desc->has_before = true;
                        dumped_desc->dumped_resource_before =
                            DumpedBuffer(buffer_info->handle, buffer_info->capture_id, offset, size);
                    }
                }
                else
                {
                    dumped_desc = find_dumped_descriptor(desc_tuple, DumpResourceType::kDispatchTraceRaysBuffer);
                    GFXRECON_ASSERT(dumped_desc != nullptr);
                    if (dumped_desc == nullptr)
                    {
                        continue;
                    }
                }

                VulkanDelegateDumpResourceContext res_info = res_info_base;
                res_info.dumped_resource                   = dumped_desc;
                res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
                auto& dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);

                const DumpedBuffer& dumped_buffer = before_command
                                                        ? std::get<DumpedBuffer>(dumped_desc->dumped_resource_before)
                                                        : std::get<DumpedBuffer>(dumped_desc->dumped_resource);

                VkResult res = DumpBuffer(dumped_buffer,
                                          dumped_buffer_data.data,
                                          device_info,
                                          device_table_,
                                          instance_table_,
                                          object_info_table_);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Reading from buffer descriptor %" PRIu64 " failed (%s)",
                                       buffer_info->capture_id,
                                       util::ToString<VkResult>(res).c_str())

                    if (insert_new_resource_entry)
                    {
                        dumped_resources.dumped_descriptors.pop_back();
                    }

                    return res;
                }

                delegate_.DumpResource(res_info);
            }
            break;

            default:
                // Read only descriptors are handled by DumpDescriptors
                break;
        }
    }

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::DumpCommand(Index cmd_index,
                                                      bool  is_trace_rays,
                                                      bool  is_before_window,
                                                      Index window_index,
                                                      Index submit_info_index,
                                                      Index submit_info_cmd_buf_index)
{
    const bool is_dispatch = !is_trace_rays;

    // What is dumped once per command is dumped on its first window: the only one, or the "before" one with
    // --dump-resources-before. The command's info goes out on its last window, once everything is in place.
    const bool first_window = !options_.dump_resources_before || is_before_window;
    const bool last_window  = !options_.dump_resources_before || !is_before_window;

    GFXRECON_LOG_INFO("Dumping mutable resources for %s index %" PRIu64 "%s",
                      is_dispatch ? "dispatch" : "trace rays",
                      cmd_index,
                      is_before_window ? " (before)" : "");

    DumpResourcesCommandBufferLevel              command_buffer_level  = DumpResourcesCommandBufferLevel::kPrimary;
    const std::map<Index, SecondaryIdentifiers>* secondary_identifiers = nullptr;
    const void*                                  command_params        = nullptr;
    DumpedResourcesInfo*                         dumped_resources      = nullptr;

    VkResult res = VK_SUCCESS;
    if (is_dispatch)
    {
        const auto entry = dispatch_params_.find(cmd_index);
        if (entry == dispatch_params_.end())
        {
            GFXRECON_LOG_ERROR("Could not correlate dispatch with index %" PRIu64 " with its parameters", cmd_index);
            GFXRECON_ASSERT(0);
            return VK_ERROR_UNKNOWN;
        }

        DispatchParams& disp_params = *entry->second;
        command_buffer_level        = disp_params.command_buffer_level;
        secondary_identifiers       = &disp_params.secondary_identifiers;
        command_params              = &disp_params;
        dumped_resources            = &disp_params.dumped_resources;

        // The copy of the indirect parameters was recorded into the first window
        if (first_window && IsDispatchIndirect(disp_params.type))
        {
            res = FetchDispatchIndirectParams(disp_params);
        }
    }
    else
    {
        const auto entry = trace_rays_params_.find(cmd_index);
        if (entry == trace_rays_params_.end())
        {
            GFXRECON_LOG_ERROR("Could not correlate trace rays with index %" PRIu64 " with its parameters", cmd_index);
            GFXRECON_ASSERT(0);
            return VK_ERROR_UNKNOWN;
        }

        TraceRaysParams& tr_params = *entry->second;
        command_buffer_level       = tr_params.command_buffer_level;
        secondary_identifiers      = &tr_params.secondary_identifiers;
        command_params             = &tr_params;
        dumped_resources           = &tr_params.dumped_resources;

        if (first_window && IsTraceRaysIndirect(tr_params.type))
        {
            res = FetchTraceRaysIndirectParams(tr_params);
        }
    }

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Fetching params for indirect calls failed (%s).", util::ToString<VkResult>(res).c_str())
        return res;
    }

    SecondaryIdentifiers secondary_indices;
    if (command_buffer_level == DumpResourcesCommandBufferLevel::kSecondary)
    {
        // This map is filled in by MergeSecondaryCommand, keyed by the primary's window
        const auto entry = secondary_identifiers->find(window_index);
        GFXRECON_ASSERT(entry != secondary_identifiers->end());
        if (entry != secondary_identifiers->end())
        {
            secondary_indices = entry->second;
            GFXRECON_ASSERT(secondary_indices.execute_cmds_index != UNDEFINED_INDEX);
            GFXRECON_ASSERT(secondary_indices.execute_cmds_cmd_buf_index != UNDEFINED_INDEX);
        }
    }

    const DumpResourcesPipelineStage ppl_stage =
        is_dispatch ? DumpResourcesPipelineStage::kCompute : DumpResourcesPipelineStage::kRayTracing;

    const DumpedResourceBase dumped_resource_base(ppl_stage,
                                                  bcb_index_,
                                                  cmd_index,
                                                  qs_index_,
                                                  submit_info_index,
                                                  submit_info_cmd_buf_index,
                                                  secondary_indices.execute_cmds_index,
                                                  secondary_indices.execute_cmds_cmd_buf_index);

    // The parameters of a command recorded in a secondary are shared by every execution of that secondary, so what
    // was dumped for a previous execution must not leak into this slot. Reset once per slot: with
    // --dump-resources-before the "after" window finds the entries the "before" window created.
    if (first_window)
    {
        dumped_resources->Reset();
    }

    res = DumpMutableResources(dumped_resource_base, is_dispatch, is_before_window);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Dumping %s mutable resources failed (%s).",
                           is_dispatch ? "compute" : "ray tracing",
                           util::ToString<VkResult>(res).c_str())
        return res;
    }

    if (options_.dump_all_descriptors && first_window)
    {
        res = DumpDescriptors(dumped_resource_base, is_dispatch);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }
    }

    if (last_window)
    {
        if (is_dispatch)
        {
            const VulkanDelegateDumpDrawCallContext draw_call_info(
                ppl_stage, instance_table_, device_table_, static_cast<const DispatchParams*>(command_params));
            delegate_.DumpDrawCallInfo(draw_call_info);
        }
        else
        {
            const VulkanDelegateDumpDrawCallContext draw_call_info(
                ppl_stage, instance_table_, device_table_, static_cast<const TraceRaysParams*>(command_params));
            delegate_.DumpDrawCallInfo(draw_call_info);
        }

        DumpResourcesProgress::Advance();
    }

    return VK_SUCCESS;
}

void DispatchTraceRaysDumpingContext::ResetDumpedResources()
{
    // Clean up references to dumped descriptors in case this command buffer is submitted again
    dispatch_dumped_descriptors_.buffer_descriptors.clear();
    dispatch_dumped_descriptors_.image_descriptors.clear();
    dispatch_dumped_descriptors_.acceleration_structures.clear();

    trace_rays_dumped_descriptors_.buffer_descriptors.clear();
    trace_rays_dumped_descriptors_.image_descriptors.clear();
    trace_rays_dumped_descriptors_.acceleration_structures.clear();

    for (auto& tr_params : trace_rays_params_)
    {
        tr_params.second->dumped_resources.Reset();
    }

    for (auto& disp_params : dispatch_params_)
    {
        disp_params.second->dumped_resources.Reset();
    }
}

VkResult DispatchTraceRaysDumpingContext::ReadIndirectParams(VkBuffer params_buffer, VkDeviceSize size, void* params)
{
    GFXRECON_ASSERT(params_buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(params != nullptr);

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    const uint32_t transfer_queue_index = FindTransferQueueFamilyIndex(device_info->enabled_queue_family_flags);
    if (transfer_queue_index == VK_QUEUE_FAMILY_IGNORED)
    {
        GFXRECON_LOG_ERROR("Failed to find a transfer queue")
        return VK_ERROR_UNKNOWN;
    }

    graphics::VulkanResourcesUtil resource_util(device_info->handle,
                                                device_info->parent,
                                                device_table_,
                                                *instance_table_,
                                                device_info->property_feature_info,
                                                device_info->version_extension_info,
                                                *phys_dev_info->replay_device_info->memory_properties);

    std::vector<uint8_t> data;
    VkResult             res = resource_util.ReadFromBufferResource(params_buffer, size, 0, transfer_queue_index, data);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Reading from buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
        return res;
    }

    GFXRECON_ASSERT(data.size() == size);
    util::platform::MemoryCopy(params, size, data.data(), size);

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::FetchDispatchIndirectParams(DispatchParams& disp_params)
{
    GFXRECON_ASSERT(IsDispatchIndirect(disp_params.type));

    DispatchParams::DispatchParamsUnion::DispatchIndirect& i_params =
        disp_params.dispatch_params_union.dispatch_indirect;

    // No copy of the parameters was recorded
    if (i_params.new_params_buffer == VK_NULL_HANDLE)
    {
        return VK_SUCCESS;
    }

    return ReadIndirectParams(
        i_params.new_params_buffer, sizeof(VkDispatchIndirectCommand), &i_params.fetched_dispatch_params);
}

VkResult DispatchTraceRaysDumpingContext::FetchTraceRaysIndirectParams(TraceRaysParams& tr_params)
{
    GFXRECON_ASSERT(IsTraceRaysIndirect(tr_params.type));

    if (tr_params.type == kTraceRaysIndirect)
    {
        TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect& i_params =
            tr_params.trace_rays_params_union.trace_rays_indirect;

        // No copy of the parameters was recorded (null indirect device address)
        if (i_params.new_params_buffer == VK_NULL_HANDLE)
        {
            return VK_SUCCESS;
        }

        return ReadIndirectParams(
            i_params.new_params_buffer, sizeof(VkTraceRaysIndirectCommandKHR), &i_params.trace_rays_params);
    }
    else
    {
        TraceRaysParams::TraceRaysParamsUnion::TraceRaysIndirect2& i_params =
            tr_params.trace_rays_params_union.trace_rays_indirect2;

        if (i_params.new_params_buffer == VK_NULL_HANDLE)
        {
            return VK_SUCCESS;
        }

        return ReadIndirectParams(
            i_params.new_params_buffer, sizeof(VkTraceRaysIndirectCommand2KHR), &i_params.trace_rays_params);
    }
}

VkResult DispatchTraceRaysDumpingContext::DumpSlot(const WindowSlot& slot,
                                                   size_t            window_index,
                                                   VkQueue           queue,
                                                   Index             submit_info_index,
                                                   Index             submit_info_cmd_buf_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_ASSERT(slot.kind == WindowSlot::Kind::kDispatch || slot.kind == WindowSlot::Kind::kTraceRays);

    // With --dump-resources-before the even windows end right before their command
    const bool is_before_window = options_.dump_resources_before && !(window_index % 2);

    return DumpCommand(slot.index,
                       slot.kind == WindowSlot::Kind::kTraceRays,
                       is_before_window,
                       window_index,
                       submit_info_index,
                       submit_info_cmd_buf_index);
}

void DispatchTraceRaysDumpingContext::PrepareSecondary(DumpingContextBase& secondary_owner)
{
    // The purpose of this function is to transfer the compute/ray tracing context from a primary to its secondaries.
    // This function must be called only for primary command buffer contexes, even if a secondary has secondaries.
    GFXRECON_ASSERT(windows_->GetCommandBufferLevel() == DumpResourcesCommandBufferLevel::kPrimary);

    auto& secondary_context = static_cast<DispatchTraceRaysDumpingContext&>(secondary_owner);
    secondary_context.SecondaryUpdateContextFromPrimary(bound_descriptor_sets_compute_,
                                                        bound_descriptor_sets_ray_tracing_);
}

void DispatchTraceRaysDumpingContext::ExecuteSecondarySlot(DumpingContextBase& secondary_owner,
                                                           const WindowSlot&   secondary_slot,
                                                           Index               execute_cmd_index,
                                                           Index               command_buffer_execute_index)
{
    GFXRECON_ASSERT(secondary_slot.kind == WindowSlot::Kind::kDispatch ||
                    secondary_slot.kind == WindowSlot::Kind::kTraceRays);

    auto&      secondary_context = static_cast<DispatchTraceRaysDumpingContext&>(secondary_owner);
    const bool is_trace_rays     = (secondary_slot.kind == WindowSlot::Kind::kTraceRays);

    // The identifiers are keyed by the window of the primary that runs this execution of the command
    MergeSecondaryCommand(secondary_context,
                          secondary_slot.index,
                          is_trace_rays,
                          windows_->GetCurrentWindowIndex(),
                          execute_cmd_index,
                          command_buffer_execute_index);
    windows_->FinalizeWindow();

    // Finalize the command buffer for the before case as well
    if (options_.dump_resources_before)
    {
        MergeSecondaryCommand(secondary_context,
                              secondary_slot.index,
                              is_trace_rays,
                              windows_->GetCurrentWindowIndex(),
                              execute_cmd_index,
                              command_buffer_execute_index);
        windows_->FinalizeWindow();
    }
}

void DispatchTraceRaysDumpingContext::MergeSecondaryCommand(DispatchTraceRaysDumpingContext& secondary_context,
                                                            Index                            cmd_index,
                                                            bool                             is_trace_rays,
                                                            Index                            window_index,
                                                            Index                            execute_cmd_index,
                                                            Index command_buffer_execute_index)
{
    GFXRECON_ASSERT(windows_->GetCommandBufferLevel() == DumpResourcesCommandBufferLevel::kPrimary);

    // Share the secondary's parameters of the command with the primary, which is the one submitted and dumped, and
    // remember under which of its windows and which vkCmdExecuteCommands this execution of the command runs.
    const auto merge = [&](auto& params, auto& secondary_params) {
        const auto secondary_entry = secondary_params.find(cmd_index);
        if (secondary_entry == secondary_params.end())
        {
            GFXRECON_LOG_ERROR("Could not correlate %s with index %" PRIu64 " from a secondary with its parameters",
                               is_trace_rays ? "trace rays" : "dispatch",
                               cmd_index);
            GFXRECON_ASSERT(0);
            return;
        }

        auto entry = params.find(cmd_index);
        if (entry == params.end())
        {
            auto [new_entry, success] = params.insert(std::make_pair(cmd_index, secondary_entry->second));
            GFXRECON_ASSERT(success);
            entry = new_entry;
        }
        else
        {
            // This case will happen when a secondary command buffer is executed multiple times from the same primary
            GFXRECON_ASSERT(!entry->second->secondary_identifiers.empty());
        }

        entry->second->secondary_identifiers.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(window_index),
            std::forward_as_tuple(execute_cmd_index, command_buffer_execute_index));
    };

    if (is_trace_rays)
    {
        merge(trace_rays_params_, secondary_context.trace_rays_params_);
    }
    else
    {
        merge(dispatch_params_, secondary_context.dispatch_params_);
    }
}

VkResult DispatchTraceRaysDumpingContext::DumpDescriptors(const DumpedResourceBase& dumped_resource_base,
                                                          bool                      is_dispatch)
{
    const Index        cmd_index          = dumped_resource_base.cmd_index;
    DumpedDescriptors& dumped_descriptors = is_dispatch ? dispatch_dumped_descriptors_ : trace_rays_dumped_descriptors_;
    GFXRECON_ASSERT((dispatch_params_.find(cmd_index) != dispatch_params_.end()) ||
                    (trace_rays_params_.find(cmd_index) != trace_rays_params_.end()));
    const BoundDescriptorSets& referenced_descriptors = is_dispatch
                                                            ? (dispatch_params_[cmd_index]->referenced_descriptors)
                                                            : (trace_rays_params_[cmd_index]->referenced_descriptors);

    DumpedResourcesInfo& dumped_resources =
        is_dispatch ? dispatch_params_[cmd_index]->dumped_resources : trace_rays_params_[cmd_index]->dumped_resources;

    const DumpResourcesPipelineStage ppl_stage =
        is_dispatch ? DumpResourcesPipelineStage::kCompute : DumpResourcesPipelineStage::kRayTracing;

    const CommandImageSubresource& command_subresources = is_dispatch ? disp_subresources_ : tr_subresources_;

    const decode::CommandLocation command_location(bcb_index_, qs_index_, cmd_index);
    const auto&                   cmd_subresources_entry = command_subresources.find(command_location);

    // If there is no entry for this command index then we should dump all referenced descriptors
    const bool cull_resources = cmd_subresources_entry != command_subresources.end();

    // An empty descriptors array in the input json means that we don't want to dump any descriptors for this call
    if (cull_resources && cmd_subresources_entry->second.empty())
    {
        return VK_SUCCESS;
    }

    // Filter requested descriptors based on which are actually relevant to this draw call
    const DescriptorImageSubresourcesVector* requested_descriptors =
        cull_resources ? &cmd_subresources_entry->second : nullptr;
    DescriptorImageSubresourcesVector descriptors_to_dump;
    CullDescriptors(object_info_table_,
                    referenced_descriptors,
                    requested_descriptors,
                    cmd_index,
                    options_.dump_resources_dump_all_image_subresources,
                    descriptors_to_dump);

    const VulkanDelegateDumpResourceContext res_info_base{ instance_table_, device_table_, compressor_ };

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    for (const auto& [desc_tuple, img_subres_range] : descriptors_to_dump)
    {
        const auto desc_set_entry = referenced_descriptors.find(desc_tuple.set);
        GFXRECON_ASSERT(desc_set_entry != referenced_descriptors.end());
        const auto& desc_set = desc_set_entry->second;

        const auto desc_binding_entry = desc_set.find(desc_tuple.binding);
        GFXRECON_ASSERT(desc_binding_entry != desc_set.end());
        const auto& desc_binding = desc_binding_entry->second;

        switch (desc_binding.desc_type)
        {
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            {
                const auto img_desc_info_entry = desc_binding.image_info.find(desc_tuple.array_index);
                GFXRECON_ASSERT(img_desc_info_entry != desc_binding.image_info.end());
                const auto img_desc_info = img_desc_info_entry->second;
                if (img_desc_info.image_view_info != nullptr)
                {
                    const VulkanImageInfo* img_info =
                        object_info_table_.GetVkImageInfo(img_desc_info.image_view_info->image_id);
                    if (img_info == nullptr)
                    {
                        continue;
                    }

                    const ImageDumpResult can_dump_image = CanDumpImage(instance_table_,
                                                                        device_info->parent,
                                                                        img_info,
                                                                        device_info->property_feature_info,
                                                                        device_info->version_extension_info);

                    auto& new_dumped_desc = dumped_resources.dumped_descriptors.emplace_back(
                        dumped_resource_base,
                        DumpResourceType::kDispatchTraceRaysImageDescriptor,
                        desc_binding.stage_flags,
                        desc_binding.desc_type,
                        desc_tuple,
                        img_info,
                        can_dump_image,
                        ppl_stage);

                    if (can_dump_image != ImageDumpResult::kCanDump)
                    {
                        continue;
                    }

                    auto&       new_dumped_image   = std::get<DumpedImage>(new_dumped_desc.dumped_resource);
                    const auto& dumped_descs_entry = dumped_descriptors.image_descriptors.find(desc_tuple);
                    if (dumped_descs_entry == dumped_descriptors.image_descriptors.end() ||
                        dumped_descs_entry->second.image_info != img_info)
                    {
                        VulkanDelegateDumpResourceContext res_info = res_info_base;
                        res_info.dumped_resource                   = &new_dumped_desc;
                        res_info.dumped_data                       = VulkanDelegateImageDumpedData();
                        auto& dumped_image_data = std::get<VulkanDelegateImageDumpedData>(res_info.dumped_data);

                        VkResult res = DumpImage(new_dumped_image,
                                                 img_info->intermediate_layout,
                                                 options_.dump_resources_scale,
                                                 options_.dump_resources_dump_raw_images,
                                                 img_subres_range,
                                                 dumped_image_data.data,
                                                 device_info,
                                                 device_table_,
                                                 instance_table_,
                                                 object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Reading from image descriptor %" PRIu64 " failed (%s)",
                                               img_info->capture_id,
                                               util::ToString(res).c_str());

                            dumped_resources.dumped_descriptors.pop_back();

                            return res;
                        }

                        delegate_.DumpResource(res_info);

                        dumped_descriptors.image_descriptors.emplace(desc_tuple, new_dumped_image);
                    }
                    else
                    {
                        new_dumped_image = dumped_descs_entry->second;
                    }
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            {
                const auto buf_desc_info_entry = desc_binding.texel_buffer_view_info.find(desc_tuple.array_index);
                GFXRECON_ASSERT(buf_desc_info_entry != desc_binding.texel_buffer_view_info.end());
                const auto buf_desc_info = buf_desc_info_entry->second;

                const VulkanBufferInfo* buffer_info = object_info_table_.GetVkBufferInfo(buf_desc_info->buffer_id);
                if (buffer_info == nullptr)
                {
                    continue;
                }

                const VkDeviceSize offset = buf_desc_info->offset;
                const VkDeviceSize range  = buf_desc_info->range;
                const VkDeviceSize size   = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

                auto& new_dumped_desc = dumped_resources.dumped_descriptors.emplace_back(
                    dumped_resource_base,
                    DumpResourceType::kDispatchTraceRaysBufferDescriptor,
                    desc_binding.stage_flags,
                    desc_binding.desc_type,
                    desc_tuple,
                    buffer_info->handle,
                    buffer_info->capture_id,
                    offset,
                    size,
                    ppl_stage);

                const auto& dumped_desc_entry = dumped_descriptors.buffer_descriptors.find(desc_tuple);
                if (dumped_desc_entry == dumped_descriptors.buffer_descriptors.end() ||
                    dumped_desc_entry->second.buffer_info.capture_id != buffer_info->capture_id)
                {
                    const auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                    VulkanDelegateDumpResourceContext res_info = res_info_base;
                    res_info.dumped_resource                   = &new_dumped_desc;
                    res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
                    auto dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);

                    VkResult res = DumpBuffer(new_dumped_buffer,
                                              dumped_buffer_data.data,
                                              device_info,
                                              device_table_,
                                              instance_table_,
                                              object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Reading from buffer descriptor %" PRIu64 " failed (%s)",
                                           buffer_info->capture_id,
                                           util::ToString(res).c_str());

                        dumped_resources.dumped_descriptors.pop_back();

                        return res;
                    }

                    delegate_.DumpResource(res_info);

                    dumped_descriptors.buffer_descriptors.emplace(desc_tuple, new_dumped_buffer);
                }
                else
                {
                    auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                    new_dumped_buffer       = dumped_desc_entry->second;
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            {
                const auto desc_buf_info_entry = desc_binding.buffer_info.find(desc_tuple.array_index);
                GFXRECON_ASSERT(desc_buf_info_entry != desc_binding.buffer_info.end());
                const auto buf_desc_info = desc_buf_info_entry->second;

                const VulkanBufferInfo* buffer_info = buf_desc_info.buffer_info;
                if (buffer_info == nullptr)
                {
                    continue;
                }

                const VkDeviceSize offset = buf_desc_info.offset;
                const VkDeviceSize range  = buf_desc_info.range;
                const VkDeviceSize size   = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

                auto& new_dumped_desc = dumped_resources.dumped_descriptors.emplace_back(
                    dumped_resource_base,
                    DumpResourceType::kDispatchTraceRaysBufferDescriptor,
                    desc_binding.stage_flags,
                    desc_binding.desc_type,
                    desc_tuple,
                    buffer_info->handle,
                    buffer_info->capture_id,
                    offset,
                    size,
                    ppl_stage);

                const auto dumped_desc_entry = dumped_descriptors.buffer_descriptors.find(desc_tuple);
                if (dumped_desc_entry == dumped_descriptors.buffer_descriptors.end() ||
                    dumped_desc_entry->second.buffer_info.capture_id != buffer_info->capture_id)
                {
                    const auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                    VulkanDelegateDumpResourceContext res_info = res_info_base;
                    res_info.dumped_resource                   = &new_dumped_desc;
                    res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
                    auto& dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);

                    VkResult res = DumpBuffer(new_dumped_buffer,
                                              dumped_buffer_data.data,
                                              device_info,
                                              device_table_,
                                              instance_table_,
                                              object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Reading from buffer descriptor %" PRIu64 " failed (%s)",
                                           buffer_info->capture_id,
                                           util::ToString(res).c_str());

                        dumped_resources.dumped_descriptors.pop_back();

                        return res;
                    }

                    delegate_.DumpResource(res_info);

                    dumped_descriptors.buffer_descriptors.emplace(desc_tuple, new_dumped_buffer);
                }
                else
                {
                    auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                    new_dumped_buffer       = dumped_desc_entry->second;
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            {
                GFXRECON_ASSERT(!desc_tuple.array_index);
                auto& new_dumped_desc = dumped_resources.dumped_descriptors.emplace_back(
                    dumped_resource_base,
                    DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor,
                    desc_binding.stage_flags,
                    desc_binding.desc_type,
                    desc_tuple,
                    ppl_stage);

                VulkanDelegateDumpResourceContext res_info = res_info_base;
                res_info.dumped_resource                   = &new_dumped_desc;
                res_info.dumped_data                       = VulkanDelegateImageDumpedData();
                auto& dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);
                dumped_buffer_data.data  = desc_binding.inline_uniform_block;
                delegate_.DumpResource(res_info);
            }
            break;

            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            {
                const auto as_info_entry = desc_binding.acceleration_structs_khr_info.find(desc_tuple.array_index);
                GFXRECON_ASSERT(as_info_entry != desc_binding.acceleration_structs_khr_info.end());
                const auto as_info = as_info_entry->second;

                if (as_info == nullptr)
                {
                    continue;
                }

                GFXRECON_ASSERT(as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);
                auto& new_dumped_desc = dumped_resources.dumped_descriptors.emplace_back(
                    dumped_resource_base,
                    DumpResourceType::kAccelerationStructure,
                    desc_binding.stage_flags,
                    desc_binding.desc_type,
                    desc_tuple,
                    as_info,
                    options_.dump_resources_dump_build_AS_input_buffers,
                    ppl_stage);

                auto&       new_dumped_as     = std::get<DumpedAccelerationStructure>(new_dumped_desc.dumped_resource);
                const auto& dumped_desc_entry = dumped_descriptors.acceleration_structures.find(desc_tuple);
                if (dumped_desc_entry == dumped_descriptors.acceleration_structures.end() ||
                    dumped_desc_entry->second.as_info->capture_id != as_info->capture_id)
                {
                    VulkanDelegateDumpResourceContext res_info = res_info_base;
                    res_info.dumped_resource                   = &new_dumped_desc;
                    res_info.dumped_data                       = VulkanDelegateAccelerationStructureDumpedData();
                    auto& dumped_as_data =
                        std::get<VulkanDelegateAccelerationStructureDumpedData>(res_info.dumped_data);

                    auto tlas_context_entry = acceleration_structures_context_.find(as_info);
                    GFXRECON_ASSERT(tlas_context_entry != acceleration_structures_context_.end());
                    AccelerationStructureDumpResourcesContext* tlas_context = tlas_context_entry->second.get();

                    VkResult res = DumpAccelerationStructure(new_dumped_as,
                                                             dumped_as_data.data,
                                                             tlas_context,
                                                             acceleration_structures_context_,
                                                             device_info,
                                                             device_table_,
                                                             object_info_table_,
                                                             *instance_table_,
                                                             device_contexts_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Dumping acceleration structure %" PRIu64 " failed (%s)",
                                           as_info->capture_id,
                                           util::ToString(res).c_str());
                        dumped_resources.dumped_descriptors.pop_back();
                        return res;
                    }

                    delegate_.DumpResource(res_info);

                    // Stored once it is complete: this is a copy of what was dumped
                    dumped_descriptors.acceleration_structures.emplace(desc_tuple, new_dumped_as);
                }
                else
                {
                    new_dumped_as = dumped_desc_entry->second;
                }
            }
            break;

            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_SAMPLER:
                break;

            default:
                GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                          __func__,
                                          util::ToString<VkDescriptorType>(desc_binding.desc_type).c_str());
                break;
        }
    }

    return VK_SUCCESS;
}

VkResult DispatchTraceRaysDumpingContext::CopyDispatchIndirectParameters(DispatchParams& disp_params)
{
    GFXRECON_ASSERT(IsDispatchIndirect(disp_params.type));
    GFXRECON_ASSERT(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info != nullptr);
    GFXRECON_ASSERT(disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->handle != VK_NULL_HANDLE);

    const VkDeviceSize size               = sizeof(VkDispatchIndirectCommand);
    const auto*        parent_device_info = object_info_table_.GetVkDeviceInfo(
        disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->parent_id);
    VkResult res = CreateVkBuffer(size,
                                  device_table_,
                                  parent_device_info->handle,
                                  nullptr,
                                  nullptr,
                                  replay_device_phys_mem_props_,
                                  VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                  &disp_params.dispatch_params_union.dispatch_indirect.new_params_buffer,
                                  &disp_params.dispatch_params_union.dispatch_indirect.new_params_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Cloning buffer resources failed (%s)", util::ToString<VkResult>(res).c_str())
        return res;
    }

    // Inject a cmdCopyBuffer to copy the dispatch params into the new buffer
    {
        const VkDeviceSize offset  = disp_params.dispatch_params_union.dispatch_indirect.params_buffer_offset;
        VkCommandBuffer    cmd_buf = RecordingCommandBuffer();

        const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ offset, 0, size } };
        CopyBufferAndBarrier(cmd_buf,
                             device_table_,
                             disp_params.dispatch_params_union.dispatch_indirect.params_buffer_info->handle,
                             disp_params.dispatch_params_union.dispatch_indirect.new_params_buffer,
                             copy_region);
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
                                  reinterpret_cast<const VkBaseInStructure*>(&bdaci),
                                  nullptr,
                                  replay_device_phys_mem_props_,
                                  VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
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
                         reinterpret_cast<const VkBaseInStructure*>(&bdaci),
                         nullptr,
                         replay_device_phys_mem_props_,
                         VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                         &new_params_buffer,
                         &new_params_buffer_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("%s(): Failed to create buffer (%s)", __func__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Copy the parameters from one buffer into the other
    const std::vector<VkBufferCopy> copy_region{ VkBufferCopy{ 0, 0, size } };
    CopyBufferAndBarrier(
        RecordingCommandBuffer(), device_table_, buffer_on_device_address, new_params_buffer, copy_region);

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

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t index,
                                                                  uint32_t groupCountX,
                                                                  uint32_t groupCountY,
                                                                  uint32_t groupCountZ)
{
    auto new_entry = dispatch_params_.insert({ index,
                                               std::make_shared<DispatchParams>(DispatchTypes::kDispatch,
                                                                                windows_->GetCommandBufferLevel(),
                                                                                index,
                                                                                groupCountX,
                                                                                groupCountY,
                                                                                groupCountZ) });
    assert(new_entry.second);

    SnapshotDispatchState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::InsertNewDispatchParameters(uint64_t                index,
                                                                  const VulkanBufferInfo* buffer_info,
                                                                  VkDeviceSize            offset)
{
    auto new_entry = dispatch_params_.insert(
        { index,
          std::make_shared<DispatchParams>(
              DispatchTypes::kDispatchIndirect, windows_->GetCommandBufferLevel(), index, buffer_info, offset) });
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
        { index,
          std::make_shared<TraceRaysParams>(
              TraceRaysTypes::kTraceRays, windows_->GetCommandBufferLevel(), index, width, height, depth) });
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
        { index,
          std::make_shared<TraceRaysParams>(
              TraceRaysTypes::kTraceRaysIndirect, windows_->GetCommandBufferLevel(), index, indirectDeviceAddress) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotTraceRaysState(*new_entry.first->second);
}

void DispatchTraceRaysDumpingContext::InsertNewTraceRaysIndirect2Parameters(uint64_t        index,
                                                                            VkDeviceAddress indirectDeviceAddress)
{
    auto new_entry = trace_rays_params_.insert(
        { index,
          std::make_shared<TraceRaysParams>(
              TraceRaysTypes::kTraceRaysIndirect2, windows_->GetCommandBufferLevel(), index, indirectDeviceAddress) });
    GFXRECON_ASSERT(new_entry.second);

    SnapshotTraceRaysState(*new_entry.first->second);
}

std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>>
DispatchTraceRaysDumpingContext::GetSecondaryContexts() const
{
    // The secondaries are found through the windows, which hold the hierarchy of the command buffers. Only the ones
    // that dump dispatch/trace rays commands have a dispatch/trace rays context.
    std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> secondary_contexts;
    for (const auto& secondary_windows : windows_->GetSecondaries())
    {
        std::shared_ptr<DispatchTraceRaysDumpingContext> secondary_context =
            std::static_pointer_cast<DispatchTraceRaysDumpingContext>(
                secondary_windows->GetSlotOwner(WindowSlot::Kind::kDispatch));
        if (secondary_context != nullptr)
        {
            secondary_contexts.push_back(std::move(secondary_context));
        }
    }

    return secondary_contexts;
}

void DispatchTraceRaysDumpingContext::SecondaryUpdateContextFromPrimary(
    const BoundDescriptorSets& dispatch_descriptor_sets, const BoundDescriptorSets& tr_descriptor_sets)
{
    GFXRECON_ASSERT(windows_->GetCommandBufferLevel() == DumpResourcesCommandBufferLevel::kSecondary);

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> secondary_contexts = GetSecondaryContexts();

    // Recursively update secondaries of secondary
    for (const auto& secondary_context : secondary_contexts)
    {
        secondary_context->SecondaryUpdateContextFromPrimary(dispatch_descriptor_sets, tr_descriptor_sets);
    }

    // Having updated all secondary's context attributes update its dispatch/trace rays params.
    // Secondary command buffer can inherit state from the primary. Part of that state that we care about are the
    // bound descriptors. If that state is missing from the secondary then we get it from the primary. The best time
    // to do this is when vkCmdExecuteCommands is called.
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

    // Move secondary dispatch and trace rays parameters to primary.
    // When the commands are dumped it's better to have all parameters available in the primary which is submitted.
    for (const auto& secondary_context : secondary_contexts)
    {
        const DispatchParameters& secondary_disp_params = secondary_context->GetDispatchParameters();
        for (const auto& secondary_disp_param : secondary_disp_params)
        {
            const auto new_entry =
                dispatch_params_.insert(std::make_pair(secondary_disp_param.first, secondary_disp_param.second));
            GFXRECON_ASSERT(new_entry.second);
        }

        const TraceRaysParameters& secondary_tr_params = secondary_context->GetTraceRaysParameters();
        for (const auto& secondary_tr_param : secondary_tr_params)
        {
            const auto new_entry =
                trace_rays_params_.insert(std::make_pair(secondary_tr_param.first, secondary_tr_param.second));
            GFXRECON_ASSERT(new_entry.second);
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
