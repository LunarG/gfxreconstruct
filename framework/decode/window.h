/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
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
        kWin32HWnd
    };

  public:
    Window() {}

    virtual ~Window() {}

    virtual bool Create(const std::string& title,
                        const int32_t      xpos,
                        const int32_t      ypos,
                        const uint32_t     width,
                        const uint32_t     height) = 0;

    virtual bool Destroy() = 0;

    virtual void SetTitle(const std::string& title) = 0;

    virtual void SetPosition(const int32_t x, const int32_t y) = 0;

    virtual void SetSize(const uint32_t width, const uint32_t height) = 0;

    virtual void SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) = 0;

    virtual void SetVisibility(bool show) = 0;

    virtual void SetForeground() = 0;

    virtual bool GetNativeHandle(HandleType type, void** handle) = 0;

    virtual VkResult
    CreateSurface(const encode::InstanceTable* table, VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) = 0;
};

class WindowFactory
{
  public:
    WindowFactory(){};

    virtual ~WindowFactory(){};

    virtual const char* GetSurfaceExtensionName() const = 0;

    virtual Window* Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) = 0;

    virtual void Destroy(Window* window) = 0;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_WINDOW_H