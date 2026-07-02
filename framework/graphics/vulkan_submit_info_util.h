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

//  SubmitInfoTranslator narrows an array of VkSubmitInfo2 structures into the equivalent array of VkSubmitInfo
//  structures, so that callers can forward to vkQueueSubmit when neither vkQueueSubmit2 (Vulkan 1.3) nor
//  vkQueueSubmit2KHR (VK_KHR_synchronization2) is available.
//
//  VkSubmitInfo2 carries timeline values and device-group indices/masks inline in its sub-structures and encodes
//  protected submission in its flags, whereas VkSubmitInfo conveys all of these through pNext structures. Those
//  VkTimelineSemaphoreSubmitInfo / VkDeviceGroupSubmitInfo / VkProtectedSubmitInfo structures are reconstructed and
//  chained ahead of the original pNext chain.
//
//  The per-semaphore wait stage masks are narrowed from VkPipelineStageFlags2 to VkPipelineStageFlags. These are only
//  meaningful for queue-side synchronization, so this translation is intended for callers that serialize their submits
//  with host fence waits.
class SubmitInfoTranslator
{
  public:
    explicit SubmitInfoTranslator(std::span<const VkSubmitInfo2> submit_infos_2);

    const std::vector<VkSubmitInfo>& GetSubmitInfos() const { return submit_infos_; }

  private:
    // The translated submit infos. Each entry references the backing storage below.
    std::vector<VkSubmitInfo> submit_infos_;

    // Backing storage referenced by submit_infos_. Indexed per source VkSubmitInfo2.
    std::vector<std::vector<VkSemaphore>>          wait_semaphores_;
    std::vector<std::vector<VkPipelineStageFlags>> wait_stage_masks_;
    std::vector<std::vector<VkCommandBuffer>>      command_buffers_;
    std::vector<std::vector<VkSemaphore>>          signal_semaphores_;

    // Backing storage for the reconstructed pNext structures and the arrays they reference.
    // Indexed per source VkSubmitInfo2.
    std::vector<std::vector<uint64_t>> wait_values_;
    std::vector<std::vector<uint64_t>> signal_values_;
    std::vector<std::vector<uint32_t>> wait_device_indices_;
    std::vector<std::vector<uint32_t>> signal_device_indices_;
    std::vector<std::vector<uint32_t>> command_buffer_device_masks_;

    // The structs that will be injected in the pNext chain if necessary.
    // Indexed per source VkSubmitInfo2.
    std::vector<VkTimelineSemaphoreSubmitInfo> timeline_submit_infos_;
    std::vector<VkDeviceGroupSubmitInfo>       device_group_submit_infos_;
    std::vector<VkProtectedSubmitInfo>         protected_submit_infos_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_SUBMIT_INFO_UTIL_H
