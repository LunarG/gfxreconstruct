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

#include "application/wayland_window.h"

#include "util/logging.h"

#include <cassert>
#include <stdexcept>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

struct wl_surface_listener       WaylandWindow::surface_listener_;
struct wl_shell_surface_listener WaylandWindow::shell_surface_listener_;
struct xdg_surface_listener      WaylandWindow::xdg_surface_listener_;
struct xdg_toplevel_listener     WaylandWindow::xdg_toplevel_listener_;

WaylandWindow::WaylandWindow(WaylandContext* wayland_context) :
    wayland_context_(wayland_context), surface_(nullptr), shell_surface_(nullptr), xdg_surface_(nullptr),
    xdg_toplevel_(nullptr), width_(0), height_(0), scale_(1), output_(nullptr), xdg_surface_configured_(false)
{
    assert(wayland_context_ != nullptr);

    // Populate callback structs
    surface_listener_.enter = HandleSurfaceEnter;
    surface_listener_.leave = HandleSurfaceLeave;

    shell_surface_listener_.ping       = HandleShellSurfacePing;
    shell_surface_listener_.configure  = HandleShellSurfaceConfigure;
    shell_surface_listener_.popup_done = HandleShellSurfacePopupDone;

    xdg_surface_listener_.configure = HandleXdgSurfaceConfigure;

    xdg_toplevel_listener_.configure = HandleXdgToplevelConfigure;
    xdg_toplevel_listener_.close     = HandleXdgToplevelClose;
}

WaylandWindow::~WaylandWindow()
{
    if (surface_ != nullptr)
    {
        auto& wl = wayland_context_->GetWaylandFunctionTable();

        if (xdg_toplevel_ != nullptr)
        {
            wl.xdg->xdg_toplevel_destroy(xdg_toplevel_);
            wl.xdg->xdg_surface_destroy(xdg_surface_);
        }
        else if (shell_surface_ != nullptr)
        {
            wl.shell_surface_destroy(shell_surface_);
        }

        wl.surface_destroy(surface_);
    }
}

bool WaylandWindow::Create(const std::string& title,
                           const int32_t      x,
                           const int32_t      y,
                           const uint32_t     width,
                           const uint32_t     height,
                           bool               force_windowed)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(force_windowed);

    auto& wl = wayland_context_->GetWaylandFunctionTable();
    surface_ = wl.compositor_create_surface(wayland_context_->GetCompositor());

    if (surface_ == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create Wayland surface");
        return false;
    }

    // If we have the choice between xdg_toplevel and wl_shell_surface, chose the xdg_toplevel

    if (wayland_context_->GetXdgWmBase() != nullptr)
    {
        xdg_surface_ = wl.xdg->xdg_wm_base_get_xdg_surface(wayland_context_->GetXdgWmBase(), surface_);
        if (xdg_surface_ != nullptr)
        {
            wl.xdg->xdg_surface_add_listener(xdg_surface_, &WaylandWindow::xdg_surface_listener_, this);
            xdg_toplevel_ = wl.xdg->xdg_surface_get_toplevel(xdg_surface_);
        }
    }

    if (xdg_toplevel_ == nullptr && wayland_context_->GetShell() != nullptr)
    {
        shell_surface_ = wl.shell_get_shell_surface(wayland_context_->GetShell(), surface_);
    }

    // Check what was created, setup listener for it, and clean up if nothing was successfuly created

    wayland_context_->RegisterWaylandWindow(this);

    if (xdg_toplevel_ != nullptr)
    {
        wl.xdg->xdg_toplevel_add_listener(xdg_toplevel_, &WaylandWindow::xdg_toplevel_listener_, this);
    }
    else if (shell_surface_ != nullptr)
    {
        wl.shell_surface_add_listener(shell_surface_, &WaylandWindow::shell_surface_listener_, this);
    }
    else
    {
        if (xdg_surface_ != nullptr)
        {
            wl.xdg->xdg_surface_destroy(xdg_surface_);
            xdg_surface_ = nullptr;
        }

        GFXRECON_LOG_ERROR("Failed to create Wayland shell surface");
        return false;
    }

    wl.surface_add_listener(surface_, &WaylandWindow::surface_listener_, this);

    SetTitle(title);

    if (xdg_toplevel_ != nullptr)
    {
        wl.surface_commit(surface_);
        while (!xdg_surface_configured_)
        {
            wl.display_dispatch(wayland_context_->GetDisplay());
        }
    }

    width_  = width;
    height_ = height;
    UpdateWindowSize();

    return true;
}

