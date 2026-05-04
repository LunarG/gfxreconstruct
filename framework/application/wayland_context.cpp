/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#include "application/wayland_context.h"
#include "application/application.h"
#include "application/wayland_window.h"
#include "util/logging.h"

#include <cstring>
#include <linux/input.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

struct wl_pointer_listener  WaylandContext::pointer_listener_;
struct wl_keyboard_listener WaylandContext::keyboard_listener_;
struct wl_seat_listener     WaylandContext::seat_listener_;
struct wl_registry_listener WaylandContext::registry_listener_;
struct wl_output_listener   WaylandContext::output_listener_;
struct xdg_wm_base_listener WaylandContext::xdg_wm_base_listener_;

WaylandContext::WaylandContext(Application* application) : WsiContext(application)
{
    bool success = true;

    // Populate callback structs.
    registry_listener_.global        = HandleRegistryGlobal;
    registry_listener_.global_remove = HandleRegistryGlobalRemove;

    seat_listener_.capabilities = HandleSeatCapabilities;

    keyboard_listener_.keymap    = HandleKeyboardKeymap;
    keyboard_listener_.enter     = HandleKeyboardEnter;
    keyboard_listener_.leave     = HandleKeyboardLeave;
    keyboard_listener_.key       = HandleKeyboardKey;
    keyboard_listener_.modifiers = HandleKeyboardModifiers;

    pointer_listener_.enter  = HandlePointerEnter;
    pointer_listener_.leave  = HandlePointerLeave;
    pointer_listener_.motion = HandlePointerMotion;
    pointer_listener_.button = HandlePointerButton;
    pointer_listener_.axis   = HandlePointerAxis;

    output_listener_.geometry = HandleOutputGeometry;
    output_listener_.mode     = HandleOutputMode;
    output_listener_.done     = HandleOutputDone;
    output_listener_.scale    = HandleOutputScale;

    xdg_wm_base_listener_.ping = HandleXdgWmBasePing;

    success  = wayland_loader_.Initialize();
    auto& wl = wayland_loader_.GetFunctionTable();

    // Initialize wayland application
    if (success)
    {
        display_ = wl.display_connect(nullptr);
        if (display_ == nullptr)
        {
            GFXRECON_LOG_DEBUG("Failed to connect to a Wayland display server");
            success = false;
        }
    }

    if (success)
    {
        registry_ = wl.display_get_registry(display_);
        if (registry_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to get Wayland registry");
            success = false;
        }
    }

    if (success)
    {
        wl.registry_add_listener(registry_, &WaylandContext::registry_listener_, this);
        wl.display_roundtrip(display_);

        if (compositor_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland compositor");
            success = false;
        }
        else if (shell_ == nullptr && xdg_wm_base_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland shell");
            success = false;
        }
    }

    if (success)
    {
        window_factory_ = std::make_unique<WaylandWindowFactory>(this);
    }
}

WaylandContext::~WaylandContext()
{
    auto& wl = wayland_loader_.GetFunctionTable();
    if (keyboard_)
    {
        wl.keyboard_destroy(keyboard_);
    }

    if (pointer_)
    {
        wl.pointer_destroy(pointer_);
    }

    if (seat_)
    {
        wl.seat_destroy(seat_);
    }

    if (shell_)
    {
        wl.shell_destroy(shell_);
    }

    if (xdg_wm_base_)
    {
        wl.xdg->xdg_wm_base_destroy(xdg_wm_base_);
    }

    if (compositor_)
    {
        wl.compositor_destroy(compositor_);
    }

    if (registry_)
    {
        wl.registry_destroy(registry_);
    }

    if (display_)
    {
        wl.display_disconnect(display_);
    }
}

bool WaylandContext::RegisterWaylandWindow(WaylandWindow* window)
{
    bool success = WsiContext::RegisterWindow(window);

    if (success)
    {
        struct wl_surface* surface = window->GetSurface();

        if (surface != nullptr)
        {
            wayland_windows_.insert(std::make_pair(surface, window));
        }
    }

    return success;
}

bool WaylandContext::UnregisterWaylandWindow(WaylandWindow* window)
{
    bool success = WsiContext::UnregisterWindow(window);

    if (success)
    {
        wayland_windows_.erase(window->GetSurface());
    }

    return success;
}

