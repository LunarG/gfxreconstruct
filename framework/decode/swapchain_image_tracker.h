/*
** Copyright (c) 2020 LunarG, Inc.
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
