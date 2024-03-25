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

struct xdg_wm_base;
struct xdg_positioner;
struct xdg_surface;
struct xdg_toplevel;
struct xdg_popup;

// xdg_wm_base static declarations

enum xdg_wm_base_error
{
	XDG_WM_BASE_ERROR_ROLE = 0,
	XDG_WM_BASE_ERROR_DEFUNCT_SURFACES = 1,
	XDG_WM_BASE_ERROR_NOT_THE_TOPMOST_POPUP = 2,
	XDG_WM_BASE_ERROR_INVALID_POPUP_PARENT = 3,
	XDG_WM_BASE_ERROR_INVALID_SURFACE_STATE = 4,
	XDG_WM_BASE_ERROR_INVALID_POSITIONER = 5,
	XDG_WM_BASE_ERROR_UNRESPONSIVE = 6,
};

struct xdg_wm_base_listener
{
	void (*ping)(void* data, xdg_wm_base* object, uint32_t serial);
};

// xdg_positioner static declarations

enum xdg_positioner_error
{
	XDG_POSITIONER_ERROR_INVALID_INPUT = 0,
};

enum xdg_positioner_anchor
{
	XDG_POSITIONER_ANCHOR_NONE = 0,
	XDG_POSITIONER_ANCHOR_TOP = 1,
	XDG_POSITIONER_ANCHOR_BOTTOM = 2,
	XDG_POSITIONER_ANCHOR_LEFT = 3,
	XDG_POSITIONER_ANCHOR_RIGHT = 4,
	XDG_POSITIONER_ANCHOR_TOP_LEFT = 5,
	XDG_POSITIONER_ANCHOR_BOTTOM_LEFT = 6,
	XDG_POSITIONER_ANCHOR_TOP_RIGHT = 7,
	XDG_POSITIONER_ANCHOR_BOTTOM_RIGHT = 8,
};

enum xdg_positioner_gravity
{
	XDG_POSITIONER_GRAVITY_NONE = 0,
	XDG_POSITIONER_GRAVITY_TOP = 1,
	XDG_POSITIONER_GRAVITY_BOTTOM = 2,
	XDG_POSITIONER_GRAVITY_LEFT = 3,
	XDG_POSITIONER_GRAVITY_RIGHT = 4,
	XDG_POSITIONER_GRAVITY_TOP_LEFT = 5,
	XDG_POSITIONER_GRAVITY_BOTTOM_LEFT = 6,
	XDG_POSITIONER_GRAVITY_TOP_RIGHT = 7,
	XDG_POSITIONER_GRAVITY_BOTTOM_RIGHT = 8,
};

enum xdg_positioner_constraint_adjustment
{
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_NONE = 0,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_X = 1,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_SLIDE_Y = 2,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_FLIP_X = 4,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_FLIP_Y = 8,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_RESIZE_X = 16,
	XDG_POSITIONER_CONSTRAINT_ADJUSTMENT_RESIZE_Y = 32,
};

// xdg_surface static declarations

enum xdg_surface_error
{
	XDG_SURFACE_ERROR_NOT_CONSTRUCTED = 1,
	XDG_SURFACE_ERROR_ALREADY_CONSTRUCTED = 2,
	XDG_SURFACE_ERROR_UNCONFIGURED_BUFFER = 3,
	XDG_SURFACE_ERROR_INVALID_SERIAL = 4,
	XDG_SURFACE_ERROR_INVALID_SIZE = 5,
	XDG_SURFACE_ERROR_DEFUNCT_ROLE_OBJECT = 6,
};

struct xdg_surface_listener
{
	void (*configure)(void* data, xdg_surface* object, uint32_t serial);
};

// xdg_toplevel static declarations

enum xdg_toplevel_error
{
	XDG_TOPLEVEL_ERROR_INVALID_RESIZE_EDGE = 0,
	XDG_TOPLEVEL_ERROR_INVALID_PARENT = 1,
	XDG_TOPLEVEL_ERROR_INVALID_SIZE = 2,
};