void WaylandContext::ProcessEvents(bool wait_for_input)
{
    auto& wl = wayland_loader_.GetFunctionTable();
    if (!wait_for_input)
    {
        wl.display_dispatch_pending(display_);
        wl.display_flush(display_);
    }
    else
    {
        wl.display_dispatch(display_);
    }
}

void WaylandContext::HandleRegistryGlobal(
    void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version)
{
    auto  wayland_context = reinterpret_cast<WaylandContext*>(data);
    auto& wl              = wayland_context->GetWaylandFunctionTable();
    if (util::platform::StringCompare(interface, wl.compositor_interface->name) == 0)
    {
        // wl_compositor needs to support wl_surface::set_buffer_scale request
        wayland_context->compositor_ = reinterpret_cast<wl_compositor*>(
            wl.registry_bind(registry, id, wl.compositor_interface, WL_SURFACE_SET_BUFFER_SCALE_SINCE_VERSION));
    }
    else if (util::platform::StringCompare(interface, wl.shell_interface->name) == 0)
    {
        wayland_context->shell_ = reinterpret_cast<wl_shell*>(wl.registry_bind(registry, id, wl.shell_interface, 1));
    }
    else if (util::platform::StringCompare(interface, wl.xdg->xdg_wm_base_interface.name) == 0)
    {
        wayland_context->xdg_wm_base_ =
            reinterpret_cast<xdg_wm_base*>(wl.registry_bind(registry, id, &wl.xdg->xdg_wm_base_interface, 1));
        wl.xdg->xdg_wm_base_add_listener(wayland_context->xdg_wm_base_, &xdg_wm_base_listener_, wayland_context);
    }
    else if (util::platform::StringCompare(interface, wl.seat_interface->name) == 0)
    {
        wayland_context->seat_ = reinterpret_cast<wl_seat*>(wl.registry_bind(registry, id, wl.seat_interface, 1));
        wl.seat_add_listener(wayland_context->seat_, &seat_listener_, wayland_context);
    }
    else if (util::platform::StringCompare(interface, wl.output_interface->name) == 0)
    {
        // wl_output needs to support wl_output::scale event
        auto output = reinterpret_cast<wl_output*>(
            wl.registry_bind(registry, id, wl.output_interface, WL_OUTPUT_SCALE_SINCE_VERSION));
        wl.output_add_listener(output, &output_listener_, wayland_context);
    }
}

void WaylandContext::HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name) {}

void WaylandContext::HandleSeatCapabilities(void* data, wl_seat* seat, uint32_t caps)
{
    // Subscribe to pointer events.
    auto  wayland_context = reinterpret_cast<WaylandContext*>(data);
    auto& wl              = wayland_context->GetWaylandFunctionTable();
    if ((caps & WL_SEAT_CAPABILITY_POINTER) && (wayland_context->pointer_ == nullptr))
    {
        wayland_context->pointer_ = wl.seat_get_pointer(seat);
        wl.pointer_add_listener(wayland_context->pointer_, &pointer_listener_, wayland_context);
    }
    else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && (wayland_context->pointer_ != nullptr))
    {
        wl.pointer_destroy(wayland_context->pointer_);
        wayland_context->pointer_ = nullptr;
    }

    // Subscribe to keyboard events.
    if (caps & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        wayland_context->keyboard_ = wl.seat_get_keyboard(seat);
        wl.keyboard_add_listener(wayland_context->keyboard_, &keyboard_listener_, wayland_context);
    }
    else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD))
    {
        wl.keyboard_destroy(wayland_context->keyboard_);
        wayland_context->keyboard_ = nullptr;
    }
}

void WaylandContext::HandleKeyboardKeymap(
    void* data, struct wl_keyboard* keyboard, uint32_t format, int fd, uint32_t size)
{}

void WaylandContext::HandleKeyboardEnter(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, struct wl_surface* surface, struct wl_array* keys)
{
    auto wayland_context                       = reinterpret_cast<WaylandContext*>(data);
    wayland_context->current_keyboard_surface_ = surface;
}

void WaylandContext::HandleKeyboardLeave(void*               data,
                                         struct wl_keyboard* keyboard,
                                         uint32_t            serial,
                                         struct wl_surface*  surface)
{}

