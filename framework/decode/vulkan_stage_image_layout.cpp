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

#include "decode/vulkan_stage_image_layout.h"

#include "decode/vulkan_command_buffer_util.h"
#include "graphics/vulkan_resources_util.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Images

void VulkanStageImageLayout::Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args)
{
    Forward(call_info, args);

    // The replay consumer filled the image info from the create info that replay used, when the image was created.
    const format::HandleId* image_id   = args.pImage.GetPointer();
    VulkanImageInfo*        image_info = (image_id != nullptr) ? object_info_table_.GetVkImageInfo(*image_id) : nullptr;
    if ((image_info != nullptr) && (image_info->level_count != 0))
    {
        image_info->subresource_layouts.Initialize(
            image_info->level_count, image_info->layer_count, graphics::GetFormatAspects(image_info->format));
        image_info->subresource_layouts.SetUniformLayout(image_info->initial_layout);
    }
}

void VulkanStageImageLayout::Process_vkGetSwapchainImagesKHR(const ApiCallInfo&           call_info,
                                                             args::GetSwapchainImagesKHR& args)
{
    Forward(call_info, args);

    if ((args.result != VK_SUCCESS) && (args.result != VK_INCOMPLETE))
    {
        return;
    }

    for (const format::HandleId image_id : args.pSwapchainImages.GetSpan())
    {
        // The replay consumer fills the info of each image that it gets back. Initialize() leaves every subresource
        // VK_IMAGE_LAYOUT_UNDEFINED, where swapchain images start.
        VulkanImageInfo* image_info = object_info_table_.GetVkImageInfo(image_id);
        if ((image_info != nullptr) && (image_info->level_count != 0))
        {
            image_info->subresource_layouts.Initialize(
                image_info->level_count, image_info->layer_count, graphics::GetFormatAspects(image_info->format));
        }
    }
}

void VulkanStageImageLayout::ProcessInitImageCommand(format::HandleId             device_id,
                                                     format::HandleId             image_id,
                                                     uint64_t                     data_size,
                                                     uint32_t                     aspect,
                                                     uint32_t                     layout,
                                                     const std::vector<uint64_t>& level_sizes,
                                                     const uint8_t*               data)
{
    VulkanConsumerStage::ProcessInitImageCommand(device_id, image_id, data_size, aspect, layout, level_sizes, data);

    // The replay consumer moved the image to the layout, when it could.
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device_id);
    VulkanImageInfo*        image_info  = object_info_table_.GetVkImageInfo(image_id);
    if ((device_info == nullptr) || (device_info->resource_initializer == nullptr) || (image_info == nullptr))
    {
        return;
    }

    image_info->intermediate_layout = static_cast<VkImageLayout>(layout);

    // This runs per aspect.
    const VkImageSubresourceRange aspect_range = {
        static_cast<VkImageAspectFlags>(aspect), 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
    };
    image_info->subresource_layouts.SetLayout(aspect_range, static_cast<VkImageLayout>(layout));
}

// Commands that move images to other layouts

template <typename BarrierMetaT>
void VulkanStageImageLayout::UpdateBarrierLayouts(format::HandleId    command_buffer_id,
                                                  const BarrierMetaT* barriers,
                                                  size_t              count)
{
    VulkanCommandBufferInfo* command_buffer_info = object_info_table_.GetVkCommandBufferInfo(command_buffer_id);
    if ((command_buffer_info == nullptr) || (barriers == nullptr))
    {
        return;
    }

    for (size_t i = 0; i < count; ++i)
    {
        const auto*      barrier    = barriers[i].decoded_value;
        VulkanImageInfo* image_info = object_info_table_.GetVkImageInfo(barriers[i].image);
        if ((barrier == nullptr) || (image_info == nullptr))
        {
            continue;
        }

        InitializeCommandBufferImageLayouts(command_buffer_info, image_info);
        command_buffer_info->image_layout_barriers[barriers[i].image].SetLayout(barrier->subresourceRange,
                                                                                barrier->newLayout);

        image_info->intermediate_layout = barrier->newLayout;
    }
}

void VulkanStageImageLayout::UpdateDependencyInfoLayouts(format::HandleId                command_buffer_id,
                                                         const Decoded_VkDependencyInfo* infos,
                                                         size_t                          count)
{
    for (size_t i = 0; (infos != nullptr) && (i < count); ++i)
    {
        const auto* image_barriers = infos[i].pImageMemoryBarriers;
        if (image_barriers != nullptr)
        {
            UpdateBarrierLayouts(
                command_buffer_id, image_barriers->GetMetaStructPointer(), image_barriers->GetLength());
        }
    }
}

