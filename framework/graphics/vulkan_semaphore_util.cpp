/*
** Copyright (c) 2021-2026 LunarG, Inc.
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

#include "graphics/vulkan_semaphore_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

template <typename T>
std::vector<VulkanSemaphore> StripWaitSemaphoresUtil(T* submit_info)
{
    static_assert(std::is_same_v<T, VkSubmitInfo> || std::is_same_v<T, VkSubmitInfo2>);
    std::vector<VulkanSemaphore> semaphore_wait_infos;

    if constexpr (std::is_same_v<T, VkSubmitInfo>)
    {
        semaphore_wait_infos.resize(submit_info->waitSemaphoreCount);

        for (uint32_t s = 0; s < submit_info->waitSemaphoreCount; ++s)
        {
            semaphore_wait_infos[s] = VulkanSemaphore{ submit_info->pWaitSemaphores[s], 1 };
        }

        if (auto* timeline_info = graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(submit_info))
        {
            GFXRECON_ASSERT(submit_info->waitSemaphoreCount == timeline_info->waitSemaphoreValueCount);

            for (uint32_t s = 0; s < timeline_info->waitSemaphoreValueCount; ++s)
            {
                semaphore_wait_infos[s].timeline_value = timeline_info->pWaitSemaphoreValues[s];
            }

            // strip out wait-semaphores from timeline_info-info
            timeline_info->waitSemaphoreValueCount = 0;
            timeline_info->pWaitSemaphoreValues    = nullptr;
        }

        // strip out wait-semaphores from submit-info
        submit_info->waitSemaphoreCount = 0;
        submit_info->pWaitSemaphores    = nullptr;
    }

    if constexpr (std::is_same_v<T, VkSubmitInfo2>)
    {
        semaphore_wait_infos.resize(submit_info->waitSemaphoreInfoCount);

        for (uint32_t s = 0; s < submit_info->waitSemaphoreInfoCount; ++s)
        {
            semaphore_wait_infos[s] = VulkanSemaphore{ submit_info->pWaitSemaphoreInfos[s].semaphore,
                                                       submit_info->pWaitSemaphoreInfos[s].value };
        }

        // strip out wait-semaphores from submit-info
        submit_info->waitSemaphoreInfoCount = 0;
        submit_info->pWaitSemaphoreInfos    = nullptr;
    }
    return semaphore_wait_infos;
}

std::vector<VulkanSemaphore> StripWaitSemaphores(VkSubmitInfo* submit_info)
{
    return StripWaitSemaphoresUtil(submit_info);
}

std::vector<VulkanSemaphore> StripWaitSemaphores(VkSubmitInfo2* submit_info)
{
    return StripWaitSemaphoresUtil(submit_info);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
