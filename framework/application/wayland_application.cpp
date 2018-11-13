/*
** Copyright (c) 2018 Valve Corporation
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

#include "application/wayland_application.h"

#include "application/wayland_window.h"
#include "util/logging.h"

#include <cstring>
#include <linux/input.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

struct wl_pointer_listener  WaylandApplication::pointer_listener_;
struct wl_keyboard_listener WaylandApplication::keyboard_listener_;
struct wl_seat_listener     WaylandApplication::seat_listener_;
struct wl_registry_listener WaylandApplication::registry_listener_;

WaylandApplication::WaylandApplication(const std::string& name) :
    Application(name), display_(nullptr), shell_(nullptr), compositor_(nullptr), registry_(nullptr), seat_(nullptr),
    pointer_(nullptr), keyboard_(nullptr), current_keyboard_surface_(nullptr), current_pointer_surface_(nullptr)
{}

WaylandApplication::~WaylandApplication()
{
    if (keyboard_)
    {
        wl_keyboard_destroy(keyboard_);
    }

    if (pointer_)
    {
        wl_pointer_destroy(pointer_);
    }

    if (seat_)
    {
        wl_seat_destroy(seat_);
    }

    if (shell_)
    {
        wl_shell_destroy(shell_);
    }

    if (compositor_)
    {
        wl_compositor_destroy(compositor_);
    }

    if (registry_)
    {
        wl_registry_destroy(registry_);
    }

    if (display_)
    {
        wl_display_disconnect(display_);
    }
}

bool WaylandApplication::Initialize(decode::FileProcessor* file_processor)
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

    // Initialize wayland application
    display_ = wl_display_connect(nullptr);
    if (display_ == nullptr)
    {
        GFXRECON_LOG_ERROR("Failed to connect to the Wayland display server");
        success = false;
    }

    if (success)
    {
        registry_ = wl_display_get_registry(display_);
        if (registry_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to get Wayland registry");
            success = false;
        }
    }

    if (success)
    {
        wl_registry_add_listener(registry_, &WaylandApplication::registry_listener_, this);
        wl_display_roundtrip(display_);

        if (compositor_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland compositor");
            success = false;
        }
        else if (shell_ == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to bind Wayland shell");
            success = false;
        }
    }

    SetFileProcessor(file_processor);

    return success;
}

bool WaylandApplication::RegisterWaylandWindow(WaylandWindow* window)
{
    bool success = Application::RegisterWindow(window);

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

bool WaylandApplication::UnregisterWaylandWindow(WaylandWindow* window)
{
    bool success = Application::UnregisterWindow(window);

    if (success)
    {
        wayland_windows_.erase(window->GetSurface());
    }

    return success;
}

void WaylandApplication::ProcessEvents(bool wait_for_input)
{
    wl_display_dispatch_pending(display_);
}

void WaylandApplication::HandleRegistryGlobal(
    void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version)
{
    auto app = (WaylandApplication*)data;
    if (strcmp(interface, "wl_compositor") == 0)
    {
        app->compositor_ =
            reinterpret_cast<wl_compositor*>(wl_registry_bind(registry, id, &wl_compositor_interface, 1));
    }
    else if (strcmp(interface, "wl_shell") == 0)
    {
        app->shell_ = reinterpret_cast<wl_shell*>(wl_registry_bind(registry, id, &wl_shell_interface, 1));
    }
    else if (strcmp(interface, "wl_seat") == 0)
    {
        app->seat_ = reinterpret_cast<wl_seat*>(wl_registry_bind(registry, id, &wl_seat_interface, 1));
        wl_seat_add_listener(app->seat_, &seat_listener_, app);
    }
}

void WaylandApplication::HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name) {}

void WaylandApplication::HandleSeatCapabilities(void* data, wl_seat* seat, uint32_t caps)
{
    // Subscribe to pointer events.
    auto app = reinterpret_cast<WaylandApplication*>(data);
    if ((caps & WL_SEAT_CAPABILITY_POINTER) && (app->pointer_ == nullptr))
    {
        app->pointer_ = wl_seat_get_pointer(seat);
        wl_pointer_add_listener(app->pointer_, &pointer_listener_, app);
    }
    else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && (app->pointer_ != nullptr))
    {
        wl_pointer_destroy(app->pointer_);
        app->pointer_ = nullptr;
    }

    // Subscribe to keyboard events.
    if (caps & WL_SEAT_CAPABILITY_KEYBOARD)
    {
        app->keyboard_ = wl_seat_get_keyboard(seat);
        wl_keyboard_add_listener(app->keyboard_, &keyboard_listener_, app);
    }
    else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD))
    {
        wl_keyboard_destroy(app->keyboard_);
        app->keyboard_ = nullptr;
    }
}

void WaylandApplication::HandleKeyboardKeymap(
    void* data, struct wl_keyboard* keyboard, uint32_t format, int fd, uint32_t size)
{}

void WaylandApplication::HandleKeyboardEnter(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, struct wl_surface* surface, struct wl_array* keys)
{
    auto app                       = reinterpret_cast<WaylandApplication*>(data);
    app->current_keyboard_surface_ = surface;
}

void WaylandApplication::HandleKeyboardLeave(void*               data,
                                             struct wl_keyboard* keyboard,
                                             uint32_t            serial,
                                             struct wl_surface*  surface)
{}

void WaylandApplication::HandleKeyboardKey(
    void* data, struct wl_keyboard* keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state)
{
    if (state == WL_KEYBOARD_KEY_STATE_RELEASED)
    {
        auto app = reinterpret_cast<WaylandApplication*>(data);

        switch (key)
        {
            case KEY_ESC:
                app->StopRunning();
                break;
            case KEY_SPACE:
                app->SetPaused(!app->GetPaused());
                break;
        }
    }
}

void WaylandApplication::HandleKeyboardModifiers(void*        data,
                                                 wl_keyboard* keyboard,
                                                 uint32_t     serial,
                                                 uint32_t     mods_depressed,
                                                 uint32_t     mods_latched,
                                                 uint32_t     mods_locked,
                                                 uint32_t     group)
{}

void WaylandApplication::HandlePointerEnter(
    void* data, struct wl_pointer* pointer, uint32_t serial, struct wl_surface* surface, wl_fixed_t sx, wl_fixed_t sy)
{
    auto app                      = reinterpret_cast<WaylandApplication*>(data);
    app->current_pointer_surface_ = surface;
}

void WaylandApplication::HandlePointerLeave(void*              data,
                                            struct wl_pointer* pointer,
                                            uint32_t           serial,
                                            struct wl_surface* surface)
{}

void WaylandApplication::HandlePointerMotion(
    void* data, struct wl_pointer* pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy)
{}

void WaylandApplication::HandlePointerButton(
    void* data, struct wl_pointer* wl_pointer, uint32_t serial, uint32_t time, uint32_t button, uint32_t state)
{
    auto app   = reinterpret_cast<WaylandApplication*>(data);
    auto entry = app->wayland_windows_.find(app->current_keyboard_surface_);

    if (entry != app->wayland_windows_.end())
    {
        WaylandWindow* window = entry->second;
        if ((button == BTN_LEFT) && (state == WL_POINTER_BUTTON_STATE_PRESSED))
        {
            wl_shell_surface_move(window->GetShellSurface(), app->seat_, serial);
        }
    }
}

void WaylandApplication::HandlePointerAxis(
    void* data, struct wl_pointer* wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value)
{}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
