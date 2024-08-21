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

#ifndef GFXRECON_DECODE_WINDOW_H
#define GFXRECON_DECODE_WINDOW_H

#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Window
{
  public:
    enum HandleType
    {
        kAndroidNativeWindow,
        kXcbConnection,
        kXcbWindow,
        kXlibDisplay,
        kXlibWindow,
        kWaylandDisplay,
        kWaylandSurface,
        kWin32HInstance,
        kWin32HWnd,
        kMetalLayer,
    };

  public:
    Window() {}

    virtual ~Window() {}

    virtual bool Create(const std::string& title,
                        const int32_t      xpos,
                        const int32_t      ypos,
                        const uint32_t     width,
                        const uint32_t     height,
                        bool               force_windowed = false) = 0;

    virtual bool Destroy() = 0;

    virtual void SetTitle(const std::string& title) = 0;

    virtual void SetPosition(const int32_t x, const int32_t y) = 0;

    virtual void SetSize(const uint32_t width, const uint32_t height) = 0;

    virtual void SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) = 0;

    virtual void SetVisibility(bool show) = 0;

    virtual void SetForeground() = 0;

    virtual bool GetNativeHandle(HandleType type, void** handle) = 0;

    virtual std::string GetWsiExtension() const = 0;

    virtual VkResult CreateSurface(const encode::VulkanInstanceTable* table,
                                   VkInstance                         instance,
                                   VkFlags                            flags,
                                   VkSurfaceKHR*                      pSurface) = 0;

    virtual void
    DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface) = 0;
};

class WindowFactory
{
  public:
    WindowFactory() {}

    virtual ~WindowFactory() {}

    virtual const char* GetSurfaceExtensionName() const = 0;

    virtual Window* Create(
        const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed = false) = 0;

    virtual void Destroy(Window* window) = 0;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                          VkPhysicalDevice                   physical_device,
                                                          uint32_t                           queue_family_index) = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_WINDOW_H