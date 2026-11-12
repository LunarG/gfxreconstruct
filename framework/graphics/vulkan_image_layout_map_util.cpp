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

#include "graphics/vulkan_image_layout_map_util.h"
#include "graphics/vulkan_resources_util.h"

#include <iterator>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

bool IsRestorableLayout(VkImageLayout layout)
{
    return (layout != VK_IMAGE_LAYOUT_UNDEFINED) && (layout != VK_IMAGE_LAYOUT_PREINITIALIZED);
}

VkImageMemoryBarrier MakeLayoutRestoreBarrier(VkImage                        image,
                                              VkImageLayout                  old_layout,
                                              VkImageLayout                  new_layout,
                                              const VkImageSubresourceRange& subresource_range)
{
    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
    barrier.srcAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    barrier.dstAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    barrier.oldLayout            = old_layout;
    barrier.newLayout            = new_layout;
    barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.image                = image;
    barrier.subresourceRange     = subresource_range;
    return barrier;
}

VkImageAspectFlags ToBarrierAspects(VkImageAspectFlags transition_aspects, VkImageAspectFlags image_aspects)
{
    constexpr VkImageAspectFlags kPlaneAspects =
        VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT | VK_IMAGE_ASPECT_PLANE_2_BIT;

    const VkImageAspectFlags planes = transition_aspects & kPlaneAspects;
    if ((planes != 0) && (planes == (image_aspects & kPlaneAspects)))
    {
        return (transition_aspects & ~kPlaneAspects) | VK_IMAGE_ASPECT_COLOR_BIT;
    }

    return transition_aspects;
}

void AppendImageLayoutBarriers(VkImage                            image,
                               const ImageLayoutMap&              current_layouts,
                               const ImageLayoutMap&              target_layouts,
                               std::vector<VkImageMemoryBarrier>& barriers)
{
    if (!target_layouts.IsInitialized() || !current_layouts.IsInitialized())
    {
        return;
    }

    const VkImageAspectFlags aspects      = target_layouts.GetAspects();
    const uint32_t           mip_levels   = target_layouts.GetMipLevels();
    const uint32_t           array_layers = target_layouts.GetArrayLayers();

    // Uniform fast path.
    if (target_layouts.IsUniform() && current_layouts.IsUniform())
    {
        const VkImageAspectFlagBits first_aspect = static_cast<VkImageAspectFlagBits>(aspects & ~(aspects - 1));
        const VkImageLayout         target       = target_layouts.GetSubresourceLayout(first_aspect, 0, 0);
        const VkImageLayout         current      = current_layouts.GetSubresourceLayout(first_aspect, 0, 0);

        if ((target != current) && IsRestorableLayout(target))
        {
            barriers.push_back(MakeLayoutRestoreBarrier(
                image, current, target, { ToBarrierAspects(aspects, aspects), 0, mip_levels, 0, array_layers }));
        }
        return;
    }

    struct AspectTransition
    {
        VkImageAspectFlags aspects;
        VkImageLayout      old_layout;
        VkImageLayout      new_layout;
    };
    // Map to group aspects sharing the same transition.
    AspectTransition transitions[std::size(kLayoutMapAspects)];

    // Restore each subresource individually, while coalescing aspects.
    for (uint32_t mip_level = 0; mip_level < mip_levels; ++mip_level)
    {
        for (uint32_t array_layer = 0; array_layer < array_layers; ++array_layer)
        {
            uint32_t transition_count = 0;

            for (VkImageAspectFlagBits aspect : kLayoutMapAspects)
            {
                if ((aspects & aspect) == 0)
                {
                    continue;
                }

                const VkImageLayout target  = target_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);
                const VkImageLayout current = current_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);

                if ((target == current) || !IsRestorableLayout(target))
                {
                    continue;
                }

                // Check if there is an existing transition (uses the same old and new layouts).
                uint32_t index = 0;
                while ((index < transition_count) &&
                       ((transitions[index].old_layout != current) || (transitions[index].new_layout != target)))
                {
                    ++index;
                }
                // Otherwise create a new transition.
                if (index == transition_count)
                {
                    transitions[transition_count++] = { 0, current, target };
                }

                transitions[index].aspects |= aspect;
            }

            for (uint32_t index = 0; index < transition_count; ++index)
            {
                const AspectTransition& transition = transitions[index];

                barriers.push_back(MakeLayoutRestoreBarrier(
                    image,
                    transition.old_layout,
                    transition.new_layout,
                    { ToBarrierAspects(transition.aspects, aspects), mip_level, 1, array_layer, 1 }));
            }
        }
    }
}

