/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/vulkan_replay_dump_resources_windows.h"

#include "decode/vulkan_command_buffer_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <ranges>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

DumpingContextWindows::DumpingContextWindows(const CommandIndices*      draw_indices,
                                             const CommandIndices*      dispatch_indices,
                                             const CommandIndices*      trace_rays_indices,
                                             const RenderPassIndices*   renderpass_indices,
                                             CommonObjectInfoTable&     object_info_table,
                                             const VulkanReplayOptions& options) :
    original_command_buffer_info_(nullptr), current_cb_index_(0), options_(options), inside_renderpass_(false),
    has_tail_clone_(false), command_buffer_level_(DumpResourcesCommandBufferLevel::kPrimary),
    object_info_table_(object_info_table)
{
    // Every dumped command of the command buffer is a slot, in block index order. Each kind's indices are sorted
    // (the dump args parser checks that), so the three rows are merged.
    const auto append_slots = [this](const CommandIndices* indices, WindowSlot::Kind kind) {
        if (indices != nullptr)
        {
            for (const Index index : *indices)
            {
                slots_.push_back({ index, UNDEFINED_INDEX, kind });
            }
        }
    };
    append_slots(draw_indices, WindowSlot::Kind::kDraw);
    append_slots(dispatch_indices, WindowSlot::Kind::kDispatch);
    append_slots(trace_rays_indices, WindowSlot::Kind::kTraceRays);
    std::sort(slots_.begin(), slots_.end(), [](const WindowSlot& a, const WindowSlot& b) { return a.index < b.index; });

    const size_t n_cmd_buffs = options_.dump_resources_before ? 2 * slots_.size() : slots_.size();
    command_buffers_.resize(n_cmd_buffs, VK_NULL_HANDLE);

    if (renderpass_indices != nullptr)
    {
        RP_indices_ = *renderpass_indices;
    }
}

DumpingContextWindows::~DumpingContextWindows()
{
    Release();
}

void DumpingContextWindows::Release()
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
        assert(device_table_.IsValid());

        const VulkanCommandPoolInfo* pool_info =
            object_info_table_.GetVkCommandPoolInfo(original_command_buffer_info_->pool_id);
        assert(pool_info);

        auto injected = device_table_.Open();

        if (!command_buffers_.empty())
        {
            injected->FreeCommandBuffers(device,
                                         pool_info->handle,
                                         GFXRECON_NARROWING_CAST(uint32_t, command_buffers_.size()),
                                         command_buffers_.data());
        }
        command_buffers_.clear();

        // cleanup cloned renderpasses
        for (const auto& rps : render_pass_contexts_)
        {
            for (VkRenderPass renderpass : rps->render_pass_clones)
            {
                if (renderpass != VK_NULL_HANDLE)
                {
                    injected->DestroyRenderPass(device, renderpass, nullptr);
                }
            }

            for (const auto& renderpass : rps->render_pass_load_clones | std::views::values)
            {
                if (renderpass != VK_NULL_HANDLE)
                {
                    injected->DestroyRenderPass(device, renderpass, nullptr);
                }
            }
        }
        render_pass_contexts_.clear();
        inside_renderpass_ = false;

        original_command_buffer_info_ = nullptr;
    }

    slots_.clear();
    RP_indices_.clear();

    current_cb_index_ = 0;
    has_tail_clone_   = false;
}

void DumpingContextWindows::SetSlotOwner(WindowSlot::Kind kind, const std::shared_ptr<DumpingContextBase>& owner)
{
    slot_owners_[static_cast<size_t>(kind)] = owner;
}

std::shared_ptr<DumpingContextBase> DumpingContextWindows::GetSlotOwner(WindowSlot::Kind kind) const
{
    return slot_owners_[static_cast<size_t>(kind)].lock();
}

std::vector<std::pair<WindowSlot::Kind, std::shared_ptr<DumpingContextBase>>>
DumpingContextWindows::GetDistinctSlotOwners() const
{
    std::vector<std::pair<WindowSlot::Kind, std::shared_ptr<DumpingContextBase>>> owners;
    for (size_t kind = 0; kind < static_cast<size_t>(WindowSlot::Kind::kKindCount); ++kind)
    {
        std::shared_ptr<DumpingContextBase> owner = slot_owners_[kind].lock();
        if (owner != nullptr &&
            std::none_of(owners.begin(), owners.end(), [&owner](const auto& entry) { return entry.second == owner; }))
        {
            owners.emplace_back(static_cast<WindowSlot::Kind>(kind), std::move(owner));
        }
    }

    return owners;
}

