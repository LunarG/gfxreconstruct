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

#ifndef GFXRECON_APPLICATION_XLIB_WINDOW_H
#define GFXRECON_APPLICATION_XLIB_WINDOW_H

#include "application/xlib_context.h"
#include "decode/window.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class XlibWindow : public decode::Window
{
  public:
    XlibWindow(XlibContext* xlib_context);

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

    virtual std::string GetWsiExtension() const override;

    virtual VkResult CreateSurface(const encode::VulkanInstanceTable* table,
                                   VkInstance                         instance,
                                   VkFlags                            flags,
                                   VkSurfaceKHR*                      pSurface) override;

    virtual void
    DestroySurface(const encode::VulkanInstanceTable* table, VkInstance instance, VkSurfaceKHR surface) override;

  private:
    void SetFullscreen(bool fullscreen);

  private:
  private:
    XlibContext* xlib_context_;
    Display*     display_;
    ::Window     window_;
    uint32_t     width_;
    uint32_t     height_;
    uint32_t     screen_width_;
    uint32_t     screen_height_;
    bool         visible_;
    bool         fullscreen_;
};

class XlibWindowFactory : public decode::WindowFactory
{
  public:
    XlibWindowFactory(XlibContext* xlib_context);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_XLIB_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                          VkPhysicalDevice                   physical_device,
                                                          uint32_t queue_family_index) override;

  private:
    XlibContext* xlib_context_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_XLIB_WINDOW_H