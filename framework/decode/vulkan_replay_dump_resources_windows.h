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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_WINDOWS_H
#define GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_WINDOWS_H

#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/defines.h"
#include "util/logging.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <map>
#include <memory>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// A render pass (or dynamic rendering) instance of a command buffer that is executed through windows: its render
// targets and the render pass clones with which it is begun in, and resumed across, the window clones.
struct WindowRenderPassContext
{
    enum RenderPassType
    {
        kRenderPass,
        kDynamicRendering
    };

    WindowRenderPassContext() = delete;

    // Render pass
    WindowRenderPassContext(const VulkanRenderPassInfo*     rp,
                            const VulkanFramebufferInfo*    fb,
                            DumpResourcesCommandBufferLevel level) :
        type(RenderPassType::kRenderPass), renderpass_info(rp), framebuffer_info(fb), cmd_buf_level(level)
    {
        GFXRECON_ASSERT(cmd_buf_level != DumpResourcesCommandBufferLevel::kUnknown);
    }

    // Dynamic rendering
    WindowRenderPassContext(const std::vector<VulkanImageInfo*>& color_attachments,
                            const std::vector<VkImageLayout>&    color_attachment_layouts,
                            VulkanImageInfo*                     depth_attachment,
                            VkImageLayout                        depth_attachment_layout,
                            DumpResourcesCommandBufferLevel      level) :
        type(RenderPassType::kDynamicRendering), renderpass_info(nullptr), framebuffer_info(nullptr),
        cmd_buf_level(level)
    {
        GFXRECON_ASSERT(cmd_buf_level != DumpResourcesCommandBufferLevel::kUnknown);

        auto& new_render_targets                    = render_targets.emplace_back();
        new_render_targets.color_att_imgs           = color_attachments;
        new_render_targets.color_attachment_layouts = color_attachment_layouts;
        new_render_targets.depth_att_img            = depth_attachment;
        new_render_targets.depth_attachment_layout  = depth_attachment_layout;
    }

    // Contexts are shared through shared_ptr (DumpingContextWindows::render_pass_contexts_ and
    // WindowSlot::render_pass_context) and own their cloned VkRenderPass handles, which
    // DumpingContextWindows::Release() destroys exactly once.
    WindowRenderPassContext(const WindowRenderPassContext&)            = delete;
    WindowRenderPassContext& operator=(const WindowRenderPassContext&) = delete;

    // Render targets context for each subpass
    struct RenderTargets
    {
        RenderTargets() : depth_att_img(nullptr), depth_attachment_layout(VK_IMAGE_LAYOUT_UNDEFINED) {}

        std::vector<VulkanImageInfo*> color_att_imgs;
        std::vector<VkImageLayout>    color_attachment_layouts;

        VulkanImageInfo* depth_att_img;
        VkImageLayout    depth_attachment_layout;
    };

    RenderPassType                  type;
    DumpResourcesCommandBufferLevel cmd_buf_level;
    const VulkanRenderPassInfo*     renderpass_info;
    const VulkanFramebufferInfo*    framebuffer_info;

    // Block index of the vkCmdBeginRenderPass/vkCmdBeginRendering that began this instance. Dumped
    // resources are labeled with it so their filenames do not depend on which other render passes
    // were requested for dumping.
    Index begin_block_index{ UNDEFINED_INDEX };

    // One entry per subpass
    std::vector<RenderTargets> render_targets;

    // Also one entry per subpass. For each subpass we create a new render pass
    std::vector<VkRenderPass> render_pass_clones;

    // LOAD variants of render_pass_clones, used by a clone that resumes this render pass instead of
    // starting it, keyed by the subpass the window resumes in and the subpass its target draw is in.
    std::map<std::pair<uint32_t, uint32_t>, VkRenderPass> render_pass_load_clones;

    // Half-open range of clones that have this instance begun, as command buffer indices.
    size_t first_clone{ 0 };
    size_t last_clone{ 0 };
};

// An dumping context independent representation of a dump-able command. Each slot represents a command marked for
// dumping. Each slot ends a DumpingContextWindows. If --dump-resources-before is enabled then each slot is assigned two
// windows, one for before and one for after the command.
struct WindowSlot
{
    enum class Kind
    {
        kDraw,
        kDispatch,
        kTraceRays,
        kKindCount
    };

    // Command's block index
    Index index;

    // Holds the CmdExecuteCommands block index when the command is recorded in secondary, otherwise UNDEFINED_INDEX
    Index execute_index;
    Kind  kind{ Kind::kDraw };

