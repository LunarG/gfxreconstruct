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

#include <stdexcept>

#include "application/wayland_window.h"

#include "volk.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(application)

WaylandWindow::WaylandWindow(WaylandApplication* application)
{
    wayland_application_ = application;
    wayland_application_->RegisterWindow(this);

    // Populate callback structs
    shell_surface_listener.ping = handle_ping;
    shell_surface_listener.configure = handle_configure;
    shell_surface_listener.popup_done = handle_popup_done;
}

WaylandWindow::~WaylandWindow()
{
    wayland_application_->UnregisterWindow(this);
}

bool WaylandWindow::Create(const uint32_t width, const uint32_t height)
{
    width_ = width;
    height_ = height;

    surface = wl_compositor_create_surface(wayland_application_->compositor);
    if (!surface) throw std::runtime_error("Failed to create surface");

    shell_surface = wl_shell_get_shell_surface(wayland_application_->shell, surface);
    if (!shell_surface) throw std::runtime_error("Failed to get shell_surface");

    wl_shell_surface_add_listener(shell_surface, &WaylandWindow::shell_surface_listener, this);
    wl_shell_surface_set_title(shell_surface, name.c_str());
    wl_shell_surface_set_toplevel(shell_surface);

    return true;
}

bool WaylandWindow::Destroy()
{
    if (shell_surface) wl_shell_surface_destroy(shell_surface);
    if (surface) wl_surface_destroy(surface);
    return true;
}

void WaylandWindow::SetPosition(const uint32_t x, const uint32_t y)
{
}

void WaylandWindow::SetSize(const uint32_t width, const uint32_t height)
{
    if (width != width_ || height != height_) {
        width_ = width;
        height_ = height;
        // In Wayland, the shell_surface should resize based on the Vulkan surface automagically
    }
}

void WaylandWindow::SetVisibility(bool show)
{
    // TODO
}

void WaylandWindow::SetFocus()
{
    // TODO
}

bool WaylandWindow::GetNativeHandle(uint32_t id, void ** handle)
{
    switch (id) {
        case WaylandWindow::kDisplay:
            *handle = reinterpret_cast<void*>(wayland_application_->display);
            return true;
        case WaylandWindow::kSurface:
            *handle = reinterpret_cast<void*>(surface);
            return true;
        default:
            return false;
    }
}

VkResult WaylandWindow::CreateSurface(VkInstance instance, VkFlags flags, VkSurfaceKHR* pSurface)
{
    VkWaylandSurfaceCreateInfoKHR create_info
    {
        .sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR,
        .pNext = nullptr,
        .flags = flags,
        .display = wayland_application_->display,
        .surface = surface
    };

    return vkCreateWaylandSurfaceKHR(instance, &create_info, nullptr, pSurface);
}

struct wl_shell_surface_listener WaylandWindow::shell_surface_listener;

void WaylandWindow::handle_ping(void *data, wl_shell_surface *shell_surface, uint32_t serial)
{
    wl_shell_surface_pong(shell_surface, serial);
}

void WaylandWindow::handle_configure(void *data, wl_shell_surface *shell_surface, uint32_t edges, int32_t width,
                                        int32_t height) {}

void WaylandWindow::handle_popup_done(void *data, wl_shell_surface *shell_surface) {}

WaylandWindowFactory::WaylandWindowFactory(WaylandApplication* application)
{
    wayland_application_ = application;
}

format::Window* WaylandWindowFactory::Create(const uint32_t width, const uint32_t height)
{
    auto window = new WaylandWindow(wayland_application_);
    window->Create(width, height);
    return window;
}

BRIMSTONE_END_NAMESPACE(application)
BRIMSTONE_END_NAMESPACE(brimstone)
