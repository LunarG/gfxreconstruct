/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_UTIL_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"
#include "util/platform.h"

#include "vulkan/vulkan.h"

#if VK_USE_64_BIT_PTR_DEFINES == 1
#define VK_HANDLE_TO_UINT64(value) reinterpret_cast<uint64_t>(value)
#define UINT64_TO_VK_HANDLE(handle_type, value) reinterpret_cast<handle_type>(value)
#else
#define VK_HANDLE_TO_UINT64(value) (value)
#define UINT64_TO_VK_HANDLE(handle_type, value) static_cast<handle_type>(value)
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

typedef uint64_t PresentId;

const std::vector<std::string> kLoaderLibNames = {
#if defined(WIN32)
    "vulkan-1.dll"
#elif defined(__APPLE__)
    "libvulkan.dylib", "libvulkan.1.dylib", "libMoltenVK.dylib"
#else
    "libvulkan.so.1", "libvulkan.so"
#endif
};

/// @brief Initialize the Vulkan loader by loading the Vulkan library.
/// @param loader_path Optional path to the Vulkan loader library. If not provided, the function will search for
/// `kLoaderLibNames` in the system library paths.
/// @return A handle to the loaded Vulkan library, or nullptr if the library could not be loaded.
util::platform::LibraryHandle InitializeLoader(const char* loader_path = nullptr);

void ReleaseLoader(util::platform::LibraryHandle loader_handle);

bool ImageHasUsage(VkImageUsageFlags usage_flags, VkImageUsageFlagBits bit);

/**
 * @brief   copy_dispatch_table_from_device can be used if a command-buffer was not allocated through the loader,
 *          in order to assign the dispatch table from an existing VkDevice.
 *
 * @param   device  a VkDevice handle
 * @param   handle  a VkCommandBuffer handle
 */
static inline void copy_dispatch_table_from_device(VkDevice device, VkCommandBuffer handle)
{
    // Because this command buffer was not allocated through the loader, it must be assigned a dispatch table.
    *reinterpret_cast<void**>(handle) = *reinterpret_cast<void**>(device);
}

/**
 * @brief   StripWaitSemaphores can be used to remove all wait-semaphores for a provided VkSubmitInfo.
 *          Respective pointer in submit_info will be set to nullptr and count to zero.
 *
 * @param   submit_info     a provided VkSubmitInfo(2) struct
 * @return  an array of Semaphores that have been stripped/removed from submit_info
 */
std::vector<std::pair<VkSemaphore, uint64_t>> StripWaitSemaphores(VkSubmitInfo* submit_info);
std::vector<std::pair<VkSemaphore, uint64_t>> StripWaitSemaphores(VkSubmitInfo2* submit_info);

[[maybe_unused]] static const char* kVulkanVrFrameDelimiterString = "vr-marker,frame_end,type,application";

/**
 * @brief   Scales a VkExtent3D to the provided mip map level
 *
 * @param[in]   extent    The VkExtent3D to scale
 * @param[in]   level     The mip map level
 * @return  The scaled VkExtent3D
 */
static constexpr VkExtent3D ScaleToMipLevel(const VkExtent3D& extent, uint32_t level)
{
    const VkExtent3D mip_extent = VkExtent3D{ std::max(1u, extent.width >> level),
                                              std::max(1u, extent.height >> level),
                                              std::max(1u, extent.depth >> level) };

    return mip_extent;
}

/**
 * @brief   Scales a VkExtent3D with the provided scaling factor
 *
 * @param[in]   extent    The VkExtent3D to scale
 * @param[in]   scale     The scaling factor
 * @return  The scaled VkExtent3D
 */
static constexpr VkExtent3D ScaleExtent(const VkExtent3D& extent, float scale)
{
    const VkExtent3D scaled_extent =
        VkExtent3D{ static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.width) * scale)),
                    static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.height) * scale)),
                    static_cast<uint32_t>(std::max(1.0f, static_cast<float>(extent.depth) * scale)) };

    return scaled_extent;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_UTIL_H