VkResult DumpingContextWindows::BeginCommandBuffer(VulkanCommandBufferInfo*                   orig_cmd_buf_info,
                                                   const graphics::VulkanInjectedDeviceCalls& dev_table,
                                                   const VkCommandBufferBeginInfo*            begin_info)
{
    GFXRECON_ASSERT(orig_cmd_buf_info);
    GFXRECON_ASSERT(dev_table.IsValid());

    GFXRECON_ASSERT(original_command_buffer_info_ == nullptr);
    original_command_buffer_info_ = orig_cmd_buf_info;

    GFXRECON_ASSERT(!device_table_.IsValid());
    device_table_ = dev_table;

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

    auto injected = dev_table.Open();
    for (auto& command_buffer : command_buffers_)
    {
        GFXRECON_ASSERT(command_buffer == VK_NULL_HANDLE);
        VkResult res = injected->AllocateCommandBuffers(dev_info->handle, &ai, &command_buffer);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        res = injected.BeginCommandBuffer(command_buffer, begin_info, "DumpingContextWindows::BeginCommandBuffer");
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("BeginCommandBuffer failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

std::shared_ptr<DumpingContextWindows::RenderPassContext> DumpingContextWindows::EndRenderPassInWindow()
{
    assert(current_cb_index_ < GetWindowCount());
    assert(device_table_.IsValid());

    // When calling CmdEndRenderPass/CmdEndRendering we need to distinguish the following two cases:
    // 1. While inside a render pass then we need to call it once from the primary right after CmdExecuteCommands
    // 2. For dynamic rendering we need to make sure that we call CmdEndRendering only once, either from the secondary
    // (it that's the case) or from the primary
    // inside_renderpass_ guards against ending a render pass that this context does not currently have active:
    // render_pass_contexts_ keeps finished render passes, so back() alone does not imply an active instance.
    if (!inside_renderpass_ || render_pass_contexts_.empty() ||
        (render_pass_contexts_.back()->cmd_buf_level != command_buffer_level_))
    {
        return nullptr;
    }

    const VkCommandBuffer                    current_command_buffer = command_buffers_[current_cb_index_];
    const std::shared_ptr<RenderPassContext> current_rp_context     = render_pass_contexts_.back();

    // Correlate this slot with the render pass it is being finalized in. Commands from secondaries that
    // inherit the primary's render pass are correlated here as well, when UpdateSecondaries finalizes them
    // from within the primary at vkCmdExecuteCommands time. With --dump-resources-before the "before" and
    // "after" clones map to the same slot and are finalized inside the same render pass.
    GFXRECON_ASSERT(!current_rp_context->render_targets.empty());
    WindowSlot& slot         = slots_[WindowToSlotIndex(current_cb_index_)];
    slot.render_pass_context = current_rp_context;
    slot.subpass             = current_rp_context->render_targets.size() - 1;

    if (current_rp_context->type == RenderPassType::kRenderPass)
    {
        auto injected = device_table_.Open();
        injected->CmdEndRenderPass(current_command_buffer);
    }
    else if (current_rp_context->type == RenderPassType::kDynamicRendering)
    {
        RecordCmdEndRendering(current_command_buffer);
    }

    return current_rp_context;
}

void DumpingContextWindows::EndWindow()
{
    assert(current_cb_index_ < GetWindowCount());
    assert(device_table_.IsValid());

    auto injected = device_table_.Open();
    injected->EndCommandBuffer(command_buffers_[current_cb_index_]);

    // Increment index of command buffer that is going to be finalized next
    ++current_cb_index_;
}

VkResult DumpingContextWindows::SubmitAndDump(VkQueue              queue,
                                              const VkSubmitInfo2& submit_info,
                                              Index                submit_info_index,
                                              Index                submit_info_cmd_buf_index)
{
    const size_t window_count = GetWindowCount();

    // the tail clone holds work following the last target command. it is submitted after the windows.
    const VkCommandBuffer tail_command_buffer = GetTailCommandBuffer();
    const size_t          submission_count    = window_count + (tail_command_buffer != VK_NULL_HANDLE ? 1 : 0);

    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    GFXRECON_ASSERT(device_info);

    TemporaryFence submission_fence(device_info->handle, device_table_);

    // Forward the original submit's wait semaphores only on the first clone and its signal semaphores only on the
    // last one, so the application-visible synchronization is preserved across the split submissions.
    const auto submit_clone = [&](VkCommandBuffer clone, size_t submission) -> VkResult {
        const VkCommandBufferSubmitInfo cb_info{
            VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, nullptr, clone, 0 /* deviceMask */
        };

        const bool first = (submission == 0);
        const bool last  = (submission == (submission_count - 1));

        VkSubmitInfo2 si{};
        si.sType                    = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
        si.pNext                    = submit_info.pNext;
        si.flags                    = submit_info.flags;
        si.waitSemaphoreInfoCount   = first ? submit_info.waitSemaphoreInfoCount : 0;
        si.pWaitSemaphoreInfos      = first ? submit_info.pWaitSemaphoreInfos : nullptr;
        si.commandBufferInfoCount   = 1;
        si.pCommandBufferInfos      = &cb_info;
        si.signalSemaphoreInfoCount = last ? submit_info.signalSemaphoreInfoCount : 0;
        si.pSignalSemaphoreInfos    = last ? submit_info.pSignalSemaphoreInfos : nullptr;

        VkResult res =
            SubmitInfo2OnQueue(device_table_, device_info->version_extension_info, queue, si, submission_fence.handle);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = submission_fence.Wait();
        if (res != VK_SUCCESS)
        {
            return res;
        }

        // Reset fence for next submission
        return submission_fence.Reset();
    };

    // Run the windows. The window just executed ends with the command of its slot (or, with
    // --dump-resources-before, right before it), so the original resources hold what must be dumped.
    for (size_t cb = 0; cb < window_count; ++cb)
    {
        VkResult res = submit_clone(command_buffers_[cb], cb);
        if (res != VK_SUCCESS)
        {
            return res;
        }

        // If options_.dump_resources_before is true, it means that we have two command buffer clones for each
        // slot. In this case WindowToSlotIndex will return the command buffer index divided by 2 so it can be used
        // to index inside slots_
        const WindowSlot& slot = slots_[WindowToSlotIndex(cb)];

        const std::shared_ptr<DumpingContextBase> owner = GetSlotOwner(slot.kind);
        GFXRECON_ASSERT(owner != nullptr);
        if (owner == nullptr)
        {
            GFXRECON_LOG_ERROR("There is no dumping context to dump the command with index %" PRIu64, slot.index);
            return VK_ERROR_UNKNOWN;
        }

        res = owner->DumpSlot(slot, cb, queue, submit_info_index, submit_info_cmd_buf_index);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    if (tail_command_buffer != VK_NULL_HANDLE)
    {
        VkResult res = submit_clone(tail_command_buffer, submission_count - 1);
        if (res != VK_SUCCESS)
        {
            return res;
        }
    }

    // Clean up some state in case this command buffer is submitted again
    for (const auto& [kind, owner] : GetDistinctSlotOwners())
    {
        owner->ResetDumpedResources();
    }

    GFXRECON_LOG_INFO("Done.")

    return VK_SUCCESS;
}

std::vector<std::shared_ptr<DumpingContextWindows>> DumpingContextWindows::GetSecondaries() const
{
    std::vector<std::shared_ptr<DumpingContextWindows>> all_secondaries;
    for (const auto& secondaries : secondaries_ | std::views::values)
    {
        all_secondaries.insert(all_secondaries.end(), secondaries.begin(), secondaries.end());
    }

    return all_secondaries;
}

void DumpingContextWindows::UpdateSecondaries(DumpingContextWindows& secondary_windows,
                                              Index                  execute_cmd_index,
                                              Index                  command_buffer_execute_index)
{
    // The purpose of this function is to transfer rendering context from a primary to its secondaries.
    // This function must be called only for primary command buffer contexes, even if a secondary has secondaries.
    GFXRECON_ASSERT(command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary);

    // Each owner hands the state a secondary can inherit down to the secondary's owner of the same kind
    for (const auto& [kind, owner] : GetDistinctSlotOwners())
    {
        const std::shared_ptr<DumpingContextBase> secondary_owner = secondary_windows.GetSlotOwner(kind);
        if (secondary_owner != nullptr)
        {
            owner->PrepareSecondary(*secondary_owner);
        }
    }

    // The primary takes over the slots of the secondary and finalizes one of its own slots for each of them. The
    // primary's windows run the secondary's windows one after the other, so this follows the secondary's own slot
    // order, with the commands of the different owners interleaved as they were recorded.
    for (const WindowSlot& secondary_slot : secondary_windows.GetSlots())
    {
        // The slot the owner is going to finalize
        const size_t primary_slot_index = WindowToSlotIndex(current_cb_index_);
        GFXRECON_ASSERT(slots_[primary_slot_index].kind == secondary_slot.kind);

        const std::shared_ptr<DumpingContextBase> owner           = GetSlotOwner(secondary_slot.kind);
        const std::shared_ptr<DumpingContextBase> secondary_owner = secondary_windows.GetSlotOwner(secondary_slot.kind);
        GFXRECON_ASSERT(owner != nullptr && secondary_owner != nullptr);
        if (owner != nullptr && secondary_owner != nullptr)
        {
            owner->ExecuteSecondarySlot(
                *secondary_owner, secondary_slot, execute_cmd_index, command_buffer_execute_index);
        }
        else
        {
            // Nobody dumps this slot. Its windows still have to close for the ones that follow to line up.
            FinalizeWindow();
            if (options_.dump_resources_before)
            {
                FinalizeWindow();
            }
        }

        // A secondary that begins its own render pass instance (dynamic rendering) is executed outside any render
        // pass of the primary, so the primary could not correlate the slot above. The secondary correlated its own
        // slot when its window closed, so take the render pass context from there.
        WindowSlot& primary_slot = slots_[primary_slot_index];
        if (primary_slot.render_pass_context == nullptr)
        {
            primary_slot.render_pass_context = secondary_slot.render_pass_context;
            primary_slot.subpass             = secondary_slot.subpass;
        }
    }
}

// Find the subpass interval of the given render pass block range that contains the given block index
static bool FindSubpassInRange(const std::vector<uint64_t>& render_pass, uint64_t block_index, uint64_t& sp)
{
    for (uint64_t s = 0; s + 1 < render_pass.size(); ++s)
    {
        if (block_index > render_pass[s] && block_index < render_pass[s + 1])
        {
            sp = s;
            return true;
        }
    }

    return false;
}

PFN_vkCmdBeginRendering DumpingContextWindows::ResolveCmdBeginRendering(
    const graphics::VulkanInjectedDeviceCalls::Scope& injected_commands_scope) const
{
    GFXRECON_ASSERT(original_command_buffer_info_ != nullptr);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    const auto raw_table = injected_commands_scope.GetTable();
    return device_info->version_extension_info.SelectApiCallFlavor(VK_API_VERSION_1_3,
                                                                   raw_table->CmdBeginRendering,
                                                                   VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME,
                                                                   raw_table->CmdBeginRenderingKHR);
}

PFN_vkCmdEndRendering DumpingContextWindows::ResolveCmdEndRendering(
    const graphics::VulkanInjectedDeviceCalls::Scope& injected_commands_scope) const
{
    GFXRECON_ASSERT(original_command_buffer_info_ != nullptr);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    const auto raw_table = injected_commands_scope.GetTable();
    return device_info->version_extension_info.SelectApiCallFlavor(VK_API_VERSION_1_3,
                                                                   raw_table->CmdEndRendering,
                                                                   VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME,
                                                                   raw_table->CmdEndRenderingKHR);
}

void DumpingContextWindows::RecordCmdBeginRendering(VkCommandBuffer        command_buffer,
                                                    const VkRenderingInfo* rendering_info) const
{
    auto                          injected            = device_table_.Open();
    const PFN_vkCmdBeginRendering cmd_begin_rendering = ResolveCmdBeginRendering(injected);
    if (cmd_begin_rendering != nullptr)
    {
        cmd_begin_rendering(command_buffer, rendering_info);
    }
}

void DumpingContextWindows::RecordCmdEndRendering(VkCommandBuffer command_buffer) const
{
    auto                        injected          = device_table_.Open();
    const PFN_vkCmdEndRendering cmd_end_rendering = ResolveCmdEndRendering(injected);
    if (cmd_end_rendering != nullptr)
    {
        cmd_end_rendering(command_buffer);
    }
}

bool DumpingContextWindows::ShouldHandleRenderPass(uint64_t index) const
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

template <typename CreateInfoType>
void DumpingContextWindows::ParseAttachmentsInRenderPassCreateInfo(const VulkanRenderPassInfo*       render_pass_info,
                                                                   const CreateInfoType*             ci,
                                                                   const VulkanFramebufferInfo*      framebuffer_info,
                                                                   uint32_t                          subpass,
                                                                   RenderPassContext::RenderTargets& render_targets)
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
            img_view_info = object_info_table_.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[att_idx]);
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            GFXRECON_ASSERT(render_pass_info->begin_renderpass_override_attachments.size() >
                            static_cast<size_t>(att_idx));

            img_view_info =
                object_info_table_.GetVkImageViewInfo(render_pass_info->begin_renderpass_override_attachments[att_idx]);
        }
        else
        {
            GFXRECON_LOG_WARNING("unhandled missing color-attachment in %s", __func__);
            continue;
        }

        GFXRECON_ASSERT(img_view_info != nullptr);
        VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_view_info->image_id);
        GFXRECON_ASSERT(img_info != nullptr);

        render_targets.color_att_imgs.push_back(img_info);
        render_targets.color_attachment_layouts.push_back(ci->pAttachments[att_idx].finalLayout);
    }

    // Detect depth attachment
    if (ci->pSubpasses[subpass].pDepthStencilAttachment != nullptr &&
        ci->pSubpasses[subpass].pDepthStencilAttachment->attachment != VK_ATTACHMENT_UNUSED)
    {
        const VulkanImageViewInfo* depth_img_view_info = nullptr;
        const uint32_t             depth_att_idx       = ci->pSubpasses[subpass].pDepthStencilAttachment->attachment;

        if (depth_att_idx < framebuffer_info->attachment_image_view_ids.size())
        {
            depth_img_view_info =
                object_info_table_.GetVkImageViewInfo(framebuffer_info->attachment_image_view_ids[depth_att_idx]);
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            GFXRECON_ASSERT(render_pass_info->begin_renderpass_override_attachments.size() >
                            static_cast<size_t>(depth_att_idx));

            depth_img_view_info = object_info_table_.GetVkImageViewInfo(
                render_pass_info->begin_renderpass_override_attachments[depth_att_idx]);
        }
        else
        {
            GFXRECON_LOG_WARNING("unhandled missing depth-attachment in %s", __func__);
        }

        if (depth_img_view_info != nullptr)
        {
            render_targets.depth_attachment_layout = ci->pAttachments[depth_att_idx].finalLayout;
            render_targets.depth_att_img           = object_info_table_.GetVkImageInfo(depth_img_view_info->image_id);
            GFXRECON_ASSERT(render_targets.depth_att_img != nullptr);
        }
        else
        {
            render_targets.depth_att_img = nullptr;
        }
    }
}

