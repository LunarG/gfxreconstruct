/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_XLIB_WINDOW_H
#define GFXRECON_APPLICATION_XLIB_WINDOW_H

#include "application/xlib_application.h"
#include "decode/window.h"
#include "util/defines.h"

#include <X11/Xlib.h>
#include <X11/X.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XlibWindow : public decode::Window
{
  public:
    XlibWindow(XlibApplication* application);

    virtual ~XlibWindow() override;

    virtual bool Create(const std::string& title,
                        const int32_t      xpos,
                        const int32_t      ypos,
                        const uint32_t     width,
                        const uint32_t     height) override;

    virtual bool Destroy() override;

    virtual void SetTitle(const std::string& title) override;

    virtual void SetPosition(const int32_t x, const int32_t y) override;

    virtual void SetSize(const uint32_t width, const uint32_t height) override;

    virtual void
    SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform) override;

    virtual void SetVisibility(bool show) override;

    virtual void SetForeground() override;

    virtual bool GetNativeHandle(HandleType type, void** handle) override;

    virtual VkResult CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface) override;

    virtual void DestroySurface(const encode::InstanceTable* table, VkInstance instance, VkSurfaceKHR surface) override;

  private:
    void SetFullscreen(bool fullscreen);

  private:
  private:
    XlibApplication* xlib_application_;
    ::Window         window_;
    uint32_t         width_;
    uint32_t         height_;
    uint32_t         screen_width_;
    uint32_t         screen_height_;
    bool             visible_;
    bool             fullscreen_;
};

class XlibWindowFactory : public decode::WindowFactory
{
  public:
    XlibWindowFactory(XlibApplication* application);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_XLIB_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) override;

  private:
    XlibApplication* xlib_application_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XLIB_WINDOW_H