enum xdg_toplevel_resize_edge
{
	XDG_TOPLEVEL_RESIZE_EDGE_NONE = 0,
	XDG_TOPLEVEL_RESIZE_EDGE_TOP = 1,
	XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM = 2,
	XDG_TOPLEVEL_RESIZE_EDGE_LEFT = 4,
	XDG_TOPLEVEL_RESIZE_EDGE_TOP_LEFT = 5,
	XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_LEFT = 6,
	XDG_TOPLEVEL_RESIZE_EDGE_RIGHT = 8,
	XDG_TOPLEVEL_RESIZE_EDGE_TOP_RIGHT = 9,
	XDG_TOPLEVEL_RESIZE_EDGE_BOTTOM_RIGHT = 10,
};

enum xdg_toplevel_state
{
	XDG_TOPLEVEL_STATE_MAXIMIZED = 1,
	XDG_TOPLEVEL_STATE_FULLSCREEN = 2,
	XDG_TOPLEVEL_STATE_RESIZING = 3,
	XDG_TOPLEVEL_STATE_ACTIVATED = 4,
	XDG_TOPLEVEL_STATE_TILED_LEFT = 5,
	XDG_TOPLEVEL_STATE_TILED_RIGHT = 6,
	XDG_TOPLEVEL_STATE_TILED_TOP = 7,
	XDG_TOPLEVEL_STATE_TILED_BOTTOM = 8,
	XDG_TOPLEVEL_STATE_SUSPENDED = 9,
};

enum xdg_toplevel_wm_capabilities
{
	XDG_TOPLEVEL_WM_CAPABILITIES_WINDOW_MENU = 1,
	XDG_TOPLEVEL_WM_CAPABILITIES_MAXIMIZE = 2,
	XDG_TOPLEVEL_WM_CAPABILITIES_FULLSCREEN = 3,
	XDG_TOPLEVEL_WM_CAPABILITIES_MINIMIZE = 4,
};

struct xdg_toplevel_listener
{
	void (*configure)(void* data, xdg_toplevel* object, int32_t width, int32_t height, wl_array* states);
	void (*close)(void* data, xdg_toplevel* object);
	void (*configure_bounds)(void* data, xdg_toplevel* object, int32_t width, int32_t height);
	void (*wm_capabilities)(void* data, xdg_toplevel* object, wl_array* capabilities);
};

// xdg_popup static declarations

enum xdg_popup_error
{
	XDG_POPUP_ERROR_INVALID_GRAB = 0,
};

struct xdg_popup_listener
{
	void (*configure)(void* data, xdg_popup* object, int32_t x, int32_t y, int32_t width, int32_t height);
	void (*popup_done)(void* data, xdg_popup* object);
	void (*repositioned)(void* data, xdg_popup* object, uint32_t token);
};

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Global to xdg_shell

class wayland_xdg_shell_table
{
	private:

		const WaylandLoader::FunctionTable* _wl;
		std::vector<wl_message> _messages;
		std::vector<const wl_interface*> _messageArgs;

	public:

		// xdg_wm_base dynamic declarations

		wl_interface xdg_wm_base_interface;

		int xdg_wm_base_add_listener(xdg_wm_base* self, xdg_wm_base_listener* listener, void* data) const
		{
			return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
		}

