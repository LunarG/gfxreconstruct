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

#ifndef GFXRECON_GENERATED_WAYLAND_VIEWPORTER_H
#define GFXRECON_GENERATED_WAYLAND_VIEWPORTER_H

#include <vector>

#include <wayland-client.h>

#include "util/defines.h"
#include "util/wayland_loader.h"

struct wp_viewporter;
struct wp_viewport;

// wp_viewporter static declarations

enum wp_viewporter_error
{
	WP_VIEWPORTER_ERROR_VIEWPORT_EXISTS = 0,
};

// wp_viewport static declarations

enum wp_viewport_error
{
	WP_VIEWPORT_ERROR_BAD_VALUE = 0,
	WP_VIEWPORT_ERROR_BAD_SIZE = 1,
	WP_VIEWPORT_ERROR_OUT_OF_BUFFER = 2,
	WP_VIEWPORT_ERROR_NO_SURFACE = 3,
};

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Global to viewporter

class wayland_viewporter_table
{
	private:

		const WaylandLoader::FunctionTable* _wl;
		std::vector<wl_message> _messages;
		std::vector<const wl_interface*> _messageArgs;

	public:

		// wp_viewporter dynamic declarations

		wl_interface wp_viewporter_interface;

		void wp_viewporter_destroy(wp_viewporter* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		wp_viewport* wp_viewporter_get_viewport(wp_viewporter* self, wl_surface* surface) const
		{
			return reinterpret_cast<wp_viewport*>(_wl->proxy_marshal_constructor(reinterpret_cast<wl_proxy*>(self), 1, &wp_viewport_interface, NULL, surface));
		}

		// wp_viewport dynamic declarations

		wl_interface wp_viewport_interface;

		void wp_viewport_destroy(wp_viewport* self) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 0);
			_wl->proxy_destroy(reinterpret_cast<wl_proxy*>(self));
		}

		void wp_viewport_set_source(wp_viewport* self, wl_fixed_t x, wl_fixed_t y, wl_fixed_t width, wl_fixed_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 1, x, y, width, height);
		}

		void wp_viewport_set_destination(wp_viewport* self, int32_t width, int32_t height) const
		{
			_wl->proxy_marshal(reinterpret_cast<wl_proxy*>(self), 2, width, height);
		}

		// Call this once libwayland-client is successfully loaded

		void initialize(const WaylandLoader* waylandLoader)
		{
			_wl = &waylandLoader->GetFunctionTable();

			_messageArgs = {
				&wp_viewport_interface,
				_wl->surface_interface,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
			};

			_messages = {
				{ "destroy", "", _messageArgs.data() + 0 },
				{ "get_viewport", "no", _messageArgs.data() + 0 },
				{ "destroy", "", _messageArgs.data() + 0 },
				{ "set_source", "ffff", _messageArgs.data() + 2 },
				{ "set_destination", "ii", _messageArgs.data() + 2 },
			};

			wp_viewporter_interface = { "wp_viewporter", 1, 2, _messages.data() + 0, 0, _messages.data() + 2 };
			wp_viewport_interface = { "wp_viewport", 1, 3, _messages.data() + 2, 0, _messages.data() + 5 };
		}
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_WAYLAND_VIEWPORTER_H
