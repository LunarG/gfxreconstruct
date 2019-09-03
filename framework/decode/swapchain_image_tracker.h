/*
** Copyright (c) 2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_DECODE_SWAPCHAIN_IMAGE_TRACKER_H
#define GFXRECON_DECODE_SWAPCHAIN_IMAGE_TRACKER_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class SwapchainImageTracker
{
  public:
    bool TrackPreAcquiredImage(VkSwapchainKHR swapchain, uint32_t image_index, VkSemaphore semaphore, VkFence fence)
    {
        auto result = images_[swapchain].emplace(image_index, ImageAcquireResources{ semaphore, fence });
        return result.second;
    }

    bool
    RetrievePreAcquiredImage(VkSwapchainKHR swapchain, uint32_t image_index, VkSemaphore* semaphore, VkFence* fence)
    {
        bool found           = false;
        auto swapchain_entry = images_.find(swapchain);

        if (swapchain_entry != images_.end())
        {
            auto image_entry = swapchain_entry->second.find(image_index);
            if (image_entry != swapchain_entry->second.end())
            {
                found = true;

                if (semaphore != nullptr)
                {
                    (*semaphore) = image_entry->second.semaphore;
                }

                if (fence != nullptr)
                {
                    (*fence) = image_entry->second.fence;
                }

                swapchain_entry->second.erase(image_entry);
            }
        }

        return found;
    }

  private:
    struct ImageAcquireResources
    {
        VkSemaphore semaphore;
        VkFence     fence;
    };

    typedef std::unordered_map<uint32_t, ImageAcquireResources>   PreAcquiredImages;
    typedef std::unordered_map<VkSwapchainKHR, PreAcquiredImages> SwapchainImages;

  private:
    SwapchainImages images_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SWAPCHAIN_IMAGE_TRACKER_H
