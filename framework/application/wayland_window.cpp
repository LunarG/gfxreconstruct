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

#include "application/wayland_window.h"

#include "util/logging.h"

#include <cassert>
#include <stdexcept>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

struct wl_shell_surface_listener WaylandWindow::shell_surface_listener_;

WaylandWindow::WaylandWindow(WaylandApplication* application) :
    wayland_application_(application), surface_(nullptr), shell_surface_(nullptr)
{
    assert(application != nullptr);

    // Populate callback structs
    shell_surface_listener_.ping       = HandlePing;
    shell_surface_listener_.configure  = HandleConfigure;
    shell_surface_listener_.popup_done = HandlePopupDone;
}

WaylandWindow::~WaylandWindow()
{
    auto& wl = wayland_application_->GetWaylandFunctionTable();
    if (surface_)
    {
        if (shell_surface_)
        {
            wl.shell_surface_destroy(shell_surface_);
        }

        wl.surface_destroy(surface_);
    }
}

bool WaylandWindow::Create(
    const std::string& title, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);

    auto& wl = wayland_application_->GetWaylandFunctionTable();
    surface_ = wl.compositor_create_surface(wayland_application_->GetCompositor());

    if (surface_ == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to create Wayland surface");
        return false;
    }

    shell_surface_ = wl.shell_get_shell_surface(wayland_application_->GetShell(), surface_);
    if (!shell_surface_)
    {
        GFXRECON_LOG_ERROR("Failed to create Wayland shell surface");
        return false;
    }

    wayland_application_->RegisterWaylandWindow(this);

    wl.shell_surface_add_listener(shell_surface_, &WaylandWindow::shell_surface_listener_, this);
    wl.shell_surface_set_title(shell_surface_, title.c_str());
    wl.shell_surface_set_toplevel(shell_surface_);

    return true;
}

bool WaylandWindow::Destroy()
{
    if (surface_)
    {
        auto& wl = wayland_application_->GetWaylandFunctionTable();
        if (shell_surface_)
        {
            wl.shell_surface_destroy(shell_surface_);
            shell_surface_ = nullptr;
        }

        wl.surface_destroy(surface_);
        wayland_application_->UnregisterWaylandWindow(this);
        surface_ = nullptr;
        return true;
    }

    return false;
}

void WaylandWindow::SetTitle(const std::string& title)
{
    auto& wl = wayland_application_->GetWaylandFunctionTable();
    wl.shell_surface_set_title(shell_surface_, title.c_str());
}

void WaylandWindow::SetPosition(const int32_t x, const int32_t y)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    // TODO: May be possible with xdg-shell extension.
}

void WaylandWindow::SetSize(const uint32_t width, const uint32_t height)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    // The shell surface should be automatically configured to match the VkSurface dimensions.
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
            *handle = reinterpret_cast<void*>(wayland_application_->GetDisplay());
            return true;
        case Window::kWaylandSurface:
            *handle = reinterpret_cast<void*>(surface_);
            return true;
        default:
            return false;
    }
}

VkResult WaylandWindow::CreateSurface(const encode::InstanceTable* table,
                                      VkInstance                   instance,
                                      VkFlags                      flags,
                                      VkSurfaceKHR*                pSurface)
{
    VkWaylandSurfaceCreateInfoKHR create_info{
        VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR, nullptr, flags, wayland_application_->GetDisplay(), surface_
    };

    return table->CreateWaylandSurfaceKHR(instance, &create_info, nullptr, pSurface);
}

void WaylandWindow::HandlePing(void* data, wl_shell_surface* shell_surface, uint32_t serial)
{
    auto& wl = reinterpret_cast<WaylandWindow*>(data)->wayland_application_->GetWaylandFunctionTable();
    wl.shell_surface_pong(shell_surface, serial);
}

void WaylandWindow::HandleConfigure(
    void* data, wl_shell_surface* shell_surface, uint32_t edges, int32_t width, int32_t height)
{}

void WaylandWindow::HandlePopupDone(void* data, wl_shell_surface* shell_surface) {}

WaylandWindowFactory::WaylandWindowFactory(WaylandApplication* application) : wayland_application_(application)
{
    assert(application != nullptr);
}

decode::Window*
WaylandWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    auto window = new WaylandWindow(wayland_application_);
    window->Create(wayland_application_->GetName(), x, y, width, height);
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

VkBool32 WaylandWindowFactory::GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                                    VkPhysicalDevice             physical_device,
                                                                    uint32_t                     queue_family_index)
{
    assert(wayland_application_->GetDisplay() != nullptr);
    return table->GetPhysicalDeviceWaylandPresentationSupportKHR(
        physical_device, queue_family_index, wayland_application_->GetDisplay());
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