template <typename CreateInfoType>
static void UpdateOriginalCommandBufferWithNewImageLayouts(const VulkanRenderPassInfo*  render_pass_info,
                                                           const CreateInfoType*        original_render_pass_ci,
                                                           const VulkanFramebufferInfo* framebuffer_info,
                                                           CommonObjectInfoTable&       object_info_table,
                                                           VulkanCommandBufferInfo*     original_command_buffer_info)
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

            GFXRECON_ASSERT(att_img_view_info != nullptr);

            VulkanImageInfo* att_img_info = object_info_table.GetVkImageInfo(att_img_view_info->image_id);
            if (att_img_info != nullptr)
            {
                InitializeCommandBufferImageLayouts(original_command_buffer_info, att_img_info);
                original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id].SetLayout(
                    att_img_view_info->subresource_range, att_ref.layout);
            }
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
        }
        else if (!render_pass_info->begin_renderpass_override_attachments.empty())
        {
            att_img_view_info = object_info_table.GetVkImageViewInfo(
                render_pass_info->begin_renderpass_override_attachments[depth_att_idx]);
        }

        if (att_img_view_info != nullptr)
        {
            VulkanImageInfo* att_img_info = object_info_table.GetVkImageInfo(att_img_view_info->image_id);
            if (att_img_info != nullptr)
            {
                InitializeCommandBufferImageLayouts(original_command_buffer_info, att_img_info);
                original_command_buffer_info->image_layout_barriers[att_img_view_info->image_id].SetLayout(
                    att_img_view_info->subresource_range,
                    original_render_pass_ci->pSubpasses[0].pDepthStencilAttachment->layout);
            }
        }
    }
}

