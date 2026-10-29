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

// Queue family ownership transfers, as the trim state tracker records them.

#ifndef GFXRECON_ENCODE_VULKAN_QUEUE_FAMILY_OWNERSHIP_H
#define GFXRECON_ENCODE_VULKAN_QUEUE_FAMILY_OWNERSHIP_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_state_info)

// The parameters of a queue family ownership transfer made by a buffer or image memory barrier. An acquire has to
// repeat the parameters of the release it completes (VUID-vkQueueSubmit-pSubmits-02207), so a submitted release is
// kept as recorded until the acquire is submitted.
struct QueueFamilyOwnershipTransfer
{
    uint32_t src_queue_family_index{ VK_QUEUE_FAMILY_IGNORED };
    uint32_t dst_queue_family_index{ VK_QUEUE_FAMILY_IGNORED };

    // Buffer barriers only.
    VkDeviceSize offset{ 0 };
    VkDeviceSize size{ 0 };

    // Image barriers only.
    VkImageLayout           old_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    VkImageLayout           new_layout{ VK_IMAGE_LAYOUT_UNDEFINED };
    VkImageSubresourceRange subresource_range{};

    bool operator==(const QueueFamilyOwnershipTransfer& other) const
    {
        return (src_queue_family_index == other.src_queue_family_index) &&
               (dst_queue_family_index == other.dst_queue_family_index) && (offset == other.offset) &&
               (size == other.size) && (old_layout == other.old_layout) && (new_layout == other.new_layout) &&
               (subresource_range.aspectMask == other.subresource_range.aspectMask) &&
               (subresource_range.baseMipLevel == other.subresource_range.baseMipLevel) &&
               (subresource_range.levelCount == other.subresource_range.levelCount) &&
               (subresource_range.baseArrayLayer == other.subresource_range.baseArrayLayer) &&
               (subresource_range.layerCount == other.subresource_range.layerCount);
    }
};

// Whether a barrier with these queue family indices transfers ownership between two of the device's queue families.
// Transfers to or from an external or foreign owner are not included: the snapshot cannot re-create the other side.
inline bool IsQueueFamilyOwnershipTransfer(uint32_t src_queue_family_index, uint32_t dst_queue_family_index)
{
    const auto is_device_family = [](uint32_t index) {
        return (index != VK_QUEUE_FAMILY_IGNORED) && (index != VK_QUEUE_FAMILY_EXTERNAL) &&
               (index != VK_QUEUE_FAMILY_FOREIGN_EXT);
    };

    return (src_queue_family_index != dst_queue_family_index) && is_device_family(src_queue_family_index) &&
           is_device_family(dst_queue_family_index);
}

// Applies a submitted transfer to a resource's pending releases: a release is added, and an acquire removes the
// release it completes.
inline void ApplyQueueFamilyOwnershipTransfer(std::vector<QueueFamilyOwnershipTransfer>& pending_releases,
                                              const QueueFamilyOwnershipTransfer&        transfer,
                                              bool                                       is_release)
{
    const auto match = std::find(pending_releases.begin(), pending_releases.end(), transfer);

    if (is_release)
    {
        if (match == pending_releases.end())
        {
            pending_releases.push_back(transfer);
        }
    }
    else if (match != pending_releases.end())
    {
        pending_releases.erase(match);
    }
}

GFXRECON_END_NAMESPACE(vulkan_state_info)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_QUEUE_FAMILY_OWNERSHIP_H
