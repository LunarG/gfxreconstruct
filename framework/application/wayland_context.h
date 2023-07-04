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

#ifndef GFXRECON_APPLICATION_WAYLAND_CONTEXT_H
#define GFXRECON_APPLICATION_WAYLAND_CONTEXT_H

#include "application/application.h"
#include "util/defines.h"
#include "util/wayland_loader.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class Application;
class WaylandWindow;

class WaylandContext : public WsiContext
{
  public:
    struct OutputInfo
    {
        int32_t scale;
        int32_t width;
        int32_t height;
    };

    WaylandContext(Application* application);

    virtual ~WaylandContext() override;

    const util::WaylandLoader::FunctionTable& GetWaylandFunctionTable() const
    {
        return wayland_loader_.GetFunctionTable();
    }

    struct wl_display* GetDisplay() const { return display_; }

    struct wl_shell* GetShell() const { return shell_; }

    struct xdg_wm_base* GetXdgWmBase() const { return xdg_wm_base_; }

    struct wl_compositor* GetCompositor() const { return compositor_; }

    const OutputInfo& GetOutputInfo(const struct wl_output* wl_output) { return output_info_map_[wl_output]; }

    bool RegisterWaylandWindow(WaylandWindow* window);

    bool UnregisterWaylandWindow(WaylandWindow* window);

    virtual void ProcessEvents(bool wait_for_input) override;

  private:
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

    static void HandlePointerEnter(void*              data,
                                   struct wl_pointer* pointer,
                                   uint32_t           serial,
                                   struct wl_surface* surface,
                                   wl_fixed_t         sx,
                                   wl_fixed_t         sy);

    static void HandlePointerLeave(void* data, struct wl_pointer* pointer, uint32_t serial, struct wl_surface* surface);

    static void
    HandlePointerMotion(void* data, struct wl_pointer* pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy);

    static void HandlePointerButton(
        void* data, struct wl_pointer* wl_pointer, uint32_t serial, uint32_t time, uint32_t button, uint32_t state);

    static void
    HandlePointerAxis(void* data, struct wl_pointer* wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value);

    static void HandleOutputGeometry(void*             data,
                                     struct wl_output* wl_output,
                                     int32_t           x,
                                     int32_t           y,
                                     int32_t           physical_width,
                                     int32_t           physical_height,
                                     int32_t           subpixel,
                                     const char*       make,
                                     const char*       model,
                                     int32_t           transform);
    static void HandleOutputMode(
        void* data, struct wl_output* wl_output, uint32_t flags, int32_t width, int32_t height, int32_t refresh);
    static void HandleOutputDone(void* data, struct wl_output* wl_output);
    static void HandleOutputScale(void* data, struct wl_output* wl_output, int32_t factor);

    static void HandleXdgWmBasePing(void* data, struct xdg_wm_base* xdg_wm_base, uint32_t serial);

    typedef std::unordered_map<struct wl_surface*, WaylandWindow*>  WaylandWindowMap;
    typedef std::unordered_map<const struct wl_output*, OutputInfo> OutputInfoMap;

    static struct wl_pointer_listener  pointer_listener_;
    static struct wl_keyboard_listener keyboard_listener_;
    static struct wl_seat_listener     seat_listener_;
    static struct wl_registry_listener registry_listener_;
    static struct wl_output_listener   output_listener_;
    static struct xdg_wm_base_listener xdg_wm_base_listener_;
    struct wl_display*                 display_{};
    struct wl_shell*                   shell_{};
    struct xdg_wm_base*                xdg_wm_base_{};
    struct wl_compositor*              compositor_{};
    struct wl_registry*                registry_{};
    struct wl_seat*                    seat_{};
    struct wl_pointer*                 pointer_{};
    struct wl_keyboard*                keyboard_{};
    struct wl_surface*                 current_keyboard_surface_{};
    struct wl_surface*                 current_pointer_surface_{};
    WaylandWindowMap                   wayland_windows_{};
    OutputInfoMap                      output_info_map_{};
    util::WaylandLoader                wayland_loader_{};
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_WAYLAND_CONTEXT_H