// Force attachment writes to be stored. Final layouts are left untouched: TransitionRenderTargetLayouts records
// explicit barriers out of the original final layouts, so the cloned render pass must end in them as well.
template <typename AttachmentDescriptionType>
static void FixAttachmentStoreOps(std::vector<AttachmentDescriptionType>& attachments)
{
    for (auto& att : attachments)
    {
        att.storeOp = VK_ATTACHMENT_STORE_OP_STORE;

        if (vkuFormatHasStencil(att.format))
        {
            att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
        }
    }
}

// The subpass each attachment is first used in, kNeverUsed for one that no subpass references. A render pass
// performs an attachment's load operation when the subpass that first uses it begins.
template <typename CreateInfoType>
static std::vector<uint32_t> FirstUseSubpassPerAttachment(const CreateInfoType* create_info)
{
    std::vector<uint32_t> first_use(create_info->attachmentCount, DumpingContextWindows::kNeverUsed);

    const auto use = [&first_use](uint32_t attachment, uint32_t subpass) {
        if (attachment != VK_ATTACHMENT_UNUSED && attachment < first_use.size() && subpass < first_use[attachment])
        {
            first_use[attachment] = subpass;
        }
    };

    for (uint32_t sub = 0; sub < create_info->subpassCount; ++sub)
    {
        const auto& subpass = create_info->pSubpasses[sub];

        for (uint32_t i = 0; i < subpass.colorAttachmentCount; ++i)
        {
            use(subpass.pColorAttachments[i].attachment, sub);

            if (subpass.pResolveAttachments != nullptr)
            {
                use(subpass.pResolveAttachments[i].attachment, sub);
            }
        }

        for (uint32_t i = 0; i < subpass.inputAttachmentCount; ++i)
        {
            use(subpass.pInputAttachments[i].attachment, sub);
        }

        if (subpass.pDepthStencilAttachment != nullptr)
        {
            use(subpass.pDepthStencilAttachment->attachment, sub);
        }
    }

    return first_use;
}

// load what the previous window stored, for attachments it 'could' have written in 'subpass -> resume_subpass'.
// an attachment the previous window never reached keeps the original ops:
// -> clear still happens, in the window that first enters the subpass using it.
// -> attachments are in their original finalLayout at window boundaries, used or not.
template <typename AttachmentDescriptionType>
static void FixAttachmentLoadOps(std::vector<AttachmentDescriptionType>& attachments,
                                 const std::vector<uint32_t>&            first_use_subpass,
                                 uint32_t                                resume_subpass)
{
    GFXRECON_ASSERT(attachments.size() == first_use_subpass.size());

    for (size_t i = 0; i < attachments.size(); ++i)
    {
        auto& att = attachments[i];

        if (first_use_subpass[i] <= resume_subpass)
        {
            att.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;

            if (vkuFormatHasStencil(att.format))
            {
                att.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
            }
        }

        att.initialLayout = att.finalLayout;
    }
}

template <typename CreateInfoType>
void DumpingContextWindows::FinalizeRenderPassClone(RenderPassContext&    renderpass_context,
                                                    const CreateInfoType* create_info)
{
    // Get render targets info of current renderpass/subpass
    GFXRECON_ASSERT(renderpass_context.render_targets.empty());
    auto& new_render_targets = renderpass_context.render_targets.emplace_back();
    ParseAttachmentsInRenderPassCreateInfo(
        renderpass_context.renderpass_info, create_info, renderpass_context.framebuffer_info, 0, new_render_targets);

    // Update tracked layouts in VulkanCommandBufferInfo
    UpdateOriginalCommandBufferWithNewImageLayouts(renderpass_context.renderpass_info,
                                                   create_info,
                                                   renderpass_context.framebuffer_info,
                                                   object_info_table_,
                                                   original_command_buffer_info_);
}

VkResult DumpingContextWindows::CloneRenderPass(RenderPassContext& renderpass_context)
{
    const auto* original_render_pass_ci =
        reinterpret_cast<const VkRenderPassCreateInfo*>(renderpass_context.renderpass_info->create_info.data());

    std::vector<VkAttachmentDescription> modified_attachments(original_render_pass_ci->pAttachments,
                                                              original_render_pass_ci->pAttachments +
                                                                  original_render_pass_ci->attachmentCount);

    FixAttachmentStoreOps(modified_attachments);

    const std::vector<uint32_t> first_use_subpass = FirstUseSubpassPerAttachment(original_render_pass_ci);

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
        }

        auto& new_subp_desc = subpass_descs.emplace_back();
        new_subp_desc       = original_render_pass_ci->pSubpasses[sub];

        VkRenderPassCreateInfo ci;
        ci.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        ci.flags = original_render_pass_ci->flags;
        GFXRECON_NARROWING_ASSIGN(ci.attachmentCount, modified_attachments.size());
        ci.pAttachments = modified_attachments.empty() ? nullptr : modified_attachments.data();

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        GFXRECON_NARROWING_ASSIGN(ci.dependencyCount, modified_dependencies.size());
        ci.pDependencies = modified_dependencies.empty() ? nullptr : modified_dependencies.data();

        ci.pNext = original_render_pass_ci->pNext;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        VkDevice device = device_info->handle;

        auto          injected        = device_table_.Open();
        VkRenderPass& new_render_pass = renderpass_context.render_pass_clones.emplace_back();
        VkResult      res             = injected->CreateRenderPass(device, &ci, nullptr, &new_render_pass);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        // One LOAD variant per subpass a window can resume this render pass in
        for (uint32_t resume = 0; resume <= sub; ++resume)
        {
            std::vector<VkAttachmentDescription> load_attachments = modified_attachments;
            FixAttachmentLoadOps(load_attachments, first_use_subpass, resume);
            ci.pAttachments = load_attachments.empty() ? nullptr : load_attachments.data();

            VkRenderPass& load_render_pass = renderpass_context.render_pass_load_clones[{ resume, sub }];
            res                            = injected->CreateRenderPass(device, &ci, nullptr, &load_render_pass);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
                return res;
            }
        }
    }

    FinalizeRenderPassClone(renderpass_context, original_render_pass_ci);

    return VK_SUCCESS;
}

