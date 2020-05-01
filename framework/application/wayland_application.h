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

#ifndef GFXRECON_APPLICATION_WAYLAND_APPLICATION_H
#define GFXRECON_APPLICATION_WAYLAND_APPLICATION_H

#include "application/application.h"
#include "util/defines.h"
#include "util/wayland_loader.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class WaylandWindow;

class WaylandApplication : public Application
{
  public:
    struct OutputInfo
    {
        int32_t scale;
        int32_t width;
        int32_t height;
    };

  public:
    WaylandApplication(const std::string& name);

    virtual ~WaylandApplication() override;

    const util::WaylandLoader::FunctionTable& GetWaylandFunctionTable() const { return wayland_loader_.GetFunctionTable(); }

    struct wl_display* GetDisplay() const { return display_; }

    struct wl_shell* GetShell() const { return shell_; }

    struct wl_compositor* GetCompositor() const { return compositor_; }

    const OutputInfo& GetOutputInfo(const struct wl_output* wl_output) { return output_info_map_[wl_output]; }

    virtual bool Initialize(decode::FileProcessor* file_processor) override;

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

  private:
    typedef std::unordered_map<struct wl_surface*, WaylandWindow*> WaylandWindowMap;
    typedef std::unordered_map<const struct wl_output*, OutputInfo> OutputInfoMap;

  private:
    static struct wl_pointer_listener  pointer_listener_;
    static struct wl_keyboard_listener keyboard_listener_;
    static struct wl_seat_listener     seat_listener_;
    static struct wl_registry_listener registry_listener_;
    static struct wl_output_listener   output_listener_;
    struct wl_display*                 display_;
    struct wl_shell*                   shell_;
    struct wl_compositor*              compositor_;
    struct wl_registry*                registry_;
    struct wl_seat*                    seat_;
    struct wl_pointer*                 pointer_;
    struct wl_keyboard*                keyboard_;
    struct wl_surface*                 current_keyboard_surface_;
    struct wl_surface*                 current_pointer_surface_;
    WaylandWindowMap                   wayland_windows_;
    OutputInfoMap                      output_info_map_;
    util::WaylandLoader                wayland_loader_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_WAYLAND_APPLICATION_H