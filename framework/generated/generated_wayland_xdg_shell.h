/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef GFXRECON_GENERATED_WAYLAND_XDG_SHELL_H
#define GFXRECON_GENERATED_WAYLAND_XDG_SHELL_H

#include <vector>

#include <wayland-client.h>

#include "util/defines.h"
#include "util/wayland_loader.h"

struct GfxrXdgWmBase;
struct GfxrXdgPositioner;
struct GfxrXdgSurface;
struct GfxrXdgToplevel;
struct GfxrXdgPopup;

// xdg_wm_base static declarations

enum GfxrXdgWmBaseError
{
    GFXR_XDG_WM_BASE_ERROR_ROLE = 0,
    GFXR_XDG_WM_BASE_ERROR_DEFUNCT_SURFACES = 1,
    GFXR_XDG_WM_BASE_ERROR_NOT_THE_TOPMOST_POPUP = 2,
    GFXR_XDG_WM_BASE_ERROR_INVALID_POPUP_PARENT = 3,
    GFXR_XDG_WM_BASE_ERROR_INVALID_SURFACE_STATE = 4,
    GFXR_XDG_WM_BASE_ERROR_INVALID_POSITIONER = 5,
    GFXR_XDG_WM_BASE_ERROR_UNRESPONSIVE = 6,
};

struct GfxrXdgWmBaseListener
{
    void (*ping)(void* data, GfxrXdgWmBase* object, uint32_t serial);
};

// xdg_positioner static declarations

enum GfxrXdgPositionerError
{
    GFXR_XDG_POSITIONER_ERROR_INVALID_INPUT = 0,
};

enum GfxrXdgPositionerAnchor
{
    GFXR_XDG_POSITIONER_ANCHOR_NONE = 0,
    GFXR_XDG_POSITIONER_ANCHOR_TOP = 1,
    GFXR_XDG_POSITIONER_ANCHOR_BOTTOM = 2,
    GFXR_XDG_POSITIONER_ANCHOR_LEFT = 3,
    GFXR_XDG_POSITIONER_ANCHOR_RIGHT = 4,
    GFXR_XDG_POSITIONER_ANCHOR_TOP_LEFT = 5,
    GFXR_XDG_POSITIONER_ANCHOR_BOTTOM_LEFT = 6,
    GFXR_XDG_POSITIONER_ANCHOR_TOP_RIGHT = 7,
    GFXR_XDG_POSITIONER_ANCHOR_BOTTOM_RIGHT = 8,
};

enum GfxrXdgPositionerGravity
{
    GFXR_XDG_POSITIONER_GRAVITY_NONE = 0,
    GFXR_XDG_POSITIONER_GRAVITY_TOP = 1,
    GFXR_XDG_POSITIONER_GRAVITY_BOTTOM = 2,
    GFXR_XDG_POSITIONER_GRAVITY_LEFT = 3,
    GFXR_XDG_POSITIONER_GRAVITY_RIGHT = 4,
    GFXR_XDG_POSITIONER_GRAVITY_TOP_LEFT = 5,
    GFXR_XDG_POSITIONER_GRAVITY_BOTTOM_LEFT = 6,
    GFXR_XDG_POSITIONER_GRAVITY_TOP_RIGHT = 7,
    GFXR_XDG_POSITIONER_GRAVITY_BOTTOM_RIGHT = 8,
};

enum GfxrXdgPositionerConstraintAdjustment
{
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_NONE = 0,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_X = 1,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_Y = 2,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_FLIP_X = 4,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_FLIP_Y = 8,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_RESIZE_X = 16,
    GFXR_XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_RESIZE_Y = 32,
};

// xdg_surface static declarations

enum GfxrXdgSurfaceError
{
    GFXR_XDG_SURFACE_ERROR_NOT_CONSTRUCTED = 1,
    GFXR_XDG_SURFACE_ERROR_ALREADY_CONSTRUCTED = 2,
    GFXR_XDG_SURFACE_ERROR_UNCONFIGURED_BUFFER = 3,
    GFXR_XDG_SURFACE_ERROR_INVALID_SERIAL = 4,
    GFXR_XDG_SURFACE_ERROR_INVALID_SIZE = 5,
    GFXR_XDG_SURFACE_ERROR_DEFUNCT_ROLE_OBJECT = 6,
};

struct GfxrXdgSurfaceListener
{
    void (*configure)(void* data, GfxrXdgSurface* object, uint32_t serial);
};

// xdg_toplevel static declarations