VkResult DumpingContextWindows::CloneRenderPass2(RenderPassContext& renderpass_context)
{
    auto* original_render_pass_ci =
        reinterpret_cast<const VkRenderPassCreateInfo2*>(renderpass_context.renderpass_info->create_info.data());

    std::vector<VkAttachmentDescription2> modified_attachments(original_render_pass_ci->pAttachments,
                                                               original_render_pass_ci->pAttachments +
                                                                   original_render_pass_ci->attachmentCount);

    FixAttachmentStoreOps(modified_attachments);

    const std::vector<uint32_t> first_use_subpass = FirstUseSubpassPerAttachment(original_render_pass_ci);

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
        }

        auto& new_subp_desc = subpass_descs.emplace_back();
        new_subp_desc       = original_render_pass_ci->pSubpasses[sub];

        VkRenderPassCreateInfo2 ci;
        // VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2 and VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR are equal so
        // it doesn't matter which one we use
        ci.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
        ci.flags = original_render_pass_ci->flags;
        GFXRECON_NARROWING_ASSIGN(ci.attachmentCount, modified_attachments.size());
        ci.pAttachments = modified_attachments.empty() ? nullptr : modified_attachments.data();

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        GFXRECON_NARROWING_ASSIGN(ci.dependencyCount, modified_dependencies.size());
        ci.pDependencies = modified_dependencies.empty() ? nullptr : modified_dependencies.data();

        ci.correlatedViewMaskCount = original_render_pass_ci->correlatedViewMaskCount;
        ci.pCorrelatedViewMasks    = original_render_pass_ci->pCorrelatedViewMasks;
        ci.pNext                   = original_render_pass_ci->pNext;

        const VulkanDeviceInfo* device_info =
            object_info_table_.GetVkDeviceInfo(original_command_buffer_info_->parent_id);
        VkDevice device = device_info->handle;

        VkResult      res;
        auto          injected        = device_table_.Open();
        VkRenderPass& new_render_pass = renderpass_context.render_pass_clones.emplace_back();
        if (renderpass_context.renderpass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass2)
        {
            res = injected->CreateRenderPass2(device, &ci, nullptr, &new_render_pass);
        }
        else
        {
            GFXRECON_ASSERT(renderpass_context.renderpass_info->func_version ==
                            VulkanRenderPassInfo::kCreateRenderPass2KHR);
            res = injected->CreateRenderPass2KHR(device, &ci, nullptr, &new_render_pass);
        }

        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        // One LOAD variant per subpass a window can resume this render pass in
        for (uint32_t resume = 0; resume <= sub; ++resume)
        {
            std::vector<VkAttachmentDescription2> load_attachments = modified_attachments;
            FixAttachmentLoadOps(load_attachments, first_use_subpass, resume);
            ci.pAttachments = load_attachments.empty() ? nullptr : load_attachments.data();

            VkRenderPass& load_render_pass = renderpass_context.render_pass_load_clones[{ resume, sub }];
            if (renderpass_context.renderpass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass2)
            {
                res = injected->CreateRenderPass2(device, &ci, nullptr, &load_render_pass);
            }
            else
            {
                res = injected->CreateRenderPass2KHR(device, &ci, nullptr, &load_render_pass);
            }

            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
                return res;
            }
        }
    }

    FinalizeRenderPassClone(renderpass_context, original_render_pass_ci);

    return VK_SUCCESS;
}