    // The render pass context the window of this slot closed in and the subpass ordinal within it.
    // Captured in DumpingContextWindows::EndRenderPassInWindow while the render pass is active. For commands recorded
    // in a secondary command buffer that inherits the primary's render pass (RENDER_PASS_CONTINUE), it is filled in
    // from the primary at vkCmdExecuteCommands time.
    std::shared_ptr<WindowRenderPassContext> render_pass_context;
    uint64_t                                 subpass{ 0 };
};

// Abstraction for the windows logic.
//
// Each command marked for dumping is a slot (WindowSlot) and is assigned a window. Each window is a Vulkan command
// buffer clone. A window is the half-open block-index range (lo, hi] of the original command stream that one clone
// records. hi is the block index of the clone's target command, lo is the block index of the previous target command,
// or 0 for the first clone. For a command merged from a secondary, the position used is that of the
// vkCmdExecuteCommands that executes it.
// Each clone records the work commands (1) of its window. State commands (2) are recorded into every clone from the
// one taking work to the last, so that each window starts with the state the stream has set so far.
//
// A DumpingContextWindows is created for each (BeginCommandBuffer, QueueSubmit) pair from which commands are dumped,
// and for each primary that executes such a secondary. Each dumping context of the pair is assigned the corresponding
// DumpingContextWindows.
//
// If a command buffer is marked to dump commands of different kinds, each kind handled by its own dumping context, then
// every one of those contexts is assigned the same DumpingContextWindows. A dumping context owns the slots of the
// commands it knows: while the command buffer is recorded it tracks the state it needs, records its target commands
// into the clone taking work and tells the windows where a window ends. When the command buffer is submitted the
// windows run and call the owner of each slot back, through the virtual functions of DumpingContextBase, to dump it.
//
// Example:
// Command buffer with block indices: BeginRP(10), BindPipeline(11), Draw(12), Draw(13)*,
// BindDS(14), Draw(15)*, EndRP(16), CopyBuffer(17). Targets are 13 and 15; the render pass (10, 16) is listed in
// the dump arguments.
//
// Clone    Window       Contents
// 0        (0, 13]      BeginRP normal clone, BindPipeline, Draw12, Draw13, EndRP + barrier, End
// 1        (13, 15]     BeginRP LOAD variant, BindPipeline, BindDS, Draw15, EndRP + barrier, End
// tail     (15, inf)    BeginRP LOAD variant, BindPipeline, BindDS, original EndRP, CopyBuffer, EndCommandBuffer
//
// With DumpBeforeCommand each target command gets two clones: the "before" clone records (lo, hi), so it ends right
// before the command, and the "after" clone has lo = hi, so it holds the target command alone.
//
// (1) Work commands are commands that execute some work on the gpu: draw calls, dispatch, trace rays, transfer etc.
// (2) State commands are commands that configure state: bind pipeline, descriptor sets, etc.
class DumpingContextWindows
{
  public:
    using RenderPassContext = WindowRenderPassContext;
    using RenderPassType    = WindowRenderPassContext::RenderPassType;

    // Marks an attachment that no subpass of a render pass references
    static constexpr uint32_t kNeverUsed = std::numeric_limits<uint32_t>::max();

    // draw_indices, dispatch_indices and trace_rays_indices are the commands dumped from the command buffer; each
    // one is a slot. Any of them can be null.
    DumpingContextWindows(const CommandIndices*      draw_indices,
                          const CommandIndices*      dispatch_indices,
                          const CommandIndices*      trace_rays_indices,
                          const RenderPassIndices*   rp_indices,
                          CommonObjectInfoTable&     object_info_table,
                          const VulkanReplayOptions& options);

    ~DumpingContextWindows();

    // The dumping context that owns the slots of the given kind. Held weakly: the owners hold their windows.
    void SetSlotOwner(WindowSlot::Kind kind, const std::shared_ptr<DumpingContextBase>& owner);
    std::shared_ptr<DumpingContextBase> GetSlotOwner(WindowSlot::Kind kind) const;
    bool HasSlotOwner(WindowSlot::Kind kind) const { return GetSlotOwner(kind) != nullptr; }

    // Allocates and begins the clones
    VkResult BeginCommandBuffer(VulkanCommandBufferInfo*                   orig_cmd_buf_info,
                                const graphics::VulkanInjectedDeviceCalls& dev_table,
                                const VkCommandBufferBeginInfo*            begin_info);

    // The window clones are ended as their target command is reached. This ends the tail clone.
    void EndCommandBuffer();

    void Release();