bool IsSubresourceCopyable(const ImageLayoutMap& layouts,
                           VkImageAspectFlags    aspects,
                           uint32_t              mip_level,
                           uint32_t              array_layer)
{
    for (VkImageAspectFlagBits aspect : kLayoutMapAspects)
    {
        if (((aspects & aspect) != 0) &&
            !IsRestorableLayout(layouts.GetSubresourceLayout(aspect, mip_level, array_layer)))
        {
            return false;
        }
    }
    return true;
}

void BuildCopyableSubresourceRanges(VkFormat                              format,
                                    uint32_t                              mip_levels,
                                    uint32_t                              array_layers,
                                    const ImageLayoutMap&                 initial_layouts,
                                    std::vector<VkImageSubresourceRange>& ranges,
                                    std::vector<VkImageSubresourceRange>& excluded_ranges)
{
    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil = false;
    GetFormatAspects(format, &aspects, &combined_depth_stencil);

    // The depth and stencil aspects of a combined format
    if (combined_depth_stencil)
    {
        aspects.assign(1, static_cast<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT));
    }

    for (VkImageAspectFlagBits aspect : aspects)
    {
        const VkImageAspectFlags aspect_mask = static_cast<VkImageAspectFlags>(aspect);

        for (uint32_t mip_level = 0; mip_level < mip_levels; ++mip_level)
        {
            // Coalesce neighbouring layers
            uint32_t run_start    = 0;
            uint32_t run_count    = 0;
            bool     run_copyable = false;

            for (uint32_t array_layer = 0; array_layer < array_layers; ++array_layer)
            {
                const bool copyable = IsSubresourceCopyable(initial_layouts, aspect_mask, mip_level, array_layer);

                if ((run_count != 0) && (copyable != run_copyable))
                {
                    (run_copyable ? ranges : excluded_ranges)
                        .push_back({ aspect_mask, mip_level, 1, run_start, run_count });
                    run_count = 0;
                }

                if (run_count == 0)
                {
                    run_start    = array_layer;
                    run_copyable = copyable;
                }
                ++run_count;
            }

            if (run_count != 0)
            {
                (run_copyable ? ranges : excluded_ranges)
                    .push_back({ aspect_mask, mip_level, 1, run_start, run_count });
            }
        }
    }
}

void AppendTransferLayoutBarriers(VkImage                                     image,
                                  const ImageLayoutMap&                       current_layouts,
                                  const std::vector<VkImageSubresourceRange>& excluded_ranges,
                                  VkImageLayout                               transfer_layout,
                                  std::vector<VkImageMemoryBarrier>&          barriers)
{
    ImageLayoutMap target_layouts = current_layouts;
    target_layouts.SetUniformLayout(transfer_layout);

    for (const VkImageSubresourceRange& range : excluded_ranges)
    {
        target_layouts.SetLayout(range, VK_IMAGE_LAYOUT_UNDEFINED);
    }

    AppendImageLayoutBarriers(image, current_layouts, target_layouts, barriers);
}

void ReverseLayoutBarriers(std::vector<VkImageMemoryBarrier>& barriers, size_t first)
{
    for (size_t i = first; i < barriers.size(); ++i)
    {
        std::swap(barriers[i].oldLayout, barriers[i].newLayout);
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