VkResult DumpingContextWindows::BeginRenderPass(uint64_t                     block_index,
                                                const VulkanRenderPassInfo*  render_pass_info,
                                                const VulkanFramebufferInfo* framebuffer_info,
                                                const VkRenderPassBeginInfo* renderpass_begin_info,
                                                VkSubpassContents            contents)
{
    GFXRECON_ASSERT(render_pass_info != nullptr);
    GFXRECON_ASSERT(framebuffer_info != nullptr);
    GFXRECON_ASSERT(renderpass_begin_info != nullptr);
    GFXRECON_ASSERT(!render_pass_info->create_info.empty());

    auto& new_render_pass_context = render_pass_contexts_.emplace_back(
        std::make_shared<RenderPassContext>(render_pass_info, framebuffer_info, command_buffer_level_));
    new_render_pass_context->begin_block_index = block_index;

    VkResult res;
    if (render_pass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        res = CloneRenderPass(*new_render_pass_context);
    }
    else
    {
        res = CloneRenderPass2(*new_render_pass_context);
    }

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed cloning render pass (%s).", util::ToString<VkResult>(res).c_str())
        return res;
    }

    // Find this render pass' block index range. It determines which of the remaining draw calls (and executed
    // secondaries) fall inside this render pass and therefore replay with the cloned render pass.
    const std::vector<Index>* block_range = FindRenderPassBlockRange(block_index);

    // The range holds the begin, one entry per vkCmdNextSubpass and the end.
    // Any other size does not match this render pass, e.g. a stale or hand-edited json.
    const size_t subpass_count = new_render_pass_context->render_pass_clones.size();
    if (block_range != nullptr && block_range->size() != subpass_count + 1)
    {
        GFXRECON_LOG_FATAL("Dump resources: the range of the render pass at block %" PRIu64
                           " has %zu entries, but the render pass has %zu subpass(es) and needs %zu entries.",
                           block_index,
                           block_range->size(),
                           subpass_count,
                           subpass_count + 1);
    }

    // Add vkCmdBeginRenderPass into the cloned command buffers using the modified render pass
    CommandBufferIterator first, last;
    GetActiveCommandBuffers(first, last);

    // copy original begin-info
    VkRenderPassBeginInfo modified_renderpass_begin_info = *renderpass_begin_info;

    auto injected = device_table_.Open();

    // The render pass is begun in every clone whose window overlaps it, and those clones form a contiguous
    // range.
    const uint64_t pass_begin    = block_range != nullptr ? block_range->front() : 0;
    const uint64_t pass_end      = block_range != nullptr ? block_range->back() : 0;
    bool           found_overlap = false;

    // Find the subpass that holds the clone's target draw.
    // If the clone stops after this render pass, it runs the pass to its end, so use the last subpass.
    // A draw from a secondary is located by the vkCmdExecuteCommands that ran it.
    const auto find_subpass =
        [this, block_range, pass_end, &new_render_pass_context](size_t cmd_buf_idx, uint64_t hi, uint64_t& sp) {
            if (block_range == nullptr)
            {
                return false;
            }

            if (hi > pass_end)
            {
                sp = new_render_pass_context->render_pass_clones.size() - 1;
                return true;
            }

            const WindowSlot& slot = slots_[WindowToSlotIndex(cmd_buf_idx)];
            return slot.execute_index != UNDEFINED_INDEX ? FindSubpassInRange(*block_range, slot.execute_index, sp)
                                                         : FindSubpassInRange(*block_range, slot.index, sp);
        };

    size_t cmd_buf_idx = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        uint64_t sp = 0;
        uint64_t lo, hi;
        GetCloneWindow(cmd_buf_idx, lo, hi);
        if (lo >= pass_end || hi <= pass_begin)
        {
            continue;
        }

        find_subpass(cmd_buf_idx, hi, sp);

        // Only the window that contains the begin starts the render pass the way the application did. The
        // others resume it in the subpass the window before them ended in, and load what it stored.
        if (lo < pass_begin)
        {
            GFXRECON_ASSERT(sp < new_render_pass_context->render_pass_clones.size());
            modified_renderpass_begin_info.renderPass = new_render_pass_context->render_pass_clones[sp];
        }
        else
        {
            uint64_t resume_subpass = 0;
            FindSubpassInRange(*block_range, lo, resume_subpass);

            const auto load_clone = new_render_pass_context->render_pass_load_clones.find(
                { GFXRECON_NARROWING_CAST(uint32_t, resume_subpass), GFXRECON_NARROWING_CAST(uint32_t, sp) });
            GFXRECON_ASSERT(load_clone != new_render_pass_context->render_pass_load_clones.end());
            modified_renderpass_begin_info.renderPass = load_clone->second;
        }

        if (!found_overlap)
        {
            new_render_pass_context->first_clone = cmd_buf_idx;
            found_overlap                        = true;
        }
        new_render_pass_context->last_clone = cmd_buf_idx + 1;

        injected->CmdBeginRenderPass(*it, &modified_renderpass_begin_info, contents);
    }

    inside_renderpass_ = true;

    return VK_SUCCESS;
}

void DumpingContextWindows::NextSubpass(VkSubpassContents contents)
{
    CommandBufferIterator first, last;
    GetRenderPassCommandBuffers(first, last);
    auto injected = device_table_.Open();
    for (auto it = first; it < last; ++it)
    {
        injected->CmdNextSubpass(*it, contents);
    }

    GFXRECON_ASSERT(!render_pass_contexts_.empty());
    auto& current_render_pass_context = *render_pass_contexts_.back();

    // First increment, then query size
    auto&      new_render_targets = current_render_pass_context.render_targets.emplace_back();
    const auto current_subpass =
        GFXRECON_NARROWING_CAST(uint32_t, current_render_pass_context.render_targets.size() - 1);

    if (current_render_pass_context.renderpass_info->func_version == VulkanRenderPassInfo::kCreateRenderPass)
    {
        ParseAttachmentsInRenderPassCreateInfo(current_render_pass_context.renderpass_info,
                                               reinterpret_cast<const VkRenderPassCreateInfo*>(
                                                   current_render_pass_context.renderpass_info->create_info.data()),
                                               current_render_pass_context.framebuffer_info,
                                               current_subpass,
                                               new_render_targets);

        UpdateOriginalCommandBufferWithNewImageLayouts(
            current_render_pass_context.renderpass_info,
            reinterpret_cast<const VkRenderPassCreateInfo*>(
                current_render_pass_context.renderpass_info->create_info.data()),
            current_render_pass_context.framebuffer_info,
            object_info_table_,
            original_command_buffer_info_);
    }
    else
    {
        ParseAttachmentsInRenderPassCreateInfo(current_render_pass_context.renderpass_info,
                                               reinterpret_cast<const VkRenderPassCreateInfo2*>(
                                                   current_render_pass_context.renderpass_info->create_info.data()),
                                               current_render_pass_context.framebuffer_info,
                                               current_subpass,
                                               new_render_targets);

        UpdateOriginalCommandBufferWithNewImageLayouts(
            current_render_pass_context.renderpass_info,
            reinterpret_cast<const VkRenderPassCreateInfo2*>(
                current_render_pass_context.renderpass_info->create_info.data()),
            current_render_pass_context.framebuffer_info,
            object_info_table_,
            original_command_buffer_info_);
    }
}

void DumpingContextWindows::EndRenderPass()
{
    GFXRECON_ASSERT(!render_pass_contexts_.empty());
    GFXRECON_ASSERT(render_pass_contexts_.back()->type == RenderPassType::kRenderPass);

    CommandBufferIterator first, last;
    GetRenderPassCommandBuffers(first, last);
    auto injected = device_table_.Open();
    for (auto it = first; it < last; ++it)
    {
        injected->CmdEndRenderPass(*it);
    }

    inside_renderpass_ = false;
}

void DumpingContextWindows::EndRendering()
{
    GFXRECON_ASSERT(!render_pass_contexts_.empty());
    GFXRECON_ASSERT(render_pass_contexts_.back()->type == RenderPassType::kDynamicRendering);

    CommandBufferIterator first, last;
    GetRenderPassCommandBuffers(first, last);
    for (auto it = first; it < last; ++it)
    {
        RecordCmdEndRendering(*it);
    }

    inside_renderpass_ = false;
}

void DumpingContextWindows::EndRendering(PFN_vkCmdEndRendering2KHR    func,
                                         const VkRenderingEndInfoKHR* rendering_end_info)
{
    GFXRECON_ASSERT(!render_pass_contexts_.empty());
    GFXRECON_ASSERT(render_pass_contexts_.back()->type == RenderPassType::kDynamicRendering);

    CommandBufferIterator first, last;
    GetRenderPassCommandBuffers(first, last);
    for (auto it = first; it < last; ++it)
    {
        func(*it, rendering_end_info);
    }

    inside_renderpass_ = false;
}

