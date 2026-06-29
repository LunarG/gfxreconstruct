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

#ifndef GFXRECON_GRAPHICS_VULKAN_SUBMIT_INFO_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_SUBMIT_INFO_UTIL_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <span>
#include <vector>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

//  SubmitInfo2Translator losslessly widens an array of VkSubmitInfo structures into the equivalent array of
//  VkSubmitInfo2 structures, so that callers can forward to vkQueueSubmit2.
//
//  VkTimelineSemaphoreSubmitInfo, VkProtectedSubmitInfo and VkDeviceGroupSubmitInfo are handled by translation: their
//  information is copied into the VkSubmitInfo2 / VkSemaphoreSubmitInfo / VkCommandBufferSubmitInfo fields and the
//  structures themselves are removed from the pNext chain. All other pNext structures that are valid on VkSubmitInfo2
//  are preserved; the remaining VkSubmitInfo-only structures (e.g. VkD3D12FenceSubmitInfoKHR) are not translated.
class SubmitInfo2Translator
{
  public:
    explicit SubmitInfo2Translator(std::span<const VkSubmitInfo> submit_infos);

    const std::vector<VkSubmitInfo2>& GetSubmitInfos2() const { return submit_infos_2_; }

  private:
    // The translated submit infos. Each entry references the backing storage below.
    std::vector<VkSubmitInfo2> submit_infos_2_;

    // Backing storage referenced by submit_infos_2_. Indexed per source VkSubmitInfo.
    std::vector<std::vector<VkSemaphoreSubmitInfo>>     wait_semaphores_;
    std::vector<std::vector<VkCommandBufferSubmitInfo>> command_buffers_;
    std::vector<std::vector<VkSemaphoreSubmitInfo>>     signal_semaphores_;

    // Deep copies of the source pNext chains, only populated for submits whose chain had to be edited.
    std::vector<std::vector<uint8_t>> pnext_deep_copies_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_SUBMIT_INFO_UTIL_H
