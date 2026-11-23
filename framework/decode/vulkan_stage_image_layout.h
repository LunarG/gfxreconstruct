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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_IMAGE_LAYOUT_H
#define GFXRECON_DECODE_VULKAN_STAGE_IMAGE_LAYOUT_H

#include "decode/common_object_info_table.h"
#include "generated/generated_vulkan_consumer_stage.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// This stage tracks image layouts in the object info table of the replay consumer, and changes no call:
/// - VulkanImageInfo::subresource_layouts, the layouts once the submitted work is done,
/// - VulkanImageInfo::intermediate_layout, the last layout that a command buffer recorded,
/// - VulkanCommandBufferInfo::image_layout_barriers, the layouts that a command buffer leaves behind.
///
/// The replay consumer creates the infos, so the stage updates them after it forwards a call that creates an
/// image. For a command or a submit, the stage updates them before it forwards the call, so the consumers see the
/// layouts that the call leaves behind. A submit moves the images only when it succeeded in the capture. The replay
/// consumer clears image_layout_barriers when a command buffer begins or resets.
class VulkanStageImageLayout : public VulkanConsumerStage
{
  public:
    explicit VulkanStageImageLayout(CommonObjectInfoTable& object_info_table) : object_info_table_(object_info_table) {}

    // Images

    void Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args) override;
    void Process_vkGetSwapchainImagesKHR(const ApiCallInfo& call_info, args::GetSwapchainImagesKHR& args) override;

    void ProcessInitImageCommand(format::HandleId             device_id,
                                 format::HandleId             image_id,
                                 uint64_t                     data_size,
                                 uint32_t                     aspect,
                                 uint32_t                     layout,
                                 const std::vector<uint64_t>& level_sizes,
                                 const uint8_t*               data) override;

    // Commands that move images to other layouts

    void Process_vkCmdPipelineBarrier(const ApiCallInfo& call_info, args::CmdPipelineBarrier& args) override;
    void Process_vkCmdPipelineBarrier2(const ApiCallInfo& call_info, args::CmdPipelineBarrier2& args) override;
    void Process_vkCmdPipelineBarrier2KHR(const ApiCallInfo& call_info, args::CmdPipelineBarrier2KHR& args) override;
    void Process_vkCmdWaitEvents(const ApiCallInfo& call_info, args::CmdWaitEvents& args) override;
    void Process_vkCmdWaitEvents2(const ApiCallInfo& call_info, args::CmdWaitEvents2& args) override;
    void Process_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, args::CmdWaitEvents2KHR& args) override;

    void Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, args::CmdEndRenderPass& args) override;
    void Process_vkCmdEndRenderPass2(const ApiCallInfo& call_info, args::CmdEndRenderPass2& args) override;
    void Process_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, args::CmdEndRenderPass2KHR& args) override;

    void Process_vkCmdBeginRendering(const ApiCallInfo& call_info, args::CmdBeginRendering& args) override;
    void Process_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, args::CmdBeginRenderingKHR& args) override;

    void Process_vkCmdExecuteCommands(const ApiCallInfo& call_info, args::CmdExecuteCommands& args) override;

    // Submits

    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;

  private:
    template <typename ArgsT>
    void ProcessPipelineBarrier2(const ApiCallInfo& call_info, ArgsT& args);

    template <typename ArgsT>
    void ProcessWaitEvents2(const ApiCallInfo& call_info, ArgsT& args);

    template <typename ArgsT>
    void ProcessEndRenderPass(const ApiCallInfo& call_info, ArgsT& args);

    template <typename ArgsT>
    void ProcessBeginRendering(const ApiCallInfo& call_info, ArgsT& args);

    template <typename ArgsT>
    void ProcessQueueSubmit2(const ApiCallInfo& call_info, ArgsT& args);

    template <typename BarrierMetaT>
    void UpdateBarrierLayouts(format::HandleId command_buffer_id, const BarrierMetaT* barriers, size_t count);

    void UpdateDependencyInfoLayouts(format::HandleId                command_buffer_id,
                                     const Decoded_VkDependencyInfo* infos,
                                     size_t                          count);

    void UpdateAttachmentLayout(format::HandleId                         command_buffer_id,
                                const Decoded_VkRenderingAttachmentInfo* attachment);

    void UpdateImageViewLayout(VulkanCommandBufferInfo* command_buffer_info,
                               format::HandleId         image_view_id,
                               VkImageLayout            layout);

    /// Moves the images to the layouts that the command buffer leaves them in.
    void PropagateImageLayouts(format::HandleId command_buffer_id);

    CommonObjectInfoTable& object_info_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_IMAGE_LAYOUT_H
