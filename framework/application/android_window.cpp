/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "application/android_window.h"

#include "util/logging.h"

#include <android/native_window.h>

#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

AndroidWindow::AndroidWindow(AndroidApplication* application, ANativeWindow* window) :
    android_application_(application), window_(window), width_(0), height_(0)
{
    assert((application != nullptr) && (window != nullptr));

    width_  = ANativeWindow_getWidth(window_);
    height_ = ANativeWindow_getHeight(window_);
}

void AndroidWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if ((width != width_) || (height != height_))
    {
        width_  = width;
        height_ = height;

        // For Android, we adjust the screen orientation based on requested width and height.
        int32_t pixel_width  = ANativeWindow_getWidth(window_);
        int32_t pixel_height = ANativeWindow_getHeight(window_);

        // We don't change the current orientation if width == height or if the requested orientation matches the
        // current orientation.
        if ((width != height) && ((width < height) != (pixel_width < pixel_height)))
        {
            if (width > height)
            {
                android_application_->SetOrientation(AndroidApplication::ScreenOrientation::kLandscape);
            }
            else
            {
                android_application_->SetOrientation(AndroidApplication::ScreenOrientation::kPortrait);
            }
        }

        int32_t result = ANativeWindow_setBuffersGeometry(window_, width, height, ANativeWindow_getFormat(window_));
        if (result != 0)
        {
            GFXRECON_LOG_ERROR("Failed to change native window geometry: ANativeWindow_setBuffersGeometry returned %d",
                               result);
        }
    }
}

bool AndroidWindow::GetNativeHandle(uint32_t id, void** handle)
{
    assert(handle != nullptr);

    switch (id)
    {
        case AndroidWindow::kNativeWindow:
            *handle = reinterpret_cast<void*>(window_);
            return true;
        default:
            return false;
    }
}

VkResult AndroidWindow::CreateSurface(const encode::InstanceTable* table,
                                      VkInstance                   instance,
                                      VkFlags                      flags,
                                      VkSurfaceKHR*                pSurface)
{
    VkAndroidSurfaceCreateInfoKHR create_info{
        VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR, nullptr, flags, window_
    };

    return table->CreateAndroidSurfaceKHR(instance, &create_info, nullptr, pSurface);
}

AndroidWindowFactory::AndroidWindowFactory(AndroidApplication* application) : android_application_(application)
{
    assert(application != nullptr);
}

AndroidWindowFactory::~AndroidWindowFactory() {}

decode::Window*
AndroidWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);

    return android_application_->GetWindow();
}

void AndroidWindowFactory::Destroy(decode::Window* window)
{
    // Android currently has a single window whose lifetime is managed by AndroidApplication.
    GFXRECON_UNREFERENCED_PARAMETER(window);
}

VkBool32 AndroidWindowFactory::GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                                    VkPhysicalDevice             physical_device,
                                                                    uint32_t                     queue_family_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(table);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(queue_family_index);

    return VK_TRUE;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
