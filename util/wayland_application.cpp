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
#include <cstring>
#include <linux/input.h>

#include "util/wayland_application.h"
#include "util/wayland_window.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

WaylandApplication::WaylandApplication()
{
    // Populate callback structs
    pointer_listener.enter = pointer_handle_enter;
    pointer_listener.leave = pointer_handle_leave;
    pointer_listener.motion = pointer_handle_motion;
    pointer_listener.button = pointer_handle_button;
    pointer_listener.axis = pointer_handle_axis;

    keyboard_listener.keymap = keyboard_handle_keymap;
    keyboard_listener.enter = keyboard_handle_enter;
    keyboard_listener.leave = keyboard_handle_leave;
    keyboard_listener.key = keyboard_handle_key;
    keyboard_listener.modifiers = keyboard_handle_modifiers;

    seat_listener.capabilities = seat_handle_capabilities;

    registry_listener.global = registry_handle_global;
    registry_listener.global_remove = registry_handle_global_remove;

    // Initialize wayland application
    try
    {
        display = wl_display_connect(nullptr);
        if (!display) throw std::runtime_error("Wayland failed to connect to the display server");

        registry_ = wl_display_get_registry(display);
        if (!registry_) throw std::runtime_error("Wayland failed to get registry");

        wl_registry_add_listener(registry_, &WaylandApplication::registry_listener, this);
        wl_display_roundtrip(display);

        if (!compositor) throw std::runtime_error("Wayland failed to bind compositor");

        if (!shell) throw std::runtime_error("Wayland failed to bind shell");
    } catch (const std::runtime_error &ex)
    {
        if (shell) wl_shell_destroy(shell);
        if (compositor) wl_compositor_destroy(compositor);
        if (registry_) wl_registry_destroy(registry_);
        if (display) wl_display_disconnect(display);

        // log(ex.what())
        throw;
    }
}

WaylandApplication::~WaylandApplication()
{
    if (keyboard_) wl_keyboard_destroy(keyboard_);
    if (pointer_) wl_pointer_destroy(pointer_);
    if (seat_) wl_seat_destroy(seat_);
    if (shell) wl_shell_destroy(shell);
    if (compositor) wl_compositor_destroy(compositor);
    if (registry_) wl_registry_destroy(registry_);
    if (display) wl_display_disconnect(display);
}

void WaylandApplication::ProcessEvents(bool wait_for_input)
{
    // Interaction is handled in the callbacks
    wl_display_dispatch_pending(display);
}

struct wl_registry_listener WaylandApplication::registry_listener;

void WaylandApplication::registry_handle_global(void *data, wl_registry *registry, uint32_t id, const char *interface,
                                              uint32_t version)
{
    // pickup wayland objects when they appear
    auto app = (WaylandApplication *)data;
    if (strcmp(interface, "wl_compositor") == 0) {
        app->compositor = (wl_compositor *)wl_registry_bind(registry, id, &wl_compositor_interface, 1);
    } else if (strcmp(interface, "wl_shell") == 0) {
        app->shell = (wl_shell *)wl_registry_bind(registry, id, &wl_shell_interface, 1);
    } else if (strcmp(interface, "wl_seat") == 0) {
        app->seat_ = (wl_seat *)wl_registry_bind(registry, id, &wl_seat_interface, 1);
        wl_seat_add_listener(app->seat_, &seat_listener, app);
    }
}

void WaylandApplication::registry_handle_global_remove(void *data, wl_registry *registry, uint32_t name) {}

struct wl_seat_listener WaylandApplication::seat_listener;

void WaylandApplication::seat_handle_capabilities(void *data, wl_seat *seat, uint32_t caps)
{
    // Subscribe to pointer events
    auto app = (WaylandApplication *)data;
    if ((caps & WL_SEAT_CAPABILITY_POINTER) && !app->pointer_) {
        app->pointer_ = wl_seat_get_pointer(seat);
        wl_pointer_add_listener(app->pointer_, &pointer_listener, app);
    } else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && app->pointer_) {
        wl_pointer_destroy(app->pointer_);
        app->pointer_ = NULL;
    }
    // Subscribe to keyboard events
    if (caps & WL_SEAT_CAPABILITY_KEYBOARD) {
        app->keyboard_ = wl_seat_get_keyboard(seat);
        wl_keyboard_add_listener(app->keyboard_, &keyboard_listener, app);
    } else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD)) {
        wl_keyboard_destroy(app->keyboard_);
        app->keyboard_ = NULL;
    }
}

struct wl_keyboard_listener WaylandApplication::keyboard_listener;

void WaylandApplication::keyboard_handle_keymap(void *data, struct wl_keyboard *keyboard, uint32_t format, int fd, uint32_t size) {}

void WaylandApplication::keyboard_handle_enter(void *data, struct wl_keyboard *keyboard, uint32_t serial, struct wl_surface *surface,
                                             struct wl_array *keys)
{
    auto app = (WaylandApplication *)data;
    app->current_keyboard_surface_ = surface;
}

void WaylandApplication::keyboard_handle_leave(void *data, struct wl_keyboard *keyboard, uint32_t serial,
                                             struct wl_surface *surface) {}

void WaylandApplication::keyboard_handle_key(void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t time, uint32_t key,
                                           uint32_t state)
{
    if (state != WL_KEYBOARD_KEY_STATE_RELEASED) return;
    auto app = (WaylandApplication *)data;
    WaylandWindow* window = nullptr;
    for (auto window : app->windows)
    {
        auto wl_wind = (WaylandWindow*)window;
        if (wl_wind->surface == app->current_keyboard_surface_)
        {
            window = wl_wind;
            break;
        }
    }
    if (window)
    {
        switch (key)
        {
            case KEY_ESC:
                window->Destroy();
                break;
            case KEY_SPACE:
                app->SetPaused(!app->GetPaused());
                break;
        }
    }
}

void WaylandApplication::keyboard_handle_modifiers(void *data, wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed,
                                                 uint32_t mods_latched, uint32_t mods_locked, uint32_t group) {}

struct wl_pointer_listener WaylandApplication::pointer_listener;

void WaylandApplication::pointer_handle_enter(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface,
                                            wl_fixed_t sx, wl_fixed_t sy)
{
    auto app = (WaylandApplication *)data;
    app->current_pointer_surface_ = surface;
}

void WaylandApplication::pointer_handle_leave(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface) {}

void WaylandApplication::pointer_handle_motion(void *data, struct wl_pointer *pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy) {}

void WaylandApplication::pointer_handle_button(void *data, struct wl_pointer *wl_pointer, uint32_t serial, uint32_t time,
                                             uint32_t button, uint32_t state)
{
    auto app = (WaylandApplication *)data;
    WaylandWindow* window = nullptr;
    for (auto window : app->windows)
    {
        auto wl_wind = (WaylandWindow*)window;
        if (wl_wind->surface == app->current_pointer_surface_)
        {
            window = wl_wind;
            break;
        }
    }
    if (window)
    {
        if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED)
        {
            wl_shell_surface_move(window->shell_surface, app->seat_, serial);
        }
    }
}

void WaylandApplication::pointer_handle_axis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis,
                                           wl_fixed_t value) {}


BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
