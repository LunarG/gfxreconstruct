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

#ifndef BRIMSTONE_UTIL_WAYLAND_WINDOW_H
#define BRIMSTONE_UTIL_WAYLAND_WINDOW_H

#include <wayland-client.h>

#include "util/window.h"
#include "util/wayland_application.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

class WaylandWindow : public Window
{
public:
    enum HandleId : uint32_t
    {
        kDisplay = 0,
        kSurface = 1
    };

public:
    WaylandWindow(WaylandApplication* application);

    bool Create(const uint32_t width, const uint32_t height) override;

    bool Destroy() override;

    void SetPosition(const uint32_t x, const uint32_t y) override;

    void SetSize(const uint32_t width, const uint32_t height) override;

    void SetVisibility(bool show) override;

    void SetFocus() override;

    bool GetNativeHandle(uint32_t id, void ** handle) override;

public:
    struct wl_surface*          surface;
    struct wl_shell_surface*    shell_surface;

private:
    WaylandApplication*             wayland_application_;
    uint32_t                    width_;
    uint32_t                    height_;

    static struct wl_shell_surface_listener shell_surface_listener;

    static void handle_ping(void *data, wl_shell_surface *shell_surface, uint32_t serial);
    static void handle_configure(void *data, wl_shell_surface *shell_surface, uint32_t edges, int32_t width, int32_t height);
    static void handle_popup_done(void *data, wl_shell_surface *shell_surface);
};

class WaylandWindowFactory : public WindowFactory
{
public:
    WaylandWindowFactory(WaylandApplication* application);

    Window* Create(const uint32_t width, const uint32_t height) override;

private:
    WaylandApplication*            wayland_application_;
};

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_WAYLAND_WINDOW_H