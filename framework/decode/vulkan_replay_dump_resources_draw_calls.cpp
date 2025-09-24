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
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>

#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DrawCallsDumpingContext::DrawCallsDumpingContext(const CommandIndices*          draw_indices,
                                                 const RenderPassIndices*       renderpass_indices,
                                                 const CommandImageSubresource& dc_subresources,
                                                 CommonObjectInfoTable&         object_info_table,
                                                 const VulkanReplayOptions&     options,
                                                 VulkanDumpResourcesDelegate&   delegate,
                                                 const util::Compressor*        compressor) :
    original_command_buffer_info_(nullptr),
    current_cb_index_(0), dc_subresources_(dc_subresources), active_renderpass_(nullptr),
    active_framebuffer_(nullptr), bound_gr_pipeline_{ nullptr }, current_renderpass_(0), current_subpass_(0),
    delegate_(delegate), options_(options), compressor_(compressor), current_render_pass_type_(kNone),
    aux_command_buffer_(VK_NULL_HANDLE), aux_fence_(VK_NULL_HANDLE),
    command_buffer_level_(DumpResourcesCommandBufferLevel::kPrimary), device_table_(nullptr), instance_table_(nullptr),
    object_info_table_(object_info_table), replay_device_phys_mem_props_(nullptr)
{
    if (draw_indices != nullptr)
    {
        const size_t n_cmd_buffs = options_.dump_resources_before ? 2 * draw_indices->size() : draw_indices->size();
        command_buffers_.resize(n_cmd_buffs, VK_NULL_HANDLE);

        dc_indices_ = *draw_indices;
    }

    if (renderpass_indices != nullptr)
    {
        const size_t n_render_passes = renderpass_indices->size();
        render_pass_dumped_descriptors_.resize(n_render_passes);

        RP_indices_ = *renderpass_indices;
    }
}

DrawCallsDumpingContext::~DrawCallsDumpingContext()
{
    Release();
}

void DrawCallsDumpingContext::Release()
{
    if (original_command_buffer_info_)
    {
        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);

        if (device_info == nullptr)
        {
            return;
        }

        VkDevice device = device_info->handle;
        assert(device_table_);

        const VulkanCommandPoolInfo* pool_info =
            object_info_table_.GetVkCommandPoolInfo(original_command_buffer_info_->pool_id);
        assert(pool_info);

        if (!command_buffers_.empty())
        {
            device_table_->FreeCommandBuffers(
                device, pool_info->handle, command_buffers_.size(), command_buffers_.data());
        }
        command_buffers_.clear();

        if (aux_command_buffer_ != VK_NULL_HANDLE)
        {
            device_table_->FreeCommandBuffers(device, pool_info->handle, 1, &aux_command_buffer_);
            aux_command_buffer_ = VK_NULL_HANDLE;
        }

        if (aux_fence_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyFence(device, aux_fence_, nullptr);
        }

        DestroyMutableResourceBackups();
        ReleaseIndirectParams();

        // cleanup cloned renderpasses
        for (auto& subpasses : render_pass_clones_)
        {
            for (VkRenderPass renderpass : subpasses)
            {
                if (renderpass != VK_NULL_HANDLE)
                {
                    device_table_->DestroyRenderPass(device, renderpass, nullptr);
                }
            }
        }

        original_command_buffer_info_ = nullptr;
    }

    draw_call_params_.clear();
    dc_indices_.clear();
    RP_indices_.clear();
    render_pass_dumped_descriptors_.clear();

    current_renderpass_ = 0;
    current_subpass_    = 0;
    current_cb_index_   = 0;
}

