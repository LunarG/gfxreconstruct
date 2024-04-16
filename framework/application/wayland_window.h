/*
** Copyright (c) 2018,2020 Valve Corporation
** Copyright (c) 2018,2020 LunarG, Inc.
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

#ifndef GFXRECON_APPLICATION_WAYLAND_WINDOW_H
#define GFXRECON_APPLICATION_WAYLAND_WINDOW_H

#include "application/wayland_context.h"
#include "decode/window.h"
#include "util/defines.h"

#include <wayland-client.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class WaylandWindow : public decode::Window
{
  public:
    WaylandWindow(WaylandContext* wayland_context);

    virtual ~WaylandWindow() override;

    struct wl_surface* GetSurface() const { return surface_; }

    struct wl_shell_surface* GetShellSurface() const { return shell_surface_; }

    struct xdg_toplevel* GetXdgToplevel() const { return xdg_toplevel_; }

    virtual bool Create(const std::string& title,
                        const int32_t      x,
                        const int32_t      y,
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
    static void HandleSurfaceEnter(void* data, struct wl_surface* surface, struct wl_output* output);
    static void HandleSurfaceLeave(void* data, struct wl_surface* surface, struct wl_output* output);

    static void HandleShellSurfacePing(void* data, wl_shell_surface* shell_surface, uint32_t serial);
    static void HandleShellSurfaceConfigure(
        void* data, wl_shell_surface* shell_surface, uint32_t edges, int32_t width, int32_t height);
    static void HandleShellSurfacePopupDone(void* data, wl_shell_surface* shell_surface);

    static void HandleXdgSurfaceConfigure(void* data, struct xdg_surface* xdg_surface, uint32_t serial);

    static void HandleXdgToplevelConfigure(
        void* data, struct xdg_toplevel* xdg_toplevel, int32_t width, int32_t height, struct wl_array* states);
    static void HandleXdgToplevelClose(void* data, struct xdg_toplevel* xdg_toplevel);

    void UpdateWindowSize();

  private:
    static struct wl_surface_listener       surface_listener_;
    static struct wl_shell_surface_listener shell_surface_listener_;
    static struct xdg_surface_listener      xdg_surface_listener_;
    static struct xdg_toplevel_listener     xdg_toplevel_listener_;
    WaylandContext*                         wayland_context_;
    struct wl_surface*                      surface_;
    struct wl_shell_surface*                shell_surface_;
    struct xdg_surface*                     xdg_surface_;
    struct xdg_toplevel*                    xdg_toplevel_;
    uint32_t                                width_;
    uint32_t                                height_;
    int32_t                                 scale_;
    struct wl_output*                       output_;
    bool                                    xdg_surface_configured_;
};

class WaylandWindowFactory : public decode::WindowFactory
{
  public:
    WaylandWindowFactory(WaylandContext* wayland_context);

    virtual const char* GetSurfaceExtensionName() const override { return VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::VulkanInstanceTable* table,
                                                          VkPhysicalDevice                   physical_device,
                                                          uint32_t queue_family_index) override;

  private:
    WaylandContext* wayland_context_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_WAYLAND_WINDOW_H