    VkCommandBuffer GetOriginalCommandBuffer() const
    {
        return original_command_buffer_info_ != nullptr ? original_command_buffer_info_->handle : VK_NULL_HANDLE;
    }

    DumpResourcesCommandBufferLevel GetCommandBufferLevel() const { return command_buffer_level_; }
    bool IsPrimary() const { return command_buffer_level_ == DumpResourcesCommandBufferLevel::kPrimary; }

    // The clone a work command is recorded into: the current one.
    VkCommandBuffer GetWorkCommandBuffer() const;

    // The index of the clone taking work
    size_t GetCurrentWindowIndex() const { return current_cb_index_; }

    // Every clone from the one taking work to the last. State commands are recorded into all of them.
    uint32_t GetActiveCommandBuffers(CommandBufferIterator& first, CommandBufferIterator& last) const;

    // The clones that have the active render pass instance begun: the stored range of an instance this
    // context began, or the current clone for one it only forwards.
    uint32_t GetRenderPassCommandBuffers(CommandBufferIterator& first, CommandBufferIterator& last) const;

    const std::vector<VkCommandBuffer>& GetCommandBuffers() const { return command_buffers_; }

    // The clones that hold a window. The tail clone, when there is one, follows them in command_buffers_.
    size_t GetWindowCount() const { return command_buffers_.size() - (has_tail_clone_ ? 1 : 0); }

    // The clone holding the work recorded after the last target command, VK_NULL_HANDLE if there is none.
    VkCommandBuffer GetTailCommandBuffer() const { return has_tail_clone_ ? command_buffers_.back() : VK_NULL_HANDLE; }

    // Closing a window, called by the owner of its slot when the target command is reached (and, with
    // --dump-resources-before, right before it as well). It is done in two steps so that the owner can record what it
    // needs at the boundary in between, outside of any render pass:
    //
    // EndRenderPassInWindow ends the render pass instance this context has active, if any, in the clone taking work
    // and correlates the slot of that clone with it. It returns the render pass context, null if the clone is not
    // inside one.
    // EndWindow ends the clone taking work and moves on to the next one.
    std::shared_ptr<RenderPassContext> EndRenderPassInWindow();
    void                               EndWindow();

    // Both steps, for owners with nothing to record at the boundary
    void FinalizeWindow()
    {
        EndRenderPassInWindow();
        EndWindow();
    }

    // Render pass instances listed in the dump arguments are begun in every clone whose window overlaps them, with
    // render passes cloned to store what a window wrote and load what the window before it stored. The rest are
    // forwarded to the clone taking work as they are.
    bool ShouldHandleRenderPass(uint64_t index) const;

    VkResult BeginRenderPass(uint64_t                     block_index,
                             const VulkanRenderPassInfo*  render_pass_info,
                             const VulkanFramebufferInfo* framebuffer_info,
                             const VkRenderPassBeginInfo* renderpass_begin_info,
                             VkSubpassContents            contents);

    void NextSubpass(VkSubpassContents contents);

    void EndRenderPass();

    void BeginRendering(uint64_t                             block_index,
                        const VkRenderingInfo*               rendering_info,
                        const std::vector<VulkanImageInfo*>& color_attachments,
                        const std::vector<VkImageLayout>&    color_attachment_layouts,
                        VulkanImageInfo*                     depth_attachment,
                        VkImageLayout                        depth_attachment_layout);

    void EndRendering();

    void EndRendering(PFN_vkCmdEndRendering2KHR func, const VkRenderingEndInfoKHR* rendering_end_info);

    void RecordCmdBeginRendering(VkCommandBuffer command_buffer, const VkRenderingInfo* rendering_info) const;

    void RecordCmdEndRendering(VkCommandBuffer command_buffer) const;

    // Secondaries. The windows of a secondary are executed by the windows of its primary, one each, so the primary
    // gets one slot for each slot of the secondaries it executes.
    void AssignSecondary(uint64_t execute_commands_index, std::shared_ptr<DumpingContextWindows> secondary_windows);

    std::vector<std::shared_ptr<DumpingContextWindows>> SecondariesToExecute(uint64_t execute_commands_index) const;

    // Every assigned secondary, in the order the vkCmdExecuteCommands are replayed
    std::vector<std::shared_ptr<DumpingContextWindows>> GetSecondaries() const;

    void ReorderSecondaries(Index                                                      execute_commands_index,
                            const std::vector<std::shared_ptr<DumpingContextWindows>>& execution_order);

    uint32_t RecalculateCommandBuffers();

    // Gives every secondary this context executes its tail clone. Call it once, after
    // RecalculateCommandBuffers and before anything is recorded.
    void AppendTailClones();