bool WaylandWindow::Destroy()
{
    if (surface_ != nullptr)
    {
        wayland_context_->UnregisterWaylandWindow(this);

        auto& wl = wayland_context_->GetWaylandFunctionTable();

        if (xdg_toplevel_ != nullptr)
        {
            wl.xdg->xdg_toplevel_destroy(xdg_toplevel_);
            xdg_toplevel_ = nullptr;
            wl.xdg->xdg_surface_destroy(xdg_surface_);
            xdg_surface_ = nullptr;

            xdg_surface_configured_ = false;
        }
        else if (shell_surface_ != nullptr)
        {
            wl.shell_surface_destroy(shell_surface_);
            shell_surface_ = nullptr;
        }

        wl.surface_destroy(surface_);
        surface_ = nullptr;

        return true;
    }

    return false;
}

void WaylandWindow::SetTitle(const std::string& title)
{
    auto& wl = wayland_context_->GetWaylandFunctionTable();
    if (xdg_toplevel_ != nullptr)
    {
        wl.xdg->xdg_toplevel_set_title(xdg_toplevel_, title.c_str());
    }
    else if (shell_surface_ != nullptr)
    {
        wl.shell_surface_set_title(shell_surface_, title.c_str());
    }
}

void WaylandWindow::SetPosition(const int32_t x, const int32_t y)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    // TODO: May be possible with xdg-shell extension.
}

void WaylandWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if (width != width_ || height != height_)
    {
        width_  = width;
        height_ = height;
        UpdateWindowSize();
    }
}

void WaylandWindow::SetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    GFXRECON_UNREFERENCED_PARAMETER(pre_transform);
    SetSize(width, height);
}

void WaylandWindow::SetVisibility(bool show)
{
    GFXRECON_UNREFERENCED_PARAMETER(show);
}

void WaylandWindow::SetForeground() {}

bool WaylandWindow::GetNativeHandle(HandleType type, void** handle)
{
    assert(handle != nullptr);
    switch (type)
    {
        case Window::kWaylandDisplay:
            *handle = reinterpret_cast<void*>(wayland_context_->GetDisplay());
            return true;
        case Window::kWaylandSurface:
            *handle = reinterpret_cast<void*>(surface_);
            return true;
        default:
            return false;
    }
}

std::string WaylandWindow::GetWsiExtension() const
{
    return VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
}

VkExtent2D WaylandWindow::GetSize() const
{
    return { width_, height_ };
}

VkResult WaylandWindow::CreateSurface(const graphics::VulkanInstanceTable* table,
                                      VkInstance                           instance,
                                      VkFlags                              flags,
                                      VkSurfaceKHR*                        pSurface)
{
    if (table != nullptr)
    {
        VkWaylandSurfaceCreateInfoKHR create_info{
            VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR, nullptr, flags, wayland_context_->GetDisplay(), surface_
        };

        return table->CreateWaylandSurfaceKHR(instance, &create_info, nullptr, pSurface);
    }

    return VK_ERROR_INITIALIZATION_FAILED;
}

void WaylandWindow::DestroySurface(const graphics::VulkanInstanceTable* table,
                                   VkInstance                           instance,
                                   VkSurfaceKHR                         surface)
{
    if (table != nullptr)
    {
        table->DestroySurfaceKHR(instance, surface, nullptr);
    }
}