void WaylandContext::HandleKeyboardKey(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state)
{
    if (state == WL_KEYBOARD_KEY_STATE_RELEASED)
    {
        auto wayland_context = reinterpret_cast<WaylandContext*>(data);
        auto application     = wayland_context ? wayland_context->GetApplication() : nullptr;
        assert(application);
        if (application)
        {
            switch (key)
            {
                case KEY_ESC:
                    application->StopRunning();
                    break;
                case KEY_SPACE:
                case KEY_P:
                    application->SetPaused(!application->GetPaused());
                    break;
                default:
                    break;
            }
        }
    }
    else if (state == WL_KEYBOARD_KEY_STATE_PRESSED)
    {
        auto wayland_context = reinterpret_cast<WaylandContext*>(data);
        auto application     = wayland_context ? wayland_context->GetApplication() : nullptr;
        assert(application);
        if (application)
        {
            switch (key)
            {
                case KEY_RIGHT:
                case KEY_N:
                    if (application->GetPaused())
                    {
                        application->PlaySingleFrame();
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void WaylandContext::HandleKeyboardModifiers(void*        data,
                                             wl_keyboard* keyboard,
                                             uint32_t     serial,
                                             uint32_t     mods_depressed,
                                             uint32_t     mods_latched,
                                             uint32_t     mods_locked,
                                             uint32_t     group)
{}

void WaylandContext::HandlePointerEnter(
    void* data, struct wl_pointer* pointer, uint32_t serial, struct wl_surface* surface, wl_fixed_t sx, wl_fixed_t sy)
{
    auto wayland_context                      = reinterpret_cast<WaylandContext*>(data);
    wayland_context->current_pointer_surface_ = surface;
}

void WaylandContext::HandlePointerLeave(void*              data,
                                        struct wl_pointer* pointer,
                                        uint32_t           serial,
                                        struct wl_surface* surface)
{}

void WaylandContext::HandlePointerMotion(
    void* data, struct wl_pointer* pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy)
{}

void WaylandContext::HandlePointerButton(
    void* data, struct wl_pointer* wl_pointer, uint32_t serial, uint32_t time, uint32_t button, uint32_t state)
{
    auto  wayland_context = reinterpret_cast<WaylandContext*>(data);
    auto& wl              = wayland_context->GetWaylandFunctionTable();
    auto  entry           = wayland_context->wayland_windows_.find(wayland_context->current_keyboard_surface_);

    if (entry != wayland_context->wayland_windows_.end())
    {
        if ((button == BTN_LEFT) && (state == WL_POINTER_BUTTON_STATE_PRESSED))
        {
            WaylandWindow* window = entry->second;
            if (window->GetXdgToplevel() != nullptr)
            {
                wl.xdg->xdg_toplevel_move(window->GetXdgToplevel(), wayland_context->seat_, serial);
            }
            else if (window->GetShellSurface() != nullptr)
            {
                wl.shell_surface_move(window->GetShellSurface(), wayland_context->seat_, serial);
            }
        }
    }
}

void WaylandContext::HandlePointerAxis(
    void* data, struct wl_pointer* wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value)
{}

void WaylandContext::HandleOutputGeometry(void*             data,
                                          struct wl_output* wl_output,
                                          int32_t           x,
                                          int32_t           y,
                                          int32_t           physical_width,
                                          int32_t           physical_height,
                                          int32_t           subpixel,
                                          const char*       make,
                                          const char*       model,
                                          int32_t           transform)
{}

void WaylandContext::HandleOutputMode(
    void* data, struct wl_output* wl_output, uint32_t flags, int32_t width, int32_t height, int32_t refresh)
{
    auto wayland_context = reinterpret_cast<WaylandContext*>(data);
    if ((flags & WL_OUTPUT_MODE_CURRENT) == WL_OUTPUT_MODE_CURRENT)
    {
        auto& output_info  = wayland_context->output_info_map_[wl_output];
        output_info.width  = width;
        output_info.height = height;
    }
}

void WaylandContext::HandleOutputDone(void* data, struct wl_output* wl_output) {}

void WaylandContext::HandleOutputScale(void* data, struct wl_output* wl_output, int32_t factor)
{
    auto  wayland_context = reinterpret_cast<WaylandContext*>(data);
    auto& output_info     = wayland_context->output_info_map_[wl_output];
    output_info.scale     = factor;
}

void WaylandContext::HandleXdgWmBasePing(void* data, struct xdg_wm_base* xdg_wm_base, uint32_t serial)
{
    auto& wl = reinterpret_cast<WaylandContext*>(data)->GetWaylandFunctionTable();
    wl.xdg->xdg_wm_base_pong(xdg_wm_base, serial);
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