    // Called from vkCmdExecuteCommands for each executed secondary that has windows: the owners hand the state a
    // secondary inherits down to the secondary's owners and take over each of the secondary's slots, finalizing one
    // window of this (primary) context for each window of the secondary.
    void UpdateSecondaries(DumpingContextWindows& secondary_windows,
                           Index                  execute_cmd_index,
                           Index                  command_buffer_execute_index);

    // Runs the windows in place of the original command buffer: each one is submitted and waited for, then the
    // owner of its slot dumps it. The original submit's wait semaphores go to the first submission and its signal
    // semaphores to the last one.
    VkResult SubmitAndDump(VkQueue              queue,
                           const VkSubmitInfo2& submit_info,
                           Index                submit_info_index,
                           Index                submit_info_cmd_buf_index);

  private:
    // If options_.dump_resources_before is true, it means that we have two command buffer clones for each slot.
    // This function converts the provided command buffer index into an absolute one (divided by 2 in the case of
    // dump_resources_before is true) so it can be used to index arrays that don't double their sizes in case of
    // dump_resources_before is true.
    size_t WindowToSlotIndex(size_t cmd_buf_index) const;

    // The block index window (lo, hi] of the stream that the given clone records.
    void GetCloneWindow(size_t cmd_buf_index, uint64_t& lo, uint64_t& hi) const;

    // The block index range of the render pass instance the given block index belongs to
    const std::vector<Index>* FindRenderPassBlockRange(uint64_t block_index) const;

    const std::vector<WindowSlot>& GetSlots() const { return slots_; }

    // The owners, each one once, with the first slot kind it owns
    std::vector<std::pair<WindowSlot::Kind, std::shared_ptr<DumpingContextBase>>> GetDistinctSlotOwners() const;

    PFN_vkCmdBeginRendering
    ResolveCmdBeginRendering(const graphics::VulkanInjectedDeviceCalls::Scope& injected_commands_scope) const;

    PFN_vkCmdEndRendering
    ResolveCmdEndRendering(const graphics::VulkanInjectedDeviceCalls::Scope& injected_commands_scope) const;

    template <typename CreateInfoType>
    void ParseAttachmentsInRenderPassCreateInfo(const VulkanRenderPassInfo*       render_pass_info,
                                                const CreateInfoType*             ci,
                                                const VulkanFramebufferInfo*      framebuffer_info,
                                                uint32_t                          subpass,
                                                RenderPassContext::RenderTargets& render_targets);

    VkResult CloneRenderPass(RenderPassContext& renderpass_context);

    VkResult CloneRenderPass2(RenderPassContext& renderpass_context);

    // Common tail of CloneRenderPass/CloneRenderPass2: parse the first subpass' attachments and update the
    // tracked image layouts in the original command buffer info.
    template <typename CreateInfoType>
    void FinalizeRenderPassClone(RenderPassContext& renderpass_context, const CreateInfoType* create_info);

    VulkanCommandBufferInfo*     original_command_buffer_info_;
    std::vector<VkCommandBuffer> command_buffers_;
    size_t                       current_cb_index_;

    std::vector<WindowSlot> slots_;

    RenderPassIndices          RP_indices_;
    const VulkanReplayOptions& options_;

    // Execute commands block index : windows of the executed secondaries
    // This must be an ordered map: RecalculateCommandBuffers merges secondary slots in iteration
    // order, which must match the ascending block index order in which the vkCmdExecuteCommands are replayed.
    std::map<Index, std::vector<std::shared_ptr<DumpingContextWindows>>> secondaries_;

    // The owner of the slots of each kind
    std::array<std::weak_ptr<DumpingContextBase>, static_cast<size_t>(WindowSlot::Kind::kKindCount)> slot_owners_;

    // One entry per render pass, in replay order. Held through shared_ptr so that each slot can point
    // at the context its window closed in.
    std::vector<std::shared_ptr<RenderPassContext>> render_pass_contexts_;

    // True while a render pass (or dynamic rendering) instance begun by this context is active. Used by
    // EndRenderPassInWindow to decide whether a CmdEndRenderPass/CmdEndRendering must be recorded.
    bool inside_renderpass_;

    // True when command_buffers_ ends in a tail clone: the work a secondary records after its last target
    // command, which the target commands that follow it still need.
    bool has_tail_clone_;

    DumpResourcesCommandBufferLevel command_buffer_level_;

    graphics::VulkanInjectedDeviceCalls device_table_;
    CommonObjectInfoTable&              object_info_table_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_WINDOWS_H */