enum GfxrXdgToplevelError
{
    GFXR_XDG_TOPLEVEL_ERROR_INVALID_RESIZE_EDGE = 0,
    GFXR_XDG_TOPLEVEL_ERROR_INVALID_PARENT = 1,
    GFXR_XDG_TOPLEVEL_ERROR_INVALID_SIZE = 2,
};

enum GfxrXdgToplevelResizeEdge
{
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_NONE = 0,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_TOP = 1,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM = 2,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_LEFT = 4,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_TOP_LEFT = 5,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_LEFT = 6,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_RIGHT = 8,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_TOP_RIGHT = 9,
    GFXR_XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_RIGHT = 10,
};

enum GfxrXdgToplevelState
{
    GFXR_XDG_TOPLEVEL_STATE_MAXIMIZED = 1,
    GFXR_XDG_TOPLEVEL_STATE_FULLSCREEN = 2,
    GFXR_XDG_TOPLEVEL_STATE_RESIZING = 3,
    GFXR_XDG_TOPLEVEL_STATE_ACTIVATED = 4,
    GFXR_XDG_TOPLEVEL_STATE_TILED_LEFT = 5,
    GFXR_XDG_TOPLEVEL_STATE_TILED_RIGHT = 6,
    GFXR_XDG_TOPLEVEL_STATE_TILED_TOP = 7,
    GFXR_XDG_TOPLEVEL_STATE_TILED_BOTTOM = 8,
    GFXR_XDG_TOPLEVEL_STATE_SUSPENDED = 9,
};

enum GfxrXdgToplevelWmCapabilities
{
    GFXR_XDG_TOPLEVEL_WM_CAPABILITIES_WINDOW_MENU = 1,
    GFXR_XDG_TOPLEVEL_WM_CAPABILITIES_MAXIMIZE = 2,
    GFXR_XDG_TOPLEVEL_WM_CAPABILITIES_FULLSCREEN = 3,
    GFXR_XDG_TOPLEVEL_WM_CAPABILITIES_MINIMIZE = 4,
};

struct GfxrXdgToplevelListener
{
    void (*configure)(void* data, GfxrXdgToplevel* object, int32_t width, int32_t height, wl_array* states);
    void (*close)(void* data, GfxrXdgToplevel* object);
    void (*configure_bounds)(void* data, GfxrXdgToplevel* object, int32_t width, int32_t height);
    void (*wm_capabilities)(void* data, GfxrXdgToplevel* object, wl_array* capabilities);
};

// xdg_popup static declarations

enum GfxrXdgPopupError
{
    GFXR_XDG_POPUP_ERROR_INVALID_GRAB = 0,
};

struct GfxrXdgPopupListener
{
    void (*configure)(void* data, GfxrXdgPopup* object, int32_t x, int32_t y, int32_t width, int32_t height);
    void (*popup_done)(void* data, GfxrXdgPopup* object);
    void (*repositioned)(void* data, GfxrXdgPopup* object, uint32_t token);
};

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Global to xdg_shell

class WaylandXdgShellTable
{
  private:

    const WaylandLoader::FunctionTable* _wl;
    std::vector<wl_message> _messages;
    std::vector<const wl_interface*> _messageArgs;

  public:

    // xdg_wm_base dynamic declarations

    wl_interface xdg_wm_base_interface;

    int xdg_wm_base_add_listener(GfxrXdgWmBase* self, GfxrXdgWmBaseListener* listener, void* data) const
    {
        return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
    }

    void xdg_wm_base_destroy(GfxrXdgWmBase* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
        _wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
    }

