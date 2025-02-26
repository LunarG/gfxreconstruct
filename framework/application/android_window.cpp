/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "application/android_window.h"
#include "application/application.h"
#include "util/logging.h"

#include <android/native_window.h>

#include <array>
#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)
ANativeWindow* tmp_window = nullptr;

AndroidWindow::AndroidWindow(AndroidContext* android_context, ANativeWindow* window) :
    android_context_(android_context), window_(window), width_(0), height_(0), pre_transform_(0)
{
    assert((android_context_ != nullptr) && (window != nullptr));

    width_  = ANativeWindow_getWidth(window_);
    height_ = ANativeWindow_getHeight(window_);
}

void AndroidWindow::SetSize(const uint32_t width, const uint32_t height)
{
    SetSizePreTransform(width, height, format::ResizeWindowPreTransform::kPreTransform0);
}

void AndroidWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    if ((width != width_) || (height != height_) || (pre_transform != pre_transform_))
    {
        width_         = width;
        height_        = height;
        pre_transform_ = pre_transform;

        // For Android, we adjust the screen orientation based on requested width and height.
        int32_t pixel_width  = ANativeWindow_getWidth(window_);
        int32_t pixel_height = ANativeWindow_getHeight(window_);

        // We don't change the current orientation if width == height or if the requested orientation matches the
        // current orientation, unless a pre-transform has been applied to the swapchain, in which case the orientation
        // will be adjusted to match the pre-transform.
        if (((width != height) && ((width < height) != (pixel_width < pixel_height))) ||
            (pre_transform != format::ResizeWindowPreTransform::kPreTransform0))
        {
            const std::array<AndroidContext::ScreenOrientation, 2> kOrientations{
                AndroidContext::ScreenOrientation::kLandscape, AndroidContext::ScreenOrientation::kPortrait
            };

            uint32_t orientation_index = 0;

            if (height > width)
            {
                orientation_index = 1;
            }

            // Toggle orientation between landscape and portrait for 90 and 270 degree pre-transform values.
            if ((pre_transform == format::ResizeWindowPreTransform::kPreTransform90) ||
                (pre_transform == format::ResizeWindowPreTransform::kPreTransform270))
            {
                orientation_index ^= 1;
            }

            android_context_->SetOrientation(kOrientations[orientation_index]);
        }

        int32_t result = ANativeWindow_setBuffersGeometry(window_, width, height, ANativeWindow_getFormat(window_));
        if (result != 0)
        {
            GFXRECON_LOG_ERROR("Failed to change native window geometry: ANativeWindow_setBuffersGeometry returned %d",
                               result);
        }
    }
}

bool AndroidWindow::GetNativeHandle(HandleType type, void** handle)
{
    assert(handle != nullptr);

    switch (type)
    {
        case Window::kAndroidNativeWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

std::string AndroidWindow::GetWsiExtension() const
{
    return VK_KHR_ANDROID_SURFACE_EXTENSION_NAME;
}

VkExtent2D AndroidWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult AndroidWindow::CreateSurface(const encode::VulkanInstanceTable* table,
                                      VkInstance                         instance,
                                      VkFlags                            flags,
                                      VkSurfaceKHR*                      pSurface)
{
    if (table != nullptr)
    {
        VkAndroidSurfaceCreateInfoKHR create_info{
            VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR, nullptr, flags, window_
        };

        return table->CreateAndroidSurfaceKHR(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void AndroidWindow::DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

AndroidWindowFactory::AndroidWindowFactory(AndroidContext* android_context) : android_context_(android_context)
{
    assert(android_context_ != nullptr);
}

AndroidWindowFactory::~AndroidWindowFactory() {}

decode::Window* AndroidWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);

#ifdef GFXR_MULTI_WINDOW_REPLAY
    tmp_window = nullptr;
    android_context_->requestNativeWindow(width, height);
    AndroidWindow* tmpwin = nullptr;
    if (tmp_window != nullptr)
    {
        tmpwin = new AndroidWindow(android_context_, tmp_window);
        GFXRECON_LOG_INFO("Got android window %p", tmp_window);
    }
    else
    {
        GFXRECON_LOG_WARNING("Get android window failed");
    }
    return tmpwin;
#else // !GFXR_MULTI_WINDOW_REPLAY
    return android_context_->GetWindow();
#endif
}

void AndroidWindowFactory::Destroy(decode::Window* window)
{
#ifdef GFXR_MULTI_WINDOW_REPLAY
    if (window)
    {
        ANativeWindow* native_window = nullptr;
        if (window->GetNativeHandle(decode::Window::kAndroidNativeWindow, reinterpret_cast<void**>(&native_window)))
        {
            ANativeWindow_release(native_window);
        }
        else
        {
            GFXRECON_LOG_ERROR("Couldn't retrieve Android native window from window %p for destruction", window)
        }

        int32_t window_index = created_window_.at(window);
        android_context_->destroyNativeWindow(window_index);
    }
#else // !GFXR_MULTI_WINDOW_REPLAY
    // Standard replay app only has a single window whose lifetime is managed by AndroidContext.
    GFXRECON_UNREFERENCED_PARAMETER(window);
#endif
}

VkBool32 AndroidWindowFactory::GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                                    VkPhysicalDevice                   physical_device,
                                                                    uint32_t queue_family_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(table);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(queue_family_index);

    return VK_TRUE;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