void VulkanStageImageLayout::Process_vkCmdPipelineBarrier(const ApiCallInfo& call_info, args::CmdPipelineBarrier& args)
{
    UpdateBarrierLayouts(args.commandBuffer,
                         args.pImageMemoryBarriers.GetMetaStructPointer(),
                         std::min<size_t>(args.imageMemoryBarrierCount, args.pImageMemoryBarriers.GetLength()));
    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageImageLayout::ProcessPipelineBarrier2(const ApiCallInfo& call_info, ArgsT& args)
{
    UpdateDependencyInfoLayouts(args.commandBuffer, args.pDependencyInfo.GetMetaStructPointer(), 1);
    Forward(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdPipelineBarrier2(const ApiCallInfo&         call_info,
                                                           args::CmdPipelineBarrier2& args)
{
    ProcessPipelineBarrier2(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdPipelineBarrier2KHR(const ApiCallInfo&            call_info,
                                                              args::CmdPipelineBarrier2KHR& args)
{
    ProcessPipelineBarrier2(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdWaitEvents(const ApiCallInfo& call_info, args::CmdWaitEvents& args)
{
    UpdateBarrierLayouts(args.commandBuffer,
                         args.pImageMemoryBarriers.GetMetaStructPointer(),
                         std::min<size_t>(args.imageMemoryBarrierCount, args.pImageMemoryBarriers.GetLength()));
    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageImageLayout::ProcessWaitEvents2(const ApiCallInfo& call_info, ArgsT& args)
{
    UpdateDependencyInfoLayouts(args.commandBuffer,
                                args.pDependencyInfos.GetMetaStructPointer(),
                                std::min<size_t>(args.eventCount, args.pDependencyInfos.GetLength()));
    Forward(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdWaitEvents2(const ApiCallInfo& call_info, args::CmdWaitEvents2& args)
{
    ProcessWaitEvents2(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, args::CmdWaitEvents2KHR& args)
{
    ProcessWaitEvents2(call_info, args);
}

void VulkanStageImageLayout::UpdateImageViewLayout(VulkanCommandBufferInfo* command_buffer_info,
                                                   format::HandleId         image_view_id,
                                                   VkImageLayout            layout)
{
    if ((image_view_id == format::kNullHandleId) || (layout == VK_IMAGE_LAYOUT_UNDEFINED))
    {
        return;
    }

    const VulkanImageViewInfo* image_view_info = object_info_table_.GetVkImageViewInfo(image_view_id);
    if (image_view_info == nullptr)
    {
        return;
    }

    VulkanImageInfo* image_info = object_info_table_.GetVkImageInfo(image_view_info->image_id);
    if (image_info == nullptr)
    {
        return;
    }

    InitializeCommandBufferImageLayouts(command_buffer_info, image_info);

    // A layout such as VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL applies to some aspects of the view only.
    VkImageSubresourceRange range = image_view_info->subresource_range;
    range.aspectMask &= graphics::GetLayoutAspects(layout);

    if (range.aspectMask != 0)
    {
        command_buffer_info->image_layout_barriers[image_view_info->image_id].SetLayout(range, layout);
    }

    image_info->intermediate_layout = layout;
}

template <typename ArgsT>
void VulkanStageImageLayout::ProcessEndRenderPass(const ApiCallInfo& call_info, ArgsT& args)
{
    // The replay consumer clears the attachments of the render pass when it ends the render pass, so read them first.
    VulkanCommandBufferInfo* command_buffer_info = object_info_table_.GetVkCommandBufferInfo(args.commandBuffer);
    if (command_buffer_info != nullptr)
    {
        const auto& attachment_image_view_ids =
            command_buffer_info->render_pass_contexts.active_render_pass_attachment_image_view_ids;
        const VulkanRenderPassInfo* render_pass_info =
            object_info_table_.GetVkRenderPassInfo(command_buffer_info->render_pass_contexts.active_render_pass_id);

        if (render_pass_info != nullptr)
        {
            const auto&  final_layouts = render_pass_info->attachment_description_final_layouts;
            const size_t count         = std::min(attachment_image_view_ids.size(), final_layouts.size());
            GFXRECON_ASSERT(attachment_image_view_ids.empty() ||
                            (attachment_image_view_ids.size() == final_layouts.size()));

            // The end of the render pass moves each attachment to its final layout.
            for (size_t i = 0; i < count; ++i)
            {
                UpdateImageViewLayout(command_buffer_info, attachment_image_view_ids[i], final_layouts[i]);

                // The stencil aspect can have its own final layout.
                UpdateImageViewLayout(command_buffer_info,
                                      attachment_image_view_ids[i],
                                      render_pass_info->attachment_description_stencil_final_layouts[i]);
            }
        }
    }

    Forward(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdEndRenderPass(const ApiCallInfo& call_info, args::CmdEndRenderPass& args)
{
    ProcessEndRenderPass(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdEndRenderPass2(const ApiCallInfo& call_info, args::CmdEndRenderPass2& args)
{
    ProcessEndRenderPass(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdEndRenderPass2KHR(const ApiCallInfo&          call_info,
                                                            args::CmdEndRenderPass2KHR& args)
{
    ProcessEndRenderPass(call_info, args);
}

void VulkanStageImageLayout::UpdateAttachmentLayout(format::HandleId                         command_buffer_id,
                                                    const Decoded_VkRenderingAttachmentInfo* attachment)
{
    VulkanCommandBufferInfo* command_buffer_info = object_info_table_.GetVkCommandBufferInfo(command_buffer_id);
    if ((command_buffer_info == nullptr) || (attachment == nullptr) || (attachment->decoded_value == nullptr))
    {
        return;
    }

    UpdateImageViewLayout(command_buffer_info, attachment->imageView, attachment->decoded_value->imageLayout);

    if (attachment->decoded_value->resolveMode != VK_RESOLVE_MODE_NONE)
    {
        UpdateImageViewLayout(
            command_buffer_info, attachment->resolveImageView, attachment->decoded_value->resolveImageLayout);
    }
}

template <typename ArgsT>
void VulkanStageImageLayout::ProcessBeginRendering(const ApiCallInfo& call_info, ArgsT& args)
{
    const Decoded_VkRenderingInfo* rendering_info = args.pRenderingInfo.GetMetaStructPointer();
    if ((rendering_info != nullptr) && (rendering_info->decoded_value != nullptr))
    {
        if (rendering_info->pColorAttachments != nullptr)
        {
            const Decoded_VkRenderingAttachmentInfo* colors = rendering_info->pColorAttachments->GetMetaStructPointer();
            const size_t count = std::min<size_t>(rendering_info->decoded_value->colorAttachmentCount,
                                                  rendering_info->pColorAttachments->GetLength());
            for (size_t i = 0; (colors != nullptr) && (i < count); ++i)
            {
                UpdateAttachmentLayout(args.commandBuffer, &colors[i]);
            }
        }

        if (rendering_info->pDepthAttachment != nullptr)
        {
            UpdateAttachmentLayout(args.commandBuffer, rendering_info->pDepthAttachment->GetMetaStructPointer());
        }

        if (rendering_info->pStencilAttachment != nullptr)
        {
            UpdateAttachmentLayout(args.commandBuffer, rendering_info->pStencilAttachment->GetMetaStructPointer());
        }
    }

    Forward(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdBeginRendering(const ApiCallInfo& call_info, args::CmdBeginRendering& args)
{
    ProcessBeginRendering(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdBeginRenderingKHR(const ApiCallInfo&          call_info,
                                                            args::CmdBeginRenderingKHR& args)
{
    ProcessBeginRendering(call_info, args);
}

void VulkanStageImageLayout::Process_vkCmdExecuteCommands(const ApiCallInfo& call_info, args::CmdExecuteCommands& args)
{
    VulkanCommandBufferInfo* primary_info = object_info_table_.GetVkCommandBufferInfo(args.commandBuffer);
    if (primary_info != nullptr)
    {
        for (const format::HandleId secondary_id : args.pCommandBuffers.GetSpan())
        {
            const VulkanCommandBufferInfo* secondary_info = object_info_table_.GetVkCommandBufferInfo(secondary_id);
            if (secondary_info == nullptr)
            {
                continue;
            }

            // The primary leaves the images in the layouts that the secondary recorded.
            for (const auto& [image_id, secondary_layouts] : secondary_info->image_layout_barriers)
            {
                auto& primary_layouts = primary_info->image_layout_barriers[image_id];
                if (primary_layouts.IsInitialized())
                {
                    primary_layouts.MergeFrom(secondary_layouts);
                }
                else
                {
                    primary_layouts = secondary_layouts;
                }
            }
        }
    }

    Forward(call_info, args);
}

// Submits

void VulkanStageImageLayout::PropagateImageLayouts(format::HandleId command_buffer_id)
{
    const VulkanCommandBufferInfo* command_buffer_info = object_info_table_.GetVkCommandBufferInfo(command_buffer_id);
    if (command_buffer_info == nullptr)
    {
        return;
    }

    for (const auto& [image_id, command_buffer_layouts] : command_buffer_info->image_layout_barriers)
    {
        VulkanImageInfo* image_info = object_info_table_.GetVkImageInfo(image_id);
        if (image_info != nullptr)
        {
            image_info->subresource_layouts.MergeFrom(command_buffer_layouts);
        }
    }
}

void VulkanStageImageLayout::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    if (args.result == VK_SUCCESS)
    {
        for (const Decoded_VkSubmitInfo& submit : args.pSubmits.GetMetaStructSpan())
        {
            for (const format::HandleId command_buffer_id : submit.pCommandBuffers.GetSpan())
            {
                PropagateImageLayouts(command_buffer_id);
            }
        }
    }

    Forward(call_info, args);
}

template <typename ArgsT>
void VulkanStageImageLayout::ProcessQueueSubmit2(const ApiCallInfo& call_info, ArgsT& args)
{
    if (args.result == VK_SUCCESS)
    {
        for (const Decoded_VkSubmitInfo2& submit : args.pSubmits.GetMetaStructSpan())
        {
            if (submit.pCommandBufferInfos == nullptr)
            {
                continue;
            }

            for (const Decoded_VkCommandBufferSubmitInfo& info : submit.pCommandBufferInfos->GetMetaStructSpan())
            {
                PropagateImageLayouts(info.commandBuffer);
            }
        }
    }

    Forward(call_info, args);
}

void VulkanStageImageLayout::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    ProcessQueueSubmit2(call_info, args);
}

void VulkanStageImageLayout::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    ProcessQueueSubmit2(call_info, args);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