void WaylandWindow::UpdateWindowSize()
{
    auto& wl = wayland_context_->GetWaylandFunctionTable();
    if (output_)
    {
        auto& output_info = wayland_context_->GetOutputInfo(output_);

        if (output_info.scale > 0 && output_info.scale != scale_)
        {
            wl.surface_set_buffer_scale(surface_, output_info.scale);
            scale_ = output_info.scale;
        }

        if (output_info.width == width_ && output_info.height == height_)
        {
            if (xdg_toplevel_ != nullptr)
            {
                wl.xdg->xdg_toplevel_set_fullscreen(xdg_toplevel_, output_);
            }
            else if (shell_surface_ != nullptr)
            {
                wl.shell_surface_set_fullscreen(shell_surface_, WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT, 0, output_);
            }
        }
        else if (shell_surface_ != nullptr)
        {
            wl.shell_surface_set_toplevel(shell_surface_);
        }
    }
    else if (shell_surface_ != nullptr)
    {
        wl.shell_surface_set_toplevel(shell_surface_);
    }
}

void WaylandWindow::HandleSurfaceEnter(void* data, struct wl_surface* surface, struct wl_output* output)
{
    auto window     = reinterpret_cast<WaylandWindow*>(data);
    window->output_ = output;

    window->UpdateWindowSize();
}

void WaylandWindow::HandleSurfaceLeave(void* data, struct wl_surface* surface, struct wl_output* output) {}

void WaylandWindow::HandleShellSurfacePing(void* data, wl_shell_surface* shell_surface, uint32_t serial)
{
    auto& wl = reinterpret_cast<WaylandWindow*>(data)->wayland_context_->GetWaylandFunctionTable();
    wl.shell_surface_pong(shell_surface, serial);
}

void WaylandWindow::HandleShellSurfaceConfigure(
    void* data, wl_shell_surface* shell_surface, uint32_t edges, int32_t width, int32_t height)
{}

void WaylandWindow::HandleShellSurfacePopupDone(void* data, wl_shell_surface* shell_surface) {}

void WaylandWindow::HandleXdgSurfaceConfigure(void* data, struct xdg_surface* xdg_surface, uint32_t serial)
{
    WaylandWindow* window = reinterpret_cast<WaylandWindow*>(data);

    auto& wl = window->wayland_context_->GetWaylandFunctionTable();

    wl.xdg->xdg_surface_ack_configure(xdg_surface, serial);
    window->xdg_surface_configured_ = true;
}

void WaylandWindow::HandleXdgToplevelConfigure(
    void* data, struct xdg_toplevel* xdg_toplevel, int32_t width, int32_t height, struct wl_array* states)
{}

void WaylandWindow::HandleXdgToplevelClose(void* data, struct xdg_toplevel* xdg_toplevel) {}

WaylandWindowFactory::WaylandWindowFactory(WaylandContext* wayland_context) : wayland_context_(wayland_context)
{
    assert(wayland_context_ != nullptr);
}

decode::Window* WaylandWindowFactory::Create(
    const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, bool force_windowed)
{
    assert(wayland_context_);
    decode::Window* window      = new WaylandWindow(wayland_context_);
    auto            application = wayland_context_->GetApplication();
    assert(application);
    window->Create(application->GetName(), x, y, width, height, force_windowed);
    return window;
}

void WaylandWindowFactory::Destroy(decode::Window* window)
{
    if (window != nullptr)
    {
        window->Destroy();
        delete window;
    }
}

VkBool32 WaylandWindowFactory::GetPhysicalDevicePresentationSupport(const graphics::VulkanInstanceTable* table,
                                                                    VkPhysicalDevice physical_device,
                                                                    uint32_t         queue_family_index)
{
    assert(wayland_context_->GetDisplay() != nullptr);
    return table->GetPhysicalDeviceWaylandPresentationSupportKHR(
        physical_device, queue_family_index, wayland_context_->GetDisplay());
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
