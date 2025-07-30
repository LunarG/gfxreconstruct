/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "graphics/vulkan_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

util::platform::LibraryHandle InitializeLoader(const char* loader_path)
{
    if (loader_path != nullptr && loader_path[0] != '\0')
    {
        return util::platform::OpenLibrary(loader_path);
    }
    else
    {
        return util::platform::OpenLibrary(kLoaderLibNames);
    }
}

void ReleaseLoader(util::platform::LibraryHandle loader_handle)
{
    if (loader_handle != nullptr)
    {
        util::platform::CloseLibrary(loader_handle);
    }
}

bool ImageHasUsage(VkImageUsageFlags usage_flags, VkImageUsageFlagBits bit)
{
    return (usage_flags & bit) == bit;
}

template <typename T>
std::vector<std::pair<VkSemaphore, uint64_t>> StripWaitSemaphoresUtil(T* submit_info)
{
    static_assert(std::is_same_v<T, VkSubmitInfo> || std::is_same_v<T, VkSubmitInfo2>);
    std::vector<std::pair<VkSemaphore, uint64_t>> semaphore_wait_infos;

    if constexpr (std::is_same_v<T, VkSubmitInfo>)
    {
        semaphore_wait_infos.resize(submit_info->waitSemaphoreCount);

        for (uint32_t s = 0; s < submit_info->waitSemaphoreCount; ++s)
        {
            semaphore_wait_infos[s] = { submit_info->pWaitSemaphores[s], 1 };
        }

        if (auto* timeline_info = graphics::vulkan_struct_get_pnext<VkTimelineSemaphoreSubmitInfo>(submit_info))
        {
            GFXRECON_ASSERT(submit_info->waitSemaphoreCount == timeline_info->waitSemaphoreValueCount);

            for (uint32_t s = 0; s < timeline_info->waitSemaphoreValueCount; ++s)
            {
                semaphore_wait_infos[s].second = timeline_info->pWaitSemaphoreValues[s];
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
            semaphore_wait_infos[s] = { submit_info->pWaitSemaphoreInfos[s].semaphore,
                                        submit_info->pWaitSemaphoreInfos[s].value };
        }

        // strip out wait-semaphores from submit-info
        submit_info->waitSemaphoreInfoCount = 0;
        submit_info->pWaitSemaphoreInfos    = nullptr;
    }
    return semaphore_wait_infos;
}

std::vector<std::pair<VkSemaphore, uint64_t>> StripWaitSemaphores(VkSubmitInfo* submit_info)
{
    return StripWaitSemaphoresUtil(submit_info);
}

std::vector<std::pair<VkSemaphore, uint64_t>> StripWaitSemaphores(VkSubmitInfo2* submit_info)
{
    return StripWaitSemaphoresUtil(submit_info);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
