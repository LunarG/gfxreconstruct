/*
** Copyright (c) 2020 Valve Corporation
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

#ifndef GFXRECON_UTIL_KEYBOARD_H
#define GFXRECON_UTIL_KEYBOARD_H

#include "util/defines.h"

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include "util/xcb_keysyms_loader.h"
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
#include "X11/Xlib.h"
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include "util/wayland_loader.h"
#endif

#include <array>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class Keyboard
{
  public:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    bool Initialize(xcb_connection_t* connection);
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    bool Initialize(Display* display);
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    bool Initialize(struct wl_display* display);
#endif
    void Shutdown();

    bool GetKeyState(const std::string& key);

    Keyboard()
    {
#if defined(VK_USE_PLATFORM_XCB_KHR)
        xcb_connection_ = nullptr;
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        wayland_loader_                   = util::WaylandLoader{};
        wayland_display_                  = nullptr;
        wayland_wrapped_display_          = nullptr;
        wayland_registry_                 = nullptr;
        wayland_event_queue_              = nullptr;
        wayland_seat_                     = nullptr;
        wayland_keyboard_                 = nullptr;
        wayland_current_keyboard_surface_ = nullptr;
        wayland_keyboard_state_           = {};
#endif
    }

  private:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    xcb_connection_t* xcb_connection_;
    XcbKeysymsLoader  xcb_keysyms_loader_;
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    const util::WaylandLoader::FunctionTable& GetWaylandFunctionTable() const;

    static void
    HandleRegistryGlobal(void* data, wl_registry* registry, uint32_t id, const char* interface, uint32_t version);

    static void HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name);

    static void HandleSeatCapabilities(void* data, wl_seat* seat, uint32_t caps);

    static void HandleKeyboardKeymap(void* data, struct wl_keyboard* keyboard, uint32_t format, int fd, uint32_t size);

    static void HandleKeyboardEnter(
        void* data, struct wl_keyboard* keyboard, uint32_t serial, struct wl_surface* surface, struct wl_array* keys);

    static void
    HandleKeyboardLeave(void* data, struct wl_keyboard* keyboard, uint32_t serial, struct wl_surface* surface);

    static void HandleKeyboardKey(
        void* data, struct wl_keyboard* keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state);

    static void HandleKeyboardModifiers(void*        data,
                                        wl_keyboard* keyboard,
                                        uint32_t     serial,
                                        uint32_t     mods_depressed,
                                        uint32_t     mods_latched,
                                        uint32_t     mods_locked,
                                        uint32_t     group);

    util::WaylandLoader                wayland_loader_{};
    struct wl_display*                 wayland_display_{};
    struct wl_display*                 wayland_wrapped_display_{};
    struct wl_registry*                wayland_registry_{};
    struct wl_event_queue*             wayland_event_queue_;
    struct wl_seat*                    wayland_seat_{};
    struct wl_keyboard*                wayland_keyboard_{};
    struct wl_surface*                 wayland_current_keyboard_surface_{};
    static struct wl_keyboard_listener wayland_keyboard_listener_;
    static struct wl_seat_listener     wayland_seat_listener_;
    static struct wl_registry_listener wayland_registry_listener_;

    static constexpr uint32_t                       WAYLAND_KEYBOARD_STATE_LENGTH = 15;
    std::array<bool, WAYLAND_KEYBOARD_STATE_LENGTH> wayland_keyboard_state_;

#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_KEYBOARD_H
