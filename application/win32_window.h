/*
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

#ifndef BRIMSTONE_APPLICATION_WIN32_WINDOW_H
#define BRIMSTONE_APPLICATION_WIN32_WINDOW_H

#include "util/defines.h"
#include "util/platform.h"
#include "format/window.h"
#include "application/win32_application.h"

#define IDI_ICON 101

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

class Win32Window : public format::Window
{
  public:
    enum HandleId : uint32_t
    {
        kHInstance = 0,
        kHWnd      = 1
    };

  public:
    Win32Window(Win32Application* application);

    virtual ~Win32Window();

    virtual bool Create(const std::string& title, const int32_t xpos, const int32_t ypos, const uint32_t width, const uint32_t height) override;

    virtual bool Destroy() override;

    virtual void SetTitle(const std::string& title) override;

    virtual void SetPosition(const int32_t x, const int32_t y) override;

    virtual void SetSize(const uint32_t width, const uint32_t height) override;

    virtual void SetVisibility(bool show) override;

    virtual void SetForeground() override;

    virtual bool GetNativeHandle(uint32_t id, void** handle) override;

    virtual VkResult CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface) override;

  private:
    HWND              hwnd_;
    Win32Application* win32_application_;
    int32_t           xpos_;
    int32_t           ypos_;
    uint32_t          width_;
    uint32_t          height_;
    uint32_t          screen_width_;
    uint32_t          screen_height_;
    HINSTANCE         hinstance_;
};

class Win32WindowFactory : public format::WindowFactory
{
  public:
    Win32WindowFactory(Win32Application* application);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_WIN32_SURFACE_EXTENSION_NAME; }

    virtual format::Window* Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(VkPhysicalDevice physical_device,
                                                          uint32_t         queue_family_index) override;

  private:
    Win32Application* win32_application_;
};

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_APPLICATION_WIN32_WINDOW_H