		void xdg_wm_base_destroy(xdg_wm_base* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		xdg_positioner* xdg_wm_base_create_positioner(xdg_wm_base* self) const
		{
			return reinterpret_cast<xdg_positioner*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &xdg_positioner_interface, NULL));
		}

		xdg_surface* xdg_wm_base_get_xdg_surface(xdg_wm_base* self, wl_surface* surface) const
		{
			return reinterpret_cast<xdg_surface*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 2, &xdg_surface_interface, NULL, surface));
		}

		void xdg_wm_base_pong(xdg_wm_base* self, uint32_t serial) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, serial);
		}

		// xdg_positioner dynamic declarations

		wl_interface xdg_positioner_interface;

		void xdg_positioner_destroy(xdg_positioner* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		void xdg_positioner_set_size(xdg_positioner* self, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, width, height);
		}

		void xdg_positioner_set_anchor_rect(xdg_positioner* self, int32_t x, int32_t y, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, x, y, width, height);
		}

		void xdg_positioner_set_anchor(xdg_positioner* self, uint32_t anchor) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, anchor);
		}

		void xdg_positioner_set_gravity(xdg_positioner* self, uint32_t gravity) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, gravity);
		}

		void xdg_positioner_set_constraint_adjustment(xdg_positioner* self, uint32_t constraint_adjustment) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 5, constraint_adjustment);
		}

		void xdg_positioner_set_offset(xdg_positioner* self, int32_t x, int32_t y) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 6, x, y);
		}

		void xdg_positioner_set_reactive(xdg_positioner* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 7);
		}

		void xdg_positioner_set_parent_size(xdg_positioner* self, int32_t parent_width, int32_t parent_height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 8, parent_width, parent_height);
		}

		void xdg_positioner_set_parent_configure(xdg_positioner* self, uint32_t serial) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 9, serial);
		}

		// xdg_surface dynamic declarations

		wl_interface xdg_surface_interface;

		int xdg_surface_add_listener(xdg_surface* self, xdg_surface_listener* listener, void* data) const
		{
			return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
		}

		void xdg_surface_destroy(xdg_surface* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		xdg_toplevel* xdg_surface_get_toplevel(xdg_surface* self) const
		{
			return reinterpret_cast<xdg_toplevel*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &xdg_toplevel_interface, NULL));
		}

		xdg_popup* xdg_surface_get_popup(xdg_surface* self, xdg_surface* parent, xdg_positioner* positioner) const
		{
			return reinterpret_cast<xdg_popup*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 2, &xdg_popup_interface, NULL, parent, positioner));
		}

		void xdg_surface_set_window_geometry(xdg_surface* self, int32_t x, int32_t y, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, x, y, width, height);
		}

		void xdg_surface_ack_configure(xdg_surface* self, uint32_t serial) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, serial);
		}

		// xdg_toplevel dynamic declarations

		wl_interface xdg_toplevel_interface;

		int xdg_toplevel_add_listener(xdg_toplevel* self, xdg_toplevel_listener* listener, void* data) const
		{
			return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
		}

		void xdg_toplevel_destroy(xdg_toplevel* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		void xdg_toplevel_set_parent(xdg_toplevel* self, xdg_toplevel* parent) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, parent);
		}

		void xdg_toplevel_set_title(xdg_toplevel* self, const char* title) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, title);
		}

		void xdg_toplevel_set_app_id(xdg_toplevel* self, const char* app_id) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 3, app_id);
		}

		void xdg_toplevel_show_window_menu(xdg_toplevel* self, wl_seat* seat, uint32_t serial, int32_t x, int32_t y) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 4, seat, serial, x, y);
		}

		void xdg_toplevel_move(xdg_toplevel* self, wl_seat* seat, uint32_t serial) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 5, seat, serial);
		}

		void xdg_toplevel_resize(xdg_toplevel* self, wl_seat* seat, uint32_t serial, uint32_t edges) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 6, seat, serial, edges);
		}

		void xdg_toplevel_set_max_size(xdg_toplevel* self, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 7, width, height);
		}

		void xdg_toplevel_set_min_size(xdg_toplevel* self, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 8, width, height);
		}

		void xdg_toplevel_set_maximized(xdg_toplevel* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 9);
		}

		void xdg_toplevel_unset_maximized(xdg_toplevel* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 10);
		}

		void xdg_toplevel_set_fullscreen(xdg_toplevel* self, wl_output* output) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 11, output);
		}

		void xdg_toplevel_unset_fullscreen(xdg_toplevel* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 12);
		}

		void xdg_toplevel_set_minimized(xdg_toplevel* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 13);
		}

		// xdg_popup dynamic declarations

		wl_interface xdg_popup_interface;

		int xdg_popup_add_listener(xdg_popup* self, xdg_popup_listener* listener, void* data) const
		{
			return _wl->proxy_add_listener(reinterpret_cast<wl_proxy*>(self), reinterpret_cast<void (**)(void)>(listener), data);
		}

		void xdg_popup_destroy(xdg_popup* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		void xdg_popup_grab(xdg_popup* self, wl_seat* seat, uint32_t serial) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, seat, serial);
		}

		void xdg_popup_reposition(xdg_popup* self, xdg_positioner* positioner, uint32_t token) const
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