// If options_.dump_resources_before is true, it means that we have two command buffer clones for each draw
// This function converts the provided command buffer index into an absolute one (divided by 2 in the case of
// dump_resources_before is true) so it can be used to index arrays that don't double their sizes in case of
// dump_resources_before is true.
size_t DumpingContextWindows::WindowToSlotIndex(size_t cmd_buf_index) const
{
    assert(cmd_buf_index < GetWindowCount());

    if (options_.dump_resources_before)
    {
        assert(cmd_buf_index / 2 < slots_.size());

        return cmd_buf_index / 2;
    }
    else
    {
        assert(cmd_buf_index < slots_.size());

        return cmd_buf_index;
    }
}

bool DumpingContextWindows::IsNextSlot(Index index, WindowSlot::Kind kind) const
{
    // Every window is closed: only the tail clone, if there is one, still takes work
    if (current_cb_index_ >= GetWindowCount())
    {
        return false;
    }

    const WindowSlot& slot = slots_[WindowToSlotIndex(current_cb_index_)];
    return slot.execute_index == UNDEFINED_INDEX && slot.kind == kind && slot.index == index;
}

void DumpingContextWindows::GetCloneWindow(size_t cmd_buf_index, uint64_t& lo, uint64_t& hi) const
{
    // A slot's position in the primary's stream is where the vkCmdExecuteCommands that merged it sits,
    // or the command's block index for the primary's own commands.
    const auto slot_position = [this](size_t slot_index) {
        GFXRECON_ASSERT(slot_index < slots_.size());
        const WindowSlot& slot = slots_[slot_index];
        return slot.execute_index != UNDEFINED_INDEX ? slot.execute_index : slot.index;
    };

    // The tail clone has no slot of its own: it runs everything after the last target command
    if (has_tail_clone_ && cmd_buf_index + 1 == command_buffers_.size())
    {
        lo = slots_.empty() ? 0 : slot_position(slots_.size() - 1);
        hi = std::numeric_limits<uint64_t>::max();
        return;
    }

    const size_t slot_index = WindowToSlotIndex(cmd_buf_index);

    hi = slot_position(slot_index);
    lo = slot_index > 0 ? slot_position(slot_index - 1) : 0;

    // With --dump-resources-before the "before" clone runs (lo, hi) and the "after" clone the target command alone
    if (options_.dump_resources_before && (cmd_buf_index % 2) != 0)
    {
        lo = hi;
    }
}

const std::vector<Index>* DumpingContextWindows::FindRenderPassBlockRange(uint64_t block_index) const
{
    for (const auto& range : RP_indices_)
    {
        if (IsInsideRange(range, block_index))
        {
            return &range;
        }
    }

    return nullptr;
}

uint32_t DumpingContextWindows::GetActiveCommandBuffers(CommandBufferIterator& first, CommandBufferIterator& last) const
{
    GFXRECON_ASSERT(current_cb_index_ <= command_buffers_.size());
    first = command_buffers_.begin() + static_cast<int>(current_cb_index_);
    last  = command_buffers_.end();
    return GFXRECON_NARROWING_CAST(uint32_t, current_cb_index_);
}

VkCommandBuffer DumpingContextWindows::GetWorkCommandBuffer() const
{
    GFXRECON_ASSERT(current_cb_index_ < command_buffers_.size());
    return command_buffers_[current_cb_index_];
}

uint32_t DumpingContextWindows::GetRenderPassCommandBuffers(CommandBufferIterator& first,
                                                            CommandBufferIterator& last) const
{
    // An instance this context did not begin itself lives entirely inside the current clone's window
    if (!inside_renderpass_ || render_pass_contexts_.empty())
    {
        GFXRECON_ASSERT(current_cb_index_ < command_buffers_.size());
        first = command_buffers_.begin() + static_cast<int>(current_cb_index_);
        last  = first + 1;
        return GFXRECON_NARROWING_CAST(uint32_t, current_cb_index_);
    }

    const RenderPassContext& render_pass_context = *render_pass_contexts_.back();

    const size_t begin = std::max(render_pass_context.first_clone, current_cb_index_);
    const size_t end   = std::max(begin, render_pass_context.last_clone);
    GFXRECON_ASSERT(end <= command_buffers_.size());

    first = command_buffers_.begin() + static_cast<int>(begin);
    last  = command_buffers_.begin() + static_cast<int>(end);
    return GFXRECON_NARROWING_CAST(uint32_t, begin);
}

namespace
{
// A VkRenderingInfo whose attachments store their results, and load them first when a window resumes the
// instance. The copies are referenced by the info, so this must outlive the call it is passed to.
class ChainedRenderingInfo
{
  public:
    ChainedRenderingInfo(const VkRenderingInfo& original, bool load) :
        info_(original),
        color_attachments_(original.pColorAttachments, original.pColorAttachments + original.colorAttachmentCount)
    {
        for (auto& attachment : color_attachments_)
        {
            FixOps(attachment, load);
        }
        info_.pColorAttachments = color_attachments_.empty() ? nullptr : color_attachments_.data();

        if (original.pDepthAttachment != nullptr)
        {
            depth_attachment_ = *original.pDepthAttachment;
            FixOps(depth_attachment_, load);
            info_.pDepthAttachment = &depth_attachment_;
        }

        if (original.pStencilAttachment != nullptr)
        {
            stencil_attachment_ = *original.pStencilAttachment;
            FixOps(stencil_attachment_, load);
            info_.pStencilAttachment = &stencil_attachment_;
        }
    }

    ChainedRenderingInfo(const ChainedRenderingInfo&)            = delete;
    ChainedRenderingInfo& operator=(const ChainedRenderingInfo&) = delete;

    const VkRenderingInfo* Get() const { return &info_; }

  private:
    static void FixOps(VkRenderingAttachmentInfo& attachment, bool load)
    {
        if (attachment.imageView == VK_NULL_HANDLE)
        {
            return;
        }

        attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        if (load)
        {
            attachment.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
        }
    }

    VkRenderingInfo                        info_;
    std::vector<VkRenderingAttachmentInfo> color_attachments_;
    VkRenderingAttachmentInfo              depth_attachment_{};
    VkRenderingAttachmentInfo              stencil_attachment_{};
};
} // namespace

