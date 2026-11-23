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

#ifndef GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_UTIL_H

#include "graphics/vulkan_image_layout_map.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstddef>
#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Returns true if a subresource can be transitioned back to `layout`. VK_IMAGE_LAYOUT_UNDEFINED and
// VK_IMAGE_LAYOUT_PREINITIALIZED can only be transitioned away from.
bool IsRestorableLayout(VkImageLayout layout);

// Builds an image layout transition barrier that makes all prior memory accesses available and visible.
VkImageMemoryBarrier MakeLayoutRestoreBarrier(VkImage                        image,
                                              VkImageLayout                  old_layout,
                                              VkImageLayout                  new_layout,
                                              const VkImageSubresourceRange& subresource_range);

// Accounts for multi-planar formats, which require that all planes be transitioned together.
// If `transition_aspects` holds every plane of `image_aspects`, the planes are replaced with VK_IMAGE_ASPECT_COLOR_BIT.
VkImageAspectFlags ToBarrierAspects(VkImageAspectFlags transition_aspects, VkImageAspectFlags image_aspects);

// Appends the barriers that transition `image` from `current_layouts` to `target_layouts`. Aspects of a subresource
// that share the same transition are coalesced into one barrier. Subresources whose target layout is not restorable
// are skipped. Nothing is appended if either map is uninitialized.
void AppendImageLayoutBarriers(VkImage                            image,
                               const ImageLayoutMap&              current_layouts,
                               const ImageLayoutMap&              target_layouts,
                               std::vector<VkImageMemoryBarrier>& barriers);

// Returns true if every aspect in `aspects` of the subresource is in a restorable layout.
bool IsSubresourceCopyable(const ImageLayoutMap& layouts,
                           VkImageAspectFlags    aspects,
                           uint32_t              mip_level,
                           uint32_t              array_layer);

// Collects the subresources whose layout at the start of the loop range can be transitioned away from and back to
// into `ranges`, and the rest into `excluded_ranges`. Neighbouring array layers are coalesced into a single range.
void BuildCopyableSubresourceRanges(VkFormat                              format,
                                    uint32_t                              mip_levels,
                                    uint32_t                              array_layers,
                                    const ImageLayoutMap&                 initial_layouts,
                                    std::vector<VkImageSubresourceRange>& ranges,
                                    std::vector<VkImageSubresourceRange>& excluded_ranges);

// Appends the barriers that transition `image` from `current_layouts` to `transfer_layout`, leaving the subresources
// in `excluded_ranges` untouched.
void AppendTransferLayoutBarriers(VkImage                                     image,
                                  const ImageLayoutMap&                       current_layouts,
                                  const std::vector<VkImageSubresourceRange>& excluded_ranges,
                                  VkImageLayout                               transfer_layout,
                                  std::vector<VkImageMemoryBarrier>&          barriers);

// Swaps the old and new layouts of every barrier from `first` onwards.
void ReverseLayoutBarriers(std::vector<VkImageMemoryBarrier>& barriers, size_t first = 0);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_UTIL_H