    GfxrXdgPositioner* xdg_wm_base_create_positioner(GfxrXdgWmBase* self) const
    {
        return reinterpret_cast<GfxrXdgPositioner*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &xdg_positioner_interface, NULL));
    }

    GfxrXdgSurface* xdg_wm_base_get_xdg_surface(GfxrXdgWmBase* self, wl_surface* surface) const
    {
        return reinterpret_cast<GfxrXdgSurface*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 2, &xdg_surface_interface, NULL, surface));
    }

    void xdg_wm_base_pong(GfxrXdgWmBase* self, uint32_t serial) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, serial);
    }

    // xdg_positioner dynamic declarations

    wl_interface xdg_positioner_interface;

    void xdg_positioner_destroy(GfxrXdgPositioner* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
        _wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
    }

    void xdg_positioner_set_size(GfxrXdgPositioner* self, int32_t width, int32_t height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, width, height);
    }

    void xdg_positioner_set_anchor_rect(GfxrXdgPositioner* self, int32_t x, int32_t y, int32_t width, int32_t height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, x, y, width, height);
    }

    void xdg_positioner_set_anchor(GfxrXdgPositioner* self, uint32_t anchor) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, anchor);
    }

    void xdg_positioner_set_gravity(GfxrXdgPositioner* self, uint32_t gravity) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, gravity);
    }

    void xdg_positioner_set_constraint_adjustment(GfxrXdgPositioner* self, uint32_t constraint_adjustment) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 5, constraint_adjustment);
    }

    void xdg_positioner_set_offset(GfxrXdgPositioner* self, int32_t x, int32_t y) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 6, x, y);
    }

    void xdg_positioner_set_reactive(GfxrXdgPositioner* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 7);
    }

    void xdg_positioner_set_parent_size(GfxrXdgPositioner* self, int32_t parent_width, int32_t parent_height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 8, parent_width, parent_height);
    }

    void xdg_positioner_set_parent_configure(GfxrXdgPositioner* self, uint32_t serial) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 9, serial);
    }

    // xdg_surface dynamic declarations

    wl_interface xdg_surface_interface;

    int xdg_surface_add_listener(GfxrXdgSurface* self, GfxrXdgSurfaceListener* listener, void* data) const
    {
        return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
    }

    void xdg_surface_destroy(GfxrXdgSurface* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
        _wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
    }

    GfxrXdgToplevel* xdg_surface_get_toplevel(GfxrXdgSurface* self) const
    {
        return reinterpret_cast<GfxrXdgToplevel*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &xdg_toplevel_interface, NULL));
    }

    GfxrXdgPopup* xdg_surface_get_popup(GfxrXdgSurface* self, GfxrXdgSurface* parent, GfxrXdgPositioner* positioner) const
    {
        return reinterpret_cast<GfxrXdgPopup*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 2, &xdg_popup_interface, NULL, parent, positioner));
    }

    void xdg_surface_set_window_geometry(GfxrXdgSurface* self, int32_t x, int32_t y, int32_t width, int32_t height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, x, y, width, height);
    }

    void xdg_surface_ack_configure(GfxrXdgSurface* self, uint32_t serial) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, serial);
    }

    // xdg_toplevel dynamic declarations

    wl_interface xdg_toplevel_interface;

    int xdg_toplevel_add_listener(GfxrXdgToplevel* self, GfxrXdgToplevelListener* listener, void* data) const
    {
        return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
    }

    void xdg_toplevel_destroy(GfxrXdgToplevel* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
        _wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
    }

    void xdg_toplevel_set_parent(GfxrXdgToplevel* self, GfxrXdgToplevel* parent) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, parent);
    }

    void xdg_toplevel_set_title(GfxrXdgToplevel* self, const char* title) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, title);
    }

    void xdg_toplevel_set_app_id(GfxrXdgToplevel* self, const char* app_id) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, app_id);
    }

    void xdg_toplevel_show_window_menu(GfxrXdgToplevel* self, wl_seat* seat, uint32_t serial, int32_t x, int32_t y) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, seat, serial, x, y);
    }

    void xdg_toplevel_move(GfxrXdgToplevel* self, wl_seat* seat, uint32_t serial) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 5, seat, serial);
    }

    void xdg_toplevel_resize(GfxrXdgToplevel* self, wl_seat* seat, uint32_t serial, uint32_t edges) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 6, seat, serial, edges);
    }

    void xdg_toplevel_set_max_size(GfxrXdgToplevel* self, int32_t width, int32_t height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 7, width, height);
    }

    void xdg_toplevel_set_min_size(GfxrXdgToplevel* self, int32_t width, int32_t height) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 8, width, height);
    }

    void xdg_toplevel_set_maximized(GfxrXdgToplevel* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 9);
    }

    void xdg_toplevel_unset_maximized(GfxrXdgToplevel* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 10);
    }

    void xdg_toplevel_set_fullscreen(GfxrXdgToplevel* self, wl_output* output) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 11, output);
    }

    void xdg_toplevel_unset_fullscreen(GfxrXdgToplevel* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 12);
    }

    void xdg_toplevel_set_minimized(GfxrXdgToplevel* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 13);
    }

    // xdg_popup dynamic declarations

    wl_interface xdg_popup_interface;

    int xdg_popup_add_listener(GfxrXdgPopup* self, GfxrXdgPopupListener* listener, void* data) const
    {
        return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
    }

    void xdg_popup_destroy(GfxrXdgPopup* self) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
        _wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
    }

    void xdg_popup_grab(GfxrXdgPopup* self, wl_seat* seat, uint32_t serial) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, seat, serial);
    }

    void xdg_popup_reposition(GfxrXdgPopup* self, GfxrXdgPositioner* positioner, uint32_t token) const
    {
        _wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, positioner, token);
    }

    // Call this once libwayland-client is successfully loaded

    void initialize(const WaylandLoader* waylandLoader)
    {
        _wl = &waylandLoader->GetFunctionTable();

        _messageArgs = {
            &xdg_positioner_interface,
            &xdg_surface_interface,
            _wl->surface_interface,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            &xdg_toplevel_interface,
            &xdg_popup_interface,
            &xdg_surface_interface,
            &xdg_positioner_interface,
            _wl->seat_interface,
            nullptr,
            nullptr,
            nullptr,
            _wl->output_interface,
            &xdg_positioner_interface,
            nullptr,
        };

        _messages = {
            { "destroy", "", _messageArgs.data() + 0 },
            { "create_positioner", "n", _messageArgs.data() + 0 },
            { "get_xdg_surface", "no", _messageArgs.data() + 1 },
            { "pong", "u", _messageArgs.data() + 3 },
            { "ping", "u", _messageArgs.data() + 3 },
            { "destroy", "", _messageArgs.data() + 0 },
            { "set_size", "ii", _messageArgs.data() + 3 },
            { "set_anchor_rect", "iiii", _messageArgs.data() + 3 },
            { "set_anchor", "u", _messageArgs.data() + 3 },
            { "set_gravity", "u", _messageArgs.data() + 3 },
            { "set_constraint_adjustment", "u", _messageArgs.data() + 3 },
            { "set_offset", "ii", _messageArgs.data() + 3 },
            { "set_reactive", "3", _messageArgs.data() + 0 },
            { "set_parent_size", "3ii", _messageArgs.data() + 3 },
            { "set_parent_configure", "3u", _messageArgs.data() + 3 },
            { "destroy", "", _messageArgs.data() + 0 },
            { "get_toplevel", "n", _messageArgs.data() + 7 },
            { "get_popup", "no?o", _messageArgs.data() + 8 },
            { "set_window_geometry", "iiii", _messageArgs.data() + 3 },
            { "ack_configure", "u", _messageArgs.data() + 3 },
            { "configure", "u", _messageArgs.data() + 3 },
            { "destroy", "", _messageArgs.data() + 0 },
            { "set_parent", "o?", _messageArgs.data() + 7 },
            { "set_title", "s", _messageArgs.data() + 3 },
            { "set_app_id", "s", _messageArgs.data() + 3 },
            { "show_window_menu", "ouii", _messageArgs.data() + 11 },
            { "move", "ou", _messageArgs.data() + 11 },
            { "resize", "ouu", _messageArgs.data() + 11 },
            { "set_max_size", "ii", _messageArgs.data() + 3 },
            { "set_min_size", "ii", _messageArgs.data() + 3 },
            { "set_maximized", "", _messageArgs.data() + 0 },
            { "unset_maximized", "", _messageArgs.data() + 0 },
            { "set_fullscreen", "o?", _messageArgs.data() + 15 },
            { "unset_fullscreen", "", _messageArgs.data() + 0 },
            { "set_minimized", "", _messageArgs.data() + 0 },
            { "configure", "iia", _messageArgs.data() + 3 },
            { "close", "", _messageArgs.data() + 0 },
            { "configure_bounds", "4ii", _messageArgs.data() + 3 },
            { "wm_capabilities", "5a", _messageArgs.data() + 3 },
            { "destroy", "", _messageArgs.data() + 0 },
            { "grab", "ou", _messageArgs.data() + 11 },
            { "reposition", "3ou", _messageArgs.data() + 16 },
            { "configure", "iiii", _messageArgs.data() + 3 },
            { "popup_done", "", _messageArgs.data() + 0 },
            { "repositioned", "3u", _messageArgs.data() + 3 },
        };

        xdg_wm_base_interface = { "xdg_wm_base", 6, 4, _messages.data() + 0, 1, _messages.data() + 4 };
        xdg_positioner_interface = { "xdg_positioner", 6, 10, _messages.data() + 5, 0, _messages.data() + 15 };
        xdg_surface_interface = { "xdg_surface", 6, 5, _messages.data() + 15, 1, _messages.data() + 20 };
        xdg_toplevel_interface = { "xdg_toplevel", 6, 14, _messages.data() + 21, 4, _messages.data() + 35 };
        xdg_popup_interface = { "xdg_popup", 6, 3, _messages.data() + 39, 3, _messages.data() + 42 };
    }
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_WAYLAND_XDG_SHELL_H