void DumpingContextWindows::BeginRendering(uint64_t                             block_index,
                                           const VkRenderingInfo*               rendering_info,
                                           const std::vector<VulkanImageInfo*>& color_attachments,
                                           const std::vector<VkImageLayout>&    color_attachment_layouts,
                                           VulkanImageInfo*                     depth_attachment,
                                           VkImageLayout                        depth_attachment_layout)
{
    assert(color_attachments.size() == color_attachment_layouts.size());
    GFXRECON_ASSERT(rendering_info != nullptr);

    auto& new_render_pass_context    = render_pass_contexts_.emplace_back(std::make_shared<RenderPassContext>(
        color_attachments, color_attachment_layouts, depth_attachment, depth_attachment_layout, command_buffer_level_));
    new_render_pass_context->begin_block_index = block_index;

    CommandBufferIterator first, last;
    GetActiveCommandBuffers(first, last);

    // The rendering instance is begun in every clone whose window overlaps it, and those clones form a
    // contiguous range. Only the window that contains the begin starts the instance the way the application
    // did, the others resume it and load what the window before them stored.
    const std::vector<Index>* block_range = FindRenderPassBlockRange(block_index);
    const uint64_t            pass_begin  = block_range != nullptr ? block_range->front() : 0;
    const uint64_t            pass_end    = block_range != nullptr ? block_range->back() : 0;

    const ChainedRenderingInfo stored(*rendering_info, false);
    const ChainedRenderingInfo resumed(*rendering_info, true);

    bool   found_overlap = false;
    size_t cmd_buf_idx   = current_cb_index_;
    for (auto it = first; it < last; ++it, ++cmd_buf_idx)
    {
        uint64_t lo, hi;
        GetCloneWindow(cmd_buf_idx, lo, hi);
        if (lo >= pass_end || hi <= pass_begin)
        {
            continue;
        }

        RecordCmdBeginRendering(*it, (lo < pass_begin) ? stored.Get() : resumed.Get());

        if (!found_overlap)
        {
            new_render_pass_context->first_clone = cmd_buf_idx;
            found_overlap                        = true;
        }
        new_render_pass_context->last_clone = cmd_buf_idx + 1;
    }

    inside_renderpass_ = true;
}

void DumpingContextWindows::AppendTailClones()
{
    // clones are the only execution, so any work after last target command gets a clone of its own.
    if (!has_tail_clone_)
    {
        command_buffers_.push_back(VK_NULL_HANDLE);
        has_tail_clone_ = true;
    }

    for (const auto& secondaries : secondaries_ | std::views::values)
    {
        for (const auto& secondary_context : secondaries)
        {
            secondary_context->AppendTailClones();
        }
    }
}

// The window clones are ended by EndWindow as their target command is reached. The tail clone has no
// target command, so it is ended here, while the application still has the command buffer open.
void DumpingContextWindows::EndCommandBuffer()
{
    if (!has_tail_clone_)
    {
        return;
    }

    GFXRECON_ASSERT(device_table_.IsValid());

    auto injected = device_table_.Open();
    injected->EndCommandBuffer(command_buffers_.back());
}

void DumpingContextWindows::AssignSecondary(uint64_t                               execute_commands_index,
                                            std::shared_ptr<DumpingContextWindows> secondary_context)
{
    GFXRECON_ASSERT(secondary_context);

    secondaries_[execute_commands_index].push_back(secondary_context);
    secondary_context->command_buffer_level_ = DumpResourcesCommandBufferLevel::kSecondary;
}

std::vector<std::shared_ptr<DumpingContextWindows>>
DumpingContextWindows::SecondariesToExecute(uint64_t execute_commands_index) const
{
    auto entry = secondaries_.find(execute_commands_index);
    if (entry != secondaries_.end())
    {
        return entry->second;
    }

    return std::vector<std::shared_ptr<DumpingContextWindows>>();
}

// Rewrite this vkCmdExecuteCommands block's segment of slots_ so that the labels follow the
// given execution order. RecalculateCommandBuffers merges secondaries in dump-args order at setup,
// but slots are consumed in pCommandBuffers order, which is only known when the execute replays.
void DumpingContextWindows::ReorderSecondaries(
    Index execute_commands_index, const std::vector<std::shared_ptr<DumpingContextWindows>>& execution_order)
{
    const auto seg_entry = std::find_if(slots_.begin(), slots_.end(), [execute_commands_index](const WindowSlot& slot) {
        return slot.execute_index == execute_commands_index;
    });
    if (seg_entry == slots_.end())
    {
        return;
    }

    size_t pos = std::distance(slots_.begin(), seg_entry);
    for (const auto& secondary_context : execution_order)
    {
        for (const WindowSlot& secondary_slot : secondary_context->GetSlots())
        {
            GFXRECON_ASSERT(pos < slots_.size() && slots_[pos].execute_index == execute_commands_index);
            slots_[pos].index = secondary_slot.index;
            slots_[pos].kind  = secondary_slot.kind;
            ++pos;
        }
    }
}

uint32_t DumpingContextWindows::RecalculateCommandBuffers()
{
    if (secondaries_.empty())
    {
        return GFXRECON_NARROWING_CAST(uint32_t, command_buffers_.size());
    }

    auto n_command_buffers = GFXRECON_NARROWING_CAST(uint32_t, command_buffers_.size());

    // Merge the secondaries' slots into the primary in finalization order: the primary's own
    // commands and the vkCmdExecuteCommands blocks replay in ascending block index order, and each
    // execute finalizes its secondaries' slots at its own position in the primary's command stream.
    // Each merged slot is tagged with the block index of the vkCmdExecuteCommands that ran it, so
    // that render pass correlation can tell apart multiple executions of the same secondary.
    std::vector<WindowSlot> merged_slots;

    auto       primary_it  = slots_.begin();
    const auto primary_end = slots_.end();

    for (const auto& execute_commands : secondaries_)
    {
        // The primary's own commands recorded before this vkCmdExecuteCommands finalize first
        for (; primary_it != primary_end && primary_it->index < execute_commands.first; ++primary_it)
        {
            merged_slots.push_back(*primary_it);
        }

        for (const auto& secondary_context : execute_commands.second)
        {
            const size_t secondary_n_command_buffers = secondary_context->RecalculateCommandBuffers();
            if (!secondary_n_command_buffers)
            {
                // Abort the merge, leaving the primary in its original, consistent state
                return GFXRECON_NARROWING_CAST(uint32_t, command_buffers_.size());
            }

            n_command_buffers += secondary_n_command_buffers;

            for (const WindowSlot& secondary_slot : secondary_context->GetSlots())
            {
                merged_slots.push_back({ secondary_slot.index, execute_commands.first, secondary_slot.kind });
            }
        }
    }

    // The primary's own commands recorded after the last vkCmdExecuteCommands
    merged_slots.insert(merged_slots.end(), primary_it, primary_end);

    slots_ = std::move(merged_slots);

    GFXRECON_ASSERT(n_command_buffers >= command_buffers_.size())
    command_buffers_.resize(n_command_buffers);

    return n_command_buffers;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