DrawCallsDumpingContext::DrawCallParams* DrawCallsDumpingContext::InsertNewDrawParameters(
    uint64_t index, uint32_t vertex_count, uint32_t instance_count, uint32_t first_vertex, uint32_t first_instance)
{
    auto [entry_it, success] = draw_call_params_.insert(
        { index,
          std::make_unique<DrawCallParams>(
              DrawCallType::kDraw, vertex_count, instance_count, first_vertex, first_instance) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

DrawCallsDumpingContext::DrawCallParams*
DrawCallsDumpingContext::InsertNewDrawIndexedParameters(uint64_t index,
                                                        uint32_t index_count,
                                                        uint32_t instance_count,
                                                        uint32_t first_index,
                                                        int32_t  vertexOffset,
                                                        uint32_t first_instance)
{
    auto [entry_it, success] = draw_call_params_.insert(
        { index,
          std::make_unique<DrawCallParams>(
              DrawCallType::kDrawIndexed, index_count, instance_count, first_index, vertexOffset, first_instance) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

DrawCallsDumpingContext::DrawCallParams* DrawCallsDumpingContext::InsertNewDrawIndirectParameters(
    uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride)
{
    auto [entry_it, success] = draw_call_params_.insert(
        { index,
          std::make_unique<DrawCallParams>(DrawCallType::kDrawIndirect, buffer_info, offset, draw_count, stride) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

DrawCallsDumpingContext::DrawCallParams* DrawCallsDumpingContext::InsertNewDrawIndexedIndirectParameters(
    uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, uint32_t draw_count, uint32_t stride)
{
    auto [entry_it, success] =
        draw_call_params_.insert({ index,
                                   std::make_unique<DrawCallParams>(
                                       DrawCallType::kDrawIndexedIndirect, buffer_info, offset, draw_count, stride) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

DrawCallsDumpingContext::DrawCallParams*
DrawCallsDumpingContext::InsertNewIndirectCountParameters(uint64_t                index,
                                                          const VulkanBufferInfo* buffer_info,
                                                          VkDeviceSize            offset,
                                                          const VulkanBufferInfo* count_buffer_info,
                                                          VkDeviceSize            count_buffer_offset,
                                                          uint32_t                max_draw_count,
                                                          uint32_t                stride,
                                                          DrawCallType            drawcall_type)
{
    GFXRECON_ASSERT(drawcall_type == kDrawIndirectCount || drawcall_type == kDrawIndirectCountKHR ||
                    drawcall_type == kDrawIndirectCountAMD);
    auto [entry_it, success] = draw_call_params_.insert(
        { index,
          std::make_unique<DrawCallParams>(
              drawcall_type, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

DrawCallsDumpingContext::DrawCallParams*
DrawCallsDumpingContext::InsertNewDrawIndexedIndirectCountParameters(uint64_t                index,
                                                                     const VulkanBufferInfo* buffer_info,
                                                                     VkDeviceSize            offset,
                                                                     const VulkanBufferInfo* count_buffer_info,
                                                                     VkDeviceSize            count_buffer_offset,
                                                                     uint32_t                max_draw_count,
                                                                     uint32_t                stride,
                                                                     DrawCallType            drawcall_type)
{
    GFXRECON_ASSERT(drawcall_type == kDrawIndexedIndirectCount || drawcall_type == kDrawIndexedIndirectCountKHR ||
                    drawcall_type == kDrawIndexedIndirectCountAMD);
    auto [entry_it, success] = draw_call_params_.insert(
        { index,
          std::make_unique<DrawCallParams>(
              drawcall_type, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride) });
    GFXRECON_ASSERT(success);
    SnapshotState(*entry_it->second);

    return entry_it->second.get();
}

VkResult DrawCallsDumpingContext::CopyDrawIndirectParameters(DrawCallParams& dc_params)
{
    GFXRECON_ASSERT(IsDrawCallIndirect(dc_params.type));

    if (IsDrawCallIndirectCount(dc_params.type))
    {
        DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
            dc_params.dc_params_union.draw_indirect_count;

        const uint32_t max_draw_count = ic_params.max_draw_count;

        // Not sure from spec if maxDrawCount can be zero. Assume it can
        if (!max_draw_count)
        {
            ic_params.actual_draw_count = 0;
            return VK_SUCCESS;
        }

        const VkDeviceSize draw_call_params_size =
            IsDrawCallIndexed(dc_params.type) ? sizeof(VkDrawIndexedIndirectCommand) : sizeof(VkDrawIndirectCommand);

        // Create a buffer to copy the parameters buffer
        const uint32_t     param_buffer_stride = max_draw_count > 1 ? ic_params.stride : draw_call_params_size;
        const VkDeviceSize param_buffer_offset = ic_params.params_buffer_offset;
        const VkDeviceSize copy_buffer_size    = draw_call_params_size * max_draw_count;

        ic_params.new_params_buffer_size = copy_buffer_size;

        VkResult res = CloneBuffer(object_info_table_,
                                   device_table_,
                                   replay_device_phys_mem_props_,
                                   ic_params.params_buffer_info,
                                   &ic_params.new_params_buffer,
                                   &ic_params.new_params_memory,
                                   copy_buffer_size);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed cloning vk buffer (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Inject a cmdCopyBuffer to copy the draw params into the new buffer
        {
            std::vector<VkBufferCopy> regions(1);
            if (param_buffer_stride != draw_call_params_size)
            {
                // requires separate copies
                regions.resize(max_draw_count);

                VkDeviceSize src_offset = param_buffer_offset;
                VkDeviceSize dst_offset = 0;
                for (uint32_t i = 0; i < max_draw_count; ++i)
                {
                    regions[i].size = draw_call_params_size;

                    regions[i].srcOffset = src_offset;
                    src_offset += param_buffer_stride;

                    regions[i].dstOffset = dst_offset;
                    dst_offset += draw_call_params_size;
                }
            }
            else
            {
                regions[0].size      = copy_buffer_size;
                regions[0].srcOffset = param_buffer_offset;
                regions[0].dstOffset = 0;
            }

            VkCommandBuffer cmd_buf = command_buffers_[current_cb_index_];
            device_table_->CmdCopyBuffer(cmd_buf,
                                         ic_params.params_buffer_info->handle,
                                         ic_params.new_params_buffer,
                                         regions.size(),
                                         regions.data());

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = ic_params.new_params_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = copy_buffer_size;
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

        // Create a buffer to copy the draw count parameter
        const VkDeviceSize count_buffer_size = sizeof(uint32_t);
        assert(count_buffer_size <= ic_params.count_buffer_info->size);
        res = CloneBuffer(object_info_table_,
                          device_table_,
                          replay_device_phys_mem_props_,
                          ic_params.count_buffer_info,
                          &ic_params.new_count_buffer,
                          &ic_params.new_count_memory,
                          count_buffer_size);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed cloning vk buffer (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Inject a cmdCopyBuffer to copy the count into the new buffer
        {
            VkBufferCopy region;
            region.size      = count_buffer_size;
            region.srcOffset = ic_params.count_buffer_offset;
            region.dstOffset = 0;

            VkCommandBuffer cmd_buf = command_buffers_[current_cb_index_];
            device_table_->CmdCopyBuffer(
                cmd_buf, ic_params.count_buffer_info->handle, ic_params.new_count_buffer, 1, &region);

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = ic_params.new_count_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = count_buffer_size;
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
    }
    else
    {
        DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params = dc_params.dc_params_union.draw_indirect;

        const uint32_t draw_count = i_params.draw_count;

        // According to spec drawCount can be zero. Nothing to do in this case
        if (!draw_count)
        {
            return VK_SUCCESS;
        }

        const VkDeviceSize draw_call_params_size =
            IsDrawCallIndexed(dc_params.type) ? sizeof(VkDrawIndexedIndirectCommand) : sizeof(VkDrawIndirectCommand);

        // Create a buffer to copy the parameters buffer
        const uint32_t     param_buffer_stride = draw_count > 1 ? i_params.stride : draw_call_params_size;
        const uint32_t     param_buffer_offset = i_params.params_buffer_offset;
        const VkDeviceSize copy_buffer_size    = draw_call_params_size * draw_count;

        i_params.new_params_buffer_size = copy_buffer_size;

        VkResult res = CloneBuffer(object_info_table_,
                                   device_table_,
                                   replay_device_phys_mem_props_,
                                   i_params.params_buffer_info,
                                   &i_params.new_params_buffer,
                                   &i_params.new_params_memory,
                                   copy_buffer_size);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed cloning vk buffer (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Inject a cmdCopyBuffer to copy the draw params into the new buffer
        {
            std::vector<VkBufferCopy> regions(1);
            if (param_buffer_stride != draw_call_params_size)
            {
                // requires separate copies
                regions.resize(draw_count);

                VkDeviceSize src_offset = param_buffer_offset;
                VkDeviceSize dst_offset = 0;
                for (uint32_t i = 0; i < draw_count; ++i)
                {
                    regions[i].size = draw_call_params_size;

                    regions[i].srcOffset = src_offset;
                    src_offset += param_buffer_stride;

                    regions[i].dstOffset = dst_offset;
                    dst_offset += draw_call_params_size;
                }
            }
            else
            {
                regions[0].size      = copy_buffer_size;
                regions[0].srcOffset = i_params.params_buffer_offset;
                regions[0].dstOffset = 0;
            }

            VkCommandBuffer cmd_buf = command_buffers_[current_cb_index_];
            device_table_->CmdCopyBuffer(cmd_buf,
                                         i_params.params_buffer_info->handle,
                                         i_params.new_params_buffer,
                                         regions.size(),
                                         regions.data());

            VkBufferMemoryBarrier buf_barrier;
            buf_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buf_barrier.pNext               = nullptr;
            buf_barrier.buffer              = i_params.new_params_buffer;
            buf_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
            buf_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            buf_barrier.size                = copy_buffer_size;
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
    }

    return VK_SUCCESS;
}

static void SnapshotBoundDescriptors(DrawCallsDumpingContext::DrawCallParams& dc_params,
                                     const VulkanPipelineInfo*                bound_pipeline,
                                     const BoundDescriptorSets&               bound_descriptor_sets)
{
    if (dc_params.updated_referenced_descriptors || bound_descriptor_sets.empty() || bound_pipeline == nullptr)
    {
        return;
    }

    // Copy all bound descriptors that are compatible with the current pipeline layout
    for (const auto& [desc_set_index, set_info] : bound_descriptor_sets)
    {
        // Check against pipeline layout
        if (bound_pipeline->desc_set_layouts.size() <= desc_set_index)
        {
            continue;
        }

        for (const auto& [desc_binding_index, binding_info] : set_info)
        {
            // Check against pipeline layout
            const auto layout_entry = bound_pipeline->desc_set_layouts[desc_set_index].find(desc_binding_index);

            if (layout_entry == bound_pipeline->desc_set_layouts[desc_set_index].end() ||
                !(bound_pipeline->shader_stages & binding_info.stage_flags))
            {
                continue;
            }

            dc_params.referenced_descriptors[desc_set_index][desc_binding_index].desc_type = binding_info.desc_type;
            dc_params.referenced_descriptors[desc_set_index][desc_binding_index].stage_flags =
                (bound_pipeline->shader_stages & binding_info.stage_flags);

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

                        dc_params.referenced_descriptors[desc_set_index][desc_binding_index].image_info[array_idx] =
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

                        dc_params.referenced_descriptors[desc_set_index][desc_binding_index]
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

                        dc_params.referenced_descriptors[desc_set_index][desc_binding_index].buffer_info[array_idx] =
                            buf_info;
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                {
                    dc_params.referenced_descriptors[desc_set_index][desc_binding_index].inline_uniform_block =
                        binding_info.inline_uniform_block;
                }
                break;

                default:
                    break;
            }
        }
    }
}

static void CopyVertexInputStateInfo(DrawCallsDumpingContext::DrawCallParams&               dc_params,
                                     const VulkanPipelineInfo*                              bound_pipeline,
                                     const DrawCallsDumpingContext::VertexInputState&       dynamic_vertex_input_state,
                                     const DrawCallsDumpingContext::BoundVertexBuffersInfo& bound_vertex_buffers,
                                     const DrawCallsDumpingContext::BoundIndexBuffer&       bound_index_buffer)
{
    // params for this draw call are already updated or there's nothing to update
    if ((dc_params.updated_bound_vertex_buffers && dc_params.updated_bound_index_buffer) ||
        (bound_vertex_buffers.bound_vertex_buffer_per_binding.empty() && bound_index_buffer.buffer_info == nullptr))
    {
        return;
    }

    // Pipeline has no vertex binding and/or attribute information.
    // This can be a case of shader generated vertices, or vertex buffer is bound as a UBO
    if (bound_pipeline != nullptr &&
        (bound_pipeline->vertex_input_attribute_map.empty() && bound_pipeline->vertex_input_attribute_map.empty()) &&
        (!bound_pipeline->dynamic_vertex_input && !bound_pipeline->dynamic_vertex_binding_stride))
    {
        return;
    }

    // If VK_DYNAMIC_STATE_VERTEX_INPUT_EXT is enabled then get all vertex input state from
    // vkCmdSetVertexInputEXT
    if (bound_pipeline == nullptr || bound_pipeline->dynamic_vertex_input)
    {
        dc_params.vertex_input_state = dynamic_vertex_input_state;
    }
    else
    {
        if (bound_pipeline)
        {
            // Copy vertex input binding state
            dc_params.vertex_input_state.vertex_input_binding_map = bound_pipeline->vertex_input_binding_map;

            // If VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT is enabled, ignore strides from
            // pipeline and get them from vkCmdBindVertexBuffers2EXT instead
            if (bound_pipeline->dynamic_vertex_binding_stride)
            {
                for (auto& vb_binding : dc_params.vertex_input_state.vertex_input_binding_map)
                {
                    const uint32_t binding = vb_binding.first;
                    if (dynamic_vertex_input_state.vertex_input_binding_map.find(binding) !=
                        dynamic_vertex_input_state.vertex_input_binding_map.end())
                    {
                        const auto& binding_entry = dynamic_vertex_input_state.vertex_input_binding_map.find(binding);
                        if (binding_entry != dynamic_vertex_input_state.vertex_input_binding_map.end())
                        {
                            vb_binding.second.stride = binding_entry->second.stride;
                        }
                    }
                }
            }

            // Copy vertex attributes info
            dc_params.vertex_input_state.vertex_input_attribute_map = bound_pipeline->vertex_input_attribute_map;
        }
    }

    // Keep a copy of the bound vertex buffers information
    dc_params.referenced_vertex_buffers    = bound_vertex_buffers;
    dc_params.updated_bound_vertex_buffers = !bound_vertex_buffers.bound_vertex_buffer_per_binding.empty();

    if (DrawCallsDumpingContext::IsDrawCallIndexed(dc_params.type))
    {
        dc_params.referenced_index_buffer    = bound_index_buffer;
        dc_params.updated_bound_index_buffer = (bound_index_buffer.buffer_info != nullptr);
    }
}

void DrawCallsDumpingContext::SnapshotState(DrawCallParams& dc_params)
{
    gfxrecon::decode::SnapshotBoundDescriptors(dc_params, bound_gr_pipeline_, bound_descriptor_sets_gr_);

    // Copy vertex input information
    CopyVertexInputStateInfo(
        dc_params, bound_gr_pipeline_, dynamic_vertex_input_state_, bound_vertex_buffers_, bound_index_buffer_);

    // NOTE: for indirect draws, we defer copying the indirect command-buffer until FinalizeCommandBuffer
}

void DrawCallsDumpingContext::FinalizeCommandBuffer(DrawCallsDumpingContext::DrawCallParams* dc_params)
{
    assert((current_render_pass_type_ == kRenderPass || current_render_pass_type_ == kDynamicRendering) ||
           command_buffer_level_ == DumpResourcesCommandBufferLevel::kSecondary);
    assert(current_cb_index_ < command_buffers_.size());
    assert(device_table_ != nullptr);

    VkCommandBuffer current_command_buffer = command_buffers_[current_cb_index_];

    if (command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary)
    {
        GFXRECON_ASSERT(!RP_indices_.empty());

        if (current_render_pass_type_ == kRenderPass)
        {
            device_table_->CmdEndRenderPass(current_command_buffer);
        }
        else
        {
            device_table_->CmdEndRenderingKHR(current_command_buffer);

            // Transition render targets into TRANSFER_SRC_OPTIMAL
            assert(current_renderpass_ == render_targets_.size() - 1);
            assert(render_targets_[current_renderpass_].size() == 1);
            for (auto& rt : render_targets_[current_renderpass_])
            {
                for (auto& cat : rt.color_att_imgs)
                {
                    if (cat->intermediate_layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
                    {
                        VkImageMemoryBarrier barrier;
                        barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                        barrier.pNext               = nullptr;
                        barrier.srcAccessMask       = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
                        barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
                        barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
                        barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
                        barrier.oldLayout           = cat->intermediate_layout;
                        barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                        barrier.image               = cat->handle;
                        barrier.subresourceRange    = { graphics::GetFormatAspects(cat->format),
                                                        0,
                                                        VK_REMAINING_MIP_LEVELS,
                                                        0,
                                                        VK_REMAINING_ARRAY_LAYERS };

                        device_table_->CmdPipelineBarrier(current_command_buffer,
                                                          VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                          0,
                                                          0,
                                                          nullptr,
                                                          0,
                                                          nullptr,
                                                          1,
                                                          &barrier);

                        cat->intermediate_layout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                    }
                }
            }
        }
    }

    // Copy indirect draw params.
    // In case --dump-resources-before-draw is set, since each dc_params (each entry in draw_call_params_) represents
    // both "before" and "after" case, we should do this only once. For the "before" commands dc_params in
    // FinalizeCommandBuffer() will be null so we distinquish between "befre" and "after" and call
    // CopyDrawIndirectParameters() just once.
    if (dc_params != nullptr && IsDrawCallIndirect(dc_params->type))
    {
        CopyDrawIndirectParameters(*dc_params);
    }

    device_table_->EndCommandBuffer(current_command_buffer);

    // Increment index of command buffer that is going to be finalized next
    ++current_cb_index_;
}

bool DrawCallsDumpingContext::MustDumpDrawCall(uint64_t index) const
{
    // Indices should be sorted
    if (std::find(dc_indices_.begin(), dc_indices_.end(), index) == dc_indices_.end())
    {
        return false;
    }

    for (size_t i = options_.dump_resources_before ? current_cb_index_ / 2 : current_cb_index_; i < dc_indices_.size();
         ++i)
    {
        if (index == dc_indices_[i])
        {
            return true;
        }
    }

    return false;
}

bool DrawCallsDumpingContext::ShouldHandleRenderPass(uint64_t index) const
{
    for (const auto& rp : RP_indices_)
    {
        if (IsInsideRange(rp, index))
        {
            return true;
        }
    }

    return false;
}

bool DrawCallsDumpingContext::ShouldHandleExecuteCommands(uint64_t index) const
{
    return secondaries_.find(index) != secondaries_.end();
}

VkResult DrawCallsDumpingContext::DumpDrawCalls(
    VkQueue queue, uint64_t qs_index, uint64_t bcb_index, const VkSubmitInfo& submit_info, VkFence fence)
{
    const size_t n_drawcalls = command_buffers_.size();

    // Dump render targets
    for (size_t cb = 0; cb < n_drawcalls; ++cb)
    {
        VkSubmitInfo si;
        si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        si.pNext                = nullptr;
        si.waitSemaphoreCount   = !cb ? submit_info.waitSemaphoreCount : 0;
        si.pWaitSemaphores      = !cb ? submit_info.pWaitSemaphores : nullptr;
        si.pWaitDstStageMask    = !cb ? submit_info.pWaitDstStageMask : nullptr;
        si.commandBufferCount   = 1;
        si.pCommandBuffers      = &command_buffers_[cb];
        si.signalSemaphoreCount = (cb == (n_drawcalls - 1)) ? submit_info.signalSemaphoreCount : 0;
        si.pSignalSemaphores    = (cb == (n_drawcalls - 1)) ? submit_info.pSignalSemaphores : nullptr;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        assert(device_info);

        const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
        VkFence                 submission_fence;
        if (fence == VK_NULL_HANDLE)
        {
            VkResult res = device_table_->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
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

        VkResult res = device_table_->QueueSubmit(queue, 1, &si, submission_fence);
        if (res != VK_SUCCESS)
        {
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

        const size_t                dc_index = dc_indices_[CmdBufToDCVectorIndex(cb)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              sp       = RP_index.second;
        const uint64_t              rp       = RP_index.first;

        // Some things need to be dumped once. It shouldn't matter if this is for the "before" or "after" command buffer
        // but we need to distinguish between the two in order to make sure we make each thing once.
        const bool is_before_command = !options_.dump_resources_before || options_.dump_resources_before && !(cb % 2);

        // Fetch draw params for all Indirect and IndirectCount draw calls from the buffers into the DrawCallParams.
        if (is_before_command)
        {
            res = FetchDrawIndirectParams(dc_index);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Fetching indirect draw parameters failed (%s).",
                                   util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        // Dump vertex/index buffers
        if (options_.dump_resources_dump_vertex_index_buffer && is_before_command)
        {
            res = DumpVertexIndexBuffers(qs_index, bcb_index, dc_index);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping vertex/index buffers failed (%s)", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        // Dump render targets
        res = DumpRenderTargetAttachments(cb, rp, sp, qs_index, bcb_index);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Dumping render target attachments failed (%s)", util::ToString<VkResult>(res).c_str())
            return res;
        }

        // Dump immutable resources
        if (options_.dump_resources_dump_immutable_resources && is_before_command)
        {
            res = DumpDescriptors(qs_index, bcb_index, dc_index, rp);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Dumping immutable resources failed (%s)", util::ToString<VkResult>(res).c_str())
                return res;
            }
        }

        if (!options_.dump_resources_before || options_.dump_resources_before && (cb % 2))
        {
            const auto& dc_param_entry = draw_call_params_.find(dc_index);
            GFXRECON_ASSERT(dc_param_entry != draw_call_params_.end());
            const auto& dc_entry = dc_param_entry->second.get();

            const VulkanDelegateDumpDrawCallContext draw_call_info{
                DumpResourcesCommandType::kGraphics, instance_table_, device_table_, dc_entry
            };

            delegate_.DumpDrawCallInfo(draw_call_info);
        }

        res = RevertRenderTargetImageLayouts(queue, cb);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reverting render target attachments layouts failed(%s)",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }
    }

    // Clean up some state in case this command buffer is submitted again
    ResetFetchedIndirectParams();
    for (auto& rpc : render_pass_dumped_descriptors_)
    {
        rpc.image_descriptors.clear();
        rpc.buffer_descriptors.clear();
    }

    GFXRECON_LOG_INFO("Done.")

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::RevertRenderTargetImageLayouts(VkQueue queue, uint64_t cmd_buf_index)
{
    const size_t                dc_index = dc_indices_[CmdBufToDCVectorIndex(cmd_buf_index)];
    const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
    const uint64_t              rp       = RP_index.first;
    const uint64_t              sp       = RP_index.second;

    if (render_targets_[rp][sp].color_att_imgs.empty() && render_targets_[rp][sp].depth_att_img == nullptr)
    {
        return VK_SUCCESS;
    }

    const auto entry = dynamic_rendering_attachment_layouts_.find(rp);
    assert(entry != dynamic_rendering_attachment_layouts_.end());

    if (!entry->second.is_dynamic)
    {
        return VK_SUCCESS;
    }

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    VkResult                       res = device_table_->BeginCommandBuffer(aux_command_buffer_, &bi);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "(%s:%u) BeginCommandBuffer failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    std::vector<VkImageMemoryBarrier> img_barriers;

    VkImageMemoryBarrier img_barrier;
    img_barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    img_barrier.pNext               = nullptr;
    img_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    img_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    img_barrier.oldLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.subresourceRange    = {
           VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
    };

    for (size_t i = 0; i < render_targets_[rp][sp].color_att_imgs.size(); ++i)
    {
        if (options_.dump_resources_color_attachment_index != kUnspecifiedColorAttachment &&
            static_cast<size_t>(options_.dump_resources_color_attachment_index) != i)
        {
            continue;
        }

        VulkanImageInfo* image_info = render_targets_[rp][sp].color_att_imgs[i];

        img_barrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        img_barrier.newLayout     = entry->second.color_attachment_layouts[i];
        img_barrier.image         = image_info->handle;
        img_barriers.push_back(img_barrier);

        image_info->intermediate_layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }

    if (options_.dump_resources_dump_depth && render_targets_[rp][sp].depth_att_img != nullptr)
    {
        VulkanImageInfo* image_info = render_targets_[rp][sp].depth_att_img;

        img_barrier.subresourceRange.aspectMask = graphics::GetFormatAspects(image_info->format);

        img_barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        img_barrier.newLayout     = entry->second.depth_attachment_layout;
        img_barrier.image         = image_info->handle;
        img_barriers.push_back(img_barrier);

        image_info->intermediate_layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }

    if (!img_barriers.empty())
    {
        device_table_->CmdPipelineBarrier(aux_command_buffer_,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          img_barriers.size(),
                                          img_barriers.data());

        res = device_table_->EndCommandBuffer(aux_command_buffer_);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) EndCommandBuffer failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        VkSubmitInfo si;
        si.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        si.pNext                = nullptr;
        si.waitSemaphoreCount   = 0;
        si.pWaitSemaphores      = nullptr;
        si.pWaitDstStageMask    = nullptr;
        si.commandBufferCount   = 1;
        si.pCommandBuffers      = &aux_command_buffer_;
        si.signalSemaphoreCount = 0;
        si.pSignalSemaphores    = nullptr;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        assert(device_info);

        res = device_table_->ResetFences(device_info->handle, 1, &aux_fence_);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) EndCommandBuffer failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        res = device_table_->QueueSubmit(queue, 1, &si, aux_fence_);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = device_table_->WaitForFences(device_info->handle, 1, &aux_fence_, VK_TRUE, ~0UL);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) WaitForFences failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::DumpRenderTargetAttachments(
    uint64_t cmd_buf_index, uint64_t rp, uint64_t sp, uint64_t qs_index, uint64_t bcb_index)
{
    assert(device_table_ != nullptr);

    const size_t dc_index = dc_indices_[CmdBufToDCVectorIndex(cmd_buf_index)];

    if (render_targets_[rp][sp].color_att_imgs.empty() && render_targets_[rp][sp].depth_att_img == nullptr)
    {
        return VK_SUCCESS;
    }

    auto            dc_params_entry = draw_call_params_.find(dc_index);
    DrawCallParams& dc_params       = *dc_params_entry->second;

    dc_params.dumped_resources.bcb_index = bcb_index;
    dc_params.dumped_resources.cmd_index = dc_index;
    dc_params.dumped_resources.qs_index  = qs_index;

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    auto&      dumped_rts                = dc_params.dumped_resources.dumped_render_targets;
    const bool before_command            = options_.dump_resources_before && !(cmd_buf_index % 2);
    const bool insert_new_resource_entry = before_command || !options_.dump_resources_before;
    const bool has_depth                 = render_targets_[rp][sp].depth_att_img != nullptr;

    const VulkanDelegateDumpResourceContext res_info_base(instance_table_, device_table_, compressor_, before_command);

    // Dump color attachments
    for (size_t i = 0; i < render_targets_[rp][sp].color_att_imgs.size(); ++i)
    {
        if (options_.dump_resources_color_attachment_index != kUnspecifiedColorAttachment &&
            static_cast<size_t>(options_.dump_resources_color_attachment_index) != i)
        {
            continue;
        }

        const VulkanImageInfo* image_info     = render_targets_[rp][sp].color_att_imgs[i];
        const ImageDumpResult  can_dump_image = CanDumpImage(instance_table_, device_info->parent, image_info);
        auto&                  dumped_rt = insert_new_resource_entry ? dumped_rts.emplace_back(DumpResourceType::kRtv,
                                                                              bcb_index,
                                                                              dc_index,
                                                                              qs_index,
                                                                              rp,
                                                                              sp,
                                                                              static_cast<uint32_t>(i),
                                                                              before_command,
                                                                              image_info,
                                                                              can_dump_image)
                                                                     : *(dumped_rts.begin() + i);
        if (can_dump_image != ImageDumpResult::kCanDump)
        {
            continue;
        }

        VulkanDelegateDumpResourceContext res_info = res_info_base;
        res_info.dumped_resource                   = &dumped_rt;
        res_info.dumped_data                       = VulkanDelegateImageDumpedData();
        auto& dumped_image_data                    = std::get<VulkanDelegateImageDumpedData>(res_info.dumped_data);

        const VkImageSubresourceRange subresource_range = {
            graphics::GetFormatAspects(image_info->format),
            0,
            options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_MIP_LEVELS : 1,
            0,
            options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_ARRAY_LAYERS : 1
        };
        VkResult res = DumpImage(before_command ? dumped_rt.dumped_image_before : dumped_rt.dumped_image,
                                 VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                 options_.dump_resources_scale,
                                 options_.dump_resources_dump_raw_images,
                                 subresource_range,
                                 dumped_image_data.data,
                                 device_info,
                                 device_table_,
                                 instance_table_,
                                 object_info_table_);
        if (res == VK_SUCCESS)
        {
            delegate_.DumpResource(res_info);
        }
        else
        {
            dumped_rts.pop_back();

            if (res == VK_ERROR_FEATURE_NOT_PRESENT)
            {
                // Failures to dump images due to multisampling should be ok
                GFXRECON_LOG_WARNING("Image %" PRIu64 " could not be resolved (%s)",
                                     image_info->capture_id,
                                     util::ToString<VkFormat>(image_info->format).c_str())
            }
            else
            {
                GFXRECON_LOG_ERROR("Reading from render target image %" PRIu64 " failed (%s)",
                                   image_info->capture_id,
                                   util::ToString(res).c_str());

                return res;
            }
        }
    }

    // Dump depth attachment
    if (has_depth && options_.dump_resources_dump_depth)
    {
        const VulkanImageInfo* image_info = render_targets_[rp][sp].depth_att_img;

        const ImageDumpResult can_dump_image = CanDumpImage(instance_table_, device_info->parent, image_info);
        // The "before" depth target will be at the back() of the vector
        GFXRECON_ASSERT(image_info != nullptr);
        auto& dumped_rt = insert_new_resource_entry ? dumped_rts.emplace_back(DumpResourceType::kDsv,
                                                                              bcb_index,
                                                                              dc_index,
                                                                              qs_index,
                                                                              rp,
                                                                              sp,
                                                                              DEPTH_ATTACHMENT,
                                                                              before_command,
                                                                              image_info,
                                                                              can_dump_image)
                                                    : dumped_rts.back();

        if (can_dump_image == ImageDumpResult::kCanDump)
        {
            VulkanDelegateDumpResourceContext res_info = res_info_base;
            res_info.dumped_resource                   = &dumped_rt;
            res_info.dumped_data                       = VulkanDelegateImageDumpedData();
            auto& dumped_image_data                    = std::get<VulkanDelegateImageDumpedData>(res_info.dumped_data);

            const VkImageSubresourceRange subresource_range = {
                graphics::GetFormatAspects(image_info->format),
                0,
                options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_MIP_LEVELS : 1,
                0,
                options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_ARRAY_LAYERS : 1
            };
            VkResult res = DumpImage(before_command ? dumped_rt.dumped_image_before : dumped_rt.dumped_image,
                                     VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                     options_.dump_resources_scale,
                                     options_.dump_resources_dump_raw_images,
                                     subresource_range,
                                     dumped_image_data.data,
                                     device_info,
                                     device_table_,
                                     instance_table_,
                                     object_info_table_);

            if (res == VK_SUCCESS)
            {
                delegate_.DumpResource(res_info);
            }
            else
            {
                dumped_rts.pop_back();

                if (res == VK_ERROR_FEATURE_NOT_PRESENT)
                {
                    // Failures to dump images due to multisampling should be ok
                    GFXRECON_LOG_WARNING("Image %" PRIu64 " could not be resolved (%s)",
                                         image_info->capture_id,
                                         util::ToString<VkFormat>(image_info->format).c_str())
                }
                else
                {
                    GFXRECON_LOG_ERROR("Reading from depth render target image %" PRIu64 " failed (%s)",
                                       image_info->capture_id,
                                       util::ToString(res).c_str());

                    return res;
                }
            }
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::DumpDescriptors(uint64_t qs_index, uint64_t bcb_index, uint64_t dc_index, uint64_t rp)
{
    assert(rp < render_pass_dumped_descriptors_.size());
    assert(draw_call_params_.find(dc_index) != draw_call_params_.end());

    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    assert(device_info);

    const VulkanDelegateDumpResourceContext res_info_base(instance_table_, device_table_, compressor_);

    CommandImageSubresourceIterator cmd_subresources_entry;
    cmd_subresources_entry    = dc_subresources_.find(dc_index);
    const bool cull_resources = cmd_subresources_entry != dc_subresources_.end();

    auto dc_param_entry = draw_call_params_.find(dc_index);
    GFXRECON_ASSERT(dc_param_entry != draw_call_params_.end());

    DrawCallParams& dc_params = *dc_param_entry->second;
    for (const auto& [desc_set_index, desc_set] : dc_params.referenced_descriptors)
    {
        for (const auto& [desc_binding_index, desc_binding] : desc_set)
        {
            switch (desc_binding.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    for (const auto& [array_index, img_desc_info] : desc_binding.image_info)
                    {
                        if (img_desc_info.image_view_info != nullptr)
                        {
                            const VulkanImageInfo* image_info =
                                object_info_table_.GetVkImageInfo(img_desc_info.image_view_info->image_id);

                            if (image_info == nullptr)
                            {
                                continue;
                            }

                            // Cull dumped descriptors
                            VkImageSubresourceRange subresource_range = {
                                graphics::GetFormatAspects(image_info->format),
                                0,
                                options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_MIP_LEVELS : 1,
                                0,
                                options_.dump_resources_dump_all_image_subresources ? VK_REMAINING_ARRAY_LAYERS : 1
                            };
                            if (cull_resources && CullDescriptor(cmd_subresources_entry,
                                                                 desc_set_index,
                                                                 desc_binding_index,
                                                                 array_index,
                                                                 &subresource_range))
                            {
                                continue;
                            }

                            const ImageDumpResult can_dump_image =
                                CanDumpImage(instance_table_, device_info->parent, image_info);

                            auto& new_dumped_desc = dc_params.dumped_resources.dumped_descriptors.emplace_back(
                                DumpResourceType::kImageDescriptor,
                                bcb_index,
                                dc_index,
                                qs_index,
                                rp,
                                static_cast<uint64_t>(current_subpass_),
                                desc_binding.stage_flags,
                                desc_binding.desc_type,
                                desc_set_index,
                                desc_binding_index,
                                array_index,
                                image_info,
                                can_dump_image,
                                DumpResourcesCommandType::kGraphics);

                            if (can_dump_image != ImageDumpResult::kCanDump)
                            {
                                continue;
                            }

                            auto&      new_dumped_image = std::get<DumpedImage>(new_dumped_desc.dumped_resource);
                            const auto dumped_desc_entry =
                                render_pass_dumped_descriptors_[rp].image_descriptors.find(image_info);
                            if (dumped_desc_entry == render_pass_dumped_descriptors_[rp].image_descriptors.end())
                            {
                                VulkanDelegateDumpResourceContext res_info = res_info_base;
                                res_info.dumped_resource                   = &new_dumped_desc;
                                res_info.dumped_data                       = VulkanDelegateImageDumpedData();
                                auto& image_raw_data = std::get<VulkanDelegateImageDumpedData>(res_info.dumped_data);

                                VkResult res = DumpImage(new_dumped_image,
                                                         VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                         options_.dump_resources_scale,
                                                         options_.dump_resources_dump_raw_images,
                                                         subresource_range,
                                                         image_raw_data.data,
                                                         device_info,
                                                         device_table_,
                                                         instance_table_,
                                                         object_info_table_);
                                if (res != VK_SUCCESS)
                                {
                                    dc_params.dumped_resources.dumped_descriptors.pop_back();

                                    if (res == VK_ERROR_FEATURE_NOT_PRESENT)
                                    {
                                        // Failures to dump images due to multisampling should be ok
                                        GFXRECON_LOG_WARNING("Image %" PRIu64 " could not be resolved (%s)",
                                                             image_info->capture_id,
                                                             util::ToString<VkFormat>(image_info->format).c_str())

                                        return VK_SUCCESS;
                                    }
                                    else
                                    {
                                        GFXRECON_LOG_ERROR("Reading from image %" PRIu64 " failed (%s)",
                                                           image_info->capture_id,
                                                           util::ToString(res).c_str());

                                        return res;
                                    }
                                }

                                delegate_.DumpResource(res_info);

                                render_pass_dumped_descriptors_[rp].image_descriptors.emplace(image_info,
                                                                                              new_dumped_image);
                            }
                            else
                            {
                                new_dumped_image.CopyDumpedInfo(dumped_desc_entry->second);
                            }
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    for (const auto& [array_index, buf_desc_info] : desc_binding.texel_buffer_view_info)
                    {
                        const VulkanBufferInfo* buffer_info =
                            object_info_table_.GetVkBufferInfo(buf_desc_info->buffer_id);

                        if (buffer_info == nullptr)
                        {
                            continue;
                        }

                        // Cull dumped descriptors
                        if (cull_resources &&
                            CullDescriptor(cmd_subresources_entry, desc_set_index, desc_binding_index, array_index))
                        {
                            continue;
                        }

                        const VkDeviceSize offset = buf_desc_info->offset;
                        const VkDeviceSize range  = buf_desc_info->range;
                        const VkDeviceSize size   = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

                        auto& new_dumped_desc = dc_params.dumped_resources.dumped_descriptors.emplace_back(
                            DumpResourceType::kBufferDescriptor,
                            bcb_index,
                            dc_index,
                            qs_index,
                            rp,
                            static_cast<uint64_t>(current_subpass_),
                            desc_binding.stage_flags,
                            desc_binding.desc_type,
                            desc_set_index,
                            desc_binding_index,
                            array_index,
                            buffer_info,
                            offset,
                            size,
                            DumpResourcesCommandType::kGraphics);

                        const auto& dumped_desc_entry =
                            render_pass_dumped_descriptors_[rp].buffer_descriptors.find(buffer_info);
                        if (dumped_desc_entry == render_pass_dumped_descriptors_[rp].buffer_descriptors.end())
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

                                dc_params.dumped_resources.dumped_descriptors.pop_back();

                                return res;
                            }

                            delegate_.DumpResource(res_info);

                            render_pass_dumped_descriptors_[rp].buffer_descriptors.emplace(buffer_info,
                                                                                           new_dumped_buffer);
                        }
                        else
                        {
                            auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                            new_dumped_buffer.CopyDumpedInfo(dumped_desc_entry->second);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    for (const auto& [array_index, buf_desc_info] : desc_binding.buffer_info)
                    {
                        const VulkanBufferInfo* buffer_info = buf_desc_info.buffer_info;
                        if (buffer_info == nullptr)
                        {
                            continue;
                        }

                        // Cull dumped descriptors
                        if (cull_resources &&
                            CullDescriptor(cmd_subresources_entry, desc_set_index, desc_binding_index, array_index))
                        {
                            continue;
                        }

                        const VkDeviceSize offset = buf_desc_info.offset;
                        const VkDeviceSize range  = buf_desc_info.range;
                        const VkDeviceSize size   = range == VK_WHOLE_SIZE ? buffer_info->size - offset : range;

                        auto& new_dumped_desc = dc_params.dumped_resources.dumped_descriptors.emplace_back(
                            DumpResourceType::kBufferDescriptor,
                            bcb_index,
                            dc_index,
                            qs_index,
                            rp,
                            static_cast<uint64_t>(current_subpass_),
                            desc_binding.stage_flags,
                            desc_binding.desc_type,
                            desc_set_index,
                            desc_binding_index,
                            array_index,
                            buffer_info,
                            offset,
                            size,
                            DumpResourcesCommandType::kGraphics);

                        const auto& dumped_desc_entry =
                            render_pass_dumped_descriptors_[rp].buffer_descriptors.find(buffer_info);
                        if (dumped_desc_entry == render_pass_dumped_descriptors_[rp].buffer_descriptors.end())
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

                                dc_params.dumped_resources.dumped_descriptors.pop_back();

                                return res;
                            }

                            delegate_.DumpResource(res_info);

                            render_pass_dumped_descriptors_[rp].buffer_descriptors.emplace(buffer_info,
                                                                                           new_dumped_buffer);
                        }
                        else
                        {
                            auto& new_dumped_buffer = std::get<DumpedBuffer>(new_dumped_desc.dumped_resource);
                            new_dumped_buffer.CopyDumpedInfo(dumped_desc_entry->second);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                {
                    // Cull dumped descriptors
                    if (cull_resources && CullDescriptor(cmd_subresources_entry, desc_set_index, desc_binding_index, 0))
                    {
                        continue;
                    }

                    auto& new_dumped_desc = dc_params.dumped_resources.dumped_descriptors.emplace_back(
                        DumpResourceType::kInlineUniformBufferDescriptor,
                        bcb_index,
                        dc_index,
                        qs_index,
                        rp,
                        static_cast<uint64_t>(current_subpass_),
                        desc_binding.stage_flags,
                        desc_binding.desc_type,
                        desc_set_index,
                        desc_binding_index,
                        DumpResourcesCommandType::kGraphics);

                    VulkanDelegateDumpResourceContext res_info = res_info_base;
                    res_info.dumped_resource                   = &new_dumped_desc;
                    res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
                    auto& dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);
                    dumped_buffer_data.data  = desc_binding.inline_uniform_block;
                    delegate_.DumpResource(res_info);
                }
                break;

                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                case VK_DESCRIPTOR_TYPE_SAMPLER:
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(desc_binding.desc_type).c_str());
                    break;
            }
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::FetchDrawIndirectParams(uint64_t dc_index)
{
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
                                                *device_table_,
                                                *instance_table_,
                                                *phys_dev_info->replay_device_info->memory_properties);

    auto dc_param_entry = draw_call_params_.find(dc_index);
    assert(dc_param_entry != draw_call_params_.end());

    DrawCallParams& dc_params = *dc_param_entry->second;
    if (!IsDrawCallIndirect(dc_params.type))
    {
        return VK_SUCCESS;
    }

    if (IsDrawCallIndirectCount(dc_params.type))
    {
        DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
            dc_params.dc_params_union.draw_indirect_count;

        if (!ic_params.max_draw_count)
        {
            return VK_SUCCESS;
        }

        // Fetch draw count buffer
        std::vector<uint8_t> data;
        VkResult             res = resource_util.ReadFromBufferResource(
            ic_params.new_count_buffer, sizeof(uint32_t), 0, transfer_queue_index, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(data.size() == sizeof(uint32_t));
        assert(ic_params.actual_draw_count == std::numeric_limits<uint32_t>::max());
        util::platform::MemoryCopy(&ic_params.actual_draw_count, sizeof(uint32_t), data.data(), data.size());
        assert(ic_params.actual_draw_count != std::numeric_limits<uint32_t>::max());

        if (!ic_params.actual_draw_count)
        {
            return VK_SUCCESS;
        }

        const uint32_t actual_draw_count = ic_params.actual_draw_count;

        VkDeviceSize params_actual_size;
        if (IsDrawCallIndexed(dc_params.type))
        {
            assert(ic_params.draw_indexed_params == nullptr);
            ic_params.draw_indexed_params = new VkDrawIndexedIndirectCommand[actual_draw_count];
            if (ic_params.draw_indexed_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            // Now we know the exact draw count. We can fetch the exact draw params instead of the whole buffer
            params_actual_size = sizeof(VkDrawIndexedIndirectCommand) * actual_draw_count;
        }
        else
        {
            assert(ic_params.draw_params == nullptr);
            ic_params.draw_params = new VkDrawIndirectCommand[actual_draw_count];
            if (ic_params.draw_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            // Now we know the exact draw count. We can fetch the exact draw params instead of the whole buffer
            params_actual_size = sizeof(VkDrawIndirectCommand) * actual_draw_count;
        }

        // Fetch param buffers
        res = resource_util.ReadFromBufferResource(
            ic_params.new_params_buffer, params_actual_size, 0, transfer_queue_index, data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(data.size() == params_actual_size);
        if (IsDrawCallIndexed(dc_params.type))
        {
            util::platform::MemoryCopy(
                ic_params.draw_indexed_params, params_actual_size, data.data(), params_actual_size);
        }
        else
        {
            util::platform::MemoryCopy(ic_params.draw_params, params_actual_size, data.data(), params_actual_size);
        }
    }
    else
    {
        DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params = dc_params.dc_params_union.draw_indirect;

        if (!i_params.draw_count)
        {
            return VK_SUCCESS;
        }

        if (IsDrawCallIndexed(dc_params.type))
        {
            assert(i_params.draw_indexed_params == nullptr);
            i_params.draw_indexed_params = new VkDrawIndexedIndirectCommand[i_params.draw_count];
            if (i_params.draw_indexed_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }
        }
        else
        {
            assert(i_params.draw_params == nullptr);
            i_params.draw_params = new VkDrawIndirectCommand[i_params.draw_count];
            if (i_params.draw_params == nullptr)
            {
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }
        }

        std::vector<uint8_t> params_data;
        VkResult             res = resource_util.ReadFromBufferResource(
            i_params.new_params_buffer, i_params.new_params_buffer_size, 0, transfer_queue_index, params_data);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Reading from buffer resource failed (%s).", util::ToString<VkResult>(res).c_str())
            return res;
        }

        assert(params_data.size() == i_params.new_params_buffer_size);

        if (IsDrawCallIndexed(dc_params.type))
        {
            util::platform::MemoryCopy(
                i_params.draw_indexed_params, i_params.new_params_buffer_size, params_data.data(), params_data.size());
        }
        else
        {
            GFXRECON_ASSERT(dc_params.type == DrawCallType::kDrawIndirect);
            util::platform::MemoryCopy(
                i_params.draw_params, i_params.new_params_buffer_size, params_data.data(), params_data.size());
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::DumpVertexIndexBuffers(uint64_t qs_index, uint64_t bcb_index, uint64_t dc_index)
{
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
                                                *device_table_,
                                                *instance_table_,
                                                *phys_dev_info->replay_device_info->memory_properties);

    auto dc_params_entry = draw_call_params_.find(dc_index);
    assert(dc_params_entry != draw_call_params_.end());
    DrawCallParams& dc_params = *dc_params_entry->second;

    MinMaxVertexIndex min_max_vertex_indices = { 0, 0 };
    bool              empty_draw_call        = false;

    const VulkanDelegateDumpResourceContext res_info_base(instance_table_, device_table_, compressor_);

    // Dump index buffer
    if (IsDrawCallIndexed(dc_params.type) && dc_params.referenced_index_buffer.buffer_info != nullptr)
    {
        min_max_vertex_indices.min = std::numeric_limits<uint32_t>::max();

        struct DrawIndexedParams
        {
            uint32_t index_count;
            uint32_t first_index;
            int32_t  vertex_offset;
        };

        // Store all indexCount, firstIndex and vertexOffset used by all draw calls (in case of indirect)
        // associated with this index buffer. Then we will parse the index buffer using all these pairs
        // in order to detect the greatest index which should help calculate the size of the vertex buffer
        // actually used by the draw calls.
        std::vector<DrawIndexedParams> indexed_params;
        uint32_t                       abs_index_count = 0;

        if (IsDrawCallIndirect(dc_params.type))
        {
            if (IsDrawCallIndirectCount(dc_params.type))
            {
                const DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                    dc_params.dc_params_union.draw_indirect_count;
                empty_draw_call = !ic_params.actual_draw_count;

                if (ic_params.actual_draw_count)
                {
                    bool has_count = false;
                    assert(ic_params.draw_indexed_params != nullptr);
                    for (uint32_t d = 0; d < ic_params.actual_draw_count; ++d)
                    {
                        const uint32_t indirect_index_count    = ic_params.draw_indexed_params[d].indexCount;
                        const uint32_t indirect_instance_count = ic_params.draw_indexed_params[d].instanceCount;
                        if (indirect_index_count && indirect_instance_count)
                        {
                            const uint32_t indirect_first_index = ic_params.draw_indexed_params[d].firstIndex;
                            abs_index_count = std::max(abs_index_count, indirect_index_count + indirect_first_index);
                            indexed_params.emplace_back(
                                DrawIndexedParams{ indirect_index_count,
                                                   indirect_first_index,
                                                   ic_params.draw_indexed_params[d].vertexOffset });
                            has_count = true;
                        }
                    }
                    empty_draw_call = !has_count;
                }
            }
            else
            {
                const DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params =
                    dc_params.dc_params_union.draw_indirect;
                empty_draw_call = !i_params.draw_count;

                if (i_params.draw_count)
                {
                    bool has_count = false;
                    assert(i_params.draw_indexed_params != nullptr);
                    for (uint32_t d = 0; d < i_params.draw_count; ++d)
                    {
                        const uint32_t indirect_index_count    = i_params.draw_indexed_params[d].indexCount;
                        const uint32_t indirect_instance_count = i_params.draw_indexed_params[d].instanceCount;
                        if (indirect_index_count && indirect_instance_count)
                        {
                            const uint32_t indirect_first_index = i_params.draw_indexed_params[d].firstIndex;
                            abs_index_count = std::max(abs_index_count, indirect_index_count + indirect_first_index);
                            indexed_params.emplace_back(
                                DrawIndexedParams{ indirect_index_count,
                                                   indirect_first_index,
                                                   i_params.draw_indexed_params[d].vertexOffset });
                            has_count = true;
                        }
                    }
                    empty_draw_call = !has_count;
                }
            }
        }
        else
        {
            const uint32_t index_count = dc_params.dc_params_union.draw_indexed.indexCount;
            if (index_count && dc_params.dc_params_union.draw_indexed.instanceCount)
            {
                const uint32_t first_index = dc_params.dc_params_union.draw_indexed.firstIndex;
                empty_draw_call            = !index_count;
                abs_index_count            = index_count + first_index;

                indexed_params.emplace_back(
                    DrawIndexedParams{ index_count, first_index, dc_params.dc_params_union.draw_indexed.vertexOffset });
            }
        }

        if (abs_index_count)
        {
            const VkIndexType index_type = dc_params.referenced_index_buffer.index_type;
            const uint32_t    index_size = VkIndexTypeToBytes(index_type);
            const uint32_t    offset     = dc_params.referenced_index_buffer.offset;

            // Check if the exact size has been provided by vkCmdBindIndexBuffer2
            uint32_t total_size = (dc_params.referenced_index_buffer.size != 0)
                                      ? (dc_params.referenced_index_buffer.size)
                                      : (abs_index_count * index_size);

            // There is something wrong with the calculations if this is true
            assert(total_size <= dc_params.referenced_index_buffer.buffer_info->size - offset);
            if (total_size > dc_params.referenced_index_buffer.buffer_info->size - offset)
            {
                total_size = dc_params.referenced_index_buffer.buffer_info->size - offset;
            }

            auto& new_dumped_index_buffer = dc_params.dumped_resources.dumped_vertex_index_buffers.emplace_back(
                DumpResourceType::kIndex,
                bcb_index,
                dc_index,
                qs_index,
                index_type,
                dc_params.referenced_index_buffer.buffer_info,
                total_size,
                offset);

            VulkanDelegateDumpResourceContext res_info = res_info_base;
            res_info.dumped_resource                   = &new_dumped_index_buffer;
            res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
            auto& dumped_buffer_data                   = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);

            VkResult res = DumpBuffer(new_dumped_index_buffer.buffer,
                                      dumped_buffer_data.data,
                                      device_info,
                                      device_table_,
                                      instance_table_,
                                      object_info_table_);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("Reading from index buffer resource failed (%s).",
                                   util::ToString<VkResult>(res).c_str())

                dc_params.dumped_resources.dumped_vertex_index_buffers.erase(
                    dc_params.dumped_resources.dumped_vertex_index_buffers.end() - 1);

                return res;
            }

            delegate_.DumpResource(res_info);

            // Parse all indices in order to find the smallest and greatest index
            for (const auto& params : indexed_params)
            {
                MinMaxVertexIndex min_max_indices = FindMinMaxVertexIndices(
                    dumped_buffer_data.data, params.index_count, params.first_index, params.vertex_offset, index_type);

                min_max_vertex_indices.min = std::min(min_max_indices.min, min_max_vertex_indices.min);
                min_max_vertex_indices.max = std::max(min_max_indices.max, min_max_vertex_indices.max);
            }
        }
    }

    // Dump vertex buffer
    if (!empty_draw_call && !dc_params.referenced_vertex_buffers.bound_vertex_buffer_per_binding.empty())
    {
        uint32_t vertex_count   = 0;
        uint32_t instance_count = 0;
        uint32_t first_vertex   = 0;
        uint32_t first_instance = 0;

        if (IsDrawCallIndexed(dc_params.type))
        {
            // For indexed draw calls the greatest vertex index will be used as the max vertex count
            GFXRECON_ASSERT(min_max_vertex_indices.max >= min_max_vertex_indices.min);
            vertex_count = (min_max_vertex_indices.max - min_max_vertex_indices.min) + 1;

            if (IsDrawCallIndirect(dc_params.type))
            {
                if (IsDrawCallIndirectCount(dc_params.type))
                {
                    const DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                        dc_params.dc_params_union.draw_indirect_count;

                    if (ic_params.actual_draw_count)
                    {
                        assert(ic_params.draw_indexed_params != nullptr);
                        assert(ic_params.draw_params == nullptr);
                        for (uint32_t d = 0; d < ic_params.actual_draw_count; ++d)
                        {
                            instance_count = std::max(instance_count, ic_params.draw_indexed_params[d].instanceCount);
                            first_instance = std::min(first_instance, ic_params.draw_indexed_params[d].firstInstance);
                        }
                    }
                }
                else
                {
                    const DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params =
                        dc_params.dc_params_union.draw_indirect;

                    if (i_params.draw_count)
                    {
                        assert(i_params.draw_indexed_params != nullptr);
                        assert(i_params.draw_params == nullptr);
                        for (uint32_t d = 0; d < i_params.draw_count; ++d)
                        {
                            instance_count = std::max(instance_count, i_params.draw_indexed_params[d].instanceCount);
                            first_instance = std::min(first_instance, i_params.draw_indexed_params[d].firstInstance);
                        }
                    }
                }
            }
            else
            {
                instance_count = dc_params.dc_params_union.draw_indexed.instanceCount;
                first_instance = dc_params.dc_params_union.draw_indexed.firstInstance;
            }
        }
        else
        {
            if (IsDrawCallIndirect(dc_params.type))
            {
                first_vertex = std::numeric_limits<uint32_t>::max();

                if (IsDrawCallIndirectCount(dc_params.type))
                {
                    const DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                        dc_params.dc_params_union.draw_indirect_count;

                    if (ic_params.actual_draw_count)
                    {
                        assert(ic_params.draw_params != nullptr);
                        assert(ic_params.draw_indexed_params == nullptr);
                        for (uint32_t d = 0; d < ic_params.actual_draw_count; ++d)
                        {
                            if (ic_params.draw_params[d].vertexCount && ic_params.draw_params[d].instanceCount)
                            {
                                vertex_count   = std::max(vertex_count, ic_params.draw_params[d].vertexCount);
                                instance_count = std::max(instance_count, ic_params.draw_params[d].instanceCount);
                                first_vertex   = std::min(first_vertex, ic_params.draw_params[d].firstVertex);
                                first_instance = std::min(first_instance, ic_params.draw_params[d].firstInstance);
                            }
                        }
                    }
                }
                else
                {
                    const DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params =
                        dc_params.dc_params_union.draw_indirect;

                    if (i_params.draw_count)
                    {
                        assert(i_params.draw_params != nullptr);
                        assert(i_params.draw_indexed_params == nullptr);
                        for (uint32_t d = 0; d < i_params.draw_count; ++d)
                        {
                            if (i_params.draw_params[d].vertexCount && i_params.draw_params[d].instanceCount)
                            {
                                vertex_count   = std::max(vertex_count, i_params.draw_params[d].vertexCount);
                                instance_count = std::max(instance_count, i_params.draw_params[d].instanceCount);
                                first_vertex   = std::min(first_vertex, i_params.draw_params[d].firstVertex);
                                first_instance = std::min(first_instance, i_params.draw_params[d].firstInstance);
                            }
                        }
                    }
                }

                if (first_vertex == std::numeric_limits<uint32_t>::max())
                {
                    first_vertex = 0;
                }
            }
            else
            {
                vertex_count   = dc_params.dc_params_union.draw.vertexCount;
                instance_count = dc_params.dc_params_union.draw.instanceCount;
                first_vertex   = dc_params.dc_params_union.draw.firstVertex;
                first_instance = dc_params.dc_params_union.draw.firstInstance;
            }
        }

        if (vertex_count)
        {
            for (const auto& [binding_index, binding_desc] : dc_params.vertex_input_state.vertex_input_binding_map)
            {
                auto vb_entry_it =
                    dc_params.referenced_vertex_buffers.bound_vertex_buffer_per_binding.find(binding_index);
                GFXRECON_ASSERT(vb_entry_it !=
                                dc_params.referenced_vertex_buffers.bound_vertex_buffer_per_binding.end());

                // For some reason there was no buffer bound for this binding
                if (vb_entry_it == dc_params.referenced_vertex_buffers.bound_vertex_buffer_per_binding.end())
                {
                    continue;
                }

                auto& vb_entry = vb_entry_it->second;

                // Buffers can be NULL
                if (vb_entry.buffer_info == nullptr)
                {
                    continue;
                }

                // Check if an attribute references this binding
                if (!options_.dump_resources_dump_unused_vertex_bindings &&
                    !dc_params.vertex_input_state.IsVertexBindingReferenced(binding_index))
                {
                    continue;
                }

                const uint32_t count =
                    binding_desc.inputRate == VK_VERTEX_INPUT_RATE_VERTEX ? vertex_count : instance_count;
                uint32_t total_size = 0;
                uint32_t binding_stride;

                if (vb_entry.size)
                {
                    // Exact size was provided by vkCmdBindVertexBuffers2
                    total_size     = vb_entry.size;
                    binding_stride = vb_entry.stride;
                }
                else
                {
                    binding_stride = binding_desc.stride;
                    if (binding_stride)
                    {
                        total_size = count * binding_stride;
                    }
                    else
                    {
                        // According to the spec providing a VkVertexInputBindingDescription.stride equal to zero is
                        // valid. In these cases we will assume that information for only 1 vertex will be consumed
                        // (since we can't tell where the next one is located). So calculate the total size of all
                        // attributes that are using that binding and use that as the size of the vertex information
                        // for 1 vertex.
                        for (const auto& [location, input_attrib_desc] :
                             dc_params.vertex_input_state.vertex_input_attribute_map)
                        {
                            if (input_attrib_desc.binding != binding_index)
                            {
                                continue;
                            }

                            total_size = std::max(
                                total_size, vkuFormatElementSize(input_attrib_desc.format) + input_attrib_desc.offset);
                        }

                        if (!total_size)
                        {
                            continue;
                        }
                    }
                }

                // Calculate offset including vertexOffset
                uint32_t offset = vb_entry.offset;
                offset +=
                    (binding_desc.inputRate == VK_VERTEX_INPUT_RATE_VERTEX ? min_max_vertex_indices.min + first_vertex
                                                                           : first_instance) *
                    binding_stride;

                GFXRECON_ASSERT(total_size <= vb_entry.buffer_info->size - offset);
                // There is something wrong with the calculations if this is true
                if (total_size > vb_entry.buffer_info->size - offset)
                {
                    total_size = vb_entry.buffer_info->size - offset;
                }

                auto& new_dumped_vertex_buffer =
                    dc_params.dumped_resources.dumped_vertex_index_buffers.emplace_back(DumpResourceType::kVertex,
                                                                                        bcb_index,
                                                                                        dc_index,
                                                                                        qs_index,
                                                                                        binding_index,
                                                                                        vb_entry.buffer_info,
                                                                                        total_size,
                                                                                        offset);

                VulkanDelegateDumpResourceContext res_info = res_info_base;
                res_info.dumped_resource                   = &new_dumped_vertex_buffer;
                res_info.dumped_data                       = VulkanDelegateBufferDumpedData();
                auto& dumped_buffer_data = std::get<VulkanDelegateBufferDumpedData>(res_info.dumped_data);

                VkResult res = DumpBuffer(new_dumped_vertex_buffer.buffer,
                                          dumped_buffer_data.data,
                                          device_info,
                                          device_table_,
                                          instance_table_,
                                          object_info_table_);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Reading from vertex buffer resource failed (%s).",
                                       util::ToString<VkResult>(res).c_str())

                    dc_params.dumped_resources.dumped_vertex_index_buffers.erase(
                        dc_params.dumped_resources.dumped_vertex_index_buffers.end() - 1);

                    return res;
                }

                delegate_.DumpResource(res_info);
            }
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::CloneCommandBuffer(VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                                     const graphics::VulkanDeviceTable*   dev_table,
                                                     const graphics::VulkanInstanceTable* inst_table,
                                                     const VkCommandBufferBeginInfo*      begin_info)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);
    assert(inst_table);

    const VulkanCommandPoolInfo* cb_pool_info = object_info_table_.GetVkCommandPoolInfo(orig_cmd_buf_info->pool_id);

    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary ||
                    command_buffer_level_ == DumpResourcesCommandBufferLevel::kSecondary);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary
                                              ? VK_COMMAND_BUFFER_LEVEL_PRIMARY
                                              : VK_COMMAND_BUFFER_LEVEL_SECONDARY,
                                          1 };

    const VulkanDeviceInfo* dev_info = object_info_table_.GetVkDeviceInfo(orig_cmd_buf_info->parent_id);

    for (auto& command_buffer : command_buffers_)
    {
        GFXRECON_ASSERT(command_buffer == VK_NULL_HANDLE);
        VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &command_buffer);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
        dev_table->BeginCommandBuffer(command_buffer, begin_info);
    }

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

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties);
    replay_device_phys_mem_props_ = &phys_dev_info->replay_device_info->memory_properties.value();

    // Allocate auxiliary command buffer
    VkResult res = device_table_->AllocateCommandBuffers(dev_info->handle, &ai, &aux_command_buffer_);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    res                        = device_table_->CreateFence(dev_info->handle, &ci, nullptr, &aux_fence_);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

void DrawCallsDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                                pipeline_bind_point,
    uint32_t                                           first_set,
    const std::vector<const VulkanDescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                           dynamicOffsetCount,
    const uint32_t*                                    pDynamicOffsets)
{
    if (pipeline_bind_point != VK_PIPELINE_BIND_POINT_GRAPHICS)
    {
        return;
    }

    uint32_t dynamic_offset_index = 0;
    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        const uint32_t set_index = first_set + i;

        if (descriptor_sets_infos[i] != nullptr)
        {
            bound_descriptor_sets_gr_[set_index] = descriptor_sets_infos[i]->descriptors;

            if (dynamicOffsetCount && pDynamicOffsets != nullptr)
            {
                for (auto& [binding_index, binding] : bound_descriptor_sets_gr_[set_index])
                {
                    if (binding.desc_type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                        binding.desc_type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
                    {
                        for (auto& [array_index, buf_info] : binding.buffer_info)
                        {
                            buf_info.offset += pDynamicOffsets[dynamic_offset_index];
                            ++dynamic_offset_index;
                        }
                    }
                }
            }
        }
    }

    assert((dynamic_offset_index == dynamicOffsetCount && pDynamicOffsets != nullptr) || (!dynamic_offset_index));
}

VkResult DrawCallsDumpingContext::CloneRenderPass(const VkRenderPassCreateInfo* original_render_pass_ci)
{
    std::vector<VkAttachmentDescription> modified_attachments(original_render_pass_ci->pAttachments,
                                                              original_render_pass_ci->pAttachments +
                                                                  original_render_pass_ci->attachmentCount);

    // Fix storeOps and final layouts
    for (auto& att : modified_attachments)
    {
        att.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
        att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

        if (vkuFormatHasStencil(att.format))
        {
            att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
        }
    }

    // Create new render passes
    std::vector<VkRenderPass>& new_render_pass = render_pass_clones_.emplace_back();
    new_render_pass.resize(original_render_pass_ci->subpassCount);

    // Do one quick pass over the subpass references in order to check if the render pass
    // uses color and/or depth attachments. This information might be necessary when
    // defining the dependencies of the custom render passes
    bool has_color = false, has_depth = false;
    for (uint32_t i = 0; i < original_render_pass_ci->subpassCount; ++i)
    {
        for (uint32_t j = 0; j < original_render_pass_ci->pSubpasses[i].colorAttachmentCount; ++j)
        {
            if (original_render_pass_ci->pSubpasses[i].pColorAttachments[j].attachment != VK_ATTACHMENT_UNUSED)
            {
                has_color = true;
                break;
            }
        }

        if (original_render_pass_ci->pSubpasses[i].pDepthStencilAttachment != nullptr &&
            original_render_pass_ci->pSubpasses[i].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
        {
            has_depth = true;
        }
    }

    // Create new render passes. For each subpass in the original render pass a new render pass will be created.
    // Each new render pass will progressively contain an additional subpass until all subpasses of the original
    // renderpass are exhausted.
    // For example for a render pass with 3 subpasses, 3 new render passes will be created and will contain the
    // following subpasses:
    // Renderpass 0: Will contain 1 subpass.
    // Renderpass 1: Will contain 2 subpass.
    // Renderpass 2: Will contain 3 subpass.
    // Each draw call that is marked for dumping will be "assigned" the appropriate render pass depending on which
    // subpasses it was called from in the original render pass
    std::vector<VkSubpassDescription> subpass_descs;
    for (uint32_t sub = 0; sub < original_render_pass_ci->subpassCount; ++sub)
    {
        bool                             has_external_dependencies_post = false;
        std::vector<VkSubpassDependency> modified_dependencies;

        for (uint32_t i = 0; i < original_render_pass_ci->dependencyCount; ++i)
        {
            const auto& original_dep = original_render_pass_ci->pDependencies[i];

            if ((original_dep.srcSubpass > sub || original_dep.dstSubpass > sub) &&
                (original_dep.srcSubpass != VK_SUBPASS_EXTERNAL && original_dep.dstSubpass != VK_SUBPASS_EXTERNAL))
            {
                // Skip this dependency as out of scope
                continue;
            }

            auto new_dep = modified_dependencies.insert(modified_dependencies.end(), original_dep);
            if (new_dep->srcSubpass != VK_SUBPASS_EXTERNAL && new_dep->srcSubpass > sub)
            {
                new_dep->srcSubpass = sub;
            }
            else if (new_dep->dstSubpass != VK_SUBPASS_EXTERNAL && new_dep->dstSubpass > sub)
            {
                new_dep->dstSubpass = sub;
            }

            if (new_dep->dstSubpass == VK_SUBPASS_EXTERNAL)
            {
                has_external_dependencies_post = true;
            }
        }

        // No post renderpass dependency was detected
        if (!has_external_dependencies_post)
        {
            VkSubpassDependency post_dependency;
            post_dependency.srcSubpass    = sub;
            post_dependency.dstSubpass    = VK_SUBPASS_EXTERNAL;
            post_dependency.dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
            post_dependency.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

            // Injecting one for color
            if (has_color)
            {
                post_dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }

            // Injecting one for depth
            if (has_depth)
            {
                post_dependency.srcStageMask =
                    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }
        }

        auto& new_subp_desc = subpass_descs.emplace_back();
        new_subp_desc       = original_render_pass_ci->pSubpasses[sub];

        VkRenderPassCreateInfo ci;
        ci.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        ci.flags           = original_render_pass_ci->flags;
        ci.attachmentCount = modified_attachments.size();
        ci.pAttachments    = modified_attachments.empty() ? nullptr : modified_attachments.data();

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        ci.dependencyCount = modified_dependencies.size();
        ci.pDependencies   = modified_dependencies.empty() ? nullptr : modified_dependencies.data();

        ci.pNext = original_render_pass_ci->pNext;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        VkDevice device = device_info->handle;

        assert(sub < new_render_pass.size());
        VkResult res = device_table_->CreateRenderPass(device, &ci, nullptr, &new_render_pass[sub]);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult DrawCallsDumpingContext::CloneRenderPass2(const VulkanRenderPassInfo*    render_pass_info,
                                                   const VkRenderPassCreateInfo2* original_render_pass_ci)
{
    std::vector<VkAttachmentDescription2> modified_attachments(original_render_pass_ci->pAttachments,
                                                               original_render_pass_ci->pAttachments +
                                                                   original_render_pass_ci->attachmentCount);

    // Fix storeOps and final layouts
    for (auto& att : modified_attachments)
    {
        att.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
        att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

        if (vkuFormatHasStencil(att.format))
        {
            att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
        }
    }

    // Create new render passes
    std::vector<VkRenderPass>& new_render_pass = render_pass_clones_.emplace_back();
    new_render_pass.resize(original_render_pass_ci->subpassCount);

    // Do one quick pass over the subpass references in order to check if the render pass
    // uses color and/or depth attachments. This information might be necessary when
    // defining the dependencies of the custom render passes
    bool has_color = false, has_depth = false;
    for (uint32_t i = 0; i < original_render_pass_ci->subpassCount; ++i)
    {
        for (uint32_t j = 0; j < original_render_pass_ci->pSubpasses[i].colorAttachmentCount; ++j)
        {
            if (original_render_pass_ci->pSubpasses[i].pColorAttachments[j].attachment != VK_ATTACHMENT_UNUSED)
            {
                has_color = true;
                break;
            }
        }

        if (original_render_pass_ci->pSubpasses[i].pDepthStencilAttachment != nullptr &&
            original_render_pass_ci->pSubpasses[i].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
        {
            has_depth = true;
        }
    }

    // Create new render passes. For each subpass in the original render pass a new render pass will be created.
    // Each new render pass will progressively contain an additional subpass until all subpasses of the original
    // renderpass are exhausted.
    // For example for a render pass with 3 subpasses, 3 new render passes will be created and will contain the
    // following subpasses:
    // Renderpass 0: Will contain 1 subpass.
    // Renderpass 1: Will contain 2 subpass.
    // Renderpass 2: Will contain 3 subpass.
    // Each draw call that is marked for dumping will be "assigned" the appropriate render pass depending on which
    // subpasses it was called from in the original render pass
    std::vector<VkSubpassDescription2> subpass_descs;
    for (uint32_t sub = 0; sub < original_render_pass_ci->subpassCount; ++sub)
    {
        bool                              has_external_dependencies_post = false;
        std::vector<VkSubpassDependency2> modified_dependencies;

        for (uint32_t i = 0; i < original_render_pass_ci->dependencyCount; ++i)
        {
            const auto& original_dep = original_render_pass_ci->pDependencies[i];

            if ((original_dep.srcSubpass > sub || original_dep.dstSubpass > sub) &&
                (original_dep.srcSubpass != VK_SUBPASS_EXTERNAL && original_dep.dstSubpass != VK_SUBPASS_EXTERNAL))
            {
                // Skip this dependency as out of scope
                continue;
            }

            auto new_dep = modified_dependencies.insert(modified_dependencies.end(), original_dep);
            if (new_dep->srcSubpass != VK_SUBPASS_EXTERNAL && new_dep->srcSubpass > sub)
            {
                new_dep->srcSubpass = sub;
            }
            else if (new_dep->dstSubpass != VK_SUBPASS_EXTERNAL && new_dep->dstSubpass > sub)
            {
                new_dep->dstSubpass = sub;
            }

            if (new_dep->dstSubpass == VK_SUBPASS_EXTERNAL)
            {
                has_external_dependencies_post = true;
            }
        }

        // No post renderpass dependency was detected
        if (!has_external_dependencies_post)
        {
            VkSubpassDependency2 post_dependency;
            post_dependency.sType         = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2;
            post_dependency.pNext         = nullptr;
            post_dependency.srcSubpass    = sub;
            post_dependency.dstSubpass    = VK_SUBPASS_EXTERNAL;
            post_dependency.dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
            post_dependency.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

            // Injecting one for color
            if (has_color)
            {
                post_dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }

            // Injecting one for depth
            if (has_depth)
            {
                post_dependency.srcStageMask =
                    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }
        }

        auto& new_subp_desc = subpass_descs.emplace_back();
        new_subp_desc       = original_render_pass_ci->pSubpasses[sub];

        VkRenderPassCreateInfo2 ci;
        // VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2 and VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR are equal so
        // it doesn't matter which one we use
        ci.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
        ci.flags           = original_render_pass_ci->flags;
        ci.attachmentCount = modified_attachments.size();
        ci.pAttachments    = modified_attachments.empty() ? nullptr : modified_attachments.data();

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        ci.dependencyCount = modified_dependencies.size();
        ci.pDependencies   = modified_dependencies.empty() ? nullptr : modified_dependencies.data();

        ci.correlatedViewMaskCount = original_render_pass_ci->correlatedViewMaskCount;
        ci.pCorrelatedViewMasks    = original_render_pass_ci->pCorrelatedViewMasks;
        ci.pNext                   = original_render_pass_ci->pNext;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        VkDevice device = device_info->handle;

        assert(sub < new_render_pass.size());

        VkResult res;
        if (render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass2)
        {
            res = device_table_->CreateRenderPass2(device, &ci, nullptr, &new_render_pass[sub]);
        }
        else
        {
            GFXRECON_ASSERT(render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass2KHR);
            res = device_table_->CreateRenderPass2KHR(device, &ci, nullptr, &new_render_pass[sub]);
        }

        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

template <typename CreateInfoType>
static void ParseAttachmentsInRenderPassCreateInfo(const VulkanRenderPassInfo*    render_pass_info,
                                                   const CreateInfoType*          ci,
                                                   const VulkanFramebufferInfo*   framebuffer_info,
                                                   uint32_t                       subpass,
                                                   CommonObjectInfoTable&         object_info_table,
                                                   std::vector<VulkanImageInfo*>& color_att_imgs,
                                                   VulkanImageInfo**              depth_img_info)
{
    // Parse color attachments
    for (uint32_t i = 0; i < ci->pSubpasses[subpass].colorAttachmentCount; ++i)
    {
        const uint32_t att_idx = ci->pSubpasses[subpass].pColorAttachments[i].attachment;
        if (att_idx == VK_ATTACHMENT_UNUSED)
        {
            continue;
        }

        const VulkanImageViewInfo* img_view_info = nullptr;
        if (att_idx < framebuffer_info->attachment_image_view_ids.size())
        {
            img_view_info = object_info_table.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[att_idx]);
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            GFXRECON_ASSERT(render_pass_info->begin_renderpass_override_attachments.size() >
                            static_cast<size_t>(att_idx));

            img_view_info =
                object_info_table.GetVkImageViewInfo(render_pass_info->begin_renderpass_override_attachments[att_idx]);
        }
        else
        {
            GFXRECON_LOG_WARNING("unhandled missing color-attachment in %s", __func__);
            continue;
        }

        GFXRECON_ASSERT(img_view_info != nullptr);
        VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(img_view_info->image_id);
        GFXRECON_ASSERT(img_info != nullptr);

        color_att_imgs.push_back(img_info);
    }

    // Detect depth attachment
    const VulkanImageViewInfo* depth_img_view_info = nullptr;

    if (ci->pSubpasses[subpass].pDepthStencilAttachment != nullptr &&
        ci->pSubpasses[subpass].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
    {
        GFXRECON_ASSERT(depth_img_info != nullptr);

        const uint32_t depth_att_idx = ci->pSubpasses[subpass].pDepthStencilAttachment->attachment;

        if (depth_att_idx < framebuffer_info->attachment_image_view_ids.size())
        {
            depth_img_view_info =
                object_info_table.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[depth_att_idx]);
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            GFXRECON_ASSERT(render_pass_info->begin_renderpass_override_attachments.size() >
                            static_cast<size_t>(depth_att_idx));

            depth_img_view_info = object_info_table.GetVkImageViewInfo(
                render_pass_info->begin_renderpass_override_attachments[depth_att_idx]);
        }
        else
        {
            GFXRECON_LOG_WARNING("unhandled missing depth-attachment in %s", __func__);
        }
    }

    if (depth_img_view_info != nullptr)
    {
        *depth_img_info = object_info_table.GetVkImageInfo(depth_img_view_info->image_id);
        GFXRECON_ASSERT(*depth_img_info != nullptr);
    }
    else
    {
        *depth_img_info = nullptr;
    }
}

template <typename CreateInfoType>
static void UpdateOriginalCommandBufferWithNewImageLayouts(const VulkanRenderPassInfo*  render_pass_info,
                                                           const CreateInfoType*        original_render_pass_ci,
                                                           const VulkanFramebufferInfo* framebuffer_info,
                                                           VulkanCommandBufferInfo*     original_command_buffer_info,
                                                           CommonObjectInfoTable&       object_info_table)
{
    // Inform the original command buffer about the new image layouts
    GFXRECON_ASSERT(original_render_pass_ci->subpassCount && original_render_pass_ci->pSubpasses != nullptr);
    for (uint32_t i = 0; i < original_render_pass_ci->pSubpasses[0].colorAttachmentCount; ++i)
    {
        const auto& att_ref = original_render_pass_ci->pSubpasses[0].pColorAttachments[i];

        const VulkanImageViewInfo* att_img_view_info = nullptr;
        if (att_ref.attachment < framebuffer_info->attachment_image_view_ids.size())
        {
            att_img_view_info =
                object_info_table.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[att_ref.attachment]);
            original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id] = att_ref.layout;
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            att_img_view_info = object_info_table.GetVkImageViewInfo(
                render_pass_info->begin_renderpass_override_attachments[att_ref.attachment]);
        }
        else
        {
            GFXRECON_LOG_WARNING("unhandled missing color-attachment in %s", __func__);
            continue;
        }
        GFXRECON_ASSERT(att_img_view_info != nullptr);
        VulkanImageInfo* img_info = object_info_table.GetVkImageInfo(att_img_view_info->image_id);
        GFXRECON_ASSERT(img_info != nullptr);
        img_info->intermediate_layout = att_ref.layout;
    }

    if (original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment != nullptr &&
        original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
    {
        const VulkanImageViewInfo* att_img_view_info = nullptr;

        const uint32_t depth_att_idx = original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment->attachment;
        if (depth_att_idx < framebuffer_info->attachment_image_view_ids.size())
        {
            att_img_view_info =
                object_info_table.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[depth_att_idx]);
            original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id] =
                original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment->layout;
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            att_img_view_info = object_info_table.GetVkImageViewInfo(
                render_pass_info->begin_renderpass_override_attachments[depth_att_idx]);
            original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id] =
                original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment->layout;
        }
    }
}

VkResult DrawCallsDumpingContext::BeginRenderPass(const VulkanRenderPassInfo*  render_pass_info,
                                                  const VulkanFramebufferInfo* framebuffer_info,
                                                  const VkRenderPassBeginInfo* renderpass_begin_info,
                                                  VkSubpassContents            contents)
{
    GFXRECON_ASSERT(render_pass_info != nullptr);
    GFXRECON_ASSERT(framebuffer_info != nullptr);
    GFXRECON_ASSERT(renderpass_begin_info != nullptr);
    GFXRECON_ASSERT(!render_pass_info->create_info.empty());

    std::vector<VulkanImageInfo*> color_att_imgs;
    VulkanImageInfo*              depth_img_info;

    current_render_pass_type_ = kRenderPass;
    current_subpass_          = 0;
    active_renderpass_        = render_pass_info;
    active_framebuffer_       = framebuffer_info;

    if (render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        ParseAttachmentsInRenderPassCreateInfo(
            render_pass_info,
            reinterpret_cast<const VkRenderPassCreateInfo*>(render_pass_info->create_info.data()),
            framebuffer_info,
            current_subpass_,
            object_info_table_,
            color_att_imgs,
            &depth_img_info);
    }
    else
    {
        ParseAttachmentsInRenderPassCreateInfo(
            render_pass_info,
            reinterpret_cast<const VkRenderPassCreateInfo2*>(render_pass_info->create_info.data()),
            framebuffer_info,
            current_subpass_,
            object_info_table_,
            color_att_imgs,
            &depth_img_info);
    }

    SetRenderTargets(color_att_imgs, depth_img_info, true);
    SetRenderArea(renderpass_begin_info->renderArea);

    if (render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        UpdateOriginalCommandBufferWithNewImageLayouts(
            render_pass_info,
            reinterpret_cast<const VkRenderPassCreateInfo*>(render_pass_info->create_info.data()),
            framebuffer_info,
            original_command_buffer_info_,
            object_info_table_);
    }
    else
    {
        UpdateOriginalCommandBufferWithNewImageLayouts(
            render_pass_info,
            reinterpret_cast<const VkRenderPassCreateInfo2*>(render_pass_info->create_info.data()),
            framebuffer_info,
            original_command_buffer_info_,
            object_info_table_);
    }

    VkResult res;
    if (render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        res = CloneRenderPass(reinterpret_cast<const VkRenderPassCreateInfo*>(render_pass_info->create_info.data()));
    }
    else
    {
        res = CloneRenderPass2(render_pass_info,
                               reinterpret_cast<const VkRenderPassCreateInfo2*>(render_pass_info->create_info.data()));
    }

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed cloning render pass (%s).", util::ToString<VkResult>(res).c_str())
        return res;
    }

    // Add vkCmdBeginRenderPass into the cloned command buffers using the modified render pass
    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);

    // copy original begin-info
    VkRenderPassBeginInfo modified_renderpass_begin_info = *renderpass_begin_info;

    size_t cmd_buf_idx = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t dc_index = dc_indices_[CmdBufToDCVectorIndex(cmd_buf_idx)];

        // GetRenderPassIndex will tell us which render pass each cloned command buffer should use depending on the
        // assigned draw call index
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index >= RP_indices_[rp][0])
        {
            if (dc_index > RP_indices_[rp][RP_indices_[rp].size() - 1] || rp > current_renderpass_)
            {
                // Command buffers / Draw calls outside this specific render pass should get
                // assigned the original render pass
                modified_renderpass_begin_info.renderPass = render_pass_info->handle;
            }
            else
            {
                // Command buffers / Draw calls inside this render pass should get the newly created / modified
                // render pass
                assert(rp < render_pass_clones_.size());
                assert(sp < render_pass_clones_[rp].size());
                modified_renderpass_begin_info.renderPass = render_pass_clones_[rp][sp];
            }
        }
        else
        {
            // This must be from a secondary
            for (const auto& ex_com : secondaries_)
            {
                const uint64_t execute_commands_index = ex_com.first;
                if (execute_commands_index > RP_indices_[rp][RP_indices_[rp].size() - 1] || rp > current_renderpass_)
                {
                    // Command buffers / Draw calls outside this specific render pass should get
                    // assigned the original render pass
                    modified_renderpass_begin_info.renderPass = render_pass_info->handle;
                }
                else
                {
                    // Command buffers / Draw calls inside this render pass should get the newly created / modified
                    // render pass
                    assert(rp < render_pass_clones_.size());
                    assert(sp < render_pass_clones_[rp].size());
                    modified_renderpass_begin_info.renderPass = render_pass_clones_[rp][sp];
                }
            }
        }
        device_table_->CmdBeginRenderPass(*it, &modified_renderpass_begin_info, contents);
    }

    auto new_entry = dynamic_rendering_attachment_layouts_.emplace(
        std::piecewise_construct, std::forward_as_tuple(current_renderpass_), std::forward_as_tuple());
    assert(new_entry.second);
    new_entry.first->second.is_dynamic = false;

    return VK_SUCCESS;
}

void DrawCallsDumpingContext::NextSubpass(VkSubpassContents contents)
{
    assert(active_renderpass_);
    assert(!active_renderpass_->create_info.empty());
    assert(active_framebuffer_);

    std::vector<VulkanImageInfo*>    color_att_imgs;
    std::vector<VkAttachmentStoreOp> color_att_storeOps;
    std::vector<VkImageLayout>       color_att_final_layouts;

    ++current_subpass_;

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices_[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;

        device_table_->CmdNextSubpass(*it, contents);
    }

    VulkanImageInfo*    depth_img_info;
    VkAttachmentStoreOp depth_att_storeOp;
    VkImageLayout       depth_final_layout;

    if (active_renderpass_->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        ParseAttachmentsInRenderPassCreateInfo(
            active_renderpass_,
            reinterpret_cast<const VkRenderPassCreateInfo*>(active_renderpass_->create_info.data()),
            active_framebuffer_,
            current_subpass_,
            object_info_table_,
            color_att_imgs,
            &depth_img_info);
    }
    else
    {
        ParseAttachmentsInRenderPassCreateInfo(
            active_renderpass_,
            reinterpret_cast<const VkRenderPassCreateInfo2*>(active_renderpass_->create_info.data()),
            active_framebuffer_,
            current_subpass_,
            object_info_table_,
            color_att_imgs,
            &depth_img_info);
    }

    SetRenderTargets(color_att_imgs, depth_img_info, false);

    if (active_renderpass_->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        UpdateOriginalCommandBufferWithNewImageLayouts(
            active_renderpass_,
            reinterpret_cast<const VkRenderPassCreateInfo*>(active_renderpass_->create_info.data()),
            active_framebuffer_,
            original_command_buffer_info_,
            object_info_table_);
    }
    else
    {
        UpdateOriginalCommandBufferWithNewImageLayouts(
            active_renderpass_,
            reinterpret_cast<const VkRenderPassCreateInfo2*>(active_renderpass_->create_info.data()),
            active_framebuffer_,
            original_command_buffer_info_,
            object_info_table_);
    }
}

void DrawCallsDumpingContext::BindPipeline(VkPipelineBindPoint pipeline_bind_point, const VulkanPipelineInfo* pipeline)
{
    if (pipeline_bind_point != VK_PIPELINE_BIND_POINT_GRAPHICS)
    {
        return;
    }

    bound_gr_pipeline_ = pipeline;
}

void DrawCallsDumpingContext::EndRenderPass()
{
    assert(current_render_pass_type_ == kRenderPass);

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices_[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices_[rp][0])
        {
            continue;
        }

        device_table_->CmdEndRenderPass(*it);
    }

    ++current_renderpass_;

    current_render_pass_type_ = kNone;
}

void DrawCallsDumpingContext::EndRendering()
{
    assert(current_render_pass_type_ == kDynamicRendering);

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        device_table_->CmdEndRendering(*it);
    }

    ++current_renderpass_;

    current_render_pass_type_ = kNone;
}

void DrawCallsDumpingContext::BindVertexBuffers(uint64_t                                    index,
                                                uint32_t                                    firstBinding,
                                                const std::vector<const VulkanBufferInfo*>& buffer_infos,
                                                const VkDeviceSize*                         pOffsets)
{
    if (buffer_infos.empty())
    {
        return;
    }

    for (size_t i = 0; i < buffer_infos.size(); ++i)
    {
        const auto binding = static_cast<uint32_t>(firstBinding + i);
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].buffer_info = buffer_infos[i];
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].offset      = pOffsets[i];
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].size        = 0;
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].stride      = 0;
    }
}

void DrawCallsDumpingContext::BindVertexBuffers2(uint64_t                                    index,
                                                 uint32_t                                    first_binding,
                                                 const std::vector<const VulkanBufferInfo*>& buffer_infos,
                                                 const VkDeviceSize*                         pOffsets,
                                                 const VkDeviceSize*                         pSizes,
                                                 const VkDeviceSize*                         pStrides)
{
    if (buffer_infos.empty())
    {
        return;
    }

    for (size_t i = 0; i < buffer_infos.size(); ++i)
    {
        VkDeviceSize buffer_size = 0;
        if (pSizes != nullptr && buffer_infos[i] != nullptr)
        {
            if (pSizes[i] == VK_WHOLE_SIZE)
            {
                assert(buffer_infos[i]->size > pOffsets[i]);
                buffer_size = buffer_infos[i]->size - pOffsets[i];
            }
            else
            {
                buffer_size = pSizes[i];
            }
        }

        const auto binding = static_cast<uint32_t>(first_binding + i);
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].buffer_info = buffer_infos[i];
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].offset      = pOffsets[i];
        bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].stride = pStrides != nullptr ? pStrides[i] : 0;
        if (pSizes != nullptr)
        {
            bound_vertex_buffers_.bound_vertex_buffer_per_binding[binding].size = buffer_size;
        }
    }
}

void DrawCallsDumpingContext::SetVertexInput(uint32_t                                   vertexBindingDescriptionCount,
                                             const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                             uint32_t                                   vertexAttributeDescriptionCount,
                                             const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    for (uint32_t i = 0; i < vertexBindingDescriptionCount; ++i)
    {
        const VkVertexInputBindingDescription2EXT& input_binding_description = pVertexBindingDescriptions[i];
        GFXRECON_ASSERT(input_binding_description.stride != 0);
        dynamic_vertex_input_state_.vertex_input_binding_map[input_binding_description.binding].inputRate =
            input_binding_description.inputRate;
        dynamic_vertex_input_state_.vertex_input_binding_map[input_binding_description.binding].stride =
            input_binding_description.stride;
    }

    for (uint32_t i = 0; i < vertexAttributeDescriptionCount; ++i)
    {
        const VkVertexInputAttributeDescription2EXT& attribute_description = pVertexAttributeDescriptions[i];
        dynamic_vertex_input_state_.vertex_input_attribute_map[attribute_description.location].binding =
            attribute_description.binding;
        dynamic_vertex_input_state_.vertex_input_attribute_map[attribute_description.location].format =
            attribute_description.format;
        dynamic_vertex_input_state_.vertex_input_attribute_map[attribute_description.location].offset =
            attribute_description.offset;
    }
}

void DrawCallsDumpingContext::BindIndexBuffer(
    uint64_t index, const VulkanBufferInfo* buffer_info, VkDeviceSize offset, VkIndexType index_type, VkDeviceSize size)
{
    VkDeviceSize index_buffer_size = 0;
    if (size)
    {
        if (size == VK_WHOLE_SIZE && buffer_info != nullptr)
        {
            assert(buffer_info->size > offset);
            index_buffer_size = buffer_info->size - offset;
        }
        else
        {
            index_buffer_size = size;
        }
    }

    bound_index_buffer_.buffer_info = buffer_info;
    bound_index_buffer_.offset      = offset;
    bound_index_buffer_.index_type  = index_type;
    bound_index_buffer_.size        = index_buffer_size;
}

void DrawCallsDumpingContext::SetRenderTargets(const std::vector<VulkanImageInfo*>& color_att_imgs,
                                               VulkanImageInfo*                     depth_att_img,
                                               bool                                 new_render_pass)
{
    if (new_render_pass)
    {
        render_targets_.emplace_back();
    }

    auto new_render_targets = render_targets_.end() - 1;

    new_render_targets->emplace_back(RenderTargets());
    auto new_rts = new_render_targets->end() - 1;

    new_rts->color_att_imgs = color_att_imgs;
    new_rts->depth_att_img  = depth_att_img;
}

void DrawCallsDumpingContext::SetRenderArea(const VkRect2D& new_render_area)
{
    render_area_.push_back(new_render_area);
}

void DrawCallsDumpingContext::ResetFetchedIndirectParams()
{
    for (auto& dc_param_entry : draw_call_params_)
    {
        DrawCallParams& dc_params = *dc_param_entry.second;
        if (IsDrawCallIndirect(dc_params.type))
        {
            if (IsDrawCallIndirectCount(dc_params.type))
            {
                DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                    dc_params.dc_params_union.draw_indirect_count;

                if (ic_params.draw_params != nullptr)
                {
                    delete[] ic_params.draw_params;
                    ic_params.draw_params = nullptr;
                }

                if (ic_params.draw_indexed_params != nullptr)
                {
                    delete[] ic_params.draw_indexed_params;
                    ic_params.draw_indexed_params = nullptr;
                }

                ic_params.actual_draw_count = std::numeric_limits<uint32_t>::max();
            }
            else
            {
                DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params =
                    dc_params.dc_params_union.draw_indirect;

                if (i_params.draw_params != nullptr)
                {
                    delete[] i_params.draw_params;
                    i_params.draw_params = nullptr;
                }

                if (i_params.draw_indexed_params != nullptr)
                {
                    delete[] i_params.draw_indexed_params;
                    i_params.draw_indexed_params = nullptr;
                }
            }
        }
    }
}

void DrawCallsDumpingContext::ReleaseIndirectParams()
{
    assert(original_command_buffer_info_);
    assert(original_command_buffer_info_->parent_id != format::kNullHandleId);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);

    if (device_info == nullptr)
    {
        return;
    }

    for (auto& dc_param_entry : draw_call_params_)
    {
        DrawCallParams& dc_params = *dc_param_entry.second;
        if (IsDrawCallIndirect(dc_params.type))
        {
            if (IsDrawCallIndirectCount(dc_params.type))
            {
                DrawCallParams::DrawCallParamsUnion::DrawIndirectCountParams& ic_params =
                    dc_params.dc_params_union.draw_indirect_count;

                if (ic_params.draw_params != nullptr)
                {
                    delete[] ic_params.draw_params;
                    ic_params.draw_params = nullptr;
                }

                if (ic_params.draw_indexed_params != nullptr)
                {
                    delete[] ic_params.draw_indexed_params;
                    ic_params.draw_indexed_params = nullptr;
                }

                if (ic_params.new_params_buffer != VK_NULL_HANDLE)
                {
                    device_table_->DestroyBuffer(device_info->handle, ic_params.new_params_buffer, nullptr);
                    ic_params.new_params_buffer = VK_NULL_HANDLE;
                }

                if (ic_params.new_params_memory != VK_NULL_HANDLE)
                {
                    device_table_->FreeMemory(device_info->handle, ic_params.new_params_memory, nullptr);
                    ic_params.new_params_memory = VK_NULL_HANDLE;
                }

                if (ic_params.new_count_buffer != VK_NULL_HANDLE)
                {
                    device_table_->DestroyBuffer(device_info->handle, ic_params.new_count_buffer, nullptr);
                    ic_params.new_count_buffer = VK_NULL_HANDLE;
                }

                if (ic_params.new_count_memory != VK_NULL_HANDLE)
                {
                    device_table_->FreeMemory(device_info->handle, ic_params.new_count_memory, nullptr);
                    ic_params.new_count_memory = VK_NULL_HANDLE;
                }
            }
            else
            {
                DrawCallParams::DrawCallParamsUnion::DrawIndirectParams& i_params =
                    dc_params.dc_params_union.draw_indirect;

                if (i_params.draw_params != nullptr)
                {
                    delete[] i_params.draw_params;
                    i_params.draw_params = nullptr;
                }

                if (i_params.draw_indexed_params != nullptr)
                {
                    delete[] i_params.draw_indexed_params;
                    i_params.draw_indexed_params = nullptr;
                }

                if (i_params.new_params_buffer != VK_NULL_HANDLE)
                {
                    device_table_->DestroyBuffer(device_info->handle, i_params.new_params_buffer, nullptr);
                    i_params.new_params_buffer = VK_NULL_HANDLE;
                }

                if (i_params.new_params_memory != VK_NULL_HANDLE)
                {
                    device_table_->FreeMemory(device_info->handle, i_params.new_params_memory, nullptr);
                    i_params.new_params_memory = VK_NULL_HANDLE;
                }
            }
        }
    }
}

void DrawCallsDumpingContext::DestroyMutableResourceBackups()
{
    assert(original_command_buffer_info_);

    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    if (device_info == nullptr)
    {
        return;
    }

    VkDevice device = device_info->handle;

    for (const auto& image : mutable_resource_backups_.images)
    {
        device_table_->DestroyImage(device, image, nullptr);
    }

    for (const auto& image_memory : mutable_resource_backups_.image_memories)
    {
        device_table_->FreeMemory(device, image_memory, nullptr);
    }

    mutable_resource_backups_.images.clear();
    mutable_resource_backups_.image_memories.clear();
    mutable_resource_backups_.original_images.clear();

    for (const auto& buffer : mutable_resource_backups_.buffers)
    {
        device_table_->DestroyBuffer(device, buffer, nullptr);
    }

    for (const auto& buffer_memory : mutable_resource_backups_.buffer_memories)
    {
        device_table_->FreeMemory(device, buffer_memory, nullptr);
    }

    mutable_resource_backups_.buffers.clear();
    mutable_resource_backups_.buffer_memories.clear();
    mutable_resource_backups_.original_buffers.clear();
}

DrawCallsDumpingContext::RenderPassSubpassPair DrawCallsDumpingContext::GetRenderPassIndex(uint64_t dc_index) const
{
    assert(RP_indices_.size());

    if (secondaries_.empty())
    {
        for (size_t rp = 0; rp < RP_indices_.size(); ++rp)
        {
            const std::vector<uint64_t>& render_pass = RP_indices_[rp];
            assert(render_pass.size());

            if (dc_index > render_pass[render_pass.size() - 1])
            {
                continue;
            }

            for (uint64_t sp = 0; sp < render_pass.size() - 1; ++sp)
            {
                if (dc_index > render_pass[sp] && dc_index < render_pass[sp + 1])
                {
                    return { rp, sp };
                }
            }
        }
    }
    else
    {
        for (const auto& ex_com : secondaries_)
        {
            const uint64_t execute_commands_index = ex_com.first;
            for (const DrawCallsDumpingContext* secondary_context : ex_com.second)
            {
                const CommandIndices& secondary_dcs = secondary_context->GetDrawCallIndices();

                if (IsInsideRange(secondary_dcs, dc_index))
                {
                    // Draw call from secondary
                    for (size_t rp = 0; rp < RP_indices_.size(); ++rp)
                    {
                        const std::vector<uint64_t>& render_pass = RP_indices_[rp];
                        GFXRECON_ASSERT(!render_pass.empty());

                        if (execute_commands_index > render_pass[render_pass.size() - 1])
                        {
                            continue;
                        }

                        for (uint64_t sp = 0; sp < render_pass.size() - 1; ++sp)
                        {
                            if (execute_commands_index > render_pass[sp] &&
                                execute_commands_index < render_pass[sp + 1])
                            {
                                return { rp, sp };
                            }
                        }
                    }
                }
                else
                {
                    // Draw call from primary
                    for (size_t rp = 0; rp < RP_indices_.size(); ++rp)
                    {
                        const std::vector<uint64_t>& render_pass = RP_indices_[rp];
                        assert(render_pass.size());

                        if (dc_index > render_pass[render_pass.size() - 1])
                        {
                            continue;
                        }

                        for (uint64_t sp = 0; sp < render_pass.size() - 1; ++sp)
                        {
                            if (dc_index > render_pass[sp] && dc_index < render_pass[sp + 1])
                            {
                                return { rp, sp };
                            }
                        }
                    }
                }
            }
        }
    }

    // If this is hit then probably there's something wrong with the draw call and/or render pass indices
    GFXRECON_LOG_ERROR(
        "It appears that there is an error with the provided Draw indices in combination with the render pass indices.")
    assert(0);

    return { 0, 0 };
}

size_t DrawCallsDumpingContext::CmdBufToDCVectorIndex(size_t cmd_buf_index) const
{
    assert(cmd_buf_index < command_buffers_.size());

    if (options_.dump_resources_before)
    {
        assert(cmd_buf_index / 2 < dc_indices_.size());

        return cmd_buf_index / 2;
    }
    else
    {
        assert(cmd_buf_index < dc_indices_.size());

        return cmd_buf_index;
    }
}

uint32_t DrawCallsDumpingContext::GetDrawCallActiveCommandBuffers(CommandBufferIterator& first,
                                                                  CommandBufferIterator& last) const
{
    GFXRECON_ASSERT(current_cb_index_ <= command_buffers_.size());
    first = command_buffers_.begin() + static_cast<int>(current_cb_index_);
    last  = command_buffers_.end();
    return current_cb_index_;
}

void DrawCallsDumpingContext::BeginRendering(const std::vector<VulkanImageInfo*>& color_attachments,
                                             const std::vector<VkImageLayout>&    color_attachment_layouts,
                                             VulkanImageInfo*                     depth_attachment,
                                             VkImageLayout                        depth_attachment_layout,
                                             const VkRect2D&                      render_area)
{
    assert(color_attachments.size() == color_attachment_layouts.size());
    assert(current_render_pass_type_ == kNone);

    current_render_pass_type_ = kDynamicRendering;

    for (size_t i = 0; i < color_attachments.size(); ++i)
    {
        color_attachments[i]->intermediate_layout = color_attachment_layouts[i];
    }

    if (depth_attachment != nullptr)
    {
        depth_attachment->intermediate_layout = depth_attachment_layout;
    }

    SetRenderTargets(color_attachments, depth_attachment, true);
    SetRenderArea(render_area);

    auto [new_entry_it, success] = dynamic_rendering_attachment_layouts_.emplace(
        std::piecewise_construct, std::forward_as_tuple(current_renderpass_), std::forward_as_tuple());
    GFXRECON_ASSERT(success);

    new_entry_it->second.is_dynamic               = true;
    new_entry_it->second.color_attachment_layouts = color_attachment_layouts;
    new_entry_it->second.depth_attachment_layout  = depth_attachment_layout;
}

void DrawCallsDumpingContext::AssignSecondary(uint64_t                 execute_commands_index,
                                              DrawCallsDumpingContext* secondary_context)
{
    GFXRECON_ASSERT(secondary_context);

    secondaries_[execute_commands_index].push_back(secondary_context);
    secondary_context->command_buffer_level_ = DumpResourcesCommandBufferLevel::kSecondary;
}

uint32_t DrawCallsDumpingContext::RecaclulateCommandBuffers()
{
    uint32_t n_command_buffers = command_buffers_.size();

    if (secondaries_.empty())
    {
        return n_command_buffers;
    }

    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            const size_t secondary_n_command_buffers = secondary_context->RecaclulateCommandBuffers();
            if (!secondary_n_command_buffers)
            {
                return n_command_buffers;
            }

            n_command_buffers += secondary_n_command_buffers;

            // Merge draw call indices into primary
            std::vector<decode::Index>& secondary_dc_indices = secondary_context->GetDrawCallIndices();
            dc_indices_.reserve(n_command_buffers);
            dc_indices_.insert(dc_indices_.end(), secondary_dc_indices.begin(), secondary_dc_indices.end());
            std::sort(dc_indices_.begin(), dc_indices_.end());
        }
    }

    GFXRECON_ASSERT(n_command_buffers >= command_buffers_.size())
    command_buffers_.resize(n_command_buffers);

    return n_command_buffers;
}

void DrawCallsDumpingContext::UpdateSecondaries()
{
    // The purpose of this function is to transfer rendering context from a primary to its secondaries.
    // This function must be called only for primary command buffer contexes, even if a secondary has secondaries.
    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary);

    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            secondary_context->SecondaryUpdateContextFromPrimary(bound_gr_pipeline_,
                                                                 bound_vertex_buffers_,
                                                                 bound_index_buffer_,
                                                                 dynamic_vertex_input_state_,
                                                                 bound_descriptor_sets_gr_);
        }
    }

    // Move secondary draw call parameters to primary's list of draw call params.
    // When DumpDrawCalls is called it's better to have all draw call parameters available in the primary which is
    // submitted.
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            DrawCallParameters& secondary_dc_params = secondary_context->GetDrawCallParameters();
            for (auto& secondary_dc_param : secondary_dc_params)
            {
                const auto new_entry = draw_call_params_.insert(
                    std::make_pair(secondary_dc_param.first, std::move(secondary_dc_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_dc_params.clear();
        }
    }
}

void DrawCallsDumpingContext::SecondaryUpdateContextFromPrimary(const VulkanPipelineInfo*     gr_pipeline,
                                                                const BoundVertexBuffersInfo& vertex_buffers,
                                                                const BoundIndexBuffer&       index_buffer,
                                                                const VertexInputState&       dynamic_vertex_input,
                                                                const BoundDescriptorSets&    descriptor_sets)
{
    // This function must be called only for secondary command buffer contexes
    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kSecondary);

    // Recursively update secondaries of secondary
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            secondary_context->SecondaryUpdateContextFromPrimary(
                gr_pipeline, vertex_buffers, index_buffer, dynamic_vertex_input, descriptor_sets);
        }
    }

    // Having updated all secondary's context attributes update its dc params.
    // Secondary command buffer can inherit state from the primary. Part of that state that we care about are the bound
    // descriptors and the vertex input state. If that state is missing from the secondary then we get it from the
    // primary. The best time to do this is when vkCmdExecuteCommands is called.
    for (auto& dc : draw_call_params_)
    {
        GFXRECON_ASSERT(dc.second);

        gfxrecon::decode::CopyVertexInputStateInfo(
            *dc.second, gr_pipeline, dynamic_vertex_input, vertex_buffers, index_buffer);
        gfxrecon::decode::SnapshotBoundDescriptors(*dc.second, gr_pipeline, descriptor_sets);
    }

    // Move secondary draw call parameters to primary's list of draw call params.
    // When DumpDrawCalls is called it's better to have all draw call parameters available in the primary which is
    // submitted.
    for (auto& execute_commands : secondaries_)
    {
        for (auto& secondary_context : execute_commands.second)
        {
            DrawCallParameters& secondary_dc_params = secondary_context->GetDrawCallParameters();
            for (auto& secondary_dc_param : secondary_dc_params)
            {
                const auto new_entry = draw_call_params_.insert(
                    std::make_pair(secondary_dc_param.first, std::move(secondary_dc_param.second)));
                GFXRECON_ASSERT(new_entry.second);
            }
            secondary_dc_params.clear();
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
